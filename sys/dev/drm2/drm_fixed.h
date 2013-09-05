begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2009 Red Hat Inc.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors: Dave Airlie  */
end_comment

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

begin_ifndef
ifndef|#
directive|ifndef
name|DRM_FIXED_H
end_ifndef

begin_define
define|#
directive|define
name|DRM_FIXED_H
end_define

begin_typedef
typedef|typedef
union|union
name|dfixed
block|{
name|u32
name|full
decl_stmt|;
block|}
name|fixed20_12
typedef|;
end_typedef

begin_define
define|#
directive|define
name|dfixed_const
parameter_list|(
name|A
parameter_list|)
value|(u32)(((A)<< 12))
end_define

begin_comment
comment|/*  + ((B + 0.000122)*4096)) */
end_comment

begin_define
define|#
directive|define
name|dfixed_const_half
parameter_list|(
name|A
parameter_list|)
value|(u32)(((A)<< 12) + 2048)
end_define

begin_define
define|#
directive|define
name|dfixed_const_666
parameter_list|(
name|A
parameter_list|)
value|(u32)(((A)<< 12) + 2731)
end_define

begin_define
define|#
directive|define
name|dfixed_const_8
parameter_list|(
name|A
parameter_list|)
value|(u32)(((A)<< 12) + 3277)
end_define

begin_define
define|#
directive|define
name|dfixed_mul
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|((u64)((u64)(A).full * (B).full + 2048)>> 12)
end_define

begin_define
define|#
directive|define
name|dfixed_init
parameter_list|(
name|A
parameter_list|)
value|{ .full = dfixed_const((A)) }
end_define

begin_define
define|#
directive|define
name|dfixed_init_half
parameter_list|(
name|A
parameter_list|)
value|{ .full = dfixed_const_half((A)) }
end_define

begin_define
define|#
directive|define
name|dfixed_trunc
parameter_list|(
name|A
parameter_list|)
value|((A).full>> 12)
end_define

begin_define
define|#
directive|define
name|dfixed_frac
parameter_list|(
name|A
parameter_list|)
value|((A).full& ((1<< 12) - 1))
end_define

begin_function
specifier|static
specifier|inline
name|u32
name|dfixed_floor
parameter_list|(
name|fixed20_12
name|A
parameter_list|)
block|{
name|u32
name|non_frac
init|=
name|dfixed_trunc
argument_list|(
name|A
argument_list|)
decl_stmt|;
return|return
name|dfixed_const
argument_list|(
name|non_frac
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|u32
name|dfixed_ceil
parameter_list|(
name|fixed20_12
name|A
parameter_list|)
block|{
name|u32
name|non_frac
init|=
name|dfixed_trunc
argument_list|(
name|A
argument_list|)
decl_stmt|;
if|if
condition|(
name|A
operator|.
name|full
operator|>
name|dfixed_const
argument_list|(
name|non_frac
argument_list|)
condition|)
return|return
name|dfixed_const
argument_list|(
name|non_frac
operator|+
literal|1
argument_list|)
return|;
else|else
return|return
name|dfixed_const
argument_list|(
name|non_frac
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|u32
name|dfixed_div
parameter_list|(
name|fixed20_12
name|A
parameter_list|,
name|fixed20_12
name|B
parameter_list|)
block|{
name|u64
name|tmp
init|=
operator|(
operator|(
name|u64
operator|)
name|A
operator|.
name|full
operator|<<
literal|13
operator|)
decl_stmt|;
name|do_div
argument_list|(
name|tmp
argument_list|,
name|B
operator|.
name|full
argument_list|)
expr_stmt|;
name|tmp
operator|+=
literal|1
expr_stmt|;
name|tmp
operator|/=
literal|2
expr_stmt|;
return|return
name|lower_32_bits
argument_list|(
name|tmp
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

