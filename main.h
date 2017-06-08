begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: main.h,v 1.27 2017/03/03 14:23:23 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2009, 2010, 2011 Kristaps Dzonsons<kristaps@bsd.lv>  * Copyright (c) 2014, 2015 Ingo Schwarze<schwarze@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHORS DISCLAIM ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_struct_decl
struct_decl|struct
name|roff_man
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|manoutput
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Definitions for main.c-visible output device functions, e.g., -Thtml  * and -Tascii.  Note that ascii_alloc() is named as such in  * anticipation of latin1_alloc() and so on, all of which map into the  * terminal output routines with different character settings.  */
end_comment

begin_function_decl
name|void
modifier|*
name|html_alloc
parameter_list|(
specifier|const
name|struct
name|manoutput
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|html_mdoc
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|struct
name|roff_man
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|html_man
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|struct
name|roff_man
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|html_free
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tree_mdoc
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|struct
name|roff_man
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tree_man
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|struct
name|roff_man
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|man_mdoc
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|struct
name|roff_man
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|man_man
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|struct
name|roff_man
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|locale_alloc
parameter_list|(
specifier|const
name|struct
name|manoutput
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|utf8_alloc
parameter_list|(
specifier|const
name|struct
name|manoutput
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ascii_alloc
parameter_list|(
specifier|const
name|struct
name|manoutput
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ascii_free
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|pdf_alloc
parameter_list|(
specifier|const
name|struct
name|manoutput
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ps_alloc
parameter_list|(
specifier|const
name|struct
name|manoutput
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pspdf_free
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terminal_mdoc
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|struct
name|roff_man
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terminal_man
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|struct
name|roff_man
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terminal_sepline
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|markdown_mdoc
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|struct
name|roff_man
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

