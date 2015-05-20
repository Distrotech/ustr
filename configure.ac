dnl Process this file with autoconf to produce a configure script.

AC_INIT(ustr, 1.0.4, [james@and.org], , [http://www.and.org/ustr/])
AC_PREFIX_DEFAULT(/usr)

# checks for programs
AC_PROG_RANLIB
AC_CHECK_TOOLS(AR, [ar], false)
AC_PATH_PROG(LDCONFIG, [ldconfig], , ["$PATH:/sbin:/usr/sbin"])
# recent gcc with -Og ?
AX_CHECK_COMPILE_FLAG([-Og], [DBG_CFLAGS_OPT="-Og"], [DBG_CFLAGS_OPT="-O1"], [])

# checks for header files
AC_CHECK_HEADER([stdint.h], [HAVE_STDINT_H=1], [HAVE_STDINT_H=0])

# checks for types
AC_CHECK_SIZEOF([size_t])
test "$ac_cv_sizeof_size_t" -ge 8 && HAVE_64bit_SIZE_MAX=1 || HAVE_64bit_SIZE_MAX=0

# check if we are using GNU C Library
AC_MSG_CHECKING([GNU C library will be used])
AC_COMPILE_IFELSE([AC_LANG_SOURCE([[
#include <features.h>
int version = __GLIBC__;
	]])],
	[AC_MSG_RESULT([yes]); GLIBC_USED=1;],
	[AC_MSG_RESULT([no]); GLIBC_USED=0;])

# check if vsnprintf() is retarded
define([check_vsnprintf_retarded_code], [[AC_LANG_SOURCE([[
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>

static int my_autoconf(const char *fmt, ...)
{
  va_list ap;
  char buf[1] = "";
  int ret = -1;

  va_start(ap, fmt);
  ret = vsnprintf(buf, sizeof(buf), fmt, ap);
  va_end(ap);

  return (ret);
}

int main(void)
{
  if (my_autoconf("12") == -1) {
    puts("yes");
    return 1;
  } else {
    puts("no");
    return 0;
  }
}
	]])]])
AC_MSG_CHECKING([retarded vsnprintf()])
AC_RUN_IFELSE(check_vsnprintf_retarded_code,
	[HAVE_RETARDED_VSNPRINTF=0],
	[HAVE_RETARDED_VSNPRINTF=1],
	[
	  case 1 in
	    $GLIBC_USED)
		AC_MSG_RESULT([can't test, assume not retarted in GLibC])
		HAVE_RETARDED_VSNPRINTF=0
		;;
	    *)
		AC_MSG_FAILURE([can't test vsnprintf() when cross compiling])
		;;
	  esac
	]
)

AC_MSG_CHECKING([building Debian package])
test -f "$srcdir/debian/control" -a -f "$srcdir/debian/rules" \
    && dpkg --version >/dev/null 2>&1 \
    && debian_build=1
if test -n "$debian_build"
then
    AC_MSG_RESULT([yes])
    # We are building Debian based distro packages...
    SHRDIR=["$datadir/libustr-dev"]
    DOCSHRDIR=["$datadir/doc/libustr-doc"]
else
    AC_MSG_RESULT([no])
    # The rest of the world...
    SHRDIR=["$datadir/${PACKAGE_NAME}-${PACKAGE_VERSION}"]
    DOCSHRDIR=["$datadir/doc/${PACKAGE_NAME}-devel-${PACKAGE_VERSION}"]
fi


AC_SUBST([DBG_CFLAGS_OPT])
AC_SUBST([HAVE_STDINT_H])
AC_SUBST([HAVE_64bit_SIZE_MAX])
AC_SUBST([HAVE_RETARDED_VSNPRINTF])

# Compatibility vars
# versions
version_major=[$(echo $PACKAGE_VERSION | sed 's/^\([0-9]*\)\..*/\1/;')]
version_minor=[$(echo $PACKAGE_VERSION | sed 's/^[0-9]*\.\([0-9]*\)\..*/\1/;')]
version_release=[$(echo $PACKAGE_VERSION | sed 's/^[0-9]*\.[0-9]*\.\(.*\)/\1/;')]
AC_SUBST([version_major])
AC_SUBST([version_minor])
AC_SUBST([version_release])
# paths
EXAMDIR=["$DOCSHRDIR/examples"]
MBINDIR=["$libexecdir/${PACKAGE_NAME}-${PACKAGE_VERSION}"]
AC_SUBST([SHRDIR])
AC_SUBST([DOCSHRDIR])
AC_SUBST([EXAMDIR])
AC_SUBST([MBINDIR])


AC_CONFIG_FILES( [Makefile] )
AC_CONFIG_FILES( [ustr-conf.h ustr-conf-debug.h] )
AC_CONFIG_FILES( [ustr-import-multilib  ustr-import] )
AC_OUTPUT
