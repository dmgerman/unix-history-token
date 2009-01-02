begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2008, Ulf Lilleengen<lulf@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RCSFILE_H_
end_ifndef

begin_define
define|#
directive|define
name|_RCSFILE_H_
end_define

begin_comment
comment|/* RCSFILE fields. */
end_comment

begin_define
define|#
directive|define
name|RCSFILE_HEAD
value|0
end_define

begin_define
define|#
directive|define
name|RCSFILE_BRANCH
value|1
end_define

begin_define
define|#
directive|define
name|RCSFILE_STRICT
value|2
end_define

begin_define
define|#
directive|define
name|RCSFILE_COMMENT
value|3
end_define

begin_define
define|#
directive|define
name|RCSFILE_EXPAND
value|4
end_define

begin_define
define|#
directive|define
name|RCSFILE_DESC
value|5
end_define

begin_struct_decl
struct_decl|struct
name|rcsfile
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|delta
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|stream
struct_decl|;
end_struct_decl

begin_comment
comment|/* Fetching, sending and writing an RCS file. */
end_comment

begin_function_decl
name|struct
name|rcsfile
modifier|*
name|rcsfile_frompath
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rcsfile_send_details
parameter_list|(
name|struct
name|rcsfile
modifier|*
parameter_list|,
name|struct
name|stream
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rcsfile_write
parameter_list|(
name|struct
name|rcsfile
modifier|*
parameter_list|,
name|struct
name|stream
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rcsfile_print
parameter_list|(
name|struct
name|rcsfile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rcsfile_free
parameter_list|(
name|struct
name|rcsfile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Used for adding and setting rcsfile values. */
end_comment

begin_function_decl
name|void
name|rcsfile_addaccess
parameter_list|(
name|struct
name|rcsfile
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rcsfile_addtag
parameter_list|(
name|struct
name|rcsfile
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rcsfile_importtag
parameter_list|(
name|struct
name|rcsfile
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rcsfile_deleterev
parameter_list|(
name|struct
name|rcsfile
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rcsfile_deletetag
parameter_list|(
name|struct
name|rcsfile
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|delta
modifier|*
name|rcsfile_getdelta
parameter_list|(
name|struct
name|rcsfile
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rcsfile_setval
parameter_list|(
name|struct
name|rcsfile
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions used for operating on RCS deltas. */
end_comment

begin_function_decl
name|struct
name|delta
modifier|*
name|rcsfile_addelta
parameter_list|(
name|struct
name|rcsfile
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rcsfile_importdelta
parameter_list|(
name|struct
name|rcsfile
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rcsdelta_addlog
parameter_list|(
name|struct
name|delta
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rcsdelta_addtext
parameter_list|(
name|struct
name|delta
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rcsdelta_appendlog
parameter_list|(
name|struct
name|delta
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rcsdelta_appendtext
parameter_list|(
name|struct
name|delta
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rcsdelta_setstate
parameter_list|(
name|struct
name|delta
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rcsdelta_truncatetext
parameter_list|(
name|struct
name|delta
modifier|*
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rcsdelta_truncatelog
parameter_list|(
name|struct
name|delta
modifier|*
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RCSFILE_H_ */
end_comment

end_unit

