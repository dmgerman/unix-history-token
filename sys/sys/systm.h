begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1988, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)systm.h	8.7 (Berkeley) 3/29/95  * $FreeBSD$  */
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
name|__NULLABILITY_PRAGMA_PUSH
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
name|int
name|suspend_blocked
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* block suspend due to pending shutdown */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rebooting
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kern_reboot() has been called. */
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
name|compiler_version
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* compiler version */
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
name|u_long
name|pagesizes
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* supported page sizes */
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
name|long
name|realmem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 'real' memory */
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

begin_decl_stmt
specifier|extern
name|int
name|ngroups_max
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max # of supplemental groups */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vm_guest
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Running as virtual machine guest? */
end_comment

begin_comment
comment|/*  * Detected virtual machine guest types. The intention is to expand  * and/or add to the VM_GUEST_VM type if specific VM functionality is  * ever implemented (e.g. vendor-specific paravirtualization features).  * Keep in sync with vm_guest_sysctl_names[].  */
end_comment

begin_enum
enum|enum
name|VM_GUEST
block|{
name|VM_GUEST_NO
init|=
literal|0
block|,
name|VM_GUEST_VM
block|,
name|VM_GUEST_XEN
block|,
name|VM_GUEST_HV
block|,
name|VM_GUEST_VMWARE
block|,
name|VM_GUEST_KVM
block|,
name|VM_GUEST_BHYVE
block|,
name|VM_LAST
block|}
enum|;
end_enum

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WITNESS
argument_list|)
operator|||
name|defined
argument_list|(
name|INVARIANT_SUPPORT
argument_list|)
end_if

begin_function_decl
name|void
name|kassert_panic
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
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

