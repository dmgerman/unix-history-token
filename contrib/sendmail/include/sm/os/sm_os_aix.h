begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: sm_os_aix.h,v 1.9 2001/10/09 23:12:13 ca Exp $  */
end_comment

begin_comment
comment|/* **  sm_os_aix.h -- platform definitions for AIX */
end_comment

begin_define
define|#
directive|define
name|SM_OS_NAME
value|"aix"
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

begin_comment
comment|/* AIX 3 doesn't have a prototype for syslog()? */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX3
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_AIX4
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_SYSLOG
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_SYSLOG
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_CONF_SYSLOG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _AIX4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AIX3 */
end_comment

end_unit

