begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* MI Command Set - breakpoint and watchpoint commands.    Copyright 2000, 2001, 2002 Free Software Foundation, Inc.    Contributed by Cygnus Solutions (a Red Hat company).     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"mi-cmds.h"
end_include

begin_include
include|#
directive|include
file|"mi-getopt.h"
end_include

begin_include
include|#
directive|include
file|"ui-out.h"
end_include

begin_include
include|#
directive|include
file|"symtab.h"
end_include

begin_include
include|#
directive|include
file|"source.h"
end_include

begin_comment
comment|/* Return to the client the absolute path and line number of the     current file being executed. */
end_comment

begin_function
name|enum
name|mi_cmd_result
name|mi_cmd_file_list_exec_source_file
parameter_list|(
name|char
modifier|*
name|command
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
name|int
name|argc
parameter_list|)
block|{
name|struct
name|symtab_and_line
name|st
decl_stmt|;
name|int
name|optind
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|optarg
decl_stmt|;
if|if
condition|(
operator|!
name|mi_valid_noargs
argument_list|(
literal|"mi_cmd_file_list_exec_source_file"
argument_list|,
name|argc
argument_list|,
name|argv
argument_list|)
condition|)
name|error
argument_list|(
literal|"mi_cmd_file_list_exec_source_file: Usage: No args"
argument_list|)
expr_stmt|;
comment|/* Set the default file and line, also get them */
name|set_default_source_symtab_and_line
argument_list|()
expr_stmt|;
name|st
operator|=
name|get_current_source_symtab_and_line
argument_list|()
expr_stmt|;
comment|/* We should always get a symtab.       Apparently, filename does not need to be tested for NULL.      The documentation in symtab.h suggests it will always be correct */
if|if
condition|(
operator|!
name|st
operator|.
name|symtab
condition|)
name|error
argument_list|(
literal|"mi_cmd_file_list_exec_source_file: No symtab"
argument_list|)
expr_stmt|;
comment|/* Extract the fullname if it is not known yet */
if|if
condition|(
name|st
operator|.
name|symtab
operator|->
name|fullname
operator|==
name|NULL
condition|)
name|symtab_to_filename
argument_list|(
name|st
operator|.
name|symtab
argument_list|)
expr_stmt|;
comment|/* We may not be able to open the file (not available). */
if|if
condition|(
name|st
operator|.
name|symtab
operator|->
name|fullname
operator|==
name|NULL
condition|)
name|error
argument_list|(
literal|"mi_cmd_file_list_exec_source_file: File not found"
argument_list|)
expr_stmt|;
comment|/* Print to the user the line, filename and fullname */
name|ui_out_field_int
argument_list|(
name|uiout
argument_list|,
literal|"line"
argument_list|,
name|st
operator|.
name|line
argument_list|)
expr_stmt|;
name|ui_out_field_string
argument_list|(
name|uiout
argument_list|,
literal|"file"
argument_list|,
name|st
operator|.
name|symtab
operator|->
name|filename
argument_list|)
expr_stmt|;
name|ui_out_field_string
argument_list|(
name|uiout
argument_list|,
literal|"fullname"
argument_list|,
name|st
operator|.
name|symtab
operator|->
name|fullname
argument_list|)
expr_stmt|;
return|return
name|MI_CMD_DONE
return|;
block|}
end_function

end_unit

