begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The following symbols are defined if your operating system supports  * functions by that name.  All Unixes I know of support them, thus they  * are not checked by the configuration script, but are directly defined  * here.  */
end_comment

begin_comment
comment|/* HAS_IOCTL:  *	This symbol, if defined, indicates that the ioctl() routine is  *	available to set I/O characteristics  */
end_comment

begin_define
define|#
directive|define
name|HAS_IOCTL
value|/ **/
end_define

begin_comment
comment|/* HAS_UTIME:  *	This symbol, if defined, indicates that the routine utime() is  *	available to update the access and modification times of files.  */
end_comment

begin_define
define|#
directive|define
name|HAS_UTIME
value|/ **/
end_define

begin_comment
comment|/* HAS_GROUP  *	This symbol, if defined, indicates that the getgrnam() and  *	getgrgid() routines are available to get group entries.  *	The getgrent() has a separate definition, HAS_GETGRENT.  */
end_comment

begin_define
define|#
directive|define
name|HAS_GROUP
value|/ **/
end_define

begin_comment
comment|/* HAS_PASSWD  *	This symbol, if defined, indicates that the getpwnam() and  *	getpwuid() routines are available to get password entries.  *	The getpwent() has a separate definition, HAS_GETPWENT.  */
end_comment

begin_define
define|#
directive|define
name|HAS_PASSWD
value|/ **/
end_define

begin_define
define|#
directive|define
name|HAS_KILL
end_define

begin_define
define|#
directive|define
name|HAS_WAIT
end_define

begin_comment
comment|/* USEMYBINMODE  *	This symbol, if defined, indicates that the program should  *	use the routine my_binmode(FILE *fp, char iotype) to insure  *	that a file is in "binary" mode -- that is, that no translation  *	of bytes occurs on read or write operations.  */
end_comment

begin_undef
undef|#
directive|undef
name|USEMYBINMODE
end_undef

begin_comment
comment|/* Stat_t:  *	This symbol holds the type used to declare buffers for information  *	returned by stat().  It's usually just struct stat.  It may be necessary  *	to include<sys/stat.h> and<sys/types.h> to get any typedef'ed  *	information.  */
end_comment

begin_define
define|#
directive|define
name|Stat_t
value|struct stat
end_define

begin_comment
comment|/* USE_STAT_RDEV:  *	This symbol is defined if this system has a stat structure declaring  *	st_rdev  */
end_comment

begin_define
define|#
directive|define
name|USE_STAT_RDEV
value|/ **/
end_define

begin_comment
comment|/* ACME_MESS:  *	This symbol, if defined, indicates that error messages should be   *	should be generated in a format that allows the use of the Acme  *	GUI/editor's autofind feature.  */
end_comment

begin_undef
undef|#
directive|undef
name|ACME_MESS
end_undef

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* UNLINK_ALL_VERSIONS:  *	This symbol, if defined, indicates that the program should arrange  *	to remove all versions of a file if unlink() is called.  This is  *	probably only relevant for VMS.  */
end_comment

begin_comment
comment|/* #define UNLINK_ALL_VERSIONS		/ **/
end_comment

begin_comment
comment|/* VMS:  *	This symbol, if defined, indicates that the program is running under  *	VMS.  It is currently automatically set by cpps running under VMS,  *	and is included here for completeness only.  */
end_comment

begin_comment
comment|/* #define VMS		/ **/
end_comment

begin_comment
comment|/* ALTERNATE_SHEBANG:  *	This symbol, if defined, contains a "magic" string which may be used  *	as the first line of a Perl program designed to be executed directly  *	by name, instead of the standard Unix #!.  If ALTERNATE_SHEBANG  *	begins with a character other then #, then Perl will only treat  *	it as a command line if if finds the string "perl" in the first  *	word; otherwise it's treated as the first line of code in the script.  *	(IOW, Perl won't hand off to another interpreter via an alternate  *	shebang sequence that might be legal Perl code.)  */
end_comment

begin_comment
comment|/* #define ALTERNATE_SHEBANG "#!" / **/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NSIG
argument_list|)
operator|||
name|defined
argument_list|(
name|M_UNIX
argument_list|)
operator|||
name|defined
argument_list|(
name|M_XENIX
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIGABRT
end_ifndef

begin_define
define|#
directive|define
name|SIGABRT
value|SIGILL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIGILL
end_ifndef

begin_define
define|#
directive|define
name|SIGILL
value|6
end_define

begin_comment
comment|/* blech */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ABORT
parameter_list|()
value|kill(PerlProc_getpid(),SIGABRT);
end_define

begin_comment
comment|/*  * fwrite1() should be a routine with the same calling sequence as fwrite(),  * but which outputs all of the bytes requested as a single stream (unlike  * fwrite() itself, which on some systems outputs several distinct records  * if the number_of_items parameter is>1).  */
end_comment

begin_define
define|#
directive|define
name|fwrite1
value|fwrite
end_define

begin_define
define|#
directive|define
name|Stat
parameter_list|(
name|fname
parameter_list|,
name|bufptr
parameter_list|)
value|stat((fname),(bufptr))
end_define

begin_define
define|#
directive|define
name|Fstat
parameter_list|(
name|fd
parameter_list|,
name|bufptr
parameter_list|)
value|fstat((fd),(bufptr))
end_define

begin_define
define|#
directive|define
name|Fflush
parameter_list|(
name|fp
parameter_list|)
value|fflush(fp)
end_define

begin_define
define|#
directive|define
name|Mkdir
parameter_list|(
name|path
parameter_list|,
name|mode
parameter_list|)
value|mkdir((path),(mode))
end_define

begin_comment
comment|/* these should be set in a hint file, not here */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_SYS_INIT
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PERL_SCO5
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<floatingpoint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PERL_SYS_INIT
parameter_list|(
name|c
parameter_list|,
name|v
parameter_list|)
value|fpsetmask(0); MALLOC_INIT
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX_BC
end_ifdef

begin_define
define|#
directive|define
name|PERL_SYS_INIT
parameter_list|(
name|c
parameter_list|,
name|v
parameter_list|)
value|sigignore(SIGFPE); MALLOC_INIT
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PERL_SYS_INIT
parameter_list|(
name|c
parameter_list|,
name|v
parameter_list|)
value|MALLOC_INIT
end_define

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

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_SYS_TERM
end_ifndef

begin_define
define|#
directive|define
name|PERL_SYS_TERM
parameter_list|()
value|OP_REFCNT_TERM; MALLOC_TERM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BIT_BUCKET
value|"/dev/null"
end_define

begin_define
define|#
directive|define
name|dXSUB_SYS
end_define

begin_define
define|#
directive|define
name|USE_ENVIRON_ARRAY
end_define

end_unit

