begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vmmon.h	4.1	11/9/80	*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PGINPROF
end_ifdef

begin_define
define|#
directive|define
name|NDMON
value|128
end_define

begin_define
define|#
directive|define
name|NSMON
value|128
end_define

begin_define
define|#
directive|define
name|DRES
value|20
end_define

begin_define
define|#
directive|define
name|SRES
value|5
end_define

begin_define
define|#
directive|define
name|PMONMIN
value|20
end_define

begin_define
define|#
directive|define
name|PRES
value|50
end_define

begin_define
define|#
directive|define
name|NPMON
value|64
end_define

begin_define
define|#
directive|define
name|RMONMIN
value|130
end_define

begin_define
define|#
directive|define
name|RRES
value|5
end_define

begin_define
define|#
directive|define
name|NRMON
value|64
end_define

begin_comment
comment|/* data and stack size distribution counters */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|dmon
index|[
name|NDMON
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
name|smon
index|[
name|NSMON
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* page in time distribution counters */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|pmon
index|[
name|NPMON
operator|+
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reclaim time distribution counters */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|rmon
index|[
name|NRMON
operator|+
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pmonmin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pres
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rmonmin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rres
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|rectime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* accumulator for reclaim times */
end_comment

begin_decl_stmt
name|unsigned
name|pgintime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* accumulator for page in times */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

