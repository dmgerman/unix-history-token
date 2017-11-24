begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2009 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_switch_t.  *	This object represents an IBA switch.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_SWITCH_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_SWITCH_H_
end_define

begin_include
include|#
directive|include
file|<iba/ib_types.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_base.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_madw.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_node.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_port.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_mcast_tbl.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_port_profile.h>
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
comment|/****h* OpenSM/Switch * NAME *	Switch * * DESCRIPTION *	The Switch object encapsulates the information needed by the *	OpenSM to manage switches.  The OpenSM allocates one switch object *	per switch in the IBA subnet. * *	The Switch object is not thread safe, thus callers must provide *	serialization. * *	This object should be treated as opaque and should be *	manipulated only through the provided functions. * * AUTHOR *	Steve King, Intel * *********/
end_comment

begin_comment
comment|/****s* OpenSM: Switch/osm_switch_t * NAME *	osm_switch_t * * DESCRIPTION *	Switch structure. * *	This object should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_switch
block|{
name|cl_map_item_t
name|map_item
decl_stmt|;
name|osm_node_t
modifier|*
name|p_node
decl_stmt|;
name|ib_switch_info_t
name|switch_info
decl_stmt|;
name|uint16_t
name|max_lid_ho
decl_stmt|;
name|uint8_t
name|num_ports
decl_stmt|;
name|uint16_t
name|num_hops
decl_stmt|;
name|uint8_t
modifier|*
modifier|*
name|hops
decl_stmt|;
name|osm_port_profile_t
modifier|*
name|p_prof
decl_stmt|;
name|uint8_t
modifier|*
name|search_ordering_ports
decl_stmt|;
name|uint8_t
modifier|*
name|lft
decl_stmt|;
name|uint8_t
modifier|*
name|new_lft
decl_stmt|;
name|uint16_t
name|lft_size
decl_stmt|;
name|osm_mcast_tbl_t
name|mcast_tbl
decl_stmt|;
name|int32_t
name|mft_block_num
decl_stmt|;
name|uint32_t
name|mft_position
decl_stmt|;
name|unsigned
name|endport_links
decl_stmt|;
name|unsigned
name|need_update
decl_stmt|;
name|void
modifier|*
name|priv
decl_stmt|;
name|cl_map_item_t
name|mgrp_item
decl_stmt|;
name|uint32_t
name|num_of_mcm
decl_stmt|;
name|uint8_t
name|is_mc_member
decl_stmt|;
block|}
name|osm_switch_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	map_item *		Linkage structure for cl_qmap.  MUST BE FIRST MEMBER! * *	p_node *		Pointer to the Node object for this switch. * *	switch_info *		IBA defined SwitchInfo structure for this switch. * *	max_lid_ho *		Max LID that is accessible from this switch. * *	num_ports *		Number of ports for this switch. * *	num_hops *		Size of hops table for this switch. * *	hops *		LID Matrix for this switch containing the hop count *		to every LID from every port. * *	p_prof *		Pointer to array of Port Profile objects for this switch. * *	lft *		This switch's linear forwarding table. * *	new_lft *		This switch's linear forwarding table, as was *		calculated by the last routing engine execution. * *	mcast_tbl *		Multicast forwarding table for this switch. * *	need_update *		When set indicates that switch was probably reset, so *		fwd tables and rest cached data should be flushed * *	mgrp_item *		map item for switch in building mcast tree * *	num_of_mcm *		number of mcast members(ports) connected to switch * *	is_mc_member *		whether switch is a mcast member itself * * SEE ALSO *	Switch object *********/
end_comment

begin_comment
comment|/****s* OpenSM: Switch/struct osm_remote_guids_count * NAME *	struct osm_remote_guids_count * * DESCRIPTION *	Stores array of pointers to remote node and the numbers of *	times a switch has forwarded to it. * * SYNOPSIS */
end_comment

