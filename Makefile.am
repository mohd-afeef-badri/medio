SUBDIRS = ext src test

AUTOMAKE_LIST=autom4te.cache \
config.h \
config.status \
configure \
compile \
depcomp  \
install-sh \
missing \
Makefile \
Makefile.in \
aclocal.m4 \
config.h.in \
config.log \
stamp-h1 \
.swp

all-local:
	@echo ""
	@echo "*============================================================*"
	@echo " medio version 1.0 compilation successfully done"
	@echo ""
	@echo " In order to use medio please ensure to edit LD_LIBRARY_PATH"
	@echo " use the following"
	@echo ""
if HAVEMED
	@echo ' export LD_LIBRARY_PATH=$$LD_LIBRARY_PATH:$(hdf5)/lib:$(medfile)/lib:$(medcoupling)/lib'
else !HAVEMED
	@echo ' export LD_LIBRARY_PATH=$$LD_LIBRARY_PATH:$(MEDIO_HDF5_DIR)/lib:$(MEDIO_MEDFILE_DIR)/lib:$(MEDIO_MEDCOUPLING_DIR)/lib'
endif
	@echo ""
	@echo " medio can be used in FreeFEM .edp scripts via the line"
	@echo ""
	@echo '  load "$(prefix)/lib/medio";'
	@echo ""
	@echo "*============================================================*"
	@echo ""

clean-local:
	@echo ""
	@echo "*============================================================*"
	@echo " Cleaning files in :"; pwd
	@echo "*============================================================*"
	@echo ""
	rm  -f *~


maintainer-clean-local: clean-local
	@echo ""
	@echo "*============================================================*"
	@echo " Cleaning automake generated files"
	@echo "*============================================================*"
	@echo ""
	rm  -rf Makefile Makefile.in
	rm  -rf $(AUTOMAKE_LIST)
