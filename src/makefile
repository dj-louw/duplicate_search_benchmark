#specify the compiler
CXX=g++ -std=c++0x


#########################################
##     Compilation Directives
#########################################

# all: 1-afile 2-ifile 3-quicksort 4-bstree-nodelete 5-bstree-withdelete 6-ofile 7-dfile	
# 	$(CXX) main.cpp -o bin/main.out

all:
	make 1-afile
	make 2-ifile
	make 3-quicksort
	make 4-bstree-nodelete
	make 5-bstree-withdelete
	make 6-ofile
	make 7-dfile

1-afile: init-afile
	$(CXX) 1-afile.cpp -o bin/1-afile.out

2-ifile: init-ifile
	$(CXX) 2-ifile.cpp -o bin/2-ifile.out

3-quicksort: init-quicksort
	$(CXX) 3-quicksort.cpp -o bin/3-quicksort.out

4-bstree-nodelete: init-bstree-nodelete
	$(CXX) 4-bstree-nodelete.cpp -o bin/4-bstree-nodelete.out

5-bstree-withdelete: init-bstree-withdelete
	$(CXX) 5-bstree-withdelete.cpp -o bin/5-bstree-withdelete.out

6-ofile: init-ofile
	$(CXX) 6-ofile.cpp -o bin/6-ofile.out	

7-dfile: init-dfile
	$(CXX) 7-dfile.cpp -o bin/7-dfile.out	


#########################################
##     Clean Directives
#########################################

clean-all:
	rm -rf bin/*	

clean-afile:
	rm bin/output/afile/*

clean-ifile:
	rm bin/output/ifile/*

clean-quicksort:
	rm bin/output/quicksort/*

clean-bstree-nodelete:
	rm bin/output/bstree-nodelete/*

clean-bstree-withdelete:
	rm bin/output/bstree-withdelete/*	

clean-ofile:
	rm bin/output/ofile/*

clean-dfile:
	rm bin/output/dfile/*



#########################################
##     Init Directives
#########################################

init-afile:
	mkdir -p bin/output/afile	

init-ifile:
	mkdir -p bin/output/ifile	

init-quicksort:
	mkdir -p bin/output/quicksort

init-bstree-nodelete:
	mkdir -p bin/output/bstree-nodelete

init-bstree-withdelete:
	mkdir -p bin/output/bstree-withdelete	

init-ofile:
	mkdir -p bin/output/ofile	

init-dfile:
	mkdir -p bin/output/dfile	