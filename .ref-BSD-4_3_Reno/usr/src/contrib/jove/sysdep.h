begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|THINK_C
end_ifdef

begin_define
define|#
directive|define
name|MAC
value|1
end_define

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

begin_typedef
typedef|typedef
name|int
name|size_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MAC
argument_list|)
operator|||
name|defined
argument_list|(
name|MSDOS
argument_list|)
end_if

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
comment|/* MAC */
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
operator|||
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|void
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_define
define|#
directive|define
name|const
end_define

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

begin_if
if|#
directive|if
operator|!
name|sun
end_if

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

begin_if
if|#
directive|if
name|sun
end_if

begin_define
define|#
directive|define
name|YP_PASSWD
end_define

begin_comment
comment|/* if you are a sun running the yellow pages */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KILL0
end_define

begin_comment
comment|/* kill(pid, 0) returns 0 if proc exists */
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
name|UNIX
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|pdp11
end_ifdef

begin_define
define|#
directive|define
name|SMALL
end_define

begin_define
define|#
directive|define
name|JBUFSIZ
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

begin_else
else|#
directive|else
end_else

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
name|JBUFSIZ
value|1024
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|iAPX286
end_ifdef

begin_define
define|#
directive|define
name|NBUF
value|48
end_define

begin_comment
comment|/* NBUF*JBUFSIZ must be less than 64 kB */
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
name|SMALL
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|daddr
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
name|daddr
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int
name|daddr
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
comment|/*# define SYSVR3	/* system 5, rel. 3 */
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
name|SYSVR3
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|SYSVR2
end_ifndef

begin_define
define|#
directive|define
name|SYSVR2
end_define

begin_comment
comment|/* SYSVR2 is a subset of SYSVR3 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIGRESULT
value|void
end_define

begin_define
define|#
directive|define
name|SIGRETURN
value|{ return; }
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SIGCHLD
end_ifndef

begin_define
define|#
directive|define
name|SIGCHLD
value|SIGCLD
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
comment|/* we have segments */
end_comment

begin_define
define|#
directive|define
name|BSD_DIR
end_define

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
name|JBUFSIZ
value|512
end_define

begin_comment
comment|/* or 1024 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|BSD4_3
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

begin_define
define|#
directive|define
name|byte_zero
value|bzero
end_define

begin_define
define|#
directive|define
name|strchr
value|index
end_define

begin_define
define|#
directive|define
name|strrchr
value|rindex
end_define

begin_define
define|#
directive|define
name|BSD_SIGS
end_define

begin_comment
comment|/* Berkeley style signals */
end_comment

begin_define
define|#
directive|define
name|BSD_WAIT
end_define

begin_comment
comment|/* Berkeley style sys/wait.h */
end_comment

begin_define
define|#
directive|define
name|WAIT3
end_define

begin_comment
comment|/* Berkeley style wait3() */
end_comment

begin_define
define|#
directive|define
name|BSD_DIR
end_define

begin_comment
comment|/* Berkeley style dirent routines */
end_comment

begin_define
define|#
directive|define
name|VFORK
end_define

begin_comment
comment|/* if you have vfork(2) */
end_comment

begin_define
define|#
directive|define
name|JOB_CONTROL
end_define

begin_comment
comment|/* if you have job stopping */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|apple_ux
end_ifdef

begin_comment
comment|/* A/UX on a MacII */
end_comment

begin_define
define|#
directive|define
name|BSD_WAIT
end_define

begin_comment
comment|/* Berkeley style sys/wait.h */
end_comment

begin_define
define|#
directive|define
name|BSD_DIR
end_define

begin_comment
comment|/* Berkeley style dirent routines */
end_comment

begin_define
define|#
directive|define
name|WAIT3
end_define

begin_comment
comment|/* Berkeley style wait3() */
end_comment

begin_define
define|#
directive|define
name|BSD_SIGS
end_define

begin_comment
comment|/* Berkeley style signals */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mips
end_ifdef

begin_comment
comment|/*  * MIPS and SGI boxes have BSD style wait, and directory routines if you link  * -lbsd and define -I/usr/include/bsd on the compile line. But they have SysV  * style signals.  */
end_comment

begin_define
define|#
directive|define
name|BSD_WAIT
end_define

begin_comment
comment|/* Berkeley style sys/wait.h */
end_comment

begin_define
define|#
directive|define
name|BSD_DIR
end_define

begin_comment
comment|/* Berkeley style dirent routines */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sgi
end_ifdef

begin_define
define|#
directive|define
name|WAIT3
end_define

begin_comment
comment|/* Berkeley style wait3() */
end_comment

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
name|VFORK
end_ifndef

begin_define
define|#
directive|define
name|vfork
value|fork
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BSD4_2
end_ifndef

begin_define
define|#
directive|define
name|PIPEPROCS
end_define

begin_comment
comment|/* if IPROCS selected, use pipes */
end_comment

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

begin_include
include|#
directive|include
file|<memory.h>
end_include

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
value|memcpy((s1), (s2), (n))
end_define

begin_define
define|#
directive|define
name|byte_zero
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|memset((s), 0, (n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIGRESULT
end_ifndef

begin_define
define|#
directive|define
name|SIGRESULT
value|int
end_define

begin_define
define|#
directive|define
name|SIGRETURN
value|{ return 0; }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BSD4_2
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|MENLO_JCL
end_ifdef

begin_define
define|#
directive|define
name|signal
value|sigset
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MENLO_JCL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
name|TERMCAP
end_define

begin_define
define|#
directive|define
name|ASCII
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ASCII
end_ifdef

begin_comment
comment|/* seven bit characters */
end_comment

begin_define
define|#
directive|define
name|NCHARS
value|0200
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NCHARS
value|0400
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CHARMASK
value|(NCHARS - 1)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MSDOS
end_ifndef

begin_define
define|#
directive|define
name|FILESIZE
value|256
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* MSDOS */
end_comment

begin_define
define|#
directive|define
name|FILESIZE
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MSDOS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD_SIGS
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|long
name|SigMask
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SigHold
parameter_list|(
name|s
parameter_list|)
value|sigblock(SigMask |= sigmask((s)))
end_define

begin_define
define|#
directive|define
name|SigRelse
parameter_list|(
name|s
parameter_list|)
value|sigsetmask(SigMask&= ~sigmask((s)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SigHold
parameter_list|(
name|s
parameter_list|)
value|sighold(s)
end_define

begin_define
define|#
directive|define
name|SigRelse
parameter_list|(
name|s
parameter_list|)
value|sigrelse(s)
end_define

begin_define
define|#
directive|define
name|killpg
parameter_list|(
name|pid
parameter_list|,
name|sig
parameter_list|)
value|kill(-(pid), (sig))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

