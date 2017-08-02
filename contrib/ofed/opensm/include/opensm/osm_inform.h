begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  * Copyright (c) 2013 Oracle and/or its affiliates. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_inform_rec_t.  *	This object represents an IBA Inform Record.  *	This object is part of the OpenSM family of objects.  *  * Author:  *    Eitan Zahavi, Mellanox  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_INFR_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_INFR_H_
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
file|<complib/cl_spinlock.h>
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
file|<opensm/osm_log.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_sa.h>
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
comment|/****h* OpenSM/Inform Record * NAME *	Inform Record * * DESCRIPTION *	The Inform record encapsulates the information needed by the *	SA to manage InformInfo registrations and sending Reports(Notice) *	when SM receives Traps for registered LIDs. * *	The inform records is not thread safe, thus callers must provide *	serialization. * *	This object should be treated as opaque and should be *	manipulated only through the provided functions. * * AUTHOR *    Eitan Zahavi, Mellanox * *********/
end_comment

begin_comment
comment|/****s* OpenSM: Inform Record/osm_infr_t * NAME *	osm_infr_t * * DESCRIPTION *	Inform Record structure. * *	The osm_infr_t object should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_infr
block|{
name|cl_list_item_t
name|list_item
decl_stmt|;
name|osm_bind_handle_t
name|h_bind
decl_stmt|;
name|osm_sa_t
modifier|*
name|sa
decl_stmt|;
name|osm_mad_addr_t
name|report_addr
decl_stmt|;
name|ib_inform_info_record_t
name|inform_record
decl_stmt|;
block|}
name|osm_infr_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	list_item *		List Item for qlist linkage.  Must be first element!! * *	h_bind *		A handle of lower level mad srvc * *	sa *		A pointer to osm_sa object * *	report_addr *		Report address * *	inform_record *		The Inform Info Record * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Inform Record/osm_infr_new * NAME *	osm_infr_new * * DESCRIPTION *	Allocates and initializes a Inform Record for use. * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_infr_t
modifier|*
name|osm_infr_new
parameter_list|(
name|IN
specifier|const
name|osm_infr_t
modifier|*
name|p_infr_rec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_inf_rec *		[in] Pointer to IB Inform Record * * RETURN VALUES *	pointer to osm_infr_t structure. * * NOTES *	Allows calling other inform record methods. * * SEE ALSO *	Inform Record, osm_infr_delete *********/
end_comment

begin_comment
comment|/****f* OpenSM: Inform Record/osm_infr_delete * NAME *	osm_infr_delete * * DESCRIPTION *	Destroys and deallocates the osm_infr_t structure. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_infr_delete
parameter_list|(
name|IN
name|osm_infr_t
modifier|*
name|p_infr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_infr *		[in] Pointer to osm_infr_t structure * * SEE ALSO *	Inform Record, osm_infr_new *********/
end_comment

begin_comment
comment|/****f* OpenSM: Inform Record/osm_infr_get_by_rec * NAME *	osm_infr_get_by_rec * * DESCRIPTION *	Find a matching osm_infr_t in the subnet DB by inform_info_record * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_infr_t
modifier|*
name|osm_infr_get_by_rec
parameter_list|(
name|IN
name|osm_subn_t
specifier|const
modifier|*
name|p_subn
parameter_list|,
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
name|osm_infr_t
modifier|*
name|p_infr_rec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_subn *		[in] Pointer to the subnet object * *	p_log *		[in] Pointer to the log object * *	p_inf_rec *		[in] Pointer to an inform_info record * * RETURN *	The matching osm_infr_t * SEE ALSO *	Inform Record, osm_infr_new, osm_infr_delete *********/
end_comment

begin_function_decl
name|void
name|osm_infr_insert_to_db
parameter_list|(
name|IN
name|osm_subn_t
modifier|*
name|p_subn
parameter_list|,
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
name|osm_infr_t
modifier|*
name|p_infr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_infr_remove_from_db
parameter_list|(
name|IN
name|osm_subn_t
modifier|*
name|p_subn
parameter_list|,
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
name|osm_infr_t
modifier|*
name|p_infr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****f* OpenSM: Inform Record/osm_infr_remove_subscriptions * NAME *	osm_infr_remove_subscriptions * * DESCRIPTION *	Remove all event subscriptions of a port * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_infr_remove_subscriptions
parameter_list|(
name|IN
name|osm_subn_t
modifier|*
name|p_subn
parameter_list|,
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
name|ib_net64_t
name|port_guid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_subn *		[in] Pointer to the subnet object * *	p_log *		[in] Pointer to the log object * *	port_guid *		[in] PortGUID of the subscriber that should be removed * * RETURN *	CL_SUCCESS if port_guid had any subscriptions being removed *	CL_NOT_FOUND if port_guid did not have any active subscriptions * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Inform Record/osm_report_notice * NAME *	osm_report_notice * * DESCRIPTION * Once a Trap was received by the osm_trap_rcv, or a Trap sourced in * the SM was sent (Traps 64-67) this routine is called with a copy of * the notice data. * Given a notice attribute - compare and see if it matches the InformInfo * Element and if it does - call the Report(Notice) for the * target QP registered by the address stored in the InformInfo element * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_report_notice
parameter_list|(
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
name|osm_subn_t
modifier|*
name|p_subn
parameter_list|,
name|IN
name|ib_mad_notice_attr_t
modifier|*
name|p_ntc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_rcv *		[in] Pointer to the trap receiver * *	p_ntc *		[in] Pointer to a copy of the incoming trap notice attribute. * * RETURN *	IB_SUCCESS on good completion * * SEE ALSO *	Inform Record, osm_trap_rcv *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_INFR_H_ */
end_comment

end_unit

