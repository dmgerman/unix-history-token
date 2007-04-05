begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995 Terrence R. Lambert  * All rights reserved.  *  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)kernel.h	8.3 (Berkeley) 1/21/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_KERNEL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_KERNEL_H_
end_define

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* for intrhook below */
end_comment

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/* Global variables for the kernel. */
end_comment

begin_comment
comment|/* 1.1 */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|hostid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|hostname
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|domainname
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|kernelname
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tick
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* usec per tick (1000000 / hz) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|hz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system clock's frequency */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|psratio
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ratio: prof / stat */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|stathz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* statistics clock's frequency */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|profhz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* profiling clock's frequency */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|profprocs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of process's profiling */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ticks
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|_SOLARIS_C_SOURCE
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|lbolt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* once a second sleep address */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * Enumerated types for known system startup interfaces.  *  * Startup occurs in ascending numeric order; the list entries are  * sorted prior to attempting startup to guarantee order.  Items  * of the same level are arbitrated for order based on the 'order'  * element.  *  * These numbers are arbitrary and are chosen ONLY for ordering; the  * enumeration values are explicit rather than implicit to provide  * for binary compatibility with inserted elements.  *  * The SI_SUB_RUN_SCHEDULER value must have the highest lexical value.  *  * The SI_SUB_SWAP values represent a value used by  * the BSD 4.4Lite but not by FreeBSD; it is maintained in dependent  * order to support porting.  *  * The SI_SUB_PROTO_BEGIN and SI_SUB_PROTO_END bracket a range of  * initializations to take place at splimp().  This is a historical  * wart that should be removed -- probably running everything at  * splimp() until the first init that doesn't want it is the correct  * fix.  They are currently present to ensure historical behavior.  */
end_comment

