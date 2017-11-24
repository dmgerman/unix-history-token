begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2010 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_vl15_t.  *	This object represents a VL15 interface object.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_VL15INTF_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_VL15INTF_H_
end_define

begin_include
include|#
directive|include
file|<iba/ib_types.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_spinlock.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_event.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_thread.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_qlist.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_stats.h>
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

begin_include
include|#
directive|include
file|<opensm/osm_mad_pool.h>
end_include

begin_include
include|#
directive|include
file|<vendor/osm_vendor_api.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_subnet.h>
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
comment|/****h* OpenSM/VL15 * NAME *	VL15 * * DESCRIPTION *	The VL15 object encapsulates the information needed by the *	OpenSM to instantiate the VL15 interface.  The OpenSM allocates *	one VL15 object per subnet. * *	The VL15 object transmits MADs to the wire at a throttled rate, *	so as to not overload the VL15 buffering of subnet components. *	OpenSM modules may post VL15 MADs to the VL15 interface as fast *	as possible. * *	The VL15 object is thread safe. * *	This object should be treated as opaque and should *	be manipulated only through the provided functions. * * AUTHOR *	Steve King, Intel * *********/
end_comment

begin_comment
comment|/****d* OpenSM: SM/osm_vl15_state_t * NAME *	osm_vl15_state_t * * DESCRIPTION *	Enumerates the possible states of SM object. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_osm_vl15_state
block|{
name|OSM_VL15_STATE_INIT
init|=
literal|0
block|,
name|OSM_VL15_STATE_READY
block|}
name|osm_vl15_state_t
typedef|;
end_typedef

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****s* OpenSM: VL15/osm_vl15_t * NAME *	osm_vl15_t * * DESCRIPTION *	VL15 structure. * *	This object should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_vl15
block|{
name|osm_thread_state_t
name|thread_state
decl_stmt|;
name|osm_vl15_state_t
name|state
decl_stmt|;
name|uint32_t
name|max_wire_smps
decl_stmt|;
name|uint32_t
name|max_wire_smps2
decl_stmt|;
name|uint32_t
name|max_smps_timeout
decl_stmt|;
name|cl_event_t
name|signal
decl_stmt|;
name|cl_thread_t
name|poller
decl_stmt|;
name|cl_qlist_t
name|rfifo
decl_stmt|;
name|cl_qlist_t
name|ufifo
decl_stmt|;
name|cl_spinlock_t
name|lock
decl_stmt|;
name|osm_vendor_t
modifier|*
name|p_vend
decl_stmt|;
name|osm_log_t
modifier|*
name|p_log
decl_stmt|;
name|osm_stats_t
modifier|*
name|p_stats
decl_stmt|;
name|osm_subn_t
modifier|*
name|p_subn
decl_stmt|;
block|}
name|osm_vl15_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	thread_state *		Tracks the thread state of the poller thread. * *	state *		Tracks the state of the VL15 interface itself. * *	max_wire_smps *		Maximum number of VL15 MADs allowed on the wire at one time. * *	max_wire_smps2 *		Maximum number of timeout based SMPs allowed to be outstanding. * *	max_smps_timeout *		Wait time in usec for timeout based SMPs. * *	signal *		Event on which the poller sleeps. * *	rfifo *		First-in First-out queue for outbound VL15 MADs for which *		a response is expected, aka the "response fifo" * *	ufifo *		First-in First-out queue for outbound VL15 MADs for which *		no response is expected, aka the "unicast fifo". * *	poller *		Worker thread pool that services the fifo to transmit VL15 MADs * *	lock *		Spinlock guarding the FIFO. * *	p_vend *		Pointer to the vendor transport object. * *	p_log *		Pointer to the log object. * *	p_stats *		Pointer to the OpenSM statistics block. * *	p_subn *		Pointer to the OpenSM subnet object. * * SEE ALSO *	VL15 object *********/
end_comment

begin_comment
comment|/****f* OpenSM: VL15/osm_vl15_construct * NAME *	osm_vl15_construct * * DESCRIPTION *	This function constructs an VL15 object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_vl15_construct
parameter_list|(
name|IN
name|osm_vl15_t
modifier|*
name|p_vl15
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_vl15 *		[in] Pointer to a VL15 object to construct. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Allows calling osm_vl15_destroy. * *	Calling osm_vl15_construct is a prerequisite to calling any other *	method except osm_vl15_init. * * SEE ALSO *	VL15 object, osm_vl15_init, osm_vl15_destroy *********/
end_comment

