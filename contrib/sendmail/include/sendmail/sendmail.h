begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998-2000 Sendmail, Inc. and its suppliers.  *	All rights reserved.  * Copyright (c) 1983, 1995-1997 Eric P. Allman.  All rights reserved.  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *  *	$Id: sendmail.h,v 8.34.4.8 2001/06/01 05:06:51 gshapiro Exp $  */
end_comment

begin_comment
comment|/* **  SENDMAIL.H -- Global definitions for sendmail. */
end_comment

begin_if
if|#
directive|if
name|SFIO
end_if

begin_include
include|#
directive|include
file|<sfio/stdio.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SFIO */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SFIO */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"conf.h"
end_include

begin_include
include|#
directive|include
file|"sendmail/errstring.h"
end_include

begin_include
include|#
directive|include
file|"sendmail/useful.h"
end_include

begin_comment
comment|/********************************************************************** **  Table sizes, etc.... **	There shouldn't be much need to change these.... **********************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXMAILERS
end_ifndef

begin_define
define|#
directive|define
name|MAXMAILERS
value|25
end_define

begin_comment
comment|/* maximum mailers known to system */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! MAXMAILERS */
end_comment

begin_comment
comment|/* **  Data structure for bit maps. ** **	Each bit in this map can be referenced by an ascii character. **	This is 256 possible bits, or 32 8-bit bytes. */
end_comment

begin_define
define|#
directive|define
name|BITMAPBITS
value|256
end_define

begin_comment
comment|/* number of bits in a bit map */
end_comment

begin_define
define|#
directive|define
name|BYTEBITS
value|8
end_define

begin_comment
comment|/* number of bits in a byte */
end_comment

begin_define
define|#
directive|define
name|BITMAPBYTES
value|(BITMAPBITS / BYTEBITS)
end_define

begin_comment
comment|/* number of bytes in bit map */
end_comment

begin_comment
comment|/* internal macros */
end_comment

begin_define
define|#
directive|define
name|_BITWORD
parameter_list|(
name|bit
parameter_list|)
value|((bit) / (BYTEBITS * sizeof (int)))
end_define

begin_define
define|#
directive|define
name|_BITBIT
parameter_list|(
name|bit
parameter_list|)
value|((unsigned int)1<< ((bit) % (BYTEBITS * sizeof (int))))
end_define

begin_typedef
typedef|typedef
name|unsigned
name|int
name|BITMAP256
index|[
name|BITMAPBYTES
operator|/
sizeof|sizeof
argument_list|(
name|int
argument_list|)
index|]
typedef|;
end_typedef

begin_comment
comment|/* properly case and truncate bit */
end_comment

begin_define
define|#
directive|define
name|bitidx
parameter_list|(
name|bit
parameter_list|)
value|((unsigned int) (bit)& 0xff)
end_define

begin_comment
comment|/* test bit number N */
end_comment

begin_define
define|#
directive|define
name|bitnset
parameter_list|(
name|bit
parameter_list|,
name|map
parameter_list|)
value|((map)[_BITWORD(bit)]& _BITBIT(bit))
end_define

begin_comment
comment|/* set bit number N */
end_comment

begin_define
define|#
directive|define
name|setbitn
parameter_list|(
name|bit
parameter_list|,
name|map
parameter_list|)
value|(map)[_BITWORD(bit)] |= _BITBIT(bit)
end_define

begin_comment
comment|/* clear bit number N */
end_comment

begin_define
define|#
directive|define
name|clrbitn
parameter_list|(
name|bit
parameter_list|,
name|map
parameter_list|)
value|(map)[_BITWORD(bit)]&= ~_BITBIT(bit)
end_define

begin_comment
comment|/* clear an entire bit map */
end_comment

begin_define
define|#
directive|define
name|clrbitmap
parameter_list|(
name|map
parameter_list|)
value|memset((char *) map, '\0', BITMAPBYTES)
end_define

begin_comment
comment|/* **  Utility macros */
end_comment

begin_comment
comment|/* return number of bytes left in a buffer */
end_comment

begin_define
define|#
directive|define
name|SPACELEFT
parameter_list|(
name|buf
parameter_list|,
name|ptr
parameter_list|)
value|(sizeof buf - ((ptr) - buf))
end_define

begin_comment
comment|/* **  Flags passed to safefile/safedirpath. */
end_comment

begin_define
define|#
directive|define
name|SFF_ANYFILE
value|0L
end_define

begin_comment
comment|/* no special restrictions */
end_comment

begin_define
define|#
directive|define
name|SFF_MUSTOWN
value|0x00000001L
end_define

begin_comment
comment|/* user must own this file */
end_comment

begin_define
define|#
directive|define
name|SFF_NOSLINK
value|0x00000002L
end_define

begin_comment
comment|/* file cannot be a symbolic link */
end_comment

begin_define
define|#
directive|define
name|SFF_ROOTOK
value|0x00000004L
end_define

