PKGS=gtk+-2.0
CFLAGS=-Wall -Wextra -std=c11 -pedantic `pkg-config --cflags $(PKGS)`
LDFLAGS=`pkg-config --libs $(PKGS)` -lm

.PHONY: rtags
rtags:
	bear --append make all
	rc -J .

.PHONY: clean
clean:
	find . -maxdepth 1 -executable -type f -delete

.clang-format:
	clang-format -style=llvm -dump-config > .clang-format

.PHONY: all
all: .clang-format 14helloworld 15button 15signals 16boxnlabels 16updatelabel 17expandfill 17tables 18check 18radio 18spin 18text 19combobox 19liststores

