begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: byaddr.h,v 1.12.2.1.2.4 2004/03/08 09:04:34 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_BYADDR_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_BYADDR_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * DNS ByAddr  *  * The byaddr module provides reverse lookup services for IPv4 and IPv6  * addresses.  *  * MP:  *	The module ensures appropriate synchronization of data structures it  *	creates and manipulates.  *  * Reliability:  *	No anticipated impact.  *  * Resources:  *<TBS>  *  * Security:  *	No anticipated impact.  *  * Standards:  *	RFCs:	1034, 1035, 2181,<TBS>  *	Drafts:<TBS>  */
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
comment|/*  * A 'dns_byaddrevent_t' is returned when a byaddr completes.  * The sender field will be set to the byaddr that completed.  If 'result'  * is ISC_R_SUCCESS, then 'names' will contain a list of names associated  * with the address.  The recipient of the event must not change the list  * and must not refer to any of the name data after the event is freed.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dns_byaddrevent
block|{
name|ISC_EVENT_COMMON
argument_list|(
expr|struct
name|dns_byaddrevent
argument_list|)
expr_stmt|;
name|isc_result_t
name|result
decl_stmt|;
name|dns_namelist_t
name|names
decl_stmt|;
block|}
name|dns_byaddrevent_t
typedef|;
end_typedef

begin_comment
comment|/*  * This option is deprecated since we now only consider nibbles. #define DNS_BYADDROPT_IPV6NIBBLE	0x0001  */
end_comment

begin_define
define|#
directive|define
name|DNS_BYADDROPT_IPV6INT
value|0x0002
end_define

begin_function_decl
name|isc_result_t
name|dns_byaddr_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_netaddr_t
modifier|*
name|address
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
name|dns_byaddr_t
modifier|*
modifier|*
name|byaddrp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Find the domain name of 'address'.  *  * Notes:  *  *	There is a reverse lookup format for IPv6 addresses, 'nibble'  *  *	The 'nibble' format for that address is  *  *   1.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.8.e.f.ip6.arpa.  *  *	DNS_BYADDROPT_IPV6INT can be used to get nibble lookups under ip6.int.  *  * Requires:  *  *	'mctx' is a valid mctx.  *  *	'address' is a valid IPv4 or IPv6 address.  *  *	'view' is a valid view which has a resolver.  *  *	'task' is a valid task.  *  *	byaddrp != NULL&& *byaddrp == NULL  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  *  *	Any resolver-related error (e.g. ISC_R_SHUTTINGDOWN) may also be  *	returned.  */
end_comment

begin_function_decl
name|void
name|dns_byaddr_cancel
parameter_list|(
name|dns_byaddr_t
modifier|*
name|byaddr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Cancel 'byaddr'.  *  * Notes:  *  *	If 'byaddr' has not completed, post its BYADDRDONE event with a  *	result code of ISC_R_CANCELED.  *  * Requires:  *  *	'byaddr' is a valid byaddr.  */
end_comment

begin_function_decl
name|void
name|dns_byaddr_destroy
parameter_list|(
name|dns_byaddr_t
modifier|*
modifier|*
name|byaddrp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Destroy 'byaddr'.  *  * Requires:  *  *	'*byaddrp' is a valid byaddr.  *  *	The caller has received the BYADDRDONE event (either because the  *	byaddr completed or because dns_byaddr_cancel() was called).  *  * Ensures:  *  *	*byaddrp == NULL.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_byaddr_createptrname
parameter_list|(
name|isc_netaddr_t
modifier|*
name|address
parameter_list|,
name|isc_boolean_t
name|nibble
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_byaddr_createptrname2
parameter_list|(
name|isc_netaddr_t
modifier|*
name|address
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Creates a name that would be used in a PTR query for this address.  The  * nibble flag indicates that the 'nibble' format is to be used if an IPv6  * address is provided, instead of the 'bitstring' format.  Since we dropped  * the support of the bitstring labels, it is expected that the flag is always  * set.  'options' are the same as for dns_byaddr_create().  *  * Requires:  *   * 	'address' is a valid address.  * 	'name' is a valid name with a dedicated buffer.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_BYADDR_H */
end_comment

end_unit

