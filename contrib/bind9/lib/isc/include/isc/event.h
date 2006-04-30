begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1998-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: event.h,v 1.24.2.2.8.2 2004/04/15 02:10:41 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_EVENT_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_EVENT_H
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

begin_comment
comment|/*****  ***** Events.  *****/
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|isc_eventdestructor_t
function_decl|)
parameter_list|(
name|isc_event_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|ISC_EVENT_COMMON
parameter_list|(
name|ltype
parameter_list|)
define|\
value|size_t				ev_size; \ 	unsigned int			ev_attributes; \ 	void *				ev_tag; \ 	isc_eventtype_t			ev_type; \ 	isc_taskaction_t		ev_action; \ 	void *				ev_arg; \ 	void *				ev_sender; \ 	isc_eventdestructor_t		ev_destroy; \ 	void *				ev_destroy_arg; \ 	ISC_LINK(ltype)			ev_link
end_define

begin_comment
comment|/*  * Attributes matching a mask of 0x000000ff are reserved for the task library's  * definition.  Attributes of 0xffffff00 may be used by the application  * or non-ISC libraries.  */
end_comment

begin_define
define|#
directive|define
name|ISC_EVENTATTR_NOPURGE
value|0x00000001
end_define

begin_comment
comment|/*  * The ISC_EVENTATTR_CANCELED attribute is intended to indicate  * that an event is delivered as a result of a canceled operation  * rather than successful completion, by mutual agreement  * between the sender and receiver.  It is not set or used by  * the task system.  */
end_comment

begin_define
define|#
directive|define
name|ISC_EVENTATTR_CANCELED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ISC_EVENT_INIT
parameter_list|(
name|event
parameter_list|,
name|sz
parameter_list|,
name|at
parameter_list|,
name|ta
parameter_list|,
name|ty
parameter_list|,
name|ac
parameter_list|,
name|ar
parameter_list|,
name|sn
parameter_list|,
name|df
parameter_list|,
name|da
parameter_list|)
define|\
value|do { \ 	(event)->ev_size = (sz); \ 	(event)->ev_attributes = (at); \ 	(event)->ev_tag = (ta); \ 	(event)->ev_type = (ty); \ 	(event)->ev_action = (ac); \ 	(event)->ev_arg = (ar); \ 	(event)->ev_sender = (sn); \ 	(event)->ev_destroy = (df); \ 	(event)->ev_destroy_arg = (da); \ 	ISC_LINK_INIT((event), ev_link); \ } while (0)
end_define

begin_comment
comment|/*  * This structure is public because "subclassing" it may be useful when  * defining new event types.  */
end_comment

begin_struct
struct|struct
name|isc_event
block|{
name|ISC_EVENT_COMMON
argument_list|(
expr|struct
name|isc_event
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISC_EVENTTYPE_FIRSTEVENT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ISC_EVENTTYPE_LASTEVENT
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|ISC_EVENT_PTR
parameter_list|(
name|p
parameter_list|)
value|((isc_event_t **)(void *)(p))
end_define

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_event_t
modifier|*
name|isc_event_allocate
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|void
modifier|*
name|sender
parameter_list|,
name|isc_eventtype_t
name|type
parameter_list|,
name|isc_taskaction_t
name|action
parameter_list|,
specifier|const
name|void
modifier|*
name|arg
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Allocate and initialize in a structure with initial elements  * defined by:  *  *	struct {  *		ISC_EVENT_COMMON(struct isc_event);  *		...  *	};  *	  * Requires:  *	'size'>= sizeof(struct isc_event)  *	'action' to be non NULL  *  * Returns:  *	a pointer to a initialized structure of the requested size.  *	NULL if unable to allocate memory.  */
end_comment

begin_function_decl
name|void
name|isc_event_free
parameter_list|(
name|isc_event_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_EVENT_H */
end_comment

end_unit

