begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993, 1996  *	Berkeley Software Design, Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Berkeley Software  *	Design, Inc.  *  * THIS SOFTWARE IS PROVIDED BY Berkeley Software Design, Inc. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Berkeley Software Design, Inc. BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	BSDI doscmd.h,v 2.3 1996/04/08 19:32:32 bostic Exp  *  * $FreeBSD$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_define
define|#
directive|define
name|USE_VM86
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<machine/sigframe.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_include
include|#
directive|include
file|<machine/npx.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USE_VM86
end_ifdef

begin_include
include|#
directive|include
file|<machine/vm86.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"register.h"
end_include

begin_include
include|#
directive|include
file|"dos.h"
end_include

begin_include
include|#
directive|include
file|"callback.h"
end_include

begin_include
include|#
directive|include
file|"cwd.h"
end_include

begin_define
define|#
directive|define
name|drlton
parameter_list|(
name|a
parameter_list|)
value|((islower((a)) ? toupper((a)) : (a)) - 'A')
end_define

begin_define
define|#
directive|define
name|drntol
parameter_list|(
name|a
parameter_list|)
value|((a) + 'A')
end_define

begin_comment
comment|/*  ** assorted hardware/scope constants  */
end_comment

begin_define
define|#
directive|define
name|MAX_AVAIL_SEG
value|0xa000
end_define

begin_define
define|#
directive|define
name|MAXPORT
value|0x400
end_define

begin_define
define|#
directive|define
name|N_PARALS_MAX
value|3
end_define

begin_define
define|#
directive|define
name|N_COMS_MAX
value|4
end_define

begin_comment
comment|/* DOS restriction (sigh) */
end_comment

