begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * LZ4 - Fast LZ compression algorithm  * Header File  * Copyright (C) 2011-2013, Yann Collet.  * BSD 2-Clause License (http://www.opensource.org/licenses/bsd-license.php)  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *     * Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above  * copyright notice, this list of conditions and the following disclaimer  * in the documentation and/or other materials provided with the  * distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * You can contact the author at :  * - LZ4 homepage : http://fastcompression.blogspot.com/p/lz4.html  * - LZ4 source repository : http://code.google.com/p/lz4/  *  * $FreeBSD$  */
end_comment

begin_function_decl
specifier|static
name|int
name|LZ4_uncompress_unknownOutputSize
parameter_list|(
specifier|const
name|char
modifier|*
name|source
parameter_list|,
name|char
modifier|*
name|dest
parameter_list|,
name|int
name|isize
parameter_list|,
name|int
name|maxOutputSize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|int
name|lz4_decompress
parameter_list|(
name|void
modifier|*
name|s_start
parameter_list|,
name|void
modifier|*
name|d_start
parameter_list|,
name|size_t
name|s_len
parameter_list|,
name|size_t
name|d_len
parameter_list|,
name|int
name|dummy
name|__unused
parameter_list|)
block|{
specifier|const
name|uint8_t
modifier|*
name|src
init|=
name|s_start
decl_stmt|;
name|uint32_t
name|bufsiz
init|=
name|htonl
argument_list|(
operator|*
operator|(
name|uint32_t
operator|*
operator|)
name|src
argument_list|)
decl_stmt|;
comment|/* invalid compressed buffer size encoded at start */
if|if
condition|(
name|bufsiz
operator|+
literal|4
operator|>
name|s_len
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* 	 * Returns 0 on success (decompression function returned non-negative) 	 * and non-zero on failure (decompression function returned negative). 	 */
return|return
operator|(
name|LZ4_uncompress_unknownOutputSize
argument_list|(
name|s_start
operator|+
literal|4
argument_list|,
name|d_start
argument_list|,
name|bufsiz
argument_list|,
name|d_len
argument_list|)
operator|<
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * CPU Feature Detection  */
end_comment

begin_comment
comment|/* 32 or 64 bits ? */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__amd64
argument_list|)
operator|||
name|defined
argument_list|(
name|__ppc64__
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN64
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__LP64__
argument_list|)
operator|||
name|defined
argument_list|(
name|_LP64
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|LZ4_ARCH64
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LZ4_ARCH64
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Little Endian or Big Endian?  * Note: overwrite the below #define if you know your architecture endianess.  */
end_comment

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|LZ4_BIG_ENDIAN
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* 	 * Little Endian assumed. PDP Endian and other very rare endian format 	 * are unsupported. 	 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Unaligned memory access is automatically enabled for "common" CPU,  * such as x86. For others CPU, the compiler will be more cautious, and  * insert extra code to ensure aligned access is respected. If you know  * your target CPU supports unaligned memory access, you may want to  * force this option manually to improve performance  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_FEATURE_UNALIGNED
argument_list|)
end_if

begin_define
define|#
directive|define
name|LZ4_FORCE_UNALIGNED_ACCESS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Compiler Options  */
end_comment

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|>=
literal|199901L
end_if

begin_comment
comment|/* C99 */
end_comment

begin_comment
comment|/* "restrict" is a known keyword */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Disable restrict */
end_comment

begin_define
define|#
directive|define
name|restrict
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GCC_VERSION
value|(__GNUC__ * 100 + __GNUC_MINOR__)
end_define

begin_define
define|#
directive|define
name|lz4_bswap16
parameter_list|(
name|x
parameter_list|)
value|((unsigned short int) ((((x)>> 8)& 0xffu) \ 	| (((x)& 0xffu)<< 8)))
end_define

begin_if
if|#
directive|if
operator|(
name|GCC_VERSION
operator|>=
literal|302
operator|)
operator|||
operator|(
name|__INTEL_COMPILER
operator|>=
literal|800
operator|)
operator|||
name|defined
argument_list|(
name|__clang__
argument_list|)
end_if

begin_define
define|#
directive|define
name|expect
parameter_list|(
name|expr
parameter_list|,
name|value
parameter_list|)
value|(__builtin_expect((expr), (value)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|expect
parameter_list|(
name|expr
parameter_list|,
name|value
parameter_list|)
value|(expr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|likely
parameter_list|(
name|expr
parameter_list|)
value|expect((expr) != 0, 1)
end_define

begin_define
define|#
directive|define
name|unlikely
parameter_list|(
name|expr
parameter_list|)
value|expect((expr) != 0, 0)
end_define

begin_comment
comment|/* Basic types */
end_comment

begin_define
define|#
directive|define
name|BYTE
value|uint8_t
end_define

begin_define
define|#
directive|define
name|U16
value|uint16_t
end_define

begin_define
define|#
directive|define
name|U32
value|uint32_t
end_define

begin_define
define|#
directive|define
name|S32
value|int32_t
end_define

begin_define
define|#
directive|define
name|U64
value|uint64_t
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LZ4_FORCE_UNALIGNED_ACCESS
end_ifndef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_U16_S
block|{
name|U16
name|v
decl_stmt|;
block|}
name|U16_S
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_U32_S
block|{
name|U32
name|v
decl_stmt|;
block|}
name|U32_S
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_U64_S
block|{
name|U64
name|v
decl_stmt|;
block|}
name|U64_S
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|LZ4_FORCE_UNALIGNED_ACCESS
end_ifndef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|A64
parameter_list|(
name|x
parameter_list|)
value|(((U64_S *)(x))->v)
end_define

begin_define
define|#
directive|define
name|A32
parameter_list|(
name|x
parameter_list|)
value|(((U32_S *)(x))->v)
end_define

begin_define
define|#
directive|define
name|A16
parameter_list|(
name|x
parameter_list|)
value|(((U16_S *)(x))->v)
end_define

begin_comment
comment|/*  * Constants  */
end_comment

begin_define
define|#
directive|define
name|MINMATCH
value|4
end_define

begin_define
define|#
directive|define
name|COPYLENGTH
value|8
end_define

begin_define
define|#
directive|define
name|LASTLITERALS
value|5
end_define

begin_define
define|#
directive|define
name|ML_BITS
value|4
end_define

begin_define
define|#
directive|define
name|ML_MASK
value|((1U<<ML_BITS)-1)
end_define

begin_define
define|#
directive|define
name|RUN_BITS
value|(8-ML_BITS)
end_define

begin_define
define|#
directive|define
name|RUN_MASK
value|((1U<<RUN_BITS)-1)
end_define

begin_comment
comment|/*  * Architecture-specific macros  */
end_comment

begin_if
if|#
directive|if
name|LZ4_ARCH64
end_if

begin_define
define|#
directive|define
name|STEPSIZE
value|8
end_define

begin_define
define|#
directive|define
name|UARCH
value|U64
end_define

begin_define
define|#
directive|define
name|AARCH
value|A64
end_define

begin_define
define|#
directive|define
name|LZ4_COPYSTEP
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|A64(d) = A64(s); d += 8; s += 8;
end_define

begin_define
define|#
directive|define
name|LZ4_COPYPACKET
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|LZ4_COPYSTEP(s, d)
end_define

begin_define
define|#
directive|define
name|LZ4_SECURECOPY
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|if (d< e) LZ4_WILDCOPY(s, d, e)
end_define

begin_define
define|#
directive|define
name|HTYPE
value|U32
end_define

begin_define
define|#
directive|define
name|INITBASE
parameter_list|(
name|base
parameter_list|)
value|const BYTE* const base = ip
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STEPSIZE
value|4
end_define

begin_define
define|#
directive|define
name|UARCH
value|U32
end_define

begin_define
define|#
directive|define
name|AARCH
value|A32
end_define

begin_define
define|#
directive|define
name|LZ4_COPYSTEP
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|A32(d) = A32(s); d += 4; s += 4;
end_define

begin_define
define|#
directive|define
name|LZ4_COPYPACKET
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|LZ4_COPYSTEP(s, d); LZ4_COPYSTEP(s, d);
end_define

begin_define
define|#
directive|define
name|LZ4_SECURECOPY
value|LZ4_WILDCOPY
end_define

begin_define
define|#
directive|define
name|HTYPE
value|const BYTE*
end_define

begin_define
define|#
directive|define
name|INITBASE
parameter_list|(
name|base
parameter_list|)
value|const int base = 0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|LZ4_BIG_ENDIAN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|BIG_ENDIAN_NATIVE_BUT_INCOMPATIBLE
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|LZ4_READ_LITTLEENDIAN_16
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|p
parameter_list|)
define|\
value|{ U16 v = A16(p); v = lz4_bswap16(v); d = (s) - v; }
end_define

begin_define
define|#
directive|define
name|LZ4_WRITE_LITTLEENDIAN_16
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|)
define|\
value|{ U16 v = (U16)(i); v = lz4_bswap16(v); A16(p) = v; p += 2; }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LZ4_READ_LITTLEENDIAN_16
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|p
parameter_list|)
value|{ d = (s) - A16(p); }
end_define

begin_define
define|#
directive|define
name|LZ4_WRITE_LITTLEENDIAN_16
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|{ A16(p) = v; p += 2; }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Macros */
end_comment

begin_define
define|#
directive|define
name|LZ4_WILDCOPY
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|do { LZ4_COPYPACKET(s, d) } while (d< e);
end_define

begin_comment
comment|/* Decompression functions */
end_comment

begin_function
specifier|static
name|int
name|LZ4_uncompress_unknownOutputSize
parameter_list|(
specifier|const
name|char
modifier|*
name|source
parameter_list|,
name|char
modifier|*
name|dest
parameter_list|,
name|int
name|isize
parameter_list|,
name|int
name|maxOutputSize
parameter_list|)
block|{
comment|/* Local Variables */
specifier|const
name|BYTE
modifier|*
specifier|restrict
name|ip
init|=
operator|(
specifier|const
name|BYTE
operator|*
operator|)
name|source
decl_stmt|;
specifier|const
name|BYTE
modifier|*
specifier|const
name|iend
init|=
name|ip
operator|+
name|isize
decl_stmt|;
specifier|const
name|BYTE
modifier|*
specifier|restrict
name|ref
decl_stmt|;
name|BYTE
modifier|*
specifier|restrict
name|op
init|=
operator|(
name|BYTE
operator|*
operator|)
name|dest
decl_stmt|;
name|BYTE
modifier|*
specifier|const
name|oend
init|=
name|op
operator|+
name|maxOutputSize
decl_stmt|;
name|BYTE
modifier|*
name|cpy
decl_stmt|;
name|size_t
name|dec
index|[]
init|=
block|{
literal|0
block|,
literal|3
block|,
literal|2
block|,
literal|3
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
comment|/* Main Loop */
while|while
condition|(
name|ip
operator|<
name|iend
condition|)
block|{
name|BYTE
name|token
decl_stmt|;
name|int
name|length
decl_stmt|;
comment|/* get runlength */
name|token
operator|=
operator|*
name|ip
operator|++
expr_stmt|;
if|if
condition|(
operator|(
name|length
operator|=
operator|(
name|token
operator|>>
name|ML_BITS
operator|)
operator|)
operator|==
name|RUN_MASK
condition|)
block|{
name|int
name|s
init|=
literal|255
decl_stmt|;
while|while
condition|(
operator|(
name|ip
operator|<
name|iend
operator|)
operator|&&
operator|(
name|s
operator|==
literal|255
operator|)
condition|)
block|{
name|s
operator|=
operator|*
name|ip
operator|++
expr_stmt|;
name|length
operator|+=
name|s
expr_stmt|;
block|}
block|}
comment|/* copy literals */
name|cpy
operator|=
name|op
operator|+
name|length
expr_stmt|;
if|if
condition|(
operator|(
name|cpy
operator|>
name|oend
operator|-
name|COPYLENGTH
operator|)
operator|||
operator|(
name|ip
operator|+
name|length
operator|>
name|iend
operator|-
name|COPYLENGTH
operator|)
condition|)
block|{
if|if
condition|(
name|cpy
operator|>
name|oend
condition|)
comment|/* 				 * Error: request to write beyond destination 				 * buffer. 				 */
goto|goto
name|_output_error
goto|;
if|if
condition|(
name|ip
operator|+
name|length
operator|>
name|iend
condition|)
comment|/* 				 * Error : request to read beyond source 				 * buffer. 				 */
goto|goto
name|_output_error
goto|;
name|memcpy
argument_list|(
name|op
argument_list|,
name|ip
argument_list|,
name|length
argument_list|)
expr_stmt|;
name|op
operator|+=
name|length
expr_stmt|;
name|ip
operator|+=
name|length
expr_stmt|;
if|if
condition|(
name|ip
operator|<
name|iend
condition|)
comment|/* Error : LZ4 format violation */
goto|goto
name|_output_error
goto|;
comment|/* Necessarily EOF, due to parsing restrictions. */
break|break;
block|}
name|LZ4_WILDCOPY
argument_list|(
name|ip
argument_list|,
name|op
argument_list|,
name|cpy
argument_list|)
expr_stmt|;
name|ip
operator|-=
operator|(
name|op
operator|-
name|cpy
operator|)
expr_stmt|;
name|op
operator|=
name|cpy
expr_stmt|;
comment|/* get offset */
name|LZ4_READ_LITTLEENDIAN_16
argument_list|(
name|ref
argument_list|,
name|cpy
argument_list|,
name|ip
argument_list|)
expr_stmt|;
name|ip
operator|+=
literal|2
expr_stmt|;
if|if
condition|(
name|ref
operator|<
operator|(
name|BYTE
operator|*
specifier|const
operator|)
name|dest
condition|)
comment|/* 			 * Error: offset creates reference outside of 			 * destination buffer. 			 */
goto|goto
name|_output_error
goto|;
comment|/* get matchlength */
if|if
condition|(
operator|(
name|length
operator|=
operator|(
name|token
operator|&
name|ML_MASK
operator|)
operator|)
operator|==
name|ML_MASK
condition|)
block|{
while|while
condition|(
name|ip
operator|<
name|iend
condition|)
block|{
name|int
name|s
init|=
operator|*
name|ip
operator|++
decl_stmt|;
name|length
operator|+=
name|s
expr_stmt|;
if|if
condition|(
name|s
operator|==
literal|255
condition|)
continue|continue;
break|break;
block|}
block|}
comment|/* copy repeated sequence */
if|if unlikely
condition|(
name|op
operator|-
name|ref
operator|<
name|STEPSIZE
condition|)
block|{
if|#
directive|if
name|LZ4_ARCH64
name|size_t
name|dec2table
index|[]
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|}
decl_stmt|;
name|size_t
name|dec2
init|=
name|dec2table
index|[
name|op
operator|-
name|ref
index|]
decl_stmt|;
else|#
directive|else
specifier|const
name|int
name|dec2
init|=
literal|0
decl_stmt|;
endif|#
directive|endif
operator|*
name|op
operator|++
operator|=
operator|*
name|ref
operator|++
expr_stmt|;
operator|*
name|op
operator|++
operator|=
operator|*
name|ref
operator|++
expr_stmt|;
operator|*
name|op
operator|++
operator|=
operator|*
name|ref
operator|++
expr_stmt|;
operator|*
name|op
operator|++
operator|=
operator|*
name|ref
operator|++
expr_stmt|;
name|ref
operator|-=
name|dec
index|[
name|op
operator|-
name|ref
index|]
expr_stmt|;
name|A32
argument_list|(
name|op
argument_list|)
operator|=
name|A32
argument_list|(
name|ref
argument_list|)
expr_stmt|;
name|op
operator|+=
name|STEPSIZE
operator|-
literal|4
expr_stmt|;
name|ref
operator|-=
name|dec2
expr_stmt|;
block|}
else|else
block|{
name|LZ4_COPYSTEP
argument_list|(
name|ref
argument_list|,
name|op
argument_list|)
expr_stmt|;
block|}
name|cpy
operator|=
name|op
operator|+
name|length
operator|-
operator|(
name|STEPSIZE
operator|-
literal|4
operator|)
expr_stmt|;
if|if
condition|(
name|cpy
operator|>
name|oend
operator|-
name|COPYLENGTH
condition|)
block|{
if|if
condition|(
name|cpy
operator|>
name|oend
condition|)
comment|/* 				 * Error: request to write outside of 				 * destination buffer. 				 */
goto|goto
name|_output_error
goto|;
name|LZ4_SECURECOPY
argument_list|(
name|ref
argument_list|,
name|op
argument_list|,
operator|(
name|oend
operator|-
name|COPYLENGTH
operator|)
argument_list|)
expr_stmt|;
while|while
condition|(
name|op
operator|<
name|cpy
condition|)
operator|*
name|op
operator|++
operator|=
operator|*
name|ref
operator|++
expr_stmt|;
name|op
operator|=
name|cpy
expr_stmt|;
if|if
condition|(
name|op
operator|==
name|oend
condition|)
comment|/* 				 * Check EOF (should never happen, since last 				 * 5 bytes are supposed to be literals). 				 */
break|break;
continue|continue;
block|}
name|LZ4_SECURECOPY
argument_list|(
name|ref
argument_list|,
name|op
argument_list|,
name|cpy
argument_list|)
expr_stmt|;
name|op
operator|=
name|cpy
expr_stmt|;
comment|/* correction */
block|}
comment|/* end of decoding */
return|return
call|(
name|int
call|)
argument_list|(
operator|(
operator|(
name|char
operator|*
operator|)
name|op
operator|)
operator|-
name|dest
argument_list|)
return|;
comment|/* write overflow error detected */
name|_output_error
label|:
return|return
call|(
name|int
call|)
argument_list|(
operator|-
operator|(
operator|(
operator|(
name|char
operator|*
operator|)
name|ip
operator|)
operator|-
name|source
operator|)
argument_list|)
return|;
block|}
end_function

end_unit

