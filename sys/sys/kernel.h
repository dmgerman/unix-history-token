begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995 Terrence R. Lambert  * All rights reserved.  *  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)kernel.h	8.3 (Berkeley) 1/21/94  * $Id: kernel.h,v 1.34 1997/09/21 22:09:11 gibbs Exp $  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/* Global variables for the kernel. */
end_comment

begin_comment
comment|/* 1.1 */
end_comment

begin_decl_stmt
specifier|extern
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
name|int
name|hostnamelen
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
name|int
name|domainnamelen
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

begin_comment
comment|/* 1.2 */
end_comment

begin_decl_stmt
specifier|extern
specifier|volatile
name|struct
name|timeval
name|mono_time
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|boottime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|runtime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|time
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* nonvolatile at ipl>= splclock() */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|timezone
name|tz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX */
end_comment

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
name|tickadj
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "standard" clock skew, us./tick */
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
name|ticks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lbolt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* once a second sleep address */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tickdelta
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|timedelta
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_comment
comment|/*  * The following macros are used to declare global sets of objects, which  * are collected by the linker into a `struct linker_set' as defined below.  * For ELF, this is done by constructing a separate segment for each set.  * For a.out, it is done automatically by the linker.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ELF__
argument_list|)
end_if

begin_define
define|#
directive|define
name|MAKE_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
define|\
value|__asm__(".section .set." #set ",\"aw\"");       \ 	__asm__(".long " #sym);				\ 	__asm__(".previous")
end_define

begin_define
define|#
directive|define
name|TEXT_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
value|MAKE_SET(set, sym)
end_define

begin_define
define|#
directive|define
name|DATA_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
value|MAKE_SET(set, sym)
end_define

begin_define
define|#
directive|define
name|BSS_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
value|MAKE_SET(set, sym)
end_define

begin_define
define|#
directive|define
name|ABS_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
value|MAKE_SET(set, sym)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * NB: the constants defined below must match those defined in  * ld/ld.h.  Since their calculation requires arithmetic, we  * can't name them symbolically (e.g., 23 is N_SETT | N_EXT).  */
end_comment

begin_define
define|#
directive|define
name|MAKE_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|,
name|type
parameter_list|)
define|\
value|static void const * const __set_##set##_sym_##sym =&sym; \ 	asm(".stabs \"_" #set "\", " #type ", 0, 0, _" #sym)
end_define

begin_define
define|#
directive|define
name|TEXT_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
value|MAKE_SET(set, sym, 23)
end_define

begin_define
define|#
directive|define
name|DATA_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
value|MAKE_SET(set, sym, 25)
end_define

begin_define
define|#
directive|define
name|BSS_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
value|MAKE_SET(set, sym, 27)
end_define

begin_define
define|#
directive|define
name|ABS_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
value|MAKE_SET(set, sym, 21)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Enumerated types for known system startup interfaces.  *  * Startup occurs in ascending numeric order; the list entries are  * sorted prior to attempting startup to guarantee order.  Items  * of the same level are arbitrated for order based on the 'order'  * element.  *  * These numbers are arbitrary and are chosen ONLY for ordering; the  * enumeration values are explicit rather than implicit to provide  * for binary compatibility with inserted elements.  *  * The SI_SUB_RUN_SCHEDULER value must have the highest lexical value.  *  * The SI_SUB_CONSOLE and SI_SUB_SWAP values represent values used by  * the BSD 4.4Lite but not by FreeBSD; they are maintained in dependent  * order to support porting.  *  * The SI_SUB_PROTO_BEGIN and SI_SUB_PROTO_END bracket a range of  * initializations to take place at splimp().  This is a historical  * wart that should be removed -- probably running everything at  * splimp() until the first init that doesn't want it is the correct  * fix.  They are currently present to ensure historical behavior.  */
end_comment

