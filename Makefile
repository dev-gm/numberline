CC=gcc
INSTALL_DIR=/usr/local/bin
OUT=numberline
SRC=numberline.c

$(OUT):
	gcc -o $(OUT) $(SRC)

.PHONY: clean install

clean:
	rm $(OUT)

install:
	make && sudo cp OUT $(INSTALL_DIR)/$(OUT)
