begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, Brian Berliner and Jeff Polk  * Copyright (c) 1989-1992, Brian Berliner  *  * You may distribute under the terms of the GNU General Public License as  * specified in the README file that comes with the CVS kit.  */
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
comment|/* Changed from if __STDC__ to ifdef __STDC__ because of Sun's acc compiler */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

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

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* Under OS/2,<stdio.h> doesn't define popen()/pclose(). */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_OWN_POPEN
end_ifdef

begin_include
include|#
directive|include
file|"popen.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|STDC_HEADERS
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|exit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
end_ifdef

begin_comment
comment|/* If the system doesn't provide strerror, it won't be declared in    string.h.  */
end_comment

begin_function_decl
name|char
modifier|*
name|strerror
parameter_list|()
function_decl|;
end_function_decl

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SERVER_SUPPORT
argument_list|)
operator|||
name|defined
argument_list|(
name|CLIENT_SUPPORT
argument_list|)
end_if

begin_include
include|#
directive|include
file|"client.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* This actually gets set in system.h.  Note that the _ONLY_ reason for    this is if various system calls (getwd, getcwd, readlink) require/want    us to use it.  All other parts of CVS allocate pathname buffers    dynamically, and we want to keep it that way.  */
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
comment|/* Definitions for the CVS Administrative directory and the files it contains.    Here as #define's to make changing the names a simple task.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_VMS_FILENAMES
end_ifdef

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
value|"CVS/Entries."
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
name|CVSADM_ENTLOG
value|"CVS/Entries.Log"
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
value|"CVS/Repository."
end_define

begin_define
define|#
directive|define
name|CVSADM_ROOT
value|"CVS/Root."
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
value|"CVS/Tag."
end_define

begin_define
define|#
directive|define
name|CVSADM_NOTIFY
value|"CVS/Notify."
end_define

begin_define
define|#
directive|define
name|CVSADM_NOTIFYTMP
value|"CVS/Notify.tmp"
end_define

begin_define
define|#
directive|define
name|CVSADM_BASE
value|"CVS/Base"
end_define

begin_define
define|#
directive|define
name|CVSADM_BASEREV
value|"CVS/Baserev."
end_define

begin_define
define|#
directive|define
name|CVSADM_BASEREVTMP
value|"CVS/Baserev.tmp"
end_define

begin_define
define|#
directive|define
name|CVSADM_TEMPLATE
value|"CVS/Template."
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* USE_VMS_FILENAMES */
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
name|CVSADM_ENTLOG
value|"CVS/Entries.Log"
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

begin_define
define|#
directive|define
name|CVSADM_NOTIFY
value|"CVS/Notify"
end_define

begin_define
define|#
directive|define
name|CVSADM_NOTIFYTMP
value|"CVS/Notify.tmp"
end_define

begin_comment
comment|/* A directory in which we store base versions of files we currently are    editing with "cvs edit".  */
end_comment

begin_define
define|#
directive|define
name|CVSADM_BASE
value|"CVS/Base"
end_define

begin_define
define|#
directive|define
name|CVSADM_BASEREV
value|"CVS/Baserev"
end_define

begin_define
define|#
directive|define
name|CVSADM_BASEREVTMP
value|"CVS/Baserev.tmp"
end_define

begin_comment
comment|/* File which contains the template for use in log messages.  */
end_comment

begin_define
define|#
directive|define
name|CVSADM_TEMPLATE
value|"CVS/Template"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_VMS_FILENAMES */
end_comment

begin_comment
comment|/* This is the special directory which we use to store various extra    per-directory information in the repository.  It must be the same as    CVSADM to avoid creating a new reserved directory name which users cannot    use, but is a separate #define because if anyone changes it (which I don't    recommend), one needs to deal with old, unconverted, repositories.        See fileattr.h for details about file attributes, the only thing stored    in CVSREP currently.  */
end_comment

begin_define
define|#
directive|define
name|CVSREP
value|"CVS"
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
name|CVSROOTADM_TAGINFO
value|"taginfo"
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
name|CVSROOTADM_VERIFYMSG
value|"verifymsg"
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
name|CVSROOTADM_VALTAGS
value|"val-tags"
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
name|CVSROOTADM_WRAPPER
value|"cvswrappers"
end_define

begin_define
define|#
directive|define
name|CVSROOTADM_NOTIFY
value|"notify"
end_define

