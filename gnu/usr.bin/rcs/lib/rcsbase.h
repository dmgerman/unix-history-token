begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RCS common definitions and data structures */
end_comment

begin_define
define|#
directive|define
name|RCSBASE
value|"$FreeBSD$"
end_define

begin_comment
comment|/* Copyright 1982, 1988, 1989 Walter Tichy    Copyright 1990, 1991, 1992, 1993, 1994, 1995 Paul Eggert    Distributed under license by the Free Software Foundation, Inc.  This file is part of RCS.  RCS is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  RCS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with RCS; see the file COPYING. If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  Report problems and direct all questions to:      rcs-bugs@cs.purdue.edu  */
end_comment

begin_comment
comment|/*  * Revision 5.20  1995/06/16 06:19:24  eggert  * Update FSF address.  *  * Revision 5.19  1995/06/01 16:23:43  eggert  * (SIZEABLE_PATH): Don't depend on PATH_MAX: it's not worth configuring.  * (Ioffset_type,BINARY_EXPAND,MIN_UNEXPAND,MIN_UNCHANGED_EXPAND): New macros.  * (maps_memory): New macro; replaces many instances of `has_mmap'.  * (cacheptr): Renamed from cachetell.  * (struct RILE): New alternate name for RILE; the type is now recursive.  * (deallocate): New member for RILE, used for generic buffer deallocation.  * (cacheunget_): No longer take a failure arg; just call Ierror on failure.  * (struct rcslock): Renamed from struct lock, to avoid collisions with  * system headers on some hosts.  All users changed.  * (basefilename): Renamed from basename, likewise.  * (dirtpname): Remove; no longer external.  * (dirlen, dateform): Remove; no longer used.  * (cmpdate, fopenSafer, fdSafer, readAccessFilenameBuffer): New functions.  * (zonelenmax): Increase to 9 for full ISO 8601 format.  * (catchmmapints): Depend on has_NFS.  *  * Revision 5.18  1994/03/17 14:05:48  eggert  * Add primitives for reading backwards from a RILE;  * this is needed to go back and find the $Log prefix.  * Specify subprocess input via file descriptor, not file name.  Remove lint.  *  * Revision 5.17  1993/11/09 17:40:15  eggert  * Move RCS-specific time handling into rcstime.c.  * printf_string now takes two arguments, alas.  *  * Revision 5.16  1993/11/03 17:42:27  eggert  * Don't arbitrarily limit the number of joins.  Remove `nil'.  * Add Name keyword.  Don't discard ignored phrases.  * Add support for merge -A vs -E, and allow up to three labels.  * Improve quality of diagnostics and prototypes.  *  * Revision 5.15  1992/07/28  16:12:44  eggert  * Statement macro names now end in _.  *  * Revision 5.14  1992/02/17  23:02:22  eggert  * Add -T support.  Work around NFS mmap SIGBUS problem.  *  * Revision 5.13  1992/01/24  18:44:19  eggert  * Add support for bad_creat0.  lint -> RCS_lint  *  * Revision 5.12  1992/01/06  02:42:34  eggert  * while (E) ; -> while (E) continue;  *  * Revision 5.11  1991/10/07  17:32:46  eggert  * Support piece tables even if !has_mmap.  *  * Revision 5.10  1991/09/24  00:28:39  eggert  * Remove unexported functions.  *  * Revision 5.9  1991/08/19  03:13:55  eggert  * Add piece tables and other tuneups, and NFS workarounds.  *  * Revision 5.8  1991/04/21  11:58:20  eggert  * Add -x, RCSINIT, MS-DOS support.  *  * Revision 5.7  1991/02/28  19:18:50  eggert  * Try setuid() if seteuid() doesn't work.  *  * Revision 5.6  1991/02/26  17:48:37  eggert  * Support new link behavior.  Move ANSI C / Posix declarations into conf.sh.  *  * Revision 5.5  1990/12/04  05:18:43  eggert  * Use -I for prompts and -q for diagnostics.  *  * Revision 5.4  1990/11/01  05:03:35  eggert  * Don't assume that builtins are functions; they may be macros.  * Permit arbitrary data in logs.  *  * Revision 5.3  1990/09/26  23:36:58  eggert  * Port wait() to non-Posix ANSI C hosts.  *  * Revision 5.2  1990/09/04  08:02:20  eggert  * Don't redefine NAME_MAX, PATH_MAX.  * Improve incomplete line handling.  Standardize yes-or-no procedure.  *  * Revision 5.1  1990/08/29  07:13:53  eggert  * Add -kkvl.  Fix type typos exposed by porting.  Clean old log messages too.  *  * Revision 5.0  1990/08/22  08:12:44  eggert  * Adjust ANSI C / Posix support.  Add -k, -V, setuid.  Don't call access().  * Remove compile-time limits; use malloc instead.  * Ansify and Posixate.  Add support for ISO 8859.  * Remove snoop and v2 support.  *  * Revision 4.9  89/05/01  15:17:14  narten  * botched previous USG fix  *  * Revision 4.8  89/05/01  14:53:05  narten  * changed #include<strings.h> -> string.h for USG systems.  *  * Revision 4.7  88/11/08  15:58:45  narten  * removed defs for functions loaded from libraries  *  * Revision 4.6  88/08/09  19:12:36  eggert  * Shrink stdio code size; remove lint; permit -Dhshsize=nn.  *  * Revision 4.5  87/12/18  17:06:41  narten  * made removed BSD ifdef, now uses V4_2BSD  *  * Revision 4.4  87/10/18  10:29:49  narten  * Updating version numbers  * Changes relative to 1.1 are actually relative to 4.2  *  * Revision 1.3  87/09/24  14:02:25  narten  * changes for lint  *  * Revision 1.2  87/03/27  14:22:02  jenkins  * Port to suns  *  * Revision 4.2  83/12/20  16:04:20  wft  * merged 3.6.1.1 and 4.1 (SMALLOG, logsize).  * moved setting of STRICT_LOCKING to Makefile.  * changed DOLLAR to UNKN (conflict with KDELIM).  *  * Revision 4.1  83/05/04  09:12:41  wft  * Added markers Id and RCSfile.  * Added Dbranch for default branches.  *  * Revision 3.6.1.1  83/12/02  21:56:22  wft  * Increased logsize, added macro SMALLOG.  *  * Revision 3.6  83/01/15  16:43:28  wft  * 4.2 prerelease  *  * Revision 3.6  83/01/15  16:43:28  wft  * Replaced dbm.h with BYTESIZ, fixed definition of rindex().  * Added variants of NCPFN and NCPPN for bsd 4.2, selected by defining V4_2BSD.  * Added macro DELNUMFORM to have uniform format for printing delta text nodes.  * Added macro DELETE to mark deleted deltas.  *  * Revision 3.5  82/12/10  12:16:56  wft  * Added two forms of DATEFORM, one using %02d, the other %.2d.  *  * Revision 3.4  82/12/04  20:01:25  wft  * added LOCKER, Locker, and USG (redefinition of rindex).  *  * Revision 3.3  82/12/03  12:22:04  wft  * Added dbm.h, stdio.h, RCSBASE, RCSSEP, RCSSUF, WORKMODE, TMPFILE3,  * PRINTDATE, PRINTTIME, map, and ctab; removed Suffix. Redefined keyvallength  * using NCPPN. Changed putc() to abort on write error.  *  * Revision 3.2  82/10/18  15:03:52  wft  * added macro STRICT_LOCKING, removed RCSUMASK.  * renamed JOINFILE[1,2] to JOINFIL[1,2].  *  * Revision 3.1  82/10/11  19:41:17  wft  * removed NBPW, NBPC, NCPW.  * added typdef int void to aid compiling  */
end_comment

