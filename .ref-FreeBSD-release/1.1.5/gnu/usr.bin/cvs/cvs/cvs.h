begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)cvs.h 1.72 92/03/31	 */
end_comment

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

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

begin_include
include|#
directive|include
file|"hash.h"
end_include

begin_include
include|#
directive|include
file|"rcs.h"
end_include

begin_include
include|#
directive|include
file|"regex.h"
end_include

begin_include
include|#
directive|include
file|"fnmatch.h"
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
file|"config.h"
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
comment|/* !MY_NDBM */
end_comment

begin_comment
comment|/* XXX - for now this is static */
end_comment

begin_undef
undef|#
directive|undef
name|PATH_MAX
end_undef

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
comment|/*  * Copyright (c) 1992, Brian Berliner and Jeff Polk  * Copyright (c) 1989-1992, Brian Berliner  *   * You may distribute under the terms of the GNU General Public License as  * specified in the README file that comes with the CVS 1.3 kit.  *   * Definitions for the CVS Administrative directory and the files it contains.  * Here as #define's to make changing the names a simple task.  */
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
name|EDITOR_ENV
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
comment|/*  * If the beginning of the Repository matches the following string, strip it  * so that the output to the logfile does not contain a full pathname.  *   * If the CVSROOT environment variable is set, it overrides this define.  */
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
name|MAXMESGLEN
value|10000
end_define

begin_comment
comment|/* max RCS log message size */
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
comment|/*  * a struct vers_ts contains all the information about a file including the  * user and rcs file names, and the version checked out and the head.  *   * this is usually obtained from a call to Version_TS which takes a tag argument  * for the RCS file if desired  */
end_comment

