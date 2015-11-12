CC=gcc
OUT=run
SRCs=$(wildcard *.c)

run: $(SRCs)
	$(CC) -o $(OUT) $^
clean:
	rm $(OUT)
