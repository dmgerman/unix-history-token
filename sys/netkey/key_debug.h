begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: key_debug.h,v 1.10 2001/08/05 08:37:52 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETKEY_KEY_DEBUG_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETKEY_KEY_DEBUG_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* debug flags */
end_comment

begin_define
define|#
directive|define
name|KEYDEBUG_STAMP
value|0x00000001
end_define

begin_comment
comment|/* path */
end_comment

begin_define
define|#
directive|define
name|KEYDEBUG_DATA
value|0x00000002
end_define

begin_comment
comment|/* data */
end_comment

begin_define
define|#
directive|define
name|KEYDEBUG_DUMP
value|0x00000004
end_define

begin_comment
comment|/* dump */
end_comment

begin_define
define|#
directive|define
name|KEYDEBUG_KEY
value|0x00000010
end_define

begin_comment
comment|/* key processing */
end_comment

begin_define
define|#
directive|define
name|KEYDEBUG_ALG
value|0x00000020
end_define

begin_comment
comment|/* ciph& auth algorithm */
end_comment

begin_define
define|#
directive|define
name|KEYDEBUG_IPSEC
value|0x00000040
end_define

begin_comment
comment|/* ipsec processing */
end_comment

begin_define
define|#
directive|define
name|KEYDEBUG_KEY_STAMP
value|(KEYDEBUG_KEY | KEYDEBUG_STAMP)
end_define

begin_define
define|#
directive|define
name|KEYDEBUG_KEY_DATA
value|(KEYDEBUG_KEY | KEYDEBUG_DATA)
end_define

begin_define
define|#
directive|define
name|KEYDEBUG_KEY_DUMP
value|(KEYDEBUG_KEY | KEYDEBUG_DUMP)
end_define

begin_define
define|#
directive|define
name|KEYDEBUG_ALG_STAMP
value|(KEYDEBUG_ALG | KEYDEBUG_STAMP)
end_define

begin_define
define|#
directive|define
name|KEYDEBUG_ALG_DATA
value|(KEYDEBUG_ALG | KEYDEBUG_DATA)
end_define

begin_define
define|#
directive|define
name|KEYDEBUG_ALG_DUMP
value|(KEYDEBUG_ALG | KEYDEBUG_DUMP)
end_define

begin_define
define|#
directive|define
name|KEYDEBUG_IPSEC_STAMP
value|(KEYDEBUG_IPSEC | KEYDEBUG_STAMP)
end_define

begin_define
define|#
directive|define
name|KEYDEBUG_IPSEC_DATA
value|(KEYDEBUG_IPSEC | KEYDEBUG_DATA)
end_define

begin_define
define|#
directive|define
name|KEYDEBUG_IPSEC_DUMP
value|(KEYDEBUG_IPSEC | KEYDEBUG_DUMP)
end_define

begin_define
define|#
directive|define
name|KEYDEBUG
parameter_list|(
name|lev
parameter_list|,
name|arg
parameter_list|)
define|\
value|do { if ((key_debug_level& (lev)) == (lev)) { arg; } } while (0)
end_define

begin_decl_stmt
specifier|extern
name|u_int32_t
name|key_debug_level
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_KERNEL*/
end_comment

begin_struct_decl
struct_decl|struct
name|sadb_msg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sadb_ext
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|kdebug_sadb
parameter_list|(
name|struct
name|sadb_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|kdebug_sadb_x_policy
parameter_list|(
name|struct
name|sadb_ext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|secpolicy
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|secpolicyindex
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|secasindex
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|secasvar
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|secreplay
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|kdebug_secpolicy
parameter_list|(
name|struct
name|secpolicy
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|kdebug_secpolicyindex
parameter_list|(
name|struct
name|secpolicyindex
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|kdebug_secasindex
parameter_list|(
name|struct
name|secasindex
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|kdebug_secasv
parameter_list|(
name|struct
name|secasvar
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|kdebug_mbufhdr
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|kdebug_mbuf
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_KERNEL*/
end_comment

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|kdebug_sockaddr
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ipsec_hexdump
parameter_list|(
name|caddr_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ipsec_bindump
parameter_list|(
name|caddr_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETKEY_KEY_DEBUG_H_ */
end_comment

end_unit

