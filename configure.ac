#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([ipcam-ftest], [1.0.0], [chenk@apical.com.cn])

AC_CONFIG_SRCDIR([test.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])

AM_INIT_AUTOMAKE([subdir-objects])

# Checks for programs.
AC_PROG_CC
AM_PROG_AS
AC_PROG_LIBTOOL

# Checks for pkg-config
PKG_PROG_PKG_CONFIG

CFLAGS="-std=gnu99 -Os -g -Wall -Werror -Wno-strict-aliasing -funwind-tables -ffunction-sections -fdata-sections"
LDFLAGS="--specs=picolibc.specs -Tfreertos.ld"

# Checks for Optional Features
AC_ARG_ENABLE(debug, [AS_HELP_STRING([--enable-debug], [enable debug mode [default=no]])], [], [debug=no])
AM_CONDITIONAL([ENABLE_DEBUG], [test x"$enable_debug" = x"yes"])

AC_ARG_ENABLE(tests, [AS_HELP_STRING([--enable-tests], [enable test programs [default=no]])], [], [tests=no])
AM_CONDITIONAL([ENABLE_TESTS], [test x"$enable_tests" = x"yes"])

AC_OUTPUT

