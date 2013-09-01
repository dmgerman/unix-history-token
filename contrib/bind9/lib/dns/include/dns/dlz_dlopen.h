begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2011, 2012  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_comment
comment|/*! \file dns/dlz_open.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DLZ_DLOPEN_H
end_ifndef

begin_define
define|#
directive|define
name|DLZ_DLOPEN_H
end_define

begin_include
include|#
directive|include
file|<dns/sdlz.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/*  * This header provides a minimal set of defines and typedefs needed  * for the entry points of an external DLZ module for bind9.  */
end_comment

begin_define
define|#
directive|define
name|DLZ_DLOPEN_VERSION
value|2
end_define

begin_comment
comment|/*  * dlz_dlopen_version() is required for all DLZ external drivers. It  * should return DLZ_DLOPEN_VERSION  */
end_comment

begin_typedef
typedef|typedef
name|int
name|dlz_dlopen_version_t
parameter_list|(
name|unsigned
name|int
modifier|*
name|flags
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * dlz_dlopen_create() is required for all DLZ external drivers.  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
name|dlz_dlopen_create_t
parameter_list|(
specifier|const
name|char
modifier|*
name|dlzname
parameter_list|,
name|unsigned
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|void
modifier|*
modifier|*
name|dbdata
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * dlz_dlopen_destroy() is optional, and will be called when the  * driver is unloaded if supplied  */
end_comment

begin_typedef
typedef|typedef
name|void
name|dlz_dlopen_destroy_t
parameter_list|(
name|void
modifier|*
name|dbdata
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * dlz_dlopen_findzonedb() is required for all DLZ external drivers  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
name|dlz_dlopen_findzonedb_t
parameter_list|(
name|void
modifier|*
name|dbdata
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * dlz_dlopen_lookup() is required for all DLZ external drivers  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
name|dlz_dlopen_lookup_t
parameter_list|(
specifier|const
name|char
modifier|*
name|zone
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|dbdata
parameter_list|,
name|dns_sdlzlookup_t
modifier|*
name|lookup
parameter_list|,
name|dns_clientinfomethods_t
modifier|*
name|methods
parameter_list|,
name|dns_clientinfo_t
modifier|*
name|clientinfo
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * dlz_dlopen_authority is optional() if dlz_dlopen_lookup()  * supplies authority information for the dns record  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
name|dlz_dlopen_authority_t
parameter_list|(
specifier|const
name|char
modifier|*
name|zone
parameter_list|,
name|void
modifier|*
name|dbdata
parameter_list|,
name|dns_sdlzlookup_t
modifier|*
name|lookup
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * dlz_dlopen_allowzonexfr() is optional, and should be supplied if  * you want to support zone transfers  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
name|dlz_dlopen_allowzonexfr_t
parameter_list|(
name|void
modifier|*
name|dbdata
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|client
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * dlz_dlopen_allnodes() is optional, but must be supplied if supply a  * dlz_dlopen_allowzonexfr() function  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
name|dlz_dlopen_allnodes_t
parameter_list|(
specifier|const
name|char
modifier|*
name|zone
parameter_list|,
name|void
modifier|*
name|dbdata
parameter_list|,
name|dns_sdlzallnodes_t
modifier|*
name|allnodes
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * dlz_dlopen_newversion() is optional. It should be supplied if you  * want to support dynamic updates.  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
name|dlz_dlopen_newversion_t
parameter_list|(
specifier|const
name|char
modifier|*
name|zone
parameter_list|,
name|void
modifier|*
name|dbdata
parameter_list|,
name|void
modifier|*
modifier|*
name|versionp
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * dlz_closeversion() is optional, but must be supplied if you supply  * a dlz_newversion() function  */
end_comment

begin_typedef
typedef|typedef
name|void
name|dlz_dlopen_closeversion_t
parameter_list|(
specifier|const
name|char
modifier|*
name|zone
parameter_list|,
name|isc_boolean_t
name|commit
parameter_list|,
name|void
modifier|*
name|dbdata
parameter_list|,
name|void
modifier|*
modifier|*
name|versionp
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * dlz_dlopen_configure() is optional, but must be supplied if you  * want to support dynamic updates  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
name|dlz_dlopen_configure_t
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|void
modifier|*
name|dbdata
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * dlz_dlopen_setclientcallback() is optional, but must be supplied if you  * want to retrieve information about the client (e.g., source address)  * before sending a replay.  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
name|dlz_dlopen_setclientcallback_t
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|void
modifier|*
name|dbdata
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * dlz_dlopen_ssumatch() is optional, but must be supplied if you want  * to support dynamic updates  */
end_comment

begin_typedef
typedef|typedef
name|isc_boolean_t
name|dlz_dlopen_ssumatch_t
parameter_list|(
specifier|const
name|char
modifier|*
name|signer
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|tcpaddr
parameter_list|,
specifier|const
name|char
modifier|*
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|key
parameter_list|,
name|isc_uint32_t
name|keydatalen
parameter_list|,
name|unsigned
name|char
modifier|*
name|keydata
parameter_list|,
name|void
modifier|*
name|dbdata
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * dlz_dlopen_addrdataset() is optional, but must be supplied if you  * want to support dynamic updates  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
name|dlz_dlopen_addrdataset_t
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|rdatastr
parameter_list|,
name|void
modifier|*
name|dbdata
parameter_list|,
name|void
modifier|*
name|version
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * dlz_dlopen_subrdataset() is optional, but must be supplied if you  * want to support dynamic updates  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
name|dlz_dlopen_subrdataset_t
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|rdatastr
parameter_list|,
name|void
modifier|*
name|dbdata
parameter_list|,
name|void
modifier|*
name|version
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * dlz_dlopen_delrdataset() is optional, but must be supplied if you  * want to support dynamic updates  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
name|dlz_dlopen_delrdataset_t
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|type
parameter_list|,
name|void
modifier|*
name|dbdata
parameter_list|,
name|void
modifier|*
name|version
parameter_list|)
function_decl|;
end_typedef

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

