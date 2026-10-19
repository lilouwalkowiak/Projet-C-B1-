#include <stdio.h>
#include "includes/rectangle.h"
#include "includes/ellipse.h"
#include "includes/line.h"

int main(void)
{
    rectangle_t *rectangle = ask_for_rectangle();

    print_rectangle(rectangle);
    modify_rectangle(rectangle);
    print_rectangle(rectangle);
    free_rectangle(rectangle);
    return 0;
}
