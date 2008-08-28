begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: xtrap.h,v 1.7 2001/04/03 01:53:01 gshapiro Exp $  */
end_comment

begin_comment
comment|/* **  scaffolding for testing exception handler code */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_XTRAP_H
end_ifndef

begin_define
define|#
directive|define
name|SM_XTRAP_H
end_define

begin_include
include|#
directive|include
file|<sm/debug.h>
end_include

begin_include
include|#
directive|include
file|<sm/exc.h>
end_include

begin_decl_stmt
specifier|extern
name|SM_ATOMIC_UINT_T
name|SmXtrapCount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SM_DEBUG_T
name|SmXtrapDebug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SM_DEBUG_T
name|SmXtrapReport
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|SM_DEBUG_CHECK
end_if

begin_define
define|#
directive|define
name|sm_xtrap_check
parameter_list|()
value|(++SmXtrapCount == sm_debug_level(&SmXtrapDebug))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SM_DEBUG_CHECK */
end_comment

begin_define
define|#
directive|define
name|sm_xtrap_check
parameter_list|()
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_DEBUG_CHECK */
end_comment

begin_define
define|#
directive|define
name|sm_xtrap_raise_x
parameter_list|(
name|exc
parameter_list|)
define|\
value|if (sm_xtrap_check()) \ 		{ \ 			sm_exc_raise_x(exc); \ 		} else
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_XTRAP_H */
end_comment

end_unit

