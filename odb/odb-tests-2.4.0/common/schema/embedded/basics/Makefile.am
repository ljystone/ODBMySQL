# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std schema-embedded-basics-mysql-vc8.vcproj schema-embedded-basics-sqlite-vc8.vcproj schema-embedded-basics-pgsql-vc8.vcproj schema-embedded-basics-oracle-vc8.vcproj schema-embedded-basics-mssql-vc8.vcproj schema-embedded-basics-mysql-vc9.vcproj schema-embedded-basics-sqlite-vc9.vcproj schema-embedded-basics-pgsql-vc9.vcproj schema-embedded-basics-oracle-vc9.vcproj schema-embedded-basics-mssql-vc9.vcproj schema-embedded-basics-mysql-vc10.vcxproj schema-embedded-basics-sqlite-vc10.vcxproj schema-embedded-basics-pgsql-vc10.vcxproj schema-embedded-basics-oracle-vc10.vcxproj schema-embedded-basics-mssql-vc10.vcxproj schema-embedded-basics-mysql-vc10.vcxproj.filters schema-embedded-basics-sqlite-vc10.vcxproj.filters schema-embedded-basics-pgsql-vc10.vcxproj.filters schema-embedded-basics-oracle-vc10.vcxproj.filters schema-embedded-basics-mssql-vc10.vcxproj.filters schema-embedded-basics-mysql-vc11.vcxproj schema-embedded-basics-sqlite-vc11.vcxproj schema-embedded-basics-pgsql-vc11.vcxproj schema-embedded-basics-oracle-vc11.vcxproj schema-embedded-basics-mssql-vc11.vcxproj schema-embedded-basics-mysql-vc11.vcxproj.filters schema-embedded-basics-sqlite-vc11.vcxproj.filters schema-embedded-basics-pgsql-vc11.vcxproj.filters schema-embedded-basics-oracle-vc11.vcxproj.filters schema-embedded-basics-mssql-vc11.vcxproj.filters schema-embedded-basics-mysql-vc12.vcxproj schema-embedded-basics-sqlite-vc12.vcxproj schema-embedded-basics-pgsql-vc12.vcxproj schema-embedded-basics-oracle-vc12.vcxproj schema-embedded-basics-mssql-vc12.vcxproj schema-embedded-basics-mysql-vc12.vcxproj.filters schema-embedded-basics-sqlite-vc12.vcxproj.filters schema-embedded-basics-pgsql-vc12.vcxproj.filters schema-embedded-basics-oracle-vc12.vcxproj.filters schema-embedded-basics-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --schema-format embedded --schema-name test --table-prefix schema_embd_bscs_ $<


