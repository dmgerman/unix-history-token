begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * file.h - definitions for file(1) program  * @(#)$Id: file.h,v 1.43 2002/07/03 18:57:52 christos Exp $  *  * Copyright (c) Ian F. Darwin, 1987.  * Written by Ian F. Darwin.  *  * This software is not subject to any license of the American Telephone  * and Telegraph Company or of the Regents of the University of California.  *  * Permission is granted to anyone to use this software for any purpose on  * any computer system, and to alter it and redistribute it freely, subject  * to the following restrictions:  *  * 1. The author is not responsible for the consequences of use of this  *    software, no matter how awful, even if they arise from flaws in it.  *  * 2. The origin of this software must not be misrepresented, either by  *    explicit claim or by omission.  Since few users ever read sources,  *    credits must appear in the documentation.  *  * 3. Altered versions must be plainly marked as such, and must not be  *    misrepresented as being the original software.  Since few users  *    ever read sources, credits must appear in the documentation.  *  * 4. This notice may not be removed or altered.  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|__linux__
end_ifndef

begin_define
define|#
directive|define
name|_LARGEFILE_SOURCE
end_define

begin_define
define|#
directive|define
name|_LARGEFILE64_SOURCE
end_define

begin_define
define|#
directive|define
name|_FILE_OFFSET_BITS
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

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
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
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
value|50
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
value|1
end_define

begin_define
define|#
directive|define
name|CHECK
value|1
end_define

begin_define
define|#
directive|define
name|COMPILE
value|2
end_define

begin_struct
struct|struct
name|magic
block|{
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
name|BYTE
value|1
define|#
directive|define
name|SHORT
value|2
define|#
directive|define
name|LONG
value|4
define|#
directive|define
name|STRING
value|5
define|#
directive|define
name|DATE
value|6
define|#
directive|define
name|BESHORT
value|7
define|#
directive|define
name|BELONG
value|8
define|#
directive|define
name|BEDATE
value|9
define|#
directive|define
name|LESHORT
value|10
define|#
directive|define
name|LELONG
value|11
define|#
directive|define
name|LEDATE
value|12
define|#
directive|define
name|PSTRING
value|13
define|#
directive|define
name|LDATE
value|14
define|#
directive|define
name|BELDATE
value|15
define|#
directive|define
name|LELDATE
value|16
define|#
directive|define
name|REGEX
value|17
name|uint8_t
name|in_op
decl_stmt|;
comment|/* operator for indirection */
name|uint8_t
name|mask_op
decl_stmt|;
comment|/* operator for mask */
define|#
directive|define
name|OPAND
value|1
define|#
directive|define
name|OPOR
value|2
define|#
directive|define
name|OPXOR
value|3
define|#
directive|define
name|OPADD
value|4
define|#
directive|define
name|OPMINUS
value|5
define|#
directive|define
name|OPMULTIPLY
value|6
define|#
directive|define
name|OPDIVIDE
value|7
define|#
directive|define
name|OPMODULO
value|8
define|#
directive|define
name|OPINVERSE
value|0x80
name|int32_t
name|offset
decl_stmt|;
comment|/* offset to magic number */
name|int32_t
name|in_offset
decl_stmt|;
comment|/* offset from indirection */
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
name|uint32_t
name|mask
decl_stmt|;
comment|/* mask before comparison with value */
name|char
name|desc
index|[
name|MAXDESC
index|]
decl_stmt|;
comment|/* description */
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
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

begin_function_decl
specifier|extern
name|int
name|apprentice
parameter_list|(
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
name|int
name|ascmagic
parameter_list|(
name|unsigned
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
name|error
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ckfputs
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|stat
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|fsmagic
parameter_list|(
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
specifier|extern
name|char
modifier|*
name|fmttime
parameter_list|(
name|long
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|is_compress
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|is_tar
parameter_list|(
name|unsigned
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
name|magwarn
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mdump
parameter_list|(
name|struct
name|magic
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|process
parameter_list|(
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
name|showstr
parameter_list|(
name|FILE
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
name|int
name|softmagic
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tryit
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|char
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
name|int
name|zmagic
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
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
name|ckfprintf
parameter_list|(
name|FILE
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
specifier|extern
name|uint32_t
name|signextend
parameter_list|(
name|struct
name|magic
modifier|*
parameter_list|,
name|unsigned
name|int32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tryelf
parameter_list|(
name|int
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pipe2file
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the program name 			*/
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|magicfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of the magic file		*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lineno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current line number in magic file	*/
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mlist
name|mlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of arrays of magic entries	*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* enable debugging?			*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|zflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* process compressed files?		*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* follow symbolic links?		*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* read/analyze block special files?	*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|iflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output types as mime-types		*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_GETOPT
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|optind
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From getopt(3)			*/
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|optarg
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __file_h__ */
end_comment

end_unit

