begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2006 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *	Implementation specific header files for atomic operations.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CL_ATOMIC_OSD_H_
end_ifndef

begin_define
define|#
directive|define
name|_CL_ATOMIC_OSD_H_
end_define

begin_include
include|#
directive|include
file|<complib/cl_types.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_spinlock.h>
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

begin_decl_stmt
name|BEGIN_C_DECLS
specifier|extern
name|cl_spinlock_t
name|cl_atomic_spinlock
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|int32_t
name|cl_atomic_inc
parameter_list|(
name|IN
name|atomic32_t
modifier|*
specifier|const
name|p_value
parameter_list|)
block|{
name|int32_t
name|new_val
decl_stmt|;
name|cl_spinlock_acquire
argument_list|(
operator|&
name|cl_atomic_spinlock
argument_list|)
expr_stmt|;
name|new_val
operator|=
operator|*
name|p_value
operator|+
literal|1
expr_stmt|;
operator|*
name|p_value
operator|=
name|new_val
expr_stmt|;
name|cl_spinlock_release
argument_list|(
operator|&
name|cl_atomic_spinlock
argument_list|)
expr_stmt|;
return|return
operator|(
name|new_val
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int32_t
name|cl_atomic_dec
parameter_list|(
name|IN
name|atomic32_t
modifier|*
specifier|const
name|p_value
parameter_list|)
block|{
name|int32_t
name|new_val
decl_stmt|;
name|cl_spinlock_acquire
argument_list|(
operator|&
name|cl_atomic_spinlock
argument_list|)
expr_stmt|;
name|new_val
operator|=
operator|*
name|p_value
operator|-
literal|1
expr_stmt|;
operator|*
name|p_value
operator|=
name|new_val
expr_stmt|;
name|cl_spinlock_release
argument_list|(
operator|&
name|cl_atomic_spinlock
argument_list|)
expr_stmt|;
return|return
operator|(
name|new_val
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int32_t
name|cl_atomic_add
parameter_list|(
name|IN
name|atomic32_t
modifier|*
specifier|const
name|p_value
parameter_list|,
name|IN
specifier|const
name|int32_t
name|increment
parameter_list|)
block|{
name|int32_t
name|new_val
decl_stmt|;
name|cl_spinlock_acquire
argument_list|(
operator|&
name|cl_atomic_spinlock
argument_list|)
expr_stmt|;
name|new_val
operator|=
operator|*
name|p_value
operator|+
name|increment
expr_stmt|;
operator|*
name|p_value
operator|=
name|new_val
expr_stmt|;
name|cl_spinlock_release
argument_list|(
operator|&
name|cl_atomic_spinlock
argument_list|)
expr_stmt|;
return|return
operator|(
name|new_val
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int32_t
name|cl_atomic_sub
parameter_list|(
name|IN
name|atomic32_t
modifier|*
specifier|const
name|p_value
parameter_list|,
name|IN
specifier|const
name|int32_t
name|decrement
parameter_list|)
block|{
name|int32_t
name|new_val
decl_stmt|;
name|cl_spinlock_acquire
argument_list|(
operator|&
name|cl_atomic_spinlock
argument_list|)
expr_stmt|;
name|new_val
operator|=
operator|*
name|p_value
operator|-
name|decrement
expr_stmt|;
operator|*
name|p_value
operator|=
name|new_val
expr_stmt|;
name|cl_spinlock_release
argument_list|(
operator|&
name|cl_atomic_spinlock
argument_list|)
expr_stmt|;
return|return
operator|(
name|new_val
operator|)
return|;
block|}
end_function

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CL_ATOMIC_OSD_H_ */
end_comment

end_unit

