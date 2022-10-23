// Homework1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vec3.h"

int main()
{
    Vec3<float>* v = new Vec3<float>();
    std::cout << "Vec v = {" << v->GetX() << "," << v->GetY() << "," << v->GetZ() << "}\n";
    delete v;

    v = new Vec3<float>(2, 4, 7);
    std::cout << "Vec v = {" << v->GetX() << "," << v->GetY() << "," << v->GetZ() << "}\n";

    Vec3<float>* v2 = new Vec3<float>(*v);
    std::cout << "Vec v2 = {" << v2->GetX() << "," << v2->GetY() << "," << v2->GetZ() << "}\n";

    Vec3<float>* v3 = new Vec3<float>(3,2,0);
    std::cout << "Vec v3 = {" << v3->GetX() << "," << v3->GetY() << "," << v3->GetZ() << "}\n";

    Vec3<float>* v4 = new Vec3<float>(-2, -2, 0);
    std::cout << "Vec v4 = {" << v4->GetX() << "," << v4->GetY() << "," << v4->GetZ() << "}\n";

    *v2 = *v2 + *v;
    std::cout << "Vec v2 + v = {" << v2->GetX() << "," << v2->GetY() << "," << v2->GetZ() << "}\n";

    *v2 = v2->Normalize();
    std::cout << "v2 Normalize = {" << v2->GetX() << "," << v2->GetY() << "," << v2->GetZ() << "}\n";

    std::cout << "v Distance to v3= {" << v->DistanceTo(*v3) << "}\n";

    std::cout << "v dot product with v3= {" << v->DotProduct(*v3) << "}\n";

    Vec3<float>* crossV_v3 = new Vec3<float>();
    *crossV_v3 = v->CrossProduct(*v3);
    std::cout << "v cross product with v3= {" << crossV_v3->GetX() << "," << crossV_v3->GetY() << "," << crossV_v3->GetZ() << "}\n";
    
    std::cout << "Angle between v and v3= {" << v->AngleBetween(*v3) << "}\n";
    std::cout << "Angle between v and v4= {" << v->AngleBetween(*v4) << "}\n";

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file