begin_include
include|#
directive|include
file|"conf.h"
end_include

begin_define
define|#
directive|define
name|EXIT_TROUBLE
value|DIFF_TROUBLE
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_PATH_MAX
end_ifdef

begin_define
define|#
directive|define
name|SIZEABLE_PATH
value|_POSIX_PATH_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIZEABLE_PATH
value|255
end_define

begin_comment
comment|/* size of a large path; not a hard limit */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* for traditional C hosts with unusual size arguments */
end_comment

begin_define
define|#
directive|define
name|Fread
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|,
name|f
parameter_list|)
value|fread(p, (freadarg_type)(s), (freadarg_type)(n), f)
end_define

begin_define
define|#
directive|define
name|Fwrite
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|,
name|f
parameter_list|)
value|fwrite(p, (freadarg_type)(s), (freadarg_type)(n), f)
end_define

begin_comment
comment|/*  * Parameters  */
end_comment

begin_comment
comment|/* backwards compatibility with old versions of RCS */
end_comment

begin_define
define|#
directive|define
name|VERSION_min
value|3
end_define

begin_comment
comment|/* old output RCS format supported */
end_comment

begin_define
define|#
directive|define
name|VERSION_max
value|5
end_define

begin_comment
comment|/* newest output RCS format supported */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VERSION_DEFAULT
end_ifndef

begin_comment
comment|/* default RCS output format */
end_comment

begin_define
define|#
directive|define
name|VERSION_DEFAULT
value|VERSION_max
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VERSION
parameter_list|(
name|n
parameter_list|)
value|((n) - VERSION_DEFAULT)
end_define

begin_comment
comment|/* internally, 0 is the default */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STRICT_LOCKING
end_ifndef

begin_define
define|#
directive|define
name|STRICT_LOCKING
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 sets the default locking to non-strict;  */
end_comment

begin_comment
comment|/* used in experimental environments.         */
end_comment

begin_comment
comment|/* 1 sets the default locking to strict;      */
end_comment

begin_comment
comment|/* used in production environments.           */
end_comment

begin_define
define|#
directive|define
name|yearlength
value|16
end_define

begin_comment
comment|/* (good through AD 9,999,999,999,999,999)    */
end_comment

begin_define
define|#
directive|define
name|datesize
value|(yearlength+16)
end_define

begin_comment
comment|/* size of output of time2date */
end_comment

begin_define
define|#
directive|define
name|RCSTMPPREFIX
value|'_'
end_define

begin_comment
comment|/* prefix for temp files in working dir  */
end_comment

begin_define
define|#
directive|define
name|KDELIM
value|'$'
end_define

begin_comment
comment|/* delimiter for keywords                     */
end_comment

begin_define
define|#
directive|define
name|VDELIM
value|':'
end_define

begin_comment
comment|/* separates keywords from values             */
end_comment

begin_define
define|#
directive|define
name|DEFAULTSTATE
value|"Exp"
end_define

begin_comment
comment|/* default state of revisions                 */
end_comment

begin_define
define|#
directive|define
name|true
value|1
end_define

begin_define
define|#
directive|define
name|false
value|0
end_define

