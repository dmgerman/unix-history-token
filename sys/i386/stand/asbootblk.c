begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * sys/i386/stand/asbootblk.c  *  * Boot block for Adaptech 1542 SCSI  *  * April 10, 1992  * Pace Willisson  * pace@blitz.com  *  * Placed in the public domain with NO WARRANTIES, not even the  * implied warranties for MERCHANTABILITY or FITNESS FOR A   * PARTICULAR PURPOSE.  *  * To compile:  *  *	cc -O -c -DRELOC=0x70000 asbootblk.c  *	ld -N -T 7c00 asbootblk.o  *  * This should result in a file with 512 bytes of text and no initialized   * data.  Strip the 32 bit header and place in block 0.  *  * When run, this program copies at least the first 8 blocks of SCSI  * target 0 to the address specified by RELOC, then jumps to the  * address RELOC+1024 (skipping the boot block and disk label).  Usually,  * disks have 512 bytes per block, but I don't think they ever have  * less, and it wont hurt if they are bigger, as long as RELOC + 8*SIZE  * is less than 0xa0000.  *  * This bootblock does not support fdisk partitions, and can only be used  * as the master boot block.  *  *	from: 386BSD 0.1  *	$Id$  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"disklabel.h"
end_include

begin_include
include|#
directive|include
file|"i386/isa/asreg.h"
end_include

begin_comment
comment|/* RELOC should be defined with a -D flag to cc */
end_comment

begin_define
define|#
directive|define
name|SECOND_LEVEL_BOOT_START
value|(RELOC + 0x400)
end_define

begin_define
define|#
directive|define
name|READ_SIZE
value|8192
end_define

begin_define
define|#
directive|define
name|as_port
value|0x330
end_define

begin_define
define|#
directive|define
name|target
value|0
end_define

begin_define
define|#
directive|define
name|NBLOCKS
value|(READ_SIZE / 512)
end_define

begin_comment
comment|/* how many logical blocks to read */
end_comment

begin_comment
comment|/* These are the parameters to pass to the second level boot */
end_comment

begin_define
define|#
directive|define
name|dev
value|4
end_define

begin_comment
comment|/* major device number of as driver in 		 i386/stand/conf.c and i386/i386/conf.c */
end_comment

begin_define
define|#
directive|define
name|unit
value|0
end_define

begin_comment
comment|/* partition number of root file system */
end_comment

begin_define
define|#
directive|define
name|off
value|0
end_define

begin_comment
comment|/* block offset of root file system */
end_comment

begin_comment
comment|/* inline i/o borrowed from Roell X server */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|outb
parameter_list|(
name|port
parameter_list|,
name|val
parameter_list|)
name|short
name|port
decl_stmt|;
name|char
name|val
decl_stmt|;
block|{
asm|__asm__
specifier|volatile
asm|("outb %%al, %1" : :"a" (val), "d" (port));
block|}
end_function

begin_function
specifier|static
name|__inline__
name|unsigned
name|int
name|inb
parameter_list|(
name|port
parameter_list|)
name|short
name|port
decl_stmt|;
block|{
name|unsigned
name|int
name|ret
decl_stmt|;
asm|__asm__
specifier|volatile
asm|("xorl %%eax, %%eax; inb %1, %%al" 		    : "=a" (ret) : "d" (port));
return|return
name|ret
return|;
block|}
end_function

begin_comment
comment|/* this code is linked at 0x7c00 and is loaded there by the BIOS */
end_comment

begin_asm
asm|asm (" 	/* we're running in 16 real mode, so normal assembly doesn't work */ bootbase: 	/* interrupts off */ 	cli  	/* load gdt */ 	.byte 0x2e,0x0f,0x01,0x16 /* lgdt %cs:$imm */ 	.word _gdtarg + 2  	/* turn on protected mode */ 	smsw	%ax 	orb	$1,%al 	lmsw	%ax  	/* flush prefetch queue and reload %cs */ 	.byte 0xea /* ljmp $8, flush */ 	.word flush 	.word 8  flush: 	/* now running in 32 bit mode */ 	movl	$0x10,%eax 	movl	%ax,%ds 	movl	%ax,%es 	movl	%ax,%ss  	movl	$0x7c00,%esp 	call	_main ");
end_asm