begin_struct
struct|struct
name|vconnect_area
block|{
name|int
name|int_state
decl_stmt|;
name|int
name|magic
decl_stmt|;
comment|/* 0x4242 -> PRB format */
name|u_long
name|passthru
index|[
literal|256
operator|>>
literal|5
index|]
expr_stmt|;
comment|/* bitmap of INTs to handle */
name|u_long
name|magiciret
index|[
literal|2
index|]
decl_stmt|;
comment|/* Bounds of "magic" IRET */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vconnect_area
name|vconnect_area
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IntState
value|vconnect_area.int_state
end_define

begin_comment
comment|/* debug.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tmode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|debugf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|debug_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lower 8 bits are int number */
end_comment

begin_define
define|#
directive|define
name|D_ALWAYS
value|0x0000100
end_define

begin_comment
comment|/* always emit this message */
end_comment

begin_define
define|#
directive|define
name|D_TRAPS
value|0x0000200
end_define

begin_comment
comment|/* trap-related activity */
end_comment

begin_define
define|#
directive|define
name|D_FILE_OPS
value|0x0000400
end_define

begin_comment
comment|/* file-related activity */
end_comment

begin_define
define|#
directive|define
name|D_MEMORY
value|0x0000800
end_define

begin_comment
comment|/* memory-related activity */
end_comment

begin_define
define|#
directive|define
name|D_HALF
value|0x0001000
end_define

begin_comment
comment|/* for "half-implemented" system calls */
end_comment

begin_define
define|#
directive|define
name|D_FLOAT
value|0x0002000
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|D_DISK
value|0x0004000
end_define

begin_comment
comment|/* disk (not file) operations */
end_comment

begin_define
define|#
directive|define
name|D_TRAPS2
value|0x0008000
end_define

begin_define
define|#
directive|define
name|D_PORT
value|0x0010000
end_define

begin_comment
comment|/* port accesses */
end_comment

begin_define
define|#
directive|define
name|D_EXEC
value|0x0020000
end_define

begin_define
define|#
directive|define
name|D_ITRAPS
value|0x0040000
end_define

begin_define
define|#
directive|define
name|D_REDIR
value|0x0080000
end_define

begin_comment
comment|/* redirector functions */
end_comment

begin_define
define|#
directive|define
name|D_PRINTER
value|0x0100000
end_define

begin_define
define|#
directive|define
name|D_TRAPS3
value|0x0200000
end_define

begin_define
define|#
directive|define
name|D_DEBUGIN
value|0x0400000
end_define

begin_define
define|#
directive|define
name|D_DOSCALL
value|0x0800000
end_define

begin_comment
comment|/* MS-DOS function results */
end_comment

begin_define
define|#
directive|define
name|D_XMS
value|0x1000000
end_define

begin_comment
comment|/* XMS calls */
end_comment

begin_define
define|#
directive|define
name|D_EMS
value|0x2000000
end_define

begin_comment
comment|/* EMS calls */
end_comment

begin_define
define|#
directive|define
name|TTYF_ECHO
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TTYF_ECHONL
value|0x00000003
end_define

begin_define
define|#
directive|define
name|TTYF_CTRL
value|0x00000004
end_define

begin_define
define|#
directive|define
name|TTYF_BLOCK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|TTYF_POLL
value|0x00000010
end_define

begin_define
define|#
directive|define
name|TTYF_REDIRECT
value|0x00010000
end_define

begin_comment
comment|/* Cannot have 0xffff bits set */
end_comment

begin_define
define|#
directive|define
name|TTYF_ALL
value|(TTYF_ECHO | TTYF_CTRL | TTYF_REDIRECT)
end_define

begin_define
define|#
directive|define
name|TTYF_BLOCKALL
value|(TTYF_ECHO | TTYF_CTRL | TTYF_REDIRECT | TTYF_BLOCK)
end_define

begin_function_decl
specifier|extern
name|void
name|unknown_int2
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|regcontext_t
modifier|*
name|REGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|unknown_int3
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|regcontext_t
modifier|*
name|REGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|unknown_int4
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|regcontext_t
modifier|*
name|REGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fatal
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug
parameter_list|(
name|int
name|flags
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_regs
parameter_list|(
name|regcontext_t
modifier|*
name|REGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_set
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_unset
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_long
name|debug_isset
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* doscmd.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|capture_fd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dead
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|xmode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|booting
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|raw_kbd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|timer_disable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|cmdname
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|boot_time
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
modifier|*
name|ivec
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|open_prog
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|done
parameter_list|(
name|regcontext_t
modifier|*
name|REGS
parameter_list|,
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|quit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|call_on_quit
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|iomap_port
parameter_list|(
name|int
name|port
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* signal.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|sigframe
modifier|*
name|saved_sigframe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|regcontext_t
modifier|*
name|saved_regcontext
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|saved_valid
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|setsignal
parameter_list|(
name|int
name|s
parameter_list|,
name|void
function_decl|(
modifier|*
name|h
function_decl|)
parameter_list|(
name|struct
name|sigframe
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* cmos.c */
end_comment

begin_decl_stmt
specifier|extern
name|time_t
name|delta_clock
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|cmos_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* config.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|read_config
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* tty.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|xfont
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* setver.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|setver
parameter_list|(
name|char
modifier|*
parameter_list|,
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|short
name|getver
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* mem.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dosmem
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|mem_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mem_alloc
parameter_list|(
name|int
name|size
parameter_list|,
name|int
name|owner
parameter_list|,
name|int
modifier|*
name|biggestp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mem_adjust
parameter_list|(
name|int
name|addr
parameter_list|,
name|int
name|size
parameter_list|,
name|int
modifier|*
name|availp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mem_free_owner
parameter_list|(
name|int
name|owner
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mem_change_owner
parameter_list|(
name|int
name|addr
parameter_list|,
name|int
name|owner
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* intff.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|int2f_11
parameter_list|(
name|regcontext_t
modifier|*
name|REGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|intff
parameter_list|(
name|regcontext_t
modifier|*
name|REGS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* emuint.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|emuint
parameter_list|(
name|regcontext_t
modifier|*
name|REGS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* trap.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|fake_int
parameter_list|(
name|regcontext_t
modifier|*
name|REGS
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sigtrap
parameter_list|(
name|struct
name|sigframe
modifier|*
name|sf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sigtrace
parameter_list|(
name|struct
name|sigframe
modifier|*
name|sf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sigalrm
parameter_list|(
name|struct
name|sigframe
modifier|*
name|sf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sigill
parameter_list|(
name|struct
name|sigframe
modifier|*
name|sf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sigfpe
parameter_list|(
name|struct
name|sigframe
modifier|*
name|sf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|breakpoint
parameter_list|(
name|struct
name|sigframe
modifier|*
name|sf
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|USE_VM86
end_ifdef

begin_function_decl
specifier|extern
name|void
name|sigurg
parameter_list|(
name|struct
name|sigframe
modifier|*
name|sf
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|sigbus
parameter_list|(
name|struct
name|sigframe
modifier|*
name|sf
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* int.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|softint
parameter_list|(
name|int
name|intnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|hardint
parameter_list|(
name|int
name|intnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|delay_interrupt
parameter_list|(
name|int
name|intnum
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|resume_interrupt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* bios.c */
end_comment

begin_define
define|#
directive|define
name|BIOSDATA
value|((u_char *)0x400)
end_define

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|rom_config
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nfloppies
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ndisks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nserial
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nparallel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|int
name|poll_cnt
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|wakeup_poll
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reset_poll
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sleep_poll
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* int13.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|init_hdisk
parameter_list|(
name|int
name|drive
parameter_list|,
name|int
name|cyl
parameter_list|,
name|int
name|head
parameter_list|,
name|int
name|tracksize
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|char
modifier|*
name|boot_sector
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|init_floppy
parameter_list|(
name|int
name|drive
parameter_list|,
name|int
name|type
parameter_list|,
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|disk_fd
parameter_list|(
name|int
name|drive
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|make_readonly
parameter_list|(
name|int
name|drive
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|search_floppy
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|disk_bios_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* int17.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|lpt_poll
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|printer_direct
parameter_list|(
name|int
name|printer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|printer_spool
parameter_list|(
name|int
name|printer
parameter_list|,
name|char
modifier|*
name|print_queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|printer_timeout
parameter_list|(
name|int
name|printer
parameter_list|,
name|char
modifier|*
name|time_out
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* xms.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|int2f_43
parameter_list|(
name|regcontext_t
modifier|*
name|REGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|get_raw_extmemory_info
parameter_list|(
name|regcontext_t
modifier|*
name|REGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|initHMA
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|u_long
name|xms_maxsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ems.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|ems_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ems_entry
parameter_list|(
name|regcontext_t
modifier|*
name|REGS
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|u_long
name|ems_frame_addr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/****************************** dirty below here ******************************/
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|pending
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pending interrupts */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|n_pending
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
modifier|*
name|VREG
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nmice
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|redirect0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|redirect1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|redirect2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|kbd_fd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|jmp_okay
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|put_dosenv
parameter_list|(
name|char
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* TTY subsystem   XXX rewrite! */
end_comment

begin_function_decl
name|int
name|tty_eread
parameter_list|(
name|REGISTERS
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_write
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_rwrite
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_move
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_report
parameter_list|(
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_flush
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_index
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_pause
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tty_peek
parameter_list|(
name|REGISTERS
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tty_state
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_scroll
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_rscroll
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tty_char
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|video_setborder
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|outb_traceport
parameter_list|(
name|int
parameter_list|,
name|unsigned
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
name|inb_traceport
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|outb_port
parameter_list|(
name|int
parameter_list|,
name|unsigned
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
name|inb_port
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

