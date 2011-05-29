begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of dispatcher abstraction.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CL_DISPATCHER_H_
end_ifndef

begin_define
define|#
directive|define
name|_CL_DISPATCHER_H_
end_define

begin_include
include|#
directive|include
file|<complib/cl_atomic.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_threadpool.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_qlist.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_qpool.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_spinlock.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_ptr_vector.h>
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
comment|/****h* Component Library/Dispatcher * NAME *	Dispatcher * * DESCRIPTION *	The Dispatcher provides a facility for message routing to *	asynchronous worker threads. * *	The Dispatcher functions operate on a cl_dispatcher_t structure *	which should be treated as opaque and should be manipulated *	only through the provided functions. * * SEE ALSO *	Structures: *		cl_dispatcher_t * *	Initialization/Destruction: *		cl_disp_construct, cl_disp_init, cl_disp_shutdown, cl_disp_destroy * *	Manipulation: *		cl_disp_post, cl_disp_reset, cl_disp_wait_on *********/
end_comment

begin_comment
comment|/****s* Component Library: Dispatcher/cl_disp_msgid_t * NAME *	cl_disp_msgid_t * * DESCRIPTION *	Defines the type of dispatcher messages. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|cl_disp_msgid_t
typedef|;
end_typedef

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****s* Component Library: Dispatcher/CL_DISP_MSGID_NONE * NAME *	CL_DISP_MSGID_NONE * * DESCRIPTION *	Defines a message value that means "no message". *	This value is used during registration by Dispatcher clients *	that do not wish to receive messages. * *	No Dispatcher message is allowed to have this value. * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|CL_DISP_MSGID_NONE
value|0xFFFFFFFF
end_define

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****s* Component Library: Dispatcher/CL_DISP_INVALID_HANDLE * NAME *	CL_DISP_INVALID_HANDLE * * DESCRIPTION *	Defines the value of an invalid Dispatcher registration handle. * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|CL_DISP_INVALID_HANDLE
value|((cl_disp_reg_handle_t)0)
end_define

begin_comment
comment|/*********/
end_comment

begin_comment
comment|/****f* Component Library: Dispatcher/cl_pfn_msgrcv_cb_t * NAME *	cl_pfn_msgrcv_cb_t * * DESCRIPTION *	This typedef defines the prototype for client functions invoked *	by the Dispatcher.  The Dispatcher calls the corresponding *	client function when delivering a message to the client. * *	The client function must be reentrant if the user creates a *	Dispatcher with more than one worker thread. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|cl_pfn_msgrcv_cb_t
function_decl|)
parameter_list|(
name|IN
name|void
modifier|*
name|context
parameter_list|,
name|IN
name|void
modifier|*
name|p_data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* * PARAMETERS *	context *		[in] Client specific context specified in a call to *		cl_disp_register * *	p_data *		[in] Pointer to the client specific data payload *		of this message. * * RETURN VALUE *	This function does not return a value. * * NOTES *	This typedef provides a function prototype reference for *	the function provided by Dispatcher clients as a parameter *	to the cl_disp_register function. * * SEE ALSO *	Dispatcher, cl_disp_register *********/
end_comment

begin_comment
comment|/****f* Component Library: Dispatcher/cl_pfn_msgdone_cb_t * NAME *	cl_pfn_msgdone_cb_t * * DESCRIPTION *	This typedef defines the prototype for client functions invoked *	by the Dispatcher.  The Dispatcher calls the corresponding *	client function after completing delivery of a message. * *	The client function must be reentrant if the user creates a *	Dispatcher with more than one worker thread. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|cl_pfn_msgdone_cb_t
function_decl|)
parameter_list|(
name|IN
name|void
modifier|*
name|context
parameter_list|,
name|IN
name|void
modifier|*
name|p_data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* * PARAMETERS *	context *		[in] Client specific context specified in a call to *		cl_disp_post * *	p_data *		[in] Pointer to the client specific data payload *		of this message. * * RETURN VALUE *	This function does not return a value. * * NOTES *	This typedef provides a function prototype reference for *	the function provided by Dispatcher clients as a parameter *	to the cl_disp_post function. * * SEE ALSO *	Dispatcher, cl_disp_post *********/
end_comment

