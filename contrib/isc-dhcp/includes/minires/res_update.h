begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 by Internet Software Consortium, Inc.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  *	$Id: res_update.h,v 1.2.2.1 2001/05/17 20:47:28 mellon Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RES_UPDATE_H
end_ifndef

begin_define
define|#
directive|define
name|__RES_UPDATE_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"arpa/nameser.h"
end_include

begin_include
include|#
directive|include
file|<isc-dhcp/list.h>
end_include

begin_comment
comment|/*  * This RR-like structure is particular to UPDATE.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ns_updrec
block|{
name|ISC_LINK
argument_list|(
argument|struct ns_updrec
argument_list|)
name|r_link
operator|,
name|r_glink
expr_stmt|;
name|ns_sect
name|r_section
decl_stmt|;
comment|/* ZONE/PREREQUISITE/UPDATE */
name|char
modifier|*
name|r_dname
decl_stmt|;
comment|/* owner of the RR */
name|ns_class
name|r_class
decl_stmt|;
comment|/* class number */
name|ns_type
name|r_type
decl_stmt|;
comment|/* type number */
name|u_int32_t
name|r_ttl
decl_stmt|;
comment|/* time to live */
specifier|const
name|unsigned
name|char
modifier|*
name|r_data
decl_stmt|;
comment|/* rdata fields as text string */
name|unsigned
name|char
modifier|*
name|r_data_ephem
decl_stmt|;
comment|/* pointer to freeable r_data */
name|unsigned
name|int
name|r_size
decl_stmt|;
comment|/* size of r_data field */
name|int
name|r_opcode
decl_stmt|;
comment|/* type of operation */
comment|/* following fields for private use by the resolver/server 		   routines */
name|struct
name|databuf
modifier|*
name|r_dp
decl_stmt|;
comment|/* databuf to process */
name|struct
name|databuf
modifier|*
name|r_deldp
decl_stmt|;
comment|/* databuf's deleted/overwritten */
name|unsigned
name|int
name|r_zone
decl_stmt|;
comment|/* zone number on server */
block|}
name|ns_updrec
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ISC_LIST
argument_list|(
argument|ns_updrec
argument_list|)
name|ns_updque
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__RES_UPDATE_H*/
end_comment

end_unit

