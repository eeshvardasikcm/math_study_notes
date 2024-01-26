#include <iostream>
#include <cmath>
#include <utility>
#include <vector>
#ifdef VARIABLE_INCLUDE_standard
#include "standard.h"
#endif
#ifdef VARIABLE_INLUCDE_experimental
#include "experimental.h"
#endif
using namespace std;
namespace class_10_od {
    struct _menu_runnable {
        string name;
        virtual void inputVariables() {};
        void runFromMenu() {
            inputVariables();
        };
    };

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
            string s=" ";
            s.append(_km);
            s.append("/");
            s.append(_unit_of_measure::_hr);
            s.append(" ");
            return s;
        };
    };
    const string _unit_of_measure::_km = "km";
    const string _unit_of_measure::_hr = "hour";

    struct _speed : _menu_runnable {
        float v=0;
        void calculate(float kilometers, float hours) {
            v = kilometers / hours;
        };
        [[nodiscard]] string getV() const {
            string s=to_string(v);
            s.append(_unit_of_measure::_km_per_h());
            return s;
        };
        void inputVariables() override {
            cout << "distance(" << _unit_of_measure::_km << "): ";
            float d;
            cin >> d; cin.ignore();
            cout << "time(" << _unit_of_measure::_hr << "): ";
            float t;
            cin >> t; cin.ignore();
            calculate(d,t);
            cout << getV() << endl;
        }
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

    struct _sin : _menu_runnable {
        static float nx(float n, float x) {
            return sin(n*x);
        }
        void inputVariables() override {
            cout << "sin n*x" << endl;
            cout << "n: ";
            float n;
            cin >> n; cin.ignore();
            cout << "x: ";
            float x;
            cin >> x; cin.ignore();
            cout << "sin " << n << "x, ";
            cout << "where x=" << x << " is equal to: ";
            cout << nx(n,x) << endl;
        };
    };

    struct _menu {
    private:
        struct _item {
            _menu_runnable* pMr;
        };
        vector<_item> menuItems;
        struct _n_item {
            int n;
            _item item;
        };
        vector<_n_item> nItems;
    public:
        void add_item(_menu_runnable* pMenuRunnable, const string& name) {
            pMenuRunnable->name=name;
            menuItems.emplace_back(_item{pMenuRunnable});
        }
        void show() {
            cout << endl;
            int i=1;
            for (const _item& one_menu_item : menuItems) {
                cout << i << ") ";
                nItems.emplace_back(_n_item{i++, one_menu_item});
                cout << one_menu_item.pMr->name << endl;
            };
            cout << "Class 10(OD) menu: ";
            int selection;
            cin >> selection; cin.ignore();
            for (_n_item nI : nItems) {
                if(nI.n==selection) nI.item.pMr->runFromMenu();
            }
        };
    };
}
using namespace class_10_od;
int main() {
    std::cout << "khan_academy_math_study_notes (beta)" << std::endl;
    class_10_od::_speed velocity;
    class_10_od::_sin trigSin;
    class_10_od::_menu menu;
    menu.add_item(&velocity, "velocity");
    menu.add_item(&trigSin, "trigonometry sin");
    menu.show();
    return 0;
}
