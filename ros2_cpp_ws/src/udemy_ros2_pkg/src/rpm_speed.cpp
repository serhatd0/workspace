#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "std_msgs/msg/float64.hpp"
#include <linux/spi/spidev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

#define SPI_CHANNEL 0
#define SPI_SPEED   1000000
#define SPI_MODE    0


class RobotController : public rclcpp::Node {
public:
  RobotController() : Node("robot_controller") {
    cmd_vel_sub_ = this->create_subscription<geometry_msgs::msg::Twist>(
      "cmd_vel", 10, std::bind(&RobotController::cmd_vel_callback, this, std::placeholders::_1));
    rpm_sub_ = this->create_subscription<std_msgs::msg::Float64>(
      "rpm", 10, std::bind(&RobotController::rpm_callback, this, std::placeholders::_1));
    speed_sub_ = this->create_subscription<std_msgs::msg::Float64>(
      "speed", 10, std::bind(&RobotController::speed_callback, this, std::placeholders::_1));
      
   
  }

private:
  void cmd_vel_callback(const geometry_msgs::msg::Twist::SharedPtr msg) {
    double linear_vel = msg->linear.x;
    double angular_vel = msg->angular.z;

    // Lineer ve açısal hızlara göre tekerlek hızlarını hesaplayın
    double left_speed = (linear_vel - angular_vel) / 2;
    double right_speed = (linear_vel + angular_vel) / 2;

    // RPM ve hız değerlerini de kullanarak tekerlek hızlarını ayarlayın
    double rpm_factor = 1.0;
    if (rpm_msg_ != nullptr) {
      rpm_factor = rpm_msg_->data;
    }
    double speed_factor = 1.0;
    if (speed_msg_ != nullptr) {
      speed_factor = speed_msg_->data ;
    }

    left_speed *= rpm_factor * speed_factor;
    right_speed *= rpm_factor * speed_factor;
  	std::cout <<"RPM : "<<rpm_factor << std::endl;
	  std::cout <<"Speed : "<<speed_factor << std::endl;
	  std::cout <<"SOL TEKER : "<<left_speed << std::endl;
	  std::cout <<"SAĞ TEKER : "<<right_speed << std::endl;
  }

  

  void rpm_callback(const std_msgs::msg::Float64::SharedPtr msg) {
    rpm_msg_ = msg;
  }

  void speed_callback(const std_msgs::msg::Float64::SharedPtr msg) {
    speed_msg_ = msg;
  }
  
  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub_;
  rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr rpm_sub_;
  rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr speed_sub_;

  std_msgs::msg::Float64::SharedPtr rpm_msg_ = nullptr;
  std_msgs::msg::Float64::SharedPtr speed_msg_ = nullptr;

  static constexpr double MAX_RPM = 1000.0;
  static constexpr double MAX_SPEED = 10.0;
};



int main(int argc, char * argv[]){
	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<RobotController>());
	rclcpp::shutdown();

	return 0;
}

