begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: sm_os_freebsd.h,v 1.9 2001/06/27 21:46:48 gshapiro Exp $  */
end_comment

begin_comment
comment|/* **  Platform definitions for FreeBSD */
end_comment

begin_define
define|#
directive|define
name|SM_OS_NAME
value|"freebsd"
end_define

begin_define
define|#
directive|define
name|SM_CONF_SYS_CDEFS_H
value|1
end_define

begin_if
if|#
directive|if
name|__FreeBSD__
operator|>=
literal|2
end_if

begin_include
include|#
directive|include
file|<osreldate.h>
end_include

begin_comment
comment|/* defines __FreeBSD_version */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|199512
end_if

begin_comment
comment|/* 2.2-current when it appeared */
end_comment

begin_define
define|#
directive|define
name|MI_SOMAXCONN
value|-1
end_define

begin_comment
comment|/* listen() max backlog for milter */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD_version>= 199512 */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|330000
end_if

begin_comment
comment|/* 3.3.0-release and later have strlcpy()/strlcat() */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_STRL
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_STRL
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

begin_endif
endif|#
directive|endif
end_endif

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
value|1
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

end_unit

