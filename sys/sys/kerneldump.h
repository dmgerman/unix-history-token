begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Poul-Henning Kamp  * Copyright (c) 2002 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by Poul-Henning Kamp  * and NAI Labs, the Security Research Division of Network Associates, Inc.  * under DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"), as part of the  * DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The names of the authors may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_KERNELDUMP_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_KERNELDUMP_H
end_define

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|dtoh32
parameter_list|(
name|x
parameter_list|)
value|__bswap32(x)
end_define

begin_define
define|#
directive|define
name|dtoh64
parameter_list|(
name|x
parameter_list|)
value|__bswap64(x)
end_define

begin_define
define|#
directive|define
name|htod32
parameter_list|(
name|x
parameter_list|)
value|__bswap32(x)
end_define

begin_define
define|#
directive|define
name|htod64
parameter_list|(
name|x
parameter_list|)
value|__bswap64(x)
end_define

begin_elif
elif|#
directive|elif
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_elif

begin_define
define|#
directive|define
name|dtoh32
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|dtoh64
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|htod32
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|htod64
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * All uintX_t fields are in dump byte order, which is the same as  * network byte order. Use the macros defined above to read or  * write the fields.  */
end_comment

begin_struct
struct|struct
name|kerneldumpheader
block|{
name|char
name|magic
index|[
literal|20
index|]
decl_stmt|;
define|#
directive|define
name|KERNELDUMPMAGIC
value|"FreeBSD Kernel Dump"
name|char
name|architecture
index|[
literal|12
index|]
decl_stmt|;
name|uint32_t
name|version
decl_stmt|;
define|#
directive|define
name|KERNELDUMPVERSION
value|1
name|uint32_t
name|architectureversion
decl_stmt|;
define|#
directive|define
name|KERNELDUMP_I386_VERSION
value|1
define|#
directive|define
name|KERNELDUMP_IA64_VERSION
value|1
name|uint64_t
name|dumplength
decl_stmt|;
comment|/* excl headers */
name|uint64_t
name|dumptime
decl_stmt|;
name|uint32_t
name|blocksize
decl_stmt|;
name|char
name|hostname
index|[
literal|64
index|]
decl_stmt|;
name|char
name|versionstring
index|[
literal|192
index|]
decl_stmt|;
name|char
name|panicstring
index|[
literal|192
index|]
decl_stmt|;
name|uint32_t
name|parity
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Parity calculation is endian insensitive.  */
end_comment

begin_function
specifier|static
name|__inline
name|u_int32_t
name|kerneldump_parity
parameter_list|(
name|struct
name|kerneldumpheader
modifier|*
name|kdhp
parameter_list|)
block|{
name|uint32_t
modifier|*
name|up
decl_stmt|,
name|parity
decl_stmt|;
name|u_int
name|i
decl_stmt|;
name|up
operator|=
operator|(
name|uint32_t
operator|*
operator|)
name|kdhp
expr_stmt|;
name|parity
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
expr|*
name|kdhp
condition|;
name|i
operator|+=
sizeof|sizeof
expr|*
name|up
control|)
name|parity
operator|^=
operator|*
name|up
operator|++
expr_stmt|;
return|return
operator|(
name|parity
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_KERNELDUMP_H */
end_comment

end_unit

