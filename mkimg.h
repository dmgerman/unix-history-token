begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Juniper Networks, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MKIMG_MKIMG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MKIMG_MKIMG_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_struct
struct|struct
name|part
block|{
name|STAILQ_ENTRY
argument_list|(
argument|part
argument_list|)
name|link
expr_stmt|;
name|char
modifier|*
name|alias
decl_stmt|;
comment|/* Partition type alias. */
name|char
modifier|*
name|contents
decl_stmt|;
comment|/* Contents/size specification. */
name|u_int
name|kind
decl_stmt|;
comment|/* Content kind. */
define|#
directive|define
name|PART_UNDEF
value|0
define|#
directive|define
name|PART_KIND_FILE
value|1
define|#
directive|define
name|PART_KIND_PIPE
value|2
define|#
directive|define
name|PART_KIND_SIZE
value|3
name|u_int
name|index
decl_stmt|;
comment|/* Partition index (0-based). */
name|uintptr_t
name|type
decl_stmt|;
comment|/* Scheme-specific partition type. */
name|off_t
name|offset
decl_stmt|;
comment|/* Byte-offset of partition in image. */
name|off_t
name|size
decl_stmt|;
comment|/* Size in bytes of partition. */
block|}
struct|;
end_struct

begin_extern
extern|extern STAILQ_HEAD(partlisthead
operator|,
extern|part
end_extern

begin_expr_stmt
unit|)
name|partlist
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|nparts
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MKIMG_MKIMG_H_ */
end_comment

end_unit

