begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_COMPAT_OPENSOLARIS_SYS_CPUVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_COMPAT_OPENSOLARIS_SYS_CPUVAR_H
end_define

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|CPU_CACHE_COHERENCE_SIZE
value|64
end_define

begin_comment
comment|/*  * The cpu_core structure consists of per-CPU state available in any context.  * On some architectures, this may mean that the page(s) containing the  * NCPU-sized array of cpu_core structures must be locked in the TLB -- it  * is up to the platform to assure that this is performed properly.  Note that  * the structure is sized to avoid false sharing.  */
end_comment

begin_define
define|#
directive|define
name|CPUC_SIZE
value|(sizeof (uint16_t) + sizeof (uintptr_t) + \ 				sizeof (kmutex_t))
end_define

begin_define
define|#
directive|define
name|CPUC_PADSIZE
value|CPU_CACHE_COHERENCE_SIZE - CPUC_SIZE
end_define

begin_typedef
typedef|typedef
struct|struct
name|cpu_core
block|{
name|uint16_t
name|cpuc_dtrace_flags
decl_stmt|;
comment|/* DTrace flags */
name|uint8_t
name|cpuc_pad
index|[
name|CPUC_PADSIZE
index|]
decl_stmt|;
comment|/* padding */
name|uintptr_t
name|cpuc_dtrace_illval
decl_stmt|;
comment|/* DTrace illegal value */
name|kmutex_t
name|cpuc_pid_lock
decl_stmt|;
comment|/* DTrace pid provider lock */
block|}
name|cpu_core_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|cpu_core_t
name|cpu_core
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

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

begin_typedef
typedef|typedef
enum|enum
block|{
name|CPU_INIT
block|,
name|CPU_CONFIG
block|,
name|CPU_UNCONFIG
block|,
name|CPU_ON
block|,
name|CPU_OFF
block|,
name|CPU_CPUPART_IN
block|,
name|CPU_CPUPART_OUT
block|}
name|cpu_setup_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|cpu_setup_func_t
parameter_list|(
name|cpu_setup_t
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _COMPAT_OPENSOLARIS_SYS_CPUVAR_H */
end_comment

end_unit

