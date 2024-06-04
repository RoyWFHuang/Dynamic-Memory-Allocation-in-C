
MM_MGMT = free.c calloc.c malloc.c realloc.c
MM_MGMT_LIB = $(MM_MGMT)
MM_MGMT_LIB_NAME = libmm.so
MM_MGMT_LIB_AR_NAME = libmm_ar.a
INCLUDE_DIR = \
-Iinclude

all: lib glibc my_mm

lib:
	$(CC) -c $(MM_MGMT_LIB) $(INCLUDE_DIR)
	ar -r $(MM_MGMT_LIB_AR_NAME) *.o
	$(CC) -c $(MM_MGMT_LIB) $(INCLUDE_DIR) -fPIC
	gcc -shared -o $(MM_MGMT_LIB_NAME) *.o
	rm -rf *.o

clean:
	rm -rf *.o $(MM_MGMT_LIB_NAME) $(MM_MGMT_LIB_AR_NAME)

glibc:
	gcc main.c -o glib_test

my_mm: lib
	gcc main.c -DMY_MM -I. -L. -lmm -o my_mm_test

check: lib my_mm glibc
	@echo "run glibc"
	./glib_test
	@echo "run self define"
	ldd my_mm_test
	LD_LIBRARY_PATH=./:$$LD_LIBRARY_PATH ./my_mm_test
distclean: clean

.PHONY: all clean lib glibc
