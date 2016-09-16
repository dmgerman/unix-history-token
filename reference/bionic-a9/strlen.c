begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2008 The Android Open Source Project  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE  * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_undef
undef|#
directive|undef
name|strlen
end_undef

begin_define
define|#
directive|define
name|__ARM_HAVE_PLD
value|1
end_define

begin_function
name|size_t
name|strlen
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
block|{
name|__builtin_prefetch
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|__builtin_prefetch
argument_list|(
name|s
operator|+
literal|32
argument_list|)
expr_stmt|;
union|union
block|{
specifier|const
name|char
modifier|*
name|b
decl_stmt|;
specifier|const
name|uint32_t
modifier|*
name|w
decl_stmt|;
name|uintptr_t
name|i
decl_stmt|;
block|}
name|u
union|;
comment|// these are some scratch variables for the asm code below
name|uint32_t
name|v
decl_stmt|,
name|t
decl_stmt|;
comment|// initialize the string length to zero
name|size_t
name|l
init|=
literal|0
decl_stmt|;
comment|// align the pointer to a 32-bit word boundary
name|u
operator|.
name|b
operator|=
name|s
expr_stmt|;
while|while
condition|(
name|u
operator|.
name|i
operator|&
literal|0x3
condition|)
block|{
if|if
condition|(
name|__builtin_expect
argument_list|(
operator|*
name|u
operator|.
name|b
operator|++
operator|==
literal|0
argument_list|,
literal|0
argument_list|)
condition|)
block|{
goto|goto
name|done
goto|;
block|}
name|l
operator|++
expr_stmt|;
block|}
comment|// loop for each word, testing if it contains a zero byte
comment|// if so, exit the loop and update the length.
comment|// We need to process 32 bytes per loop to schedule PLD properly
comment|// and achieve the maximum bus speed.
asm|asm(         "ldr     %[v], [%[s]], #4         \n"         "sub     %[l], %[l], %[s]           \n"         "0:                                 \n"
if|#
directive|if
name|__ARM_HAVE_PLD
asm|"pld     [%[s], #64]              \n"
endif|#
directive|endif
asm|"sub     %[t], %[v], %[mask], lsr #7\n"         "and     %[t], %[t], %[mask]        \n"         "bics    %[t], %[t], %[v]           \n"         "ldreq   %[v], [%[s]], #4         \n"
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__OPTIMIZE_SIZE__
argument_list|)
asm|"bne     1f                         \n"         "sub     %[t], %[v], %[mask], lsr #7\n"         "and     %[t], %[t], %[mask]        \n"         "bics    %[t], %[t], %[v]           \n"         "ldreq   %[v], [%[s]], #4         \n"         "bne     1f                         \n"         "sub     %[t], %[v], %[mask], lsr #7\n"         "and     %[t], %[t], %[mask]        \n"         "bics    %[t], %[t], %[v]           \n"         "ldreq   %[v], [%[s]], #4         \n"         "bne     1f                         \n"         "sub     %[t], %[v], %[mask], lsr #7\n"         "and     %[t], %[t], %[mask]        \n"         "bics    %[t], %[t], %[v]           \n"         "ldreq   %[v], [%[s]], #4         \n"         "bne     1f                         \n"         "sub     %[t], %[v], %[mask], lsr #7\n"         "and     %[t], %[t], %[mask]        \n"         "bics    %[t], %[t], %[v]           \n"         "ldreq   %[v], [%[s]], #4         \n"         "bne     1f                         \n"         "sub     %[t], %[v], %[mask], lsr #7\n"         "and     %[t], %[t], %[mask]        \n"         "bics    %[t], %[t], %[v]           \n"         "ldreq   %[v], [%[s]], #4         \n"         "bne     1f                         \n"         "sub     %[t], %[v], %[mask], lsr #7\n"         "and     %[t], %[t], %[mask]        \n"         "bics    %[t], %[t], %[v]           \n"         "ldreq   %[v], [%[s]] , #4         \n"         "bne     1f                         \n"         "sub     %[t], %[v], %[mask], lsr #7\n"         "and     %[t], %[t], %[mask]        \n"         "bics    %[t], %[t], %[v]           \n"         "ldreq   %[v], [%[s]], #4         \n"
endif|#
directive|endif
asm|"beq     0b                         \n"         "1:                                 \n"         "add     %[l], %[l], %[s]           \n"         "tst     %[v], #0xFF                \n"         "beq     2f                         \n"         "add     %[l], %[l], #1             \n"         "tst     %[v], #0xFF00              \n"         "beq     2f                         \n"         "add     %[l], %[l], #1             \n"         "tst     %[v], #0xFF0000            \n"         "addne   %[l], %[l], #1             \n"         "2:                                 \n"         : [l]"=&r"(l), [v]"=&r"(v), [t]"=&r"(t), [s]"=&r"(u.b)         : "%[l]"(l), "%[s]"(u.b), [mask]"r"(0x80808080UL)         : "cc"     );
name|done
label|:
return|return
name|l
return|;
block|}
end_function

end_unit

