begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * validator/val_nsec.h - validator NSEC denial of existance functions.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains helper functions for the validator module.  * The functions help with NSEC checking, the different NSEC proofs  * for denial of existance, and proofs for presence of types.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VALIDATOR_VAL_NSEC_H
end_ifndef

begin_define
define|#
directive|define
name|VALIDATOR_VAL_NSEC_H
end_define

begin_include
include|#
directive|include
file|"util/data/packed_rrset.h"
end_include

begin_struct_decl
struct_decl|struct
name|val_env
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|module_env
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ub_packed_rrset_key
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|reply_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|query_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|key_entry_key
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * Check DS absence.  * There is a NODATA reply to a DS that needs checking.  * NSECs can prove this is not a delegation point, or sucessfully prove  * that there is no DS. Or this fails.  *  * @param env: module env for rrsig verification routines.  * @param ve: validator env for rrsig verification routines.  * @param qinfo: the DS queried for.  * @param rep: reply received.  * @param kkey: key entry to use for verification of signatures.  * @param proof_ttl: if secure, the TTL of how long this proof lasts.  * @param reason: string explaining why bogus.  * @return security status.  *	SECURE: proved absence of DS.  *	INSECURE: proved that this was not a delegation point.  *	BOGUS: crypto bad, or no absence of DS proven.   *	UNCHECKED: there was no way to prove anything (no NSECs, unknown algo).  */
end_comment

begin_function_decl
name|enum
name|sec_status
name|val_nsec_prove_nodata_dsreply
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|struct
name|val_env
modifier|*
name|ve
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|,
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|,
name|struct
name|key_entry_key
modifier|*
name|kkey
parameter_list|,
name|time_t
modifier|*
name|proof_ttl
parameter_list|,
name|char
modifier|*
modifier|*
name|reason
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * nsec typemap check, takes an NSEC-type bitmap as argument, checks for type.  * @param bitmap: pointer to the bitmap part of wireformat rdata.  * @param len: length of the bitmap, in bytes.  * @param type: the type (in host order) to check for.  * @return true if the type bit was set in the bitmap. false if not, or  * 	if the bitmap was malformed in some way.  */
end_comment

begin_function_decl
name|int
name|nsecbitmap_has_type_rdata
parameter_list|(
name|uint8_t
modifier|*
name|bitmap
parameter_list|,
name|size_t
name|len
parameter_list|,
name|uint16_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check if type is present in the NSEC typemap  * @param nsec: the nsec RRset.  *	If there are multiple RRs, then each must have the same typemap,  *	since the typemap represents the types at this domain node.  * @param type: type to check for, host order.  * @return true if present  */
end_comment

begin_function_decl
name|int
name|nsec_has_type
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|nsec
parameter_list|,
name|uint16_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Determine if a NSEC proves the NOERROR/NODATA conditions. This will also  * handle the empty non-terminal (ENT) case and partially handle the  * wildcard case. If the ownername of 'nsec' is a wildcard, the validator  * must still be provided proof that qname did not directly exist and that  * the wildcard is, in fact, *.closest_encloser.  *  * @param nsec: the nsec record to check against.  * @param qinfo: the query info.  * @param wc: if the nodata is proven for a wildcard match, the wildcard  * 	closest encloser is returned, else NULL (wc is unchanged).  * 	This closest encloser must then match the nameerror given for the  * 	nextcloser of qname.  * @return true if NSEC proves this.  */
end_comment

begin_function_decl
name|int
name|nsec_proves_nodata
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|nsec
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|,
name|uint8_t
modifier|*
modifier|*
name|wc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Determine if the given NSEC proves a NameError (NXDOMAIN) for a given  * qname.  *  * @param nsec: the nsec to check  * @param qname: what was queried.  * @return true if proven.  */
end_comment

begin_function_decl
name|int
name|val_nsec_proves_name_error
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|nsec
parameter_list|,
name|uint8_t
modifier|*
name|qname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Determine if the given NSEC proves a positive wildcard response.  * @param nsec: the nsec to check  * @param qinf: what was queried.  * @param wc: wildcard (without *. label)  * @return true if proven.  */
end_comment

begin_function_decl
name|int
name|val_nsec_proves_positive_wildcard
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|nsec
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinf
parameter_list|,
name|uint8_t
modifier|*
name|wc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Determine closest encloser of a query name and the NSEC that covers it  * (and thus disproved it).   * A name error must have been proven already, otherwise this will be invalid.  * @param qname: the name queried for.  * @param nsec: the nsec RRset.  * @return closest encloser dname or NULL on error (bad nsec RRset).  */
end_comment

begin_function_decl
name|uint8_t
modifier|*
name|nsec_closest_encloser
parameter_list|(
name|uint8_t
modifier|*
name|qname
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|nsec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Determine if the given NSEC proves that a wildcard match does not exist.  *  * @param nsec: the nsec RRset.  * @param qname: the name queried for.  * @param qnamelen: length of qname.  * @return true if proven.  */
end_comment

begin_function_decl
name|int
name|val_nsec_proves_no_wc
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|nsec
parameter_list|,
name|uint8_t
modifier|*
name|qname
parameter_list|,
name|size_t
name|qnamelen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Determine the DLV result, what to do with NSEC DLV reply.  * @param qinfo: what was queried for.  * @param rep: the nonpositive reply.  * @param nm: dlv lookup name, to adjust for new lookup name (if needed).  * @param nm_len: length of lookup name.  * @return 0 on error, 1 if a higher point is found.  * 	If the higher point is above the dlv repo anchor, the qname does   * 	not exist.  */
end_comment

begin_function_decl
name|int
name|val_nsec_check_dlv
parameter_list|(
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|,
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|,
name|uint8_t
modifier|*
modifier|*
name|nm
parameter_list|,
name|size_t
modifier|*
name|nm_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Determine if an nsec proves an insecure delegation towards the qname.  * @param nsec: nsec rrset.  * @param qinfo: what was queries for.  * @return 0 if not, 1 if an NSEC that signals an insecure delegation to  * 	the qname.  */
end_comment

begin_function_decl
name|int
name|val_nsec_proves_insecuredelegation
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|nsec
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VALIDATOR_VAL_NSEC_H */
end_comment

end_unit

