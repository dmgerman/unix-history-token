begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* Input routines.     Copyright (C) 1989-1998, 2002-2003 Free Software Foundation, Inc.    Written by Douglas C. Schmidt<schmidt@ics.uci.edu>    and Bruno Haible<bruno@clisp.org>.     This file is part of GNU GPERF.     GNU GPERF is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GNU GPERF is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; see the file COPYING.    If not, write to the Free Software Foundation, Inc.,    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|input_h
end_ifndef

begin_define
define|#
directive|define
name|input_h
value|1
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"keyword-list.h"
end_include

begin_decl_stmt
name|class
name|Input
block|{
name|public
label|:
name|Input
argument_list|(
name|FILE
operator|*
name|stream
argument_list|,
name|Keyword_Factory
operator|*
name|keyword_factory
argument_list|)
expr_stmt|;
operator|~
name|Input
argument_list|()
expr_stmt|;
name|void
name|read_input
parameter_list|()
function_decl|;
name|private
label|:
comment|/* Input stream.  */
name|FILE
modifier|*
name|_stream
decl_stmt|;
comment|/* Creates the keywords.  */
name|Keyword_Factory
modifier|*
specifier|const
name|_factory
decl_stmt|;
name|public
label|:
comment|/* Memory block containing the entire input.  */
name|char
modifier|*
name|_input
decl_stmt|;
name|char
modifier|*
name|_input_end
decl_stmt|;
comment|/* The C code from the declarations section.  */
specifier|const
name|char
modifier|*
name|_verbatim_declarations
decl_stmt|;
specifier|const
name|char
modifier|*
name|_verbatim_declarations_end
decl_stmt|;
name|unsigned
name|int
name|_verbatim_declarations_lineno
decl_stmt|;
comment|/* The C code from the end of the file.  */
specifier|const
name|char
modifier|*
name|_verbatim_code
decl_stmt|;
specifier|const
name|char
modifier|*
name|_verbatim_code_end
decl_stmt|;
name|unsigned
name|int
name|_verbatim_code_lineno
decl_stmt|;
comment|/* Declaration of struct type for a keyword and its attributes.  */
specifier|const
name|char
modifier|*
name|_struct_decl
decl_stmt|;
name|unsigned
name|int
name|_struct_decl_lineno
decl_stmt|;
comment|/* Return type of the lookup function.  */
specifier|const
name|char
modifier|*
name|_return_type
decl_stmt|;
comment|/* Shorthand for user-defined struct tag type.  */
specifier|const
name|char
modifier|*
name|_struct_tag
decl_stmt|;
comment|/* List of all keywords.  */
name|Keyword_List
modifier|*
name|_head
decl_stmt|;
comment|/* Whether the keyword chars would have different values in a different      character set.  */
name|bool
name|_charset_dependent
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

