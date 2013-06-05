begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Extended regular expression matching and search library.    Copyright (C) 2002-2012 Free Software Foundation, Inc.    This file is part of the GNU C Library.    Contributed by Isamu Hasegawa<isamu@yamato.ibm.com>.     The GNU C Library is free software; you can redistribute it and/or    modify it under the terms of the GNU Lesser General Public    License as published by the Free Software Foundation; either    version 2.1 of the License, or (at your option) any later version.     The GNU C Library is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Lesser General Public License for more details.     You should have received a copy of the GNU Lesser General Public    License along with the GNU C Library; if not, see<http://www.gnu.org/licenses/>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_REGEX_INTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|_REGEX_INTERNAL_H
value|1
end_define

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_if
if|#
directive|if
name|defined
name|HAVE_LANGINFO_H
operator|||
name|defined
name|HAVE_LANGINFO_CODESET
operator|||
name|defined
name|_LIBC
end_if

begin_include
include|#
directive|include
file|<langinfo.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
name|HAVE_LOCALE_H
operator|||
name|defined
name|_LIBC
end_if

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
name|HAVE_WCHAR_H
operator|||
name|defined
name|_LIBC
end_if

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_WCHAR_H || _LIBC */
end_comment

begin_if
if|#
directive|if
name|defined
name|HAVE_WCTYPE_H
operator|||
name|defined
name|_LIBC
end_if

begin_include
include|#
directive|include
file|<wctype.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_WCTYPE_H || _LIBC */
end_comment

begin_if
if|#
directive|if
name|defined
name|HAVE_STDBOOL_H
operator|||
name|defined
name|_LIBC
end_if

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STDBOOL_H || _LIBC */
end_comment

begin_if
if|#
directive|if
name|defined
name|HAVE_STDINT_H
operator|||
name|defined
name|_LIBC
end_if

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STDINT_H || _LIBC */
end_comment

begin_if
if|#
directive|if
name|defined
name|_LIBC
end_if

