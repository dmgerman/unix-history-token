begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* cmds.h -- declarations for cmds.c.    $Id: cmds.h,v 1.4 1999/04/25 20:43:51 karl Exp $     Copyright (C) 1998, 99 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License along    with this program; if not, write to the Free Software Foundation, Inc.,    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CMDS_H
end_ifndef

begin_define
define|#
directive|define
name|CMDS_H
end_define

begin_comment
comment|/* The three arguments a command can get are a flag saying whether it is    before argument parsing (START) or after (END), the starting position    of the arguments, and the ending position.  */
end_comment

begin_typedef
typedef|typedef
name|void
name|COMMAND_FUNCTION
parameter_list|()
function_decl|;
end_typedef

begin_comment
comment|/* So we can say COMMAND_FUNCTION *foo; */
end_comment

begin_comment
comment|/* Each command has an associated function.  When the command is    encountered in the text, the associated function is called with START    as the argument.  If the function expects arguments in braces, it    remembers itself on the stack.  When the corresponding close brace is    encountered, the function is called with END as the argument. */
end_comment

begin_define
define|#
directive|define
name|START
value|0
end_define

begin_define
define|#
directive|define
name|END
value|1
end_define

begin_comment
comment|/* Does the command expect braces?  */
end_comment

begin_define
define|#
directive|define
name|NO_BRACE_ARGS
value|0
end_define

begin_define
define|#
directive|define
name|BRACE_ARGS
value|1
end_define

begin_define
define|#
directive|define
name|MAYBE_BRACE_ARGS
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|COMMAND_FUNCTION
modifier|*
name|proc
decl_stmt|;
name|int
name|argument_in_braces
decl_stmt|;
block|}
name|COMMAND
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|COMMAND
name|command_table
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !CMDS_H */
end_comment

end_unit

