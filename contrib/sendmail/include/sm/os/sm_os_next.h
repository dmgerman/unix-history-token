begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: sm_os_next.h,v 1.7 2001/04/03 01:53:06 gshapiro Exp $  */
end_comment

begin_comment
comment|/* **  Platform definitions for NeXT */
end_comment

begin_define
define|#
directive|define
name|SM_OS_NAME
value|"next"
end_define

begin_define
define|#
directive|define
name|SM_CONF_SIGSETJMP
value|0
end_define

begin_define
define|#
directive|define
name|SM_CONF_SSIZE_T
value|0
end_define

begin_define
define|#
directive|define
name|SM_CONF_FORMAT_TEST
value|0
end_define

begin_comment
comment|/* doesn't seem to work on NeXT 3.x */
end_comment

begin_define
define|#
directive|define
name|SM_DEAD
parameter_list|(
name|proto
parameter_list|)
value|proto
end_define

begin_define
define|#
directive|define
name|SM_UNUSED
parameter_list|(
name|decl
parameter_list|)
value|decl
end_define

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

end_unit

