begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Header file for command-reading library command.c.    Copyright (C) 1986, 1989 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 1, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* This structure records one command'd definition.  */
end_comment

begin_struct
struct|struct
name|cmd_list_element
block|{
comment|/* Points to next command in this list.  */
name|struct
name|cmd_list_element
modifier|*
name|next
decl_stmt|;
comment|/* Name of this command.  */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Command class; class values are chosen by application program.  */
name|int
name|class
decl_stmt|;
comment|/* Function definition of this command.        Zero for command class names and for help topics that        are not really commands.  */
name|void
function_decl|(
modifier|*
name|function
function_decl|)
parameter_list|()
function_decl|;
comment|/* Documentation of this command (or help topic).        First line is brief documentation; remaining lines form, with it,        the full documentation.  First line should end with a period.        Entire string should also end with a period, not a newline.  */
name|char
modifier|*
name|doc
decl_stmt|;
comment|/* Auxiliary information.        It is up to the calling program to decide what this means.  */
name|char
modifier|*
name|aux
decl_stmt|;
comment|/* Nonzero identifies a prefix command.  For them, the address        of the variable containing the list of subcommands.  */
name|struct
name|cmd_list_element
modifier|*
modifier|*
name|prefixlist
decl_stmt|;
comment|/* For prefix commands only:        String containing prefix commands to get here: this one        plus any others needed to get to it.  Should end in a space.        It is used before the word "command" in describing the        commands reached through this prefix.  */
name|char
modifier|*
name|prefixname
decl_stmt|;
comment|/* For prefix commands only:        nonzero means do not get an error if subcommand is not        recognized; call the prefix's own function in that case.  */
name|char
name|allow_unknown
decl_stmt|;
comment|/* Nonzero says this is an abbreviation, and should not        be mentioned in lists of commands.        This allows "br<tab>" to complete to "break", which it        otherwise wouldn't.  */
name|char
name|abbrev_flag
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Forward-declarations of the entry-points of command.c.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|add_cmd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|add_alias_cmd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|add_prefix_cmd
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|lookup_cmd
argument_list|()
decl_stmt|,
modifier|*
name|lookup_cmd_1
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|complete_on_cmdlist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|delete_cmd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|help_cmd
parameter_list|()
function_decl|;
end_function_decl

end_unit

