begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)param.c	8.3 (Berkeley) 8/20/94  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"opt_param.h"
end_include

begin_include
include|#
directive|include
file|"opt_msgbuf.h"
end_include

begin_include
include|#
directive|include
file|"opt_maxusers.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/limits.h>
end_include

begin_include
include|#
directive|include
file|<sys/msgbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_comment
comment|/*  * System parameter formulae.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HZ
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips__
argument_list|)
operator|||
name|defined
argument_list|(
name|__arm__
argument_list|)
end_if

begin_define
define|#
directive|define
name|HZ
value|100
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HZ
value|1000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HZ_VM
end_ifndef

begin_define
define|#
directive|define
name|HZ_VM
value|100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|HZ_VM
end_ifndef

begin_define
define|#
directive|define
name|HZ_VM
value|HZ
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NPROC
value|(20 + 16 * maxusers)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NBUF
end_ifndef

begin_define
define|#
directive|define
name|NBUF
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXFILES
end_ifndef

begin_define
define|#
directive|define
name|MAXFILES
value|(40 + 32 * maxusers)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|static
name|int
name|sysctl_kern_vm_guest
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|hz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system clock's frequency */
end_comment

begin_decl_stmt
name|int
name|tick
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* usec per tick (1000000 / hz) */
end_comment

begin_decl_stmt
name|struct
name|bintime
name|tick_bt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bintime per tick (1s / hz) */
end_comment

begin_decl_stmt
name|sbintime_t
name|tick_sbt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|maxusers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* base tunable */
end_comment

begin_decl_stmt
name|int
name|maxproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum # of processes */
end_comment

begin_decl_stmt
name|int
name|maxprocperuid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max # of procs per user */
end_comment

begin_decl_stmt
name|int
name|maxfiles
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sys. wide open files limit */
end_comment

begin_decl_stmt
name|int
name|maxfilesperproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* per-proc open files limit */
end_comment

begin_decl_stmt
name|int
name|msgbufsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of kernel message buffer */
end_comment

begin_decl_stmt
name|int
name|nbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bio_transient_maxcnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ngroups_max
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max # groups per process */
end_comment

begin_decl_stmt
name|int
name|nswbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pid_t
name|pid_max
init|=
name|PID_MAX
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|maxswzone
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max swmeta KVA storage */
end_comment

begin_decl_stmt
name|long
name|maxbcache
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max buffer cache KVA storage */
end_comment

begin_decl_stmt
name|long
name|maxpipekva
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Limit on pipe KVA */
end_comment

begin_decl_stmt
name|int
name|vm_guest
init|=
name|VM_GUEST_NO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Running as virtual machine guest? */
end_comment

begin_decl_stmt
name|u_long
name|maxtsiz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max text size */
end_comment

begin_decl_stmt
name|u_long
name|dfldsiz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial data size limit */
end_comment

begin_decl_stmt
name|u_long
name|maxdsiz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max data size */
end_comment

begin_decl_stmt
name|u_long
name|dflssiz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial stack size limit */
end_comment

begin_decl_stmt
name|u_long
name|maxssiz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max stack size */
end_comment

