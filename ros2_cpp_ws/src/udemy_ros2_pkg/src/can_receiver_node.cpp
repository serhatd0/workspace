#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <net/if.h>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class CanReceiverNode : public rclcpp::Node
{
public:
  CanReceiverNode()
  : Node("can_receiver_node")
  {
    const char* ifname = "vcan0";

    // Socket oluşturma
    if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
        perror("Socket oluşturulamadı");
        return;
    }

    // Arabirim isim bilgisini ayarlama
    strcpy(ifr.ifr_name, ifname);
    ioctl(s, SIOCGIFINDEX, &ifr);

    // Socket ve arabirim arasındaki bağlantıyı kurma
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
    if (bind(s, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("Bind hatası");
        return;
    }

    RCLCPP_INFO(this->get_logger(), "CAN arabirimi '%s' için dinleme başladı...", ifname);

    // Mesaj alma ve ROS 2 üzerinde yayınlama
    while (rclcpp::ok()) {
        if (read(s, &frame, sizeof(struct can_frame)) < 0) {
            perror("Read hatası");
            return;
        }

        std::ostringstream msg_stream;
        msg_stream << "Arbitration ID: 0x" << std::hex << frame.can_id << ", Data:";
        for (int i = 0; i < frame.can_dlc; i++) {
            msg_stream << " " << std::dec << static_cast<int>(frame.data[i]);
        }
        RCLCPP_INFO(this->get_logger(), msg_stream.str().c_str());

        auto msg = std::make_shared<std_msgs::msg::String>();
        msg->data = msg_stream.str();
        publisher_->publish(*msg);
    }
  }

private:
  int s;
  struct sockaddr_can addr;
  struct ifreq ifr;
  struct can_frame frame;

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_ = 
    this->create_publisher<std_msgs::msg::String>("can_receiver_topic", 10);
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CanReceiverNode>());
  rclcpp::shutdown();
  return 0;
}