begin_include
include|#
directive|include
file|<bits/libc-lock.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__libc_lock_define
parameter_list|(
name|CLASS
parameter_list|,
name|NAME
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__libc_lock_init
parameter_list|(
name|NAME
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|__libc_lock_lock
parameter_list|(
name|NAME
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|__libc_lock_unlock
parameter_list|(
name|NAME
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In case that the system doesn't have isblank().  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|_LIBC
operator|&&
operator|!
name|defined
name|HAVE_ISBLANK
operator|&&
operator|!
name|defined
name|isblank
end_if

begin_define
define|#
directive|define
name|isblank
parameter_list|(
name|ch
parameter_list|)
value|((ch) == ' ' || (ch) == '\t')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_RE_DEFINE_LOCALE_FUNCTIONS
end_ifndef

begin_define
define|#
directive|define
name|_RE_DEFINE_LOCALE_FUNCTIONS
value|1
end_define

begin_include
include|#
directive|include
file|<locale/localeinfo.h>
end_include

begin_include
include|#
directive|include
file|<locale/elem-hash.h>
end_include

begin_include
include|#
directive|include
file|<locale/coll-lookup.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is for other GNU distributions with internationalized messages.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|HAVE_LIBINTL_H
operator|&&
name|ENABLE_NLS
operator|)
operator|||
name|defined
name|_LIBC
end_if

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_undef
undef|#
directive|undef
name|gettext
end_undef

begin_define
define|#
directive|define
name|gettext
parameter_list|(
name|msgid
parameter_list|)
define|\
value|__dcgettext (_libc_intl_domainname, msgid, LC_MESSAGES)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|gettext
parameter_list|(
name|msgid
parameter_list|)
value|(msgid)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|gettext_noop
end_ifndef

begin_comment
comment|/* This define is so xgettext can find the internationalizable    strings.  */
end_comment

begin_define
define|#
directive|define
name|gettext_noop
parameter_list|(
name|String
parameter_list|)
value|String
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For loser systems without the definition.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIZE_MAX
end_ifndef

begin_define
define|#
directive|define
name|SIZE_MAX
value|((size_t) -1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
name|MB_CUR_MAX
operator|&&
name|HAVE_LOCALE_H
operator|&&
name|HAVE_WCTYPE_H
operator|&&
name|HAVE_WCHAR_H
operator|&&
name|HAVE_WCRTOMB
operator|&&
name|HAVE_MBRTOWC
operator|&&
name|HAVE_WCSCOLL
operator|)
operator|||
name|_LIBC
end_if

begin_define
define|#
directive|define
name|RE_ENABLE_I18N
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__GNUC__
operator|>=
literal|3
end_if

begin_define
define|#
directive|define
name|BE
parameter_list|(
name|expr
parameter_list|,
name|val
parameter_list|)
value|__builtin_expect (expr, val)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BE
parameter_list|(
name|expr
parameter_list|,
name|val
parameter_list|)
value|(expr)
end_define

begin_define
define|#
directive|define
name|inline
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of single byte character.  */
end_comment

begin_define
define|#
directive|define
name|SBC_MAX
value|256
end_define

begin_define
define|#
directive|define
name|COLL_ELEM_LEN_MAX
value|8
end_define

begin_comment
comment|/* The character which represents newline.  */
end_comment

begin_define
define|#
directive|define
name|NEWLINE_CHAR
value|'\n'
end_define

begin_define
define|#
directive|define
name|WIDE_NEWLINE_CHAR
value|L'\n'
end_define

begin_comment
comment|/* Rename to standard API for using out of glibc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBC
end_ifndef

begin_define
define|#
directive|define
name|__wctype
value|wctype
end_define

begin_define
define|#
directive|define
name|__iswctype
value|iswctype
end_define

begin_define
define|#
directive|define
name|__btowc
value|btowc
end_define

begin_define
define|#
directive|define
name|__mbrtowc
value|mbrtowc
end_define

begin_define
define|#
directive|define
name|__mempcpy
value|mempcpy
end_define

begin_define
define|#
directive|define
name|__wcrtomb
value|wcrtomb
end_define

begin_define
define|#
directive|define
name|__regfree
value|regfree
end_define

begin_define
define|#
directive|define
name|attribute_hidden
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _LIBC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|__attribute
parameter_list|(
name|arg
parameter_list|)
value|__attribute__ (arg)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__attribute
parameter_list|(
name|arg
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|__re_error_msgid
index|[]
name|attribute_hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|size_t
name|__re_error_msgid_idx
index|[]
name|attribute_hidden
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* An integer used to represent a set of bits.  It must be unsigned,    and must be at least as wide as unsigned int.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|int
name|bitset_word_t
typedef|;
end_typedef

begin_comment
comment|/* All bits set in a bitset_word_t.  */
end_comment

begin_define
define|#
directive|define
name|BITSET_WORD_MAX
value|ULONG_MAX
end_define

begin_comment
comment|/* Number of bits in a bitset_word_t.  */
end_comment

begin_define
define|#
directive|define
name|BITSET_WORD_BITS
value|(sizeof (bitset_word_t) * CHAR_BIT)
end_define

begin_comment
comment|/* Number of bitset_word_t in a bit_set.  */
end_comment

begin_define
define|#
directive|define
name|BITSET_WORDS
value|(SBC_MAX / BITSET_WORD_BITS)
end_define

begin_typedef
typedef|typedef
name|bitset_word_t
name|bitset_t
index|[
name|BITSET_WORDS
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|bitset_word_t
modifier|*
name|re_bitset_ptr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|bitset_word_t
modifier|*
name|re_const_bitset_ptr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|bitset_set
parameter_list|(
name|set
parameter_list|,
name|i
parameter_list|)
define|\
value|(set[i / BITSET_WORD_BITS] |= (bitset_word_t) 1<< i % BITSET_WORD_BITS)
end_define

begin_define
define|#
directive|define
name|bitset_clear
parameter_list|(
name|set
parameter_list|,
name|i
parameter_list|)
define|\
value|(set[i / BITSET_WORD_BITS]&= ~((bitset_word_t) 1<< i % BITSET_WORD_BITS))
end_define

begin_define
define|#
directive|define
name|bitset_contain
parameter_list|(
name|set
parameter_list|,
name|i
parameter_list|)
define|\
value|(set[i / BITSET_WORD_BITS]& ((bitset_word_t) 1<< i % BITSET_WORD_BITS))
end_define

begin_define
define|#
directive|define
name|bitset_empty
parameter_list|(
name|set
parameter_list|)
value|memset (set, '\0', sizeof (bitset_t))
end_define

begin_define
define|#
directive|define
name|bitset_set_all
parameter_list|(
name|set
parameter_list|)
value|memset (set, '\xff', sizeof (bitset_t))
end_define

begin_define
define|#
directive|define
name|bitset_copy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
value|memcpy (dest, src, sizeof (bitset_t))
end_define

begin_define
define|#
directive|define
name|PREV_WORD_CONSTRAINT
value|0x0001
end_define

begin_define
define|#
directive|define
name|PREV_NOTWORD_CONSTRAINT
value|0x0002
end_define

begin_define
define|#
directive|define
name|NEXT_WORD_CONSTRAINT
value|0x0004
end_define

begin_define
define|#
directive|define
name|NEXT_NOTWORD_CONSTRAINT
value|0x0008
end_define

begin_define
define|#
directive|define
name|PREV_NEWLINE_CONSTRAINT
value|0x0010
end_define

begin_define
define|#
directive|define
name|NEXT_NEWLINE_CONSTRAINT
value|0x0020
end_define

begin_define
define|#
directive|define
name|PREV_BEGBUF_CONSTRAINT
value|0x0040
end_define

begin_define
define|#
directive|define
name|NEXT_ENDBUF_CONSTRAINT
value|0x0080
end_define

begin_define
define|#
directive|define
name|WORD_DELIM_CONSTRAINT
value|0x0100
end_define

begin_define
define|#
directive|define
name|NOT_WORD_DELIM_CONSTRAINT
value|0x0200
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|INSIDE_WORD
init|=
name|PREV_WORD_CONSTRAINT
operator||
name|NEXT_WORD_CONSTRAINT
block|,
name|WORD_FIRST
init|=
name|PREV_NOTWORD_CONSTRAINT
operator||
name|NEXT_WORD_CONSTRAINT
block|,
name|WORD_LAST
init|=
name|PREV_WORD_CONSTRAINT
operator||
name|NEXT_NOTWORD_CONSTRAINT
block|,
name|INSIDE_NOTWORD
init|=
name|PREV_NOTWORD_CONSTRAINT
operator||
name|NEXT_NOTWORD_CONSTRAINT
block|,
name|LINE_FIRST
init|=
name|PREV_NEWLINE_CONSTRAINT
block|,
name|LINE_LAST
init|=
name|NEXT_NEWLINE_CONSTRAINT
block|,
name|BUF_FIRST
init|=
name|PREV_BEGBUF_CONSTRAINT
block|,
name|BUF_LAST
init|=
name|NEXT_ENDBUF_CONSTRAINT
block|,
name|WORD_DELIM
init|=
name|WORD_DELIM_CONSTRAINT
block|,
name|NOT_WORD_DELIM
init|=
name|NOT_WORD_DELIM_CONSTRAINT
block|}
name|re_context_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|alloc
decl_stmt|;
name|int
name|nelem
decl_stmt|;
name|int
modifier|*
name|elems
decl_stmt|;
block|}
name|re_node_set
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|NON_TYPE
init|=
literal|0
block|,
comment|/* Node type, These are used by token, node, tree.  */
name|CHARACTER
init|=
literal|1
block|,
name|END_OF_RE
init|=
literal|2
block|,
name|SIMPLE_BRACKET
init|=
literal|3
block|,
name|OP_BACK_REF
init|=
literal|4
block|,
name|OP_PERIOD
init|=
literal|5
block|,
ifdef|#
directive|ifdef
name|RE_ENABLE_I18N
name|COMPLEX_BRACKET
init|=
literal|6
block|,
name|OP_UTF8_PERIOD
init|=
literal|7
block|,
endif|#
directive|endif
comment|/* RE_ENABLE_I18N */
comment|/* We define EPSILON_BIT as a macro so that OP_OPEN_SUBEXP is used      when the debugger shows values of this enum type.  */
define|#
directive|define
name|EPSILON_BIT
value|8
name|OP_OPEN_SUBEXP
init|=
name|EPSILON_BIT
operator||
literal|0
block|,
name|OP_CLOSE_SUBEXP
init|=
name|EPSILON_BIT
operator||
literal|1
block|,
name|OP_ALT
init|=
name|EPSILON_BIT
operator||
literal|2
block|,
name|OP_DUP_ASTERISK
init|=
name|EPSILON_BIT
operator||
literal|3
block|,
name|ANCHOR
init|=
name|EPSILON_BIT
operator||
literal|4
block|,
comment|/* Tree type, these are used only by tree. */
name|CONCAT
init|=
literal|16
block|,
name|SUBEXP
init|=
literal|17
block|,
comment|/* Token type, these are used only by token.  */
name|OP_DUP_PLUS
init|=
literal|18
block|,
name|OP_DUP_QUESTION
block|,
name|OP_OPEN_BRACKET
block|,
name|OP_CLOSE_BRACKET
block|,
name|OP_CHARSET_RANGE
block|,
name|OP_OPEN_DUP_NUM
block|,
name|OP_CLOSE_DUP_NUM
block|,
name|OP_NON_MATCH_LIST
block|,
name|OP_OPEN_COLL_ELEM
block|,
name|OP_CLOSE_COLL_ELEM
block|,
name|OP_OPEN_EQUIV_CLASS
block|,
name|OP_CLOSE_EQUIV_CLASS
block|,
name|OP_OPEN_CHAR_CLASS
block|,
name|OP_CLOSE_CHAR_CLASS
block|,
name|OP_WORD
block|,
name|OP_NOTWORD
block|,
name|OP_SPACE
block|,
name|OP_NOTSPACE
block|,
name|BACK_SLASH
block|}
name|re_token_type_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|RE_ENABLE_I18N
end_ifdef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Multibyte characters.  */
name|wchar_t
modifier|*
name|mbchars
decl_stmt|;
comment|/* Collating symbols.  */
ifdef|#
directive|ifdef
name|_LIBC
name|int32_t
modifier|*
name|coll_syms
decl_stmt|;
endif|#
directive|endif
comment|/* Equivalence classes. */
ifdef|#
directive|ifdef
name|_LIBC
name|int32_t
modifier|*
name|equiv_classes
decl_stmt|;
endif|#
directive|endif
comment|/* Range expressions. */
ifdef|#
directive|ifdef
name|_LIBC
name|uint32_t
modifier|*
name|range_starts
decl_stmt|;
name|uint32_t
modifier|*
name|range_ends
decl_stmt|;
else|#
directive|else
comment|/* not _LIBC */
name|wchar_t
modifier|*
name|range_starts
decl_stmt|;
name|wchar_t
modifier|*
name|range_ends
decl_stmt|;
endif|#
directive|endif
comment|/* not _LIBC */
comment|/* Character classes. */
name|wctype_t
modifier|*
name|char_classes
decl_stmt|;
comment|/* If this character set is the non-matching list.  */
name|unsigned
name|int
name|non_match
range|:
literal|1
decl_stmt|;
comment|/* # of multibyte characters.  */
name|int
name|nmbchars
decl_stmt|;
comment|/* # of collating symbols.  */
name|int
name|ncoll_syms
decl_stmt|;
comment|/* # of equivalence classes. */
name|int
name|nequiv_classes
decl_stmt|;
comment|/* # of range expressions. */
name|int
name|nranges
decl_stmt|;
comment|/* # of character classes. */
name|int
name|nchar_classes
decl_stmt|;
block|}
name|re_charset_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RE_ENABLE_I18N */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
union|union
block|{
name|unsigned
name|char
name|c
decl_stmt|;
comment|/* for CHARACTER */
name|re_bitset_ptr_t
name|sbcset
decl_stmt|;
comment|/* for SIMPLE_BRACKET */
ifdef|#
directive|ifdef
name|RE_ENABLE_I18N
name|re_charset_t
modifier|*
name|mbcset
decl_stmt|;
comment|/* for COMPLEX_BRACKET */
endif|#
directive|endif
comment|/* RE_ENABLE_I18N */
name|int
name|idx
decl_stmt|;
comment|/* for BACK_REF */
name|re_context_type
name|ctx_type
decl_stmt|;
comment|/* for ANCHOR */
block|}
name|opr
union|;
if|#
directive|if
name|__GNUC__
operator|>=
literal|2
name|re_token_type_t
name|type
range|:
literal|8
decl_stmt|;
else|#
directive|else
name|re_token_type_t
name|type
decl_stmt|;
endif|#
directive|endif
name|unsigned
name|int
name|constraint
range|:
literal|10
decl_stmt|;
comment|/* context constraint */
name|unsigned
name|int
name|duplicated
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|opt_subexp
range|:
literal|1
decl_stmt|;
ifdef|#
directive|ifdef
name|RE_ENABLE_I18N
name|unsigned
name|int
name|accept_mb
range|:
literal|1
decl_stmt|;
comment|/* These 2 bits can be moved into the union if needed (e.g. if running out      of bits; move opr.c to opr.c.c and move the flags to opr.c.flags).  */
name|unsigned
name|int
name|mb_partial
range|:
literal|1
decl_stmt|;
endif|#
directive|endif
name|unsigned
name|int
name|word_char
range|:
literal|1
decl_stmt|;
block|}
name|re_token_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IS_EPSILON_NODE
parameter_list|(
name|type
parameter_list|)
value|((type)& EPSILON_BIT)
end_define

