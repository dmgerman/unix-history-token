begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *      DEFS.H  *      UTREE global definitions.  *      3.01-um klin, Tue Jun  4 14:16:55 1991  *              klin, Tue Oct 15 14:01:57 1991, Handling of symlinks changed  *              klin, Sat Oct 26 15:27:40 1991, Some additions  *      3.02-um klin, Fri Nov  1 10:43:31 1991, Screen layout changed  *              klin, Sun Nov 24 19:30:43 1991, Cd to current directory before  *                                              executing some commands  *      3.03-um klin, Sat Jan 11 19:53:57 1992, Generic list glist added  *                                              List definitions to list.h  *                                              Line editor extended  *              klin, Sat Feb 15 19:18:06 1992, Display attributes added  *                                              Partinioning of directory and  *                                              file windows on tree screen  *                                              changed  *              klin, Sun Feb 23 18:16:24 1992, Key handlings and key bindings  *                                              changed  *            e klin, Sat Apr 11 11:05:54 1992, Use colors for video attributes  *  *      Copyright (c) 1991/92 by Peter Klingebiel& UNIX Magazin Muenchen.  *      For copying and distribution information see the file COPYRIGHT.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MAIN_
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid_defs
index|[]
init|=
literal|"@(#) utree 3.03e-um (klin) Apr 11 1992 defs.h"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MAIN_&& !lint */
end_comment

begin_comment
comment|/*  *      Global and local include files.  */
end_comment

begin_include
include|#
directive|include
file|"conf.h"
end_include

begin_comment
comment|/* Configurable definitions             */
end_comment

begin_include
include|#
directive|include
file|"cmds.h"
end_include

begin_comment
comment|/* System commands definitions          */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SYSV */
end_comment

begin_include
include|#
directive|include
file|<sys/sysmacros.h>
end_include

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NODIRENT
end_ifdef

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !NODIRENT */
end_comment

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NODIRENT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<grp.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NULL
end_ifdef

begin_comment
comment|/* Reset the standard NULL definition   */
end_comment

begin_undef
undef|#
directive|undef
name|NULL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NULL */
end_comment

begin_define
define|#
directive|define
name|NULL
value|((char *) 0)
end_define

begin_comment
comment|/* The string NIL pointer               */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NOWINCHG
end_ifdef

begin_undef
undef|#
directive|undef
name|SIGWINCH
end_undef

begin_undef
undef|#
directive|undef
name|TIOCGWINSZ
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOWINCHG */
end_comment

begin_comment
comment|/*  *      Definitions for utree which should not be changed.  */
end_comment

begin_comment
comment|/* Buffer size definitions to avoid too often alloc() and free()        */
end_comment

begin_define
define|#
directive|define
name|NBUFSZ
value|1024
end_define

begin_comment
comment|/* Filename buffer size                 */
end_comment

begin_define
define|#
directive|define
name|NFILES
value|64
end_define

begin_comment
comment|/* Filename vector size (= NBUFSZ/16)   */
end_comment

begin_define
define|#
directive|define
name|NBUFINC
value|512
end_define

begin_comment
comment|/* Filename buffer increment            */
end_comment

begin_define
define|#
directive|define
name|NFILINC
value|32
end_define

begin_comment
comment|/* Filename vector incr (= NBUFINC/16)  */
end_comment

begin_comment
comment|/* Other global definitions                                             */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_define
define|#
directive|define
name|NAMELEN
value|256
end_define

begin_comment
comment|/* Max length of pathnames              */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !MAXPATHLEN */
end_comment

begin_define
define|#
directive|define
name|NAMELEN
value|MAXPATHLEN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAXPATHLEN */
end_comment

begin_define
define|#
directive|define
name|FILELEN
value|256
end_define

begin_comment
comment|/* Max input length of filenames        */
end_comment

begin_define
define|#
directive|define
name|INPLEN
value|256
end_define

begin_comment
comment|/* Often used input buffer length       */
end_comment

begin_define
define|#
directive|define
name|PATLEN
value|256
end_define

begin_comment
comment|/* Search pattern length                */
end_comment

begin_define
define|#
directive|define
name|FNAMSZ
value|16
end_define

begin_comment
comment|/* Max filename length on screen        */
end_comment

