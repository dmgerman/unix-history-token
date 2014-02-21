begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_subn_t.  *	This object represents an IBA subnet.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_PKT_RANDOMIZER_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_PKT_RANDOMIZER_H_
end_define

begin_include
include|#
directive|include
file|<iba/ib_types.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_qmap.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_map.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_ptr_vector.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_list.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_log.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_path.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_madw.h>
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
comment|/****h* OpenSM/Packet Randomizer * NAME *	Packet Randomizer * * DESCRIPTION *	The Packet Randomizer object encapsulates the information needed for *	randomly dropping packets for debug. * *	The Packet Randomizer object is not thread safe, thus callers must *	provide serialization. * * AUTHOR *	Yael Kalka, Mellanox * *********/
end_comment

begin_comment
comment|/****d* OpenSM: Pkt_Randomizer/osm_pkt_randomizer_t * NAME *	osm_pkt_randomizer_t * * DESCRIPTION *	Packet randomizer structure. This structure contains the various *  parameters needed by the packet randomizer. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_osm_pkt_randomizer
block|{
name|uint8_t
name|osm_pkt_drop_rate
decl_stmt|;
name|uint8_t
name|osm_pkt_num_unstable_links
decl_stmt|;
name|uint8_t
name|osm_pkt_unstable_link_rate
decl_stmt|;
name|osm_dr_path_t
modifier|*
name|fault_dr_paths
decl_stmt|;
name|uint8_t
name|num_paths_initialized
decl_stmt|;
block|}
name|osm_pkt_randomizer_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS * *  osm_pkt_drop_rate *     Used by the randomizer whether to drop a packet or not. *     Taken from the global variable OSM_PKT_DROP_RATE. If not given or *     if set to zero, the randomizer will not run. * *  osm_pkt_num_unstable_links *     The number of unstable links to be drawn. *     Taken from the global variable OSM_PKT_NUM_UNSTABLE_LINKS. default = 1. * *  osm_pkt_unstable_link_rate *     Used by the randomizer whether to add a packet to the unstable links *     list or not. Taken from the global variable OSM_PKT_UNSTABLE_LINK_RATE. *     default = 20. * *	fault_dr_path *		Array of osm_dr_path_t objects, that includes all the dr_paths *     that are marked as errored. * *  num_paths_initialized *     Describes the number of paths from the fault_dr_paths array that *     have already been initialized. * * SEE ALSO *	Packet Randomizer object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Pkt_Randomizer/osm_pkt_randomizer_init * NAME *	osm_pkt_randomizer_init * * DESCRIPTION *	The osm_pkt_randomizer_init function initializes the Packet Randomizer object. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_pkt_randomizer_init
parameter_list|(
name|IN
name|OUT
name|osm_pkt_randomizer_t
modifier|*
modifier|*
name|pp_pkt_randomizer
parameter_list|,
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *  p_pkt_randomizer *     [in] Pointer to the Packet Randomizer object to be initialized. * *	p_log *		[in] Pointer to the log object. * * RETURN VALUE *	None * * NOTES * * SEE ALSO * *********/
end_comment

begin_comment
comment|/****f* OpenSM: Pkt_Randomizer/osm_pkt_randomizer_destroy * NAME *	osm_pkt_randomizer_destroy * * DESCRIPTION *	The osm_pkt_randomizer_destroy function destroys the Packet Randomizer object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_pkt_randomizer_destroy
parameter_list|(
name|IN
name|osm_pkt_randomizer_t
modifier|*
modifier|*
name|pp_pkt_randomizer
parameter_list|,
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *  p_pkt_randomizer *     [in] Pointer to the Packet Randomizer object to be destroyed. * *	p_log *		[in] Pointer to the log object. * * RETURN VALUE *	None * * NOTES * * SEE ALSO * *********/
end_comment

begin_comment
comment|/****f* OpenSM: Pkt_Randomizer/osm_pkt_randomizer_madw_drop * NAME *	osm_pkt_randomizer_madw_drop * * DESCRIPTION *	The osm_pkt_randomizer_madw_drop is base function of the packet *  randomizer. *  It decides according to different random criteria whether or not *  the packet received should be dropped (according to its dr_path). *  This function is relevant both for mads sent by the SM and mads *  received by the SM. *  It returns TRUE if the mad should be dropped, and FALSE otherwise. * * SYNOPSIS */
end_comment

begin_function_decl
name|boolean_t
name|osm_pkt_randomizer_mad_drop
parameter_list|(
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
name|osm_pkt_randomizer_t
modifier|*
name|p_pkt_randomizer
parameter_list|,
name|IN
specifier|const
name|ib_mad_t
modifier|*
name|p_mad
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *  p_subn *     [in] Pointer to the Subnet object for this subnet. * *	p_log *		[in] Pointer to the log object. * *  p_mad *     [in] Pointer to the ib_mad_t mad to be checked. * * RETURN VALUE *	TRUE if the mad should be dropped. FALSE otherwise. * * NOTES * * SEE ALSO * *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_PKT_RANDOMIZER_H */
end_comment

end_unit

