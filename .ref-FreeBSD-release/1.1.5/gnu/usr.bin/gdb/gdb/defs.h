begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Basic, host-specific, and target-specific definitions for GDB.    Copyright (C) 1986, 1989, 1991 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEFS_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEFS_H
value|1
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* First include ansidecl.h so we can use the various macro definitions    here and in all subsequent file inclusions.  */
end_comment

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_comment
comment|/* An address in the program being debugged.  Host byte order.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CORE_ADDR_TYPE
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|CORE_ADDR
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|CORE_ADDR_TYPE
name|CORE_ADDR
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/* Gdb does *lots* of string compares.  Use macros to speed them up by    avoiding function calls if the first characters are not the same. */
end_comment

begin_define
define|#
directive|define
name|STRCMP
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(*(a) == *(b) ? strcmp ((a), (b)) : (int)*(a) - (int)*(b))
end_define

begin_define
define|#
directive|define
name|STREQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(*(a) == *(b) ? !strcmp ((a), (b)) : 0)
end_define

begin_define
define|#
directive|define
name|STREQN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(*(a) == *(b) ? !strncmp ((a), (b), (c)) : 0)
end_define

begin_comment
comment|/* The character GNU C++ uses to build identifiers that must be unique from    the program's identifiers (such as $this and $$vptr).  */
end_comment

begin_define
define|#
directive|define
name|CPLUS_MARKER
value|'$'
end_define

begin_comment
comment|/* May be overridden to '.' for SysV */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/* System call error return status */
end_comment

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

begin_decl_stmt
specifier|extern
name|int
name|sevenbit_strings
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|quit
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|QUIT
value|{ if (quit_flag) quit (); }
end_define

begin_comment
comment|/* Command classes are top-level categories into which commands are broken    down for "help" purposes.      Notes on classes: class_alias is for alias commands which are not    abbreviations of the original command.  class-pseudo is for commands    which are not really commands nor help topics ("stop").  */
end_comment

begin_enum
enum|enum
name|command_class
block|{
comment|/* Special args to help_list */
name|all_classes
init|=
operator|-
literal|2
block|,
name|all_commands
init|=
operator|-
literal|1
block|,
comment|/* Classes of commands */
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
block|,
name|class_maintenance
block|,
name|class_pseudo
block|}
enum|;
end_enum

begin_comment
comment|/* Languages represented in the symbol table and elsewhere.    This should probably be in language.h, but since enum's can't    be forward declared to satisfy opaque references before their    actual definition, needs to be here. */
end_comment

begin_enum
enum|enum
name|language
block|{
name|language_unknown
block|,
comment|/* Language not known */
name|language_auto
block|,
comment|/* Placeholder for automatic setting */
name|language_c
block|,
comment|/* C */
name|language_cplus
block|,
comment|/* C++ */
name|language_chill
block|,
comment|/* Chill */
name|language_m2
comment|/* Modula-2 */
block|}
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
argument_list|(
argument|*function
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|)
argument_list|)
expr_stmt|;
name|PTR
name|arg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* From blockframe.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inside_entry_func
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inside_entry_file
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
name|addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inside_main_func
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
name|pc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From ch-lang.c, for the moment. (FIXME) */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|chill_demangle
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From libiberty.a */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cplus_demangle
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cplus_mangle_opname
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From libmmalloc.a (memory mapped malloc library) */
end_comment

