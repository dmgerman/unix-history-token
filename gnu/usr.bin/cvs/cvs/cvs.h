begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $CVSid: @(#)cvs.h 1.86 94/10/22 $	 */
end_comment

begin_comment
comment|/*  * basic information used in all source files  *  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_comment
comment|/* this is stuff found via autoconf */
end_comment

begin_include
include|#
directive|include
file|"options.h"
end_include

begin_comment
comment|/* these are some larger questions which 				   can't easily be automatically checked 				   for */
end_comment

begin_comment
comment|/* AIX requires this to be the first thing in the file. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|alloca
value|__builtin_alloca
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __GNUC__ */
end_comment

begin_if
if|#
directive|if
name|HAVE_ALLOCA_H
end_if

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not HAVE_ALLOCA_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|alloca
end_pragma

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not _AIX */
end_comment

begin_function_decl
name|char
modifier|*
name|alloca
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _AIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_ALLOCA_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __GNUC__ */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_define
define|#
directive|define
name|CONST
value|const
end_define

begin_define
define|#
directive|define
name|PTR
value|void *
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CONST
end_define

begin_define
define|#
directive|define
name|PTR
value|char *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Add prototype support.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PROTO
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_PROTOTYPES
argument_list|)
condition|?
name|USE_PROTOTYPES
expr|:
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|PROTO
parameter_list|(
name|ARGS
parameter_list|)
value|ARGS
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PROTO
parameter_list|(
name|ARGS
parameter_list|)
value|()
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
name|__GNUC__
operator|==
literal|2
end_if

