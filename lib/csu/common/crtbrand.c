begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 1996, 1997, 1998, 2000 John D. Polstra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_define
define|#
directive|define
name|ABI_VENDOR
value|"FreeBSD"
end_define

begin_define
define|#
directive|define
name|ABI_SECTION
value|".note.ABI-tag"
end_define

begin_define
define|#
directive|define
name|ABI_NOTETYPE
value|1
end_define

begin_comment
comment|/*  * Special ".note" entry specifying the ABI version.  See  * http://www.netbsd.org/Documentation/kernel/elf-notes.html  * for more information.  */
end_comment

begin_struct
specifier|static
specifier|const
struct|struct
block|{
name|int32_t
name|namesz
decl_stmt|;
name|int32_t
name|descsz
decl_stmt|;
name|int32_t
name|type
decl_stmt|;
name|char
name|name
index|[
sizeof|sizeof
name|ABI_VENDOR
index|]
decl_stmt|;
name|int32_t
name|desc
decl_stmt|;
block|}
name|abitag
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
name|ABI_SECTION
argument_list|)
operator|)
argument_list|)
init|=
block|{
sizeof|sizeof
name|ABI_VENDOR
block|,
sizeof|sizeof
argument_list|(
name|int32_t
argument_list|)
block|,
name|ABI_NOTETYPE
block|,
name|ABI_VENDOR
block|,
name|__FreeBSD_version
block|}
struct|;
end_struct

end_unit

