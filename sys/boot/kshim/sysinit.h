begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2013 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYSINIT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYSINIT_H_
end_define

begin_struct
struct|struct
name|sysinit_data
block|{
name|uint8_t
name|b_keyword_name
index|[
literal|64
index|]
decl_stmt|;
name|uint8_t
name|b_debug_info
index|[
literal|128
index|]
decl_stmt|;
name|uint8_t
name|b_global_type
index|[
literal|128
index|]
decl_stmt|;
name|uint8_t
name|b_global_name
index|[
literal|128
index|]
decl_stmt|;
name|uint8_t
name|b_file_name
index|[
literal|256
index|]
decl_stmt|;
name|uint32_t
name|dw_endian32
decl_stmt|;
name|uint32_t
name|dw_msb_value
decl_stmt|;
comment|/* must be non-zero, else entry is skipped */
name|uint32_t
name|dw_lsb_value
decl_stmt|;
name|uint32_t
name|dw_file_line
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|SYSINIT_ENTRY
parameter_list|(
name|uniq
parameter_list|,
name|keyword
parameter_list|,
name|msb
parameter_list|,
name|lsb
parameter_list|,
name|g_type
parameter_list|,
name|g_name
parameter_list|,
name|debug
parameter_list|)
define|\
value|static const struct sysinit_data sysinit_##uniq			\ 	__attribute__((__section__(".debug.sysinit"),			\ 		__used__, __aligned__(1))) = {				\ 	.b_keyword_name = { keyword },					\ 	.b_debug_info = { debug },					\ 	.b_global_type = { g_type },					\ 	.b_global_name = { g_name },					\ 	.b_file_name = { __FILE__ },					\ 	.dw_endian32 = 0x76543210U,					\ 	.dw_msb_value = (msb),						\ 	.dw_lsb_value = (lsb),						\ 	.dw_file_line = __LINE__					\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYSINIT_H_ */
end_comment

end_unit

