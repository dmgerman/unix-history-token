begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* From: NetBSD: proc.h,v 1.3 1997/04/06 08:47:36 cgd Exp */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_include
include|#
directive|include
file|<machine/globaldata.h>
end_include

begin_include
include|#
directive|include
file|<machine/globals.h>
end_include

begin_comment
comment|/*  * Machine-dependent part of the proc struct for the Alpha.  */
end_comment

begin_struct
struct|struct
name|mdproc
block|{
name|u_long
name|md_flags
decl_stmt|;
name|struct
name|trapframe
modifier|*
name|md_tf
decl_stmt|;
comment|/* trap/syscall registers */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MDP_FPUSED
value|0x0001
end_define

begin_comment
comment|/* Process used the FPU */
end_comment

begin_define
define|#
directive|define
name|MDP_UAC_NOPRINT
value|0x0010
end_define

begin_comment
comment|/* Don't print unaligned traps */
end_comment

begin_define
define|#
directive|define
name|MDP_UAC_NOFIX
value|0x0020
end_define

begin_comment
comment|/* Don't fixup unaligned traps */
end_comment

begin_define
define|#
directive|define
name|MDP_UAC_SIGBUS
value|0x0040
end_define

begin_comment
comment|/* Deliver SIGBUS upon 					   unaligned access */
end_comment

begin_define
define|#
directive|define
name|MDP_UAC_MASK
value|(MDP_UAC_NOPRINT | MDP_UAC_NOFIX | MDP_UAC_SIGBUS)
end_define

end_unit

