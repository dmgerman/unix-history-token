begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_lid_mgr_t.  *	This object represents the LID Manager object.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_LID_MGR_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_LID_MGR_H_
end_define

begin_include
include|#
directive|include
file|<complib/cl_passivelock.h>
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
file|<opensm/osm_subnet.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_db.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_log.h>
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

begin_define
define|#
directive|define
name|OSM_LID_MGR_LIST_SIZE_MIN
value|256
end_define

begin_comment
comment|/****h* OpenSM/LID Manager * NAME *	LID Manager * * DESCRIPTION *	The LID Manager object encapsulates the information *	needed to control LID assignments on the subnet. * *	The LID Manager object is thread safe. * *	This object should be treated as opaque and should be *	manipulated only through the provided functions. * * AUTHOR *	Steve King, Intel * *********/
end_comment

begin_struct_decl
struct_decl|struct
name|osm_sm
struct_decl|;
end_struct_decl

begin_comment
comment|/****s* OpenSM: LID Manager/osm_lid_mgr_t * NAME *	osm_lid_mgr_t * * DESCRIPTION *	LID Manager structure. * *	This object should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_lid_mgr
block|{
name|struct
name|osm_sm
modifier|*
name|sm
decl_stmt|;
name|osm_subn_t
modifier|*
name|p_subn
decl_stmt|;
name|osm_db_t
modifier|*
name|p_db
decl_stmt|;
name|osm_log_t
modifier|*
name|p_log
decl_stmt|;
name|cl_plock_t
modifier|*
name|p_lock
decl_stmt|;
name|osm_db_domain_t
modifier|*
name|p_g2l
decl_stmt|;
name|cl_qlist_t
name|free_ranges
decl_stmt|;
name|boolean_t
name|dirty
decl_stmt|;
name|uint8_t
name|used_lids
index|[
name|IB_LID_UCAST_END_HO
operator|+
literal|1
index|]
decl_stmt|;
block|}
name|osm_lid_mgr_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	sm *		Pointer to the SM object. * *	p_subn *		Pointer to the Subnet object for this subnet. * *	p_db *		Pointer to the database (persistency) object * *	p_log *		Pointer to the log object. * *	p_lock *		Pointer to the serializing lock. * *	p_g2l *		Pointer to the database domain storing guid to lid mapping. * *	free_ranges *		A list of available free lid ranges. The list is initialized *		by the code that initializes the lid assignment and is consumed *		by the procedure that finds a free range. It holds elements of *		type osm_lid_mgr_range_t * *	dirty *		 Indicates that lid table was updated * *	used_lids *		 An array of used lids. keeps track of *		 existing and non existing mapping of guid->lid * * SEE ALSO *	LID Manager object *********/
end_comment

begin_comment
comment|/****f* OpenSM: LID Manager/osm_lid_mgr_construct * NAME *	osm_lid_mgr_construct * * DESCRIPTION *	This function constructs a LID Manager object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_lid_mgr_construct
parameter_list|(
name|IN
name|osm_lid_mgr_t
modifier|*
name|p_mgr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_mgr *		[in] Pointer to a LID Manager object to construct. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Allows osm_lid_mgr_destroy * *	Calling osm_lid_mgr_construct is a prerequisite to calling any other *	method except osm_lid_mgr_init. * * SEE ALSO *	LID Manager object, osm_lid_mgr_init, *	osm_lid_mgr_destroy *********/
end_comment

begin_comment
comment|/****f* OpenSM: LID Manager/osm_lid_mgr_destroy * NAME *	osm_lid_mgr_destroy * * DESCRIPTION *	The osm_lid_mgr_destroy function destroys the object, releasing *	all resources. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_lid_mgr_destroy
parameter_list|(
name|IN
name|osm_lid_mgr_t
modifier|*
name|p_mgr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_mgr *		[in] Pointer to the object to destroy. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Performs any necessary cleanup of the specified *	LID Manager object. *	Further operations should not be attempted on the destroyed object. *	This function should only be called after a call to *	osm_lid_mgr_construct or osm_lid_mgr_init. * * SEE ALSO *	LID Manager object, osm_lid_mgr_construct, *	osm_lid_mgr_init *********/
end_comment

begin_comment
comment|/****f* OpenSM: LID Manager/osm_lid_mgr_init * NAME *	osm_lid_mgr_init * * DESCRIPTION *	The osm_lid_mgr_init function initializes a *	LID Manager object for use. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_lid_mgr_init
parameter_list|(
name|IN
name|osm_lid_mgr_t
modifier|*
name|p_mgr
parameter_list|,
name|IN
name|struct
name|osm_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_mgr *		[in] Pointer to an osm_lid_mgr_t object to initialize. * *	sm *		[in] Pointer to the SM object for this subnet. * * RETURN VALUES *	CL_SUCCESS if the LID Manager object was initialized *	successfully. * * NOTES *	Allows calling other LID Manager methods. * * SEE ALSO *	LID Manager object, osm_lid_mgr_construct, *	osm_lid_mgr_destroy *********/
end_comment

begin_comment
comment|/****f* OpenSM: LID Manager/osm_lid_mgr_process_sm * NAME *	osm_lid_mgr_process_sm * * DESCRIPTION *	Configures the SM's port with its designated LID values. * * SYNOPSIS */
end_comment

begin_function_decl
name|int
name|osm_lid_mgr_process_sm
parameter_list|(
name|IN
name|osm_lid_mgr_t
modifier|*
name|p_mgr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_mgr *		[in] Pointer to an osm_lid_mgr_t object. * * RETURN VALUES *	Returns 0 on success and non-zero value otherwise. * * NOTES * * SEE ALSO *	LID Manager *********/
end_comment

begin_comment
comment|/****f* OpenSM: LID Manager/osm_lid_mgr_process_subnet * NAME *	osm_lid_mgr_process_subnet * * DESCRIPTION *	Configures subnet ports (except the SM port itself) with their *	designated LID values. * * SYNOPSIS */
end_comment

begin_function_decl
name|int
name|osm_lid_mgr_process_subnet
parameter_list|(
name|IN
name|osm_lid_mgr_t
modifier|*
name|p_mgr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_mgr *		[in] Pointer to an osm_lid_mgr_t object. * * RETURN VALUES *	Returns 0 on success and non-zero value otherwise. * * NOTES * * SEE ALSO *	LID Manager *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_LID_MGR_H_ */
end_comment

end_unit

