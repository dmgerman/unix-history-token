begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) Ian F. Darwin 1986-1995.  * Software written by Ian F. Darwin and others;  * maintained 1995-present by Christos Zoulas and others.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *    * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * file.h - definitions for file(1) program  * @(#)$Id: file.h,v 1.64 2004/11/20 23:50:12 christos Exp $  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDINT_H
end_ifdef

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

begin_comment
comment|/* Do this here and now, because struct stat gets re-defined on solaris */
end_comment

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

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

begin_ifdef
ifdef|#
directive|ifdef
name|__EMX__
end_ifdef

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

begin_define
define|#
directive|define
name|public
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HOWMANY
end_ifndef

begin_define
define|#
directive|define
name|HOWMANY
value|65536
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
value|4096
end_define

begin_comment
comment|/* max entries in /etc/magic */
end_comment

begin_define
define|#
directive|define
name|MAXDESC
value|64
end_define

begin_comment
comment|/* max leng of text description */
end_comment

begin_define
define|#
directive|define
name|MAXstring
value|32
end_define

begin_comment
comment|/* max leng of "string" types */
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
value|2
end_define

begin_define
define|#
directive|define
name|FILE_MAGICSIZE
value|(32 * 4)
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
name|nospflag
decl_stmt|;
comment|/* supress space character */
name|uint8_t
name|flag
decl_stmt|;
define|#
directive|define
name|INDIR
value|1
comment|/* if '>(...)' appears,  */
define|#
directive|define
name|UNSIGNED
value|2
comment|/* comparison is unsigned */
define|#
directive|define
name|OFFADD
value|4
comment|/* if '>&' appears,  */
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
comment|/* int, short, long or string. */
name|uint8_t
name|in_type
decl_stmt|;
comment|/* type of indirrection */
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
name|FILE_FORMAT_NAME
define|\
comment|/* 0 */
value|"invalid 0",		\
comment|/* 1 */
value|"byte",			\
comment|/* 2 */
value|"short",		\
comment|/* 3 */
value|"invalid 3",		\
comment|/* 4 */
value|"long",			\
comment|/* 5 */
value|"string",		\
comment|/* 6 */
value|"date",			\
comment|/* 7 */
value|"beshort",		\
comment|/* 8 */
value|"belong",		\
comment|/* 9 */
value|"bedate"		\
comment|/* 10 */
value|"leshort",		\
comment|/* 11 */
value|"lelong",		\
comment|/* 12 */
value|"ledate",		\
comment|/* 13 */
value|"pstring",		\
comment|/* 14 */
value|"ldate",		\
comment|/* 15 */
value|"beldate",		\
comment|/* 16 */
value|"leldate",		\
comment|/* 17 */
value|"regex",		\
comment|/* 18 */
value|"bestring16",		\
comment|/* 19 */
value|"lestring16",
define|#
directive|define
name|FILE_FMT_NUM
value|"cduxXi"
define|#
directive|define
name|FILE_FMT_STR
value|"s"
define|#
directive|define
name|FILE_FORMAT_STRING
define|\
comment|/* 0 */
value|NULL,			\
comment|/* 1 */
value|FILE_FMT_NUM,		\
comment|/* 2 */
value|FILE_FMT_NUM,		\
comment|/* 3 */
value|NULL,			\
comment|/* 4 */
value|FILE_FMT_NUM,		\
comment|/* 5 */
value|FILE_FMT_STR,		\
comment|/* 6 */
value|FILE_FMT_STR,		\
comment|/* 7 */
value|FILE_FMT_NUM,		\
comment|/* 8 */
value|FILE_FMT_NUM,		\
comment|/* 9 */
value|FILE_FMT_STR,		\
comment|/* 10 */
value|FILE_FMT_NUM,		\
comment|/* 11 */
value|FILE_FMT_NUM,		\
comment|/* 12 */
value|FILE_FMT_STR,		\
comment|/* 13 */
value|FILE_FMT_STR,		\
comment|/* 14 */
value|FILE_FMT_STR,		\
comment|/* 15 */
value|FILE_FMT_STR,		\
comment|/* 16 */
value|FILE_FMT_STR,		\
comment|/* 17 */
value|FILE_FMT_STR,		\
comment|/* 18 */
value|FILE_FMT_STR,		\
comment|/* 19 */
value|FILE_FMT_STR,
comment|/* Word 3 */
name|uint8_t
name|in_op
decl_stmt|;
comment|/* operator for indirection */
name|uint8_t
name|mask_op
decl_stmt|;
comment|/* operator for mask */
name|uint8_t
name|dummy1
decl_stmt|;
name|uint8_t
name|dummy2
decl_stmt|;
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
name|FILE_OPINVERSE
value|0x80
comment|/* Word 4 */
name|uint32_t
name|offset
decl_stmt|;
comment|/* offset to magic number */
comment|/* Word 5 */
name|uint32_t
name|in_offset
decl_stmt|;
comment|/* offset from indirection */
comment|/* Word 6 */
name|uint32_t
name|mask
decl_stmt|;
comment|/* mask before comparison with value */
comment|/* Word 7 */
name|uint32_t
name|dummy3
decl_stmt|;
comment|/* Word 8 */
name|uint32_t
name|dummp4
decl_stmt|;
comment|/* Words 9-16 */
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
name|char
name|s
index|[
name|MAXstring
index|]
decl_stmt|;
name|char
modifier|*
name|buf
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
block|}
name|value
union|;
comment|/* either number or string */
comment|/* Words 17..31 */
name|char
name|desc
index|[
name|MAXDESC
index|]
decl_stmt|;
comment|/* description */
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
name|STRING_IGNORE_LOWERCASE
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|STRING_COMPACT_BLANK
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|STRING_COMPACT_OPTIONAL_BLANK
value|BIT(2)
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
name|CHAR_COMPACT_BLANK
value|'B'
end_define

