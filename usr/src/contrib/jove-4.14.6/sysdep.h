begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_comment
comment|/* Determine if really ANSI C */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_if
if|#
directive|if
name|__STDC__
operator|>=
literal|0
end_if

begin_define
define|#
directive|define
name|REALSTDC
value|1
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
name|THINK_C
end_ifdef

begin_define
define|#
directive|define
name|MAC
value|1
end_define

begin_comment
comment|/* Think C does not have a "defined" preprocessor operator.  * This kludge is intended to avoid the problem.  * ??? Perhaps Think C has been fixed by now. -- DHR  */
end_comment

begin_define
define|#
directive|define
name|defined
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

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

begin_comment
comment|/* The operating system (MSDOS or MAC) must be defined by this point.    IBMPC is defined in the Makefile. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MSDOS
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|MAC
end_ifndef

begin_define
define|#
directive|define
name|UNIX
value|1
end_define

begin_comment
comment|/* default to UNIX */
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
name|MAC
end_ifdef

begin_define
define|#
directive|define
name|byte_zero
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|setmem((s),(n),0)
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
name|JBUFSIZ
value|1024
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
value|1
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
value|1
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
value|1
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
name|SVR3
end_ifdef

begin_define
define|#
directive|define
name|SYSVR3
value|1
end_define

begin_comment
comment|/* system 5, rel. 3 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SVR2
end_ifdef

begin_define
define|#
directive|define
name|SYSVR2
value|1
end_define

begin_comment
comment|/* system 5, rel. 2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_define
define|#
directive|define
name|BSD4_2
value|1
end_define

begin_comment
comment|/* Berkeley 4.2 BSD or later */
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
name|sun
argument_list|)
operator|||
name|defined
argument_list|(
name|__sun__
argument_list|)
end_if

begin_define
define|#
directive|define
name|BSD4_2
value|1
end_define

begin_comment
comment|/* True enough for Jove's purposes */
end_comment

begin_comment
comment|/* # define YP_PASSWD	1	/* if you are a sun running the yellow pages */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUNOS4
end_ifdef

begin_comment
comment|/* gone to void */
end_comment

begin_define
define|#
directive|define
name|TERMIOS
value|1
end_define

begin_comment
comment|/* uses termio struct for terminal modes */
end_comment

begin_define
define|#
directive|define
name|DIRENT
value|1
end_define

begin_comment
comment|/* Posix style dirent.h */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|GCC
end_ifdef

begin_define
define|#
directive|define
name|POSIX_UNISTD
value|1
end_define

begin_comment
comment|/* prototypes in unistd.h, don't use our own */
end_comment

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD386
argument_list|)
end_if

begin_define
define|#
directive|define
name|BSD4_2
value|1
end_define

begin_comment
comment|/* True enough for Jove's purposes */
end_comment

begin_define
define|#
directive|define
name|TERMIOS
value|1
end_define

begin_comment
comment|/* uses termio struct for terminal modes */
end_comment

begin_define
define|#
directive|define
name|DIRENT
value|1
end_define

begin_comment
comment|/* Posix style dirent.h */
end_comment

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

begin_define
define|#
directive|define
name|POSIX_UNISTD
value|1
end_define

begin_comment
comment|/* prototypes in unistd.h, don't use our own */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KILL0
value|1
end_define

begin_comment
comment|/* kill(pid, 0) returns 0 if proc exists */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ultrix
argument_list|)
operator|||
name|defined
argument_list|(
name|__ultrix__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ULTRIX
value|1
end_define

begin_define
define|#
directive|define
name|BSD4_2
value|1
end_define

begin_comment
comment|/* True enough for Jove's purposes */
end_comment

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
value|{return;}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* M_XENIX is defined by the Compiler */
end_comment

begin_comment
comment|/* SYSV should be defined for (System III/System V) UNIX systems */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSVR4
end_ifdef

begin_define
define|#
directive|define
name|SYSVR3
value|1
end_define

begin_define
define|#
directive|define
name|DIRENT
value|1
end_define

begin_comment
comment|/* Posix style dirent.h */
end_comment

begin_define
define|#
directive|define
name|POSIX_UNISTD
value|1
end_define

begin_comment
comment|/* prototypes in unistd.h, don't use our own */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
value|1
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
name|SYSVR4
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
value|1
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
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYSTYPE_BSD43
argument_list|)
operator|||
name|defined
argument_list|(
name|__SYSTYPE_BSD43
argument_list|)
end_if

