begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)times.h	7.1 (Berkeley) 6/4/86  */
end_comment

begin_comment
comment|/*  * Structure returned by times()  */
end_comment

begin_struct
struct|struct
name|tms
block|{
name|time_t
name|tms_utime
decl_stmt|;
comment|/* user time */
name|time_t
name|tms_stime
decl_stmt|;
comment|/* system time */
name|time_t
name|tms_cutime
decl_stmt|;
comment|/* user time, children */
name|time_t
name|tms_cstime
decl_stmt|;
comment|/* system time, children */
block|}
struct|;
end_struct

end_unit

