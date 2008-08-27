begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_COMPAT_OPENSOLARIS_SYS_CPUVAR_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|_COMPAT_OPENSOLARIS_SYS_CPUVAR_DEFS_H
end_define

begin_comment
comment|/*  * DTrace flags.  */
end_comment

begin_define
define|#
directive|define
name|CPU_DTRACE_NOFAULT
value|0x0001
end_define

begin_comment
comment|/* Don't fault */
end_comment

begin_define
define|#
directive|define
name|CPU_DTRACE_DROP
value|0x0002
end_define

begin_comment
comment|/* Drop this ECB */
end_comment

begin_define
define|#
directive|define
name|CPU_DTRACE_BADADDR
value|0x0004
end_define

begin_comment
comment|/* DTrace fault: bad address */
end_comment

begin_define
define|#
directive|define
name|CPU_DTRACE_BADALIGN
value|0x0008
end_define

begin_comment
comment|/* DTrace fault: bad alignment */
end_comment

begin_define
define|#
directive|define
name|CPU_DTRACE_DIVZERO
value|0x0010
end_define

begin_comment
comment|/* DTrace fault: divide by zero */
end_comment

begin_define
define|#
directive|define
name|CPU_DTRACE_ILLOP
value|0x0020
end_define

begin_comment
comment|/* DTrace fault: illegal operation */
end_comment

begin_define
define|#
directive|define
name|CPU_DTRACE_NOSCRATCH
value|0x0040
end_define

begin_comment
comment|/* DTrace fault: out of scratch */
end_comment

begin_define
define|#
directive|define
name|CPU_DTRACE_KPRIV
value|0x0080
end_define

begin_comment
comment|/* DTrace fault: bad kernel access */
end_comment

begin_define
define|#
directive|define
name|CPU_DTRACE_UPRIV
value|0x0100
end_define

begin_comment
comment|/* DTrace fault: bad user access */
end_comment

begin_define
define|#
directive|define
name|CPU_DTRACE_TUPOFLOW
value|0x0200
end_define

begin_comment
comment|/* DTrace fault: tuple stack overflow */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sparc
argument_list|)
end_if

begin_define
define|#
directive|define
name|CPU_DTRACE_FAKERESTORE
value|0x0400
end_define

begin_comment
comment|/* pid provider hint to getreg */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CPU_DTRACE_ENTRY
value|0x0800
end_define

begin_comment
comment|/* pid provider hint to ustack() */
end_comment

begin_define
define|#
directive|define
name|CPU_DTRACE_BADSTACK
value|0x1000
end_define

begin_comment
comment|/* DTrace fault: bad stack */
end_comment

begin_define
define|#
directive|define
name|CPU_DTRACE_FAULT
value|(CPU_DTRACE_BADADDR | CPU_DTRACE_BADALIGN | \ 				CPU_DTRACE_DIVZERO | CPU_DTRACE_ILLOP | \ 				CPU_DTRACE_NOSCRATCH | CPU_DTRACE_KPRIV | \ 				CPU_DTRACE_UPRIV | CPU_DTRACE_TUPOFLOW | \ 				CPU_DTRACE_BADSTACK)
end_define

begin_define
define|#
directive|define
name|CPU_DTRACE_ERROR
value|(CPU_DTRACE_FAULT | CPU_DTRACE_DROP)
end_define

begin_define
define|#
directive|define
name|PANICSTKSIZE
value|8192
end_define

begin_define
define|#
directive|define
name|REGSIZE
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _COMPAT_OPENSOLARIS_SYS_CPUVAR_DEFS_H */
end_comment

end_unit

