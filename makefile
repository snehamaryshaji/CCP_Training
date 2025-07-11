all: boot.img run

boot.img: boot.asm
	nasm -f bin boot.asm -o boot.img

run: boot.img
	qemu-system-x86_64 -drive format=raw,file=boot.img

clean:
	rm -f boot.img