begin_decl_stmt
specifier|extern
name|PTR
name|mmalloc_attach
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PTR
name|mmalloc_detach
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PTR
name|mmalloc
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PTR
name|mrealloc
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|PTR
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mfree
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mmalloc_setkey
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|int
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PTR
name|mmalloc_getkey
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From utils.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|strcmp_iw
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|safe_strerror
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|safe_strsignal
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_malloc
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|request_quit
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|do_cleanups
name|PARAMS
argument_list|(
operator|(
expr|struct
name|cleanup
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|discard_cleanups
name|PARAMS
argument_list|(
operator|(
expr|struct
name|cleanup
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The bare make_cleanup function is one of those rare beasts that    takes almost any type of function as the first arg and anything that    will fit in a "void *" as the second arg.     Should be, once all calls and called-functions are cleaned up: extern struct cleanup * make_cleanup PARAMS ((void (*function) (void *), void *));     Until then, lint and/or various type-checking compiler options will    complain about make_cleanup calls.  It'd be wrong to just cast things,    since the type actually passed when the function is called would be    wrong.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|cleanup
modifier|*
name|make_cleanup
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|cleanup
modifier|*
name|save_cleanups
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|restore_cleanups
name|PARAMS
argument_list|(
operator|(
expr|struct
name|cleanup
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_current_contents
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|null_cleanup
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|myread
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|query
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|begin_line
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|wrap_here
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|reinitialize_more_filter
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|print_insn
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fputs_filtered
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|puts_filtered
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|vprintf_filtered
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vfprintf_filtered
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
name|fprintfi_filtered
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
name|printfi_filtered
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|print_spaces
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_spaces_filtered
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|n_spaces
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|gdb_printchar
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|FILE
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fprintf_symbol_filtered
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|char
operator|*
operator|,
expr|enum
name|language
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|perror_with_name
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_sys_errmsg
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From regex.c or libc.  BSD 4.4 declares this with the argument type as    "const char *" in unistd.h, so we can't declare the argument    as "char *".  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|re_comp
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From symfile.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|symbol_file_command
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From main.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|skip_quoted
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|gdb_readline
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|command_line_input
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_prompt
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|batch_mode
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|input_from_terminal_p
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From printcmd.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|set_next_address
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_address_symbolic
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|FILE
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_address
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From source.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|openp
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mod_path
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|directory_command
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_source_path
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From findvar.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|read_relative_register_raw_bytes
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From readline (but not in any readline .h files).  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tilde_expand
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|command_line
modifier|*
name|read_command_lines
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_command_lines
name|PARAMS
argument_list|(
operator|(
expr|struct
name|command_line
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* String containing the current directory (what getwd would return).  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|current_directory
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default radixes for input and output.  Only some values supported.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|input_radix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|output_radix
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Possibilities for prettyprint parameters to routines which print    things.  Like enum language, this should be in value.h, but needs    to be here for the same reason.  FIXME:  If we can eliminate this    as an arg to LA_VAL_PRINT, then we can probably move it back to    value.h. */
end_comment

begin_enum
enum|enum
name|val_prettyprint
block|{
name|Val_no_prettyprint
init|=
literal|0
block|,
name|Val_prettyprint
block|,
comment|/* Use the default setting which the user has specified.  */
name|Val_pretty_default
block|}
enum|;
end_enum

begin_escape
end_escape

begin_comment
comment|/* Host machine definition.  This will be a symlink to one of the    xm-*.h files, built by the `configure' script.  */
end_comment

begin_include
include|#
directive|include
file|"xm.h"
end_include

begin_comment
comment|/* Native machine support.  This will be a symlink to one of the    nm-*.h files, built by the `configure' script.  */
end_comment

begin_include
include|#
directive|include
file|"nm.h"
end_include

begin_comment
comment|/* If the xm.h file did not define the mode string used to open the    files, assume that binary files are opened the same way as text    files */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FOPEN_RB
end_ifndef

begin_include
include|#
directive|include
file|"fopen-same.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Allow things in gdb to be declared "const".  If compiling ANSI, it  * just works.  If compiling with gcc but non-ansi, redefine to __const__.  * If non-ansi, non-gcc, then eliminate "const" entirely, making those  * objects be read-write rather than read-only.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|const
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|const
value|__const__
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|const
end_define

begin_comment
comment|/*nothing*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GNUC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STDC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* const */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|volatile
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|volatile
value|__volatile__
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|volatile
end_define

begin_comment
comment|/*nothing*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GNUC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STDC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* volatile */
end_comment

begin_if
if|#
directive|if
literal|1
end_if

begin_define
define|#
directive|define
name|NORETURN
end_define

begin_comment
comment|/*nothing*/
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not 1 */
end_comment

begin_comment
comment|/* FIXME: This is bogus.  Having "volatile void" mean a function doesn't    return is a gcc extension and should be based on #ifdef __GNUC__.    Also, as of Sep 93 I'm told gcc is changing the syntax for ansi    reasons (so declaring exit here as "volatile void" and as "void" in    a system header loses).  Using the new "__attributes__ ((noreturn));"    syntax would lose for old versions of gcc; using      typedef void exit_fn_type PARAMS ((int));      volatile exit_fn_type exit;    would win.  */
end_comment

begin_comment
comment|/* Some compilers (many AT&T SVR4 compilers for instance), do not accept    declarations of functions that never return (exit for instance) as    "volatile void".  For such compilers "NORETURN" can be defined away    to keep them happy */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NORETURN
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__lucid
end_ifdef

begin_define
define|#
directive|define
name|NORETURN
end_define

begin_comment
comment|/*nothing*/
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NORETURN
value|volatile
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not 1 */
end_comment

begin_comment
comment|/* Defaults for system-wide constants (if not defined by xm.h, we fake it).  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|UINT_MAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|UINT_MAX
value|((unsigned int)(~0))
end_define

begin_comment
comment|/* 0xFFFFFFFF for 32-bits */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|INT_MAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|INT_MAX
value|((int)(UINT_MAX>> 1))
end_define

begin_comment
comment|/* 0x7FFFFFFF for 32-bits */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|INT_MIN
argument_list|)
end_if

begin_define
define|#
directive|define
name|INT_MIN
value|(-INT_MAX - 1)
end_define

begin_comment
comment|/* 0x80000000 for 32-bits */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ULONG_MAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|ULONG_MAX
value|((unsigned long)(~0L))
end_define

begin_comment
comment|/* 0xFFFFFFFF for 32-bits */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LONG_MAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|LONG_MAX
value|((long)(ULONG_MAX>> 1))
end_define

begin_comment
comment|/* 0x7FFFFFFF for 32-bits */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of bits in a char or unsigned char for the target machine.    Just like CHAR_BIT in<limits.h> but describes the target machine.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TARGET_CHAR_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_CHAR_BIT
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of bits in a short or unsigned short for the target machine. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TARGET_SHORT_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_SHORT_BIT
value|(2 * TARGET_CHAR_BIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of bits in an int or unsigned int for the target machine. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TARGET_INT_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_INT_BIT
value|(4 * TARGET_CHAR_BIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of bits in a long or unsigned long for the target machine. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TARGET_LONG_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_LONG_BIT
value|(4 * TARGET_CHAR_BIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of bits in a long long or unsigned long long for the target machine. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TARGET_LONG_LONG_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_LONG_LONG_BIT
value|(2 * TARGET_LONG_BIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of bits in a float for the target machine. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TARGET_FLOAT_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_FLOAT_BIT
value|(4 * TARGET_CHAR_BIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of bits in a double for the target machine. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TARGET_DOUBLE_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_DOUBLE_BIT
value|(8 * TARGET_CHAR_BIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of bits in a long double for the target machine.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TARGET_LONG_DOUBLE_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_LONG_DOUBLE_BIT
value|(2 * TARGET_DOUBLE_BIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of bits in a "complex" for the target machine. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TARGET_COMPLEX_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_COMPLEX_BIT
value|(2 * TARGET_FLOAT_BIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of bits in a "double complex" for the target machine. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TARGET_DOUBLE_COMPLEX_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_DOUBLE_COMPLEX_BIT
value|(2 * TARGET_DOUBLE_BIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of bits in a pointer for the target machine */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TARGET_PTR_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_PTR_BIT
value|TARGET_INT_BIT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default to support for "long long" if the host compiler being used is gcc.    Config files must define CC_HAS_LONG_LONG to use other host compilers    that are capable of supporting "long long", and to cause gdb to use that    support.  Not defining CC_HAS_LONG_LONG will suppress use of "long long"    regardless of what compiler is used.     FIXME: For now, automatic selection of "long long" as the default when    gcc is used is disabled, pending further testing.  Concerns include the    impact on gdb performance and the universality of bugfree long long    support on platforms that do have gcc.  Compiling with FORCE_LONG_LONG    will select "long long" use for testing purposes.  -fnf */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CC_HAS_LONG_LONG
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|FORCE_LONG_LONG
argument_list|)
end_if

begin_comment
comment|/* See FIXME above */
end_comment

begin_define
define|#
directive|define
name|CC_HAS_LONG_LONG
value|1
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
comment|/* LONGEST should not be a typedef, because "unsigned LONGEST" needs to work.    CC_HAS_LONG_LONG is defined if the host compiler supports "long long"    variables and we wish to make use of that support.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LONGEST
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|CC_HAS_LONG_LONG
end_ifdef

begin_define
define|#
directive|define
name|LONGEST
value|long long
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LONGEST
value|long
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
comment|/* Convert a LONGEST to an int.  This is used in contexts (e.g. number of    arguments to a function, number in a value history, register number, etc.)    where the value must not be larger than can fit in an int.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|longest_to_int
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|CC_HAS_LONG_LONG
end_ifdef

begin_define
define|#
directive|define
name|longest_to_int
parameter_list|(
name|x
parameter_list|)
value|(((x)> INT_MAX || (x)< INT_MIN) \ 			       ? (error ("Value out of range."),0) : (int) (x))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Assume sizeof (int) == sizeof (long).  */
end_comment

begin_define
define|#
directive|define
name|longest_to_int
parameter_list|(
name|x
parameter_list|)
value|((int) (x))
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
comment|/* If we picked up a copy of CHAR_BIT from a configuration file    (which may get it by including<limits.h>) then use it to set    the number of bits in a host char.  If not, use the same size    as the target. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CHAR_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|HOST_CHAR_BIT
value|CHAR_BIT
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HOST_CHAR_BIT
value|TARGET_CHAR_BIT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Assorted functions we can declare, now that const and volatile are     defined.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|savestring
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|msavestring
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strsave
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mstrsave
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|concat
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PTR
name|xmalloc
name|PARAMS
argument_list|(
operator|(
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PTR
name|xrealloc
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PTR
name|xmmalloc
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PTR
name|xmrealloc
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|PTR
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PTR
name|mmalloc
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PTR
name|mrealloc
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|PTR
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mfree
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mmcheck
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mmtrace
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|parse_escape
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|reg_names
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|NORETURN
name|void
comment|/* Does not return to the caller.  */
name|error
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|NORETURN
name|void
comment|/* Does not return to the caller.  */
name|fatal
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|NORETURN
name|void
comment|/* Not specified as volatile in ... */
name|exit
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 4.10.4.3 */
end_comment

begin_decl_stmt
specifier|extern
name|NORETURN
name|void
comment|/* Does not return to the caller.  */
name|nomem
name|PARAMS
argument_list|(
operator|(
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Reasons for calling return_to_top_level.  */
end_comment

begin_enum
enum|enum
name|return_reason
block|{
comment|/* User interrupt.  */
name|RETURN_QUIT
block|,
comment|/* Any other error.  */
name|RETURN_ERROR
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|RETURN_MASK_QUIT
value|(1<< (int)RETURN_QUIT)
end_define

begin_define
define|#
directive|define
name|RETURN_MASK_ERROR
value|(1<< (int)RETURN_ERROR)
end_define

begin_define
define|#
directive|define
name|RETURN_MASK_ALL
value|(RETURN_MASK_QUIT | RETURN_MASK_ERROR)
end_define

begin_typedef
typedef|typedef
name|int
name|return_mask
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|NORETURN
name|void
comment|/* Does not return to the caller.  */
name|return_to_top_level
name|PARAMS
argument_list|(
operator|(
expr|enum
name|return_reason
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|catch_errors
name|PARAMS
argument_list|(
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|char
operator|*
argument_list|)
operator|,
name|void
operator|*
operator|,
name|char
operator|*
operator|,
name|return_mask
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|warning_setup
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|warning
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Global functions from other, non-gdb GNU thingies (libiberty for    instance) */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|basename
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|getenv
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|buildargv
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|freeargv
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strerrno
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strsigno
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|errno_max
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|signo_max
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|strtoerrno
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|strtosigno
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strsignal
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From other system libraries */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PSIGNAL_IN_SIGNAL_H
end_ifndef

begin_decl_stmt
specifier|extern
name|void
name|psignal
name|PARAMS
argument_list|(
operator|(
name|unsigned
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For now, we can't include<stdlib.h> because it conflicts with    "../include/getopt.h".  (FIXME)     However, if a function is defined in the ANSI C standard and a prototype    for that function is defined and visible in any header file in an ANSI    conforming environment, then that prototype must match the definition in    the ANSI standard.  So we can just duplicate them here without conflict,    since they must be the same in all conforming ANSI environments.  If    these cause problems, then the environment is not ANSI conformant. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|fclose
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
name|stream
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 4.9.5.1 */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|perror
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 4.9.10.4 */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|atof
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|nptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 4.10.1.1 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|atoi
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 4.10.1.2 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MALLOC_INCOMPATIBLE
end_ifndef

begin_decl_stmt
specifier|extern
name|PTR
name|malloc
name|PARAMS
argument_list|(
operator|(
name|size_t
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 4.10.3.3 */
end_comment

begin_decl_stmt
specifier|extern
name|PTR
name|realloc
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
name|ptr
operator|,
name|size_t
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 4.10.3.4 */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|free
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 4.10.3.2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MALLOC_INCOMPATIBLE */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|qsort
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
name|base
operator|,
name|size_t
name|nmemb
operator|,
comment|/* 4.10.5.2 */
name|size_t
name|size
operator|,
name|int
argument_list|(
operator|*
name|comp
argument_list|)
argument_list|(
specifier|const
name|void
operator|*
argument_list|,
specifier|const
name|void
operator|*
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|MEM_FNS_DECLARED
end_ifndef

begin_comment
comment|/* Some non-ANSI use void *, not char *.  */
end_comment

begin_decl_stmt
specifier|extern
name|PTR
name|memcpy
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
operator|,
specifier|const
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 4.11.2.1 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|memcmp
name|PARAMS
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|,
specifier|const
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 4.11.4.1 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strchr
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 4.11.5.2 */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strrchr
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 4.11.5.5 */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strstr
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 4.11.5.7 */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strtok
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 4.11.5.8 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MEM_FNS_DECLARED
end_ifndef

begin_comment
comment|/* Some non-ANSI use void *, not char *.  */
end_comment

begin_decl_stmt
specifier|extern
name|PTR
name|memset
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
operator|,
name|int
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 4.11.6.1 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strerror
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 4.11.6.2 */
end_comment

begin_comment
comment|/* Various possibilities for alloca.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|alloca
end_ifndef

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

begin_comment
comment|/* NOTE:  Doesn't declare alloca() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
specifier|extern
name|void
modifier|*
name|alloca
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STDC__ */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TARGET_BYTE_ORDER and HOST_BYTE_ORDER must be defined to one of these.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BIG_ENDIAN
argument_list|)
end_if

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|4321
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LITTLE_ENDIAN
argument_list|)
end_if

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
value|1234
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Target-system-dependent parameters for GDB. */
end_comment

begin_comment
comment|/* Target machine definition.  This will be a symlink to one of the    tm-*.h files, built by the `configure' script.  */
end_comment

begin_include
include|#
directive|include
file|"tm.h"
end_include

begin_comment
comment|/* The bit byte-order has to do just with numbering of bits in    debugging symbols and such.  Conceptually, it's quite separate    from byte/word byte order.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BITS_BIG_ENDIAN
argument_list|)
end_if

begin_if
if|#
directive|if
name|TARGET_BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|BITS_BIG_ENDIAN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Big endian.  */
end_comment

begin_if
if|#
directive|if
name|TARGET_BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|BITS_BIG_ENDIAN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Little endian.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BITS_BIG_ENDIAN not defined.  */
end_comment

begin_comment
comment|/* Swap LEN bytes at BUFFER between target and host byte-order.  This is    the wrong way to do byte-swapping because it assumes that you have a way    to have a host variable of exactly the right size.    extract_* are the right way.  */
end_comment

begin_if
if|#
directive|if
name|TARGET_BYTE_ORDER
operator|==
name|HOST_BYTE_ORDER
end_if

begin_define
define|#
directive|define
name|SWAP_TARGET_AND_HOST
parameter_list|(
name|buffer
parameter_list|,
name|len
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Target and host byte order differ.  */
end_comment

begin_define
define|#
directive|define
name|SWAP_TARGET_AND_HOST
parameter_list|(
name|buffer
parameter_list|,
name|len
parameter_list|)
define|\
value|{	       	       	       	       	       	       	       	       	 \     char tmp;								 \     char *p = (char *)(buffer);						 \     char *q = ((char *)(buffer)) + len - 1;		   		 \     for (; p< q; p++, q--)				 		 \       {									 \         tmp = *q;							 \         *q = *p;							 \         *p = tmp;							 \       }									 \   }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Target and host byte order differ.  */
end_comment

begin_comment
comment|/* In findvar.c.  */
end_comment

begin_decl_stmt
name|LONGEST
name|extract_signed_integer
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|LONGEST
name|extract_unsigned_integer
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CORE_ADDR
name|extract_address
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|store_signed_integer
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
operator|,
name|int
operator|,
name|LONGEST
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|store_unsigned_integer
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
operator|,
name|int
operator|,
name|unsigned
name|LONGEST
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|store_address
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
operator|,
name|int
operator|,
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* On some machines there are bits in addresses which are not really    part of the address, but are used by the kernel, the hardware, etc.    for special purposes.  ADDR_BITS_REMOVE takes out any such bits    so we get a "real" address such as one would find in a symbol    table.  This is used only for addresses of instructions, and even then    I'm not sure it's used in all contexts.  It exists to deal with there    being a few stray bits in the PC which would mislead us, not as some sort    of generic thing to handle alignment or segmentation (it's possible it    should be in TARGET_READ_PC instead).  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ADDR_BITS_REMOVE
argument_list|)
end_if

begin_define
define|#
directive|define
name|ADDR_BITS_REMOVE
parameter_list|(
name|addr
parameter_list|)
value|(addr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* No ADDR_BITS_REMOVE.  */
end_comment

begin_comment
comment|/* From valops.c */
end_comment

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|push_bytes
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In some modules, we don't have a definition of REGISTER_TYPE yet, so we    must avoid prototyping this function for now.  FIXME.  Should be: extern CORE_ADDR push_word PARAMS ((CORE_ADDR, REGISTER_TYPE));  */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|push_word
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Some parts of gdb might be considered optional, in the sense that they    are not essential for being able to build a working, usable debugger    for a specific environment.  For example, the maintenance commands    are there for the benefit of gdb maintainers.  As another example,    some environments really don't need gdb's that are able to read N    different object file formats.  In order to make it possible (but    not necessarily recommended) to build "stripped down" versions of    gdb, the following defines control selective compilation of those    parts of gdb which can be safely left out when necessary.  Note that    the default is to include everything. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAINTENANCE_CMDS
end_ifndef

begin_define
define|#
directive|define
name|MAINTENANCE_CMDS
value|1
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
comment|/* !defined (DEFS_H) */
end_comment

end_unit

