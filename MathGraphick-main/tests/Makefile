PREF_SRC = ../src/

all: test_save_lib save_lib error_proc_lib test_math_lib math_lib test_view_lib view_lib
	gcc -o tests main_test.c -L../src/save/save_test -L../src/save -I../src/save/save_test -l_save_test -l_save -L../src/error_proc -l_error_proc -L../src/math/math_test -L../src/math -I../src/math/math_test -l_math_test -l_math -L../src/view/test_view -L../src/view -I../src/view/test_view -l_test_view -l_view

test_save_lib:
	$(MAKE) -C ${PREF_SRC}save/save_test
	
save_lib:
	$(MAKE) -C ../src/save
	
error_proc_lib:
	$(MAKE) -C ../src/error_proc

test_math_lib:
	$(MAKE) -C ../src/math/math_test

math_lib:
	$(MAKE) -C ../src/math

test_view_lib:
	$(MAKE) -C ${PREF_SRC}view/test_view
	
view_lib:
	$(MAKE) -C ../src/view