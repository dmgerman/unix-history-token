begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Part of CPP library.    Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002    Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This header defines all the internal data structures and functions    that need to be visible across files.  It's called cpphash.h for    historical reasons.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_CPPHASH_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_CPPHASH_H
end_define

begin_include
include|#
directive|include
file|"hashtable.h"
end_include

begin_struct_decl
struct_decl|struct
name|directive
struct_decl|;
end_struct_decl

begin_comment
comment|/* Deliberately incomplete.  */
end_comment

begin_comment
comment|/* Test if a sign is valid within a preprocessing number.  */
end_comment

begin_define
define|#
directive|define
name|VALID_SIGN
parameter_list|(
name|c
parameter_list|,
name|prevc
parameter_list|)
define|\
value|(((c) == '+' || (c) == '-')&& \    ((prevc) == 'e' || (prevc) == 'E' \     || (((prevc) == 'p' || (prevc) == 'P') \&& CPP_OPTION (pfile, extended_numbers))))
end_define

begin_define
define|#
directive|define
name|CPP_OPTION
parameter_list|(
name|PFILE
parameter_list|,
name|OPTION
parameter_list|)
value|((PFILE)->opts.OPTION)
end_define

begin_define
define|#
directive|define
name|CPP_BUFFER
parameter_list|(
name|PFILE
parameter_list|)
value|((PFILE)->buffer)
end_define

begin_define
define|#
directive|define
name|CPP_BUF_COLUMN
parameter_list|(
name|BUF
parameter_list|,
name|CUR
parameter_list|)
value|((CUR) - (BUF)->line_base + (BUF)->col_adjust)
end_define

begin_define
define|#
directive|define
name|CPP_BUF_COL
parameter_list|(
name|BUF
parameter_list|)
value|CPP_BUF_COLUMN(BUF, (BUF)->cur)
end_define

begin_comment
comment|/* Maximum nesting of cpp_buffers.  We use a static limit, partly for    efficiency, and partly to limit runaway recursion.  */
end_comment

begin_define
define|#
directive|define
name|CPP_STACK_MAX
value|200
end_define

begin_comment
comment|/* A generic memory buffer, and operations on it.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_cpp_buff
name|_cpp_buff
typedef|;
end_typedef

begin_struct
struct|struct
name|_cpp_buff
block|{
name|struct
name|_cpp_buff
modifier|*
name|next
decl_stmt|;
name|unsigned
name|char
modifier|*
name|base
decl_stmt|,
modifier|*
name|cur
decl_stmt|,
modifier|*
name|limit
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|_cpp_buff
modifier|*
name|_cpp_get_buff
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_cpp_release_buff
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
name|_cpp_buff
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_cpp_extend_buff
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
name|_cpp_buff
operator|*
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|_cpp_buff
modifier|*
name|_cpp_append_extend_buff
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
name|_cpp_buff
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_cpp_free_buff
name|PARAMS
argument_list|(
operator|(
name|_cpp_buff
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|_cpp_aligned_alloc
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|_cpp_unaligned_alloc
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BUFF_ROOM
parameter_list|(
name|BUFF
parameter_list|)
value|(size_t) ((BUFF)->limit - (BUFF)->cur)
end_define

begin_define
define|#
directive|define
name|BUFF_FRONT
parameter_list|(
name|BUFF
parameter_list|)
value|((BUFF)->cur)
end_define

begin_define
define|#
directive|define
name|BUFF_LIMIT
parameter_list|(
name|BUFF
parameter_list|)
value|((BUFF)->limit)
end_define

begin_comment
comment|/* List of directories to look for include files in.  */
end_comment

