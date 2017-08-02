begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *	Declaration of event wheel abstraction.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CL_EVENT_WHEEL_H_
end_ifndef

begin_define
define|#
directive|define
name|_CL_EVENT_WHEEL_H_
end_define

begin_include
include|#
directive|include
file|<complib/cl_atomic.h>
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
file|<complib/cl_spinlock.h>
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
comment|/****h* Component Library/Event_Wheel * NAME *	Event_Wheel * * DESCRIPTION *	The Event_Wheel provides a facility for registering delayed events *  and getting called once they timeout. * *	The Event_Wheel functions operate on a cl_event_wheel_t structure *  which should be treated as opaque and should be manipulated *  only through the provided functions. * * SEE ALSO *	Structures: *		cl_event_wheel_t * *	Initialization/Destruction: *		cl_event_wheel_construct, cl_event_wheel_init, cl_event_wheel_destroy * *	Manipulation: *		cl_event_wheel_reg, cl_event_wheel_unreg * *********/
end_comment

begin_comment
comment|/****f* Component Library: Event_Wheel/cl_pfn_event_aged_cb_t * NAME *	cl_pfn_event_aged_cb_t * * DESCRIPTION *	This typedef defines the prototype for client functions invoked *  by the Event_Wheel.  The Event_Wheel calls the corresponding *  client function when the specific item has aged. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|uint64_t
function_decl|(
modifier|*
name|cl_pfn_event_aged_cb_t
function_decl|)
parameter_list|(
name|IN
name|uint64_t
name|key
parameter_list|,
name|IN
name|uint32_t
name|num_regs
parameter_list|,
name|IN
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* * PARAMETERS *	key *		[in] The key used for registering the item in the call to *		cl_event_wheel_reg. * *	num_regs *		[in] The number of times this event was registered (pushed in time). * *	context *		[in] Client specific context specified in a call to *		cl_event_wheel_reg * * RETURN VALUE *	This function returns the abosolute time the event should fire in [usec]. *  If lower then current time means the event should be unregistered *  immediatly. * * NOTES *	This typedef provides a function prototype reference for *  the function provided by Event_Wheel clients as a parameter *  to the cl_event_wheel_reg function. * * SEE ALSO *	Event_Wheel, cl_event_wheel_reg *********/
end_comment

begin_comment
comment|/****s* Component Library: Event_Wheel/cl_event_wheel_t * NAME *	cl_event_wheel_t * * DESCRIPTION *	Event_Wheel structure. * *	The Event_Wheel is thread safe. * *	The cl_event_wheel_t structure should be treated as opaque and should *  be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_cl_event_wheel
block|{
name|cl_spinlock_t
name|lock
decl_stmt|;
name|cl_spinlock_t
modifier|*
name|p_external_lock
decl_stmt|;
name|cl_qmap_t
name|events_map
decl_stmt|;
name|boolean_t
name|closing
decl_stmt|;
name|cl_qlist_t
name|events_wheel
decl_stmt|;
name|cl_timer_t
name|timer
decl_stmt|;
block|}
name|cl_event_wheel_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	lock *		Spinlock to guard internal structures. * *	p_external_lock *		Reference to external spinlock to guard internal structures *		if the event wheel is part of a larger object protected by its own lock * *	events_map *		A Map holding all registered event items by their key. * *	closing *		A flag indicating the event wheel is closing. This means that *		callbacks that are called when closing == TRUE should just be ignored. * *	events_wheel *		A list of the events sorted by expiration time. * *	timer *		The timer scheduling event time propagation. * * SEE ALSO *	Event_Wheel *********/
end_comment

begin_comment
comment|/****s* Component Library: Event_Wheel/cl_event_wheel_reg_info_t * NAME *	cl_event_wheel_reg_info_t * * DESCRIPTION *	Defines the event_wheel registration object structure. * *	The cl_event_wheel_reg_info_t structure is for internal use by the *	Event_Wheel only. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_cl_event_wheel_reg_info
block|{
name|cl_map_item_t
name|map_item
decl_stmt|;
name|cl_list_item_t
name|list_item
decl_stmt|;
name|uint64_t
name|key
decl_stmt|;
name|cl_pfn_event_aged_cb_t
name|pfn_aged_callback
decl_stmt|;
name|uint64_t
name|aging_time
decl_stmt|;
name|uint32_t
name|num_regs
decl_stmt|;
name|void
modifier|*
name|context
decl_stmt|;
name|cl_event_wheel_t
modifier|*
name|p_event_wheel
decl_stmt|;
block|}
name|cl_event_wheel_reg_info_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	map_item *		The map item of this event * *	list_item *		The sorted by aging time list item * *	key *		The key by which one can find the event * *	pfn_aged_callback *		The clients Event-Aged callback * *	aging_time *		The delta time [msec] for which the event should age. * *	num_regs *		The number of times the same event (key) was registered * *	context *		Client's context for event-aged callback. * *	p_event_wheel *		Pointer to this event wheel object * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* Component Library: Event_Wheel/cl_event_wheel_construct * NAME *	cl_event_wheel_construct * * DESCRIPTION *	This function constructs a Event_Wheel object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_event_wheel_construct
parameter_list|(
name|IN
name|cl_event_wheel_t
modifier|*
specifier|const
name|p_event_wheel
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_event_wheel *		[in] Pointer to a Event_Wheel. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Allows calling cl_event_wheel_init and cl_event_wheel_destroy. * * SEE ALSO *	Event_Wheel, cl_event_wheel_init, cl_event_wheel_destroy *********/
end_comment

