begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2010-2012 Broadcom. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The names of the above-listed copyright holders may not be used  *    to endorse or promote products derived from this software without  *    specific prior written permission.  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2, as published by the Free  * Software Foundation.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS  * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHIQ_PAGELIST_H
end_ifndef

begin_define
define|#
directive|define
name|VCHIQ_PAGELIST_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PAGE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|PAGE_SIZE
value|4096
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|CACHE_LINE_SIZE
end_undef

begin_define
define|#
directive|define
name|CACHE_LINE_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|PAGELIST_WRITE
value|0
end_define

begin_define
define|#
directive|define
name|PAGELIST_READ
value|1
end_define

begin_define
define|#
directive|define
name|PAGELIST_READ_WITH_FRAGMENTS
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|pagelist_struct
block|{
name|unsigned
name|long
name|length
decl_stmt|;
name|unsigned
name|short
name|type
decl_stmt|;
name|unsigned
name|short
name|offset
decl_stmt|;
name|unsigned
name|long
name|addrs
index|[
literal|1
index|]
decl_stmt|;
comment|/* N.B. 12 LSBs hold the number of following 				   pages at consecutive addresses. */
block|}
name|PAGELIST_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|fragments_struct
block|{
name|char
name|headbuf
index|[
name|CACHE_LINE_SIZE
index|]
decl_stmt|;
name|char
name|tailbuf
index|[
name|CACHE_LINE_SIZE
index|]
decl_stmt|;
block|}
name|FRAGMENTS_T
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VCHIQ_PAGELIST_H */
end_comment

end_unit

