begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1988, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)systm.h	8.7 (Berkeley) 3/29/95  * $Id: systm.h,v 1.63 1997/11/21 11:37:03 bde Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SYSTM_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SYSTM_H_
end_define

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|securelevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system security level (see init(8)) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cold
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* nonzero if we are doing a cold boot */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|panicstr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* panic message */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|safepri
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* safe ipl when cold or panicing */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|version
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system version */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|copyright
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system copyright */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nblkdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of entries in bdevsw */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nchrdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of entries in cdevsw */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nswap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of swap space */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|selwait
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* select timeout address */
end_comment

begin_decl_stmt
specifier|extern
name|u_char
name|curpriority
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* priority of current process */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|physmem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* physical memory */
end_comment

begin_decl_stmt
specifier|extern
name|dev_t
name|dumpdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dump device */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|dumplo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* offset into dumpdev */
end_comment

begin_decl_stmt
specifier|extern
name|dev_t
name|rootdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* root device */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vnode
modifier|*
name|rootvp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vnode equivalent to above */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vnode
modifier|*
name|swapdev_vp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vnode for swap device */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|boothowto
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reboot flags, from console subsystem */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bootverbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* nonzero to print verbose messages */
end_comment

begin_comment
comment|/*  * General function declarations.  */
end_comment

