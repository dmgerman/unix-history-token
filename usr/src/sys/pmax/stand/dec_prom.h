begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)dec_prom.h	7.1 (Berkeley) %G%  *  * machMon.h --  *  *	Structures, constants and defines for access to the pmax prom.  *  *	Copyright (C) 1989 Digital Equipment Corporation.  *	Permission to use, copy, modify, and distribute this software and  *	its documentation for any purpose and without fee is hereby granted,  *	provided that the above copyright notice appears in all copies.  *	Digital Equipment Corporation makes no representations about the  *	suitability of this software for any purpose.  It is provided "as is"  *	without express or implied warranty.  *  * from: $Header: /sprite/src/kernel/mach/ds3100.md/RCS/machMon.h,  *	v 9.3 90/02/20 14:34:07 shirriff Exp $ SPRITE (Berkeley)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEC_PROM
end_ifndef

begin_define
define|#
directive|define
name|_DEC_PROM
end_define

begin_comment
comment|/*  * This file was created based on information from the document  * "TURBOchannel Firmware Specification" (EK-TCAAD-FS-003)  * by Digital Equipment Corporation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/*  * Programs loaded by the new PROMs pass the following arguments:  *	a0	argc  *	a1	argv  *	a2	DEC_PROM_MAGIC  *	a3	The callback vector defined below  */
end_comment

