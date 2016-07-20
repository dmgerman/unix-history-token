begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2016 Maxim Sobolev<sobomax@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_expr_stmt
name|DEFINE_RAW_METHOD
argument_list|(
name|f_init
argument_list|,
name|void
operator|*
argument_list|,
name|uint32_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_RAW_METHOD
argument_list|(
name|f_compress
argument_list|,
expr|struct
name|mkuz_blk
operator|*
argument_list|,
name|void
operator|*
argument_list|,
specifier|const
expr|struct
name|mkuz_blk
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|mkuz_format
block|{
specifier|const
name|char
modifier|*
name|magic
decl_stmt|;
specifier|const
name|char
modifier|*
name|default_sufx
decl_stmt|;
name|f_init_t
name|f_init
decl_stmt|;
name|f_compress_t
name|f_compress
decl_stmt|;
block|}
struct|;
end_struct

end_unit

