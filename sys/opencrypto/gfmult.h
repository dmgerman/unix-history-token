begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by John-Mark Gurney under  * the sponsorship of the FreeBSD Foundation and  * Rubicon Communications, LLC (Netgate).  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1.  Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  * 2.  Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GFMULT_H_
end_ifndef

begin_define
define|#
directive|define
name|_GFMULT_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_define
define|#
directive|define
name|__aligned
parameter_list|(
name|x
parameter_list|)
value|__attribute__((__aligned__(x)))
end_define

begin_define
define|#
directive|define
name|be64dec
parameter_list|(
name|buf
parameter_list|)
value|__builtin_bswap64(*(uint64_t *)buf)
end_define

begin_define
define|#
directive|define
name|be64enc
parameter_list|(
name|buf
parameter_list|,
name|x
parameter_list|)
value|(*(uint64_t *)buf = __builtin_bswap64(x))
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|REQ_ALIGN
value|(16 * 4)
end_define

begin_comment
comment|/*  * The rows are striped across cache lines.  Note that the indexes  * are bit reversed to make accesses quicker.  */
end_comment

begin_struct
struct|struct
name|gf128table
block|{
name|uint32_t
name|a
index|[
literal|16
index|]
name|__aligned
parameter_list|(
name|REQ_ALIGN
parameter_list|)
function_decl|;
comment|/* bits   0 - 31 */
name|uint32_t
name|b
index|[
literal|16
index|]
name|__aligned
parameter_list|(
name|REQ_ALIGN
parameter_list|)
function_decl|;
comment|/* bits  63 - 32 */
name|uint32_t
name|c
index|[
literal|16
index|]
name|__aligned
parameter_list|(
name|REQ_ALIGN
parameter_list|)
function_decl|;
comment|/* bits  95 - 64 */
name|uint32_t
name|d
index|[
literal|16
index|]
name|__aligned
parameter_list|(
name|REQ_ALIGN
parameter_list|)
function_decl|;
comment|/* bits 127 - 96 */
block|}
name|__aligned
argument_list|(
name|REQ_ALIGN
argument_list|)
struct|;
end_struct

begin_comment
comment|/*  * A set of tables that contain h, h^2, h^3, h^4.  To be used w/ gf128_mul4.  */
end_comment

begin_struct
struct|struct
name|gf128table4
block|{
name|struct
name|gf128table
name|tbls
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * GCM per spec is bit reversed in memory.  So byte 0 is really bit reversed  * and contains bits 0-7.  We can deal w/ this by using right shifts and  * related math instead of having to bit reverse everything.  This means that  * the low bits are in v[0] (bits 0-63) and reverse order, while the high  * bits are in v[1] (bits 64-127) and reverse order.  The high bit of v[0] is  * bit 0, and the low bit of v[1] is bit 127.  */
end_comment

begin_struct
struct|struct
name|gf128
block|{
name|uint64_t
name|v
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Note that we don't bit reverse in MAKE_GF128. */
end_comment

begin_define
define|#
directive|define
name|MAKE_GF128
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((struct gf128){.v = { (a), (b) } })
end_define

begin_define
define|#
directive|define
name|GF128_EQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((((a).v[0] ^ (b).v[0]) | \ 				    ((a).v[1] ^ (b).v[1])) == 0)
end_define

begin_function
specifier|static
specifier|inline
name|struct
name|gf128
name|gf128_read
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|buf
parameter_list|)
block|{
name|struct
name|gf128
name|r
decl_stmt|;
name|r
operator|.
name|v
index|[
literal|0
index|]
operator|=
name|be64dec
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|buf
operator|+=
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
expr_stmt|;
name|r
operator|.
name|v
index|[
literal|1
index|]
operator|=
name|be64dec
argument_list|(
name|buf
argument_list|)
expr_stmt|;
return|return
name|r
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|gf128_write
parameter_list|(
name|struct
name|gf128
name|v
parameter_list|,
name|uint8_t
modifier|*
name|buf
parameter_list|)
block|{
name|uint64_t
name|tmp
decl_stmt|;
name|be64enc
argument_list|(
name|buf
argument_list|,
name|v
operator|.
name|v
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|buf
operator|+=
sizeof|sizeof
name|tmp
expr_stmt|;
name|be64enc
argument_list|(
name|buf
argument_list|,
name|v
operator|.
name|v
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|struct
name|gf128
name|__pure
comment|/* XXX - __pure2 instead */
name|gf128_add
parameter_list|(
name|struct
name|gf128
name|a
parameter_list|,
name|struct
name|gf128
name|b
parameter_list|)
block|{
name|a
operator|.
name|v
index|[
literal|0
index|]
operator|^=
name|b
operator|.
name|v
index|[
literal|0
index|]
expr_stmt|;
name|a
operator|.
name|v
index|[
literal|1
index|]
operator|^=
name|b
operator|.
name|v
index|[
literal|1
index|]
expr_stmt|;
return|return
name|a
return|;
block|}
end_function

begin_function_decl
name|void
name|gf128_genmultable
parameter_list|(
name|struct
name|gf128
name|h
parameter_list|,
name|struct
name|gf128table
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gf128_genmultable4
parameter_list|(
name|struct
name|gf128
name|h
parameter_list|,
name|struct
name|gf128table4
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|gf128
name|gf128_mul
parameter_list|(
name|struct
name|gf128
name|v
parameter_list|,
name|struct
name|gf128table
modifier|*
name|tbl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|gf128
name|gf128_mul4
parameter_list|(
name|struct
name|gf128
name|a
parameter_list|,
name|struct
name|gf128
name|b
parameter_list|,
name|struct
name|gf128
name|c
parameter_list|,
name|struct
name|gf128
name|d
parameter_list|,
name|struct
name|gf128table4
modifier|*
name|tbl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|gf128
name|gf128_mul4b
parameter_list|(
name|struct
name|gf128
name|r
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|v
parameter_list|,
name|struct
name|gf128table4
modifier|*
name|tbl
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GFMULT_H_ */
end_comment

end_unit

