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
comment|/*static char	privatehid[] = "@(#)private.h	7.33";*/
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
file|"ctype.h"
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
comment|/* ** Workarounds for compilers/systems. */
end_comment

begin_comment
comment|/* ** SunOS 4.1.1 cc lacks const. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|const
end_ifndef

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
comment|/* !defined __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined const */
end_comment

begin_comment
comment|/* ** SunOS 4.1.1 cc lacks prototypes. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|P
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined __STDC__ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined P */
end_comment

begin_comment
comment|/* ** SunOS 4.1.1 headers lack EXIT_SUCCESS. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EXIT_SUCCESS
end_ifndef

begin_define
define|#
directive|define
name|EXIT_SUCCESS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined EXIT_SUCCESS */
end_comment

begin_comment
comment|/* ** SunOS 4.1.1 headers lack EXIT_FAILURE. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EXIT_FAILURE
end_ifndef

begin_define
define|#
directive|define
name|EXIT_FAILURE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined EXIT_FAILURE */
end_comment

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
comment|/* ** SunOS 4.1.1 libraries lack remove. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|remove
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|unlink
name|P
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

begin_define
define|#
directive|define
name|remove
value|unlink
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined remove */
end_comment

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
name|INT_STRLEN_MAXIMUM
end_ifndef

begin_comment
comment|/* ** 302 / 1000 is log10(2.0) rounded up. ** Subtract one for the sign bit; ** add one for integer division truncation; ** add one more for a minus sign. */
end_comment

begin_define
define|#
directive|define
name|INT_STRLEN_MAXIMUM
parameter_list|(
name|type
parameter_list|)
define|\
value|((sizeof(type) * CHAR_BIT - 1) * 302 / 1000 + 2)
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
comment|/* ** UNIX was a registered trademark of UNIX System Laboratories in 1993. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined PRIVATE_H */
end_comment

end_unit

