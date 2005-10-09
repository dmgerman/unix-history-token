begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: sm_os_linux.h,v 1.12 2001/10/05 01:52:41 ca Exp $  */
end_comment

begin_comment
comment|/* **  Platform definitions for Linux */
end_comment

begin_define
define|#
directive|define
name|SM_OS_NAME
value|"linux"
end_define

begin_comment
comment|/* to get version number */
end_comment

begin_include
include|#
directive|include
file|<linux/version.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|KERNEL_VERSION
argument_list|)
end_if

begin_comment
comment|/* not defined in 2.0.x kernel series */
end_comment

begin_define
define|#
directive|define
name|KERNEL_VERSION
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(((a)<< 16) + ((b)<< 8) + (c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! KERNEL_VERSION */
end_comment

begin_comment
comment|/* doesn't seem to work on Linux */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_SETITIMER
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_SETITIMER
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_CONF_SETITIMER */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_SHM
end_ifndef

begin_if
if|#
directive|if
operator|(
name|LINUX_VERSION_CODE
operator|>=
name|KERNEL_VERSION
argument_list|(
literal|2
operator|,
literal|2
operator|,
literal|19
argument_list|)
operator|)
end_if

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
comment|/* LINUX_VERSION_CODE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_CONF_SHM */
end_comment

begin_define
define|#
directive|define
name|SM_CONF_SYS_CDEFS_H
value|1
end_define

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

end_unit

