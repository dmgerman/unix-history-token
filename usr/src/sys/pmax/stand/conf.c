begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)conf.c	7.5 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<stand/stand.h>
end_include

begin_decl_stmt
specifier|const
name|struct
name|callback
modifier|*
name|callv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|errno
decl_stmt|;
end_decl_stmt

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
name|rzstrategy
argument_list|()
decl_stmt|,
name|rzopen
argument_list|()
decl_stmt|,
name|rzclose
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|rzioctl
value|noioctl
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BOOT
end_ifndef

begin_decl_stmt
name|int
name|tzstrategy
argument_list|()
decl_stmt|,
name|tzopen
argument_list|()
decl_stmt|,
name|tzclose
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|tzioctl
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
literal|"rz"
block|,
name|rzstrategy
block|,
name|rzopen
block|,
name|rzclose
block|,
name|rzioctl
block|}
block|,
comment|/*0*/
ifndef|#
directive|ifndef
name|BOOT
block|{
literal|"tz"
block|,
name|tzstrategy
block|,
name|tzopen
block|,
name|tzclose
block|,
name|tzioctl
block|}
block|,
comment|/*1*/
endif|#
directive|endif
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