begin_define
define|#
directive|define
name|CVSROOTADM_USERS
value|"users"
end_define

begin_define
define|#
directive|define
name|CVSROOTADM_READERS
value|"readers"
end_define

begin_define
define|#
directive|define
name|CVSROOTADM_WRITERS
value|"writers"
end_define

begin_define
define|#
directive|define
name|CVSROOTADM_PASSWD
value|"passwd"
end_define

begin_define
define|#
directive|define
name|CVSROOTADM_CONFIG
value|"config"
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
comment|/* Other CVS file names */
end_comment

begin_comment
comment|/* Files go in the attic if the head main branch revision is dead,    otherwise they go in the regular repository directories.  The whole    concept of having an attic is sort of a relic from before death    support but on the other hand, it probably does help the speed of    some operations (such as main branch checkouts and updates).  */
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

begin_define
define|#
directive|define
name|CVSDOTWRAPPER
value|".cvswrappers"
end_define

begin_comment
comment|/* Command attributes -- see function lookup_command_attribute(). */
end_comment

begin_define
define|#
directive|define
name|CVS_CMD_IGNORE_ADMROOT
value|1
end_define

begin_comment
comment|/* Set if CVS needs to create a CVS/Root file upon completion of this    command.  The name may be slightly confusing, because the flag    isn't really as general purpose as it seems (it is not set for cvs    release).  */
end_comment

begin_define
define|#
directive|define
name|CVS_CMD_USES_WORK_DIR
value|2
end_define

begin_define
define|#
directive|define
name|CVS_CMD_MODIFIES_REPOSITORY
value|4
end_define

begin_comment
comment|/* miscellaneous CVS defines */
end_comment

begin_comment
comment|/* This is the string which is at the start of the non-log-message lines    that we put up for the user when they edit the log message.  */
end_comment

begin_define
define|#
directive|define
name|CVSEDITPREFIX
value|"CVS: "
end_define

begin_comment
comment|/* Number of characters in CVSEDITPREFIX to compare when deciding to strip    off those lines.  We don't check for the space, to accomodate users who    have editors which strip trailing spaces.  */
end_comment

begin_define
define|#
directive|define
name|CVSEDITPREFIXLEN
value|4
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

begin_ifdef
ifdef|#
directive|ifdef
name|USE_VMS_FILENAMES
end_ifdef

begin_define
define|#
directive|define
name|BAKPREFIX
value|"_$"
end_define

begin_define
define|#
directive|define
name|DEVNULL
value|"NLA0:"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* USE_VMS_FILENAMES */
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

begin_ifndef
ifndef|#
directive|ifndef
name|DEVNULL
end_ifndef

begin_define
define|#
directive|define
name|DEVNULL
value|"/dev/null"
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
comment|/* USE_VMS_FILENAMES */
end_comment

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
value|0
end_define

begin_comment
comment|/* writable files by default */
end_comment

begin_define
define|#
directive|define
name|TMPDIR_ENV
value|"TMPDIR"
end_define

begin_comment
comment|/* Temporary directory */
end_comment

begin_comment
comment|/* #define	TMPDIR_DFLT		   Set by options.h */
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
value|"VISUAL"
end_define

begin_comment
comment|/* which editor to use */
end_comment

begin_define
define|#
directive|define
name|EDITOR3_ENV
value|"EDITOR"
end_define

begin_comment
comment|/* which editor to use */
end_comment

begin_comment
comment|/* #define	EDITOR_DFLT		   Set by options.h */
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

begin_define
define|#
directive|define
name|WRAPPER_ENV
value|"CVSWRAPPERS"
end_define

begin_comment
comment|/* name of the wrapper file */
end_comment

begin_define
define|#
directive|define
name|CVSUMASK_ENV
value|"CVSUMASK"
end_define

begin_comment
comment|/* Effective umask for repository */
end_comment

begin_comment
comment|/* #define	CVSUMASK_DFLT		   Set by options.h */
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
comment|/* Large enough to hold DATEFORM.  Not an arbitrary limit as long as    it is used for that purpose, and not to hold a string from the    command line, the client, etc.  */
end_comment

begin_define
define|#
directive|define
name|MAXDATELEN
value|50
end_define

begin_comment
comment|/* The type of an entnode.  */
end_comment

begin_enum
enum|enum
name|ent_type
block|{
name|ENT_FILE
block|,
name|ENT_SUBDIR
block|}
enum|;
end_enum

