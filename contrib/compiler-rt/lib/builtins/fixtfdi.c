begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- fixtfdi.c - Implement __fixtfdi -----------------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_define
define|#
directive|define
name|QUAD_PRECISION
end_define

begin_include
include|#
directive|include
file|"fp_lib.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CRT_HAS_128BIT
argument_list|)
operator|&&
name|defined
argument_list|(
name|CRT_LDBL_128BIT
argument_list|)
end_if

begin_typedef
typedef|typedef
name|di_int
name|fixint_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|du_int
name|fixuint_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"fp_fixint_impl.inc"
end_include

begin_function
name|COMPILER_RT_ABI
name|di_int
name|__fixtfdi
parameter_list|(
name|fp_t
name|a
parameter_list|)
block|{
return|return
name|__fixint
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