begin_define
define|#
directive|define
name|FWINSZ
value|20
end_define

begin_comment
comment|/* Filename width in window             */
end_comment

begin_define
define|#
directive|define
name|USERCMD
value|10
end_define

begin_comment
comment|/* # of user defined commands           */
end_comment

begin_define
define|#
directive|define
name|MININD
value|3
end_define

begin_comment
comment|/* Minimal tree indention               */
end_comment

begin_define
define|#
directive|define
name|MAXIND
value|9
end_define

begin_comment
comment|/* Maximal tree indention               */
end_comment

begin_define
define|#
directive|define
name|MINFIL
value|1
end_define

begin_comment
comment|/* Minimal number of file lines         */
end_comment

begin_define
define|#
directive|define
name|MAXFIL
value|9
end_define

begin_comment
comment|/* Maximal number of file lines         */
end_comment

begin_define
define|#
directive|define
name|DEFFIL
value|3
end_define

begin_comment
comment|/* Default number of file lines         */
end_comment

begin_define
define|#
directive|define
name|VMODE0
value|0
end_define

begin_comment
comment|/* Minimal video mode: no attributes    */
end_comment

begin_define
define|#
directive|define
name|VMODE1
value|1
end_define

begin_comment
comment|/* Middle video mode: reverse+underline */
end_comment

begin_define
define|#
directive|define
name|VMODE2
value|2
end_define

begin_comment
comment|/* Maximal video mode: all attributes   */
end_comment

begin_define
define|#
directive|define
name|HLEVEL
value|9999
end_define

begin_comment
comment|/* Huge number for tree level           */
end_comment

begin_define
define|#
directive|define
name|EXECLEN
value|(2*NAMELEN)
end_define

begin_comment
comment|/* Command buffer length                */
end_comment

begin_define
define|#
directive|define
name|HLMIN
value|6
end_define

begin_comment
comment|/* Minimal size of history list         */
end_comment

begin_define
define|#
directive|define
name|HLMAX
value|99
end_define

begin_comment
comment|/* Maximal size of history list         */
end_comment

begin_define
define|#
directive|define
name|HLDEF
value|22
end_define

begin_comment
comment|/* Default size of history list         */
end_comment

begin_comment
comment|/* Return values for many functions                                     */
end_comment

begin_define
define|#
directive|define
name|RV_OK
value|IN_OK
end_define

begin_comment
comment|/* Work is done         (See keys.h)    */
end_comment

begin_define
define|#
directive|define
name|RV_NUL
value|IN_NUL
end_define

begin_comment
comment|/* No input             (See keys.h)    */
end_comment

begin_define
define|#
directive|define
name|RV_INT
value|IN_INT
end_define

begin_comment
comment|/* Break                (See keys.h)    */
end_comment

begin_define
define|#
directive|define
name|RV_END
value|IN_EOF
end_define

begin_comment
comment|/* EOF                  (See keys.h)    */
end_comment

begin_define
define|#
directive|define
name|RV_HLP
value|IN_HLP
end_define

begin_comment
comment|/* Help requested       (See keys.h)    */
end_comment

begin_define
define|#
directive|define
name|RV_NXT
value|IN_NXT
end_define

begin_comment
comment|/* Next requested       (See keys.h)    */
end_comment

begin_define
define|#
directive|define
name|RV_PRV
value|IN_PRV
end_define

begin_comment
comment|/* Prev requested       (See keys.h)    */
end_comment

begin_define
define|#
directive|define
name|RV_SIZ
value|IN_SIZ
end_define

begin_comment
comment|/* Screen size changed  (See keys.h)    */
end_comment

begin_define
define|#
directive|define
name|RV_DIR
value|-11
end_define

begin_comment
comment|/* Change directory                     */
end_comment

begin_define
define|#
directive|define
name|RV_RET
value|-12
end_define

begin_comment
comment|/* Return from file menu                */
end_comment

begin_define
define|#
directive|define
name|RV_ERR
value|-13
end_define

begin_comment
comment|/* Memory error                         */
end_comment

