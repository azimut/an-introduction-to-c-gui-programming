PKGS=gtk+-2.0
CFLAGS=-Wall -Wextra -std=c11 -pedantic `pkg-config --cflags $(PKGS)`
LDFLAGS=`pkg-config --libs $(PKGS)` -lm

14:
15:
15v2:


.PHONY: clear
clear:
	find . -maxdepth 1 -executable -type f -delete
