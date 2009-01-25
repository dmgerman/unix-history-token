begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Xin LI<delphij@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_include
include|#
directive|include
file|<sys/limits.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/*  * Portable strlen() for 32-bit and 64-bit systems.  *  * Rationale: it is generally much more efficient to do word length  * operations and avoid branches on modern computer systems, as  * compared to byte-length operations with a lot of branches.  *  * The expression:  *  *	((x - 0x01....01)& ~x& 0x80....80)  *  * would evaluate to a non-zero value iff any of the bytes in the  * original word is zero.  However, we can further reduce ~1/3 of  * time if we consider that strlen() usually operate on 7-bit ASCII  * by employing the following expression, which allows false positive  * when high bit of 1 and use the tail case to catch these case:  *  *	((x - 0x01....01)& 0x80....80)  *  * This is more than 5.2 times as compared to the raw implementation  * on Intel T7300 under EM64T mode for strings longer than word length.  */
end_comment

begin_comment
comment|/* Magic numbers for the algorithm */
end_comment

begin_if
if|#
directive|if
name|LONG_BIT
operator|==
literal|32
end_if

begin_decl_stmt
specifier|static
specifier|const
name|unsigned
name|long
name|mask01
init|=
literal|0x01010101
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|unsigned
name|long
name|mask80
init|=
literal|0x80808080
decl_stmt|;
end_decl_stmt

begin_elif
elif|#
directive|elif
name|LONG_BIT
operator|==
literal|64
end_elif

begin_decl_stmt
specifier|static
specifier|const
name|unsigned
name|long
name|mask01
init|=
literal|0x0101010101010101
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|unsigned
name|long
name|mask80
init|=
literal|0x8080808080808080
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Unsupported word size
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LONGPTR_MASK
value|(sizeof(long) - 1)
end_define

begin_comment
comment|/*  * Helper macro to return string length if we caught the zero  * byte.  */
end_comment

begin_define
define|#
directive|define
name|testbyte
parameter_list|(
name|x
parameter_list|)
define|\
value|do {					\ 		if (p[x] == '\0')		\ 		    return (p - str + x);	\ 	} while (0)
end_define

begin_function
name|size_t
name|strlen
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|p
decl_stmt|;
specifier|const
name|unsigned
name|long
modifier|*
name|lp
decl_stmt|;
comment|/* Skip the first few bytes until we have an aligned p */
for|for
control|(
name|p
operator|=
name|str
init|;
operator|(
name|uintptr_t
operator|)
name|p
operator|&
name|LONGPTR_MASK
condition|;
name|p
operator|++
control|)
if|if
condition|(
operator|*
name|p
operator|==
literal|'\0'
condition|)
return|return
operator|(
name|p
operator|-
name|str
operator|)
return|;
comment|/* Scan the rest of the string using word sized operation */
for|for
control|(
name|lp
operator|=
operator|(
specifier|const
name|unsigned
name|long
operator|*
operator|)
name|p
init|;
condition|;
name|lp
operator|++
control|)
if|if
condition|(
operator|(
operator|*
name|lp
operator|-
name|mask01
operator|)
operator|&
name|mask80
condition|)
block|{
name|p
operator|=
operator|(
specifier|const
name|char
operator|*
operator|)
operator|(
name|lp
operator|)
expr_stmt|;
name|testbyte
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|testbyte
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|testbyte
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|testbyte
argument_list|(
literal|3
argument_list|)
expr_stmt|;
if|#
directive|if
operator|(
name|LONG_BIT
operator|>=
literal|64
operator|)
name|testbyte
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|testbyte
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|testbyte
argument_list|(
literal|6
argument_list|)
expr_stmt|;
name|testbyte
argument_list|(
literal|7
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
comment|/* NOTREACHED */
return|return
literal|0
return|;
block|}
end_function

end_unit

