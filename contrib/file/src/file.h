begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) Ian F. Darwin 1986-1995.  * Software written by Ian F. Darwin and others;  * maintained 1995-present by Christos Zoulas and others.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * file.h - definitions for file(1) program  * @(#)$File: file.h,v 1.152 2014/06/03 19:01:34 christos Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__file_h__
end_ifndef

begin_define
define|#
directive|define
name|__file_h__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN64
end_ifdef

begin_define
define|#
directive|define
name|SIZE_T_FORMAT
value|"I64"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIZE_T_FORMAT
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|INT64_T_FORMAT
value|"I64"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIZE_T_FORMAT
value|"z"
end_define

begin_define
define|#
directive|define
name|INT64_T_FORMAT
value|"ll"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* Include that here, to make sure __P gets defined */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_comment
comment|/* For open and flags */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDINT_H
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC_LIMIT_MACROS
end_ifndef

begin_define
define|#
directive|define
name|__STDC_LIMIT_MACROS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_INTTYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* Do this here and now, because struct stat gets re-defined on solaris */
end_comment

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_define
define|#
directive|define
name|ENABLE_CONDITIONALS
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MAGIC
end_ifndef

begin_define
define|#
directive|define
name|MAGIC
value|"/etc/magic"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__EMX__
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN32
argument_list|)
end_if

begin_define
define|#
directive|define
name|PATHSEP
value|';'
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PATHSEP
value|':'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|private
value|static
end_define

begin_if
if|#
directive|if
name|HAVE_VISIBILITY
operator|&&
operator|!
name|defined
argument_list|(
name|WIN32
argument_list|)
end_if

begin_define
define|#
directive|define
name|public
value|__attribute__ ((__visibility__("default")))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|protected
end_ifndef

begin_define
define|#
directive|define
name|protected
value|__attribute__ ((__visibility__("hidden")))
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
name|public
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|protected
end_ifndef

begin_define
define|#
directive|define
name|protected
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
name|__arraycount
end_ifndef

begin_define
define|#
directive|define
name|__arraycount
parameter_list|(
name|a
parameter_list|)
value|(sizeof(a) / sizeof(a[0]))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC_PREREQ__
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|__GNUC_PREREQ__
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|((__GNUC__ == (x)&& __GNUC_MINOR__>= (y)) ||			\ 	 (__GNUC__> (x)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__GNUC_PREREQ__
parameter_list|(
name|x
parameter_list|,
name|y
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

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__attribute__
end_ifndef

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|a
parameter_list|)
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
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)< (b)) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAX
end_ifndef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)> (b)) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HOWMANY
end_ifndef

begin_define
define|#
directive|define
name|HOWMANY
value|(256 * 1024)
end_define

begin_comment
comment|/* how much of the file to look at */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAXMAGIS
value|8192
end_define

begin_comment
comment|/* max entries in any one magic file 				   or directory */
end_comment

begin_define
define|#
directive|define
name|MAXDESC
value|64
end_define

begin_comment
comment|/* max len of text description/MIME type */
end_comment

begin_define
define|#
directive|define
name|MAXMIME
value|80
end_define

begin_comment
comment|/* max len of text MIME type */
end_comment

begin_define
define|#
directive|define
name|MAXstring
value|64
end_define

begin_comment
comment|/* max len of "string" types */
end_comment

begin_define
define|#
directive|define
name|MAGICNO
value|0xF11E041C
end_define

begin_define
define|#
directive|define
name|VERSIONNO
value|12
end_define

begin_define
define|#
directive|define
name|FILE_MAGICSIZE
value|248
end_define

begin_define
define|#
directive|define
name|FILE_LOAD
value|0
end_define

begin_define
define|#
directive|define
name|FILE_CHECK
value|1
end_define

begin_define
define|#
directive|define
name|FILE_COMPILE
value|2
end_define

begin_define
define|#
directive|define
name|FILE_LIST
value|3
end_define

