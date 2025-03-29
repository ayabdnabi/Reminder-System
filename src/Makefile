all: reminders

reminders: main.o reminder.o linked_list.o interact.o
	gcc -g -Wall -o reminders main.o reminder.o linked_list.o interact.o

main.o: main.c reminder.h interact.h
	gcc -g -Wall -c main.c

reminder.o: reminder.c reminder.h linked_list.h
	gcc -g -Wall -c reminder.c

linked_list.o: linked_list.c linked_list.h
	gcc -g -Wall -c linked_list.c

interact.o: interact.c interact.h reminder.h
	gcc -g -Wall -c interact.c

clean:
	rm -f *.o reminders
