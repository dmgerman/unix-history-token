begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Matthew Dillon.  This code is distributed under  * the BSD copyright, /usr/src/COPYRIGHT.  *  * This file contains prototypes and high-level inlines related to  * machine-level critical function support:  *  *	cpu_critical_enter()		- inlined  *	cpu_critical_exit()		- inlined  *	cpu_critical_fork_exit()	- prototyped  *	related support functions residing  *	in<arch>/<arch>/critical.c	- prototyped  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CRITICAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CRITICAL_H_
end_define

begin_function_decl
name|__BEGIN_DECLS
comment|/*  * Prototypes - see<arch>/<arch>/critical.c  */
name|void
name|cpu_unpend
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_critical_fork_exit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_comment
comment|/*  *	cpu_critical_enter:  *  *	This routine is called from critical_enter() on the 0->1 transition  *	of td_critnest, prior to it being incremented to 1.  *  *	If new-style critical section handling we do not have to do anything.  *	However, as a side effect any interrupts occuring while td_critnest  *	is non-zero will be deferred.  */
end_comment

begin_define
define|#
directive|define
name|cpu_critical_enter
parameter_list|()
end_define

begin_comment
comment|/*  *	cpu_critical_exit:  *  *	This routine is called from critical_exit() on a 1->0 transition  *	of td_critnest, after it has been decremented to 0.  We are  *	exiting the last critical section.  *  *	Note that the td->critnest (1->0) transition interrupt race against  *	our int_pending/unpend() check below is handled by the interrupt  *	code for us, so we do not have to do anything fancy.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|cpu_critical_exit
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* 	 * We may have to schedule pending interrupts.  Create 	 * conditions similar to an interrupt context and call 	 * unpend(). 	 * 	 * note: we do this even if we are in an interrupt 	 * nesting level.  Deep nesting is protected by 	 * critical_*() and if we conditionalized it then we 	 * would have to check int_pending again whenever 	 * we decrement td_intr_nesting_level to 0. 	 */
if|if
condition|(
name|PCPU_GET
argument_list|(
name|int_pending
argument_list|)
condition|)
name|cpu_unpend
argument_list|()
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__GNUC__ */
end_comment

begin_decl_stmt
name|void
name|cpu_critical_enter
argument_list|(
name|void
argument_list|)
name|void
name|cpu_critical_exit
argument_list|(
name|void
argument_list|)
endif|#
directive|endif
comment|/* __GNUC__ */
name|__END_DECLS
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_CRITICAL_H_ */
end_comment

end_unit

