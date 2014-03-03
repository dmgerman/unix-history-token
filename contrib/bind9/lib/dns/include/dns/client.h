begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2009, 2013  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: client.h,v 1.3 2009/09/02 23:48:02 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_CLIENT_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_CLIENT_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*! \file  *  * \brief  * The DNS client module provides convenient programming interfaces to various  * DNS services, such as name resolution with or without DNSSEC validation or  * dynamic DNS update.  This module is primarily expected to be used by other  * applications than BIND9-related ones that need such advanced DNS features.  *  * MP:  *\li	In the typical usage of this module, application threads will not share  *	the same data structures created and manipulated in this module.  *	However, the module still ensures appropriate synchronization of such  *	data structures.  *  * Resources:  *\li	TBS  *  * Security:  *\li	This module does not handle any low-level data directly, and so no  *	security issue specific to this module is anticipated.  */
end_comment

begin_include
include|#
directive|include
file|<isc/event.h>
end_include

begin_include
include|#
directive|include
file|<isc/sockaddr.h>
end_include

begin_include
include|#
directive|include
file|<dns/tsig.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_include
include|#
directive|include
file|<dst/dst.h>
end_include

begin_typedef
typedef|typedef
enum|enum
block|{
name|updateop_none
init|=
literal|0
block|,
name|updateop_add
init|=
literal|1
block|,
name|updateop_delete
init|=
literal|2
block|,
name|updateop_exist
init|=
literal|3
block|,
name|updateop_notexist
init|=
literal|4
block|,
name|updateop_max
init|=
literal|5
block|}
name|dns_client_updateop_t
typedef|;
end_typedef

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/***  *** Types  ***/
end_comment

begin_comment
comment|/*%  * Optional flags for dns_client_create(x).  */
end_comment

begin_comment
comment|/*%< Enable caching resolution results (experimental). */
end_comment

begin_define
define|#
directive|define
name|DNS_CLIENTCREATEOPT_USECACHE
value|0x8000
end_define

begin_comment
comment|/*%  * Optional flags for dns_client_(start)resolve.  */
end_comment

begin_comment
comment|/*%< Disable DNSSEC validation. */
end_comment

begin_define
define|#
directive|define
name|DNS_CLIENTRESOPT_NODNSSEC
value|0x01
end_define

begin_comment
comment|/*%< Allow running external context. */
end_comment

begin_define
define|#
directive|define
name|DNS_CLIENTRESOPT_ALLOWRUN
value|0x02
end_define

begin_comment
comment|/*%  * Optional flags for dns_client_(start)request.  */
end_comment

begin_comment
comment|/*%< Allow running external context. */
end_comment

begin_define
define|#
directive|define
name|DNS_CLIENTREQOPT_ALLOWRUN
value|0x01
end_define

begin_comment
comment|/*%  * A dns_clientresevent_t is sent when name resolution performed by a client  * completes.  'result' stores the result code of the entire resolution  * procedure.  'vresult' specifically stores the result code of DNSSEC  * validation if it is performed.  When name resolution successfully completes,  * 'answerlist' is typically non empty, containing answer names along with  * RRsets.  It is the receiver's responsibility to free this list by calling  * dns_client_freeresanswer() before freeing the event structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dns_clientresevent
block|{
name|ISC_EVENT_COMMON
argument_list|(
expr|struct
name|dns_clientresevent
argument_list|)
expr_stmt|;
name|isc_result_t
name|result
decl_stmt|;
name|isc_result_t
name|vresult
decl_stmt|;
name|dns_namelist_t
name|answerlist
decl_stmt|;
block|}
name|dns_clientresevent_t
typedef|;
end_typedef

begin_comment
comment|/* too long? */
end_comment

begin_comment
comment|/*%  * Status of a dynamic update procedure.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|dns_clientupdatestate_prepare
block|,
comment|/*%< no updates have been sent */
name|dns_clientupdatestate_sent
block|,
comment|/*%< updates were sent, no response */
name|dns_clientupdatestate_done
comment|/*%< update was sent and succeeded */
block|}
name|dns_clientupdatestate_t
typedef|;
end_typedef

begin_comment
comment|/*%  * A dns_clientreqevent_t is sent when a DNS request is completed by a client.  * 'result' stores the result code of the entire transaction.  * If the transaction is successfully completed but the response packet cannot  * be parsed, 'result' will store the result code of dns_message_parse().  * If the response packet is received, 'rmessage' will contain the response  * message, whether it is successfully parsed or not.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dns_clientreqevent
block|{
name|ISC_EVENT_COMMON
argument_list|(
expr|struct
name|dns_clientreqevent
argument_list|)
expr_stmt|;
name|isc_result_t
name|result
decl_stmt|;
name|dns_message_t
modifier|*
name|rmessage
decl_stmt|;
block|}
name|dns_clientreqevent_t
typedef|;
end_typedef

begin_comment
comment|/* too long? */
end_comment

begin_comment
comment|/*%  * A dns_clientupdateevent_t is sent when dynamic update performed by a client  * completes.  'result' stores the result code of the entire update procedure.  * 'state' specifies the status of the update procedure when this event is  * sent.  This can be used as a hint by the receiver to determine whether  * the update attempt was ever made.  In particular, if the state is  * dns_clientupdatestate_prepare, the receiver can be sure that the requested  * update was not applied.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dns_clientupdateevent
block|{
name|ISC_EVENT_COMMON
argument_list|(
expr|struct
name|dns_clientupdateevent
argument_list|)
expr_stmt|;
name|isc_result_t
name|result
decl_stmt|;
name|dns_clientupdatestate_t
name|state
decl_stmt|;
block|}
name|dns_clientupdateevent_t
typedef|;
end_typedef

begin_comment
comment|/* too long? */
end_comment

begin_function_decl
name|isc_result_t
name|dns_client_create
parameter_list|(
name|dns_client_t
modifier|*
modifier|*
name|clientp
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_client_createx
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_appctx_t
modifier|*
name|actx
parameter_list|,
name|isc_taskmgr_t
modifier|*
name|taskmgr
parameter_list|,
name|isc_socketmgr_t
modifier|*
name|socketmgr
parameter_list|,
name|isc_timermgr_t
modifier|*
name|timermgr
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|dns_client_t
modifier|*
modifier|*
name|clientp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_client_createx2
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_appctx_t
modifier|*
name|actx
parameter_list|,
name|isc_taskmgr_t
modifier|*
name|taskmgr
parameter_list|,
name|isc_socketmgr_t
modifier|*
name|socketmgr
parameter_list|,
name|isc_timermgr_t
modifier|*
name|timermgr
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|dns_client_t
modifier|*
modifier|*
name|clientp
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|localaddr4
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|localaddr6
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Create a DNS client.  These functions create a new client object with  * minimal internal resources such as the default 'view' for the IN class and  * IPv4/IPv6 dispatches for the view.  *  * dns_client_createx() takes 'manager' arguments so that the caller can  * control the behavior of the client through the underlying event framework.  * On the other hand, dns_client_create() simplifies the interface and creates  * the managers internally.  A DNS client object created via  * dns_client_create() is expected to be used by an application that only needs  * simple synchronous services or by a thread-based application.  *  * dns_client_createx2 takes two additional parameters, 'localaddr4' and  * 'localaddr6', to specify the local address to use for each family. If  * both are set to NULL, then wildcard addresses will be used for both  * families. If only one is NULL, then the other address will be used  * as the local address, and the other protocol family will not be used.  *  * If the DNS_CLIENTCREATEOPT_USECACHE flag is set in 'options',  * dns_client_create(x) will create a cache database with the view.  *  * Requires:  *  *\li	'mctx' is a valid memory context.  *  *\li	'actx' is a valid application context.  *  *\li	'taskmgr' is a valid task manager.  *  *\li	'socketmgr' is a valid socket manager.  *  *\li	'timermgr' is a valid timer manager.  *  *\li	clientp != NULL&& *clientp == NULL.  *  * Returns:  *  *\li	#ISC_R_SUCCESS				On success.  *  *\li	Anything else				Failure.  */
end_comment

begin_function_decl
name|void
name|dns_client_destroy
parameter_list|(
name|dns_client_t
modifier|*
modifier|*
name|clientp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Destroy 'client'.  *  * Requires:  *  *\li	'*clientp' is a valid client.  *  * Ensures:  *  *\li	*clientp == NULL.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_client_setservers
parameter_list|(
name|dns_client_t
modifier|*
name|client
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|dns_name_t
modifier|*
name|namespace
parameter_list|,
name|isc_sockaddrlist_t
modifier|*
name|addrs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Specify a list of addresses of recursive name servers that the client will  * use for name resolution.  A view for the 'rdclass' class must be created  * beforehand.  If 'namespace' is non NULL, the specified server will be used  * if and only if the query name is a subdomain of 'namespace'.  When servers  * for multiple 'namespace's are provided, and a query name is covered by  * more than one 'namespace', the servers for the best (longest) matching  * namespace will be used.  If 'namespace' is NULL, it works as if  * dns_rootname (.) were specified.  *  * Requires:  *  *\li	'client' is a valid client.  *  *\li	'namespace' is NULL or a valid name.  *  *\li	'addrs' != NULL.  *  * Returns:  *  *\li	#ISC_R_SUCCESS				On success.  *  *\li	Anything else				Failure.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_client_clearservers
parameter_list|(
name|dns_client_t
modifier|*
name|client
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|dns_name_t
modifier|*
name|namespace
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Remove configured recursive name servers for the 'rdclass' and 'namespace'  * from the client.  See the description of dns_client_setservers() for  * the requirements about 'rdclass' and 'namespace'.  *  * Requires:  *  *\li	'client' is a valid client.  *  *\li	'namespace' is NULL or a valid name.  *  * Returns:  *  *\li	#ISC_R_SUCCESS				On success.  *  *\li	Anything else				Failure.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_client_resolve
parameter_list|(
name|dns_client_t
modifier|*
name|client
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|dns_namelist_t
modifier|*
name|namelist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_client_startresolve
parameter_list|(
name|dns_client_t
modifier|*
name|client
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|dns_rdatatype_t
name|type
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
name|dns_clientrestrans_t
modifier|*
modifier|*
name|transp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Perform name resolution for 'name', 'rdclass', and 'type'.  *  * If any trusted keys are configured and the query name is considered to  * belong to a secure zone, these functions also validate the responses  * using DNSSEC by default.  If the DNS_CLIENTRESOPT_NODNSSEC flag is set  * in 'options', DNSSEC validation is disabled regardless of the configured  * trusted keys or the query name.  *  * dns_client_resolve() provides a synchronous service.  This function starts  * name resolution internally and blocks until it completes.  On success,  * 'namelist' will contain a list of answer names, each of which has  * corresponding RRsets.  The caller must provide a valid empty list, and  * is responsible for freeing the list content via dns_client_freeresanswer().  * If the name resolution fails due to an error in DNSSEC validation,  * dns_client_resolve() returns the result code indicating the validation  * error. Otherwise, it returns the result code of the entire resolution  * process, either success or failure.  *  * It is typically expected that the client object passed to  * dns_client_resolve() was created via dns_client_create() and has its own  * managers and contexts.  However, if the DNS_CLIENTRESOPT_ALLOWRUN flag is  * set in 'options', this function performs the synchronous service even if  * it does not have its own manager and context structures.  *  * dns_client_startresolve() is an asynchronous version of dns_client_resolve()  * and does not block.  When name resolution is completed, 'action' will be  * called with the argument of a 'dns_clientresevent_t' object, which contains  * the resulting list of answer names (on success).  On return, '*transp' is  * set to an opaque transaction ID so that the caller can cancel this  * resolution process.  *  * Requires:  *  *\li	'client' is a valid client.  *  *\li	'addrs' != NULL.  *  *\li	'name' is a valid name.  *  *\li	'namelist' != NULL and is not empty.  *  *\li	'task' is a valid task.  *  *\li	'transp' != NULL&& *transp == NULL;  *  * Returns:  *  *\li	#ISC_R_SUCCESS				On success.  *  *\li	Anything else				Failure.  */
end_comment

begin_function_decl
name|void
name|dns_client_cancelresolve
parameter_list|(
name|dns_clientrestrans_t
modifier|*
name|trans
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Cancel an ongoing resolution procedure started via  * dns_client_startresolve().  *  * Notes:  *  *\li	If the resolution procedure has not completed, post its CLIENTRESDONE  *	event with a result code of #ISC_R_CANCELED.  *  * Requires:  *  *\li	'trans' is a valid transaction ID.  */
end_comment

begin_function_decl
name|void
name|dns_client_destroyrestrans
parameter_list|(
name|dns_clientrestrans_t
modifier|*
modifier|*
name|transp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Destroy name resolution transaction state identified by '*transp'.  *  * Requires:  *  *\li	'*transp' is a valid transaction ID.  *  *\li	The caller has received the CLIENTRESDONE event (either because the  *	resolution completed or because dns_client_cancelresolve() was called).  *  * Ensures:  *  *\li	*transp == NULL.  */
end_comment

begin_function_decl
name|void
name|dns_client_freeresanswer
parameter_list|(
name|dns_client_t
modifier|*
name|client
parameter_list|,
name|dns_namelist_t
modifier|*
name|namelist
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Free resources allocated for the content of 'namelist'.  *  * Requires:  *  *\li	'client' is a valid client.  *  *\li	'namelist' != NULL.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_client_addtrustedkey
parameter_list|(
name|dns_client_t
modifier|*
name|client
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|dns_name_t
modifier|*
name|keyname
parameter_list|,
name|isc_buffer_t
modifier|*
name|keydatabuf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Add a DNSSEC trusted key for the 'rdclass' class.  A view for the 'rdclass'  * class must be created beforehand.  'keyname' is the DNS name of the key,  * and 'keydatabuf' stores the resource data of the key.  *  * Requires:  *  *\li	'client' is a valid client.  *  *\li	'keyname' is a valid name.  *  *\li	'keydatabuf' is a valid buffer.  *  * Returns:  *  *\li	#ISC_R_SUCCESS				On success.  *  *\li	Anything else				Failure.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_client_request
parameter_list|(
name|dns_client_t
modifier|*
name|client
parameter_list|,
name|dns_message_t
modifier|*
name|qmessage
parameter_list|,
name|dns_message_t
modifier|*
name|rmessage
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|server
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|unsigned
name|int
name|parseoptions
parameter_list|,
name|dns_tsec_t
modifier|*
name|tsec
parameter_list|,
name|unsigned
name|int
name|timeout
parameter_list|,
name|unsigned
name|int
name|udptimeout
parameter_list|,
name|unsigned
name|int
name|udpretries
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_client_startrequest
parameter_list|(
name|dns_client_t
modifier|*
name|client
parameter_list|,
name|dns_message_t
modifier|*
name|qmessage
parameter_list|,
name|dns_message_t
modifier|*
name|rmessage
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|server
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|unsigned
name|int
name|parseoptions
parameter_list|,
name|dns_tsec_t
modifier|*
name|tsec
parameter_list|,
name|unsigned
name|int
name|timeout
parameter_list|,
name|unsigned
name|int
name|udptimeout
parameter_list|,
name|unsigned
name|int
name|udpretries
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
name|dns_clientreqtrans_t
modifier|*
modifier|*
name|transp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Send a DNS request containig a query message 'query' to 'server'.  *  * 'parseoptions' will be used when the response packet is parsed, and will be  * passed to dns_message_parse() via dns_request_getresponse().  See  * dns_message_parse() for more details.  *  * 'tsec' is a transaction security object containing, e.g. a TSIG key for  * authenticating the request/response transaction.  This is optional and can  * be NULL, in which case this library performs the transaction  without any  * transaction authentication.  *  * 'timeout', 'udptimeout', and 'udpretries' are passed to  * dns_request_createvia3().  See dns_request_createvia3() for more details.  *  * dns_client_request() provides a synchronous service.  This function sends  * the request and blocks until a response is received.  On success,  * 'rmessage' will contain the response message.  The caller must provide a  * valid initialized message.  *  * It is usually expected that the client object passed to  * dns_client_request() was created via dns_client_create() and has its own  * managers and contexts.  However, if the DNS_CLIENTREQOPT_ALLOWRUN flag is  * set in 'options', this function performs the synchronous service even if  * it does not have its own manager and context structures.  *  * dns_client_startrequest() is an asynchronous version of dns_client_request()  * and does not block.  When the transaction is completed, 'action' will be  * called with the argument of a 'dns_clientreqevent_t' object, which contains  * the response message (on success).  On return, '*transp' is set to an opaque  * transaction ID so that the caller can cancel this request.  *  * Requires:  *  *\li	'client' is a valid client.  *  *\li	'qmessage' and 'rmessage' are valid initialized message.  *  *\li	'server' is a valid socket address structure.  *  *\li	'task' is a valid task.  *  *\li	'transp' != NULL&& *transp == NULL;  *  * Returns:  *  *\li	#ISC_R_SUCCESS				On success.  *  *\li	Anything else				Failure.  *  *\li	Any result that dns_message_parse() can return.  */
end_comment

begin_function_decl
name|void
name|dns_client_cancelrequest
parameter_list|(
name|dns_clientreqtrans_t
modifier|*
name|transp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Cancel an ongoing DNS request procedure started via  * dns_client_startrequest().  *  * Notes:  *  *\li	If the request procedure has not completed, post its CLIENTREQDONE  *	event with a result code of #ISC_R_CANCELED.  *  * Requires:  *  *\li	'trans' is a valid transaction ID.  */
end_comment

begin_function_decl
name|void
name|dns_client_destroyreqtrans
parameter_list|(
name|dns_clientreqtrans_t
modifier|*
modifier|*
name|transp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Destroy DNS request transaction state identified by '*transp'.  *  * Requires:  *  *\li	'*transp' is a valid transaction ID.  *  *\li	The caller has received the CLIENTREQDONE event (either because the  *	request completed or because dns_client_cancelrequest() was called).  *  * Ensures:  *  *\li	*transp == NULL.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_client_update
parameter_list|(
name|dns_client_t
modifier|*
name|client
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|dns_name_t
modifier|*
name|zonename
parameter_list|,
name|dns_namelist_t
modifier|*
name|prerequisites
parameter_list|,
name|dns_namelist_t
modifier|*
name|updates
parameter_list|,
name|isc_sockaddrlist_t
modifier|*
name|servers
parameter_list|,
name|dns_tsec_t
modifier|*
name|tsec
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_client_startupdate
parameter_list|(
name|dns_client_t
modifier|*
name|client
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|dns_name_t
modifier|*
name|zonename
parameter_list|,
name|dns_namelist_t
modifier|*
name|prerequisites
parameter_list|,
name|dns_namelist_t
modifier|*
name|updates
parameter_list|,
name|isc_sockaddrlist_t
modifier|*
name|servers
parameter_list|,
name|dns_tsec_t
modifier|*
name|tsec
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
name|dns_clientupdatetrans_t
modifier|*
modifier|*
name|transp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Perform DNS dynamic update for 'updates' of the 'rdclass' class with  * optional 'prerequisites'.  *  * 'updates' are a list of names with associated RRsets to be updated.  *  * 'prerequisites' are a list of names with associated RRsets corresponding to  * the prerequisites of the updates.  This is optional and can be NULL, in  * which case the prerequisite section of the update message will be empty.  *  * Both 'updates' and 'prerequisites' must be constructed as specified in  * RFC2136.  *  * 'zonename' is the name of the zone in which the updated names exist.  * This is optional and can be NULL.  In this case, these functions internally  * identify the appropriate zone through some queries for the SOA RR starting  * with the first name in prerequisites or updates.  *  * 'servers' is a list of authoritative servers to which the update message  * should be sent.  This is optional and can be NULL.  In this case, these  * functions internally identify the appropriate primary server name and its  * addresses through some queries for the SOA RR (like the case of zonename)  * and supplemental A/AAAA queries for the server name.  * Note: The client module generally assumes the given addresses are of the  * primary server of the corresponding zone.  It will work even if a secondary  * server address is specified as long as the server allows update forwarding,  * it is generally discouraged to include secondary server addresses unless  * there's strong reason to do so.  *  * 'tsec' is a transaction security object containing, e.g. a TSIG key for  * authenticating the update transaction (and the supplemental query/response  * transactions if the server is specified).  This is optional and can be  * NULL, in which case the library tries the update without any transaction  * authentication.  *  * dns_client_update() provides a synchronous service.  This function blocks  * until the entire update procedure completes, including the additional  * queries when necessary.  *  * dns_client_startupdate() is an asynchronous version of dns_client_update().  * It immediately returns (typically with *transp being set to a non-NULL  * pointer), and performs the update procedure through a set of internal  * events.  All transactions including the additional query exchanges are  * performed as a separate event, so none of these events cause blocking  * operation.  When the update procedure completes, the specified function  * 'action' will be called with the argument of a 'dns_clientupdateevent_t'  * structure.  On return, '*transp' is set to an opaque transaction ID so that  * the caller can cancel this update process.  *  * Notes:  *\li	No options are currently defined.  *  * Requires:  *  *\li	'client' is a valid client.  *  *\li	'updates' != NULL.  *  *\li	'task' is a valid task.  *  *\li	'transp' != NULL&& *transp == NULL;  *  * Returns:  *  *\li	#ISC_R_SUCCESS				On success.  *  *\li	Anything else				Failure.  */
end_comment

begin_function_decl
name|void
name|dns_client_cancelupdate
parameter_list|(
name|dns_clientupdatetrans_t
modifier|*
name|trans
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Cancel an ongoing dynamic update procedure started via  * dns_client_startupdate().  *  * Notes:  *  *\li	If the update procedure has not completed, post its UPDATEDONE  *	event with a result code of #ISC_R_CANCELED.  *  * Requires:  *  *\li	'trans' is a valid transaction ID.  */
end_comment

begin_function_decl
name|void
name|dns_client_destroyupdatetrans
parameter_list|(
name|dns_clientupdatetrans_t
modifier|*
modifier|*
name|transp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Destroy dynamic update transaction identified by '*transp'.  *  * Requires:  *  *\li	'*transp' is a valid transaction ID.  *  *\li	The caller has received the UPDATEDONE event (either because the  *	update completed or because dns_client_cancelupdate() was called).  *  * Ensures:  *  *\li	*transp == NULL.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_client_updaterec
parameter_list|(
name|dns_client_updateop_t
name|op
parameter_list|,
name|dns_name_t
modifier|*
name|owner
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|dns_rdata_t
modifier|*
name|source
parameter_list|,
name|dns_ttl_t
name|ttl
parameter_list|,
name|dns_name_t
modifier|*
name|target
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdatalist_t
modifier|*
name|rdatalist
parameter_list|,
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * TBD  */
end_comment

begin_function_decl
name|void
name|dns_client_freeupdate
parameter_list|(
name|dns_name_t
modifier|*
modifier|*
name|namep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * TBD  */
end_comment

begin_function_decl
name|isc_mem_t
modifier|*
name|dns_client_mctx
parameter_list|(
name|dns_client_t
modifier|*
name|client
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
comment|/* DNS_CLIENT_H */
end_comment

end_unit

