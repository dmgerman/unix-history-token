begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989, 1991, 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)init_main.c	8.3 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/filedesc.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/exec.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/map.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/resourcevar.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/clist.h>
end_include

begin_include
include|#
directive|include
file|<sys/device.h>
end_include

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_include
include|#
directive|include
file|<sys/reboot.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HPFPLIB
end_ifdef

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
literal|"Copyright (c) 1982, 1986, 1989, 1991, 1993\n\tThe Regents of the University of California.\nCopyright (c) 1992 Hewlett-Packard Company\nCopyright (c) 1992 Motorola Inc.\nAll rights reserved.\n\n"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
literal|"Copyright (c) 1982, 1986, 1989, 1991, 1993\n\tThe Regents of the University of California.  All rights reserved.\n\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Components of the first process -- never freed. */
end_comment

begin_decl_stmt
name|struct
name|session
name|session0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pgrp
name|pgrp0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|proc
name|proc0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pcred
name|cred0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|filedesc0
name|filedesc0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|plimit
name|limit0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vmspace
name|vmspace0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|proc
modifier|*
name|curproc
init|=
operator|&
name|proc0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|proc
modifier|*
name|initproc
decl_stmt|,
modifier|*
name|pageproc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cmask
init|=
name|CMASK
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|user
modifier|*
name|proc0paddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|rootvp
decl_stmt|,
modifier|*
name|swapdev_vp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|boothowto
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timeval
name|boottime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timeval
name|runtime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|start_init
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
name|int
operator|*
name|regs
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * System startup; initialize the world, create process 0, mount root  * filesystem, and fork to create init and pagedaemon.  Most of the  * hard work is done in the lower-level initialization routines including  * startup(), which does memory initialization and autoconfiguration.  */
end_comment

