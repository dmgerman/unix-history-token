begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* global.h:  The global variables for bc.  */
end_comment

begin_comment
comment|/*  This file is part of bc written for MINIX.     Copyright (C) 1991, 1992, 1993, 1994 Free Software Foundation, Inc.      This program is free software; you can redistribute it and/or modify     it under the terms of the GNU General Public License as published by     the Free Software Foundation; either version 2 of the License , or     (at your option) any later version.      This program is distributed in the hope that it will be useful,     but WITHOUT ANY WARRANTY; without even the implied warranty of     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the     GNU General Public License for more details.      You should have received a copy of the GNU General Public License     along with this program; see the file COPYING.  If not, write to     the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.      You may contact the author by:        e-mail:  phil@cs.wwu.edu       us-mail:  Philip A. Nelson                 Computer Science Department, 9062                 Western Washington University                 Bellingham, WA 98226-9062  *************************************************************************/
end_comment

begin_comment
comment|/* The current break level's label. */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|break_label
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The current if statement's else label or label after else. */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|if_label
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The current for statement label for continuing the loop. */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|continue_label
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Next available label number. */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|next_label
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Byte code character storage.  Used in many places for generation of code. */
end_comment

begin_decl_stmt
name|EXTERN
name|char
name|genstr
index|[
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Count of characters printed to the output in compile_only mode. */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|out_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Have we generated any code since the last initialization of the code    generator.  */
end_comment

begin_decl_stmt
name|EXTERN
name|char
name|did_gen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Is this run an interactive execution.  (Is stdin a terminal?) */
end_comment

begin_decl_stmt
name|EXTERN
name|char
name|interactive
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Just generate the byte code.  -c flag. */
end_comment

begin_decl_stmt
name|EXTERN
name|char
name|compile_only
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Load the standard math functions.  -l flag. */
end_comment

begin_decl_stmt
name|EXTERN
name|char
name|use_math
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Give a warning on use of any non-standard feature (non-POSIX).  -w flag. */
end_comment

begin_decl_stmt
name|EXTERN
name|char
name|warn_not_std
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Accept POSIX bc only!  -s flag. */
end_comment

begin_decl_stmt
name|EXTERN
name|char
name|std_only
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global variables for the bc machine. All will be dynamic in size.*/
end_comment

begin_comment
comment|/* Function storage. main is (0) and functions (1-f_count) */
end_comment

begin_decl_stmt
name|EXTERN
name|bc_function
modifier|*
name|functions
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
modifier|*
name|f_names
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|f_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Variable stoarge and reverse names. */
end_comment

begin_decl_stmt
name|EXTERN
name|bc_var
modifier|*
modifier|*
name|variables
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
modifier|*
name|v_names
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|v_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Array Variable storage and reverse names. */
end_comment

begin_decl_stmt
name|EXTERN
name|bc_var_array
modifier|*
modifier|*
name|arrays
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
modifier|*
name|a_names
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|a_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Execution stack. */
end_comment

begin_decl_stmt
name|EXTERN
name|estack_rec
modifier|*
name|ex_stack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Function return stack. */
end_comment

begin_decl_stmt
name|EXTERN
name|fstack_rec
modifier|*
name|fn_stack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Other "storage". */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|i_base
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|o_base
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|scale
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
name|c_code
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|out_col
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
name|runtime_error
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|program_counter
name|pc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Input Line numbers and other error information. */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|line_no
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|had_error
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For larger identifiers, a tree, and how many "storage" locations    have been allocated. */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|next_array
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|next_func
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|next_var
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|id_rec
modifier|*
name|name_tree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For error message production */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
modifier|*
name|g_argv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|g_argc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
name|is_std_in
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defined in number.c */
end_comment

begin_decl_stmt
specifier|extern
name|bc_num
name|_zero_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bc_num
name|_one_
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For use with getopt.  Do not declare them here.*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|optind
decl_stmt|;
end_decl_stmt

end_unit

