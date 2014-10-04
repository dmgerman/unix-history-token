begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 Topspin Communications.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
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
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<infiniband/verbs.h>
end_include

begin_include
include|#
directive|include
file|<infiniband/arch.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|struct
name|ibv_device
modifier|*
modifier|*
name|dev_list
decl_stmt|;
name|int
name|num_devices
decl_stmt|,
name|i
decl_stmt|;
name|dev_list
operator|=
name|ibv_get_device_list
argument_list|(
operator|&
name|num_devices
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|dev_list
condition|)
block|{
name|perror
argument_list|(
literal|"Failed to get IB devices list"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|printf
argument_list|(
literal|"    %-16s\t   node GUID\n"
argument_list|,
literal|"device"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"    %-16s\t----------------\n"
argument_list|,
literal|"------"
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|num_devices
condition|;
operator|++
name|i
control|)
block|{
name|printf
argument_list|(
literal|"    %-16s\t%016llx\n"
argument_list|,
name|ibv_get_device_name
argument_list|(
name|dev_list
index|[
name|i
index|]
argument_list|)
argument_list|,
operator|(
name|unsigned
name|long
name|long
operator|)
name|ntohll
argument_list|(
name|ibv_get_device_guid
argument_list|(
name|dev_list
index|[
name|i
index|]
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|ibv_free_device_list
argument_list|(
name|dev_list
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

