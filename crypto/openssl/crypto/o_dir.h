begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/o_dir.h -*- mode:C; c-file-style: "eay" -*- */
end_comment

begin_comment
comment|/* Copied from Richard Levitte's (richard@levitte.org) LP library.  All  * symbol names have been changed, with permission from the author.  */
end_comment

begin_comment
comment|/* $LP: LPlib/source/LPdir.h,v 1.1 2004/06/14 08:56:04 _cvs_levitte Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2004, Richard Levitte<richard@levitte.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|O_DIR_H
end_ifndef

begin_define
define|#
directive|define
name|O_DIR_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
typedef|typedef
name|struct
name|OPENSSL_dir_context_st
name|OPENSSL_DIR_CTX
typedef|;
comment|/* returns NULL on error or end-of-directory.      If it is end-of-directory, errno will be zero */
specifier|const
name|char
modifier|*
name|OPENSSL_DIR_read
parameter_list|(
name|OPENSSL_DIR_CTX
modifier|*
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|directory
parameter_list|)
function_decl|;
comment|/* returns 1 on success, 0 on error */
name|int
name|OPENSSL_DIR_end
parameter_list|(
name|OPENSSL_DIR_CTX
modifier|*
modifier|*
name|ctx
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LPDIR_H */
end_comment

end_unit