begin_comment
comment|/*  *      Generic list type for scrolling in lists.  *      Is a component in many other list types.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_glist
block|{
name|char
modifier|*
name|string
decl_stmt|;
comment|/*  General used string                 */
name|struct
name|_glist
modifier|*
name|prev
decl_stmt|;
comment|/*  Previous element in list            */
name|struct
name|_glist
modifier|*
name|next
decl_stmt|;
comment|/*  Next element in list                */
block|}
name|glist
typedef|;
end_typedef

begin_define
define|#
directive|define
name|GNULL
value|((glist *) 0)
end_define

begin_comment
comment|/* The glist NIL pointer                */
end_comment

begin_comment
comment|/*  *      Access to items of glist record is done with macros  *      to hide this record and for abbreviation.  */
end_comment

begin_define
define|#
directive|define
name|GNAME
parameter_list|(
name|p
parameter_list|)
value|((p)->string)
end_define

begin_define
define|#
directive|define
name|GPREV
parameter_list|(
name|p
parameter_list|)
value|((p)->prev)
end_define

begin_define
define|#
directive|define
name|GNEXT
parameter_list|(
name|p
parameter_list|)
value|((p)->next)
end_define

begin_include
include|#
directive|include
file|"list.h"
end_include

begin_comment
comment|/* Directory/file list definitions      */
end_comment

begin_include
include|#
directive|include
file|"hist.h"
end_include

begin_comment
comment|/* History list definitons              */
end_comment

begin_include
include|#
directive|include
file|"vars.h"
end_include

begin_comment
comment|/* Variable/command definitions         */
end_comment

begin_include
include|#
directive|include
file|"help.h"
end_include

begin_comment
comment|/* Help page definitions                */
end_comment

begin_include
include|#
directive|include
file|"term.h"
end_include

begin_comment
comment|/* Terminal/screen definitions          */
end_comment

begin_include
include|#
directive|include
file|"keys.h"
end_include

begin_comment
comment|/* Key definitions                      */
end_comment

begin_comment
comment|/*  *      Screen update flags.  */
end_comment

begin_define
define|#
directive|define
name|SF_TREE
value|0x0001
end_define

begin_comment
comment|/* Update tree/file window              */
end_comment

begin_define
define|#
directive|define
name|SF_LIST
value|0x0002
end_define

begin_comment
comment|/* Update current list entry            */
end_comment

begin_define
define|#
directive|define
name|SF_LAST
value|0x0004
end_define

begin_comment
comment|/* Update last list entry               */
end_comment

begin_define
define|#
directive|define
name|SF_SEPL
value|0x0008
end_define

begin_comment
comment|/* Update separator line                */
end_comment

begin_define
define|#
directive|define
name|SF_HELP
value|0x0010
end_define

begin_comment
comment|/* Update help line                     */
end_comment

begin_define
define|#
directive|define
name|SF_ECHO
value|0x0020
end_define

begin_comment
comment|/* Update echo line                     */
end_comment

begin_define
define|#
directive|define
name|SF_MOVE
value|0x0040
end_define

begin_comment
comment|/* Update cursor position               */
end_comment

begin_define
define|#
directive|define
name|SF_FILE
value|0x0080
end_define

begin_comment
comment|/* Update file window on tree screen    */
end_comment

begin_define
define|#
directive|define
name|SF_PBAR
value|0x0100
end_define

begin_comment
comment|/* Update position bar                  */
end_comment

begin_define
define|#
directive|define
name|SF_FULL
value|0xffff
end_define

begin_comment
comment|/* Full update                          */
end_comment

begin_comment
comment|/*  *      Display attribute flags.  */
end_comment

begin_define
define|#
directive|define
name|DA_NONE
value|0
end_define

begin_comment
comment|/* No attributes                        */
end_comment

begin_define
define|#
directive|define
name|DA_NORMAL
value|0
end_define

begin_comment
comment|/* Reset to normal state                */
end_comment

begin_define
define|#
directive|define
name|DA_REVERSE
value|1
end_define

begin_comment
comment|/* Reverse                              */
end_comment

begin_define
define|#
directive|define
name|DA_BOLD
value|2
end_define

begin_comment
comment|/* Highlight                            */
end_comment

begin_define
define|#
directive|define
name|DA_HALF
value|3
end_define

begin_comment
comment|/* Hide                                 */
end_comment

begin_define
define|#
directive|define
name|DA_ERROR
value|4
end_define