begin_comment
comment|/*  * RILE - readonly file  * declarecache; - declares local cache for RILE variable(s)  * setupcache - sets up the local RILE cache, but does not initialize it  * cache, uncache - caches and uncaches the local RILE;  *	(uncache,cache) is needed around functions that advance the RILE pointer  * Igeteof_(f,c,s) - get a char c from f, executing statement s at EOF  * cachegeteof_(c,s) - Igeteof_ applied to the local RILE  * Iget_(f,c) - like Igeteof_, except EOF is an error  * cacheget_(c) - Iget_ applied to the local RILE  * cacheunget_(f,c,s) - read c backwards from cached f, executing s at BOF  * Ifileno, Ioffset_type, Irewind, Itell - analogs to stdio routines  *  * By conventions, macros whose names end in _ are statements, not expressions.  * Following such macros with `; else' results in a syntax error.  */
end_comment

begin_define
define|#
directive|define
name|maps_memory
value|(has_map_fd || has_mmap)
end_define

begin_if
if|#
directive|if
name|large_memory
end_if

begin_typedef
typedef|typedef
name|unsigned
name|char
specifier|const
modifier|*
name|Iptr_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|RILE
block|{
name|Iptr_type
name|ptr
decl_stmt|,
name|lim
decl_stmt|;
name|unsigned
name|char
modifier|*
name|base
decl_stmt|;
comment|/* not Iptr_type for lint's sake */
name|unsigned
name|char
modifier|*
name|readlim
decl_stmt|;
name|int
name|fd
decl_stmt|;
if|#
directive|if
name|maps_memory
name|void
argument_list|(
argument|*deallocate
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|RILE
operator|*
operator|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|FILE
modifier|*
name|stream
decl_stmt|;
endif|#
directive|endif
block|}
name|RILE
typedef|;
end_typedef

begin_if
if|#
directive|if
name|maps_memory
end_if

begin_define
define|#
directive|define
name|declarecache
value|register Iptr_type ptr, lim
end_define

begin_define
define|#
directive|define
name|setupcache
parameter_list|(
name|f
parameter_list|)
value|(lim = (f)->lim)
end_define

begin_define
define|#
directive|define
name|Igeteof_
parameter_list|(
name|f
parameter_list|,
name|c
parameter_list|,
name|s
parameter_list|)
value|if ((f)->ptr==(f)->lim) s else (c)= *(f)->ptr++;
end_define

begin_define
define|#
directive|define
name|cachegeteof_
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|)
value|if (ptr==lim) s else (c)= *ptr++;
end_define

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|Igetmore
name|P
argument_list|(
operator|(
name|RILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|declarecache
value|register Iptr_type ptr; register RILE *rRILE
end_define

begin_define
define|#
directive|define
name|setupcache
parameter_list|(
name|f
parameter_list|)
value|(rRILE = (f))
end_define

begin_define
define|#
directive|define
name|Igeteof_
parameter_list|(
name|f
parameter_list|,
name|c
parameter_list|,
name|s
parameter_list|)
value|if ((f)->ptr==(f)->readlim&& !Igetmore(f)) s else (c)= *(f)->ptr++;
end_define

begin_define
define|#
directive|define
name|cachegeteof_
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|)
value|if (ptr==rRILE->readlim&& !Igetmore(rRILE)) s else (c)= *ptr++;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|uncache
parameter_list|(
name|f
parameter_list|)
value|((f)->ptr = ptr)
end_define

begin_define
define|#
directive|define
name|cache
parameter_list|(
name|f
parameter_list|)
value|(ptr = (f)->ptr)
end_define

begin_define
define|#
directive|define
name|Iget_
parameter_list|(
name|f
parameter_list|,
name|c
parameter_list|)
value|Igeteof_(f,c,Ieof();)
end_define

begin_define
define|#
directive|define
name|cacheget_
parameter_list|(
name|c
parameter_list|)
value|cachegeteof_(c,Ieof();)
end_define

begin_define
define|#
directive|define
name|cacheunget_
parameter_list|(
name|f
parameter_list|,
name|c
parameter_list|)
value|(c)=(--ptr)[-1];
end_define

begin_define
define|#
directive|define
name|Ioffset_type
value|size_t
end_define

begin_define
define|#
directive|define
name|Itell
parameter_list|(
name|f
parameter_list|)
value|((f)->ptr - (f)->base)
end_define

begin_define
define|#
directive|define
name|Irewind
parameter_list|(
name|f
parameter_list|)
value|((f)->ptr = (f)->base)
end_define

begin_define
define|#
directive|define
name|cacheptr
parameter_list|()
value|ptr
end_define

begin_define
define|#
directive|define
name|Ifileno
parameter_list|(
name|f
parameter_list|)
value|((f)->fd)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RILE
value|FILE
end_define

begin_define
define|#
directive|define
name|declarecache
value|register FILE *ptr
end_define

begin_define
define|#
directive|define
name|setupcache
parameter_list|(
name|f
parameter_list|)
value|(ptr = (f))
end_define

begin_define
define|#
directive|define
name|uncache
parameter_list|(
name|f
parameter_list|)
end_define

begin_define
define|#
directive|define
name|cache
parameter_list|(
name|f
parameter_list|)
end_define

begin_define
define|#
directive|define
name|Igeteof_
parameter_list|(
name|f
parameter_list|,
name|c
parameter_list|,
name|s
parameter_list|)
value|{if(((c)=getc(f))==EOF){testIerror(f);if(feof(f))s}}
end_define

begin_define
define|#
directive|define
name|cachegeteof_
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|)
value|Igeteof_(ptr,c,s)
end_define

