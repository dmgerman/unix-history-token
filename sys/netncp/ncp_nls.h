begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999, Boris Popov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Boris Popov.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNCP_NCP_NLS_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNCP_NCP_NLS_H_
end_define

begin_comment
comment|/* options for handle path& caseopt in mount struct */
end_comment

begin_define
define|#
directive|define
name|NWHP_HDB
value|0x01
end_define

begin_comment
comment|/* have dir base */
end_comment

begin_define
define|#
directive|define
name|NWHP_UPPER
value|0x02
end_define

begin_comment
comment|/* local names has upper case */
end_comment

begin_define
define|#
directive|define
name|NWHP_LOWER
value|0x04
end_define

begin_comment
comment|/* --"-- lower case */
end_comment

begin_define
define|#
directive|define
name|NWHP_DOS
value|0x08
end_define

begin_comment
comment|/* using dos name space */
end_comment

begin_define
define|#
directive|define
name|NWHP_NLS
value|0x10
end_define

begin_comment
comment|/* do name translation via tables, any nmspc */
end_comment

begin_define
define|#
directive|define
name|NWHP_NOSTRICT
value|0x20
end_define

begin_comment
comment|/* pretend to be a case insensitive */
end_comment

begin_struct
struct|struct
name|ncp_nlstables
block|{
name|u_char
modifier|*
name|to_lower
decl_stmt|;
comment|/* local charset to lower case */
name|u_char
modifier|*
name|to_upper
decl_stmt|;
comment|/* local charset to upper case */
name|u_char
modifier|*
name|n2u
decl_stmt|;
comment|/* NetWare to Unix */
name|u_char
modifier|*
name|u2n
decl_stmt|;
name|int
name|opt
decl_stmt|;
comment|/* may depend on context */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_comment
comment|/*  * NLS, supported character conversion schemes.  * NCP_NLS_UNIXCHARSET_NETWARECHARSET  */
end_comment

begin_define
define|#
directive|define
name|NCP_NLS_AS_IS
value|1
end_define

begin_define
define|#
directive|define
name|NCP_NLS_AS_IS_NAME
value|"asis"
end_define

begin_define
define|#
directive|define
name|NCP_NLS_KOI_866
value|2
end_define

begin_define
define|#
directive|define
name|NCP_NLS_KOI_866_NAME
value|"koi2cp866"
end_define

begin_decl_stmt
specifier|extern
name|struct
name|ncp_nlstables
name|ncp_nls
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* active nls */
end_comment

begin_function_decl
name|__BEGIN_DECLS
name|int
name|ncp_nls_setrecode
parameter_list|(
name|int
name|scheme
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_nls_setrecodebyname
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_nls_setlocale
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ncp_nls_str_n2u
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ncp_nls_str_u2n
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ncp_nls_mem_n2u
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ncp_nls_mem_u2n
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|__END_DECLS
else|#
directive|else
comment|/* !_KERNEL */
specifier|extern
expr|struct
name|ncp_nlstables
name|ncp_defnls
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|ncp_str_upper
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncp_str_lower
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncp_pathcopy
parameter_list|(
name|char
modifier|*
name|src
parameter_list|,
name|char
modifier|*
name|dst
parameter_list|,
name|int
name|len
parameter_list|,
name|struct
name|ncp_nlstables
modifier|*
name|nt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_pathcheck
parameter_list|(
name|char
modifier|*
name|s
parameter_list|,
name|int
name|len
parameter_list|,
name|struct
name|ncp_nlstables
modifier|*
name|nt
parameter_list|,
name|int
name|strict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncp_path2unix
parameter_list|(
name|char
modifier|*
name|src
parameter_list|,
name|char
modifier|*
name|dst
parameter_list|,
name|int
name|len
parameter_list|,
name|struct
name|ncp_nlstables
modifier|*
name|nt
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NCP_NCP_NLS_H_ */
end_comment

end_unit

