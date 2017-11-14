begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This module derived from code donated to the FreeBSD Project by   * Matthew Dillon<dillon@backplane.com>  *  * Copyright (c) 1998 The FreeBSD Project  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * DEFS.H  */
end_comment

begin_define
define|#
directive|define
name|USEGUARD
end_define

begin_comment
comment|/* use stard/end guard bytes */
end_comment

begin_define
define|#
directive|define
name|USEENDGUARD
end_define

begin_define
define|#
directive|define
name|DMALLOCDEBUG
end_define

begin_comment
comment|/* add debugging code to gather stats */
end_comment

begin_define
define|#
directive|define
name|ZALLOCDEBUG
end_define

begin_include
include|#
directive|include
file|<sys/stdint.h>
end_include

begin_include
include|#
directive|include
file|"stand.h"
end_include

begin_include
include|#
directive|include
file|"zalloc_mem.h"
end_include

begin_define
define|#
directive|define
name|Library
value|extern
end_define

begin_comment
comment|/*  * block extension for sbrk()  */
end_comment

begin_define
define|#
directive|define
name|BLKEXTEND
value|(4 * 1024)
end_define

begin_define
define|#
directive|define
name|BLKEXTENDMASK
value|(BLKEXTEND - 1)
end_define

begin_comment
comment|/*  * Required malloc alignment.  *  * Embedded platforms using the u-boot API drivers require that all I/O buffers  * be on a cache line sized boundary.  The worst case size for that is 64 bytes.  * For other platforms, 16 bytes works fine.  The alignment also must be at  * least sizeof(struct MemNode); this is asserted in zalloc.c.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips__
argument_list|)
operator|||
name|defined
argument_list|(
name|__powerpc__
argument_list|)
end_if

begin_define
define|#
directive|define
name|MALLOCALIGN
value|64
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MALLOCALIGN
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MALLOCALIGN_MASK
value|(MALLOCALIGN - 1)
end_define

begin_typedef
typedef|typedef
struct|struct
name|Guard
block|{
name|size_t
name|ga_Bytes
decl_stmt|;
name|size_t
name|ga_Magic
decl_stmt|;
comment|/* must be at least 32 bits */
block|}
name|Guard
typedef|;
end_typedef

begin_define
define|#
directive|define
name|GAMAGIC
value|0x55FF44FD
end_define

begin_define
define|#
directive|define
name|GAFREE
value|0x5F54F4DF
end_define

begin_include
include|#
directive|include
file|"zalloc_protos.h"
end_include

end_unit

