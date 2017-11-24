begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *	Defines standard math related macros and functions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CL_MATH_H_
end_ifndef

begin_define
define|#
directive|define
name|_CL_MATH_H_
end_define

begin_include
include|#
directive|include
file|<complib/cl_types.h>
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

begin_expr_stmt
name|BEGIN_C_DECLS
comment|/****d* Component Library: Math/MAX * NAME *	MAX * * DESCRIPTION *	The MAX macro returns the greater of two values. * * SYNOPSIS *	MAX( x, y ); * * PARAMETERS *	x *		[in] First of two values to compare. * *	y *		[in] Second of two values to compare. * * RETURN VALUE *	Returns the greater of the x and y parameters. * * SEE ALSO *	MIN, ROUNDUP *********/
ifndef|#
directive|ifndef
name|MAX
define|#
directive|define
name|MAX
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)> (y) ? (x) : (y))
endif|#
directive|endif
comment|/****d* Component Library: Math/MIN * NAME *	MIN * * DESCRIPTION *	The MIN macro returns the greater of two values. * * SYNOPSIS *	MIN( x, y ); * * PARAMETERS *	x *		[in] First of two values to compare. * *	y *		[in] Second of two values to compare. * * RETURN VALUE *	Returns the lesser of the x and y parameters. * * SEE ALSO *	MAX, ROUNDUP *********/
ifndef|#
directive|ifndef
name|MIN
define|#
directive|define
name|MIN
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)< (y) ? (x) : (y))
endif|#
directive|endif
comment|/****d* Component Library: Math/ROUNDUP * NAME *	ROUNDUP * * DESCRIPTION *	The ROUNDUP macro rounds a value up to a given multiple. * * SYNOPSIS *	ROUNDUP( val, align ); * * PARAMETERS *	val *		[in] Value that is to be rounded up. The type of the value is *		indeterminate, but must be at most the size of a natural integer *		for the platform. * *	align *		[in] Multiple to which the val parameter must be rounded up. * * RETURN VALUE *	Returns a value that is the input value specified by val rounded up to *	the nearest multiple of align. * * NOTES *	The value provided must be of a type at most the size of a natural integer. *********/
ifndef|#
directive|ifndef
name|ROUNDUP
define|#
directive|define
name|ROUNDUP
parameter_list|(
name|val
parameter_list|,
name|align
parameter_list|)
define|\
value|((((val) / (align))*(align)) + (((val) % (align)) ? (align) : 0))
endif|#
directive|endif
name|END_C_DECLS
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CL_MATH_H_ */
end_comment

end_unit

