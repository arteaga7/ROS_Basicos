/*matriz_node: Realiza operaciones matriciales utilizando la libreria Eigen.
Pegar en CMakeList:
find_package(Eigen3 REQUIRED)
include_directories(${Eigen3_INCLUDE_DIRS})*/
#include <ros/ros.h>
#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

int main(int argc, char* argv[])
{
ros::init(argc,argv,"matriz_node"); //Inicializa el nodo
//Definicion de vector
Vector2d X;  		//pertenece a 2x1
//Llenar un vector
X << -5, 3;
Vector2d Q(2,8);
cout << "X=\n" << X << "\n\n";
cout << "Q=\n" << Q << "\n\n\n\n";
//Definicion de matriz
Matrix2d R;  		//pertenece a 2x2
MatrixXf T(3,2);  	//pertenece a 3x2
//Llenar una matriz
R <<2,3,
    0,7;
R(0,0) = 1;
cout << "R=\n" << R << "\n\n";
T.row(0) << 1,0;
T.row(1) << 0,33;
T.row(2) << 0,33;
T.col(1) << 0,1,9;
cout << "T=\n" << T << "\n\n\n----------------------------\n";
//----------------------------------------------------
//Matriz o vector de ceros
Vector3d C;
C = MatrixXd::Zero(3,1);
cout << "C=\n" << C << "\n\n";
//Multiplicacion de vectores/matrices
Vector2d V;
V = R*X;
cout << "V=R*X=\n" << V << "\n\n";
//Obtener elementos de un vector
cout << "V(0)=" << V(0) <<"  V(1)=" << V(1) << "\n\n\n----------------------------\n";
//------------------------------------------------------
//Norma de vector
cout << "|V|= " << V.norm() << "\n\n";
//Producto punto
Vector3d v(1,2,3);
Vector3d w(0,1,2);
cout << "v . w = " << v.dot(w) << "\n\n";
//Producto cruz
cout << "v x w =\n" << v.cross(w) << "\n\n";
cout << "w x v = -(v x w) =\n" << w.cross(v) << "\n\n\n----------------------------\n";
//----------------------------------------------------
//Transpuesta de matriz
Matrix3d R3;
R3 <<1,-2,-3,
     0, 4,-5,
     6,-7, 9;
cout << "R3=\n" << R3 << "\n\n";
cout << "R3 transpuesta=\n" << R3.transpose() << "\n\n";
//Inversa de matriz
cout << "R3 inversa=\n" << R3.inverse() << "\n\n";
//-----------------------------------------------------
//Eigenvalores de matriz
VectorXcd eigvals = R3.eigenvalues();
cout << "Eigenvalores de R3=\n" << eigvals << "\n\n";
return 0;
}
