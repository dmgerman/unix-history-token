begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: sm_os_sunos.h,v 1.14 2001/08/14 18:09:42 ca Exp $  */
end_comment

begin_comment
comment|/* **  platform definitions for SunOS 4.0.3, SunOS 4.1.x and Solaris 2.x */
end_comment

begin_define
define|#
directive|define
name|SM_OS_NAME
value|"sunos"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SOLARIS
end_ifdef

begin_comment
comment|/* **  Solaris 2.x (aka SunOS 5.x) **  M4 config file is devtools/OS/SunOS.5.x, which defines the SOLARIS macro. */
end_comment

begin_define
define|#
directive|define
name|SM_CONF_LONGLONG
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_SHM
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_SHM
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_CONF_SHM */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_SEM
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_SEM
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_CONF_SEM */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_MSG
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_MSG
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_CONF_MSG */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SOLARIS */
end_comment

begin_comment
comment|/* **  SunOS 4.0.3 or 4.1.x */
end_comment

begin_define
define|#
directive|define
name|SM_CONF_SSIZE_T
value|0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_BROKEN_SIZE_T
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_BROKEN_SIZE_T
value|1
end_define

begin_comment
comment|/* size_t is signed? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_CONF_BROKEN_SIZE_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_BROKEN_STRTOD
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_BROKEN_STRTOD
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_CONF_BROKEN_STRTOD */
end_comment

begin_comment
comment|/* has memchr() prototype? (if not: needs memory.h) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_MEMCHR
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_MEMCHR
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_CONF_MEMCHR */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUNOS403
end_ifdef

begin_comment
comment|/* **  SunOS 4.0.3 **  M4 config file is devtools/OS/SunOS4.0, which defines the SUNOS403 macro. */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SUNOS403 */
end_comment

begin_comment
comment|/* **  SunOS 4.1.x **  M4 config file is devtools/OS/SunOS, which defines no macros. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUNOS403 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS */
end_comment

end_unit

