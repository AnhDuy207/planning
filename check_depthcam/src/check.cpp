#include <iostream>

#include <ros/ros.h>

#include <cv_bridge/cv_bridge.h>

ros::Subscriber depth_image_sub;
ros::Publisher changeDepth;
cv::Mat depth_image;

void DepthCallback(const sensor_msgs::ImageConstPtr& img)
{
  cv_bridge::CvImagePtr cv_ptr;
  cv_ptr = cv_bridge::toCvCopy(img, img->encoding);

  if (img->encoding == sensor_msgs::image_encodings::TYPE_16UC1) {
    (cv_ptr->image).convertTo(cv_ptr->image, CV_32FC1, 0.001);
  }

  cv_ptr->image.copyTo(depth_image);
  cv_ptr->header = img->header;    
  cv_ptr->encoding = sensor_msgs::image_encodings::TYPE_32FC1;

  changeDepth.publish(cv_ptr);
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "check_depthcamera");
  ros::NodeHandle nh;

  depth_image_sub = nh.subscribe("camera/depth/image_rect_raw", 10, &DepthCallback);
  changeDepth = nh.advertise<sensor_msgs::Image>("/camera/ChangeDepth", 10);

  ros::Duration(1.0).sleep();
  ros::spin();

  return 0;
}
