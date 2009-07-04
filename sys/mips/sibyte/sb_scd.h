begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Neelkanth Natu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SB_SCD_H_
end_ifndef

begin_define
define|#
directive|define
name|_SB_SCD_H_
end_define

begin_define
define|#
directive|define
name|NUM_INTSRC
value|64
end_define

begin_comment
comment|/* total number of interrupt sources */
end_comment

begin_function_decl
name|uint64_t
name|sb_cpu_speed
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sb_system_reset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sb_route_intsrc
parameter_list|(
name|int
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sb_enable_intsrc
parameter_list|(
name|int
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sb_disable_intsrc
parameter_list|(
name|int
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|sb_read_intsrc_mask
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sb_read_intmap
parameter_list|(
name|int
name|intsrc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sb_write_intmap
parameter_list|(
name|int
name|intsrc
parameter_list|,
name|int
name|intrnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|sb_read_syscfg
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sb_write_syscfg
parameter_list|(
name|uint64_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SB_SCD_H_ */
end_comment

end_unit

