begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *    Implementation of osm_router_t.  * This object represents an Infiniband router.  * This object is part of the opensm family of objects.  */
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
file|<iba/ib_types.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_file_ids.h>
end_include

begin_define
define|#
directive|define
name|FILE_ID
value|OSM_FILE_ROUTER_C
end_define

begin_include
include|#
directive|include
file|<opensm/osm_router.h>
end_include

begin_function
name|void
name|osm_router_delete
parameter_list|(
name|IN
name|OUT
name|osm_router_t
modifier|*
modifier|*
name|pp_rtr
parameter_list|)
block|{
name|free
argument_list|(
operator|*
name|pp_rtr
argument_list|)
expr_stmt|;
operator|*
name|pp_rtr
operator|=
name|NULL
expr_stmt|;
block|}
end_function

begin_function
name|osm_router_t
modifier|*
name|osm_router_new
parameter_list|(
name|IN
name|osm_port_t
modifier|*
name|p_port
parameter_list|)
block|{
name|osm_router_t
modifier|*
name|p_rtr
decl_stmt|;
name|CL_ASSERT
argument_list|(
name|p_port
argument_list|)
expr_stmt|;
name|p_rtr
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
operator|*
name|p_rtr
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|p_rtr
condition|)
block|{
name|memset
argument_list|(
name|p_rtr
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|p_rtr
argument_list|)
argument_list|)
expr_stmt|;
name|p_rtr
operator|->
name|p_port
operator|=
name|p_port
expr_stmt|;
block|}
return|return
name|p_rtr
return|;
block|}
end_function

end_unit

