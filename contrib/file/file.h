begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * file.h - definitions for file(1) program  * @(#)$Id: file.h,v 1.37 2001/07/22 21:04:15 christos Exp $  *  * Copyright (c) Ian F. Darwin, 1987.  * Written by Ian F. Darwin.  *  * This software is not subject to any license of the American Telephone  * and Telegraph Company or of the Regents of the University of California.  *  * Permission is granted to anyone to use this software for any purpose on  * any computer system, and to alter it and redistribute it freely, subject  * to the following restrictions:  *  * 1. The author is not responsible for the consequences of use of this  *    software, no matter how awful, even if they arise from flaws in it.  *  * 2. The origin of this software must not be misrepresented, either by  *    explicit claim or by omission.  Since few users ever read sources,  *    credits must appear in the documentation.  *  * 3. Altered versions must be plainly marked as such, and must not be  *    misrepresented as being the original software.  Since few users  *    ever read sources, credits must appear in the documentation.  *  * 4. This notice may not be removed or altered.  */
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

begin_typedef
typedef|typedef
name|int
name|int32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|int16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|uint16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|int8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uint8
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|HOWMANY
end_ifndef

begin_define
define|#
directive|define
name|HOWMANY
value|16384
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
value|1000
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
name|uint16
name|cont_level
decl_stmt|;
comment|/* level of ">" */
name|uint8
name|nospflag
decl_stmt|;
comment|/* supress space character */
name|uint8
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
name|uint8
name|reln
decl_stmt|;
comment|/* relation (0=eq, '>'=gt, etc) */
name|uint8
name|vallen
decl_stmt|;
comment|/* length of string value, if any */
name|uint8
name|type
decl_stmt|;
comment|/* int, short, long or string. */
name|uint8
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
name|uint8
name|in_op
decl_stmt|;
comment|/* operator for indirection */
name|uint8
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
name|int32
name|offset
decl_stmt|;
comment|/* offset to magic number */
name|int32
name|in_offset
decl_stmt|;
comment|/* offset from indirection */
union|union
name|VALUETYPE
block|{
name|unsigned
name|char
name|b
decl_stmt|;
name|unsigned
name|short
name|h
decl_stmt|;
name|uint32
name|l
decl_stmt|;
name|char
name|s
index|[
name|MAXstring
index|]
decl_stmt|;
name|unsigned
name|char
name|hs
index|[
literal|2
index|]
decl_stmt|;
comment|/* 2 bytes of a fixed-endian "short" */
name|unsigned
name|char
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
name|uint32
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
name|uint32
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

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|a
parameter_list|)
value|a
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|a
parameter_list|)
value|()
end_define

begin_define
define|#
directive|define
name|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|apprentice
name|__P
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
name|int
name|ascmagic
name|__P
argument_list|(
operator|(
name|unsigned
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
name|error
name|__P
argument_list|(
operator|(
specifier|const
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
name|void
name|ckfputs
name|__P
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

begin_struct_decl
struct_decl|struct
name|stat
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|int
name|fsmagic
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
expr|struct
name|stat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fmttime
name|__P
argument_list|(
operator|(
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|is_compress
name|__P
argument_list|(
operator|(
specifier|const
name|unsigned
name|char
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
name|is_tar
name|__P
argument_list|(
operator|(
name|unsigned
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
name|magwarn
name|__P
argument_list|(
operator|(
specifier|const
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
name|void
name|mdump
name|__P
argument_list|(
operator|(
expr|struct
name|magic
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|process
name|__P
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
name|void
name|showstr
name|__P
argument_list|(
operator|(
name|FILE
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
name|int
name|softmagic
name|__P
argument_list|(
operator|(
name|unsigned
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
name|int
name|tryit
name|__P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|zmagic
name|__P
argument_list|(
operator|(
name|unsigned
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
name|ckfprintf
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
specifier|const
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
name|uint32
name|signextend
name|__P
argument_list|(
operator|(
expr|struct
name|magic
operator|*
operator|,
name|unsigned
name|int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tryelf
name|__P
argument_list|(
operator|(
name|int
operator|,
name|unsigned
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

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

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

begin_define
define|#
directive|define
name|FILE_RCSID
parameter_list|(
name|id
parameter_list|)
value|static char rcsid[] = id;
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