begin_comment
comment|/* structure of a entry record */
end_comment

begin_struct
struct|struct
name|entnode
block|{
name|enum
name|ent_type
name|type
decl_stmt|;
name|char
modifier|*
name|user
decl_stmt|;
name|char
modifier|*
name|version
decl_stmt|;
comment|/* Timestamp, or "" if none (never NULL).  */
name|char
modifier|*
name|timestamp
decl_stmt|;
comment|/* Keyword expansion options, or "" if none (never NULL).  */
name|char
modifier|*
name|options
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
name|conflict
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|entnode
name|Entnode
typedef|;
end_typedef

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
block|,
name|EXPORT
block|}
enum|;
end_enum

begin_comment
comment|/*  * structure used for list-private storage by Entries_Open() and  * Version_TS() and Find_Directories().  */
end_comment

begin_struct
struct|struct
name|stickydirtag
block|{
comment|/* These fields pass sticky tag information from Entries_Open() to        Version_TS().  */
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
name|int
name|nonbranch
decl_stmt|;
comment|/* This field is set by Entries_Open() if there was subdirectory        information; Find_Directories() uses it to see whether it needs        to scan the directory itself.  */
name|int
name|subdirs
decl_stmt|;
block|}
struct|;
end_struct

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

begin_ifdef
ifdef|#
directive|ifdef
name|ENUMS_CAN_BE_TROUBLE
end_ifdef

begin_typedef
typedef|typedef
name|int
name|Dtype
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|enum
name|direnter_type
name|Dtype
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|program_name
decl_stmt|,
modifier|*
name|program_path
decl_stmt|,
modifier|*
name|command_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Tmpdir
decl_stmt|,
modifier|*
name|Editor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cvsadmin_root
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
name|mode_t
name|cvsumask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Access method specified in CVSroot. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|local_method
block|,
name|server_method
block|,
name|pserver_method
block|,
name|kserver_method
block|,
name|gserver_method
block|,
name|ext_method
block|}
name|CVSmethod
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|method_names
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* change this in root.c if you change 				   the enum above */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|CVSroot_original
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the active, complete CVSroot string */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|client_active
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* nonzero if we are doing remote access */
end_comment

begin_decl_stmt
specifier|extern
name|CVSmethod
name|CVSroot_method
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* one of the enum values above */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|CVSroot_username
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the username or NULL if method == local */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|CVSroot_hostname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the hostname or NULL if method == local */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|CVSroot_directory
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the directory name */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|emptydir_name
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
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
name|AUTH_SERVER_SUPPORT
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Pserver_Repos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used to check that same repos is                                    transmitted in pserver auth and in                                    CVS protocol. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUTH_SERVER_SUPPORT */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|hostname
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Externs that are included directly in the CVS sources */
end_comment

