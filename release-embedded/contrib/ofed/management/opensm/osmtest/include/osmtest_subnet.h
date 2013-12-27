begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osmtest_t.  *	This object represents the OSMTest Test object.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSMTEST_SUBNET_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSMTEST_SUBNET_H_
end_define

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_qmap.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_log.h>
end_include

begin_include
include|#
directive|include
file|<vendor/osm_vendor_api.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_mad_pool.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_helper.h>
end_include

begin_comment
comment|/****s* Subnet Database/generic_t * NAME *	generic_t * * DESCRIPTION *	Subnet database object for fields common to all record types. *	All other database types must be castable to this type. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_generic
block|{
name|cl_map_item_t
name|map_item
decl_stmt|;
comment|/* must be first element! */
name|uint32_t
name|count
decl_stmt|;
comment|/* must be second element! */
block|}
name|generic_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS * * SEE ALSO *********/
end_comment

begin_comment
comment|/****s* Subnet Database/node_t * NAME *	node_t * * DESCRIPTION *	Subnet database object for nodes. *	Must be castable to generic_t. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_node
block|{
name|cl_map_item_t
name|map_item
decl_stmt|;
comment|/* must be first element! */
name|uint32_t
name|count
decl_stmt|;
comment|/* must be second element! */
name|ib_node_record_t
name|rec
decl_stmt|;
name|ib_node_record_t
name|comp
decl_stmt|;
block|}
name|node_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS * map_item *	Provides linkage for the qmap container. * * rec *	NodeRecord for this node as read from the database file. * * comp *	NodeRecord indicating which fields should be compared against rec. *	Bits set in the comp NodeRecord indicate that bit in the rec structure *	should be compared against real-time data from the SA. * * count *	Utility counter used by the validation logic.  Typically used to *	to indicate the number of times a matching node was received from *	the SA. * * SEE ALSO *********/
end_comment

