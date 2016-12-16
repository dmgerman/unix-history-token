begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Emmanuel Vadot<manu@bidouilliste.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALLWINNER_PINCTRL_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALLWINNER_PINCTRL_H_
end_define

begin_define
define|#
directive|define
name|AW_MAX_FUNC_BY_PIN
value|8
end_define

begin_struct
struct|struct
name|allwinner_pins
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|uint8_t
name|port
decl_stmt|;
name|uint8_t
name|pin
decl_stmt|;
specifier|const
name|char
modifier|*
name|functions
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|eint_func
decl_stmt|;
name|uint8_t
name|eint_num
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|allwinner_padconf
block|{
name|uint32_t
name|npins
decl_stmt|;
specifier|const
name|struct
name|allwinner_pins
modifier|*
name|pins
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ALLWINNER_PINCTRL_H_ */
end_comment

end_unit

