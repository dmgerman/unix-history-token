begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  */
end_comment

begin_include
include|#
directive|include
file|<sm/gen.h>
end_include

begin_macro
name|SM_RCSID
argument_list|(
literal|"@(#)$Id: xtrap.c,v 1.5 2001/09/11 04:04:49 gshapiro Exp $"
argument_list|)
end_macro

begin_include
include|#
directive|include
file|<sm/xtrap.h>
end_include

begin_decl_stmt
name|SM_ATOMIC_UINT_T
name|SmXtrapCount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SM_DEBUG_T
name|SmXtrapDebug
init|=
name|SM_DEBUG_INITIALIZER
argument_list|(
literal|"sm_xtrap"
argument_list|,
literal|"@(#)$Debug: sm_xtrap - raise exception at N'th xtrap point $"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SM_DEBUG_T
name|SmXtrapReport
init|=
name|SM_DEBUG_INITIALIZER
argument_list|(
literal|"sm_xtrap_report"
argument_list|,
literal|"@(#)$Debug: sm_xtrap_report - report xtrap count on exit $"
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

