begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Process machine description and calculate constant conditions.    Copyright (C) 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GCC is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street, Fifth Floor,    Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* In a machine description, all of the insn patterns - define_insn,    define_expand, define_split, define_peephole, define_peephole2 -    contain an optional C expression which makes the final decision    about whether or not this pattern is usable.  That expression may    turn out to be always false when the compiler is built.  If it is,    most of the programs that generate code from the machine    description can simply ignore the entire pattern.  */
end_comment

begin_include
include|#
directive|include
file|"bconfig.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"coretypes.h"
end_include

begin_include
include|#
directive|include
file|"tm.h"
end_include

begin_include
include|#
directive|include
file|"rtl.h"
end_include

begin_include
include|#
directive|include
file|"errors.h"
end_include

begin_include
include|#
directive|include
file|"hashtab.h"
end_include

begin_include
include|#
directive|include
file|"gensupport.h"
end_include

begin_comment
comment|/* so we can include except.h in the generated file.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|saw_eh_return
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|write_header
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|write_conditions
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|write_one_condition
parameter_list|(
name|void
modifier|*
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Generate the header for insn-conditions.c.  */
end_comment

begin_function
specifier|static
name|void
name|write_header
parameter_list|(
name|void
parameter_list|)
block|{
name|puts
argument_list|(
literal|"\ /* Generated automatically by the program `genconditions' from the target\n\    machine description file.  */\n\ \n\ #include \"bconfig.h\"\n\ #include \"system.h\"\n\ \n\ /* It is necessary, but not entirely safe, to include the headers below\n\    in a generator program.  As a defensive measure, don't do so when the\n\    table isn't going to have anything in it.  */\n\ #if GCC_VERSION>= 3001\n\ \n\ /* Do not allow checking to confuse the issue.  */\n\ #undef ENABLE_CHECKING\n\ #undef ENABLE_TREE_CHECKING\n\ #undef ENABLE_RTL_CHECKING\n\ #undef ENABLE_RTL_FLAG_CHECKING\n\ #undef ENABLE_GC_CHECKING\n\ #undef ENABLE_GC_ALWAYS_COLLECT\n\ \n\ #include \"coretypes.h\"\n\ #include \"tm.h\"\n\ #include \"insn-constants.h\"\n\ #include \"rtl.h\"\n\ #include \"tm_p.h\"\n\ #include \"function.h\"\n\ \n\ /* Fake - insn-config.h doesn't exist yet.  */\n\ #define MAX_RECOG_OPERANDS 10\n\ #define MAX_DUP_OPERANDS 10\n\ #define MAX_INSNS_PER_SPLIT 5\n\ \n\ #include \"regs.h\"\n\ #include \"recog.h\"\n\ #include \"real.h\"\n\ #include \"output.h\"\n\ #include \"flags.h\"\n\ #include \"hard-reg-set.h\"\n\ #include \"resource.h\"\n\ #include \"toplev.h\"\n\ #include \"reload.h\"\n\ #include \"tm-constrs.h\"\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|saw_eh_return
condition|)
name|puts
argument_list|(
literal|"#define HAVE_eh_return 1"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"#include \"except.h\"\n"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"\ /* Dummy external declarations.  */\n\ extern rtx insn;\n\ extern rtx ins1;\n\ extern rtx operands[];\n\ \n\ #endif /* gcc>= 3.0.1 */\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Write out one entry in the conditions table, using the data pointed    to by SLOT.  Each entry looks like this:     { "! optimize_size&& ! TARGET_READ_MODIFY_WRITE",      __builtin_constant_p (! optimize_size&& ! TARGET_READ_MODIFY_WRITE)      ? (int) (! optimize_size&& ! TARGET_READ_MODIFY_WRITE)      : -1) },  */
end_comment

begin_function
specifier|static
name|int
name|write_one_condition
parameter_list|(
name|void
modifier|*
modifier|*
name|slot
parameter_list|,
name|void
modifier|*
name|ARG_UNUSED
parameter_list|(
name|dummy
parameter_list|)
parameter_list|)
block|{
specifier|const
name|struct
name|c_test
modifier|*
name|test
init|=
operator|*
operator|(
specifier|const
expr|struct
name|c_test
operator|*
operator|*
operator|)
name|slot
decl_stmt|;
specifier|const
name|char
modifier|*
name|p
decl_stmt|;
name|print_rtx_ptr_loc
argument_list|(
name|test
operator|->
name|expr
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"  { \""
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
for|for
control|(
name|p
operator|=
name|test
operator|->
name|expr
init|;
operator|*
name|p
condition|;
name|p
operator|++
control|)
block|{
switch|switch
condition|(
operator|*
name|p
condition|)
block|{
case|case
literal|'\n'
case|:
name|fputs
argument_list|(
literal|"\\n\\"
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'\\'
case|:
case|case
literal|'\"'
case|:
name|putchar
argument_list|(
literal|'\\'
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
name|putchar
argument_list|(
operator|*
name|p
argument_list|)
expr_stmt|;
block|}
name|fputs
argument_list|(
literal|"\",\n    __builtin_constant_p "
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|print_c_condition
argument_list|(
name|test
operator|->
name|expr
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\n    ? (int) "
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|print_c_condition
argument_list|(
name|test
operator|->
name|expr
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\n    : -1 },\n"
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/* Write out the complete conditions table, its size, and a flag    indicating that gensupport.c can now do insn elision.  */
end_comment

begin_function
specifier|static
name|void
name|write_conditions
parameter_list|(
name|void
parameter_list|)
block|{
name|puts
argument_list|(
literal|"\ /* Structure definition duplicated from gensupport.h rather than\n\    drag in that file and its dependencies.  */\n\ struct c_test\n\ {\n\   const char *expr;\n\   int value;\n\ };\n\ \n\ /* This table lists each condition found in the machine description.\n\    Each condition is mapped to its truth value (0 or 1), or -1 if that\n\    cannot be calculated at compile time.\n\    If we don't have __builtin_constant_p, or it's not acceptable in array\n\    initializers, fall back to assuming that all conditions potentially\n\    vary at run time.  It works in 3.0.1 and later; 3.0 only when not\n\    optimizing.  */\n\ \n\ #if GCC_VERSION>= 3001\n\ static const struct c_test insn_conditions[] = {\n"
argument_list|)
expr_stmt|;
name|traverse_c_tests
argument_list|(
name|write_one_condition
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"\n};\n#endif /* gcc>= 3.0.1 */\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Emit code which will convert the C-format table to a    (define_conditions) form, which the MD reader can understand.    The result will be added to the set of files scanned by    'downstream' generators.  */
end_comment

begin_function
specifier|static
name|void
name|write_writer
parameter_list|(
name|void
parameter_list|)
block|{
name|puts
argument_list|(
literal|"int\n"
literal|"main(void)\n"
literal|"{\n"
literal|"  unsigned int i;\n"
literal|"  const char *p;\n"
literal|"  puts (\"(define_conditions [\");\n"
literal|"#if GCC_VERSION>= 3001\n"
literal|"  for (i = 0; i< ARRAY_SIZE (insn_conditions); i++)\n"
literal|"    {\n"
literal|"      printf (\"  (%d \\\"\", insn_conditions[i].value);\n"
literal|"      for (p = insn_conditions[i].expr; *p; p++)\n"
literal|"        {\n"
literal|"          switch (*p)\n"
literal|"	     {\n"
literal|"	     case '\\\\':\n"
literal|"	     case '\\\"': putchar ('\\\\'); break;\n"
literal|"	     default: break;\n"
literal|"	     }\n"
literal|"          putchar (*p);\n"
literal|"        }\n"
literal|"      puts (\"\\\")\");\n"
literal|"    }\n"
literal|"#endif /* gcc>= 3.0.1 */\n"
literal|"  puts (\"])\");\n"
literal|"  fflush (stdout);\n"
literal|"return ferror (stdout) != 0 ? FATAL_EXIT_CODE : SUCCESS_EXIT_CODE;\n"
literal|"}"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|rtx
name|desc
decl_stmt|;
name|int
name|pattern_lineno
decl_stmt|;
comment|/* not used */
name|int
name|code
decl_stmt|;
name|progname
operator|=
literal|"genconditions"
expr_stmt|;
if|if
condition|(
name|init_md_reader_args
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
operator|!=
name|SUCCESS_EXIT_CODE
condition|)
return|return
operator|(
name|FATAL_EXIT_CODE
operator|)
return|;
comment|/* Read the machine description.  */
while|while
condition|(
literal|1
condition|)
block|{
name|desc
operator|=
name|read_md_rtx
argument_list|(
operator|&
name|pattern_lineno
argument_list|,
operator|&
name|code
argument_list|)
expr_stmt|;
if|if
condition|(
name|desc
operator|==
name|NULL
condition|)
break|break;
comment|/* N.B. define_insn_and_split, define_cond_exec are handled 	 entirely within read_md_rtx; we never see them.  */
switch|switch
condition|(
name|GET_CODE
argument_list|(
name|desc
argument_list|)
condition|)
block|{
default|default:
break|break;
case|case
name|DEFINE_INSN
case|:
case|case
name|DEFINE_EXPAND
case|:
name|add_c_test
argument_list|(
name|XSTR
argument_list|(
name|desc
argument_list|,
literal|2
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|/* except.h needs to know whether there is an eh_return 	     pattern in the machine description.  */
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|XSTR
argument_list|(
name|desc
argument_list|,
literal|0
argument_list|)
argument_list|,
literal|"eh_return"
argument_list|)
condition|)
name|saw_eh_return
operator|=
literal|1
expr_stmt|;
break|break;
case|case
name|DEFINE_SPLIT
case|:
case|case
name|DEFINE_PEEPHOLE
case|:
case|case
name|DEFINE_PEEPHOLE2
case|:
name|add_c_test
argument_list|(
name|XSTR
argument_list|(
name|desc
argument_list|,
literal|1
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
name|write_header
argument_list|()
expr_stmt|;
name|write_conditions
argument_list|()
expr_stmt|;
name|write_writer
argument_list|()
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
return|return
operator|(
name|ferror
argument_list|(
name|stdout
argument_list|)
operator|!=
literal|0
condition|?
name|FATAL_EXIT_CODE
else|:
name|SUCCESS_EXIT_CODE
operator|)
return|;
block|}
end_function

end_unit

