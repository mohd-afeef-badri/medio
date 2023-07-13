LIST_COMPILE= Test_1 \
Test_2

all-local:
	@echo ""

check-local: check-header $(LIST_COMPILE)
	@echo ""
	@echo "*============================================================*"
	@echo " Checking medio plugin : SUCCESS                      "
	@echo "*============================================================*"
	@echo ""

check-header:
	@echo ""
	@echo "*============================================================*"
	@echo " Checking medio plugin : RUNNING                      "
	@echo "*============================================================*"
	@echo ""

Test_1: Test_1.edp
	@echo "Test_1 : medio save test"
	@$(FFMPI) -np 1 Test_1.edp -v 1 >  Test_1.log
	@echo "  PASSED "

Test_2: Test_2.edp
	@echo "Test_2 : medio load test"
	@$(FFMPI) -np 1 Test_2.edp -v 1 >  Test_2.log
	@echo "  PASSED "


clean-local:
	@echo ""
	@echo "*============================================================*"
	@echo " Cleaning files in :"; pwd
	@echo "*============================================================*"
	@echo ""
	rm  -f *~ *.mesh *.pvd *.vtu *.pvtu *.info *.pdf *.xyz *.dat *.gnu *.med
	rm  -f *~ *.log *.out *.txt


maintainer-clean-local: clean-local
	@echo ""
	@echo "*============================================================*"
	@echo " Cleaning automake generated files"
	@echo "*============================================================*"
	@echo ""
	rm  -rf Makefile Makefile.in
