begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  MONITOR.H -- structures dealing with performance monitoring ** **	Version: **		@(#)pmon.h	7.1	2/5/81 */
end_comment

begin_struct
struct|struct
name|monitor
block|{
name|long
name|mon_utime
decl_stmt|;
comment|/* user time in milliseconds */
name|long
name|mon_stime
decl_stmt|;
comment|/* system time in milliseconds */
name|long
name|mon_pread
decl_stmt|;
comment|/* pages read */
name|long
name|mon_pwrit
decl_stmt|;
comment|/* pages written */
name|long
name|mon_cread
decl_stmt|;
comment|/* catalog pages read */
name|long
name|mon_cwrit
decl_stmt|;
comment|/* catalog pages written */
name|long
name|mon_xread
decl_stmt|;
comment|/* ISAM/BTREE index pages read */
block|}
struct|;
end_struct

end_unit