begin_function
specifier|static
specifier|inline
name|node_t
modifier|*
name|node_new
parameter_list|(
name|void
parameter_list|)
block|{
name|node_t
modifier|*
name|p_obj
decl_stmt|;
name|p_obj
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
operator|*
name|p_obj
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|p_obj
condition|)
name|memset
argument_list|(
name|p_obj
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|p_obj
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|p_obj
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|node_delete
parameter_list|(
name|IN
name|node_t
modifier|*
name|p_obj
parameter_list|)
block|{
name|free
argument_list|(
name|p_obj
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/****s* Subnet Database/port_t * NAME *	port_t * * DESCRIPTION *	Subnet database object for ports. *	Must be castable to generic_t. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_port
block|{
name|cl_map_item_t
name|map_item
decl_stmt|;
comment|/* must be first element! */
name|uint32_t
name|count
decl_stmt|;
comment|/* must be second element! */
comment|/* Since there is no unique identifier for all ports we 	   must be able to have such a key by the lid and port num */
name|uint64_t
name|port_id
decl_stmt|;
name|ib_portinfo_record_t
name|rec
decl_stmt|;
name|ib_portinfo_record_t
name|comp
decl_stmt|;
block|}
name|port_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS * * map_item *	Provides linkage for the qmap container. * * rec *	PortInfoRecord for this port as read from the database file. * * comp *	PortInfoRecord indicating which fields should be compared against rec. *	Bits set in the comp NodeRecord indicate that bit in the rec structure *	should be compared against real-time data from the SA. * * count *	Utility counter used by the validation logic.  Typically used to *	to indicate the number of times a matching node was received from *	the SA. * * SEE ALSO *********/
end_comment

begin_function
specifier|static
specifier|inline
name|port_t
modifier|*
name|port_new
parameter_list|(
name|void
parameter_list|)
block|{
name|port_t
modifier|*
name|p_obj
decl_stmt|;
name|p_obj
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
operator|*
name|p_obj
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|p_obj
condition|)
name|memset
argument_list|(
name|p_obj
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|p_obj
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|p_obj
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|port_delete
parameter_list|(
name|IN
name|port_t
modifier|*
name|p_obj
parameter_list|)
block|{
name|free
argument_list|(
name|p_obj
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint64_t
name|port_gen_id
parameter_list|(
name|IN
name|ib_net16_t
specifier|const
name|lid
parameter_list|,
name|IN
name|uint8_t
specifier|const
name|port_num
parameter_list|)
block|{
return|return
operator|(
name|lid
operator|<<
literal|8
operator||
name|port_num
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|port_ext_id
parameter_list|(
name|IN
name|uint64_t
name|id
parameter_list|,
name|IN
name|ib_net16_t
modifier|*
name|p_lid
parameter_list|,
name|IN
name|uint8_t
modifier|*
name|p_port_num
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
operator|(
name|id
operator|&
literal|0xFF
operator|)
operator|<
literal|0x100
argument_list|)
expr_stmt|;
operator|*
name|p_port_num
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|id
operator|&
literal|0xFF
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
operator|(
operator|(
name|id
operator|>>
literal|8
operator|)
operator|&
literal|0xFFFF
operator|)
operator|<
literal|0x10000
argument_list|)
expr_stmt|;
operator|*
name|p_lid
operator|=
call|(
name|uint16_t
call|)
argument_list|(
operator|(
name|id
operator|>>
literal|8
operator|)
operator|&
literal|0xFFFF
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|port_set_id
parameter_list|(
name|IN
name|port_t
modifier|*
name|p_obj
parameter_list|,
name|IN
name|ib_net16_t
specifier|const
name|lid
parameter_list|,
name|IN
name|uint8_t
specifier|const
name|port_num
parameter_list|)
block|{
name|p_obj
operator|->
name|port_id
operator|=
name|port_gen_id
argument_list|(
name|lid
argument_list|,
name|port_num
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|port_get_id
parameter_list|(
name|IN
name|port_t
modifier|*
name|p_obj
parameter_list|,
name|IN
name|ib_net16_t
modifier|*
name|p_lid
parameter_list|,
name|IN
name|uint8_t
modifier|*
name|p_port_num
parameter_list|)
block|{
name|port_ext_id
argument_list|(
name|p_obj
operator|->
name|port_id
argument_list|,
name|p_lid
argument_list|,
name|p_port_num
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/****s* Subnet Database/path_t * NAME *	node_t * * DESCRIPTION *	Subnet database object for paths. *	Must be castable to generic_t. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_path
block|{
name|cl_map_item_t
name|map_item
decl_stmt|;
comment|/* must be first element! */
name|uint32_t
name|count
decl_stmt|;
comment|/* must be second element! */
name|ib_path_rec_t
name|rec
decl_stmt|;
name|ib_path_rec_t
name|comp
decl_stmt|;
block|}
name|path_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS * map_item *	Provides linkage for the qmap container. * * rec *	PathRecord for this path as read from the database file. * * comp *	PathRecord indicating which fields should be compared against rec. *	Bits set in the comp PathRecord indicate that bit in the rec structure *	should be compared against real-time data from the SA. * * count *	Utility counter used by the validation logic.  Typically used to *	to indicate the number of times a matching node was received from *	the SA. * * SEE ALSO *********/
end_comment

begin_function
specifier|static
specifier|inline
name|path_t
modifier|*
name|path_new
parameter_list|(
name|void
parameter_list|)
block|{
name|path_t
modifier|*
name|p_obj
decl_stmt|;
name|p_obj
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
operator|*
name|p_obj
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|p_obj
condition|)
name|memset
argument_list|(
name|p_obj
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|p_obj
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|p_obj
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|path_delete
parameter_list|(
name|IN
name|path_t
modifier|*
name|p_obj
parameter_list|)
block|{
name|free
argument_list|(
name|p_obj
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/****s* Subnet Database/subnet_t * NAME *	subnet_t * * DESCRIPTION *	Subnet database object. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_subnet
block|{
name|cl_qmap_t
name|node_lid_tbl
decl_stmt|;
name|cl_qmap_t
name|node_guid_tbl
decl_stmt|;
name|cl_qmap_t
name|mgrp_mlid_tbl
decl_stmt|;
comment|/* cl_qmap_t port_lid_tbl; */
comment|/* cl_qmap_t port_guid_tbl; */
name|cl_qmap_t
name|port_key_tbl
decl_stmt|;
name|cl_qmap_t
name|link_tbl
decl_stmt|;
name|cl_qmap_t
name|path_tbl
decl_stmt|;
block|}
name|subnet_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* Subnet Database/subnet_construct * NAME *	subnet_construct * * DESCRIPTION *	This function constructs an subnet database object. *	This function cannot fail. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|subnet_construct
parameter_list|(
name|IN
name|subnet_t
modifier|*
specifier|const
name|p_subn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * FIELDS * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* Subnet Database/subnet_init * NAME *	subnet_init * * DESCRIPTION *	This function initializes an subnet database object. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|subnet_init
parameter_list|(
name|IN
name|subnet_t
modifier|*
specifier|const
name|p_subn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * FIELDS * * SEE ALSO *********/
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

