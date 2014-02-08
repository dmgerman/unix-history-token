begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_function_decl
name|int
name|dmamux_configure
parameter_list|(
name|int
name|mux
parameter_list|,
name|int
name|source
parameter_list|,
name|int
name|channel
parameter_list|,
name|int
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|mux_num
block|{
name|MUX0
block|,
name|MUX1
block|,
name|MUX2
block|,
name|MUX3
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|mux_grp
block|{
name|MUXGRP0
block|,
comment|/* MUX[0,3] */
name|MUXGRP1
block|,
comment|/* MUX[1,2] */
block|}
enum|;
end_enum

begin_comment
comment|/* DMAMUX */
end_comment

begin_define
define|#
directive|define
name|MUX_READ1
parameter_list|(
name|_sc
parameter_list|,
name|_mux
parameter_list|,
name|_reg
parameter_list|)
define|\
value|bus_space_read_1(_sc->bst[_mux], _sc->bsh[_mux], _reg)
end_define

begin_define
define|#
directive|define
name|MUX_WRITE1
parameter_list|(
name|_sc
parameter_list|,
name|_mux
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|bus_space_write_1(_sc->bst[_mux], _sc->bsh[_mux], _reg, _val)
end_define

end_unit

