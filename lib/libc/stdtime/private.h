begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|PRIVATE_H
end_define

begin_comment
comment|/* ** This file is in the public domain, so clarified as of ** 1996-06-05 by Arthur David Olson (arthur_david_olson@nih.gov). ** ** $FreeBSD$ */
end_comment

begin_comment
comment|/* Stuff moved from Makefile.inc to reduce clutter */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_GMTOFF
end_ifndef

begin_define
define|#
directive|define
name|TM_GMTOFF
value|tm_gmtoff
end_define

begin_define
define|#
directive|define
name|TM_ZONE
value|tm_zone
end_define

begin_define
define|#
directive|define
name|STD_INSPIRED
value|1
end_define

begin_define
define|#
directive|define
name|PCTS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LONG_DOUBLE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_define
define|#
directive|define
name|LOCALE_HOME
value|_PATH_LOCALE
end_define

begin_define
define|#
directive|define
name|TZDIR
value|"/usr/share/zoneinfo"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef TM_GMTOFF */
end_comment

begin_comment
comment|/* ** This header is for use ONLY with the time conversion code. ** There is no guarantee that it will remain unchanged, ** or that it will remain at all. ** Do NOT copy it to any system include directory. ** Thank you! */
end_comment

begin_comment
comment|/* ** ID */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NOID
end_ifndef

begin_comment
comment|/* static char	privatehid[] = "@(#)private.h	7.53"; */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined NOID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined lint */
end_comment

begin_comment
comment|/* ** Defaults for preprocessor symbols. ** You can override these in your C compiler options, e.g. `-DHAVE_ADJTIME=0'. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_ADJTIME
end_ifndef

begin_define
define|#
directive|define
name|HAVE_ADJTIME
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined HAVE_ADJTIME */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETTEXT
end_ifndef

begin_define
define|#
directive|define
name|HAVE_GETTEXT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined HAVE_GETTEXT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_INCOMPATIBLE_CTIME_R
end_ifndef

begin_define
define|#
directive|define
name|HAVE_INCOMPATIBLE_CTIME_R
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined INCOMPATIBLE_CTIME_R */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SETTIMEOFDAY
end_ifndef

begin_define
define|#
directive|define
name|HAVE_SETTIMEOFDAY
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined HAVE_SETTIMEOFDAY */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRERROR
end_ifndef

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined HAVE_STRERROR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SYMLINK
end_ifndef

begin_define
define|#
directive|define
name|HAVE_SYMLINK
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined HAVE_SYMLINK */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SYS_STAT_H
end_ifndef

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined HAVE_SYS_STAT_H */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SYS_WAIT_H
end_ifndef

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined HAVE_SYS_WAIT_H */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_UNISTD_H
end_ifndef

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined HAVE_UNISTD_H */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_UTMPX_H
end_ifndef

begin_define
define|#
directive|define
name|HAVE_UTMPX_H
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined HAVE_UTMPX_H */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCALE_HOME
end_ifndef

begin_define
define|#
directive|define
name|LOCALE_HOME
value|"/usr/lib/locale"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined LOCALE_HOME */
end_comment

begin_if
if|#
directive|if
name|HAVE_INCOMPATIBLE_CTIME_R
end_if

begin_define
define|#
directive|define
name|asctime_r
value|_incompatible_asctime_r
end_define

begin_define
define|#
directive|define
name|ctime_r
value|_incompatible_ctime_r
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_INCOMPATIBLE_CTIME_R */
end_comment

begin_comment
comment|/* ** Nested includes */
end_comment

begin_include
include|#
directive|include
file|"sys/types.h"
end_include

begin_comment
comment|/* for time_t */
end_comment

begin_include
include|#
directive|include
file|"stdio.h"
end_include

begin_include
include|#
directive|include
file|"errno.h"
end_include

begin_include
include|#
directive|include
file|"string.h"
end_include

begin_include
include|#
directive|include
file|"limits.h"
end_include

begin_comment
comment|/* for CHAR_BIT */
end_comment

begin_include
include|#
directive|include
file|"time.h"
end_include

begin_include
include|#
directive|include
file|"stdlib.h"
end_include

begin_if
if|#
directive|if
name|HAVE_GETTEXT
operator|-
literal|0
end_if

begin_include
include|#
directive|include
file|"libintl.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_GETTEXT - 0 */
end_comment

