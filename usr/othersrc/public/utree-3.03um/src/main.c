begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *      MAIN.C  *      UTREE main routine.  *      3.01-um klin, Sat May  4 15:45:02 1991  *              klin, Tue Oct 15 12:26:53 1991, Option -L added  *              klin, Sat Oct 26 15:04:54 1991, writedlist() changed  *      3.02-um klin, Fri Nov  1 10:46:14 1991, Option -u changed to -n  *                                              Option -u added  *              klin, Sun Nov 10 19:37:45 1991, buildlist() changed  *              klin, Sun Nov 24 19:30:43 1991, Cd to current directory before  *                                              executing some commands  *      3.03-um klin, Tue Feb 11 22:35:55 1992, Shell command history added  *              klin, Sat Feb 15 19:18:30 1992, Video handling and option -v  *                                              changed  *                                              Partinioning of directory and  *                                              file windows changed and  *                                              option -p added  *              klin, Sun Feb 23 18:45:19 1992, Keybindings, variable AUTOSAVE  *                                              and option -o added  *            d klin, Thu Apr  2 09:07:41 1992, Handle -o  *            e klin, Sat Apr 11 11:06:20 1992, Color handling and option -C added  *  *      Copyright (c) 1991/92 by Peter Klingebiel& UNIX Magazin Muenchen.  *      For copying and distribution information see the file COPYRIGHT.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#) utree 3.03e-um (klin) Apr 11 1992 main.c"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !lint */
end_comment

begin_comment
comment|/*  *      Usage:  utree   [-CLSVabcghnoqrstuw] [-d var=[val]] [-d cmd:[typ]] [-f lst]  *                      [-f lst] [-i ind] [-l lev] [-p lin] [-v mod] [-x cmd]  *                      [rootdir]  *  *      Options:        -C              Don't use colors  *                      -L              Follow symbolic links  *                      -S              Ignore minimal screen size.  *                      -V              Display program version.  *                      -a              Read in all dirs including hidden.  *                      -b              No bell  *                      -c              No clock display/update in echoline.  *                      -d var=[val]    Define/undefine variable var.  *                      -d typ:[cmd]    Define/undefine command for type typ.  *                      -f lst          Build tree from list file lst.  *                      -g              No graphic characters.  *                      -h              Display some help about options.  *                      -i ind          Set tree indention to ind (3..9)  *                      -l lev          Build tree up to level lev.  *                      -n              No scan tree for changes.  *                      -o              Omit saving definition/history changes.  *                      -p lin          Set file window to lin lines (1..9)  *                      -q              Build tree up to level 2 (like -l 2).  *                      -r              Recreate tree list (always scan disk).  *                      -s              No hardware scrolling.  *                      -t              Sort files by modification times.  *                      -u              Update directory tree.  *                      -v mod          Set video attribute settings (0,1,2)  *                      -w              No warning about unreadable dirs.  *                      -x cmd          Use string cmd as initial input.  *                      The options bcginopsvw may also be set in the environment  *                      variable $UTREE.  *  *      Directory:      /usr/local/bin  *  *      Environment:    $EDITOR $HOME $PAGER $SHELL $TERM $UTREE $UTLIB  *  *      Files:          $UTLIB/utree.help       - Utree help pages.  *                      $UTLIB/utree            - Global startup file.  *                      $UTLIB/utree-$TERM      - Global key bindings for $TERM  *                      $HOME/.utree            - User's startupfile.  *                      $HOME/.utreelist        - User's tree list file.  *                      $HOME/.utreehist        - Shell command history.  *                      $HOME/.utree-$TERM      - Users key bindings for $TERM  *                      $PATH/utree.prlist      - Tree display program  *                      $PATH/utree.backup      - Backup shell script.  *                      $PATH/utree.mklist      - Create tree list.  *  *      Libraries:      -lcurses (SYSV), -ltermcap or -ltermlib (BSD)  *  *      Bugs:           Changes in filesystem after shell or editor escape  *                      are not always detected!  *                      Directory tree depth> 32 may confuse utree!  *                      Symbolic links to directories may confuse utree!  *                      Chown() and chgrp() for normal users on some BSD  *                      systems are not allowed!  */
end_comment

begin_define
define|#
directive|define
name|_MAIN_
end_define

begin_comment
comment|/* Declare external variables   */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_comment
comment|/* defined in header files      */
end_comment

begin_comment
comment|/* ---- Gobal variables and definitions ------------------------------- */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USEANSICOLORS
end_ifdef

begin_define
define|#
directive|define
name|USES1
value|"[-CLSVabcghnoqrstuw] [-d var=[val]] [-d cmd:[typ]] [-f lst]"
end_define

