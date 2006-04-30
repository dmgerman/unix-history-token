begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: zt.h,v 1.27.2.2.8.1 2004/03/06 08:14:01 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_ZT_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_ZT_H
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
file|<dns/types.h>
end_include

begin_define
define|#
directive|define
name|DNS_ZTFIND_NOEXACT
value|0x01
end_define

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|dns_zt_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|dns_zt_t
modifier|*
modifier|*
name|zt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Creates a new zone table.  *  * Requires:  * 	'mctx' to be initialized.  *  * Returns:  *	ISC_R_SUCCESS on success.  *	ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zt_mount
parameter_list|(
name|dns_zt_t
modifier|*
name|zt
parameter_list|,
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Mounts the zone on the zone table.  *  * Requires:  *	'zt' to be valid  *	'zone' to be valid  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_EXISTS  *	ISC_R_NOSPACE  *	ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zt_unmount
parameter_list|(
name|dns_zt_t
modifier|*
name|zt
parameter_list|,
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Unmount the given zone from the table.  *  * Requires:  * 	'zt' to be valid  *	'zone' to be valid  *  * Returns:  * 	ISC_R_SUCCESS  *	ISC_R_NOTFOUND  *	ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zt_find
parameter_list|(
name|dns_zt_t
modifier|*
name|zt
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|dns_name_t
modifier|*
name|foundname
parameter_list|,
name|dns_zone_t
modifier|*
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Find the best match for 'name' in 'zt'.  If foundname is non NULL  * then the name of the zone found is returned.  *  * Notes:  *	If the DNS_ZTFIND_NOEXACT is set, the best partial match (if any)  *	to 'name' will be returned.  *  * Requires:  *	'zt' to be valid  *	'name' to be valid  *	'foundname' to be initialized and associated with a fixedname or NULL  *	'zone' to be non NULL and '*zone' to be NULL  *  * Returns:  * 	ISC_R_SUCCESS  *	DNS_R_PARTIALMATCH  *	ISC_R_NOTFOUND  *	ISC_R_NOSPACE  */
end_comment

begin_function_decl
name|void
name|dns_zt_detach
parameter_list|(
name|dns_zt_t
modifier|*
modifier|*
name|ztp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Detach the given zonetable, if the reference count goes to zero the  * zonetable will be freed.  In either case 'ztp' is set to NULL.  *  * Requires:  *	'*ztp' to be valid  */
end_comment

begin_function_decl
name|void
name|dns_zt_flushanddetach
parameter_list|(
name|dns_zt_t
modifier|*
modifier|*
name|ztp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Detach the given zonetable, if the reference count goes to zero the  * zonetable will be flushed and then freed.  In either case 'ztp' is  * set to NULL.  *  * Requires:  *	'*ztp' to be valid  */
end_comment

begin_function_decl
name|void
name|dns_zt_attach
parameter_list|(
name|dns_zt_t
modifier|*
name|zt
parameter_list|,
name|dns_zt_t
modifier|*
modifier|*
name|ztp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attach 'zt' to '*ztp'.  *  * Requires:  *	'zt' to be valid  *	'*ztp' to be NULL  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zt_load
parameter_list|(
name|dns_zt_t
modifier|*
name|zt
parameter_list|,
name|isc_boolean_t
name|stop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_zt_loadnew
parameter_list|(
name|dns_zt_t
modifier|*
name|zt
parameter_list|,
name|isc_boolean_t
name|stop
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Load all zones in the table.  If 'stop' is ISC_TRUE,  * stop on the first error and return it.  If 'stop'  * is ISC_FALSE, ignore errors.  *  * dns_zt_loadnew() only loads zones that are not yet loaded.  * dns_zt_load() also loads zones that are already loaded and  * and whose master file has changed since the last load.  *  * Requires:  *	'zt' to be valid  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zt_apply
parameter_list|(
name|dns_zt_t
modifier|*
name|zt
parameter_list|,
name|isc_boolean_t
name|stop
parameter_list|,
name|isc_result_t
function_decl|(
modifier|*
name|action
function_decl|)
parameter_list|(
name|dns_zone_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|uap
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Apply a given 'action' to all zone zones in the table.  * If 'stop' is 'ISC_TRUE' then walking the zone tree will stop if  * 'action' does not return ISC_R_SUCCESS.  *  * Requires:  *	'zt' to be valid.  *	'action' to be non NULL.  *  * Returns:  *	ISC_R_SUCCESS if action was applied to all nodes.  *	any error code from 'action'.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_ZT_H */
end_comment

end_unit