begin_if
if|#
directive|if
name|HAVE_SYS_WAIT_H
operator|-
literal|0
end_if

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_comment
comment|/* for WIFEXITED and WEXITSTATUS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_WAIT_H - 0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WIFEXITED
end_ifndef

begin_define
define|#
directive|define
name|WIFEXITED
parameter_list|(
name|status
parameter_list|)
value|(((status)& 0xff) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined WIFEXITED */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WEXITSTATUS
end_ifndef

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|status
parameter_list|)
value|(((status)>> 8)& 0xff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined WEXITSTATUS */
end_comment

begin_if
if|#
directive|if
name|HAVE_UNISTD_H
operator|-
literal|0
end_if

begin_include
include|#
directive|include
file|"unistd.h"
end_include

begin_comment
comment|/* for F_OK and R_OK */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_UNISTD_H - 0 */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|HAVE_UNISTD_H
operator|-
literal|0
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|F_OK
end_ifndef

begin_define
define|#
directive|define
name|F_OK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined F_OK */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|R_OK
end_ifndef

begin_define
define|#
directive|define
name|R_OK
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined R_OK */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !(HAVE_UNISTD_H - 0) */
end_comment

begin_comment
comment|/* Unlike<ctype.h>'s isdigit, this also works if c< 0 | c> UCHAR_MAX.  */
end_comment

begin_define
define|#
directive|define
name|is_digit
parameter_list|(
name|c
parameter_list|)
value|((unsigned)(c) - '0'<= 9)
end_define

begin_comment
comment|/* ** SunOS 4.1.1 headers lack FILENAME_MAX. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FILENAME_MAX
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|unix
end_ifdef

begin_include
include|#
directive|include
file|"sys/param.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined unix */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined MAXPATHLEN */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAXPATHLEN
end_ifdef

begin_define
define|#
directive|define
name|FILENAME_MAX
value|MAXPATHLEN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined MAXPATHLEN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_define
define|#
directive|define
name|FILENAME_MAX
value|1024
end_define

begin_comment
comment|/* Pure guesswork */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined MAXPATHLEN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined FILENAME_MAX */
end_comment

begin_comment
comment|/* ** Private function declarations. */
end_comment

begin_function_decl
name|char
modifier|*
name|icalloc
parameter_list|(
name|int
name|nelem
parameter_list|,
name|int
name|elsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|icatalloc
parameter_list|(
name|char
modifier|*
name|old
parameter_list|,
specifier|const
name|char
modifier|*
name|new
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|icpyalloc
parameter_list|(
specifier|const
name|char
modifier|*
name|string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|imalloc
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|irealloc
parameter_list|(
name|void
modifier|*
name|pointer
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|icfree
parameter_list|(
name|char
modifier|*
name|pointer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ifree
parameter_list|(
name|char
modifier|*
name|pointer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|scheck
parameter_list|(
specifier|const
name|char
modifier|*
name|string
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ** Finally, some convenience items. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined TRUE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined FALSE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_BIT
end_ifndef

begin_define
define|#
directive|define
name|TYPE_BIT
parameter_list|(
name|type
parameter_list|)
value|(sizeof (type) * CHAR_BIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined TYPE_BIT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_SIGNED
end_ifndef

begin_define
define|#
directive|define
name|TYPE_SIGNED
parameter_list|(
name|type
parameter_list|)
value|(((type) -1)< 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined TYPE_SIGNED */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INT_STRLEN_MAXIMUM
end_ifndef

begin_comment
comment|/* ** 302 / 1000 is log10(2.0) rounded up. ** Subtract one for the sign bit if the type is signed; ** add one for integer division truncation; ** add one more for a minus sign if the type is signed. */
end_comment

begin_define
define|#
directive|define
name|INT_STRLEN_MAXIMUM
parameter_list|(
name|type
parameter_list|)
define|\
value|((TYPE_BIT(type) - TYPE_SIGNED(type)) * 302 / 1000 + 1 + TYPE_SIGNED(type))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined INT_STRLEN_MAXIMUM */
end_comment

begin_comment
comment|/* ** INITIALIZE(x) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GNUC_or_lint
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_define
define|#
directive|define
name|GNUC_or_lint
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined lint */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|GNUC_or_lint
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined __GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined lint */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined GNUC_or_lint */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INITIALIZE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|GNUC_or_lint
end_ifdef

begin_define
define|#
directive|define
name|INITIALIZE
parameter_list|(
name|x
parameter_list|)
value|((x) = 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined GNUC_or_lint */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GNUC_or_lint
end_ifndef

begin_define
define|#
directive|define
name|INITIALIZE
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined GNUC_or_lint */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined INITIALIZE */
end_comment

begin_comment
comment|/* ** For the benefit of GNU folk... ** `_(MSGID)' uses the current locale's message library string for MSGID. ** The default is to use gettext if available, and use MSGID otherwise. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_
end_ifndef

begin_if
if|#
directive|if
name|HAVE_GETTEXT
operator|-
literal|0
end_if

begin_define
define|#
directive|define
name|_
parameter_list|(
name|msgid
parameter_list|)
value|gettext(msgid)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !(HAVE_GETTEXT - 0) */
end_comment

begin_define
define|#
directive|define
name|_
parameter_list|(
name|msgid
parameter_list|)
value|msgid
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !(HAVE_GETTEXT - 0) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined _ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TZ_DOMAIN
end_ifndef

begin_define
define|#
directive|define
name|TZ_DOMAIN
value|"tz"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined TZ_DOMAIN */
end_comment

begin_if
if|#
directive|if
name|HAVE_INCOMPATIBLE_CTIME_R
end_if

begin_undef
undef|#
directive|undef
name|asctime_r
end_undef

begin_undef
undef|#
directive|undef
name|ctime_r
end_undef

begin_function_decl
name|char
modifier|*
name|asctime_r
parameter_list|(
name|struct
name|tm
specifier|const
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ctime_r
parameter_list|(
name|time_t
specifier|const
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_INCOMPATIBLE_CTIME_R */
end_comment

begin_comment
comment|/* ** UNIX was a registered trademark of The Open Group in 2003. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined PRIVATE_H */
end_comment

end_unit

