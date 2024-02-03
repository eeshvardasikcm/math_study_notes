#include <iostream>
#include <cmath>
#include <utility>
#include <vector>
#include <cstdint>
#ifdef VARIABLE_INCLUDE_standard
#include "standard.h"
#endif
#ifdef VARIABLE_INLUCDE_experimental
#include "experimental.h"
#endif
namespace study_notes {
    struct menuControl {
    };

    struct menuRunnable : menuControl {
        virtual void inputVariables() {};
        void runFromMenu() {
            inputVariables();
        };
    };

    struct point {
        float x;
        float y;
    };

    struct line {
    };

    struct unitOfMeasure {
    private:
    public:
        static const std::string km;
        static const std::string hr;
        static std::string kmPerH() {
            std::basic_string bs = " " + km + "/" + unitOfMeasure::hr + " ";
            return bs;
        };
    };
    const std::string unitOfMeasure::km = "km";
    const std::string unitOfMeasure::hr = "hour";

    struct speed : menuRunnable {private:
        float v=static_cast<float>(0);
        void calculate(float kilometers, float hours) {
            v = kilometers / hours;
        };
        [[nodiscard]] std::string getV() const {
            std::string s=std::to_string(v)
                    .append(unitOfMeasure::kmPerH());
            return s;
        };
        void inputVariables() override  {
            std::cout << "distance(" << unitOfMeasure::km << "): ";
            float d;
            std::cin >> d; (void)std::cin.ignore();
            std::cout << "time(" << unitOfMeasure::hr << "): ";
            float t;
            std::cin >> t; (void)std::cin.ignore();
            calculate(d,t);
            std::cout << getV() << std::endl;
        }
    };

    struct lineFormula {
#ifdef VARIABLE_INLUCDE_experimental
        point _equation_1(float x, float y, float xn=11, float yn=65) {
            return point((float _f1(*(x)))*(xn), (float _f2(*(y)))*(yn));
        }

        point intersect(line l1, lineFormula l2) {

        }
#endif
    };

    struct trigSin : menuRunnable {
        static double nx(double n, double x) {
            return sin(n*x);
        }
        void inputVariables() override {
            std::cout << "sin n*x" << std::endl;
            std::cout << "n: ";
            float n;
            std::cin >> n; (void)std::cin.ignore();
            std::cout << "x: ";
            float x;
            std::cin >> x; (void)std::cin.ignore();
            std::cout << "sin " << n << "x, ";
            std::cout << "where x=" << x << " is equal to: ";
            std::cout << nx(n,x) << std::endl;
        };
    };

    struct menu {
    private:
        struct menuItem {
        private:
            int n;
            std::string name;
            menuControl* pMc;
            menuRunnable* pMr;
        public:
            static int totalCreated;
            explicit menuItem(std::string name, menuRunnable* pMenuRunnable):
            pMr(pMenuRunnable), name(std::move(name)) {
               pMc=nullptr;
               totalCreated++;
               n=totalCreated;
            };
            explicit menuItem(std::string name, menuControl* pMenuControl):
            pMc(pMenuControl), name(std::move(name)) {
                pMr= nullptr;
                totalCreated++;
                n=totalCreated;
            };
            [[nodiscard]] menuControl * getPMc() const {return pMc;}
            [[nodiscard]] menuRunnable * getPMr() const {return pMr;}
            [[nodiscard]] int getN() const {return n;}
            [[nodiscard]] std::string getName() {return name;}
        };
        std::vector<menuItem> menuItems;
        std::vector<menuItem> nMenuItemsShowing;
        static void drawItemOnMenu(menuItem shownMenuItem) {
            int n = shownMenuItem.getN();
            std::cout << n << ") ";
            std::cout << shownMenuItem.getName() << std::endl;
        }
    public:
        void addExitItem() {
            menuControl mc;
            menuItem newItem("exit", &mc);
            menuItem shownMenuItem = nMenuItemsShowing.emplace_back(newItem);
            if (shownMenuItem.getPMc() != &mc) {
                throw std::logic_error("control style menu item was "
                                       "not added to the list of"
                                       "created menu items properly.");
            }
        }
        void addItem(menuRunnable *pMenuRunnable, const std::string &name) {
            menuItem newItem(name, pMenuRunnable);
            menuItem shownMenuItem = nMenuItemsShowing.emplace_back(newItem);
            if (shownMenuItem.getPMr()!=pMenuRunnable) {
                throw std::logic_error("runnable style menu item was "
                                       "not added to the list of"
                                       "created menu items properly.");
            }
        }
        void show() {
            bool continueRunning = true;
            while (continueRunning) {
                std::cout << std::endl;
                for (const menuItem& oneMenuItem: nMenuItemsShowing) {
                    drawItemOnMenu(oneMenuItem);
                }
                std::cout << "study notes menu: ";
                int selection;
                std::cin >> selection; (void)std::cin.ignore();
                for (const menuItem& nI: nMenuItemsShowing) {
                    if (nI.getN() == selection) {
                        if (nullptr == nI.getPMr()) {
                            continueRunning = false;
                        } else {
                            nI.getPMr()->runFromMenu();
                            continueRunning = true;
                        }
                    }
                }
            }
        };
    };
    int menu::menuItem::totalCreated=0;
}


int main() {
    std::cout << "khan_academy_math_study_notes (beta)" << std::endl;
    study_notes::speed velocity;
    study_notes::trigSin trigSin;
    study_notes::menu menu;
    menu.addItem(&velocity, "velocity");
    menu.addItem(&trigSin, "trigonometry sin");
    menu.addExitItem();
    menu.show();
    return 0;
}
