begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2006, Maxime Henrion<mux@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DIFF_H_
end_ifndef

begin_define
define|#
directive|define
name|_DIFF_H_
end_define

begin_struct_decl
struct_decl|struct
name|stream
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|keyword
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|file_update
struct_decl|;
end_struct_decl

begin_comment
comment|/* Description of an RCS delta. */
end_comment

begin_struct
struct|struct
name|diffinfo
block|{
name|char
modifier|*
name|di_rcsfile
decl_stmt|;
comment|/* RCS filename */
name|char
modifier|*
name|di_cvsroot
decl_stmt|;
comment|/* CVS root prefix */
name|char
modifier|*
name|di_revnum
decl_stmt|;
comment|/* Revision number */
name|char
modifier|*
name|di_revdate
decl_stmt|;
comment|/* Revision date */
name|char
modifier|*
name|di_author
decl_stmt|;
comment|/* Author of the delta */
name|char
modifier|*
name|di_tag
decl_stmt|;
comment|/* CVS tag, if any */
name|char
modifier|*
name|di_state
decl_stmt|;
comment|/* State of the branch */
name|int
name|di_expand
decl_stmt|;
comment|/* CVS expansion mode */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|diff_apply
parameter_list|(
name|struct
name|stream
modifier|*
parameter_list|,
name|struct
name|stream
modifier|*
parameter_list|,
name|struct
name|stream
modifier|*
parameter_list|,
name|struct
name|keyword
modifier|*
parameter_list|,
name|struct
name|diffinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DIFF_H_ */
end_comment

end_unit