begin_comment
comment|/* ok for root to own this file */
end_comment

begin_define
define|#
directive|define
name|SFF_RUNASREALUID
value|0x00000008L
end_define

begin_comment
comment|/* if no ctladdr, run as real uid */
end_comment

begin_define
define|#
directive|define
name|SFF_NOPATHCHECK
value|0x00000010L
end_define

begin_comment
comment|/* don't bother checking dir path */
end_comment

begin_define
define|#
directive|define
name|SFF_SETUIDOK
value|0x00000020L
end_define

begin_comment
comment|/* setuid files are ok */
end_comment

begin_define
define|#
directive|define
name|SFF_CREAT
value|0x00000040L
end_define

begin_comment
comment|/* ok to create file if necessary */
end_comment

begin_define
define|#
directive|define
name|SFF_REGONLY
value|0x00000080L
end_define

begin_comment
comment|/* regular files only */
end_comment

begin_define
define|#
directive|define
name|SFF_SAFEDIRPATH
value|0x00000100L
end_define

begin_comment
comment|/* no writable directories allowed */
end_comment

begin_define
define|#
directive|define
name|SFF_NOHLINK
value|0x00000200L
end_define

begin_comment
comment|/* file cannot have hard links */
end_comment

begin_define
define|#
directive|define
name|SFF_NOWLINK
value|0x00000400L
end_define

begin_comment
comment|/* links only in non-writable dirs */
end_comment

begin_define
define|#
directive|define
name|SFF_NOGWFILES
value|0x00000800L
end_define

begin_comment
comment|/* disallow world writable files */
end_comment

begin_define
define|#
directive|define
name|SFF_NOWWFILES
value|0x00001000L
end_define

begin_comment
comment|/* disallow group writable files */
end_comment

begin_define
define|#
directive|define
name|SFF_OPENASROOT
value|0x00002000L
end_define

begin_comment
comment|/* open as root instead of real user */
end_comment

begin_define
define|#
directive|define
name|SFF_NOLOCK
value|0x00004000L
end_define

begin_comment
comment|/* don't lock the file */
end_comment

begin_define
define|#
directive|define
name|SFF_NOGRFILES
value|0x00008000L
end_define

begin_comment
comment|/* disallow g readable files */
end_comment

begin_define
define|#
directive|define
name|SFF_NOWRFILES
value|0x00010000L
end_define

begin_comment
comment|/* disallow o readable files */
end_comment

begin_define
define|#
directive|define
name|SFF_NOTEXCL
value|0x00020000L
end_define

begin_comment
comment|/* creates don't need to be exclusive */
end_comment

begin_define
define|#
directive|define
name|SFF_EXECOK
value|0x00040000L
end_define

begin_comment
comment|/* executable files are ok (E_SM_ISEXEC) */
end_comment

begin_define
define|#
directive|define
name|SFF_NORFILES
value|(SFF_NOGRFILES|SFF_NOWRFILES)
end_define

begin_comment
comment|/* pseudo-flags */
end_comment

begin_define
define|#
directive|define
name|SFF_NOLINK
value|(SFF_NOHLINK|SFF_NOSLINK)
end_define

begin_comment
comment|/* functions */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|safefile
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|UID_T
operator|,
name|GID_T
operator|,
name|char
operator|*
operator|,
name|long
operator|,
name|int
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
name|safedirpath
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|UID_T
operator|,
name|GID_T
operator|,
name|char
operator|*
operator|,
name|long
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
name|safeopen
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dfopen
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|filechanged
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
expr|struct
name|stat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **  DontBlameSendmail options ** **	Hopefully nobody uses these. */
end_comment

begin_define
define|#
directive|define
name|DBS_SAFE
value|0
end_define

begin_define
define|#
directive|define
name|DBS_ASSUMESAFECHOWN
value|1
end_define

begin_define
define|#
directive|define
name|DBS_GROUPWRITABLEDIRPATHSAFE
value|2
end_define

begin_define
define|#
directive|define
name|DBS_GROUPWRITABLEFORWARDFILESAFE
value|3
end_define

begin_define
define|#
directive|define
name|DBS_GROUPWRITABLEINCLUDEFILESAFE
value|4
end_define

begin_define
define|#
directive|define
name|DBS_GROUPWRITABLEALIASFILE
value|5
end_define

begin_define
define|#
directive|define
name|DBS_WORLDWRITABLEALIASFILE
value|6
end_define

begin_define
define|#
directive|define
name|DBS_FORWARDFILEINUNSAFEDIRPATH
value|7
end_define

begin_define
define|#
directive|define
name|DBS_MAPINUNSAFEDIRPATH
value|8
end_define

begin_define
define|#
directive|define
name|DBS_LINKEDALIASFILEINWRITABLEDIR
value|9
end_define

begin_define
define|#
directive|define
name|DBS_LINKEDCLASSFILEINWRITABLEDIR
value|10
end_define

