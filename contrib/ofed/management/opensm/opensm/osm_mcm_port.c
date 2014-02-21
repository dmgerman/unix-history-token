begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2008 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *    Implementation of osm_mcm_port_t.  * This object represents the membership of a port in a multicast group.  * This object is part of the OpenSM family of objects.  */
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
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_mcm_port.h>
end_include

begin_comment
comment|/**********************************************************************  **********************************************************************/
end_comment

begin_function
name|osm_mcm_port_t
modifier|*
name|osm_mcm_port_new
parameter_list|(
name|IN
specifier|const
name|ib_gid_t
modifier|*
specifier|const
name|p_port_gid
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|scope_state
parameter_list|,
name|IN
specifier|const
name|boolean_t
name|proxy_join
parameter_list|)
block|{
name|osm_mcm_port_t
modifier|*
name|p_mcm
decl_stmt|;
name|p_mcm
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
operator|*
name|p_mcm
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|p_mcm
condition|)
block|{
name|memset
argument_list|(
name|p_mcm
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|p_mcm
argument_list|)
argument_list|)
expr_stmt|;
name|p_mcm
operator|->
name|port_gid
operator|=
operator|*
name|p_port_gid
expr_stmt|;
name|p_mcm
operator|->
name|scope_state
operator|=
name|scope_state
expr_stmt|;
name|p_mcm
operator|->
name|proxy_join
operator|=
name|proxy_join
expr_stmt|;
block|}
return|return
operator|(
name|p_mcm
operator|)
return|;
block|}
end_function

begin_comment
comment|/**********************************************************************  **********************************************************************/
end_comment

begin_function
name|void
name|osm_mcm_port_delete
parameter_list|(
name|IN
name|osm_mcm_port_t
modifier|*
specifier|const
name|p_mcm
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_mcm
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|p_mcm
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

