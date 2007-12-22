begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2007 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: sm_os_qnx.h,v 1.1 2007/03/21 23:56:20 ca Exp $  */
end_comment

begin_comment
comment|/* **  sm_os_qnx.h -- platform definitions for QNX */
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

end_unit

