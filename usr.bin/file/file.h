begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * file.h - definitions for file(1) program  * @(#)$Id: file.h,v 1.7 1997/03/18 19:37:18 mpp Exp $  *  * Copyright (c) Ian F. Darwin, 1987.  * Written by Ian F. Darwin.  *  * This software is not subject to any license of the American Telephone  * and Telegraph Company or of the Regents of the University of California.  *  * Permission is granted to anyone to use this software for any purpose on  * any computer system, and to alter it and redistribute it freely, subject  * to the following restrictions:  *  * 1. The author is not responsible for the consequences of use of this  *    software, no matter how awful, even if they arise from flaws in it.  *  * 2. The origin of this software must not be misrepresented, either by  *    explicit claim or by omission.  Since few users ever read sources,  *    credits must appear in the documentation.  *  * 3. Altered versions must be plainly marked as such, and must not be  *    misrepresented as being the original software.  Since few users  *    ever read sources, credits must appear in the documentation.  *  * 4. This notice may not be removed or altered.  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|HOWMANY
end_ifndef

begin_define
define|#
directive|define
name|HOWMANY
value|8192
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

begin_struct
struct|struct
name|magic
block|{
name|short
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
name|ADD
value|4
comment|/* if '>&' appears,  */
name|short
name|cont_level
decl_stmt|;
comment|/* level of ">" */
struct|struct
block|{
name|char
name|type
decl_stmt|;
comment|/* byte short long */
name|int32
name|offset
decl_stmt|;
comment|/* offset from indirection */
block|}
name|in
struct|;
name|int32
name|offset
decl_stmt|;
comment|/* offset to magic number */
name|unsigned
name|char
name|reln
decl_stmt|;
comment|/* relation (0=eq, '>'=gt, etc) */
name|char
name|type
decl_stmt|;
comment|/* int, short, long or string. */
name|char
name|vallen
decl_stmt|;
comment|/* length of string value, if any */
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
comment|/* 2 bytes of a fixed-endian "long" */
block|}
name|value
union|;
comment|/* either number or string */
name|uint32
name|mask
decl_stmt|;
comment|/* mask before comparison with value */
name|char
name|nospflag
decl_stmt|;
comment|/* supress space character */
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

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* Include that here, to make sure __P gets defined */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|__cplusplus
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
name|int
name|internatmagic
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
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Some unixes don't define this..	*/
end_comment

begin_decl_stmt
specifier|extern
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
name|magic
modifier|*
name|magic
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* array of magic entries		*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nmagic
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of valid magic[]s 		*/
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|||
name|defined
argument_list|(
name|__sun__
argument_list|)
operator|||
name|defined
argument_list|(
name|__sun
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__svr4
argument_list|)
operator|||
name|defined
argument_list|(
name|__SVR4
argument_list|)
operator|||
name|defined
argument_list|(
name|__svr4__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SOLARIS
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SUNOS
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|SUNOS
argument_list|)
operator|||
name|defined
argument_list|(
name|__convex__
argument_list|)
end_if

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
name|MAXPATHLEN
end_ifndef

begin_define
define|#
directive|define
name|MAXPATHLEN
value|512
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

