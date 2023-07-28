LIST_COMPILE= Test_savemed_2D \
Test_savemed_3D  \
Test_savemed_3DS \
Test_savemed_3DC \
Test_loadmed_2D  \
Test_loadmed_3D  \
Test_loadmed_3DS \
Test_loadmed_3DC \
Test_redmedlabels_2D  \
Test_redmedlabels_3D  \
Test_loadmedfield_2D

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


#-----------------------------------------------------------------------
## Savemed testing 
#-----------------------------------------------------------------------

Test_savemed_2D: Test_savemed_2D.edp
	@echo "Test_savemed_2D : medio save test 2D"
	@$(FFMPI) -np 1 Test_savemed_2D.edp -v 1 > Test_savemed_2D.log
	@echo "  PASSED "

Test_savemed_3D: Test_savemed_3D.edp
	@echo "Test_savemed_3D : medio save test 3D"
	@$(FFMPI) -np 1 Test_savemed_3D.edp -v 1 > Test_savemed_3D.log
	@echo "  PASSED "

Test_savemed_3DS: Test_savemed_3DS.edp
	@echo "Test_savemed_3DS : medio save test 3DS"
	@$(FFMPI) -np 1 Test_savemed_3DS.edp -v 1 > Test_savemed_3DS.log
	@echo "  PASSED "

Test_savemed_3DC: Test_savemed_3DC.edp
	@echo "Test_savemed_3DC : medio save test 3DC"
	@$(FFMPI) -np 1 Test_savemed_3DC.edp -v 1 > Test_savemed_3DC.log
	@echo "  PASSED "

#-----------------------------------------------------------------------
## Loadmed testing 
#-----------------------------------------------------------------------

Test_loadmed_2D: Test_loadmed_2D.edp
	@echo "Test_loadmed_2D : medio load test 2D"
	@$(FFMPI) -np 1 Test_loadmed_2D.edp -v 1 > Test_loadmed_2D.log
	@echo "  PASSED "

Test_loadmed_3D: Test_loadmed_3D.edp
	@echo "Test_loadmed_3D : medio load test 3D"
	@$(FFMPI) -np 1 Test_loadmed_3D.edp -v 1 > Test_loadmed_3D.log
	@echo "  PASSED "

Test_loadmed_3DS: Test_loadmed_3DS.edp
	@echo "Test_loadmed_3DS : medio load test 3DS"
	@$(FFMPI) -np 1 Test_loadmed_3DS.edp -v 1 > Test_loadmed_3DS.log
	@echo "  PASSED "

Test_loadmed_3DC: Test_loadmed_3DC.edp
	@echo "Test_loadmed_3DC : medio load test 3DC"
	@$(FFMPI) -np 1 Test_loadmed_3DC.edp -v 1 > Test_loadmed_3DC.log
	@echo "  PASSED "

#-----------------------------------------------------------------------
## Redmedlabels testing 
#-----------------------------------------------------------------------

Test_redmedlabels_2D: Test_redmedlabels_2D.edp
	@echo "Test_redmedlabels_2D : redmedlabels load test 2D"
	@$(FFMPI) -np 1 Test_redmedlabels_2D.edp -v 1 > Test_redmedlabels_2D.log
	@echo "  PASSED "

Test_redmedlabels_3D: Test_redmedlabels_3D.edp
	@echo "Test_redmedlabels_3D : redmedlabels load test 3D"
	@$(FFMPI) -np 1 Test_redmedlabels_3D.edp -v 1 > Test_redmedlabels_3D.log
	@echo "  PASSED "


#-----------------------------------------------------------------------
## loadmedfile testing 
#-----------------------------------------------------------------------

Test_loadmedfield_2D: Test_loadmedfield_2D.edp
	@echo "Test_loadmedfield_2D : medio laod filed test 2D"
	@$(FFMPI) -np 1 Test_loadmedfield_2D.edp -v 1 > Test_loadmedfield_2D.log
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
