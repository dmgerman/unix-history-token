begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	dk.h	4.1	11/9/80	*/
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|long
name|cp_time
index|[
name|CPUSTATES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dk_busy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|dk_time
index|[
name|DK_NDRIVE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|dk_seek
index|[
name|DK_NDRIVE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|dk_xfer
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
name|float
name|dk_mspw
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

