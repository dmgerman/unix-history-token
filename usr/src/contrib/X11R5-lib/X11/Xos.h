begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: Xos.h,v 1.47 91/08/17 17:14:38 rws Exp $  *   * Copyright 1987 by the Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided   * that the above copyright notice appear in all copies and that both that   * copyright notice and this permission notice appear in supporting   * documentation, and that the name of M.I.T. not be used in advertising  * or publicity pertaining to distribution of the software without specific,   * written prior permission. M.I.T. makes no representations about the   * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * The X Window System is a Trademark of MIT.  *  */
end_comment

begin_comment
comment|/* This is a collection of things to try and minimize system dependencies  * in a "signficant" number of source files.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XOS_H_
end_ifndef

begin_define
define|#
directive|define
name|_XOS_H_
end_define

begin_include
include|#
directive|include
file|<X11/Xosdefs.h>
end_include

begin_comment
comment|/*  * Get major data types (esp. caddr_t)  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__TYPES__
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|CRAY
end_ifdef

begin_define
define|#
directive|define
name|word
value|word_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRAY */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* forgot to protect it... */
end_comment

begin_define
define|#
directive|define
name|__TYPES__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __TYPES__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* USG */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
operator|&&
name|defined
argument_list|(
name|MOTOROLA
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|_POSIX_SOURCE
end_undef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|_POSIX_SOURCE
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USG */
end_comment

begin_comment
comment|/*  * Just about everyone needs the strings routines.  We provide both forms here,  * index/rindex and strchr/strrchr, so any systems that don't provide them all  * need to have #defines here.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|X_NOT_STDC_ENV
end_ifndef

begin_include
include|#
directive|include
file|<string.h>
end_include

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

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

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

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

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

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Get open(2) constants  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|X_NOT_POSIX
end_ifdef

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USL
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CRAY
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRAY */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MOTOROLA
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MOTOROLA */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV386
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSV386 */
end_comment

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* X_NOT_POSIX */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
operator|&&
name|defined
argument_list|(
name|macII
argument_list|)
end_if

begin_define
define|#
directive|define
name|_POSIX_SOURCE
end_define

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_undef
undef|#
directive|undef
name|_POSIX_SOURCE
end_undef

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* X_NOT_POSIX else */
end_comment

begin_comment
comment|/*  * Get struct timeval  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|USL
end_ifndef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CRAY
end_ifdef

begin_undef
undef|#
directive|undef
name|word
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRAY */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USG
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CRAY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MOTOROLA
argument_list|)
end_if

begin_struct
struct|struct
name|timeval
block|{
name|long
name|tv_sec
decl_stmt|;
name|long
name|tv_usec
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|USL_SHARELIB
end_ifndef

begin_struct
struct|struct
name|timezone
block|{
name|int
name|tz_minuteswest
decl_stmt|;
name|int
name|tz_dsttime
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USL_SHARELIB */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USG */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not SYSV */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
operator|&&
name|defined
argument_list|(
name|SVR4
argument_list|)
end_if

begin_comment
comment|/* need to omit _POSIX_SOURCE in order to get what we want in SVR4 */
end_comment

begin_undef
undef|#
directive|undef
name|_POSIX_SOURCE
end_undef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_define
define|#
directive|define
name|_POSIX_SOURCE
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSV */
end_comment

begin_comment
comment|/* use POSIX name for signal */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|X_NOT_POSIX
argument_list|)
operator|&&
name|defined
argument_list|(
name|SYSV
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SIGCHLD
argument_list|)
end_if

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

begin_ifdef
ifdef|#
directive|ifdef
name|ISC
end_ifdef

begin_include
include|#
directive|include
file|<sys/bsdtypes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XOS_H_ */
end_comment

end_unit

