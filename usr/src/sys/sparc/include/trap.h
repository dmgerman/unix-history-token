begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)trap.h	7.3 (Berkeley) %G%  *  * from: $Header: trap.h,v 1.9 92/11/26 02:04:47 torek Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_TRAP_H
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_TRAP_H
end_define

begin_comment
comment|/*  *  * The SPARC has a Trap Base Register (TBR) which holds the upper 20 bits  * of the trap vector table.  The next eight bits are supplied by the  * hardware when the trap occurs, and the bottom four bits are always  * zero (so that we can shove up to 16 bytes of executable code---exactly  * four instructions---into each trap vector).  *  * The hardware allocates half the trap vectors to hardware and half to  * software.  *  * Traps have priorities assigned (lower number => higher priority).  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
end_if

begin_struct
struct|struct
name|trapvec
block|{
name|int
name|tv_instr
index|[
literal|4
index|]
decl_stmt|;
comment|/* the four instructions */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|trapvec
name|trapbase
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the 256 vectors */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*	trap		vec	  (pri) description	*/
end_comment

begin_define
define|#
directive|define
name|T_RESET
value|0x00
end_define

begin_comment
comment|/* (1) not actually vectored; jumps to 0 */
end_comment

begin_define
define|#
directive|define
name|T_TEXTFAULT
value|0x01
end_define

begin_comment
comment|/* (2) address fault during instr fetch */
end_comment

begin_define
define|#
directive|define
name|T_ILLINST
value|0x02
end_define

begin_comment
comment|/* (3) illegal instruction */
end_comment

begin_define
define|#
directive|define
name|T_PRIVINST
value|0x03
end_define

begin_comment
comment|/* (4) privileged instruction */
end_comment

begin_define
define|#
directive|define
name|T_FPDISABLED
value|0x04
end_define

begin_comment
comment|/* (5) fp instr while fp disabled */
end_comment

begin_define
define|#
directive|define
name|T_WINOF
value|0x05
end_define

begin_comment
comment|/* (6) register window overflow */
end_comment

begin_define
define|#
directive|define
name|T_WINUF
value|0x06
end_define

begin_comment
comment|/* (7) register window underflow */
end_comment

begin_define
define|#
directive|define
name|T_ALIGN
value|0x07
end_define

begin_comment
comment|/* (8) address not properly aligned */
end_comment

begin_define
define|#
directive|define
name|T_FPE
value|0x08
end_define

begin_comment
comment|/* (9) floating point exception */
end_comment

begin_define
define|#
directive|define
name|T_DATAFAULT
value|0x09
end_define

begin_comment
comment|/* (10) address fault during data fetch */
end_comment

begin_define
define|#
directive|define
name|T_TAGOF
value|0x0a
end_define

begin_comment
comment|/* (11) tag overflow */
end_comment

begin_comment
comment|/*			0x0b	   unused */
end_comment

begin_comment
comment|/*			0x0c	   unused */
end_comment

begin_comment
comment|/*			0x0d	   unused */
end_comment

begin_comment
comment|/*			0x0e	   unused */
end_comment

begin_comment
comment|/*			0x0f	   unused */
end_comment

begin_comment
comment|/*			0x10	   unused */
end_comment

begin_define
define|#
directive|define
name|T_L1INT
value|0x11
end_define

begin_comment
comment|/* (27) level 1 interrupt */
end_comment

begin_define
define|#
directive|define
name|T_L2INT
value|0x12
end_define

begin_comment
comment|/* (26) level 2 interrupt */
end_comment

begin_define
define|#
directive|define
name|T_L3INT
value|0x13
end_define

begin_comment
comment|/* (25) level 3 interrupt */
end_comment

begin_define
define|#
directive|define
name|T_L4INT
value|0x14
end_define

begin_comment
comment|/* (24) level 4 interrupt */
end_comment

begin_define
define|#
directive|define
name|T_L5INT
value|0x15
end_define

begin_comment
comment|/* (23) level 5 interrupt */
end_comment

begin_define
define|#
directive|define
name|T_L6INT
value|0x16
end_define

begin_comment
comment|/* (22) level 6 interrupt */
end_comment

begin_define
define|#
directive|define
name|T_L7INT
value|0x17
end_define

begin_comment
comment|/* (21) level 7 interrupt */
end_comment

begin_define
define|#
directive|define
name|T_L8INT
value|0x18
end_define

begin_comment
comment|/* (20) level 8 interrupt */
end_comment

begin_define
define|#
directive|define
name|T_L9INT
value|0x19
end_define

begin_comment
comment|/* (19) level 9 interrupt */
end_comment

begin_define
define|#
directive|define
name|T_L10INT
value|0x1a
end_define

begin_comment
comment|/* (18) level 10 interrupt */
end_comment

