#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <chrono>
#include "rclcpp/rclcpp.hpp"

class CanCore {
public:
    int skt;
    struct sockaddr_can addr;
    struct ifreq ifr;
    int nbytes;
    struct can_frame frame;

    CanCore(const char* ifname) {
        skt = socket(PF_CAN, SOCK_RAW, CAN_RAW);
        if (skt < 0) {
            throw std::runtime_error("Failed to create socket.");
        }

        strcpy(ifr.ifr_name, ifname);
        ioctl(skt, SIOCGIFINDEX, &ifr);

        addr.can_family = AF_CAN;
        addr.can_ifindex = ifr.ifr_ifindex;

        if (bind(skt, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            throw std::runtime_error("Failed to bind to address.");
        }
    }

    ~CanCore() {
        close(skt);
    }

    void SendCanBus(uint32_t id, std::vector<uint8_t> bytes) {
        frame.can_id = id;
        frame.can_dlc = bytes.size();
        std::memcpy(frame.data, bytes.data(), bytes.size());
        nbytes = write(skt, &frame, sizeof(struct can_frame));
    }

    std::vector<uint8_t> GetCanFrame() {
        nbytes = read(skt, &frame, sizeof(struct can_frame));
        std::vector<uint8_t> bytes(frame.can_dlc);
        std::memcpy(bytes.data(), frame.data, frame.can_dlc);
        return bytes;
    }
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    if (argc != 2) {
        RCLCPP_ERROR(rclcpp::get_logger("canbus_test"), "Usage: ./canbus_test <can_interface_name>");
        return -1;
    }

    CanCore can_core(argv[1]);

    RCLCPP_INFO(rclcpp::get_logger("canbus_test"), "Sending test frame...");
    std::vector<uint8_t> test_bytes{0x12, 0x34, 0x56, 0x78};
    can_core.SendCanBus(0x123, test_bytes);
    RCLCPP_INFO(rclcpp::get_logger("canbus_test"), "Waiting for response...");
    auto start_time = std::chrono::high_resolution_clock::now();

    std::vector<uint8_t> response_bytes;
    while (response_bytes.empty()) {
        response_bytes = can_core.GetCanFrame();
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        if (duration > 5000) {
            RCLCPP_ERROR(rclcpp::get_logger("canbus_test"), "Timeout while waiting for response.");
            return -1;
        }
    }

    RCLCPP_INFO(rclcpp::get_logger("canbus_test"), "Received response:");
    for (const auto& byte : response_bytes) {
        RCLCPP_INFO(rclcpp::get_logger("canbus_test"), "0x%02X", byte);
    }

    return 0;
}


