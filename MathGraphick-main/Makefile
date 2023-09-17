all: _save_test.a _math_test.a
	gcc -o main src/main.c -Isrc/save -l_save -Lsrc/save -Isrc/error_proc -l_error_proc -Lsrc/error_proc -Isrc/math -l_math -Lsrc/math -Isrc/view -l_view -Lsrc/view
	
_save_test.a _math_test.a _test_view.a:
	$(MAKE) -C tests
