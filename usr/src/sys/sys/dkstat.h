begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	dkstat.h	3.1	%G%	*/
end_comment

begin_comment
comment|/*  * Instrumentation  */
end_comment

begin_define
define|#
directive|define
name|CPUSTATES
value|4
end_define

begin_define
define|#
directive|define
name|CP_USER
value|0
end_define

begin_define
define|#
directive|define
name|CP_NICE
value|1
end_define

begin_define
define|#
directive|define
name|CP_SYS
value|2
end_define

begin_define
define|#
directive|define
name|CP_IDLE
value|3
end_define

begin_define
define|#
directive|define
name|DK_NDRIVE
value|4
end_define

begin_define
define|#
directive|define
name|DK_NSTATES
value|16
end_define

begin_comment
comment|/* 2^DK_NDRIVE */
end_comment

begin_decl_stmt
name|int
name|dk_busy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|dk_time
index|[
name|CPUSTATES
index|]
index|[
name|DK_NSTATES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|dk_numb
index|[
name|DK_NDRIVE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|dk_wds
index|[
name|DK_NDRIVE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|tk_nin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|tk_nout
decl_stmt|;
end_decl_stmt

end_unit

