/*listener1_node: se suscribe al topico "/chatter" e imprime el contenido*/
#include "ros/ros.h"
#include <std_msgs/String.h>
using namespace std;

void subscriber_Callback(const std_msgs::String::ConstPtr &received){
//tipo de mensaje "std_msgs/String" correspondiente al topico "/chatter"
//Paso de parametros por referencia usando puntero a constante

    //ROS_INFO("I received the following: %s", received->data.c_str());
    cout << "Yo recibo: " << received->data << endl;
	//received->data = (*received).data
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener_node");	//Inicializa el nodo
  ros::NodeHandle node_handle;			//Crea el handle

  ros::Subscriber sub = node_handle.subscribe("/chatter", 1, subscriber_Callback);
  //topico "/chatter", buffer=1, funcion de callback
  ros::spin();  //Espera por callbacks. Necesaria porque este nodo solo es suscriptor
  return 0;
}
