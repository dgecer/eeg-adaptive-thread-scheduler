CC = gcc

CFLAGS = -Wall

SRC = src/main.c src/eeg.c src/scheduler.c src/workload.c

OUT = eeg_scheduler

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run:
	./$(OUT)

clean:
	rm -f $(OUT)
