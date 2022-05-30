#include "stack.h"
#include <stdlib.h>
#include <time.h>
#include <check.h>

START_TEST(test_init)
{
    int len = 8;
    stack_t* s = newStack(int, len);
    ck_assert(s->_size == sizeof(int) && s->len == len);
}
END_TEST


START_TEST(test_push_and_pop_even)
{
    long var;
    int len = 24;
    long* additional = malloc(sizeof(long) * 2 * len);
    bool result = 1;

    stack_t* s = newStack(long, len);
    for (int i = 0; i < 48; i++) {
        var = rand();
        pushStack(s, &var);
        additional[i] = var;
    }
    for (int i = 47; i > -1; i--) {
        result &= additional[i] == *(long*) popStack(s);
    }
    free(additional);
    ck_assert(result);
}
END_TEST


START_TEST(test_push_and_pop_odd)
{
    long var;
    int len = 3;
    int f_len = 100;
    long* additional = malloc(sizeof(long) * 2 * f_len);
    bool result = 1;
    srand(time(NULL));
    stack_t* s = newStack(long, len);
    for (int i = 0; i < f_len; i++) {
        var = rand();
        pushStack(s, &var);
        additional[i] = var;
    }
    for (int i = f_len - 1; i >= 0; i--) {
        result &= additional[i] == *(long*) popStack(s);
    }
    free(additional);
    ck_assert(result);
}
END_TEST


Suite* stack_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Stack");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_init);
    tcase_add_test(tc_core, test_push_and_pop_even);
    tcase_add_test(tc_core, test_push_and_pop_odd);
    suite_add_tcase(s, tc_core);

    return s;
}


int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = stack_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}