begin_define
define|#
directive|define
name|USES2
value|"[-i ind] [-l lev] [-p lin] [-v mod] [-x cmd] [rootdir]"
end_define

begin_define
define|#
directive|define
name|UOPTS
value|"CLSVabcd:f:ghi:nol:p:qrstuv:wx:"
end_define

begin_comment
comment|/* String for getopt() */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|USES1
value|"[-LSVabcghnoqrstuw] [-d var=[val]] [-d cmd:[typ]] [-f lst]"
end_define

begin_define
define|#
directive|define
name|USES2
value|"[-i ind] [-l lev] [-p lin] [-v mod] [-x cmd] [rootdir]"
end_define

begin_define
define|#
directive|define
name|UOPTS
value|"LSVabcd:f:ghi:nol:p:qrstuv:wx:"
end_define

begin_comment
comment|/* String for getopt() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USEANSICOLORS */
end_comment

begin_decl_stmt
name|GLOBL
name|int
name|helpline
decl_stmt|,
name|echoline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Help/echo lines              */
end_comment

begin_decl_stmt
name|GLOBL
name|int
name|firstline
decl_stmt|,
name|lastline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* First/last lines             */
end_comment

begin_decl_stmt
name|GLOBL
name|int
name|firstdline
decl_stmt|,
name|lastdline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* First/last tree lines        */
end_comment

begin_decl_stmt
name|GLOBL
name|int
name|ndlines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # dir lines on tree screen   */
end_comment

begin_decl_stmt
name|GLOBL
name|int
name|firstfline
decl_stmt|,
name|lastfline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* First/last file lines        */
end_comment

begin_decl_stmt
name|GLOBL
name|int
name|nflines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # file lines on tree screen  */
end_comment

begin_decl_stmt
name|GLOBL
name|int
name|maxnflines
init|=
name|DEFFIL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Max file lines               */
end_comment

begin_decl_stmt
name|GLOBL
name|int
name|fperpage
decl_stmt|,
name|fperline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Files per page/line          */
end_comment

begin_decl_stmt
name|GLOBL
name|int
name|treeflag
decl_stmt|,
name|fileflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Screen update flags          */
end_comment

begin_decl_stmt
name|GLOBL
name|int
name|filecount
decl_stmt|,
name|dircount
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of files/directories       */
end_comment

begin_decl_stmt
name|GLOBL
name|int
name|indent
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tree indention: 2..9         */
end_comment

begin_decl_stmt
name|GLOBL
name|int
name|videomode
init|=
name|VMODE2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Video mode: all attributes   */
end_comment

begin_decl_stmt
name|GLOBL
name|int
name|videoattr
init|=
name|VA_NORMAL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Video attribute              */
end_comment

begin_decl_stmt
name|GLOBL
name|int
name|graphattr
init|=
name|GC_OFF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Graphic character set flag   */
end_comment

begin_decl_stmt
name|GLOBL
name|int
name|maxindent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* User defined tree indention  */
end_comment

begin_decl_stmt
name|GLOBL
name|int
name|maxlevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current max tree level       */
end_comment

begin_decl_stmt
name|GLOBL
name|int
name|buildflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Rebuild directory flag       */
end_comment

begin_decl_stmt
name|GLOBL
name|int
name|writeflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Rewrite tree list file       */
end_comment

begin_decl_stmt
name|GLOBL
name|int
name|sortbytime
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Sort file by mod times       */
end_comment

begin_decl_stmt
name|GLOBL
name|int
name|hiddendirs
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Build up hidden directories  */
end_comment

begin_decl_stmt
name|GLOBL
name|int
name|sizechange
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Screen size changed          */
end_comment

begin_function_decl
name|GLOBL
name|int
function_decl|(
modifier|*
name|statfun
function_decl|)
parameter_list|()
init|=
name|lstat
function_decl|;
end_function_decl

begin_comment
comment|/* Follow symbolic links        */
end_comment

begin_decl_stmt
name|GLOBL
name|dlist
modifier|*
name|droot
init|=
name|DNULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Root of directory list       */
end_comment

begin_decl_stmt
name|GLOBL
name|dlist
modifier|*
name|cdlist
init|=
name|DNULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current directory list       */
end_comment

begin_decl_stmt
name|GLOBL
name|dlist
modifier|*
name|cwlist
init|=
name|DNULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current working directory    */
end_comment

