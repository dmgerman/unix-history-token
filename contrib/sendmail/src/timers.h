begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: timers.h,v 8.4 1999/11/04 19:31:26 ca Exp $  *  * Contributed by Exactis.com, Inc.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TIMERS_H
end_ifndef

begin_define
define|#
directive|define
name|TIMERS_H
value|1
end_define

begin_define
define|#
directive|define
name|MAXTIMERSTACK
value|20
end_define

begin_comment
comment|/* maximum timer depth */
end_comment

begin_define
define|#
directive|define
name|TIMER
value|struct _timer
end_define

begin_macro
name|TIMER
end_macro

begin_block
block|{
name|long
name|ti_wall_sec
decl_stmt|;
comment|/* wall clock seconds */
name|long
name|ti_wall_usec
decl_stmt|;
comment|/* ... microseconds */
name|long
name|ti_cpu_sec
decl_stmt|;
comment|/* cpu time seconds */
name|long
name|ti_cpu_usec
decl_stmt|;
comment|/* ... microseconds */
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|extern
name|void
name|pushtimer
name|__P
argument_list|(
operator|(
name|TIMER
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|poptimer
name|__P
argument_list|(
operator|(
name|TIMER
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strtimer
name|__P
argument_list|(
operator|(
name|TIMER
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TIMERS_H */
end_comment

end_unit