begin_define
define|#
directive|define
name|BSD4_2
value|1
end_define

begin_comment
comment|/* RISCOS4.x on MIPS */
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

begin_define
define|#
directive|define
name|byte_copy
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|,
name|len
parameter_list|)
value|bcopy((UnivConstPtr)(from), (UnivPtr)(to), (size_t)(len))
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
value|bzero((UnivPtr)(s), (size_t)(n))
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
value|1
end_define

begin_comment
comment|/* Berkeley style signals */
end_comment

begin_define
define|#
directive|define
name|BSD_WAIT
value|1
end_define

begin_comment
comment|/* Berkeley style sys/wait.h */
end_comment

begin_define
define|#
directive|define
name|WAIT3
value|1
end_define

begin_comment
comment|/* Berkeley style wait3() */
end_comment

begin_define
define|#
directive|define
name|BSD_DIR
value|1
end_define

begin_comment
comment|/* Berkeley style dirent routines */
end_comment

begin_define
define|#
directive|define
name|VFORK
value|1
end_define

begin_comment
comment|/* if you have vfork(2) */
end_comment

begin_define
define|#
directive|define
name|JOB_CONTROL
value|1
end_define

begin_comment
comment|/* if you have job stopping */
end_comment

begin_define
define|#
directive|define
name|MENLO_JCL
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETWD
value|1
end_define

begin_comment
comment|/* have the getwd() routine */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TERMIOS
end_ifndef

begin_define
define|#
directive|define
name|SGTTY
value|1
end_define

begin_comment
comment|/* uses SGTTY for terminal modes */
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
name|A_UX
end_ifdef

begin_comment
comment|/* A/UX on a MacII (Do *not* define "MAC") */
end_comment

begin_comment
comment|/* It might be better to define POSIX compatibility and try that. Oh well! */
end_comment

begin_define
define|#
directive|define
name|BSD_WAIT
value|1
end_define

begin_comment
comment|/* Berkeley style sys/wait.h */
end_comment

begin_define
define|#
directive|define
name|BSD_DIR
value|1
end_define

begin_comment
comment|/* Berkeley style dirent routines */
end_comment

begin_define
define|#
directive|define
name|WAIT3
value|1
end_define

begin_comment
comment|/* Berkeley style wait3() */
end_comment

begin_define
define|#
directive|define
name|BSD_SIGS
value|1
end_define

begin_comment
comment|/* Berkeley style signals */
end_comment

begin_define
define|#
directive|define
name|SYSV
value|1
end_define

begin_comment
comment|/* System V everything else */
end_comment

begin_define
define|#
directive|define
name|TERMIO
value|1
end_define

begin_comment
comment|/* uses termio struct for terminal modes */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AIX
end_ifdef

begin_comment
comment|/* from guttman@mashie.ece.jhu.edu via buchanan@cs.ubc.ca */
end_comment

begin_define
define|#
directive|define
name|BSD_DIR
end_define

begin_define
define|#
directive|define
name|HAVE_GETWD
end_define

begin_define
define|#
directive|define
name|SYSV
end_define

begin_define
define|#
directive|define
name|TERMIO
value|1
end_define

begin_comment
comment|/* uses termio struct for terminal modes */
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
name|mips
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips__
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|BSD4_2
argument_list|)
end_if

