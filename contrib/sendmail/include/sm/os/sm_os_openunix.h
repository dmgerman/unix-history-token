begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: sm_os_openunix.h,v 1.5 2001/11/11 16:32:00 ca Exp $  */
end_comment

begin_define
define|#
directive|define
name|SM_OS_NAME
value|"openunix"
end_define

begin_comment
comment|/* needs alarm(), our sleep() otherwise hangs. */
end_comment

begin_define
define|#
directive|define
name|SM_CONF_SETITIMER
value|0
end_define

begin_comment
comment|/* long long seems to work */
end_comment

begin_define
define|#
directive|define
name|SM_CONF_LONGLONG
value|1
end_define

begin_comment
comment|/* don't use flock() in mail.local.c */
end_comment

begin_define
define|#
directive|define
name|LDA_USE_LOCKF
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

end_unit

