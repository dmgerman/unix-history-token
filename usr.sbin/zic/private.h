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
comment|/* ** This file is in the public domain, so clarified as of ** 1996-06-05 by Arthur David Olson (arthur_david_olson@nih.gov). */
end_comment

begin_comment
comment|/*  * FreeBSD modifications: separate libc's privates from zic's.  * This makes it easier when we need to update one but not the other.  * I have removed all of the ifdef spaghetti which is not relevant to  * zic from this file.  *  * $FreeBSD$  */
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

begin_decl_stmt
specifier|static
name|char
name|privatehid
index|[]
init|=
literal|"@(#)private.h	7.48"
decl_stmt|;
end_decl_stmt

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

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_comment
comment|/* ** Private function declarations. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|icalloc
name|P
argument_list|(
operator|(
name|int
name|nelem
operator|,
name|int
name|elsize
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|icatalloc
name|P
argument_list|(
operator|(
name|char
operator|*
name|old
operator|,
specifier|const
name|char
operator|*
name|new
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|icpyalloc
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|string
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|imalloc
name|P
argument_list|(
operator|(
name|int
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|irealloc
name|P
argument_list|(
operator|(
name|void
operator|*
name|pointer
operator|,
name|int
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|icfree
name|P
argument_list|(
operator|(
name|char
operator|*
name|pointer
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ifree
name|P
argument_list|(
operator|(
name|char
operator|*
name|pointer
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|scheck
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|string
operator|,
specifier|const
name|char
operator|*
name|format
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

