begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: types.h,v 1.13 2001/04/03 01:53:01 gshapiro Exp $  */
end_comment

begin_comment
comment|/* **  This header file defines standard integral types. **  - It includes<sys/types.h>, and fixes portability problems that **    exist on older Unix platforms. **  - It defines LONGLONG_T and ULONGLONG_T, which are portable locutions **    for 'long long' and 'unsigned long long'. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|SM_TYPES_H
end_define

begin_include
include|#
directive|include
file|<sm/config.h>
end_include

begin_comment
comment|/* **  On BSD 4.2 systems,<sys/types.h> was not idempotent. **  This problem is circumvented by replacing all occurrences **  of<sys/types.h> with<sm/types.h>, which is idempotent. */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* **  On some old Unix platforms, some of the standard types are missing. **  We fix that here. */
end_comment

begin_if
if|#
directive|if
operator|!
name|SM_CONF_UID_GID
end_if

begin_define
define|#
directive|define
name|uid_t
value|int
end_define

begin_define
define|#
directive|define
name|gid_t
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SM_CONF_UID_GID */
end_comment

begin_if
if|#
directive|if
operator|!
name|SM_CONF_SSIZE_T
end_if

begin_define
define|#
directive|define
name|ssize_t
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SM_CONF_SSIZE_T */
end_comment

begin_comment
comment|/* **  Define LONGLONG_T and ULONGLONG_T, which are portable locutions **  for 'long long' and 'unsigned long long' from the C 1999 standard. */
end_comment

begin_if
if|#
directive|if
name|SM_CONF_LONGLONG
end_if

begin_typedef
typedef|typedef
name|long
name|long
name|LONGLONG_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|ULONGLONG_T
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SM_CONF_LONGLONG */
end_comment

begin_if
if|#
directive|if
name|SM_CONF_QUAD_T
end_if

begin_typedef
typedef|typedef
name|quad_t
name|LONGLONG_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_quad_t
name|ULONGLONG_T
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SM_CONF_QUAD_T */
end_comment

begin_typedef
typedef|typedef
name|long
name|LONGLONG_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ULONGLONG_T
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_CONF_QUAD_T */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_CONF_LONGLONG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_TYPES_H */
end_comment

end_unit

