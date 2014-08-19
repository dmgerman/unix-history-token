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
name|lba_t
name|block
decl_stmt|;
comment|/* Block-offset of partition in image. */
name|lba_t
name|size
decl_stmt|;
comment|/* Size in blocks of partition. */
name|char
modifier|*
name|label
decl_stmt|;
comment|/* Partition label. */
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

begin_decl_stmt
specifier|extern
name|u_int
name|unit_testing
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|verbose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|ncyls
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|nheads
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|nsecs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|secsz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Logical block size. */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|blksz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Physical block size. */
end_comment

begin_function
specifier|static
specifier|inline
name|lba_t
name|round_block
parameter_list|(
name|lba_t
name|n
parameter_list|)
block|{
name|lba_t
name|b
init|=
name|blksz
operator|/
name|secsz
decl_stmt|;
return|return
operator|(
operator|(
name|n
operator|+
name|b
operator|-
literal|1
operator|)
operator|&
operator|~
operator|(
name|b
operator|-
literal|1
operator|)
operator|)
return|;
block|}
end_function

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SPARSE_WRITE
argument_list|)
end_if

begin_define
define|#
directive|define
name|sparse_write
value|write
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
name|ssize_t
name|sparse_write
parameter_list|(
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|uuid
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|mkimg_uuid
parameter_list|(
name|struct
name|uuid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MKIMG_MKIMG_H_ */
end_comment

end_unit

