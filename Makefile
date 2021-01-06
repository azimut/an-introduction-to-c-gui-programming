PKGS=glib-2.0 gtk+-2.0
CFLAGS=-Wall -Wextra -std=c11 -pedantic `pkg-config --cflags $(PKGS)`
LDFLAGS=`pkg-config --libs $(PKGS)` -lm

14:
