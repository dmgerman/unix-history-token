begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: validator.h,v 1.18.12.11 2006/01/06 00:01:42 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_VALIDATOR_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_VALIDATOR_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*! \file  *  * \brief  * DNS Validator  * This is the BIND 9 validator, the module responsible for validating the  * rdatasets and negative responses (messages).  It makes use of zones in  * the view and may fetch RRset to complete trust chains.  It implements  * DNSSEC as specified in RFC 4033, 4034 and 4035.  *  * It can also optionally implement ISC's DNSSEC look-aside validation.  *  * Correct operation is critical to preventing spoofed answers from secure  * zones being accepted.  *  * MP:  *\li	The module ensures appropriate synchronization of data structures it  *	creates and manipulates.  *  * Reliability:  *\li	No anticipated impact.  *  * Resources:  *\li	TBS  *  * Security:  *\li	No anticipated impact.  *  * Standards:  *\li	RFCs:	1034, 1035, 2181, 4033, 4034, 4035.  */
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
file|<isc/mutex.h>
end_include

begin_include
include|#
directive|include
file|<dns/fixedname.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_include
include|#
directive|include
file|<dns/rdataset.h>
end_include

begin_include
include|#
directive|include
file|<dns/rdatastruct.h>
end_include

begin_comment
comment|/* for dns_rdata_rrsig_t */
end_comment

begin_include
include|#
directive|include
file|<dst/dst.h>
end_include

begin_comment
comment|/*%  * A dns_validatorevent_t is sent when a 'validation' completes.  * \brief  * 'name', 'rdataset', 'sigrdataset', and 'message' are the values that were  * supplied when dns_validator_create() was called.  They are returned to the  * caller so that they may be freed.  *  * If the RESULT is ISC_R_SUCCESS and the answer is secure then  * proofs[] will contain the the names of the NSEC records that hold the  * various proofs.  Note the same name may appear multiple times.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dns_validatorevent
block|{
name|ISC_EVENT_COMMON
argument_list|(
expr|struct
name|dns_validatorevent
argument_list|)
expr_stmt|;
name|dns_validator_t
modifier|*
name|validator
decl_stmt|;
name|isc_result_t
name|result
decl_stmt|;
name|dns_name_t
modifier|*
name|name
decl_stmt|;
name|dns_rdatatype_t
name|type
decl_stmt|;
name|dns_rdataset_t
modifier|*
name|rdataset
decl_stmt|;
name|dns_rdataset_t
modifier|*
name|sigrdataset
decl_stmt|;
name|dns_message_t
modifier|*
name|message
decl_stmt|;
name|dns_name_t
modifier|*
name|proofs
index|[
literal|3
index|]
decl_stmt|;
block|}
name|dns_validatorevent_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DNS_VALIDATOR_NOQNAMEPROOF
value|0
end_define

begin_define
define|#
directive|define
name|DNS_VALIDATOR_NODATAPROOF
value|1
end_define

begin_define
define|#
directive|define
name|DNS_VALIDATOR_NOWILDCARDPROOF
value|2
end_define

begin_comment
comment|/*%  * A validator object represents a validation in progress.  * \brief  * Clients are strongly discouraged from using this type directly, with  * the exception of the 'link' field, which may be used directly for  * whatever purpose the client desires.  */
end_comment

begin_struct
struct|struct
name|dns_validator
block|{
comment|/* Unlocked. */
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_mutex_t
name|lock
decl_stmt|;
name|dns_view_t
modifier|*
name|view
decl_stmt|;
comment|/* Locked by lock. */
name|unsigned
name|int
name|options
decl_stmt|;
name|unsigned
name|int
name|attributes
decl_stmt|;
name|dns_validatorevent_t
modifier|*
name|event
decl_stmt|;
name|dns_fetch_t
modifier|*
name|fetch
decl_stmt|;
name|dns_validator_t
modifier|*
name|subvalidator
decl_stmt|;
name|dns_validator_t
modifier|*
name|parent
decl_stmt|;
name|dns_keytable_t
modifier|*
name|keytable
decl_stmt|;
name|dns_keynode_t
modifier|*
name|keynode
decl_stmt|;
name|dst_key_t
modifier|*
name|key
decl_stmt|;
name|dns_rdata_rrsig_t
modifier|*
name|siginfo
decl_stmt|;
name|isc_task_t
modifier|*
name|task
decl_stmt|;
name|isc_taskaction_t
name|action
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
name|unsigned
name|int
name|labels
decl_stmt|;
name|dns_rdataset_t
modifier|*
name|currentset
decl_stmt|;
name|isc_boolean_t
name|seensig
decl_stmt|;
name|dns_rdataset_t
modifier|*
name|keyset
decl_stmt|;
name|dns_rdataset_t
modifier|*
name|dsset
decl_stmt|;
name|dns_rdataset_t
modifier|*
name|soaset
decl_stmt|;
name|dns_rdataset_t
modifier|*
name|nsecset
decl_stmt|;
name|dns_name_t
modifier|*
name|soaname
decl_stmt|;
name|dns_rdataset_t
name|frdataset
decl_stmt|;
name|dns_rdataset_t
name|fsigrdataset
decl_stmt|;
name|dns_fixedname_t
name|fname
decl_stmt|;
name|dns_fixedname_t
name|wild
decl_stmt|;
name|ISC_LINK
argument_list|(
argument|dns_validator_t
argument_list|)
name|link
expr_stmt|;
name|dns_rdataset_t
name|dlv
decl_stmt|;
name|dns_fixedname_t
name|dlvsep
decl_stmt|;
name|isc_boolean_t
name|havedlvsep
decl_stmt|;
name|isc_boolean_t
name|mustbesecure
decl_stmt|;
name|unsigned
name|int
name|dlvlabels
decl_stmt|;
name|unsigned
name|int
name|depth
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*%  * dns_validator_create() options.  */
end_comment

begin_define
define|#
directive|define
name|DNS_VALIDATOR_DLV
value|1U
end_define

begin_define
define|#
directive|define
name|DNS_VALIDATOR_DEFER
value|2U
end_define

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|dns_validator_create
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdataset_t
modifier|*
name|sigrdataset
parameter_list|,
name|dns_message_t
modifier|*
name|message
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
name|dns_validator_t
modifier|*
modifier|*
name|validatorp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Start a DNSSEC validation.  *  * This validates a response to the question given by  * 'name' and 'type'.  *  * To validate a positive response, the response data is  * given by 'rdataset' and 'sigrdataset'.  If 'sigrdataset'  * is NULL, the data is presumed insecure and an attempt  * is made to prove its insecurity by finding the appropriate  * null key.  *  * The complete response message may be given in 'message',  * to make available any authority section NSECs that may be  * needed for validation of a response resulting from a  * wildcard expansion (though no such wildcard validation  * is implemented yet).  If the complete response message  * is not available, 'message' is NULL.  *  * To validate a negative response, the complete negative response  * message is given in 'message'.  The 'rdataset', and  * 'sigrdataset' arguments must be NULL, but the 'name' and 'type'  * arguments must be provided.  *  * The validation is performed in the context of 'view'.  *  * When the validation finishes, a dns_validatorevent_t with  * the given 'action' and 'arg' are sent to 'task'.  * Its 'result' field will be ISC_R_SUCCESS iff the  * response was successfully proven to be either secure or  * part of a known insecure domain.  *  * options:  * If DNS_VALIDATOR_DLV is set the caller knows there is not a  * trusted key and the validator should immediately attempt to validate  * the answer by looking for a appopriate DLV RRset.  */
end_comment

begin_function_decl
name|void
name|dns_validator_send
parameter_list|(
name|dns_validator_t
modifier|*
name|validator
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Send a deferred validation request  *  * Requires:  *	'validator' to points to a valid DNSSEC validator.  */
end_comment

begin_function_decl
name|void
name|dns_validator_cancel
parameter_list|(
name|dns_validator_t
modifier|*
name|validator
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Cancel a DNSSEC validation in progress.  *  * Requires:  *\li	'validator' points to a valid DNSSEC validator, which  *	may or may not already have completed.  *  * Ensures:  *\li	It the validator has not already sent its completion  *	event, it will send it with result code ISC_R_CANCELED.  */
end_comment

begin_function_decl
name|void
name|dns_validator_destroy
parameter_list|(
name|dns_validator_t
modifier|*
modifier|*
name|validatorp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Destroy a DNSSEC validator.  *  * Requires:  *\li	'*validatorp' points to a valid DNSSEC validator.  * \li	The validator must have completed and sent its completion  * 	event.  *  * Ensures:  *\li	All resources used by the validator are freed.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_VALIDATOR_H */
end_comment

end_unit

