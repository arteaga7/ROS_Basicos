/*suscribe_node: se suscribe al topico "/my_topic" e imprime
 * mensajes personalizados tipo "pack_msg/Msg"*/
#include "ros/ros.h"
#include <pack_msg/Msg.h>

void msgCallback(const pack_msg::Msg::ConstPtr &received){
//tipo de mensaje "pack_msg/Msg" correspondiente al topico "/my_topic"
printf("Recibo= %d, %d, %f\n\n",received->stamp.sec,received->data,received->w);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "suscribe_node");	//Inicializa el nodo
  ros::NodeHandle nh;				//Crea el handle
  ros::Subscriber sub = nh.subscribe("/my_topic", 1, msgCallback);
  //topico "/my_topic", buffer=1, funcion de callback
  ros::spin();  //Espera por callbacks. Necesaria porque este nodo solo es suscriptor
  return 0;
}
