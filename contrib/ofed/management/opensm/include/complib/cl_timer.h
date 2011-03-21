begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *	Declaration of timer abstraction.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CL_TIMER_H_
end_ifndef

begin_define
define|#
directive|define
name|_CL_TIMER_H_
end_define

begin_include
include|#
directive|include
file|<complib/cl_types.h>
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
comment|/****h* Component Library/Timer * NAME *	Timer * * DESCRIPTION *	The Timer provides the ability to schedule a function to be invoked at *	a given time in the future. * *	The timer callback function must not perform any blocking operations. * *	The timer functions operate on a cl_timer_t structure which should be *	treated as opaque and should be manipulated only through the provided *	functions. * * SEE ALSO *	Structures: *		cl_timer_t * *	Callbacks: *		cl_pfn_timer_callback_t * *	Initialization: *		cl_timer_construct, cl_timer_init, cl_timer_destroy * *	Manipulation: *		cl_timer_start, cl_timer_stop *********/
end_comment

begin_comment
comment|/****d* Component Library: Timer/cl_pfn_timer_callback_t * NAME *	cl_pfn_timer_callback_t * * DESCRIPTION *	The cl_pfn_timer_callback_t function type defines the prototype for *	functions used to notify users of a timer expiration. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|cl_pfn_timer_callback_t
function_decl|)
parameter_list|(
name|IN
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* * PARAMETERS *	context *		[in] Value specified in a previous call to cl_timer_init. * * RETURN VALUE *	This function does not return a value. * * NOTES *	This function type is provided as function prototype reference for the *	function provided by users as a parameter to the cl_timer_init function. * * SEE ALSO *	Timer, cl_timer_init *********/
end_comment

begin_comment
comment|/*  * This include file defines the timer structure, and depends on the timer  * callback definition.  */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_timer_osd.h>
end_include

begin_comment
comment|/****f* Component Library: Timer/cl_timer_construct * NAME *	cl_timer_construct * * DESCRIPTION *	The cl_timer_construct function initializes the state of a timer. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_timer_construct
parameter_list|(
name|IN
name|cl_timer_t
modifier|*
specifier|const
name|p_timer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_timer *		[in] Pointer to a cl_timer_t structure whose state to initialize. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Allows calling cl_timer_destroy without first calling cl_timer_init. * *	Calling cl_timer_construct is a prerequisite to calling any other *	timer function except cl_timer_init. * * SEE ALSO *	Timer, cl_timer_init, cl_timer_destroy *********/
end_comment

begin_comment
comment|/****f* Component Library: Timer/cl_timer_init * NAME *	cl_timer_init * * DESCRIPTION *	The cl_timer_init function initializes a timer for use. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_timer_init
parameter_list|(
name|IN
name|cl_timer_t
modifier|*
specifier|const
name|p_timer
parameter_list|,
name|IN
name|cl_pfn_timer_callback_t
name|pfn_callback
parameter_list|,
name|IN
specifier|const
name|void
modifier|*
specifier|const
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_timer *		[in] Pointer to a cl_timer_t structure to initialize. * *	pfn_callback *		[in] Address of a callback function to be invoked when a timer expires. *		See the cl_pfn_timer_callback_t function type definition for details *		about the callback function. * *	context *		[in] Value to pass to the callback function. * * RETURN VALUES *	CL_SUCCESS if the timer was successfully initialized. * *	CL_ERROR otherwise. * * NOTES *	Allows calling cl_timer_start and cl_timer_stop. * * SEE ALSO *	Timer, cl_timer_construct, cl_timer_destroy, cl_timer_start, *	cl_timer_stop, cl_pfn_timer_callback_t *********/
end_comment

begin_comment
comment|/****f* Component Library: Timer/cl_timer_destroy * NAME *	cl_timer_destroy * * DESCRIPTION *	The cl_timer_destroy function performs any necessary cleanup of a timer. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_timer_destroy
parameter_list|(
name|IN
name|cl_timer_t
modifier|*
specifier|const
name|p_timer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_timer *		[in] Pointer to a cl_timer_t structure to destroy. * * RETURN VALUE *	This function does not return a value. * * NOTES *	cl_timer_destroy cancels any pending callbacks. * *	This function should only be called after a call to cl_timer_construct *	or cl_timer_init. * * SEE ALSO *	Timer, cl_timer_construct, cl_timer_init *********/
end_comment