begin_union
union|union
name|VALUETYPE
block|{
name|uint8_t
name|b
decl_stmt|;
name|uint16_t
name|h
decl_stmt|;
name|uint32_t
name|l
decl_stmt|;
name|uint64_t
name|q
decl_stmt|;
name|uint8_t
name|hs
index|[
literal|2
index|]
decl_stmt|;
comment|/* 2 bytes of a fixed-endian "short" */
name|uint8_t
name|hl
index|[
literal|4
index|]
decl_stmt|;
comment|/* 4 bytes of a fixed-endian "long" */
name|uint8_t
name|hq
index|[
literal|8
index|]
decl_stmt|;
comment|/* 8 bytes of a fixed-endian "quad" */
name|char
name|s
index|[
name|MAXstring
index|]
decl_stmt|;
comment|/* the search string or regex pattern */
name|unsigned
name|char
name|us
index|[
name|MAXstring
index|]
decl_stmt|;
name|float
name|f
decl_stmt|;
name|double
name|d
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|magic
block|{
comment|/* Word 1 */
name|uint16_t
name|cont_level
decl_stmt|;
comment|/* level of ">" */
name|uint8_t
name|flag
decl_stmt|;
define|#
directive|define
name|INDIR
value|0x01
comment|/* if '(...)' appears */
define|#
directive|define
name|OFFADD
value|0x02
comment|/* if '>&' or '>...(&' appears */
define|#
directive|define
name|INDIROFFADD
value|0x04
comment|/* if '>&(' appears */
define|#
directive|define
name|UNSIGNED
value|0x08
comment|/* comparison is unsigned */
define|#
directive|define
name|NOSPACE
value|0x10
comment|/* suppress space character before output */
define|#
directive|define
name|BINTEST
value|0x20
comment|/* test is for a binary type (set only 				   for top-level tests) */
define|#
directive|define
name|TEXTTEST
value|0x40
comment|/* for passing to file_softmagic */
name|uint8_t
name|factor
decl_stmt|;
comment|/* Word 2 */
name|uint8_t
name|reln
decl_stmt|;
comment|/* relation (0=eq, '>'=gt, etc) */
name|uint8_t
name|vallen
decl_stmt|;
comment|/* length of string value, if any */
name|uint8_t
name|type
decl_stmt|;
comment|/* comparison type (FILE_*) */
name|uint8_t
name|in_type
decl_stmt|;
comment|/* type of indirection */
define|#
directive|define
name|FILE_INVALID
value|0
define|#
directive|define
name|FILE_BYTE
value|1
define|#
directive|define
name|FILE_SHORT
value|2
define|#
directive|define
name|FILE_DEFAULT
value|3
define|#
directive|define
name|FILE_LONG
value|4
define|#
directive|define
name|FILE_STRING
value|5
define|#
directive|define
name|FILE_DATE
value|6
define|#
directive|define
name|FILE_BESHORT
value|7
define|#
directive|define
name|FILE_BELONG
value|8
define|#
directive|define
name|FILE_BEDATE
value|9
define|#
directive|define
name|FILE_LESHORT
value|10
define|#
directive|define
name|FILE_LELONG
value|11
define|#
directive|define
name|FILE_LEDATE
value|12
define|#
directive|define
name|FILE_PSTRING
value|13
define|#
directive|define
name|FILE_LDATE
value|14
define|#
directive|define
name|FILE_BELDATE
value|15
define|#
directive|define
name|FILE_LELDATE
value|16
define|#
directive|define
name|FILE_REGEX
value|17
define|#
directive|define
name|FILE_BESTRING16
value|18
define|#
directive|define
name|FILE_LESTRING16
value|19
define|#
directive|define
name|FILE_SEARCH
value|20
define|#
directive|define
name|FILE_MEDATE
value|21
define|#
directive|define
name|FILE_MELDATE
value|22
define|#
directive|define
name|FILE_MELONG
value|23
define|#
directive|define
name|FILE_QUAD
value|24
define|#
directive|define
name|FILE_LEQUAD
value|25
define|#
directive|define
name|FILE_BEQUAD
value|26
define|#
directive|define
name|FILE_QDATE
value|27
define|#
directive|define
name|FILE_LEQDATE
value|28
define|#
directive|define
name|FILE_BEQDATE
value|29
define|#
directive|define
name|FILE_QLDATE
value|30
define|#
directive|define
name|FILE_LEQLDATE
value|31
define|#
directive|define
name|FILE_BEQLDATE
value|32
define|#
directive|define
name|FILE_FLOAT
value|33
define|#
directive|define
name|FILE_BEFLOAT
value|34
define|#
directive|define
name|FILE_LEFLOAT
value|35
define|#
directive|define
name|FILE_DOUBLE
value|36
define|#
directive|define
name|FILE_BEDOUBLE
value|37
define|#
directive|define
name|FILE_LEDOUBLE
value|38
define|#
directive|define
name|FILE_BEID3
value|39
define|#
directive|define
name|FILE_LEID3
value|40
define|#
directive|define
name|FILE_INDIRECT
value|41
define|#
directive|define
name|FILE_QWDATE
value|42
define|#
directive|define
name|FILE_LEQWDATE
value|43
define|#
directive|define
name|FILE_BEQWDATE
value|44
define|#
directive|define
name|FILE_NAME
value|45
define|#
directive|define
name|FILE_USE
value|46
define|#
directive|define
name|FILE_CLEAR
value|47
define|#
directive|define
name|FILE_NAMES_SIZE
value|48
comment|/* size of array to contain all names */
define|#
directive|define
name|IS_STRING
parameter_list|(
name|t
parameter_list|)
define|\
value|((t) == FILE_STRING || \ 	 (t) == FILE_PSTRING || \ 	 (t) == FILE_BESTRING16 || \ 	 (t) == FILE_LESTRING16 || \ 	 (t) == FILE_REGEX || \ 	 (t) == FILE_SEARCH || \ 	 (t) == FILE_NAME || \ 	 (t) == FILE_USE)
define|#
directive|define
name|FILE_FMT_NONE
value|0
define|#
directive|define
name|FILE_FMT_NUM
value|1
comment|/* "cduxXi" */
define|#
directive|define
name|FILE_FMT_STR
value|2
comment|/* "s" */
define|#
directive|define
name|FILE_FMT_QUAD
value|3
comment|/* "ll" */
define|#
directive|define
name|FILE_FMT_FLOAT
value|4
comment|/* "eEfFgG" */
define|#
directive|define
name|FILE_FMT_DOUBLE
value|5
comment|/* "eEfFgG" */
comment|/* Word 3 */
name|uint8_t
name|in_op
decl_stmt|;
comment|/* operator for indirection */
name|uint8_t
name|mask_op
decl_stmt|;
comment|/* operator for mask */
ifdef|#
directive|ifdef
name|ENABLE_CONDITIONALS
name|uint8_t
name|cond
decl_stmt|;
comment|/* conditional type */
else|#
directive|else
name|uint8_t
name|dummy
decl_stmt|;
endif|#
directive|endif
name|uint8_t
name|factor_op
decl_stmt|;
define|#
directive|define
name|FILE_FACTOR_OP_PLUS
value|'+'
define|#
directive|define
name|FILE_FACTOR_OP_MINUS
value|'-'
define|#
directive|define
name|FILE_FACTOR_OP_TIMES
value|'*'
define|#
directive|define
name|FILE_FACTOR_OP_DIV
value|'/'
define|#
directive|define
name|FILE_FACTOR_OP_NONE
value|'\0'
define|#
directive|define
name|FILE_OPS
value|"&|^+-*/%"
define|#
directive|define
name|FILE_OPAND
value|0
define|#
directive|define
name|FILE_OPOR
value|1
define|#
directive|define
name|FILE_OPXOR
value|2
define|#
directive|define
name|FILE_OPADD
value|3
define|#
directive|define
name|FILE_OPMINUS
value|4
define|#
directive|define
name|FILE_OPMULTIPLY
value|5
define|#
directive|define
name|FILE_OPDIVIDE
value|6
define|#
directive|define
name|FILE_OPMODULO
value|7
define|#
directive|define
name|FILE_OPS_MASK
value|0x07
comment|/* mask for above ops */
define|#
directive|define
name|FILE_UNUSED_1
value|0x08
define|#
directive|define
name|FILE_UNUSED_2
value|0x10
define|#
directive|define
name|FILE_UNUSED_3
value|0x20
define|#
directive|define
name|FILE_OPINVERSE
value|0x40
define|#
directive|define
name|FILE_OPINDIRECT
value|0x80
ifdef|#
directive|ifdef
name|ENABLE_CONDITIONALS
define|#
directive|define
name|COND_NONE
value|0
define|#
directive|define
name|COND_IF
value|1
define|#
directive|define
name|COND_ELIF
value|2
define|#
directive|define
name|COND_ELSE
value|3
endif|#
directive|endif
comment|/* ENABLE_CONDITIONALS */
comment|/* Word 4 */
name|uint32_t
name|offset
decl_stmt|;
comment|/* offset to magic number */
comment|/* Word 5 */
name|int32_t
name|in_offset
decl_stmt|;
comment|/* offset from indirection */
comment|/* Word 6 */
name|uint32_t
name|lineno
decl_stmt|;
comment|/* line number in magic file */
comment|/* Word 7,8 */
union|union
block|{
name|uint64_t
name|_mask
decl_stmt|;
comment|/* for use with numeric and date types */
struct|struct
block|{
name|uint32_t
name|_count
decl_stmt|;
comment|/* repeat/line count */
name|uint32_t
name|_flags
decl_stmt|;
comment|/* modifier flags */
block|}
name|_s
struct|;
comment|/* for use with string types */
block|}
name|_u
union|;
define|#
directive|define
name|num_mask
value|_u._mask
define|#
directive|define
name|str_range
value|_u._s._count
define|#
directive|define
name|str_flags
value|_u._s._flags
comment|/* Words 9-16 */
name|union
name|VALUETYPE
name|value
decl_stmt|;
comment|/* either number or string */
comment|/* Words 17-32 */
name|char
name|desc
index|[
name|MAXDESC
index|]
decl_stmt|;
comment|/* description */
comment|/* Words 33-52 */
name|char
name|mimetype
index|[
name|MAXMIME
index|]
decl_stmt|;
comment|/* MIME type */
comment|/* Words 53-54 */
name|char
name|apple
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIT
parameter_list|(
name|A
parameter_list|)
value|(1<< (A))
end_define

begin_define
define|#
directive|define
name|STRING_COMPACT_WHITESPACE
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|STRING_COMPACT_OPTIONAL_WHITESPACE
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|STRING_IGNORE_LOWERCASE
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|STRING_IGNORE_UPPERCASE
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|REGEX_OFFSET_START
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|STRING_TEXTTEST
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|STRING_BINTEST
value|BIT(6)
end_define

begin_define
define|#
directive|define
name|PSTRING_1_BE
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|PSTRING_1_LE
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|PSTRING_2_BE
value|BIT(8)
end_define

begin_define
define|#
directive|define
name|PSTRING_2_LE
value|BIT(9)
end_define

begin_define
define|#
directive|define
name|PSTRING_4_BE
value|BIT(10)
end_define

begin_define
define|#
directive|define
name|PSTRING_4_LE
value|BIT(11)
end_define

begin_define
define|#
directive|define
name|REGEX_LINE_COUNT
value|BIT(11)
end_define

begin_define
define|#
directive|define
name|PSTRING_LEN
define|\
value|(PSTRING_1_BE|PSTRING_2_LE|PSTRING_2_BE|PSTRING_4_LE|PSTRING_4_BE)
end_define

begin_define
define|#
directive|define
name|PSTRING_LENGTH_INCLUDES_ITSELF
value|BIT(12)
end_define

begin_define
define|#
directive|define
name|STRING_TRIM
value|BIT(13)
end_define

begin_define
define|#
directive|define
name|CHAR_COMPACT_WHITESPACE
value|'W'
end_define

begin_define
define|#
directive|define
name|CHAR_COMPACT_OPTIONAL_WHITESPACE
value|'w'
end_define

begin_define
define|#
directive|define
name|CHAR_IGNORE_LOWERCASE
value|'c'
end_define

begin_define
define|#
directive|define
name|CHAR_IGNORE_UPPERCASE
value|'C'
end_define

begin_define
define|#
directive|define
name|CHAR_REGEX_OFFSET_START
value|'s'
end_define

begin_define
define|#
directive|define
name|CHAR_TEXTTEST
value|'t'
end_define

begin_define
define|#
directive|define
name|CHAR_TRIM
value|'T'
end_define

begin_define
define|#
directive|define
name|CHAR_BINTEST
value|'b'
end_define

begin_define
define|#
directive|define
name|CHAR_PSTRING_1_BE
value|'B'
end_define

begin_define
define|#
directive|define
name|CHAR_PSTRING_1_LE
value|'B'
end_define

begin_define
define|#
directive|define
name|CHAR_PSTRING_2_BE
value|'H'
end_define

begin_define
define|#
directive|define
name|CHAR_PSTRING_2_LE
value|'h'
end_define

begin_define
define|#
directive|define
name|CHAR_PSTRING_4_BE
value|'L'
end_define

begin_define
define|#
directive|define
name|CHAR_PSTRING_4_LE
value|'l'
end_define

begin_define
define|#
directive|define
name|CHAR_PSTRING_LENGTH_INCLUDES_ITSELF
value|'J'
end_define

begin_define
define|#
directive|define
name|STRING_IGNORE_CASE
value|(STRING_IGNORE_LOWERCASE|STRING_IGNORE_UPPERCASE)
end_define

begin_define
define|#
directive|define
name|STRING_DEFAULT_RANGE
value|100
end_define

begin_comment
comment|/* list of magic entries */
end_comment

begin_struct
struct|struct
name|mlist
block|{
name|struct
name|magic
modifier|*
name|magic
decl_stmt|;
comment|/* array of magic entries */
name|uint32_t
name|nmagic
decl_stmt|;
comment|/* number of entries in array */
name|void
modifier|*
name|map
decl_stmt|;
comment|/* internal resources used by entry */
name|struct
name|mlist
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|CAST
parameter_list|(
name|T
parameter_list|,
name|b
parameter_list|)
value|static_cast<T>(b)
end_define

begin_define
define|#
directive|define
name|RCAST
parameter_list|(
name|T
parameter_list|,
name|b
parameter_list|)
value|reinterpret_cast<T>(b)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CAST
parameter_list|(
name|T
parameter_list|,
name|b
parameter_list|)
value|(T)(b)
end_define

begin_define
define|#
directive|define
name|RCAST
parameter_list|(
name|T
parameter_list|,
name|b
parameter_list|)
value|(T)(b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|level_info
block|{
name|int32_t
name|off
decl_stmt|;
name|int
name|got_match
decl_stmt|;
ifdef|#
directive|ifdef
name|ENABLE_CONDITIONALS
name|int
name|last_match
decl_stmt|;
name|int
name|last_cond
decl_stmt|;
comment|/* used for error checking by parse() */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAGIC_SETS
value|2
end_define

begin_struct
struct|struct
name|magic_set
block|{
name|struct
name|mlist
modifier|*
name|mlist
index|[
name|MAGIC_SETS
index|]
decl_stmt|;
comment|/* list of regular entries */
struct|struct
name|cont
block|{
name|size_t
name|len
decl_stmt|;
name|struct
name|level_info
modifier|*
name|li
decl_stmt|;
block|}
name|c
struct|;
struct|struct
name|out
block|{
name|char
modifier|*
name|buf
decl_stmt|;
comment|/* Accumulation buffer */
name|char
modifier|*
name|pbuf
decl_stmt|;
comment|/* Printable buffer */
block|}
name|o
struct|;
name|uint32_t
name|offset
decl_stmt|;
name|int
name|error
decl_stmt|;
name|int
name|flags
decl_stmt|;
comment|/* Control magic tests. */
name|int
name|event_flags
decl_stmt|;
comment|/* Note things that happened. */
define|#
directive|define
name|EVENT_HAD_ERR
value|0x01
specifier|const
name|char
modifier|*
name|file
decl_stmt|;
name|size_t
name|line
decl_stmt|;
comment|/* current magic line number */
comment|/* data for searches */
struct|struct
block|{
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
comment|/* start of search in original source */
name|size_t
name|s_len
decl_stmt|;
comment|/* length of search region */
name|size_t
name|offset
decl_stmt|;
comment|/* starting offset in source: XXX - should this be off_t? */
name|size_t
name|rm_len
decl_stmt|;
comment|/* match length */
block|}
name|search
struct|;
comment|/* FIXME: Make the string dynamically allocated so that e.g. 	   strings matched in files can be longer than MAXstring */
name|union
name|VALUETYPE
name|ms_value
decl_stmt|;
comment|/* either number or string */
block|}
struct|;
end_struct

begin_comment
comment|/* Type for Unicode characters */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|unichar
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|stat
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|FILE_T_LOCAL
value|1
end_define

begin_define
define|#
directive|define
name|FILE_T_WINDOWS
value|2
end_define

begin_function_decl
name|protected
specifier|const
name|char
modifier|*
name|file_fmttime
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|struct
name|magic_set
modifier|*
name|file_ms_alloc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|file_ms_free
parameter_list|(
name|struct
name|magic_set
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|file_buffer
parameter_list|(
name|struct
name|magic_set
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|file_fsmagic
parameter_list|(
name|struct
name|magic_set
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|stat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|file_pipe2file
parameter_list|(
name|struct
name|magic_set
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|file_vprintf
parameter_list|(
name|struct
name|magic_set
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|2
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|protected
name|size_t
name|file_printedlen
parameter_list|(
specifier|const
name|struct
name|magic_set
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|file_replace
parameter_list|(
name|struct
name|magic_set
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|file_printf
parameter_list|(
name|struct
name|magic_set
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|protected
name|int
name|file_reset
parameter_list|(
name|struct
name|magic_set
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|file_tryelf
parameter_list|(
name|struct
name|magic_set
modifier|*
parameter_list|,
name|int
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
name|protected
name|int
name|file_trycdf
parameter_list|(
name|struct
name|magic_set
modifier|*
parameter_list|,
name|int
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

begin_if
if|#
directive|if
name|HAVE_FORK
end_if

begin_function_decl
name|protected
name|int
name|file_zmagic
parameter_list|(
name|struct
name|magic_set
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
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

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|protected
name|int
name|file_ascmagic
parameter_list|(
name|struct
name|magic_set
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
name|protected
name|int
name|file_ascmagic_with_encoding
parameter_list|(
name|struct
name|magic_set
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|unichar
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
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
name|protected
name|int
name|file_encoding
parameter_list|(
name|struct
name|magic_set
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|unichar
modifier|*
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|file_is_tar
parameter_list|(
name|struct
name|magic_set
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
name|protected
name|int
name|file_softmagic
parameter_list|(
name|struct
name|magic_set
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|file_apprentice
parameter_list|(
name|struct
name|magic_set
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
name|protected
name|int
name|file_magicfind
parameter_list|(
name|struct
name|magic_set
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|mlist
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|uint64_t
name|file_signextend
parameter_list|(
name|struct
name|magic_set
modifier|*
parameter_list|,
name|struct
name|magic
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|file_badread
parameter_list|(
name|struct
name|magic_set
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|file_badseek
parameter_list|(
name|struct
name|magic_set
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|file_oomem
parameter_list|(
name|struct
name|magic_set
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|file_error
parameter_list|(
name|struct
name|magic_set
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|protected
name|void
name|file_magerror
parameter_list|(
name|struct
name|magic_set
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|protected
name|void
name|file_magwarn
parameter_list|(
name|struct
name|magic_set
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|protected
name|void
name|file_mdump
parameter_list|(
name|struct
name|magic
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|file_showstr
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|size_t
name|file_mbswidth
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
specifier|const
name|char
modifier|*
name|file_getbuffer
parameter_list|(
name|struct
name|magic_set
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|ssize_t
name|sread
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|file_check_mem
parameter_list|(
name|struct
name|magic_set
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|file_looks_utf8
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|unichar
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|size_t
name|file_pstring_length_size
parameter_list|(
specifier|const
name|struct
name|magic
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|size_t
name|file_pstring_get_length
parameter_list|(
specifier|const
name|struct
name|magic
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__EMX__
end_ifdef

begin_function_decl
name|protected
name|int
name|file_os2_apptype
parameter_list|(
name|struct
name|magic_set
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __EMX__ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|char
modifier|*
name|pat
decl_stmt|;
name|char
modifier|*
name|old_lc_ctype
decl_stmt|;
name|int
name|rc
decl_stmt|;
name|regex_t
name|rx
decl_stmt|;
block|}
name|file_regex_t
typedef|;
end_typedef

begin_function_decl
name|protected
name|int
name|file_regcomp
parameter_list|(
name|file_regex_t
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
name|protected
name|int
name|file_regexec
parameter_list|(
name|file_regex_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|regmatch_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|file_regfree
parameter_list|(
name|file_regex_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|file_regerror
parameter_list|(
name|file_regex_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|magic_set
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|COMPILE_ONLY
end_ifndef

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|file_names
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|size_t
name|file_nnames
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRERROR
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|strerror
parameter_list|(
name|e
parameter_list|)
define|\
value|(((e)>= 0&& (e)< sys_nerr) ? sys_errlist[(e)] : "Unknown error")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRTOUL
end_ifndef

begin_define
define|#
directive|define
name|strtoul
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|strtol(a, b, c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_PREAD
end_ifndef

begin_function_decl
name|ssize_t
name|pread
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_VASPRINTF
end_ifndef

begin_function_decl
name|int
name|vasprintf
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_ASPRINTF
end_ifndef

begin_function_decl
name|int
name|asprintf
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRLCPY
end_ifndef

begin_function_decl
name|size_t
name|strlcpy
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRLCAT
end_ifndef

begin_function_decl
name|size_t
name|strlcat
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRCASESTR
end_ifndef

begin_function_decl
name|char
modifier|*
name|strcasestr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETLINE
end_ifndef

begin_function_decl
name|ssize_t
name|getline
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|getdelim
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_CTIME_R
end_ifndef

begin_function_decl
name|char
modifier|*
name|ctime_r
parameter_list|(
specifier|const
name|time_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_ASCTIME_R
end_ifndef

begin_function_decl
name|char
modifier|*
name|asctime_r
parameter_list|(
specifier|const
name|struct
name|tm
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_FMTCHECK
end_ifndef

begin_function_decl
specifier|const
name|char
modifier|*
name|fmtcheck
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format_arg__
parameter_list|(
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_MMAP
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SYS_MMAN_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QUICK
argument_list|)
end_if

begin_define
define|#
directive|define
name|QUICK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_BINARY
end_ifndef

begin_define
define|#
directive|define
name|O_BINARY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|>=
literal|3
operator|)
end_if

begin_define
define|#
directive|define
name|FILE_RCSID
parameter_list|(
name|id
parameter_list|)
define|\
value|static const char rcsid[] __attribute__((__used__)) = id;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FILE_RCSID
parameter_list|(
name|id
parameter_list|)
define|\
value|static const char *rcsid(const char *p) { \ 	return rcsid(p = id); \ }
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
name|FILE_RCSID
parameter_list|(
name|id
parameter_list|)
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
comment|/* __file_h__ */
end_comment

end_unit

