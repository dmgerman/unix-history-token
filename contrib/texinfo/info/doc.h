begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* doc.h -- Structure associating function pointers with documentation. */
end_comment

begin_comment
comment|/* This file is part of GNU Info, a program for reading online documentation    stored in Info format.     Copyright (C) 1993 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DOC_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|DOC_H
end_define

begin_include
include|#
directive|include
file|"info.h"
end_include

begin_comment
comment|/* for NAMED_FUNCTIONS, VFunction, etc.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|VFunction
modifier|*
name|func
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|NAMED_FUNCTIONS
argument_list|)
name|char
modifier|*
name|func_name
decl_stmt|;
endif|#
directive|endif
comment|/* NAMED_FUNCTIONS */
name|char
modifier|*
name|doc
decl_stmt|;
block|}
name|FUNCTION_DOC
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|FUNCTION_DOC
name|function_doc_array
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|function_documentation
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|key_documentation
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|pretty_keyname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|replace_in_documentation
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_document_key
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_map_to_message_buffer
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NAMED_FUNCTIONS
argument_list|)
end_if

begin_function_decl
specifier|extern
name|char
modifier|*
name|function_name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VFunction
modifier|*
name|named_function
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NAMED_FUNCTIONS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !DOC_H */
end_comment

end_unit

