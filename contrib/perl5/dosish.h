begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|ABORT
parameter_list|()
value|abort();
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SH_PATH
end_ifndef

begin_define
define|#
directive|define
name|SH_PATH
value|"/bin/sh"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DJGPP
end_ifdef

begin_define
define|#
directive|define
name|BIT_BUCKET
value|"nul"
end_define

begin_define
define|#
directive|define
name|OP_BINARY
value|O_BINARY
end_define

begin_define
define|#
directive|define
name|PERL_SYS_INIT
parameter_list|(
name|c
parameter_list|,
name|v
parameter_list|)
value|Perl_DJGPP_init(c,v)
end_define

begin_define
define|#
directive|define
name|init_os_extras
value|Perl_init_os_extras
end_define

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_define
define|#
directive|define
name|HAS_UTIME
end_define

begin_define
define|#
directive|define
name|HAS_KILL
end_define

begin_function_decl
name|char
modifier|*
name|djgpp_pathexp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|DJGPP
operator|==
literal|2
operator|&&
name|DJGPP_MINOR
operator|<
literal|2
operator|)
end_if

begin_define
define|#
directive|define
name|NO_LOCALECONV_MON_THOUSANDS_SEP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREADS
end_ifdef

begin_define
define|#
directive|define
name|OLD_PTHREADS_API
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PERL_FS_VER_FMT
value|"%d_%d_%d"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* DJGPP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
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
value|Perl_win32_init(c,v)
end_define

begin_define
define|#
directive|define
name|BIT_BUCKET
value|"nul"
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
end_define

begin_define
define|#
directive|define
name|BIT_BUCKET
value|"\\dev\\nul"
end_define

begin_comment
comment|/* "wanna be like, umm, Newlined, or somethin?" */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DJGPP */
end_comment

begin_define
define|#
directive|define
name|PERL_SYS_TERM
parameter_list|()
value|OP_REFCNT_TERM; MALLOC_TERM
end_define

begin_define
define|#
directive|define
name|dXSUB_SYS
end_define

begin_comment
comment|/*  * 5.003_07 and earlier keyed on #ifdef MSDOS for determining if we were   * running on DOS, *and* if we had to cope with 16 bit memory addressing   * constraints, *and* we need to have memory allocated as unsigned long.  *  * with the advent of *real* compilers for DOS, they are not locked together.  * MSDOS means "I am running on MSDOS". HAS_64K_LIMIT means "I have   * 16 bit memory addressing constraints".  *  * if you need the last, try #DEFINE MEM_SIZE unsigned long.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MSDOS
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|DJGPP
end_ifndef

begin_define
define|#
directive|define
name|HAS_64K_LIMIT
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
comment|/* USEMYBINMODE  *	This symbol, if defined, indicates that the program should  *	use the routine my_binmode(FILE *fp, char iotype, int mode) to insure  *	that a file is in "binary" mode -- that is, that no translation  *	of bytes occurs on read or write operations.  */
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
end_define

begin_comment
comment|/**/
end_comment

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
comment|/* ALTERNATE_SHEBANG:  *	This symbol, if defined, contains a "magic" string which may be used  *	as the first line of a Perl program designed to be executed directly  *	by name, instead of the standard Unix #!.  If ALTERNATE_SHEBANG  *	begins with a character other then #, then Perl will only treat  *	it as a command line if if finds the string "perl" in the first  *	word; otherwise it's treated as the first line of code in the script.  *	(IOW, Perl won't hand off to another interpreter via an alternate  *	shebang sequence that might be legal Perl code.)  */
end_comment

begin_comment
comment|/* #define ALTERNATE_SHEBANG "#!" / **/
end_comment

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
name|Fstat
parameter_list|(
name|fd
parameter_list|,
name|bufptr
parameter_list|)
value|fstat((fd),(bufptr))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DJGPP
end_ifdef

begin_define
define|#
directive|define
name|Fflush
parameter_list|(
name|fp
parameter_list|)
value|djgpp_fflush(fp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Fflush
parameter_list|(
name|fp
parameter_list|)
value|fflush(fp)
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifndef
ifndef|#
directive|ifndef
name|WIN32
end_ifndef

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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HAS_IOCTL
end_define

begin_define
define|#
directive|define
name|HAS_UTIME
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

begin_define
define|#
directive|define
name|HAS_CHOWN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WIN32 */
end_comment

end_unit

