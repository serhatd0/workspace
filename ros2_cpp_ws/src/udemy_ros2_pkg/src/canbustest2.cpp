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

int main()
{
    int s;
    struct sockaddr_can addr;
    struct ifreq ifr;

    const char* ifname = "can0"; // açmak istediğimiz arabirim adı

    s = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    strcpy(ifr.ifr_name, ifname);
    ioctl(s, SIOCGIFINDEX, &ifr);
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
    bind(s, (struct sockaddr *)&addr, sizeof(addr));

    while (1)
    {
        struct can_frame frame;
        int nbytes = read(s, &frame, sizeof(struct can_frame));
        if (nbytes > 0)
        {
            std::string data;
            for (int i = 0; i < frame.can_dlc; i++)
            {
                data += std::to_string(frame.data[i]);
                data += " ";
            }
            std::cout << "Received message on CAN bus: " << data << std::endl;
        }
    }

    close(s);

    return 0;
}