#include <iostream>
#include <cmath>
#include <vector>
#ifdef VARIABLE_INCLUDE_standard
#include "standard.h"
#endif
#ifdef VARIABLE_INLUCDE_experimental
#include "experimental.h"
#endif
using namespace std;
namespace class_10_od {
    struct _menu_control {
        string name;
        static const int EXIT_PROGRAM;
        int control=EXIT_PROGRAM;
    };const int _menu_control::EXIT_PROGRAM=EXIT_SUCCESS;
    struct _menu_runnable : _menu_control {
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
            cout << "sin _n*x" << endl;
            cout << "_n: ";
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
            _item(nullptr_t pVoid) {

            }

        private:
            _menu_control* pMc;
        public:
            _menu_runnable* pMr;
            explicit _item(_menu_runnable* pMenuRunnable):pMr(pMenuRunnable) {
               pMc=nullptr;
            };
            explicit _item(_menu_control* pMenuControl):pMc(pMenuControl){
                pMr= nullptr;
            };
            [[nodiscard]] _menu_control * getPMc() const {return pMc;}
        };
        vector<_item> menuItems;
        struct _n_menu_item_showing {
        public:
            int _n;
            _item item = _item(nullptr);
            _n_menu_item_showing(int n, _menu_control* pMc): _n(n) {
                item=_item(pMc);
            };
        };
        vector<_n_menu_item_showing> nMenuItemsShowing;
        void _printItem(
                _menu_runnable* pMenuRunnable=nullptr,
                _menu_control* pMenuControl=nullptr) {
            if (nullptr==pMenuRunnable) {
                if (nullptr==pMenuControl) {
                    throw logic_error("Only one object pointer can be nullptr. ");
                } else {
                    bool contains=false;
                    int n;
                    for (_item mc : menuItems) {
                        if (mc.getPMc()==pMenuControl) {
                            contains=true;

                        }
                    }
                    if (contains) {

                    } else {
                        nMenuItemsShowing.emplace_back(_n_menu_item_showing(menuItems.size() + 1, pMenuControl));
                    }
                    cout << *pI << ") ";
                    cout << pMenuControl->name << endl;
                }
            } else {
                bool contains=false;
                for (_item mr : menuItems) {
                    if (mr.pMr==pMenuRunnable) {
                        contains=true;
                    }
                }
                if (contains) {

                } else {
                    nMenuItemsShowing.emplace_back(_n_menu_item_showing{*pI, _item(pMenuRunnable)});
                }
                cout << *pI << ") ";
                cout << pMenuRunnable->name << endl;
            }
        }
        void _printItem(_menu_control* pMenuControl) {
            _printItem(nullptr, pMenuControl);
        }
        void showItem(_menu_runnable* pMenuRunnable) {
            _printItem(pMenuRunnable);
        }
        void showItem(_menu_control* pMenuControl) {
            _printItem(pMenuControl);
        }
        using _exit_program = _menu_control;
    public:
        void add_exit_item() {
            _exit_program menuControl;
            menuControl.control=_menu_control::EXIT_PROGRAM;
            menuControl.name="exit";
            menuItems.emplace_back(_item(&menuControl));
        }
        void add_item(
                _menu_runnable* pMenuRunnable,
                const string& name,
                int _control_option = _menu_control::EXIT_PROGRAM) {
            pMenuRunnable->control=_control_option;
            pMenuRunnable->name=name;
            menuItems.emplace_back(_item(pMenuRunnable));
        }
        void show() {
            bool continueRunning = true;
            while (continueRunning) {
                cout << endl;
                for (const _item &one_menu_item: menuItems) {
                    if (nullptr==one_menu_item.pMr) {
                        showItem(one_menu_item.getPMc());
                    } else {
                        showItem(one_menu_item.pMr);
                    }
                }
                for (const _n_menu_item_showing &one_menu_n_item: nMenuItemsShowing) {
                    if (nullptr==one_menu_n_item.item.pMr) {
                        showItem(one_menu_n_item);
                    } else {
                        showItem(one_menu_n_item);
                    }
                }
                cout << "Class 10(OD) menu: ";
                int selection;
                cin >> selection; cin.ignore();
                for (_n_menu_item_showing nI: nMenuItemsShowing) {
                    if (nI._n == selection) {
                        if (nullptr == nI.item.pMr) {
                            continueRunning = false;
                        } else {
                            nI.item.pMr->runFromMenu();
                            continueRunning = true;
                        }
                    }
                }
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
    menu.add_exit_item();
    menu.show();
    return 0;
}
