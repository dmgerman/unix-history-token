begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1987 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)time.h	1.2 (Berkeley) 3/4/87  */
end_comment

begin_comment
comment|/*  * Structure returned by gmtime and localtime calls (see ctime(3)).  */
end_comment

begin_struct
struct|struct
name|tm
block|{
name|int
name|tm_sec
decl_stmt|;
name|int
name|tm_min
decl_stmt|;
name|int
name|tm_hour
decl_stmt|;
name|int
name|tm_mday
decl_stmt|;
name|int
name|tm_mon
decl_stmt|;
name|int
name|tm_year
decl_stmt|;
name|int
name|tm_wday
decl_stmt|;
name|int
name|tm_yday
decl_stmt|;
name|int
name|tm_isdst
decl_stmt|;
name|long
name|tm_gmtoff
decl_stmt|;
name|char
modifier|*
name|tm_zone
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|tm
modifier|*
name|gmtime
argument_list|()
decl_stmt|,
modifier|*
name|localtime
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|asctime
argument_list|()
decl_stmt|,
modifier|*
name|ctime
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

