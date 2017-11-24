begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2006 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CONFIG_H */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_types.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_debug.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_spinlock.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/*  *  Prototypes  */
end_comment

begin_function_decl
specifier|extern
name|cl_status_t
name|__cl_timer_prov_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__cl_timer_prov_destroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|cl_spinlock_t
name|cl_atomic_spinlock
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|complib_init
parameter_list|(
name|void
parameter_list|)
block|{
name|cl_status_t
name|status
init|=
name|CL_SUCCESS
decl_stmt|;
name|status
operator|=
name|cl_spinlock_init
argument_list|(
operator|&
name|cl_atomic_spinlock
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
name|CL_SUCCESS
condition|)
goto|goto
name|_error
goto|;
name|status
operator|=
name|__cl_timer_prov_create
argument_list|()
expr_stmt|;
if|if
condition|(
name|status
operator|!=
name|CL_SUCCESS
condition|)
goto|goto
name|_error
goto|;
return|return;
name|_error
label|:
name|cl_msg_out
argument_list|(
literal|"__init: failed to create complib (%s)\n"
argument_list|,
name|CL_STATUS_MSG
argument_list|(
name|status
argument_list|)
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|complib_exit
parameter_list|(
name|void
parameter_list|)
block|{
name|__cl_timer_prov_destroy
argument_list|()
expr_stmt|;
name|cl_spinlock_destroy
argument_list|(
operator|&
name|cl_atomic_spinlock
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|boolean_t
name|cl_is_debug
parameter_list|(
name|void
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|_DEBUG_
argument_list|)
return|return
name|TRUE
return|;
else|#
directive|else
return|return
name|FALSE
return|;
endif|#
directive|endif
comment|/* defined( _DEBUG_ ) */
block|}
end_function

end_unit

