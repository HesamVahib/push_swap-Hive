#include "push_swap.h"

void    current_index_median(t_stack_elem *stack)
{
    int i;
    int median;

    i = 0;
    if (!stack)
        return ;
    median = ft_lstsize(stack) / 2;
    while (stack)
    {
        stack->index = i;
        if (i <= median)
            stack->above_median = true;
        else
            stack->above_median = false;
        stack = stack->next;
        i++; //++i used to be
    }
}

static void set_target_a(t_stack_elem *stack_a, t_stack_elem *stack_b) // here we are setting the target for each element of a
{
    t_stack_elem    *current_b;
    t_stack_elem    *target_elem;
    long            match_index; // to check and control if a is not the biggest one or something

    while (stack_a) // for each a--
    {
        match_index = LONG_MIN;
        current_b = stack_b;
        while (current_b) // -- to address b
        {
            if (current_b->value < stack_a->value && current_b->value > match_index)
            {
                match_index = current_b->value;
                target_elem = current_b;
            }
            current_b = current_b->next;
        }
        if (match_index == LONG_MIN)
            stack_a->target_elem = find_max(stack_b); // in stack_utils
        else
            stack_a->target_elem = target_elem;
        stack_a = stack_a->next;
    }
}

static void cost_to_push_a(t_stack_elem *stack_a, t_stack_elem *stack_b)
{
    int len_a;
    int len_b;

    len_a = ft_lstsize(stack_a);
    len_b = ft_lstsize(stack_b);
    while (stack_a)
    {
        stack_a->push_cost = stack_a->index; // lets say index is 10
        if (!(stack_a->above_median))
            stack_a->push_cost = len_a - (stack_a->index); // if median is 15 so the cost is 15 - 10
        if (stack_a->target_elem->above_median) // plus b moves
            stack_a->push_cost += stack_a->target_elem->index; // go through the target element in b which has index
        else
            stack_a->push_cost += len_b - (stack_a->target_elem->index); // same rule for element b which is below median
        stack_a = stack_a->next;
    }
}

void    find_cheapest(t_stack_elem  *stack)
{
    long            cheapest_value;
    t_stack_elem   *cheapest_elem;

    if (!stack)
        return ;
    cheapest_elem = NULL;
    cheapest_value = LONG_MAX;
    while (stack)
    {
        if (stack->push_cost < cheapest_value)
        {
            cheapest_value = stack->push_cost;
            cheapest_elem = stack;
        }
        stack = stack->next;
    }
    cheapest_elem->cheapest = true; // just one element is the cheapest one
}

void    init_elems_a(t_stack_elem *stack_a, t_stack_elem *stack_b)
{
    current_index_median(stack_a); // here
    current_index_median(stack_b);
    set_target_a(stack_a, stack_b); // here
    cost_to_push_a(stack_a, stack_b); // here
    find_cheapest(stack_a);
}

// dar haghighat inja aval oomad somare gozari kard har kodom ro bad goft a hazinash vase har element cheghadre k bekhad bere b k n bar in asas bood k vase har a y target gozasht k khodesh y elemente dar haghighat. hala goft agar in elemnt dar hahighat koochitar az value e a bood pas mishe targetesh. dar gheire in soorat mizarimesh rooye bozorgtarin (manteghiam hast in yani elemane a koochiktarin mishe  pas mishe targetam bozorgtarine b). bad goft hala har kodom chghad hazine dare vasash k bekhad bere oonvar, bar in asas k cheghad az top door tare v hamino baraye b k b inja hamun target elemente va dar nahayat inaro baham jam kard v esmesho gozasht cost e push. hala oomad goft kodom yeki azina kamtarin cost ro dare k esmesho gozasht cheapest one k boolean e cheapest ro TRUE kard oonja.