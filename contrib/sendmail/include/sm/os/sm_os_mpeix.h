begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: sm_os_mpeix.h,v 1.2 2001/12/14 00:23:02 ca Exp $  */
end_comment

begin_comment
comment|/* **  sm_os_mpeix.h -- platform definitions for HP MPE/iX */
end_comment

begin_define
define|#
directive|define
name|SM_OS_NAME
value|"mpeix"
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

begin_define
define|#
directive|define
name|SM_CONF_SETITIMER
value|0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_CANT_SETRGID
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_CANT_SETRGID
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_CONF_CANT_SETRGID */
end_comment

end_unit