begin_comment
comment|/****f* Component Library: Event_Wheel/cl_event_wheel_init * NAME *	cl_event_wheel_init * * DESCRIPTION *	This function initializes a Event_Wheel object. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_event_wheel_init
parameter_list|(
name|IN
name|cl_event_wheel_t
modifier|*
specifier|const
name|p_event_wheel
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_event_wheel *		[in] Pointer to a Event_Wheel. * * RETURN VALUE *	CL_SUCCESS if the operation is successful. * * SEE ALSO *	Event_Wheel, cl_event_wheel_destoy, cl_event_wheel_reg, cl_event_wheel_unreg * *********/
end_comment

begin_comment
comment|/****f* Component Library: Event_Wheel/cl_event_wheel_init * NAME *	cl_event_wheel_init * * DESCRIPTION *	This function initializes a Event_Wheel object. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_event_wheel_init_ex
parameter_list|(
name|IN
name|cl_event_wheel_t
modifier|*
specifier|const
name|p_event_wheel
parameter_list|,
name|IN
name|cl_spinlock_t
modifier|*
name|p_external_lock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_event_wheel *		[in] Pointer to a Event_Wheel. * *	p_external_lock *		[in] Reference to external spinlock to guard internal structures *		if the event wheel is part of a larger object protected by its own lock * * RETURN VALUE *	CL_SUCCESS if the operation is successful. * * SEE ALSO *	Event_Wheel, cl_event_wheel_destoy, cl_event_wheel_reg, cl_event_wheel_unreg * *********/
end_comment

begin_comment
comment|/****f* Component Library: Event_Wheel/cl_event_wheel_destroy * NAME *	cl_event_wheel_destroy * * DESCRIPTION *	This function destroys a Event_Wheel object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_event_wheel_destroy
parameter_list|(
name|IN
name|cl_event_wheel_t
modifier|*
specifier|const
name|p_event_wheel
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_event_wheel *		[in] Pointer to a Event_Wheel. * * RETURN VALUE *	This function does not return a value. * * NOTES *	This function does not returns until all client callback functions *  been successfully finished. * * SEE ALSO *	Event_Wheel, cl_event_wheel_construct, cl_event_wheel_init *********/
end_comment

begin_comment
comment|/****f* Component Library: Event_Wheel/cl_event_wheel_dump * NAME *	cl_event_wheel_dump * * DESCRIPTION *	This function dumps the details of an Event_Whell object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_event_wheel_dump
parameter_list|(
name|IN
name|cl_event_wheel_t
modifier|*
specifier|const
name|p_event_wheel
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_event_wheel *		[in] Pointer to a Event_Wheel. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Note that this function should be called inside a lock of the event wheel! *  It doesn't aquire the lock by itself. * * SEE ALSO *	Event_Wheel, cl_event_wheel_construct, cl_event_wheel_init *********/
end_comment

begin_comment
comment|/****f* Component Library: Event_Wheel/cl_event_wheel_reg * NAME *	cl_event_wheel_reg * * DESCRIPTION *	This function registers a client with a Event_Wheel object. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_event_wheel_reg
parameter_list|(
name|IN
name|cl_event_wheel_t
modifier|*
specifier|const
name|p_event_wheel
parameter_list|,
name|IN
specifier|const
name|uint64_t
name|key
parameter_list|,
name|IN
specifier|const
name|uint64_t
name|aging_time_usec
parameter_list|,
name|IN
name|cl_pfn_event_aged_cb_t
name|pfn_callback
parameter_list|,
name|IN
name|void
modifier|*
specifier|const
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_event_wheel *		[in] Pointer to a Event_Wheel. * *	key *		[in] The specifc Key by which events are registered. * *	aging_time_usec *		[in] The absolute time this event should age in usec * *	pfn_callback *		[in] Event Aging callback.  The Event_Wheel calls this *		function after the time the event has registed for has come. * *	context *		[in] Client context value passed to the cl_pfn_event_aged_cb_t *		function. * * RETURN VALUE *	On success a Event_Wheel CL_SUCCESS or CL_ERROR otherwise. * * SEE ALSO *	Event_Wheel, cl_event_wheel_unreg *********/
end_comment

begin_comment
comment|/****f* Component Library: Event_Wheel/cl_event_wheel_unreg * NAME *	cl_event_wheel_unreg * * DESCRIPTION *	This function unregisters a client event from a Event_Wheel. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_event_wheel_unreg
parameter_list|(
name|IN
name|cl_event_wheel_t
modifier|*
specifier|const
name|p_event_wheel
parameter_list|,
name|IN
name|uint64_t
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_event_wheel *		[in] Pointer to a Event_Wheel. * *	key *		[in] The key used for registering the event * * RETURN VALUE *	This function does not return a value. * * NOTES *	After the event has aged it is automatically removed from *  the event wheel. So it should only be invoked when the need arises *  to remove existing events before they age. * * SEE ALSO *	Event_Wheel, cl_event_wheel_reg *********/
end_comment

begin_comment
comment|/****f* Component Library: Event_Wheel/cl_event_wheel_num_regs * NAME *	cl_event_wheel_num_regs * * DESCRIPTION *	This function returns the number of times an event was registered. * * SYNOPSIS */
end_comment

begin_function_decl
name|uint32_t
name|cl_event_wheel_num_regs
parameter_list|(
name|IN
name|cl_event_wheel_t
modifier|*
specifier|const
name|p_event_wheel
parameter_list|,
name|IN
name|uint64_t
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_event_wheel *		[in] Pointer to a Event_Wheel. * *	key *		[in] The key used for registering the event * * RETURN VALUE *	The number of times the event was registered. *  0 if never registered or eventually aged. * * SEE ALSO *	Event_Wheel, cl_event_wheel_reg, cl_event_wheel_unreg *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(_CL_EVENT_WHEEL_H_) */
end_comment

end_unit

