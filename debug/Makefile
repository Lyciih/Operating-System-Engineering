CC = riscv64-unknown-elf-gcc
FLAG = -nostdlib -fno-builtin -march=rv32ima -mabi=ilp32 -g
DUMP = riscv64-unknown-elf-objdump
QEMU = qemu-system-riscv32
QFLAGS = -nographic -smp 1 -machine virt -bios none
GDB = riscv64-unknown-elf-gdb

#開機程式在編譯a.out時一定要放在第一個

SRCS_O = \
	./objs/start.o \
	./objs/memory.o \
	./objs/context_switch.o \
	./objs/trap_vector.o \
	./objs/os.o \
	./objs/uart.o \
	./objs/printf.o \
	./objs/page.o \
	./objs/malloc.o \
	./objs/schedule.o \
	./objs/trap.o \
	./objs/plic.o \
	./objs/hwtimer.o \
	./objs/showPCB.o \
	./objs/alarm.o \
	./lib/double_linked_list.a \

INCLUDE = -I include


all: a.out 

#start.o memory.o hello.o uart.o printf.o page.o malloc.o
a.out: $(SRCS_O)
	$(CC) $(FLAG) $(INCLUDE) -T os.ld -g $^


./objs/%.o : ./startup/%.s
	$(CC) $(FLAG) -c -o $@ $<

./objs/%.o : ./asm/%.s
	$(CC) $(FLAG) -c -o $@ $<

./objs/%.o :  ./kernel/%.c
	$(CC) $(FLAG) $(INCLUDE) -c -o $@ $<  

./objs/%.o : ./lib/%.c
	$(CC) $(FLAG) $(INCLUDE) -c -o $@ $<





.PHONY: clean
clean:
	rm -f ./objs/*.o *.exe *.out

.PHONY: dump
dump:
	$(DUMP) -D a.out



.PHONY: run
run:
	${QEMU} ${QFLAGS} -kernel a.out

.PHONY: runstop
runstop:
	${QEMU} ${QFLAGS} -kernel a.out -s -S



.PHONY: gdb
gdb:
	${QEMU} ${QFLAGS} -kernel a.out -s -S &
	$(GDB) a.out -q -x gdbinit
