#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Define
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
   // Initializa
  ros::init(argc, argv, "move_turtlebot");

  //tell the action
  MoveBaseClient ac("move_base", true);

  //Wait 5 sec
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  //set up the frame parametrs
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

float goals[2][3] = {{-2.0, 0.0, 1.57}, {0.0, 0.0, 1.57}};
  for (int i=0; i<2; i++){
  // define a position and orientation
  goal.target_pose.pose.position.x = goals[i][0];
  goal.target_pose.pose.position.y = goals[i][1];
  goal.target_pose.pose.orientation.w = goals[i][2];

// Send the goal position
  ROS_INFO("Sending goal");
  ac.sendGoal(goal);

//Wait an infinite time 
  ac.waitForResult();


  ros::Duration(5.0).sleep();
  }
    //Chek if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
      ROS_INFO("Hooray, reached drop off zone");
  else
      ROS_INFO("The base failed to move forward");

  return 0;
}

