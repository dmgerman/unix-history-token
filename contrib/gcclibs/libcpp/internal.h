begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Part of CPP library.    Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005    Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* This header defines all the internal data structures and functions    that need to be visible across files.  It should not be used outside    cpplib.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LIBCPP_INTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|LIBCPP_INTERNAL_H
end_define

begin_include
include|#
directive|include
file|"symtab.h"
end_include

begin_include
include|#
directive|include
file|"cpp-id-data.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_ICONV_H
end_ifndef

begin_undef
undef|#
directive|undef
name|HAVE_ICONV
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_ICONV
end_if

begin_include
include|#
directive|include
file|<iconv.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HAVE_ICONV
value|0
end_define

begin_typedef
typedef|typedef
name|int
name|iconv_t
typedef|;
end_typedef

begin_comment
comment|/* dummy */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|directive
struct_decl|;
end_struct_decl

begin_comment
comment|/* Deliberately incomplete.  */
end_comment

begin_struct_decl
struct_decl|struct
name|pending_option
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|op
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_cpp_strbuf
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|bool
function_decl|(
modifier|*
name|convert_f
function_decl|)
parameter_list|(
name|iconv_t
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|struct
name|_cpp_strbuf
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|cset_converter
block|{
name|convert_f
name|func
decl_stmt|;
name|iconv_t
name|cd
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BITS_PER_CPPCHAR_T
value|(CHAR_BIT * sizeof (cppchar_t))
end_define

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
value|((CUR) - (BUF)->line_base)
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

begin_define
define|#
directive|define
name|CPP_INCREMENT_LINE
parameter_list|(
name|PFILE
parameter_list|,
name|COLS_HINT
parameter_list|)
value|do { \     const struct line_maps *line_table = PFILE->line_table; \     const struct line_map *map =&line_table->maps[line_table->used-1]; \     unsigned int line = SOURCE_LINE (map, line_table->highest_line); \     linemap_line_start (PFILE->line_table, line + 1, COLS_HINT); \   } while (0)
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
comment|/* Host alignment handling.  */
end_comment

begin_struct
struct|struct
name|dummy
block|{
name|char
name|c
decl_stmt|;
union|union
block|{
name|double
name|d
decl_stmt|;
name|int
modifier|*
name|p
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DEFAULT_ALIGNMENT
value|offsetof (struct dummy, u)
end_define

begin_define
define|#
directive|define
name|CPP_ALIGN2
parameter_list|(
name|size
parameter_list|,
name|align
parameter_list|)
value|(((size) + ((align) - 1))& ~((align) - 1))
end_define

begin_define
define|#
directive|define
name|CPP_ALIGN
parameter_list|(
name|size
parameter_list|)
value|CPP_ALIGN2 (size, DEFAULT_ALIGNMENT)
end_define

begin_define
define|#
directive|define
name|_cpp_mark_macro_used
parameter_list|(
name|NODE
parameter_list|)
value|do {					\   if ((NODE)->type == NT_MACRO&& !((NODE)->flags& NODE_BUILTIN))	\     (NODE)->value.macro->used = 1; } while (0)
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

begin_function_decl
specifier|extern
name|_cpp_buff
modifier|*
name|_cpp_get_buff
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cpp_release_buff
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|_cpp_buff
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cpp_extend_buff
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|_cpp_buff
modifier|*
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|_cpp_buff
modifier|*
name|_cpp_append_extend_buff
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|_cpp_buff
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cpp_free_buff
parameter_list|(
name|_cpp_buff
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
name|_cpp_aligned_alloc
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
name|_cpp_unaligned_alloc
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

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

begin_comment
comment|/* Accessor macros for struct cpp_context.  */
end_comment

begin_define
define|#
directive|define
name|FIRST
parameter_list|(
name|c
parameter_list|)
value|((c)->u.iso.first)
end_define

begin_define
define|#
directive|define
name|LAST
parameter_list|(
name|c
parameter_list|)
value|((c)->u.iso.last)
end_define

begin_define
define|#
directive|define
name|CUR
parameter_list|(
name|c
parameter_list|)
value|((c)->u.trad.cur)
end_define

begin_define
define|#
directive|define
name|RLIMIT
parameter_list|(
name|c
parameter_list|)
value|((c)->u.trad.rlimit)
end_define

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
union|union
block|{
comment|/* For ISO macro expansion.  Contexts other than the base context        are contiguous tokens.  e.g. macro expansions, expanded        argument tokens.  */
struct|struct
block|{
name|union
name|utoken
name|first
decl_stmt|;
name|union
name|utoken
name|last
decl_stmt|;
block|}
name|iso
struct|;
comment|/* For traditional macro expansion.  */
struct|struct
block|{
specifier|const
name|unsigned
name|char
modifier|*
name|cur
decl_stmt|;
specifier|const
name|unsigned
name|char
modifier|*
name|rlimit
decl_stmt|;
block|}
name|trad
struct|;
block|}
name|u
union|;
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
comment|/* Nonzero if in a directive that will handle padding tokens itself.      #include needs this to avoid problems with computed include and      spacing between tokens.  */
name|unsigned
name|char
name|directive_wants_padding
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
comment|/* Nonzero if in a #if or #elif directive.  */
name|unsigned
name|char
name|in_expression
decl_stmt|;
comment|/* Nonzero to save comments.  Turned off if discard_comments, and in      all directives apart from #define.  */
name|unsigned
name|char
name|save_comments
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
comment|/* Nonzero if prevent_expansion is true only because output is      being discarded.  */
name|unsigned
name|char
name|discarding_output
decl_stmt|;
comment|/* Nonzero to skip evaluating part of an expression.  */
name|unsigned
name|int
name|skip_eval
decl_stmt|;
comment|/* Nonzero when handling a deferred pragma.  */
name|unsigned
name|char
name|in_deferred_pragma
decl_stmt|;
comment|/* Nonzero if the deferred pragma being handled allows macro expansion.  */
name|unsigned
name|char
name|pragma_allow_expansion
decl_stmt|;
comment|/* APPLE LOCAL begin #error with unmatched quotes 5607574 */
comment|/* Nonzero when handling #error and #warning to allow unmatched quotes.  */
name|unsigned
name|char
name|in_diagnostic
decl_stmt|;
comment|/* APPLE LOCAL end #error with unmatched quotes 5607574 */
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
name|n__VA_ARGS__
decl_stmt|;
comment|/* C99 vararg macros */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_cpp_line_note
name|_cpp_line_note
typedef|;
end_typedef

begin_struct
struct|struct
name|_cpp_line_note
block|{
comment|/* Location in the clean line the note refers to.  */
specifier|const
name|unsigned
name|char
modifier|*
name|pos
decl_stmt|;
comment|/* Type of note.  The 9 'from' trigraph characters represent those      trigraphs, '\\' an escaped newline, ' ' an escaped newline with      intervening space, and anything else is invalid.  */
name|unsigned
name|int
name|type
decl_stmt|;
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
comment|/* Current location.  */
specifier|const
name|unsigned
name|char
modifier|*
name|line_base
decl_stmt|;
comment|/* Start of current physical line.  */
specifier|const
name|unsigned
name|char
modifier|*
name|next_line
decl_stmt|;
comment|/* Start of to-be-cleaned logical line.  */
specifier|const
name|unsigned
name|char
modifier|*
name|buf
decl_stmt|;
comment|/* Entire character buffer.  */
specifier|const
name|unsigned
name|char
modifier|*
name|rlimit
decl_stmt|;
comment|/* Writable byte at end of file.  */
name|_cpp_line_note
modifier|*
name|notes
decl_stmt|;
comment|/* Array of notes.  */
name|unsigned
name|int
name|cur_note
decl_stmt|;
comment|/* Next note to process.  */
name|unsigned
name|int
name|notes_used
decl_stmt|;
comment|/* Number of notes.  */
name|unsigned
name|int
name|notes_cap
decl_stmt|;
comment|/* Size of allocated array.  */
name|struct
name|cpp_buffer
modifier|*
name|prev
decl_stmt|;
comment|/* Pointer into the file table; non-NULL if this is a file buffer.      Used for include_next and to record control macros.  */
name|struct
name|_cpp_file
modifier|*
name|file
decl_stmt|;
comment|/* Saved value of __TIMESTAMP__ macro - date and time of last modification      of the assotiated file.  */
specifier|const
name|unsigned
name|char
modifier|*
name|timestamp
decl_stmt|;
comment|/* Value of if_stack at start of this file.      Used to prohibit unmatched #endif (etc) in an include file.  */
name|struct
name|if_stack
modifier|*
name|if_stack
decl_stmt|;
comment|/* True if we need to get the next clean line.  */
name|bool
name|need_line
decl_stmt|;
comment|/* True if we have already warned about C++ comments in this file.      The warning happens only for C89 extended mode with -pedantic on,      or for -Wtraditional, and only once per file (otherwise it would      be far too noisy).  */
name|unsigned
name|int
name|warned_cplusplus_comments
range|:
literal|1
decl_stmt|;
comment|/* True if we don't process trigraphs and escaped newlines.  True      for preprocessed input, command line directives, and _Pragma      buffers.  */
name|unsigned
name|int
name|from_stage3
range|:
literal|1
decl_stmt|;
comment|/* At EOF, a buffer is automatically popped.  If RETURN_AT_EOF is      true, a CPP_EOF token is then returned.  Otherwise, the next      token from the enclosing buffer is returned.  */
name|unsigned
name|int
name|return_at_eof
range|:
literal|1
decl_stmt|;
comment|/* One for a system header, two for a C system header file that therefore      needs to be extern "C" protected in C++, and zero otherwise.  */
name|unsigned
name|char
name|sysp
decl_stmt|;
comment|/* The directory of the this buffer's file.  Its NAME member is not      allocated, so we don't need to worry about freeing it.  */
name|struct
name|cpp_dir
name|dir
decl_stmt|;
comment|/* Descriptor for converting from the input character set to the      source character set.  */
name|struct
name|cset_converter
name|input_cset_desc
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
comment|/* Overlaid buffer (can be different after processing #include).  */
name|cpp_buffer
modifier|*
name|overlaid_buffer
decl_stmt|;
comment|/* Lexer state.  */
name|struct
name|lexer_state
name|state
decl_stmt|;
comment|/* Source line tracking.  */
name|struct
name|line_maps
modifier|*
name|line_table
decl_stmt|;
comment|/* The line of the '#' of the current directive.  */
name|source_location
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
comment|/* Token generated while handling a directive, if any. */
name|cpp_token
name|directive_result
decl_stmt|;
comment|/* Search paths for include files.  */
name|struct
name|cpp_dir
modifier|*
name|quote_include
decl_stmt|;
comment|/* "" */
name|struct
name|cpp_dir
modifier|*
name|bracket_include
decl_stmt|;
comment|/*<> */
name|struct
name|cpp_dir
name|no_search_path
decl_stmt|;
comment|/* No path.  */
comment|/* Chain of all hashed _cpp_file instances.  */
name|struct
name|_cpp_file
modifier|*
name|all_files
decl_stmt|;
name|struct
name|_cpp_file
modifier|*
name|main_file
decl_stmt|;
comment|/* File and directory hash table.  */
name|struct
name|htab
modifier|*
name|file_hash
decl_stmt|;
name|struct
name|htab
modifier|*
name|dir_hash
decl_stmt|;
name|struct
name|file_hash_entry
modifier|*
name|file_hash_entries
decl_stmt|;
name|unsigned
name|int
name|file_hash_entries_allocated
decl_stmt|,
name|file_hash_entries_used
decl_stmt|;
comment|/* Negative path lookup hash table.  */
name|struct
name|htab
modifier|*
name|nonexistent_file_hash
decl_stmt|;
name|struct
name|obstack
name|nonexistent_file_ob
decl_stmt|;
comment|/* Nonzero means don't look for #include "foo" the source-file      directory.  */
name|bool
name|quote_ignores_source_dir
decl_stmt|;
comment|/* Nonzero if any file has contained #pragma once or #import has      been used.  */
name|bool
name|seen_once_only
decl_stmt|;
comment|/* Multiple include optimization.  */
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
comment|/* Nonzero prevents the lexer from re-using the token runs.  */
name|unsigned
name|int
name|keep_tokens
decl_stmt|;
comment|/* Error counter for exit code.  */
name|unsigned
name|int
name|errors
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
comment|/* Descriptor for converting from the source character set to the      execution character set.  */
name|struct
name|cset_converter
name|narrow_cset_desc
decl_stmt|;
comment|/* Descriptor for converting from the source character set to the      wide execution character set.  */
name|struct
name|cset_converter
name|wide_cset_desc
decl_stmt|;
comment|/* Date and time text.  Calculated together if either is requested.  */
specifier|const
name|unsigned
name|char
modifier|*
name|date
decl_stmt|;
specifier|const
name|unsigned
name|char
modifier|*
name|time
decl_stmt|;
comment|/* EOF token, and a token forcing paste avoidance.  */
name|cpp_token
name|avoid_paste
decl_stmt|;
name|cpp_token
name|eof
decl_stmt|;
comment|/* Opaque handle to the dependencies of mkdeps.c.  */
name|struct
name|deps
modifier|*
name|deps
decl_stmt|;
comment|/* Obstack holding all macro hash nodes.  This never shrinks.      See identifiers.c */
name|struct
name|obstack
name|hash_ob
decl_stmt|;
comment|/* Obstack holding buffer and conditional structures.  This is a      real stack.  See directives.c.  */
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
comment|/* Call backs to cpplib client.  */
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
comment|/* Expression parser stack.  */
name|struct
name|op
modifier|*
name|op_stack
decl_stmt|,
modifier|*
name|op_limit
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
comment|/* Whether cpplib owns the hashtable.  */
name|bool
name|our_hashtable
decl_stmt|;
comment|/* Traditional preprocessing output buffer (a logical line).  */
struct|struct
block|{
name|unsigned
name|char
modifier|*
name|base
decl_stmt|;
name|unsigned
name|char
modifier|*
name|limit
decl_stmt|;
name|unsigned
name|char
modifier|*
name|cur
decl_stmt|;
name|source_location
name|first_line
decl_stmt|;
block|}
name|out
struct|;
comment|/* Used for buffer overlays by traditional.c.  */
specifier|const
name|unsigned
name|char
modifier|*
name|saved_cur
decl_stmt|,
modifier|*
name|saved_rlimit
decl_stmt|,
modifier|*
name|saved_line_base
decl_stmt|;
comment|/* A saved list of the defined macros, for dependency checking      of precompiled headers.  */
name|struct
name|cpp_savedstate
modifier|*
name|savedstate
decl_stmt|;
name|unsigned
name|int
name|nextcounter
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Character classes.  Based on the more primitive macros in safe-ctype.h.    If the definition of `numchar' looks odd to you, please look up the    definition of a pp-number in the C standard [section 6.4.8 of C99].     In the unlikely event that characters other than \r and \n enter    the set is_vspace, the macro handle_newline() in lex.c must be    updated.  */
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

begin_function_decl
specifier|static
specifier|inline
name|int
name|cpp_in_system_header
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|int
name|cpp_in_system_header
parameter_list|(
name|cpp_reader
modifier|*
name|pfile
parameter_list|)
block|{
return|return
name|pfile
operator|->
name|buffer
condition|?
name|pfile
operator|->
name|buffer
operator|->
name|sysp
else|:
literal|0
return|;
block|}
end_function

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
comment|/* In errors.c  */
end_comment

begin_function_decl
specifier|extern
name|int
name|_cpp_begin_message
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|int
parameter_list|,
name|source_location
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In macro.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|_cpp_free_definition
parameter_list|(
name|cpp_hashnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|_cpp_create_definition
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|cpp_hashnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cpp_pop_context
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cpp_push_text_context
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|cpp_hashnode
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|_cpp_save_parameter
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|cpp_macro
modifier|*
parameter_list|,
name|cpp_hashnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|_cpp_arguments_ok
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|cpp_macro
modifier|*
parameter_list|,
specifier|const
name|cpp_hashnode
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|unsigned
name|char
modifier|*
name|_cpp_builtin_macro_text
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|cpp_hashnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_cpp_warn_if_unused_macro
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|cpp_hashnode
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cpp_push_token_context
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|cpp_hashnode
modifier|*
parameter_list|,
specifier|const
name|cpp_token
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In identifiers.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|_cpp_init_hashtable
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|hash_table
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cpp_destroy_hashtable
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In files.c */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_cpp_file
name|_cpp_file
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|_cpp_file
modifier|*
name|_cpp_find_file
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|cpp_dir
modifier|*
parameter_list|,
name|bool
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|_cpp_find_failed
parameter_list|(
name|_cpp_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cpp_mark_file_once_only
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|struct
name|_cpp_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cpp_fake_include
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|_cpp_stack_file
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|_cpp_file
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|_cpp_stack_include
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|enum
name|include_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_cpp_compare_file_date
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cpp_report_missing_guards
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cpp_init_files
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cpp_cleanup_files
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cpp_pop_file_buffer
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|struct
name|_cpp_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|_cpp_save_file_entries
parameter_list|(
name|cpp_reader
modifier|*
name|pfile
parameter_list|,
name|FILE
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|_cpp_read_file_entries
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|stat
modifier|*
name|_cpp_get_file_stat
parameter_list|(
name|_cpp_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In expr.c */
end_comment

begin_function_decl
specifier|extern
name|bool
name|_cpp_parse_expr
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|op
modifier|*
name|_cpp_expand_op_stack
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In lex.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|_cpp_process_line_notes
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cpp_clean_line
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|_cpp_get_fresh_line
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|_cpp_skip_block_comment
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|cpp_token
modifier|*
name|_cpp_temp_token
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|cpp_token
modifier|*
name|_cpp_lex_token
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|cpp_token
modifier|*
name|_cpp_lex_direct
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_cpp_equiv_tokens
parameter_list|(
specifier|const
name|cpp_token
modifier|*
parameter_list|,
specifier|const
name|cpp_token
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cpp_init_tokenrun
parameter_list|(
name|tokenrun
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In init.c.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|_cpp_maybe_push_include_file
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In directives.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|_cpp_test_assertion
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|unsigned
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_cpp_handle_directive
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cpp_define_builtin
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|_cpp_save_pragma_names
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cpp_restore_pragma_names
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cpp_do__Pragma
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cpp_init_directives
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cpp_init_internal_pragmas
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cpp_do_file_change
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|enum
name|lc_reason
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cpp_pop_buffer
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In directives.c */
end_comment

begin_struct
struct|struct
name|_cpp_dir_only_callbacks
block|{
comment|/* Called to print a block of lines. */
name|void
function_decl|(
modifier|*
name|print_lines
function_decl|)
parameter_list|(
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|maybe_print_line
function_decl|)
parameter_list|(
name|source_location
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|_cpp_preprocess_dir_only
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|struct
name|_cpp_dir_only_callbacks
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In traditional.c.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|_cpp_scan_out_logical_line
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|cpp_macro
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|_cpp_read_logical_line_trad
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cpp_overlay_buffer
parameter_list|(
name|cpp_reader
modifier|*
name|pfile
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cpp_remove_overlay
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|_cpp_create_trad_definition
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|cpp_macro
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|_cpp_expansions_different_trad
parameter_list|(
specifier|const
name|cpp_macro
modifier|*
parameter_list|,
specifier|const
name|cpp_macro
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
name|_cpp_copy_replacement_text
parameter_list|(
specifier|const
name|cpp_macro
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|_cpp_replacement_text_len
parameter_list|(
specifier|const
name|cpp_macro
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In charset.c.  */
end_comment

begin_comment
comment|/* The normalization state at this point in the sequence.    It starts initialized to all zeros, and at the end    'level' is the normalization level of the sequence.  */
end_comment

begin_struct
struct|struct
name|normalize_state
block|{
comment|/* The previous character.  */
name|cppchar_t
name|previous
decl_stmt|;
comment|/* The combining class of the previous character.  */
name|unsigned
name|char
name|prev_class
decl_stmt|;
comment|/* The lowest normalization level so far.  */
name|enum
name|cpp_normalize_level
name|level
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|INITIAL_NORMALIZE_STATE
value|{ 0, 0, normalized_KC }
end_define

begin_define
define|#
directive|define
name|NORMALIZE_STATE_RESULT
parameter_list|(
name|st
parameter_list|)
value|((st)->level)
end_define

begin_comment
comment|/* We saw a character that matches ISIDNUM(), update a    normalize_state appropriately.  */
end_comment

begin_define
define|#
directive|define
name|NORMALIZE_STATE_UPDATE_IDNUM
parameter_list|(
name|st
parameter_list|)
define|\
value|((st)->previous = 0, (st)->prev_class = 0)
end_define

begin_function_decl
specifier|extern
name|cppchar_t
name|_cpp_valid_ucn
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|normalize_state
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cpp_destroy_iconv
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
name|_cpp_convert_input
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|off_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|_cpp_default_encoding
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|cpp_hashnode
modifier|*
name|_cpp_interpret_identifier
parameter_list|(
name|cpp_reader
modifier|*
name|pfile
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|id
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

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
value|(const unsigned char *)str, sizeof str - 1
end_define

begin_comment
comment|/* These are inline functions instead of macros so we can get type    checking.  */
end_comment

begin_function_decl
specifier|static
specifier|inline
name|int
name|ustrcmp
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|int
name|ustrncmp
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|size_t
name|ustrlen
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|unsigned
name|char
modifier|*
name|uxstrdup
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|unsigned
name|char
modifier|*
name|ustrchr
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|int
name|ufputs
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Use a const char for the second parameter since it is usually a literal.  */
end_comment

begin_function_decl
specifier|static
specifier|inline
name|int
name|ustrcspn
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|int
name|ustrcmp
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|s2
parameter_list|)
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
end_function

begin_function
specifier|static
specifier|inline
name|int
name|ustrncmp
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
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
end_function

begin_function
specifier|static
specifier|inline
name|int
name|ustrcspn
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|)
block|{
return|return
name|strcspn
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|s1
argument_list|,
name|s2
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|size_t
name|ustrlen
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|s1
parameter_list|)
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
name|unsigned
name|char
modifier|*
name|uxstrdup
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|s1
parameter_list|)
block|{
return|return
operator|(
name|unsigned
name|char
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
name|unsigned
name|char
modifier|*
name|ustrchr
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|s1
parameter_list|,
name|int
name|c
parameter_list|)
block|{
return|return
operator|(
name|unsigned
name|char
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
specifier|const
name|unsigned
name|char
modifier|*
name|s
parameter_list|,
name|FILE
modifier|*
name|f
parameter_list|)
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
comment|/* ! LIBCPP_INTERNAL_H */
end_comment

end_unit

