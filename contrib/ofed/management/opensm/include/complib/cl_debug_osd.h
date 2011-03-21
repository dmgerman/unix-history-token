begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2006 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *	Debug Macros.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CL_DEBUG_OSD_H_
end_ifndef

begin_define
define|#
directive|define
name|_CL_DEBUG_OSD_H_
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
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__MODULE__
argument_list|)
define|#
directive|define
name|__MODULE__
value|""
define|#
directive|define
name|__MOD_DELIMITER__
value|""
else|#
directive|else
comment|/* !defined(__MODULE__) */
define|#
directive|define
name|__MOD_DELIMITER__
value|":"
endif|#
directive|endif
comment|/* !defined(__MODULE__) */
comment|/*  * Define specifiers for print functions based on the platform  */
ifdef|#
directive|ifdef
name|__IA64__
define|#
directive|define
name|PRIdSIZE_T
value|"ld"
else|#
directive|else
define|#
directive|define
name|PRIdSIZE_T
value|"d"
endif|#
directive|endif
include|#
directive|include
file|<inttypes.h>
include|#
directive|include
file|<stdio.h>
define|#
directive|define
name|cl_msg_out
value|printf
if|#
directive|if
name|defined
argument_list|(
name|_DEBUG_
argument_list|)
define|#
directive|define
name|cl_dbg_out
value|printf
else|#
directive|else
define|#
directive|define
name|cl_dbg_out
value|foo
endif|#
directive|endif
comment|/* _DEBUG_ */
comment|/*  * The following macros are used internally by the CL_ENTER, CL_TRACE,  * CL_TRACE_EXIT, and CL_EXIT macros.  */
define|#
directive|define
name|_CL_DBG_ENTER
define|\
value|("%s%s%s() [\n", __MODULE__, __MOD_DELIMITER__, __func__)
define|#
directive|define
name|_CL_DBG_EXIT
define|\
value|("%s%s%s() ]\n", __MODULE__, __MOD_DELIMITER__, __func__)
define|#
directive|define
name|_CL_DBG_INFO
define|\
value|("%s%s%s(): ", __MODULE__, __MOD_DELIMITER__, __func__)
define|#
directive|define
name|_CL_DBG_ERROR
define|\
value|("%s%s%s() !ERROR!: ", __MODULE__, __MOD_DELIMITER__, __func__)
define|#
directive|define
name|CL_CHK_STK
name|END_C_DECLS
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CL_DEBUG_OSD_H_ */
end_comment

end_unit

