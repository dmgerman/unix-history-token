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
name|struct
name|timeval
name|boottime
decl_stmt|;
end_decl_stmt

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
comment|/*  * Enumerated types for known system startup interfaces.  *  * Startup occurs in ascending numeric order; the list entries are  * sorted prior to attempting startup to guarantee order.  Items  * of the same level are arbitrated for order based on the 'order'  * element.  *  * These numbers are arbitrary and are chosen ONLY for ordering; the  * enumeration values are explicit rather than implicit to provide  * for binary compatibility with inserted elements.  *  * The SI_SUB_RUN_SCHEDULER value must have the highest lexical value.  *  * The SI_SUB_CONSOLE and SI_SUB_SWAP values represent values used by  * the BSD 4.4Lite but not by FreeBSD; they are maintained in dependent  * order to support porting.  *  * The SI_SUB_PROTO_BEGIN and SI_SUB_PROTO_END bracket a range of  * initializations to take place at splimp().  This is a historical  * wart that should be removed -- probably running everything at  * splimp() until the first init that doesn't want it is the correct  * fix.  They are currently present to ensure historical behavior.  */
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
name|SI_SUB_CONSOLE
init|=
literal|0x0800000
block|,
comment|/* console*/
name|SI_SUB_COPYRIGHT
init|=
literal|0x0800001
block|,
comment|/* first use of console*/
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
name|SI_SUB_CPU
init|=
literal|0x2000000
block|,
comment|/* CPU resource(s)*/
name|SI_SUB_KLD
init|=
literal|0x2100000
block|,
comment|/* KLD and module setup */
name|SI_SUB_DEVFS
init|=
literal|0x2200000
block|,
comment|/* get DEVFS ready */
name|SI_SUB_DRIVERS
init|=
literal|0x2300000
block|,
comment|/* Let Drivers initialize */
name|SI_SUB_CONFIGURE
init|=
literal|0x2400000
block|,
comment|/* Configure devices */
name|SI_SUB_INTRINSIC
init|=
literal|0x2800000
block|,
comment|/* proc 0*/
name|SI_SUB_RUN_QUEUE
init|=
literal|0x3000000
block|,
comment|/* the run queue*/
name|SI_SUB_VM_CONF
init|=
literal|0x3800000
block|,
comment|/* config VM, set limits*/
name|SI_SUB_VFS
init|=
literal|0x4000000
block|,
comment|/* virtual file system*/
name|SI_SUB_CLOCKS
init|=
literal|0x4800000
block|,
comment|/* real time and stat clocks*/
name|SI_SUB_MBUF
init|=
literal|0x5000000
block|,
comment|/* mbufs*/
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
name|SI_SUB_MOUNT_ROOT
init|=
literal|0xb400000
block|,
comment|/* root mount*/
name|SI_SUB_ROOT_FDTAB
init|=
literal|0xb800000
block|,
comment|/* root vnode in fd table...*/
name|SI_SUB_SWAP
init|=
literal|0xc000000
block|,
comment|/* swap*/
name|SI_SUB_INTRINSIC_POST
init|=
literal|0xd000000
block|,
comment|/* proc 0 cleanup*/
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
comment|/* idle procs*/
name|SI_SUB_RUN_SCHEDULER
init|=
literal|0xfffffff
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
block|,
comment|/* start kernel thread*/
name|SI_TYPE_KPROCESS
init|=
literal|0x00000002
comment|/* start kernel process*/
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
comment|/*  * Called on module unload: no special processing  */
end_comment

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
value|static struct sysinit uniquifier ## _sys_uninit = {	\ 		subsystem,					\ 		order,						\ 		func,						\ 		ident,						\ 		SI_TYPE_DEFAULT					\ 	};							\ 	DATA_SET(sysuninit_set,uniquifier ## _sys_uninit)
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

begin_define
define|#
directive|define
name|SYSINIT_KP
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
value|static struct sysinit uniquifier ## _sys_init = {	\ 		subsystem,					\ 		order,						\ 		func,						\ 		ident,						\ 		SI_TYPE_KPROCESS					\ 	};							\ 	DATA_SET(sysinit_set,uniquifier ## _sys_init);
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

begin_decl_stmt
name|void
name|sysinit_add
name|__P
argument_list|(
operator|(
expr|struct
name|sysinit
operator|*
operator|*
name|set
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

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_define
define|#
directive|define
name|PSEUDO_SET
parameter_list|(
name|sym
parameter_list|,
name|name
parameter_list|)
define|\
value|static int name ## _modevent(module_t mod, int type, void *data) \ 	{ \ 		void (*initfunc)(void *) = (void (*)(void *))data; \ 		switch (type) { \ 		case MOD_LOAD: \
comment|/* printf(#name " module load\n"); */
value|\ 			initfunc(NULL); \ 			break; \ 		case MOD_UNLOAD: \ 			printf(#name " module unload - not possible for this module type\n"); \ 			return EINVAL; \ 		} \ 		return 0; \ 	} \ 	static moduledata_t name ## _mod = { \ 		#name, \ 		name ## _modevent, \ 		(void *)sym \ 	}; \ 	DECLARE_MODULE(name, name ## _mod, SI_SUB_PSEUDO, SI_ORDER_ANY)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PSEUDO_LKM */
end_comment

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