begin_endif
endif|#
directive|endif
end_endif

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
value|do {						\ 	if (__predict_false(!(exp)))					\ 		kassert_panic msg;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|VNASSERT
parameter_list|(
name|exp
parameter_list|,
name|vp
parameter_list|,
name|msg
parameter_list|)
value|do {					\ 	if (__predict_false(!(exp))) {					\ 		vn_printf(vp, "VNASSERT failed\n");			\ 		kassert_panic msg;					\ 	}								\ } while (0)
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
value|do { \ } while (0)
end_define

begin_define
define|#
directive|define
name|VNASSERT
parameter_list|(
name|exp
parameter_list|,
name|vp
parameter_list|,
name|msg
parameter_list|)
value|do { \ } while (0)
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
value|_Static_assert(x, "compile-time assertion failed")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Assert that a pointer can be loaded from memory atomically.  *  * This assertion enforces stronger alignment than necessary.  For example,  * on some architectures, atomicity for unaligned loads will depend on  * whether or not the load spans multiple cache lines.  */
end_comment

begin_define
define|#
directive|define
name|ASSERT_ATOMIC_LOAD_PTR
parameter_list|(
name|var
parameter_list|,
name|msg
parameter_list|)
define|\
value|KASSERT(sizeof(var) == sizeof(void *)&&			\ 	    ((uintptr_t)&(var)& (sizeof(void *) - 1)) == 0, msg)
end_define

begin_comment
comment|/*  * Assert that a thread is in critical(9) section.  */
end_comment

begin_define
define|#
directive|define
name|CRITICAL_ASSERT
parameter_list|(
name|td
parameter_list|)
define|\
value|KASSERT((td)->td_critnest>= 1, ("Not in critical section"));
end_define

begin_comment
comment|/*  * If we have already panic'd and this is the thread that called  * panic(), then don't block on any mutexes but silently succeed.  * Otherwise, the kernel will deadlock since the scheduler isn't  * going to run the thread that holds any lock we need.  */
end_comment

begin_define
define|#
directive|define
name|SCHEDULER_STOPPED_TD
parameter_list|(
name|td
parameter_list|)
value|({					\ 	MPASS((td) == curthread);					\ 	__predict_false((td)->td_stopsched);				\ })
end_define

begin_define
define|#
directive|define
name|SCHEDULER_STOPPED
parameter_list|()
value|SCHEDULER_STOPPED_TD(curthread)
end_define

begin_comment
comment|/*  * Align variables.  */
end_comment

begin_define
define|#
directive|define
name|__read_mostly
value|__section(".data.read_mostly")
end_define

begin_define
define|#
directive|define
name|__exclusive_cache_line
value|__aligned(CACHE_LINE_SIZE) \ 				    __section(".data.exclusive_cache_line")
end_define

begin_comment
comment|/*  * XXX the hints declarations are even more misplaced than most declarations  * in this file, since they are needed in one file (per arch) and only used  * in two files.  * XXX most of these variables should be const.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|osreldate
decl_stmt|;
end_decl_stmt

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
name|mtx
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

begin_decl_stmt
specifier|extern
specifier|const
name|void
modifier|*
name|zero_region
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* address space maps to a zeroed page	*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|unmapped_buf_allowed
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__LP64__
end_ifdef

begin_define
define|#
directive|define
name|IOSIZE_MAX
value|iosize_max()
end_define

begin_define
define|#
directive|define
name|DEVFS_IOSIZE_MAX
value|devfs_iosize_max()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IOSIZE_MAX
value|SSIZE_MAX
end_define

begin_define
define|#
directive|define
name|DEVFS_IOSIZE_MAX
value|SSIZE_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * General function declarations.  */
end_comment

begin_struct_decl
struct_decl|struct
name|inpcb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|lock_object
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

begin_struct_decl
struct_decl|struct
name|trapframe
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|eventtimer
struct_decl|;
end_struct_decl

begin_decl_stmt
name|int
name|setjmp
argument_list|(
expr|struct
name|_jmp_buf
operator|*
argument_list|)
name|__returns_twice
decl_stmt|;
end_decl_stmt

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
name|hashinit_flags
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
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|HASH_NOWAIT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HASH_WAITOK
value|0x00000002
end_define

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

begin_function_decl
name|void
modifier|*
name|phashinit_flags
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
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_waitidle
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|panic
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
operator|...
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

begin_decl_stmt
name|void
name|vpanic
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|__va_list
argument_list|)
name|__dead2
name|__printflike
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|cpu_flush_dcache
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
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
name|init_static_kenv
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
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

begin_ifdef
ifdef|#
directive|ifdef
name|EARLY_PRINTF
end_ifdef