begin_comment
comment|/****s* Component Library: Dispatcher/cl_dispatcher_t * NAME *	cl_dispatcher_t * * DESCRIPTION *	Dispatcher structure. * *	The Dispatcher is thread safe. * *	The cl_dispatcher_t structure should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_cl_dispatcher
block|{
name|cl_spinlock_t
name|lock
decl_stmt|;
name|cl_ptr_vector_t
name|reg_vec
decl_stmt|;
name|cl_qlist_t
name|reg_list
decl_stmt|;
name|cl_thread_pool_t
name|worker_threads
decl_stmt|;
name|cl_qlist_t
name|msg_fifo
decl_stmt|;
name|cl_qpool_t
name|msg_pool
decl_stmt|;
name|uint64_t
name|last_msg_queue_time_us
decl_stmt|;
block|}
name|cl_dispatcher_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	reg_vec *		Vector of registration info objects.  Indexed by message msg_id. * *	lock *		Spinlock to guard internal structures. * *	msg_fifo *		FIFO of messages being processed by the Dispatcher.  New *		messages are posted to the tail of the FIFO.  Worker threads *		pull messages from the front. * *	worker_threads *		Thread pool of worker threads to dispose of posted messages. * *	msg_pool *		Pool of message objects to be processed through the FIFO. * *	reg_count *		Count of the number of registrants. * *	state *		Indicates the state of the object. * *       last_msg_queue_time_us *               The time that the last message spent in the Q in usec * * SEE ALSO *	Dispatcher *********/
end_comment

begin_comment
comment|/****s* Component Library: Dispatcher/cl_disp_reg_info_t * NAME *	cl_disp_reg_info_t * * DESCRIPTION *	Defines the dispatcher registration object structure. * *	The cl_disp_reg_info_t structure is for internal use by the *	Dispatcher only. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_cl_disp_reg_info
block|{
name|cl_list_item_t
name|list_item
decl_stmt|;
name|cl_pfn_msgrcv_cb_t
name|pfn_rcv_callback
decl_stmt|;
specifier|const
name|void
modifier|*
name|context
decl_stmt|;
name|atomic32_t
name|ref_cnt
decl_stmt|;
name|cl_disp_msgid_t
name|msg_id
decl_stmt|;
name|cl_dispatcher_t
modifier|*
name|p_disp
decl_stmt|;
block|}
name|cl_disp_reg_info_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	pfn_rcv_callback *		Client's message receive callback. * *	context *		Client's context for message receive callback. * *	rcv_thread_count *		Number of threads currently in the receive callback. * *	msg_done_thread_count *		Number of threads currently in the message done callback. * *	state *		State of this registration object. *			DISP_REGSTATE_INIT: initialized and inactive *			DISP_REGSTATE_ACTIVE: in active use *			DISP_REGSTATE_UNREGPEND: unregistration is pending * *	msg_id *		Dispatcher message msg_id value for this registration object. * *	p_disp *		Pointer to parent Dispatcher. * * SEE ALSO *********/
end_comment

begin_comment
comment|/****s* Component Library: Dispatcher/cl_disp_msg_t * NAME *	cl_disp_msg_t * * DESCRIPTION *	Defines the dispatcher message structure. * *	The cl_disp_msg_t structure is for internal use by the *	Dispatcher only. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_cl_disp_msg
block|{
name|cl_pool_item_t
name|item
decl_stmt|;
specifier|const
name|void
modifier|*
name|p_data
decl_stmt|;
name|cl_disp_reg_info_t
modifier|*
name|p_src_reg
decl_stmt|;
name|cl_disp_reg_info_t
modifier|*
name|p_dest_reg
decl_stmt|;
name|cl_pfn_msgdone_cb_t
name|pfn_xmt_callback
decl_stmt|;
name|uint64_t
name|in_time
decl_stmt|;
specifier|const
name|void
modifier|*
name|context
decl_stmt|;
block|}
name|cl_disp_msg_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	item *		List& Pool linkage.  Must be first element in the structure!! * *	msg_id *		The message's numberic ID value. * *	p_data *		Pointer to the data payload for this message.  The payload *		is opaque to the Dispatcher. * *	p_reg_info *		Pointer to the registration info of the sender. * *	pfn_xmt_callback *		Client's message done callback. * *       in_time *               The absolute time the message was inserted into the queue * *	context *		Client's message done callback context. * * SEE ALSO *********/
end_comment

