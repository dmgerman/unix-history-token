begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2011  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: clientinfo.h,v 1.3 2011/10/11 23:46:45 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_CLIENTINFO_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_CLIENTINFO_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*! \file dns/clientinfo.h  * \brief  * The DNS clientinfo interface allows libdns to retrieve information  * about the client from the caller.  *  * The clientinfo interface is used by the DNS DB and DLZ interfaces;  * it allows databases to modify their answers on the basis of information  * about the client, such as source IP address.  *  * dns_clientinfo_t contains a pointer to an opaque structure containing  * client information in some form.  dns_clientinfomethods_t contains a  * list of methods which operate on that opaque structure to return  * potentially useful data.  Both structures also contain versioning  * information.  */
end_comment

begin_comment
comment|/*****  ***** Imports  *****/
end_comment

begin_include
include|#
directive|include
file|<isc/sockaddr.h>
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
comment|/*****  ***** Types  *****/
end_comment

begin_define
define|#
directive|define
name|DNS_CLIENTINFO_VERSION
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|dns_clientinfo
block|{
name|isc_uint16_t
name|version
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
block|}
name|dns_clientinfo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|dns_clientinfo_sourceip_t
function_decl|)
parameter_list|(
name|dns_clientinfo_t
modifier|*
name|client
parameter_list|,
name|isc_sockaddr_t
modifier|*
modifier|*
name|addrp
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|DNS_CLIENTINFOMETHODS_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|DNS_CLIENTINFOMETHODS_AGE
value|0
end_define

begin_typedef
typedef|typedef
struct|struct
name|dns_clientinfomethods
block|{
name|isc_uint16_t
name|version
decl_stmt|;
name|isc_uint16_t
name|age
decl_stmt|;
name|dns_clientinfo_sourceip_t
name|sourceip
decl_stmt|;
block|}
name|dns_clientinfomethods_t
typedef|;
end_typedef

begin_comment
comment|/*****  ***** Methods  *****/
end_comment

begin_function_decl
name|void
name|dns_clientinfomethods_init
parameter_list|(
name|dns_clientinfomethods_t
modifier|*
name|methods
parameter_list|,
name|dns_clientinfo_sourceip_t
name|sourceip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_clientinfo_init
parameter_list|(
name|dns_clientinfo_t
modifier|*
name|ci
parameter_list|,
name|void
modifier|*
name|data
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
comment|/* DNS_CLIENTINFO_H */
end_comment

end_unit

