begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: query.h,v 1.28.2.3.8.6 2004/03/08 04:04:21 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NAMED_QUERY_H
end_ifndef

begin_define
define|#
directive|define
name|NAMED_QUERY_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_include
include|#
directive|include
file|<isc/buffer.h>
end_include

begin_include
include|#
directive|include
file|<isc/netaddr.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_include
include|#
directive|include
file|<named/types.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|ns_dbversion
block|{
name|dns_db_t
modifier|*
name|db
decl_stmt|;
name|dns_dbversion_t
modifier|*
name|version
decl_stmt|;
name|isc_boolean_t
name|queryok
decl_stmt|;
name|ISC_LINK
argument_list|(
argument|struct ns_dbversion
argument_list|)
name|link
expr_stmt|;
block|}
name|ns_dbversion_t
typedef|;
end_typedef

begin_struct
struct|struct
name|ns_query
block|{
name|unsigned
name|int
name|attributes
decl_stmt|;
name|unsigned
name|int
name|restarts
decl_stmt|;
name|isc_boolean_t
name|timerset
decl_stmt|;
name|dns_name_t
modifier|*
name|qname
decl_stmt|;
name|dns_name_t
modifier|*
name|origqname
decl_stmt|;
name|unsigned
name|int
name|dboptions
decl_stmt|;
name|unsigned
name|int
name|fetchoptions
decl_stmt|;
name|dns_db_t
modifier|*
name|gluedb
decl_stmt|;
name|dns_db_t
modifier|*
name|authdb
decl_stmt|;
name|dns_zone_t
modifier|*
name|authzone
decl_stmt|;
name|isc_boolean_t
name|authdbset
decl_stmt|;
name|isc_boolean_t
name|isreferral
decl_stmt|;
name|isc_mutex_t
name|fetchlock
decl_stmt|;
name|dns_fetch_t
modifier|*
name|fetch
decl_stmt|;
name|isc_bufferlist_t
name|namebufs
decl_stmt|;
name|ISC_LIST
argument_list|(
argument|ns_dbversion_t
argument_list|)
name|activeversions
expr_stmt|;
name|ISC_LIST
argument_list|(
argument|ns_dbversion_t
argument_list|)
name|freeversions
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NS_QUERYATTR_RECURSIONOK
value|0x0001
end_define

begin_define
define|#
directive|define
name|NS_QUERYATTR_CACHEOK
value|0x0002
end_define

begin_define
define|#
directive|define
name|NS_QUERYATTR_PARTIALANSWER
value|0x0004
end_define

begin_define
define|#
directive|define
name|NS_QUERYATTR_NAMEBUFUSED
value|0x0008
end_define

begin_define
define|#
directive|define
name|NS_QUERYATTR_RECURSING
value|0x0010
end_define

begin_define
define|#
directive|define
name|NS_QUERYATTR_CACHEGLUEOK
value|0x0020
end_define

begin_define
define|#
directive|define
name|NS_QUERYATTR_QUERYOKVALID
value|0x0040
end_define

begin_define
define|#
directive|define
name|NS_QUERYATTR_QUERYOK
value|0x0080
end_define

begin_define
define|#
directive|define
name|NS_QUERYATTR_WANTRECURSION
value|0x0100
end_define

begin_define
define|#
directive|define
name|NS_QUERYATTR_SECURE
value|0x0200
end_define

begin_define
define|#
directive|define
name|NS_QUERYATTR_NOAUTHORITY
value|0x0400
end_define

begin_define
define|#
directive|define
name|NS_QUERYATTR_NOADDITIONAL
value|0x0800
end_define

begin_function_decl
name|isc_result_t
name|ns_query_init
parameter_list|(
name|ns_client_t
modifier|*
name|client
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_query_free
parameter_list|(
name|ns_client_t
modifier|*
name|client
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_query_start
parameter_list|(
name|ns_client_t
modifier|*
name|client
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_query_cancel
parameter_list|(
name|ns_client_t
modifier|*
name|client
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NAMED_QUERY_H */
end_comment

end_unit

