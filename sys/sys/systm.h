begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1988, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)systm.h	8.4 (Berkeley) 2/23/94  * $FreeBSD$  */
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
file|<machine/stdarg.h>
end_include

begin_comment
comment|/*  * The `securelevel' variable controls the security level of the system.  * It can only be decreased by process 1 (/sbin/init).  *  * Security levels are as follows:  *   -1	permannently insecure mode - always run system in level 0 mode.  *    0	insecure mode - immutable and append-only flags make be turned off.  *	All devices may be read or written subject to permission modes.  *    1	secure mode - immutable and append-only flags may not be changed;  *	raw disks of mounted filesystems, /dev/mem, and /dev/kmem are  *	read-only.  *    2	highly secure mode - same as (1) plus raw disks are always  *	read-only whether mounted or not. This level precludes tampering  *	with filesystems by unmounting them, but also inhibits running  *	newfs while the system is secured.  *  * In normal operation, the system runs in level 0 mode while single user  * and in level 1 mode while multiuser. If level 2 mode is desired while  * running multiuser, it can be set in the multiuser startup script  * (/etc/rc.local) using sysctl(1). If it is desired to run the system  * in level 0 mode while multiuser, initialize the variable securelevel  * in /sys/kern/kern_sysctl.c to -1. Note that it is NOT initialized to  * zero as that would allow the kernel binary to be patched to -1.  * Without initialization, securelevel loads in the BSS area which only  * comes into existence when the kernel is loaded and hence cannot be  * patched by a stalking hacker.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|securelevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system security level */
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
name|struct
name|swdevt
modifier|*
name|swdevt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* swap-device information */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nswdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of swap devices */
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
name|dev_t
name|swapdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* swapping device */
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

begin_comment
comment|/*  * General function declarations.  */
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
name|int
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
name|int
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
name|__dead
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
name|__dead
name|void
name|boot
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
name|__dead2
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
name|kprintf
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|fmt
operator|,
name|int
name|flags
operator|,
expr|struct
name|tty
operator|*
name|tp
operator|,
name|va_list
name|ap
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

begin_decl_stmt
name|void
name|blkclr
name|__P
argument_list|(
operator|(
name|void
operator|*
name|buf
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
name|buf
operator|,
name|size_t
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|initclocks
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

begin_include
include|#
directive|include
file|<sys/libkern.h>
end_include

begin_comment
comment|/* Initialize the world */
end_comment

begin_function_decl
specifier|extern
name|void
name|consinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|kmeminit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cpu_startup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|usrinfoinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rqinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vfsinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mbinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clist_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ifinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|domaininit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cpu_initclocks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vntblinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nchinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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

begin_decl_stmt
specifier|extern
name|__dead
name|void
name|vm_pageout
argument_list|(
name|void
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pagedaemon, called in proc 2 */
end_comment

begin_decl_stmt
specifier|extern
name|__dead
name|void
name|vfs_update
argument_list|(
name|void
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* update, called in proc 3 */
end_comment

begin_decl_stmt
specifier|extern
name|__dead
name|void
name|scheduler
argument_list|(
name|void
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sched, called in process 0 */
end_comment

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
function_decl|(
name|timeout_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* actual timeout function type */
end_comment

begin_typedef
typedef|typedef
name|timeout_t
modifier|*
name|timeout_func_t
typedef|;
end_typedef

begin_comment
comment|/* a pointer to this type */
end_comment

begin_function_decl
name|void
name|timeout
parameter_list|(
name|timeout_func_t
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
name|timeout_func_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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

begin_comment
comment|/* Syscalls that are called internally. */
end_comment

begin_struct
struct|struct
name|close_args
block|{
name|int
name|fd
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|close
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|close_args
operator|*
name|uap
operator|,
name|int
operator|*
name|retval
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|execve_args
block|{
name|char
modifier|*
name|fname
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
name|char
modifier|*
modifier|*
name|envv
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|execve
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|execve_args
operator|*
operator|,
name|int
operator|*
name|retval
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|fork_args
block|{
name|int
name|dummy
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|fork
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|fork_args
operator|*
operator|,
name|int
name|retval
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|sync_args
block|{
name|int
name|dummy
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|sync
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|sync_args
operator|*
operator|,
name|int
operator|*
name|retval
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|wait_args
block|{
name|int
name|pid
decl_stmt|;
name|int
modifier|*
name|status
decl_stmt|;
name|int
name|options
decl_stmt|;
name|struct
name|rusage
modifier|*
name|rusage
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|COMPAT_43
argument_list|)
operator|||
name|defined
argument_list|(
name|COMPAT_IBCS2
argument_list|)
name|int
name|compat
decl_stmt|;
comment|/* pseudo */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|wait1
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|wait_args
operator|*
operator|,
name|int
name|retval
index|[]
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

