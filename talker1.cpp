/* talker1_node: publica en el topico llamado "chatter" para que
 * el nodo "listener_node" se suscriba a dicho topico.*/
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>
using namespace std;

int main(int argc, char* argv[])
{
  ros::init(argc, argv, "talker_node"); //Inicializa el nodo
  ros::NodeHandle node_handle;          //Crea el handle
  ros::Publisher pub;           //Crea objeto "pub" de tipo "Publisher"

  pub = node_handle.advertise<std_msgs::String>("/chatter", 1);
  //tipo de mensaje "std_msgs/String" correspondiente al topico "/chatter", buffer=1
  ros::Rate loop_rate(10);      //Frecuencia de ejecucion=10hz

  int count = 0;
  while (ros::ok())
  {
    std_msgs::String msg;       //Crea objeto "msg" para mensajes tipo "std_msgs/String"
    std::stringstream ss;       //Crea objeto "ss" de tipo "stringstream"

    ss << "Hello world " << count;  	//inserta "Hello world " y count en ss
    msg.data = ss.str();        	//Transforma ss a string
    //ROS_INFO("%s", msg.data.c_str());
    cout << msg.data << endl;
    pub.publish(msg);
    ros::spinOnce();            //Activa callbacks
    loop_rate.sleep();          //Espera lo necesario para completar el loop rate
    count++;
  }
  return 0;
}
