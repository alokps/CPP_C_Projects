#include <stdlib.h>
#include <check.h>
#include "../src/Roman_Neumerals.h"


START_TEST (test_roman_add)
{
  char str1[][10] = {"mMD","IVL"};
  ck_assert_str_eq (AddRomanNeumerals (str1[0],str1[1]), "MMDXLVI");
}
END_TEST

START_TEST (test_roman_sub)
{
  char str1[][10] = {"mMD","IVL"};
  ck_assert_str_eq (SubRomanNeumerals (str1[0],str1[1]), "MMCDLIV");
}
END_TEST

START_TEST (test_roman_null)
{
  char str1[][10] = {"mMD","\0"};
  ck_assert_str_eq (SubRomanNeumerals (str1[0],str1[1]), str1[0]);
}
END_TEST

START_TEST (test_invalid_sub)
{
  char str1[][10] = {"IvL","mMD"};
  ck_assert_str_eq (SubRomanNeumerals (str1[0],str1[1]), "\0");
}
END_TEST

Suite* roman_suite (void)
{
  Suite *s = suite_create ("Roman");

  /* Core test case */
  TCase *tc_core = tcase_create ("Core");
  tcase_add_test (tc_core, test_roman_add);
  tcase_add_test (tc_core, test_roman_sub);
  suite_add_tcase (s, tc_core);

  /* Abnormal test case*/  
  TCase *tc_abnormal = tcase_create ("Abnormal");
  tcase_add_test (tc_abnormal, test_roman_null);
  tcase_add_test (tc_abnormal, test_invalid_sub);
  suite_add_tcase (s, tc_abnormal);

  return s;
}

int main (void)
{
  int number_failed;
  Suite *s = roman_suite ();
  SRunner *sr = srunner_create (s);
  srunner_run_all (sr, CK_NORMAL);
  number_failed = srunner_ntests_failed (sr);
  srunner_free (sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
