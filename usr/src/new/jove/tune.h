begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
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
comment|/*#define MAC 1		/* alas, there is no command line for this */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_define
define|#
directive|define
name|defined
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_comment
comment|/* take this out and you're in trouble... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The operating system (MSDOS or MAC) must be defined by this point.    IBMPC is defined in the Makefile. All MAC defines should be    numerical (i.e. #define MAC 1) so that defined() will work. */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|||
name|defined
argument_list|(
name|MAC
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|UNIX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX
end_ifdef

begin_comment
comment|/* pick your version of Unix */
end_comment

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
comment|/* Berkeley 4.3 BSD and 2.10 BSD */
end_comment

begin_comment
comment|/*# define SYSV		/* for (System III/System V) UNIX systems */
end_comment

begin_comment
comment|/*# define SYSVR2	/* system 5, rel. 2 */
end_comment

begin_comment
comment|/* M_XENIX is defined by the Compiler */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSVR2
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|SYSV
end_ifndef

begin_define
define|#
directive|define
name|SYSV
end_define

begin_comment
comment|/* SYSV is a subset of SYSVR2 */
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
name|M_XENIX
end_ifdef

begin_define
define|#
directive|define
name|iAPX286
value|1
end_define

begin_comment
comment|/* we have segments. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MSDOS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|M_I86LM
end_ifdef

begin_comment
comment|/* large memory model */
end_comment

begin_define
define|#
directive|define
name|NBUF
value|64
end_define

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

begin_define
define|#
directive|define
name|SMALL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BUFSIZ
value|512
end_define

begin_comment
comment|/* or 1024 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX
end_ifdef

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
operator|||
name|iAPX286
operator|||
name|GOULD_NP1
operator|||
name|u3b2
operator|||
name|accel
end_if

begin_define
define|#
directive|define
name|VMUNIX
end_define

begin_comment
comment|/* Virtual Memory UNIX */
end_comment

begin_define
define|#
directive|define
name|BUFSIZ
value|1024
end_define

begin_if
if|#
directive|if
name|iAPX286
end_if

begin_define
define|#
directive|define
name|NBUF
value|48
end_define

begin_comment
comment|/* NBUF*BUFSIZ must be less than 64 kB */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NBUF
value|64
end_define

begin_comment
comment|/* number of disk buffers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* iAPX286 */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SMALL
end_define

begin_define
define|#
directive|define
name|BUFSIZ
value|512
end_define

begin_comment
comment|/* or 1024 */
end_comment

begin_define
define|#
directive|define
name|NBUF
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_empty
empty|#
end_empty

begin_define
define|#
directive|define
name|LOAD_AV
end_define

begin_comment
comment|/* Use the load average for various commands. #			   Do not define this if you lack a load average #			   system call and kmem is read protected. */
end_comment

begin_empty
empty|#
end_empty

begin_define
define|#
directive|define
name|JOB_CONTROL
end_define

begin_comment
comment|/* if you have job stopping */
end_comment

begin_empty
empty|#
end_empty

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
comment|/* Interactive processes only work with JOB_CONTROL. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_empty
empty|#
end_empty

begin_define
define|#
directive|define
name|SUBPROCS
end_define

begin_comment
comment|/* only on UNIX systems (NOT INCORPORATED YET) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SMALL
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|disk_line
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|iAPX286
argument_list|)
operator|||
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|||
name|defined
argument_list|(
name|MAC
argument_list|)
end_if

begin_typedef
typedef|typedef
name|long
name|disk_line
typedef|;
end_typedef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* iAPX286 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMALL */
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
name|F_COMPLETION
end_define

begin_comment
comment|/* filename completion */
end_comment

begin_define
define|#
directive|define
name|ABBREV
end_define

begin_comment
comment|/* word abbreviation mode */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|IBMPC
argument_list|)
operator|||
name|defined
argument_list|(
name|MAC
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|ANSICODES
end_define

begin_comment
comment|/* extra commands that process ANSI codes */
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

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CHDIR
end_define

begin_comment
comment|/* cd command and absolute pathnames */
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
name|CMT_FMT
end_define

begin_comment
comment|/* include the comment formatting routines */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX
end_ifdef

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
name|KILL0
end_define

begin_comment
comment|/* kill(pid, 0) returns 0 if proc exists */
end_comment

begin_define
define|#
directive|define
name|SPELL
end_define

begin_comment
comment|/* spell words and buffer commands */
end_comment

begin_if
if|#
directive|if
operator|!
name|sun
operator|&&
operator|!
name|iAPX286
end_if

begin_define
define|#
directive|define
name|MY_MALLOC
end_define

begin_comment
comment|/* use more memory efficient malloc (not on suns) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|IPROCS
end_ifdef

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYSV
argument_list|)
operator|||
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|||
name|defined
argument_list|(
name|M_XENIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|byte_copy
parameter_list|(
name|s2
parameter_list|,
name|s1
parameter_list|,
name|n
parameter_list|)
value|memcpy(s1, s2, n)
end_define

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|memset(s, 0, n)
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_undef
undef|#
directive|undef
name|F_COMPLETION
end_undef

begin_comment
comment|/* can't do it with spaces in filenames */
end_comment

begin_undef
undef|#
directive|undef
name|CHDIR
end_undef

begin_define
define|#
directive|define
name|CHDIR
value|1
end_define

begin_define
define|#
directive|define
name|rindex
value|strrchr
end_define

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|setmem(s,n,0)
end_define

begin_define
define|#
directive|define
name|LINT_ARGS
end_define

begin_define
define|#
directive|define
name|NBUF
value|64
end_define

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
name|d_tempfile
decl_stmt|,
modifier|*
name|p_tempfile
decl_stmt|,
modifier|*
name|Recover
decl_stmt|,
modifier|*
name|Joverc
decl_stmt|,
ifdef|#
directive|ifdef
name|PIPEPROCS
modifier|*
name|Portsrv
decl_stmt|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|MSDOS
name|CmdDb
index|[]
decl_stmt|,
else|#
directive|else
modifier|*
name|CmdDb
decl_stmt|,
endif|#
directive|endif
name|TmpFilePath
index|[]
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
end_endif

begin_comment
comment|/* NOEXTERNS */
end_comment

end_unit