begin_define
define|#
directive|define
name|USE
parameter_list|(
name|var
parameter_list|)
value|static char sizeof##var = sizeof(sizeof##var) + sizeof(var);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|USE
parameter_list|(
name|var
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRING_H
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<fnmatch.h>
end_include

begin_comment
comment|/* This is supposed to be available on Posix systems */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ERRNO_H
end_ifdef

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|errno
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !errno */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_ERRNO_H */
end_comment

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"hash.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|MY_NDBM
end_ifdef

begin_include
include|#
directive|include
file|"myndbm.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<ndbm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MY_NDBM */
end_comment

begin_include
include|#
directive|include
file|"regex.h"
end_include

begin_include
include|#
directive|include
file|"getopt.h"
end_include

begin_include
include|#
directive|include
file|"wait.h"
end_include

begin_include
include|#
directive|include
file|"rcs.h"
end_include

begin_comment
comment|/* XXX - for now this is static */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PATH_MAX
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|MAXPATHLEN
end_ifdef

begin_define
define|#
directive|define
name|PATH_MAX
value|MAXPATHLEN+2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PATH_MAX
value|1024+2
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
comment|/* PATH_MAX */
end_comment

begin_comment
comment|/* just in case this implementation does not define this */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|L_tmpnam
end_ifndef

begin_define
define|#
directive|define
name|L_tmpnam
value|50
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Copyright (c) 1992, Brian Berliner and Jeff Polk  * Copyright (c) 1989-1992, Brian Berliner  *  * You may distribute under the terms of the GNU General Public License as  * specified in the README file that comes with the CVS 1.4 kit.  *  * Definitions for the CVS Administrative directory and the files it contains.  * Here as #define's to make changing the names a simple task.  */
end_comment

begin_define
define|#
directive|define
name|CVSADM
value|"CVS"
end_define

begin_define
define|#
directive|define
name|CVSADM_ENT
value|"CVS/Entries"
end_define

begin_define
define|#
directive|define
name|CVSADM_ENTBAK
value|"CVS/Entries.Backup"
end_define

begin_define
define|#
directive|define
name|CVSADM_ENTSTAT
value|"CVS/Entries.Static"
end_define

begin_define
define|#
directive|define
name|CVSADM_REP
value|"CVS/Repository"
end_define

begin_define
define|#
directive|define
name|CVSADM_ROOT
value|"CVS/Root"
end_define

begin_define
define|#
directive|define
name|CVSADM_CIPROG
value|"CVS/Checkin.prog"
end_define

begin_define
define|#
directive|define
name|CVSADM_UPROG
value|"CVS/Update.prog"
end_define

begin_define
define|#
directive|define
name|CVSADM_TAG
value|"CVS/Tag"
end_define

begin_comment
comment|/*  * The following are obsolete and are maintained here only so that they can be  * cleaned up during the transition  */
end_comment

begin_define
define|#
directive|define
name|OCVSADM
value|"CVS.adm"
end_define

begin_comment
comment|/* for CVS 1.2 and earlier */
end_comment

begin_define
define|#
directive|define
name|CVSADM_FILE
value|"CVS/Files"
end_define

begin_define
define|#
directive|define
name|CVSADM_MOD
value|"CVS/Mod"
end_define

begin_comment
comment|/*  * Definitions for the CVSROOT Administrative directory and the files it  * contains.  This directory is created as a sub-directory of the $CVSROOT  * environment variable, and holds global administration information for the  * entire source repository beginning at $CVSROOT.  */
end_comment

begin_define
define|#
directive|define
name|CVSROOTADM
value|"CVSROOT"
end_define

begin_define
define|#
directive|define
name|CVSROOTADM_MODULES
value|"modules"
end_define

begin_define
define|#
directive|define
name|CVSROOTADM_LOGINFO
value|"loginfo"
end_define

begin_define
define|#
directive|define
name|CVSROOTADM_RCSINFO
value|"rcsinfo"
end_define

begin_define
define|#
directive|define
name|CVSROOTADM_COMMITINFO
value|"commitinfo"
end_define

begin_define
define|#
directive|define
name|CVSROOTADM_EDITINFO
value|"editinfo"
end_define

begin_define
define|#
directive|define
name|CVSROOTADM_HISTORY
value|"history"
end_define

begin_define
define|#
directive|define
name|CVSROOTADM_IGNORE
value|"cvsignore"
end_define

begin_define
define|#
directive|define
name|CVSROOTADM_CHECKOUTLIST
value|"checkoutlist"
end_define

begin_define
define|#
directive|define
name|CVSNULLREPOS
value|"Emptydir"
end_define

begin_comment
comment|/* an empty directory */
end_comment

begin_comment
comment|/* support for the modules file (CVSROOTADM_MODULES) */
end_comment

begin_define
define|#
directive|define
name|CVSMODULE_OPTS
value|"ad:i:lo:s:t:u:"
end_define

begin_comment
comment|/* options in modules file */
end_comment

begin_define
define|#
directive|define
name|CVSMODULE_SPEC
value|'&'
end_define

begin_comment
comment|/* special delimiter */
end_comment

begin_comment
comment|/*  * The following are obsolete and are maintained here only so that they can be  * cleaned up during the transition  */
end_comment

begin_define
define|#
directive|define
name|OCVSROOTADM
value|"CVSROOT.adm"
end_define

begin_comment
comment|/* for CVS 1.2 and earlier */
end_comment

begin_comment
comment|/* Other CVS file names */
end_comment

begin_define
define|#
directive|define
name|CVSATTIC
value|"Attic"
end_define

begin_define
define|#
directive|define
name|CVSLCK
value|"#cvs.lock"
end_define

begin_define
define|#
directive|define
name|CVSTFL
value|"#cvs.tfl"
end_define

begin_define
define|#
directive|define
name|CVSRFL
value|"#cvs.rfl"
end_define

begin_define
define|#
directive|define
name|CVSWFL
value|"#cvs.wfl"
end_define

begin_define
define|#
directive|define
name|CVSRFLPAT
value|"#cvs.rfl.*"
end_define

begin_comment
comment|/* wildcard expr to match read locks */
end_comment

begin_define
define|#
directive|define
name|CVSEXT_OPT
value|",p"
end_define

begin_define
define|#
directive|define
name|CVSEXT_LOG
value|",t"
end_define

begin_define
define|#
directive|define
name|CVSPREFIX
value|",,"
end_define

begin_define
define|#
directive|define
name|CVSDOTIGNORE
value|".cvsignore"
end_define

begin_comment
comment|/* miscellaneous CVS defines */
end_comment

begin_define
define|#
directive|define
name|CVSEDITPREFIX
value|"CVS: "
end_define

begin_define
define|#
directive|define
name|CVSLCKAGE
value|(60*60)
end_define

begin_comment
comment|/* 1-hour old lock files cleaned up */
end_comment

begin_define
define|#
directive|define
name|CVSLCKSLEEP
value|30
end_define

begin_comment
comment|/* wait 30 seconds before retrying */
end_comment

begin_define
define|#
directive|define
name|CVSBRANCH
value|"1.1.1"
end_define

begin_comment
comment|/* RCS branch used for vendor srcs */
end_comment

begin_define
define|#
directive|define
name|BAKPREFIX
value|".#"
end_define

begin_comment
comment|/* when rcsmerge'ing */
end_comment

begin_define
define|#
directive|define
name|DEVNULL
value|"/dev/null"
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_comment
comment|/*  * Special tags. -rHEAD	refers to the head of an RCS file, regardless of any  * sticky tags. -rBASE	refers to the current revision the user has checked  * out This mimics the behaviour of RCS.  */
end_comment

begin_define
define|#
directive|define
name|TAG_HEAD
value|"HEAD"
end_define

begin_define
define|#
directive|define
name|TAG_BASE
value|"BASE"
end_define

begin_comment
comment|/* Environment variable used by CVS */
end_comment

begin_define
define|#
directive|define
name|CVSREAD_ENV
value|"CVSREAD"
end_define

begin_comment
comment|/* make files read-only */
end_comment

begin_define
define|#
directive|define
name|CVSREAD_DFLT
value|FALSE
end_define

begin_comment
comment|/* writable files by default */
end_comment

begin_define
define|#
directive|define
name|RCSBIN_ENV
value|"RCSBIN"
end_define

begin_comment
comment|/* RCS binary directory */
end_comment

begin_comment
comment|/* #define	RCSBIN_DFLT		   Set by config.h */
end_comment

begin_define
define|#
directive|define
name|EDITOR1_ENV
value|"CVSEDITOR"
end_define

begin_comment
comment|/* which editor to use */
end_comment

begin_define
define|#
directive|define
name|EDITOR2_ENV
value|"EDITOR"
end_define

begin_comment
comment|/* which editor to use */
end_comment

begin_comment
comment|/* #define	EDITOR_DFLT		   Set by config.h */
end_comment

begin_define
define|#
directive|define
name|CVSROOT_ENV
value|"CVSROOT"
end_define

begin_comment
comment|/* source directory root */
end_comment

begin_define
define|#
directive|define
name|CVSROOT_DFLT
value|NULL
end_define

begin_comment
comment|/* No dflt; must set for checkout */
end_comment

begin_define
define|#
directive|define
name|IGNORE_ENV
value|"CVSIGNORE"
end_define

begin_comment
comment|/* More files to ignore */
end_comment

begin_comment
comment|/*  * If the beginning of the Repository matches the following string, strip it  * so that the output to the logfile does not contain a full pathname.  *  * If the CVSROOT environment variable is set, it overrides this define.  */
end_comment

begin_define
define|#
directive|define
name|REPOS_STRIP
value|"/master/"
end_define

begin_comment
comment|/*  * The maximum number of files per each CVS directory. This is mainly for  * sizing arrays statically rather than dynamically.  3000 seems plenty for  * now.  */
end_comment

begin_define
define|#
directive|define
name|MAXFILEPERDIR
value|3000
end_define

begin_define
define|#
directive|define
name|MAXLINELEN
value|5000
end_define

begin_comment
comment|/* max input line from a file */
end_comment

begin_define
define|#
directive|define
name|MAXPROGLEN
value|30000
end_define

begin_comment
comment|/* max program length to system() */
end_comment

begin_define
define|#
directive|define
name|MAXLISTLEN
value|40000
end_define

begin_comment
comment|/* For [A-Z]list holders */
end_comment

begin_define
define|#
directive|define
name|MAXDATELEN
value|50
end_define

begin_comment
comment|/* max length for a date */
end_comment

begin_comment
comment|/* The type of request that is being done in do_module() */
end_comment

begin_enum
enum|enum
name|mtype
block|{
name|CHECKOUT
block|,
name|TAG
block|,
name|PATCH
block|}
enum|;
end_enum

begin_comment
comment|/*  * defines for Classify_File() to determine the current state of a file.  * These are also used as types in the data field for the list we make for  * Update_Logfile in commit, import, and add.  */
end_comment

begin_enum
enum|enum
name|classify_type
block|{
name|T_UNKNOWN
init|=
literal|1
block|,
comment|/* no old-style analog existed	 */
name|T_CONFLICT
block|,
comment|/* C (conflict) list		 */
name|T_NEEDS_MERGE
block|,
comment|/* G (needs merging) list	 */
name|T_MODIFIED
block|,
comment|/* M (needs checked in) list 	 */
name|T_CHECKOUT
block|,
comment|/* O (needs checkout) list	 */
name|T_ADDED
block|,
comment|/* A (added file) list		 */
name|T_REMOVED
block|,
comment|/* R (removed file) list	 */
name|T_REMOVE_ENTRY
block|,
comment|/* W (removed entry) list	 */
name|T_UPTODATE
block|,
comment|/* File is up-to-date		 */
name|T_TITLE
comment|/* title for node type 		 */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|classify_type
name|Ctype
typedef|;
end_typedef

begin_comment
comment|/*  * a struct vers_ts contains all the information about a file including the  * user and rcs file names, and the version checked out and the head.  *  * this is usually obtained from a call to Version_TS which takes a tag argument  * for the RCS file if desired  */
end_comment

begin_struct
struct|struct
name|vers_ts
block|{
name|char
modifier|*
name|vn_user
decl_stmt|;
comment|/* rcs version user file derives from 					 * it can have the following special 					 * values: 					 *    empty = no user file 					 *    0 = user file is new 					 *    -vers = user file to be removed */
name|char
modifier|*
name|vn_rcs
decl_stmt|;
comment|/* the version for the rcs file 					 * (tag version?) 	 */
name|char
modifier|*
name|ts_user
decl_stmt|;
comment|/* the timestamp for the user file */
name|char
modifier|*
name|ts_rcs
decl_stmt|;
comment|/* the user timestamp from entries */
name|char
modifier|*
name|options
decl_stmt|;
comment|/* opts from Entries file 					 * (keyword expansion)	 */
name|char
modifier|*
name|ts_conflict
decl_stmt|;
comment|/* Holds time_stamp of conflict */
name|char
modifier|*
name|tag
decl_stmt|;
comment|/* tag stored in the Entries file */
name|char
modifier|*
name|date
decl_stmt|;
comment|/* date stored in the Entries file */
name|Entnode
modifier|*
name|entdata
decl_stmt|;
comment|/* pointer to entries file node  */
name|RCSNode
modifier|*
name|srcfile
decl_stmt|;
comment|/* pointer to parsed src file info */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vers_ts
name|Vers_TS
typedef|;
end_typedef

begin_comment
comment|/*  * structure used for list-private storage by ParseEntries() and  * Version_TS().  */
end_comment

begin_struct
struct|struct
name|stickydirtag
block|{
name|int
name|aflag
decl_stmt|;
name|char
modifier|*
name|tag
decl_stmt|;
name|char
modifier|*
name|date
decl_stmt|;
name|char
modifier|*
name|options
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* flags for run_exec(), the fast system() for CVS */
end_comment

begin_define
define|#
directive|define
name|RUN_NORMAL
value|0x0000
end_define

begin_comment
comment|/* no special behaviour */
end_comment

begin_define
define|#
directive|define
name|RUN_COMBINED
value|0x0001
end_define

begin_comment
comment|/* stdout is duped to stderr */
end_comment

begin_define
define|#
directive|define
name|RUN_REALLY
value|0x0002
end_define

begin_comment
comment|/* do the exec, even if noexec is on */
end_comment

begin_define
define|#
directive|define
name|RUN_STDOUT_APPEND
value|0x0004
end_define

begin_comment
comment|/* append to stdout, don't truncate */
end_comment

begin_define
define|#
directive|define
name|RUN_STDERR_APPEND
value|0x0008
end_define

begin_comment
comment|/* append to stderr, don't truncate */
end_comment

begin_define
define|#
directive|define
name|RUN_SIGIGNORE
value|0x0010
end_define

begin_comment
comment|/* ignore interrupts for command */
end_comment

begin_define
define|#
directive|define
name|RUN_TTY
value|(char *)0
end_define

begin_comment
comment|/* for the benefit of lint */
end_comment

begin_comment
comment|/* Flags for find_{names,dirs} routines */
end_comment

begin_define
define|#
directive|define
name|W_LOCAL
value|0x01
end_define

begin_comment
comment|/* look for files locally */
end_comment

begin_define
define|#
directive|define
name|W_REPOS
value|0x02
end_define

begin_comment
comment|/* look for files in the repository */
end_comment

begin_define
define|#
directive|define
name|W_ATTIC
value|0x04
end_define

begin_comment
comment|/* look for files in the attic */
end_comment

begin_comment
comment|/* Flags for return values of direnter procs for the recursion processor */
end_comment

begin_enum
enum|enum
name|direnter_type
block|{
name|R_PROCESS
init|=
literal|1
block|,
comment|/* process files and maybe dirs */
name|R_SKIP_FILES
block|,
comment|/* don't process files in this dir */
name|R_SKIP_DIRS
block|,
comment|/* don't process sub-dirs */
name|R_SKIP_ALL
comment|/* don't process files or dirs */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|direnter_type
name|Dtype
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|program_name
decl_stmt|,
modifier|*
name|command_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Rcsbin
decl_stmt|,
modifier|*
name|Editor
decl_stmt|,
modifier|*
name|CVSroot
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|CVSADM_ROOT
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|CVSADM_Root
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cvsadmin_root
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CVSADM_ROOT */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|CurDir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|really_quiet
decl_stmt|,
name|quiet
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|use_editor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cvswrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|trace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Show all commands */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|noexec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Don't modify disk anywhere */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|logoff
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Don't write history entry */
end_comment

begin_comment
comment|/* Externs that are included directly in the CVS sources */
end_comment

begin_decl_stmt
name|DBM
modifier|*
name|open_module
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|Fopen
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|char
operator|*
name|mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|open_file
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|char
operator|*
name|mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|List
modifier|*
name|Find_Dirs
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|repository
operator|,
name|int
name|which
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|List
modifier|*
name|ParseEntries
name|PROTO
argument_list|(
operator|(
name|int
name|aflag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Make_Date
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|rawdate
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Name_Repository
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|dir
operator|,
name|char
operator|*
name|update_dir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|CVSADM_ROOT
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|Name_Root
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|dir
operator|,
name|char
operator|*
name|update_dir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Create_Root
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|dir
operator|,
name|char
operator|*
name|rootdir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|same_directories
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|dir1
operator|,
name|char
operator|*
name|dir2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CVSADM_ROOT */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Short_Repository
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|repository
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|gca
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|rev1
operator|,
name|char
operator|*
name|rev2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|getcaller
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|time_stamp
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|file
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|xmalloc
name|PROTO
argument_list|(
operator|(
name|size_t
name|bytes
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|xrealloc
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|ptr
operator|,
name|size_t
name|bytes
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|xstrdup
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|str
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|No_Difference
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|file
operator|,
name|Vers_TS
operator|*
name|vers
operator|,
name|List
operator|*
name|entries
operator|,
name|char
operator|*
name|repository
operator|,
name|char
operator|*
name|update_dir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Parse_Info
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|infofile
operator|,
name|char
operator|*
name|repository
operator|,
name|int
name|PROTO
argument_list|(
argument|(*callproc)
argument_list|)
name|PROTO
argument_list|(
operator|(
operator|)
argument_list|)
operator|,
name|int
name|all
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Reader_Lock
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|xrepository
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|SIG_register
name|PROTO
argument_list|(
operator|(
name|int
name|sig
operator|,
name|RETSIGTYPE
name|PROTO
argument_list|(
argument|(*fn)
argument_list|)
name|PROTO
argument_list|(
operator|(
operator|)
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Writer_Lock
name|PROTO
argument_list|(
operator|(
name|List
operator|*
name|list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ign_name
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isdir
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|file
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isfile
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|file
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|islink
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|file
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isreadable
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|file
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|iswritable
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|file
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|joining
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|link_file
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|from
operator|,
name|char
operator|*
name|to
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|numdots
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|run_exec
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|stin
operator|,
name|char
operator|*
name|stout
operator|,
name|char
operator|*
name|sterr
operator|,
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|unlink_file
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|f
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|update
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
name|argv
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|xcmp
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|file1
operator|,
name|char
operator|*
name|file2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|yesno
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|time_t
name|get_date
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|date
operator|,
expr|struct
name|timeb
operator|*
name|now
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Create_Admin
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|dir
operator|,
name|char
operator|*
name|repository
operator|,
name|char
operator|*
name|tag
operator|,
name|char
operator|*
name|date
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Lock_Cleanup
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ParseTag
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|*
name|tagp
operator|,
name|char
operator|*
operator|*
name|datep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Scratch_Entry
name|PROTO
argument_list|(
operator|(
name|List
operator|*
name|list
operator|,
name|char
operator|*
name|fname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|WriteTag
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|dir
operator|,
name|char
operator|*
name|tag
operator|,
name|char
operator|*
name|date
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cat_module
name|PROTO
argument_list|(
operator|(
name|int
name|status
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|check_entries
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|dir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|close_module
name|PROTO
argument_list|(
operator|(
name|DBM
operator|*
name|db
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|copy_file
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|from
operator|,
name|char
operator|*
name|to
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|error
name|PROTO
argument_list|(
operator|(
name|int
name|status
operator|,
name|int
name|errnum
operator|,
name|char
operator|*
name|message
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fperror
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
name|fp
operator|,
name|int
name|status
operator|,
name|int
name|errnum
operator|,
name|char
operator|*
name|message
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|free_names
name|PROTO
argument_list|(
operator|(
name|int
operator|*
name|pargc
operator|,
name|char
operator|*
name|argv
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|freevers_ts
name|PROTO
argument_list|(
operator|(
name|Vers_TS
operator|*
operator|*
name|versp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ign_add
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|ign
operator|,
name|int
name|hold
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ign_add_file
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|file
operator|,
name|int
name|hold
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ign_setup
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ign_dir_add
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ignore_directory
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|line2argv
name|PROTO
argument_list|(
operator|(
name|int
operator|*
name|pargc
operator|,
name|char
operator|*
name|argv
index|[]
operator|,
name|char
operator|*
name|line
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|make_directories
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|make_directory
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rename_file
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|from
operator|,
name|char
operator|*
name|to
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|run_arg
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|run_args
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|run_print
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
name|fp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|run_setup
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|strip_path
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|path
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|strip_trailing_slashes
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|path
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|update_delproc
name|PROTO
argument_list|(
operator|(
name|Node
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|usage
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|*
name|cpp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|xchmod
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|fname
operator|,
name|int
name|writable
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Checkin
name|PROTO
argument_list|(
operator|(
name|int
name|type
operator|,
name|char
operator|*
name|file
operator|,
name|char
operator|*
name|repository
operator|,
name|char
operator|*
name|rcs
operator|,
name|char
operator|*
name|rev
operator|,
name|char
operator|*
name|tag
operator|,
name|char
operator|*
name|options
operator|,
name|char
operator|*
name|message
operator|,
name|List
operator|*
name|entries
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Ctype
name|Classify_File
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|file
operator|,
name|char
operator|*
name|tag
operator|,
name|char
operator|*
name|date
operator|,
name|char
operator|*
name|options
operator|,
name|int
name|force_tag_match
operator|,
name|int
name|aflag
operator|,
name|char
operator|*
name|repository
operator|,
name|List
operator|*
name|entries
operator|,
name|List
operator|*
name|srcfiles
operator|,
name|Vers_TS
operator|*
operator|*
name|versp
operator|,
name|char
operator|*
name|update_dir
operator|,
name|int
name|pipeout
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|List
modifier|*
name|Find_Names
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|repository
operator|,
name|int
name|which
operator|,
name|int
name|aflag
operator|,
name|List
operator|*
operator|*
name|optentries
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Register
name|PROTO
argument_list|(
operator|(
name|List
operator|*
name|list
operator|,
name|char
operator|*
name|fname
operator|,
name|char
operator|*
name|vn
operator|,
name|char
operator|*
name|ts
operator|,
name|char
operator|*
name|options
operator|,
name|char
operator|*
name|tag
operator|,
name|char
operator|*
name|date
operator|,
name|char
operator|*
name|ts_conflict
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Update_Logfile
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|repository
operator|,
name|char
operator|*
name|xmessage
operator|,
name|char
operator|*
name|xrevision
operator|,
name|FILE
operator|*
name|xlogfp
operator|,
name|List
operator|*
name|xchanges
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Vers_TS
modifier|*
name|Version_TS
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|repository
operator|,
name|char
operator|*
name|options
operator|,
name|char
operator|*
name|tag
operator|,
name|char
operator|*
name|date
operator|,
name|char
operator|*
name|user
operator|,
name|int
name|force_tag_match
operator|,
name|int
name|set_time
operator|,
name|List
operator|*
name|entries
operator|,
name|List
operator|*
name|xfiles
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|do_editor
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|dir
operator|,
name|char
operator|*
operator|*
name|messagep
operator|,
name|char
operator|*
name|repository
operator|,
name|List
operator|*
name|changes
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|do_module
name|PROTO
argument_list|(
operator|(
name|DBM
operator|*
name|db
operator|,
name|char
operator|*
name|mname
operator|,
expr|enum
name|mtype
name|m_type
operator|,
name|char
operator|*
name|msg
operator|,
name|int
name|PROTO
argument_list|(
operator|(
operator|*
name|callback_proc
operator|)
argument_list|)
argument_list|()
operator|,
name|char
operator|*
name|where
operator|,
name|int
name|shorten
operator|,
name|int
name|local_specified
operator|,
name|int
name|run_module_prog
operator|,
name|char
operator|*
name|extra_arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|do_recursion
name|PROTO
argument_list|(
operator|(
name|int
name|PROTO
argument_list|(
operator|(
operator|*
name|xfileproc
operator|)
argument_list|)
argument_list|()
operator|,
name|int
name|PROTO
argument_list|(
operator|(
operator|*
name|xfilesdoneproc
operator|)
argument_list|)
argument_list|()
operator|,
name|Dtype
name|PROTO
argument_list|(
operator|(
operator|*
name|xdirentproc
operator|)
argument_list|)
argument_list|()
operator|,
name|int
name|PROTO
argument_list|(
operator|(
operator|*
name|xdirleaveproc
operator|)
argument_list|)
argument_list|()
operator|,
name|Dtype
name|xflags
operator|,
name|int
name|xwhich
operator|,
name|int
name|xaflag
operator|,
name|int
name|xreadlock
operator|,
name|int
name|xdosrcs
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|do_update
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
name|argv
index|[]
operator|,
name|char
operator|*
name|xoptions
operator|,
name|char
operator|*
name|xtag
operator|,
name|char
operator|*
name|xdate
operator|,
name|int
name|xforce
operator|,
name|int
name|local
operator|,
name|int
name|xbuild
operator|,
name|int
name|xaflag
operator|,
name|int
name|xprune
operator|,
name|int
name|xpipeout
operator|,
name|int
name|which
operator|,
name|char
operator|*
name|xjoin_rev1
operator|,
name|char
operator|*
name|xjoin_rev2
operator|,
name|char
operator|*
name|preload_update_dir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|history_write
name|PROTO
argument_list|(
operator|(
name|int
name|type
operator|,
name|char
operator|*
name|update_dir
operator|,
name|char
operator|*
name|revs
operator|,
name|char
operator|*
name|name
operator|,
name|char
operator|*
name|repository
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|start_recursion
name|PROTO
argument_list|(
operator|(
name|int
name|PROTO
argument_list|(
operator|(
operator|*
name|fileproc
operator|)
argument_list|)
argument_list|()
operator|,
name|int
name|PROTO
argument_list|(
operator|(
operator|*
name|filesdoneproc
operator|)
argument_list|)
argument_list|()
operator|,
name|Dtype
name|PROTO
argument_list|(
operator|(
operator|*
name|direntproc
operator|)
argument_list|)
argument_list|()
operator|,
name|int
name|PROTO
argument_list|(
operator|(
operator|*
name|dirleaveproc
operator|)
argument_list|)
argument_list|()
operator|,
name|int
name|argc
operator|,
name|char
operator|*
name|argv
index|[]
operator|,
name|int
name|local
operator|,
name|int
name|which
operator|,
name|int
name|aflag
operator|,
name|int
name|readlock
operator|,
name|char
operator|*
name|update_preload
operator|,
name|int
name|dosrcs
operator|,
name|int
name|wd_is_repos
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|SIG_beginCrSect
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|SIG_endCrSect
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|read_cvsrc
name|PROTO
argument_list|(
operator|(
name|int
operator|*
name|argc
operator|,
name|char
operator|*
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

