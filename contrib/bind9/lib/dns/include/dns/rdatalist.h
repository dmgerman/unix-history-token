begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2008  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: rdatalist.h,v 1.22 2008-04-03 06:09:05 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_RDATALIST_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_RDATALIST_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*! \file dns/rdatalist.h  * \brief  * A DNS rdatalist is a list of rdata of a common type and class.  *  * MP:  *\li	Clients of this module must impose any required synchronization.  *  * Reliability:  *\li	No anticipated impact.  *  * Resources:  *\li	TBS  *  * Security:  *\li	No anticipated impact.  *  * Standards:  *\li	None.  */
end_comment

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

begin_comment
comment|/*%  * Clients may use this type directly.  */
end_comment

begin_struct
struct|struct
name|dns_rdatalist
block|{
name|dns_rdataclass_t
name|rdclass
decl_stmt|;
name|dns_rdatatype_t
name|type
decl_stmt|;
name|dns_rdatatype_t
name|covers
decl_stmt|;
name|dns_ttl_t
name|ttl
decl_stmt|;
name|ISC_LIST
argument_list|(
argument|dns_rdata_t
argument_list|)
name|rdata
expr_stmt|;
name|ISC_LINK
argument_list|(
argument|dns_rdatalist_t
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|void
name|dns_rdatalist_init
parameter_list|(
name|dns_rdatalist_t
modifier|*
name|rdatalist
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Initialize rdatalist.  *  * Ensures:  *\li	All fields of rdatalist have been initialized to their default  *	values.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdatalist_tordataset
parameter_list|(
name|dns_rdatalist_t
modifier|*
name|rdatalist
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Make 'rdataset' refer to the rdata in 'rdatalist'.  *  * Note:  *\li	The caller must ensure that 'rdatalist' remains valid and unchanged  *	while 'rdataset' is associated with it.  *  * Requires:  *  *\li	'rdatalist' is a valid rdatalist.  *  *\li	'rdataset' is a valid rdataset that is not currently associated with  *	any rdata.  *  * Ensures,  *	on success,  *  *\li		'rdataset' is associated with the rdata in rdatalist.  *  * Returns:  *\li	#ISC_R_SUCCESS  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdatalist_fromrdataset
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdatalist_t
modifier|*
modifier|*
name|rdatalist
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Point 'rdatalist' to the rdatalist in 'rdataset'.  *  * Requires:  *  *\li	'rdatalist' is a pointer to a NULL dns_rdatalist_t pointer.  *  *\li	'rdataset' is a valid rdataset associated with an rdatalist.  *  * Ensures,  *	on success,  *  *\li		'rdatalist' is pointed to the rdatalist in rdataset.  *  * Returns:  *\li	#ISC_R_SUCCESS  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_RDATALIST_H */
end_comment

end_unit

