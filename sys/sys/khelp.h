begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Lawrence Stewart<lstewart@freebsd.org>  * Copyright (c) 2010 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Lawrence Stewart while studying at the Centre  * for Advanced Internet Architectures, Swinburne University of Technology, made  * possible in part by grants from the FreeBSD Foundation and Cisco University  * Research Program Fund at Community Foundation Silicon Valley.  *  * Portions of this software were developed at the Centre for Advanced  * Internet Architectures, Swinburne University of Technology, Melbourne,  * Australia by Lawrence Stewart under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * A KPI for managing kernel helper modules which perform useful functionality  * within the kernel. Originally released as part of the NewTCP research project  * at Swinburne University of Technology's Centre for Advanced Internet  * Architectures, Melbourne, Australia, which was made possible in part by a  * grant from the Cisco University Research Program Fund at Community Foundation  * Silicon Valley. More details are available at:  *   http://caia.swin.edu.au/urp/newtcp/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_KHELP_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_KHELP_H_
end_define

begin_struct_decl
struct_decl|struct
name|helper
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|hookinfo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|osd
struct_decl|;
end_struct_decl

begin_comment
comment|/* Helper classes. */
end_comment

begin_define
define|#
directive|define
name|HELPER_CLASS_TCP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HELPER_CLASS_SOCKET
value|0x00000002
end_define

begin_comment
comment|/* Public KPI functions. */
end_comment

begin_function_decl
name|int
name|khelp_register_helper
parameter_list|(
name|struct
name|helper
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|khelp_deregister_helper
parameter_list|(
name|struct
name|helper
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|khelp_init_osd
parameter_list|(
name|uint32_t
name|classes
parameter_list|,
name|struct
name|osd
modifier|*
name|hosd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|khelp_destroy_osd
parameter_list|(
name|struct
name|osd
modifier|*
name|hosd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|khelp_get_osd
parameter_list|(
name|struct
name|osd
modifier|*
name|hosd
parameter_list|,
name|int32_t
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|khelp_get_id
parameter_list|(
name|char
modifier|*
name|hname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|khelp_add_hhook
parameter_list|(
name|struct
name|hookinfo
modifier|*
name|hki
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|khelp_remove_hhook
parameter_list|(
name|struct
name|hookinfo
modifier|*
name|hki
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_KHELP_H_ */
end_comment

end_unit

