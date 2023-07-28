LIST_COMPILE= medio.cpp

DEP1 = medio.$(SO_SUFFIX)

all-local: $(DEP1)
	@echo ""
	@echo "*============================================================*"
	@echo " Compilation done in :"; pwd
	@echo "*============================================================*"
	@echo ""
	@echo " Compilation list $(LIST_COMPILE)"

$(DEP1): medio.cpp medio.hpp medioSaveMedMesh.hpp medioLoadMedMesh.hpp medioLoadMedField.hpp medioGetGroupLabel.hpp
	$(FFCXX) -auto medio.cpp $(CXXFLAGS_MED)  $(LDFLAGS_MED) $(LIBS_MED) -DMEDCOUPLING

install-exec-local:
	@mkdir -p ${prefix}
	@mkdir -p ${prefix}/lib
	@cp $(DEP1) ${prefix}/lib/$(DEP1)

clean-local:
	@echo ""
	@echo "*============================================================*"
	@echo " Cleaning files in :"; pwd
	@echo "*============================================================*"
	@echo ""
	rm  -f *~  *.$(SO_SUFFIX) *.o


maintainer-clean-local: clean-local
	@echo ""
	@echo "*============================================================*"
	@echo " Cleaning automake generated files"
	@echo "*============================================================*"
	@echo ""
	rm  -rf Makefile Makefile.in