begin_decl_stmt
name|int
name|RCS_merge
name|PROTO
argument_list|(
operator|(
name|RCSNode
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
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
comment|/* Flags used by RCS_* functions.  See the description of the individual    functions for which flags mean what for each function.  */
end_comment

begin_define
define|#
directive|define
name|RCS_FLAGS_FORCE
value|1
end_define

begin_define
define|#
directive|define
name|RCS_FLAGS_DEAD
value|2
end_define

begin_define
define|#
directive|define
name|RCS_FLAGS_QUIET
value|4
end_define

begin_define
define|#
directive|define
name|RCS_FLAGS_MODTIME
value|8
end_define

begin_decl_stmt
specifier|extern
name|int
name|RCS_exec_rcsdiff
name|PROTO
argument_list|(
operator|(
name|RCSNode
operator|*
name|rcsfile
operator|,
name|char
operator|*
name|opts
operator|,
name|char
operator|*
name|options
operator|,
name|char
operator|*
name|rev1
operator|,
name|char
operator|*
name|rev2
operator|,
name|char
operator|*
name|label1
operator|,
name|char
operator|*
name|label2
operator|,
name|char
operator|*
name|workfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|diff_exec
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
operator|,
name|char
operator|*
name|options
operator|,
name|char
operator|*
name|out
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|diff_execv
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
operator|,
name|char
operator|*
name|label1
operator|,
name|char
operator|*
name|label2
operator|,
name|char
operator|*
name|options
operator|,
name|char
operator|*
name|out
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_include
include|#
directive|include
file|"error.h"
end_include

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
name|open_file
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|List
modifier|*
name|Find_Directories
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
name|List
operator|*
name|entries
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Entries_Close
name|PROTO
argument_list|(
operator|(
name|List
operator|*
name|entries
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|List
modifier|*
name|Entries_Open
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
name|void
name|Subdirs_Known
name|PROTO
argument_list|(
operator|(
name|List
operator|*
name|entries
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Subdir_Register
name|PROTO
argument_list|(
operator|(
name|List
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Subdir_Deregister
name|PROTO
argument_list|(
operator|(
name|List
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
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
name|void
name|Sanitize_Repository_Name
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
name|int
name|parse_cvsroot
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|CVSroot
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|set_local_cvsroot
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
name|void
name|root_allow_add
name|PROTO
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
name|root_allow_free
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
name|root_allow_ok
name|PROTO
argument_list|(
operator|(
name|char
operator|*
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
specifier|const
name|char
operator|*
name|rev1
operator|,
specifier|const
name|char
operator|*
name|rev2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|check_numeric
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|*
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
name|void
modifier|*
name|xrealloc
name|PROTO
argument_list|(
operator|(
name|void
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
name|void
name|expand_string
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|,
name|size_t
operator|*
operator|,
name|size_t
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
specifier|const
name|char
operator|*
name|str
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|strip_trailing_newlines
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
name|pathname_levels
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

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*CALLPROC
argument_list|)
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|repository
operator|,
name|char
operator|*
name|value
operator|)
argument_list|)
expr_stmt|;
end_typedef

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
name|CALLPROC
name|callproc
operator|,
name|int
name|all
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|parse_config
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|RETSIGTYPE
argument_list|(
argument|*SIGCLEANUPPROC
argument_list|)
name|PROTO
argument_list|(
operator|(
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_decl_stmt
name|int
name|SIG_register
name|PROTO
argument_list|(
operator|(
name|int
name|sig
operator|,
name|SIGCLEANUPPROC
name|sigcleanup
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
specifier|const
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
specifier|const
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
specifier|const
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
specifier|const
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
specifier|const
name|char
operator|*
name|file
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isaccessible
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|file
operator|,
specifier|const
name|int
name|mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isabsolute
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|filename
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|last_component
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
name|char
modifier|*
name|get_homedir
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
name|cvs_temp_name
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
name|numdots
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|increment_revnum
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|compare_revnums
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
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
specifier|const
name|char
operator|*
name|f
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
specifier|const
name|char
operator|*
name|from
operator|,
specifier|const
name|char
operator|*
name|to
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|unlink_file_dir
name|PROTO
argument_list|(
operator|(
specifier|const
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
specifier|const
name|char
operator|*
name|file1
operator|,
specifier|const
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
name|void
modifier|*
name|valloc
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
specifier|extern
name|int
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
name|update_dir
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
operator|,
name|int
name|nonbranch
operator|,
name|int
name|warn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|expand_at_signs
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|off_t
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Locking subsystem (implemented in lock.c).  */
end_comment

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

begin_comment
comment|/* Writelock an entire subtree, well the part specified by ARGC, ARGV, LOCAL,    and AFLAG, anyway.  */
end_comment

begin_decl_stmt
name|void
name|lock_tree_for_write
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|,
name|int
name|local
operator|,
name|int
name|aflag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* See lock.c for description.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|lock_dir_for_write
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

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
operator|,
name|int
operator|*
name|nonbranchp
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
operator|,
name|int
name|nonbranch
operator|,
name|char
operator|*
name|update_dir
operator|,
name|char
operator|*
name|repository
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
specifier|const
name|char
operator|*
name|from
operator|,
specifier|const
name|char
operator|*
name|to
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
specifier|extern
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

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*Ignore_proc
argument_list|)
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|extern
name|void
name|ignore_files
name|PROTO
argument_list|(
operator|(
name|List
operator|*
operator|,
name|List
operator|*
operator|,
name|char
operator|*
operator|,
name|Ignore_proc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ign_inhibit_server
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ign_case
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"update.h"
end_include

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
operator|*
operator|*
name|argv
operator|,
name|char
operator|*
name|line
operator|,
name|char
operator|*
name|sepchars
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
specifier|const
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
specifier|const
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mkdir_if_needed
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
specifier|const
name|char
operator|*
name|from
operator|,
specifier|const
name|char
operator|*
name|to
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Expand wildcards in each element of (ARGC,ARGV).  This is according to the    files which exist in the current directory, and accordingly to OS-specific    conventions regarding wildcard syntax.  It might be desirable to change the    former in the future (e.g. "cvs status *.h" including files which don't exist    in the working directory).  The result is placed in *PARGC and *PARGV;    the *PARGV array itself and all the strings it contains are newly    malloc'd.  It is OK to call it with PARGC ==&ARGC or PARGV ==&ARGV.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|expand_wild
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|,
name|int
operator|*
name|pargc
operator|,
name|char
operator|*
operator|*
operator|*
name|pargv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|cvs_casecmp
name|PROTO
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

begin_decl_stmt
specifier|extern
name|int
name|fopen_case
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|FILE
operator|*
operator|*
operator|,
name|char
operator|*
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
specifier|const
name|char
operator|*
specifier|const
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
name|char
modifier|*
name|xgetwd
name|PROTO
argument_list|(
operator|(
name|void
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
name|void
name|do_verify
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|message
operator|,
name|char
operator|*
name|repository
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*CALLBACKPROC
argument_list|)
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
name|where
operator|,
name|char
operator|*
name|mwhere
operator|,
name|char
operator|*
name|mfile
operator|,
name|int
name|shorten
operator|,
name|int
name|local_specified
operator|,
name|char
operator|*
name|omodule
operator|,
name|char
operator|*
name|msg
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_comment
comment|/* This is the structure that the recursion processor passes to the    fileproc to tell it about a particular file.  */
end_comment

begin_struct
struct|struct
name|file_info
block|{
comment|/* Name of the file, without any directory component.  */
name|char
modifier|*
name|file
decl_stmt|;
comment|/* Name of the directory we are in, relative to the directory in        which this command was issued.  We have cd'd to this directory        (either in the working directory or in the repository, depending        on which sort of recursion we are doing).  If we are in the directory        in which the command was issued, this is "".  */
name|char
modifier|*
name|update_dir
decl_stmt|;
comment|/* update_dir and file put together, with a slash between them as        necessary.  This is the proper way to refer to the file in user        messages.  */
name|char
modifier|*
name|fullname
decl_stmt|;
comment|/* Name of the directory corresponding to the repository which contains        this file.  */
name|char
modifier|*
name|repository
decl_stmt|;
comment|/* The pre-parsed entries for this directory.  */
name|List
modifier|*
name|entries
decl_stmt|;
name|RCSNode
modifier|*
name|rcs
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*FILEPROC
argument_list|)
name|PROTO
argument_list|(
operator|(
name|void
operator|*
name|callerdat
operator|,
expr|struct
name|file_info
operator|*
name|finfo
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*FILESDONEPROC
argument_list|)
name|PROTO
argument_list|(
operator|(
name|void
operator|*
name|callerdat
operator|,
name|int
name|err
operator|,
name|char
operator|*
name|repository
operator|,
name|char
operator|*
name|update_dir
operator|,
name|List
operator|*
name|entries
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|Dtype
argument_list|(
argument|*DIRENTPROC
argument_list|)
name|PROTO
argument_list|(
operator|(
name|void
operator|*
name|callerdat
operator|,
name|char
operator|*
name|dir
operator|,
name|char
operator|*
name|repos
operator|,
name|char
operator|*
name|update_dir
operator|,
name|List
operator|*
name|entries
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*DIRLEAVEPROC
argument_list|)
name|PROTO
argument_list|(
operator|(
name|void
operator|*
name|callerdat
operator|,
name|char
operator|*
name|dir
operator|,
name|int
name|err
operator|,
name|char
operator|*
name|update_dir
operator|,
name|List
operator|*
name|entries
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|mkmodules
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
specifier|extern
name|int
name|init
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
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
name|CALLBACKPROC
name|callback_proc
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
name|FILEPROC
name|fileproc
operator|,
name|FILESDONEPROC
name|filesdoneproc
operator|,
name|DIRENTPROC
name|direntproc
operator|,
name|DIRLEAVEPROC
name|dirleaveproc
operator|,
name|void
operator|*
name|callerdat
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
operator|,
name|char
operator|*
name|cmdname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|make_message_rcslegal
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|message
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|file_has_markers
name|PROTO
argument_list|(
operator|(
specifier|const
expr|struct
name|file_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|get_file
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|size_t
operator|*
operator|,
name|size_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|void
name|run_arg
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|s
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
specifier|const
name|char
operator|*
name|prog
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
specifier|const
name|char
operator|*
name|stin
operator|,
specifier|const
name|char
operator|*
name|stout
operator|,
specifier|const
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

begin_comment
comment|/* other similar-minded stuff from run.c.  */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|run_popen
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|piped_child
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|close_on_exec
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|filter_stream_through_program
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|,
name|pid_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pid_t
name|waitpid
name|PROTO
argument_list|(
operator|(
name|pid_t
operator|,
name|int
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*  * a struct vers_ts contains all the information about a file including the  * user and rcs file names, and the version checked out and the head.  *  * this is usually obtained from a call to Version_TS which takes a  * tag argument for the RCS file if desired  */
end_comment

begin_struct
struct|struct
name|vers_ts
block|{
comment|/* rcs version user file derives from, from CVS/Entries.        It can have the following special values:         NULL = file is not mentioned in Entries (this is also used for a 	      directory).        "" = ILLEGAL!  The comment used to say that it meant "no user file" 	    but as far as I know CVS didn't actually use it that way. 	    Note that according to cvs.texinfo, "" is not legal in the 	    Entries file.        0 = user file is new        -vers = user file to be removed.  */
name|char
modifier|*
name|vn_user
decl_stmt|;
comment|/* Numeric revision number corresponding to ->vn_tag (->vn_tag        will often be symbolic).  */
name|char
modifier|*
name|vn_rcs
decl_stmt|;
comment|/* If ->tag is a simple tag in the RCS file--a tag which really        exists which is not a magic revision--and if ->date is NULL,        then this is a copy of ->tag.  Otherwise, it is a copy of        ->vn_rcs.  */
name|char
modifier|*
name|vn_tag
decl_stmt|;
comment|/* This is the timestamp from stating the file in the working directory.        It is NULL if there is no file in the working directory.  It is        "Is-modified" if we know the file is modified but don't have its        contents.  */
name|char
modifier|*
name|ts_user
decl_stmt|;
comment|/* Timestamp from CVS/Entries.  For the server, ts_user and ts_rcs        are computed in a slightly different way, but the fact remains that        if they are equal the file in the working directory is unmodified        and if they differ it is modified.  */
name|char
modifier|*
name|ts_rcs
decl_stmt|;
comment|/* Options from CVS/Entries (keyword expansion), malloc'd.  If none,        then it is an empty string (never NULL).  */
name|char
modifier|*
name|options
decl_stmt|;
comment|/* If non-NULL, there was a conflict (or merely a merge?  See merge_file)        and the time stamp in this field is the time stamp of the working        directory file which was created with the conflict markers in it.        This is from CVS/Entries.  */
name|char
modifier|*
name|ts_conflict
decl_stmt|;
comment|/* Tag specified on the command line, or if none, tag stored in        CVS/Entries.  */
name|char
modifier|*
name|tag
decl_stmt|;
comment|/* Date specified on the command line, or if none, date stored in        CVS/Entries.  */
name|char
modifier|*
name|date
decl_stmt|;
comment|/* If this is 1, then tag is not a branch tag.  If this is 0, then        tag may or may not be a branch tag.  */
name|int
name|nonbranch
decl_stmt|;
comment|/* Pointer to entries file node  */
name|Entnode
modifier|*
name|entdata
decl_stmt|;
comment|/* Pointer to parsed src file info */
name|RCSNode
modifier|*
name|srcfile
decl_stmt|;
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

begin_decl_stmt
name|Vers_TS
modifier|*
name|Version_TS
name|PROTO
argument_list|(
operator|(
expr|struct
name|file_info
operator|*
name|finfo
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
name|int
name|force_tag_match
operator|,
name|int
name|set_time
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

begin_escape
end_escape

begin_comment
comment|/* Miscellaneous CVS infrastructure which layers on top of the recursion    processor (for example, needs struct file_info).  */
end_comment

begin_decl_stmt
name|int
name|Checkin
name|PROTO
argument_list|(
operator|(
name|int
name|type
operator|,
expr|struct
name|file_info
operator|*
name|finfo
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
expr|struct
name|file_info
operator|*
name|finfo
operator|,
name|Vers_TS
operator|*
name|vers
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CVSADM_BASEREV stuff, from entries.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|base_get
name|PROTO
argument_list|(
operator|(
expr|struct
name|file_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|base_register
name|PROTO
argument_list|(
operator|(
expr|struct
name|file_info
operator|*
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
name|base_deregister
name|PROTO
argument_list|(
operator|(
expr|struct
name|file_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
name|T_PATCH
block|,
comment|/* P Like C, but can patch	 */
endif|#
directive|endif
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

begin_decl_stmt
name|Ctype
name|Classify_File
name|PROTO
argument_list|(
operator|(
expr|struct
name|file_info
operator|*
name|finfo
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
name|Vers_TS
operator|*
operator|*
name|versp
operator|,
name|int
name|pipeout
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * structure used for list nodes passed to Update_Logfile() and  * do_editor().  */
end_comment

begin_struct
struct|struct
name|logfile_info
block|{
name|enum
name|classify_type
name|type
decl_stmt|;
name|char
modifier|*
name|tag
decl_stmt|;
name|char
modifier|*
name|rev_old
decl_stmt|;
comment|/* rev number before a commit/modify, 				   NULL for add or import */
name|char
modifier|*
name|rev_new
decl_stmt|;
comment|/* rev number after a commit/modify, 				   add, or import, NULL for remove */
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* Wrappers.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|WRAP_MERGE
block|,
name|WRAP_COPY
block|}
name|WrapMergeMethod
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* -t and -f wrapper options.  Treating directories as single files.  */
name|WRAP_TOCVS
block|,
name|WRAP_FROMCVS
block|,
comment|/* -k wrapper option.  Default keyword expansion options.  */
name|WRAP_RCSOPTION
block|}
name|WrapMergeHas
typedef|;
end_typedef

begin_decl_stmt
name|void
name|wrap_setup
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
name|wrap_name_has
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|,
name|WrapMergeHas
name|has
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|wrap_rcsoption
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|fileName
operator|,
name|int
name|asFlag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|wrap_tocvs_process_file
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|fileName
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wrap_merge_is_copy
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|fileName
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|wrap_fromcvs_process_file
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|fileName
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|wrap_add_file
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|file
operator|,
name|int
name|temp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|wrap_add
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|line
operator|,
name|int
name|temp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|wrap_send
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SERVER_SUPPORT
argument_list|)
operator|||
name|defined
argument_list|(
name|CLIENT_SUPPORT
argument_list|)
end_if

begin_decl_stmt
name|void
name|wrap_unparse_rcs_options
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SERVER_SUPPORT || CLIENT_SUPPORT */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Pathname expansion */
end_comment

begin_decl_stmt
name|char
modifier|*
name|expand_path
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|char
operator|*
name|file
operator|,
name|int
name|line
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* User variables.  */
end_comment

begin_decl_stmt
specifier|extern
name|List
modifier|*
name|variable_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|variable_set
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|nameval
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_decl_stmt
name|int
name|watch
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|edit
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|unedit
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|editors
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|watchers
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|annotate
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|add
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|admin
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|checkout
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|commit
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|diff
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|history
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|import
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cvslog
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|AUTH_CLIENT_SUPPORT
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|login
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|logout
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUTH_CLIENT_SUPPORT */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|patch
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|release
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cvsremove
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rtag
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|status
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cvstag
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|int
name|lookup_command_attribute
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AUTH_CLIENT_SUPPORT
argument_list|)
operator|||
name|defined
argument_list|(
name|AUTH_SERVER_SUPPORT
argument_list|)
end_if

begin_decl_stmt
name|char
modifier|*
name|scramble
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
name|char
modifier|*
name|descramble
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUTH_CLIENT_SUPPORT || AUTH_SERVER_SUPPORT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AUTH_CLIENT_SUPPORT
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|get_cvs_password
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUTH_CLIENT_SUPPORT */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|tag_check_valid
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|,
name|int
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
name|tag_check_valid_join
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* From server.c and documented there.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|cvs_output
name|PROTO
argument_list|(
operator|(
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
name|void
name|cvs_output_binary
name|PROTO
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
specifier|extern
name|void
name|cvs_outerr
name|PROTO
argument_list|(
operator|(
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
name|void
name|cvs_flusherr
name|PROTO
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
name|cvs_flushout
name|PROTO
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
name|cvs_output_tagged
name|PROTO
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

begin_escape
end_escape

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SERVER_SUPPORT
argument_list|)
operator|||
name|defined
argument_list|(
name|CLIENT_SUPPORT
argument_list|)
end_if

begin_include
include|#
directive|include
file|"server.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

