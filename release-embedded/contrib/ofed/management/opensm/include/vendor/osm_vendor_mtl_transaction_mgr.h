begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Definition of interface for the MTL Vendor  *	   This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_TRANSACTION_MGR_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_TRANSACTION_MGR_H_
end_define

begin_comment
comment|/*      #include<vapi_types.h>      #include<evapi.h>    */
end_comment

begin_include
include|#
directive|include
file|<iba/ib_types.h>
end_include

begin_include
include|#
directive|include
file|<iba/ib_al.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_qlist.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_qmap.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_timer.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_thread.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_types_osd.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_spinlock.h>
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
file|<opensm/osm_madw.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|OSM_VENDOR_INTF_MTL
end_ifdef

begin_include
include|#
directive|include
file|<ib_mgt.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_mtl_bind.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
comment|/****s* OpenSM: Transaction Manager/osm_madw_req_t * NAME *  osm_madw_req_t * * DESCRIPTION *  The structure defining each object in the transaction_mgr. *  For every request mad sent, we will save such an object for it. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_osm_madw_req
block|{
name|cl_list_item_t
name|list_item
decl_stmt|;
name|cl_map_item_t
name|map_item
decl_stmt|;
name|osm_madw_t
modifier|*
name|p_madw
decl_stmt|;
name|uint64_t
name|waking_time
decl_stmt|;
name|uint8_t
name|retry_cnt
decl_stmt|;
name|osm_bind_handle_t
modifier|*
name|p_bind
decl_stmt|;
block|}
name|osm_madw_req_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *  list_item *     List item for qlist linkage. Must be first element!! * *  map_item *     Map item for qmap linkage. * *  p_madw *     pointer to mad wrapper that is expecting to get a response. * *  waking_time *     Time stamp (in microseconds) when the p_madw needs to wake up. *     This value is *      cl_get_time_stamp() + timeout  during the sending of the mad. *      where timeout should be given in microseconds. * *  retry_cnt *     The number of outstanding retries to be called. *********/
end_comment

begin_comment
comment|/****s* OpenSM: Transaction Manager/osm_transaction_mgr_t * NAME *  osm_transaction_mgr_t * * DESCRIPTION *  This structure defines the transaction manager. *  It holds a qlist and a qmap, a lock on the transaction manager, and *  a timer used for the list. *  The manager is responsible for keeping track of every request mad that was *  sent. It is used for finding mads according to their transaction id, and for *  acting as an event wheel - reporting as error each packet was supposed to get *  a response and didn't get one by the timeout time expected. * *  Both the list and the map hold the osm_madw_req_t objects - one for every madw. * *  Managing of the list: *  The timer wakes on the timeout of the first madw. If the waking_time is greater than *  the current time - then the mad received a response. If not - the mad didn't get *  its response. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_osm_transaction_mgr
block|{
name|cl_qmap_t
modifier|*
name|madw_by_tid_map_p
decl_stmt|;
name|cl_qlist_t
modifier|*
name|madw_reqs_list_p
decl_stmt|;
name|cl_spinlock_t
name|transaction_mgr_lock
decl_stmt|;
name|cl_timer_t
name|madw_list_timer
decl_stmt|;
block|}
name|osm_transaction_mgr_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *  madw_by_tid_map_p *     A qmap with key = transaction id. and value of osm_madw_req_t. * *  madw_reqs_list_p *     A qlist of all the madw with their waking time. * *  transaction_mgr_lock *     Lock used on the transaction manager - make sure changes on it are serial. * *  madw_list_timer *     Timer on the list. *********/
end_comment

begin_comment
comment|/****f* OpenSM: Transaction Manager/osm_transaction_mgr_init * NAME *	osm_transaction_mgr_init * * DESCRIPTION *	Initialize the transaction manager. *  Will update the p_transaction_mgr in the vendor object with *  the new Transaction Manager created.* * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_transaction_mgr_init
parameter_list|(
name|IN
name|osm_vendor_t
modifier|*
specifier|const
name|p_vend
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_vend *		[in] Pointer to a Osm Vendor object. * *********/
end_comment

begin_comment
comment|/****f* OpenSM: Transaction Manager/osm_transaction_mgr_destroy * NAME *	osm_transaction_mgr_destroy * * DESCRIPTION *	Destroy the transaction manager. *  Will de-allocate all memory allocated by the Transaction *  Manager up to now. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_transaction_mgr_destroy
parameter_list|(
name|IN
name|osm_vendor_t
modifier|*
specifier|const
name|p_vend
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_vend *		[in] Pointer to a Osm Vendor object. * *********/
end_comment

begin_comment
comment|/****f* OpenSM: Transaction Manager/osm_transaction_mgr_insert_madw * NAME *	osm_transaction_mgr_insert_madw * * DESCRIPTION *	Insert a new madw to the manager. The madw is added with a waking_time, *  Which is equal to the current_time + timeout. This is the maximum time *  that the madw can leave without being handled (e.g - get a response). *  If there are no madw saved in the manager - start the timer for vendor *  timeout period. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_transaction_mgr_insert_madw
parameter_list|(
name|IN
name|osm_bind_handle_t
modifier|*
name|p_bind
parameter_list|,
name|IN
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_vend *		[in] Pointer to a mtl bind object. * *  p_madw *     [in] Pointer to the Mad Wrapper to be added. * *********/
end_comment

begin_comment
comment|/****f* OpenSM: Transaction Manager/osm_transaction_mgr_erase_madw * NAME *	osm_transaction_mgr_erase_madw * * DESCRIPTION *	Erase a madw object from the manager. *  The removal is done using the transaction id of the mad - using *  it the madw_p is allocated (in the qmap) and removed from the *  qmap and qlist. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_transaction_mgr_erase_madw
parameter_list|(
name|IN
name|osm_vendor_t
modifier|*
specifier|const
name|p_vend
parameter_list|,
name|IN
name|ib_mad_t
modifier|*
name|p_mad
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_vend *		[in] Pointer to a Osm Vendor object. * *  p_mad *      [in] Pointer to the Mad to be removed. * *********/
end_comment

begin_comment
comment|/****f* OpenSM: Transaction Manager/osm_transaction_mgr_get_madw_for_tid * NAME *	osm_transaction_mgr_get_madw_for_tid * * DESCRIPTION *	Return the mad wrapper, given the p_mad (and in it the transaction id) * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_transaction_mgr_get_madw_for_tid
parameter_list|(
name|IN
name|osm_vendor_t
modifier|*
specifier|const
name|p_vend
parameter_list|,
name|IN
name|ib_mad_t
modifier|*
specifier|const
name|p_mad
parameter_list|,
name|OUT
name|osm_madw_t
modifier|*
modifier|*
name|req_madw_p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_vend *		[in] Pointer to a Osm Vendor object. * *  p_mad *      [in] Pointer to the Mad to be located. * * req_madw_p *      [out] Pointer to the mad Wrapper to be found. * *********/
end_comment

begin_comment
comment|/****f* OpenSM: Transaction Manager/osm_transaction_mgr_callback * NAME *	osm_transaction_mgr_callback * * DESCRIPTION *	This callback is called on timeout of the timer. *  It checks the time of the head madw in the qlist, and compares it to *  the current time. *  Will send an error callback if the time of the madw is less than the *  current time - this means that the madw wasn't removed in the timeout *  it was supposed to be handled. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_transaction_mgr_callback
parameter_list|(
name|IN
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	context *		[in] void* context * *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_TRANSACTION_MGR_H_ */
end_comment

end_unit

