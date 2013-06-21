
BUILDDIR := build
SRCDIR := src

all: builddir release

debug: builddir
	cd $(BUILDDIR); \
	cmake -DCMAKE_BUILD_TYPE=Debug ../$(SRCDIR); \
	make --no-print-directory 

release: builddir
	cd $(BUILDDIR); \
	cmake ../$(SRCDIR); \
	make --no-print-directory 
	
builddir:
	test -d $(BUILDDIR) || mkdir $(BUILDDIR)

run: builddir release
	./$(BUILDDIR)/exec/main

rundebug: builddir debug
	./$(BUILDDIR)/exec/main

clean:
	rm -rf $(BUILDDIR)/*
	
