begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<ieeefp.h>
end_include

begin_function
name|fp_rnd_t
name|fpsetround
parameter_list|(
name|fp_rnd_t
name|rnd
parameter_list|)
block|{
name|uint64_t
name|fpsr
decl_stmt|;
name|fp_rnd_t
name|prev
decl_stmt|;
asm|__asm __volatile("mov %0=ar.fpsr" : "=r"(fpsr));
name|prev
operator|=
call|(
name|fp_rnd_t
call|)
argument_list|(
operator|(
name|fpsr
operator|>>
literal|10
operator|)
operator|&
literal|3
argument_list|)
expr_stmt|;
name|fpsr
operator|=
operator|(
name|fpsr
operator|&
operator|~
literal|0xC00ULL
operator|)
operator||
operator|(
operator|(
name|unsigned
name|int
operator|)
name|rnd
operator|<<
literal|10
operator|)
expr_stmt|;
asm|__asm __volatile("mov ar.fpsr=%0" :: "r"(fpsr));
return|return
operator|(
name|prev
operator|)
return|;
block|}
end_function

end_unit

