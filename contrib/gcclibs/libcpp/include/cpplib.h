begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for CPP library.    Copyright (C) 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003,    2004, 2005    Free Software Foundation, Inc.    Written by Per Bothner, 1994-95.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.   In other words, you are welcome to use, share and improve this program.  You are forbidden to forbid anyone else to use, share and improve  what you give them.   Help stamp out software-hoarding!  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LIBCPP_CPPLIB_H
end_ifndef

begin_define
define|#
directive|define
name|LIBCPP_CPPLIB_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"symtab.h"
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
typedef|typedef
name|struct
name|cpp_reader
name|cpp_reader
typedef|;
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
typedef|typedef
name|struct
name|cpp_dir
name|cpp_dir
typedef|;
struct_decl|struct
name|answer
struct_decl|;
struct_decl|struct
name|_cpp_file
struct_decl|;
comment|/* The first three groups, apart from '=', can appear in preprocessor    expressions (+= and -= are used to indicate unary + and - resp.).    This allows a lookup table to be implemented in _cpp_parse_expr.     The first group, to CPP_LAST_EQ, can be immediately followed by an    '='.  The lexer needs operators ending in '=', like ">>=", to be in    the same order as their counterparts without the '=', like ">>".     See the cpp_operator table optab in expr.c if you change the order or    add or remove anything in the first group.  */
define|#
directive|define
name|TTYPE_TABLE
define|\
value|OP(EQ,		"=")						\   OP(NOT,		"!")						\   OP(GREATER,		">")
comment|/* compare */
value|\   OP(LESS,		"<")						\   OP(PLUS,		"+")
comment|/* math */
value|\   OP(MINUS,		"-")						\   OP(MULT,		"*")						\   OP(DIV,		"/")						\   OP(MOD,		"%")						\   OP(AND,		"&")
comment|/* bit ops */
value|\   OP(OR,		"|")						\   OP(XOR,		"^")						\   OP(RSHIFT,		">>")						\   OP(LSHIFT,		"<<")						\ 									\   OP(COMPL,		"~")						\   OP(AND_AND,		"&&")
comment|/* logical */
value|\   OP(OR_OR,		"||")						\   OP(QUERY,		"?")						\   OP(COLON,		":")						\   OP(COMMA,		",")
comment|/* grouping */
value|\   OP(OPEN_PAREN,	"(")						\   OP(CLOSE_PAREN,	")")						\   TK(EOF,		NONE)						\   OP(EQ_EQ,		"==")
comment|/* compare */
value|\   OP(NOT_EQ,		"!=")						\   OP(GREATER_EQ,	">=")						\   OP(LESS_EQ,		"<=")						\ 									\
comment|/* These two are unary + / - in preprocessor expressions.  */
value|\   OP(PLUS_EQ,		"+=")
comment|/* math */
value|\   OP(MINUS_EQ,		"-=")						\ 									\   OP(MULT_EQ,		"*=")						\   OP(DIV_EQ,		"/=")						\   OP(MOD_EQ,		"%=")						\   OP(AND_EQ,		"&=")
comment|/* bit ops */
value|\   OP(OR_EQ,		"|=")						\   OP(XOR_EQ,		"^=")						\   OP(RSHIFT_EQ,		">>=")						\   OP(LSHIFT_EQ,		"<<=")						\
comment|/* Digraphs together, beginning with CPP_FIRST_DIGRAPH.  */
value|\   OP(HASH,		"#")
comment|/* digraphs */
value|\   OP(PASTE,		"##")						\   OP(OPEN_SQUARE,	"[")						\   OP(CLOSE_SQUARE,	"]")						\   OP(OPEN_BRACE,	"{")						\   OP(CLOSE_BRACE,	"}")						\
comment|/* The remainder of the punctuation.	Order is not significant.  */
value|\   OP(SEMICOLON,		";")
comment|/* structure */
value|\   OP(ELLIPSIS,		"...")						\   OP(PLUS_PLUS,		"++")
comment|/* increment */
value|\   OP(MINUS_MINUS,	"--")						\   OP(DEREF,		"->")
comment|/* accessors */
value|\   OP(DOT,		".")						\   OP(SCOPE,		"::")						\   OP(DEREF_STAR,	"->*")						\   OP(DOT_STAR,		".*")						\   OP(ATSIGN,		"@")
comment|/* used in Objective-C */
value|\ 									\   TK(NAME,		IDENT)
comment|/* word */
value|\   TK(AT_NAME,		IDENT)
comment|/* @word - Objective-C */
value|\   TK(NUMBER,		LITERAL)
comment|/* 34_be+ta  */
value|\ 									\   TK(CHAR,		LITERAL)
comment|/* 'char' */
value|\   TK(WCHAR,		LITERAL)
comment|/* L'char' */
value|\   TK(OTHER,		LITERAL)
comment|/* stray punctuation */
value|\ 									\   TK(STRING,		LITERAL)
comment|/* "string" */
value|\   TK(WSTRING,		LITERAL)
comment|/* L"string" */
value|\   TK(OBJC_STRING,	LITERAL)
comment|/* @"string" - Objective-C */
value|\   TK(HEADER_NAME,	LITERAL)
comment|/*<stdio.h> in #include */
value|\ 									\   TK(COMMENT,		LITERAL)
comment|/* Only if output comments.  */
value|\
comment|/* SPELL_LITERAL happens to DTRT.  */
value|\   TK(MACRO_ARG,		NONE)
comment|/* Macro argument.  */
value|\   TK(PRAGMA,		NONE)
comment|/* Only for deferred pragmas.  */
value|\   TK(PRAGMA_EOL,	NONE)
comment|/* End-of-line for deferred pragmas.  */
value|\   TK(PADDING,		NONE)
comment|/* Whitespace for -E.	*/
define|#
directive|define
name|OP
parameter_list|(
name|e
parameter_list|,
name|s
parameter_list|)
value|CPP_ ## e,
define|#
directive|define
name|TK
parameter_list|(
name|e
parameter_list|,
name|s
parameter_list|)
value|CPP_ ## e,
enum|enum
name|cpp_ttype
block|{
name|TTYPE_TABLE
name|N_TTYPES
block|,
comment|/* Positions in the table.  */
name|CPP_LAST_EQ
init|=
name|CPP_LSHIFT
block|,
name|CPP_FIRST_DIGRAPH
init|=
name|CPP_HASH
block|,
name|CPP_LAST_PUNCTUATOR
init|=
name|CPP_ATSIGN
block|,
name|CPP_LAST_CPP_OP
init|=
name|CPP_LESS_EQ
block|}
enum|;
undef|#
directive|undef
name|OP
undef|#
directive|undef
name|TK
comment|/* C language kind, used when calling cpp_create_reader.  */
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
name|struct
name|cpp_string
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
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
empty_stmt|;
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
define|#
directive|define
name|PURE_ZERO
value|(1<< 7)
comment|/* Single 0 digit, used by the C++ frontend, 				    set in c-lex.c.  */
comment|/* Specify which field, if any, of the cpp_token union is used.  */
enum|enum
name|cpp_token_fld_kind
block|{
name|CPP_TOKEN_FLD_NODE
block|,
name|CPP_TOKEN_FLD_SOURCE
block|,
name|CPP_TOKEN_FLD_STR
block|,
name|CPP_TOKEN_FLD_ARG_NO
block|,
name|CPP_TOKEN_FLD_PRAGMA
block|,
name|CPP_TOKEN_FLD_NONE
block|}
enum|;
comment|/* A preprocessing token.  This has been carefully packed and should    occupy 16 bytes on 32-bit hosts and 24 bytes on 64-bit hosts.  */
name|struct
name|cpp_token
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|source_location
name|src_loc
decl_stmt|;
comment|/* Location of first char of token.  */
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
name|cpp_token_u
block|{
comment|/* An identifier.  */
name|cpp_hashnode
modifier|*
name|GTY
argument_list|(
operator|(
name|nested_ptr
argument_list|(
expr|union
name|tree_node
argument_list|,
literal|"%h ? CPP_HASHNODE (GCC_IDENT_TO_HT_IDENT (%h)) : NULL"
argument_list|,
literal|"%h ? HT_IDENT_TO_GCC_IDENT (HT_NODE (%h)) : NULL"
argument_list|)
operator|,
name|tag
argument_list|(
literal|"CPP_TOKEN_FLD_NODE"
argument_list|)
operator|)
argument_list|)
name|node
decl_stmt|;
comment|/* Inherit padding from this token.  */
name|cpp_token
modifier|*
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"CPP_TOKEN_FLD_SOURCE"
argument_list|)
operator|)
argument_list|)
name|source
decl_stmt|;
comment|/* A string, or number.  */
name|struct
name|cpp_string
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"CPP_TOKEN_FLD_STR"
argument_list|)
operator|)
argument_list|)
name|str
decl_stmt|;
comment|/* Argument no. for a CPP_MACRO_ARG.  */
name|unsigned
name|int
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"CPP_TOKEN_FLD_ARG_NO"
argument_list|)
operator|)
argument_list|)
name|arg_no
decl_stmt|;
comment|/* Caller-supplied identifier for a CPP_PRAGMA.  */
name|unsigned
name|int
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"CPP_TOKEN_FLD_PRAGMA"
argument_list|)
operator|)
argument_list|)
name|pragma
decl_stmt|;
block|}
name|GTY
argument_list|(
operator|(
name|desc
argument_list|(
literal|"cpp_token_val_index (&%1)"
argument_list|)
operator|)
argument_list|)
name|val
union|;
block|}
empty_stmt|;
comment|/* Say which field is in use.  */
specifier|extern
name|enum
name|cpp_token_fld_kind
name|cpp_token_val_index
parameter_list|(
name|cpp_token
modifier|*
name|tok
parameter_list|)
function_decl|;
comment|/* A type wide enough to hold any multibyte source character.    cpplib's character constant interpreter requires an unsigned type.    Also, a typedef for the signed equivalent.    The width of this type is capped at 32 bits; there do exist targets    where wchar_t is 64 bits, but only in a non-default mode, and there    would be no meaningful interpretation for a wchar_t value greater    than 2^32 anyway -- the widest wide-character encoding around is    ISO 10646, which stops at 2^31.  */
if|#
directive|if
name|CHAR_BIT
operator|*
name|SIZEOF_INT
operator|>=
literal|32
define|#
directive|define
name|CPPCHAR_SIGNED_T
value|int
elif|#
directive|elif
name|CHAR_BIT
operator|*
name|SIZEOF_LONG
operator|>=
literal|32
define|#
directive|define
name|CPPCHAR_SIGNED_T
value|long
else|#
directive|else
error|#
directive|error
literal|"Cannot find a least-32-bit signed integer type"
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
comment|/* Style of header dependencies to generate.  */
enum|enum
name|cpp_deps_style
block|{
name|DEPS_NONE
init|=
literal|0
block|,
name|DEPS_USER
block|,
name|DEPS_SYSTEM
block|}
enum|;
comment|/* The possible normalization levels, from most restrictive to least.  */
enum|enum
name|cpp_normalize_level
block|{
comment|/* In NFKC.  */
name|normalized_KC
init|=
literal|0
block|,
comment|/* In NFC.  */
name|normalized_C
block|,
comment|/* In NFC, except for subsequences where being in NFC would make      the identifier invalid.  */
name|normalized_identifier_C
block|,
comment|/* Not normalized at all.  */
name|normalized_none
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
comment|/* The language we're preprocessing.  */
name|enum
name|c_lang
name|lang
decl_stmt|;
comment|/* Nonzero means use extra default include directories for C++.  */
name|unsigned
name|char
name|cplusplus
decl_stmt|;
comment|/* Nonzero means handle cplusplus style comments.  */
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
comment|/* Nonzero means complain about deprecated features.  */
name|unsigned
name|char
name|warn_deprecated
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
comment|/* Nonzero means warn if a user-supplied include directory does not      exist.  */
name|unsigned
name|char
name|warn_missing_include_dirs
decl_stmt|;
comment|/* Nonzero means warn if there are any trigraphs.  */
name|unsigned
name|char
name|warn_trigraphs
decl_stmt|;
comment|/* APPLE LOCAL begin -Wnewline-eof 2001-08-23 --sts */
comment|/* Nonzero means warn if no newline at end of file.  */
name|unsigned
name|char
name|warn_newline_at_eof
decl_stmt|;
comment|/* APPLE LOCAL end -Wnewline-eof 2001-08-23 --sts */
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
comment|/* Zero means don't warn about __VA_ARGS__ usage in c89 pedantic mode.      Presumably the usage is protected by the appropriate #ifdef.  */
name|unsigned
name|char
name|warn_variadic_macros
decl_stmt|;
comment|/* Nonzero means turn warnings into errors.  */
name|unsigned
name|char
name|warnings_are_errors
decl_stmt|;
comment|/* Nonzero means we should look for header.gcc files that remap file      names.  */
name|unsigned
name|char
name|remap
decl_stmt|;
comment|/* Zero means dollar signs are punctuation.  */
name|unsigned
name|char
name|dollars_in_ident
decl_stmt|;
comment|/* Nonzero means UCNs are accepted in identifiers.  */
name|unsigned
name|char
name|extended_identifiers
decl_stmt|;
comment|/* True if we should warn about dollars in identifiers or numbers      for this translation unit.  */
name|unsigned
name|char
name|warn_dollars
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
comment|/* Holds the name of the target (execution) character set.  */
specifier|const
name|char
modifier|*
name|narrow_charset
decl_stmt|;
comment|/* Holds the name of the target wide character set.  */
specifier|const
name|char
modifier|*
name|wide_charset
decl_stmt|;
comment|/* Holds the name of the input character set.  */
specifier|const
name|char
modifier|*
name|input_charset
decl_stmt|;
comment|/* The minimum permitted level of normalization before a warning      is generated.  */
name|enum
name|cpp_normalize_level
name|warn_normalize
decl_stmt|;
comment|/* True to warn about precompiled header files we couldn't use.  */
name|bool
name|warn_invalid_pch
decl_stmt|;
comment|/* True if dependencies should be restored from a precompiled header.  */
name|bool
name|restore_pch_deps
decl_stmt|;
comment|/* Dependency generation.  */
struct|struct
block|{
comment|/* Style of header dependencies to generate.  */
name|enum
name|cpp_deps_style
name|style
decl_stmt|;
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
comment|/* True if the most significant byte in a word has the lowest      address in memory.  */
name|bool
name|bytes_big_endian
decl_stmt|;
comment|/* Nonzero means __STDC__ should have the value 0 in system headers.  */
name|unsigned
name|char
name|stdc_0_in_system_headers
decl_stmt|;
comment|/* True means error callback should be used for diagnostics.  */
name|bool
name|client_diagnostic
decl_stmt|;
comment|/* True disables tokenization outside of preprocessing directives. */
name|bool
name|directives_only
decl_stmt|;
block|}
struct|;
comment|/* Callback for header lookup for HEADER, which is the name of a    source file.  It is used as a method of last resort to find headers    that are not otherwise found during the normal include processing.    The return value is the malloced name of a header to try and open,    if any, or NULL otherwise.  This callback is called only if the    header is otherwise unfound.  */
typedef|typedef
specifier|const
name|char
modifier|*
function_decl|(
modifier|*
name|missing_header_cb
function_decl|)
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|header
parameter_list|,
name|cpp_dir
modifier|*
modifier|*
parameter_list|)
function_decl|;
comment|/* Call backs to cpplib client.  */
struct|struct
name|cpp_callbacks
block|{
comment|/* Called when a new line of preprocessed output is started.  */
name|void
function_decl|(
modifier|*
name|line_change
function_decl|)
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|cpp_token
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* Called when switching to/from a new file.      The line_map is for the new file.  It is NULL if there is no new file.      (In C this happens when done with<built-in>+<command line> and also      when done with a main file.)  This can be used for resource cleanup.  */
name|void
function_decl|(
modifier|*
name|file_change
function_decl|)
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|struct
name|line_map
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|dir_change
function_decl|)
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|include
function_decl|)
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|cpp_token
modifier|*
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|define
function_decl|)
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|cpp_hashnode
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|undef
function_decl|)
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|cpp_hashnode
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ident
function_decl|)
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
specifier|const
name|cpp_string
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|def_pragma
function_decl|)
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|valid_pch
function_decl|)
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
name|void
function_decl|(
modifier|*
name|read_pch
function_decl|)
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
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|missing_header_cb
name|missing_header
decl_stmt|;
comment|/* Called to emit a diagnostic if client_diagnostic option is true.      This callback receives the translated message.  */
name|void
function_decl|(
modifier|*
name|error
function_decl|)
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
modifier|*
parameter_list|)
function_decl|ATTRIBUTE_FPTR_PRINTF
parameter_list|(
function_decl|3
operator|,
function_decl|0
block|)
struct|;
block|}
end_extern

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Chain of directories to look for include files in.  */
end_comment

