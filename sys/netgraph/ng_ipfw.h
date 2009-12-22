begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2005, Gleb Smirnoff<glebius@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|NG_IPFW_NODE_TYPE
value|"ipfw"
end_define

begin_define
define|#
directive|define
name|NGM_IPFW_COOKIE
value|1105988990
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_typedef
typedef|typedef
name|int
name|ng_ipfw_input_t
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ip_fw_args
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|ng_ipfw_input_t
modifier|*
name|ng_ipfw_input_p
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NG_IPFW_LOADED
value|(ng_ipfw_input_p != NULL)
end_define

begin_struct
struct|struct
name|ng_ipfw_tag
block|{
name|struct
name|m_tag
name|mt
decl_stmt|;
comment|/* tag header */
name|uint32_t
name|slot
decl_stmt|;
comment|/* slot for next rule */
name|uint32_t
name|rulenum
decl_stmt|;
comment|/* matching rule number */
name|uint32_t
name|rule_id
decl_stmt|;
comment|/* matching rule id */
name|uint32_t
name|chain_id
decl_stmt|;
comment|/* ruleset id */
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
comment|/* interface, for ip_output */
name|int
name|dir
decl_stmt|;
define|#
directive|define
name|NG_IPFW_OUT
value|0
define|#
directive|define
name|NG_IPFW_IN
value|1
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TAGSIZ
value|(sizeof(struct ng_ipfw_tag) - sizeof(struct m_tag))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

end_unit

