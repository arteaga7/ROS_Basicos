/* code1_node: publica velocidades en el topico "/turtle1/cmd_vel" y se
 suscribe al topico "/turtle1/pose" para imprimir en pantalla la postura de la tortuga.*/
#include <ros/ros.h>
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include "std_srvs/Empty.h"
#include <stdio.h>

using namespace std;

//Variables globales
double x,y,theta;

geometry_msgs::Twist 	vel;    //Crea objeto "vel" para mensajes tipo "geometry_msgs/Twist"
std_srvs::Empty         empty;  //Crea objeto "empty" para mensajes tipo "std_srvs/Empty"

void PoseCallback(const turtlesim::Pose::ConstPtr &msg){
//Paso de parametros por referencia usando puntero a constante
//tipo de mensaje "turtlesim/Pose" correspondiente al topico "/turtle1/pose"
 x = msg->x;    //x = (*msg).x
 y = msg->y;
 theta = msg->theta;
}

geometry_msgs::Twist movimiento(float linear, float angular){
    vel.linear.x = linear;
    vel.angular.z = angular;
    return vel;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "code1_node");	//Inicializa el nodo
  ros::NodeHandle nh;			//Crea el handle
  ros::Publisher  pub;                  //Crea objeto "pub" de tipo "Publisher"
  ros::Subscriber sub;                  //Crea objeto "sub" de tipo "Subscriber"
  ros::ServiceClient serviceclear;	//Crea objeto "serviceclear" de tipo "ServiceClient"

  pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);
//tipo de mensaje "geometry_msgs/Twist" correspondiente al topico "/turtle1/cmd_vel", buffer=1
  sub = nh.subscribe("/turtle1/pose", 1, PoseCallback);
//topico "/turtle1/pose", buffer=10, funcion de callback
  serviceclear = nh.serviceClient<std_srvs::Empty>("/clear");
//tipo de mensaje "std_srvs/Empty" correspondiente al servicio "/clear"
  ros::Rate loop_rate(10);	//Frecuencia de ejecucion=10hz
  serviceclear.call(empty);     //Llamada al servicio "/clear"
  while (ros::ok())
  {
    vel = movimiento(3,1);
    pub.publish(vel);
    printf("x = %.3f\ty = %.3f\ttheta = %.3f\n",x,y,theta);
    ros::spinOnce();	//Activa callbacks
    loop_rate.sleep();	//Espera lo necesario para completar el loop rate
  }
  ros::spin();          //Espera por callbacks
  return 0;
}
