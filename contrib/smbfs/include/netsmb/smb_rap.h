begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001, Boris Popov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Boris Popov.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: smb_rap.h,v 1.3 2001/04/10 05:37:22 bp Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETSMB_SMB_RAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETSMB_SMB_RAP_H_
end_define

begin_struct
struct|struct
name|smb_rap
block|{
name|char
modifier|*
name|r_sparam
decl_stmt|;
name|char
modifier|*
name|r_nparam
decl_stmt|;
name|char
modifier|*
name|r_sdata
decl_stmt|;
name|char
modifier|*
name|r_ndata
decl_stmt|;
name|char
modifier|*
name|r_pbuf
decl_stmt|;
comment|/* rq parameters */
name|int
name|r_plen
decl_stmt|;
comment|/* rq param len */
name|char
modifier|*
name|r_npbuf
decl_stmt|;
name|char
modifier|*
name|r_dbuf
decl_stmt|;
comment|/* rq data */
name|int
name|r_dlen
decl_stmt|;
comment|/* rq data len */
name|char
modifier|*
name|r_ndbuf
decl_stmt|;
name|u_int32_t
name|r_result
decl_stmt|;
name|char
modifier|*
name|r_rcvbuf
decl_stmt|;
name|int
name|r_rcvbuflen
decl_stmt|;
name|int
name|r_entries
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|smb_share_info_1
block|{
name|char
name|shi1_netname
index|[
literal|13
index|]
decl_stmt|;
name|char
name|shi1_pad
decl_stmt|;
name|u_int16_t
name|shi1_type
decl_stmt|;
name|u_int32_t
name|shi1_remark
decl_stmt|;
comment|/* char * */
block|}
struct|;
end_struct

begin_function_decl
name|__BEGIN_DECLS
name|int
name|smb_rap_create
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|smb_rap
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smb_rap_done
parameter_list|(
name|struct
name|smb_rap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_rap_request
parameter_list|(
name|struct
name|smb_rap
modifier|*
parameter_list|,
name|struct
name|smb_ctx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_rap_setNparam
parameter_list|(
name|struct
name|smb_rap
modifier|*
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_rap_setPparam
parameter_list|(
name|struct
name|smb_rap
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_rap_error
parameter_list|(
name|struct
name|smb_rap
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_rap_NetShareEnum
parameter_list|(
name|struct
name|smb_ctx
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
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
comment|/* _NETSMB_SMB_RAP_H_ */
end_comment

end_unit

