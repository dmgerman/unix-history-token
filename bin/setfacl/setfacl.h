begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Chris D. Faulhaber  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR THE VOICES IN HIS HEAD BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SETFACL_H
end_ifndef

begin_define
define|#
directive|define
name|_SETFACL_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/acl.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/* file operations */
end_comment

begin_define
define|#
directive|define
name|OP_MERGE_ACL
value|0x00
end_define

begin_comment
comment|/* merge acl's (-mM) */
end_comment

begin_define
define|#
directive|define
name|OP_REMOVE_DEF
value|0x01
end_define

begin_comment
comment|/* remove default acl's (-k) */
end_comment

begin_define
define|#
directive|define
name|OP_REMOVE_EXT
value|0x02
end_define

begin_comment
comment|/* remove extended acl's (-b) */
end_comment

begin_define
define|#
directive|define
name|OP_REMOVE_ACL
value|0x03
end_define

begin_comment
comment|/* remove acl's (-xX) */
end_comment

begin_define
define|#
directive|define
name|OP_REMOVE_BY_NUMBER
value|0x04
end_define

begin_comment
comment|/* remove acl's (-xX) by acl entry number */
end_comment

begin_define
define|#
directive|define
name|OP_ADD_ACL
value|0x05
end_define

begin_comment
comment|/* add acls entries at a given position */
end_comment

begin_comment
comment|/* TAILQ entry for acl operations */
end_comment

begin_struct
struct|struct
name|sf_entry
block|{
name|uint
name|op
decl_stmt|;
name|acl_t
name|acl
decl_stmt|;
name|uint
name|entry_number
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|sf_entry
argument_list|)
name|next
expr_stmt|;
block|}
struct|;
end_struct

begin_macro
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|sf_entry
argument_list|)
end_macro

begin_expr_stmt
name|entrylist
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* TAILQ entry for files */
end_comment

begin_struct
struct|struct
name|sf_file
block|{
specifier|const
name|char
modifier|*
name|filename
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|sf_file
argument_list|)
name|next
expr_stmt|;
block|}
struct|;
end_struct

begin_macro
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|sf_file
argument_list|)
end_macro

begin_expr_stmt
name|filelist
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* files.c */
end_comment

begin_function_decl
name|acl_t
name|get_acl_from_file
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* merge.c */
end_comment

begin_function_decl
name|int
name|merge_acl
parameter_list|(
name|acl_t
name|acl
parameter_list|,
name|acl_t
modifier|*
name|prev_acl
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|add_acl
parameter_list|(
name|acl_t
name|acl
parameter_list|,
name|uint
name|entry_number
parameter_list|,
name|acl_t
modifier|*
name|prev_acl
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* remove.c */
end_comment

begin_function_decl
name|int
name|remove_acl
parameter_list|(
name|acl_t
name|acl
parameter_list|,
name|acl_t
modifier|*
name|prev_acl
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|remove_by_number
parameter_list|(
name|uint
name|entry_number
parameter_list|,
name|acl_t
modifier|*
name|prev_acl
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|remove_default
parameter_list|(
name|acl_t
modifier|*
name|prev_acl
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|remove_ext
parameter_list|(
name|acl_t
modifier|*
name|prev_acl
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* mask.c */
end_comment

begin_function_decl
name|int
name|set_acl_mask
parameter_list|(
name|acl_t
modifier|*
name|prev_acl
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* util.c */
end_comment

begin_function_decl
name|void
modifier|*
name|zmalloc
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|uint
name|have_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint
name|need_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint
name|have_stdin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint
name|n_flag
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SETFACL_H */
end_comment

end_unit

