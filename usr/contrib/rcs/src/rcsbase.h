begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *                     RCS common definitions and data structures  */
end_comment

begin_define
define|#
directive|define
name|RCSBASE
value|"$Header: /usr/src/new/rcs/src/RCS/rcsbase.h,v 3.7 83/10/19 04:22:11 lepreau Exp $"
end_define

begin_comment
comment|/*****************************************************************************  * INSTRUCTIONS:  * =============  * For USG Unix, define USG; for BSD Unix, don't (see ifdef USG).  * For 4.2 bsd, define V4_2BSD; this will replace the routines  * getwd() and rename() with the corresponding ones in the C-library.  * V4_2BSD also selects different definitions for the macros NCPFN and NCPPN  * (max. number of characters per filename, number of characters per path name).  * Define STRICT_LOCKING appropriately (see STRICT_LOCKING).  * Change BYTESIZ if necessary.  *****************************************************************************  *  * Copyright (C) 1982 by Walter F. Tichy  *                       Purdue University  *                       Computer Science Department  *                       West Lafayette, IN 47907  *  * All rights reserved. No part of this software may be sold or distributed  * in any form or by any means without the prior written permission of the  * author.  * Report problems and direct all inquiries to Tichy@purdue (ARPA net).  */
end_comment

begin_comment
comment|/* $Log:	rcsbase.h,v $  * Revision 3.7  83/10/19  04:22:11  lepreau  * Make teeny logsize big  *   * Revision 3.6  83/01/15  16:43:28  wft  * 4.2 prerelease  *   * Revision 3.6  83/01/15  16:43:28  wft  * Replaced dbm.h with BYTESIZ, fixed definition of rindex().  * Added variants of NCPFN and NCPPN for bsd 4.2, selected by defining V4_2BSD.  * Added macro DELNUMFORM to have uniform format for printing delta text nodes.  * Added macro DELETE to mark deleted deltas.  *   * Revision 3.5  82/12/10  12:16:56  wft  * Added two forms of DATEFORM, one using %02d, the other %.2d.  *  * Revision 3.4  82/12/04  20:01:25  wft  * added LOCKER, Locker, and USG (redefinition of rindex).  *  * Revision 3.3  82/12/03  12:22:04  wft  * Added dbm.h, stdio.h, RCSBASE, RCSSEP, RCSSUF, WORKMODE, TMPFILE3,  * PRINTDATE, PRINTTIME, map, and ctab; removed Suffix. Redefined keyvallength  * using NCPPN. Changed putc() to abort on write error.  *  * Revision 3.2  82/10/18  15:03:52  wft  * added macro STRICT_LOCKING, removed RCSUMASK.  * renamed JOINFILE[1,2] to JOINFIL[1,2].  *  * Revision 3.1  82/10/11  19:41:17  wft  * removed NBPW, NBPC, NCPW.  * added typdef int void to aid compiling  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_undef
undef|#
directive|undef
name|putc
end_undef

begin_comment
comment|/* will be redefined */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_define
define|#
directive|define
name|rindex
value|strrchr
end_define

begin_define
define|#
directive|define
name|DATEFORM
value|"%.2d.%.2d.%.2d.%.2d.%.2d.%.2d"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DATEFORM
value|"%02d.%02d.%02d.%02d.%02d.%02d"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Make sure one of %02d or %.2d prints a number with a field width 2, with  * leading zeroes. For example, 0, 1, and 22 must be printed as 00, 01, and  * 22. Otherwise, there will be problems with the dates.  */
end_comment

begin_define
define|#
directive|define
name|PRINTDATE
parameter_list|(
name|file
parameter_list|,
name|date
parameter_list|)
value|fprintf(file,"%.2s/%.2s/%.2s",date,date+3,date+6)
end_define

begin_define
define|#
directive|define
name|PRINTTIME
parameter_list|(
name|file
parameter_list|,
name|date
parameter_list|)
value|fprintf(file,"%.2s:%.2s:%.2s",date+9,date+12,date+15)
end_define

begin_comment
comment|/* print RCS format date and time in nice format from a string              */
end_comment

begin_comment
comment|/*  * Parameters  */
end_comment

begin_define
define|#
directive|define
name|BYTESIZ
value|8
end_define

begin_comment
comment|/* number of bits in a byte                   */
end_comment

begin_define
define|#
directive|define
name|STRICT_LOCKING
value|1
end_define

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
name|hshsize
value|239
end_define

begin_comment
comment|/* hashtable size; MUST be prime and -1 mod 4 */
end_comment

begin_comment
comment|/* other choices: 547 or 719                  */
end_comment

begin_define
define|#
directive|define
name|strtsize
value|(hshsize * 50)
end_define

begin_comment
comment|/* string table size                        */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|pdp11
end_ifdef

begin_define
define|#
directive|define
name|logsize
value|1024
end_define

begin_comment
comment|/* size of logmessage                        */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|logsize
value|4096
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|revlength
value|30
end_define

begin_comment
comment|/* max. length of revision numbers            */
end_comment

