begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  * Copyright (c) 2009 HNR Consulting. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_PATH_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_PATH_H_
end_define

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_base.h>
end_include

begin_include
include|#
directive|include
file|<vendor/osm_vendor_api.h>
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

begin_macro
name|BEGIN_C_DECLS
end_macro

begin_comment
comment|/*  * Abstract:  * 	Declaration of path related objects.  *	These objects are part of the OpenSM family of objects.  */
end_comment

begin_comment
comment|/****h* OpenSM/DR Path * NAME *	DR Path * * DESCRIPTION *	The DR Path structure encapsulates a directed route through the subnet. * *	This structure allows direct access to member variables. * * AUTHOR *	Steve King, Intel * *********/
end_comment

begin_comment
comment|/****s* OpenSM: DR Path/osm_dr_path_t * NAME *	osm_dr_path_t * * DESCRIPTION *	Directed Route structure. * *	This structure allows direct access to member variables. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_dr_path
block|{
name|uint8_t
name|hop_count
decl_stmt|;
name|uint8_t
name|path
index|[
name|IB_SUBNET_PATH_HOPS_MAX
index|]
decl_stmt|;
block|}
name|osm_dr_path_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	h_bind *		Bind handle for port to which this path applies. * *	hop_count *		The number of hops in this path. * *	path *		The array of port numbers that comprise this path. * * SEE ALSO *	DR Path structure *********/
end_comment

begin_comment
comment|/****f* OpenSM: DR Path/osm_dr_path_construct * NAME *	osm_dr_path_construct * * DESCRIPTION *	This function constructs a directed route path object. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osm_dr_path_construct
parameter_list|(
name|IN
name|osm_dr_path_t
modifier|*
name|p_path
parameter_list|)
block|{
comment|/* The first location in the path array is reserved. */
name|memset
argument_list|(
name|p_path
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|p_path
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_path *		[in] Pointer to a directed route path object to initialize. * *	h_bind *		[in] Bind handle for the port on which this path applies. * *	hop_count *		[in] Hop count needed to reach this node. * *	path *		[in] Directed route path to reach this node. * * RETURN VALUE *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: DR Path/osm_dr_path_init * NAME *	osm_dr_path_init * * DESCRIPTION *	This function initializes a directed route path object. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osm_dr_path_init
parameter_list|(
name|IN
name|osm_dr_path_t
modifier|*
name|p_path
parameter_list|,
name|IN
name|uint8_t
name|hop_count
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|path
index|[
name|IB_SUBNET_PATH_HOPS_MAX
index|]
parameter_list|)
block|{
comment|/* The first location in the path array is reserved. */
name|CL_ASSERT
argument_list|(
name|path
index|[
literal|0
index|]
operator|==
literal|0
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|hop_count
operator|<
name|IB_SUBNET_PATH_HOPS_MAX
argument_list|)
expr_stmt|;
name|p_path
operator|->
name|hop_count
operator|=
name|hop_count
expr_stmt|;
name|memcpy
argument_list|(
name|p_path
operator|->
name|path
argument_list|,
name|path
argument_list|,
name|hop_count
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_path *		[in] Pointer to a directed route path object to initialize. * *	h_bind *		[in] Bind handle for the port on which this path applies. * *	hop_count *		[in] Hop count needed to reach this node. * *	path *		[in] Directed route path to reach this node. * * RETURN VALUE *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: DR Path/osm_dr_path_extend * NAME *	osm_dr_path_extend * * DESCRIPTION *	Adds a new hop to a path. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|osm_dr_path_extend
parameter_list|(
name|IN
name|osm_dr_path_t
modifier|*
name|p_path
parameter_list|,
name|IN
name|uint8_t
name|port_num
parameter_list|)
block|{
name|p_path
operator|->
name|hop_count
operator|++
expr_stmt|;
if|if
condition|(
name|p_path
operator|->
name|hop_count
operator|>=
name|IB_SUBNET_PATH_HOPS_MAX
condition|)
return|return
operator|-
literal|1
return|;
comment|/* 	   Location 0 in the path array is reserved per IB spec. 	 */
name|p_path
operator|->
name|path
index|[
name|p_path
operator|->
name|hop_count
index|]
operator|=
name|port_num
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_path *		[in] Pointer to a directed route path object to initialize. * *	port_num *		[in] Additional port to add to the DR path. * * RETURN VALUES *	0 indicates path was extended. *	Other than 0 indicates path was not extended. * * NOTES * * SEE ALSO *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_PATH_H_ */
end_comment

end_unit

