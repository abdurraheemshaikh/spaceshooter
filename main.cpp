#include "menu.h"
int main()
{	int ship=1;
	int bullet=1;

    Menu m;
    m.Startmenu(ship,bullet);
    m.display_menu(ship,bullet);
    return 0;
}
