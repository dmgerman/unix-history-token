begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* vi.h */
end_comment

begin_comment
comment|/* Author:  *	Steve Kirkendall  *	14407 SW Teal Blvd. #C  *	Beaverton, OR 97005  *	kirkenda@cs.pdx.edu  */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|"ELVIS 1.7, by Steve Kirkendall (30 December 1992)"
end_define

begin_define
define|#
directive|define
name|COPYING
value|"This version of ELVIS is freely redistributable."
end_define

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_if
if|#
directive|if
name|TOS
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_define
define|#
directive|define
name|ENOENT
value|(-AEFILNF)
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
name|TOS
operator|||
name|VMS
end_if

begin_include
include|#
directive|include
file|<types.h>
end_include

begin_define
define|#
directive|define
name|O_RDONLY
value|0
end_define

begin_define
define|#
directive|define
name|O_WRONLY
value|1
end_define

begin_define
define|#
directive|define
name|O_RDWR
value|2
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|S_IJDIR
value|S_IFDIR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|OSK
end_if

begin_include
include|#
directive|include
file|<modes.h>
end_include

begin_define
define|#
directive|define
name|O_RDONLY
value|S_IREAD
end_define

begin_define
define|#
directive|define
name|O_WRONLY
value|S_IWRITE
end_define

begin_define
define|#
directive|define
name|O_RDWR
value|(S_IREAD | S_IWRITE)
end_define

begin_define
define|#
directive|define
name|ENOENT
value|E_PNNF
end_define

begin_define
define|#
directive|define
name|sprintf
value|Sprintf
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|!
name|AMIGA
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|COH_286
end_if

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_include
include|#
directive|include
file|"curses.h"
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* for [v]sprintf prototype		*/
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/* for str* prototypes			*/
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/* for atoi, system, malloc, free	*/
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_comment
comment|/* for vararg definitions		*/
end_comment

begin_if
if|#
directive|if
name|ANY_UNIX
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|/* for read, write, ... prototypes	*/
end_comment

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_comment
comment|/* for wait prototype			*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* Miscellaneous constants.						  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|REGEX
end_ifdef

begin_define
define|#
directive|define
name|SE_MAX
value|30
end_define

begin_comment
comment|/* max number of subexpressions */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|INFINITY
value|2000000001L
end_define

begin_comment
comment|/* a very large integer */
end_comment

begin_define
define|#
directive|define
name|LONGKEY
value|10
end_define

begin_comment
comment|/* longest possible raw :map key */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXRCLEN
end_ifndef

begin_define
define|#
directive|define
name|MAXRCLEN
value|1000
end_define

begin_comment
comment|/* longest possible :@ command */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* These describe how temporary files are divided into blocks             */
end_comment

begin_define
define|#
directive|define
name|MAXBLKS
value|(BLKSIZE / sizeof(unsigned short))
end_define

begin_typedef
typedef|typedef
union|union
block|{
name|char
name|c
index|[
name|BLKSIZE
index|]
decl_stmt|;
comment|/* for text blocks */
name|unsigned
name|short
name|n
index|[
name|MAXBLKS
index|]
decl_stmt|;
comment|/* for the header block */
block|}
name|BLK
typedef|;
end_typedef

begin_comment
comment|/*------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* These are used manipulate BLK buffers.                                 */
end_comment

begin_decl_stmt
specifier|extern
name|BLK
name|hdr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer for the header block */
end_comment

begin_decl_stmt
specifier|extern
name|BLK
modifier|*
name|blkget
name|P_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* given index into hdr.c[], reads block */
end_comment

begin_decl_stmt
specifier|extern
name|BLK
modifier|*
name|blkadd
name|P_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* inserts a new block into hdr.c[] */
end_comment

begin_comment
comment|/*------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* These are used to keep track of various flags                          */
end_comment

begin_struct
specifier|extern
struct|struct
name|_viflags
block|{
name|short
name|file
decl_stmt|;
comment|/* file flags */
block|}
name|viflags
struct|;
end_struct

begin_comment
comment|/* file flags */
end_comment

begin_define
define|#
directive|define
name|NEWFILE
value|0x0001
end_define

begin_comment
comment|/* the file was just created */
end_comment

begin_define
define|#
directive|define
name|READONLY
value|0x0002
end_define

begin_comment
comment|/* the file is read-only */
end_comment

begin_define
define|#
directive|define
name|HADNUL
value|0x0004
end_define

begin_comment
comment|/* the file contained NUL characters */
end_comment

begin_define
define|#
directive|define
name|MODIFIED
value|0x0008
end_define

begin_comment
comment|/* the file has been modified, but not saved */
end_comment

