begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * %sccs.include.redist.c%  *  *	@(#)ioconf.c	7.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/map.h>
end_include

begin_include
include|#
directive|include
file|<luna68k/stand/device.h>
end_include

begin_define
define|#
directive|define
name|C
value|(caddr_t)
end_define

begin_define
define|#
directive|define
name|D
value|(struct driver *)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|driver
name|scdriver
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|driver
name|sddriver
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|driver
name|stdriver
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|hp_ctlr
name|hp_cinit
index|[]
init|=
block|{
comment|/*	driver,		unit,	alive,	addr,	flags */
block|{
operator|&
name|scdriver
block|,
literal|0
block|,
literal|0
block|,
name|C
literal|0x0
block|,
literal|0x0
block|}
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|hp_device
name|hp_dinit
index|[]
init|=
block|{
comment|/*driver,	cdriver,	unit,	ctlr,	slave,	addr,	dk,	flags*/
block|{
operator|&
name|sddriver
block|,
operator|&
name|scdriver
block|,
literal|0
block|,
literal|0
block|,
literal|6
block|,
name|C
literal|0x0
block|,
literal|1
block|,
literal|0x0
block|}
block|,
block|{
operator|&
name|sddriver
block|,
operator|&
name|scdriver
block|,
literal|1
block|,
literal|0
block|,
literal|5
block|,
name|C
literal|0x0
block|,
literal|1
block|,
literal|0x0
block|}
block|,
block|{
operator|&
name|stdriver
block|,
operator|&
name|scdriver
block|,
literal|0
block|,
literal|0
block|,
literal|4
block|,
name|C
literal|0x0
block|,
literal|0
block|,
literal|0x0
block|}
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

end_unit