begin_define
define|#
directive|define
name|DBS_LINKEDFORWARDFILEINWRITABLEDIR
value|11
end_define

begin_define
define|#
directive|define
name|DBS_LINKEDINCLUDEFILEINWRITABLEDIR
value|12
end_define

begin_define
define|#
directive|define
name|DBS_LINKEDMAPINWRITABLEDIR
value|13
end_define

begin_define
define|#
directive|define
name|DBS_LINKEDSERVICESWITCHFILEINWRITABLEDIR
value|14
end_define

begin_define
define|#
directive|define
name|DBS_FILEDELIVERYTOHARDLINK
value|15
end_define

begin_define
define|#
directive|define
name|DBS_FILEDELIVERYTOSYMLINK
value|16
end_define

begin_define
define|#
directive|define
name|DBS_WRITEMAPTOHARDLINK
value|17
end_define

begin_define
define|#
directive|define
name|DBS_WRITEMAPTOSYMLINK
value|18
end_define

begin_define
define|#
directive|define
name|DBS_WRITESTATSTOHARDLINK
value|19
end_define

begin_define
define|#
directive|define
name|DBS_WRITESTATSTOSYMLINK
value|20
end_define

begin_define
define|#
directive|define
name|DBS_FORWARDFILEINGROUPWRITABLEDIRPATH
value|21
end_define

begin_define
define|#
directive|define
name|DBS_INCLUDEFILEINGROUPWRITABLEDIRPATH
value|22
end_define

begin_define
define|#
directive|define
name|DBS_CLASSFILEINUNSAFEDIRPATH
value|23
end_define

begin_define
define|#
directive|define
name|DBS_ERRORHEADERINUNSAFEDIRPATH
value|24
end_define

begin_define
define|#
directive|define
name|DBS_HELPFILEINUNSAFEDIRPATH
value|25
end_define

begin_define
define|#
directive|define
name|DBS_FORWARDFILEINUNSAFEDIRPATHSAFE
value|26
end_define

begin_define
define|#
directive|define
name|DBS_INCLUDEFILEINUNSAFEDIRPATHSAFE
value|27
end_define

begin_define
define|#
directive|define
name|DBS_RUNPROGRAMINUNSAFEDIRPATH
value|28
end_define

begin_comment
comment|/* Not used yet */
end_comment

begin_define
define|#
directive|define
name|DBS_RUNWRITABLEPROGRAM
value|29
end_define

begin_define
define|#
directive|define
name|DBS_INCLUDEFILEINUNSAFEDIRPATH
value|30
end_define

begin_define
define|#
directive|define
name|DBS_NONROOTSAFEADDR
value|31
end_define

begin_define
define|#
directive|define
name|DBS_TRUSTSTICKYBIT
value|32
end_define

begin_define
define|#
directive|define
name|DBS_DONTWARNFORWARDFILEINUNSAFEDIRPATH
value|33
end_define

begin_define
define|#
directive|define
name|DBS_INSUFFICIENTENTROPY
value|34
end_define

begin_if
if|#
directive|if
name|_FFR_UNSAFE_SASL
end_if

begin_define
define|#
directive|define
name|DBS_GROUPREADABLESASLFILE
value|35
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FFR_UNSAFE_SASL */
end_comment

begin_if
if|#
directive|if
name|_FFR_UNSAFE_WRITABLE_INCLUDE
end_if

begin_define
define|#
directive|define
name|DBS_GROUPWRITABLEFORWARDFILE
value|36
end_define

begin_define
define|#
directive|define
name|DBS_GROUPWRITABLEINCLUDEFILE
value|37
end_define

begin_define
define|#
directive|define
name|DBS_WORLDWRITABLEFORWARDFILE
value|38
end_define

begin_define
define|#
directive|define
name|DBS_WORLDWRITABLEINCLUDEFILE
value|39
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FFR_UNSAFE_WRITABLE_INCLUDE */
end_comment

begin_comment
comment|/* struct defining such things */
end_comment

begin_struct
struct|struct
name|dbsval
block|{
name|char
modifier|*
name|dbs_name
decl_stmt|;
comment|/* name of DontBlameSendmail flag */
name|u_char
name|dbs_flag
decl_stmt|;
comment|/* numeric level */
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|_FFR_DPRINTF
end_if

begin_decl_stmt
specifier|extern
name|void
name|dprintf
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
name|int
name|dflush
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _FFR_DPRINTF */
end_comment

begin_define
define|#
directive|define
name|dprintf
value|printf
end_define

begin_define
define|#
directive|define
name|dflush
parameter_list|()
value|fflush(stdout)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FFR_DPRINTF */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sm_snprintf
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|size_t
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
name|int
name|sm_vsnprintf
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|size_t
operator|,
specifier|const
name|char
operator|*
operator|,
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|quad_to_string
name|__P
argument_list|(
operator|(
name|QUAD_T
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|strlcpy
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|strlcat
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

