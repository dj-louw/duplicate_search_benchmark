#specify the compiler
CXX=g++ -std=c++0x


#########################################
##     Compilation Directives
#########################################
# all: init	
# 	$(CXX) main.cpp -o bin/main.out

afile: init-afile
	$(CXX) 1-afile.cpp -o bin/afile.out

ifile:
	$(CXX) 2-ifile.cpp -o bin/ifile.out

quicksort:
	$(CXX) 3-quicksort.cpp -o bin/quicksort.out

bstree-nodelete:
	$(CXX) 4-bstree-nodelete.cpp -o bin/bstree-nodelete.out

bstree-withdelete:	
	$(CXX) bstree-withdelete.cpp -o bin/bstree-withdelete.out

ofile:
	$(CXX) ofile.cpp -o bin/ofile.out	

dfile:
	$(CXX) dfile.cpp -o bin/dfile.out	


#########################################
##     Clean Directives
#########################################

# clean:
# 	rm -rf bin/*	

clean-afile:
	rm bin/output/afile/*




#########################################
##     Init Directives
#########################################

init-afile:
	mkdir -p bin/output/afile	