begin_enum
enum|enum
name|sysinit_sub_id
block|{
name|SI_SUB_DUMMY
init|=
literal|0x00000000
block|,
comment|/* not executed; for linker*/
name|SI_SUB_CONSOLE
init|=
literal|0x08000000
block|,
comment|/* console*/
name|SI_SUB_COPYRIGHT
init|=
literal|0x08000001
block|,
comment|/* first use of console*/
name|SI_SUB_VM
init|=
literal|0x10000000
block|,
comment|/* virtual memory system init*/
name|SI_SUB_KMEM
init|=
literal|0x18000000
block|,
comment|/* kernel memory*/
name|SI_SUB_CPU
init|=
literal|0x20000000
block|,
comment|/* CPU resource(s)*/
name|SI_SUB_DEVFS
init|=
literal|0x22000000
block|,
comment|/* get DEVFS ready */
name|SI_SUB_DRIVERS
init|=
literal|0x23000000
block|,
comment|/* Let Drivers initialize */
name|SI_SUB_CONFIGURE
init|=
literal|0x24000000
block|,
comment|/* Configure devices */
name|SI_SUB_INTRINSIC
init|=
literal|0x28000000
block|,
comment|/* proc 0*/
name|SI_SUB_RUN_QUEUE
init|=
literal|0x30000000
block|,
comment|/* the run queue*/
name|SI_SUB_VM_CONF
init|=
literal|0x38000000
block|,
comment|/* config VM, set limits*/
name|SI_SUB_VFS
init|=
literal|0x40000000
block|,
comment|/* virtual file system*/
name|SI_SUB_CLOCKS
init|=
literal|0x48000000
block|,
comment|/* real time and stat clocks*/
name|SI_SUB_MBUF
init|=
literal|0x50000000
block|,
comment|/* mbufs*/
name|SI_SUB_CLIST
init|=
literal|0x58000000
block|,
comment|/* clists*/
name|SI_SUB_SYSV_SHM
init|=
literal|0x64000000
block|,
comment|/* System V shared memory*/
name|SI_SUB_SYSV_SEM
init|=
literal|0x68000000
block|,
comment|/* System V semaphores*/
name|SI_SUB_SYSV_MSG
init|=
literal|0x6C000000
block|,
comment|/* System V message queues*/
name|SI_SUB_PSEUDO
init|=
literal|0x70000000
block|,
comment|/* pseudo devices*/
name|SI_SUB_PROTO_BEGIN
init|=
literal|0x80000000
block|,
comment|/* XXX: set splimp (kludge)*/
name|SI_SUB_PROTO_IF
init|=
literal|0x84000000
block|,
comment|/* interfaces*/
name|SI_SUB_PROTO_DOMAIN
init|=
literal|0x88000000
block|,
comment|/* domains (address families?)*/
name|SI_SUB_PROTO_END
init|=
literal|0x8fffffff
block|,
comment|/* XXX: set splx (kludge)*/
name|SI_SUB_KPROF
init|=
literal|0x90000000
block|,
comment|/* kernel profiling*/
name|SI_SUB_KICK_SCHEDULER
init|=
literal|0xa0000000
block|,
comment|/* start the timeout events*/
name|SI_SUB_INT_CONFIG_HOOKS
init|=
literal|0xa8000000
block|,
comment|/* Interrupts enabled config */
name|SI_SUB_ROOT_CONF
init|=
literal|0xb0000000
block|,
comment|/* Find root devices */
name|SI_SUB_DUMP_CONF
init|=
literal|0xb2000000
block|,
comment|/* Find dump devices */
name|SI_SUB_MOUNT_ROOT
init|=
literal|0xb4000000
block|,
comment|/* root mount*/
name|SI_SUB_ROOT_FDTAB
init|=
literal|0xb8000000
block|,
comment|/* root vnode in fd table...*/
name|SI_SUB_SWAP
init|=
literal|0xc0000000
block|,
comment|/* swap*/
name|SI_SUB_INTRINSIC_POST
init|=
literal|0xd0000000
block|,
comment|/* proc 0 cleanup*/
name|SI_SUB_KTHREAD_INIT
init|=
literal|0xe0000000
block|,
comment|/* init process*/
name|SI_SUB_KTHREAD_PAGE
init|=
literal|0xe4000000
block|,
comment|/* pageout daemon*/
name|SI_SUB_KTHREAD_VM
init|=
literal|0xe8000000
block|,
comment|/* vm daemon*/
name|SI_SUB_KTHREAD_UPDATE
init|=
literal|0xec000000
block|,
comment|/* update daemon*/
name|SI_SUB_KTHREAD_IDLE
init|=
literal|0xee000000
block|,
comment|/* idle procs*/
name|SI_SUB_SMP
init|=
literal|0xf0000000
block|,
comment|/* idle procs*/
name|SI_SUB_RUN_SCHEDULER
init|=
literal|0xffffffff
comment|/* scheduler: no return*/
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
literal|0x00000000
block|,
comment|/* first*/
name|SI_ORDER_SECOND
init|=
literal|0x00000001
block|,
comment|/* second*/
name|SI_ORDER_THIRD
init|=
literal|0x00000002
block|,
comment|/* third*/
name|SI_ORDER_MIDDLE
init|=
literal|0x10000000
block|,
comment|/* somewhere in the middle */
name|SI_ORDER_ANY
init|=
literal|0xffffffff
comment|/* last*/
block|}
enum|;
end_enum

