#include <iostream>
#ifdef VARIABLE_INCLUDE_standard
#include "standard.h"
#endif
#ifdef VARIABLE_INLUCDE_experimental
#include "experimental.h"
#endif
using namespace std;
namespace class_10_od {
    struct _point {
        float x, y;

        string printV();
    };

    struct _line {
        _point A, B;
    };

    struct _line_formula {
        float y, x;
#ifdef VARIABLE_INLUCDE_experimental
        _point _equation_1(float x, float y, float xn=11, float yn=65) {
            return _point((float f1(*(x)))*(xn), (float f2(*(y)))*(yn));
        }

        _point intersect(_line l1, _line_formula l2) {

        }
#endif
    };

}
int main() {
    std::cout << "khan_academy_math_study_notes (beta)" << std::endl;
    return 0;
}
