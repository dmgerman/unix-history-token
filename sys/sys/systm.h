begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1988, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)systm.h	8.7 (Berkeley) 3/29/95  * $FreeBSD$  */
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
file|<machine/atomic.h>
end_include

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
name|suser_enabled
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* suser_xxx() is permitted to return 0 */
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
name|dumping
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system is dumping */
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
name|nswap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of swap space */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nselcoll
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* select collisions since boot */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|sellock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* select lock variable */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cv
name|selwait
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* select conditional variable */
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
name|dev_t
name|rootdevs
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* possible root devices */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rootdevnames
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* names of possible root devices */
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

begin_decl_stmt
specifier|extern
name|int
name|maxusers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system tune hint */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

begin_comment
comment|/* The option is always available */
end_comment

begin_define
define|#
directive|define
name|KASSERT
parameter_list|(
name|exp
parameter_list|,
name|msg
parameter_list|)
value|do { if (!(exp)) panic msg; } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KASSERT
parameter_list|(
name|exp
parameter_list|,
name|msg
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * XXX the hints declarations are even more misplaced than most declarations  * in this file, since they are needed in one file (per arch) and only used  * in two files.  * XXX most of these variables should be const.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|envmode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hintmode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0 = off. 1 = config, 2 = fallback */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|kern_envp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|static_env
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|static_hints
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* by config for now */
end_comment

begin_comment
comment|/*  * General function declarations.  */
end_comment

begin_struct_decl
struct_decl|struct
name|clockframe
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|malloc_type
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mtx
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|kse
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tty
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_jmp_buf
struct_decl|;
end_struct_decl

begin_decl_stmt
name|int
name|setjmp
name|__P
argument_list|(
operator|(
expr|struct
name|_jmp_buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|longjmp
name|__P
argument_list|(
operator|(
expr|struct
name|_jmp_buf
operator|*
operator|,
name|int
operator|)
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

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
name|dumpstatus
name|__P
argument_list|(
operator|(
name|vm_offset_t
name|addr
operator|,
name|off_t
name|count
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
name|thread
operator|*
name|td
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

begin_ifdef
ifdef|#
directive|ifdef
name|RESTARTABLE_PANICS
end_ifdef

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
name|__printflike
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

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
name|__printflike
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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
name|critical_enter
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
name|critical_exit
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
name|init_param1
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
name|init_param2
name|__P
argument_list|(
operator|(
name|int
name|physpages
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
name|__printflike
argument_list|(
literal|1
argument_list|,
literal|0
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
name|__printflike
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|log_console
name|__P
argument_list|(
operator|(
expr|struct
name|uio
operator|*
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
name|__printflike
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|snprintf
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|size_t
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|__printflike
argument_list|(
literal|3
argument_list|,
literal|4
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
name|__printflike
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
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
name|__printflike
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
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
name|__printflike
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vsnprintf
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|size_t
operator|,
specifier|const
name|char
operator|*
operator|,
name|_BSD_VA_LIST_
operator|)
argument_list|)
name|__printflike
argument_list|(
literal|3
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vsprintf
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
name|_BSD_VA_LIST_
operator|)
argument_list|)
name|__printflike
argument_list|(
literal|2
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
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
name|__printflike
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sscanf
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vsscanf
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|_BSD_VA_LIST_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|strtol
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|strtoul
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|quad_t
name|strtoq
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_quad_t
name|strtouq
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tprintf
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
name|int
name|pri
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|__printflike
argument_list|(
literal|3
argument_list|,
literal|4
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

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

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

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|void
name|bzero
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
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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
name|long
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
name|long
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
name|hardclock_process
name|__P
argument_list|(
operator|(
expr|struct
name|thread
operator|*
name|td
operator|,
name|int
name|user
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
operator|*
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
name|statclock_process
name|__P
argument_list|(
operator|(
expr|struct
name|kse
operator|*
name|ke
operator|,
name|register_t
name|pc
operator|,
name|int
name|user
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

begin_comment
comment|/* flags for suser_xxx() */
end_comment

begin_define
define|#
directive|define
name|PRISON_ROOT
value|1
end_define

begin_decl_stmt
name|int
name|suser
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
name|int
name|suser_td
name|__P
argument_list|(
operator|(
expr|struct
name|thread
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|suser_xxx
name|__P
argument_list|(
operator|(
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|proc
operator|,
name|int
name|flag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|suser_xxx_td
name|__P
argument_list|(
operator|(
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|thread
operator|*
name|thread
operator|,
name|int
name|flag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cr_cansee
name|__P
argument_list|(
operator|(
expr|struct
name|ucred
operator|*
name|u1
operator|,
expr|struct
name|ucred
operator|*
name|u2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|getenv
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getenv_int
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|,
name|int
operator|*
name|data
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getenv_string
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|,
name|char
operator|*
name|data
operator|,
name|int
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getenv_quad
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|,
name|quad_t
operator|*
name|data
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|APM_FIXUP_CALLTODO
end_ifdef

begin_struct_decl
struct_decl|struct
name|timeval
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|adjust_timeout_calltodo
name|__P
argument_list|(
operator|(
expr|struct
name|timeval
operator|*
name|time_change
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APM_FIXUP_CALLTODO */
end_comment

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
name|usrinfoinit
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
name|int
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

begin_decl_stmt
name|caddr_t
name|kern_timeout_callwheel_alloc
name|__P
argument_list|(
operator|(
name|caddr_t
name|v
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|kern_timeout_callwheel_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Stubs for obsolete functions that used to be for interrupt  management */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|spl0
parameter_list|(
name|void
parameter_list|)
block|{
return|return;
block|}
end_function

begin_function
specifier|static
name|__inline
name|intrmask_t
name|splbio
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|intrmask_t
name|splcam
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|intrmask_t
name|splclock
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|intrmask_t
name|splhigh
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|intrmask_t
name|splimp
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|intrmask_t
name|splnet
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|intrmask_t
name|splsoftcam
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|intrmask_t
name|splsoftclock
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|intrmask_t
name|splsofttty
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|intrmask_t
name|splsoftvm
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|intrmask_t
name|splsofttq
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|intrmask_t
name|splstatclock
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|intrmask_t
name|spltty
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|intrmask_t
name|splvm
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|splx
parameter_list|(
name|intrmask_t
name|ipl
parameter_list|)
block|{
return|return;
block|}
end_function

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
comment|/* Exec callout list declarations. */
end_comment

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*execlist_fn
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
name|at_exec
name|__P
argument_list|(
operator|(
name|execlist_fn
name|function
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rm_at_exec
name|__P
argument_list|(
operator|(
name|execlist_fn
name|function
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
name|msleep
name|__P
argument_list|(
operator|(
name|void
operator|*
name|chan
operator|,
expr|struct
name|mtx
operator|*
name|mtx
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

begin_define
define|#
directive|define
name|tsleep
parameter_list|(
name|chan
parameter_list|,
name|pri
parameter_list|,
name|wmesg
parameter_list|,
name|timo
parameter_list|)
value|msleep(chan, NULL, pri, wmesg, timo)
end_define

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

begin_decl_stmt
name|void
name|wakeup_one
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

begin_comment
comment|/*  * Common `dev_t' stuff are declared here to avoid #include poisoning  */
end_comment

begin_function_decl
name|int
name|major
parameter_list|(
name|dev_t
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|minor
parameter_list|(
name|dev_t
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dev_t
name|makedev
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|udev_t
name|dev2udev
parameter_list|(
name|dev_t
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dev_t
name|udev2dev
parameter_list|(
name|udev_t
name|x
parameter_list|,
name|int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uminor
parameter_list|(
name|udev_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umajor
parameter_list|(
name|udev_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|udev_t
name|makeudev
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX: Should be void nanodelay(u_int nsec); */
end_comment

begin_decl_stmt
name|void
name|DELAY
name|__P
argument_list|(
operator|(
name|int
name|usec
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

