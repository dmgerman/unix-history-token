begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2011 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of port related objects.  *	These objects comprise an IBA port.  *	These objects are part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_PORT_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_PORT_H_
end_define

begin_include
include|#
directive|include
file|<complib/cl_qmap.h>
end_include

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
file|<opensm/osm_subnet.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_madw.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_path.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_pkey.h>
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
comment|/* 	Forward references. */
end_comment

begin_struct_decl
struct_decl|struct
name|osm_port
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|osm_node
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|osm_mgrp
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|osm_sm
struct_decl|;
end_struct_decl

begin_comment
comment|/****h* OpenSM/Physical Port * NAME *	Physical Port * * DESCRIPTION *	The Physical Port object encapsulates the information needed by the *	OpenSM to manage physical ports.  The OpenSM allocates one Physical Port *	per physical port in the IBA subnet. * *	In a switch, one multiple Physical Port objects share the same port GUID. *	In an end-point, Physical Ports do not share GUID values. * *	The Physical Port is not thread safe, thus callers must provide *	serialization. * *	These objects should be treated as opaque and should be *	manipulated only through the provided functions. * * AUTHOR *	Steve King, Intel * *********/
end_comment

begin_comment
comment|/****s* OpenSM: Physical Port/osm_physp_t * NAME *	osm_physp_t * * DESCRIPTION *	This object represents a physical port on a switch, router or end-point. * *	The osm_physp_t object should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_physp
block|{
name|ib_port_info_t
name|port_info
decl_stmt|;
name|ib_mlnx_ext_port_info_t
name|ext_port_info
decl_stmt|;
name|ib_net64_t
name|port_guid
decl_stmt|;
name|ib_net64_t
argument_list|(
operator|*
name|p_guids
argument_list|)
index|[]
expr_stmt|;
name|uint8_t
name|port_num
decl_stmt|;
name|struct
name|osm_node
modifier|*
name|p_node
decl_stmt|;
name|struct
name|osm_physp
modifier|*
name|p_remote_physp
decl_stmt|;
name|boolean_t
name|healthy
decl_stmt|;
name|uint8_t
name|vl_high_limit
decl_stmt|;
name|unsigned
name|need_update
decl_stmt|;
name|unsigned
name|is_prof_ignored
decl_stmt|;
name|osm_dr_path_t
name|dr_path
decl_stmt|;
name|osm_pkey_tbl_t
name|pkeys
decl_stmt|;
name|ib_vl_arb_table_t
name|vl_arb
index|[
literal|4
index|]
decl_stmt|;
name|cl_ptr_vector_t
name|slvl_by_port
decl_stmt|;
name|uint8_t
name|hop_wf
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|ib_sw_cong_setting_t
name|sw_cong_setting
decl_stmt|;
block|}
name|sw
struct|;
struct|struct
block|{
name|ib_ca_cong_setting_t
name|ca_cong_setting
decl_stmt|;
name|ib_cc_tbl_t
name|cc_tbl
index|[
name|OSM_CCT_ENTRY_MAD_BLOCKS
index|]
decl_stmt|;
block|}
name|ca
struct|;
block|}
name|cc
union|;
block|}
name|osm_physp_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	port_info *		The IBA defined PortInfo data for this port. * *	ext_port_info *		Mellanox vendor specific ExtendedPortInfo data for this port. * *	port_guid *		Port GUID value of this port.  For switches, *		all ports share the same GUID value. * *	p_guids *		Pointer to array of GUIDs obtained from GUIDInfo. *		This pointer is null for switch physical/external ports *		(used for endports only). * *	port_num *		The port number of this port.  The PortInfo also *		contains a port_number, but that number is not *		the port number of this port, but rather the number *		of the port that received the SMP during discovery. *		Therefore, we must keep a separate record for this *		port's port number. * *	p_node *		Pointer to the parent Node object of this Physical Port. * *	p_remote_physp *		Pointer to the Physical Port on the other side of the wire. *		If this pointer is NULL no link exists at this port. * *	healthy *		Tracks the health of the port. Normally should be TRUE but *		might change as a result of incoming traps indicating the port *		healthy is questionable. * *	vl_high_limit *		PortInfo:VLHighLimit value which installed by QoS manager *		and should be uploaded to port's PortInfo * *	need_update *		When set indicates that port was probably reset and port *		related tables (PKey, SL2VL, VLArb) require refreshing. * *	is_prof_ignored *		When set indicates that switch port will be ignored by *		the link load equalization algorithm. * *	dr_path *		The directed route path to this port. * *	pkeys *		osm_pkey_tbl_t object holding the port PKeys. * *	vl_arb[] *		Each Physical Port has 4 sections of VL Arbitration table. * *	slvl_by_port *		A vector of pointers to the sl2vl tables (ordered by input port). *		Switches have an entry for every other input port (inc SMA=0). *		On CAs only one per port. * *	hop_wf *		Hop weighting factor to be used in the routing. * *	sw_cong_setting *		Physical port switch congestion settings (switches only) * *	ca_cong_setting *		Physical port ca congestion settings (cas only) * *	cc_tbl *		Physical port ca congestion control table (cas only) * * SEE ALSO *	Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_construct * NAME *	osm_physp_construct * * DESCRIPTION *	Constructs a Physical Port. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_physp_construct
parameter_list|(
name|IN
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_physp *		[in] Pointer to an osm_physp_t object to initialize. * * RETURN VALUES *	This function does not return a value. * * NOTES * * SEE ALSO *	Port, Physical Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_init * NAME *	osm_physp_init * * DESCRIPTION *	Initializes a Physical Port for use. * * SYNOPSIS */
end_comment