begin_struct
struct|struct
name|osm_remote_guids_count
block|{
name|unsigned
name|count
decl_stmt|;
struct|struct
name|osm_remote_node
block|{
name|osm_node_t
modifier|*
name|node
decl_stmt|;
name|unsigned
name|forwarded_to
decl_stmt|;
name|uint8_t
name|port
decl_stmt|;
block|}
name|guids
index|[
literal|0
index|]
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/* * FIELDS *	count *		A number of used entries in array. * *	node *		A pointer to node. * *	forwarded_to *		A count of lids forwarded to this node. * *	port *		Port number on the node. *********/
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_delete * NAME *	osm_switch_delete * * DESCRIPTION *	Destroys and deallocates the object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_switch_delete
parameter_list|(
name|IN
name|OUT
name|osm_switch_t
modifier|*
modifier|*
name|pp_sw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to the object to destroy. * * RETURN VALUE *	None. * * NOTES * * SEE ALSO *	Switch object, osm_switch_new *********/
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_new * NAME *	osm_switch_new * * DESCRIPTION *	The osm_switch_new function initializes a Switch object for use. * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_switch_t
modifier|*
name|osm_switch_new
parameter_list|(
name|IN
name|osm_node_t
modifier|*
name|p_node
parameter_list|,
name|IN
specifier|const
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_node *		[in] Pointer to the node object of this switch * *	p_madw *		[in] Pointer to the MAD Wrapper containing the switch's *		SwitchInfo attribute. * * RETURN VALUES *	Pointer to the new initialized switch object. * * NOTES * * SEE ALSO *	Switch object, osm_switch_delete *********/
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_get_hop_count * NAME *	osm_switch_get_hop_count * * DESCRIPTION *	Returns the hop count at the specified LID/Port intersection. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|osm_switch_get_hop_count
parameter_list|(
name|IN
specifier|const
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|,
name|IN
name|uint16_t
name|lid_ho
parameter_list|,
name|IN
name|uint8_t
name|port_num
parameter_list|)
block|{
return|return
operator|(
name|lid_ho
operator|>
name|p_sw
operator|->
name|max_lid_ho
operator|||
operator|!
name|p_sw
operator|->
name|hops
index|[
name|lid_ho
index|]
operator|)
condition|?
name|OSM_NO_PATH
else|:
name|p_sw
operator|->
name|hops
index|[
name|lid_ho
index|]
index|[
name|port_num
index|]
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to a Switch object. * *	lid_ho *		[in] LID value (host order) for which to return the hop count * *	port_num *		[in] Port number in the switch * * RETURN VALUES *	Returns the hop count at the specified LID/Port intersection. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_set_hops * NAME *	osm_switch_set_hops * * DESCRIPTION *	Sets the hop count at the specified LID/Port intersection. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|osm_switch_set_hops
parameter_list|(
name|IN
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|,
name|IN
name|uint16_t
name|lid_ho
parameter_list|,
name|IN
name|uint8_t
name|port_num
parameter_list|,
name|IN
name|uint8_t
name|num_hops
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to a Switch object. * *	lid_ho *		[in] LID value (host order) for which to set the count. * *	port_num *		[in] port number for which to set the count. * *	num_hops *		[in] value to assign to this entry. * * RETURN VALUES *	Returns 0 if successful. -1 if it failed * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_clear_hops * NAME *	osm_switch_clear_hops * * DESCRIPTION *	Cleanup existing hops tables (lid matrix) * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_switch_clear_hops
parameter_list|(
name|IN
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to a Switch object. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_get_least_hops * NAME *	osm_switch_get_least_hops * * DESCRIPTION *	Returns the number of hops in the short path to this lid from *	any port on the switch. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|osm_switch_get_least_hops
parameter_list|(
name|IN
specifier|const
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|,
name|IN
name|uint16_t
name|lid_ho
parameter_list|)
block|{
return|return
operator|(
name|lid_ho
operator|>
name|p_sw
operator|->
name|max_lid_ho
operator|||
operator|!
name|p_sw
operator|->
name|hops
index|[
name|lid_ho
index|]
operator|)
condition|?
name|OSM_NO_PATH
else|:
name|p_sw
operator|->
name|hops
index|[
name|lid_ho
index|]
index|[
literal|0
index|]
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to an osm_switch_t object. * *	lid_ho *		[in] LID (host order) for which to retrieve the shortest hop count. * * RETURN VALUES *	Returns the number of hops in the short path to this lid from *	any port on the switch. * * NOTES * * SEE ALSO *	Switch object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_get_port_least_hops * NAME *	osm_switch_get_port_least_hops * * DESCRIPTION *	Returns the number of hops in the short path to this port from *	any port on the switch. * * SYNOPSIS */
end_comment

begin_function_decl
name|uint8_t
name|osm_switch_get_port_least_hops
parameter_list|(
name|IN
specifier|const
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|,
name|IN
specifier|const
name|osm_port_t
modifier|*
name|p_port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to an osm_switch_t object. * *	p_port *		[in] Pointer to an osm_port_t object for which to *		retrieve the shortest hop count. * * RETURN VALUES *	Returns the number of hops in the short path to this lid from *	any port on the switch. * * NOTES * * SEE ALSO *	Switch object *********/
end_comment

begin_comment
comment|/****d* OpenSM: osm_lft_type_enum * NAME *	osm_lft_type_enum * * DESCRIPTION *	Enumerates LFT sets types of a switch. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|osm_lft_type_enum
block|{
name|OSM_LFT
init|=
literal|0
block|,
name|OSM_NEW_LFT
block|}
name|osm_lft_type_enum
typedef|;
end_typedef

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_get_port_by_lid * NAME *	osm_switch_get_port_by_lid * * DESCRIPTION *	Returns the switch port number on which the specified LID is routed. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|osm_switch_get_port_by_lid
parameter_list|(
name|IN
specifier|const
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|,
name|IN
name|uint16_t
name|lid_ho
parameter_list|,
name|IN
name|osm_lft_type_enum
name|lft_enum
parameter_list|)
block|{
if|if
condition|(
name|lid_ho
operator|==
literal|0
operator|||
name|lid_ho
operator|>
name|p_sw
operator|->
name|max_lid_ho
condition|)
return|return
name|OSM_NO_PATH
return|;
return|return
name|lft_enum
operator|==
name|OSM_LFT
condition|?
name|p_sw
operator|->
name|lft
index|[
name|lid_ho
index|]
else|:
name|p_sw
operator|->
name|new_lft
index|[
name|lid_ho
index|]
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to an osm_switch_t object. * *	lid_ho *		[in] LID (host order) for which to retrieve the shortest hop count. * *	lft_enum *		[in] Use LFT that was calculated by routing engine, or *		current LFT on the switch. * * RETURN VALUES *	Returns the switch port on which the specified LID is routed. * * NOTES * * SEE ALSO *	Switch object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_get_route_by_lid * NAME *	osm_switch_get_route_by_lid * * DESCRIPTION *	Gets the physical port object that routes the specified LID. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|osm_physp_t
modifier|*
name|osm_switch_get_route_by_lid
parameter_list|(
name|IN
specifier|const
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|,
name|IN
name|ib_net16_t
name|lid
parameter_list|)
block|{
name|uint8_t
name|port_num
decl_stmt|;
name|CL_ASSERT
argument_list|(
name|p_sw
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|lid
argument_list|)
expr_stmt|;
name|port_num
operator|=
name|osm_switch_get_port_by_lid
argument_list|(
name|p_sw
argument_list|,
name|cl_ntoh16
argument_list|(
name|lid
argument_list|)
argument_list|,
name|OSM_NEW_LFT
argument_list|)
expr_stmt|;
comment|/* 	   In order to avoid holes in the subnet (usually happens when 	   running UPDN algorithm), i.e. cases where port is 	   unreachable through a switch (we put an OSM_NO_PATH value at 	   the port entry, we do not assert on unreachable lid entries 	   at the fwd table but return NULL 	 */
if|if
condition|(
name|port_num
operator|!=
name|OSM_NO_PATH
condition|)
return|return
operator|(
name|osm_node_get_physp_ptr
argument_list|(
name|p_sw
operator|->
name|p_node
argument_list|,
name|port_num
argument_list|)
operator|)
return|;
else|else
return|return
name|NULL
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to an osm_switch_t object. * *	lid *		[in] LID for which to find a route.  This must be a unicast *		LID value< 0xC000. * * RETURN VALUES *	Returns a pointer to the Physical Port Object object that *	routes the specified LID.  A return value of zero means *	there is no route for the lid through this switch. *	The lid value must be a unicast LID. * * NOTES * * SEE ALSO *	Switch object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_sp0_is_lmc_capable * NAME *	osm_switch_sp0_is_lmc_capable * * DESCRIPTION *	Returns whether switch port 0 (SP0) can support LMC * */
end_comment

begin_function
specifier|static
specifier|inline
name|unsigned
name|osm_switch_sp0_is_lmc_capable
parameter_list|(
name|IN
specifier|const
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|,
name|IN
name|osm_subn_t
modifier|*
name|p_subn
parameter_list|)
block|{
return|return
operator|(
name|p_subn
operator|->
name|opt
operator|.
name|lmc_esp0
operator|&&
name|ib_switch_info_is_enhanced_port0
argument_list|(
operator|&
name|p_sw
operator|->
name|switch_info
argument_list|)
operator|)
condition|?
literal|1
else|:
literal|0
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to an osm_switch_t object. * *	p_subn *		[in] Pointer to an osm_subn_t object. * * RETURN VALUES *	TRUE if SP0 is enhanced and globally enabled. FALSE otherwise. * * NOTES *	This is workaround function, it takes into account user defined *	p_subn->opt.lmc_esp0 parameter. * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_get_max_block_id_in_use * NAME *	osm_switch_get_max_block_id_in_use * * DESCRIPTION *	Returns the maximum block ID (host order) of this switch that *	is used for unicast routing. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint16_t
name|osm_switch_get_max_block_id_in_use
parameter_list|(
name|IN
specifier|const
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|)
block|{
return|return
name|cl_ntoh16
argument_list|(
name|p_sw
operator|->
name|switch_info
operator|.
name|lin_top
argument_list|)
operator|/
name|IB_SMP_DATA_SIZE
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to an osm_switch_t object. * * RETURN VALUES *	Returns the maximum block ID (host order) of this switch. * * NOTES * * SEE ALSO *	Switch object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_get_lft_block * NAME *	osm_switch_get_lft_block * * DESCRIPTION *	Retrieve a linear forwarding table block. * * SYNOPSIS */
end_comment

begin_function_decl
name|boolean_t
name|osm_switch_get_lft_block
parameter_list|(
name|IN
specifier|const
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|,
name|IN
name|uint16_t
name|block_id
parameter_list|,
name|OUT
name|uint8_t
modifier|*
name|p_block
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to an osm_switch_t object. * *	block_id *		[in] The block_id to retrieve. * *	p_block *		[out] Pointer to the 64 byte array to store the *		forwarding table block specified by block_id. * * RETURN VALUES *	Returns true if there are more blocks necessary to *	configure all the LIDs reachable from this switch. *	FALSE otherwise. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_supports_mcast * NAME *	osm_switch_supports_mcast * * DESCRIPTION *	Indicates if a switch supports multicast. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|osm_switch_supports_mcast
parameter_list|(
name|IN
specifier|const
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|)
block|{
return|return
operator|(
name|p_sw
operator|->
name|switch_info
operator|.
name|mcast_cap
operator|!=
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to an osm_switch_t object. * * RETURN VALUES *	Returns TRUE if the switch supports multicast. *	FALSE otherwise. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_set_switch_info * NAME *	osm_switch_set_switch_info * * DESCRIPTION *	Updates the switch info attribute of this switch. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osm_switch_set_switch_info
parameter_list|(
name|IN
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|,
name|IN
specifier|const
name|ib_switch_info_t
modifier|*
name|p_si
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_sw
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_si
argument_list|)
expr_stmt|;
name|p_sw
operator|->
name|switch_info
operator|=
operator|*
name|p_si
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to a Switch object. * *	p_si *		[in] Pointer to the SwitchInfo attribute for this switch. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_count_path * NAME *	osm_switch_count_path * * DESCRIPTION *	Counts this path in port profile. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osm_switch_count_path
parameter_list|(
name|IN
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|,
name|IN
name|uint8_t
name|port
parameter_list|)
block|{
name|osm_port_prof_path_count_inc
argument_list|(
operator|&
name|p_sw
operator|->
name|p_prof
index|[
name|port
index|]
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to the switch object. * *	port *		[in] Port to count path. * * RETURN VALUE *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_set_lft_block * NAME *	osm_switch_set_lft_block * * DESCRIPTION *	Copies in the specified block into *	the switch's Linear Forwarding Table. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_api_status_t
name|osm_switch_set_lft_block
parameter_list|(
name|IN
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|,
name|IN
specifier|const
name|uint8_t
modifier|*
name|p_block
parameter_list|,
name|IN
name|uint32_t
name|block_num
parameter_list|)
block|{
name|uint16_t
name|lid_start
init|=
call|(
name|uint16_t
call|)
argument_list|(
name|block_num
operator|*
name|IB_SMP_DATA_SIZE
argument_list|)
decl_stmt|;
name|CL_ASSERT
argument_list|(
name|p_sw
argument_list|)
expr_stmt|;
if|if
condition|(
name|lid_start
operator|+
name|IB_SMP_DATA_SIZE
operator|>
name|p_sw
operator|->
name|lft_size
condition|)
return|return
name|IB_INVALID_PARAMETER
return|;
name|memcpy
argument_list|(
operator|&
name|p_sw
operator|->
name|lft
index|[
name|lid_start
index|]
argument_list|,
name|p_block
argument_list|,
name|IB_SMP_DATA_SIZE
argument_list|)
expr_stmt|;
return|return
name|IB_SUCCESS
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to the switch object. * *	p_block *		[in] Pointer to the forwarding table block. * *	block_num *		[in] Block number for this block * * RETURN VALUE *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_set_mft_block * NAME *	osm_switch_set_mft_block * * DESCRIPTION *	Sets a block of multicast port masks into the multicast table. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_api_status_t
name|osm_switch_set_mft_block
parameter_list|(
name|IN
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|,
name|IN
specifier|const
name|ib_net16_t
modifier|*
name|p_block
parameter_list|,
name|IN
name|uint16_t
name|block_num
parameter_list|,
name|IN
name|uint8_t
name|position
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_sw
argument_list|)
expr_stmt|;
return|return
name|osm_mcast_tbl_set_block
argument_list|(
operator|&
name|p_sw
operator|->
name|mcast_tbl
argument_list|,
name|p_block
argument_list|,
name|block_num
argument_list|,
name|position
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to the switch object. * *	p_block *		[in] Pointer to the block of port masks to set. * *	block_num *		[in] Block number (0-511) to set. * *	position *		[in] Port mask position (0-15) to set. * * RETURN VALUE *	IB_SUCCESS on success. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_get_mft_block * NAME *	osm_switch_get_mft_block * * DESCRIPTION *	Retrieve a block of multicast port masks from the multicast table. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|osm_switch_get_mft_block
parameter_list|(
name|IN
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|,
name|IN
name|uint16_t
name|block_num
parameter_list|,
name|IN
name|uint8_t
name|position
parameter_list|,
name|OUT
name|ib_net16_t
modifier|*
name|p_block
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_sw
argument_list|)
expr_stmt|;
return|return
name|osm_mcast_tbl_get_block
argument_list|(
operator|&
name|p_sw
operator|->
name|mcast_tbl
argument_list|,
name|block_num
argument_list|,
name|position
argument_list|,
name|p_block
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to the switch object. * *	block_num *		[in] Block number (0-511) to set. * *	position *		[in] Port mask position (0-15) to set. * *	p_block *		[out] Pointer to the block of port masks stored. * * RETURN VALUES *	Returns true if there are more blocks necessary to *	configure all the MLIDs reachable from this switch. *	FALSE otherwise. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_get_mft_max_block * NAME *	osm_switch_get_mft_max_block * * DESCRIPTION *       Get the max_block from the associated multicast table. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint16_t
name|osm_switch_get_mft_max_block
parameter_list|(
name|IN
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_sw
argument_list|)
expr_stmt|;
return|return
name|osm_mcast_tbl_get_max_block
argument_list|(
operator|&
name|p_sw
operator|->
name|mcast_tbl
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to the switch object. * * RETURN VALUE */
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_get_mft_max_block_in_use * NAME *	osm_switch_get_mft_max_block_in_use * * DESCRIPTION *	Get the max_block_in_use from the associated multicast table. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|int16_t
name|osm_switch_get_mft_max_block_in_use
parameter_list|(
name|IN
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_sw
argument_list|)
expr_stmt|;
return|return
name|osm_mcast_tbl_get_max_block_in_use
argument_list|(
operator|&
name|p_sw
operator|->
name|mcast_tbl
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to the switch object. * * RETURN VALUES *	Returns the maximum block ID in use in this switch's mcast table. *	A value of -1 indicates no blocks are in use. * * NOTES * * SEE ALSO */
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_get_mft_max_position * NAME *	osm_switch_get_mft_max_position * * DESCRIPTION *       Get the max_position from the associated multicast table. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|osm_switch_get_mft_max_position
parameter_list|(
name|IN
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_sw
argument_list|)
expr_stmt|;
return|return
name|osm_mcast_tbl_get_max_position
argument_list|(
operator|&
name|p_sw
operator|->
name|mcast_tbl
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to the switch object. * * RETURN VALUE */
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_get_dimn_port * NAME *	osm_switch_get_dimn_port * * DESCRIPTION *	Get the routing ordered port * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|osm_switch_get_dimn_port
parameter_list|(
name|IN
specifier|const
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|,
name|IN
name|uint8_t
name|port_num
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_sw
argument_list|)
expr_stmt|;
if|if
condition|(
name|p_sw
operator|->
name|search_ordering_ports
operator|==
name|NULL
condition|)
return|return
name|port_num
return|;
return|return
name|p_sw
operator|->
name|search_ordering_ports
index|[
name|port_num
index|]
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to the switch object. * *	port_num *		[in] Port number in the switch * * RETURN VALUES *	Returns the port number ordered for routing purposes. */
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_recommend_path * NAME *	osm_switch_recommend_path * * DESCRIPTION *	Returns the recommended port on which to route this LID. *	In cases where LMC> 0, the remote side system and node *	used for the routing are tracked in the provided arrays *	(and counts) such that other lid for the same port will *	try and avoid going through the same remote system/node. * * SYNOPSIS */
end_comment

begin_function_decl
name|uint8_t
name|osm_switch_recommend_path
parameter_list|(
name|IN
specifier|const
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|,
name|IN
name|osm_port_t
modifier|*
name|p_port
parameter_list|,
name|IN
name|uint16_t
name|lid_ho
parameter_list|,
name|IN
name|unsigned
name|start_from
parameter_list|,
name|IN
name|boolean_t
name|ignore_existing
parameter_list|,
name|IN
name|boolean_t
name|routing_for_lmc
parameter_list|,
name|IN
name|boolean_t
name|dor
parameter_list|,
name|IN
name|boolean_t
name|port_shifting
parameter_list|,
name|IN
name|uint32_t
name|scatter_ports
parameter_list|,
name|IN
name|osm_lft_type_enum
name|lft_enum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to the switch object. * *	p_port *		[in] Pointer to the port object for which to get a path *		advisory. * *	lid_ho *		[in] LID value (host order) for which to get a path advisory. * *	start_from *		[in] Port number from where to start balance counting. * *	ignore_existing *		[in] Set to cause the switch to choose the optimal route *		regardless of existing paths. *		If false, the switch will choose an existing route if one *		exists, otherwise will choose the optimal route. * *	routing_for_lmc *		[in] We support an enhanced LMC aware routing mode: *		In the case of LMC> 0, we can track the remote side *		system and node for all of the lids of the target *		and try and avoid routing again through the same *		system / node. * *		Assume if routing_for_lmc is TRUE that this procedure *		was provided with the tracking array and counter via *		p_port->priv, and we can conduct this algorithm. * *	dor *		[in] If TRUE, Dimension Order Routing will be done. * *	port_shifting *		[in] If TRUE, port_shifting will be done. * * 	scatter_ports * 		[in] If not zero, randomize the selection of the best ports. * * 	lft_enum *		[in] Use LFT that was calculated by routing engine, or *		current LFT on the switch. * * RETURN VALUE *	Returns the recommended port on which to route this LID. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_recommend_mcast_path * NAME *	osm_switch_recommend_mcast_path * * DESCRIPTION *	Returns the recommended port on which to route this LID. * * SYNOPSIS */
end_comment

begin_function_decl
name|uint8_t
name|osm_switch_recommend_mcast_path
parameter_list|(
name|IN
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|,
name|IN
name|osm_port_t
modifier|*
name|p_port
parameter_list|,
name|IN
name|uint16_t
name|mlid_ho
parameter_list|,
name|IN
name|boolean_t
name|ignore_existing
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to the switch object. * *	p_port *		[in] Pointer to the port object for which to get *		the multicast path. * *	mlid_ho *		[in] MLID for the multicast group in question. * *	ignore_existing *		[in] Set to cause the switch to choose the optimal route *		regardless of existing paths. *		If false, the switch will choose an existing route if one exists, *		otherwise will choose the optimal route. * * RETURN VALUE *	Returns the recommended port on which to route this LID. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_get_mcast_fwd_tbl_size * NAME *	osm_switch_get_mcast_fwd_tbl_size * * DESCRIPTION *	Returns the number of entries available in the multicast forwarding table. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint16_t
name|osm_switch_get_mcast_fwd_tbl_size
parameter_list|(
name|IN
specifier|const
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|)
block|{
return|return
name|cl_ntoh16
argument_list|(
name|p_sw
operator|->
name|switch_info
operator|.
name|mcast_cap
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to the switch. * * RETURN VALUE *	Returns the number of entries available in the multicast forwarding table. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_path_count_get * NAME *	osm_switch_path_count_get * * DESCRIPTION *	Returns the count of the number of paths going through this port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|osm_switch_path_count_get
parameter_list|(
name|IN
specifier|const
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|,
name|IN
name|uint8_t
name|port_num
parameter_list|)
block|{
return|return
name|osm_port_prof_path_count_get
argument_list|(
operator|&
name|p_sw
operator|->
name|p_prof
index|[
name|port_num
index|]
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to the Switch object. * *	port_num *		[in] Port number for which to get path count. * * RETURN VALUE *	Returns the count of the number of paths going through this port. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_prepare_path_rebuild * NAME *	osm_switch_prepare_path_rebuild * * DESCRIPTION *	Prepares a switch to rebuild pathing information. * * SYNOPSIS */
end_comment

begin_function_decl
name|int
name|osm_switch_prepare_path_rebuild
parameter_list|(
name|IN
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|,
name|IN
name|uint16_t
name|max_lids
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to the Switch object. * *	max_lids *		[in] Max number of lids in the subnet. * * RETURN VALUE *	Returns zero on success, or negative value if an error occurred. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_get_mcast_tbl_ptr * NAME *	osm_switch_get_mcast_tbl_ptr * * DESCRIPTION *	Returns a pointer to the switch's multicast table. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|osm_mcast_tbl_t
modifier|*
name|osm_switch_get_mcast_tbl_ptr
parameter_list|(
name|IN
specifier|const
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|)
block|{
return|return
operator|(
name|osm_mcast_tbl_t
operator|*
operator|)
operator|&
name|p_sw
operator|->
name|mcast_tbl
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to the switch. * * RETURN VALUE *	Returns a pointer to the switch's multicast table. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Switch/osm_switch_is_in_mcast_tree * NAME *	osm_switch_is_in_mcast_tree * * DESCRIPTION *	Returns true if this switch already belongs in the tree for the specified *	multicast group. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|osm_switch_is_in_mcast_tree
parameter_list|(
name|IN
specifier|const
name|osm_switch_t
modifier|*
name|p_sw
parameter_list|,
name|IN
name|uint16_t
name|mlid_ho
parameter_list|)
block|{
specifier|const
name|osm_mcast_tbl_t
modifier|*
name|p_tbl
decl_stmt|;
name|p_tbl
operator|=
operator|&
name|p_sw
operator|->
name|mcast_tbl
expr_stmt|;
if|if
condition|(
name|p_tbl
condition|)
return|return
name|osm_mcast_tbl_is_any_port
argument_list|(
operator|&
name|p_sw
operator|->
name|mcast_tbl
argument_list|,
name|mlid_ho
argument_list|)
return|;
else|else
return|return
name|FALSE
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_sw *		[in] Pointer to the switch. * *	mlid_ho *		[in] MLID (host order) of the multicast tree to check. * * RETURN VALUE *	Returns true if this switch already belongs in the tree for the specified *	multicast group. * * NOTES * * SEE ALSO *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_SWITCH_H_ */
end_comment

end_unit

