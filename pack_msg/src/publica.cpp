/* publica_node: publica mensajes personalizados en el topico llamado
 * "my_topic" para que el nodo "suscribe_node" se suscriba a dicho topico.*/
#include <ros/ros.h>
#include <pack_msg/Msg.h>
int main(int argc, char* argv[])
{
  ros::init(argc, argv, "publica_node");    //Inicializa el nodo
  ros::NodeHandle nh;                       //Crea el handle
  ros::Publisher pub;                       //Crea objeto "pub" de tipo "Publisher"
  pub = nh.advertise<pack_msg::Msg>("my_topic", 1);
  //mensaje "pack_msg/Msg" correspondiente al topico "my_topic", buffer=1
  ros::Rate r(10);      //Frecuencia de ejecucion=10hz
  pack_msg::Msg dato;   //Crea objeto "dato" para mensajes tipo "pack_msg/Msg"
  int count = 0;
  while (ros::ok())
  {
    dato.stamp = ros::Time::now();  //Guarda el tiempo actual en el miembro "stamp"
    dato.data = count;              //Guarda el contador en el miembro "data"
    dato.w = 12.4568;               //Guarda 12.4568 en el miembro "w"
    printf("Envio dato = %d, %d, %f\n\n",dato.stamp.sec,dato.data,dato.w);
    pub.publish(dato);
    r.sleep();      //Espera lo necesario para completar el loop rate
    count++;
  }
  return 0;
}
