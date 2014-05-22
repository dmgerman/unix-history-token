begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001, 2002 Proofpoint, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: sm_os_unixware.h,v 1.9 2013-11-22 20:51:34 ca Exp $  */
end_comment

begin_define
define|#
directive|define
name|SM_OS_NAME
value|"unixware"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_LONGLONG
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SCO_VERSION__
argument_list|)
operator|&&
name|__SCO_VERSION__
operator|>
literal|400000000L
end_if

begin_define
define|#
directive|define
name|SM_CONF_LONGLONG
value|1
end_define

begin_define
define|#
directive|define
name|SM_CONF_TEST_LLONG
value|1
end_define

begin_define
define|#
directive|define
name|SM_CONF_BROKEN_SIZE_T
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__SCO_VERSION__)&& __SCO_VERSION__> 400000000L */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SM_CONF_LONGLONG */
end_comment

begin_comment
comment|/* try LLONG tests in libsm/t-types.c? */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_TEST_LLONG
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_TEST_LLONG
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SM_CONF_TEST_LLONG */
end_comment

begin_comment
comment|/* needs alarm(), our sleep() otherwise hangs. */
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

begin_comment
comment|/* size_t seems to be signed */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_CONF_BROKEN_SIZE_T */
end_comment

begin_comment
comment|/* don't use flock() in mail.local.c */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDA_USE_LOCKF
end_ifndef

begin_define
define|#
directive|define
name|LDA_USE_LOCKF
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LDA_USE_LOCKF */
end_comment

end_unit

