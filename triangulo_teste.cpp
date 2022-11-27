
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "triangulo.hpp"
#include "triangulo.cpp"

//testar 0 e negativos

TEST_CASE("Testando Tipo: ") {

    SUBCASE("Subcaso positivo: "){ 
        shapes::Triangle triangle(2,2,1);
        CHECK(triangle.getKind() == shapes::Triangle::Kind::ISOSCELES);
        shapes::Triangle triangle1(3,2,2);
        CHECK(triangle1.getKind() == shapes::Triangle::Kind::ISOSCELES);
        shapes::Triangle triangle2(4,3,2);
        CHECK(triangle2.getKind() == shapes::Triangle::Kind::SCALENE);
        shapes::Triangle triangle3(5,4,3);
        CHECK(triangle3.getKind() == shapes::Triangle::Kind::SCALENE);

    }
   SUBCASE("Subcaso negativo: "){//função teste se o triangulo e isoceles antes de testar para equilatero, e triangulo equilatero passa no teste do escaleno
        shapes::Triangle triangle4(2,2,2);
        CHECK(triangle4.getKind() == shapes::Triangle::Kind::EQUILATERAL);
        shapes::Triangle triangle5(3,3,3);
        CHECK(triangle5.getKind() == shapes::Triangle::Kind::EQUILATERAL);
    }
}
TEST_CASE("Testando perimetro") {//formula esta errada pois retorno da funcao perimetro = (return side1 + side2 + side2;) entao, se o lado 2 for de valor diferente do lado 3 a funcao retora valor errado
    
    SUBCASE("Subcaso positivo: "){// equilateros e isoceles cujo lado diferente seja o maior
        shapes::Triangle triangleA(3,3,3);
        CHECK(triangleA.getPerimeter() == 9);
        shapes::Triangle triangleB(73,73,73);
        CHECK(triangleB.getPerimeter() == 219);
        shapes::Triangle triangleC(8,7,7);
        CHECK(triangleC.getPerimeter() == 22);
        shapes::Triangle triangleD(33,27,27);
        CHECK(triangleD.getPerimeter() == 87);
    }
   SUBCASE("Subcaso negativo: "){// escalenos e isoceles cujo lado diferente seja menor
        shapes::Triangle triangleE(9,9,7);
        CHECK(triangleE.getPerimeter() == 25);
        shapes::Triangle triangleF(12,12,11);
        CHECK(triangleF.getPerimeter() == 35);
        shapes::Triangle triangleG(8,6,5);
        CHECK(triangleG.getPerimeter() == 19);
        shapes::Triangle triangleH(97,73,65);
        CHECK(triangleH.getPerimeter() == 235);
    }
   
}
TEST_CASE("Testando Area") {//calculo de area depende de perimetro
    
    SUBCASE("Subcaso positivo: "){//casos onde perimtro retorna certo
        shapes::Triangle triangleA(3,3,3);
        CHECK(triangleA.getArea() ==   sqrt(9/2 * (9/2 - 3)*(9/2- 3)*(9/2 - 3) ));
        shapes::Triangle triangleB(73,73,73);
        CHECK(triangleB.getArea() ==  sqrt(219/2 * (219/2 - 73)*(219/2 - 73)*(219/2 - 73) ));
        shapes::Triangle triangleC(8,7,7);
        CHECK(triangleC.getArea() == sqrt(22/2 * (22/2 - 8)*(22/2 - 7)*(22/2 - 7) ));
        shapes::Triangle triangleD(33,27,27);
        CHECK(triangleD.getArea() == sqrt(87/2 * (87/2 - 33)*(87/2 - 27)*(87/2 - 27) ));
    }
   SUBCASE("Subcaso negativo: "){//casos de perimetro errado
         shapes::Triangle triangleE(9,9,7);
        CHECK(triangleE.getArea() == sqrt(25/2 * (25/2 - 9)*(25/2 - 9)*(25/2 - 7) ));
        shapes::Triangle triangleF(12,12,11);
        CHECK(triangleF.getArea() ==  sqrt(35/2 * (35/2 - 12)*(35/2 - 12)*(35/2 - 11) ));
        shapes::Triangle triangleG(8,6,5);
        CHECK(triangleG.getArea() ==  sqrt(19/2 * (19/2 - 8)*(19/2 - 6)*(19/2 - 5) ));
        shapes::Triangle triangleH(97,73,65);
        CHECK(triangleH.getArea() ==  sqrt(235/2 * (235/2- 97)*(235/2- 73)*(235/2 - 65) ));
    }
   
}

/*double halfPerimeter = getPerimeter() / 2.0;
  double radicand = halfPerimeter
                    * (halfPerimeter - side1)
                    * (halfPerimeter - side2)
                    * (halfPerimeter - side3);
  return sqrt(radicand);*/