begin_define
define|#
directive|define
name|datelength
value|20
end_define

begin_comment
comment|/* length of a date in RCS format             */
end_comment

begin_define
define|#
directive|define
name|joinlength
value|20
end_define

begin_comment
comment|/* number of joined revisions permitted       */
end_comment

begin_define
define|#
directive|define
name|RCSDIR
value|"RCS/"
end_define

begin_comment
comment|/* subdirectory for RCS files                 */
end_comment

begin_define
define|#
directive|define
name|RCSSUF
value|'v'
end_define

begin_comment
comment|/* suffix for RCS files                       */
end_comment

begin_define
define|#
directive|define
name|RCSSEP
value|','
end_define

begin_comment
comment|/* separator for RCSSUF                       */
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

begin_ifdef
ifdef|#
directive|ifdef
name|V4_2BSD
end_ifdef

begin_define
define|#
directive|define
name|NCPFN
value|256
end_define

begin_comment
comment|/* number of characters per filename          */
end_comment

begin_define
define|#
directive|define
name|NCPPN
value|1024
end_define

begin_comment
comment|/* number of characters per pathname          */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NCPFN
value|14
end_define

begin_comment
comment|/* number of characters per filename          */
end_comment

begin_define
define|#
directive|define
name|NCPPN
value|6*NCPFN
end_define

begin_comment
comment|/* number of characters per pathname          */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|keylength
value|20
end_define

begin_comment
comment|/* buffer length for expansion keywords       */
end_comment

begin_define
define|#
directive|define
name|keyvallength
value|NCPPN+revlength+datelength+60
end_define

begin_comment
comment|/* buffer length for keyword expansion        */
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

begin_define
define|#
directive|define
name|nil
value|0
end_define

begin_define
define|#
directive|define
name|elsif
value|else if
end_define

begin_define
define|#
directive|define
name|elif
value|else if
end_define

begin_comment
comment|/* temporary file names */
end_comment

begin_define
define|#
directive|define
name|NEWRCSFILE
value|",RCSnewXXXXXX"
end_define

begin_define
define|#
directive|define
name|DIFFILE
value|",RCSciXXXXXX"
end_define

begin_define
define|#
directive|define
name|TMPFILE1
value|",RCSt1XXXXXX"
end_define

begin_define
define|#
directive|define
name|TMPFILE2
value|",RCSt2XXXXXX"
end_define

begin_define
define|#
directive|define
name|TMPFILE3
value|",RCSt3XXXXXX"
end_define

begin_define
define|#
directive|define
name|JOINFIL2
value|",RCSj2XXXXXX"
end_define

begin_define
define|#
directive|define
name|JOINFIL3
value|",RCSj3XXXXXX"
end_define

begin_define
define|#
directive|define
name|putc
parameter_list|(
name|x
parameter_list|,
name|p
parameter_list|)
value|(--(p)->_cnt>=0? ((int)(*(p)->_ptr++=(unsigned)(x))):fflsbuf((unsigned)(x),p))
end_define

begin_comment
comment|/* This version of putc prints a char, but aborts on write error            */
end_comment

begin_define
define|#
directive|define
name|GETC
parameter_list|(
name|in
parameter_list|,
name|out
parameter_list|,
name|echo
parameter_list|)
value|(echo?putc(getc(in),out):getc(in))
end_define

begin_comment
comment|/* GETC writes a del-character (octal 177) on end of file                   */
end_comment

begin_define
define|#
directive|define
name|WORKMODE
parameter_list|(
name|RCSmode
parameter_list|)
value|(RCSmode&~0222)|((lockflag||!StrictLocks)?0600:0000)
end_define

begin_comment
comment|/* computes mode of working file: same as RCSmode, but write permission     */
end_comment

begin_comment
comment|/* determined by lockflag and StrictLocks.                                  */
end_comment

begin_comment
comment|/* character classes and token codes */
end_comment