begin_decl_stmt
name|u_long
name|sgrowsiz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* amount to grow stack */
end_comment

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_kern
argument_list|,
name|OID_AUTO
argument_list|,
name|hz
argument_list|,
name|CTLFLAG_RDTUN
operator||
name|CTLFLAG_NOFETCH
argument_list|,
operator|&
name|hz
argument_list|,
literal|0
argument_list|,
literal|"Number of clock ticks per second"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_kern
argument_list|,
name|OID_AUTO
argument_list|,
name|nbuf
argument_list|,
name|CTLFLAG_RDTUN
operator||
name|CTLFLAG_NOFETCH
argument_list|,
operator|&
name|nbuf
argument_list|,
literal|0
argument_list|,
literal|"Number of buffers in the buffer cache"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_kern
argument_list|,
name|OID_AUTO
argument_list|,
name|nswbuf
argument_list|,
name|CTLFLAG_RDTUN
operator||
name|CTLFLAG_NOFETCH
argument_list|,
operator|&
name|nswbuf
argument_list|,
literal|0
argument_list|,
literal|"Number of swap buffers"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_kern
argument_list|,
name|OID_AUTO
argument_list|,
name|msgbufsize
argument_list|,
name|CTLFLAG_RDTUN
operator||
name|CTLFLAG_NOFETCH
argument_list|,
operator|&
name|msgbufsize
argument_list|,
literal|0
argument_list|,
literal|"Size of the kernel message buffer"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_LONG
argument_list|(
name|_kern
argument_list|,
name|OID_AUTO
argument_list|,
name|maxswzone
argument_list|,
name|CTLFLAG_RDTUN
operator||
name|CTLFLAG_NOFETCH
argument_list|,
operator|&
name|maxswzone
argument_list|,
literal|0
argument_list|,
literal|"Maximum memory for swap metadata"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_LONG
argument_list|(
name|_kern
argument_list|,
name|OID_AUTO
argument_list|,
name|maxbcache
argument_list|,
name|CTLFLAG_RDTUN
operator||
name|CTLFLAG_NOFETCH
argument_list|,
operator|&
name|maxbcache
argument_list|,
literal|0
argument_list|,
literal|"Maximum value of vfs.maxbufspace"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_kern
argument_list|,
name|OID_AUTO
argument_list|,
name|bio_transient_maxcnt
argument_list|,
name|CTLFLAG_RDTUN
operator||
name|CTLFLAG_NOFETCH
argument_list|,
operator|&
name|bio_transient_maxcnt
argument_list|,
literal|0
argument_list|,
literal|"Maximum number of transient BIOs mappings"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_ULONG
argument_list|(
name|_kern
argument_list|,
name|OID_AUTO
argument_list|,
name|maxtsiz
argument_list|,
name|CTLFLAG_RWTUN
operator||
name|CTLFLAG_NOFETCH
argument_list|,
operator|&
name|maxtsiz
argument_list|,
literal|0
argument_list|,
literal|"Maximum text size"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_ULONG
argument_list|(
name|_kern
argument_list|,
name|OID_AUTO
argument_list|,
name|dfldsiz
argument_list|,
name|CTLFLAG_RWTUN
operator||
name|CTLFLAG_NOFETCH
argument_list|,
operator|&
name|dfldsiz
argument_list|,
literal|0
argument_list|,
literal|"Initial data size limit"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_ULONG
argument_list|(
name|_kern
argument_list|,
name|OID_AUTO
argument_list|,
name|maxdsiz
argument_list|,
name|CTLFLAG_RWTUN
operator||
name|CTLFLAG_NOFETCH
argument_list|,
operator|&
name|maxdsiz
argument_list|,
literal|0
argument_list|,
literal|"Maximum data size"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_ULONG
argument_list|(
name|_kern
argument_list|,
name|OID_AUTO
argument_list|,
name|dflssiz
argument_list|,
name|CTLFLAG_RWTUN
operator||
name|CTLFLAG_NOFETCH
argument_list|,
operator|&
name|dflssiz
argument_list|,
literal|0
argument_list|,
literal|"Initial stack size limit"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_ULONG
argument_list|(
name|_kern
argument_list|,
name|OID_AUTO
argument_list|,
name|maxssiz
argument_list|,
name|CTLFLAG_RWTUN
operator||
name|CTLFLAG_NOFETCH
argument_list|,
operator|&
name|maxssiz
argument_list|,
literal|0
argument_list|,
literal|"Maximum stack size"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_ULONG
argument_list|(
name|_kern
argument_list|,
name|OID_AUTO
argument_list|,
name|sgrowsiz
argument_list|,
name|CTLFLAG_RWTUN
operator||
name|CTLFLAG_NOFETCH
argument_list|,
operator|&
name|sgrowsiz
argument_list|,
literal|0
argument_list|,
literal|"Amount to grow stack on a stack fault"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_PROC
argument_list|(
name|_kern
argument_list|,
name|OID_AUTO
argument_list|,
name|vm_guest
argument_list|,
name|CTLFLAG_RD
operator||
name|CTLTYPE_STRING
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
name|sysctl_kern_vm_guest
argument_list|,
literal|"A"
argument_list|,
literal|"Virtual machine guest detected?"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * The elements of this array are ordered based upon the values of the  * corresponding enum VM_GUEST members.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|vm_guest_sysctl_names
index|[]
init|=
block|{
literal|"none"
block|,
literal|"generic"
block|,
literal|"xen"
block|,
literal|"hv"
block|,
literal|"vmware"
block|,
literal|"kvm"
block|,
literal|"bhyve"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|CTASSERT
argument_list|(
name|nitems
argument_list|(
name|vm_guest_sysctl_names
argument_list|)
operator|-
literal|1
operator|==
name|VM_LAST
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Boot time overrides that are not scaled against main memory  */
end_comment

begin_function
name|void
name|init_param1
parameter_list|(
name|void
parameter_list|)
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__mips__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__arm64__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__sparc64__
argument_list|)
name|TUNABLE_INT_FETCH
argument_list|(
literal|"kern.kstack_pages"
argument_list|,
operator|&
name|kstack_pages
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|hz
operator|=
operator|-
literal|1
expr_stmt|;
name|TUNABLE_INT_FETCH
argument_list|(
literal|"kern.hz"
argument_list|,
operator|&
name|hz
argument_list|)
expr_stmt|;
if|if
condition|(
name|hz
operator|==
operator|-
literal|1
condition|)
name|hz
operator|=
name|vm_guest
operator|>
name|VM_GUEST_NO
condition|?
name|HZ_VM
else|:
name|HZ
expr_stmt|;
name|tick
operator|=
literal|1000000
operator|/
name|hz
expr_stmt|;
name|tick_sbt
operator|=
name|SBT_1S
operator|/
name|hz
expr_stmt|;
name|tick_bt
operator|=
name|sbttobt
argument_list|(
name|tick_sbt
argument_list|)
expr_stmt|;
comment|/* 	 * Arrange for ticks to wrap 10 minutes after boot to help catch 	 * sign problems sooner. 	 */
name|ticks
operator|=
name|INT_MAX
operator|-
operator|(
name|hz
operator|*
literal|10
operator|*
literal|60
operator|)
expr_stmt|;
ifdef|#
directive|ifdef
name|VM_SWZONE_SIZE_MAX
name|maxswzone
operator|=
name|VM_SWZONE_SIZE_MAX
expr_stmt|;
endif|#
directive|endif
name|TUNABLE_LONG_FETCH
argument_list|(
literal|"kern.maxswzone"
argument_list|,
operator|&
name|maxswzone
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|VM_BCACHE_SIZE_MAX
name|maxbcache
operator|=
name|VM_BCACHE_SIZE_MAX
expr_stmt|;
endif|#
directive|endif
name|TUNABLE_LONG_FETCH
argument_list|(
literal|"kern.maxbcache"
argument_list|,
operator|&
name|maxbcache
argument_list|)
expr_stmt|;
name|msgbufsize
operator|=
name|MSGBUF_SIZE
expr_stmt|;
name|TUNABLE_INT_FETCH
argument_list|(
literal|"kern.msgbufsize"
argument_list|,
operator|&
name|msgbufsize
argument_list|)
expr_stmt|;
name|maxtsiz
operator|=
name|MAXTSIZ
expr_stmt|;
name|TUNABLE_ULONG_FETCH
argument_list|(
literal|"kern.maxtsiz"
argument_list|,
operator|&
name|maxtsiz
argument_list|)
expr_stmt|;
name|dfldsiz
operator|=
name|DFLDSIZ
expr_stmt|;
name|TUNABLE_ULONG_FETCH
argument_list|(
literal|"kern.dfldsiz"
argument_list|,
operator|&
name|dfldsiz
argument_list|)
expr_stmt|;
name|maxdsiz
operator|=
name|MAXDSIZ
expr_stmt|;
name|TUNABLE_ULONG_FETCH
argument_list|(
literal|"kern.maxdsiz"
argument_list|,
operator|&
name|maxdsiz
argument_list|)
expr_stmt|;
name|dflssiz
operator|=
name|DFLSSIZ
expr_stmt|;
name|TUNABLE_ULONG_FETCH
argument_list|(
literal|"kern.dflssiz"
argument_list|,
operator|&
name|dflssiz
argument_list|)
expr_stmt|;
name|maxssiz
operator|=
name|MAXSSIZ
expr_stmt|;
name|TUNABLE_ULONG_FETCH
argument_list|(
literal|"kern.maxssiz"
argument_list|,
operator|&
name|maxssiz
argument_list|)
expr_stmt|;
name|sgrowsiz
operator|=
name|SGROWSIZ
expr_stmt|;
name|TUNABLE_ULONG_FETCH
argument_list|(
literal|"kern.sgrowsiz"
argument_list|,
operator|&
name|sgrowsiz
argument_list|)
expr_stmt|;
comment|/* 	 * Let the administrator set {NGROUPS_MAX}, but disallow values 	 * less than NGROUPS_MAX which would violate POSIX.1-2008 or 	 * greater than INT_MAX-1 which would result in overflow. 	 */
name|ngroups_max
operator|=
name|NGROUPS_MAX
expr_stmt|;
name|TUNABLE_INT_FETCH
argument_list|(
literal|"kern.ngroups"
argument_list|,
operator|&
name|ngroups_max
argument_list|)
expr_stmt|;
if|if
condition|(
name|ngroups_max
operator|<
name|NGROUPS_MAX
condition|)
name|ngroups_max
operator|=
name|NGROUPS_MAX
expr_stmt|;
comment|/* 	 * Only allow to lower the maximal pid. 	 * Prevent setting up a non-bootable system if pid_max is too low. 	 */
name|TUNABLE_INT_FETCH
argument_list|(
literal|"kern.pid_max"
argument_list|,
operator|&
name|pid_max
argument_list|)
expr_stmt|;
if|if
condition|(
name|pid_max
operator|>
name|PID_MAX
condition|)
name|pid_max
operator|=
name|PID_MAX
expr_stmt|;
elseif|else
if|if
condition|(
name|pid_max
operator|<
literal|300
condition|)
name|pid_max
operator|=
literal|300
expr_stmt|;
name|TUNABLE_INT_FETCH
argument_list|(
literal|"vfs.unmapped_buf_allowed"
argument_list|,
operator|&
name|unmapped_buf_allowed
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Boot time overrides that are scaled against main memory  */
end_comment

begin_function
name|void
name|init_param2
parameter_list|(
name|long
name|physpages
parameter_list|)
block|{
comment|/* Base parameters */
name|maxusers
operator|=
name|MAXUSERS
expr_stmt|;
name|TUNABLE_INT_FETCH
argument_list|(
literal|"kern.maxusers"
argument_list|,
operator|&
name|maxusers
argument_list|)
expr_stmt|;
if|if
condition|(
name|maxusers
operator|==
literal|0
condition|)
block|{
name|maxusers
operator|=
name|physpages
operator|/
operator|(
literal|2
operator|*
literal|1024
operator|*
literal|1024
operator|/
name|PAGE_SIZE
operator|)
expr_stmt|;
if|if
condition|(
name|maxusers
operator|<
literal|32
condition|)
name|maxusers
operator|=
literal|32
expr_stmt|;
ifdef|#
directive|ifdef
name|VM_MAX_AUTOTUNE_MAXUSERS
if|if
condition|(
name|maxusers
operator|>
name|VM_MAX_AUTOTUNE_MAXUSERS
condition|)
name|maxusers
operator|=
name|VM_MAX_AUTOTUNE_MAXUSERS
expr_stmt|;
endif|#
directive|endif
comment|/*                  * Scales down the function in which maxusers grows once                  * we hit 384.                  */
if|if
condition|(
name|maxusers
operator|>
literal|384
condition|)
name|maxusers
operator|=
literal|384
operator|+
operator|(
operator|(
name|maxusers
operator|-
literal|384
operator|)
operator|/
literal|8
operator|)
expr_stmt|;
block|}
comment|/* 	 * The following can be overridden after boot via sysctl.  Note: 	 * unless overriden, these macros are ultimately based on maxusers. 	 * Limit maxproc so that kmap entries cannot be exhausted by 	 * processes. 	 */
name|maxproc
operator|=
name|NPROC
expr_stmt|;
name|TUNABLE_INT_FETCH
argument_list|(
literal|"kern.maxproc"
argument_list|,
operator|&
name|maxproc
argument_list|)
expr_stmt|;
if|if
condition|(
name|maxproc
operator|>
operator|(
name|physpages
operator|/
literal|12
operator|)
condition|)
name|maxproc
operator|=
name|physpages
operator|/
literal|12
expr_stmt|;
if|if
condition|(
name|maxproc
operator|>
name|pid_max
condition|)
name|maxproc
operator|=
name|pid_max
expr_stmt|;
name|maxprocperuid
operator|=
operator|(
name|maxproc
operator|*
literal|9
operator|)
operator|/
literal|10
expr_stmt|;
comment|/* 	 * The default limit for maxfiles is 1/12 of the number of 	 * physical page but not less than 16 times maxusers. 	 * At most it can be 1/6 the number of physical pages. 	 */
name|maxfiles
operator|=
name|imax
argument_list|(
name|MAXFILES
argument_list|,
name|physpages
operator|/
literal|8
argument_list|)
expr_stmt|;
name|TUNABLE_INT_FETCH
argument_list|(
literal|"kern.maxfiles"
argument_list|,
operator|&
name|maxfiles
argument_list|)
expr_stmt|;
if|if
condition|(
name|maxfiles
operator|>
operator|(
name|physpages
operator|/
literal|4
operator|)
condition|)
name|maxfiles
operator|=
name|physpages
operator|/
literal|4
expr_stmt|;
name|maxfilesperproc
operator|=
operator|(
name|maxfiles
operator|/
literal|10
operator|)
operator|*
literal|9
expr_stmt|;
name|TUNABLE_INT_FETCH
argument_list|(
literal|"kern.maxfilesperproc"
argument_list|,
operator|&
name|maxfilesperproc
argument_list|)
expr_stmt|;
comment|/* 	 * Cannot be changed after boot. 	 */
name|nbuf
operator|=
name|NBUF
expr_stmt|;
name|TUNABLE_INT_FETCH
argument_list|(
literal|"kern.nbuf"
argument_list|,
operator|&
name|nbuf
argument_list|)
expr_stmt|;
name|TUNABLE_INT_FETCH
argument_list|(
literal|"kern.bio_transient_maxcnt"
argument_list|,
operator|&
name|bio_transient_maxcnt
argument_list|)
expr_stmt|;
comment|/* 	 * The default for maxpipekva is min(1/64 of the kernel address space, 	 * max(1/64 of main memory, 512KB)).  See sys_pipe.c for more details. 	 */
name|maxpipekva
operator|=
operator|(
name|physpages
operator|/
literal|64
operator|)
operator|*
name|PAGE_SIZE
expr_stmt|;
name|TUNABLE_LONG_FETCH
argument_list|(
literal|"kern.ipc.maxpipekva"
argument_list|,
operator|&
name|maxpipekva
argument_list|)
expr_stmt|;
if|if
condition|(
name|maxpipekva
operator|<
literal|512
operator|*
literal|1024
condition|)
name|maxpipekva
operator|=
literal|512
operator|*
literal|1024
expr_stmt|;
if|if
condition|(
name|maxpipekva
operator|>
operator|(
name|VM_MAX_KERNEL_ADDRESS
operator|-
name|VM_MIN_KERNEL_ADDRESS
operator|)
operator|/
literal|64
condition|)
name|maxpipekva
operator|=
operator|(
name|VM_MAX_KERNEL_ADDRESS
operator|-
name|VM_MIN_KERNEL_ADDRESS
operator|)
operator|/
literal|64
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Sysctl stringifying handler for kern.vm_guest.  */
end_comment

begin_function
specifier|static
name|int
name|sysctl_kern_vm_guest
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
block|{
return|return
operator|(
name|SYSCTL_OUT_STR
argument_list|(
name|req
argument_list|,
name|vm_guest_sysctl_names
index|[
name|vm_guest
index|]
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

