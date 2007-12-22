begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* OPENBSD BASED ON : include/netdb.h */
end_comment

begin_comment
comment|/* $OpenBSD: getrrsetbyname.c,v 1.4 2001/08/16 18:16:43 ho Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 Jakob Schlyter. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT   * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Portions Copyright (c) 1999-2001 Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM  * DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL  * INTERNET SOFTWARE CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING  * FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,  * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION  * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GETRRSETBYNAME_H
end_ifndef

begin_define
define|#
directive|define
name|_GETRRSETBYNAME_H
end_define

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETRRSETBYNAME
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<arpa/nameser.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<resolv.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HFIXEDSZ
end_ifndef

begin_define
define|#
directive|define
name|HFIXEDSZ
value|12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_SIG
end_ifndef

begin_define
define|#
directive|define
name|T_SIG
value|24
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Flags for getrrsetbyname()  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RRSET_VALIDATED
end_ifndef

begin_define
define|#
directive|define
name|RRSET_VALIDATED
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Return codes for getrrsetbyname()  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ERRSET_SUCCESS
end_ifndef

begin_define
define|#
directive|define
name|ERRSET_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|ERRSET_NOMEMORY
value|1
end_define

begin_define
define|#
directive|define
name|ERRSET_FAIL
value|2
end_define

begin_define
define|#
directive|define
name|ERRSET_INVAL
value|3
end_define

begin_define
define|#
directive|define
name|ERRSET_NONAME
value|4
end_define

begin_define
define|#
directive|define
name|ERRSET_NODATA
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|rdatainfo
block|{
name|unsigned
name|int
name|rdi_length
decl_stmt|;
comment|/* length of data */
name|unsigned
name|char
modifier|*
name|rdi_data
decl_stmt|;
comment|/* record data */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rrsetinfo
block|{
name|unsigned
name|int
name|rri_flags
decl_stmt|;
comment|/* RRSET_VALIDATED ... */
name|unsigned
name|int
name|rri_rdclass
decl_stmt|;
comment|/* class number */
name|unsigned
name|int
name|rri_rdtype
decl_stmt|;
comment|/* RR type number */
name|unsigned
name|int
name|rri_ttl
decl_stmt|;
comment|/* time to live */
name|unsigned
name|int
name|rri_nrdatas
decl_stmt|;
comment|/* size of rdatas array */
name|unsigned
name|int
name|rri_nsigs
decl_stmt|;
comment|/* size of sigs array */
name|char
modifier|*
name|rri_name
decl_stmt|;
comment|/* canonical name */
name|struct
name|rdatainfo
modifier|*
name|rri_rdatas
decl_stmt|;
comment|/* individual records */
name|struct
name|rdatainfo
modifier|*
name|rri_sigs
decl_stmt|;
comment|/* individual signatures */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|getrrsetbyname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|struct
name|rrsetinfo
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freerrset
parameter_list|(
name|struct
name|rrsetinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(HAVE_GETRRSETBYNAME) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GETRRSETBYNAME_H */
end_comment

end_unit

