begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: sm_os_hp.h,v 1.8 2001/10/31 15:36:56 ca Exp $  */
end_comment

begin_comment
comment|/* **  sm_os_hp.h -- platform definitions for HP */
end_comment

begin_define
define|#
directive|define
name|SM_OS_NAME
value|"hp"
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
comment|/* max/min buffer size of other than regular files */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_IO_MAX_BUF
end_ifndef

begin_define
define|#
directive|define
name|SM_IO_MAX_BUF
value|8192
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_IO_MAX_BUF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_IO_MIN_BUF
end_ifndef

begin_define
define|#
directive|define
name|SM_IO_MIN_BUF
value|4096
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_IO_MIN_BUF */
end_comment

end_unit

