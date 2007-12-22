begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Bruce D. Evans  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_typedef
typedef|typedef
name|u_char
specifier|volatile
modifier|*
name|cy_addr
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|devclass_t
name|cy_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|cy_driver_name
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
modifier|*
name|cyattach_common
parameter_list|(
name|cy_addr
name|cy_iobase
parameter_list|,
name|int
name|cy_align
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|driver_filter_t
name|cyintr
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|cy_units
parameter_list|(
name|cy_addr
name|cy_iobase
parameter_list|,
name|int
name|cy_align
parameter_list|)
function_decl|;
end_function_decl

end_unit