begin_enum
enum|enum
name|sysinit_sub_id
block|{
name|SI_SUB_DUMMY
init|=
literal|0x0000000
block|,
comment|/* not executed; for linker*/
name|SI_SUB_DONE
init|=
literal|0x0000001
block|,
comment|/* processed*/
name|SI_SUB_TUNABLES
init|=
literal|0x0700000
block|,
comment|/* establish tunable values */
name|SI_SUB_COPYRIGHT
init|=
literal|0x0800001
block|,
comment|/* first use of console*/
name|SI_SUB_SETTINGS
init|=
literal|0x0880000
block|,
comment|/* check and recheck settings */
name|SI_SUB_MTX_POOL_STATIC
init|=
literal|0x0900000
block|,
comment|/* static mutex pool */
name|SI_SUB_LOCKMGR
init|=
literal|0x0980000
block|,
comment|/* lockmgr locks */
name|SI_SUB_VM
init|=
literal|0x1000000
block|,
comment|/* virtual memory system init*/
name|SI_SUB_KMEM
init|=
literal|0x1800000
block|,
comment|/* kernel memory*/
name|SI_SUB_KVM_RSRC
init|=
literal|0x1A00000
block|,
comment|/* kvm operational limits*/
name|SI_SUB_WITNESS
init|=
literal|0x1A80000
block|,
comment|/* witness initialization */
name|SI_SUB_MTX_POOL_DYNAMIC
init|=
literal|0x1AC0000
block|,
comment|/* dynamic mutex pool */
name|SI_SUB_LOCK
init|=
literal|0x1B00000
block|,
comment|/* various locks */
name|SI_SUB_EVENTHANDLER
init|=
literal|0x1C00000
block|,
comment|/* eventhandler init */
name|SI_SUB_KLD
init|=
literal|0x2000000
block|,
comment|/* KLD and module setup */
name|SI_SUB_CPU
init|=
literal|0x2100000
block|,
comment|/* CPU resource(s)*/
name|SI_SUB_MAC
init|=
literal|0x2180000
block|,
comment|/* TrustedBSD MAC subsystem */
name|SI_SUB_MAC_POLICY
init|=
literal|0x21C0000
block|,
comment|/* TrustedBSD MAC policies */
name|SI_SUB_MAC_LATE
init|=
literal|0x21D0000
block|,
comment|/* TrustedBSD MAC subsystem */
name|SI_SUB_INTRINSIC
init|=
literal|0x2200000
block|,
comment|/* proc 0*/
name|SI_SUB_VM_CONF
init|=
literal|0x2300000
block|,
comment|/* config VM, set limits*/
name|SI_SUB_RUN_QUEUE
init|=
literal|0x2400000
block|,
comment|/* set up run queue*/
name|SI_SUB_KTRACE
init|=
literal|0x2480000
block|,
comment|/* ktrace */
name|SI_SUB_AUDIT
init|=
literal|0x24C0000
block|,
comment|/* audit */
name|SI_SUB_CREATE_INIT
init|=
literal|0x2500000
block|,
comment|/* create init process*/
name|SI_SUB_SCHED_IDLE
init|=
literal|0x2600000
block|,
comment|/* required idle procs */
name|SI_SUB_MBUF
init|=
literal|0x2700000
block|,
comment|/* mbuf subsystem */
name|SI_SUB_INTR
init|=
literal|0x2800000
block|,
comment|/* interrupt threads */
name|SI_SUB_SOFTINTR
init|=
literal|0x2800001
block|,
comment|/* start soft interrupt thread */
name|SI_SUB_ACL
init|=
literal|0x2900000
block|,
comment|/* start for filesystem ACLs */
name|SI_SUB_DEVFS
init|=
literal|0x2F00000
block|,
comment|/* devfs ready for devices */
name|SI_SUB_INIT_IF
init|=
literal|0x3000000
block|,
comment|/* prep for net interfaces */
name|SI_SUB_NETGRAPH
init|=
literal|0x3010000
block|,
comment|/* Let Netgraph initialize */
name|SI_SUB_DRIVERS
init|=
literal|0x3100000
block|,
comment|/* Let Drivers initialize */
name|SI_SUB_CONFIGURE
init|=
literal|0x3800000
block|,
comment|/* Configure devices */
name|SI_SUB_VFS
init|=
literal|0x4000000
block|,
comment|/* virtual filesystem*/
name|SI_SUB_CLOCKS
init|=
literal|0x4800000
block|,
comment|/* real time and stat clocks*/
name|SI_SUB_CLIST
init|=
literal|0x5800000
block|,
comment|/* clists*/
name|SI_SUB_SYSV_SHM
init|=
literal|0x6400000
block|,
comment|/* System V shared memory*/
name|SI_SUB_SYSV_SEM
init|=
literal|0x6800000
block|,
comment|/* System V semaphores*/
name|SI_SUB_SYSV_MSG
init|=
literal|0x6C00000
block|,
comment|/* System V message queues*/
name|SI_SUB_P1003_1B
init|=
literal|0x6E00000
block|,
comment|/* P1003.1B realtime */
name|SI_SUB_PSEUDO
init|=
literal|0x7000000
block|,
comment|/* pseudo devices*/
name|SI_SUB_EXEC
init|=
literal|0x7400000
block|,
comment|/* execve() handlers */
name|SI_SUB_PROTO_BEGIN
init|=
literal|0x8000000
block|,
comment|/* XXX: set splimp (kludge)*/
name|SI_SUB_PROTO_IF
init|=
literal|0x8400000
block|,
comment|/* interfaces*/
name|SI_SUB_PROTO_DOMAIN
init|=
literal|0x8800000
block|,
comment|/* domains (address families?)*/
name|SI_SUB_PROTO_IFATTACHDOMAIN
init|=
literal|0x8800001
block|,
comment|/* domain dependent data init*/
name|SI_SUB_PROTO_END
init|=
literal|0x8ffffff
block|,
comment|/* XXX: set splx (kludge)*/
name|SI_SUB_KPROF
init|=
literal|0x9000000
block|,
comment|/* kernel profiling*/
name|SI_SUB_KICK_SCHEDULER
init|=
literal|0xa000000
block|,
comment|/* start the timeout events*/
name|SI_SUB_INT_CONFIG_HOOKS
init|=
literal|0xa800000
block|,
comment|/* Interrupts enabled config */
name|SI_SUB_ROOT_CONF
init|=
literal|0xb000000
block|,
comment|/* Find root devices */
name|SI_SUB_DUMP_CONF
init|=
literal|0xb200000
block|,
comment|/* Find dump devices */
name|SI_SUB_RAID
init|=
literal|0xb380000
block|,
comment|/* Configure GEOM classes */
name|SI_SUB_MOUNT_ROOT
init|=
literal|0xb400000
block|,
comment|/* root mount*/
name|SI_SUB_SWAP
init|=
literal|0xc000000
block|,
comment|/* swap */
name|SI_SUB_INTRINSIC_POST
init|=
literal|0xd000000
block|,
comment|/* proc 0 cleanup*/
name|SI_SUB_SYSCALLS
init|=
literal|0xd800000
block|,
comment|/* register system calls */
name|SI_SUB_KTHREAD_INIT
init|=
literal|0xe000000
block|,
comment|/* init process*/
name|SI_SUB_KTHREAD_PAGE
init|=
literal|0xe400000
block|,
comment|/* pageout daemon*/
name|SI_SUB_KTHREAD_VM
init|=
literal|0xe800000
block|,
comment|/* vm daemon*/
name|SI_SUB_KTHREAD_BUF
init|=
literal|0xea00000
block|,
comment|/* buffer daemon*/
name|SI_SUB_KTHREAD_UPDATE
init|=
literal|0xec00000
block|,
comment|/* update daemon*/
name|SI_SUB_KTHREAD_IDLE
init|=
literal|0xee00000
block|,
comment|/* idle procs*/
name|SI_SUB_SMP
init|=
literal|0xf000000
block|,
comment|/* start the APs*/
name|SI_SUB_RUN_SCHEDULER
init|=
literal|0xfffffff
comment|/* scheduler*/
block|}
enum|;
end_enum

