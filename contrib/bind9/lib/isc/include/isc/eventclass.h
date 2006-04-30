begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1998-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: eventclass.h,v 1.13.206.1 2004/03/06 08:14:40 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_EVENTCLASS_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_EVENTCLASS_H
value|1
end_define

begin_comment
comment|/*****  ***** Registry of Predefined Event Type Classes  *****/
end_comment

begin_comment
comment|/*  * An event class is an unsigned 16 bit number.  Each class may contain up  * to 65536 events.  An event type is formed by adding the event number  * within the class to the class number.  */
end_comment

begin_define
define|#
directive|define
name|ISC_EVENTCLASS
parameter_list|(
name|eclass
parameter_list|)
value|((eclass)<< 16)
end_define

begin_comment
comment|/*  * Classes< 1024 are reserved for ISC use.  */
end_comment

begin_define
define|#
directive|define
name|ISC_EVENTCLASS_TASK
value|ISC_EVENTCLASS(0)
end_define

begin_define
define|#
directive|define
name|ISC_EVENTCLASS_TIMER
value|ISC_EVENTCLASS(1)
end_define

begin_define
define|#
directive|define
name|ISC_EVENTCLASS_SOCKET
value|ISC_EVENTCLASS(2)
end_define

begin_define
define|#
directive|define
name|ISC_EVENTCLASS_FILE
value|ISC_EVENTCLASS(3)
end_define

begin_define
define|#
directive|define
name|ISC_EVENTCLASS_DNS
value|ISC_EVENTCLASS(4)
end_define

begin_define
define|#
directive|define
name|ISC_EVENTCLASS_APP
value|ISC_EVENTCLASS(5)
end_define

begin_define
define|#
directive|define
name|ISC_EVENTCLASS_OMAPI
value|ISC_EVENTCLASS(6)
end_define

begin_define
define|#
directive|define
name|ISC_EVENTCLASS_RATELIMITER
value|ISC_EVENTCLASS(7)
end_define

begin_define
define|#
directive|define
name|ISC_EVENTCLASS_ISCCC
value|ISC_EVENTCLASS(8)
end_define

begin_comment
comment|/*  * Event classes>= 1024 and<= 65535 are reserved for application use.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_EVENTCLASS_H */
end_comment

end_unit