begin_decl_stmt
name|GLOBL
name|char
name|fpattern
index|[
name|PATLEN
index|]
init|=
block|{
literal|'\0'
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Search pattern file search   */
end_comment

begin_decl_stmt
name|GLOBL
name|char
name|gpattern
index|[
name|PATLEN
index|]
init|=
block|{
literal|'\0'
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Search pattern file grep     */
end_comment

begin_decl_stmt
name|GLOBL
name|char
name|tpattern
index|[
name|PATLEN
index|]
init|=
block|{
literal|'\0'
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tag pattern file tag         */
end_comment

begin_decl_stmt
name|GLOBL
name|char
name|rootdir
index|[
name|NAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Root directory name          */
end_comment

begin_decl_stmt
name|GLOBL
name|char
name|utreemenu
index|[
name|MINCOLS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* User command tree menu line  */
end_comment

begin_decl_stmt
name|GLOBL
name|char
name|ufilemenu
index|[
name|MINCOLS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* User command file menu line  */
end_comment

begin_decl_stmt
name|GLOBL
name|char
modifier|*
name|prgname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Program name/version         */
end_comment

begin_decl_stmt
name|GLOBL
name|char
modifier|*
name|home
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Home directory               */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_decl_stmt
name|GLOBL
name|jmp_buf
name|winchjump
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Global goto for SIGWINCH     */
end_comment

begin_decl_stmt
name|GLOBL
name|int
name|atread
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flag if we are in getchar()  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USEANSICOLORS
end_ifdef

begin_decl_stmt
name|GLOBL
name|int
name|usecolors
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use colors if defined        */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USEANSICOLORS */
end_comment

begin_decl_stmt
name|GLOBL
name|char
modifier|*
name|who
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of current command      */
end_comment

begin_decl_stmt
name|GLOBL
name|char
modifier|*
name|hitkey
init|=
literal|"(Hit a key)"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ---- External variables and functions ------------------------------ */
end_comment

begin_decl_stmt
name|EXTRN
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From getopt()                */
end_comment

begin_decl_stmt
name|EXTRN
name|int
name|optind
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   "     "                    */
end_comment

begin_function_decl
name|EXTRN
name|char
modifier|*
name|initscreen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|EXTRN
name|int
name|exitscreen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|EXTRN
name|char
modifier|*
name|calloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|EXTRN
name|char
modifier|*
name|writedlist
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* ---- Functions and procedures -------------------------------------- */
end_comment

begin_comment
comment|/*  *      INTERNAL USED ROUTINES  */
end_comment

begin_comment
comment|/* Display usage message and some help about options if flag f is set */
end_comment

begin_function
name|LOCAL
name|VOID
name|usage
parameter_list|(
name|f
parameter_list|)
specifier|register
name|int
name|f
decl_stmt|;
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Usage:\t%s\t%s\n\t\t%s\n"
argument_list|,
name|prgname
argument_list|,
name|USES1
argument_list|,
name|USES2
argument_list|)
expr_stmt|;
if|if
condition|(
name|f
condition|)
block|{
ifdef|#
directive|ifdef
name|USEANSICOLORS
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t-C\t\tDon't use colors on color terminals\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* USEANSICOLORS */
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t-L\t\tFollow symbolic links\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t-S\t\tIgnore minimal screen size\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t-V\t\tDisplay program version\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t-a\t\tRead in all (incl hidden) directories\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t-b\t\tSuppress ringing of the bell\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t-c\t\tDon't display and update a clock\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t-d var=[val]\tSet/unset variable\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t-d typ:[cmd]\tSet/unset filetype command\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t-f lst\t\tBuild tree from list file lst\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t-g\t\tDon't use graphic characters\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t-h\t\tDisplay some help about options\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t-i ind\t\tSet tree indention to ind (3..9)\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t-l lev\t\tBuild tree up to level lev\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t-n\t\tDon't scan tree for changes in tree\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t-o\t\tOmit saving definition/history changes\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t-p lin\t\tSet file lines on tree screen to lin (1..9)\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t-q\t\tBuild tree up to level 2 (like -l 2)\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t-r\t\tRecreate tree list (always scan disk)\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t-s\t\tDon't use hardware scrolling\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t-t\t\tSort files by modification times\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t-u\t\tUpdate file lists in directory tree\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t-v mod\t\tSet video attribute mode to mod (0, 1 or 2)\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t-w\t\tNo warning about unreadable directories\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t-x cmd\t\tUse string cmd as initial input\n"
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* usage() */
end_comment

begin_comment
comment|/* Exit utree on error */
end_comment

begin_function
name|LOCAL
name|VOID
name|uerror
parameter_list|(
name|err
parameter_list|)
specifier|register
name|char
modifier|*
name|err
decl_stmt|;
block|{
operator|(
name|void
operator|)
name|cursorxy
argument_list|(
literal|0
argument_list|,
name|lines
operator|-
literal|1
argument_list|)
expr_stmt|;
name|clearline
argument_list|()
expr_stmt|;
name|flushout
argument_list|()
expr_stmt|;
name|terminalreset
argument_list|(
literal|1
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: "
argument_list|,
name|prgname
argument_list|)
expr_stmt|;
name|perror
argument_list|(
name|err
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/*NOTREACHED*/
block|}
end_function

begin_comment
comment|/* uerror() */
end_comment

begin_comment
comment|/*  *      SETUP VARIABLES  */
end_comment

begin_comment
comment|/* Set up terminal dependent variables */
end_comment

begin_function
name|LOCAL
name|int
name|setupscreen
parameter_list|(
name|sig
parameter_list|)
specifier|register
name|int
name|sig
decl_stmt|;
block|{
if|#
directive|if
name|defined
argument_list|(
name|SIGWINCH
argument_list|)
operator|&&
name|defined
argument_list|(
name|TIOCGWINSZ
argument_list|)
name|struct
name|winsize
name|ws
decl_stmt|;
comment|/* Signal SIGWINCH catched: get new screen size */
if|if
condition|(
name|sig
operator|&&
name|ioctl
argument_list|(
name|fileno
argument_list|(
name|stdin
argument_list|)
argument_list|,
name|TIOCGWINSZ
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|ws
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|ws
operator|.
name|ws_row
operator|>
literal|0
condition|)
name|lines
operator|=
name|ws
operator|.
name|ws_row
expr_stmt|;
if|if
condition|(
name|ws
operator|.
name|ws_col
operator|>
literal|0
condition|)
name|columns
operator|=
name|ws
operator|.
name|ws_col
expr_stmt|;
name|sizechange
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|lines
operator|<
name|MINLINS
condition|)
name|bell
argument_list|(
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|columns
operator|<
name|MINCOLS
condition|)
name|bell
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|flushout
argument_list|()
expr_stmt|;
block|}
comment|/* Catch signal SIGWINCH for window changes */
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGWINCH
argument_list|,
operator|(
name|SIGNL
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
name|setupscreen
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SIGWINCH&& TIOCGWINSZ */
comment|/* Set up some screen size dependent variables */
name|echoline
operator|=
literal|0
expr_stmt|;
name|helpline
operator|=
literal|1
expr_stmt|;
name|firstline
operator|=
literal|2
expr_stmt|;
name|lastline
operator|=
name|lines
operator|-
literal|1
expr_stmt|;
name|firstdline
operator|=
name|firstline
expr_stmt|;
name|lastfline
operator|=
name|lastline
expr_stmt|;
name|fperline
operator|=
name|columns
operator|/
name|FWINSZ
expr_stmt|;
name|fperpage
operator|=
operator|(
name|lines
operator|-
literal|2
operator|)
operator|*
name|fperline
expr_stmt|;
if|if
condition|(
name|fperline
operator|<=
literal|0
condition|)
name|fperline
operator|=
literal|1
expr_stmt|;
comment|/* Check some variables */
if|if
condition|(
name|fperpage
operator|<=
literal|0
condition|)
name|fperpage
operator|=
literal|1
expr_stmt|;
name|checklines
argument_list|(
literal|1
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|setvideomode
argument_list|(
name|videomode
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
name|defined
argument_list|(
name|SIGWINCH
argument_list|)
operator|&&
name|defined
argument_list|(
name|TIOCGWINSZ
argument_list|)
comment|/* BSD: Because signal SIGWINCH doesn't interrupt the systemcall */
comment|/*      read use the global goto longjmp() to return to getchar  */
if|if
condition|(
name|sig
operator|&&
name|atread
operator|&&
name|sizechange
condition|)
name|longjmp
argument_list|(
name|winchjump
argument_list|,
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* BSD&& SIGWINCH&& TIOCGWINSZ */
block|}
end_function

begin_comment
comment|/* setupscreen() */
end_comment

begin_comment
comment|/*  *      GET STARTUPFILES  */
end_comment

begin_comment
comment|/* Build startupfile name from file f and copy it to buffer b */
end_comment

begin_function
name|GLOBL
name|int
name|startup
parameter_list|(
name|b
parameter_list|,
name|f
parameter_list|)
specifier|register
name|char
modifier|*
name|b
decl_stmt|,
decl|*
name|f
decl_stmt|;
end_function

begin_block
block|{
specifier|register
name|char
modifier|*
name|e
decl_stmt|;
comment|/* First: Try user's home directory */
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|b
argument_list|,
literal|".%s"
argument_list|,
name|f
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|b
argument_list|,
name|pathname
argument_list|(
name|b
argument_list|,
name|home
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|access
argument_list|(
name|b
argument_list|,
literal|04
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* Second: Try libdir if defined in environment */
if|if
condition|(
name|e
operator|=
name|getenv
argument_list|(
literal|"UTLIB"
argument_list|)
condition|)
block|{
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|b
argument_list|,
name|pathname
argument_list|(
name|f
argument_list|,
name|e
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|access
argument_list|(
name|b
argument_list|,
literal|04
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
literal|1
operator|)
return|;
block|}
comment|/* Third: Try global libdir if defined */
ifdef|#
directive|ifdef
name|UTLIB
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|b
argument_list|,
name|pathname
argument_list|(
name|f
argument_list|,
name|UTLIB
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|access
argument_list|(
name|b
argument_list|,
literal|04
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
literal|1
operator|)
return|;
endif|#
directive|endif
comment|/* UTLIB */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/* startup() */
end_comment

begin_comment
comment|/*  *      MEMORY ALLOCATION  */
end_comment

begin_comment
comment|/* Allocate memory. Exit on error */
end_comment

begin_function
name|GLOBL
name|char
modifier|*
name|ualloc
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|)
specifier|register
name|unsigned
name|n
decl_stmt|,
name|s
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
if|if
condition|(
name|p
operator|=
name|calloc
argument_list|(
name|n
argument_list|,
name|s
argument_list|)
condition|)
return|return
operator|(
name|p
operator|)
return|;
name|uerror
argument_list|(
literal|"ualloc"
argument_list|)
expr_stmt|;
comment|/*NOTREACHED*/
block|}
end_function

begin_comment
comment|/* ualloc() */
end_comment

begin_comment
comment|/* Free allocated memory */
end_comment

begin_function
name|GLOBL
name|VOID
name|ufree
parameter_list|(
name|p
parameter_list|)
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
block|{
if|if
condition|(
name|p
condition|)
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ufree() */
end_comment

begin_comment
comment|/*  *      MAIN ROUTINE  */
end_comment

begin_function
name|GLOBL
name|VOID
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|char
name|list
index|[
name|NAMELEN
index|]
decl_stmt|,
name|name
index|[
name|NAMELEN
index|]
decl_stmt|,
name|cwd
index|[
name|NAMELEN
index|]
decl_stmt|;
name|struct
name|stat
name|st
decl_stmt|;
name|FILE
modifier|*
name|fp
decl_stmt|;
name|char
modifier|*
name|lst
init|=
name|NULL
decl_stmt|;
name|char
modifier|*
name|cp
decl_stmt|,
modifier|*
name|root
decl_stmt|,
modifier|*
name|term
decl_stmt|;
name|int
name|hard
init|=
literal|0
decl_stmt|,
name|level
init|=
literal|0
decl_stmt|,
name|siz
init|=
literal|1
decl_stmt|,
name|update
init|=
literal|0
decl_stmt|;
name|int
name|opt
decl_stmt|,
name|any
decl_stmt|,
name|rval
decl_stmt|,
name|i
decl_stmt|;
comment|/* Set up programs name and commandline variables */
name|prgname
operator|=
name|basename
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
comment|/* Get users home directory */
if|if
condition|(
operator|(
name|home
operator|=
name|getenv
argument_list|(
literal|"HOME"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: Can't get your home directory\n"
argument_list|,
name|prgname
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* Check if utree is running from a terminal */
if|if
condition|(
operator|!
name|isatty
argument_list|(
name|fileno
argument_list|(
name|stdin
argument_list|)
argument_list|)
operator|||
operator|!
name|isatty
argument_list|(
name|fileno
argument_list|(
name|stdout
argument_list|)
argument_list|)
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: Not attached to a terminal\n"
argument_list|,
name|prgname
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* Init utree variables before parsing command line options */
name|initvariables
argument_list|()
expr_stmt|;
comment|/* Parse and check command line options */
while|while
condition|(
operator|(
name|opt
operator|=
name|getopt
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
name|UOPTS
argument_list|)
operator|)
operator|!=
name|EOF
condition|)
switch|switch
condition|(
name|opt
condition|)
block|{
default|default:
comment|/* Bad option or missing argument */
name|usage
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|USEANSICOLORS
case|case
literal|'C'
case|:
comment|/* Don't use colors */
operator|(
name|void
operator|)
name|setvariable
argument_list|(
literal|"UC="
argument_list|,
name|VC_SET
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* USEANSICOLORS */
case|case
literal|'L'
case|:
comment|/* Follow symbolic links */
name|statfun
operator|=
name|stat
expr_stmt|;
break|break;
case|case
literal|'S'
case|:
comment|/* Ignore minimal screen size */
name|siz
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|'V'
case|:
comment|/* Show utree version */
name|utreeversion
argument_list|()
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
case|case
literal|'a'
case|:
comment|/* Build up all directories */
name|hiddendirs
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'b'
case|:
comment|/* No bell */
operator|(
name|void
operator|)
name|setvariable
argument_list|(
literal|"BL="
argument_list|,
name|VC_SET
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'c'
case|:
comment|/* No clock showing and update */
operator|(
name|void
operator|)
name|setvariable
argument_list|(
literal|"CL="
argument_list|,
name|VC_SET
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'d'
case|:
comment|/* Define or undefine variables */
if|if
condition|(
name|strchr
argument_list|(
name|optarg
argument_list|,
literal|'='
argument_list|)
condition|)
block|{
operator|(
name|void
operator|)
name|setvariable
argument_list|(
name|optarg
argument_list|,
name|VC_SET
argument_list|)
expr_stmt|;
break|break;
block|}
elseif|else
if|if
condition|(
name|strchr
argument_list|(
name|optarg
argument_list|,
literal|':'
argument_list|)
condition|)
block|{
operator|(
name|void
operator|)
name|setcommand
argument_list|(
name|optarg
argument_list|,
name|VC_SET
argument_list|)
expr_stmt|;
break|break;
block|}
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: bad assignment -- %s\n"
argument_list|,
name|prgname
argument_list|,
name|optarg
argument_list|)
expr_stmt|;
name|usage
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
case|case
literal|'f'
case|:
comment|/* Tree list file given */
name|lst
operator|=
name|optarg
expr_stmt|;
break|break;
case|case
literal|'g'
case|:
comment|/* No graphic characters */
operator|(
name|void
operator|)
name|setvariable
argument_list|(
literal|"GC="
argument_list|,
name|VC_SET
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'h'
case|:
comment|/* Display some help */
name|utreeversion
argument_list|()
expr_stmt|;
name|usage
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
case|case
literal|'i'
case|:
comment|/* Tree level indention */
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|list
argument_list|,
literal|"TI=%s"
argument_list|,
name|optarg
argument_list|)
expr_stmt|;
if|if
condition|(
name|setvariable
argument_list|(
name|list
argument_list|,
name|VC_SET
argument_list|)
operator|<
literal|0
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: bad tree indention (must be 3 .. 9) -- %s\n"
argument_list|,
name|prgname
argument_list|,
name|optarg
argument_list|)
expr_stmt|;
name|usage
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
literal|'l'
case|:
comment|/* Level to build up the tree */
if|if
condition|(
operator|(
name|level
operator|=
name|atoi
argument_list|(
name|optarg
argument_list|)
operator|)
operator|<=
literal|0
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: bad tree level (must be> 0) -- %s\n"
argument_list|,
name|prgname
argument_list|,
name|optarg
argument_list|)
expr_stmt|;
name|usage
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
literal|'n'
case|:
comment|/* No scan tree for changes */
operator|(
name|void
operator|)
name|setvariable
argument_list|(
literal|"ST="
argument_list|,
name|VC_SET
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'o'
case|:
comment|/* Omit saving definition changes */
operator|(
name|void
operator|)
name|setvariable
argument_list|(
literal|"AS="
argument_list|,
name|VC_SET
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'p'
case|:
comment|/* Number of file lines on tree screen */
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|list
argument_list|,
literal|"FL=%s"
argument_list|,
name|optarg
argument_list|)
expr_stmt|;
if|if
condition|(
name|setvariable
argument_list|(
name|list
argument_list|,
name|VC_SET
argument_list|)
operator|<
literal|0
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: bad number of lines (must be 1 .. 9) -- %s\n"
argument_list|,
name|prgname
argument_list|,
name|optarg
argument_list|)
expr_stmt|;
name|usage
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
literal|'q'
case|:
comment|/* Build tree up to level 2 */
name|level
operator|=
literal|2
expr_stmt|;
break|break;
case|case
literal|'r'
case|:
comment|/* Hard build up the tree */
name|hard
operator|=
name|writeflag
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'s'
case|:
comment|/* No terminal scrolling */
operator|(
name|void
operator|)
name|setvariable
argument_list|(
literal|"TS="
argument_list|,
name|VC_SET
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'t'
case|:
comment|/* Sort files by modification times */
operator|(
name|void
operator|)
name|setvariable
argument_list|(
literal|"LS="
argument_list|,
name|VC_SET
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'u'
case|:
comment|/* Update filelists in tree */
name|update
operator|=
name|buildflag
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'v'
case|:
comment|/* Set video mode */
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|list
argument_list|,
literal|"VM=%s"
argument_list|,
name|optarg
argument_list|)
expr_stmt|;
if|if
condition|(
name|setvariable
argument_list|(
name|list
argument_list|,
name|VC_SET
argument_list|)
operator|<
literal|0
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: bad mode (use 0, 1 or 2) -- %s\n"
argument_list|,
name|prgname
argument_list|,
name|optarg
argument_list|)
expr_stmt|;
name|usage
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
literal|'w'
case|:
comment|/* No warning about unreadable directories */
operator|(
name|void
operator|)
name|setvariable
argument_list|(
literal|"WD="
argument_list|,
name|VC_SET
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'x'
case|:
comment|/* Fill input buffer */
if|if
condition|(
name|ungetstring
argument_list|(
name|optarg
argument_list|)
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: bad input string -- %s\n"
argument_list|,
name|prgname
argument_list|,
name|optarg
argument_list|)
expr_stmt|;
name|usage
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
comment|/* Get current working directory */
operator|(
name|void
operator|)
name|getcwd
argument_list|(
name|cwd
argument_list|,
name|NAMELEN
operator|-
literal|2
argument_list|)
expr_stmt|;
comment|/* Check list file if given and setup rootdirectory */
if|if
condition|(
name|lst
condition|)
block|{
if|if
condition|(
operator|!
operator|(
name|fp
operator|=
name|fopen
argument_list|(
name|lst
argument_list|,
literal|"r"
argument_list|)
operator|)
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: Cannot open list file %s\n"
argument_list|,
name|prgname
argument_list|,
name|lst
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
name|fgets
argument_list|(
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|name
argument_list|)
argument_list|,
name|fp
argument_list|)
condition|)
block|{
if|if
condition|(
name|VALID
argument_list|(
name|name
index|[
literal|0
index|]
argument_list|)
operator|&&
operator|(
name|name
index|[
literal|0
index|]
operator|==
literal|'/'
operator|||
name|name
index|[
literal|0
index|]
operator|==
literal|'.'
operator|)
condition|)
block|{
if|if
condition|(
name|name
index|[
name|i
operator|=
name|strlen
argument_list|(
name|name
argument_list|)
operator|-
literal|1
index|]
operator|==
literal|'\n'
condition|)
name|name
index|[
name|i
index|]
operator|=
literal|'\0'
expr_stmt|;
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|fp
argument_list|)
expr_stmt|;
goto|goto
name|OUT
goto|;
block|}
block|}
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|fp
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: No root found in list file %s\n"
argument_list|,
name|prgname
argument_list|,
name|lst
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|OUT
label|:
comment|/* Get root directory from where to build up the directory tree */
switch|switch
condition|(
name|argc
operator|-
name|optind
condition|)
block|{
case|case
literal|0
case|:
comment|/* Root from list file */
if|if
condition|(
name|lst
condition|)
block|{
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|list
argument_list|,
name|pathname
argument_list|(
name|lst
argument_list|,
name|cwd
argument_list|)
argument_list|)
expr_stmt|;
name|root
operator|=
name|pathname
argument_list|(
name|name
argument_list|,
name|cwd
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* Root is users home directory */
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|list
argument_list|,
name|pathname
argument_list|(
name|UTLIST
argument_list|,
name|home
argument_list|)
argument_list|)
expr_stmt|;
name|root
operator|=
name|home
expr_stmt|;
block|}
break|break;
case|case
literal|1
case|:
comment|/* Root is given in command line */
name|root
operator|=
name|pathname
argument_list|(
name|argv
index|[
name|optind
index|]
argument_list|,
name|cwd
argument_list|)
expr_stmt|;
break|break;
default|default:
comment|/* Too many arguments */
name|usage
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* Test and change to root directory */
if|if
condition|(
operator|!
name|ISDIR
argument_list|(
name|root
argument_list|,
name|st
argument_list|)
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: Root %s is not a directory\n"
argument_list|,
name|prgname
argument_list|,
name|root
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|chdir
argument_list|(
name|root
argument_list|)
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: Can't change to root %s\n"
argument_list|,
name|prgname
argument_list|,
name|root
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|rootdir
argument_list|,
name|root
argument_list|)
expr_stmt|;
name|any
operator|=
name|strncmp
argument_list|(
name|root
argument_list|,
name|home
argument_list|,
name|strlen
argument_list|(
name|home
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Init screen and check screen size */
name|term
operator|=
name|getenv
argument_list|(
literal|"TERM"
argument_list|)
expr_stmt|;
if|if
condition|(
name|cp
operator|=
name|initscreen
argument_list|(
name|term
argument_list|)
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: %s\n"
argument_list|,
name|prgname
argument_list|,
name|cp
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|siz
operator|&&
operator|(
name|columns
operator|<
name|MINCOLS
operator|||
name|lines
operator|<
name|MINLINS
operator|)
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: Screen too small, %dx%d instead of %dx%d\n"
argument_list|,
name|prgname
argument_list|,
name|columns
argument_list|,
name|lines
argument_list|,
name|MINCOLS
argument_list|,
name|MINLINS
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|setupscreen
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Init history list, help pages, key bindings and graphical character set */
name|inithistory
argument_list|()
expr_stmt|;
name|inithelp
argument_list|()
expr_stmt|;
name|initgraphics
argument_list|(
name|VARSET
argument_list|(
name|V_GC
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Catch signals and set terminal to raw mode. ATTENTION:  */
comment|/* SIGKILL cannot be caught. This leaves tty in raw state! */
name|terminalraw
argument_list|(
literal|1
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
operator|(
name|SIGNL
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
name|exitscreen
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGINT
argument_list|,
operator|(
name|SIGNL
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
name|exitscreen
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGTERM
argument_list|,
operator|(
name|SIGNL
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
name|exitscreen
argument_list|)
expr_stmt|;
name|enablesignals
argument_list|()
expr_stmt|;
comment|/* Show initial screen */
ifdef|#
directive|ifdef
name|USEANSICOLORS
if|if
condition|(
name|colorcap
condition|)
name|colorset
argument_list|(
name|usecolors
condition|?
name|CS_INIT
else|:
name|CS_RESET
argument_list|)
expr_stmt|;
else|else
endif|#
directive|endif
comment|/* USEANSICOLORS */
name|clearscreen
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|putversion
argument_list|(
name|helpline
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|flushout
argument_list|()
expr_stmt|;
comment|/* Build up directory tree and file lists */
if|if
condition|(
name|lst
condition|)
name|rval
operator|=
name|buildlist
argument_list|(
name|rootdir
argument_list|,
name|cwd
argument_list|,
name|list
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|level
condition|)
block|{
name|update
operator|=
literal|0
expr_stmt|;
name|rval
operator|=
name|buildread
argument_list|(
name|rootdir
argument_list|,
literal|1
argument_list|,
name|level
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|hard
operator|||
name|any
condition|)
block|{
name|update
operator|=
literal|0
expr_stmt|;
name|rval
operator|=
name|buildread
argument_list|(
name|rootdir
argument_list|,
literal|1
argument_list|,
name|HLEVEL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|rval
operator|=
name|buildlist
argument_list|(
name|rootdir
argument_list|,
name|cwd
argument_list|,
name|list
argument_list|)
operator|)
operator|!=
name|RV_OK
condition|)
block|{
name|update
operator|=
literal|0
expr_stmt|;
name|writeflag
operator|=
literal|1
expr_stmt|;
name|rval
operator|=
name|buildread
argument_list|(
name|rootdir
argument_list|,
literal|1
argument_list|,
name|HLEVEL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
comment|/* Exit on error at building tree */
if|if
condition|(
name|rval
operator|!=
name|RV_OK
condition|)
name|uerror
argument_list|(
name|rootdir
argument_list|)
expr_stmt|;
comment|/* Disable/ignore signals */
name|disablesignals
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
name|cursorset
argument_list|(
name|CF_INVISIBLE
argument_list|)
expr_stmt|;
name|flushout
argument_list|()
expr_stmt|;
comment|/* Call the tree menu */
name|cwlist
operator|=
name|droot
expr_stmt|;
name|rval
operator|=
name|treemenu
argument_list|(
name|update
argument_list|)
expr_stmt|;
comment|/* Write/rewrite tree and command history lists if needed */
if|if
condition|(
name|EQU
argument_list|(
name|rootdir
argument_list|,
name|home
argument_list|)
condition|)
block|{
if|if
condition|(
name|writeflag
operator|&&
operator|!
operator|(
name|level
operator|||
name|any
operator|)
condition|)
block|{
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|list
argument_list|,
name|pathname
argument_list|(
name|UTLIST
argument_list|,
name|home
argument_list|)
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|writedlist
argument_list|(
name|list
argument_list|,
name|droot
argument_list|,
literal|"home"
argument_list|,
literal|'d'
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* Save history list, variables, commands and key bindings */
name|savehistory
argument_list|()
expr_stmt|;
name|savevariables
argument_list|()
expr_stmt|;
name|savebindings
argument_list|(
name|term
argument_list|)
expr_stmt|;
comment|/* Clear screen, reset terminal and exit */
name|clearscreen
argument_list|()
expr_stmt|;
name|exitscreen
argument_list|(
name|rval
operator|==
name|RV_ERR
condition|?
literal|1
else|:
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* main() */
end_comment

end_unit

