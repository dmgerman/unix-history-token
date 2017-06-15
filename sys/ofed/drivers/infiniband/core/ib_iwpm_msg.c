begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 Intel Corporation. All rights reserved.  * Copyright (c) 2014 Chelsio, Inc. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|"iwpm_util.h"
end_include

begin_decl_stmt
specifier|static
name|int
name|iwpm_user_pid
init|=
name|IWPM_PID_UNDEFINED
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|iwpm_valid_pid
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|iwpm_user_pid
operator|>
literal|0
return|;
block|}
end_function

begin_expr_stmt
name|EXPORT_SYMBOL
argument_list|(
name|iwpm_valid_pid
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

