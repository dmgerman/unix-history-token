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

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/stdint.h>
end_include

begin_comment
comment|/* for people using printf mainly */
end_comment

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
comment|/* suser() is permitted to return 0 */
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
name|kstack_pages
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of kernel stack pages */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|uarea_pages
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of user struct pages */
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
name|u_int
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
name|long
name|physmem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* physical memory */
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
value|do {						\ 	if (__predict_false(!(exp)))					\ 		panic msg;						\ } while (0)
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

begin_ifndef
ifndef|#
directive|ifndef
name|CTASSERT
end_ifndef

begin_comment
comment|/* Allow lint to override */
end_comment

begin_define
define|#
directive|define
name|CTASSERT
parameter_list|(
name|x
parameter_list|)
value|_CTASSERT(x, __LINE__)
end_define

begin_define
define|#
directive|define
name|_CTASSERT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__CTASSERT(x, y)
end_define

begin_define
define|#
directive|define
name|__CTASSERT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|typedef char __assert ## y[(x) ? 1 : -1]
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
name|int
name|dynamic_kenv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sx
name|kenv_lock
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|kenvp
decl_stmt|;
end_decl_stmt

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
name|socket
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

begin_function_decl
name|int
name|setjmp
parameter_list|(
name|struct
name|_jmp_buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|longjmp
argument_list|(
expr|struct
name|_jmp_buf
operator|*
argument_list|,
name|int
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|Debugger
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|__nonnull
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|dumpstatus
parameter_list|(
name|vm_offset_t
name|addr
parameter_list|,
name|off_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nullop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eopnotsupp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ureadc
parameter_list|(
name|int
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hashdestroy
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|malloc_type
modifier|*
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|hashinit
parameter_list|(
name|int
name|count
parameter_list|,
name|struct
name|malloc_type
modifier|*
name|type
parameter_list|,
name|u_long
modifier|*
name|hashmask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|phashinit
parameter_list|(
name|int
name|count
parameter_list|,
name|struct
name|malloc_type
modifier|*
name|type
parameter_list|,
name|u_long
modifier|*
name|nentries
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|RESTARTABLE_PANICS
end_ifdef

begin_function_decl
name|void
name|__panic
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|void
name|__panic
argument_list|(
specifier|const
name|char
operator|*
name|file
argument_list|,
name|int
name|line
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|__dead2
name|__printflike
argument_list|(
literal|3
argument_list|,
literal|4
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|panic
parameter_list|(
modifier|...
parameter_list|)
value|__panic(__FILE__, __LINE__, __VA_ARGS__)
end_define

begin_function_decl
name|void
name|backtrace
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_boot
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_rootconf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|uint32_t
name|crc32_tab
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|uint32_t
name|crc32
parameter_list|(
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|critical_enter
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|critical_exit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_param1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_param2
parameter_list|(
name|long
name|physpages
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_param3
parameter_list|(
name|long
name|kmempages
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tablefull
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kvprintf
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|__va_list
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|log
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|log_console
parameter_list|(
name|struct
name|uio
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|snprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|sprintf
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|uprintf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|vprintf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|__va_list
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|vsnprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|__va_list
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|3
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|vsnrprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|__va_list
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|4
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|vsprintf
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|__va_list
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|ttyprintf
parameter_list|(
name|struct
name|tty
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|sscanf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__nonnull
parameter_list|(
function_decl|1
end_function_decl

begin_expr_stmt
unit|)
name|__nonnull
argument_list|(
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|vsscanf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|,
name|__va_list
parameter_list|)
function_decl|__nonnull
parameter_list|(
function_decl|1
end_function_decl

begin_expr_stmt
unit|)
name|__nonnull
argument_list|(
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|long
name|strtol
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|__nonnull
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|u_long
name|strtoul
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|__nonnull
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|quad_t
name|strtoq
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|__nonnull
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|u_quad_t
name|strtouq
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|__nonnull
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|tprintf
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|pri
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|hexdump
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|int
name|length
parameter_list|,
specifier|const
name|char
modifier|*
name|hdr
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|HD_COLUMN_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|HD_DELIM_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|HD_OMIT_COUNT
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|HD_OMIT_HEX
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|HD_OMIT_CHARS
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|ovbcopy
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|,
name|l
parameter_list|)
value|bcopy((f), (t), (l))
end_define

begin_function_decl
name|void
name|bcopy
parameter_list|(
specifier|const
name|void
modifier|*
name|from
parameter_list|,
name|void
modifier|*
name|to
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|__nonnull
parameter_list|(
function_decl|1
end_function_decl

begin_expr_stmt
unit|)
name|__nonnull
argument_list|(
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|bzero
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|__nonnull
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
modifier|*
name|memcpy
parameter_list|(
name|void
modifier|*
name|to
parameter_list|,
specifier|const
name|void
modifier|*
name|from
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|__nonnull
parameter_list|(
function_decl|1
end_function_decl

begin_expr_stmt
unit|)
name|__nonnull
argument_list|(
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|copystr
parameter_list|(
specifier|const
name|void
modifier|*
name|__restrict
name|kfaddr
parameter_list|,
name|void
modifier|*
name|__restrict
name|kdaddr
parameter_list|,
name|size_t
name|len
parameter_list|,
name|size_t
modifier|*
name|__restrict
name|lencopied
parameter_list|)
function_decl|__nonnull
parameter_list|(
function_decl|1
end_function_decl

begin_expr_stmt
unit|)
name|__nonnull
argument_list|(
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|copyinstr
parameter_list|(
specifier|const
name|void
modifier|*
name|__restrict
name|udaddr
parameter_list|,
name|void
modifier|*
name|__restrict
name|kaddr
parameter_list|,
name|size_t
name|len
parameter_list|,
name|size_t
modifier|*
name|__restrict
name|lencopied
parameter_list|)
function_decl|__nonnull
parameter_list|(
function_decl|1
end_function_decl

begin_expr_stmt
unit|)
name|__nonnull
argument_list|(
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|copyin
parameter_list|(
specifier|const
name|void
modifier|*
name|__restrict
name|udaddr
parameter_list|,
name|void
modifier|*
name|__restrict
name|kaddr
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|__nonnull
parameter_list|(
function_decl|1
end_function_decl

begin_expr_stmt
unit|)
name|__nonnull
argument_list|(
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|copyout
parameter_list|(
specifier|const
name|void
modifier|*
name|__restrict
name|kaddr
parameter_list|,
name|void
modifier|*
name|__restrict
name|udaddr
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|__nonnull
parameter_list|(
function_decl|1
end_function_decl

begin_expr_stmt
unit|)
name|__nonnull
argument_list|(
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|fubyte
parameter_list|(
specifier|const
name|void
modifier|*
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|fuword
parameter_list|(
specifier|const
name|void
modifier|*
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fuword16
parameter_list|(
name|void
modifier|*
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|fuword32
parameter_list|(
specifier|const
name|void
modifier|*
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int64_t
name|fuword64
parameter_list|(
specifier|const
name|void
modifier|*
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|subyte
parameter_list|(
name|void
modifier|*
name|base
parameter_list|,
name|int
name|byte
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|suword
parameter_list|(
name|void
modifier|*
name|base
parameter_list|,
name|long
name|word
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|suword16
parameter_list|(
name|void
modifier|*
name|base
parameter_list|,
name|int
name|word
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|suword32
parameter_list|(
name|void
modifier|*
name|base
parameter_list|,
name|int32_t
name|word
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|suword64
parameter_list|(
name|void
modifier|*
name|base
parameter_list|,
name|int64_t
name|word
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|intptr_t
name|casuptr
parameter_list|(
name|intptr_t
modifier|*
name|p
parameter_list|,
name|intptr_t
name|old
parameter_list|,
name|intptr_t
name|new
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|realitexpire
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hardclock
parameter_list|(
name|struct
name|clockframe
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hardclock_process
parameter_list|(
name|struct
name|clockframe
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|softclock
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|statclock
parameter_list|(
name|struct
name|clockframe
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|profclock
parameter_list|(
name|struct
name|clockframe
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|startprofclock
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stopprofclock
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_startprofclock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_stopprofclock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* flags for suser() and suser_cred() */
end_comment

begin_define
define|#
directive|define
name|PRISON_ROOT
value|1
end_define

begin_function_decl
name|int
name|suser
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|suser_cred
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cr_cansee
parameter_list|(
name|struct
name|ucred
modifier|*
name|u1
parameter_list|,
name|struct
name|ucred
modifier|*
name|u2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cr_canseesocket
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freeenv
parameter_list|(
name|char
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getenv_int
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getenv_string
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|data
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getenv_quad
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|quad_t
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setenv
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unsetenv
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|testenv
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|void
name|adjust_timeout_calltodo
parameter_list|(
name|struct
name|timeval
modifier|*
name|time_change
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|void
name|consinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_initclocks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usrinfoinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Finalize the world. */
end_comment

begin_function_decl
name|void
name|shutdown_nice
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Kernel to clock driver interface.  */
end_comment

begin_function_decl
name|void
name|inittodr
parameter_list|(
name|time_t
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|resettodr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|startrtclock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Timeouts */
end_comment

begin_typedef
typedef|typedef
name|void
name|timeout_t
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
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

begin_function_decl
name|void
name|callout_handle_init
parameter_list|(
name|struct
name|callout_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|callout_handle
name|timeout
parameter_list|(
name|timeout_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|untimeout
parameter_list|(
name|timeout_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|callout_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|caddr_t
name|kern_timeout_callwheel_alloc
parameter_list|(
name|caddr_t
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kern_timeout_callwheel_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
name|__unused
parameter_list|)
block|{
return|return;
block|}
end_function

begin_comment
comment|/*  * Various callout lists.  */
end_comment

begin_comment
comment|/*  * Not exactly a callout LIST, but a callout entry.  * Allow an external module to define a hardware watchdog tickler.  * Normally a process would do this, but there are times when the  * kernel needs to be able to hold off the watchdog, when the process  * is not active, e.g., when dumping core.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|watchdog_tickle_fn
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
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

begin_function_decl
name|int
name|msleep
parameter_list|(
name|void
modifier|*
name|chan
parameter_list|,
name|struct
name|mtx
modifier|*
name|mtx
parameter_list|,
name|int
name|pri
parameter_list|,
specifier|const
name|char
modifier|*
name|wmesg
parameter_list|,
name|int
name|timo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|abortsleep
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|void
name|wakeup
parameter_list|(
name|void
modifier|*
name|chan
parameter_list|)
function_decl|__nonnull
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|wakeup_one
parameter_list|(
name|void
modifier|*
name|chan
parameter_list|)
function_decl|__nonnull
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

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

begin_function_decl
name|void
name|DELAY
parameter_list|(
name|int
name|usec
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SYSTM_H_ */
end_comment

end_unit

