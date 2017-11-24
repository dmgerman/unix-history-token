begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2006 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *	Declaration of atomic manipulation functions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CL_ATOMIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_CL_ATOMIC_H_
end_define

begin_include
include|#
directive|include
file|<complib/cl_atomic_osd.h>
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

begin_function_decl
name|BEGIN_C_DECLS
comment|/****h* Component Library/Atomic Operations * NAME *	Atomic Operations * * DESCRIPTION *	The Atomic Operations functions allow callers to operate on *	32-bit signed integers in an atomic fashion. *********/
comment|/****f* Component Library: Atomic Operations/cl_atomic_inc * NAME *	cl_atomic_inc * * DESCRIPTION *	The cl_atomic_inc function atomically increments a 32-bit signed *	integer and returns the incremented value. * * SYNOPSIS */
name|int32_t
name|cl_atomic_inc
parameter_list|(
name|IN
name|atomic32_t
modifier|*
specifier|const
name|p_value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_value *		[in] Pointer to a 32-bit integer to increment. * * RETURN VALUE *	Returns the incremented value pointed to by p_value. * * NOTES *	The provided value is incremented and its value returned in one atomic *	operation. * *	cl_atomic_inc maintains data consistency without requiring additional *	synchronization mechanisms in multi-threaded environments. * * SEE ALSO *	Atomic Operations, cl_atomic_dec, cl_atomic_add, cl_atomic_sub *********/
end_comment

begin_comment
comment|/****f* Component Library: Atomic Operations/cl_atomic_dec * NAME *	cl_atomic_dec * * DESCRIPTION *	The cl_atomic_dec function atomically decrements a 32-bit signed *	integer and returns the decremented value. * * SYNOPSIS */
end_comment

begin_function_decl
name|int32_t
name|cl_atomic_dec
parameter_list|(
name|IN
name|atomic32_t
modifier|*
specifier|const
name|p_value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_value *		[in] Pointer to a 32-bit integer to decrement. * * RETURN VALUE *	Returns the decremented value pointed to by p_value. * * NOTES *	The provided value is decremented and its value returned in one atomic *	operation. * *	cl_atomic_dec maintains data consistency without requiring additional *	synchronization mechanisms in multi-threaded environments. * * SEE ALSO *	Atomic Operations, cl_atomic_inc, cl_atomic_add, cl_atomic_sub *********/
end_comment

begin_comment
comment|/****f* Component Library: Atomic Operations/cl_atomic_add * NAME *	cl_atomic_add * * DESCRIPTION *	The cl_atomic_add function atomically adds a value to a *	32-bit signed integer and returns the resulting value. * * SYNOPSIS */
end_comment

begin_function_decl
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
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_value *		[in] Pointer to a 32-bit integer that will be added to. * *	increment *		[in] Value by which to increment the integer pointed to by p_value. * * RETURN VALUE *	Returns the value pointed to by p_value after the addition. * * NOTES *	The provided increment is added to the value and the result returned in *	one atomic operation. * *	cl_atomic_add maintains data consistency without requiring additional *	synchronization mechanisms in multi-threaded environments. * * SEE ALSO *	Atomic Operations, cl_atomic_inc, cl_atomic_dec, cl_atomic_sub *********/
end_comment

begin_comment
comment|/****f* Component Library: Atomic Operations/cl_atomic_sub * NAME *	cl_atomic_sub * * DESCRIPTION *	The cl_atomic_sub function atomically subtracts a value from a *	32-bit signed integer and returns the resulting value. * * SYNOPSIS */
end_comment

begin_function_decl
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
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_value *		[in] Pointer to a 32-bit integer that will be subtracted from. * *	decrement *		[in] Value by which to decrement the integer pointed to by p_value. * * RETURN VALUE *	Returns the value pointed to by p_value after the subtraction. * * NOTES *	The provided decrement is subtracted from the value and the result *	returned in one atomic operation. * *	cl_atomic_sub maintains data consistency without requiring additional *	synchronization mechanisms in multi-threaded environments. * * SEE ALSO *	Atomic Operations, cl_atomic_inc, cl_atomic_dec, cl_atomic_add *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CL_ATOMIC_H_ */
end_comment

end_unit