begin_define
define|#
directive|define
name|NOFILE
value|0x0010
end_define

begin_comment
comment|/* no name is known for the current text */
end_comment

begin_define
define|#
directive|define
name|ADDEDNL
value|0x0020
end_define

begin_comment
comment|/* newlines were added to the file */
end_comment

begin_define
define|#
directive|define
name|HADBS
value|0x0040
end_define

begin_comment
comment|/* backspace chars were lost from the file */
end_comment

begin_define
define|#
directive|define
name|UNDOABLE
value|0x0080
end_define

begin_comment
comment|/* file has been modified */
end_comment

begin_define
define|#
directive|define
name|NOTEDITED
value|0x0100
end_define

begin_comment
comment|/* the :file command has been used */
end_comment

begin_comment
comment|/* macros used to set/clear/test flags */
end_comment

begin_define
define|#
directive|define
name|setflag
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|viflags.x |= y
end_define

begin_define
define|#
directive|define
name|clrflag
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|viflags.x&= ~y
end_define

begin_define
define|#
directive|define
name|tstflag
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(viflags.x& y)
end_define

begin_define
define|#
directive|define
name|initflags
parameter_list|()
value|viflags.file = 0;
end_define

begin_comment
comment|/* The options */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|o_autoindent
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_autoprint
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_autotab
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_autowrite
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_columns
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_directory
index|[
literal|30
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_edcompatible
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_equalprg
index|[
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_errorbells
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_exrefresh
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_ignorecase
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_keytime
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_keywordprg
index|[
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_lines
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_list
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_number
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_readonly
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_remap
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_report
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_scroll
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_shell
index|[
literal|60
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_shiftwidth
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_sidescroll
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_sync
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_tabstop
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_term
index|[
literal|30
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_flash
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_warn
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_wrapscan
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|CRUNCH
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|o_beautify
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_exrc
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_mesg
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_more
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_nearscroll
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_novice
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_prompt
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_taglength
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_tags
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_terse
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_window
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_wrapmargin
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_writeany
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_ERRLIST
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|o_cc
index|[
literal|30
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_make
index|[
literal|30
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CHARATTR
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|o_charattr
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_DIGRAPH
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|o_digraph
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_flipcase
index|[
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_SENTENCE
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|o_hideformat
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_EXTENSIONS
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|o_inputmode
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_ruler
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_MAGIC
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|o_magic
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_MODELINES
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|o_modelines
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_SENTENCE
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|o_paragraphs
index|[
literal|30
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|o_sections
index|[
literal|30
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|MSDOS
end_if

begin_decl_stmt
specifier|extern
name|char
name|o_pcbios
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_SHOWMATCH
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|o_showmatch
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_SHOWMODE
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|o_smd
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_TAGSTACK
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|o_tagstack
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* These help support the single-line multi-change "undo" -- shift-U      */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|U_text
index|[
name|BLKSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|U_line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* These are used to refer to places in the text 			  */
end_comment

begin_typedef
typedef|typedef
name|long
name|MARK
typedef|;
end_typedef

begin_define
define|#
directive|define
name|markline
parameter_list|(
name|x
parameter_list|)
value|(long)((x) / BLKSIZE)
end_define

begin_define
define|#
directive|define
name|markidx
parameter_list|(
name|x
parameter_list|)
value|(int)((x)& (BLKSIZE - 1))
end_define

begin_define
define|#
directive|define
name|MARK_UNSET
value|((MARK)0)
end_define

begin_define
define|#
directive|define
name|MARK_FIRST
value|((MARK)BLKSIZE)
end_define

begin_define
define|#
directive|define
name|MARK_LAST
value|((MARK)(nlines * BLKSIZE))
end_define

begin_define
define|#
directive|define
name|MARK_EOF
value|((MARK)((nlines + 1) * BLKSIZE))
end_define

begin_define
define|#
directive|define
name|MARK_AT_LINE
parameter_list|(
name|x
parameter_list|)
value|((MARK)(x) * BLKSIZE)
end_define

begin_define
define|#
directive|define
name|NMARKS
value|29
end_define

begin_decl_stmt
specifier|extern
name|MARK
name|mark
index|[
name|NMARKS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* marks a-z, plus mark ' and two temps */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|cursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mark where line is */
end_comment

begin_comment
comment|/*------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* These are used to keep track of the current& previous files.	  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|origtime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* modification date&time of the current file */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|origname
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of the current file */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|prevorig
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of the preceding file */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|prevline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line number from preceding file */
end_comment

begin_comment
comment|/*------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* misc housekeeping variables& functions				  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tmpfd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fd used to access the tmp file */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tmpnum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* counter used to generate unique filenames */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|lnum
index|[
name|MAXBLKS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last line# of each block */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|nlines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of lines in the file */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|args
index|[
name|BLKSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file names given on the command line */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|argno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the current element of args[] */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nargs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of filenames in args */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|changes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* counts changes, to prohibit short-cuts */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|significant
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* boolean: was a *REAL* change made? */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|exitcode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0=not updated, 1=overwritten, else error */
end_comment

begin_decl_stmt
specifier|extern
name|BLK
name|tmpblk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a block used to accumulate changes */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|topline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file line number of top line */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|leftcol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* column number of left col */
end_comment

begin_define
define|#
directive|define
name|botline
value|(topline + LINES - 2)
end_define

begin_define
define|#
directive|define
name|rightcol
value|(leftcol + COLS - (*o_number ? 9 : 1))
end_define

begin_decl_stmt
specifier|extern
name|int
name|physcol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* physical column number that cursor is on */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|physrow
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* physical row number that cursor is on */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|exwrote
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used to detect verbose ex commands */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|doingdot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* boolean: are we doing the "." command? */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|doingglobal
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* boolean: are doing a ":g" command? */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|rptlines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of lines affected by a command */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rptlabel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* description of how lines were affected */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fetchline
name|P_
argument_list|(
operator|(
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* read a given line from tmp file */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|parseptrn
name|P_
argument_list|(
operator|(
name|REG
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* isolate a regexp in a line */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|paste
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* paste from cut buffer to a given point */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|wildcard
name|P_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* expand wildcards in filenames */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|input
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* inserts characters from keyboard */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|linespec
name|P_
argument_list|(
operator|(
name|REG
name|char
operator|*
operator|,
name|MARK
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* finds the end of a /regexp/ string */
end_comment

begin_define
define|#
directive|define
name|ctrl
parameter_list|(
name|ch
parameter_list|)
value|((ch)&037)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_RECYCLE
end_ifndef

begin_decl_stmt
specifier|extern
name|long
name|allocate
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* allocate a free block of the tmp file */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|SIGTYPE
name|trapint
name|P_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* trap handler for SIGINT */
end_comment

begin_decl_stmt
specifier|extern
name|SIGTYPE
name|deathtrap
name|P_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* trap handler for deadly signals */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|blkdirty
name|P_
argument_list|(
operator|(
name|BLK
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* marks a block as being "dirty" */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|blksync
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* forces all "dirty" blocks to disk */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|blkinit
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* resets the block cache to "empty" state */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|beep
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rings the terminal's bell */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|exrefresh
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* writes text to the screen */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
specifier|extern
name|void
name|msg
parameter_list|(
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* writes a printf-style message to the screen */
end_comment

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|msg
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* writes a printf-style message to the screen */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|endmsgs
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if "manymsgs" is set, then scroll up 1 line */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|garbage
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reclaims any garbage blocks */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|redraw
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* updates the screen after a change */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|resume_curses
name|P_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* puts the terminal in "cbreak" mode */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|beforedo
name|P_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* saves current revision before a new change */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|afterdo
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* marks end of a beforedo() change */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|abortdo
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* like "afterdo()" followed by "undo()" */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|undo
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* restores file to previous undo() */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dumpkey
name|P_
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lists key mappings to the screen */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|mapkey
name|P_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defines a new key mapping */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|redrawrange
name|P_
argument_list|(
operator|(
name|long
operator|,
name|long
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* records clues from modify.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|cut
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* saves text in a cut buffer */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|delete
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* deletes text */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|add
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* adds text */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|change
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* deletes text, and then adds other text */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|cutswitch
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* updates cut buffers when we switch files */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|do_digraph
name|P_
argument_list|(
operator|(
name|int
operator|,
name|char
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defines or lists digraphs */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|exstring
name|P_
argument_list|(
operator|(
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

begin_comment
comment|/* execute a string as EX commands */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dumpopts
name|P_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* display current option settings on the screen */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|setopts
name|P_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* assign new values to options */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|saveopts
name|P_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* save current option values to a given fd */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|savedigs
name|P_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* save current non-standard digraphs to fd */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|savecolor
name|P_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* save current color settings (if any) to fd */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|cutname
name|P_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* select cut buffer for next cut/paste */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|initopts
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initialize options */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|cutend
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* free all cut buffers& delete temp files */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|storename
name|P_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stamp temp file with pathname of text file */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tmpstart
name|P_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* load a text file into edit buffer */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tmpsave
name|P_
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

begin_comment
comment|/* write edit buffer out to text file */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tmpend
name|P_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* call tmpsave(), and then tmpabort */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tmpabort
name|P_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* abandon the current edit buffer */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|savemaps
name|P_
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* write current :map or :ab commands to fd */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ansicolor
name|P_
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* emit ANSI color command to terminal */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|filter
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* I/O though another program */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|getkey
name|P_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* return a keystroke, interpretting maps */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vgets
name|P_
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

begin_comment
comment|/* read a single line from keyboard */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|doexrc
name|P_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* execute a string as a sequence of EX commands */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cb2str
name|P_
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* return a string containing cut buffer's contents */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ansiquit
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* neutralize previous ansicolor() call */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ttyread
name|P_
argument_list|(
operator|(
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

begin_comment
comment|/* read from keyboard with optional timeout */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tgetent
name|P_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start termcap */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tgetnum
name|P_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* get a termcap number */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tgetflag
name|P_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* get a termcap boolean */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|getsize
name|P_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* determine how big the screen is */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|endcolor
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used during color output */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|getabkey
name|P_
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

begin_comment
comment|/* like getkey(), but also does abbreviations */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|idx2col
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|REG
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* returns column# of a given MARK */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cutneeds
name|P_
argument_list|(
operator|(
name|BLK
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* returns bitmap of blocks needed to hold cutbuffer text */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|execmap
name|P_
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

begin_comment
comment|/* replaces "raw" keys with "mapped" keys */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CRUNCH
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|wset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* boolean: has the "window" size been set? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* macros that are used as control structures                             */
end_comment

begin_define
define|#
directive|define
name|BeforeAfter
parameter_list|(
name|before
parameter_list|,
name|after
parameter_list|)
value|for((before),bavar=1;bavar;(after),bavar=0)
end_define

begin_define
define|#
directive|define
name|ChangeText
value|BeforeAfter(beforedo(FALSE),afterdo())
end_define

begin_decl_stmt
specifier|extern
name|int
name|bavar
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used only in BeforeAfter macros */
end_comment

begin_comment
comment|/*------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* These are the movement commands.  Each accepts a mark for the starting */
end_comment

begin_comment
comment|/* location& number and returns a mark for the destination.		  */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|m_updnto
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* k j G */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|m_right
name|P_
argument_list|(
operator|(
name|MARK
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

begin_comment
comment|/* h */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|m_left
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* l */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|m_tocol
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* | */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|m_front
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ^ */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|m_rear
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $ */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|m_fword
name|P_
argument_list|(
operator|(
name|MARK
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

begin_comment
comment|/* w */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|m_bword
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* b */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|m_eword
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* e */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|m_paragraph
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* { } [[ ]] */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|m_match
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* % */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_SENTENCE
end_ifndef

begin_decl_stmt
specifier|extern
name|MARK
name|m_sentence
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ( ) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|MARK
name|m_tomark
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 'm */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_EXTENSIONS
end_ifndef

begin_decl_stmt
specifier|extern
name|MARK
name|m_wsrch
name|P_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|MARK
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ^A */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|MARK
name|m_nsrch
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* n */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|m_fsrch
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* /regexp */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|m_bsrch
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ?regexp */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CHARSEARCH
end_ifndef

begin_decl_stmt
specifier|extern
name|MARK
name|m__ch
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ; , */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|m_fch
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* f */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|m_tch
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* t */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|m_Fch
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* F */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|m_Tch
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* T */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|MARK
name|m_row
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* H L M */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|m_z
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* z */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|m_scroll
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ^B ^F ^E ^Y ^U ^D */
end_comment

begin_comment
comment|/* Some stuff that is used by movement functions... */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|adjmove
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|REG
name|MARK
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a helper fn, used by move fns */
end_comment

begin_comment
comment|/* This macro is used to set the default value of cnt */
end_comment

begin_define
define|#
directive|define
name|DEFAULT
parameter_list|(
name|val
parameter_list|)
value|if (cnt< 1) cnt = (val)
end_define

begin_comment
comment|/* These are used to minimize calls to fetchline() */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|plen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* length of the line */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|pline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line number that len refers to */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|pchgs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "changes" level that len refers to */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ptext
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* text of previous line, if valid */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|pfetch
name|P_
argument_list|(
operator|(
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|digraph
name|P_
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is used to build a MARK that corresponds to a specific point in the  * line that was most recently pfetch'ed.  */
end_comment

begin_define
define|#
directive|define
name|buildmark
parameter_list|(
name|text
parameter_list|)
value|(MARK)(BLKSIZE * pline + (int)((text) - ptext))
end_define

begin_comment
comment|/*------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* These are used to handle EX commands.				  */
end_comment

begin_define
define|#
directive|define
name|CMD_NULL
value|0
end_define

begin_comment
comment|/* NOT A VALID COMMAND */
end_comment

begin_define
define|#
directive|define
name|CMD_ABBR
value|1
end_define

begin_comment
comment|/* "define an abbreviation" */
end_comment

begin_define
define|#
directive|define
name|CMD_ARGS
value|2
end_define

begin_comment
comment|/* "show me the args" */
end_comment

begin_define
define|#
directive|define
name|CMD_APPEND
value|3
end_define

begin_comment
comment|/* "insert lines after this line" */
end_comment

begin_define
define|#
directive|define
name|CMD_AT
value|4
end_define

begin_comment
comment|/* "execute a cut buffer's contents via EX" */
end_comment

begin_define
define|#
directive|define
name|CMD_BANG
value|5
end_define

begin_comment
comment|/* "run a single shell command" */
end_comment

begin_define
define|#
directive|define
name|CMD_CC
value|6
end_define

begin_comment
comment|/* "run `cc` and then do CMD_ERRLIST" */
end_comment

begin_define
define|#
directive|define
name|CMD_CD
value|7
end_define

begin_comment
comment|/* "change directories" */
end_comment

begin_define
define|#
directive|define
name|CMD_CHANGE
value|8
end_define

begin_comment
comment|/* "change some lines" */
end_comment

begin_define
define|#
directive|define
name|CMD_COLOR
value|9
end_define

begin_comment
comment|/* "change the default colors" */
end_comment

begin_define
define|#
directive|define
name|CMD_COPY
value|10
end_define

begin_comment
comment|/* "copy the selected text to a given place" */
end_comment

begin_define
define|#
directive|define
name|CMD_DELETE
value|11
end_define

begin_comment
comment|/* "delete the selected text" */
end_comment

begin_define
define|#
directive|define
name|CMD_DIGRAPH
value|12
end_define

begin_comment
comment|/* "add a digraph, or display them all" */
end_comment

begin_define
define|#
directive|define
name|CMD_EDIT
value|13
end_define

begin_comment
comment|/* "switch to a different file" */
end_comment

begin_define
define|#
directive|define
name|CMD_EQUAL
value|14
end_define

begin_comment
comment|/* "display a line number" */
end_comment

begin_define
define|#
directive|define
name|CMD_ERRLIST
value|15
end_define

begin_comment
comment|/* "locate the next error in a list" */
end_comment

begin_define
define|#
directive|define
name|CMD_FILE
value|16
end_define

begin_comment
comment|/* "show the file's status" */
end_comment

begin_define
define|#
directive|define
name|CMD_GLOBAL
value|17
end_define

begin_comment
comment|/* "globally search& do a command" */
end_comment

begin_define
define|#
directive|define
name|CMD_INSERT
value|18
end_define

begin_comment
comment|/* "insert lines before the current line" */
end_comment

begin_define
define|#
directive|define
name|CMD_JOIN
value|19
end_define

begin_comment
comment|/* "join the selected line& the one after" */
end_comment

begin_define
define|#
directive|define
name|CMD_LIST
value|20
end_define

begin_comment
comment|/* "print lines, making control chars visible" */
end_comment

begin_define
define|#
directive|define
name|CMD_MAKE
value|21
end_define

begin_comment
comment|/* "run `make` and then do CMD_ERRLIST" */
end_comment

begin_define
define|#
directive|define
name|CMD_MAP
value|22
end_define

begin_comment
comment|/* "adjust the keyboard map" */
end_comment

begin_define
define|#
directive|define
name|CMD_MARK
value|23
end_define

begin_comment
comment|/* "mark this line" */
end_comment

begin_define
define|#
directive|define
name|CMD_MKEXRC
value|24
end_define

begin_comment
comment|/* "make a .exrc file" */
end_comment

begin_define
define|#
directive|define
name|CMD_MOVE
value|25
end_define

begin_comment
comment|/* "move the selected text to a given place" */
end_comment

begin_define
define|#
directive|define
name|CMD_NEXT
value|26
end_define

begin_comment
comment|/* "switch to next file in args" */
end_comment

begin_define
define|#
directive|define
name|CMD_NUMBER
value|27
end_define

begin_comment
comment|/* "print lines from the file w/ line numbers" */
end_comment

begin_define
define|#
directive|define
name|CMD_POP
value|28
end_define

begin_comment
comment|/* "pop a position off the tagstack" */
end_comment

begin_define
define|#
directive|define
name|CMD_PRESERVE
value|29
end_define

begin_comment
comment|/* "act as though vi crashed" */
end_comment

begin_define
define|#
directive|define
name|CMD_PREVIOUS
value|30
end_define

begin_comment
comment|/* "switch to the previous file in args" */
end_comment

begin_define
define|#
directive|define
name|CMD_PRINT
value|31
end_define

begin_comment
comment|/* "print the selected text" */
end_comment

begin_define
define|#
directive|define
name|CMD_PUT
value|32
end_define

begin_comment
comment|/* "insert any cut lines before this line" */
end_comment

begin_define
define|#
directive|define
name|CMD_QUIT
value|33
end_define

begin_comment
comment|/* "quit without writing the file" */
end_comment

begin_define
define|#
directive|define
name|CMD_READ
value|34
end_define

begin_comment
comment|/* "append the given file after this line */
end_comment

begin_define
define|#
directive|define
name|CMD_RECOVER
value|35
end_define

begin_comment
comment|/* "recover file after vi crashes" - USE -r FLAG */
end_comment

begin_define
define|#
directive|define
name|CMD_REWIND
value|36
end_define

begin_comment
comment|/* "rewind to first file" */
end_comment

begin_define
define|#
directive|define
name|CMD_SET
value|37
end_define

begin_comment
comment|/* "set a variable's value" */
end_comment

begin_define
define|#
directive|define
name|CMD_SHELL
value|38
end_define

begin_comment
comment|/* "run some lines through a command" */
end_comment

begin_define
define|#
directive|define
name|CMD_SHIFTL
value|39
end_define

begin_comment
comment|/* "shift lines left" */
end_comment

begin_define
define|#
directive|define
name|CMD_SHIFTR
value|40
end_define

begin_comment
comment|/* "shift lines right" */
end_comment

begin_define
define|#
directive|define
name|CMD_SOURCE
value|41
end_define

begin_comment
comment|/* "interpret a file's contents as ex commands" */
end_comment

begin_define
define|#
directive|define
name|CMD_STOP
value|42
end_define

begin_comment
comment|/* same as CMD_SUSPEND */
end_comment

begin_define
define|#
directive|define
name|CMD_SUBAGAIN
value|43
end_define

begin_comment
comment|/* "repeat the previous substitution" */
end_comment

begin_define
define|#
directive|define
name|CMD_SUBSTITUTE
value|44
end_define

begin_comment
comment|/* "substitute text in this line" */
end_comment

begin_define
define|#
directive|define
name|CMD_SUSPEND
value|45
end_define

begin_comment
comment|/* "suspend the vi session" */
end_comment

begin_define
define|#
directive|define
name|CMD_TR
value|46
end_define

begin_comment
comment|/* "transliterate chars in the selected lines" */
end_comment

begin_define
define|#
directive|define
name|CMD_TAG
value|47
end_define

begin_comment
comment|/* "go to a particular tag" */
end_comment

begin_define
define|#
directive|define
name|CMD_UNABBR
value|48
end_define

begin_comment
comment|/* "remove an abbreviation definition" */
end_comment

begin_define
define|#
directive|define
name|CMD_UNDO
value|49
end_define

begin_comment
comment|/* "undo the previous command" */
end_comment

begin_define
define|#
directive|define
name|CMD_UNMAP
value|50
end_define

begin_comment
comment|/* "remove a key sequence map */
end_comment

begin_define
define|#
directive|define
name|CMD_VERSION
value|51
end_define

begin_comment
comment|/* "describe which version this is" */
end_comment

begin_define
define|#
directive|define
name|CMD_VGLOBAL
value|52
end_define

begin_comment
comment|/* "apply a cmd to lines NOT containing an RE" */
end_comment

begin_define
define|#
directive|define
name|CMD_VISUAL
value|53
end_define

begin_comment
comment|/* "go into visual mode" */
end_comment

begin_define
define|#
directive|define
name|CMD_WQUIT
value|54
end_define

begin_comment
comment|/* "write this file out (any case)& quit" */
end_comment

begin_define
define|#
directive|define
name|CMD_WRITE
value|55
end_define

begin_comment
comment|/* "write the selected(?) text to a given file" */
end_comment

begin_define
define|#
directive|define
name|CMD_XIT
value|56
end_define

begin_comment
comment|/* "write this file out (if modified)& quit" */
end_comment

begin_define
define|#
directive|define
name|CMD_YANK
value|57
end_define

begin_comment
comment|/* "copy the selected text into the cut buffer" */
end_comment

begin_define
define|#
directive|define
name|CMD_DEBUG
value|58
end_define

begin_comment
comment|/* access to internal data structures */
end_comment

begin_define
define|#
directive|define
name|CMD_VALIDATE
value|59
end_define

begin_comment
comment|/* check for internal consistency */
end_comment

begin_typedef
typedef|typedef
name|int
name|CMD
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|void
name|ex
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|vi
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|doexcmd
name|P_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cmd_append
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cmd_args
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NO_AT
end_ifndef

begin_decl_stmt
specifier|extern
name|void
name|cmd_at
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|cmd_cd
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NO_COLOR
end_ifndef

begin_decl_stmt
specifier|extern
name|void
name|cmd_color
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|cmd_delete
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NO_DIGRAPH
end_ifndef

begin_decl_stmt
specifier|extern
name|void
name|cmd_digraph
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|cmd_edit
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NO_ERRLIST
end_ifndef

begin_decl_stmt
specifier|extern
name|void
name|cmd_errlist
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|cmd_file
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cmd_global
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cmd_join
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cmd_mark
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NO_ERRLIST
end_ifndef

begin_decl_stmt
specifier|extern
name|void
name|cmd_make
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|cmd_map
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NO_MKEXRC
end_ifndef

begin_decl_stmt
specifier|extern
name|void
name|cmd_mkexrc
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|cmd_next
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NO_TAGSTACK
end_ifndef

begin_decl_stmt
specifier|extern
name|void
name|cmd_pop
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|cmd_print
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cmd_put
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cmd_read
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cmd_set
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cmd_shell
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cmd_shift
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cmd_source
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cmd_substitute
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cmd_tag
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cmd_undo
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cmd_version
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cmd_write
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cmd_xit
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cmd_move
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|cmd_debug
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cmd_validate
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SIGTSTP
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|cmd_suspend
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|,
name|CMD
operator|,
name|int
operator|,
name|char
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
comment|/*----------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* These are used to handle VI commands 				*/
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_1ex
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* : */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_mark
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* m */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_quit
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Q */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_redraw
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ^L ^R */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_ulcase
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ~ */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_undo
name|P_
argument_list|(
operator|(
name|MARK
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* u */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_xchar
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* x X */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_replace
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* r */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_overtype
name|P_
argument_list|(
operator|(
name|MARK
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* R */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_selcut
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* " */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_paste
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* p P */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_yank
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* y Y */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_delete
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* d D */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_join
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* J */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_insert
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a A i I o O */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_change
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* c C */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_subst
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* s */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_lshift
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*< */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_rshift
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*> */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_reformat
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* = */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_filter
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ! */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_status
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ^G */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_switch
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ^^ */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_tag
name|P_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|MARK
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ^] */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_xit
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ZZ */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_undoline
name|P_
argument_list|(
operator|(
name|MARK
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* U */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_again
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*& */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_EXTENSIONS
end_ifndef

begin_decl_stmt
specifier|extern
name|MARK
name|v_keyword
name|P_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|MARK
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* K */
end_comment

begin_decl_stmt
specifier|extern
name|MARK
name|v_increment
name|P_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|MARK
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* * */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_ERRLIST
end_ifndef

begin_decl_stmt
specifier|extern
name|MARK
name|v_errlist
name|P_
argument_list|(
operator|(
name|MARK
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* * */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_AT
end_ifndef

begin_decl_stmt
specifier|extern
name|MARK
name|v_at
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* @ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SIGTSTP
end_ifdef

begin_decl_stmt
specifier|extern
name|MARK
name|v_suspend
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ^Z */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_POPUP
end_ifndef

begin_decl_stmt
specifier|extern
name|MARK
name|v_popup
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|MARK
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* \ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_TAGSTACK
end_ifndef

begin_decl_stmt
specifier|extern
name|MARK
name|v_pop
name|P_
argument_list|(
operator|(
name|MARK
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ^T */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*----------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* These flags describe the quirks of the individual visual commands */
end_comment

begin_define
define|#
directive|define
name|NO_FLAGS
value|0x00
end_define

begin_define
define|#
directive|define
name|MVMT
value|0x01
end_define

begin_comment
comment|/* this is a movement command */
end_comment

begin_define
define|#
directive|define
name|PTMV
value|0x02
end_define

begin_comment
comment|/* this can be *part* of a movement command */
end_comment

begin_define
define|#
directive|define
name|FRNT
value|0x04
end_define

begin_comment
comment|/* after move, go to front of line */
end_comment

begin_define
define|#
directive|define
name|INCL
value|0x08
end_define

begin_comment
comment|/* include last char when used with c/d/y */
end_comment

begin_define
define|#
directive|define
name|LNMD
value|0x10
end_define

begin_comment
comment|/* use line mode of c/d/y */
end_comment

begin_define
define|#
directive|define
name|NCOL
value|0x20
end_define

begin_comment
comment|/* this command can't change the column# */
end_comment

begin_define
define|#
directive|define
name|NREL
value|0x40
end_define

begin_comment
comment|/* this is "non-relative" -- set the '' mark */
end_comment

begin_define
define|#
directive|define
name|SDOT
value|0x80
end_define

begin_comment
comment|/* set the "dot" variables, for the "." cmd */
end_comment

begin_define
define|#
directive|define
name|FINL
value|0x100
end_define

begin_comment
comment|/* final testing, more strict! */
end_comment

begin_define
define|#
directive|define
name|NWRP
value|0x200
end_define

begin_comment
comment|/* no line-wrap (used for 'w' and 'W') */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_VISIBLE
end_ifndef

begin_define
define|#
directive|define
name|VIZ
value|0x400
end_define

begin_comment
comment|/* commands which can be used with 'v' */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VIZ
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This variable is zeroed before a command executes, and later ORed with the  * command's flags after the command has been executed.  It is used to force  * certain flags to be TRUE for *some* invocations of a particular command.  * For example, "/regexp/+offset" forces the LNMD flag, and sometimes a "p"  * or "P" command will force FRNT.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|force_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*----------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* These describe what mode we're in */
end_comment

begin_define
define|#
directive|define
name|MODE_EX
value|1
end_define

begin_comment
comment|/* executing ex commands */
end_comment

begin_define
define|#
directive|define
name|MODE_VI
value|2
end_define

begin_comment
comment|/* executing vi commands */
end_comment

begin_define
define|#
directive|define
name|MODE_COLON
value|3
end_define

begin_comment
comment|/* executing an ex command from vi mode */
end_comment

begin_define
define|#
directive|define
name|MODE_QUIT
value|4
end_define

begin_decl_stmt
specifier|extern
name|int
name|mode
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|WHEN_VICMD
value|1
end_define

begin_comment
comment|/* getkey: we're reading a VI command */
end_comment

begin_define
define|#
directive|define
name|WHEN_VIINP
value|2
end_define

begin_comment
comment|/* getkey: we're in VI's INPUT mode */
end_comment

begin_define
define|#
directive|define
name|WHEN_VIREP
value|4
end_define

begin_comment
comment|/* getkey: we're in VI's REPLACE mode */
end_comment

begin_define
define|#
directive|define
name|WHEN_EX
value|8
end_define

begin_comment
comment|/* getkey: we're in EX mode */
end_comment

begin_define
define|#
directive|define
name|WHEN_MSG
value|16
end_define

begin_comment
comment|/* getkey: we're at a "more" prompt */
end_comment

begin_define
define|#
directive|define
name|WHEN_POPUP
value|32
end_define

begin_comment
comment|/* getkey: we're in the pop-up menu */
end_comment

begin_define
define|#
directive|define
name|WHEN_REP1
value|64
end_define

begin_comment
comment|/* getkey: we're getting a single char for 'r' */
end_comment

begin_define
define|#
directive|define
name|WHEN_CUT
value|128
end_define

begin_comment
comment|/* getkey: we're getting a cut buffer name */
end_comment

begin_define
define|#
directive|define
name|WHEN_MARK
value|256
end_define

begin_comment
comment|/* getkey: we're getting a mark name */
end_comment

begin_define
define|#
directive|define
name|WHEN_CHAR
value|512
end_define

begin_comment
comment|/* getkey: we're getting a destination for f/F/t/T */
end_comment

begin_define
define|#
directive|define
name|WHEN_INMV
value|4096
end_define

begin_comment
comment|/* in input mode, interpret the key in VICMD mode */
end_comment

begin_define
define|#
directive|define
name|WHEN_FREE
value|8192
end_define

begin_comment
comment|/* free the keymap after doing it once */
end_comment

begin_define
define|#
directive|define
name|WHENMASK
value|(WHEN_VICMD|WHEN_VIINP|WHEN_VIREP|WHEN_REP1|WHEN_CUT|WHEN_MARK|WHEN_CHAR)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_VISIBLE
end_ifndef

begin_decl_stmt
specifier|extern
name|MARK
name|V_from
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|V_linemd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MARK
name|v_start
name|P_
argument_list|(
operator|(
name|MARK
name|m
operator|,
name|long
name|cnt
operator|,
name|int
name|cmd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|malloc
parameter_list|(
name|size
parameter_list|)
value|dbmalloc(size, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|free
parameter_list|(
name|ptr
parameter_list|)
value|dbfree(ptr, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|checkmem
parameter_list|()
value|dbcheckmem(__FILE__, __LINE__)
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dbmalloc
name|P_
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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|checkmem
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

