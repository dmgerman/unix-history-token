begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 1986, Larry Wall  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following condition is met:  * 1. Redistributions of source code must retain the above copyright notice,  * this condition and the following disclaimer.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * patch - a program to apply diffs to original files  *  * -C option added in 1998, original code by Marc Espie, based on FreeBSD  * behaviour  *  * $OpenBSD: pch.h,v 1.9 2003/10/31 20:20:45 millert Exp $  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|OLD_FILE
value|0
end_define

begin_define
define|#
directive|define
name|NEW_FILE
value|1
end_define

begin_define
define|#
directive|define
name|INDEX_FILE
value|2
end_define

begin_define
define|#
directive|define
name|MAX_FILE
value|3
end_define

begin_struct
struct|struct
name|file_name
block|{
name|char
modifier|*
name|path
decl_stmt|;
name|bool
name|exists
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|re_patch
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|open_patch_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_hunkmax
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|there_is_another_patch
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|another_hunk
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|pch_swap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|pfetch
parameter_list|(
name|LINENUM
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|short
name|pch_line_len
parameter_list|(
name|LINENUM
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LINENUM
name|pch_first
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LINENUM
name|pch_ptrn_lines
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LINENUM
name|pch_newfirst
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LINENUM
name|pch_repl_lines
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LINENUM
name|pch_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LINENUM
name|pch_context
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LINENUM
name|pch_hunk_beg
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
name|pch_char
parameter_list|(
name|LINENUM
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_ed_script
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

