begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *	Defines string to decode cl_status_t return values.  *  */
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

begin_comment
comment|/* Status values above converted to text for easier printing. */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|cl_status_text
index|[]
init|=
block|{
literal|"CL_SUCCESS"
block|,
literal|"CL_ERROR"
block|,
literal|"CL_INVALID_STATE"
block|,
literal|"CL_INVALID_OPERATION"
block|,
literal|"CL_INVALID_SETTING"
block|,
literal|"CL_INVALID_PARAMETER"
block|,
literal|"CL_INSUFFICIENT_RESOURCES"
block|,
literal|"CL_INSUFFICIENT_MEMORY"
block|,
literal|"CL_INVALID_PERMISSION"
block|,
literal|"CL_COMPLETED"
block|,
literal|"CL_NOT_DONE"
block|,
literal|"CL_PENDING"
block|,
literal|"CL_TIMEOUT"
block|,
literal|"CL_CANCELED"
block|,
literal|"CL_REJECT"
block|,
literal|"CL_OVERRUN"
block|,
literal|"CL_NOT_FOUND"
block|,
literal|"CL_UNAVAILABLE"
block|,
literal|"CL_BUSY"
block|,
literal|"CL_DISCONNECT"
block|,
literal|"CL_DUPLICATE"
block|}
decl_stmt|;
end_decl_stmt

end_unit