begin_struct_decl
struct_decl|struct
name|malloc_type
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|Debugger
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|msg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nullop
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|eopnotsupp
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|einval
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|seltrue
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|,
name|int
name|which
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ureadc
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|uio
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|hashinit
name|__P
argument_list|(
operator|(
name|int
name|count
operator|,
expr|struct
name|malloc_type
operator|*
name|type
operator|,
name|u_long
operator|*
name|hashmask
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|phashinit
name|__P
argument_list|(
operator|(
name|int
name|count
operator|,
expr|struct
name|malloc_type
operator|*
name|type
operator|,
name|u_long
operator|*
name|nentries
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|panic
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cpu_boot
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cpu_rootconf
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cpu_dumpconf
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tablefull
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|addlog
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kvprintf
name|__P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|int
argument_list|,
name|void
operator|*
argument_list|)
operator|,
name|void
operator|*
operator|,
name|int
operator|,
name|_BSD_VA_LIST_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|log
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|logwakeup
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|printf
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sprintf
name|__P
argument_list|(
operator|(
name|char
operator|*
name|buf
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|uprintf
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vprintf
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|_BSD_VA_LIST_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ttyprintf
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bcopy
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
name|from
operator|,
name|void
operator|*
name|to
operator|,
name|size_t
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ovbcopy
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
name|from
operator|,
name|void
operator|*
name|to
operator|,
name|size_t
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern void	(*bzero
end_extern

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
name|void
operator|*
name|buf
operator|,
name|size_t
name|len
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
modifier|*
name|memcpy
name|__P
argument_list|(
operator|(
name|void
operator|*
name|to
operator|,
specifier|const
name|void
operator|*
name|from
operator|,
name|size_t
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|copystr
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
name|kfaddr
operator|,
name|void
operator|*
name|kdaddr
operator|,
name|size_t
name|len
operator|,
name|size_t
operator|*
name|lencopied
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|copyinstr
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
name|udaddr
operator|,
name|void
operator|*
name|kaddr
operator|,
name|size_t
name|len
operator|,
name|size_t
operator|*
name|lencopied
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|copyin
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
name|udaddr
operator|,
name|void
operator|*
name|kaddr
operator|,
name|size_t
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|copyout
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
name|kaddr
operator|,
name|void
operator|*
name|udaddr
operator|,
name|size_t
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fubyte
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
name|base
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|subyte
name|__P
argument_list|(
operator|(
name|void
operator|*
name|base
operator|,
name|int
name|byte
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|suibyte
name|__P
argument_list|(
operator|(
name|void
operator|*
name|base
operator|,
name|int
name|byte
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fuword
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
name|base
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|suword
name|__P
argument_list|(
operator|(
name|void
operator|*
name|base
operator|,
name|int
name|word
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fusword
name|__P
argument_list|(
operator|(
name|void
operator|*
name|base
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|susword
name|__P
argument_list|(
operator|(
name|void
operator|*
name|base
operator|,
name|int
name|word
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|timeval
struct_decl|;
end_struct_decl

begin_decl_stmt
name|int
name|hzto
name|__P
argument_list|(
operator|(
expr|struct
name|timeval
operator|*
name|tv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|realitexpire
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|clockframe
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|hardclock
name|__P
argument_list|(
operator|(
expr|struct
name|clockframe
operator|*
name|frame
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|softclock
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|statclock
name|__P
argument_list|(
operator|(
expr|struct
name|clockframe
operator|*
name|frame
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|startprofclock
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|stopprofclock
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setstatclockrate
name|__P
argument_list|(
operator|(
name|int
name|hzrate
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|hardupdate
name|__P
argument_list|(
operator|(
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|hardpps
name|__P
argument_list|(
operator|(
expr|struct
name|timeval
operator|*
name|tvp
operator|,
name|long
name|usec
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<sys/libkern.h>
end_include

begin_comment
comment|/* Initialize the world */
end_comment

begin_decl_stmt
name|void
name|consinit
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cpu_initclocks
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nchinit
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|usrinfoinit
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vntblinit
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Finalize the world. */
end_comment

begin_decl_stmt
name|void
name|shutdown_nice
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Kernel to clock driver interface.  */
end_comment

begin_decl_stmt
name|void
name|inittodr
name|__P
argument_list|(
operator|(
name|time_t
name|base
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|resettodr
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|startrtclock
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Timeouts */
end_comment

begin_typedef
typedef|typedef
name|void
name|timeout_t
name|__P
typedef|((
name|void
modifier|*
typedef|));
end_typedef

begin_comment
comment|/* timeout function type */
end_comment

begin_define
define|#
directive|define
name|CALLOUT_HANDLE_INITIALIZER
parameter_list|(
name|handle
parameter_list|)
define|\
value|{ NULL }
end_define

begin_decl_stmt
name|void
name|callout_handle_init
name|__P
argument_list|(
operator|(
expr|struct
name|callout_handle
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|callout_handle
name|timeout
name|__P
argument_list|(
operator|(
name|timeout_t
operator|*
operator|,
name|void
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|untimeout
name|__P
argument_list|(
operator|(
name|timeout_t
operator|*
operator|,
name|void
operator|*
operator|,
expr|struct
name|callout_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Interrupt management */
end_comment

begin_function_decl
name|void
name|setdelayed
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setsoftast
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setsoftclock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setsoftnet
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setsoftcambio
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setsoftcamnet
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setsofttty
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|schedsoftnet
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|schedsofttty
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|schedsoftcamnet
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|schedsoftcambio
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|spl0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|intrmask_t
name|softclockpending
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|intrmask_t
name|splbio
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|intrmask_t
name|splclock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|intrmask_t
name|splhigh
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|intrmask_t
name|splimp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|intrmask_t
name|splnet
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_function_decl
name|intrmask_t
name|splq
parameter_list|(
name|intrmask_t
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|intrmask_t
name|splcam
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|intrmask_t
name|splsoftcam
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|intrmask_t
name|splsoftcambio
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|intrmask_t
name|splsoftcamnet
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|intrmask_t
name|splsoftclock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|intrmask_t
name|splsofttty
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|intrmask_t
name|splstatclock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|intrmask_t
name|spltty
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|intrmask_t
name|splvm
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|splx
parameter_list|(
name|intrmask_t
name|ipl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|splz
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * XXX It's not clear how "machine independent" these will be yet, but  * they are used all over the place especially in pci drivers.  We would  * have to modify lots of drivers since<machine/cpufunc.h> no longer  * implicitly causes these to be defined when it #included<machine/spl.h>  */
end_comment

begin_decl_stmt
specifier|extern
name|intrmask_t
name|bio_imask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* group of interrupts masked with splbio() */
end_comment

begin_decl_stmt
specifier|extern
name|intrmask_t
name|cam_imask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* group of interrupts masked with splcam() */
end_comment

begin_decl_stmt
specifier|extern
name|intrmask_t
name|net_imask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* group of interrupts masked with splimp() */
end_comment

begin_decl_stmt
specifier|extern
name|intrmask_t
name|stat_imask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interrupts masked with splstatclock() */
end_comment

begin_decl_stmt
specifier|extern
name|intrmask_t
name|tty_imask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* group of interrupts masked with spltty() */
end_comment

begin_comment
comment|/* Read only */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|intrmask_t
name|soft_imask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interrupts masked with splsoft*() */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|intrmask_t
name|softnet_imask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interrupt masked with splnet() */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|intrmask_t
name|softtty_imask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interrupt masked with splsofttty() */
end_comment

begin_comment
comment|/*  * Various callout lists.  */
end_comment

begin_comment
comment|/* Exit callout list declarations. */
end_comment

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*exitlist_fn
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|procp
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_decl_stmt
name|int
name|at_exit
name|__P
argument_list|(
operator|(
name|exitlist_fn
name|function
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rm_at_exit
name|__P
argument_list|(
operator|(
name|exitlist_fn
name|function
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Fork callout list declarations. */
end_comment

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*forklist_fn
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|parent
operator|,
expr|struct
name|proc
operator|*
name|child
operator|,
name|int
name|flags
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_decl_stmt
name|int
name|at_fork
name|__P
argument_list|(
operator|(
name|forklist_fn
name|function
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rm_at_fork
name|__P
argument_list|(
operator|(
name|forklist_fn
name|function
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Shutdown callout list definitions and declarations. */
end_comment

begin_define
define|#
directive|define
name|SHUTDOWN_PRE_SYNC
value|0
end_define

begin_define
define|#
directive|define
name|SHUTDOWN_POST_SYNC
value|1
end_define

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*bootlist_fn
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_decl_stmt
name|int
name|at_shutdown
name|__P
argument_list|(
operator|(
name|bootlist_fn
name|function
operator|,
name|void
operator|*
name|arg
operator|,
name|int
name|position
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rm_at_shutdown
name|__P
argument_list|(
operator|(
name|bootlist_fn
name|function
operator|,
name|void
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Not exactly a callout LIST, but a callout entry.  * Allow an external module to define a hardware watchdog tickler.  * Normally a process would do this, but there are times when the  * kernel needs to be able to hold off the watchdog, when the process  * is not active, e.g., when dumping core.  */
end_comment

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*watchdog_tickle_fn
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|extern
name|watchdog_tickle_fn
name|wdog_tickler
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * Common `proc' functions are declared here so that proc.h can be included  * less often.  */
end_comment

begin_decl_stmt
name|int
name|tsleep
name|__P
argument_list|(
operator|(
name|void
operator|*
name|chan
operator|,
name|int
name|pri
operator|,
specifier|const
name|char
operator|*
name|wmesg
operator|,
name|int
name|timo
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|wakeup
name|__P
argument_list|(
operator|(
name|void
operator|*
name|chan
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SYSTM_H_ */
end_comment

end_unit