begin_comment
comment|/*  * Some enumerated orders; "ANY" sorts last.  */
end_comment

begin_enum
enum|enum
name|sysinit_elem_order
block|{
name|SI_ORDER_FIRST
init|=
literal|0x0000000
block|,
comment|/* first*/
name|SI_ORDER_SECOND
init|=
literal|0x0000001
block|,
comment|/* second*/
name|SI_ORDER_THIRD
init|=
literal|0x0000002
block|,
comment|/* third*/
name|SI_ORDER_MIDDLE
init|=
literal|0x1000000
block|,
comment|/* somewhere in the middle */
name|SI_ORDER_ANY
init|=
literal|0xfffffff
comment|/* last*/
block|}
enum|;
end_enum

begin_comment
comment|/*  * A system initialization call instance  *  * At the moment there is one instance of sysinit.  We probably do not  * want two which is why this code is if'd out, but we definitely want  * to discern SYSINIT's which take non-constant data pointers and  * SYSINIT's which take constant data pointers,  *  * The C_* macros take functions expecting const void * arguments  * while the non-C_* macros take functions expecting just void * arguments.  *  * With -Wcast-qual on, the compiler issues warnings:  *	- if we pass non-const data or functions taking non-const data  *	  to a C_* macro.  *  *	- if we pass const data to the normal macros  *  * However, no warning is issued if we pass a function taking const data  * through a normal non-const macro.  This is ok because the function is  * saying it won't modify the data so we don't care whether the data is  * modifiable or not.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|sysinit_nfunc_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|sysinit_cfunc_t
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|sysinit
block|{
name|enum
name|sysinit_sub_id
name|subsystem
decl_stmt|;
comment|/* subsystem identifier*/
name|enum
name|sysinit_elem_order
name|order
decl_stmt|;
comment|/* init order within subsystem*/
name|sysinit_cfunc_t
name|func
decl_stmt|;
comment|/* function		*/
specifier|const
name|void
modifier|*
name|udata
decl_stmt|;
comment|/* multiplexer/argument */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Default: no special processing  *  * The C_ version of SYSINIT is for data pointers to const  * data ( and functions taking data pointers to const data ).  * At the moment it is no different from SYSINIT and thus  * still results in warnings.  *  * The casts are necessary to have the compiler produce the  * correct warnings when -Wcast-qual is used.  *  */
end_comment