begin_struct
struct|struct
name|vers_ts
block|{
name|char
modifier|*
name|vn_user
decl_stmt|;
comment|/* rcs version user file derives from 					 * it can have the following special 					 * values:  					 *    empty = no user file	 					 *    0 = user file is new 					 *    -vers = user file to be removed */
name|char
modifier|*
name|vn_rcs
decl_stmt|;
comment|/* the verion for the rcs file 					 * (tag version?) 	 */
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
comment|/* opts from Entries file  					 * (keyword expansion)	 */
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

begin_ifdef
ifdef|#
directive|ifdef
name|FREEBSD_DEVELOPER
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|freebsd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Assume option defaults for FreBSD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FREEBSD_DEVELOPER */
end_comment

begin_comment
comment|/* Externs that are included directly in the CVS sources */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_function_decl
name|int
name|Reader_Lock
parameter_list|(
name|char
modifier|*
name|xrepository
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DBM
modifier|*
name|open_module
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|Fopen
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|open_file
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|List
modifier|*
name|Find_Dirs
parameter_list|(
name|char
modifier|*
name|repository
parameter_list|,
name|int
name|which
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|List
modifier|*
name|ParseEntries
parameter_list|(
name|int
name|aflag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Make_Date
parameter_list|(
name|char
modifier|*
name|rawdate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Name_Repository
parameter_list|(
name|char
modifier|*
name|dir
parameter_list|,
name|char
modifier|*
name|update_dir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Short_Repository
parameter_list|(
name|char
modifier|*
name|repository
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getcaller
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|time_stamp
parameter_list|(
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xmalloc
parameter_list|(
name|int
name|bytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xrealloc
parameter_list|(
name|char
modifier|*
name|ptr
parameter_list|,
name|int
name|bytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xstrdup
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|No_Difference
parameter_list|(
name|char
modifier|*
name|file
parameter_list|,
name|Vers_TS
modifier|*
name|vers
parameter_list|,
name|List
modifier|*
name|entries
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Parse_Info
parameter_list|(
name|char
modifier|*
name|infofile
parameter_list|,
name|char
modifier|*
name|repository
parameter_list|,
name|int
function_decl|(
modifier|*
name|callproc
function_decl|)
parameter_list|()
parameter_list|,
name|int
name|all
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Reader_Lock
parameter_list|(
name|char
modifier|*
name|xrepository
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|SIG_register
parameter_list|(
name|int
name|sig
parameter_list|,
name|SIGTYPE
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Writer_Lock
parameter_list|(
name|List
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gethostname
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|int
name|namelen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ign_name
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isdir
parameter_list|(
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isfile
parameter_list|(
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|islink
parameter_list|(
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isreadable
parameter_list|(
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iswritable
parameter_list|(
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|link_file
parameter_list|(
name|char
modifier|*
name|from
parameter_list|,
name|char
modifier|*
name|to
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|numdots
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|run_exec
parameter_list|(
name|char
modifier|*
name|stin
parameter_list|,
name|char
modifier|*
name|stout
parameter_list|,
name|char
modifier|*
name|sterr
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unlink_file
parameter_list|(
name|char
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|update
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xcmp
parameter_list|(
name|char
modifier|*
name|file1
parameter_list|,
name|char
modifier|*
name|file2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|yesno
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|time_t
name|get_date
parameter_list|(
name|char
modifier|*
name|date
parameter_list|,
name|struct
name|timeb
modifier|*
name|now
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Create_Admin
parameter_list|(
name|char
modifier|*
name|dir
parameter_list|,
name|char
modifier|*
name|repository
parameter_list|,
name|char
modifier|*
name|tag
parameter_list|,
name|char
modifier|*
name|date
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Lock_Cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ParseTag
parameter_list|(
name|char
modifier|*
modifier|*
name|tagp
parameter_list|,
name|char
modifier|*
modifier|*
name|datep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Scratch_Entry
parameter_list|(
name|List
modifier|*
name|list
parameter_list|,
name|char
modifier|*
name|fname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|WriteTag
parameter_list|(
name|char
modifier|*
name|dir
parameter_list|,
name|char
modifier|*
name|tag
parameter_list|,
name|char
modifier|*
name|date
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cat_module
parameter_list|(
name|int
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|check_entries
parameter_list|(
name|char
modifier|*
name|dir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|close_module
parameter_list|(
name|DBM
modifier|*
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|copy_file
parameter_list|(
name|char
modifier|*
name|from
parameter_list|,
name|char
modifier|*
name|to
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|error
parameter_list|(
name|int
name|status
parameter_list|,
name|int
name|errnum
parameter_list|,
name|char
modifier|*
name|message
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fperror
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
name|int
name|status
parameter_list|,
name|int
name|errnum
parameter_list|,
name|char
modifier|*
name|message
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_names
parameter_list|(
name|int
modifier|*
name|pargc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freevers_ts
parameter_list|(
name|Vers_TS
modifier|*
modifier|*
name|versp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ign_add
parameter_list|(
name|char
modifier|*
name|ign
parameter_list|,
name|int
name|hold
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ign_add_file
parameter_list|(
name|char
modifier|*
name|file
parameter_list|,
name|int
name|hold
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ign_setup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|line2argv
parameter_list|(
name|int
modifier|*
name|pargc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|make_directories
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|make_directory
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rename_file
parameter_list|(
name|char
modifier|*
name|from
parameter_list|,
name|char
modifier|*
name|to
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|run_arg
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|run_args
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|run_print
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|run_setup
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|strip_path
parameter_list|(
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|update_delproc
parameter_list|(
name|Node
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usage
parameter_list|(
name|char
modifier|*
modifier|*
name|cpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xchmod
parameter_list|(
name|char
modifier|*
name|fname
parameter_list|,
name|int
name|writable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Checkin
parameter_list|(
name|int
name|type
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|char
modifier|*
name|repository
parameter_list|,
name|char
modifier|*
name|rcs
parameter_list|,
name|char
modifier|*
name|rev
parameter_list|,
name|char
modifier|*
name|tag
parameter_list|,
name|char
modifier|*
name|message
parameter_list|,
name|List
modifier|*
name|entries
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Ctype
name|Classify_File
parameter_list|(
name|char
modifier|*
name|file
parameter_list|,
name|char
modifier|*
name|tag
parameter_list|,
name|char
modifier|*
name|date
parameter_list|,
name|char
modifier|*
name|options
parameter_list|,
name|int
name|force_tag_match
parameter_list|,
name|int
name|aflag
parameter_list|,
name|char
modifier|*
name|repository
parameter_list|,
name|List
modifier|*
name|entries
parameter_list|,
name|List
modifier|*
name|srcfiles
parameter_list|,
name|Vers_TS
modifier|*
modifier|*
name|versp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|List
modifier|*
name|Find_Names
parameter_list|(
name|char
modifier|*
name|repository
parameter_list|,
name|int
name|which
parameter_list|,
name|int
name|aflag
parameter_list|,
name|List
modifier|*
modifier|*
name|optentries
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Register
parameter_list|(
name|List
modifier|*
name|list
parameter_list|,
name|char
modifier|*
name|fname
parameter_list|,
name|char
modifier|*
name|vn
parameter_list|,
name|char
modifier|*
name|ts
parameter_list|,
name|char
modifier|*
name|options
parameter_list|,
name|char
modifier|*
name|tag
parameter_list|,
name|char
modifier|*
name|date
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Update_Logfile
parameter_list|(
name|char
modifier|*
name|repository
parameter_list|,
name|char
modifier|*
name|xmessage
parameter_list|,
name|char
modifier|*
name|xrevision
parameter_list|,
name|FILE
modifier|*
name|xlogfp
parameter_list|,
name|List
modifier|*
name|xchanges
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Vers_TS
modifier|*
name|Version_TS
parameter_list|(
name|char
modifier|*
name|repository
parameter_list|,
name|char
modifier|*
name|options
parameter_list|,
name|char
modifier|*
name|tag
parameter_list|,
name|char
modifier|*
name|date
parameter_list|,
name|char
modifier|*
name|user
parameter_list|,
name|int
name|force_tag_match
parameter_list|,
name|int
name|set_time
parameter_list|,
name|List
modifier|*
name|entries
parameter_list|,
name|List
modifier|*
name|xfiles
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_editor
parameter_list|(
name|char
modifier|*
name|dir
parameter_list|,
name|char
modifier|*
name|message
parameter_list|,
name|char
modifier|*
name|repository
parameter_list|,
name|List
modifier|*
name|changes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_module
parameter_list|(
name|DBM
modifier|*
name|db
parameter_list|,
name|char
modifier|*
name|mname
parameter_list|,
name|enum
name|mtype
name|m_type
parameter_list|,
name|char
modifier|*
name|msg
parameter_list|,
name|int
function_decl|(
modifier|*
name|callback_proc
function_decl|)
parameter_list|()
parameter_list|,
name|char
modifier|*
name|where
parameter_list|,
name|int
name|shorten
parameter_list|,
name|int
name|local_specified
parameter_list|,
name|int
name|run_module_prog
parameter_list|,
name|char
modifier|*
name|extra_arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_recursion
parameter_list|(
name|int
function_decl|(
modifier|*
name|xfileproc
function_decl|)
parameter_list|()
parameter_list|,
name|int
function_decl|(
modifier|*
name|xfilesdoneproc
function_decl|)
parameter_list|()
parameter_list|,
name|Dtype
function_decl|(
modifier|*
name|xdirentproc
function_decl|)
parameter_list|()
parameter_list|,
name|int
function_decl|(
modifier|*
name|xdirleaveproc
function_decl|)
parameter_list|()
parameter_list|,
name|Dtype
name|xflags
parameter_list|,
name|int
name|xwhich
parameter_list|,
name|int
name|xaflag
parameter_list|,
name|int
name|xreadlock
parameter_list|,
name|int
name|xdosrcs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_update
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|xoptions
parameter_list|,
name|char
modifier|*
name|xtag
parameter_list|,
name|char
modifier|*
name|xdate
parameter_list|,
name|int
name|xforce
parameter_list|,
name|int
name|local
parameter_list|,
name|int
name|xbuild
parameter_list|,
name|int
name|xaflag
parameter_list|,
name|int
name|xprune
parameter_list|,
name|int
name|xpipeout
parameter_list|,
name|int
name|which
parameter_list|,
name|char
modifier|*
name|xjoin_rev1
parameter_list|,
name|char
modifier|*
name|xjoin_rev2
parameter_list|,
name|char
modifier|*
name|xK_flag
parameter_list|,
name|char
modifier|*
name|preload_update_dir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|history_write
parameter_list|(
name|int
name|type
parameter_list|,
name|char
modifier|*
name|update_dir
parameter_list|,
name|char
modifier|*
name|revs
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|repository
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|start_recursion
parameter_list|(
name|int
function_decl|(
modifier|*
name|fileproc
function_decl|)
parameter_list|()
parameter_list|,
name|int
function_decl|(
modifier|*
name|filesdoneproc
function_decl|)
parameter_list|()
parameter_list|,
name|Dtype
function_decl|(
modifier|*
name|direntproc
function_decl|)
parameter_list|()
parameter_list|,
name|int
function_decl|(
modifier|*
name|dirleaveproc
function_decl|)
parameter_list|()
parameter_list|,
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|int
name|local
parameter_list|,
name|int
name|which
parameter_list|,
name|int
name|aflag
parameter_list|,
name|int
name|readlock
parameter_list|,
name|char
modifier|*
name|update_preload
parameter_list|,
name|int
name|dosrcs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SIG_beginCrSect
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SIG_endCrSect
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__STDC__ */
end_comment

begin_function_decl
name|DBM
modifier|*
name|open_module
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|Fopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|open_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|List
modifier|*
name|Find_Dirs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|List
modifier|*
name|Find_Names
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|List
modifier|*
name|ParseEntries
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Vers_TS
modifier|*
name|Version_TS
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Make_Date
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Name_Repository
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Short_Repository
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getcaller
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|time_stamp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xmalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xrealloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xstrdup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Checkin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Ctype
name|Classify_File
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|No_Difference
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Parse_Info
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Reader_Lock
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|SIG_register
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Writer_Lock
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_module
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_recursion
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_update
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gethostname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ign_name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isdir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|islink
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isreadable
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iswritable
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|link_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|numdots
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|run_exec
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|start_recursion
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unlink_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|update
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xcmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|yesno
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|time_t
name|get_date
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Create_Admin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Lock_Cleanup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ParseTag
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ParseTag
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Register
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Scratch_Entry
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Update_Logfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|WriteTag
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cat_module
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|check_entries
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|close_module
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|copy_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_editor
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|error
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fperror
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_names
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freevers_ts
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|history_write
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ign_add
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ign_add_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ign_setup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|line2argv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|make_directories
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|make_directory
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rename_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|run_arg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|run_args
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|run_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|run_setup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|strip_path
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|update_delproc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usage
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xchmod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SIG_beginCrSect
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SIG_endCrSect
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

end_unit

