UNIT_TESTS = \
mcUT1.hpp \
mcUT2.hpp \
mcUT3.hpp \
mcUT4.hpp \
mcUT5.hpp \
mcUT6.hpp \
mcUT7.hpp \
mcUT8.hpp \
mcUT9.hpp

all-local: MedCoupling_Test
	@echo ""


check-local:
	@echo ""
	@echo "*============================================================*"
	@echo " Checking medcoupling unit tests : RUNNING                      "
	@echo "*============================================================*"
	@echo ""

MedCoupling_Test: MedCoupling_Test.o
	@echo "MedCoupling unit tests"
	$(CXX) MedCoupling_Test.cpp $(CXXFLAGS_MED)  $(LDFLAGS_MED) $(LIBS_MED)  -DMEDCOUPLING -o MedCoupling_Test
	@echo ""


MedCoupling_Test.o: MedCoupling_Test.cpp $(UNIT_TESTS)
	@echo "MedCoupling unit tests"
	$(CXX) -c MedCoupling_Test.cpp $(CXXFLAGS_MED)  $(LDFLAGS_MED) $(LIBS_MED)  -DMEDCOUPLING
	@echo ""

clean-local:
	@echo ""
	@echo "*============================================================*"
	@echo " Cleaning files in :"; pwd
	@echo "*============================================================*"
	@echo ""
	rm  -f *~ *.mesh *.pvd *.vtu *.pvtu *.info *.pdf *.xyz *.dat *.gnu *.med
	rm  -f *~ *.log *.out *.txt MedCoupling_Test MedCoupling_Test.o


maintainer-clean-local: clean-local
	@echo ""
	@echo "*============================================================*"
	@echo " Cleaning automake generated files"
	@echo "*============================================================*"
	@echo ""
	rm  -rf Makefile Makefile.in
