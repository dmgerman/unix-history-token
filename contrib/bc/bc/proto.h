begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* proto.h: Prototype function definitions for "external" functions. */
end_comment

begin_comment
comment|/*  This file is part of GNU bc.     Copyright (C) 1991-1994, 1997, 2000 Free Software Foundation, Inc.      This program is free software; you can redistribute it and/or modify     it under the terms of the GNU General Public License as published by     the Free Software Foundation; either version 2 of the License , or     (at your option) any later version.      This program is distributed in the hope that it will be useful,     but WITHOUT ANY WARRANTY; without even the implied warranty of     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the     GNU General Public License for more details.      You should have received a copy of the GNU General Public License     along with this program; see the file COPYING.  If not, write to       The Free Software Foundation, Inc.       59 Temple Place, Suite 330       Boston, MA 02111 USA      You may contact the author by:        e-mail:  philnelson@acm.org       us-mail:  Philip A. Nelson                 Computer Science Department, 9062                 Western Washington University                 Bellingham, WA 98226-9062         *************************************************************************/
end_comment

begin_comment
comment|/* For the pc version using k&r ACK. (minix1.5 and earlier.) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SHORTNAMES
end_ifdef

begin_define
define|#
directive|define
name|init_numbers
value|i_numbers
end_define

begin_define
define|#
directive|define
name|push_constant
value|push__constant
end_define

begin_define
define|#
directive|define
name|load_const
value|in_load_const
end_define

begin_define
define|#
directive|define
name|yy_get_next_buffer
value|yyget_next_buffer
end_define

begin_define
define|#
directive|define
name|yy_init_buffer
value|yyinit_buffer
end_define

begin_define
define|#
directive|define
name|yy_last_accepting_state
value|yylast_accepting_state
end_define

begin_define
define|#
directive|define
name|arglist1
value|arg1list
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Include the standard library header files. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDLIB_H
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define the _PROTOTYPE macro if it is needed. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PROTOTYPE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|_PROTOTYPE
parameter_list|(
name|func
parameter_list|,
name|args
parameter_list|)
value|func args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_PROTOTYPE
parameter_list|(
name|func
parameter_list|,
name|args
parameter_list|)
value|func()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* From execute.c */
end_comment

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void stop_execution
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|unsigned char byte
argument_list|,
argument|(program_counter *pc)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void execute
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|char prog_char
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|char input_char
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void push_constant
argument_list|,
argument|(char (*in_char)(void), int conv_base)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void push_b10_const
argument_list|,
argument|(program_counter *pc)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void assign
argument_list|,
argument|(int c_code)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* From util.c */
end_comment

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|char
operator|*
name|strcopyof
argument_list|,
operator|(
name|char
operator|*
name|str
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|arg_list
operator|*
name|nextarg
argument_list|,
operator|(
name|arg_list
operator|*
name|args
operator|,
name|int
name|val
operator|,
name|int
name|is_var
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|char
operator|*
name|arg_str
argument_list|,
operator|(
name|arg_list
operator|*
name|args
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|char
operator|*
name|call_str
argument_list|,
operator|(
name|arg_list
operator|*
name|args
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void free_args
argument_list|,
argument|(arg_list *args)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void check_params
argument_list|,
argument|(arg_list *params, arg_list *autos)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void init_gen
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void generate
argument_list|,
argument|(char *str)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void run_code
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void out_char
argument_list|,
argument|(int ch)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void out_schar
argument_list|,
argument|(int ch)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|id_rec
operator|*
name|find_id
argument_list|,
operator|(
name|id_rec
operator|*
name|tree
operator|,
name|char
operator|*
name|id
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int insert_id_rec
argument_list|,
argument|(id_rec **root, id_rec *new_id)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void init_tree
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int lookup
argument_list|,
argument|(char *name, int namekind)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|char
operator|*
name|bc_malloc
argument_list|,
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void out_of_memory
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void welcome
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void warranty
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void show_bc_version
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void limits
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void yyerror
argument_list|,
argument|(char *str ,...)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void warn
argument_list|,
argument|(char *mesg ,...)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void rt_error
argument_list|,
argument|(char *mesg ,...)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void rt_warn
argument_list|,
argument|(char *mesg ,...)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* From load.c */
end_comment

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void init_load
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void addbyte
argument_list|,
argument|(int byte)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void def_label
argument_list|,
argument|(long lab)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|long long_val
argument_list|,
argument|(char **str)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void load_code
argument_list|,
argument|(char *code)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* From main.c */
end_comment

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int open_new_file
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void new_yy_file
argument_list|,
argument|(FILE *file)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void use_quit
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* From storage.c */
end_comment

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void init_storage
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void more_functions
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void more_variables
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void more_arrays
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void clear_func
argument_list|,
argument|(int func )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int fpop
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void fpush
argument_list|,
argument|(int val )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void pop
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void push_copy
argument_list|,
argument|(bc_num num )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void push_num
argument_list|,
argument|(bc_num num )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|char check_stack
argument_list|,
argument|(int depth )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|bc_var
operator|*
name|get_var
argument_list|,
operator|(
name|int
name|var_name
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|bc_num
operator|*
name|get_array_num
argument_list|,
operator|(
name|int
name|var_index
operator|,
name|long
name|index
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void store_var
argument_list|,
argument|(int var_name )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void store_array
argument_list|,
argument|(int var_name )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void load_var
argument_list|,
argument|(int var_name )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void load_array
argument_list|,
argument|(int var_name )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void decr_var
argument_list|,
argument|(int var_name )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void decr_array
argument_list|,
argument|(int var_name )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void incr_var
argument_list|,
argument|(int var_name )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void incr_array
argument_list|,
argument|(int var_name )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void auto_var
argument_list|,
argument|(int name )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void free_a_tree
argument_list|,
argument|(bc_array_node *root, int depth )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void pop_vars
argument_list|,
argument|(arg_list *list )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void process_params
argument_list|,
argument|(program_counter *pc, int func )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* For the scanner and parser.... */
end_comment

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int yyparse
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int yylex
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBEDIT
argument_list|)
end_if

begin_comment
comment|/* The *?*&^ prompt function */
end_comment

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|char
operator|*
name|null_prompt
argument_list|,
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Other things... */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_UNISTD_H
end_ifndef

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int getopt
argument_list|,
argument|(int, char *[], CONST char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

