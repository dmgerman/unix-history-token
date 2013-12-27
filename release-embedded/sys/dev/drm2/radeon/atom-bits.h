begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008 Advanced Micro Devices, Inc.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Author: Stanislaw Skowronek  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATOM_BITS_H
end_ifndef

begin_define
define|#
directive|define
name|ATOM_BITS_H
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
specifier|inline
name|uint8_t
name|get_u8
parameter_list|(
name|void
modifier|*
name|bios
parameter_list|,
name|int
name|ptr
parameter_list|)
block|{
return|return
operator|(
operator|(
name|unsigned
name|char
operator|*
operator|)
name|bios
operator|)
index|[
name|ptr
index|]
return|;
block|}
end_function

begin_define
define|#
directive|define
name|U8
parameter_list|(
name|ptr
parameter_list|)
value|get_u8(ctx->ctx->bios, (ptr))
end_define

begin_define
define|#
directive|define
name|CU8
parameter_list|(
name|ptr
parameter_list|)
value|get_u8(ctx->bios, (ptr))
end_define

begin_function
specifier|static
specifier|inline
name|uint16_t
name|get_u16
parameter_list|(
name|void
modifier|*
name|bios
parameter_list|,
name|int
name|ptr
parameter_list|)
block|{
return|return
name|get_u8
argument_list|(
name|bios
argument_list|,
name|ptr
argument_list|)
operator||
operator|(
operator|(
operator|(
name|uint16_t
operator|)
name|get_u8
argument_list|(
name|bios
argument_list|,
name|ptr
operator|+
literal|1
argument_list|)
operator|)
operator|<<
literal|8
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|U16
parameter_list|(
name|ptr
parameter_list|)
value|get_u16(ctx->ctx->bios, (ptr))
end_define

begin_define
define|#
directive|define
name|CU16
parameter_list|(
name|ptr
parameter_list|)
value|get_u16(ctx->bios, (ptr))
end_define

begin_function
specifier|static
specifier|inline
name|uint32_t
name|get_u32
parameter_list|(
name|void
modifier|*
name|bios
parameter_list|,
name|int
name|ptr
parameter_list|)
block|{
return|return
name|get_u16
argument_list|(
name|bios
argument_list|,
name|ptr
argument_list|)
operator||
operator|(
operator|(
operator|(
name|uint32_t
operator|)
name|get_u16
argument_list|(
name|bios
argument_list|,
name|ptr
operator|+
literal|2
argument_list|)
operator|)
operator|<<
literal|16
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|U32
parameter_list|(
name|ptr
parameter_list|)
value|get_u32(ctx->ctx->bios, (ptr))
end_define

begin_define
define|#
directive|define
name|CU32
parameter_list|(
name|ptr
parameter_list|)
value|get_u32(ctx->bios, (ptr))
end_define

begin_define
define|#
directive|define
name|CSTR
parameter_list|(
name|ptr
parameter_list|)
value|(((char *)(ctx->bios))+(ptr))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

