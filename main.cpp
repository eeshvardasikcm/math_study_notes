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
        [[nodiscard]] string printV() const {
            string s="(";
            s.append(to_string(x));
            s.append(", ");
            s.append(to_string(y));
            s.append(") ");
            return s;
        }
    };

    struct _line {
        _point A, B;
    };

    struct _unit_of_measure {
        static const string _km;
        static const string _hr;
        static string _km_per_h() {
            string s=_km;
            s.append("/");
            s.append(_unit_of_measure::_hr);
            s.append(" ");
            return s;
        };
    };
    const string _unit_of_measure::_km = "km";
    const string _unit_of_measure::_hr = "hours";

    struct _speed {
        float v;
        void calculate(float kilometers, float hours) {
            v = kilometers / hours;
        };
        [[nodiscard]] string printV() const {
            string s=to_string(v);
            s.append(_unit_of_measure::_km_per_h());
            return s;
        };
    };

    struct _line_formula {
        float Ax, Ay, Bx, By;
#ifdef VARIABLE_INLUCDE_experimental
        _point _equation_1(float x, float y, float xn=11, float yn=65) {
            return _point((float _f1(*(x)))*(xn), (float _f2(*(y)))*(yn));
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
