begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Language-specific hook definitions for C front end.    Copyright (C) 1991 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"input.h"
end_include

begin_comment
comment|/* Each of the functions defined here    is an alternative to a function in objc-actions.c.  */
end_comment

begin_function
name|int
name|lang_decode_option
parameter_list|(
name|p
parameter_list|)
name|char
modifier|*
name|p
decl_stmt|;
block|{
return|return
name|c_decode_option
argument_list|(
name|p
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|lang_init
parameter_list|()
block|{
comment|/* the beginning of the file is a new line; check for # */
comment|/* With luck, we discover the real source file's name from that      and put it in input_filename.  */
name|ungetc
argument_list|(
name|check_newline
argument_list|()
argument_list|,
name|finput
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|lang_finish
parameter_list|()
block|{ }
end_function

begin_function
name|char
modifier|*
name|lang_identify
parameter_list|()
block|{
return|return
literal|"c"
return|;
block|}
end_function

begin_function
name|void
name|print_lang_statistics
parameter_list|()
block|{ }
end_function

begin_comment
comment|/* Used by c-lex.c, but only for objc.  */
end_comment

begin_function
name|tree
name|lookup_interface
parameter_list|(
name|arg
parameter_list|)
name|tree
name|arg
decl_stmt|;
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|tree
name|is_class_name
parameter_list|(
name|arg
parameter_list|)
name|tree
name|arg
decl_stmt|;
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|maybe_objc_check_decl
parameter_list|(
name|decl
parameter_list|)
name|tree
name|decl
decl_stmt|;
block|{ }
end_function

begin_function
name|int
name|maybe_objc_comptypes
parameter_list|(
name|lhs
parameter_list|,
name|rhs
parameter_list|,
name|reflexive
parameter_list|)
name|tree
name|lhs
decl_stmt|,
name|rhs
decl_stmt|;
name|int
name|reflexive
decl_stmt|;
block|{
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_function
name|tree
name|maybe_objc_method_name
parameter_list|(
name|decl
parameter_list|)
name|tree
name|decl
decl_stmt|;
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|tree
name|maybe_building_objc_message_expr
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|recognize_objc_keyword
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|tree
name|build_objc_string
parameter_list|(
name|len
parameter_list|,
name|str
parameter_list|)
name|int
name|len
decl_stmt|;
name|char
modifier|*
name|str
decl_stmt|;
block|{
name|abort
argument_list|()
expr_stmt|;
return|return
name|NULL_TREE
return|;
block|}
end_function

begin_function
name|void
name|GNU_xref_begin
parameter_list|()
block|{
name|fatal
argument_list|(
literal|"GCC does not yet support XREF"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|GNU_xref_end
parameter_list|()
block|{
name|fatal
argument_list|(
literal|"GCC does not yet support XREF"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

