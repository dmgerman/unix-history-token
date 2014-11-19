begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 by Internet Systems Consortium, Inc. ("ISC")  * Copyright (c) 1999 by Internet Software Consortium, Inc.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT  * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*  *	$Id: res_update.h,v 1.3 2005/04/27 04:56:15 sra Exp $  * $FreeBSD$  */
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

begin_comment
comment|/*! \file */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<arpa/nameser.h>
end_include

begin_include
include|#
directive|include
file|<resolv.h>
end_include

begin_comment
comment|/*%  * This RR-like structure is particular to UPDATE.  */
end_comment

begin_struct
struct|struct
name|ns_updrec
block|{
struct|struct
block|{
name|struct
name|ns_updrec
modifier|*
name|prev
decl_stmt|;
name|struct
name|ns_updrec
modifier|*
name|next
decl_stmt|;
block|}
name|r_link
struct|,
name|r_glink
struct|;
name|ns_sect
name|r_section
decl_stmt|;
comment|/*%< ZONE/PREREQUISITE/UPDATE */
name|char
modifier|*
name|r_dname
decl_stmt|;
comment|/*%< owner of the RR */
name|ns_class
name|r_class
decl_stmt|;
comment|/*%< class number */
name|ns_type
name|r_type
decl_stmt|;
comment|/*%< type number */
name|u_int32_t
name|r_ttl
decl_stmt|;
comment|/*%< time to live */
name|u_char
modifier|*
name|r_data
decl_stmt|;
comment|/*%< rdata fields as text string */
name|u_int
name|r_size
decl_stmt|;
comment|/*%< size of r_data field */
name|int
name|r_opcode
decl_stmt|;
comment|/*%< type of operation */
comment|/* following fields for private use by the resolver/server routines */
name|struct
name|databuf
modifier|*
name|r_dp
decl_stmt|;
comment|/*%< databuf to process */
name|struct
name|databuf
modifier|*
name|r_deldp
decl_stmt|;
comment|/*%< databuf's deleted/overwritten */
name|u_int
name|r_zone
decl_stmt|;
comment|/*%< zone number on server */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ns_updrec
name|ns_updrec
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|ns_updrec
modifier|*
name|head
decl_stmt|;
name|ns_updrec
modifier|*
name|tail
decl_stmt|;
block|}
name|ns_updque
typedef|;
end_typedef

begin_define
define|#
directive|define
name|res_mkupdate
value|__res_mkupdate
end_define

begin_define
define|#
directive|define
name|res_update
value|__res_update
end_define

begin_define
define|#
directive|define
name|res_mkupdrec
value|__res_mkupdrec
end_define

begin_define
define|#
directive|define
name|res_freeupdrec
value|__res_freeupdrec
end_define

begin_define
define|#
directive|define
name|res_nmkupdate
value|__res_nmkupdate
end_define

begin_define
define|#
directive|define
name|res_nupdate
value|__res_nupdate
end_define

begin_function_decl
name|int
name|res_mkupdate
parameter_list|(
name|ns_updrec
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_update
parameter_list|(
name|ns_updrec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ns_updrec
modifier|*
name|res_mkupdrec
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|res_freeupdrec
parameter_list|(
name|ns_updrec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_nmkupdate
parameter_list|(
name|res_state
parameter_list|,
name|ns_updrec
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_nupdate
parameter_list|(
name|res_state
parameter_list|,
name|ns_updrec
modifier|*
parameter_list|,
name|ns_tsig_key
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__RES_UPDATE_H*/
end_comment

begin_comment
comment|/*! \file */
end_comment

end_unit

