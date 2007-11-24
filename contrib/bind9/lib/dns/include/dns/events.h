begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: events.h,v 1.37.2.1.4.4 2004/03/08 09:04:36 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_EVENTS_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_EVENTS_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/eventclass.h>
end_include

begin_comment
comment|/*  * Registry of DNS event numbers.  */
end_comment

begin_define
define|#
directive|define
name|DNS_EVENT_FETCHCONTROL
value|(ISC_EVENTCLASS_DNS + 0)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_FETCHDONE
value|(ISC_EVENTCLASS_DNS + 1)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_VIEWRESSHUTDOWN
value|(ISC_EVENTCLASS_DNS + 2)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_VIEWADBSHUTDOWN
value|(ISC_EVENTCLASS_DNS + 3)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_UPDATE
value|(ISC_EVENTCLASS_DNS + 4)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_UPDATEDONE
value|(ISC_EVENTCLASS_DNS + 5)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_DISPATCH
value|(ISC_EVENTCLASS_DNS + 6)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_TCPMSG
value|(ISC_EVENTCLASS_DNS + 7)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_ADBMOREADDRESSES
value|(ISC_EVENTCLASS_DNS + 8)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_ADBNOMOREADDRESSES
value|(ISC_EVENTCLASS_DNS + 9)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_ADBCANCELED
value|(ISC_EVENTCLASS_DNS + 10)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_ADBNAMEDELETED
value|(ISC_EVENTCLASS_DNS + 11)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_ADBSHUTDOWN
value|(ISC_EVENTCLASS_DNS + 12)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_ADBEXPIRED
value|(ISC_EVENTCLASS_DNS + 13)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_ADBCONTROL
value|(ISC_EVENTCLASS_DNS + 14)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_CACHECLEAN
value|(ISC_EVENTCLASS_DNS + 15)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_BYADDRDONE
value|(ISC_EVENTCLASS_DNS + 16)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_ZONECONTROL
value|(ISC_EVENTCLASS_DNS + 17)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_DBDESTROYED
value|(ISC_EVENTCLASS_DNS + 18)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_VALIDATORDONE
value|(ISC_EVENTCLASS_DNS + 19)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_REQUESTDONE
value|(ISC_EVENTCLASS_DNS + 20)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_VALIDATORSTART
value|(ISC_EVENTCLASS_DNS + 21)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_VIEWREQSHUTDOWN
value|(ISC_EVENTCLASS_DNS + 22)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_NOTIFYSENDTOADDR
value|(ISC_EVENTCLASS_DNS + 23)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_ZONE
value|(ISC_EVENTCLASS_DNS + 24)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_ZONESTARTXFRIN
value|(ISC_EVENTCLASS_DNS + 25)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_MASTERQUANTUM
value|(ISC_EVENTCLASS_DNS + 26)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_CACHEOVERMEM
value|(ISC_EVENTCLASS_DNS + 27)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_MASTERNEXTZONE
value|(ISC_EVENTCLASS_DNS + 28)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_IOREADY
value|(ISC_EVENTCLASS_DNS + 29)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_LOOKUPDONE
value|(ISC_EVENTCLASS_DNS + 30)
end_define

begin_comment
comment|/* #define DNS_EVENT_unused			(ISC_EVENTCLASS_DNS + 31) */
end_comment

begin_define
define|#
directive|define
name|DNS_EVENT_DISPATCHCONTROL
value|(ISC_EVENTCLASS_DNS + 32)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_REQUESTCONTROL
value|(ISC_EVENTCLASS_DNS + 33)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_DUMPQUANTUM
value|(ISC_EVENTCLASS_DNS + 34)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_IMPORTRECVDONE
value|(ISC_EVENTCLASS_DNS + 35)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_FREESTORAGE
value|(ISC_EVENTCLASS_DNS + 36)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_FIRSTEVENT
value|(ISC_EVENTCLASS_DNS + 0)
end_define

begin_define
define|#
directive|define
name|DNS_EVENT_LASTEVENT
value|(ISC_EVENTCLASS_DNS + 65535)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_EVENTS_H */
end_comment

end_unit

