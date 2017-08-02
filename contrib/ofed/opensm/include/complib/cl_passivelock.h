begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2010 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *	This file contains the passive lock, which synchronizes passive threads.  *	The passive lock allows multiple readers to access a resource  *	simultaneously, exclusive from a single thread allowed writing.  * Several writer threads are allowed - but only one can write at a given time  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CL_PASSIVE_LOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_CL_PASSIVE_LOCK_H_
end_define

begin_include
include|#
directive|include
file|<complib/cl_types.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
value|extern "C" {
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__cplusplus */
end_comment

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_macro
name|BEGIN_C_DECLS
end_macro

begin_comment
comment|/****h* Component Library/Passive Lock * NAME *	Passive Lock * * DESCRIPTION *	The Passive Lock provides synchronization between multiple threads that *	are sharing the lock with a single thread holding the lock exclusively. * *	Passive lock works exclusively between threads and cannot be used in *	situations where the caller cannot be put into a waiting state. * *	The passive lock functions operate a cl_plock_t structure which should *	be treated as opaque and should be manipulated only through the provided *	functions. * * SEE ALSO *	Structures: *		cl_plock_t * *	Initialization: *		cl_plock_construct, cl_plock_init, cl_plock_destroy * *	Manipulation *		cl_plock_acquire, cl_plock_excl_acquire, cl_plock_release *********/
end_comment

begin_comment
comment|/****s* Component Library: Passive Lock/cl_plock_t * NAME *	cl_plock_t * * DESCRIPTION *	Passive Lock structure. * *	The cl_plock_t structure should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_cl_plock
block|{
name|pthread_rwlock_t
name|lock
decl_stmt|;
name|cl_state_t
name|state
decl_stmt|;
block|}
name|cl_plock_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	lock *		Pthread RWLOCK object * *	state *		Records the current state of the lock, such as initialized, *		destroying, etc. * * SEE ALSO *	Passive Lock *********/
end_comment

begin_comment
comment|/****f* Component Library: Passive Lock/cl_plock_construct * NAME *	cl_plock_construct * * DESCRIPTION *	The cl_plock_construct function initializes the state of a *	passive lock. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|cl_plock_construct
parameter_list|(
name|IN
name|cl_plock_t
modifier|*
specifier|const
name|p_lock
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_lock
argument_list|)
expr_stmt|;
name|p_lock
operator|->
name|state
operator|=
name|CL_UNINITIALIZED
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_lock *		[in] Pointer to a cl_plock_t structure whose state to initialize. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Allows calling cl_plock_destroy without first calling cl_plock_init. * *	Calling cl_plock_construct is a prerequisite to calling any other *	passive lock function except cl_plock_init. * * SEE ALSO *	Passive Lock, cl_plock_init, cl_plock_destroy *********/
end_comment

begin_comment
comment|/****f* Component Library: Passive Lock/cl_plock_destroy * NAME *	cl_plock_destroy * * DESCRIPTION *	The cl_plock_destroy function performs any necessary cleanup *	of a passive lock. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|cl_plock_destroy
parameter_list|(
name|IN
name|cl_plock_t
modifier|*
specifier|const
name|p_lock
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_lock
argument_list|)
expr_stmt|;
name|p_lock
operator|->
name|state
operator|=
name|CL_DESTROYING
expr_stmt|;
name|pthread_rwlock_destroy
argument_list|(
operator|&
name|p_lock
operator|->
name|lock
argument_list|)
expr_stmt|;
name|p_lock
operator|->
name|state
operator|=
name|CL_DESTROYED
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_lock *		[in] Pointer to a cl_plock_t structure whose state to initialize. * * RETURN VALUE *	This function does not return a value. * * NOTES *	cl_plock_destroy performs any necessary cleanup of the specified *	passive lock. * *	This function must only be called if cl_plock_construct or *	cl_plock_init has been called. The passive lock must not be held *	when calling this function. * * SEE ALSO *	Passive Lock, cl_plock_construct, cl_plock_init *********/
end_comment

begin_comment
comment|/****f* Component Library: Passive Lock/cl_plock_init * NAME *	cl_plock_init * * DESCRIPTION *	The cl_plock_init function initializes a passive lock. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|cl_status_t
name|cl_plock_init
parameter_list|(
name|IN
name|cl_plock_t
modifier|*
specifier|const
name|p_lock
parameter_list|)
block|{
name|cl_status_t
name|status
decl_stmt|;
name|CL_ASSERT
argument_list|(
name|p_lock
argument_list|)
expr_stmt|;
name|status
operator|=
name|pthread_rwlock_init
argument_list|(
operator|&
name|p_lock
operator|->
name|lock
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
condition|)
return|return
name|CL_ERROR
return|;
name|p_lock
operator|->
name|state
operator|=
name|CL_INITIALIZED
expr_stmt|;
return|return
operator|(
name|CL_SUCCESS
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_lock *		[in] Pointer to a cl_plock_t structure to initialize. * * RETURN VALUES *	CL_SUCCESS if the passive lock was initialized successfully. * *	CL_ERROR otherwise. * * NOTES *	Allows calling cl_plock_acquire, cl_plock_release, *	cl_plock_excl_acquire * * SEE ALSO *	Passive Lock, cl_plock_construct, cl_plock_destroy, *	cl_plock_excl_acquire, cl_plock_acquire, cl_plock_release *********/
end_comment

begin_comment
comment|/****f* Component Library: Passive Lock/cl_plock_acquire * NAME *	cl_plock_acquire * * DESCRIPTION *	The cl_plock_acquire function acquires a passive lock for *	shared access. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|cl_plock_acquire
parameter_list|(
name|IN
name|cl_plock_t
modifier|*
specifier|const
name|p_lock
parameter_list|)
block|{
name|cl_status_t
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
name|status
decl_stmt|;
name|CL_ASSERT
argument_list|(
name|p_lock
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_lock
operator|->
name|state
operator|==
name|CL_INITIALIZED
argument_list|)
expr_stmt|;
name|status
operator|=
name|pthread_rwlock_rdlock
argument_list|(
operator|&
name|p_lock
operator|->
name|lock
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|status
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_lock *		[in] Pointer to a cl_plock_t structure to acquire. * * RETURN VALUE *	This function does not return a value. * * SEE ALSO *	Passive Lock, cl_plock_release, cl_plock_excl_acquire *********/
end_comment

begin_comment
comment|/****f* Component Library: Passive Lock/cl_plock_excl_acquire * NAME *	cl_plock_excl_acquire * * DESCRIPTION *	The cl_plock_excl_acquire function acquires exclusive access *	to a passive lock. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|cl_plock_excl_acquire
parameter_list|(
name|IN
name|cl_plock_t
modifier|*
specifier|const
name|p_lock
parameter_list|)
block|{
name|cl_status_t
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
name|status
decl_stmt|;
name|CL_ASSERT
argument_list|(
name|p_lock
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_lock
operator|->
name|state
operator|==
name|CL_INITIALIZED
argument_list|)
expr_stmt|;
name|status
operator|=
name|pthread_rwlock_wrlock
argument_list|(
operator|&
name|p_lock
operator|->
name|lock
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|status
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_lock *		[in] Pointer to a cl_plock_t structure to acquire exclusively. * * RETURN VALUE *	This function does not return a value. * * SEE ALSO *	Passive Lock, cl_plock_release, cl_plock_acquire *********/
end_comment

begin_comment
comment|/****f* Component Library: Passive Lock/cl_plock_release * NAME *	cl_plock_release * * DESCRIPTION *	The cl_plock_release function releases a passive lock from *	shared or exclusive access. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|cl_plock_release
parameter_list|(
name|IN
name|cl_plock_t
modifier|*
specifier|const
name|p_lock
parameter_list|)
block|{
name|cl_status_t
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
name|status
decl_stmt|;
name|CL_ASSERT
argument_list|(
name|p_lock
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_lock
operator|->
name|state
operator|==
name|CL_INITIALIZED
argument_list|)
expr_stmt|;
name|status
operator|=
name|pthread_rwlock_unlock
argument_list|(
operator|&
name|p_lock
operator|->
name|lock
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|status
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_lock *		[in] Pointer to a cl_plock_t structure to release. * * RETURN VALUE *	This function does not return a value. * * SEE ALSO *	Passive Lock, cl_plock_acquire, cl_plock_excl_acquire *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CL_PASSIVE_LOCK_H_ */
end_comment

end_unit