begin_comment
comment|/* Error                                */
end_comment

begin_define
define|#
directive|define
name|DA_MARK
value|5
end_define

begin_comment
comment|/* Special mark in menu line            */
end_comment

begin_define
define|#
directive|define
name|DA_BOLDREV
value|6
end_define

begin_comment
comment|/* Reverse highlight                    */
end_comment

begin_define
define|#
directive|define
name|DA_HALFREV
value|7
end_define

begin_comment
comment|/* Reverse hide                         */
end_comment

begin_define
define|#
directive|define
name|DA_BLINKREV
value|8
end_define

begin_comment
comment|/* Reverse blink                        */
end_comment

begin_comment
comment|/*  *      Some other useful definitions and macros.  */
end_comment

begin_define
define|#
directive|define
name|GLOBL
end_define

begin_define
define|#
directive|define
name|LOCAL
value|static
end_define

begin_define
define|#
directive|define
name|EXTRN
value|extern
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SIGNL
end_ifndef

begin_define
define|#
directive|define
name|SIGNL
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIGNL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_comment
comment|/* Don't disturb lint !                 */
end_comment

begin_define
define|#
directive|define
name|VOID
value|int
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !lint */
end_comment

begin_define
define|#
directive|define
name|VOID
value|void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_define
define|#
directive|define
name|EQU
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp(s1, s2) == 0)
end_define

begin_define
define|#
directive|define
name|CMP
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp(s1, s2))
end_define

begin_comment
comment|/* Get type of file pointed to by struct stat s                         */
end_comment

begin_define
define|#
directive|define
name|STFMT
parameter_list|(
name|s
parameter_list|)
value|((s)->st_mode& S_IFMT)
end_define

begin_comment
comment|/* Check if file f is a directory                                       */
end_comment

begin_define
define|#
directive|define
name|ISDIR
parameter_list|(
name|f
parameter_list|,
name|s
parameter_list|)
value|((*statfun)(f,&s) == 0&& STFMT(&s) == S_IFDIR)
end_define

begin_comment
comment|/* Check if file f is a block special file                              */
end_comment

begin_define
define|#
directive|define
name|ISBLK
parameter_list|(
name|f
parameter_list|,
name|s
parameter_list|)
value|((*statfun)(f,&s) == 0&& STFMT(&s) == S_IFBLK)
end_define

begin_comment
comment|/* Line is not empty and not a comment                                  */
end_comment

begin_define
define|#
directive|define
name|VALID
parameter_list|(
name|c
parameter_list|)
value|( !(c=='\0' || c=='\n' || c=='#' || c==' ' || c=='\t'))
end_define

begin_comment
comment|/* Can we change to directory p?                                        */
end_comment

begin_define
define|#
directive|define
name|CANCD
parameter_list|(
name|p
parameter_list|)
value|(access(p, 01) == 0)
end_define

begin_comment
comment|/* Can we scroll a window and are we allowed to do this?                */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USEANSICOLORS
end_ifdef

begin_define
define|#
directive|define
name|CANSCROLL
value|(scrollcap&& VARSET(V_TS)&& (!colorcap || !usecolors))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !USEANSICOLORS */
end_comment

begin_define
define|#
directive|define
name|CANSCROLL
value|(scrollcap&& VARSET(V_TS))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USEANSICOLORS */
end_comment

begin_comment
comment|/*  *      External system variables.  */
end_comment

begin_decl_stmt
name|EXTRN
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* System error code number             */
end_comment