begin_comment
comment|/*  * System initialization call types; currently two are supported... one  * to do a simple function call and one to cause a process to be started  * by the kernel on the callers behalf.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|sysinit_elem_type
block|{
name|SI_TYPE_DEFAULT
init|=
literal|0x00000000
block|,
comment|/* No special processing*/
name|SI_TYPE_KTHREAD
init|=
literal|0x00000001
comment|/* start kernel thread*/
block|}
name|si_elem_t
typedef|;
end_typedef

begin_comment
comment|/*  * A system initialization call instance  *  * The subsystem  */
end_comment

begin_struct
struct|struct
name|sysinit
block|{
name|unsigned
name|int
name|subsystem
decl_stmt|;
comment|/* subsystem identifier*/
name|unsigned
name|int
name|order
decl_stmt|;
comment|/* init order within subsystem*/
name|void
argument_list|(
argument|*func
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* init function*/
name|void
modifier|*
name|udata
decl_stmt|;
comment|/* multiplexer/argument */
name|si_elem_t
name|type
decl_stmt|;
comment|/* sysinit_elem_type*/
block|}
struct|;
end_struct

begin_comment
comment|/*  * Default: no special processing  */
end_comment

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
value|static struct sysinit uniquifier ## _sys_init = {	\ 		subsystem,					\ 		order,						\ 		func,						\ 		ident,						\ 		SI_TYPE_DEFAULT					\ 	};							\ 	DATA_SET(sysinit_set,uniquifier ## _sys_init);
end_define

begin_comment
comment|/*  * Call 'fork()' before calling '(*func)(ident)';  * for making a kernel 'thread' (or builtin process.)  */
end_comment

begin_define
define|#
directive|define
name|SYSINIT_KT
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
value|static struct sysinit uniquifier ## _sys_init = {	\ 		subsystem,					\ 		order,						\ 		func,						\ 		ident,						\ 		SI_TYPE_KTHREAD					\ 	};							\ 	DATA_SET(sysinit_set,uniquifier ## _sys_init);
end_define

begin_comment
comment|/*  * A kernel process descriptor; used to start "internal" daemons  *  * Note: global_procpp may be NULL for no global save area  */
end_comment

begin_struct
struct|struct
name|kproc_desc
block|{
name|char
modifier|*
name|arg0
decl_stmt|;
comment|/* arg 0 (for 'ps' listing)*/
name|void
argument_list|(
argument|*func
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* "main" for kernel process*/
name|struct
name|proc
modifier|*
modifier|*
name|global_procpp
decl_stmt|;
comment|/* ptr to proc ptr save area*/
block|}
struct|;
end_struct

begin_decl_stmt
name|void
name|kproc_start
name|__P
argument_list|(
operator|(
name|void
operator|*
name|udata
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|PSEUDO_LKM
end_ifdef

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/exec.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_include
include|#
directive|include
file|<sys/lkm.h>
end_include

begin_define
define|#
directive|define
name|PSEUDO_SET
parameter_list|(
name|init
parameter_list|,
name|name
parameter_list|)
define|\
value|extern struct linker_set MODVNOPS; \ 	MOD_MISC(name); \ 	static int \ 	name ## _load(struct lkm_table *lkmtp, int cmd) \ 		{ init((void *)NULL
comment|/* XXX unused (?) */
value|); return 0; } \ 	static int \ 	name ## _unload(struct lkm_table *lkmtp, int cmd) \ 		{ return EINVAL; } \ 	int \ 	name ## _mod(struct lkm_table *lkmtp, int cmd, int ver) { \ 		MOD_DISPATCH(name, lkmtp, cmd, ver, name ## _load, name ## _unload, \ 			 lkm_nullcmd); } \ 	struct __hack
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* PSEUDO_LKM */
end_comment

begin_comment
comment|/*  * Compatibility.  To be deprecated after LKM is updated.  */
end_comment

begin_define
define|#
directive|define
name|PSEUDO_SET
parameter_list|(
name|sym
parameter_list|,
name|name
parameter_list|)
value|SYSINIT(ps, SI_SUB_PSEUDO, SI_ORDER_ANY, sym, 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PSEUDO_LKM */
end_comment

begin_struct
struct|struct
name|linker_set
block|{
name|int
name|ls_length
decl_stmt|;
specifier|const
name|void
modifier|*
name|ls_items
index|[
literal|1
index|]
decl_stmt|;
comment|/* really ls_length of them, 						 * trailing NULL */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|linker_set
name|execsw_set
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_KERNEL_H_*/
end_comment

end_unit

