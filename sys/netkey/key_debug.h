begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: key_debug.h,v 1.7 2000/07/04 04:08:16 itojun Exp $	*/
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
name|defined
argument_list|(
name|IPSEC_DEBUG
argument_list|)
operator|)
end_if

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
value|if ((key_debug_level& (lev)) == (lev)) { arg; }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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

begin_decl_stmt
specifier|extern
name|void
name|kdebug_sadb
name|__P
argument_list|(
operator|(
expr|struct
name|sadb_msg
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|kdebug_sadb_x_policy
name|__P
argument_list|(
operator|(
expr|struct
name|sadb_ext
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|void
name|kdebug_secpolicy
name|__P
argument_list|(
operator|(
expr|struct
name|secpolicy
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|kdebug_secpolicyindex
name|__P
argument_list|(
operator|(
expr|struct
name|secpolicyindex
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|kdebug_secasindex
name|__P
argument_list|(
operator|(
expr|struct
name|secasindex
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|kdebug_secasv
name|__P
argument_list|(
operator|(
expr|struct
name|secasvar
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|kdebug_mbufhdr
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|kdebug_mbuf
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
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
name|sockaddr
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|void
name|kdebug_sockaddr
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipsec_hexdump
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipsec_bindump
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KEYDEBUG
parameter_list|(
name|lev
parameter_list|,
name|arg
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!defined(_KERNEL) || (defined(_KERNEL)&& defined(IPSEC_DEBUG))*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETKEY_KEY_DEBUG_H_ */
end_comment

end_unit