begin_function
name|main
parameter_list|(
name|regs
parameter_list|)
name|int
modifier|*
name|regs
decl_stmt|;
block|{
specifier|register
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
specifier|register
name|struct
name|filedesc0
modifier|*
name|fdp
decl_stmt|;
specifier|register
name|struct
name|pdevinit
modifier|*
name|pdev
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
name|int
name|s
decl_stmt|,
name|rval
index|[
literal|2
index|]
decl_stmt|;
extern|extern int (*mountroot
block|)
function|__P
parameter_list|(
function|(void
end_function

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pdevinit
name|pdevinit
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|roundrobin
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
specifier|extern
name|void
name|schedcpu
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 	 * Initialize the current process pointer (curproc) before 	 * any possible traps/probes to simplify trap processing. 	 */
end_comment

begin_expr_stmt
name|p
operator|=
operator|&
name|proc0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|curproc
operator|=
name|p
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 	 * Attempt to find console and initialize 	 * in case of early panic or other messages. 	 */
end_comment

begin_expr_stmt
name|consinit
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
name|copyright
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|vm_mem_init
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|kmeminit
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|cpu_startup
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Create process 0 (the swapper). */
end_comment

begin_expr_stmt
name|p
operator|=
operator|&
name|proc0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|curproc
operator|=
name|p
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|allproc
operator|=
operator|(
specifier|volatile
expr|struct
name|proc
operator|*
operator|)
name|p
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|p
operator|->
name|p_prev
operator|=
operator|(
expr|struct
name|proc
operator|*
operator|*
operator|)
operator|&
name|allproc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|p
operator|->
name|p_pgrp
operator|=
operator|&
name|pgrp0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|pgrphash
index|[
literal|0
index|]
operator|=
operator|&
name|pgrp0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|pgrp0
operator|.
name|pg_mem
operator|=
name|p
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|pgrp0
operator|.
name|pg_session
operator|=
operator|&
name|session0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|session0
operator|.
name|s_count
operator|=
literal|1
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|session0
operator|.
name|s_leader
operator|=
name|p
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|p
operator|->
name|p_flag
operator|=
name|SLOAD
operator||
name|SSYS
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|p
operator|->
name|p_stat
operator|=
name|SRUN
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|p
operator|->
name|p_nice
operator|=
name|NZERO
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bcopy
argument_list|(
literal|"swapper"
argument_list|,
name|p
operator|->
name|p_comm
argument_list|,
sizeof|sizeof
argument_list|(
literal|"swapper"
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Create credentials. */
end_comment

begin_expr_stmt
name|cred0
operator|.
name|p_refcnt
operator|=
literal|1
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|p
operator|->
name|p_cred
operator|=
operator|&
name|cred0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|p
operator|->
name|p_ucred
operator|=
name|crget
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|p
operator|->
name|p_ucred
operator|->
name|cr_ngroups
operator|=
literal|1
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* group 0 */
end_comment

begin_comment
comment|/* Create the file descriptor table. */
end_comment

begin_expr_stmt
name|fdp
operator|=
operator|&
name|filedesc0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|p
operator|->
name|p_fd
operator|=
operator|&
name|fdp
operator|->
name|fd_fd
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|fdp
operator|->
name|fd_fd
operator|.
name|fd_refcnt
operator|=
literal|1
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|fdp
operator|->
name|fd_fd
operator|.
name|fd_cmask
operator|=
name|cmask
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|fdp
operator|->
name|fd_fd
operator|.
name|fd_ofiles
operator|=
name|fdp
operator|->
name|fd_dfiles
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|fdp
operator|->
name|fd_fd
operator|.
name|fd_ofileflags
operator|=
name|fdp
operator|->
name|fd_dfileflags
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|fdp
operator|->
name|fd_fd
operator|.
name|fd_nfiles
operator|=
name|NDFILE
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Create the limits structures. */
end_comment

begin_expr_stmt
name|p
operator|->
name|p_limit
operator|=
operator|&
name|limit0
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|p
operator|->
name|p_rlimit
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|p
operator|->
name|p_rlimit
index|[
literal|0
index|]
argument_list|)
condition|;
name|i
operator|++
control|)
name|limit0
operator|.
name|pl_rlimit
index|[
name|i
index|]
operator|.
name|rlim_cur
operator|=
name|limit0
operator|.
name|pl_rlimit
index|[
name|i
index|]
operator|.
name|rlim_max
operator|=
name|RLIM_INFINITY
expr_stmt|;
end_for

begin_expr_stmt
name|limit0
operator|.
name|pl_rlimit
index|[
name|RLIMIT_NOFILE
index|]
operator|.
name|rlim_cur
operator|=
name|NOFILE
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|limit0
operator|.
name|pl_rlimit
index|[
name|RLIMIT_NPROC
index|]
operator|.
name|rlim_cur
operator|=
name|MAXUPRC
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|i
operator|=
name|ptoa
argument_list|(
name|cnt
operator|.
name|v_free_count
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|limit0
operator|.
name|pl_rlimit
index|[
name|RLIMIT_RSS
index|]
operator|.
name|rlim_max
operator|=
name|i
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|limit0
operator|.
name|pl_rlimit
index|[
name|RLIMIT_MEMLOCK
index|]
operator|.
name|rlim_max
operator|=
name|i
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|limit0
operator|.
name|pl_rlimit
index|[
name|RLIMIT_MEMLOCK
index|]
operator|.
name|rlim_cur
operator|=
name|i
operator|/
literal|3
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|limit0
operator|.
name|p_refcnt
operator|=
literal|1
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Allocate a prototype map so we have something to fork. */
end_comment

begin_expr_stmt
name|p
operator|->
name|p_vmspace
operator|=
operator|&
name|vmspace0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|vmspace0
operator|.
name|vm_refcnt
operator|=
literal|1
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|pmap_pinit
argument_list|(
operator|&
name|vmspace0
operator|.
name|vm_pmap
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|vm_map_init
argument_list|(
operator|&
name|p
operator|->
name|p_vmspace
operator|->
name|vm_map
argument_list|,
name|round_page
argument_list|(
name|VM_MIN_ADDRESS
argument_list|)
argument_list|,
name|trunc_page
argument_list|(
name|VM_MAX_ADDRESS
argument_list|)
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|vmspace0
operator|.
name|vm_map
operator|.
name|pmap
operator|=
operator|&
name|vmspace0
operator|.
name|vm_pmap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|p
operator|->
name|p_addr
operator|=
name|proc0paddr
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XXX */
end_comment

begin_comment
comment|/* 	 * We continue to place resource usage info and signal 	 * actions in the user struct so they're pageable. 	 */
end_comment

begin_expr_stmt
name|p
operator|->
name|p_stats
operator|=
operator|&
name|p
operator|->
name|p_addr
operator|->
name|u_stats
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|p
operator|->
name|p_sigacts
operator|=
operator|&
name|p
operator|->
name|p_addr
operator|->
name|u_sigacts
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 	 * Initialize per uid information structure and charge 	 * root for one process. 	 */
end_comment

begin_expr_stmt
name|usrinfoinit
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|(
name|void
operator|)
name|chgproccnt
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|rqinit
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Configure virtual memory system, set vm rlimits. */
end_comment

begin_expr_stmt
name|vm_init_limits
argument_list|(
name|p
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Initialize the file systems. */
end_comment

begin_expr_stmt
name|vfsinit
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Start real time and statistics clocks. */
end_comment

begin_expr_stmt
name|initclocks
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Initialize mbuf's. */
end_comment

begin_expr_stmt
name|mbinit
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Initialize clists. */
end_comment

begin_expr_stmt
name|clist_init
argument_list|()
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SYSVSHM
end_ifdef

begin_comment
comment|/* Initialize System V style shared memory. */
end_comment

begin_expr_stmt
name|shminit
argument_list|()
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Attach pseudo-devices. */
end_comment

begin_for
for|for
control|(
name|pdev
operator|=
name|pdevinit
init|;
name|pdev
operator|->
name|pdev_attach
operator|!=
name|NULL
condition|;
name|pdev
operator|++
control|)
call|(
modifier|*
name|pdev
operator|->
name|pdev_attach
call|)
argument_list|(
name|pdev
operator|->
name|pdev_count
argument_list|)
expr_stmt|;
end_for

begin_comment
comment|/* 	 * Initialize protocols.  Block reception of incoming packets 	 * until everything is ready. 	 */
end_comment

begin_expr_stmt
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ifinit
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|domaininit
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|GPROF
end_ifdef

begin_comment
comment|/* Initialize kernel profiling. */
end_comment

begin_expr_stmt
name|kmstartup
argument_list|()
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Kick off timeout driven events by calling first time. */
end_comment

begin_expr_stmt
name|roundrobin
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|schedcpu
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Mount the root file system. */
end_comment

begin_if
if|if
condition|(
call|(
modifier|*
name|mountroot
call|)
argument_list|()
condition|)
name|panic
argument_list|(
literal|"cannot mount root"
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|/* Get the vnode for '/'.  Set fdp->fd_fd.fd_cdir to reference it. */
end_comment

begin_if
if|if
condition|(
name|VFS_ROOT
argument_list|(
name|rootfs
argument_list|,
operator|&
name|rootvnode
argument_list|)
condition|)
name|panic
argument_list|(
literal|"cannot find root vnode"
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
name|fdp
operator|->
name|fd_fd
operator|.
name|fd_cdir
operator|=
name|rootvnode
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VREF
argument_list|(
name|fdp
operator|->
name|fd_fd
operator|.
name|fd_cdir
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VOP_UNLOCK
argument_list|(
name|rootvnode
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|fdp
operator|->
name|fd_fd
operator|.
name|fd_rdir
operator|=
name|NULL
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|swapinit
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 	 * Now can look at time, having had a chance to verify the time 	 * from the file system.  Reset p->p_rtime as it may have been 	 * munched in swtch() after the time got set. 	 */
end_comment

begin_expr_stmt
name|p
operator|->
name|p_stats
operator|->
name|p_start
operator|=
name|runtime
operator|=
name|mono_time
operator|=
name|boottime
operator|=
name|time
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|p
operator|->
name|p_rtime
operator|.
name|tv_sec
operator|=
name|p
operator|->
name|p_rtime
operator|.
name|tv_usec
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Initialize signal state for process 0. */
end_comment

begin_expr_stmt
name|siginit
argument_list|(
name|p
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Create process 1 (init(8)). */
end_comment

begin_if
if|if
condition|(
name|fork
argument_list|(
name|p
argument_list|,
name|NULL
argument_list|,
name|rval
argument_list|)
condition|)
name|panic
argument_list|(
literal|"fork init"
argument_list|)
expr_stmt|;
end_if

begin_if
if|if
condition|(
name|rval
index|[
literal|1
index|]
condition|)
block|{
name|start_init
argument_list|(
name|curproc
argument_list|,
name|regs
argument_list|)
expr_stmt|;
return|return;
block|}
end_if

begin_comment
comment|/* Create process 2 (the pageout daemon). */
end_comment

begin_if
if|if
condition|(
name|fork
argument_list|(
name|p
argument_list|,
name|NULL
argument_list|,
name|rval
argument_list|)
condition|)
name|panic
argument_list|(
literal|"fork pager"
argument_list|)
expr_stmt|;
end_if

begin_if
if|if
condition|(
name|rval
index|[
literal|1
index|]
condition|)
block|{
comment|/* 		 * Now in process 2. 		 */
name|p
operator|=
name|curproc
expr_stmt|;
name|pageproc
operator|=
name|p
expr_stmt|;
name|p
operator|->
name|p_flag
operator||=
name|SLOAD
operator||
name|SSYS
expr_stmt|;
comment|/* XXX */
name|bcopy
argument_list|(
literal|"pagedaemon"
argument_list|,
name|curproc
operator|->
name|p_comm
argument_list|,
sizeof|sizeof
argument_list|(
literal|"pagedaemon"
argument_list|)
argument_list|)
expr_stmt|;
name|vm_pageout
argument_list|()
expr_stmt|;
comment|/* NOTREACHED */
block|}
end_if

begin_comment
comment|/* The scheduler is an infinite loop. */
end_comment

begin_expr_stmt
name|scheduler
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* NOTREACHED */
end_comment

begin_comment
unit|}
comment|/*  * List of paths to try when searching for "init".  */
end_comment

begin_decl_stmt
unit|static
name|char
modifier|*
name|initpaths
index|[]
init|=
block|{
literal|"/sbin/init"
block|,
literal|"/sbin/oinit"
block|,
literal|"/sbin/init.bak"
block|,
name|NULL
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Start the initial user process; try exec'ing each pathname in "initpaths".  * The program is invoked with one argument containing the boot flags.  */
end_comment

begin_function
specifier|static
name|void
name|start_init
parameter_list|(
name|p
parameter_list|,
name|regs
parameter_list|)
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
name|int
modifier|*
name|regs
decl_stmt|;
block|{
name|vm_offset_t
name|addr
decl_stmt|;
name|struct
name|execve_args
name|args
decl_stmt|;
name|int
name|options
decl_stmt|,
name|i
decl_stmt|,
name|retval
index|[
literal|2
index|]
decl_stmt|,
name|error
decl_stmt|;
name|char
modifier|*
modifier|*
name|pathp
decl_stmt|,
modifier|*
name|path
decl_stmt|,
modifier|*
name|ucp
decl_stmt|,
modifier|*
modifier|*
name|uap
decl_stmt|,
modifier|*
name|arg0
decl_stmt|,
modifier|*
name|arg1
decl_stmt|;
comment|/* 	 * We need to set p->p_md.md_regs since start_init acts like a 	 * system call and references the regs to set the entry point 	 * (see setregs) when it tries to exec.  On regular fork, the 	 * p->p_md.md_regs of the child is undefined since it is set on 	 * each system call.  The startup code in "locore.s" has arranged 	 * that there be some place to set "p->p_md.md_regs" to, and 	 * passed a pointer to that place as main's argument. 	 */
name|p
operator|->
name|p_md
operator|.
name|md_regs
operator|=
name|regs
expr_stmt|;
comment|/* 	 * Need just enough stack to hold the faked-up "execve()" arguments. 	 */
name|addr
operator|=
name|trunc_page
argument_list|(
name|VM_MAX_ADDRESS
operator|-
name|PAGE_SIZE
argument_list|)
expr_stmt|;
if|if
condition|(
name|vm_allocate
argument_list|(
operator|&
name|p
operator|->
name|p_vmspace
operator|->
name|vm_map
argument_list|,
operator|&
name|addr
argument_list|,
name|PAGE_SIZE
argument_list|,
name|FALSE
argument_list|)
operator|!=
literal|0
condition|)
name|panic
argument_list|(
literal|"init: couldn't allocate argument space"
argument_list|)
expr_stmt|;
name|p
operator|->
name|p_vmspace
operator|->
name|vm_maxsaddr
operator|=
operator|(
name|caddr_t
operator|)
name|addr
expr_stmt|;
for|for
control|(
name|pathp
operator|=
operator|&
name|initpaths
index|[
literal|0
index|]
init|;
operator|(
name|path
operator|=
operator|*
name|pathp
operator|)
operator|!=
name|NULL
condition|;
name|pathp
operator|++
control|)
block|{
comment|/* 		 * Move out the boot flag argument. 		 */
name|options
operator|=
literal|0
expr_stmt|;
name|ucp
operator|=
operator|(
name|char
operator|*
operator|)
name|USRSTACK
expr_stmt|;
operator|(
name|void
operator|)
name|subyte
argument_list|(
operator|--
name|ucp
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* trailing zero */
if|if
condition|(
name|boothowto
operator|&
name|RB_SINGLE
condition|)
block|{
operator|(
name|void
operator|)
name|subyte
argument_list|(
operator|--
name|ucp
argument_list|,
literal|'s'
argument_list|)
expr_stmt|;
name|options
operator|=
literal|1
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|notyet
if|if
condition|(
name|boothowto
operator|&
name|RB_FASTBOOT
condition|)
block|{
operator|(
name|void
operator|)
name|subyte
argument_list|(
operator|--
name|ucp
argument_list|,
literal|'f'
argument_list|)
expr_stmt|;
name|options
operator|=
literal|1
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
name|options
operator|==
literal|0
condition|)
operator|(
name|void
operator|)
name|subyte
argument_list|(
operator|--
name|ucp
argument_list|,
literal|'-'
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|subyte
argument_list|(
operator|--
name|ucp
argument_list|,
literal|'-'
argument_list|)
expr_stmt|;
comment|/* leading hyphen */
name|arg1
operator|=
name|ucp
expr_stmt|;
comment|/* 		 * Move out the file name (also arg 0). 		 */
for|for
control|(
name|i
operator|=
name|strlen
argument_list|(
name|path
argument_list|)
operator|+
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
name|i
operator|--
control|)
operator|(
name|void
operator|)
name|subyte
argument_list|(
operator|--
name|ucp
argument_list|,
name|path
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|arg0
operator|=
name|ucp
expr_stmt|;
comment|/* 		 * Move out the arg pointers. 		 */
name|uap
operator|=
operator|(
name|char
operator|*
operator|*
operator|)
operator|(
operator|(
name|int
operator|)
name|ucp
operator|&
operator|~
operator|(
name|NBPW
operator|-
literal|1
operator|)
operator|)
expr_stmt|;
operator|(
name|void
operator|)
name|suword
argument_list|(
operator|(
name|caddr_t
operator|)
operator|--
name|uap
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* terminator */
operator|(
name|void
operator|)
name|suword
argument_list|(
operator|(
name|caddr_t
operator|)
operator|--
name|uap
argument_list|,
operator|(
name|int
operator|)
name|arg1
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|suword
argument_list|(
operator|(
name|caddr_t
operator|)
operator|--
name|uap
argument_list|,
operator|(
name|int
operator|)
name|arg0
argument_list|)
expr_stmt|;
comment|/* 		 * Point at the arguments. 		 */
name|args
operator|.
name|fname
operator|=
name|arg0
expr_stmt|;
name|args
operator|.
name|argp
operator|=
name|uap
expr_stmt|;
name|args
operator|.
name|envp
operator|=
name|NULL
expr_stmt|;
comment|/* 		 * Now try to exec the program. 		 */
if|if
condition|(
operator|(
name|error
operator|=
name|execve
argument_list|(
name|p
argument_list|,
operator|&
name|args
argument_list|,
operator|&
name|retval
argument_list|)
operator|)
operator|==
literal|0
condition|)
return|return;
if|if
condition|(
name|error
operator|!=
name|ENOENT
condition|)
block|{
comment|/* 			 * Found "init", but couldn't execute it. 			 * Complain now. 			 */
name|printf
argument_list|(
literal|"Can't invoke %s: error %d\n"
argument_list|,
name|path
argument_list|,
name|error
argument_list|)
expr_stmt|;
name|panic
argument_list|(
literal|"init error"
argument_list|)
expr_stmt|;
block|}
block|}
name|printf
argument_list|(
literal|"init: not found\n"
argument_list|)
expr_stmt|;
name|panic
argument_list|(
literal|"no init"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

