begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2002 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: gen.h,v 1.22 2002/04/03 00:40:42 ca Exp $  */
end_comment

begin_comment
comment|/* **  libsm general definitions **  See libsm/gen.html for documentation. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_GEN_H
end_ifndef

begin_define
define|#
directive|define
name|SM_GEN_H
end_define

begin_include
include|#
directive|include
file|<sm/config.h>
end_include

begin_include
include|#
directive|include
file|<sm/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sm/types.h>
end_include

begin_comment
comment|/* **  Define SM_RCSID and SM_IDSTR, **  macros used to embed RCS and SCCS identification strings in object files. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_define
define|#
directive|define
name|SM_RCSID
parameter_list|(
name|str
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SM_IDSTR
parameter_list|(
name|id
parameter_list|,
name|str
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* lint */
end_comment

begin_define
define|#
directive|define
name|SM_RCSID
parameter_list|(
name|str
parameter_list|)
value|SM_UNUSED(static const char RcsId[]) = str;
end_define

begin_define
define|#
directive|define
name|SM_IDSTR
parameter_list|(
name|id
parameter_list|,
name|str
parameter_list|)
value|SM_UNUSED(static const char id[]) = str;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_comment
comment|/* **  Define NULL and offsetof (from the C89 standard) */
end_comment

begin_if
if|#
directive|if
name|SM_CONF_STDDEF_H
end_if

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SM_CONF_STDDEF_H */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|type
parameter_list|,
name|member
parameter_list|)
value|((size_t)(&((type *)0)->member))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_CONF_STDDEF_H */
end_comment

begin_comment
comment|/* **  Define bool, true, false (from the C99 standard) */
end_comment

begin_if
if|#
directive|if
name|SM_CONF_STDBOOL_H
end_if

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SM_CONF_STDBOOL_H */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_typedef
typedef|typedef
name|int
name|bool
typedef|;
end_typedef

begin_define
define|#
directive|define
name|false
value|0
end_define

begin_define
define|#
directive|define
name|true
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

begin_comment
comment|/* SM_CONF_STDBOOL_H */
end_comment

begin_comment
comment|/* **  Define SM_MAX and SM_MIN */
end_comment

begin_define
define|#
directive|define
name|SM_MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|SM_MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_comment
comment|/* Define SM_SUCCESS and SM_FAILURE */
end_comment

begin_define
define|#
directive|define
name|SM_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|SM_FAILURE
value|(-1)
end_define

begin_comment
comment|/* XXX This needs to be fixed when we start to use threads: */
end_comment

begin_typedef
typedef|typedef
name|int
name|SM_ATOMIC_INT_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|SM_ATOMIC_UINT_T
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_GEN_H */
end_comment

end_unit