begin_struct
struct|struct
name|re_string_t
block|{
comment|/* Indicate the raw buffer which is the original string passed as an      argument of regexec(), re_search(), etc..  */
specifier|const
name|unsigned
name|char
modifier|*
name|raw_mbs
decl_stmt|;
comment|/* Store the multibyte string.  In case of "case insensitive mode" like      REG_ICASE, upper cases of the string are stored, otherwise MBS points      the same address that RAW_MBS points.  */
name|unsigned
name|char
modifier|*
name|mbs
decl_stmt|;
ifdef|#
directive|ifdef
name|RE_ENABLE_I18N
comment|/* Store the wide character string which is corresponding to MBS.  */
name|wint_t
modifier|*
name|wcs
decl_stmt|;
name|int
modifier|*
name|offsets
decl_stmt|;
name|mbstate_t
name|cur_state
decl_stmt|;
endif|#
directive|endif
comment|/* Index in RAW_MBS.  Each character mbs[i] corresponds to      raw_mbs[raw_mbs_idx + i].  */
name|int
name|raw_mbs_idx
decl_stmt|;
comment|/* The length of the valid characters in the buffers.  */
name|int
name|valid_len
decl_stmt|;
comment|/* The corresponding number of bytes in raw_mbs array.  */
name|int
name|valid_raw_len
decl_stmt|;
comment|/* The length of the buffers MBS and WCS.  */
name|int
name|bufs_len
decl_stmt|;
comment|/* The index in MBS, which is updated by re_string_fetch_byte.  */
name|int
name|cur_idx
decl_stmt|;
comment|/* length of RAW_MBS array.  */
name|int
name|raw_len
decl_stmt|;
comment|/* This is RAW_LEN - RAW_MBS_IDX + VALID_LEN - VALID_RAW_LEN.  */
name|int
name|len
decl_stmt|;
comment|/* End of the buffer may be shorter than its length in the cases such      as re_match_2, re_search_2.  Then, we use STOP for end of the buffer      instead of LEN.  */
name|int
name|raw_stop
decl_stmt|;
comment|/* This is RAW_STOP - RAW_MBS_IDX adjusted through OFFSETS.  */
name|int
name|stop
decl_stmt|;
comment|/* The context of mbs[0].  We store the context independently, since      the context of mbs[0] may be different from raw_mbs[0], which is      the beginning of the input string.  */
name|unsigned
name|int
name|tip_context
decl_stmt|;
comment|/* The translation passed as a part of an argument of re_compile_pattern.  */
name|RE_TRANSLATE_TYPE
name|trans
decl_stmt|;
comment|/* Copy of re_dfa_t's word_char.  */
name|re_const_bitset_ptr_t
name|word_char
decl_stmt|;
comment|/* 1 if REG_ICASE.  */
name|unsigned
name|char
name|icase
decl_stmt|;
name|unsigned
name|char
name|is_utf8
decl_stmt|;
name|unsigned
name|char
name|map_notascii
decl_stmt|;
name|unsigned
name|char
name|mbs_allocated
decl_stmt|;
name|unsigned
name|char
name|offsets_needed
decl_stmt|;
name|unsigned
name|char
name|newline_anchor
decl_stmt|;
name|unsigned
name|char
name|word_ops_used
decl_stmt|;
name|int
name|mb_cur_max
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|re_string_t
name|re_string_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|re_dfa_t
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|re_dfa_t
name|re_dfa_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBC
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_define
define|#
directive|define
name|internal_function
value|__attribute ((regparm (3), stdcall))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|internal_function
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NOT_IN_libc
end_ifndef

begin_decl_stmt
specifier|static
name|reg_errcode_t
name|re_string_realloc_buffers
argument_list|(
name|re_string_t
operator|*
name|pstr
argument_list|,
name|int
name|new_buf_len
argument_list|)
name|internal_function
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|RE_ENABLE_I18N
end_ifdef

begin_decl_stmt
specifier|static
name|void
name|build_wcs_buffer
argument_list|(
name|re_string_t
operator|*
name|pstr
argument_list|)
name|internal_function
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|reg_errcode_t
name|build_wcs_upper_buffer
argument_list|(
name|re_string_t
operator|*
name|pstr
argument_list|)
name|internal_function
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RE_ENABLE_I18N */
end_comment

begin_decl_stmt
specifier|static
name|void
name|build_upper_buffer
argument_list|(
name|re_string_t
operator|*
name|pstr
argument_list|)
name|internal_function
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|re_string_translate_buffer
argument_list|(
name|re_string_t
operator|*
name|pstr
argument_list|)
name|internal_function
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|unsigned
name|int
name|re_string_context_at
argument_list|(
specifier|const
name|re_string_t
operator|*
name|input
argument_list|,
name|int
name|idx
argument_list|,
name|int
name|eflags
argument_list|)
name|internal_function
name|__attribute
argument_list|(
operator|(
name|pure
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|re_string_peek_byte
parameter_list|(
name|pstr
parameter_list|,
name|offset
parameter_list|)
define|\
value|((pstr)->mbs[(pstr)->cur_idx + offset])
end_define

begin_define
define|#
directive|define
name|re_string_fetch_byte
parameter_list|(
name|pstr
parameter_list|)
define|\
value|((pstr)->mbs[(pstr)->cur_idx++])
end_define

begin_define
define|#
directive|define
name|re_string_first_byte
parameter_list|(
name|pstr
parameter_list|,
name|idx
parameter_list|)
define|\
value|((idx) == (pstr)->valid_len || (pstr)->wcs[idx] != WEOF)
end_define

begin_define
define|#
directive|define
name|re_string_is_single_byte_char
parameter_list|(
name|pstr
parameter_list|,
name|idx
parameter_list|)
define|\
value|((pstr)->wcs[idx] != WEOF&& ((pstr)->valid_len == (idx) + 1 \ 				|| (pstr)->wcs[(idx) + 1] != WEOF))
end_define

begin_define
define|#
directive|define
name|re_string_eoi
parameter_list|(
name|pstr
parameter_list|)
value|((pstr)->stop<= (pstr)->cur_idx)
end_define

begin_define
define|#
directive|define
name|re_string_cur_idx
parameter_list|(
name|pstr
parameter_list|)
value|((pstr)->cur_idx)
end_define

begin_define
define|#
directive|define
name|re_string_get_buffer
parameter_list|(
name|pstr
parameter_list|)
value|((pstr)->mbs)
end_define

begin_define
define|#
directive|define
name|re_string_length
parameter_list|(
name|pstr
parameter_list|)
value|((pstr)->len)
end_define

begin_define
define|#
directive|define
name|re_string_byte_at
parameter_list|(
name|pstr
parameter_list|,
name|idx
parameter_list|)
value|((pstr)->mbs[idx])
end_define

begin_define
define|#
directive|define
name|re_string_skip_bytes
parameter_list|(
name|pstr
parameter_list|,
name|idx
parameter_list|)
value|((pstr)->cur_idx += (idx))
end_define

begin_define
define|#
directive|define
name|re_string_set_index
parameter_list|(
name|pstr
parameter_list|,
name|idx
parameter_list|)
value|((pstr)->cur_idx = (idx))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__FreeBSD__
end_ifndef

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBC
end_ifndef

begin_if
if|#
directive|if
name|HAVE_ALLOCA
end_if

begin_comment
comment|/* The OS usually guarantees only one guard page at the bottom of the stack,    and a page size can be as small as 4096 bytes.  So we cannot safely    allocate anything larger than 4096 bytes.  Also care for the possibility    of a few compiler-allocated temporary stack slots.  */
end_comment

begin_define
define|#
directive|define
name|__libc_use_alloca
parameter_list|(
name|n
parameter_list|)
value|((n)< 4032)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* alloca is implemented with malloc, so just use malloc.  */
end_comment

begin_define
define|#
directive|define
name|__libc_use_alloca
parameter_list|(
name|n
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|re_malloc
parameter_list|(
name|t
parameter_list|,
name|n
parameter_list|)
value|((t *) malloc ((n) * sizeof (t)))
end_define

begin_define
define|#
directive|define
name|re_realloc
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|,
name|n
parameter_list|)
value|((t *) realloc (p, (n) * sizeof (t)))
end_define

begin_define
define|#
directive|define
name|re_free
parameter_list|(
name|p
parameter_list|)
value|free (p)
end_define

begin_struct
struct|struct
name|bin_tree_t
block|{
name|struct
name|bin_tree_t
modifier|*
name|parent
decl_stmt|;
name|struct
name|bin_tree_t
modifier|*
name|left
decl_stmt|;
name|struct
name|bin_tree_t
modifier|*
name|right
decl_stmt|;
name|struct
name|bin_tree_t
modifier|*
name|first
decl_stmt|;
name|struct
name|bin_tree_t
modifier|*
name|next
decl_stmt|;
name|re_token_t
name|token
decl_stmt|;
comment|/* `node_idx' is the index in dfa->nodes, if `type' == 0.      Otherwise `type' indicate the type of this node.  */
name|int
name|node_idx
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bin_tree_t
name|bin_tree_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BIN_TREE_STORAGE_SIZE
define|\
value|((1024 - sizeof (void *)) / sizeof (bin_tree_t))
end_define

begin_struct
struct|struct
name|bin_tree_storage_t
block|{
name|struct
name|bin_tree_storage_t
modifier|*
name|next
decl_stmt|;
name|bin_tree_t
name|data
index|[
name|BIN_TREE_STORAGE_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bin_tree_storage_t
name|bin_tree_storage_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CONTEXT_WORD
value|1
end_define

begin_define
define|#
directive|define
name|CONTEXT_NEWLINE
value|(CONTEXT_WORD<< 1)
end_define

begin_define
define|#
directive|define
name|CONTEXT_BEGBUF
value|(CONTEXT_NEWLINE<< 1)
end_define

begin_define
define|#
directive|define
name|CONTEXT_ENDBUF
value|(CONTEXT_BEGBUF<< 1)
end_define

begin_define
define|#
directive|define
name|IS_WORD_CONTEXT
parameter_list|(
name|c
parameter_list|)
value|((c)& CONTEXT_WORD)
end_define

begin_define
define|#
directive|define
name|IS_NEWLINE_CONTEXT
parameter_list|(
name|c
parameter_list|)
value|((c)& CONTEXT_NEWLINE)
end_define

begin_define
define|#
directive|define
name|IS_BEGBUF_CONTEXT
parameter_list|(
name|c
parameter_list|)
value|((c)& CONTEXT_BEGBUF)
end_define

begin_define
define|#
directive|define
name|IS_ENDBUF_CONTEXT
parameter_list|(
name|c
parameter_list|)
value|((c)& CONTEXT_ENDBUF)
end_define

begin_define
define|#
directive|define
name|IS_ORDINARY_CONTEXT
parameter_list|(
name|c
parameter_list|)
value|((c) == 0)
end_define

begin_define
define|#
directive|define
name|IS_WORD_CHAR
parameter_list|(
name|ch
parameter_list|)
value|(isalnum (ch) || (ch) == '_')
end_define

begin_define
define|#
directive|define
name|IS_NEWLINE
parameter_list|(
name|ch
parameter_list|)
value|((ch) == NEWLINE_CHAR)
end_define

begin_define
define|#
directive|define
name|IS_WIDE_WORD_CHAR
parameter_list|(
name|ch
parameter_list|)
value|(iswalnum (ch) || (ch) == L'_')
end_define

begin_define
define|#
directive|define
name|IS_WIDE_NEWLINE
parameter_list|(
name|ch
parameter_list|)
value|((ch) == WIDE_NEWLINE_CHAR)
end_define

begin_define
define|#
directive|define
name|NOT_SATISFY_PREV_CONSTRAINT
parameter_list|(
name|constraint
parameter_list|,
name|context
parameter_list|)
define|\
value|((((constraint)& PREV_WORD_CONSTRAINT)&& !IS_WORD_CONTEXT (context)) \   || ((constraint& PREV_NOTWORD_CONSTRAINT)&& IS_WORD_CONTEXT (context)) \   || ((constraint& PREV_NEWLINE_CONSTRAINT)&& !IS_NEWLINE_CONTEXT (context))\   || ((constraint& PREV_BEGBUF_CONSTRAINT)&& !IS_BEGBUF_CONTEXT (context)))
end_define

begin_define
define|#
directive|define
name|NOT_SATISFY_NEXT_CONSTRAINT
parameter_list|(
name|constraint
parameter_list|,
name|context
parameter_list|)
define|\
value|((((constraint)& NEXT_WORD_CONSTRAINT)&& !IS_WORD_CONTEXT (context)) \   || (((constraint)& NEXT_NOTWORD_CONSTRAINT)&& IS_WORD_CONTEXT (context)) \   || (((constraint)& NEXT_NEWLINE_CONSTRAINT)&& !IS_NEWLINE_CONTEXT (context)) \   || (((constraint)& NEXT_ENDBUF_CONSTRAINT)&& !IS_ENDBUF_CONTEXT (context)))
end_define

begin_struct
struct|struct
name|re_dfastate_t
block|{
name|unsigned
name|int
name|hash
decl_stmt|;
name|re_node_set
name|nodes
decl_stmt|;
name|re_node_set
name|non_eps_nodes
decl_stmt|;
name|re_node_set
name|inveclosure
decl_stmt|;
name|re_node_set
modifier|*
name|entrance_nodes
decl_stmt|;
name|struct
name|re_dfastate_t
modifier|*
modifier|*
name|trtable
decl_stmt|,
modifier|*
modifier|*
name|word_trtable
decl_stmt|;
name|unsigned
name|int
name|context
range|:
literal|4
decl_stmt|;
name|unsigned
name|int
name|halt
range|:
literal|1
decl_stmt|;
comment|/* If this state can accept `multi byte'.      Note that we refer to multibyte characters, and multi character      collating elements as `multi byte'.  */
name|unsigned
name|int
name|accept_mb
range|:
literal|1
decl_stmt|;
comment|/* If this state has backreference node(s).  */
name|unsigned
name|int
name|has_backref
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|has_constraint
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|re_dfastate_t
name|re_dfastate_t
typedef|;
end_typedef

begin_struct
struct|struct
name|re_state_table_entry
block|{
name|int
name|num
decl_stmt|;
name|int
name|alloc
decl_stmt|;
name|re_dfastate_t
modifier|*
modifier|*
name|array
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Array type used in re_sub_match_last_t and re_sub_match_top_t.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|next_idx
decl_stmt|;
name|int
name|alloc
decl_stmt|;
name|re_dfastate_t
modifier|*
modifier|*
name|array
decl_stmt|;
block|}
name|state_array_t
typedef|;
end_typedef

begin_comment
comment|/* Store information about the node NODE whose type is OP_CLOSE_SUBEXP.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|node
decl_stmt|;
name|int
name|str_idx
decl_stmt|;
comment|/* The position NODE match at.  */
name|state_array_t
name|path
decl_stmt|;
block|}
name|re_sub_match_last_t
typedef|;
end_typedef

begin_comment
comment|/* Store information about the node NODE whose type is OP_OPEN_SUBEXP.    And information about the node, whose type is OP_CLOSE_SUBEXP,    corresponding to NODE is stored in LASTS.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|str_idx
decl_stmt|;
name|int
name|node
decl_stmt|;
name|state_array_t
modifier|*
name|path
decl_stmt|;
name|int
name|alasts
decl_stmt|;
comment|/* Allocation size of LASTS.  */
name|int
name|nlasts
decl_stmt|;
comment|/* The number of LASTS.  */
name|re_sub_match_last_t
modifier|*
modifier|*
name|lasts
decl_stmt|;
block|}
name|re_sub_match_top_t
typedef|;
end_typedef

begin_struct
struct|struct
name|re_backref_cache_entry
block|{
name|int
name|node
decl_stmt|;
name|int
name|str_idx
decl_stmt|;
name|int
name|subexp_from
decl_stmt|;
name|int
name|subexp_to
decl_stmt|;
name|char
name|more
decl_stmt|;
name|char
name|unused
decl_stmt|;
name|unsigned
name|short
name|int
name|eps_reachable_subexps_map
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* The string object corresponding to the input string.  */
name|re_string_t
name|input
decl_stmt|;
if|#
directive|if
name|defined
name|_LIBC
operator|||
operator|(
name|defined
name|__STDC_VERSION__
operator|&&
name|__STDC_VERSION__
operator|>=
literal|199901L
operator|)
specifier|const
name|re_dfa_t
modifier|*
specifier|const
name|dfa
decl_stmt|;
else|#
directive|else
specifier|const
name|re_dfa_t
modifier|*
name|dfa
decl_stmt|;
endif|#
directive|endif
comment|/* EFLAGS of the argument of regexec.  */
name|int
name|eflags
decl_stmt|;
comment|/* Where the matching ends.  */
name|int
name|match_last
decl_stmt|;
name|int
name|last_node
decl_stmt|;
comment|/* The state log used by the matcher.  */
name|re_dfastate_t
modifier|*
modifier|*
name|state_log
decl_stmt|;
name|int
name|state_log_top
decl_stmt|;
comment|/* Back reference cache.  */
name|int
name|nbkref_ents
decl_stmt|;
name|int
name|abkref_ents
decl_stmt|;
name|struct
name|re_backref_cache_entry
modifier|*
name|bkref_ents
decl_stmt|;
name|int
name|max_mb_elem_len
decl_stmt|;
name|int
name|nsub_tops
decl_stmt|;
name|int
name|asub_tops
decl_stmt|;
name|re_sub_match_top_t
modifier|*
modifier|*
name|sub_tops
decl_stmt|;
block|}
name|re_match_context_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|re_dfastate_t
modifier|*
modifier|*
name|sifted_states
decl_stmt|;
name|re_dfastate_t
modifier|*
modifier|*
name|limited_states
decl_stmt|;
name|int
name|last_node
decl_stmt|;
name|int
name|last_str_idx
decl_stmt|;
name|re_node_set
name|limits
decl_stmt|;
block|}
name|re_sift_context_t
typedef|;
end_typedef

begin_struct
struct|struct
name|re_fail_stack_ent_t
block|{
name|int
name|idx
decl_stmt|;
name|int
name|node
decl_stmt|;
name|regmatch_t
modifier|*
name|regs
decl_stmt|;
name|re_node_set
name|eps_via_nodes
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|re_fail_stack_t
block|{
name|int
name|num
decl_stmt|;
name|int
name|alloc
decl_stmt|;
name|struct
name|re_fail_stack_ent_t
modifier|*
name|stack
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|re_dfa_t
block|{
name|re_token_t
modifier|*
name|nodes
decl_stmt|;
name|size_t
name|nodes_alloc
decl_stmt|;
name|size_t
name|nodes_len
decl_stmt|;
name|int
modifier|*
name|nexts
decl_stmt|;
name|int
modifier|*
name|org_indices
decl_stmt|;
name|re_node_set
modifier|*
name|edests
decl_stmt|;
name|re_node_set
modifier|*
name|eclosures
decl_stmt|;
name|re_node_set
modifier|*
name|inveclosures
decl_stmt|;
name|struct
name|re_state_table_entry
modifier|*
name|state_table
decl_stmt|;
name|re_dfastate_t
modifier|*
name|init_state
decl_stmt|;
name|re_dfastate_t
modifier|*
name|init_state_word
decl_stmt|;
name|re_dfastate_t
modifier|*
name|init_state_nl
decl_stmt|;
name|re_dfastate_t
modifier|*
name|init_state_begbuf
decl_stmt|;
name|bin_tree_t
modifier|*
name|str_tree
decl_stmt|;
name|bin_tree_storage_t
modifier|*
name|str_tree_storage
decl_stmt|;
name|re_bitset_ptr_t
name|sb_char
decl_stmt|;
name|int
name|str_tree_storage_idx
decl_stmt|;
comment|/* number of subexpressions `re_nsub' is in regex_t.  */
name|unsigned
name|int
name|state_hash_mask
decl_stmt|;
name|int
name|init_node
decl_stmt|;
name|int
name|nbackref
decl_stmt|;
comment|/* The number of backreference in this dfa.  */
comment|/* Bitmap expressing which backreference is used.  */
name|bitset_word_t
name|used_bkref_map
decl_stmt|;
name|bitset_word_t
name|completed_bkref_map
decl_stmt|;
name|unsigned
name|int
name|has_plural_match
range|:
literal|1
decl_stmt|;
comment|/* If this dfa has "multibyte node", which is a backreference or      a node which can accept multibyte character or multi character      collating element.  */
name|unsigned
name|int
name|has_mb_node
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|is_utf8
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|map_notascii
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|word_ops_used
range|:
literal|1
decl_stmt|;
name|int
name|mb_cur_max
decl_stmt|;
name|bitset_t
name|word_char
decl_stmt|;
name|reg_syntax_t
name|syntax
decl_stmt|;
name|int
modifier|*
name|subexp_map
decl_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|char
modifier|*
name|re_str
decl_stmt|;
endif|#
directive|endif
name|__libc_lock_define
argument_list|(
argument_list|,
argument|lock
argument_list|)
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|re_node_set_init_empty
parameter_list|(
name|set
parameter_list|)
value|memset (set, '\0', sizeof (re_node_set))
end_define

begin_define
define|#
directive|define
name|re_node_set_remove
parameter_list|(
name|set
parameter_list|,
name|id
parameter_list|)
define|\
value|(re_node_set_remove_at (set, re_node_set_contains (set, id) - 1))
end_define

begin_define
define|#
directive|define
name|re_node_set_empty
parameter_list|(
name|p
parameter_list|)
value|((p)->nelem = 0)
end_define

begin_define
define|#
directive|define
name|re_node_set_free
parameter_list|(
name|set
parameter_list|)
value|re_free ((set)->elems)
end_define

begin_escape
end_escape

begin_typedef
typedef|typedef
enum|enum
block|{
name|SB_CHAR
block|,
name|MB_CHAR
block|,
name|EQUIV_CLASS
block|,
name|COLL_SYM
block|,
name|CHAR_CLASS
block|}
name|bracket_elem_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|bracket_elem_type
name|type
decl_stmt|;
union|union
block|{
name|unsigned
name|char
name|ch
decl_stmt|;
name|unsigned
name|char
modifier|*
name|name
decl_stmt|;
name|wchar_t
name|wch
decl_stmt|;
block|}
name|opr
union|;
block|}
name|bracket_elem_t
typedef|;
end_typedef

begin_comment
comment|/* Inline functions for bitset operation.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|bitset_not
parameter_list|(
name|bitset_t
name|set
parameter_list|)
block|{
name|int
name|bitset_i
decl_stmt|;
for|for
control|(
name|bitset_i
operator|=
literal|0
init|;
name|bitset_i
operator|<
name|BITSET_WORDS
condition|;
operator|++
name|bitset_i
control|)
name|set
index|[
name|bitset_i
index|]
operator|=
operator|~
name|set
index|[
name|bitset_i
index|]
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|bitset_merge
parameter_list|(
name|bitset_t
name|dest
parameter_list|,
specifier|const
name|bitset_t
name|src
parameter_list|)
block|{
name|int
name|bitset_i
decl_stmt|;
for|for
control|(
name|bitset_i
operator|=
literal|0
init|;
name|bitset_i
operator|<
name|BITSET_WORDS
condition|;
operator|++
name|bitset_i
control|)
name|dest
index|[
name|bitset_i
index|]
operator||=
name|src
index|[
name|bitset_i
index|]
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|bitset_mask
parameter_list|(
name|bitset_t
name|dest
parameter_list|,
specifier|const
name|bitset_t
name|src
parameter_list|)
block|{
name|int
name|bitset_i
decl_stmt|;
for|for
control|(
name|bitset_i
operator|=
literal|0
init|;
name|bitset_i
operator|<
name|BITSET_WORDS
condition|;
operator|++
name|bitset_i
control|)
name|dest
index|[
name|bitset_i
index|]
operator|&=
name|src
index|[
name|bitset_i
index|]
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|RE_ENABLE_I18N
end_ifdef

begin_comment
comment|/* Inline functions for re_string.  */
end_comment

begin_decl_stmt
specifier|static
specifier|inline
name|int
name|internal_function
name|__attribute
argument_list|(
operator|(
name|pure
operator|)
argument_list|)
name|re_string_char_size_at
argument_list|(
specifier|const
name|re_string_t
operator|*
name|pstr
argument_list|,
name|int
name|idx
argument_list|)
block|{
name|int
name|byte_idx
decl_stmt|;
if|if
condition|(
name|pstr
operator|->
name|mb_cur_max
operator|==
literal|1
condition|)
return|return
literal|1
return|;
for|for
control|(
name|byte_idx
operator|=
literal|1
init|;
name|idx
operator|+
name|byte_idx
operator|<
name|pstr
operator|->
name|valid_len
condition|;
operator|++
name|byte_idx
control|)
if|if
condition|(
name|pstr
operator|->
name|wcs
index|[
name|idx
operator|+
name|byte_idx
index|]
operator|!=
name|WEOF
condition|)
break|break;
return|return
name|byte_idx
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|inline
name|wint_t
name|internal_function
name|__attribute
argument_list|(
operator|(
name|pure
operator|)
argument_list|)
name|re_string_wchar_at
argument_list|(
specifier|const
name|re_string_t
operator|*
name|pstr
argument_list|,
name|int
name|idx
argument_list|)
block|{
if|if
condition|(
name|pstr
operator|->
name|mb_cur_max
operator|==
literal|1
condition|)
return|return
operator|(
name|wint_t
operator|)
name|pstr
operator|->
name|mbs
index|[
name|idx
index|]
return|;
return|return
operator|(
name|wint_t
operator|)
name|pstr
operator|->
name|wcs
index|[
name|idx
index|]
return|;
block|}
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NOT_IN_libc
end_ifndef

begin_decl_stmt
specifier|static
name|int
name|internal_function
name|__attribute
argument_list|(
operator|(
name|pure
operator|)
argument_list|)
name|re_string_elem_size_at
argument_list|(
specifier|const
name|re_string_t
operator|*
name|pstr
argument_list|,
name|int
name|idx
argument_list|)
block|{
ifdef|#
directive|ifdef
name|_LIBC
specifier|const
name|unsigned
name|char
modifier|*
name|p
decl_stmt|,
modifier|*
name|extra
decl_stmt|;
specifier|const
name|int32_t
modifier|*
name|table
decl_stmt|,
modifier|*
name|indirect
decl_stmt|;
include|#
directive|include
file|<locale/weight.h>
name|uint_fast32_t
name|nrules
init|=
name|_NL_CURRENT_WORD
argument_list|(
name|LC_COLLATE
argument_list|,
name|_NL_COLLATE_NRULES
argument_list|)
decl_stmt|;
if|if
condition|(
name|nrules
operator|!=
literal|0
condition|)
block|{
name|table
operator|=
operator|(
specifier|const
name|int32_t
operator|*
operator|)
name|_NL_CURRENT
argument_list|(
name|LC_COLLATE
argument_list|,
name|_NL_COLLATE_TABLEMB
argument_list|)
expr_stmt|;
name|extra
operator|=
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|_NL_CURRENT
argument_list|(
name|LC_COLLATE
argument_list|,
name|_NL_COLLATE_EXTRAMB
argument_list|)
expr_stmt|;
name|indirect
operator|=
operator|(
specifier|const
name|int32_t
operator|*
operator|)
name|_NL_CURRENT
argument_list|(
name|LC_COLLATE
argument_list|,
name|_NL_COLLATE_INDIRECTMB
argument_list|)
expr_stmt|;
name|p
operator|=
name|pstr
operator|->
name|mbs
operator|+
name|idx
expr_stmt|;
name|findidx
argument_list|(
operator|&
name|p
argument_list|,
name|pstr
operator|->
name|len
operator|-
name|idx
argument_list|)
expr_stmt|;
return|return
name|p
operator|-
name|pstr
operator|->
name|mbs
operator|-
name|idx
return|;
block|}
else|else
endif|#
directive|endif
comment|/* _LIBC */
return|return
literal|1
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RE_ENABLE_I18N */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  _REGEX_INTERNAL_H */
end_comment

end_unit

