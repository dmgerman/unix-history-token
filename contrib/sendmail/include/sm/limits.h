begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: limits.h,v 1.6 2001/03/08 03:23:08 ca Exp $  */
end_comment

begin_comment
comment|/* **<sm/limits.h> **  This header file is a portability wrapper for<limits.h>. **  It includes<limits.h>, then it ensures that the following macros **  from the C 1999 standard for<limits.h> are defined: **	LLONG_MIN, LLONG_MAX **	ULLONG_MAX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_LIMITS_H
end_ifndef

begin_define
define|#
directive|define
name|SM_LIMITS_H
end_define

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<sm/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* **  The following assumes two's complement binary arithmetic. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLONG_MIN
end_ifndef

begin_define
define|#
directive|define
name|LLONG_MIN
value|((LONGLONG_T)(~(ULLONG_MAX>> 1)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LLONG_MIN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLONG_MAX
end_ifndef

begin_define
define|#
directive|define
name|LLONG_MAX
value|((LONGLONG_T)(ULLONG_MAX>> 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LLONG_MAX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ULLONG_MAX
end_ifndef

begin_define
define|#
directive|define
name|ULLONG_MAX
value|((ULONGLONG_T)(-1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! ULLONG_MAX */
end_comment

begin_comment
comment|/* **  PATH_MAX is defined by the POSIX standard.  All modern systems **  provide it.  Older systems define MAXPATHLEN in<sys/param.h> instead. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PATH_MAX
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|MAXPATHLEN
end_ifdef

begin_define
define|#
directive|define
name|PATH_MAX
value|MAXPATHLEN
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* MAXPATHLEN */
end_comment

begin_define
define|#
directive|define
name|PATH_MAX
value|2048
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAXPATHLEN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! PATH_MAX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_LIMITS_H */
end_comment

end_unit

