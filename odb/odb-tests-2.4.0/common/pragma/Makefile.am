# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std pragma-mysql-vc8.vcproj pragma-sqlite-vc8.vcproj pragma-pgsql-vc8.vcproj pragma-oracle-vc8.vcproj pragma-mssql-vc8.vcproj pragma-mysql-vc9.vcproj pragma-sqlite-vc9.vcproj pragma-pgsql-vc9.vcproj pragma-oracle-vc9.vcproj pragma-mssql-vc9.vcproj pragma-mysql-vc10.vcxproj pragma-sqlite-vc10.vcxproj pragma-pgsql-vc10.vcxproj pragma-oracle-vc10.vcxproj pragma-mssql-vc10.vcxproj pragma-mysql-vc10.vcxproj.filters pragma-sqlite-vc10.vcxproj.filters pragma-pgsql-vc10.vcxproj.filters pragma-oracle-vc10.vcxproj.filters pragma-mssql-vc10.vcxproj.filters pragma-mysql-vc11.vcxproj pragma-sqlite-vc11.vcxproj pragma-pgsql-vc11.vcxproj pragma-oracle-vc11.vcxproj pragma-mssql-vc11.vcxproj pragma-mysql-vc11.vcxproj.filters pragma-sqlite-vc11.vcxproj.filters pragma-pgsql-vc11.vcxproj.filters pragma-oracle-vc11.vcxproj.filters pragma-mssql-vc11.vcxproj.filters pragma-mysql-vc12.vcxproj pragma-sqlite-vc12.vcxproj pragma-pgsql-vc12.vcxproj pragma-oracle-vc12.vcxproj pragma-mssql-vc12.vcxproj pragma-mysql-vc12.vcxproj.filters pragma-sqlite-vc12.vcxproj.filters pragma-pgsql-vc12.vcxproj.filters pragma-oracle-vc12.vcxproj.filters pragma-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --table-prefix pragma_ $<