begin_enum
enum|enum
name|tokens
block|{
comment|/* char classes*/
name|DIGIT
block|,
name|IDCHAR
block|,
name|NEWLN
block|,
name|LETTER
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
name|DATE
block|,
name|EOFILE
block|,
name|ID
block|,
name|KEYW
block|,
name|NUM
block|,
name|SEMI
block|,
name|STRING
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|AT
value|SBEGIN
end_define

begin_comment
comment|/* class SBEGIN (string begin) is returned by lex. anal. */
end_comment

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
comment|/* these must be changed consistently, for instance to:  * #define DQUOTE       SBEGIN  * #define SDELIM       '"'  * #define AT           IDCHAR  * there should be no overlap among SDELIM, KDELIM, and VDELIM  */
end_comment

begin_comment
comment|/* other characters */
end_comment

begin_define
define|#
directive|define
name|ACCENT
value|IDCHAR
end_define

begin_define
define|#
directive|define
name|AMPER
value|IDCHAR
end_define

begin_define
define|#
directive|define
name|BACKSL
value|IDCHAR
end_define

begin_define
define|#
directive|define
name|BAR
value|IDCHAR
end_define

begin_define
define|#
directive|define
name|COMMA
value|UNKN
end_define

begin_define
define|#
directive|define
name|DIVIDE
value|IDCHAR
end_define

begin_define
define|#
directive|define
name|DOLLAR
value|IDCHAR
end_define

begin_define
define|#
directive|define
name|DQUOTE
value|IDCHAR
end_define

begin_define
define|#
directive|define
name|EQUAL
value|IDCHAR
end_define

begin_define
define|#
directive|define
name|EXCLA
value|IDCHAR
end_define

begin_define
define|#
directive|define
name|GREAT
value|IDCHAR
end_define

begin_define
define|#
directive|define
name|HASH
value|IDCHAR
end_define

begin_define
define|#
directive|define
name|INSERT
value|UNKN
end_define

begin_define
define|#
directive|define
name|LBRACE
value|IDCHAR
end_define

begin_define
define|#
directive|define
name|LBRACK
value|IDCHAR
end_define

begin_define
define|#
directive|define
name|LESS
value|IDCHAR
end_define

begin_define
define|#
directive|define
name|LPARN
value|IDCHAR
end_define

begin_define
define|#
directive|define
name|MINUS
value|IDCHAR
end_define

begin_define
define|#
directive|define
name|PERCNT
value|IDCHAR
end_define

begin_define
define|#
directive|define
name|PLUS
value|IDCHAR
end_define

begin_define
define|#
directive|define
name|QUEST
value|IDCHAR
end_define

begin_define
define|#
directive|define
name|RBRACE
value|IDCHAR
end_define

begin_define
define|#
directive|define
name|RBRACK
value|IDCHAR
end_define

begin_define
define|#
directive|define
name|RPARN
value|IDCHAR
end_define

begin_define
define|#
directive|define
name|SQUOTE
value|IDCHAR
end_define

begin_define
define|#
directive|define
name|TILDE
value|IDCHAR
end_define

begin_define
define|#
directive|define
name|TIMES
value|IDCHAR
end_define

begin_define
define|#
directive|define
name|UNDER
value|IDCHAR
end_define

begin_define
define|#
directive|define
name|UPARR
value|IDCHAR
end_define

begin_comment
comment|/***************************************  * Data structures for the symbol table  ***************************************/
end_comment

begin_comment
comment|/* Hash table entry */
end_comment

begin_struct
struct|struct
name|hshentry
block|{
name|char
modifier|*
name|num
decl_stmt|;
comment|/* pointer to revision number (ASCIZ) */
name|char
modifier|*
name|date
decl_stmt|;
comment|/* pointer to date of checking        */
name|char
modifier|*
name|author
decl_stmt|;
comment|/* login of person checking in        */
name|char
modifier|*
name|lockedby
decl_stmt|;
comment|/* who locks the revision             */
name|char
modifier|*
name|log
decl_stmt|;
comment|/* log message requested at checkin   */
name|char
modifier|*
name|state
decl_stmt|;
comment|/* state of revision (Exp by default) */
name|struct
name|branchhead
modifier|*
name|branches
decl_stmt|;
comment|/* list of first revisions on branches*/
name|struct
name|hshentry
modifier|*
name|next
decl_stmt|;
comment|/* next revision on same branch       */
name|int
name|insertlns
decl_stmt|;
comment|/* lines inserted (computed by rlog)  */
name|int
name|deletelns
decl_stmt|;
comment|/* lines deleted  (computed by rlog)  */
name|char
name|selector
decl_stmt|;
comment|/* marks entry for selection/deletion */
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
name|lock
block|{
name|char
modifier|*
name|login
decl_stmt|;
name|struct
name|hshentry
modifier|*
name|delta
decl_stmt|;
name|struct
name|lock
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
modifier|*
name|symbol
decl_stmt|;
name|struct
name|hshentry
modifier|*
name|delta
decl_stmt|;
name|struct
name|assoc
modifier|*
name|nextassoc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* common variables (getadmin and getdelta())*/
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Comment
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
name|lock
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
specifier|static
name|char
name|copyright
index|[]
init|=
literal|"Copyright (C) 1982 by Walter F. Tichy"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* common variables (lexical analyzer)*/
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|tokens
name|map
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ctab
value|(&map[1])
end_define

begin_decl_stmt
specifier|extern
name|struct
name|hshentry
name|hshtab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|hshentry
modifier|*
name|nexthsh
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
name|char
modifier|*
name|NextString
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cmdid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* common routines */
end_comment

begin_function_decl
specifier|extern
name|int
name|serror
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|faterror
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fatserror
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Markers for keyword expansion (used in co and ident)  */
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
name|Locker
block|,
name|Log
block|,
name|Revision
block|,
name|Source
block|,
name|State
block|}
enum|;
end_enum

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
name|DELETE
value|'D'
end_define

begin_comment
comment|/* set by rcs -o and used by puttree() in rcssyn */
end_comment

begin_typedef
typedef|typedef
name|int
name|void
typedef|;
end_typedef

end_unit