begin_typedef
typedef|typedef
name|void
name|early_putc_t
parameter_list|(
name|int
name|ch
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|early_putc_t
modifier|*
name|early_putc
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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
name|void
name|vlog
parameter_list|(
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
name|asprintf
parameter_list|(
name|char
modifier|*
modifier|*
name|ret
parameter_list|,
name|struct
name|malloc_type
modifier|*
name|mtp
parameter_list|,
specifier|const
name|char
modifier|*
name|format
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
name|vasprintf
parameter_list|(
name|char
modifier|*
modifier|*
name|ret
parameter_list|,
name|struct
name|malloc_type
modifier|*
name|mtp
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|__va_list
name|ap
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
name|_Nonnull
parameter_list|,
modifier|...
parameter_list|)
function_decl|__scanflike
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
name|vsscanf
parameter_list|(
specifier|const
name|char
modifier|*
name|_Nonnull
parameter_list|,
name|char
specifier|const
modifier|*
name|_Nonnull
parameter_list|,
name|__va_list
parameter_list|)
function_decl|__scanflike
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
function_decl|;
end_function_decl

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
function_decl|;
end_function_decl

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
function_decl|;
end_function_decl

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
function_decl|;
end_function_decl

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
name|vtprintf
parameter_list|(
name|struct
name|proc
modifier|*
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
function_decl|3
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|hexdump
parameter_list|(
specifier|const
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
name|_Nonnull
name|from
parameter_list|,
name|void
modifier|*
name|_Nonnull
name|to
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bzero
parameter_list|(
name|void
modifier|*
name|_Nonnull
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|explicit_bzero
parameter_list|(
name|void
modifier|*
name|_Nonnull
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|memcpy
parameter_list|(
name|void
modifier|*
name|_Nonnull
name|to
parameter_list|,
specifier|const
name|void
modifier|*
name|_Nonnull
name|from
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|memmove
parameter_list|(
name|void
modifier|*
name|_Nonnull
name|dest
parameter_list|,
specifier|const
name|void
modifier|*
name|_Nonnull
name|src
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|copystr
parameter_list|(
specifier|const
name|void
modifier|*
name|_Nonnull
name|__restrict
name|kfaddr
parameter_list|,
name|void
modifier|*
name|_Nonnull
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
function_decl|;
end_function_decl

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
name|_Nonnull
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
function_decl|;
end_function_decl

begin_function_decl
name|int
name|copyin
parameter_list|(
specifier|const
name|void
modifier|*
name|_Nonnull
name|__restrict
name|udaddr
parameter_list|,
name|void
modifier|*
name|_Nonnull
name|__restrict
name|kaddr
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|copyin_nofault
parameter_list|(
specifier|const
name|void
modifier|*
name|_Nonnull
name|__restrict
name|udaddr
parameter_list|,
name|void
modifier|*
name|_Nonnull
name|__restrict
name|kaddr
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|copyout
parameter_list|(
specifier|const
name|void
modifier|*
name|_Nonnull
name|__restrict
name|kaddr
parameter_list|,
name|void
modifier|*
name|_Nonnull
name|__restrict
name|udaddr
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|copyout_nofault
parameter_list|(
specifier|const
name|void
modifier|*
name|_Nonnull
name|__restrict
name|kaddr
parameter_list|,
name|void
modifier|*
name|_Nonnull
name|__restrict
name|udaddr
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fubyte
parameter_list|(
specifier|volatile
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
specifier|volatile
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
specifier|volatile
specifier|const
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
specifier|volatile
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
specifier|volatile
specifier|const
name|void
modifier|*
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fueword
parameter_list|(
specifier|volatile
specifier|const
name|void
modifier|*
name|base
parameter_list|,
name|long
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fueword32
parameter_list|(
specifier|volatile
specifier|const
name|void
modifier|*
name|base
parameter_list|,
name|int32_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fueword64
parameter_list|(
specifier|volatile
specifier|const
name|void
modifier|*
name|base
parameter_list|,
name|int64_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|subyte
parameter_list|(
specifier|volatile
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
specifier|volatile
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
specifier|volatile
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
specifier|volatile
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
specifier|volatile
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
name|uint32_t
name|casuword32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|base
parameter_list|,
name|uint32_t
name|oldval
parameter_list|,
name|uint32_t
name|newval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_long
name|casuword
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|,
name|u_long
name|oldval
parameter_list|,
name|u_long
name|newval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|casueword32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|base
parameter_list|,
name|uint32_t
name|oldval
parameter_list|,
name|uint32_t
modifier|*
name|oldvalp
parameter_list|,
name|uint32_t
name|newval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|casueword
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|,
name|u_long
name|oldval
parameter_list|,
name|u_long
modifier|*
name|oldvalp
parameter_list|,
name|u_long
name|newval
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
name|int
name|sysbeep
parameter_list|(
name|int
name|hertz
parameter_list|,
name|int
name|period
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hardclock
parameter_list|(
name|int
name|usermode
parameter_list|,
name|uintfptr_t
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hardclock_cnt
parameter_list|(
name|int
name|cnt
parameter_list|,
name|int
name|usermode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hardclock_cpu
parameter_list|(
name|int
name|usermode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hardclock_sync
parameter_list|(
name|int
name|cpu
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
name|int
name|usermode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|statclock_cnt
parameter_list|(
name|int
name|cnt
parameter_list|,
name|int
name|usermode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|profclock
parameter_list|(
name|int
name|usermode
parameter_list|,
name|uintfptr_t
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|profclock_cnt
parameter_list|(
name|int
name|cnt
parameter_list|,
name|int
name|usermode
parameter_list|,
name|uintfptr_t
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hardclockintr
parameter_list|(
name|void
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

begin_function_decl
name|sbintime_t
name|cpu_idleclock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_activeclock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_new_callout
parameter_list|(
name|int
name|cpu
parameter_list|,
name|sbintime_t
name|bt
parameter_list|,
name|sbintime_t
name|bt_opt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_et_frequency
parameter_list|(
name|struct
name|eventtimer
modifier|*
name|et
parameter_list|,
name|uint64_t
name|newfreq
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|cpu_disable_c2_sleep
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cpu_disable_c3_sleep
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|kern_getenv
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
name|getenv_uint
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|unsigned
name|int
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getenv_long
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|long
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getenv_ulong
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|unsigned
name|long
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
name|getenv_int64
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int64_t
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getenv_uint64
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|uint64_t
modifier|*
name|data
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
name|kern_setenv
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
name|kern_unsetenv
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

begin_typedef
typedef|typedef
name|uint64_t
function_decl|(
name|cpu_tick_f
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|set_cputicker
parameter_list|(
name|cpu_tick_f
modifier|*
name|func
parameter_list|,
name|uint64_t
name|freq
parameter_list|,
name|unsigned
name|var
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|cpu_tick_f
modifier|*
name|cpu_ticks
decl_stmt|;
end_decl_stmt

begin_function_decl
name|uint64_t
name|cpu_tickrate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|cputick2usec
parameter_list|(
name|uint64_t
name|tick
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
name|cpu_initclocks_bsp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_initclocks_ap
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
comment|/* Finalize the world */
end_comment

begin_decl_stmt
name|void
name|kern_reboot
argument_list|(
name|int
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|shutdown_nice
parameter_list|(
name|int
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

begin_comment
comment|/* Stubs for obsolete functions that used to be for interrupt management */
end_comment

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
comment|/*  * Common `proc' functions are declared here so that proc.h can be included  * less often.  */
end_comment

begin_function_decl
name|int
name|_sleep
parameter_list|(
name|void
modifier|*
name|_Nonnull
name|chan
parameter_list|,
name|struct
name|lock_object
modifier|*
name|lock
parameter_list|,
name|int
name|pri
parameter_list|,
specifier|const
name|char
modifier|*
name|wmesg
parameter_list|,
name|sbintime_t
name|sbt
parameter_list|,
name|sbintime_t
name|pr
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|msleep
parameter_list|(
name|chan
parameter_list|,
name|mtx
parameter_list|,
name|pri
parameter_list|,
name|wmesg
parameter_list|,
name|timo
parameter_list|)
define|\
value|_sleep((chan),&(mtx)->lock_object, (pri), (wmesg),		\ 	    tick_sbt * (timo), 0, C_HARDCLOCK)
end_define

begin_define
define|#
directive|define
name|msleep_sbt
parameter_list|(
name|chan
parameter_list|,
name|mtx
parameter_list|,
name|pri
parameter_list|,
name|wmesg
parameter_list|,
name|bt
parameter_list|,
name|pr
parameter_list|,
name|flags
parameter_list|)
define|\
value|_sleep((chan),&(mtx)->lock_object, (pri), (wmesg), (bt), (pr),	\ 	    (flags))
end_define

begin_function_decl
name|int
name|msleep_spin_sbt
parameter_list|(
name|void
modifier|*
name|_Nonnull
name|chan
parameter_list|,
name|struct
name|mtx
modifier|*
name|mtx
parameter_list|,
specifier|const
name|char
modifier|*
name|wmesg
parameter_list|,
name|sbintime_t
name|sbt
parameter_list|,
name|sbintime_t
name|pr
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|msleep_spin
parameter_list|(
name|chan
parameter_list|,
name|mtx
parameter_list|,
name|wmesg
parameter_list|,
name|timo
parameter_list|)
define|\
value|msleep_spin_sbt((chan), (mtx), (wmesg), tick_sbt * (timo),	\ 	    0, C_HARDCLOCK)
end_define

begin_function_decl
name|int
name|pause_sbt
parameter_list|(
specifier|const
name|char
modifier|*
name|wmesg
parameter_list|,
name|sbintime_t
name|sbt
parameter_list|,
name|sbintime_t
name|pr
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|pause
parameter_list|(
name|wmesg
parameter_list|,
name|timo
parameter_list|)
define|\
value|pause_sbt((wmesg), tick_sbt * (timo), 0, C_HARDCLOCK)
end_define

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
define|\
value|_sleep((chan), NULL, (pri), (wmesg), tick_sbt * (timo),		\ 	    0, C_HARDCLOCK)
end_define

begin_define
define|#
directive|define
name|tsleep_sbt
parameter_list|(
name|chan
parameter_list|,
name|pri
parameter_list|,
name|wmesg
parameter_list|,
name|bt
parameter_list|,
name|pr
parameter_list|,
name|flags
parameter_list|)
define|\
value|_sleep((chan), NULL, (pri), (wmesg), (bt), (pr), (flags))
end_define

begin_function_decl
name|void
name|wakeup
parameter_list|(
name|void
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wakeup_one
parameter_list|(
name|void
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Common `struct cdev *' stuff are declared here to avoid #include poisoning  */
end_comment

begin_struct_decl
struct_decl|struct
name|cdev
struct_decl|;
end_struct_decl

begin_function_decl
name|dev_t
name|dev2udev
parameter_list|(
name|struct
name|cdev
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|devtoname
parameter_list|(
name|struct
name|cdev
modifier|*
name|cdev
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__LP64__
end_ifdef

begin_function_decl
name|size_t
name|devfs_iosize_max
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|iosize_max
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|poll_no_poll
parameter_list|(
name|int
name|events
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

begin_comment
comment|/* Root mount holdback API */
end_comment

begin_struct_decl
struct_decl|struct
name|root_hold_token
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|root_hold_token
modifier|*
name|root_mount_hold
parameter_list|(
specifier|const
name|char
modifier|*
name|identifier
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|root_mount_rel
parameter_list|(
name|struct
name|root_hold_token
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|root_mounted
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Unit number allocation API. (kern/subr_unit.c)  */
end_comment

begin_struct_decl
struct_decl|struct
name|unrhdr
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|unrhdr
modifier|*
name|new_unrhdr
parameter_list|(
name|int
name|low
parameter_list|,
name|int
name|high
parameter_list|,
name|struct
name|mtx
modifier|*
name|mutex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_unrhdr
parameter_list|(
name|struct
name|unrhdr
modifier|*
name|uh
parameter_list|,
name|int
name|low
parameter_list|,
name|int
name|high
parameter_list|,
name|struct
name|mtx
modifier|*
name|mutex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|delete_unrhdr
parameter_list|(
name|struct
name|unrhdr
modifier|*
name|uh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clean_unrhdr
parameter_list|(
name|struct
name|unrhdr
modifier|*
name|uh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clean_unrhdrl
parameter_list|(
name|struct
name|unrhdr
modifier|*
name|uh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|alloc_unr
parameter_list|(
name|struct
name|unrhdr
modifier|*
name|uh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|alloc_unr_specific
parameter_list|(
name|struct
name|unrhdr
modifier|*
name|uh
parameter_list|,
name|u_int
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|alloc_unrl
parameter_list|(
name|struct
name|unrhdr
modifier|*
name|uh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_unr
parameter_list|(
name|struct
name|unrhdr
modifier|*
name|uh
parameter_list|,
name|u_int
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|intr_prof_stack_use
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|trapframe
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|counted_warning
parameter_list|(
name|unsigned
modifier|*
name|counter
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__NULLABILITY_PRAGMA_POP
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SYSTM_H_ */
end_comment

end_unit

