begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Matthew Dillon.  All Rights Reserved.  Copyright   * terms are as specified in the COPYRIGHT file at the base of the source  * tree.  *  * Mutex pool routines.  These routines are designed to be used as short  * term leaf mutexes (e.g. the last mutex you might aquire other then  * calling msleep()).  They operate using a shared pool.  A mutex is chosen  * from the pool based on the supplied pointer (which may or may not be  * valid).  *  * Advantages:  *	- no structural overhead.  Mutexes can be associated with structures  *	  without adding bloat to the structures.  *	- mutexes can be obtained for invalid pointers, useful when uses  *	  mutexes to interlock destructor ops.  *	- no initialization/destructor overhead  *	- can be used with msleep.  *  * Disadvantages:  *	- should generally only be used as leaf mutexes  *	- pool/pool dependancy ordering cannot be depended on.  *	- possible L1 cache mastersip contention between cpus  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
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
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|MTX_POOL_SIZE
end_ifndef

begin_define
define|#
directive|define
name|MTX_POOL_SIZE
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MTX_POOL_MASK
value|(MTX_POOL_SIZE-1)
end_define

begin_decl_stmt
specifier|static
name|struct
name|mtx
name|mtx_pool_ary
index|[
name|MTX_POOL_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mtx_pool_valid
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Inline version of mtx_pool_find(), used to streamline our main API  * function calls.  */
end_comment

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mtx
operator|*
name|_mtx_pool_find
argument_list|(
argument|void *ptr
argument_list|)
block|{
name|int
name|p
block|;
name|p
operator|=
operator|(
name|int
operator|)
operator|(
name|uintptr_t
operator|)
name|ptr
block|;
return|return
operator|(
operator|&
name|mtx_pool_ary
index|[
operator|(
name|p
operator|^
operator|(
name|p
operator|>>
literal|6
operator|)
operator|)
operator|&
name|MTX_POOL_MASK
index|]
operator|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|void
name|mtx_pool_setup
parameter_list|(
name|void
modifier|*
name|dummy
name|__unused
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MTX_POOL_SIZE
condition|;
operator|++
name|i
control|)
name|mtx_init
argument_list|(
operator|&
name|mtx_pool_ary
index|[
name|i
index|]
argument_list|,
literal|"pool mutex"
argument_list|,
name|NULL
argument_list|,
name|MTX_DEF
operator||
name|MTX_NOWITNESS
operator||
name|MTX_QUIET
argument_list|)
expr_stmt|;
name|mtx_pool_valid
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Obtain a (shared) mutex from the pool.  The returned mutex is a leaf  * level mutex, meaning that if you obtain it you cannot obtain any other  * mutexes until you release it.  You can legally msleep() on the mutex.  */
end_comment

begin_function
name|struct
name|mtx
modifier|*
name|mtx_pool_alloc
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|int
name|si
decl_stmt|;
return|return
operator|(
operator|&
name|mtx_pool_ary
index|[
name|si
operator|++
operator|&
name|MTX_POOL_MASK
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Return the (shared) pool mutex associated with the specified address.  * The returned mutex is a leaf level mutex, meaning that if you obtain it  * you cannot obtain any other mutexes until you release it.  You can  * legally msleep() on the mutex.  */
end_comment

begin_function
name|struct
name|mtx
modifier|*
name|mtx_pool_find
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
return|return
operator|(
name|_mtx_pool_find
argument_list|(
name|ptr
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Combined find/lock operation.  Lock the pool mutex associated with  * the specified address.  */
end_comment

begin_function
name|void
name|mtx_pool_lock
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
name|mtx_lock
argument_list|(
name|_mtx_pool_find
argument_list|(
name|ptr
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Combined find/unlock operation.  Unlock the pool mutex associated with  * the specified address.  */
end_comment

begin_function
name|void
name|mtx_pool_unlock
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
name|mtx_unlock
argument_list|(
name|_mtx_pool_find
argument_list|(
name|ptr
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|SYSINIT
argument_list|(
argument|mtxpooli
argument_list|,
argument|SI_SUB_MTX_POOL
argument_list|,
argument|SI_ORDER_FIRST
argument_list|,
argument|mtx_pool_setup
argument_list|,
argument|NULL
argument_list|)
end_macro

end_unit

