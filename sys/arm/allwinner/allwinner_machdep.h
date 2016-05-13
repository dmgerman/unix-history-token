begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Emmanuel Vadot<manu@bidouilliste.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AW_MACHDEP_H
end_ifndef

begin_define
define|#
directive|define
name|AW_MACHDEP_H
end_define

begin_define
define|#
directive|define
name|ALLWINNERSOC_A10
value|0x10000000
end_define

begin_define
define|#
directive|define
name|ALLWINNERSOC_A13
value|0x13000000
end_define

begin_define
define|#
directive|define
name|ALLWINNERSOC_A10S
value|0x10000001
end_define

begin_define
define|#
directive|define
name|ALLWINNERSOC_A20
value|0x20000000
end_define

begin_define
define|#
directive|define
name|ALLWINNERSOC_H3
value|0x30000000
end_define

begin_define
define|#
directive|define
name|ALLWINNERSOC_A31
value|0x31000000
end_define

begin_define
define|#
directive|define
name|ALLWINNERSOC_A31S
value|0x31000001
end_define

begin_define
define|#
directive|define
name|ALLWINNERSOC_A83T
value|0x83000000
end_define

begin_define
define|#
directive|define
name|ALLWINNERSOC_SUN4I
value|0x40000000
end_define

begin_define
define|#
directive|define
name|ALLWINNERSOC_SUN5I
value|0x50000000
end_define

begin_define
define|#
directive|define
name|ALLWINNERSOC_SUN6I
value|0x60000000
end_define

begin_define
define|#
directive|define
name|ALLWINNERSOC_SUN7I
value|0x70000000
end_define

begin_define
define|#
directive|define
name|ALLWINNERSOC_SUN8I
value|0x80000000
end_define

begin_function_decl
name|u_int
name|allwinner_soc_type
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|allwinner_soc_family
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AW_MACHDEP_H */
end_comment

end_unit