begin_decl_stmt
name|void
name|osm_physp_init
argument_list|(
name|IN
name|osm_physp_t
operator|*
name|p_physp
argument_list|,
name|IN
name|ib_net64_t
name|port_guid
argument_list|,
name|IN
name|uint8_t
name|port_num
argument_list|,
name|IN
specifier|const
expr|struct
name|osm_node
operator|*
name|p_node
argument_list|,
name|IN
name|osm_bind_handle_t
name|h_bind
argument_list|,
name|IN
name|uint8_t
name|hop_count
argument_list|,
name|IN
specifier|const
name|uint8_t
operator|*
name|p_initial_path
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* * PARAMETERS *	p_physp *		[in] Pointer to an osm_physp_t object to initialize. * *	port_guid *		[in] GUID value of this port.  Switch ports all share *		the same value. *		Caller should use 0 if the guid is unknown. * *	port_num *		[in] The port number of this port. * *	p_node *		[in] Pointer to the parent Node object of this Physical Port. * *	h_bind *		[in] Bind handle on which this port is accessed. *		Caller should use OSM_BIND_INVALID_HANDLE if the bind *		handle to this port is unknown. * *	hop_count *		[in] Directed route hop count to reach this port. *		Caller should use 0 if the hop count is unknown. * *	p_initial_path *		[in] Pointer to the directed route path to reach this node. *		Caller should use NULL if the path is unknown. * * RETURN VALUES *	This function does not return a value. * * NOTES * * SEE ALSO *	Port, Physical Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Port/void osm_physp_destroy * NAME *	osm_physp_destroy * * DESCRIPTION *	This function destroys a Port object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_physp_destroy
parameter_list|(
name|IN
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_port *		[in] Pointer to a PhysPort object to destroy. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Performs any necessary cleanup of the specified PhysPort object. *	Further operations should not be attempted on the destroyed object. *	This function should only be called after a call to osm_physp_construct or *	osm_physp_init. * * SEE ALSO *	Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_is_valid * NAME *	osm_physp_is_valid * * DESCRIPTION *	Returns TRUE if the Physical Port has been successfully initialized. *	FALSE otherwise. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|osm_physp_is_valid
parameter_list|(
name|IN
specifier|const
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_physp
argument_list|)
expr_stmt|;
return|return
operator|(
name|p_physp
operator|->
name|port_guid
operator|!=
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_physp *		[in] Pointer to an osm_physp_t object. * * RETURN VALUES *	Returns TRUE if the Physical Port has been successfully initialized. *	FALSE otherwise. * * NOTES * * SEE ALSO *	Port, Physical Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_is_healthy * NAME *	osm_physp_is_healthy * * DESCRIPTION *	Returns TRUE if the Physical Port has been maked as healthy *	FALSE otherwise. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|osm_physp_is_healthy
parameter_list|(
name|IN
specifier|const
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_physp
argument_list|)
expr_stmt|;
return|return
name|p_physp
operator|->
name|healthy
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_physp *		[in] Pointer to an osm_physp_t object. * * RETURN VALUES *	Returns TRUE if the Physical Port has been maked as healthy *	FALSE otherwise. *  All physical ports are initialized as "healthy" but may be marked *  otherwise if a received trap claims otherwise. * * NOTES * * SEE ALSO *	Port, Physical Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_link_is_healthy * NAME *	osm_link_is_healthy * * DESCRIPTION *	Returns TRUE if the link given by the physical port is health, *  and FALSE otherwise. Link is healthy if both its physical ports are *  healthy * * SYNOPSIS */
end_comment

begin_function_decl
name|boolean_t
name|osm_link_is_healthy
parameter_list|(
name|IN
specifier|const
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_physp *		[in] Pointer to an osm_physp_t object. * * RETURN VALUES *	TRUE if both physical ports on the link are healthy, and FALSE otherwise. *  All physical ports are initialized as "healthy" but may be marked *  otherwise if a received trap claiming otherwise. * * NOTES * * SEE ALSO *	Port, Physical Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_set_health * NAME *	osm_physp_set_health * * DESCRIPTION *	Sets the port health flag. TRUE means the port is healthy and *  should be used for packet routing. FALSE means it should be avoided. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osm_physp_set_health
parameter_list|(
name|IN
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|,
name|IN
name|boolean_t
name|is_healthy
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_physp
argument_list|)
expr_stmt|;
name|p_physp
operator|->
name|healthy
operator|=
name|is_healthy
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_physp *		[in] Pointer to an osm_physp_t object. * *	is_healthy *		[in] The health value to be assigned to the port. *		     TRUE if the Physical Port should been maked as healthy *		     FALSE otherwise. * * RETURN VALUES *  NONE * * NOTES * * SEE ALSO *	Port, Physical Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_set_port_info * NAME *	osm_physp_set_port_info * * DESCRIPTION *	Copies the PortInfo attribute into the Physical Port object *	based on the PortState. * * SYNOPSIS */
end_comment

begin_decl_stmt
name|void
name|osm_physp_set_port_info
argument_list|(
name|IN
name|osm_physp_t
operator|*
name|p_physp
argument_list|,
name|IN
specifier|const
name|ib_port_info_t
operator|*
name|p_pi
argument_list|,
name|IN
specifier|const
expr|struct
name|osm_sm
operator|*
name|p_sm
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* * PARAMETERS *	p_physp *		[in] Pointer to an osm_physp_t object. * *	p_pi *		[in] Pointer to the IBA defined PortInfo at this port number. * *	p_sm *		[in] Pointer to an osm_sm_t object. * * RETURN VALUES *	This function does not return a value. * * NOTES * * SEE ALSO *	Port, Physical Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_set_base_lid * NAME *	osm_physp_set_base_lid * * DESCRIPTION *	Sets the base lid for this Physical Port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osm_physp_set_base_lid
parameter_list|(
name|IN
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|,
name|IN
name|ib_net16_t
name|base_lid
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_physp
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|osm_physp_is_valid
argument_list|(
name|p_physp
argument_list|)
argument_list|)
expr_stmt|;
name|p_physp
operator|->
name|port_info
operator|.
name|base_lid
operator|=
name|base_lid
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_physp *		[in] Pointer to an osm_physp_t object. * *	base_lid *		[in] Lid to set. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_set_pkey_tbl * NAME *  osm_physp_set_pkey_tbl * * DESCRIPTION *  Copies the P_Key table into the Physical Port object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_physp_set_pkey_tbl
parameter_list|(
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
specifier|const
name|osm_subn_t
modifier|*
name|p_subn
parameter_list|,
name|IN
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|,
name|IN
name|ib_pkey_table_t
modifier|*
name|p_pkey_tbl
parameter_list|,
name|IN
name|uint16_t
name|block_num
parameter_list|,
name|IN
name|boolean_t
name|is_set
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_log *		[in] Pointer to a log object. * *	p_subn *		[in] Pointer to the subnet data structure. * *	p_physp *		[in] Pointer to an osm_physp_t object. * *	p_pkey_tbl *		[in] Pointer to the IBA defined P_Key table for this port *		     number. * *	block_num *		[in] The part of the P_Key table as defined in the IBA *		     (valid values 0-2047, and is further limited by the *		     partitionCap). * * RETURN VALUES *  This function does not return a value. * * NOTES * * SEE ALSO *  Port, Physical Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_get_pkey_tbl * NAME *  osm_physp_get_pkey_tbl * * DESCRIPTION *  Returns a pointer to the P_Key table object of the Physical Port object. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
specifier|const
name|osm_pkey_tbl_t
modifier|*
name|osm_physp_get_pkey_tbl
parameter_list|(
name|IN
specifier|const
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|osm_physp_is_valid
argument_list|(
name|p_physp
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 	   (14.2.5.7) - the block number valid values are 0-2047, and are 	   further limited by the size of the P_Key table specified by the 	   PartitionCap on the node. 	 */
return|return
operator|&
name|p_physp
operator|->
name|pkeys
return|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* * PARAMETERS *	p_physp *		[in] Pointer to an osm_physp_t object. * * RETURN VALUES *  The pointer to the P_Key table object. * * NOTES * * SEE ALSO *  Port, Physical Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_set_slvl_tbl * NAME *	osm_physp_set_slvl_tbl * * DESCRIPTION *	Copies the SLtoVL attribute into the Physical Port object. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osm_physp_set_slvl_tbl
parameter_list|(
name|IN
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|,
name|IN
name|ib_slvl_table_t
modifier|*
name|p_slvl_tbl
parameter_list|,
name|IN
name|uint8_t
name|in_port_num
parameter_list|)
block|{
name|ib_slvl_table_t
modifier|*
name|p_tbl
decl_stmt|;
name|CL_ASSERT
argument_list|(
name|p_slvl_tbl
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|osm_physp_is_valid
argument_list|(
name|p_physp
argument_list|)
argument_list|)
expr_stmt|;
name|p_tbl
operator|=
operator|(
name|ib_slvl_table_t
operator|*
operator|)
name|cl_ptr_vector_get
argument_list|(
operator|&
name|p_physp
operator|->
name|slvl_by_port
argument_list|,
name|in_port_num
argument_list|)
expr_stmt|;
operator|*
name|p_tbl
operator|=
operator|*
name|p_slvl_tbl
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_physp *		[in] Pointer to an osm_physp_t object. * *	p_slvl_tbl *		[in] Pointer to the IBA defined SLtoVL map table for this *		     port number. * *	in_port_num *		[in] Input Port Number for this SLtoVL. * * RETURN VALUES *	This function does not return a value. * * NOTES * * SEE ALSO *	Port, Physical Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_get_slvl_tbl * NAME *	osm_physp_get_slvl_tbl * * DESCRIPTION *	Returns a pointer to the SLtoVL attribute of the Physical Port object. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_slvl_table_t
modifier|*
name|osm_physp_get_slvl_tbl
parameter_list|(
name|IN
specifier|const
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|,
name|IN
name|uint8_t
name|in_port_num
parameter_list|)
block|{
name|ib_slvl_table_t
modifier|*
name|p_tbl
decl_stmt|;
name|CL_ASSERT
argument_list|(
name|osm_physp_is_valid
argument_list|(
name|p_physp
argument_list|)
argument_list|)
expr_stmt|;
name|p_tbl
operator|=
operator|(
name|ib_slvl_table_t
operator|*
operator|)
name|cl_ptr_vector_get
argument_list|(
operator|&
name|p_physp
operator|->
name|slvl_by_port
argument_list|,
name|in_port_num
argument_list|)
expr_stmt|;
return|return
name|p_tbl
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_physp *		[in] Pointer to an osm_physp_t object. * *	in_port_num *		[in] Input Port Number for this SLtoVL. * * RETURN VALUES *	The pointer to the slvl table * * NOTES * * SEE ALSO *	Port, Physical Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_set_vla_tbl * NAME *	osm_physp_set_vla_tbl * * DESCRIPTION *	Copies the VL Arbitration attribute into the Physical Port object. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osm_physp_set_vla_tbl
parameter_list|(
name|IN
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|,
name|IN
name|ib_vl_arb_table_t
modifier|*
name|p_vla_tbl
parameter_list|,
name|IN
name|uint8_t
name|block_num
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_vla_tbl
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|osm_physp_is_valid
argument_list|(
name|p_physp
argument_list|)
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
operator|(
literal|1
operator|<=
name|block_num
operator|)
operator|&&
operator|(
name|block_num
operator|<=
literal|4
operator|)
argument_list|)
expr_stmt|;
name|p_physp
operator|->
name|vl_arb
index|[
name|block_num
operator|-
literal|1
index|]
operator|=
operator|*
name|p_vla_tbl
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_physp *		[in] Pointer to an osm_physp_t object. * *	p_vla_tbl *		[in] Pointer to the IBA defined VL Arbitration table for this *		     port number. * *	block_num *		[in] The part of the VL arbitration as defined in the IBA *		     (valid values 1-4) * * RETURN VALUES *	This function does not return a value. * * NOTES * * SEE ALSO *	Port, Physical Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_get_vla_tbl * NAME *	osm_physp_get_vla_tbl * * DESCRIPTION *	Returns a pointer to the VL Arbitration table of the Physical Port object. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_vl_arb_table_t
modifier|*
name|osm_physp_get_vla_tbl
parameter_list|(
name|IN
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|,
name|IN
name|uint8_t
name|block_num
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|osm_physp_is_valid
argument_list|(
name|p_physp
argument_list|)
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
operator|(
literal|1
operator|<=
name|block_num
operator|)
operator|&&
operator|(
name|block_num
operator|<=
literal|4
operator|)
argument_list|)
expr_stmt|;
return|return
operator|&
operator|(
name|p_physp
operator|->
name|vl_arb
index|[
name|block_num
operator|-
literal|1
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_physp *		[in] Pointer to an osm_physp_t object. * *	block_num *		[in] The part of the VL arbitration as defined in the IBA *		     (valid values 1-4) * * RETURN VALUES *  The pointer to the VL Arbitration table * * NOTES * * SEE ALSO *	Port, Physical Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_get_remote * NAME *	osm_physp_get_remote * * DESCRIPTION *	Returns a pointer to the Physical Port on the other side the wire. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|osm_physp_t
modifier|*
name|osm_physp_get_remote
parameter_list|(
name|IN
specifier|const
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|osm_physp_is_valid
argument_list|(
name|p_physp
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|p_physp
operator|->
name|p_remote_physp
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_physp *		[in] Pointer to an osm_physp_t object. * * RETURN VALUES *	Returns a pointer to the Physical Port on the other side of *	the wire.  A return value of NULL means there is no link at this port. * * NOTES * * SEE ALSO *	Port, Physical Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_get_port_guid * NAME *	osm_physp_get_port_guid * * DESCRIPTION *	Returns the port guid of this physical port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_net64_t
name|osm_physp_get_port_guid
parameter_list|(
name|IN
specifier|const
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|osm_physp_is_valid
argument_list|(
name|p_physp
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|p_physp
operator|->
name|port_guid
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_physp *		[in] Pointer to an osm_physp_t object. * * RETURN VALUES *	Returns the port guid of this physical port. * * NOTES * * SEE ALSO *	Port, Physical Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_get_subnet_prefix * NAME *	osm_physp_get_subnet_prefix * * DESCRIPTION *	Returns the subnet prefix for this physical port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_net64_t
name|osm_physp_get_subnet_prefix
parameter_list|(
name|IN
specifier|const
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|osm_physp_is_valid
argument_list|(
name|p_physp
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|p_physp
operator|->
name|port_info
operator|.
name|subnet_prefix
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_physp *		[in] Pointer to an osm_physp_t object. * * RETURN VALUES *	Returns the subnet prefix for this physical port. * * NOTES * * SEE ALSO *	Port, Physical Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_link_exists * NAME *	osm_physp_link_exists * * DESCRIPTION *	Returns TRUE if the Physical Port has a link to the specified port. *	FALSE otherwise. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|osm_physp_link_exists
parameter_list|(
name|IN
specifier|const
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|,
name|IN
specifier|const
name|osm_physp_t
modifier|*
name|p_remote_physp
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_physp
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|osm_physp_is_valid
argument_list|(
name|p_physp
argument_list|)
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_remote_physp
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|osm_physp_is_valid
argument_list|(
name|p_remote_physp
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|p_physp
operator|->
name|p_remote_physp
operator|==
name|p_remote_physp
operator|)
operator|&&
operator|(
name|p_remote_physp
operator|->
name|p_remote_physp
operator|==
name|p_physp
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_physp *		[in] Pointer to an osm_physp_t object. * *	p_remote_physp *		[in] Pointer to an osm_physp_t object. * * RETURN VALUES *	Returns TRUE if the Physical Port has a link to another port. *	FALSE otherwise. * * NOTES * * SEE ALSO *	Port, Physical Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_link * NAME *	osm_physp_link * * DESCRIPTION *	Sets the pointers to the Physical Ports on the other side the wire. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osm_physp_link
parameter_list|(
name|IN
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|,
name|IN
name|osm_physp_t
modifier|*
name|p_remote_physp
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_physp
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_remote_physp
argument_list|)
expr_stmt|;
name|p_physp
operator|->
name|p_remote_physp
operator|=
name|p_remote_physp
expr_stmt|;
name|p_remote_physp
operator|->
name|p_remote_physp
operator|=
name|p_physp
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_physp *		[in] Pointer to an osm_physp_t object to link. * *	p_remote_physp *		[in] Pointer to the adjacent osm_physp_t object to link. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *	Port, Physical Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_unlink * NAME *	osm_physp_unlink * * DESCRIPTION *	Clears the pointers to the Physical Port on the other side the wire. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osm_physp_unlink
parameter_list|(
name|IN
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|,
name|IN
name|osm_physp_t
modifier|*
name|p_remote_physp
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_physp
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_remote_physp
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|osm_physp_link_exists
argument_list|(
name|p_physp
argument_list|,
name|p_remote_physp
argument_list|)
argument_list|)
expr_stmt|;
name|p_physp
operator|->
name|p_remote_physp
operator|=
name|NULL
expr_stmt|;
name|p_remote_physp
operator|->
name|p_remote_physp
operator|=
name|NULL
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_physp *		[in] Pointer to an osm_physp_t object to link. * *	p_remote_physp *		[in] Pointer to the adjacent osm_physp_t object to link. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *	Port, Physical Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_has_any_link * NAME *	osm_physp_has_any_link * * DESCRIPTION *	Returns TRUE if the Physical Port has a link to another port. *	FALSE otherwise. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|osm_physp_has_any_link
parameter_list|(
name|IN
specifier|const
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_physp
argument_list|)
expr_stmt|;
if|if
condition|(
name|osm_physp_is_valid
argument_list|(
name|p_physp
argument_list|)
condition|)
return|return
operator|(
name|p_physp
operator|->
name|p_remote_physp
operator|!=
name|NULL
operator|)
return|;
else|else
return|return
name|FALSE
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_physp *		[in] Pointer to an osm_physp_t object. * * RETURN VALUES *	Returns TRUE if the Physical Port has a link to another port. *	FALSE otherwise. * * NOTES * * SEE ALSO *	Port, Physical Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_get_port_num * NAME *	osm_physp_get_port_num * * DESCRIPTION *	Returns the local port number of this Physical Port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|osm_physp_get_port_num
parameter_list|(
name|IN
specifier|const
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_physp
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|osm_physp_is_valid
argument_list|(
name|p_physp
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|p_physp
operator|->
name|port_num
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_physp *		[in] Pointer to an osm_physp_t object. * * RETURN VALUES *	Returns the local port number of this Physical Port. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_get_node_ptr * NAME *	osm_physp_get_node_ptr * * DESCRIPTION *	Returns a pointer to the parent Node object for this port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|struct
name|osm_node
modifier|*
name|osm_physp_get_node_ptr
parameter_list|(
name|IN
specifier|const
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_physp
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|osm_physp_is_valid
argument_list|(
name|p_physp
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|p_physp
operator|->
name|p_node
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_physp *		[in] Pointer to an osm_physp_t object. * * RETURN VALUES *	Returns a pointer to the parent Node object for this port. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_get_port_state * NAME *	osm_physp_get_port_state * * DESCRIPTION *	Returns the port state of this Physical Port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|osm_physp_get_port_state
parameter_list|(
name|IN
specifier|const
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_physp
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|osm_physp_is_valid
argument_list|(
name|p_physp
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ib_port_info_get_port_state
argument_list|(
operator|&
name|p_physp
operator|->
name|port_info
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_physp *		[in] Pointer to an osm_physp_t object. * * RETURN VALUES *	Returns the local port number of this Physical Port. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_get_base_lid * NAME *	osm_physp_get_base_lid * * DESCRIPTION *	Returns the base lid of this Physical Port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_net16_t
name|osm_physp_get_base_lid
parameter_list|(
name|IN
specifier|const
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_physp
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|osm_physp_is_valid
argument_list|(
name|p_physp
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|p_physp
operator|->
name|port_info
operator|.
name|base_lid
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_physp *		[in] Pointer to an osm_physp_t object. * * RETURN VALUES *	Returns the base lid of this Physical Port. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_get_lmc * NAME *	osm_physp_get_lmc * * DESCRIPTION *	Returns the LMC value of this Physical Port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|osm_physp_get_lmc
parameter_list|(
name|IN
specifier|const
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_physp
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|osm_physp_is_valid
argument_list|(
name|p_physp
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ib_port_info_get_lmc
argument_list|(
operator|&
name|p_physp
operator|->
name|port_info
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_physp *		[in] Pointer to an osm_physp_t object. * * RETURN VALUES *	Returns the LMC value of this Physical Port. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_get_dr_path_ptr * NAME *	osm_physp_get_dr_path_ptr * * DESCRIPTION *	Returns a pointer to the directed route path for this port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|osm_dr_path_t
modifier|*
name|osm_physp_get_dr_path_ptr
parameter_list|(
name|IN
specifier|const
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_physp
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|osm_physp_is_valid
argument_list|(
name|p_physp
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|osm_dr_path_t
operator|*
operator|)
operator|&
name|p_physp
operator|->
name|dr_path
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_physp *		[in] Pointer to a Physical Port object. * * RETURN VALUES *	Returns a pointer to the directed route path for this port. * * NOTES * * SEE ALSO *	Physical Port object *********/
end_comment

begin_comment
comment|/****h* OpenSM/Port * NAME *	Port * * DESCRIPTION *	The Port object encapsulates the information needed by the *	OpenSM to manage ports.  The OpenSM allocates one Port object *	per port in the IBA subnet. * *	Each Port object is associated with a single port GUID.  A Port object *	contains 1 or more Physical Port objects.  An end point node has *	one Physical Port per Port.  A switch node has more than *	one Physical Port per Port. * *	The Port object is not thread safe, thus callers must provide *	serialization. * *	These objects should be treated as opaque and should be *	manipulated only through the provided functions. * * AUTHOR *	Steve King, Intel * *********/
end_comment

begin_comment
comment|/****s* OpenSM: Port/osm_port_t * NAME *	osm_port_t * * DESCRIPTION *	This object represents a logical port on a switch, router, or CA. * *	The osm_port_t object should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_port
block|{
name|cl_map_item_t
name|map_item
decl_stmt|;
name|cl_list_item_t
name|list_item
decl_stmt|;
name|struct
name|osm_node
modifier|*
name|p_node
decl_stmt|;
name|ib_net64_t
name|guid
decl_stmt|;
name|uint32_t
name|discovery_count
decl_stmt|;
name|unsigned
name|is_new
decl_stmt|;
name|osm_physp_t
modifier|*
name|p_physp
decl_stmt|;
name|cl_qlist_t
name|mcm_list
decl_stmt|;
name|int
name|flag
decl_stmt|;
name|int
name|use_scatter
decl_stmt|;
name|unsigned
name|int
name|cc_timeout_count
decl_stmt|;
name|int
name|cc_unavailable_flag
decl_stmt|;
name|void
modifier|*
name|priv
decl_stmt|;
name|ib_net16_t
name|lid
decl_stmt|;
block|}
name|osm_port_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	map_item *		Linkage structure for cl_qmap.  MUST BE FIRST MEMBER! * *	list_item *		Linkage structure for cl_qlist. Used by ucast mgr during *		LFT calculation. * *	p_node *		Points to the Node object that owns this port. * *	guid *		Manufacturer assigned GUID for this port. * *	discovery_count *		The number of times this port has been discovered *		during the current fabric sweep.  This number is reset *		to zero at the start of a sweep. * *	p_physp *		The pointer to physical port used when physical *		characteristics contained in the Physical Port are needed. * *	mcm_list *		Multicast member list * *	flag *		Utility flag for port management * *	cc_timeout_count *		Count number of times congestion control config times out. * *	cc_unavailable_flag *		Flag indicating if congestion control is not supported. * * SEE ALSO *	Port, Physical Port, Physical Port Table *********/
end_comment

begin_comment
comment|/****f* OpenSM: Port/osm_port_delete * NAME *	osm_port_delete * * DESCRIPTION *	This function destroys and deallocates a Port object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_port_delete
parameter_list|(
name|IN
name|OUT
name|osm_port_t
modifier|*
modifier|*
name|pp_port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	pp_port *		[in][out] Pointer to a pointer to a Port object to delete. *		On return, this pointer is NULL. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Performs any necessary cleanup of the specified Port object. * * SEE ALSO *	Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Port/osm_port_new * NAME *	osm_port_new * * DESCRIPTION *	This function allocates and initializes a Port object. * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_port_t
modifier|*
name|osm_port_new
parameter_list|(
name|IN
specifier|const
name|ib_node_info_t
modifier|*
name|p_ni
parameter_list|,
name|IN
name|struct
name|osm_node
modifier|*
name|p_parent_node
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_ni *		[in] Pointer to the NodeInfo attribute relevant for this port. * *	p_parent_node *		[in] Pointer to the initialized parent osm_node_t object *		that owns this port. * * RETURN VALUE *	Pointer to the initialize Port object. * * NOTES *	Allows calling other port methods. * * SEE ALSO *	Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Port/osm_port_get_base_lid * NAME *	osm_port_get_base_lid * * DESCRIPTION *	Gets the base LID of a port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_net16_t
name|osm_port_get_base_lid
parameter_list|(
name|IN
specifier|const
name|osm_port_t
modifier|*
name|p_port
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_port
operator|->
name|p_physp
operator|&&
name|osm_physp_is_valid
argument_list|(
name|p_port
operator|->
name|p_physp
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|osm_physp_get_base_lid
argument_list|(
name|p_port
operator|->
name|p_physp
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_port *		[in] Pointer to a Port object. * * RETURN VALUE *	Base LID of the port. *	If the return value is 0, then this port has no assigned LID. * * NOTES * * SEE ALSO *	Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Port/osm_port_get_lmc * NAME *	osm_port_get_lmc * * DESCRIPTION *	Gets the LMC value of a port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|osm_port_get_lmc
parameter_list|(
name|IN
specifier|const
name|osm_port_t
modifier|*
name|p_port
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_port
operator|->
name|p_physp
operator|&&
name|osm_physp_is_valid
argument_list|(
name|p_port
operator|->
name|p_physp
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|osm_physp_get_lmc
argument_list|(
name|p_port
operator|->
name|p_physp
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_port *		[in] Pointer to a Port object. * * RETURN VALUE *	Gets the LMC value of a port. * * NOTES * * SEE ALSO *	Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Port/osm_port_get_guid * NAME *	osm_port_get_guid * * DESCRIPTION *	Gets the GUID of a port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_net64_t
name|osm_port_get_guid
parameter_list|(
name|IN
specifier|const
name|osm_port_t
modifier|*
name|p_port
parameter_list|)
block|{
return|return
name|p_port
operator|->
name|guid
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_port *		[in] Pointer to a Port object. * * RETURN VALUE *	Manufacturer assigned GUID of the port. * * NOTES * * SEE ALSO *	Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Port/osm_port_get_lid_range_ho * NAME *	osm_port_get_lid_range_ho * * DESCRIPTION *	Returns the HOST ORDER lid min and max values for this port, *	based on the lmc value. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_port_get_lid_range_ho
parameter_list|(
name|IN
specifier|const
name|osm_port_t
modifier|*
name|p_port
parameter_list|,
name|OUT
name|uint16_t
modifier|*
name|p_min_lid
parameter_list|,
name|OUT
name|uint16_t
modifier|*
name|p_max_lid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_port *		[in] Pointer to a Port object. * *	p_min_lid *		[out] Pointer to the minimum LID value occupied by this port. * *	p_max_lid *		[out] Pointer to the maximum LID value occupied by this port. * * RETURN VALUE *	None. * * NOTES * * SEE ALSO *	Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_calc_link_mtu * NAME *	osm_physp_calc_link_mtu * * DESCRIPTION *	Calculate the Port MTU based on current and remote *  physical ports MTU CAP values. * * SYNOPSIS */
end_comment

begin_function_decl
name|uint8_t
name|osm_physp_calc_link_mtu
parameter_list|(
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
specifier|const
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|,
name|IN
name|uint8_t
name|current_mtu
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_log *		[in] Pointer to a log object. * *	p_physp *		[in] Pointer to an osm_physp_t object. * *	current_mtu *		[in] Current neighbor mtu on this port * * RETURN VALUES *	The MTU of the link to be used. * * NOTES * * SEE ALSO *	PhysPort object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_calc_link_op_vls * NAME *	osm_physp_calc_link_op_vls * * DESCRIPTION *	Calculate the Port OP_VLS based on current and remote *  physical ports VL CAP values. Allowing user option for a max limit. * * SYNOPSIS */
end_comment

begin_function_decl
name|uint8_t
name|osm_physp_calc_link_op_vls
parameter_list|(
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
specifier|const
name|osm_subn_t
modifier|*
name|p_subn
parameter_list|,
name|IN
specifier|const
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|,
name|IN
name|uint8_t
name|current_op_vls
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_log *		[in] Pointer to a log object. * *	p_subn *		[in] Pointer to the subnet object for accessing of the options. * *	p_physp *		[in] Pointer to an osm_physp_t object. * *	current_op_vls *		[in] Current operational VL on the port * * RETURN VALUES *	The OP_VLS of the link to be used. * * NOTES * * SEE ALSO *  PhysPort object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Physical Port/osm_physp_replace_dr_path_with_alternate_dr_path * NAME *	osm_physp_replace_dr_path_with_alternate_dr_path * * DESCRIPTION *	Replace the direct route path for the given phys port with an *  alternate path going through forien set of phys port. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_physp_replace_dr_path_with_alternate_dr_path
parameter_list|(
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
name|osm_subn_t
specifier|const
modifier|*
name|p_subn
parameter_list|,
name|IN
name|osm_physp_t
specifier|const
modifier|*
name|p_physp
parameter_list|,
name|IN
name|osm_bind_handle_t
modifier|*
name|h_bind
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_log *		[in] Pointer to a log object. * *	p_subn *		[in] Pointer to the subnet object for accessing of the options. * *	p_physp *		[in] Pointer to an osm_physp_t object. * *	h_bind *		[in] Pointer to osm_bind_handle_t object. * * RETURN VALUES *	NONE * * NOTES * * SEE ALSO *	PhysPort object *********/
end_comment

begin_comment
comment|/****s* OpenSM: Port/osm_alias_guid_t * NAME *	osm_alias_guid_t * * DESCRIPTION *	This object represents an alias guid for an endport. * *	The osm_alias_guid_t object should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_alias_guid
block|{
name|cl_map_item_t
name|map_item
decl_stmt|;
name|ib_net64_t
name|alias_guid
decl_stmt|;
name|osm_port_t
modifier|*
name|p_base_port
decl_stmt|;
block|}
name|osm_alias_guid_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	map_item *		Linkage structure for cl_qmap.  MUST BE FIRST MEMBER! * *	alias_guid *		Alias GUID for port obtained from SM GUIDInfo attribute * *	p_base_port *		Pointer to osm_port_t for base port GUID * * SEE ALSO *	Port, Physical Port, Physical Port Table */
end_comment

begin_comment
comment|/****f* OpenSM: Port/osm_alias_guid_new * NAME *	osm_alias_guid_new * * DESCRIPTION *	This function allocates and initializes an alias guid object. * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_alias_guid_t
modifier|*
name|osm_alias_guid_new
parameter_list|(
name|IN
specifier|const
name|ib_net64_t
name|alias_guid
parameter_list|,
name|IN
name|osm_port_t
modifier|*
name|p_base_port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	alias_guid *		[in] Alias GUID in network order * *	p_base_port *		[in] Pointer to the port for this base GUID * * RETURN VALUE *	Pointer to the initialized alias guid object. * * NOTES *	Allows calling other alias guid methods. * * SEE ALSO *	Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Port/osm_alias_guid_delete * NAME *	osm_alias_guid_delete * * DESCRIPTION *	This function destroys and deallocates an alias guid object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_alias_guid_delete
parameter_list|(
name|IN
name|OUT
name|osm_alias_guid_t
modifier|*
modifier|*
name|pp_alias_guid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	pp_alias_guid *		[in][out] Pointer to a pointer to an alias guid object to delete. *		On return, this pointer is NULL. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Performs any necessary cleanup of the specified alias guid object. * * SEE ALSO *	Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Port/osm_alias_guid_get_alias_guid * NAME *	osm_alias_guid_get_alias_guid * * DESCRIPTION *	This function retrieves alias guid from alias guid object. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_net64_t
name|osm_alias_guid_get_alias_guid
parameter_list|(
name|IN
name|osm_alias_guid_t
modifier|*
name|p_alias_guid
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_alias_guid
argument_list|)
expr_stmt|;
return|return
name|p_alias_guid
operator|->
name|alias_guid
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_alias_guid *		[in] Pointer to a pointer to an alias guid object. * * RETURN VALUE *	This function returns the alias guid or NULL if fails. * * NOTES * * SEE ALSO *	Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Port/osm_alias_guid_get_base_guid * NAME *	osm_alias_guid_get_base_guid * * DESCRIPTION *	This function retrieves base guid from alias guid object. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_net64_t
name|osm_alias_guid_get_base_guid
parameter_list|(
name|IN
name|osm_alias_guid_t
modifier|*
name|p_alias_guid
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_alias_guid
argument_list|)
expr_stmt|;
return|return
name|osm_port_get_guid
argument_list|(
name|p_alias_guid
operator|->
name|p_base_port
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_alias_guid *		[in] Pointer to a pointer to an alias guid object. * * RETURN VALUE *	This function returns the base guid or NULL if fails. * * NOTES * * SEE ALSO *	Port *********/
end_comment

begin_comment
comment|/****f* OpenSM: Port/osm_port_clear_base_lid * NAME *	osm_port_clear_base_lid * * DESCRIPTION *	Clear the base lid of a given port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osm_port_clear_base_lid
parameter_list|(
name|OUT
name|osm_port_t
modifier|*
name|p_port
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_port
argument_list|)
expr_stmt|;
name|p_port
operator|->
name|lid
operator|=
literal|0
expr_stmt|;
name|osm_physp_set_base_lid
argument_list|(
name|p_port
operator|->
name|p_physp
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_port *		[out] Pointer to a Port object. * * RETURN VALUE *	None * * NOTES * * SEE ALSO *	Port *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_PORT_H_ */
end_comment

end_unit

