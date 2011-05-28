begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Portions Copyright (C) 2004, 2005  Internet Systems Consortium, Inc. ("ISC")  * Portions Copyright (C) 2001  Internet Software Consortium.  * Portions Copyright (C) 2001  Nominum, Inc.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC AND NOMINUM DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY  * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: events.h,v 1.3.18.2 2005-04-29 00:17:13 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISCCC_EVENTS_H
end_ifndef

begin_define
define|#
directive|define
name|ISCCC_EVENTS_H
value|1
end_define

begin_comment
comment|/*! \file */
end_comment

begin_include
include|#
directive|include
file|<isc/eventclass.h>
end_include

begin_comment
comment|/*%  * Registry of ISCCC event numbers.  */
end_comment

begin_define
define|#
directive|define
name|ISCCC_EVENT_CCMSG
value|(ISC_EVENTCLASS_ISCCC + 0)
end_define

begin_define
define|#
directive|define
name|ISCCC_EVENT_FIRSTEVENT
value|(ISC_EVENTCLASS_ISCCC + 0)
end_define

begin_define
define|#
directive|define
name|ISCCC_EVENT_LASTEVENT
value|(ISC_EVENTCLASS_ISCCC + 65535)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISCCC_EVENTS_H */
end_comment

end_unit

