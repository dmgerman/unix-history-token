begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * %sccs.include.redist.c%  *  *	@(#)conf.c	8.2 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<stand/saio.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|nullsys
argument_list|()
decl_stmt|,
name|nodev
argument_list|()
decl_stmt|,
name|noioctl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wdstrategy
argument_list|()
decl_stmt|,
name|wdopen
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|wdioctl
value|noioctl
end_define

begin_decl_stmt
name|int
name|fdstrategy
argument_list|()
decl_stmt|,
name|fdopen
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|fdioctl
value|noioctl
end_define

begin_decl_stmt
name|struct
name|devsw
name|devsw
index|[]
init|=
block|{
block|{
literal|"wd"
block|,
name|wdstrategy
block|,
name|wdopen
block|,
name|nullsys
block|,
name|wdioctl
block|}
block|,
comment|/* 0 = wd */
block|{
name|NULL
block|}
block|,
comment|/* swapdev place holder */
block|{
literal|"fd"
block|,
name|fdstrategy
block|,
name|fdopen
block|,
name|nullsys
block|,
name|fdioctl
block|}
block|,
comment|/* 2 = fd */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ndevs
init|=
operator|(
sizeof|sizeof
argument_list|(
name|devsw
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|devsw
index|[
literal|0
index|]
argument_list|)
operator|)
decl_stmt|;
end_decl_stmt

end_unit

