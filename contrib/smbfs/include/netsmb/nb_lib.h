begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000, Boris Popov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Boris Popov.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: nb_lib.h,v 1.2 2000/07/17 01:49:27 bp Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETSMB_NB_LIB_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETSMB_NB_LIB_H_
end_define

begin_comment
comment|/*  * Error codes  */
end_comment

begin_define
define|#
directive|define
name|NBERR_INVALIDFORMAT
value|0x0001
end_define

begin_define
define|#
directive|define
name|NBERR_SRVFAILURE
value|0x0002
end_define

begin_define
define|#
directive|define
name|NBERR_NAMENOTFOUND
value|0x0003
end_define

begin_define
define|#
directive|define
name|NBERR_IMP
value|0x0004
end_define

begin_define
define|#
directive|define
name|NBERR_REFUSED
value|0x0005
end_define

begin_define
define|#
directive|define
name|NBERR_ACTIVE
value|0x0006
end_define

begin_define
define|#
directive|define
name|NBERR_HOSTNOTFOUND
value|0x0101
end_define

begin_define
define|#
directive|define
name|NBERR_TOOMANYREDIRECTS
value|0x0102
end_define

begin_define
define|#
directive|define
name|NBERR_INVALIDRESPONSE
value|0x0103
end_define

begin_define
define|#
directive|define
name|NBERR_NAMETOOLONG
value|0x0104
end_define

begin_define
define|#
directive|define
name|NBERR_NOBCASTIFS
value|0x0105
end_define

begin_define
define|#
directive|define
name|NBERR_MAX
value|0x0106
end_define

begin_define
define|#
directive|define
name|NBERROR
parameter_list|(
name|e
parameter_list|)
value|((e) |  SMB_NB_ERROR)
end_define

begin_define
define|#
directive|define
name|NBCF_RESOLVED
value|0x0001
end_define

begin_comment
comment|/*  * nb environment  */
end_comment

begin_struct
struct|struct
name|nb_ctx
block|{
name|int
name|nb_flags
decl_stmt|;
name|int
name|nb_timo
decl_stmt|;
name|char
modifier|*
name|nb_scope
decl_stmt|;
comment|/* NetBIOS scope */
name|char
modifier|*
name|nb_nsname
decl_stmt|;
comment|/* name server */
name|struct
name|sockaddr_in
name|nb_ns
decl_stmt|;
comment|/* ip addr of name server */
name|struct
name|sockaddr_in
name|nb_lastns
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * resource record  */
end_comment

begin_struct
struct|struct
name|nbns_rr
block|{
name|u_char
modifier|*
name|rr_name
decl_stmt|;
comment|/* compressed NETBIOS name */
name|u_int16_t
name|rr_type
decl_stmt|;
name|u_int16_t
name|rr_class
decl_stmt|;
name|u_int32_t
name|rr_ttl
decl_stmt|;
name|u_int16_t
name|rr_rdlength
decl_stmt|;
name|u_char
modifier|*
name|rr_data
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NBRQF_BROADCAST
value|0x0001
end_define

begin_comment
comment|/*  * nbns request  */
end_comment

begin_struct
struct|struct
name|nbns_rq
block|{
name|int
name|nr_opcode
decl_stmt|;
name|int
name|nr_nmflags
decl_stmt|;
name|int
name|nr_rcode
decl_stmt|;
name|int
name|nr_qdcount
decl_stmt|;
name|int
name|nr_ancount
decl_stmt|;
name|int
name|nr_nscount
decl_stmt|;
name|int
name|nr_arcount
decl_stmt|;
name|struct
name|nb_name
modifier|*
name|nr_qdname
decl_stmt|;
name|u_int16_t
name|nr_qdtype
decl_stmt|;
name|u_int16_t
name|nr_qdclass
decl_stmt|;
name|struct
name|sockaddr_in
name|nr_dest
decl_stmt|;
comment|/* receiver of query */
name|struct
name|sockaddr_in
name|nr_sender
decl_stmt|;
comment|/* sender of response */
name|int
name|nr_rpnmflags
decl_stmt|;
name|int
name|nr_rprcode
decl_stmt|;
name|u_int16_t
name|nr_rpancount
decl_stmt|;
name|u_int16_t
name|nr_rpnscount
decl_stmt|;
name|u_int16_t
name|nr_rparcount
decl_stmt|;
name|u_int16_t
name|nr_trnid
decl_stmt|;
name|struct
name|nb_ctx
modifier|*
name|nr_nbd
decl_stmt|;
name|struct
name|mbdata
name|nr_rq
decl_stmt|;
name|struct
name|mbdata
name|nr_rp
decl_stmt|;
name|struct
name|nb_ifdesc
modifier|*
name|nr_if
decl_stmt|;
name|int
name|nr_flags
decl_stmt|;
name|int
name|nr_fd
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nb_ifdesc
block|{
name|int
name|id_flags
decl_stmt|;
name|struct
name|in_addr
name|id_addr
decl_stmt|;
name|struct
name|in_addr
name|id_mask
decl_stmt|;
name|char
name|id_name
index|[
literal|16
index|]
decl_stmt|;
comment|/* actually IFNAMSIZ */
name|struct
name|nb_ifdesc
modifier|*
name|id_next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_function_decl
name|__BEGIN_DECLS
name|int
name|nb_name_len
parameter_list|(
name|struct
name|nb_name
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nb_name_encode
parameter_list|(
name|struct
name|nb_name
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nb_encname_len
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nb_snballoc
parameter_list|(
name|int
name|namelen
parameter_list|,
name|struct
name|sockaddr_nb
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nb_snbfree
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nb_sockaddr
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|nb_name
modifier|*
parameter_list|,
name|struct
name|sockaddr_nb
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nb_resolvehost_in
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nbns_resolvename
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|nb_ctx
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nb_getlocalname
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nb_enum_if
parameter_list|(
name|struct
name|nb_ifdesc
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|nb_strerror
parameter_list|(
name|int
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nb_ctx_create
parameter_list|(
name|struct
name|nb_ctx
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nb_ctx_done
parameter_list|(
name|struct
name|nb_ctx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nb_ctx_setns
parameter_list|(
name|struct
name|nb_ctx
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nb_ctx_setscope
parameter_list|(
name|struct
name|nb_ctx
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nb_ctx_resolve
parameter_list|(
name|struct
name|nb_ctx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nb_ctx_readrcsection
parameter_list|(
name|struct
name|rcfile
modifier|*
parameter_list|,
name|struct
name|nb_ctx
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
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
comment|/* !_NETSMB_NB_LIB_H_ */
end_comment

end_unit