begin_define
define|#
directive|define
name|DEC_PROM_MAGIC
value|0x30464354
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|pagesize
decl_stmt|;
comment|/* system page size */
name|u_char
modifier|*
name|bitmap
decl_stmt|;
comment|/* bit for each page indicating safe to use */
block|}
name|memmap
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|revision
decl_stmt|;
comment|/* hardware revision level */
name|int
name|clk_period
decl_stmt|;
comment|/* clock period in nano seconds */
name|int
name|slot_size
decl_stmt|;
comment|/* slot size in magabytes */
name|int
name|io_timeout
decl_stmt|;
comment|/* I/O timeout in cycles 	int	dma_range;	/* DMA address range in megabytes */
name|int
name|max_dma_burst
decl_stmt|;
comment|/* maximum DMA burst length */
name|int
name|parity
decl_stmt|;
comment|/* true if system module supports T.C. parity */
name|int
name|reserved
index|[
literal|4
index|]
decl_stmt|;
block|}
name|tcinfo
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|jmp_buf
index|[
literal|12
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|psig_t
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|callback
block|{
name|void
operator|*
operator|(
operator|*
name|memcpy
operator|)
name|__P
argument_list|(
operator|(
name|void
operator|*
name|s1
operator|,
name|void
operator|*
name|s2
operator|,
name|int
name|n
operator|)
argument_list|)
expr_stmt|;
comment|/* 00 */
name|void
operator|*
operator|(
operator|*
name|memset
operator|)
name|__P
argument_list|(
operator|(
name|void
operator|*
name|s1
operator|,
name|int
name|c
operator|,
name|int
name|n
operator|)
argument_list|)
expr_stmt|;
comment|/* 04 */
name|char
operator|*
operator|(
operator|*
name|strcat
operator|)
name|__P
argument_list|(
operator|(
name|char
operator|*
name|s1
operator|,
name|char
operator|*
name|s2
operator|)
argument_list|)
expr_stmt|;
comment|/* 08 */
name|int
argument_list|(
argument|*strcmp
argument_list|)
name|__P
argument_list|(
operator|(
name|char
operator|*
name|s1
operator|,
name|char
operator|*
name|s2
operator|)
argument_list|)
expr_stmt|;
comment|/* 0c */
name|char
operator|*
operator|(
operator|*
name|strcpy
operator|)
name|__P
argument_list|(
operator|(
name|char
operator|*
name|s1
operator|,
name|char
operator|*
name|s2
operator|)
argument_list|)
expr_stmt|;
comment|/* 10 */
name|int
argument_list|(
argument|*strlen
argument_list|)
name|__P
argument_list|(
operator|(
name|char
operator|*
name|s1
operator|)
argument_list|)
expr_stmt|;
comment|/* 14 */
name|char
operator|*
operator|(
operator|*
name|strncat
operator|)
name|__P
argument_list|(
operator|(
name|char
operator|*
name|s1
operator|,
name|char
operator|*
name|s2
operator|,
name|int
name|n
operator|)
argument_list|)
expr_stmt|;
comment|/* 18 */
name|char
operator|*
operator|(
operator|*
name|strncpy
operator|)
name|__P
argument_list|(
operator|(
name|char
operator|*
name|s1
operator|,
name|char
operator|*
name|s2
operator|,
name|int
name|n
operator|)
argument_list|)
expr_stmt|;
comment|/* 1c */
name|int
argument_list|(
argument|*strncmp
argument_list|)
name|__P
argument_list|(
operator|(
name|char
operator|*
name|s1
operator|,
name|char
operator|*
name|s2
operator|,
name|int
name|n
operator|)
argument_list|)
expr_stmt|;
comment|/* 20 */
name|int
argument_list|(
argument|*getchar
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* 24 */
name|char
operator|*
operator|(
operator|*
name|gets
operator|)
name|__P
argument_list|(
operator|(
name|char
operator|*
name|s
operator|)
argument_list|)
expr_stmt|;
comment|/* 28 */
name|int
argument_list|(
argument|*puts
argument_list|)
name|__P
argument_list|(
operator|(
name|char
operator|*
name|s
operator|)
argument_list|)
expr_stmt|;
comment|/* 2c */
name|int
argument_list|(
argument|*printf
argument_list|)
name|__P
argument_list|(
operator|(
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
expr_stmt|;
comment|/* 30 */
name|int
argument_list|(
argument|*sprintf
argument_list|)
name|__P
argument_list|(
operator|(
name|char
operator|*
name|s
operator|,
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
expr_stmt|;
comment|/* 34 */
name|int
argument_list|(
argument|*io_poll
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* 38 */
name|long
argument_list|(
argument|*strtol
argument_list|)
name|__P
argument_list|(
operator|(
name|char
operator|*
name|s
operator|,
name|char
operator|*
operator|*
name|endptr
operator|,
name|int
name|base
operator|)
argument_list|)
expr_stmt|;
comment|/* 3c */
name|psig_t
argument_list|(
argument|*signal
argument_list|)
name|__P
argument_list|(
operator|(
name|int
name|sig
operator|,
name|psig_t
name|func
operator|)
argument_list|)
expr_stmt|;
comment|/* 40 */
name|int
argument_list|(
argument|*raise
argument_list|)
name|__P
argument_list|(
operator|(
name|int
name|sig
operator|)
argument_list|)
expr_stmt|;
comment|/* 44 */
name|long
argument_list|(
argument|*time
argument_list|)
name|__P
argument_list|(
operator|(
name|long
operator|*
name|tod
operator|)
argument_list|)
expr_stmt|;
comment|/* 48 */
name|int
argument_list|(
argument|*setjmp
argument_list|)
name|__P
argument_list|(
operator|(
name|jmp_buf
name|env
operator|)
argument_list|)
expr_stmt|;
comment|/* 4c */
name|void
argument_list|(
argument|*longjmp
argument_list|)
name|__P
argument_list|(
operator|(
name|jmp_buf
name|env
operator|,
name|int
name|value
operator|)
argument_list|)
expr_stmt|;
comment|/* 50 */
name|int
argument_list|(
argument|*bootinit
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* 54 */
name|int
argument_list|(
argument|*bootread
argument_list|)
name|__P
argument_list|(
operator|(
name|int
name|b
operator|,
name|void
operator|*
name|buffer
operator|,
name|int
name|n
operator|)
argument_list|)
expr_stmt|;
comment|/* 58 */
name|int
argument_list|(
argument|*bootwrite
argument_list|)
name|__P
argument_list|(
operator|(
name|int
name|b
operator|,
name|void
operator|*
name|buffer
operator|,
name|int
name|n
operator|)
argument_list|)
expr_stmt|;
comment|/* 5c */
name|int
argument_list|(
argument|*setenv
argument_list|)
name|__P
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|char
operator|*
name|value
operator|)
argument_list|)
expr_stmt|;
comment|/* 60 */
name|char
operator|*
operator|(
operator|*
name|getenv
operator|)
name|__P
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
expr_stmt|;
comment|/* 64 */
name|int
argument_list|(
argument|*unsetenv
argument_list|)
name|__P
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
expr_stmt|;
comment|/* 68 */
name|u_long
argument_list|(
argument|*slot_address
argument_list|)
name|__P
argument_list|(
operator|(
name|int
name|sn
operator|)
argument_list|)
expr_stmt|;
comment|/* 6c */
name|void
argument_list|(
argument|*wbflush
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* 70 */
name|void
argument_list|(
argument|*msdelay
argument_list|)
name|__P
argument_list|(
operator|(
name|int
name|delay
operator|)
argument_list|)
expr_stmt|;
comment|/* 74 */
name|void
argument_list|(
argument|*leds
argument_list|)
name|__P
argument_list|(
operator|(
name|int
name|value
operator|)
argument_list|)
expr_stmt|;
comment|/* 78 */
name|void
argument_list|(
argument|*clear_cache
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* 7c */
name|int
argument_list|(
argument|*getsysid
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* 80 */
name|int
argument_list|(
argument|*getbitmap
argument_list|)
name|__P
argument_list|(
operator|(
name|memmap
operator|*
name|map
operator|)
argument_list|)
expr_stmt|;
comment|/* 84 */
name|int
argument_list|(
argument|*disableintr
argument_list|)
name|__P
argument_list|(
operator|(
name|int
name|sn
operator|)
argument_list|)
expr_stmt|;
comment|/* 88 */
name|int
argument_list|(
argument|*enableintr
argument_list|)
name|__P
argument_list|(
operator|(
name|int
name|sn
operator|)
argument_list|)
expr_stmt|;
comment|/* 8c */
name|int
argument_list|(
argument|*testintr
argument_list|)
name|__P
argument_list|(
operator|(
name|int
name|sn
operator|)
argument_list|)
expr_stmt|;
comment|/* 90 */
name|void
modifier|*
name|reserved_data
decl_stmt|;
comment|/* 94 */
name|int
argument_list|(
argument|*console_init
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* 98 */
name|void
argument_list|(
argument|*halt
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|*
name|v
operator|,
name|int
name|cnt
operator|)
argument_list|)
expr_stmt|;
comment|/* 9c */
name|void
argument_list|(
argument|*showfault
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* a0 */
name|tcinfo
operator|*
operator|(
operator|*
name|gettcinfo
operator|)
name|__P
argument_list|(
operator|(
operator|)
argument_list|)
expr_stmt|;
comment|/* a4 */
name|int
argument_list|(
argument|*execute_cmd
argument_list|)
name|__P
argument_list|(
operator|(
name|char
operator|*
name|cmd
operator|)
argument_list|)
expr_stmt|;
comment|/* a8 */
name|void
argument_list|(
argument|*rex
argument_list|)
name|__P
argument_list|(
operator|(
name|char
name|cmd
operator|)
argument_list|)
expr_stmt|;
comment|/* ac */
comment|/* b0 to d4 reserved */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|callback
modifier|*
name|callv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|callback
name|callvec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The prom routines use the following structure to hold strings.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|argPtr
index|[
literal|16
index|]
decl_stmt|;
comment|/* Pointers to the strings. */
name|char
name|strings
index|[
literal|256
index|]
decl_stmt|;
comment|/* Buffer for the strings. */
name|char
modifier|*
name|end
decl_stmt|;
comment|/* Pointer to end of used buf. */
name|int
name|num
decl_stmt|;
comment|/* Number of strings used. */
block|}
name|MachStringTable
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
end_comment

begin_comment
comment|/*  * The prom has a jump table at the beginning of it to get to its  * functions.  */
end_comment

begin_define
define|#
directive|define
name|DEC_PROM_JUMP_TABLE_ADDR
value|0xBFC00000
end_define

begin_comment
comment|/*  * Each entry in the jump table is 8 bytes - 4 for the jump and 4 for a nop.  */
end_comment

begin_define
define|#
directive|define
name|DEC_PROM_FUNC_ADDR
parameter_list|(
name|funcNum
parameter_list|)
value|(DEC_PROM_JUMP_TABLE_ADDR+((funcNum)*8))
end_define

begin_comment
comment|/*  * The functions:  *  *	DEC_PROM_RESET		Run diags, check bootmode, reinit.  *	DEC_PROM_EXEC		Load new program image.  *	DEC_PROM_RESTART	Re-enter monitor command loop.  *	DEC_PROM_REINIT		Re-init monitor, then cmd loop.  *	DEC_PROM_REBOOT		Check bootmode, no config.  *	DEC_PROM_AUTOBOOT	Autoboot the system.  *  * The following routines access PROM saio routines and may be used by  * standalone programs that would like to use PROM I/O:  *  *	DEC_PROM_OPEN		Open a file.  *	DEC_PROM_READ		Read from a file.  *	DEC_PROM_WRITE		Write to a file.  *	DEC_PROM_IOCTL		Iocontrol on a file.  *	DEC_PROM_CLOSE		Close a file.  *	DEC_PROM_LSEEK		Seek on a file.  *	DEC_PROM_GETCHAR	Get character from console.  *	DEC_PROM_PUTCHAR	Put character on console.  *	DEC_PROM_SHOWCHAR	Show a char visibly.  *	DEC_PROM_GETS		gets with editing.  *	DEC_PROM_PUTS		Put string to console.  *	DEC_PROM_PRINTF		Kernel style printf to console.  *  * The following are other prom routines:  *	DEC_PROM_FLUSHCACHE	Flush entire cache ().  *	DEC_PROM_CLEARCACHE	Clear I& D cache in range (addr, len).  *	DEC_PROM_SAVEREGS	Save registers in a buffer.  *	DEC_PROM_LOADREGS	Get register back from buffer.  *	DEC_PROM_JUMPS8		Jump to address in s8.  *	DEC_PROM_GETENV2	Gets a string from system environment.  *	DEC_PROM_SETENV2	Sets a string in system environment.  *	DEC_PROM_ATONUM		Converts ascii string to number.  *	DEC_PROM_STRCMP		Compares strings (strcmp).  *	DEC_PROM_STRLEN		Length of string (strlen).  *	DEC_PROM_STRCPY		Copies string (strcpy).  *	DEC_PROM_STRCAT		Appends string (strcat).  *	DEC_PROM_GETCMD		Gets a command.  *	DEC_PROM_GETNUMS	Gets numbers.  *	DEC_PROM_ARGPARSE	Parses string to argc,argv.  *	DEC_PROM_HELP		Help on prom commands.  *	DEC_PROM_DUMP		Dumps memory.  *	DEC_PROM_SETENV		Sets a string in system environment.  *	DEC_PROM_UNSETENV	Unsets a string in system environment  *	DEC_PROM_PRINTENV	Prints system environment  *	DEC_PROM_JUMP2S8	Jumps to s8  *	DEC_PROM_ENABLE		Performs prom enable command.  *	DEC_PROM_DISABLE	Performs prom disable command.  *	DEC_PROM_ZEROB		Zeros a system buffer.  */
end_comment

begin_define
define|#
directive|define
name|DEC_PROM_RESET
value|DEC_PROM_FUNC_ADDR(0)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_EXEC
value|DEC_PROM_FUNC_ADDR(1)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_RESTART
value|DEC_PROM_FUNC_ADDR(2)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_REINIT
value|DEC_PROM_FUNC_ADDR(3)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_REBOOT
value|DEC_PROM_FUNC_ADDR(4)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_AUTOBOOT
value|DEC_PROM_FUNC_ADDR(5)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_OPEN
value|DEC_PROM_FUNC_ADDR(6)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_READ
value|DEC_PROM_FUNC_ADDR(7)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_WRITE
value|DEC_PROM_FUNC_ADDR(8)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_IOCTL
value|DEC_PROM_FUNC_ADDR(9)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_CLOSE
value|DEC_PROM_FUNC_ADDR(10)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_LSEEK
value|DEC_PROM_FUNC_ADDR(11)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_GETCHAR
value|DEC_PROM_FUNC_ADDR(12)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_PUTCHAR
value|DEC_PROM_FUNC_ADDR(13)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_SHOWCHAR
value|DEC_PROM_FUNC_ADDR(14)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_GETS
value|DEC_PROM_FUNC_ADDR(15)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_PUTS
value|DEC_PROM_FUNC_ADDR(16)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_PRINTF
value|DEC_PROM_FUNC_ADDR(17)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_FLUSHCACHE
value|DEC_PROM_FUNC_ADDR(28)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_CLEARCACHE
value|DEC_PROM_FUNC_ADDR(29)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_SAVEREGS
value|DEC_PROM_FUNC_ADDR(30)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_LOADREGS
value|DEC_PROM_FUNC_ADDR(31)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_JUMPS8
value|DEC_PROM_FUNC_ADDR(32)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_GETENV2
value|DEC_PROM_FUNC_ADDR(33)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_SETENV2
value|DEC_PROM_FUNC_ADDR(34)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_ATONUM
value|DEC_PROM_FUNC_ADDR(35)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_STRCMP
value|DEC_PROM_FUNC_ADDR(36)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_STRLEN
value|DEC_PROM_FUNC_ADDR(37)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_STRCPY
value|DEC_PROM_FUNC_ADDR(38)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_STRCAT
value|DEC_PROM_FUNC_ADDR(39)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_GETCMD
value|DEC_PROM_FUNC_ADDR(40)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_GETNUMS
value|DEC_PROM_FUNC_ADDR(41)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_ARGPARSE
value|DEC_PROM_FUNC_ADDR(42)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_HELP
value|DEC_PROM_FUNC_ADDR(43)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_DUMP
value|DEC_PROM_FUNC_ADDR(44)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_SETENV
value|DEC_PROM_FUNC_ADDR(45)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_UNSETENV
value|DEC_PROM_FUNC_ADDR(46)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_PRINTENV
value|DEC_PROM_FUNC_ADDR(47)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_JUMP2S8
value|DEC_PROM_FUNC_ADDR(48)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_ENABLE
value|DEC_PROM_FUNC_ADDR(49)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_DISABLE
value|DEC_PROM_FUNC_ADDR(50)
end_define

begin_define
define|#
directive|define
name|DEC_PROM_ZEROB
value|DEC_PROM_FUNC_ADDR(51)
end_define

begin_comment
comment|/*  * The nonvolatile ram has a flag to indicate it is usable.  */
end_comment

begin_define
define|#
directive|define
name|MACH_USE_NON_VOLATILE
value|((char *)0xbd0000c0)
end_define

begin_define
define|#
directive|define
name|MACH_NON_VOLATILE_FLAG
value|0x02
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEC_PROM */
end_comment

end_unit

