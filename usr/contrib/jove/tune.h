begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*************************************************************************  * This program is copyright (C) 1985, 1986 by Jonathan Payne.  It is    *  * provided to you without charge for use only on a licensed Unix        *  * system.  You may copy JOVE provided that this notice is included with *  * the copy.  You may not sell copies of this program or versions        *  * modified for use on microcomputer systems, unless the copies are      *  * included with a Unix system distribution and the source is provided.  *  *************************************************************************/
end_comment

begin_define
define|#
directive|define
name|TUNED
end_define

begin_comment
comment|/* don't touch this */
end_comment

begin_comment
comment|/*#define LSRHS		/* if this is Lincoln-Sudbury Regional High School */
end_comment

begin_define
define|#
directive|define
name|LOAD_AV
end_define

begin_comment
comment|/* Use the load average for various commands. 			   Do not define this if you lack a load average 			   system call and kmem is read protected. */
end_comment

begin_comment
comment|/* #define SYSV		/* for (System III/System V) UNIX systems */
end_comment

begin_define
define|#
directive|define
name|BACKUPFILES
end_define

begin_comment
comment|/* enable the backup files code */
end_comment

begin_define
define|#
directive|define
name|BIFF
end_define

begin_comment
comment|/* if you have biff (or the equivalent) */
end_comment

begin_define
define|#
directive|define
name|JOB_CONTROL
end_define

begin_comment
comment|/* if you have job stopping */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JOB_CONTROL
end_ifdef

begin_define
define|#
directive|define
name|MENLO_JCL
end_define

begin_define
define|#
directive|define
name|IPROCS
end_define

begin_comment
comment|/* Interactive processes.  PROCS only works 			   with JOB_CONTROL. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|F_COMPLETION
end_define

begin_comment
comment|/* filename completion */
end_comment

begin_define
define|#
directive|define
name|CHDIR
end_define

begin_comment
comment|/* change directory command and absolute pathnames */
end_comment

begin_comment
comment|/*#define	KILL0	/* kill(pid, 0) returns 0 if proc exists 			   Used by recover to test if jove is 			   still running. */
end_comment

begin_define
define|#
directive|define
name|SPELL
end_define

begin_comment
comment|/* spell words and buffer commands */
end_comment

begin_define
define|#
directive|define
name|ABBREV
end_define

begin_comment
comment|/* word abbreviation mode */
end_comment

begin_define
define|#
directive|define
name|LISP
end_define

begin_comment
comment|/* include the code for Lisp Mode */
end_comment

begin_define
define|#
directive|define
name|ID_CHAR
end_define

begin_comment
comment|/* include code to IDchar */
end_comment

begin_define
define|#
directive|define
name|WIRED_TERMS
end_define

begin_comment
comment|/* include code for wired terminals */
end_comment

begin_define
define|#
directive|define
name|ANSICODES
end_define

begin_comment
comment|/* Include extra commands that process 			   ANSI codes sequences.  Includes simple 			   mouse support pointing. */
end_comment

begin_define
define|#
directive|define
name|CMT_FMT
end_define

begin_comment
comment|/* include the comment formatting routines */
end_comment

begin_if
if|#
directive|if
operator|!
name|sun
end_if

begin_define
define|#
directive|define
name|MY_MALLOC
end_define

begin_comment
comment|/* use more memory efficient malloc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BSD4_2
end_define

begin_comment
comment|/* Berkeley 4.2 BSD */
end_comment

begin_define
define|#
directive|define
name|BSD4_3
end_define

begin_comment
comment|/* Berkeley 4.3 BSD */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4_3
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|BSD4_2
end_ifndef

begin_define
define|#
directive|define
name|BSD4_2
end_define

begin_comment
comment|/* 4.3 is 4.2 only different. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4_3
end_ifdef

begin_define
define|#
directive|define
name|RESHAPING
end_define

begin_comment
comment|/* enable windows to handle reshaping */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4_2
end_ifdef

begin_comment
comment|/* byte_copy(from, to, len) */
end_comment

begin_define
define|#
directive|define
name|byte_copy
value|bcopy
end_define

begin_comment
comment|/* use fast assembler version */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|vax
operator|||
name|sel
operator|||
name|sun
operator|||
name|pyr
operator|||
name|mc68000
operator|||
name|tahoe
end_if

begin_define
define|#
directive|define
name|VMUNIX
end_define

begin_comment
comment|/* Virtual Memory UNIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VMUNIX
end_ifndef

begin_typedef
typedef|typedef
name|short
name|disk_line
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BUFSIZ
value|512
end_define

begin_comment
comment|/* or 1024 */
end_comment

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int
name|disk_line
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BUFSIZ
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DFLT_MODE
value|0666
end_define

begin_comment
comment|/* file will be created with this mode */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMUNIX
end_ifdef

begin_define
define|#
directive|define
name|NBUF
value|64
end_define

begin_comment
comment|/* number of disk buffers */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NBUF
value|3
end_define

begin_comment
comment|/* only 3 because there is a bug */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IPROCS
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|NOEXTERNS
end_ifndef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|PORTSRV
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4_2
end_ifdef

begin_define
define|#
directive|define
name|INPUT_SIG
value|SIGIO
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PIPEPROCS
end_define

begin_comment
comment|/* do it with pipes */
end_comment

begin_define
define|#
directive|define
name|INPUT_SIG
value|SIGTINT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_define
define|#
directive|define
name|rindex
value|strrchr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* These are here since they define things in tune.c.  If you add things to    tune.c, add them here too, if necessary. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOEXTERNS
end_ifndef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|TMP_DIR
decl_stmt|,
modifier|*
name|REC_DIR
decl_stmt|,
modifier|*
name|TMPFILE
decl_stmt|,
modifier|*
name|RECFILE
decl_stmt|,
modifier|*
name|REC_BASE
decl_stmt|,
modifier|*
name|RECOVER
decl_stmt|,
modifier|*
name|CMD_DB
decl_stmt|,
modifier|*
name|JOVERC
decl_stmt|,
name|Shell
index|[]
decl_stmt|,
name|ShFlags
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|NOEXTERNS
end_endif

end_unit