begin_define
define|#
directive|define
name|T_L11INT
value|0x1b
end_define

begin_comment
comment|/* (17) level 11 interrupt */
end_comment

begin_define
define|#
directive|define
name|T_L12INT
value|0x1c
end_define

begin_comment
comment|/* (16) level 12 interrupt */
end_comment

begin_define
define|#
directive|define
name|T_L13INT
value|0x1d
end_define

begin_comment
comment|/* (15) level 13 interrupt */
end_comment

begin_define
define|#
directive|define
name|T_L14INT
value|0x1e
end_define

begin_comment
comment|/* (14) level 14 interrupt */
end_comment

begin_define
define|#
directive|define
name|T_L15INT
value|0x1f
end_define

begin_comment
comment|/* (13) level 15 interrupt */
end_comment

begin_comment
comment|/*			0x20	   unused */
end_comment

begin_comment
comment|/*	through		0x23	   unused */
end_comment

begin_define
define|#
directive|define
name|T_CPDISABLED
value|0x24
end_define

begin_comment
comment|/* (5) coprocessor instr while disabled */
end_comment

begin_comment
comment|/*			0x25	   unused */
end_comment

begin_comment
comment|/*	through		0x27	   unused */
end_comment

begin_define
define|#
directive|define
name|T_CPEXCEPTION
value|0x28
end_define

begin_comment
comment|/* (9) coprocessor exception */
end_comment

begin_comment
comment|/*			0x29	   unused */
end_comment

begin_comment
comment|/*	through		0x7f	   unused */
end_comment

begin_comment
comment|/* beginning of `user' vectors (from trap instructions) - all priority 12 */
end_comment

begin_define
define|#
directive|define
name|T_SUN_SYSCALL
value|0x80
end_define

begin_comment
comment|/* system call */
end_comment

begin_define
define|#
directive|define
name|T_BREAKPOINT
value|0x81
end_define

begin_comment
comment|/* breakpoint `instruction' */
end_comment

begin_define
define|#
directive|define
name|T_DIV0
value|0x82
end_define

begin_comment
comment|/* division routine was handed 0 */
end_comment

begin_define
define|#
directive|define
name|T_FLUSHWIN
value|0x83
end_define

begin_comment
comment|/* flush windows */
end_comment

begin_define
define|#
directive|define
name|T_CLEANWIN
value|0x84
end_define

begin_comment
comment|/* provide clean windows */
end_comment

begin_define
define|#
directive|define
name|T_RANGECHECK
value|0x85
end_define

begin_comment
comment|/* ? */
end_comment

begin_define
define|#
directive|define
name|T_FIXALIGN
value|0x86
end_define

begin_comment
comment|/* fix up unaligned accesses */
end_comment

begin_define
define|#
directive|define
name|T_INTOF
value|0x87
end_define

begin_comment
comment|/* integer overflow ? */
end_comment

begin_define
define|#
directive|define
name|T_KGDB_EXEC
value|0x88
end_define

begin_comment
comment|/* for kernel gdb */
end_comment

begin_define
define|#
directive|define
name|T_BSD_SYSCALL
value|0x89
end_define

begin_comment
comment|/* BSD system call */
end_comment

begin_comment
comment|/* 0x8a..0xff are currently unallocated */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/* pseudo traps for locore.s */
end_comment

begin_define
define|#
directive|define
name|T_RWRET
value|-1
end_define

begin_comment
comment|/* need first user window for trap return */
end_comment

begin_define
define|#
directive|define
name|T_AST
value|-2
end_define

begin_comment
comment|/* no-op, just needed reschedule or profile */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* flags to system call (flags in %g1 along with syscall number) */
end_comment

begin_define
define|#
directive|define
name|SYSCALL_G2RFLAG
value|0x400
end_define

begin_comment
comment|/* on success, return to %g2 rather than npc */
end_comment

begin_define
define|#
directive|define
name|SYSCALL_G7RFLAG
value|0x800
end_define

begin_comment
comment|/* use %g7 as above (deprecated) */
end_comment

begin_comment
comment|/*  * `software trap' macros to keep people happy (sparc v8 manual says not  * to set the upper bits).  */
end_comment

begin_define
define|#
directive|define
name|ST_BREAKPOINT
value|(T_BREAKPOINT& 0x7f)
end_define

begin_define
define|#
directive|define
name|ST_DIV0
value|(T_DIV0& 0x7f)
end_define

begin_define
define|#
directive|define
name|ST_FLUSHWIN
value|(T_FLUSHWIN& 0x7f)
end_define

begin_define
define|#
directive|define
name|ST_SYSCALL
value|(T_BSD_SYSCALL& 0x7f)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_TRAP_H_ */
end_comment

end_unit

