begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * %sccs.include.redist.c%  *  *	@(#)dkstat.h	8.2 (Berkeley) %G%  */
end_comment

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
name|CP_INTR
value|3
end_define

begin_define
define|#
directive|define
name|CP_IDLE
value|4
end_define

begin_define
define|#
directive|define
name|CPUSTATES
value|5
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
name|long
name|dk_seek
index|[
name|DK_NDRIVE
index|]
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
name|dk_wds
index|[
name|DK_NDRIVE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|dk_wpms
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
name|int
name|dk_busy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dk_ndrive
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|tk_cancc
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

begin_decl_stmt
name|long
name|tk_rawcc
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

