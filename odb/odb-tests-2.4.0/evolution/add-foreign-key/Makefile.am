# file      : evolution/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = add-foreign-key-mysql-vc8.vcproj add-foreign-key-sqlite-vc8.vcproj add-foreign-key-pgsql-vc8.vcproj add-foreign-key-oracle-vc8.vcproj add-foreign-key-mssql-vc8.vcproj add-foreign-key-mysql-vc9.vcproj add-foreign-key-sqlite-vc9.vcproj add-foreign-key-pgsql-vc9.vcproj add-foreign-key-oracle-vc9.vcproj add-foreign-key-mssql-vc9.vcproj add-foreign-key-mysql-vc10.vcxproj add-foreign-key-sqlite-vc10.vcxproj add-foreign-key-pgsql-vc10.vcxproj add-foreign-key-oracle-vc10.vcxproj add-foreign-key-mssql-vc10.vcxproj add-foreign-key-mysql-vc10.vcxproj.filters add-foreign-key-sqlite-vc10.vcxproj.filters add-foreign-key-pgsql-vc10.vcxproj.filters add-foreign-key-oracle-vc10.vcxproj.filters add-foreign-key-mssql-vc10.vcxproj.filters add-foreign-key-mysql-vc11.vcxproj add-foreign-key-sqlite-vc11.vcxproj add-foreign-key-pgsql-vc11.vcxproj add-foreign-key-oracle-vc11.vcxproj add-foreign-key-mssql-vc11.vcxproj add-foreign-key-mysql-vc11.vcxproj.filters add-foreign-key-sqlite-vc11.vcxproj.filters add-foreign-key-pgsql-vc11.vcxproj.filters add-foreign-key-oracle-vc11.vcxproj.filters add-foreign-key-mssql-vc11.vcxproj.filters add-foreign-key-mysql-vc12.vcxproj add-foreign-key-sqlite-vc12.vcxproj add-foreign-key-pgsql-vc12.vcxproj add-foreign-key-oracle-vc12.vcxproj add-foreign-key-mssql-vc12.vcxproj add-foreign-key-mysql-vc12.vcxproj.filters add-foreign-key-sqlite-vc12.vcxproj.filters add-foreign-key-pgsql-vc12.vcxproj.filters add-foreign-key-oracle-vc12.vcxproj.filters add-foreign-key-mssql-vc12.vcxproj.filters

noinst_PROGRAMS = driver
driver_SOURCES = driver.cxx  model.hxx
LDADD = $(top_builddir)/libcommon/common/libcommon.la
AM_CPPFLAGS = -I'$(top_builddir)/libcommon' -I'$(top_srcdir)/libcommon'
AM_CPPFLAGS += -I'$(builddir)' -I'$(srcdir)'

TESTS=$(top_builddir)/evolution/tester
TESTS_ENVIRONMENT=top_builddir=$(top_builddir); export top_builddir;

ODB = @ODB@
ODBFLAGS = @ODBFLAGS@
ODBCPPFLAGS = @ODBCPPFLAGS@

if HAVE_CXX11
ODBFLAGS += --std c++11
endif

# test1.hxx
#
driver_SOURCES += test1.hxx
nodist_driver_SOURCES = test1-odb.cxx
BUILT_SOURCES = test1-odb.hxx
CLEANFILES = test1-odb.hxx test1-odb.ixx test1-odb.cxx test1.sql model.xml

test1-odb.hxx: test1.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-query --generate-schema --at-once --fkeys-deferrable-mode not_deferrable --table-prefix evo_add_fk_ --init-changelog --changelog model.xml $<

# test2.hxx
#
driver_SOURCES += test2.hxx
nodist_driver_SOURCES += test2-odb.cxx
BUILT_SOURCES += test2-odb.hxx
CLEANFILES += test2-odb.hxx test2-odb.ixx test2-odb.cxx test2.sql

test2-odb.hxx: test2.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-query --generate-schema --at-once --fkeys-deferrable-mode not_deferrable --table-prefix evo_add_fk_ --omit-create --suppress-migration --changelog model.xml $<

# test3.hxx
#
driver_SOURCES += test3.hxx
nodist_driver_SOURCES += test3-odb.cxx
BUILT_SOURCES += test3-odb.hxx
CLEANFILES += test3-odb.hxx test3-odb.ixx test3-odb.cxx test3.sql \
test3-002-pre.sql test3-002-post.sql test3-003-pre.sql test3-003-post.sql

test3-odb.hxx: test3.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-query --generate-schema --at-once --fkeys-deferrable-mode not_deferrable --table-prefix evo_add_fk_ --omit-create --changelog model.xml $<

# Make sure testN.hxx are compiled serially since they share the
# changelog. Also add dependency on model.hxx
#
test2-odb.hxx: test1-odb.hxx
test3-odb.hxx: test2-odb.hxx
test1-odb.hxx test2-odb.hxx test3-odb.hxx: model.hxx
