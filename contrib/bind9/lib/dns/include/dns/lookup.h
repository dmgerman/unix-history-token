begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: lookup.h,v 1.5.206.1 2004/03/06 08:13:57 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_LOOKUP_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_LOOKUP_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * DNS Lookup  *  * The lookup module performs simple DNS lookups.  It implements  * the full resolver algorithm, both looking for local data and   * resoving external names as necessary.  *  * MP:  *	The module ensures appropriate synchronization of data structures it  *	creates and manipulates.  *  * Reliability:  *	No anticipated impact.  *  * Resources:  *<TBS>  *  * Security:  *	No anticipated impact.  *  * Standards:  *	RFCs:	1034, 1035, 2181,<TBS>  *	Drafts:<TBS>  */
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/event.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/*  * A 'dns_lookupevent_t' is returned when a lookup completes.  * The sender field will be set to the lookup that completed.  If 'result'  * is ISC_R_SUCCESS, then 'names' will contain a list of names associated  * with the address.  The recipient of the event must not change the list  * and must not refer to any of the name data after the event is freed.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dns_lookupevent
block|{
name|ISC_EVENT_COMMON
argument_list|(
expr|struct
name|dns_lookupevent
argument_list|)
expr_stmt|;
name|isc_result_t
name|result
decl_stmt|;
name|dns_name_t
modifier|*
name|name
decl_stmt|;
name|dns_rdataset_t
modifier|*
name|rdataset
decl_stmt|;
name|dns_rdataset_t
modifier|*
name|sigrdataset
decl_stmt|;
name|dns_db_t
modifier|*
name|db
decl_stmt|;
name|dns_dbnode_t
modifier|*
name|node
decl_stmt|;
block|}
name|dns_lookupevent_t
typedef|;
end_typedef

begin_function_decl
name|isc_result_t
name|dns_lookup_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_taskaction_t
name|action
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|dns_lookup_t
modifier|*
modifier|*
name|lookupp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Finds the rrsets matching 'name' and 'type'.  *  * Requires:  *  *	'mctx' is a valid mctx.  *  *	'name' is a valid name.  *  *	'view' is a valid view which has a resolver.  *  *	'task' is a valid task.  *  *	lookupp != NULL&& *lookupp == NULL  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  *  *	Any resolver-related error (e.g. ISC_R_SHUTTINGDOWN) may also be  *	returned.  */
end_comment

begin_function_decl
name|void
name|dns_lookup_cancel
parameter_list|(
name|dns_lookup_t
modifier|*
name|lookup
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Cancel 'lookup'.  *  * Notes:  *  *	If 'lookup' has not completed, post its LOOKUPDONE event with a  *	result code of ISC_R_CANCELED.  *  * Requires:  *  *	'lookup' is a valid lookup.  */
end_comment

begin_function_decl
name|void
name|dns_lookup_destroy
parameter_list|(
name|dns_lookup_t
modifier|*
modifier|*
name|lookupp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Destroy 'lookup'.  *  * Requires:  *  *	'*lookupp' is a valid lookup.  *  *	The caller has received the LOOKUPDONE event (either because the  *	lookup completed or because dns_lookup_cancel() was called).  *  * Ensures:  *  *	*lookupp == NULL.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_LOOKUP_H */
end_comment

end_unit