begin_comment
comment|/*  *      Global variables declared in main.c.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MAIN_
end_ifndef

begin_decl_stmt
name|EXTRN
name|char
modifier|*
name|prgname
decl_stmt|,
modifier|*
name|home
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTRN
name|int
name|helpline
decl_stmt|,
name|echoline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTRN
name|int
name|firstdline
decl_stmt|,
name|lastdline
decl_stmt|,
name|ndlines
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTRN
name|int
name|firstfline
decl_stmt|,
name|lastfline
decl_stmt|,
name|nflines
decl_stmt|,
name|maxnflines
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTRN
name|int
name|firstline
decl_stmt|,
name|lastline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTRN
name|int
name|indent
decl_stmt|,
name|maxindent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTRN
name|int
name|videomode
decl_stmt|,
name|videoattr
decl_stmt|,
name|graphattr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTRN
name|int
name|maxlevel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTRN
name|int
name|filecount
decl_stmt|,
name|dircount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTRN
name|int
name|treeflag
decl_stmt|,
name|fileflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTRN
name|int
name|buildflag
decl_stmt|,
name|writeflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTRN
name|int
name|sortbytime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTRN
name|int
name|hiddendirs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTRN
name|int
name|sizechange
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|USEANSICOLORS
end_ifdef

begin_decl_stmt
name|EXTRN
name|int
name|usecolors
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXTRN
name|dlist
modifier|*
name|droot
decl_stmt|,
modifier|*
name|cdlist
decl_stmt|,
modifier|*
name|cwlist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTRN
name|int
name|fperpage
decl_stmt|,
name|fperline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTRN
name|char
name|rootdir
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTRN
name|char
name|fpattern
index|[]
decl_stmt|,
name|gpattern
index|[]
decl_stmt|,
name|tpattern
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTRN
name|char
name|utreemenu
index|[]
decl_stmt|,
name|ufilemenu
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXTRN
name|int
function_decl|(
modifier|*
name|statfun
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_decl_stmt
name|EXTRN
name|jmp_buf
name|winchjump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTRN
name|int
name|atread
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

begin_decl_stmt
name|EXTRN
name|char
modifier|*
name|who
decl_stmt|,
modifier|*
name|hitkey
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MAIN_ */
end_comment

begin_comment
comment|/*  *      Declaration of library and internal utree functions.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFLNK
end_ifdef

begin_decl_stmt
name|EXTRN
name|int
name|stat
argument_list|()
decl_stmt|,
name|lstat
argument_list|()
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! S_IFLNK */
end_comment

begin_define
define|#
directive|define
name|lstat
value|stat
end_define

begin_function_decl
name|EXTRN
name|int
name|stat
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* S_IFLNK */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_define
define|#
directive|define
name|getcwd
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|getwd(p)
end_define

begin_define
define|#
directive|define
name|strchr
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|index(s, c)
end_define

begin_define
define|#
directive|define
name|strrchr
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|rindex(s, c)
end_define

begin_define
define|#
directive|define
name|memset
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|,
name|n
parameter_list|)
value|bzero(s, n)
end_define

begin_decl_stmt
name|EXTRN
name|char
modifier|*
name|index
argument_list|()
decl_stmt|,
modifier|*
name|rindex
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXTRN
name|DIR
modifier|*
name|opendir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|EXTRN
name|struct
name|direct
modifier|*
name|readdir
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SYSV */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NODIRENT
end_ifdef

begin_define
define|#
directive|define
name|DIR
value|FILE
end_define

begin_define
define|#
directive|define
name|opendir
parameter_list|(
name|n
parameter_list|)
value|fopen(n, "r")
end_define

begin_define
define|#
directive|define
name|closedir
parameter_list|(
name|p
parameter_list|)
value|fclose(p)
end_define

begin_define
define|#
directive|define
name|rewinddir
parameter_list|(
name|p
parameter_list|)
value|rewind(p)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !NODIRENT */
end_comment

begin_function_decl
name|EXTRN
name|DIR
modifier|*
name|opendir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|EXTRN
name|struct
name|dirent
modifier|*
name|readdir
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NODIRENT */
end_comment

begin_decl_stmt
name|EXTRN
name|char
modifier|*
name|strchr
argument_list|()
decl_stmt|,
modifier|*
name|strrchr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

begin_decl_stmt
name|EXTRN
name|char
modifier|*
name|strcpy
argument_list|()
decl_stmt|,
modifier|*
name|getenv
argument_list|()
decl_stmt|,
modifier|*
name|fgets
argument_list|()
decl_stmt|,
modifier|*
name|ctime
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXTRN
name|time_t
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|EXTRN
name|dlist
modifier|*
name|newdlist
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|EXTRN
name|char
modifier|*
name|ualloc
argument_list|()
decl_stmt|,
modifier|*
name|basename
argument_list|()
decl_stmt|,
modifier|*
name|pathname
argument_list|()
decl_stmt|,
modifier|*
name|fileaccess
argument_list|()
decl_stmt|,
modifier|*
name|strsav
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