begin_define
define|#
directive|define
name|CHAR_COMPACT_OPTIONAL_BLANK
value|'b'
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
name|int
name|mapped
decl_stmt|;
comment|/* allocation type: 0 => apprentice_file 		      *                  1 => apprentice_map + malloc 		      *                  2 => apprentice_map + mmap */
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

begin_struct
struct|struct
name|magic_set
block|{
name|struct
name|mlist
modifier|*
name|mlist
decl_stmt|;
struct|struct
name|cont
block|{
name|size_t
name|len
decl_stmt|;
name|int32_t
modifier|*
name|off
decl_stmt|;
block|}
name|c
struct|;
struct|struct
name|out
block|{
comment|/* Accumulation buffer */
name|char
modifier|*
name|buf
decl_stmt|;
name|char
modifier|*
name|ptr
decl_stmt|;
name|size_t
name|len
decl_stmt|;
name|size_t
name|size
decl_stmt|;
comment|/* Printable buffer */
name|char
modifier|*
name|pbuf
decl_stmt|;
name|size_t
name|psize
decl_stmt|;
block|}
name|o
struct|;
name|int
name|error
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|int
name|haderr
decl_stmt|;
specifier|const
name|char
modifier|*
name|file
decl_stmt|;
name|size_t
name|line
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|stat
struct_decl|;
end_struct_decl

begin_function_decl
name|protected
name|char
modifier|*
name|file_fmttime
parameter_list|(
name|uint32_t
parameter_list|,
name|int
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
function_decl|;
end_function_decl

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
name|file_zmagic
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|struct
name|mlist
modifier|*
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
name|uint32_t
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
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|file_delmagic
parameter_list|(
name|struct
name|magic
modifier|*
parameter_list|,
name|int
name|type
parameter_list|,
name|size_t
name|entries
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
function_decl|;
end_function_decl

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
function_decl|;
end_function_decl

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

begin_else
else|#
directive|else
end_else

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __file_h__ */
end_comment

end_unit

