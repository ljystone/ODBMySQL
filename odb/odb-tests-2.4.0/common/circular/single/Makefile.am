# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std circular-single-mysql-vc8.vcproj circular-single-sqlite-vc8.vcproj circular-single-pgsql-vc8.vcproj circular-single-oracle-vc8.vcproj circular-single-mssql-vc8.vcproj circular-single-mysql-vc9.vcproj circular-single-sqlite-vc9.vcproj circular-single-pgsql-vc9.vcproj circular-single-oracle-vc9.vcproj circular-single-mssql-vc9.vcproj circular-single-mysql-vc10.vcxproj circular-single-sqlite-vc10.vcxproj circular-single-pgsql-vc10.vcxproj circular-single-oracle-vc10.vcxproj circular-single-mssql-vc10.vcxproj circular-single-mysql-vc10.vcxproj.filters circular-single-sqlite-vc10.vcxproj.filters circular-single-pgsql-vc10.vcxproj.filters circular-single-oracle-vc10.vcxproj.filters circular-single-mssql-vc10.vcxproj.filters circular-single-mysql-vc11.vcxproj circular-single-sqlite-vc11.vcxproj circular-single-pgsql-vc11.vcxproj circular-single-oracle-vc11.vcxproj circular-single-mssql-vc11.vcxproj circular-single-mysql-vc11.vcxproj.filters circular-single-sqlite-vc11.vcxproj.filters circular-single-pgsql-vc11.vcxproj.filters circular-single-oracle-vc11.vcxproj.filters circular-single-mssql-vc11.vcxproj.filters circular-single-mysql-vc12.vcxproj circular-single-sqlite-vc12.vcxproj circular-single-pgsql-vc12.vcxproj circular-single-oracle-vc12.vcxproj circular-single-mssql-vc12.vcxproj circular-single-mysql-vc12.vcxproj.filters circular-single-sqlite-vc12.vcxproj.filters circular-single-pgsql-vc12.vcxproj.filters circular-single-oracle-vc12.vcxproj.filters circular-single-mssql-vc12.vcxproj.filters

noinst_PROGRAMS = driver
driver_SOURCES = driver.cxx  
LDADD = $(top_builddir)/libcommon/common/libcommon.la
AM_CPPFLAGS = -I'$(top_builddir)/libcommon' -I'$(top_srcdir)/libcommon'
AM_CPPFLAGS += -I'$(builddir)' -I'$(srcdir)'

TESTS=$(top_builddir)/tester
TESTS_ENVIRONMENT=top_builddir=$(top_builddir); export top_builddir;

# ODB compilation.
#
ODB = @ODB@
ODBFLAGS = @ODBFLAGS@
ODBCPPFLAGS = @ODBCPPFLAGS@

if HAVE_CXX11
ODBFLAGS += --std c++11
endif

nodist_driver_SOURCES =
BUILT_SOURCES =
CLEANFILES =

driver_SOURCES += test.hxx
nodist_driver_SOURCES += test-odb.cxx
BUILT_SOURCES += test-odb.hxx
CLEANFILES += test-odb.hxx test-odb.ixx test-odb.cxx

test-odb.hxx: test.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --table-prefix circular_s_ $<


