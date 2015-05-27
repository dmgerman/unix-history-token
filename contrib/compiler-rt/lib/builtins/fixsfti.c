begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- fixsfti.c - Implement __fixsfti -----------------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CRT_HAS_128BIT
end_ifdef

begin_define
define|#
directive|define
name|SINGLE_PRECISION
end_define

begin_include
include|#
directive|include
file|"fp_lib.h"
end_include

begin_typedef
typedef|typedef
name|ti_int
name|fixint_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|tu_int
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
name|ti_int
name|__fixsfti
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

begin_comment
comment|/* CRT_HAS_128BIT */
end_comment

end_unit