begin_comment
comment|/* end of asm */
end_comment

begin_decl_stmt
specifier|const
name|char
name|gdt
index|[]
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0x9f
block|,
literal|0xcf
block|,
literal|0
block|,
comment|/* code segment */
literal|0xff
block|,
literal|0xff
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0x93
block|,
literal|0xcf
block|,
literal|0
block|,
comment|/* data segment */
block|}
decl_stmt|;
end_decl_stmt

begin_struct
specifier|const
struct|struct
block|{
name|short
name|filler
decl_stmt|;
name|short
name|size
decl_stmt|;
specifier|const
name|char
modifier|*
name|gdt
decl_stmt|;
block|}
name|gdtarg
init|=
block|{
literal|0
block|,
sizeof|sizeof
name|gdt
operator|-
literal|1
block|,
name|gdt
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CRTBASE
value|((char *)0xb8000)
end_define

begin_define
define|#
directive|define
name|CHECKPOINT
parameter_list|(
name|x
parameter_list|)
value|(CRTBASE[0] = x)
end_define

begin_decl_stmt
specifier|volatile
name|struct
name|mailbox_entry
name|mailbox
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
name|ccb
index|[]
init|=
block|{
literal|0
block|,
comment|/* opcode: normal read/write */
operator|(
name|target
operator|<<
literal|5
operator|)
operator||
literal|8
block|,
comment|/* target num and read flag */
literal|10
block|,
comment|/* scsi cmd len */
literal|1
block|,
comment|/* no automatic request for sense */
name|READ_SIZE
operator|>>
literal|16
block|,
comment|/* data length */
name|READ_SIZE
operator|>>
literal|8
block|,
name|READ_SIZE
block|,
name|RELOC
operator|>>
literal|16
block|,
comment|/* data pointer */
name|RELOC
operator|>>
literal|8
block|,
name|RELOC
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* link pointer */
literal|0
block|,
comment|/* link id */
literal|0
block|,
comment|/* host status */
literal|0
block|,
comment|/* target status */
literal|0
block|,
literal|0
block|,
comment|/* reserved */
comment|/* scsi cdb */
literal|0x28
block|,
comment|/* read opcode */
literal|0
block|,
comment|/* logical unit number */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* logical block address */
literal|0
block|,
comment|/* reserved */
literal|0
block|,
name|NBLOCKS
block|,
comment|/* transfer length */
literal|0
block|,
comment|/* link control */
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|main
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
specifier|extern
name|char
name|edata
index|[]
decl_stmt|,
name|end
index|[]
decl_stmt|;
name|char
specifier|volatile
modifier|*
specifier|volatile
name|p
decl_stmt|,
modifier|*
name|q
decl_stmt|;
name|int
name|physaddr
decl_stmt|;
name|CHECKPOINT
argument_list|(
literal|'a'
argument_list|)
expr_stmt|;
comment|/* clear bss */
for|for
control|(
name|p
operator|=
name|edata
init|;
name|p
operator|<
name|end
condition|;
name|p
operator|++
control|)
operator|*
name|p
operator|=
literal|0
expr_stmt|;
name|f
operator|=
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
name|SECOND_LEVEL_BOOT_START
expr_stmt|;
comment|/* dma setup: see page 5-31 in the Adaptech manual */
comment|/* this knows we are using drq 5 */
name|outb
argument_list|(
literal|0xd6
argument_list|,
literal|0xc1
argument_list|)
expr_stmt|;
name|outb
argument_list|(
literal|0xd4
argument_list|,
literal|0x01
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|as_port
operator|+
name|AS_CONTROL
argument_list|,
name|AS_CONTROL_SRST
argument_list|)
expr_stmt|;
comment|/* delay a little */
name|inb
argument_list|(
literal|0x84
argument_list|)
expr_stmt|;
while|while
condition|(
name|inb
argument_list|(
name|as_port
operator|+
name|AS_STATUS
argument_list|)
operator|!=
operator|(
name|AS_STATUS_INIT
operator||
name|AS_STATUS_IDLE
operator|)
condition|)
empty_stmt|;
name|CHECKPOINT
argument_list|(
literal|'b'
argument_list|)
expr_stmt|;
name|as_put_byte
argument_list|(
name|AS_CMD_MAILBOX_INIT
argument_list|)
expr_stmt|;
name|as_put_byte
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* one mailbox out, one in */
name|as_put_byte
argument_list|(
operator|(
name|int
operator|)
name|mailbox
operator|>>
literal|16
argument_list|)
expr_stmt|;
name|as_put_byte
argument_list|(
operator|(
name|int
operator|)
name|mailbox
operator|>>
literal|8
argument_list|)
expr_stmt|;
name|as_put_byte
argument_list|(
operator|(
name|int
operator|)
name|mailbox
argument_list|)
expr_stmt|;
while|while
condition|(
name|inb
argument_list|(
name|as_port
operator|+
name|AS_STATUS
argument_list|)
operator|&
name|AS_STATUS_INIT
condition|)
empty_stmt|;
name|CHECKPOINT
argument_list|(
literal|'c'
argument_list|)
expr_stmt|;
name|mailbox
index|[
literal|0
index|]
operator|.
name|msb
operator|=
operator|(
name|int
operator|)
name|ccb
operator|>>
literal|16
expr_stmt|;
name|mailbox
index|[
literal|0
index|]
operator|.
name|mid
operator|=
operator|(
name|int
operator|)
name|ccb
operator|>>
literal|8
expr_stmt|;
name|mailbox
index|[
literal|0
index|]
operator|.
name|lsb
operator|=
operator|(
name|int
operator|)
name|ccb
expr_stmt|;
name|mailbox
index|[
literal|0
index|]
operator|.
name|cmd
operator|=
literal|1
expr_stmt|;
name|as_put_byte
argument_list|(
name|AS_CMD_START_SCSI_COMMAND
argument_list|)
expr_stmt|;
comment|/* wait for done */
while|while
condition|(
name|mailbox
index|[
literal|1
index|]
operator|.
name|cmd
operator|==
literal|0
condition|)
empty_stmt|;
name|CHECKPOINT
argument_list|(
literal|'d'
argument_list|)
expr_stmt|;
if|if
condition|(
name|mailbox
index|[
literal|1
index|]
operator|.
name|cmd
operator|!=
literal|1
condition|)
block|{
comment|/* some error */
name|CHECKPOINT
argument_list|(
literal|'X'
argument_list|)
expr_stmt|;
while|while
condition|(
literal|1
condition|)
empty_stmt|;
block|}
name|CHECKPOINT
argument_list|(
literal|'e'
argument_list|)
expr_stmt|;
comment|/* the optimazation that gcc uses when it knows we are jumpping 	 * to a constant address is broken, so we have to use a variable  	 * here 	 */
call|(
modifier|*
name|f
call|)
argument_list|(
name|dev
argument_list|,
name|unit
argument_list|,
name|off
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|as_put_byte
parameter_list|(
name|val
parameter_list|)
name|int
name|val
decl_stmt|;
block|{
while|while
condition|(
name|inb
argument_list|(
name|as_port
operator|+
name|AS_STATUS
argument_list|)
operator|&
name|AS_STATUS_CDF
condition|)
empty_stmt|;
name|outb
argument_list|(
name|as_port
operator|+
name|AS_DATA_OUT
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_asm
asm|asm (" ebootblkcode: 	. = 510 	.byte 0x55 	.byte 0xaa ebootblk: 			/* MUST BE EXACTLY 0x200 BIG FOR SURE */ ");
end_asm

end_unit