begin_comment
comment|/****f* Component Library: Timer/cl_timer_start * NAME *	cl_timer_start * * DESCRIPTION *	The cl_timer_start function sets a timer to expire after a given interval. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_timer_start
parameter_list|(
name|IN
name|cl_timer_t
modifier|*
specifier|const
name|p_timer
parameter_list|,
name|IN
specifier|const
name|uint32_t
name|time_ms
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_timer *		[in] Pointer to a cl_timer_t structure to schedule. * *	time_ms *		[in] Time, in milliseconds, before the timer should expire. * * RETURN VALUES *	CL_SUCCESS if the timer was successfully scheduled. * *	CL_ERROR otherwise. * * NOTES *	cl_timer_start implicitly stops the timer before being scheduled. * *	The interval specified by the time_ms parameter is a minimum interval. *	The timer is guaranteed to expire no sooner than the desired interval, but *	may take longer to expire. * * SEE ALSO *	Timer, cl_timer_stop, cl_timer_trim *********/
end_comment

begin_comment
comment|/****f* Component Library: Timer/cl_timer_stop * NAME *	cl_timer_stop * * DESCRIPTION *	The cl_timer_stop function stops a pending timer from expiring. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_timer_stop
parameter_list|(
name|IN
name|cl_timer_t
modifier|*
specifier|const
name|p_timer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_timer *		[in] Pointer to a cl_timer_t structure. * * RETURN VALUE *	This function does not return a value. * * SEE ALSO *	Timer, cl_timer_start, cl_timer_trim *********/
end_comment

begin_comment
comment|/****f* Component Library: Timer/cl_timer_trim * NAME *	cl_timer_trim * * DESCRIPTION *	The cl_timer_trim function pulls in the absolute expiration *	time of a timer if the current expiration time exceeds the specified *	interval. * *	sets a timer to expire after a given *	interval if that interval is less than the current timer expiration. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_timer_trim
parameter_list|(
name|IN
name|cl_timer_t
modifier|*
specifier|const
name|p_timer
parameter_list|,
name|IN
specifier|const
name|uint32_t
name|time_ms
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_timer *		[in] Pointer to a cl_timer_t structure to schedule. * *	time_ms *		[in] Maximum time, in milliseconds, before the timer should expire. * * RETURN VALUES *	CL_SUCCESS if the timer was successfully scheduled. * *	CL_ERROR otherwise. * * NOTES *	cl_timer_trim has no effect if the time interval is greater than the *	remaining time when the timer is set. * *	If the new interval time is less than the remaining time, cl_timer_trim *	implicitly stops the timer before resetting it. * *	If the timer is reset, it is guaranteed to expire no sooner than the *	new interval, but may take longer to expire. * * SEE ALSO *	Timer, cl_timer_start, cl_timer_stop *********/
end_comment

begin_comment
comment|/****f* Component Library: Time Stamp/cl_get_time_stamp * NAME *	cl_get_time_stamp * * DESCRIPTION *	The cl_get_time_stamp function returns the current time stamp in *	microseconds since the system was booted. * * SYNOPSIS */
end_comment

begin_function_decl
name|uint64_t
name|cl_get_time_stamp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * RETURN VALUE *	Time elapsed, in microseconds, since the system was booted. * * SEE ALSO *	Timer, cl_get_time_stamp_sec *********/
end_comment

begin_comment
comment|/****f* Component Library: Time Stamp/cl_get_time_stamp_sec * NAME *	cl_get_time_stamp_sec * * DESCRIPTION *	The cl_get_time_stamp_sec function returns the current time stamp in *	seconds since the system was booted. * * SYNOPSIS */
end_comment

begin_function_decl
name|uint32_t
name|cl_get_time_stamp_sec
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * RETURN VALUE *	Time elapsed, in seconds, since the system was booted. * * SEE ALSO *	Timer, cl_get_time_stamp *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CL_TIMER_H_ */
end_comment

end_unit

