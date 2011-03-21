begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2008 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_HELPER_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_HELPER_H_
end_define

begin_include
include|#
directive|include
file|<iba/ib_types.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_dispatcher.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_base.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_log.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_msgdef.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_path.h>
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

begin_function_decl
name|BEGIN_C_DECLS
comment|/*  * Abstract:  * 	Declaration of helpful functions.  */
comment|/****f* OpenSM: Helper/ib_get_sa_method_str  * NAME  *	ib_get_sa_method_str  *  * DESCRIPTION  *	Returns a string for the specified SA Method value.  *  * SYNOPSIS  */
specifier|const
name|char
modifier|*
name|ib_get_sa_method_str
parameter_list|(
name|IN
name|uint8_t
name|method
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * PARAMETERS  *	method  *		[in] Network order METHOD ID value.  *  * RETURN VALUES  *	Pointer to the method string.  *  * NOTES  *  * SEE ALSO  *********/
end_comment

begin_comment
comment|/****f* OpenSM: Helper/ib_get_sm_method_str * NAME *	ib_get_sm_method_str * * DESCRIPTION *	Returns a string for the specified SM Method value. * * SYNOPSIS */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|ib_get_sm_method_str
parameter_list|(
name|IN
name|uint8_t
name|method
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	method *		[in] Network order METHOD ID value. * * RETURN VALUES *	Pointer to the method string. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Helper/ib_get_sm_attr_str * NAME *	ib_get_sm_attr_str * * DESCRIPTION *	Returns a string for the specified SM attribute value. * * SYNOPSIS */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|ib_get_sm_attr_str
parameter_list|(
name|IN
name|ib_net16_t
name|attr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	attr *		[in] Network order attribute ID value. * * RETURN VALUES *	Pointer to the attribute string. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Helper/ib_get_sa_attr_str * NAME *	ib_get_sa_attr_str * * DESCRIPTION *	Returns a string for the specified SA attribute value. * * SYNOPSIS */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|ib_get_sa_attr_str
parameter_list|(
name|IN
name|ib_net16_t
name|attr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	attr *		[in] Network order attribute ID value. * * RETURN VALUES *	Pointer to the attribute string. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Helper/ib_get_trap_str * NAME *	ib_get_trap_str * * DESCRIPTION *	Returns a name for the specified trap. * * SYNOPSIS */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|ib_get_trap_str
parameter_list|(
name|uint16_t
name|trap_num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	trap_num *		[in] Network order trap number. * * RETURN VALUES *	Name of the trap. * *********/
end_comment

begin_comment
comment|/****f* OpenSM: Helper/osm_dump_port_info * NAME *	osm_dump_port_info * * DESCRIPTION *	Dumps the PortInfo attribute to the log. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_dump_port_info
parameter_list|(
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
specifier|const
name|ib_net64_t
name|node_guid
parameter_list|,
name|IN
specifier|const
name|ib_net64_t
name|port_guid
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|port_num
parameter_list|,
name|IN
specifier|const
name|ib_port_info_t
modifier|*
specifier|const
name|p_pi
parameter_list|,
name|IN
specifier|const
name|osm_log_level_t
name|log_level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_log *		[in] Pointer to the osm_log_t object * *	node_guid *		[in] Node GUID that owns this port. * *	port_guid *		[in] Port GUID for this port. * *	port_num *		[in] Port number for this port. * *	p_pi *		[in] Pointer to the PortInfo attribute * *	log_level *		[in] Log verbosity level with which to dump the data. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_function_decl
name|void
name|osm_dump_path_record
parameter_list|(
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
specifier|const
name|ib_path_rec_t
modifier|*
specifier|const
name|p_pr
parameter_list|,
name|IN
specifier|const
name|osm_log_level_t
name|log_level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_dump_multipath_record
parameter_list|(
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
specifier|const
name|ib_multipath_rec_t
modifier|*
specifier|const
name|p_mpr
parameter_list|,
name|IN
specifier|const
name|osm_log_level_t
name|log_level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_dump_node_record
parameter_list|(
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
specifier|const
name|ib_node_record_t
modifier|*
specifier|const
name|p_nr
parameter_list|,
name|IN
specifier|const
name|osm_log_level_t
name|log_level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_dump_mc_record
parameter_list|(
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
specifier|const
name|ib_member_rec_t
modifier|*
specifier|const
name|p_mcmr
parameter_list|,
name|IN
specifier|const
name|osm_log_level_t
name|log_level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_dump_link_record
parameter_list|(
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
specifier|const
name|ib_link_record_t
modifier|*
specifier|const
name|p_lr
parameter_list|,
name|IN
specifier|const
name|osm_log_level_t
name|log_level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_dump_service_record
parameter_list|(
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
specifier|const
name|ib_service_record_t
modifier|*
specifier|const
name|p_sr
parameter_list|,
name|IN
specifier|const
name|osm_log_level_t
name|log_level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_dump_portinfo_record
parameter_list|(
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
specifier|const
name|ib_portinfo_record_t
modifier|*
specifier|const
name|p_pir
parameter_list|,
name|IN
specifier|const
name|osm_log_level_t
name|log_level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_dump_guidinfo_record
parameter_list|(
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
specifier|const
name|ib_guidinfo_record_t
modifier|*
specifier|const
name|p_gir
parameter_list|,
name|IN
specifier|const
name|osm_log_level_t
name|log_level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_dump_inform_info
parameter_list|(
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
specifier|const
name|ib_inform_info_t
modifier|*
specifier|const
name|p_ii
parameter_list|,
name|IN
specifier|const
name|osm_log_level_t
name|log_level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_dump_inform_info_record
parameter_list|(
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
specifier|const
name|ib_inform_info_record_t
modifier|*
specifier|const
name|p_iir
parameter_list|,
name|IN
specifier|const
name|osm_log_level_t
name|log_level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_dump_switch_info_record
parameter_list|(
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
specifier|const
name|ib_switch_info_record_t
modifier|*
specifier|const
name|p_sir
parameter_list|,
name|IN
specifier|const
name|osm_log_level_t
name|log_level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_dump_sm_info_record
parameter_list|(
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
specifier|const
name|ib_sminfo_record_t
modifier|*
specifier|const
name|p_smir
parameter_list|,
name|IN
specifier|const
name|osm_log_level_t
name|log_level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_dump_pkey_block
parameter_list|(
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
name|uint64_t
name|port_guid
parameter_list|,
name|IN
name|uint16_t
name|block_num
parameter_list|,
name|IN
name|uint8_t
name|port_num
parameter_list|,
name|IN
specifier|const
name|ib_pkey_table_t
modifier|*
specifier|const
name|p_pkey_tbl
parameter_list|,
name|IN
specifier|const
name|osm_log_level_t
name|log_level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_dump_slvl_map_table
parameter_list|(
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
name|uint64_t
name|port_guid
parameter_list|,
name|IN
name|uint8_t
name|in_port_num
parameter_list|,
name|IN
name|uint8_t
name|out_port_num
parameter_list|,
name|IN
specifier|const
name|ib_slvl_table_t
modifier|*
specifier|const
name|p_slvl_tbl
parameter_list|,
name|IN
specifier|const
name|osm_log_level_t
name|log_level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_dump_vl_arb_table
parameter_list|(
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
name|uint64_t
name|port_guid
parameter_list|,
name|IN
name|uint8_t
name|block_num
parameter_list|,
name|IN
name|uint8_t
name|port_num
parameter_list|,
name|IN
specifier|const
name|ib_vl_arb_table_t
modifier|*
specifier|const
name|p_vla_tbl
parameter_list|,
name|IN
specifier|const
name|osm_log_level_t
name|log_level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****f* OpenSM: Helper/osm_dump_port_info * NAME *	osm_dump_port_info * * DESCRIPTION *	Dumps the PortInfo attribute to the log. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_dump_node_info
parameter_list|(
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
specifier|const
name|ib_node_info_t
modifier|*
specifier|const
name|p_ni
parameter_list|,
name|IN
specifier|const
name|osm_log_level_t
name|log_level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_log *		[in] Pointer to the osm_log_t object * *	p_ni *		[in] Pointer to the NodeInfo attribute * *	log_level *		[in] Log verbosity level with which to dump the data. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Helper/osm_dump_sm_info * NAME *	osm_dump_sm_info * * DESCRIPTION *	Dumps the SMInfo attribute to the log. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_dump_sm_info
parameter_list|(
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
specifier|const
name|ib_sm_info_t
modifier|*
specifier|const
name|p_smi
parameter_list|,
name|IN
specifier|const
name|osm_log_level_t
name|log_level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_log *		[in] Pointer to the osm_log_t object * *	p_smi *		[in] Pointer to the SMInfo attribute * *	log_level *		[in] Log verbosity level with which to dump the data. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Helper/osm_dump_switch_info * NAME *	osm_dump_switch_info * * DESCRIPTION *	Dumps the SwitchInfo attribute to the log. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_dump_switch_info
parameter_list|(
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
specifier|const
name|ib_switch_info_t
modifier|*
specifier|const
name|p_si
parameter_list|,
name|IN
specifier|const
name|osm_log_level_t
name|log_level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_log *		[in] Pointer to the osm_log_t object * *	p_si *		[in] Pointer to the SwitchInfo attribute * *	log_level *		[in] Log verbosity level with which to dump the data. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Helper/osm_dump_notice * NAME *	osm_dump_notice * * DESCRIPTION *	Dumps the Notice attribute to the log. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_dump_notice
parameter_list|(
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
specifier|const
name|ib_mad_notice_attr_t
modifier|*
name|p_ntci
parameter_list|,
name|IN
specifier|const
name|osm_log_level_t
name|log_level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_log *		[in] Pointer to the osm_log_t object * *	p_ntci *		[in] Pointer to the Notice attribute * *	log_level *		[in] Log verbosity level with which to dump the data. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/osm_get_disp_msg_str * NAME *	osm_get_disp_msg_str * * DESCRIPTION *	Returns a string for the specified Dispatcher message. * * SYNOPSIS */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|osm_get_disp_msg_str
parameter_list|(
name|IN
name|cl_disp_msgid_t
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	msg *		[in] Dispatcher message ID value. * * RETURN VALUES *	Pointer to the message discription string. * * NOTES * * SEE ALSO *********/
end_comment

begin_function_decl
name|void
name|osm_dump_dr_path
parameter_list|(
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
specifier|const
name|osm_dr_path_t
modifier|*
specifier|const
name|p_path
parameter_list|,
name|IN
specifier|const
name|osm_log_level_t
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_dump_smp_dr_path
parameter_list|(
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
specifier|const
name|ib_smp_t
modifier|*
specifier|const
name|p_smp
parameter_list|,
name|IN
specifier|const
name|osm_log_level_t
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_dump_dr_smp
parameter_list|(
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
specifier|const
name|ib_smp_t
modifier|*
specifier|const
name|p_smp
parameter_list|,
name|IN
specifier|const
name|osm_log_level_t
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_dump_sa_mad
parameter_list|(
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
specifier|const
name|ib_sa_mad_t
modifier|*
specifier|const
name|p_smp
parameter_list|,
name|IN
specifier|const
name|osm_log_level_t
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****f* IBA Base: Types/osm_get_sm_signal_str * NAME *	osm_get_sm_signal_str * * DESCRIPTION *	Returns a string for the specified SM state. * * SYNOPSIS */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|osm_get_sm_signal_str
parameter_list|(
name|IN
name|osm_signal_t
name|signal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	state *		[in] Signal value * * RETURN VALUES *	Pointer to the signal discription string. * * NOTES * * SEE ALSO *********/
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|osm_get_port_state_str_fixed_width
parameter_list|(
name|IN
name|uint8_t
name|port_state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|osm_get_node_type_str_fixed_width
parameter_list|(
name|IN
name|uint8_t
name|node_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|osm_get_manufacturer_str
parameter_list|(
name|IN
name|uint64_t
specifier|const
name|guid_ho
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|osm_get_mtu_str
parameter_list|(
name|IN
name|uint8_t
specifier|const
name|mtu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|osm_get_lwa_str
parameter_list|(
name|IN
name|uint8_t
specifier|const
name|lwa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|osm_get_mtu_str
parameter_list|(
name|IN
name|uint8_t
specifier|const
name|mtu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|osm_get_lwa_str
parameter_list|(
name|IN
name|uint8_t
specifier|const
name|lwa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|osm_get_lsa_str
parameter_list|(
name|IN
name|uint8_t
specifier|const
name|lsa
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****f* IBA Base: Types/osm_get_sm_mgr_signal_str * NAME *	osm_get_sm_mgr_signal_str * * DESCRIPTION *	Returns a string for the specified SM manager signal. * * SYNOPSIS */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|osm_get_sm_mgr_signal_str
parameter_list|(
name|IN
name|osm_sm_signal_t
name|signal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	signal *		[in] SM manager signal * * RETURN VALUES *	Pointer to the signal discription string. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* IBA Base: Types/osm_get_sm_mgr_state_str * NAME *	osm_get_sm_mgr_state_str * * DESCRIPTION *	Returns a string for the specified SM manager state. * * SYNOPSIS */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|osm_get_sm_mgr_state_str
parameter_list|(
name|IN
name|uint16_t
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	state *		[in] SM manager state * * RETURN VALUES *	Pointer to the state discription string. * * NOTES * * SEE ALSO *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_HELPER_H_ */
end_comment

end_unit

