AUTOMAKE_OPTIONS = foreign

INCLUDES = -I$(top_srcdir)/kernel/include -I$(top_srcdir)/kernel/portable/GCC/RISC-V

lib_LTLIBRARIES = libfreertos.la

libfreertos_la_SOURCES = \
    kernel/event_groups.c kernel/list.c kernel/queue.c kernel/stream_buffer.c kernel/tasks.c kernel/timers.c \
    kernel/portable/MemMang/heap_3.c kernel/portable/GCC/RISC-V/port.c kernel/portable/GCC/RISC-V/portASM.S

if ENABLE_TESTS
bin_PROGRAMS = test
test_SOURCES = test.c
test_LDADD   = $(top_builddir)/libfreertos.la
endif

