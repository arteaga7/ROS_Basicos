/*service_server_node: Habilita el servicio de suma de 2 enteros largos (service server)*/
#include "ros/ros.h"	
#include "pack_srv/MySrv.h"	//Creado automaticamente despues de catkin_make

// service request se declara como 'req', y service response se declara como 'res'
bool suma(pack_srv::MySrv::Request &req, pack_srv::MySrv::Response &res)
{
res.sum = req.a + req.b;
printf("Peticion: %ld, %ld\n",(long int)req.a, (long int)req.b);
printf("Respuesta: %ld\n", (long int)res.sum);
return true;
}

int main(int argc, char **argv) 			
{
ros::init(argc, argv, "service_server_node"); 	//Inicializa el nodo
ros::NodeHandle nh;                             //Crea el handle
ros::ServiceServer server = nh.advertiseService("suma2EnterosLargos",suma);
printf("Servidor listo!\n\n");
ros::spin();	//Espera por service request. Esta instruccion es necesaria.
return 0;
}
