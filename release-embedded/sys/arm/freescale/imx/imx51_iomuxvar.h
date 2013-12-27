begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012, 2013 The FreeBSD Foundation  * All rights reserved.  *  * Portions of this software were developed by Oleksandr Rybalko  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1.	Redistributions of source code must retain the above copyright  *	notice, this list of conditions and the following disclaimer.  * 2.	Redistributions in binary form must reproduce the above copyright  *	notice, this list of conditions and the following disclaimer in the  *	documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* iomux utility functions */
end_comment

begin_struct
struct|struct
name|iomux_conf
block|{
name|u_int
name|pin
decl_stmt|;
define|#
directive|define
name|IOMUX_CONF_EOT
value|((u_int)(-1))
name|u_short
name|mux
decl_stmt|;
name|u_short
name|pad
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|iomux_set_function
parameter_list|(
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iomux_set_pad
parameter_list|(
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_function_decl
name|void
name|iomux_set_input
parameter_list|(
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|iomux_mux_config
parameter_list|(
specifier|const
name|struct
name|iomux_conf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

