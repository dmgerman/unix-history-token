begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994 John Dyson  * Copyright (c) 2001 Matt Dillon  *  * All rights reserved.  Terms for use and redistribution  * are covered by the BSD Copyright as found in /usr/src/COPYRIGHT.  *  *	from: @(#)vm_machdep.c	7.3 (Berkeley) 5/13/91  *	Utah $Hdr: vm_machdep.c 1.16.1.1 89/06/23$  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"opt_npx.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_include
include|#
directive|include
file|"opt_pc98.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"opt_reset.h"
end_include

begin_include
include|#
directive|include
file|"opt_isa.h"
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
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/bio.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sys/vmmeter.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/ktr.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/unistd.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/pcb.h>
end_include

begin_include
include|#
directive|include
file|<machine/pcb_ext.h>
end_include

begin_include
include|#
directive|include
file|<machine/vm86.h>
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
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_kern.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_page.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_map.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_extern.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_include
include|#
directive|include
file|<pc98/pc98/pc98.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<i386/isa/isa.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_vm_stats_misc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|int
name|cnt_prezero
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_vm_stats_misc
argument_list|,
name|OID_AUTO
argument_list|,
name|cnt_prezero
argument_list|,
name|CTLFLAG_RD
argument_list|,
operator|&
name|cnt_prezero
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Implement the pre-zeroed page mechanism.  * This routine is called from the idle loop.  */
end_comment

begin_define
define|#
directive|define
name|ZIDLE_LO
parameter_list|(
name|v
parameter_list|)
value|((v) * 2 / 3)
end_define

begin_define
define|#
directive|define
name|ZIDLE_HI
parameter_list|(
name|v
parameter_list|)
value|((v) * 4 / 5)
end_define

begin_function
name|int
name|vm_page_zero_idle
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|int
name|free_rover
decl_stmt|;
specifier|static
name|int
name|zero_state
decl_stmt|;
name|vm_page_t
name|m
decl_stmt|;
comment|/* 	 * Attempt to maintain approximately 1/2 of our free pages in a 	 * PG_ZERO'd state.   Add some hysteresis to (attempt to) avoid 	 * generally zeroing a page when the system is near steady-state. 	 * Otherwise we might get 'flutter' during disk I/O / IPC or  	 * fast sleeps.  We also do not want to be continuously zeroing 	 * pages because doing so may flush our L1 and L2 caches too much. 	 */
if|if
condition|(
name|zero_state
operator|&&
name|vm_page_zero_count
operator|>=
name|ZIDLE_LO
argument_list|(
name|cnt
operator|.
name|v_free_count
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
name|vm_page_zero_count
operator|>=
name|ZIDLE_HI
argument_list|(
name|cnt
operator|.
name|v_free_count
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
name|mtx_trylock
argument_list|(
operator|&
name|Giant
argument_list|)
condition|)
block|{
name|zero_state
operator|=
literal|0
expr_stmt|;
name|m
operator|=
name|vm_pageq_find
argument_list|(
name|PQ_FREE
argument_list|,
name|free_rover
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
operator|!=
name|NULL
operator|&&
operator|(
name|m
operator|->
name|flags
operator|&
name|PG_ZERO
operator|)
operator|==
literal|0
condition|)
block|{
name|vm_page_queues
index|[
name|m
operator|->
name|queue
index|]
operator|.
name|lcnt
operator|--
expr_stmt|;
name|TAILQ_REMOVE
argument_list|(
operator|&
name|vm_page_queues
index|[
name|m
operator|->
name|queue
index|]
operator|.
name|pl
argument_list|,
name|m
argument_list|,
name|pageq
argument_list|)
expr_stmt|;
name|m
operator|->
name|queue
operator|=
name|PQ_NONE
expr_stmt|;
name|pmap_zero_page
argument_list|(
name|VM_PAGE_TO_PHYS
argument_list|(
name|m
argument_list|)
argument_list|)
expr_stmt|;
name|vm_page_flag_set
argument_list|(
name|m
argument_list|,
name|PG_ZERO
argument_list|)
expr_stmt|;
name|m
operator|->
name|queue
operator|=
name|PQ_FREE
operator|+
name|m
operator|->
name|pc
expr_stmt|;
name|vm_page_queues
index|[
name|m
operator|->
name|queue
index|]
operator|.
name|lcnt
operator|++
expr_stmt|;
name|TAILQ_INSERT_TAIL
argument_list|(
operator|&
name|vm_page_queues
index|[
name|m
operator|->
name|queue
index|]
operator|.
name|pl
argument_list|,
name|m
argument_list|,
name|pageq
argument_list|)
expr_stmt|;
operator|++
name|vm_page_zero_count
expr_stmt|;
operator|++
name|cnt_prezero
expr_stmt|;
if|if
condition|(
name|vm_page_zero_count
operator|>=
name|ZIDLE_HI
argument_list|(
name|cnt
operator|.
name|v_free_count
argument_list|)
condition|)
name|zero_state
operator|=
literal|1
expr_stmt|;
block|}
name|free_rover
operator|=
operator|(
name|free_rover
operator|+
name|PQ_PRIME2
operator|)
operator|&
name|PQ_L2_MASK
expr_stmt|;
name|mtx_unlock
argument_list|(
operator|&
name|Giant
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