begin_define
define|#
directive|define
name|Iget_
parameter_list|(
name|f
parameter_list|,
name|c
parameter_list|)
value|{ if (((c)=getc(f))==EOF) testIeof(f); }
end_define

begin_define
define|#
directive|define
name|cacheget_
parameter_list|(
name|c
parameter_list|)
value|Iget_(ptr,c)
end_define

begin_define
define|#
directive|define
name|cacheunget_
parameter_list|(
name|f
parameter_list|,
name|c
parameter_list|)
value|if(fseek(ptr,-2L,SEEK_CUR))Ierror();else cacheget_(c)
end_define

begin_define
define|#
directive|define
name|Ioffset_type
value|long
end_define

begin_define
define|#
directive|define
name|Itell
parameter_list|(
name|f
parameter_list|)
value|ftell(f)
end_define

begin_define
define|#
directive|define
name|Ifileno
parameter_list|(
name|f
parameter_list|)
value|fileno(f)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Print a char, but abort on write error.  */
end_comment

begin_define
define|#
directive|define
name|aputc_
parameter_list|(
name|c
parameter_list|,
name|o
parameter_list|)
value|{ if (putc(c,o)==EOF) testOerror(o); }
end_define

begin_comment
comment|/* Get a character from an RCS file, perhaps copying to a new RCS file.  */
end_comment

begin_define
define|#
directive|define
name|GETCeof_
parameter_list|(
name|o
parameter_list|,
name|c
parameter_list|,
name|s
parameter_list|)
value|{ cachegeteof_(c,s) if (o) aputc_(c,o) }
end_define

begin_define
define|#
directive|define
name|GETC_
parameter_list|(
name|o
parameter_list|,
name|c
parameter_list|)
value|{ cacheget_(c) if (o) aputc_(c,o) }
end_define

begin_define
define|#
directive|define
name|WORKMODE
parameter_list|(
name|RCSmode
parameter_list|,
name|writable
parameter_list|)
value|(((RCSmode)&(mode_t)~(S_IWUSR|S_IWGRP|S_IWOTH)) | ((writable)?S_IWUSR:0))
end_define

begin_comment
comment|/* computes mode of working file: same as RCSmode, but write permission     */
end_comment

begin_comment
comment|/* determined by writable */
end_comment

begin_comment
comment|/* character classes and token codes */
end_comment

