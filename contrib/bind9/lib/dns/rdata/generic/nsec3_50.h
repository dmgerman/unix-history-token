begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2008, 2011, 2012  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GENERIC_NSEC3_50_H
end_ifndef

begin_define
define|#
directive|define
name|GENERIC_NSEC3_50_H
value|1
end_define

begin_comment
comment|/* $Id$ */
end_comment

begin_comment
comment|/*!  * \brief Per RFC 5155 */
end_comment

begin_include
include|#
directive|include
file|<isc/iterated_hash.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|dns_rdata_nsec3
block|{
name|dns_rdatacommon_t
name|common
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|dns_hash_t
name|hash
decl_stmt|;
name|unsigned
name|char
name|flags
decl_stmt|;
name|dns_iterations_t
name|iterations
decl_stmt|;
name|unsigned
name|char
name|salt_length
decl_stmt|;
name|unsigned
name|char
name|next_length
decl_stmt|;
name|isc_uint16_t
name|len
decl_stmt|;
name|unsigned
name|char
modifier|*
name|salt
decl_stmt|;
name|unsigned
name|char
modifier|*
name|next
decl_stmt|;
name|unsigned
name|char
modifier|*
name|typebits
decl_stmt|;
block|}
name|dns_rdata_nsec3_t
typedef|;
end_typedef

begin_comment
comment|/*  * The corresponding NSEC3 interval is OPTOUT indicating possible  * insecure delegations.  */
end_comment

begin_define
define|#
directive|define
name|DNS_NSEC3FLAG_OPTOUT
value|0x01U
end_define

begin_comment
comment|/*%  * The following flags are used in the private-type record (implemented in  * lib/dns/private.c) which is used to store NSEC3PARAM data during the  * time when it is not legal to have an actual NSEC3PARAM record in the  * zone.  They are defined here because the private-type record uses the  * same flags field for the OPTOUT flag above and for the private flags  * below.  XXX: This should be considered for refactoring.  */
end_comment

begin_comment
comment|/*%  * Non-standard, private type only.  *  * Create a corresponding NSEC3 chain.  * Once the NSEC3 chain is complete this flag will be removed to signal  * that there is a complete chain.  *  * This flag is automatically set when a NSEC3PARAM record is added to  * the zone via UPDATE.  *  * NSEC3PARAM records containing this flag should never be published,  * but if they are, they should be ignored by RFC 5155 compliant  * nameservers.  */
end_comment

begin_define
define|#
directive|define
name|DNS_NSEC3FLAG_CREATE
value|0x80U
end_define

begin_comment
comment|/*%  * Non-standard, private type only.  *  * The corresponding NSEC3 set is to be removed once the NSEC chain  * has been generated.  *  * This flag is automatically set when the last active NSEC3PARAM record  * is removed from the zone via UPDATE.  *  * NSEC3PARAM records containing this flag should never be published,  * but if they are, they should be ignored by RFC 5155 compliant  * nameservers.  */
end_comment

begin_define
define|#
directive|define
name|DNS_NSEC3FLAG_REMOVE
value|0x40U
end_define

begin_comment
comment|/*%  * Non-standard, private type only.  *  * When set with the CREATE flag, a corresponding NSEC3 chain will be  * created when the zone becomes capable of supporting one (i.e., when it  * has a DNSKEY RRset containing at least one NSEC3-capable algorithm).  * Without this flag, NSEC3 chain creation would be attempted immediately,  * fail, and the private type record would be removed.  With it, the NSEC3  * parameters are stored until they can be used.  When the zone has the  * necessary prerequisites for NSEC3, then the INITIAL flag can be cleared,  * and the record will be cleaned up normally.  *  * NSEC3PARAM records containing this flag should never be published, but  * if they are, they should be ignored by RFC 5155 compliant nameservers.  */
end_comment

begin_define
define|#
directive|define
name|DNS_NSEC3FLAG_INITIAL
value|0x20U
end_define

begin_comment
comment|/*%  * Non-standard, private type only.  *  * Prevent the creation of a NSEC chain before the last NSEC3 chain  * is removed.  This will normally only be set when the zone is  * transitioning from secure with NSEC3 chains to insecure.  *  * NSEC3PARAM records containing this flag should never be published,  * but if they are, they should be ignored by RFC 5155 compliant  * nameservers.  */
end_comment

begin_define
define|#
directive|define
name|DNS_NSEC3FLAG_NONSEC
value|0x10U
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GENERIC_NSEC3_50_H */
end_comment

end_unit

