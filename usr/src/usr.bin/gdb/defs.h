begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This code is derived from software copyrighted by the Free Software  * Foundation.  *  * Modified 1991 by Donn Seeley at UUNET Technologies, Inc.  * Modified 1990 by Van Jacobson at Lawrence Berkeley Laboratory.  *  *	@(#)defs.h	6.3 (Berkeley) 5/8/91  */
end_comment

begin_comment
comment|/* Basic definitions for GDB, the GNU debugger.    Copyright (C) 1986, 1989 Free Software Foundation, Inc.  This file is part of GDB.  GDB is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GDB; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|CORE_ADDR
value|unsigned int
end_define

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (a) : (b))
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|savestring
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|concat
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|xmalloc
argument_list|()
decl_stmt|,
modifier|*
name|xrealloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|parse_escape
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|reg_names
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Various possibilities for alloca.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sparc
end_ifdef

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|alloca
value|__builtin_alloca
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|char
modifier|*
name|alloca
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|quit_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|immediate_quit
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|QUIT
value|{ if (quit_flag) quit (); }
end_define

begin_comment
comment|/* Notes on classes: class_alias is for alias commands which are not    abbreviations of the original command.  */
end_comment

begin_enum
enum|enum
name|command_class
block|{
name|no_class
init|=
operator|-
literal|1
block|,
name|class_run
init|=
literal|0
block|,
name|class_vars
block|,
name|class_stack
block|,
name|class_files
block|,
name|class_support
block|,
name|class_info
block|,
name|class_breakpoint
block|,
name|class_alias
block|,
name|class_obscure
block|,
name|class_user
block|, }
enum|;
end_enum

begin_comment
comment|/* the cleanup list records things that have to be undone    if an error happens (descriptors to be closed, memory to be freed, etc.)    Each link in the chain records a function to call and an    argument to give it.     Use make_cleanup to add an element to the cleanup chain.    Use do_cleanups to do all cleanup actions back to a given    point in the chain.  Use discard_cleanups to remove cleanups    from the chain back to a given point, not doing them.  */
end_comment

begin_struct
struct|struct
name|cleanup
block|{
name|struct
name|cleanup
modifier|*
name|next
decl_stmt|;
name|void
function_decl|(
modifier|*
name|function
function_decl|)
parameter_list|()
function_decl|;
name|int
name|arg
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|do_cleanups
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|discard_cleanups
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|cleanup
modifier|*
name|make_cleanup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|cleanup
modifier|*
name|save_cleanups
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|restore_cleanups
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_current_contents
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reinitialize_more_filter
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fputs_filtered
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fprintf_filtered
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|printf_filtered
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_spaces_filtered
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|tilde_expand
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Structure for saved commands lines    (for breakpoints, defined commands, etc).  */
end_comment

begin_struct
struct|struct
name|command_line
block|{
name|struct
name|command_line
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|line
decl_stmt|;
name|int
name|type
decl_stmt|;
comment|/* statement type */
define|#
directive|define
name|CL_END
value|0
define|#
directive|define
name|CL_NORMAL
value|1
define|#
directive|define
name|CL_WHILE
value|2
define|#
directive|define
name|CL_IF
value|3
define|#
directive|define
name|CL_EXITLOOP
value|4
define|#
directive|define
name|CL_NOP
value|5
name|struct
name|command_line
modifier|*
name|body
decl_stmt|;
comment|/* body of loop for while, body of if */
name|struct
name|command_line
modifier|*
name|elsebody
decl_stmt|;
comment|/* body of else part of if */
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|struct
name|command_line
modifier|*
name|read_command_lines
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|do_command_lines
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* String containing the current directory (what getwd would return).  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|current_directory
decl_stmt|;
end_decl_stmt

end_unit