begin_comment
comment|/****f* OpenSM: VL15/osm_vl15_destroy * NAME *	osm_vl15_destroy * * DESCRIPTION *	The osm_vl15_destroy function destroys the object, releasing *	all resources. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_vl15_destroy
parameter_list|(
name|IN
name|osm_vl15_t
modifier|*
name|p_vl15
parameter_list|,
name|IN
name|struct
name|osm_mad_pool
modifier|*
name|p_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_vl15 *		[in] Pointer to a VL15 object to destroy. * *  p_pool *     [in] The pointer to the mad pool to return outstanding mads to * * RETURN VALUE *	This function does not return a value. * * NOTES *	Performs any necessary cleanup of the specified VL15 object. *	Further operations should not be attempted on the destroyed object. *	This function should only be called after a call to osm_vl15_construct or *	osm_vl15_init. * * SEE ALSO *	VL15 object, osm_vl15_construct, osm_vl15_init *********/
end_comment

begin_comment
comment|/* 	Initialization. 	Rate specifies the minimum number of microseconds between transmissions 	on VL15. */
end_comment

begin_comment
comment|/****f* OpenSM: VL15/osm_vl15_init * NAME *	osm_vl15_init * * DESCRIPTION *	The osm_vl15_init function initializes a VL15 object for use. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_vl15_init
parameter_list|(
name|IN
name|osm_vl15_t
modifier|*
name|p_vl15
parameter_list|,
name|IN
name|osm_vendor_t
modifier|*
name|p_vend
parameter_list|,
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
name|osm_stats_t
modifier|*
name|p_stats
parameter_list|,
name|IN
name|osm_subn_t
modifier|*
name|p_subn
parameter_list|,
name|IN
name|int32_t
name|max_wire_smps
parameter_list|,
name|IN
name|int32_t
name|max_wire_smps2
parameter_list|,
name|IN
name|uint32_t
name|max_smps_timeout
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_vl15 *		[in] Pointer to an osm_vl15_t object to initialize. * *	p_vend *		[in] Pointer to the vendor transport object. * *	p_log *		[in] Pointer to the log object. * *	p_stats *		[in] Pointer to the OpenSM statistics block. * *	p_subn *		[in] Pointer to the OpenSM subnet object. * *	max_wire_smps *		[in] Maximum number of SMPs allowed on the wire at one time. * *	max_wire_smps2 *		[in] Maximum number of timeout based SMPs allowed to be *		     outstanding. * *	max_smps_timeout *		[in] Wait time in usec for timeout based SMPs. * * * RETURN VALUES *	IB_SUCCESS if the VL15 object was initialized successfully. * * NOTES *	Allows calling other VL15 methods. * * SEE ALSO *	VL15 object, osm_vl15_construct, osm_vl15_destroy *********/
end_comment

begin_comment
comment|/****f* OpenSM: VL15/osm_vl15_post * NAME *	osm_vl15_post * * DESCRIPTION *	Posts a MAD to the VL15 interface for transmission. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_vl15_post
parameter_list|(
name|IN
name|osm_vl15_t
modifier|*
name|p_vl15
parameter_list|,
name|IN
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_vl15 *		[in] Pointer to an osm_vl15_t object. * *	p_madw *		[in] Pointer to a MAD wrapper structure containing the MAD. * * RETURN VALUES *	This function does not return a value. * * NOTES *	The osm_vl15_construct or osm_vl15_init must be called before using *	this function. * * SEE ALSO *	VL15 object, osm_vl15_construct, osm_vl15_init *********/
end_comment

begin_comment
comment|/****f* OpenSM: VL15/osm_vl15_poll * NAME *	osm_vl15_poll * * DESCRIPTION *	Causes the VL15 Interface to consider sending another QP0 MAD. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_vl15_poll
parameter_list|(
name|IN
name|osm_vl15_t
modifier|*
name|p_vl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_vl15 *		[in] Pointer to an osm_vl15_t object. * * RETURN VALUES *	None. * * NOTES *	This function signals the VL15 that it may be possible to send *	a SMP.  This function checks three criteria before sending a SMP: *	1) The VL15 worker is IDLE *	2) There are no QP0 SMPs currently outstanding *	3) There is something on the VL15 FIFO to send * * SEE ALSO *	VL15 object, osm_vl15_construct, osm_vl15_init *********/
end_comment

begin_comment
comment|/****f* OpenSM: VL15/osm_vl15_shutdown * NAME *	osm_vl15_shutdown * * DESCRIPTION *	Cleanup all outstanding MADs on both fifo's. *  This is required to return all outstanding MAD resources. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_vl15_shutdown
parameter_list|(
name|IN
name|osm_vl15_t
modifier|*
name|p_vl
parameter_list|,
name|IN
name|osm_mad_pool_t
modifier|*
name|p_mad_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_vl15 *		[in] Pointer to an osm_vl15_t object. * *  p_mad_pool *     [in] The MAD pool owning the mads. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *	VL15 object, osm_vl15_construct, osm_vl15_init *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_VL15INTF_H_ */
end_comment

end_unit

