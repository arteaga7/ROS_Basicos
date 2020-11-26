/*service_client_node: Peticion de servicio de suma de 2 enteros largos (service request)*/
#include "ros/ros.h"
#include "pack_srv/MySrv.h"
#include <stdio.h>

int main(int argc, char **argv){
ros::init(argc, argv, "service_client_node");       //Inicializa el nodo
ros::NodeHandle nh;                         //Crea el handle
ros::ServiceClient client =
nh.serviceClient<pack_srv::MySrv>("suma2EnterosLargos");
//mensaje "pack_srv/MySrv" correspondiente al servicio "/suma2EnterosLargos"

pack_srv::MySrv srv;    	//Crea objeto "srv" para mensajes tipo "pack_srv/MySrv"
srv.request.a = 20000;
srv.request.b = 60000;

if (client.call(srv)){
printf("Peticion al servicio con los argumentos a=%ld y b=%ld\n",(long int)srv.request.a,(long int)srv.request.b);
printf("Respuesta = %ld\n", (long int)srv.response.sum);
}
else
{
    printf("Fallo al llamar al servicio");
    return 1;
}
return 0;
}