begin_define
define|#
directive|define
name|C_SYSINIT
parameter_list|(
name|uniquifier
parameter_list|,
name|subsystem
parameter_list|,
name|order
parameter_list|,
name|func
parameter_list|,
name|ident
parameter_list|)
define|\
value|static struct sysinit uniquifier ## _sys_init = {	\ 		subsystem,					\ 		order,						\ 		func,						\ 		(ident)						\ 	};							\ 	DATA_SET(sysinit_set,uniquifier ## _sys_init);
end_define

begin_define
define|#
directive|define
name|SYSINIT
parameter_list|(
name|uniquifier
parameter_list|,
name|subsystem
parameter_list|,
name|order
parameter_list|,
name|func
parameter_list|,
name|ident
parameter_list|)
define|\
value|C_SYSINIT(uniquifier, subsystem, order,			\ 	(sysinit_cfunc_t)(sysinit_nfunc_t)func, (void *)(ident))
end_define

begin_comment
comment|/*  * Called on module unload: no special processing  */
end_comment

begin_define
define|#
directive|define
name|C_SYSUNINIT
parameter_list|(
name|uniquifier
parameter_list|,
name|subsystem
parameter_list|,
name|order
parameter_list|,
name|func
parameter_list|,
name|ident
parameter_list|)
define|\
value|static struct sysinit uniquifier ## _sys_uninit = {	\ 		subsystem,					\ 		order,						\ 		func,						\ 		(ident)						\ 	};							\ 	DATA_SET(sysuninit_set,uniquifier ## _sys_uninit)
end_define

begin_define
define|#
directive|define
name|SYSUNINIT
parameter_list|(
name|uniquifier
parameter_list|,
name|subsystem
parameter_list|,
name|order
parameter_list|,
name|func
parameter_list|,
name|ident
parameter_list|)
define|\
value|C_SYSUNINIT(uniquifier, subsystem, order,		\ 	(sysinit_cfunc_t)(sysinit_nfunc_t)func, (void *)(ident))
end_define

