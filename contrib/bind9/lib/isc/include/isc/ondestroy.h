begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: ondestroy.h,v 1.7.206.1 2004/03/06 08:14:45 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_ONDESTROY_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_ONDESTROY_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/*  * ondestroy handling.  *  * Any class ``X'' of objects that wants to send out notifications  * on its destruction should declare a field of type isc_ondestroy_t  * (call it 'ondest').  *  * 	typedef struct {  * 		...  * 		isc_ondestroy_t	ondest;  * 		...  * 	} X;  *  * When an object ``A'' of type X is created  * it must initialize the field ondest with a call to  *  * 	isc_ondestroy_init(&A->ondest).  *  * X should also provide a registration function for third-party  * objects to call to register their interest in being told about  * the destruction of a particular instance of X.  *  *	isc_result_t  * 	X_ondestroy(X *instance, isc_task_t *task,  * 		     isc_event_t **eventp) {  * 		return(isc_ondestroy_register(&instance->ondest, task,eventp));  * 	}  *  *	Note: locking of the ondestory structure embedded inside of X, is  * 	X's responsibility.  *  * When an instance of X is destroyed, a call to  isc_ondestroy_notify()  * sends the notifications:  *  *	X *instance;  *	isc_ondestroy_t ondest = instance->ondest;  *  *	... completely cleanup 'instance' here...  *  * 	isc_ondestroy_notify(&ondest, instance);  *  *  * see dns/zone.c for an ifdef'd-out example.  */
end_comment

begin_struct
struct|struct
name|isc_ondestroy
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_eventlist_t
name|events
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|isc_ondestroy_init
parameter_list|(
name|isc_ondestroy_t
modifier|*
name|ondest
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Initialize the on ondest structure. *must* be called before first call  * to isc_ondestroy_register().  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_ondestroy_register
parameter_list|(
name|isc_ondestroy_t
modifier|*
name|ondest
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_event_t
modifier|*
modifier|*
name|eventp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Stores task and *eventp away inside *ondest.  Ownership of **event is  * taken from the caller (and *eventp is set to NULL). The task is attached  * to.  */
end_comment

begin_function_decl
name|void
name|isc_ondestroy_notify
parameter_list|(
name|isc_ondestroy_t
modifier|*
name|ondest
parameter_list|,
name|void
modifier|*
name|sender
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Dispatches the event(s) to the task(s) that were given in  * isc_ondestroy_register call(s) (done via calls to  * isc_task_sendanddetach()).  Before dispatch, the sender value of each  * event structure is set to the value of the sender paramater. The  * internal structures of the ondest parameter are cleaned out, so no other  * cleanup is needed.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_ONDESTROY_H */
end_comment

end_unit