begin_comment
comment|/*  * Older MIPS (UMIPS-SYSV, anything other than their 4.3 port before  * RISCOS4.x) and SGI 4D OSes (anything before Irix3.3) have BSD style wait,  * and directory routines if you link -lbsd and define -I/usr/include/bsd on  * the compile line. But they have SysV style signals.  Jove was ported to the  * SGI 68K boxes once, but it the mods seem to have been lost.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ULTRIX
end_ifndef

begin_comment
comment|/* Not a DECstation 3100 or suchlike */
end_comment

begin_define
define|#
directive|define
name|BSD_WAIT
value|1
end_define

begin_comment
comment|/* Berkeley style sys/wait.h */
end_comment

begin_define
define|#
directive|define
name|BSD_DIR
value|1
end_define

begin_comment
comment|/* Berkeley style dirent routines */
end_comment

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|ULTRIX
name|1
end_undef

begin_comment
comment|/* Only needed it for this test */
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
name|sgi
argument_list|)
operator|||
name|defined
argument_list|(
name|__sgi__
argument_list|)
end_if

begin_define
define|#
directive|define
name|WAIT3
value|1
end_define

begin_comment
comment|/* Berkeley style wait3() */
end_comment

begin_define
define|#
directive|define
name|JOB_CONTROL
value|1
end_define

begin_comment
comment|/* if you have job stopping */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETWD
value|1
end_define

begin_comment
comment|/* All the following are for Irix 3.3 onwards */
end_comment

begin_define
define|#
directive|define
name|BSD_SIGS
value|1
end_define

begin_comment
comment|/* Berkeley style signals */
end_comment

begin_define
define|#
directive|define
name|DIRENT
value|1
end_define

begin_comment
comment|/* Posix style dirent.h */
end_comment

begin_define
define|#
directive|define
name|TERMIOS
value|1
end_define

begin_comment
comment|/* new Posix terminal mode management */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REALSTDC
end_ifndef

begin_define
define|#
directive|define
name|REALSTDC
value|1
end_define

begin_comment
comment|/* close enough for Jove's needs */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_comment
comment|/* have ANSI strerror() */
end_comment

begin_define
define|#
directive|define
name|POSIX_UNISTD
value|1
end_define

begin_comment
comment|/* prototypes in unistd.h, don't use our own */
end_comment

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

begin_undef
undef|#
directive|undef
name|SIGCHLD
end_undef

begin_comment
comment|/* #define SIGCHLD SIGCLD in signal.h */
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
name|BSD4_2
end_ifndef

begin_define
define|#
directive|define
name|KBDSIG
value|SIGEMT
end_define

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
name|from
parameter_list|,
name|to
parameter_list|,
name|count
parameter_list|)
value|memcpy((UnivPtr)(to), (UnivConstPtr)(from), (size_t)(count))
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
value|memset((UnivPtr)(s), 0, (size_t)(n))
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

begin_define
define|#
directive|define
name|TERMCAP
value|1
end_define

begin_define
define|#
directive|define
name|ASCII7
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ASCII7
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

begin_ifndef
ifndef|#
directive|ifndef
name|SIGRESULT
end_ifndef

begin_comment
comment|/* default to old-style */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|BSD_SIGS
end_ifdef

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

begin_comment
comment|/* On a system which limits JOVE to a very small data segment,  * it may be worthwhile limiting daddr to a short.  This reduces  * the size of a Line descriptor, but reduces the addressable size  * of the temp file.  This is reasonable on a PDP-11 and perhaps  * an iAPX*86.  */
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
name|daddr
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|long
name|daddr
typedef|;
end_typedef

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
name|NULL_DADDR
value|((daddr) 0)
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TERMIOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SGTTY
argument_list|)
end_if

begin_define
define|#
directive|define
name|TERMIO
value|1
end_define

begin_comment
comment|/* uses termio struct for terminal modes */
end_comment

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
name|MAILSPOOL
value|"/usr/mail"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAILSPOOL
value|"/usr/spool/mail"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

