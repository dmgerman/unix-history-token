begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *	Declaration of event abstraction.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CL_EVENT_H_
end_ifndef

begin_define
define|#
directive|define
name|_CL_EVENT_H_
end_define

begin_comment
comment|/* Indicates that waiting on an event should never timeout */
end_comment

begin_define
define|#
directive|define
name|EVENT_NO_TIMEOUT
value|0xFFFFFFFF
end_define

begin_include
include|#
directive|include
file|<complib/cl_event_osd.h>
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
comment|/****h* Component Library/Event * NAME *	Event * * DESCRIPTION *	The Event provides the ability to suspend and wakeup a thread. * *	The event functions operates on a cl_event_t structure which should be *	treated as opaque and should be manipulated only through the provided *	functions. * * SEE ALSO *	Structures: *		cl_event_t * *	Initialization/Destruction: *		cl_event_construct, cl_event_init, cl_event_destroy * *	Manipulation: *		cl_event_signal, cl_event_reset, cl_event_wait_on *********/
comment|/****f* Component Library: Event/cl_event_construct * NAME *	cl_event_construct * * DESCRIPTION *	The cl_event_construct function constructs an event. * * SYNOPSIS */
name|void
name|cl_event_construct
parameter_list|(
name|IN
name|cl_event_t
modifier|*
specifier|const
name|p_event
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_event *		[in] Pointer to an cl_event_t structure to construct. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Allows calling cl_event_destroy without first calling cl_event_init. * *	Calling cl_event_construct is a prerequisite to calling any other event *	function except cl_event_init. * * SEE ALSO *	Event, cl_event_init, cl_event_destroy *********/
end_comment

begin_comment
comment|/****f* Component Library: Event/cl_event_init * NAME *	cl_event_init * * DESCRIPTION *	The cl_event_init function initializes an event for use. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_event_init
parameter_list|(
name|IN
name|cl_event_t
modifier|*
specifier|const
name|p_event
parameter_list|,
name|IN
specifier|const
name|boolean_t
name|manual_reset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_event *		[in] Pointer to an cl_event_t structure to initialize. * *	manual_reset *		[in] If FALSE, indicates that the event resets itself after releasing *		a single waiter.  If TRUE, the event remains in the signalled state *		until explicitly reset by a call to cl_event_reset. * * RETURN VALUES *	CL_SUCCESS if event initialization succeeded. * *	CL_ERROR otherwise. * * NOTES *	Allows calling event manipulation functions, such as cl_event_signal, *	cl_event_reset, and cl_event_wait_on. * *	The event is initially in a reset state. * * SEE ALSO *	Event, cl_event_construct, cl_event_destroy, cl_event_signal, *	cl_event_reset, cl_event_wait_on *********/
end_comment

begin_comment
comment|/****f* Component Library: Event/cl_event_destroy * NAME *	cl_event_destroy * * DESCRIPTION *	The cl_event_destroy function performs any necessary cleanup of an event. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_event_destroy
parameter_list|(
name|IN
name|cl_event_t
modifier|*
specifier|const
name|p_event
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_event *		[in] Pointer to an cl_event_t structure to destroy. * * RETURN VALUE *	This function does not return a value. * * NOTES *	This function should only be called after a call to cl_event_construct *	or cl_event_init. * * SEE ALSO *	Event, cl_event_construct, cl_event_init *********/
end_comment

begin_comment
comment|/****f* Component Library: Event/cl_event_signal * NAME *	cl_event_signal * * DESCRIPTION *	The cl_event_signal function sets an event to the signalled state and *	releases at most one waiting thread. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_event_signal
parameter_list|(
name|IN
name|cl_event_t
modifier|*
specifier|const
name|p_event
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_event *		[in] Pointer to an cl_event_t structure to set. * * RETURN VALUES *	CL_SUCCESS if the event was successfully signalled. * *	CL_ERROR otherwise. * * NOTES *	For auto-reset events, the event is reset automatically once a wait *	operation is satisfied. * *	Triggering the event multiple times does not guarantee that the same *	number of wait operations are satisfied. This is because events are *	either in a signalled on non-signalled state, and triggering an event *	that is already in the signalled state has no effect. * * SEE ALSO *	Event, cl_event_reset, cl_event_wait_on *********/
end_comment

begin_comment
comment|/****f* Component Library: Event/cl_event_reset * NAME *	cl_event_reset * * DESCRIPTION *	The cl_event_reset function sets an event to the non-signalled state. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_event_reset
parameter_list|(
name|IN
name|cl_event_t
modifier|*
specifier|const
name|p_event
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_event *		[in] Pointer to an cl_event_t structure to reset. * * RETURN VALUES *	CL_SUCCESS if the event was successfully reset. * *	CL_ERROR otherwise. * * SEE ALSO *	Event, cl_event_signal, cl_event_wait_on *********/
end_comment

begin_comment
comment|/****f* Component Library: Event/cl_event_wait_on * NAME *	cl_event_wait_on * * DESCRIPTION *	The cl_event_wait_on function waits for the specified event to be *	triggered for a minimum amount of time. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_event_wait_on
parameter_list|(
name|IN
name|cl_event_t
modifier|*
specifier|const
name|p_event
parameter_list|,
name|IN
specifier|const
name|uint32_t
name|wait_us
parameter_list|,
name|IN
specifier|const
name|boolean_t
name|interruptible
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_event *		[in] Pointer to an cl_event_t structure on which to wait. * *	wait_us *		[in] Number of microseconds to wait. * *	interruptible *		[in] Indicates whether the wait operation can be interrupted *		by external signals. * * RETURN VALUES *	CL_SUCCESS if the wait operation succeeded in response to the event *	being set. * *	CL_TIMEOUT if the specified time period elapses. * *	CL_NOT_DONE if the wait was interrupted by an external signal. * *	CL_ERROR if the wait operation failed. * * NOTES *	If wait_us is set to EVENT_NO_TIMEOUT, the function will wait until the *	event is triggered and never timeout. * *	If the timeout value is zero, this function simply tests the state of *	the event. * *	If the event is already on the signalled state at the time of the call *	to cl_event_wait_on, the call completes immediately with CL_SUCCESS. * * SEE ALSO *	Event, cl_event_signal, cl_event_reset *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CL_EVENT_H_ */
end_comment

end_unit

