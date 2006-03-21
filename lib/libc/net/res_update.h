begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1983, 1987, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RES_UPDATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_RES_UPDATE_H_
end_define

begin_comment
comment|/*  * This RR-like structure is particular to UPDATE.  */
end_comment

begin_struct
struct|struct
name|ns_updrec
block|{
name|struct
name|ns_updrec
modifier|*
name|r_prev
decl_stmt|;
comment|/* prev record */
name|struct
name|ns_updrec
modifier|*
name|r_next
decl_stmt|;
comment|/* next record */
name|u_int8_t
name|r_section
decl_stmt|;
comment|/* ZONE/PREREQUISITE/UPDATE */
name|char
modifier|*
name|r_dname
decl_stmt|;
comment|/* owner of the RR */
name|u_int16_t
name|r_class
decl_stmt|;
comment|/* class number */
name|u_int16_t
name|r_type
decl_stmt|;
comment|/* type number */
name|u_int32_t
name|r_ttl
decl_stmt|;
comment|/* time to live */
name|u_char
modifier|*
name|r_data
decl_stmt|;
comment|/* rdata fields as text string */
name|u_int16_t
name|r_size
decl_stmt|;
comment|/* size of r_data field */
name|int
name|r_opcode
decl_stmt|;
comment|/* type of operation */
comment|/* following fields for private use by the resolver/server routines */
name|struct
name|ns_updrec
modifier|*
name|r_grpnext
decl_stmt|;
comment|/* next record when grouped */
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
name|u_int16_t
name|r_zone
decl_stmt|;
comment|/* zone number on server */
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

begin_define
define|#
directive|define
name|res_freeupdrec
value|__res_freeupdrec
end_define

begin_define
define|#
directive|define
name|res_mkupdate
value|__res_mkupdate
end_define

begin_define
define|#
directive|define
name|res_mkupdrec
value|__res_mkupdrec
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|res_update
value|__res_update
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|__BEGIN_DECLS
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
name|int
name|res_update
parameter_list|(
name|ns_updrec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RES_UPDATE_H_ */
end_comment

end_unit