begin_comment
comment|/****s* Component Library: Dispatcher/cl_disp_reg_info_t * NAME *	cl_disp_reg_info_t * * DESCRIPTION *	Defines the Dispatcher registration handle.  This handle *	should be treated as opaque by the client. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
specifier|const
name|struct
name|_cl_disp_reg_info
modifier|*
name|cl_disp_reg_handle_t
typedef|;
end_typedef

begin_comment
comment|/**********/
end_comment

begin_comment
comment|/****f* Component Library: Dispatcher/cl_disp_construct * NAME *	cl_disp_construct * * DESCRIPTION *	This function constructs a Dispatcher object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_disp_construct
parameter_list|(
name|IN
name|cl_dispatcher_t
modifier|*
specifier|const
name|p_disp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_disp *		[in] Pointer to a Dispatcher. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Allows calling cl_disp_init and cl_disp_destroy. * * SEE ALSO *	Dispatcher, cl_disp_init, cl_disp_destroy *********/
end_comment

begin_comment
comment|/****f* Component Library: Dispatcher/cl_disp_init * NAME *	cl_disp_init * * DESCRIPTION *	This function initializes a Dispatcher object. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_disp_init
parameter_list|(
name|IN
name|cl_dispatcher_t
modifier|*
specifier|const
name|p_disp
parameter_list|,
name|IN
specifier|const
name|uint32_t
name|thread_count
parameter_list|,
name|IN
specifier|const
name|char
modifier|*
specifier|const
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_disp *		[in] Pointer to a Dispatcher. * *	thread_count *		[in] The number of worker threads to create in this Dispatcher. *		A value of 0 causes the Dispatcher to create one worker thread *		per CPU in the system.  When the Dispatcher is created with *		only one thread, the Dispatcher guarantees to deliver posted *		messages in order.  When the Dispatcher is created with more *		than one thread, messages may be delivered out of order. * *	name *		[in] Name to associate with the threads.  The name may be up to 16 *		characters, including a terminating null character.  All threads *		created in the Dispatcher have the same name. * * RETURN VALUE *	CL_SUCCESS if the operation is successful. * * SEE ALSO *	Dispatcher, cl_disp_destoy, cl_disp_register, cl_disp_unregister, *	cl_disp_post *********/
end_comment

begin_comment
comment|/****f* Component Library: Dispatcher/cl_disp_shutdown * NAME *	cl_disp_shutdown * * DESCRIPTION *	This function shutdown a Dispatcher object. So it unreg all messages and *  clears the fifo and waits for the threads to exit * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_disp_shutdown
parameter_list|(
name|IN
name|cl_dispatcher_t
modifier|*
specifier|const
name|p_disp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_disp *		[in] Pointer to a Dispatcher. * * RETURN VALUE *	This function does not return a value. * * NOTES *	This function does not returns until all worker threads *	have exited client callback functions and been successfully *	shutdowned. * * SEE ALSO *	Dispatcher, cl_disp_construct, cl_disp_init *********/
end_comment

begin_comment
comment|/****f* Component Library: Dispatcher/cl_disp_destroy * NAME *	cl_disp_destroy * * DESCRIPTION *	This function destroys a Dispatcher object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_disp_destroy
parameter_list|(
name|IN
name|cl_dispatcher_t
modifier|*
specifier|const
name|p_disp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_disp *		[in] Pointer to a Dispatcher. * * RETURN VALUE *	This function does not return a value. * * SEE ALSO *	Dispatcher, cl_disp_construct, cl_disp_init *********/
end_comment