begin_enum
enum|enum
name|tokens
block|{
comment|/* classes */
name|DELIM
block|,
name|DIGIT
block|,
name|IDCHAR
block|,
name|NEWLN
block|,
name|LETTER
block|,
name|Letter
block|,
name|PERIOD
block|,
name|SBEGIN
block|,
name|SPACE
block|,
name|UNKN
block|,
comment|/* tokens */
name|COLON
block|,
name|ID
block|,
name|NUM
block|,
name|SEMI
block|,
name|STRING
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|SDELIM
value|'@'
end_define

begin_comment
comment|/* the actual character is needed for string handling*/
end_comment

begin_comment
comment|/* SDELIM must be consistent with ctab[], so that ctab[SDELIM]==SBEGIN.  * there should be no overlap among SDELIM, KDELIM, and VDELIM  */
end_comment

begin_define
define|#
directive|define
name|isdigit
parameter_list|(
name|c
parameter_list|)
value|(((unsigned)(c)-'0')<= 9)
end_define

begin_comment
comment|/* faster than ctab[c]==DIGIT */
end_comment

begin_comment
comment|/***************************************  * Data structures for the symbol table  ***************************************/
end_comment

begin_comment
comment|/* Buffer of arbitrary data */
end_comment

begin_struct
struct|struct
name|buf
block|{
name|char
modifier|*
name|string
decl_stmt|;
name|size_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cbuf
block|{
name|char
specifier|const
modifier|*
name|string
decl_stmt|;
name|size_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Hash table entry */
end_comment

begin_struct
struct|struct
name|hshentry
block|{
name|char
specifier|const
modifier|*
name|num
decl_stmt|;
comment|/* pointer to revision number (ASCIZ) */
name|char
specifier|const
modifier|*
name|date
decl_stmt|;
comment|/* pointer to date of checkin	    */
name|char
specifier|const
modifier|*
name|author
decl_stmt|;
comment|/* login of person checking in	    */
name|char
specifier|const
modifier|*
name|lockedby
decl_stmt|;
comment|/* who locks the revision		    */
name|char
specifier|const
modifier|*
name|state
decl_stmt|;
comment|/* state of revision (Exp by default) */
name|char
specifier|const
modifier|*
name|name
decl_stmt|;
comment|/* name (if any) by which retrieved   */
name|struct
name|cbuf
name|log
decl_stmt|;
comment|/* log message requested at checkin   */
name|struct
name|branchhead
modifier|*
name|branches
decl_stmt|;
comment|/* list of first revisions on branches*/
name|struct
name|cbuf
name|ig
decl_stmt|;
comment|/* ignored phrases in admin part	    */
name|struct
name|cbuf
name|igtext
decl_stmt|;
comment|/* ignored phrases in deltatext part  */
name|struct
name|hshentry
modifier|*
name|next
decl_stmt|;
comment|/* next revision on same branch       */
name|struct
name|hshentry
modifier|*
name|nexthsh
decl_stmt|;
comment|/* next revision with same hash value */
name|long
name|insertlns
decl_stmt|;
comment|/* lines inserted (computed by rlog)  */
name|long
name|deletelns
decl_stmt|;
comment|/* lines deleted  (computed by rlog)  */
name|char
name|selector
decl_stmt|;
comment|/* true if selected, false if deleted */
block|}
struct|;
end_struct

begin_comment
comment|/* list of hash entries */
end_comment

begin_struct
struct|struct
name|hshentries
block|{
name|struct
name|hshentries
modifier|*
name|rest
decl_stmt|;
name|struct
name|hshentry
modifier|*
name|first
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* list element for branch lists */
end_comment

begin_struct
struct|struct
name|branchhead
block|{
name|struct
name|hshentry
modifier|*
name|hsh
decl_stmt|;
name|struct
name|branchhead
modifier|*
name|nextbranch
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* accesslist element */
end_comment

begin_struct
struct|struct
name|access
block|{
name|char
specifier|const
modifier|*
name|login
decl_stmt|;
name|struct
name|access
modifier|*
name|nextaccess
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* list element for locks  */
end_comment

begin_struct
struct|struct
name|rcslock
block|{
name|char
specifier|const
modifier|*
name|login
decl_stmt|;
name|struct
name|hshentry
modifier|*
name|delta
decl_stmt|;
name|struct
name|rcslock
modifier|*
name|nextlock
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* list element for symbolic names */
end_comment

begin_struct
struct|struct
name|assoc
block|{
name|char
specifier|const
modifier|*
name|symbol
decl_stmt|;
name|char
specifier|const
modifier|*
name|num
decl_stmt|;
name|struct
name|assoc
modifier|*
name|nextassoc
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|mainArgs
value|(argc,argv) int argc; char **argv;
end_define

begin_if
if|#
directive|if
name|RCS_lint
end_if

begin_define
define|#
directive|define
name|libId
parameter_list|(
name|name
parameter_list|,
name|rcsid
parameter_list|)
end_define

begin_define
define|#
directive|define
name|mainProg
parameter_list|(
name|name
parameter_list|,
name|cmd
parameter_list|,
name|rcsid
parameter_list|)
value|int name mainArgs
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|libId
parameter_list|(
name|name
parameter_list|,
name|rcsid
parameter_list|)
value|char const name[] = rcsid;
end_define

begin_define
define|#
directive|define
name|mainProg
parameter_list|(
name|n
parameter_list|,
name|c
parameter_list|,
name|i
parameter_list|)
value|char const Copyright[] = "Copyright 1982,1988,1989 Walter F. Tichy, Purdue CS\nCopyright 1990,1991,1992,1993,1994,1995 Paul Eggert", baseid[] = RCSBASE, cmdid[] = c; libId(n,i) int main P((int,char**)); int main mainArgs
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Markers for keyword expansion (used in co and ident)  *	Every byte must have class LETTER or Letter.  */
end_comment

begin_define
define|#
directive|define
name|AUTHOR
value|"Author"
end_define

begin_define
define|#
directive|define
name|DATE
value|"Date"
end_define

begin_define
define|#
directive|define
name|HEADER
value|"Header"
end_define

begin_define
define|#
directive|define
name|IDH
value|"Id"
end_define

begin_define
define|#
directive|define
name|LOCKER
value|"Locker"
end_define

begin_define
define|#
directive|define
name|LOG
value|"Log"
end_define

begin_define
define|#
directive|define
name|NAME
value|"Name"
end_define

begin_define
define|#
directive|define
name|RCSFILE
value|"RCSfile"
end_define

begin_define
define|#
directive|define
name|REVISION
value|"Revision"
end_define

begin_define
define|#
directive|define
name|SOURCE
value|"Source"
end_define

begin_define
define|#
directive|define
name|STATE
value|"State"
end_define

begin_define
define|#
directive|define
name|CVSHEADER
value|"CVSHeader"
end_define

begin_define
define|#
directive|define
name|keylength
value|9
end_define

begin_comment
comment|/* max length of any of the above keywords */
end_comment

begin_enum
enum|enum
name|markers
block|{
name|Nomatch
block|,
name|Author
block|,
name|Date
block|,
name|Header
block|,
name|Id
block|,
name|Locker
block|,
name|Log
block|,
name|Name
block|,
name|RCSfile
block|,
name|Revision
block|,
name|Source
block|,
name|State
block|,
name|CVSHeader
block|,
name|LocalId
block|}
enum|;
end_enum

begin_comment
comment|/* This must be in the same order as rcskeys.c's Keyword[] array. */
end_comment

begin_define
define|#
directive|define
name|DELNUMFORM
value|"\n\n%s\n%s\n"
end_define

begin_comment
comment|/* used by putdtext and scanlogtext */
end_comment

begin_define
define|#
directive|define
name|EMPTYLOG
value|"*** empty log message ***"
end_define

begin_comment
comment|/* used by ci and rlog */
end_comment

begin_comment
comment|/* main program */
end_comment

begin_decl_stmt
specifier|extern
name|char
specifier|const
name|cmdid
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|exiterr
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
name|exiting
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* merge */
end_comment

begin_decl_stmt
name|int
name|merge
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
specifier|const
index|[
literal|3
index|]
operator|,
name|char
specifier|const
operator|*
specifier|const
index|[
literal|3
index|]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rcsedit */
end_comment

begin_define
define|#
directive|define
name|ciklogsize
value|23
end_define

begin_comment
comment|/* sizeof("checked in with -k by ") */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|fcopy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
specifier|const
modifier|*
name|resultname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
specifier|const
name|ciklog
index|[
name|ciklogsize
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|locker_expansion
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|RILE
modifier|*
name|rcswriteopen
name|P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|,
expr|struct
name|stat
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
specifier|const
modifier|*
name|makedirtemp
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
specifier|const
modifier|*
name|getcaller
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|addlock
name|P
argument_list|(
operator|(
expr|struct
name|hshentry
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|addsymbol
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|checkaccesslist
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|chnamemod
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|int
operator|,
name|mode_t
operator|,
name|time_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|donerewrite
name|P
argument_list|(
operator|(
name|int
operator|,
name|time_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dorewrite
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|expandline
name|P
argument_list|(
operator|(
name|RILE
operator|*
operator|,
name|FILE
operator|*
operator|,
expr|struct
name|hshentry
specifier|const
operator|*
operator|,
name|int
operator|,
name|FILE
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|findlock
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|hshentry
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|setmtime
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|time_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ORCSclose
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ORCSerror
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|copystring
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dirtempunlink
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|enterstring
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|finishedit
name|P
argument_list|(
operator|(
expr|struct
name|hshentry
specifier|const
operator|*
operator|,
name|FILE
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|keepdirtemp
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|openfcopy
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|snapshotedit
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|xpandstring
name|P
argument_list|(
operator|(
expr|struct
name|hshentry
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|has_NFS
operator|||
name|bad_unlink
end_if

begin_decl_stmt
name|int
name|un_link
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|un_link
parameter_list|(
name|s
parameter_list|)
value|unlink(s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|large_memory
end_if

begin_decl_stmt
name|void
name|edit_string
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|editstring
parameter_list|(
name|delta
parameter_list|)
value|edit_string()
end_define

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|void
name|editstring
name|P
argument_list|(
operator|(
expr|struct
name|hshentry
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* rcsfcmp */
end_comment

begin_decl_stmt
name|int
name|rcsfcmp
name|P
argument_list|(
operator|(
name|RILE
operator|*
operator|,
expr|struct
name|stat
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
expr|struct
name|hshentry
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rcsfnms */
end_comment

begin_define
define|#
directive|define
name|bufautobegin
parameter_list|(
name|b
parameter_list|)
value|clear_buf(b)
end_define

begin_define
define|#
directive|define
name|clear_buf
parameter_list|(
name|b
parameter_list|)
value|(VOID ((b)->string = 0, (b)->size = 0))
end_define

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|workstdout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|workname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
specifier|const
modifier|*
name|RCSname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
specifier|const
modifier|*
name|suffixes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fdlock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stat
name|RCSstat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|RILE
modifier|*
name|rcsreadopen
name|P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|,
expr|struct
name|stat
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|bufenlarge
name|P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|,
name|char
specifier|const
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
specifier|const
modifier|*
name|basefilename
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
specifier|const
modifier|*
name|getfullRCSname
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
specifier|const
modifier|*
name|getfullCVSname
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
specifier|const
modifier|*
name|maketemp
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
specifier|const
modifier|*
name|rcssuffix
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pairnames
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
name|RILE
operator|*
operator|(
operator|*
operator|)
name|P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|,
expr|struct
name|stat
operator|*
operator|,
name|int
operator|)
argument_list|)
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cbuf
name|bufremember
name|P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bufalloc
name|P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bufautoend
name|P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bufrealloc
name|P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bufscat
name|P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bufscpy
name|P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tempunlink
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rcsgen */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|interactiveflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|buf
name|curlogbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
specifier|const
modifier|*
name|buildrevision
name|P
argument_list|(
operator|(
expr|struct
name|hshentries
specifier|const
operator|*
operator|,
expr|struct
name|hshentry
operator|*
operator|,
name|FILE
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getcstdin
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|putdtext
name|P
argument_list|(
operator|(
expr|struct
name|hshentry
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|FILE
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttystdin
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|yesorno
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
specifier|const
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|printf_string
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cbuf
name|cleanlogmsg
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cbuf
name|getsstdin
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|putdesc
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|putdftext
name|P
argument_list|(
operator|(
expr|struct
name|hshentry
specifier|const
operator|*
operator|,
name|RILE
operator|*
operator|,
name|FILE
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rcskeep */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|prevkeys
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|buf
name|prevauthor
decl_stmt|,
name|prevdate
decl_stmt|,
name|prevname
decl_stmt|,
name|prevrev
decl_stmt|,
name|prevstate
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getoldkeys
name|P
argument_list|(
operator|(
name|RILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rcskeys */
end_comment

begin_decl_stmt
specifier|extern
name|char
specifier|const
modifier|*
name|Keyword
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|markers
name|LocalIdMode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|enum
name|markers
name|trymatch
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|setRCSLocalId
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setIncExc
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* rcslex */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|foutptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|frewrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|RILE
modifier|*
name|finptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
specifier|const
modifier|*
name|NextString
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|tokens
name|nexttok
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hshenter
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nerror
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nextc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|quietflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|rcsline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
specifier|const
modifier|*
name|getid
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|efaterror
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
name|exiting
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|enfaterror
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
name|exiting
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fatcleanup
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
name|exiting
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|faterror
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|printf_string_exiting
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fatserror
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|printf_string_exiting
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rcsfaterror
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|printf_string_exiting
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Ieof
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
name|exiting
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Ierror
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
name|exiting
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Oerror
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
name|exiting
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|checkid
name|P
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
name|char
modifier|*
name|checksym
name|P
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
name|int
name|eoflex
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getkeyopt
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getlex
name|P
argument_list|(
operator|(
expr|enum
name|tokens
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cbuf
name|getphrases
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cbuf
name|savestring
name|P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|hshentry
modifier|*
name|getnum
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Ifclose
name|P
argument_list|(
operator|(
name|RILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Izclose
name|P
argument_list|(
operator|(
name|RILE
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Lexinit
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Ofclose
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Orewind
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Ozclose
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|aflush
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|afputc
name|P
argument_list|(
operator|(
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|aprintf
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|printf_string
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|aputs
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|checksid
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|checkssym
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|diagnose
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|printf_string
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|eerror
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|eflush
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|enerror
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|error
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|printf_string
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fvfprintf
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|getkey
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|getkeystring
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nextlex
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|oflush
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|printstring
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|readstring
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|redefined
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rcserror
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|printf_string
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rcswarn
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|printf_string
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|testIerror
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|testOerror
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|warn
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|printf_string
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|warnignore
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|workerror
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|printf_string
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|workwarn
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|printf_string
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|has_madvise
operator|&&
name|has_mmap
operator|&&
name|large_memory
end_if

begin_decl_stmt
name|void
name|advise_access
name|P
argument_list|(
operator|(
name|RILE
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|if_advise_access
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|,
name|advice
parameter_list|)
value|if (p) advise_access(f,advice)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|advise_access
parameter_list|(
name|f
parameter_list|,
name|advice
parameter_list|)
end_define

begin_define
define|#
directive|define
name|if_advise_access
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|,
name|advice
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|large_memory
operator|&&
name|maps_memory
end_if

begin_decl_stmt
name|RILE
modifier|*
name|I_open
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
expr|struct
name|stat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|Iopen
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|,
name|s
parameter_list|)
value|I_open(f,s)
end_define

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|RILE
modifier|*
name|Iopen
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
expr|struct
name|stat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|large_memory
end_if

begin_decl_stmt
name|void
name|testIeof
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Irewind
name|P
argument_list|(
operator|(
name|RILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* rcsmap */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|tokens
specifier|const
name|ctab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rcsrev */
end_comment

begin_decl_stmt
name|char
modifier|*
name|partialno
name|P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
specifier|const
modifier|*
name|namedrev
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
expr|struct
name|hshentry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
specifier|const
modifier|*
name|tiprev
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cmpdate
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cmpnum
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cmpnumfld
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|compartial
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|expandsym
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fexpandsym
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
expr|struct
name|buf
operator|*
operator|,
name|RILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|hshentry
modifier|*
name|genrevs
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
expr|struct
name|hshentries
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|countnumflds
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|getbranchno
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rcssyn */
end_comment

begin_comment
comment|/* These expand modes must agree with Expand_names[] in rcssyn.c.  */
end_comment

begin_define
define|#
directive|define
name|KEYVAL_EXPAND
value|0
end_define

begin_comment
comment|/* -kkv `$Keyword: value $' */
end_comment

begin_define
define|#
directive|define
name|KEYVALLOCK_EXPAND
value|1
end_define

begin_comment
comment|/* -kkvl `$Keyword: value locker $' */
end_comment

begin_define
define|#
directive|define
name|KEY_EXPAND
value|2
end_define

begin_comment
comment|/* -kk `$Keyword$' */
end_comment

begin_define
define|#
directive|define
name|VAL_EXPAND
value|3
end_define

begin_comment
comment|/* -kv `value' */
end_comment

begin_define
define|#
directive|define
name|OLD_EXPAND
value|4
end_define

begin_comment
comment|/* -ko use old string, omitting expansion */
end_comment

begin_define
define|#
directive|define
name|BINARY_EXPAND
value|5
end_define

begin_comment
comment|/* -kb like -ko, but use binary mode I/O */
end_comment

begin_define
define|#
directive|define
name|MIN_UNEXPAND
value|OLD_EXPAND
end_define

begin_comment
comment|/* min value for no logical expansion */
end_comment

begin_define
define|#
directive|define
name|MIN_UNCHANGED_EXPAND
value|(OPEN_O_BINARY ? BINARY_EXPAND : OLD_EXPAND)
end_define

begin_comment
comment|/* min value guaranteed to yield an identical file */
end_comment

begin_struct
struct|struct
name|diffcmd
block|{
name|long
name|line1
decl_stmt|,
comment|/* number of first line */
name|nlines
decl_stmt|,
comment|/* number of lines affected */
name|adprev
decl_stmt|,
comment|/* previous 'a' line1+1 or 'd' line1 */
name|dafter
decl_stmt|;
comment|/* sum of previous 'd' line1 and previous 'd' nlines */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|char
specifier|const
modifier|*
name|Dbranch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|access
modifier|*
name|AccessList
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|assoc
modifier|*
name|Symbols
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cbuf
name|Comment
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cbuf
name|Ignored
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|rcslock
modifier|*
name|Locks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|hshentry
modifier|*
name|Head
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Expand
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|StrictLocks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|TotalDeltas
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
specifier|const
modifier|*
specifier|const
name|expand_names
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
specifier|const
name|Kaccess
index|[]
decl_stmt|,
name|Kauthor
index|[]
decl_stmt|,
name|Kbranch
index|[]
decl_stmt|,
name|Kcomment
index|[]
decl_stmt|,
name|Kdate
index|[]
decl_stmt|,
name|Kdesc
index|[]
decl_stmt|,
name|Kexpand
index|[]
decl_stmt|,
name|Khead
index|[]
decl_stmt|,
name|Klocks
index|[]
decl_stmt|,
name|Klog
index|[]
decl_stmt|,
name|Knext
index|[]
decl_stmt|,
name|Kstate
index|[]
decl_stmt|,
name|Kstrict
index|[]
decl_stmt|,
name|Ksymbols
index|[]
decl_stmt|,
name|Ktext
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|unexpected_EOF
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
name|exiting
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getdiffcmd
name|P
argument_list|(
operator|(
name|RILE
operator|*
operator|,
name|int
operator|,
name|FILE
operator|*
operator|,
expr|struct
name|diffcmd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|str2expmode
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|getadmin
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|getdesc
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gettree
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ignorephrases
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|initdiffcmd
name|P
argument_list|(
operator|(
expr|struct
name|diffcmd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|putadmin
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|putstring
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|int
operator|,
expr|struct
name|cbuf
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|puttree
name|P
argument_list|(
operator|(
expr|struct
name|hshentry
specifier|const
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rcstime */
end_comment

begin_define
define|#
directive|define
name|zonelenmax
value|9
end_define

begin_comment
comment|/* maxiumum length of time zone string, e.g. "+12:34:56" */
end_comment

begin_decl_stmt
name|char
specifier|const
modifier|*
name|date2str
name|P
argument_list|(
operator|(
name|char
specifier|const
index|[
name|datesize
index|]
operator|,
name|char
index|[
name|datesize
operator|+
name|zonelenmax
index|]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|time_t
name|date2time
name|P
argument_list|(
operator|(
name|char
specifier|const
index|[
name|datesize
index|]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|str2date
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
index|[
name|datesize
index|]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|time2date
name|P
argument_list|(
operator|(
name|time_t
operator|,
name|char
index|[
name|datesize
index|]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|zone_set
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rcsutil */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|RCSversion
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|fopenSafer
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|cgetenv
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|fstr_save
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|str_save
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
specifier|const
modifier|*
name|getusername
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fdSafer
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getRCSINIT
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
name|char
operator|*
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|run
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
specifier|const
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|runv
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|malloc_type
name|fremember
name|P
argument_list|(
operator|(
name|malloc_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|malloc_type
name|ftestalloc
name|P
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|malloc_type
name|testalloc
name|P
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|malloc_type
name|testrealloc
name|P
argument_list|(
operator|(
name|malloc_type
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ftalloc
parameter_list|(
name|T
parameter_list|)
value|ftnalloc(T,1)
end_define

begin_define
define|#
directive|define
name|talloc
parameter_list|(
name|T
parameter_list|)
value|tnalloc(T,1)
end_define

begin_if
if|#
directive|if
name|RCS_lint
end_if

begin_decl_stmt
specifier|extern
name|malloc_type
name|lintalloc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ftnalloc
parameter_list|(
name|T
parameter_list|,
name|n
parameter_list|)
value|(lintalloc = ftestalloc(sizeof(T)*(n)), (T*)0)
end_define

begin_define
define|#
directive|define
name|tnalloc
parameter_list|(
name|T
parameter_list|,
name|n
parameter_list|)
value|(lintalloc = testalloc(sizeof(T)*(n)), (T*)0)
end_define

begin_define
define|#
directive|define
name|trealloc
parameter_list|(
name|T
parameter_list|,
name|p
parameter_list|,
name|n
parameter_list|)
value|(lintalloc = testrealloc((malloc_type)0, sizeof(T)*(n)), p)
end_define

begin_define
define|#
directive|define
name|tfree
parameter_list|(
name|p
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ftnalloc
parameter_list|(
name|T
parameter_list|,
name|n
parameter_list|)
value|((T*) ftestalloc(sizeof(T)*(n)))
end_define

begin_define
define|#
directive|define
name|tnalloc
parameter_list|(
name|T
parameter_list|,
name|n
parameter_list|)
value|((T*) testalloc(sizeof(T)*(n)))
end_define

begin_define
define|#
directive|define
name|trealloc
parameter_list|(
name|T
parameter_list|,
name|p
parameter_list|,
name|n
parameter_list|)
value|((T*) testrealloc((malloc_type)(p), sizeof(T)*(n)))
end_define

begin_define
define|#
directive|define
name|tfree
parameter_list|(
name|p
parameter_list|)
value|free((malloc_type)(p))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|time_t
name|now
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|awrite
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|size_t
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fastcopy
name|P
argument_list|(
operator|(
name|RILE
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ffree
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ffree1
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setRCSversion
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|has_signal
end_if

begin_decl_stmt
name|void
name|catchints
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ignoreints
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|restoreints
name|P
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

begin_define
define|#
directive|define
name|catchints
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ignoreints
parameter_list|()
end_define

begin_define
define|#
directive|define
name|restoreints
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|has_mmap
operator|&&
name|large_memory
end_if

begin_if
if|#
directive|if
name|has_NFS
operator|&&
name|mmap_signal
end_if

begin_decl_stmt
name|void
name|catchmmapints
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|readAccessFilenameBuffer
name|P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|unsigned
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|catchmmapints
parameter_list|()
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
name|has_getuid
end_if

begin_decl_stmt
name|uid_t
name|ruid
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|myself
parameter_list|(
name|u
parameter_list|)
value|((u) == ruid())
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|myself
parameter_list|(
name|u
parameter_list|)
value|true
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|has_setuid
end_if

begin_decl_stmt
name|uid_t
name|euid
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nosetid
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|seteid
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setrid
name|P
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

begin_define
define|#
directive|define
name|nosetid
parameter_list|()
end_define

begin_define
define|#
directive|define
name|seteid
parameter_list|()
end_define

begin_define
define|#
directive|define
name|setrid
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* version */
end_comment

begin_decl_stmt
specifier|extern
name|char
specifier|const
name|RCS_version_string
index|[]
decl_stmt|;
end_decl_stmt

end_unit

