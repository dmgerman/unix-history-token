begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/*  * config.h -- configure various defines for tcsh  *  * All source files should #include this FIRST.  *  * Edit this to match your system type.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_h_config
end_ifndef

begin_define
define|#
directive|define
name|_h_config
end_define

begin_comment
comment|/****************** System dependant compilation flags ****************/
end_comment

begin_comment
comment|/*  * POSIX	This system supports IEEE Std 1003.1-1988 (POSIX).  */
end_comment

begin_define
define|#
directive|define
name|POSIX
end_define

begin_comment
comment|/*  * POSIXJOBS	This system supports the optional IEEE Std 1003.1-1988 (POSIX)  *		job control facilities.  */
end_comment

begin_define
define|#
directive|define
name|POSIXJOBS
end_define

begin_comment
comment|/*  * POSIXSIGS	Use the POSIX signal facilities to emulate BSD signals.  */
end_comment

begin_comment
comment|/* #undef POSIXSIGS */
end_comment

begin_comment
comment|/*  * VFORK	This machine has a vfork().    *		It used to be that for job control to work, this define  *		was mandatory. This is not the case any more.  *		If you think you still need it, but you don't have vfork,   *		define this anyway and then do #define vfork fork.    *		I do this anyway on a Sun because of yellow pages brain damage,  *		[should not be needed under 4.1]  *		and on the iris4d cause	SGI's fork is sufficiently "virtual"   *		that vfork isn't necessary.  (Besides, SGI's vfork is weird).  *		Note that some machines eg. rs6000 have a vfork, but not  *		with the berkeley semantics, so we cannot use it there either.  */
end_comment

begin_define
define|#
directive|define
name|VFORK
end_define

begin_comment
comment|/*  * BSDJOBS	You have BSD-style job control (both process groups and  *		a tty that deals correctly  */
end_comment

begin_define
define|#
directive|define
name|BSDJOBS
end_define

begin_comment
comment|/*  * BSDSIGS	You have 4.2-style signals, rather than USG style.  *		Note: POSIX systems should not define this unless they  *		have sigvec() and friends (ie: 4.3BSD-RENO, HP-UX).  */
end_comment

begin_define
define|#
directive|define
name|BSDSIGS
end_define

begin_comment
comment|/*  * BSDTIMES	You have BSD-style process time stuff (like rusage)  *		This may or may not be true.  For example, Apple Unix  *		(OREO) has BSDJOBS and BSDSIGS but not BSDTIMES.  */
end_comment

begin_define
define|#
directive|define
name|BSDTIMES
end_define

begin_comment
comment|/*  * BSDLIMIT	You have BSD-style resource limit stuff (getrlimit/setrlimit)  */
end_comment

begin_define
define|#
directive|define
name|BSDLIMIT
end_define

begin_comment
comment|/*  * BSDNICE	Your system uses setpriority() instead of nice, to  *		change a processes scheduling priority  */
end_comment

begin_define
define|#
directive|define
name|BSDNICE
end_define

begin_comment
comment|/*  * TERMIO	You have struct termio instead of struct sgttyb.  * 		This is usually the case for SYSV systems, where  *		BSD uses sgttyb. POSIX systems should define this  *		anyway, even though they use struct termios.  */
end_comment

begin_define
define|#
directive|define
name|TERMIO
end_define

begin_comment
comment|/*  * SYSVREL	Your machine is SYSV based (HPUX, A/UX)  *		NOTE: don't do this if you are on a Pyramid -- tcsh is  *		built in a BSD universe.  *		Set SYSVREL to 1, 2, 3, or 4, depending the version of System V  *		you are running. Or set it to 0 if you are not SYSV based  */
end_comment

begin_define
define|#
directive|define
name|SYSVREL
value|0
end_define

begin_comment
comment|/*  * YPBUGS	Work around Sun YP bugs that cause expansion of ~username  *		to send command output to /dev/null  */
end_comment

begin_comment
comment|/* #undef YPBUGS */
end_comment

begin_comment
comment|/*  * SIGVOID	Define this if your signal handlers return void.  On older  *		systems, signal returns int, but on newer ones, it returns void.  */
end_comment

begin_define
define|#
directive|define
name|SIGVOID
end_define

begin_comment
comment|/*  * HAVEDUP2	Define this if your system supports dup2().  */
end_comment

begin_define
define|#
directive|define
name|HAVEDUP2
end_define

begin_comment
comment|/*  * UTHOST	Does the utmp file have a host field?  */
end_comment

begin_define
define|#
directive|define
name|UTHOST
end_define

begin_comment
comment|/*  * DIRENT	Your system has<dirent.h> instead of<sys/dir.h>  */
end_comment

begin_define
define|#
directive|define
name|DIRENT
end_define

begin_comment
comment|/****************** local defines *********************/
end_comment

begin_comment
comment|/****************** configurable hacks ****************/
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/* have been moved to config_f.h */
end_comment

begin_include
include|#
directive|include
file|"config_f.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|NLS_BUGS
end_define

begin_comment
comment|/* we want to use the system malloc when we install as /bin/csh */
end_comment

begin_define
define|#
directive|define
name|SYSMALLOC
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
name|__bsdi__
argument_list|)
end_if

begin_comment
comment|/*  * _PATH_TCSHELL      if you've change the installation location (vix)  */
end_comment

begin_if
if|#
directive|if
name|_BSDI_VERSION
operator|>=
literal|199701
end_if

begin_define
define|#
directive|define
name|_PATH_TCSHELL
value|"/bin/tcsh"
end_define

begin_comment
comment|/* #  undef SYSMALLOC */
end_comment

begin_define
define|#
directive|define
name|SYSMALLOC
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_PATH_TCSHELL
value|"/usr/contrib/bin/tcsh"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|NLS
end_undef

begin_undef
undef|#
directive|undef
name|NLS_CATALOGS
end_undef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|SYSMALLOC
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NLS_CATALOGS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KANJI
end_define

begin_define
define|#
directive|define
name|DSPMBYTE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _h_config */
end_comment

begin_comment
comment|/* config.h.in.  Generated automatically from configure.in by autoheader.  */
end_comment

end_unit