begin_struct
struct|struct
name|cpp_dir
block|{
comment|/* NULL-terminated singly-linked list.  */
name|struct
name|cpp_dir
modifier|*
name|next
decl_stmt|;
comment|/* NAME of the directory, NUL-terminated.  */
name|char
modifier|*
name|name
decl_stmt|;
name|unsigned
name|int
name|len
decl_stmt|;
comment|/* One if a system header, two if a system header that has extern      "C" guards for C++.  */
name|unsigned
name|char
name|sysp
decl_stmt|;
comment|/* Mapping of file names for this directory for MS-DOS and related      platforms.  A NULL-terminated array of (from, to) pairs.  */
specifier|const
name|char
modifier|*
modifier|*
name|name_map
decl_stmt|;
comment|/* Routine to construct pathname, given the search path name and the      HEADER we are trying to find, return a constructed pathname to      try and open.  If this is NULL, the constructed pathname is as      constructed by append_file_to_dir.  */
name|char
modifier|*
function_decl|(
modifier|*
name|construct
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|header
parameter_list|,
name|cpp_dir
modifier|*
name|dir
parameter_list|)
function_decl|;
comment|/* The C front end uses these to recognize duplicated      directories in the search path.  */
name|ino_t
name|ino
decl_stmt|;
name|dev_t
name|dev
decl_stmt|;
comment|/* Is this a user-supplied directory? */
name|bool
name|user_supplied_p
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Name under which this program was invoked.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The structure of a node in the hash table.  The hash table has    entries for all identifiers: either macros defined by #define    commands (type NT_MACRO), assertions created with #assert    (NT_ASSERTION), or neither of the above (NT_VOID).  Builtin macros    like __LINE__ are flagged NODE_BUILTIN.  Poisoned identifiers are    flagged NODE_POISONED.  NODE_OPERATOR (C++ only) indicates an    identifier that behaves like an operator such as "xor".    NODE_DIAGNOSTIC is for speed in lex_token: it indicates a    diagnostic may be required for this node.  Currently this only    applies to __VA_ARGS__ and poisoned identifiers.  */
end_comment

begin_comment
comment|/* Hash node flags.  */
end_comment

begin_define
define|#
directive|define
name|NODE_OPERATOR
value|(1<< 0)
end_define

begin_comment
comment|/* C++ named operator.  */
end_comment

begin_define
define|#
directive|define
name|NODE_POISONED
value|(1<< 1)
end_define

begin_comment
comment|/* Poisoned identifier.  */
end_comment

begin_define
define|#
directive|define
name|NODE_BUILTIN
value|(1<< 2)
end_define

begin_comment
comment|/* Builtin macro.  */
end_comment

begin_define
define|#
directive|define
name|NODE_DIAGNOSTIC
value|(1<< 3)
end_define

begin_comment
comment|/* Possible diagnostic when lexed.  */
end_comment

begin_define
define|#
directive|define
name|NODE_WARN
value|(1<< 4)
end_define

begin_comment
comment|/* Warn if redefined or undefined.  */
end_comment

begin_define
define|#
directive|define
name|NODE_DISABLED
value|(1<< 5)
end_define

begin_comment
comment|/* A disabled macro.  */
end_comment

begin_define
define|#
directive|define
name|NODE_MACRO_ARG
value|(1<< 6)
end_define

begin_comment
comment|/* Used during #define processing.  */
end_comment

begin_comment
comment|/* Different flavors of hash node.  */
end_comment

begin_enum
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
end_enum

begin_comment
comment|/* Different flavors of builtin macro.  _Pragma is an operator, but we    handle it with the builtin code for efficiency reasons.  */
end_comment

begin_enum
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
block|,
comment|/* `_Pragma' operator */
name|BT_TIMESTAMP
block|,
comment|/* `__TIMESTAMP__' */
name|BT_COUNTER
comment|/* `__COUNTER__' */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|CPP_HASHNODE
parameter_list|(
name|HNODE
parameter_list|)
value|((cpp_hashnode *) (HNODE))
end_define

begin_define
define|#
directive|define
name|HT_NODE
parameter_list|(
name|NODE
parameter_list|)
value|((ht_identifier *) (NODE))
end_define

begin_define
define|#
directive|define
name|NODE_LEN
parameter_list|(
name|NODE
parameter_list|)
value|HT_LEN (&(NODE)->ident)
end_define

begin_define
define|#
directive|define
name|NODE_NAME
parameter_list|(
name|NODE
parameter_list|)
value|HT_STR (&(NODE)->ident)
end_define

begin_comment
comment|/* Specify which field, if any, of the union is used.  */
end_comment

begin_enum
enum|enum
block|{
name|NTV_MACRO
block|,
name|NTV_ANSWER
block|,
name|NTV_BUILTIN
block|,
name|NTV_ARGUMENT
block|,
name|NTV_NONE
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|CPP_HASHNODE_VALUE_IDX
parameter_list|(
name|HNODE
parameter_list|)
define|\
value|((HNODE.flags& NODE_MACRO_ARG) ? NTV_ARGUMENT		\    : HNODE.type == NT_MACRO ? ((HNODE.flags& NODE_BUILTIN) 	\ 			       ? NTV_BUILTIN : NTV_MACRO)	\    : HNODE.type == NT_ASSERTION ? NTV_ANSWER			\    : NTV_NONE)
end_define

begin_comment
comment|/* The common part of an identifier node shared amongst all 3 C front    ends.  Also used to store CPP identifiers, which are a superset of    identifiers in the grammatical sense.  */
end_comment

begin_decl_stmt
name|union
name|_cpp_hashnode_value
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* If a macro.  */
name|cpp_macro
modifier|*
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"NTV_MACRO"
argument_list|)
operator|)
argument_list|)
name|macro
decl_stmt|;
comment|/* Answers to an assertion.  */
name|struct
name|answer
modifier|*
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"NTV_ANSWER"
argument_list|)
operator|)
argument_list|)
name|answers
decl_stmt|;
comment|/* Code for a builtin macro.  */
name|enum
name|builtin_type
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"NTV_BUILTIN"
argument_list|)
operator|)
argument_list|)
name|builtin
decl_stmt|;
comment|/* Macro argument index.  */
name|unsigned
name|short
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"NTV_ARGUMENT"
argument_list|)
operator|)
argument_list|)
name|arg_index
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|struct
name|cpp_hashnode
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|ht_identifier
name|ident
decl_stmt|;
name|unsigned
name|int
name|is_directive
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|directive_index
range|:
literal|7
decl_stmt|;
comment|/* If is_directive, 					   then index into directive table. 					   Otherwise, a NODE_OPERATOR.  */
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
name|union
name|_cpp_hashnode_value
name|GTY
argument_list|(
operator|(
name|desc
argument_list|(
literal|"CPP_HASHNODE_VALUE_IDX (%1)"
argument_list|)
operator|)
argument_list|)
name|value
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Call this first to get a handle to pass to other functions.     If you want cpplib to manage its own hashtable, pass in a NULL    pointer.  Otherwise you should pass in an initialized hash table    that cpplib will share; this technique is used by the C front    ends.  */
end_comment

