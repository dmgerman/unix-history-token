begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1988, 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)systm.h	7.17 (Berkeley) 5/25/91  *	$Id: systm.h,v 1.9 1993/12/19 00:55:25 wollman Exp $  */
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
file|"sys/param.h"
end_include

begin_comment
comment|/* XXX */
end_comment

begin_include
include|#
directive|include
file|"sys/sysent.h"
end_include

begin_comment
comment|/* XXX */
end_comment

begin_comment
comment|/*  * Machine-dependent function declarations.  * These must be first in case a machine-dependent function is static  * [inline].  ANSI C's linkage scope rules require the static version  * to be visible first.  However, if the machine-dependent functions  * were actually macros, they would have to be defined last.  */
end_comment

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_comment
comment|/* Initialize the world */
end_comment

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
name|vm_mem_init
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
name|kmeminit
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
name|cpu_startup
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
name|rqinit
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
name|vm_init_limits
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
name|vfsinit
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
name|mbinit
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
name|shminit
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
name|ifinit
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
name|domaininit
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
name|swapinit
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
name|enablertclock
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default network interfaces... */
end_comment

begin_function_decl
name|void
name|slattach
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pppattach
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|loattach
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* select() support functions */
end_comment

begin_decl_stmt
name|int
name|selscan
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
name|fd_set
operator|*
operator|,
name|fd_set
operator|*
operator|,
name|int
operator|,
name|int
operator|*
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
name|int
comment|/*dev_t*/
operator|,
name|int
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|selwakeup
name|__P
argument_list|(
operator|(
name|int
comment|/*pid_t*/
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|selwait
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* select timeout address */
end_comment

begin_comment
comment|/* Interrupt masking. */
end_comment

begin_decl_stmt
name|void
name|spl0
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
name|splbio
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
name|splclock
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
name|splhigh
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
name|splimp
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
name|splnet
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|splnone
value|spl0
end_define

begin_comment
comment|/* XXX traditional; the reverse is better */
end_comment

begin_decl_stmt
name|int
name|splsoftclock
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
name|splsofttty
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
name|spltty
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
name|splx
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Scheduling */
end_comment

begin_decl_stmt
name|void
name|roundrobin
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|schedcpu
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|softclock
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|setsoftclock
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
name|setpri
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
name|swtch
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
name|vmmeter
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Timeouts and sleeps */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|timeout_func_t
function_decl|)
parameter_list|(
name|caddr_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|timeout
parameter_list|(
name|timeout_func_t
parameter_list|,
name|caddr_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|wakeup
parameter_list|(
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|untimeout
parameter_list|(
name|timeout_func_t
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tsleep
parameter_list|(
name|caddr_t
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|wakeup
parameter_list|(
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* User data reference */
end_comment

begin_decl_stmt
name|int
name|useracc
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kernacc
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|int
operator|,
name|int
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
name|void
operator|*
name|kfaddr
operator|,
name|void
operator|*
name|kdaddr
operator|,
name|u_int
name|len
operator|,
name|u_int
operator|*
name|done
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
name|void
operator|*
name|udaddr
operator|,
name|void
operator|*
name|kaddr
operator|,
name|u_int
name|len
operator|,
name|u_int
operator|*
name|done
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|copyoutstr
name|__P
argument_list|(
operator|(
name|void
operator|*
name|kaddr
operator|,
name|void
operator|*
name|udaddr
operator|,
name|u_int
name|len
operator|,
name|u_int
operator|*
name|done
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
name|void
operator|*
name|udaddr
operator|,
name|void
operator|*
name|kaddr
operator|,
name|u_int
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
name|void
operator|*
name|kaddr
operator|,
name|void
operator|*
name|udaddr
operator|,
name|u_int
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
name|void
operator|*
name|base
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_decl_stmt
name|int
name|fuibyte
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

begin_endif
endif|#
directive|endif
end_endif

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
name|void
operator|*
name|base
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fuiword
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
name|suiword
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

begin_comment
comment|/* printf() family */
end_comment

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

begin_comment
comment|/* Miscellaneous */
end_comment

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
name|void
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
name|void
name|DELAY
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
name|spinwait
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_decl_stmt
name|int
name|suser
name|__P
argument_list|(
operator|(
expr|struct
name|ucred
operator|*
operator|,
name|u_short
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Functions to return errors */
end_comment

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

begin_comment
comment|/* WARNING WILL ROBINSON */
end_comment

begin_decl_stmt
name|int
name|enodev
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* All these routines are potentially */
end_comment

begin_decl_stmt
name|int
name|enoioctl
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* called with differing arguments. */
end_comment

begin_decl_stmt
name|int
name|enxio
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

begin_comment
comment|/* routines which never return */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_typedef
typedef|typedef
name|void
name|_sched_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* sched() */
end_comment

begin_decl_stmt
name|__dead
name|_sched_t
name|sched
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
name|_kexit_t
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* kexit() */
end_comment

begin_decl_stmt
name|__dead
name|_kexit_t
name|kexit
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
name|_cpu_exit_t
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* cpu_exit() */
end_comment

begin_decl_stmt
name|__dead
name|_cpu_exit_t
name|cpu_exit
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
name|_panic_t
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* panic() */
end_comment

begin_decl_stmt
name|__dead
name|_panic_t
name|panic
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
name|_boot_t
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* boot() */
end_comment

begin_decl_stmt
name|__dead
name|_boot_t
name|boot
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sched
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
name|exit
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cpu_exit
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
name|boot
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* string functions */
end_comment

begin_decl_stmt
name|int
name|strcmp
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|strncpy
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|strcat
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|strcpy
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
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
name|u_int
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
name|void
operator|*
name|from
operator|,
name|void
operator|*
name|to
operator|,
name|u_int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bzero
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_decl_stmt
name|int
name|bcmp
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
name|str1
operator|,
specifier|const
name|void
operator|*
name|str2
operator|,
name|u_int
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
name|int
name|scanc
name|__P
argument_list|(
operator|(
name|unsigned
name|size
operator|,
name|u_char
operator|*
name|cp
operator|,
name|u_char
operator|*
name|table
operator|,
name|int
name|mask
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|skpc
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_int
operator|,
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|locc
name|__P
argument_list|(
operator|(
name|int
operator|,
name|unsigned
operator|,
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Debugger entry points */
end_comment

begin_decl_stmt
name|void
name|Debugger
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_SYSTM_H_ */
end_comment

end_unit

