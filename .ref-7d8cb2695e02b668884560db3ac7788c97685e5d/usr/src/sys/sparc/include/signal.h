begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)signal.h	7.4 (Berkeley) %G%  *  * from: $Header: signal.h,v 1.5 92/11/26 02:04:46 torek Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_typedef
typedef|typedef
name|int
name|sig_atomic_t
typedef|;
end_typedef

begin_comment
comment|/*  * Information pushed on stack when a signal is delivered.  * This is used by the kernel to restore state following  * execution of the signal handler.  It is also made available  * to the handler to allow it to restore state properly if  * a non-standard exit is performed.  *  * All machines must have an sc_onstack and sc_mask.  */
end_comment

begin_struct
struct|struct
name|sigcontext
block|{
name|int
name|sc_onstack
decl_stmt|;
comment|/* sigstack state to restore */
name|int
name|sc_mask
decl_stmt|;
comment|/* signal mask to restore */
comment|/* begin machine dependent portion */
name|int
name|sc_sp
decl_stmt|;
comment|/* %sp to restore */
name|int
name|sc_pc
decl_stmt|;
comment|/* pc to restore */
name|int
name|sc_npc
decl_stmt|;
comment|/* npc to restore */
name|int
name|sc_psr
decl_stmt|;
comment|/* psr to restore */
name|int
name|sc_g1
decl_stmt|;
comment|/* %g1 to restore */
name|int
name|sc_o0
decl_stmt|;
comment|/* %o0 to restore */
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* LOCORE */
end_comment

begin_define
define|#
directive|define
name|SC_SP_OFFSET
value|8
end_define

begin_define
define|#
directive|define
name|SC_PC_OFFSET
value|12
end_define

begin_define
define|#
directive|define
name|SC_NPC_OFFSET
value|16
end_define

begin_define
define|#
directive|define
name|SC_PSR_OFFSET
value|20
end_define

begin_define
define|#
directive|define
name|SC_G1_OFFSET
value|24
end_define

begin_define
define|#
directive|define
name|SC_O0_OFFSET
value|28
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
end_comment

begin_comment
comment|/*  * `Code' arguments to signal handlers.  The names, and the funny numbering.  * are defined so as to match up with what SunOS uses; I have no idea why  * they did the numbers that way, except maybe to match up with the 68881.  */
end_comment

begin_define
define|#
directive|define
name|FPE_INTOVF_TRAP
value|0x01
end_define

begin_comment
comment|/* integer overflow */
end_comment

begin_define
define|#
directive|define
name|FPE_INTDIV_TRAP
value|0x14
end_define

begin_comment
comment|/* integer divide by zero */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTINEX_TRAP
value|0xc4
end_define

begin_comment
comment|/* inexact */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTDIV_TRAP
value|0xc8
end_define

begin_comment
comment|/* divide by zero */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTUND_TRAP
value|0xcc
end_define

begin_comment
comment|/* underflow */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTOPERR_TRAP
value|0xd0
end_define

begin_comment
comment|/* operand error */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTOVF_TRAP
value|0xd4
end_define

begin_comment
comment|/* overflow */
end_comment

end_unit