begin_function_decl
specifier|extern
name|cpp_reader
modifier|*
name|cpp_create_reader
parameter_list|(
name|enum
name|c_lang
parameter_list|,
name|struct
name|ht
modifier|*
parameter_list|,
name|struct
name|line_maps
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Call this to change the selected language standard (e.g. because of    command line options).  */
end_comment

begin_function_decl
specifier|extern
name|void
name|cpp_set_lang
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|enum
name|c_lang
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the include paths.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|cpp_set_include_chains
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|cpp_dir
modifier|*
parameter_list|,
name|cpp_dir
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Call these to get pointers to the options, callback, and deps    structures for a given reader.  These pointers are good until you    call cpp_finish on that reader.  You can either edit the callbacks    through the pointer returned from cpp_get_callbacks, or set them    with cpp_set_callbacks.  */
end_comment

begin_function_decl
specifier|extern
name|cpp_options
modifier|*
name|cpp_get_options
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|cpp_callbacks
modifier|*
name|cpp_get_callbacks
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cpp_set_callbacks
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|cpp_callbacks
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|deps
modifier|*
name|cpp_get_deps
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This function reads the file, but does not start preprocessing.  It    returns the name of the original file; this is the same as the    input file, except for preprocessed input.  This will generate at    least one file change callback, and possibly a line change callback    too.  If there was an error opening the file, it returns NULL.  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|cpp_read_main_file
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

begin_comment
comment|/* Set up built-ins with special behavior.  Use cpp_init_builtins()    instead unless your know what you are doing.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|cpp_init_special_builtins
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set up built-ins like __FILE__.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|cpp_init_builtins
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This is called after options have been parsed, and partially    processed.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|cpp_post_options
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set up translation to the target character set.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|cpp_init_iconv
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Call this to finish preprocessing.  If you requested dependency    generation, pass an open stream to write the information to,    otherwise NULL.  It is your responsibility to close the stream.     Returns cpp_errors (pfile).  */
end_comment

begin_function_decl
specifier|extern
name|int
name|cpp_finish
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|FILE
modifier|*
name|deps_stream
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Call this to release the handle at the end of preprocessing.  Any    use of the handle after this function returns is invalid.  Returns    cpp_errors (pfile).  */
end_comment

begin_function_decl
specifier|extern
name|void
name|cpp_destroy
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Error count.  */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|int
name|cpp_errors
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|cpp_token_len
parameter_list|(
specifier|const
name|cpp_token
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
name|cpp_token_as_text
parameter_list|(
name|cpp_reader
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
name|unsigned
name|char
modifier|*
name|cpp_spell_token
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|cpp_token
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cpp_register_pragma
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cpp_register_deferred_pragma
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|bool
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|cpp_avoid_paste
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
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
specifier|const
name|cpp_token
modifier|*
name|cpp_get_token
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|unsigned
name|char
modifier|*
name|cpp_macro_definition
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|cpp_hashnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cpp_backup_tokens
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Evaluate a CPP_CHAR or CPP_WCHAR token.  */
end_comment

begin_function_decl
specifier|extern
name|cppchar_t
name|cpp_interpret_charconst
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|cpp_token
modifier|*
parameter_list|,
name|unsigned
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Evaluate a vector of CPP_STRING or CPP_WSTRING tokens.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|cpp_interpret_string
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|cpp_string
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|cpp_string
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|cpp_interpret_string_notranslate
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|cpp_string
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|cpp_string
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convert a host character constant to the execution character set.  */
end_comment

begin_function_decl
specifier|extern
name|cppchar_t
name|cpp_host_to_exec_charset
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|cppchar_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Used to register macros and assertions, perhaps from the command line.    The text is the same as the command line argument.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|cpp_define
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
name|void
name|cpp_assert
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
name|void
name|cpp_undef
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
name|void
name|cpp_unassert
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

begin_comment
comment|/* Undefine all macros and assertions.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|cpp_undef_all
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|cpp_buffer
modifier|*
name|cpp_push_buffer
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|cpp_defined
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* A preprocessing number.  Code assumes that any unused high bits of    the double integer are set to zero.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|HOST_WIDE_INT
name|cpp_num_part
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|cpp_num
name|cpp_num
typedef|;
end_typedef

begin_struct
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
end_struct

begin_comment
comment|/* cpplib provides two interfaces for interpretation of preprocessing    numbers.     cpp_classify_number categorizes numeric constants according to    their field (integer, floating point, or invalid), radix (decimal,    octal, hexadecimal), and type suffixes.  */
end_comment

begin_define
define|#
directive|define
name|CPP_N_CATEGORY
value|0x000F
end_define

begin_define
define|#
directive|define
name|CPP_N_INVALID
value|0x0000
end_define

begin_define
define|#
directive|define
name|CPP_N_INTEGER
value|0x0001
end_define

begin_define
define|#
directive|define
name|CPP_N_FLOATING
value|0x0002
end_define

begin_define
define|#
directive|define
name|CPP_N_WIDTH
value|0x00F0
end_define

begin_define
define|#
directive|define
name|CPP_N_SMALL
value|0x0010
end_define

begin_comment
comment|/* int, float.  */
end_comment

begin_define
define|#
directive|define
name|CPP_N_MEDIUM
value|0x0020
end_define

begin_comment
comment|/* long, double.  */
end_comment

begin_define
define|#
directive|define
name|CPP_N_LARGE
value|0x0040
end_define

begin_comment
comment|/* long long, long double.  */
end_comment

begin_define
define|#
directive|define
name|CPP_N_RADIX
value|0x0F00
end_define

begin_define
define|#
directive|define
name|CPP_N_DECIMAL
value|0x0100
end_define

begin_define
define|#
directive|define
name|CPP_N_HEX
value|0x0200
end_define

begin_define
define|#
directive|define
name|CPP_N_OCTAL
value|0x0400
end_define

begin_define
define|#
directive|define
name|CPP_N_BINARY
value|0x0800
end_define

begin_define
define|#
directive|define
name|CPP_N_UNSIGNED
value|0x1000
end_define

begin_comment
comment|/* Properties.  */
end_comment

begin_define
define|#
directive|define
name|CPP_N_IMAGINARY
value|0x2000
end_define

begin_define
define|#
directive|define
name|CPP_N_DFLOAT
value|0x4000
end_define

begin_define
define|#
directive|define
name|CPP_N_DEFAULT
value|0x8000
end_define

begin_comment
comment|/* Classify a CPP_NUMBER token.  The return value is a combination of    the flags from the above sets.  */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|cpp_classify_number
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|cpp_token
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Evaluate a token classified as category CPP_N_INTEGER.  */
end_comment

begin_function_decl
specifier|extern
name|cpp_num
name|cpp_interpret_integer
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|cpp_token
modifier|*
parameter_list|,
name|unsigned
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Sign extend a number, with PRECISION significant bits and all    others assumed clear, to fill out a cpp_num structure.  */
end_comment

begin_function_decl
name|cpp_num
name|cpp_num_sign_extend
parameter_list|(
name|cpp_num
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Diagnostic levels.  To get a diagnostic without associating a    position in the translation unit with it, use cpp_error_with_line    with a line number of zero.  */
end_comment

begin_comment
comment|/* Warning, an error with -Werror.  */
end_comment

begin_define
define|#
directive|define
name|CPP_DL_WARNING
value|0x00
end_define

begin_comment
comment|/* Same as CPP_DL_WARNING, except it is not suppressed in system headers.  */
end_comment

begin_define
define|#
directive|define
name|CPP_DL_WARNING_SYSHDR
value|0x01
end_define

begin_comment
comment|/* Warning, an error with -pedantic-errors or -Werror.  */
end_comment

begin_define
define|#
directive|define
name|CPP_DL_PEDWARN
value|0x02
end_define

begin_comment
comment|/* An error.  */
end_comment

begin_define
define|#
directive|define
name|CPP_DL_ERROR
value|0x03
end_define

begin_comment
comment|/* An internal consistency check failed.  Prints "internal error: ",    otherwise the same as CPP_DL_ERROR.  */
end_comment

begin_define
define|#
directive|define
name|CPP_DL_ICE
value|0x04
end_define

begin_comment
comment|/* Extracts a diagnostic level from an int.  */
end_comment

begin_define
define|#
directive|define
name|CPP_DL_EXTRACT
parameter_list|(
name|l
parameter_list|)
value|(l& 0xf)
end_define

begin_comment
comment|/* Nonzero if a diagnostic level is one of the warnings.  */
end_comment

begin_define
define|#
directive|define
name|CPP_DL_WARNING_P
parameter_list|(
name|l
parameter_list|)
value|(CPP_DL_EXTRACT (l)>= CPP_DL_WARNING \&& CPP_DL_EXTRACT (l)<= CPP_DL_PEDWARN)
end_define

begin_comment
comment|/* Output a diagnostic of some kind.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|cpp_error
argument_list|(
name|cpp_reader
operator|*
argument_list|,
name|int
argument_list|,
specifier|const
name|char
operator|*
name|msgid
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_PRINTF_3
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output a diagnostic with "MSGID: " preceding the    error string of errno.  No location is printed.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|cpp_errno
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
name|msgid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Same as cpp_error, except additionally specifies a position as a    (translation unit) physical line and physical column.  If the line is    zero, then no location is printed.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|cpp_error_with_line
argument_list|(
name|cpp_reader
operator|*
argument_list|,
name|int
argument_list|,
name|source_location
argument_list|,
name|unsigned
argument_list|,
specifier|const
name|char
operator|*
name|msgid
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_PRINTF_5
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In cpplex.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|cpp_ideq
parameter_list|(
specifier|const
name|cpp_token
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
name|void
name|cpp_output_line
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
name|void
name|cpp_output_token
parameter_list|(
specifier|const
name|cpp_token
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|cpp_type2name
parameter_list|(
name|enum
name|cpp_ttype
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns the value of an escape sequence, truncated to the correct    target precision.  PSTR points to the input pointer, which is just    after the backslash.  LIMIT is how much text we have.  WIDE is true    if the escape sequence is part of a wide character constant or    string literal.  Handles all relevant diagnostics.  */
end_comment

begin_function_decl
specifier|extern
name|cppchar_t
name|cpp_parse_escape
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
modifier|*
name|pstr
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|limit
parameter_list|,
name|int
name|wide
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In cpphash.c */
end_comment

begin_comment
comment|/* Lookup an identifier in the hashtable.  Puts the identifier in the    table if it is not already there.  */
end_comment

begin_function_decl
specifier|extern
name|cpp_hashnode
modifier|*
name|cpp_lookup
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|cpp_cb
function_decl|)
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
end_typedef

begin_function_decl
specifier|extern
name|void
name|cpp_forall_identifiers
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|cpp_cb
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In cppmacro.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|cpp_scan_nooutput
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|cpp_sys_macro_p
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
name|cpp_quote_string
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In cppfiles.c */
end_comment

begin_function_decl
specifier|extern
name|bool
name|cpp_included
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
name|void
name|cpp_make_system_header
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|cpp_push_include
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
name|void
name|cpp_change_file
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|cpp_get_path
parameter_list|(
name|struct
name|_cpp_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|cpp_dir
modifier|*
name|cpp_get_dir
parameter_list|(
name|struct
name|_cpp_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|cpp_buffer
modifier|*
name|cpp_get_buffer
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|_cpp_file
modifier|*
name|cpp_get_file
parameter_list|(
name|cpp_buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|cpp_buffer
modifier|*
name|cpp_get_prev
parameter_list|(
name|cpp_buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In cpppch.c */
end_comment

begin_struct_decl
struct_decl|struct
name|save_macro_data
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|cpp_save_state
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
name|int
name|cpp_write_pch_deps
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
name|int
name|cpp_write_pch_state
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
name|int
name|cpp_valid_state
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
name|cpp_prepare_state
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|struct
name|save_macro_data
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|cpp_read_state
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
name|struct
name|save_macro_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LIBCPP_CPPLIB_H */
end_comment

end_unit