begin_comment
comment|/****f* Component Library: Dispatcher/cl_disp_register * NAME *	cl_disp_register * * DESCRIPTION *	This function registers a client with a Dispatcher object. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_disp_reg_handle_t
name|cl_disp_register
parameter_list|(
name|IN
name|cl_dispatcher_t
modifier|*
specifier|const
name|p_disp
parameter_list|,
name|IN
specifier|const
name|cl_disp_msgid_t
name|msg_id
parameter_list|,
name|IN
name|cl_pfn_msgrcv_cb_t
name|pfn_callback
name|OPTIONAL
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
comment|/* * PARAMETERS *	p_disp *		[in] Pointer to a Dispatcher. * *	msg_id *		[in] Numberic message ID for which the client is registering. *		If the client does not wish to receive any messages, *		(a send-only client) then the caller should set this value *		to CL_DISP_MSGID_NONE.  For efficiency, numeric message msg_id *		values should start with 0 and should be contiguous, or nearly so. * *	pfn_callback *		[in] Message receive callback.  The Dispatcher calls this *		function after receiving a posted message with the *		appropriate message msg_id value.  Send-only clients may specify *		NULL for this value. * *	context *		[in] Client context value passed to the cl_pfn_msgrcv_cb_t *		function. * * RETURN VALUE *	On success a Dispatcher registration handle. *	CL_CL_DISP_INVALID_HANDLE otherwise. * * SEE ALSO *	Dispatcher, cl_disp_unregister, cl_disp_post *********/
end_comment

begin_comment
comment|/****f* Component Library: Dispatcher/cl_disp_unregister * NAME *	cl_disp_unregister * * DESCRIPTION *	This function unregisters a client from a Dispatcher. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_disp_unregister
parameter_list|(
name|IN
specifier|const
name|cl_disp_reg_handle_t
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	handle *		[in] cl_disp_reg_handle_t value return by cl_disp_register. * * RETURN VALUE *	This function does not return a value. * * NOTES *	This function will not return until worker threads have exited *	the callback functions for this client.  Do not invoke this *	function from a callback. * * SEE ALSO *	Dispatcher, cl_disp_register *********/
end_comment

begin_comment
comment|/****f* Component Library: Dispatcher/cl_disp_post * NAME *	cl_disp_post * * DESCRIPTION *	This function posts a message to a Dispatcher object. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_disp_post
parameter_list|(
name|IN
specifier|const
name|cl_disp_reg_handle_t
name|handle
parameter_list|,
name|IN
specifier|const
name|cl_disp_msgid_t
name|msg_id
parameter_list|,
name|IN
specifier|const
name|void
modifier|*
specifier|const
name|p_data
parameter_list|,
name|IN
name|cl_pfn_msgdone_cb_t
name|pfn_callback
name|OPTIONAL
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
comment|/* * PARAMETERS *	handle *		[in] cl_disp_reg_handle_t value return by cl_disp_register. * *	msg_id *		[in] Numeric message msg_id value associated with this message. * *	p_data *		[in] Data payload for this message. * *	pfn_callback *		[in] Pointer to a cl_pfn_msgdone_cb_t function. *		The Dispatcher calls this function after the message has been *		processed by the recipient. *		The caller may pass NULL for this value, which indicates no *		message done callback is necessary. * *	context *		[in] Client context value passed to the cl_pfn_msgdone_cb_t *		function. * * RETURN VALUE *	CL_SUCCESS if the message was successfully queued in the Dispatcher. * * NOTES *	The caller must not modify the memory pointed to by p_data until *	the Dispatcher call the pfn_callback function. * * SEE ALSO *	Dispatcher *********/
end_comment

begin_comment
comment|/****f* Component Library: Dispatcher/cl_disp_get_queue_status * NAME *	cl_disp_get_queue_status * * DESCRIPTION *	This function posts a message to a Dispatcher object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_disp_get_queue_status
parameter_list|(
name|IN
specifier|const
name|cl_disp_reg_handle_t
name|handle
parameter_list|,
name|OUT
name|uint32_t
modifier|*
name|p_num_queued_msgs
parameter_list|,
name|OUT
name|uint64_t
modifier|*
name|p_last_msg_queue_time_ms
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *   handle *     [in] cl_disp_reg_handle_t value return by cl_disp_register. * *   p_last_msg_queue_time_ms *     [out] pointer to a variable to hold the time the last popped up message *           spent in the queue * *   p_num_queued_msgs *     [out] number of messages in the queue * * RETURN VALUE *	Thr time the last popped up message stayed in the queue, in msec * * NOTES *	Extarnel Locking is not required. * * SEE ALSO *	Dispatcher *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(_CL_DISPATCHER_H_) */
end_comment

end_unit

