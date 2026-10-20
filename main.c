#include <stdio.h>
#include "includes/rectangle.h"
#include "includes/ellipse.h"
#include "includes/line.h"
#include "includes/shape.h"

int main(void)
{
    shape_t *shape = ask_for_shape(SHAPE_RECTANGLE);

    print_shape(shape);
    modify_shape_content(shape);
    print_shape(shape);
    free_shape(shape);
    return 0;
}
