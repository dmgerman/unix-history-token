begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003-2011 Netlogic Microsystems (Netlogic). All rights  * reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *   * THIS SOFTWARE IS PROVIDED BY Netlogic Microsystems ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NETLOGIC OR CONTRIBUTORS BE   * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * NETLOGIC_BSD  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NLM_MSGRING_H
end_ifndef

begin_define
define|#
directive|define
name|_NLM_MSGRING_H
end_define

begin_define
define|#
directive|define
name|CMS_DEFAULT_CREDIT
value|50
end_define

begin_comment
comment|/*  * packets are sent to VC 0 of a thread  * freebacks are sent to VC 3 of a thread  */
end_comment

begin_define
define|#
directive|define
name|XLPGE_RX_VC
value|0
end_define

begin_define
define|#
directive|define
name|XLPGE_FB_VC
value|3
end_define

begin_decl_stmt
specifier|extern
name|uint32_t
name|xlp_msg_thread_mask
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|nlm_fmn_msg
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|msgring_handler
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|nlm_fmn_msg
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|register_msgring_handler
parameter_list|(
name|int
name|startb
parameter_list|,
name|int
name|endb
parameter_list|,
name|msgring_handler
name|action
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xlp_handle_msg_vc
parameter_list|(
name|u_int
name|vcmask
parameter_list|,
name|int
name|max_msgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xlp_msgring_cpu_init
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xlp_cms_enable_intr
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
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
comment|/* _NLM_MSGRING_H */
end_comment

end_unit