begin_function_decl
name|void
name|sysinit_add
parameter_list|(
name|struct
name|sysinit
modifier|*
modifier|*
name|set
parameter_list|,
name|struct
name|sysinit
modifier|*
modifier|*
name|set_end
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Infrastructure for tunable 'constants'.  Value may be specified at compile  * time or kernel load time.  Rules relating tunables together can be placed  * in a SYSINIT function at SI_SUB_TUNABLES with SI_ORDER_LAST.  *  * WARNING: developers should never use the reserved suffixes specified in  * loader.conf(5) for any tunables or conflicts will result.  */
end_comment

begin_comment
comment|/*  * int  * please avoid using for new tunables!  */
end_comment

begin_function_decl
specifier|extern
name|void
name|tunable_int_init
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|tunable_int
block|{
specifier|const
name|char
modifier|*
name|path
decl_stmt|;
name|int
modifier|*
name|var
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TUNABLE_INT
parameter_list|(
name|path
parameter_list|,
name|var
parameter_list|)
define|\
value|static struct tunable_int __CONCAT(__tunable_int_, __LINE__) = { \ 		(path),						\ 		(var),						\ 	};							\ 	SYSINIT(__CONCAT(__Tunable_init_, __LINE__),		\ 	    SI_SUB_TUNABLES, SI_ORDER_MIDDLE, tunable_int_init,	\&__CONCAT(__tunable_int_, __LINE__))
end_define

begin_define
define|#
directive|define
name|TUNABLE_INT_FETCH
parameter_list|(
name|path
parameter_list|,
name|var
parameter_list|)
value|getenv_int((path), (var))
end_define

begin_comment
comment|/*  * long  */
end_comment

begin_function_decl
specifier|extern
name|void
name|tunable_long_init
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|tunable_long
block|{
specifier|const
name|char
modifier|*
name|path
decl_stmt|;
name|long
modifier|*
name|var
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TUNABLE_LONG
parameter_list|(
name|path
parameter_list|,
name|var
parameter_list|)
define|\
value|static struct tunable_long __CONCAT(__tunable_long_, __LINE__) = { \ 		(path),						\ 		(var),						\ 	};							\ 	SYSINIT(__CONCAT(__Tunable_init_, __LINE__),		\ 	    SI_SUB_TUNABLES, SI_ORDER_MIDDLE, tunable_long_init,\&__CONCAT(__tunable_long_, __LINE__))
end_define

begin_define
define|#
directive|define
name|TUNABLE_LONG_FETCH
parameter_list|(
name|path
parameter_list|,
name|var
parameter_list|)
value|getenv_long((path), (var))
end_define

begin_comment
comment|/*  * unsigned long  */
end_comment

begin_function_decl
specifier|extern
name|void
name|tunable_ulong_init
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|tunable_ulong
block|{
specifier|const
name|char
modifier|*
name|path
decl_stmt|;
name|unsigned
name|long
modifier|*
name|var
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TUNABLE_ULONG
parameter_list|(
name|path
parameter_list|,
name|var
parameter_list|)
define|\
value|static struct tunable_ulong __CONCAT(__tunable_ulong_, __LINE__) = { \ 		(path),						\ 		(var),						\ 	};							\ 	SYSINIT(__CONCAT(__Tunable_init_, __LINE__),		\ 	    SI_SUB_TUNABLES, SI_ORDER_MIDDLE, tunable_ulong_init, \&__CONCAT(__tunable_ulong_, __LINE__))
end_define

begin_define
define|#
directive|define
name|TUNABLE_ULONG_FETCH
parameter_list|(
name|path
parameter_list|,
name|var
parameter_list|)
value|getenv_ulong((path), (var))
end_define

begin_function_decl
specifier|extern
name|void
name|tunable_str_init
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|tunable_str
block|{
specifier|const
name|char
modifier|*
name|path
decl_stmt|;
name|char
modifier|*
name|var
decl_stmt|;
name|int
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TUNABLE_STR
parameter_list|(
name|path
parameter_list|,
name|var
parameter_list|,
name|size
parameter_list|)
define|\
value|static struct tunable_str __CONCAT(__tunable_str_, __LINE__) = { \ 		(path),						\ 		(var),						\ 		(size),						\ 	};							\ 	SYSINIT(__CONCAT(__Tunable_init_, __LINE__),		\ 	    SI_SUB_TUNABLES, SI_ORDER_MIDDLE, tunable_str_init,	\&__CONCAT(__tunable_str_, __LINE__))
end_define

begin_define
define|#
directive|define
name|TUNABLE_STR_FETCH
parameter_list|(
name|path
parameter_list|,
name|var
parameter_list|,
name|size
parameter_list|)
define|\
value|getenv_string((path), (var), (size))
end_define

begin_function_decl
name|void
name|net_warn_not_mpsafe
parameter_list|(
specifier|const
name|char
modifier|*
name|component
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NET_NEEDS_GIANT
parameter_list|(
name|component
parameter_list|)
define|\
value|SYSINIT(__CONCAT(__net_warn_not_mpsafe_, __LINE__),		\ 	    SI_SUB_SETTINGS, SI_ORDER_SECOND, net_warn_not_mpsafe, component);
end_define

begin_struct
struct|struct
name|intr_config_hook
block|{
name|TAILQ_ENTRY
argument_list|(
argument|intr_config_hook
argument_list|)
name|ich_links
expr_stmt|;
name|void
function_decl|(
modifier|*
name|ich_func
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|void
modifier|*
name|ich_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|config_intrhook_establish
parameter_list|(
name|struct
name|intr_config_hook
modifier|*
name|hook
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|config_intrhook_disestablish
parameter_list|(
name|struct
name|intr_config_hook
modifier|*
name|hook
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_KERNEL_H_*/
end_comment

end_unit

