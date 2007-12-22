begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  *	All rights reserved.  *  * Author: Harti Brandt<harti@freebsd.org>  *  * Redistribution of this software and documentation and use in source and  * binary forms, with or without modification, are permitted provided that  * the following conditions are met:  *  * 1. Redistributions of source code or documentation must retain the above  *    copyright notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE AND DOCUMENTATION IS PROVIDED BY FRAUNHOFER FOKUS  * AND ITS CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND  * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  * FRAUNHOFER FOKUS OR ITS CONTRIBUTORS  BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  * In-kernel UNI stack message functions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_ATM_NGATMBASE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_ATM_NGATMBASE_H_
end_define

begin_comment
comment|/* forward declarations */
end_comment

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uni_msg
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|uni_msg_pack_mbuf
parameter_list|(
name|struct
name|uni_msg
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|NGATM_DEBUG
end_ifdef

begin_function_decl
name|struct
name|uni_msg
modifier|*
name|_uni_msg_alloc
parameter_list|(
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|uni_msg
modifier|*
name|_uni_msg_build
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_uni_msg_destroy
parameter_list|(
name|struct
name|uni_msg
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

begin_function_decl
name|int
name|_uni_msg_unpack_mbuf
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|uni_msg
modifier|*
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

begin_define
define|#
directive|define
name|uni_msg_alloc
parameter_list|(
name|S
parameter_list|)
value|_uni_msg_alloc((S), __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|uni_msg_build
parameter_list|(
name|P
modifier|...
parameter_list|)
value|_uni_msg_build(__FILE__, __LINE__, P)
end_define

begin_define
define|#
directive|define
name|uni_msg_destroy
parameter_list|(
name|M
parameter_list|)
value|_uni_msg_destroy((M), __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|uni_msg_unpack_mbuf
parameter_list|(
name|M
parameter_list|,
name|PP
parameter_list|)
define|\
value|_uni_msg_unpack_mbuf((M), (PP), __FILE__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !NGATM_DEBUG */
end_comment

begin_function_decl
name|struct
name|uni_msg
modifier|*
name|uni_msg_alloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|uni_msg
modifier|*
name|uni_msg_build
parameter_list|(
name|void
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uni_msg_destroy
parameter_list|(
name|struct
name|uni_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uni_msg_unpack_mbuf
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|uni_msg
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

