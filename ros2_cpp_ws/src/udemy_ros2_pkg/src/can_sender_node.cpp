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

#define CAN_INTERFACE "vcan0"

using namespace std::chrono_literals;

class CanSenderNode : public rclcpp::Node
{
public:
  CanSenderNode() : Node("can_sender_node")
  {
    pub_ = this->create_publisher<std_msgs::msg::String>("can_msg", 10);

    struct sockaddr_can addr;
    struct ifreq ifr;

    if ((can_socket_ = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
      perror("Socket creation error");
      exit(EXIT_FAILURE);
    }

    strcpy(ifr.ifr_name, CAN_INTERFACE);
    ioctl(can_socket_, SIOCGIFINDEX, &ifr);

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(can_socket_, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
      perror("Bind error");
      exit(EXIT_FAILURE);
    }

    RCLCPP_INFO(this->get_logger(), "CAN interface '%s' is up and running", CAN_INTERFACE);

    send_timer_ = this->create_wall_timer(1s, std::bind(&CanSenderNode::send_message, this));
  }

private:
  void send_message()
  {
    std_msgs::msg::String msg;
    msg.data = "Hello World";

    can_frame frame;
    frame.can_id = 0x123;
    frame.can_dlc = 8;

    for (size_t i = 0; i < msg.data.size() && i < sizeof(frame.data); i++) {
      frame.data[i] = msg.data[i];
    }

    ssize_t nbytes = write(can_socket_, &frame, sizeof(frame));

    if (nbytes != sizeof(frame)) {
      perror("Write error");
    } else {
      RCLCPP_INFO(this->get_logger(), "CAN message sent: %s", msg.data.c_str());
    }
  }

  rclcpp::TimerBase::SharedPtr send_timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
  int can_socket_;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<CanSenderNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