begin_struct
struct|struct
name|search_path
block|{
name|struct
name|search_path
modifier|*
name|next
decl_stmt|;
comment|/* NOTE: NAME may not be null terminated for the case of the current      file's directory!  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|unsigned
name|int
name|len
decl_stmt|;
comment|/* We use these to tell if the directory mentioned here is a duplicate      of an earlier directory on the search path.  */
name|ino_t
name|ino
decl_stmt|;
name|dev_t
name|dev
decl_stmt|;
comment|/* Non-zero if it is a system include directory.  */
name|int
name|sysp
decl_stmt|;
comment|/* Mapping of file names for this directory.  Only used on MS-DOS      and related platforms.  */
name|struct
name|file_name_map
modifier|*
name|name_map
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* #include types.  */
end_comment

begin_enum
enum|enum
name|include_type
block|{
name|IT_INCLUDE
block|,
name|IT_INCLUDE_NEXT
block|,
name|IT_IMPORT
block|,
name|IT_CMDLINE
block|}
enum|;
end_enum

begin_union
union|union
name|utoken
block|{
specifier|const
name|cpp_token
modifier|*
name|token
decl_stmt|;
specifier|const
name|cpp_token
modifier|*
modifier|*
name|ptoken
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* A "run" of tokens; part of a chain of runs.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|tokenrun
name|tokenrun
typedef|;
end_typedef

begin_struct
struct|struct
name|tokenrun
block|{
name|tokenrun
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
name|cpp_token
modifier|*
name|base
decl_stmt|,
modifier|*
name|limit
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|cpp_context
name|cpp_context
typedef|;
end_typedef

begin_struct
struct|struct
name|cpp_context
block|{
comment|/* Doubly-linked list.  */
name|cpp_context
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
comment|/* Contexts other than the base context are contiguous tokens.      e.g. macro expansions, expanded argument tokens.  */
name|union
name|utoken
name|first
decl_stmt|;
name|union
name|utoken
name|last
decl_stmt|;
comment|/* If non-NULL, a buffer used for storage related to this context.      When the context is popped, the buffer is released.  */
name|_cpp_buff
modifier|*
name|buff
decl_stmt|;
comment|/* For a macro context, the macro node, otherwise NULL.  */
name|cpp_hashnode
modifier|*
name|macro
decl_stmt|;
comment|/* True if utoken element is token, else ptoken.  */
name|bool
name|direct_p
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lexer_state
block|{
comment|/* Nonzero if first token on line is CPP_HASH.  */
name|unsigned
name|char
name|in_directive
decl_stmt|;
comment|/* True if we are skipping a failed conditional group.  */
name|unsigned
name|char
name|skipping
decl_stmt|;
comment|/* Nonzero if in a directive that takes angle-bracketed headers.  */
name|unsigned
name|char
name|angled_headers
decl_stmt|;
comment|/* Nonzero to save comments.  Turned off if discard_comments, and in      all directives apart from #define.  */
name|unsigned
name|char
name|save_comments
decl_stmt|;
comment|/* Nonzero if we're mid-comment.  */
name|unsigned
name|char
name|lexing_comment
decl_stmt|;
comment|/* Nonzero if lexing __VA_ARGS__ is valid.  */
name|unsigned
name|char
name|va_args_ok
decl_stmt|;
comment|/* Nonzero if lexing poisoned identifiers is valid.  */
name|unsigned
name|char
name|poisoned_ok
decl_stmt|;
comment|/* Nonzero to prevent macro expansion.  */
name|unsigned
name|char
name|prevent_expansion
decl_stmt|;
comment|/* Nonzero when parsing arguments to a function-like macro.  */
name|unsigned
name|char
name|parsing_args
decl_stmt|;
comment|/* Nonzero when in a # NUMBER directive.  */
name|unsigned
name|char
name|line_extension
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Special nodes - identifiers with predefined significance.  */
end_comment

begin_struct
struct|struct
name|spec_nodes
block|{
name|cpp_hashnode
modifier|*
name|n_defined
decl_stmt|;
comment|/* defined operator */
name|cpp_hashnode
modifier|*
name|n_true
decl_stmt|;
comment|/* C++ keyword true */
name|cpp_hashnode
modifier|*
name|n_false
decl_stmt|;
comment|/* C++ keyword false */
name|cpp_hashnode
modifier|*
name|n__STRICT_ANSI__
decl_stmt|;
comment|/* STDC_0_IN_SYSTEM_HEADERS */
name|cpp_hashnode
modifier|*
name|n__CHAR_UNSIGNED__
decl_stmt|;
comment|/* plain char is unsigned */
name|cpp_hashnode
modifier|*
name|n__VA_ARGS__
decl_stmt|;
comment|/* C99 vararg macros */
block|}
struct|;
end_struct

begin_comment
comment|/* Represents the contents of a file cpplib has read in.  */
end_comment

begin_struct
struct|struct
name|cpp_buffer
block|{
specifier|const
name|unsigned
name|char
modifier|*
name|cur
decl_stmt|;
comment|/* current position */
specifier|const
name|unsigned
name|char
modifier|*
name|backup_to
decl_stmt|;
comment|/* if peeked character is not wanted */
specifier|const
name|unsigned
name|char
modifier|*
name|rlimit
decl_stmt|;
comment|/* end of valid data */
specifier|const
name|unsigned
name|char
modifier|*
name|line_base
decl_stmt|;
comment|/* start of current line */
name|struct
name|cpp_buffer
modifier|*
name|prev
decl_stmt|;
specifier|const
name|unsigned
name|char
modifier|*
name|buf
decl_stmt|;
comment|/* Entire character buffer.  */
comment|/* Pointer into the include table; non-NULL if this is a file      buffer.  Used for include_next and to record control macros.  */
name|struct
name|include_file
modifier|*
name|inc
decl_stmt|;
comment|/* Value of if_stack at start of this file.      Used to prohibit unmatched #endif (etc) in an include file.  */
name|struct
name|if_stack
modifier|*
name|if_stack
decl_stmt|;
comment|/* Token column position adjustment owing to tabs in whitespace.  */
name|unsigned
name|int
name|col_adjust
decl_stmt|;
comment|/* Contains PREV_WHITE and/or AVOID_LPASTE.  */
name|unsigned
name|char
name|saved_flags
decl_stmt|;
comment|/* Because of the way the lexer works, -Wtrigraphs can sometimes      warn twice for the same trigraph.  This helps prevent that.  */
specifier|const
name|unsigned
name|char
modifier|*
name|last_Wtrigraphs
decl_stmt|;
comment|/* True if we have already warned about C++ comments in this file.      The warning happens only for C89 extended mode with -pedantic on,      or for -Wtraditional, and only once per file (otherwise it would      be far too noisy).  */
name|unsigned
name|char
name|warned_cplusplus_comments
decl_stmt|;
comment|/* True if we don't process trigraphs and escaped newlines.  True      for preprocessed input, command line directives, and _Pragma      buffers.  */
name|unsigned
name|char
name|from_stage3
decl_stmt|;
comment|/* Nonzero means that the directory to start searching for ""      include files has been calculated and stored in "dir" below.  */
name|unsigned
name|char
name|search_cached
decl_stmt|;
comment|/* At EOF, a buffer is automatically popped.  If RETURN_AT_EOF is      true, a CPP_EOF token is then returned.  Otherwise, the next      token from the enclosing buffer is returned.  */
name|bool
name|return_at_eof
decl_stmt|;
comment|/* The directory of the this buffer's file.  Its NAME member is not      allocated, so we don't need to worry about freeing it.  */
name|struct
name|search_path
name|dir
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A cpp_reader encapsulates the "state" of a pre-processor run.    Applying cpp_get_token repeatedly yields a stream of pre-processor    tokens.  Usually, there is only one cpp_reader object active.  */
end_comment

begin_struct
struct|struct
name|cpp_reader
block|{
comment|/* Top of buffer stack.  */
name|cpp_buffer
modifier|*
name|buffer
decl_stmt|;
comment|/* Lexer state.  */
name|struct
name|lexer_state
name|state
decl_stmt|;
comment|/* Source line tracking.  */
name|struct
name|line_maps
name|line_maps
decl_stmt|;
specifier|const
name|struct
name|line_map
modifier|*
name|map
decl_stmt|;
name|unsigned
name|int
name|line
decl_stmt|;
comment|/* The line of the '#' of the current directive.  */
name|unsigned
name|int
name|directive_line
decl_stmt|;
comment|/* Memory buffers.  */
name|_cpp_buff
modifier|*
name|a_buff
decl_stmt|;
comment|/* Aligned permanent storage.  */
name|_cpp_buff
modifier|*
name|u_buff
decl_stmt|;
comment|/* Unaligned permanent storage.  */
name|_cpp_buff
modifier|*
name|free_buffs
decl_stmt|;
comment|/* Free buffer chain.  */
comment|/* Context stack.  */
name|struct
name|cpp_context
name|base_context
decl_stmt|;
name|struct
name|cpp_context
modifier|*
name|context
decl_stmt|;
comment|/* If in_directive, the directive if known.  */
specifier|const
name|struct
name|directive
modifier|*
name|directive
decl_stmt|;
comment|/* Multiple inlcude optimisation.  */
specifier|const
name|cpp_hashnode
modifier|*
name|mi_cmacro
decl_stmt|;
specifier|const
name|cpp_hashnode
modifier|*
name|mi_ind_cmacro
decl_stmt|;
name|bool
name|mi_valid
decl_stmt|;
comment|/* Lexing.  */
name|cpp_token
modifier|*
name|cur_token
decl_stmt|;
name|tokenrun
name|base_run
decl_stmt|,
modifier|*
name|cur_run
decl_stmt|;
name|unsigned
name|int
name|lookaheads
decl_stmt|;
comment|/* Non-zero prevents the lexer from re-using the token runs.  */
name|unsigned
name|int
name|keep_tokens
decl_stmt|;
comment|/* Error counter for exit code.  */
name|unsigned
name|int
name|errors
decl_stmt|;
comment|/* Line and column where a newline was first seen in a string      constant (multi-line strings).  */
name|unsigned
name|int
name|mls_line
decl_stmt|;
name|unsigned
name|int
name|mls_col
decl_stmt|;
comment|/* Buffer to hold macro definition string.  */
name|unsigned
name|char
modifier|*
name|macro_buffer
decl_stmt|;
name|unsigned
name|int
name|macro_buffer_len
decl_stmt|;
comment|/* Tree of other included files.  See cppfiles.c.  */
name|struct
name|splay_tree_s
modifier|*
name|all_include_files
decl_stmt|;
comment|/* Current maximum length of directory names in the search path      for include files.  (Altered as we get more of them.)  */
name|unsigned
name|int
name|max_include_len
decl_stmt|;
comment|/* Date and time tokens.  Calculated together if either is requested.  */
name|cpp_token
name|date
decl_stmt|;
name|cpp_token
name|time
decl_stmt|;
comment|/* EOF token, and a token forcing paste avoidance.  */
name|cpp_token
name|avoid_paste
decl_stmt|;
name|cpp_token
name|eof
decl_stmt|;
comment|/* Opaque handle to the dependencies of mkdeps.c.  Used by -M etc.  */
name|struct
name|deps
modifier|*
name|deps
decl_stmt|;
comment|/* Obstack holding all macro hash nodes.  This never shrinks.      See cpphash.c */
name|struct
name|obstack
name|hash_ob
decl_stmt|;
comment|/* Obstack holding buffer and conditional structures.  This is a      real stack.  See cpplib.c.  */
name|struct
name|obstack
name|buffer_ob
decl_stmt|;
comment|/* Pragma table - dynamic, because a library user can add to the      list of recognized pragmas.  */
name|struct
name|pragma_entry
modifier|*
name|pragmas
decl_stmt|;
comment|/* Call backs.  */
name|struct
name|cpp_callbacks
name|cb
decl_stmt|;
comment|/* Identifier hash table.  */
name|struct
name|ht
modifier|*
name|hash_table
decl_stmt|;
comment|/* User visible options.  */
name|struct
name|cpp_options
name|opts
decl_stmt|;
comment|/* Special nodes - identifiers with predefined significance to the      preprocessor.  */
name|struct
name|spec_nodes
name|spec_nodes
decl_stmt|;
comment|/* Whether to print our version number.  Done this way so      we don't get it twice for -v -version.  */
name|unsigned
name|char
name|print_version
decl_stmt|;
comment|/* Whether cpplib owns the hashtable.  */
name|unsigned
name|char
name|our_hashtable
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Character classes.  Based on the more primitive macros in safe-ctype.h.    If the definition of `numchar' looks odd to you, please look up the    definition of a pp-number in the C standard [section 6.4.8 of C99].     In the unlikely event that characters other than \r and \n enter    the set is_vspace, the macro handle_newline() in cpplex.c must be    updated.  */
end_comment

begin_define
define|#
directive|define
name|_dollar_ok
parameter_list|(
name|x
parameter_list|)
value|((x) == '$'&& CPP_OPTION (pfile, dollars_in_ident))
end_define

begin_define
define|#
directive|define
name|is_idchar
parameter_list|(
name|x
parameter_list|)
value|(ISIDNUM(x) || _dollar_ok(x))
end_define

begin_define
define|#
directive|define
name|is_numchar
parameter_list|(
name|x
parameter_list|)
value|ISIDNUM(x)
end_define

begin_define
define|#
directive|define
name|is_idstart
parameter_list|(
name|x
parameter_list|)
value|(ISIDST(x) || _dollar_ok(x))
end_define

begin_define
define|#
directive|define
name|is_numstart
parameter_list|(
name|x
parameter_list|)
value|ISDIGIT(x)
end_define

begin_define
define|#
directive|define
name|is_hspace
parameter_list|(
name|x
parameter_list|)
value|ISBLANK(x)
end_define

begin_define
define|#
directive|define
name|is_vspace
parameter_list|(
name|x
parameter_list|)
value|IS_VSPACE(x)
end_define

begin_define
define|#
directive|define
name|is_nvspace
parameter_list|(
name|x
parameter_list|)
value|IS_NVSPACE(x)
end_define

begin_define
define|#
directive|define
name|is_space
parameter_list|(
name|x
parameter_list|)
value|IS_SPACE_OR_NUL(x)
end_define

begin_comment
comment|/* This table is constant if it can be initialized at compile time,    which is the case if cpp was compiled with GCC>=2.7, or another    compiler that supports C99.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_DESIGNATED_INITIALIZERS
end_if

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|_cpp_trigraph_map
index|[
name|UCHAR_MAX
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|_cpp_trigraph_map
index|[
name|UCHAR_MAX
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Macros.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PRINT_DEPS
parameter_list|(
name|PFILE
parameter_list|)
value|CPP_OPTION (PFILE, print_deps)
end_define

begin_define
define|#
directive|define
name|CPP_IN_SYSTEM_HEADER
parameter_list|(
name|PFILE
parameter_list|)
value|((PFILE)->map&& (PFILE)->map->sysp)
end_define

begin_define
define|#
directive|define
name|CPP_PEDANTIC
parameter_list|(
name|PF
parameter_list|)
value|CPP_OPTION (PF, pedantic)
end_define

begin_define
define|#
directive|define
name|CPP_WTRADITIONAL
parameter_list|(
name|PF
parameter_list|)
value|CPP_OPTION (PF, warn_traditional)
end_define

begin_comment
comment|/* In cpperror.c  */
end_comment

begin_enum
enum|enum
name|error_type
block|{
name|WARNING
init|=
literal|0
block|,
name|WARNING_SYSHDR
block|,
name|PEDWARN
block|,
name|ERROR
block|,
name|FATAL
block|,
name|ICE
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|int
name|_cpp_begin_message
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
expr|enum
name|error_type
operator|,
name|unsigned
name|int
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In cppmacro.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|_cpp_free_definition
name|PARAMS
argument_list|(
operator|(
name|cpp_hashnode
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_cpp_create_definition
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
name|cpp_hashnode
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_cpp_pop_context
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In cpphash.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|_cpp_init_hashtable
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
name|hash_table
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_cpp_destroy_hashtable
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In cppfiles.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|_cpp_fake_include
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
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
name|void
name|_cpp_never_reread
name|PARAMS
argument_list|(
operator|(
expr|struct
name|include_file
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_cpp_simplify_pathname
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
name|bool
name|_cpp_read_file
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
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
name|bool
name|_cpp_execute_include
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
specifier|const
name|cpp_token
operator|*
operator|,
expr|enum
name|include_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_cpp_compare_file_date
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
specifier|const
name|cpp_token
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_cpp_report_missing_guards
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_cpp_init_includes
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_cpp_cleanup_includes
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|_cpp_pop_file_buffer
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
expr|struct
name|include_file
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In cppexp.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_cpp_parse_expr
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In cpplex.c */
end_comment

begin_decl_stmt
specifier|extern
name|cpp_token
modifier|*
name|_cpp_temp_token
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|cpp_token
modifier|*
name|_cpp_lex_token
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cpp_token
modifier|*
name|_cpp_lex_direct
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_cpp_equiv_tokens
name|PARAMS
argument_list|(
operator|(
specifier|const
name|cpp_token
operator|*
operator|,
specifier|const
name|cpp_token
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_cpp_init_tokenrun
name|PARAMS
argument_list|(
operator|(
name|tokenrun
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In cppinit.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|_cpp_push_next_buffer
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In cpplib.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_cpp_test_assertion
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_cpp_handle_directive
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
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
name|_cpp_define_builtin
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
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
name|void
name|_cpp_do__Pragma
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_cpp_init_directives
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_cpp_init_internal_pragmas
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_cpp_do_file_change
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
expr|enum
name|lc_reason
operator|,
specifier|const
name|char
operator|*
operator|,
name|unsigned
name|int
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_cpp_pop_buffer
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Utility routines and macros.  */
end_comment

begin_define
define|#
directive|define
name|DSC
parameter_list|(
name|str
parameter_list|)
value|(const U_CHAR *)str, sizeof str - 1
end_define

begin_define
define|#
directive|define
name|xnew
parameter_list|(
name|T
parameter_list|)
value|(T *) xmalloc (sizeof(T))
end_define

begin_define
define|#
directive|define
name|xcnew
parameter_list|(
name|T
parameter_list|)
value|(T *) xcalloc (1, sizeof(T))
end_define

begin_define
define|#
directive|define
name|xnewvec
parameter_list|(
name|T
parameter_list|,
name|N
parameter_list|)
value|(T *) xmalloc (sizeof(T) * (N))
end_define

begin_define
define|#
directive|define
name|xcnewvec
parameter_list|(
name|T
parameter_list|,
name|N
parameter_list|)
value|(T *) xcalloc (N, sizeof(T))
end_define

begin_define
define|#
directive|define
name|xobnew
parameter_list|(
name|O
parameter_list|,
name|T
parameter_list|)
value|(T *) obstack_alloc (O, sizeof(T))
end_define

begin_comment
comment|/* These are inline functions instead of macros so we can get type    checking.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|U_CHAR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|U
value|(const U_CHAR *)
end_define

begin_comment
comment|/* Intended use: U"string" */
end_comment

begin_decl_stmt
specifier|static
specifier|inline
name|int
name|ustrcmp
name|PARAMS
argument_list|(
operator|(
specifier|const
name|U_CHAR
operator|*
operator|,
specifier|const
name|U_CHAR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|inline
name|int
name|ustrncmp
name|PARAMS
argument_list|(
operator|(
specifier|const
name|U_CHAR
operator|*
operator|,
specifier|const
name|U_CHAR
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|inline
name|size_t
name|ustrlen
name|PARAMS
argument_list|(
operator|(
specifier|const
name|U_CHAR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|inline
name|U_CHAR
modifier|*
name|uxstrdup
name|PARAMS
argument_list|(
operator|(
specifier|const
name|U_CHAR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|inline
name|U_CHAR
modifier|*
name|ustrchr
name|PARAMS
argument_list|(
operator|(
specifier|const
name|U_CHAR
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|inline
name|int
name|ufputs
name|PARAMS
argument_list|(
operator|(
specifier|const
name|U_CHAR
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|int
name|ustrcmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
specifier|const
name|U_CHAR
modifier|*
name|s1
decl_stmt|,
decl|*
name|s2
decl_stmt|;
end_function

begin_block
block|{
return|return
name|strcmp
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|s1
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|)
name|s2
argument_list|)
return|;
block|}
end_block

begin_function
specifier|static
specifier|inline
name|int
name|ustrncmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
specifier|const
name|U_CHAR
modifier|*
name|s1
decl_stmt|,
decl|*
name|s2
decl_stmt|;
end_function

begin_decl_stmt
name|size_t
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
name|strncmp
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|s1
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|)
name|s2
argument_list|,
name|n
argument_list|)
return|;
block|}
end_block

begin_function
specifier|static
specifier|inline
name|size_t
name|ustrlen
parameter_list|(
name|s1
parameter_list|)
specifier|const
name|U_CHAR
modifier|*
name|s1
decl_stmt|;
block|{
return|return
name|strlen
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|s1
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|U_CHAR
modifier|*
name|uxstrdup
parameter_list|(
name|s1
parameter_list|)
specifier|const
name|U_CHAR
modifier|*
name|s1
decl_stmt|;
block|{
return|return
operator|(
name|U_CHAR
operator|*
operator|)
name|xstrdup
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|s1
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|U_CHAR
modifier|*
name|ustrchr
parameter_list|(
name|s1
parameter_list|,
name|c
parameter_list|)
specifier|const
name|U_CHAR
modifier|*
name|s1
decl_stmt|;
name|int
name|c
decl_stmt|;
block|{
return|return
operator|(
name|U_CHAR
operator|*
operator|)
name|strchr
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|s1
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|ufputs
parameter_list|(
name|s
parameter_list|,
name|f
parameter_list|)
specifier|const
name|U_CHAR
modifier|*
name|s
decl_stmt|;
name|FILE
modifier|*
name|f
decl_stmt|;
block|{
return|return
name|fputs
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|s
argument_list|,
name|f
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_CPPHASH_H */
end_comment

end_unit

