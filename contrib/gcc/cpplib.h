begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for CPP library.    Copyright (C) 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002    Free Software Foundation, Inc.    Written by Per Bothner, 1994-95.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.   In other words, you are welcome to use, share and improve this program.  You are forbidden to forbid anyone else to use, share and improve  what you give them.   Help stamp out software-hoarding!  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_CPPLIB_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_CPPLIB_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"hashtable.h"
end_include

begin_include
include|#
directive|include
file|"line-map.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* For complex reasons, cpp_reader is also typedefed in c-pragma.h.  */
ifndef|#
directive|ifndef
name|GCC_C_PRAGMA_H
typedef|typedef
name|struct
name|cpp_reader
name|cpp_reader
typedef|;
endif|#
directive|endif
typedef|typedef
name|struct
name|cpp_buffer
name|cpp_buffer
typedef|;
typedef|typedef
name|struct
name|cpp_options
name|cpp_options
typedef|;
typedef|typedef
name|struct
name|cpp_token
name|cpp_token
typedef|;
typedef|typedef
name|struct
name|cpp_string
name|cpp_string
typedef|;
typedef|typedef
name|struct
name|cpp_hashnode
name|cpp_hashnode
typedef|;
typedef|typedef
name|struct
name|cpp_macro
name|cpp_macro
typedef|;
typedef|typedef
name|struct
name|cpp_callbacks
name|cpp_callbacks
typedef|;
struct_decl|struct
name|answer
struct_decl|;
struct_decl|struct
name|file_name_map_list
struct_decl|;
comment|/* The first three groups, apart from '=', can appear in preprocessor    expressions (+= and -= are used to indicate unary + and - resp.).    This allows a lookup table to be implemented in _cpp_parse_expr.     The first group, to CPP_LAST_EQ, can be immediately followed by an    '='.  The lexer needs operators ending in '=', like ">>=", to be in    the same order as their counterparts without the '=', like ">>".  */
comment|/* Positions in the table.  */
define|#
directive|define
name|CPP_LAST_EQ
value|CPP_MAX
define|#
directive|define
name|CPP_FIRST_DIGRAPH
value|CPP_HASH
define|#
directive|define
name|CPP_LAST_PUNCTUATOR
value|CPP_DOT_STAR
define|#
directive|define
name|CPP_LAST_CPP_OP
value|CPP_LESS_EQ
define|#
directive|define
name|TTYPE_TABLE
define|\
value|OP(CPP_EQ = 0,	"=")			\   OP(CPP_NOT,		"!")			\   OP(CPP_GREATER,	">")
comment|/* compare */
value|\   OP(CPP_LESS,		"<")			\   OP(CPP_PLUS,		"+")
comment|/* math */
value|\   OP(CPP_MINUS,		"-")			\   OP(CPP_MULT,		"*")			\   OP(CPP_DIV,		"/")			\   OP(CPP_MOD,		"%")			\   OP(CPP_AND,		"&")
comment|/* bit ops */
value|\   OP(CPP_OR,		"|")			\   OP(CPP_XOR,		"^")			\   OP(CPP_RSHIFT,	">>")			\   OP(CPP_LSHIFT,	"<<")			\   OP(CPP_MIN,		"<?")
comment|/* extension */
value|\   OP(CPP_MAX,		">?")			\ \   OP(CPP_COMPL,		"~")			\   OP(CPP_AND_AND,	"&&")
comment|/* logical */
value|\   OP(CPP_OR_OR,		"||")			\   OP(CPP_QUERY,		"?")			\   OP(CPP_COLON,		":")			\   OP(CPP_COMMA,		",")
comment|/* grouping */
value|\   OP(CPP_OPEN_PAREN,	"(")			\   OP(CPP_CLOSE_PAREN,	")")			\   TK(CPP_EOF,		SPELL_NONE)		\   OP(CPP_EQ_EQ,		"==")
comment|/* compare */
value|\   OP(CPP_NOT_EQ,	"!=")			\   OP(CPP_GREATER_EQ,	">=")			\   OP(CPP_LESS_EQ,	"<=")			\ \
comment|/* These two are unary + / - in preprocessor expressions.  */
value|\   OP(CPP_PLUS_EQ,	"+=")
comment|/* math */
value|\   OP(CPP_MINUS_EQ,	"-=")			\ \   OP(CPP_MULT_EQ,	"*=")			\   OP(CPP_DIV_EQ,	"/=")			\   OP(CPP_MOD_EQ,	"%=")			\   OP(CPP_AND_EQ,	"&=")
comment|/* bit ops */
value|\   OP(CPP_OR_EQ,		"|=")			\   OP(CPP_XOR_EQ,	"^=")			\   OP(CPP_RSHIFT_EQ,	">>=")			\   OP(CPP_LSHIFT_EQ,	"<<=")			\   OP(CPP_MIN_EQ,	"<?=")
comment|/* extension */
value|\   OP(CPP_MAX_EQ,	">?=")			\
comment|/* Digraphs together, beginning with CPP_FIRST_DIGRAPH.  */
value|\   OP(CPP_HASH,		"#")
comment|/* digraphs */
value|\   OP(CPP_PASTE,		"##")			\   OP(CPP_OPEN_SQUARE,	"[")			\   OP(CPP_CLOSE_SQUARE,	"]")			\   OP(CPP_OPEN_BRACE,	"{")			\   OP(CPP_CLOSE_BRACE,	"}")			\
comment|/* The remainder of the punctuation.  Order is not significant.  */
value|\   OP(CPP_SEMICOLON,	";")
comment|/* structure */
value|\   OP(CPP_ELLIPSIS,	"...")			\   OP(CPP_PLUS_PLUS,	"++")
comment|/* increment */
value|\   OP(CPP_MINUS_MINUS,	"--")			\   OP(CPP_DEREF,		"->")
comment|/* accessors */
value|\   OP(CPP_DOT,		".")			\   OP(CPP_SCOPE,		"::")			\   OP(CPP_DEREF_STAR,	"->*")			\   OP(CPP_DOT_STAR,	".*")			\   OP(CPP_ATSIGN,	"@")
comment|/* used in Objective-C */
value|\ \   TK(CPP_NAME,		SPELL_IDENT)
comment|/* word */
value|\   TK(CPP_NUMBER,	SPELL_NUMBER)
comment|/* 34_be+ta  */
value|\ \   TK(CPP_CHAR,		SPELL_STRING)
comment|/* 'char' */
value|\   TK(CPP_WCHAR,		SPELL_STRING)
comment|/* L'char' */
value|\   TK(CPP_OTHER,		SPELL_CHAR)
comment|/* stray punctuation */
value|\ \   TK(CPP_STRING,	SPELL_STRING)
comment|/* "string" */
value|\   TK(CPP_WSTRING,	SPELL_STRING)
comment|/* L"string" */
value|\   TK(CPP_HEADER_NAME,	SPELL_STRING)
comment|/*<stdio.h> in #include */
value|\ \   TK(CPP_COMMENT,	SPELL_NUMBER)
comment|/* Only if output comments.  */
value|\
comment|/* SPELL_NUMBER happens to DTRT.  */
value|\   TK(CPP_MACRO_ARG,	SPELL_NONE)
comment|/* Macro argument.  */
value|\   TK(CPP_PADDING,	SPELL_NONE)
comment|/* Whitespace for cpp0.  */
define|#
directive|define
name|OP
parameter_list|(
name|e
parameter_list|,
name|s
parameter_list|)
value|e,
define|#
directive|define
name|TK
parameter_list|(
name|e
parameter_list|,
name|s
parameter_list|)
value|e,
enum|enum
name|cpp_ttype
block|{
name|TTYPE_TABLE
name|N_TTYPES
block|}
enum|;
undef|#
directive|undef
name|OP
undef|#
directive|undef
name|TK
comment|/* C language kind, used when calling cpp_reader_init.  */
enum|enum
name|c_lang
block|{
name|CLK_GNUC89
init|=
literal|0
block|,
name|CLK_GNUC99
block|,
name|CLK_STDC89
block|,
name|CLK_STDC94
block|,
name|CLK_STDC99
block|,
name|CLK_GNUCXX
block|,
name|CLK_CXX98
block|,
name|CLK_ASM
block|}
enum|;
comment|/* Payload of a NUMBER, STRING, CHAR or COMMENT token.  */
struct|struct
name|cpp_string
block|{
name|unsigned
name|int
name|len
decl_stmt|;
specifier|const
name|unsigned
name|char
modifier|*
name|text
decl_stmt|;
block|}
struct|;
comment|/* Flags for the cpp_token structure.  */
define|#
directive|define
name|PREV_WHITE
value|(1<< 0)
comment|/* If whitespace before this token.  */
define|#
directive|define
name|DIGRAPH
value|(1<< 1)
comment|/* If it was a digraph.  */
define|#
directive|define
name|STRINGIFY_ARG
value|(1<< 2)
comment|/* If macro argument to be stringified.  */
define|#
directive|define
name|PASTE_LEFT
value|(1<< 3)
comment|/* If on LHS of a ## operator.  */
define|#
directive|define
name|NAMED_OP
value|(1<< 4)
comment|/* C++ named operators.  */
define|#
directive|define
name|NO_EXPAND
value|(1<< 5)
comment|/* Do not macro-expand this token.  */
define|#
directive|define
name|BOL
value|(1<< 6)
comment|/* Token at beginning of line.  */
comment|/* A preprocessing token.  This has been carefully packed and should    occupy 16 bytes on 32-bit hosts and 24 bytes on 64-bit hosts.  */
struct|struct
name|cpp_token
block|{
name|unsigned
name|int
name|line
decl_stmt|;
comment|/* Logical line of first char of token.  */
name|unsigned
name|short
name|col
decl_stmt|;
comment|/* Column of first char of token.  */
name|ENUM_BITFIELD
argument_list|(
argument|cpp_ttype
argument_list|)
name|type
label|:
name|CHAR_BIT
expr_stmt|;
comment|/* token type */
name|unsigned
name|char
name|flags
decl_stmt|;
comment|/* flags - see above */
union|union
block|{
name|cpp_hashnode
modifier|*
name|node
decl_stmt|;
comment|/* An identifier.  */
specifier|const
name|cpp_token
modifier|*
name|source
decl_stmt|;
comment|/* Inherit padding from this token.  */
name|struct
name|cpp_string
name|str
decl_stmt|;
comment|/* A string, or number.  */
name|unsigned
name|int
name|arg_no
decl_stmt|;
comment|/* Argument no. for a CPP_MACRO_ARG.  */
name|unsigned
name|char
name|c
decl_stmt|;
comment|/* Character represented by CPP_OTHER.  */
block|}
name|val
union|;
block|}
struct|;
comment|/* A type wide enough to hold any multibyte source character.    cpplib's character constant interpreter requires an unsigned type.    Also, a typedef for the signed equivalent.  */
ifndef|#
directive|ifndef
name|MAX_WCHAR_TYPE_SIZE
define|#
directive|define
name|MAX_WCHAR_TYPE_SIZE
value|WCHAR_TYPE_SIZE
endif|#
directive|endif
if|#
directive|if
name|CHAR_BIT
operator|*
name|SIZEOF_INT
operator|>=
name|MAX_WCHAR_TYPE_SIZE
define|#
directive|define
name|CPPCHAR_SIGNED_T
value|int
else|#
directive|else
if|#
directive|if
name|CHAR_BIT
operator|*
name|SIZEOF_LONG
operator|>=
name|MAX_WCHAR_TYPE_SIZE
operator|||
operator|!
name|HAVE_LONG_LONG
define|#
directive|define
name|CPPCHAR_SIGNED_T
value|long
else|#
directive|else
define|#
directive|define
name|CPPCHAR_SIGNED_T
value|long long
endif|#
directive|endif
endif|#
directive|endif
typedef|typedef
name|unsigned
name|CPPCHAR_SIGNED_T
name|cppchar_t
typedef|;
typedef|typedef
name|CPPCHAR_SIGNED_T
name|cppchar_signed_t
typedef|;
comment|/* Values for opts.dump_macros.   dump_only means inhibit output of the preprocessed text              and instead output the definitions of all user-defined              macros in a form suitable for use as input to cpp.    dump_names means pass #define and the macro name through to output.    dump_definitions means pass the whole definition (plus #define) through */
enum|enum
block|{
name|dump_none
init|=
literal|0
block|,
name|dump_only
block|,
name|dump_names
block|,
name|dump_definitions
block|}
enum|;
comment|/* This structure is nested inside struct cpp_reader, and    carries all the options visible to the command line.  */
struct|struct
name|cpp_options
block|{
comment|/* Characters between tab stops.  */
name|unsigned
name|int
name|tabstop
decl_stmt|;
comment|/* Pending options - -D, -U, -A, -I, -ixxx.  */
name|struct
name|cpp_pending
modifier|*
name|pending
decl_stmt|;
comment|/* Search paths for include files.  */
name|struct
name|search_path
modifier|*
name|quote_include
decl_stmt|;
comment|/* "" */
name|struct
name|search_path
modifier|*
name|bracket_include
decl_stmt|;
comment|/*<> */
comment|/* Map between header names and file names, used only on DOS where      file names are limited in length.  */
name|struct
name|file_name_map_list
modifier|*
name|map_list
decl_stmt|;
comment|/* Directory prefix that should replace `/usr/lib/gcc-lib/TARGET/VERSION'      in the standard include file directories.  */
specifier|const
name|char
modifier|*
name|include_prefix
decl_stmt|;
name|unsigned
name|int
name|include_prefix_len
decl_stmt|;
comment|/* The language we're preprocessing.  */
name|enum
name|c_lang
name|lang
decl_stmt|;
comment|/* Non-0 means -v, so print the full set of include dirs.  */
name|unsigned
name|char
name|verbose
decl_stmt|;
comment|/* Nonzero means use extra default include directories for C++.  */
name|unsigned
name|char
name|cplusplus
decl_stmt|;
comment|/* Nonzero means handle cplusplus style comments */
name|unsigned
name|char
name|cplusplus_comments
decl_stmt|;
comment|/* Nonzero means define __OBJC__, treat @ as a special token, and      use the OBJC[PLUS]_INCLUDE_PATH environment variable.  */
name|unsigned
name|char
name|objc
decl_stmt|;
comment|/* Nonzero means don't copy comments into the output file.  */
name|unsigned
name|char
name|discard_comments
decl_stmt|;
comment|/* Nonzero means don't copy comments into the output file during      macro expansion.  */
name|unsigned
name|char
name|discard_comments_in_macro_exp
decl_stmt|;
comment|/* Nonzero means process the ISO trigraph sequences.  */
name|unsigned
name|char
name|trigraphs
decl_stmt|;
comment|/* Nonzero means process the ISO digraph sequences.  */
name|unsigned
name|char
name|digraphs
decl_stmt|;
comment|/* Nonzero means to allow hexadecimal floats and LL suffixes.  */
name|unsigned
name|char
name|extended_numbers
decl_stmt|;
comment|/* Nonzero means print names of header files (-H).  */
name|unsigned
name|char
name|print_include_names
decl_stmt|;
comment|/* Nonzero means cpp_pedwarn causes a hard error.  */
name|unsigned
name|char
name|pedantic_errors
decl_stmt|;
comment|/* Nonzero means don't print warning messages.  */
name|unsigned
name|char
name|inhibit_warnings
decl_stmt|;
comment|/* Nonzero means don't suppress warnings from system headers.  */
name|unsigned
name|char
name|warn_system_headers
decl_stmt|;
comment|/* Nonzero means don't print error messages.  Has no option to      select it, but can be set by a user of cpplib (e.g. fix-header).  */
name|unsigned
name|char
name|inhibit_errors
decl_stmt|;
comment|/* Nonzero means warn if slash-star appears in a comment.  */
name|unsigned
name|char
name|warn_comments
decl_stmt|;
comment|/* Nonzero means warn if there are any trigraphs.  */
name|unsigned
name|char
name|warn_trigraphs
decl_stmt|;
comment|/* Nonzero means warn if #import is used.  */
name|unsigned
name|char
name|warn_import
decl_stmt|;
comment|/* Nonzero means warn about multicharacter charconsts.  */
name|unsigned
name|char
name|warn_multichar
decl_stmt|;
comment|/* Nonzero means warn about various incompatibilities with      traditional C.  */
name|unsigned
name|char
name|warn_traditional
decl_stmt|;
comment|/* Nonzero means warn about long long numeric constants.  */
name|unsigned
name|char
name|warn_long_long
decl_stmt|;
comment|/* Nonzero means warn about text after an #endif (or #else).  */
name|unsigned
name|char
name|warn_endif_labels
decl_stmt|;
comment|/* Nonzero means warn about implicit sign changes owing to integer      promotions.  */
name|unsigned
name|char
name|warn_num_sign_change
decl_stmt|;
comment|/* Nonzero means turn warnings into errors.  */
name|unsigned
name|char
name|warnings_are_errors
decl_stmt|;
comment|/* Nonzero causes output not to be done, but directives such as      #define that have side effects are still obeyed.  */
name|unsigned
name|char
name|no_output
decl_stmt|;
comment|/* Nonzero means we should look for header.gcc files that remap file      names.  */
name|unsigned
name|char
name|remap
decl_stmt|;
comment|/* Nonzero means don't output line number information.  */
name|unsigned
name|char
name|no_line_commands
decl_stmt|;
comment|/* Nonzero means -I- has been seen, so don't look for #include "foo"      the source-file directory.  */
name|unsigned
name|char
name|ignore_srcdir
decl_stmt|;
comment|/* Zero means dollar signs are punctuation.  */
name|unsigned
name|char
name|dollars_in_ident
decl_stmt|;
comment|/* Nonzero means warn if undefined identifiers are evaluated in an #if.  */
name|unsigned
name|char
name|warn_undef
decl_stmt|;
comment|/* Nonzero means warn of unused macros from the main file.  */
name|unsigned
name|char
name|warn_unused_macros
decl_stmt|;
comment|/* Nonzero for the 1999 C Standard, including corrigenda and amendments.  */
name|unsigned
name|char
name|c99
decl_stmt|;
comment|/* Nonzero if we are conforming to a specific C or C++ standard.  */
name|unsigned
name|char
name|std
decl_stmt|;
comment|/* Nonzero means give all the error messages the ANSI standard requires.  */
name|unsigned
name|char
name|pedantic
decl_stmt|;
comment|/* Nonzero means we're looking at already preprocessed code, so don't      bother trying to do macro expansion and whatnot.  */
name|unsigned
name|char
name|preprocessed
decl_stmt|;
comment|/* Nonzero disables all the standard directories for headers.  */
name|unsigned
name|char
name|no_standard_includes
decl_stmt|;
comment|/* Nonzero disables the C++-specific standard directories for headers.  */
name|unsigned
name|char
name|no_standard_cplusplus_includes
decl_stmt|;
comment|/* Nonzero means dump macros in some fashion - see above.  */
name|unsigned
name|char
name|dump_macros
decl_stmt|;
comment|/* Nonzero means pass #include lines through to the output.  */
name|unsigned
name|char
name|dump_includes
decl_stmt|;
comment|/* Print column number in error messages.  */
name|unsigned
name|char
name|show_column
decl_stmt|;
comment|/* Nonzero means handle C++ alternate operator names.  */
name|unsigned
name|char
name|operator_names
decl_stmt|;
comment|/* True for traditional preprocessing.  */
name|unsigned
name|char
name|traditional
decl_stmt|;
comment|/* Dependency generation.  */
struct|struct
block|{
comment|/* Style of header dependencies to generate.  */
enum|enum
block|{
name|DEPS_NONE
init|=
literal|0
block|,
name|DEPS_USER
block|,
name|DEPS_SYSTEM
block|}
name|style
enum|;
comment|/* Assume missing files are generated files.  */
name|bool
name|missing_files
decl_stmt|;
comment|/* Generate phony targets for each dependency apart from the first        one.  */
name|bool
name|phony_targets
decl_stmt|;
comment|/* If true, no dependency is generated on the main file.  */
name|bool
name|ignore_main_file
decl_stmt|;
block|}
name|deps
struct|;
comment|/* Target-specific features set by the front end or client.  */
comment|/* Precision for target CPP arithmetic, target characters, target      ints and target wide characters, respectively.  */
name|size_t
name|precision
decl_stmt|,
name|char_precision
decl_stmt|,
name|int_precision
decl_stmt|,
name|wchar_precision
decl_stmt|;
comment|/* True means chars (wide chars) are unsigned.  */
name|bool
name|unsigned_char
decl_stmt|,
name|unsigned_wchar
decl_stmt|;
comment|/* Nonzero means __STDC__ should have the value 0 in system headers.  */
name|unsigned
name|char
name|stdc_0_in_system_headers
decl_stmt|;
block|}
struct|;
comment|/* Call backs.  */
struct|struct
name|cpp_callbacks
block|{
comment|/* Called when a new line of preprocessed output is started.  */
name|void
argument_list|(
argument|*line_change
argument_list|)
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
name|int
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*file_change
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
specifier|const
expr|struct
name|line_map
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*include
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
name|unsigned
name|int
operator|,
specifier|const
name|unsigned
name|char
operator|*
operator|,
specifier|const
name|cpp_token
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*define
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
name|unsigned
name|int
operator|,
name|cpp_hashnode
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*undef
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
name|unsigned
name|int
operator|,
name|cpp_hashnode
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*ident
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
name|unsigned
name|int
operator|,
specifier|const
name|cpp_string
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*def_pragma
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Called when the client has a chance to properly register      built-ins with cpp_define() and cpp_assert().  */
name|void
argument_list|(
argument|*register_builtins
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
comment|/* Name under which this program was invoked.  */
specifier|extern
specifier|const
name|char
modifier|*
name|progname
decl_stmt|;
comment|/* The structure of a node in the hash table.  The hash table has    entries for all identifiers: either macros defined by #define    commands (type NT_MACRO), assertions created with #assert    (NT_ASSERTION), or neither of the above (NT_VOID).  Builtin macros    like __LINE__ are flagged NODE_BUILTIN.  Poisioned identifiers are    flagged NODE_POISONED.  NODE_OPERATOR (C++ only) indicates an    identifier that behaves like an operator such as "xor".    NODE_DIAGNOSTIC is for speed in lex_token: it indicates a    diagnostic may be required for this node.  Currently this only    applies to __VA_ARGS__ and poisoned identifiers.  */
comment|/* Hash node flags.  */
define|#
directive|define
name|NODE_OPERATOR
value|(1<< 0)
comment|/* C++ named operator.  */
define|#
directive|define
name|NODE_POISONED
value|(1<< 1)
comment|/* Poisoned identifier.  */
define|#
directive|define
name|NODE_BUILTIN
value|(1<< 2)
comment|/* Builtin macro.  */
define|#
directive|define
name|NODE_DIAGNOSTIC
value|(1<< 3)
comment|/* Possible diagnostic when lexed.  */
define|#
directive|define
name|NODE_WARN
value|(1<< 4)
comment|/* Warn if redefined or undefined.  */
define|#
directive|define
name|NODE_DISABLED
value|(1<< 5)
comment|/* A disabled macro.  */
comment|/* Different flavors of hash node.  */
enum|enum
name|node_type
block|{
name|NT_VOID
init|=
literal|0
block|,
comment|/* No definition yet.  */
name|NT_MACRO
block|,
comment|/* A macro of some form.  */
name|NT_ASSERTION
comment|/* Predicate for #assert.  */
block|}
enum|;
comment|/* Different flavors of builtin macro.  _Pragma is an operator, but we    handle it with the builtin code for efficiency reasons.  */
enum|enum
name|builtin_type
block|{
name|BT_SPECLINE
init|=
literal|0
block|,
comment|/* `__LINE__' */
name|BT_DATE
block|,
comment|/* `__DATE__' */
name|BT_FILE
block|,
comment|/* `__FILE__' */
name|BT_BASE_FILE
block|,
comment|/* `__BASE_FILE__' */
name|BT_INCLUDE_LEVEL
block|,
comment|/* `__INCLUDE_LEVEL__' */
name|BT_TIME
block|,
comment|/* `__TIME__' */
name|BT_STDC
block|,
comment|/* `__STDC__' */
name|BT_PRAGMA
comment|/* `_Pragma' operator */
block|}
enum|;
define|#
directive|define
name|CPP_HASHNODE
parameter_list|(
name|HNODE
parameter_list|)
value|((cpp_hashnode *) (HNODE))
define|#
directive|define
name|HT_NODE
parameter_list|(
name|NODE
parameter_list|)
value|((ht_identifier *) (NODE))
define|#
directive|define
name|NODE_LEN
parameter_list|(
name|NODE
parameter_list|)
value|HT_LEN (&(NODE)->ident)
define|#
directive|define
name|NODE_NAME
parameter_list|(
name|NODE
parameter_list|)
value|HT_STR (&(NODE)->ident)
comment|/* The common part of an identifier node shared amongst all 3 C front    ends.  Also used to store CPP identifiers, which are a superset of    identifiers in the grammatical sense.  */
struct|struct
name|cpp_hashnode
block|{
name|struct
name|ht_identifier
name|ident
decl_stmt|;
name|unsigned
name|short
name|arg_index
decl_stmt|;
comment|/* Macro argument index.  */
name|unsigned
name|char
name|directive_index
decl_stmt|;
comment|/* Index into directive table.  */
name|unsigned
name|char
name|rid_code
decl_stmt|;
comment|/* Rid code - for front ends.  */
name|ENUM_BITFIELD
argument_list|(
argument|node_type
argument_list|)
name|type
label|:
literal|8
expr_stmt|;
comment|/* CPP node type.  */
name|unsigned
name|char
name|flags
decl_stmt|;
comment|/* CPP flags.  */
union|union
block|{
name|cpp_macro
modifier|*
name|macro
decl_stmt|;
comment|/* If a macro.  */
name|struct
name|answer
modifier|*
name|answers
decl_stmt|;
comment|/* Answers to an assertion.  */
name|enum
name|cpp_ttype
name|operator
decl_stmt|;
comment|/* Code for a named operator.  */
name|enum
name|builtin_type
name|builtin
decl_stmt|;
comment|/* Code for a builtin macro.  */
block|}
name|value
union|;
block|}
struct|;
comment|/* Call this first to get a handle to pass to other functions.  */
specifier|extern
name|cpp_reader
modifier|*
name|cpp_create_reader
name|PARAMS
argument_list|(
operator|(
expr|enum
name|c_lang
operator|)
argument_list|)
decl_stmt|;
comment|/* Call this to change the selected language standard (e.g. because of    command line options).  */
specifier|extern
name|void
name|cpp_set_lang
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
expr|enum
name|c_lang
operator|)
argument_list|)
decl_stmt|;
comment|/* Add a dependency TARGET.  Quote it for "make" if QUOTE.  Can be    called any number of times before cpp_read_main_file().  If no    targets have been added before cpp_read_main_file(), then the    default target is used.  */
specifier|extern
name|void
name|cpp_add_dependency_target
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
specifier|const
name|char
operator|*
name|target
operator|,
name|int
name|quote
operator|)
argument_list|)
decl_stmt|;
comment|/* Call these to get pointers to the options and callback structures    for a given reader.  These pointers are good until you call    cpp_finish on that reader.  You can either edit the callbacks    through the pointer returned from cpp_get_callbacks, or set them    with cpp_set_callbacks.  */
specifier|extern
name|cpp_options
modifier|*
name|cpp_get_options
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|)
argument_list|)
decl_stmt|;
specifier|extern
specifier|const
name|struct
name|line_maps
modifier|*
name|cpp_get_line_maps
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|cpp_callbacks
modifier|*
name|cpp_get_callbacks
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|cpp_set_callbacks
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
name|cpp_callbacks
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* Now call cpp_handle_option[s] to handle 1[or more] switches.  The    return value is the number of arguments used.  If    cpp_handle_options returns without using all arguments, it couldn't    understand the next switch.  Options processing is not completed    until you call cpp_finish_options.  */
specifier|extern
name|int
name|cpp_handle_options
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|cpp_handle_option
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* This function reads the file, but does not start preprocessing.  It    returns the name of the original file; this is the same as the    input file, except for preprocessed input.  This will generate at    least one file change callback, and possibly a line change callback    too.  If there was an error opening the file, it returns NULL.     If you want cpplib to manage its own hashtable, pass in a NULL    pointer.  Otherise you should pass in an initialized hash table    that cpplib will share; this technique is used by the C front    ends.  */
specifier|extern
specifier|const
name|char
modifier|*
name|cpp_read_main_file
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
expr|struct
name|ht
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* Deferred handling of command line options that can generate debug    callbacks, such as -D and -imacros.  Call this after    cpp_read_main_file.  The front ends need this separation so they    can initialize debug output with the original file name, returned    from cpp_read_main_file, before they get debug callbacks.  */
specifier|extern
name|void
name|cpp_finish_options
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* Call this to finish preprocessing.  If you requested dependency    generation, pass an open stream to write the information to,    otherwise NULL.  It is your responsibility to close the stream.     Returns cpp_errors (pfile).  */
specifier|extern
name|int
name|cpp_finish
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
name|FILE
operator|*
name|deps_stream
operator|)
argument_list|)
decl_stmt|;
comment|/* Call this to release the handle at the end of preprocessing.  Any    use of the handle after this function returns is invalid.  Returns    cpp_errors (pfile).  */
specifier|extern
name|void
name|cpp_destroy
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* Error count.  */
specifier|extern
name|unsigned
name|int
name|cpp_errors
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|unsigned
name|int
name|cpp_token_len
name|PARAMS
argument_list|(
operator|(
specifier|const
name|cpp_token
operator|*
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|unsigned
name|char
modifier|*
name|cpp_token_as_text
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
specifier|extern
name|unsigned
name|char
modifier|*
name|cpp_spell_token
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
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|cpp_register_pragma
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|void
argument_list|(
argument|*
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|)
argument_list|)
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|cpp_avoid_paste
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
specifier|const
name|cpp_token
operator|*
operator|)
argument_list|)
decl_stmt|;
specifier|extern
specifier|const
name|cpp_token
modifier|*
name|cpp_get_token
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|)
argument_list|)
decl_stmt|;
specifier|extern
specifier|const
name|unsigned
name|char
modifier|*
name|cpp_macro_definition
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
specifier|const
name|cpp_hashnode
operator|*
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|_cpp_backup_tokens
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
comment|/* Evaluate a CPP_CHAR or CPP_WCHAR token.  */
specifier|extern
name|cppchar_t
name|cpp_interpret_charconst
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
name|unsigned
name|int
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* Used to register builtins during the register_builtins callback.    The text is the same as the command line argument.  */
specifier|extern
name|void
name|cpp_define
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
specifier|extern
name|void
name|cpp_assert
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
specifier|extern
name|void
name|cpp_undef
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
specifier|extern
name|void
name|cpp_unassert
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
specifier|extern
name|cpp_buffer
modifier|*
name|cpp_push_buffer
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
specifier|const
name|unsigned
name|char
operator|*
operator|,
name|size_t
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|cpp_defined
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
specifier|const
name|unsigned
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
comment|/* A preprocessing number.  Code assumes that any unused high bits of    the double integer are set to zero.  */
typedef|typedef
name|unsigned
name|HOST_WIDE_INT
name|cpp_num_part
typedef|;
typedef|typedef
name|struct
name|cpp_num
name|cpp_num
typedef|;
struct|struct
name|cpp_num
block|{
name|cpp_num_part
name|high
decl_stmt|;
name|cpp_num_part
name|low
decl_stmt|;
name|bool
name|unsignedp
decl_stmt|;
comment|/* True if value should be treated as unsigned.  */
name|bool
name|overflow
decl_stmt|;
comment|/* True if the most recent calculation overflowed.  */
block|}
struct|;
comment|/* cpplib provides two interfaces for interpretation of preprocessing    numbers.     cpp_classify_number categorizes numeric constants according to    their field (integer, floating point, or invalid), radix (decimal,    octal, hexadecimal), and type suffixes.  */
define|#
directive|define
name|CPP_N_CATEGORY
value|0x000F
define|#
directive|define
name|CPP_N_INVALID
value|0x0000
define|#
directive|define
name|CPP_N_INTEGER
value|0x0001
define|#
directive|define
name|CPP_N_FLOATING
value|0x0002
define|#
directive|define
name|CPP_N_WIDTH
value|0x00F0
define|#
directive|define
name|CPP_N_SMALL
value|0x0010
comment|/* int, float.  */
define|#
directive|define
name|CPP_N_MEDIUM
value|0x0020
comment|/* long, double.  */
define|#
directive|define
name|CPP_N_LARGE
value|0x0040
comment|/* long long, long double.  */
define|#
directive|define
name|CPP_N_RADIX
value|0x0F00
define|#
directive|define
name|CPP_N_DECIMAL
value|0x0100
define|#
directive|define
name|CPP_N_HEX
value|0x0200
define|#
directive|define
name|CPP_N_OCTAL
value|0x0400
define|#
directive|define
name|CPP_N_UNSIGNED
value|0x1000
comment|/* Properties.  */
define|#
directive|define
name|CPP_N_IMAGINARY
value|0x2000
comment|/* Classify a CPP_NUMBER token.  The return value is a combination of    the flags from the above sets.  */
specifier|extern
name|unsigned
name|cpp_classify_number
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
comment|/* Evaluate a token classified as category CPP_N_INTEGER.  */
specifier|extern
name|cpp_num
name|cpp_interpret_integer
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
name|unsigned
name|int
name|type
operator|)
argument_list|)
decl_stmt|;
comment|/* Sign extend a number, with PRECISION significant bits and all    others assumed clear, to fill out a cpp_num structure.  */
name|cpp_num
name|cpp_num_sign_extend
name|PARAMS
argument_list|(
operator|(
name|cpp_num
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
comment|/* Diagnostic levels.  To get a dianostic without associating a    position in the translation unit with it, use cpp_error_with_line    with a line number of zero.  */
comment|/* Warning, an error with -Werror.  */
define|#
directive|define
name|DL_WARNING
value|0x00
comment|/* Same as DL_WARNING, except it is not suppressed in system headers.  */
define|#
directive|define
name|DL_WARNING_SYSHDR
value|0x01
comment|/* Warning, an error with -pedantic-errors or -Werror.  */
define|#
directive|define
name|DL_PEDWARN
value|0x02
comment|/* An error.  */
define|#
directive|define
name|DL_ERROR
value|0x03
comment|/* An internal consistency check failed.  Prints "internal error: ",    otherwise the same as DL_ERROR.  */
define|#
directive|define
name|DL_ICE
value|0x04
comment|/* Extracts a diagnostic level from an int.  */
define|#
directive|define
name|DL_EXTRACT
parameter_list|(
name|l
parameter_list|)
value|(l& 0xf)
comment|/* Nonzero if a diagnostic level is one of the warnings.  */
define|#
directive|define
name|DL_WARNING_P
parameter_list|(
name|l
parameter_list|)
value|(DL_EXTRACT (l)>= DL_WARNING \&& DL_EXTRACT (l)<= DL_PEDWARN)
comment|/* N.B. The error-message-printer prototypes have not been nicely    formatted because exgettext needs to see 'msgid' on the same line    as the name of the function in order to work properly.  Only the    string argument gets a name in an effort to keep the lines from    getting ridiculously oversized.  */
comment|/* Output a diagnostic of some kind.  */
specifier|extern
name|void
name|cpp_error
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
name|msgid
operator|,
operator|...
operator|)
argument_list|)
name|ATTRIBUTE_PRINTF_3
decl_stmt|;
comment|/* Output a diagnostic of severity LEVEL, with "MSG: " preceding the    error string of errno.  No location is printed.  */
specifier|extern
name|void
name|cpp_errno
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
name|int
name|level
operator|,
specifier|const
name|char
operator|*
name|msg
operator|)
argument_list|)
decl_stmt|;
comment|/* Same as cpp_error, except additionally specifies a position as a    (translation unit) physical line and physical column.  If the line is    zero, then no location is printed.  */
specifier|extern
name|void
name|cpp_error_with_line
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
name|int
operator|,
name|unsigned
operator|,
name|unsigned
operator|,
specifier|const
name|char
operator|*
name|msgid
operator|,
operator|...
operator|)
argument_list|)
name|ATTRIBUTE_PRINTF_5
decl_stmt|;
comment|/* In cpplex.c */
specifier|extern
name|int
name|cpp_ideq
name|PARAMS
argument_list|(
operator|(
specifier|const
name|cpp_token
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|cpp_output_line
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|cpp_output_token
name|PARAMS
argument_list|(
operator|(
specifier|const
name|cpp_token
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
specifier|extern
specifier|const
name|char
modifier|*
name|cpp_type2name
name|PARAMS
argument_list|(
operator|(
expr|enum
name|cpp_ttype
operator|)
argument_list|)
decl_stmt|;
comment|/* Returns the value of an escape sequence, truncated to the correct    target precision.  PSTR points to the input pointer, which is just    after the backslash.  LIMIT is how much text we have.  WIDE is true    if the escape sequence is part of a wide character constant or    string literal.  Handles all relevant diagnostics.  */
specifier|extern
name|cppchar_t
name|cpp_parse_escape
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
specifier|const
name|unsigned
name|char
operator|*
operator|*
name|pstr
operator|,
specifier|const
name|unsigned
name|char
operator|*
name|limit
operator|,
name|int
name|wide
operator|)
argument_list|)
decl_stmt|;
comment|/* In cpphash.c */
comment|/* Lookup an identifier in the hashtable.  Puts the identifier in the    table if it is not already there.  */
specifier|extern
name|cpp_hashnode
modifier|*
name|cpp_lookup
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
specifier|const
name|unsigned
name|char
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
typedef|typedef
name|int
argument_list|(
argument|*cpp_cb
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
name|cpp_hashnode
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
specifier|extern
name|void
name|cpp_forall_identifiers
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
name|cpp_cb
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* In cppmacro.c */
specifier|extern
name|void
name|cpp_scan_nooutput
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|cpp_sys_macro_p
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|unsigned
name|char
modifier|*
name|cpp_quote_string
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|,
specifier|const
name|unsigned
name|char
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
comment|/* In cppfiles.c */
specifier|extern
name|int
name|cpp_included
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
specifier|extern
name|void
name|cpp_make_system_header
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
comment|/* In cppmain.c */
specifier|extern
name|void
name|cpp_preprocess_file
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_CPPLIB_H */
end_comment

end_unit

