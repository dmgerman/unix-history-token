begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)dkstat.h	7.2 (Berkeley) 5/21/88  */
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
value|8
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
name|dk_ndrive
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

