begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)conf.c	7.2 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"../machine/pte.h"
end_include

begin_include
include|#
directive|include
file|"../h/param.h"
end_include

begin_include
include|#
directive|include
file|"../h/inode.h"
end_include

begin_include
include|#
directive|include
file|"../h/fs.h"
end_include

begin_include
include|#
directive|include
file|"../vaxmba/mbareg.h"
end_include

begin_include
include|#
directive|include
file|"saio.h"
end_include

begin_expr_stmt
name|devread
argument_list|(
name|io
argument_list|)
specifier|register
expr|struct
name|iob
operator|*
name|io
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|int
name|cc
decl_stmt|;
name|io
operator|->
name|i_flgs
operator||=
name|F_RDDATA
expr_stmt|;
name|io
operator|->
name|i_error
operator|=
literal|0
expr_stmt|;
name|cc
operator|=
operator|(
operator|*
name|devsw
index|[
name|io
operator|->
name|i_ino
operator|.
name|i_dev
index|]
operator|.
name|dv_strategy
operator|)
operator|(
name|io
operator|,
name|READ
operator|)
expr_stmt|;
name|io
operator|->
name|i_flgs
operator|&=
operator|~
name|F_TYPEMASK
expr_stmt|;
return|return
operator|(
name|cc
operator|)
return|;
block|}
end_block

begin_expr_stmt
name|devwrite
argument_list|(
name|io
argument_list|)
specifier|register
expr|struct
name|iob
operator|*
name|io
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|int
name|cc
decl_stmt|;
name|io
operator|->
name|i_flgs
operator||=
name|F_WRDATA
expr_stmt|;
name|io
operator|->
name|i_error
operator|=
literal|0
expr_stmt|;
name|cc
operator|=
operator|(
operator|*
name|devsw
index|[
name|io
operator|->
name|i_ino
operator|.
name|i_dev
index|]
operator|.
name|dv_strategy
operator|)
operator|(
name|io
operator|,
name|WRITE
operator|)
expr_stmt|;
name|io
operator|->
name|i_flgs
operator|&=
operator|~
name|F_TYPEMASK
expr_stmt|;
return|return
operator|(
name|cc
operator|)
return|;
block|}
end_block

begin_expr_stmt
name|devopen
argument_list|(
name|io
argument_list|)
specifier|register
expr|struct
name|iob
operator|*
name|io
expr_stmt|;
end_expr_stmt

begin_block
block|{
return|return
operator|(
operator|*
name|devsw
index|[
name|io
operator|->
name|i_ino
operator|.
name|i_dev
index|]
operator|.
name|dv_open
operator|)
operator|(
name|io
operator|)
return|;
block|}
end_block

begin_expr_stmt
name|devclose
argument_list|(
name|io
argument_list|)
specifier|register
expr|struct
name|iob
operator|*
name|io
expr_stmt|;
end_expr_stmt

begin_block
block|{
operator|(
operator|*
name|devsw
index|[
name|io
operator|->
name|i_ino
operator|.
name|i_dev
index|]
operator|.
name|dv_close
operator|)
operator|(
name|io
operator|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|devioctl
argument_list|(
name|io
argument_list|,
name|cmd
argument_list|,
name|arg
argument_list|)
specifier|register
expr|struct
name|iob
operator|*
name|io
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|caddr_t
name|arg
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
operator|(
operator|*
name|devsw
index|[
name|io
operator|->
name|i_ino
operator|.
name|i_dev
index|]
operator|.
name|dv_ioctl
operator|)
operator|(
name|io
operator|,
name|cmd
operator|,
name|arg
operator|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|nullsys
argument_list|(
argument|io
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|iob
modifier|*
name|io
decl_stmt|;
end_decl_stmt

begin_block
block|{
empty_stmt|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|nodev
argument_list|(
argument|io
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|iob
modifier|*
name|io
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|errno
operator|=
name|EBADF
expr_stmt|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|noioctl
argument_list|(
argument|io
argument_list|,
argument|cmd
argument_list|,
argument|arg
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|iob
modifier|*
name|io
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|caddr_t
name|arg
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|ECMD
operator|)
return|;
block|}
end_block

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VAX780
argument_list|)
operator|||
name|defined
argument_list|(
name|VAX750
argument_list|)
operator|||
name|defined
argument_list|(
name|VAX8600
argument_list|)
end_if

begin_define
define|#
directive|define
name|HP
value|"hp"
end_define

begin_decl_stmt
name|int
name|hpstrategy
argument_list|()
decl_stmt|,
name|hpopen
argument_list|()
decl_stmt|,
name|hpioctl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HP
value|""
end_define

begin_define
define|#
directive|define
name|hpstrategy
value|nodev
end_define

begin_define
define|#
directive|define
name|hpopen
value|nodev
end_define

begin_define
define|#
directive|define
name|hpioctl
value|noioctl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|upstrategy
argument_list|()
decl_stmt|,
name|upopen
argument_list|()
decl_stmt|,
name|upioctl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rkstrategy
argument_list|()
decl_stmt|,
name|rkopen
argument_list|()
decl_stmt|,
name|rkioctl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rastrategy
argument_list|()
decl_stmt|,
name|raopen
argument_list|()
decl_stmt|,
name|raioctl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VAX730
argument_list|)
end_if

begin_define
define|#
directive|define
name|RB
value|"rb"
end_define

begin_decl_stmt
name|int
name|idcstrategy
argument_list|()
decl_stmt|,
name|idcopen
argument_list|()
decl_stmt|,
name|idcioctl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RB
value|""
end_define

begin_define
define|#
directive|define
name|idcstrategy
value|nodev
end_define

begin_define
define|#
directive|define
name|idcopen
value|nodev
end_define

begin_define
define|#
directive|define
name|idcioctl
value|noioctl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|rlstrategy
argument_list|()
decl_stmt|,
name|rlopen
argument_list|()
decl_stmt|,
name|rlioctl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|BOOT
end_ifndef

begin_define
define|#
directive|define
name|TM
value|"tm"
end_define

begin_decl_stmt
name|int
name|tmstrategy
argument_list|()
decl_stmt|,
name|tmopen
argument_list|()
decl_stmt|,
name|tmclose
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TS
value|"ts"
end_define

begin_decl_stmt
name|int
name|tsstrategy
argument_list|()
decl_stmt|,
name|tsopen
argument_list|()
decl_stmt|,
name|tsclose
argument_list|()
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VAX780
argument_list|)
operator|||
name|defined
argument_list|(
name|VAX750
argument_list|)
operator|||
name|defined
argument_list|(
name|VAX8600
argument_list|)
end_if

begin_define
define|#
directive|define
name|HT
value|"ht"
end_define

begin_decl_stmt
name|int
name|htstrategy
argument_list|()
decl_stmt|,
name|htopen
argument_list|()
decl_stmt|,
name|htclose
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MT
value|"mt"
end_define

begin_decl_stmt
name|int
name|mtstrategy
argument_list|()
decl_stmt|,
name|mtopen
argument_list|()
decl_stmt|,
name|mtclose
argument_list|()
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
else|massbus vax
end_else

begin_define
define|#
directive|define
name|HT
value|""
end_define

begin_define
define|#
directive|define
name|htstrategy
value|nodev
end_define

begin_define
define|#
directive|define
name|htopen
value|nodev
end_define

begin_define
define|#
directive|define
name|htclose
value|nodev
end_define

begin_define
define|#
directive|define
name|MT
value|""
end_define

begin_define
define|#
directive|define
name|mtstrategy
value|nodev
end_define

begin_define
define|#
directive|define
name|mtopen
value|nodev
end_define

begin_define
define|#
directive|define
name|mtclose
value|nodev
end_define

begin_endif
endif|#
directive|endif
endif|massbus vax
end_endif

begin_define
define|#
directive|define
name|UT
value|""
end_define

begin_decl_stmt
name|int
name|utstrategy
argument_list|()
decl_stmt|,
name|utopen
argument_list|()
decl_stmt|,
name|utclose
argument_list|()
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
else|BOOT
end_else

begin_define
define|#
directive|define
name|TM
value|""
end_define

begin_define
define|#
directive|define
name|tmstrategy
value|nodev
end_define

begin_define
define|#
directive|define
name|tmopen
value|nodev
end_define

begin_define
define|#
directive|define
name|tmclose
value|nodev
end_define

begin_define
define|#
directive|define
name|TS
value|""
end_define

begin_define
define|#
directive|define
name|tsstrategy
value|nodev
end_define

begin_define
define|#
directive|define
name|tsopen
value|nodev
end_define

begin_define
define|#
directive|define
name|tsclose
value|nodev
end_define

begin_define
define|#
directive|define
name|HT
value|""
end_define

begin_define
define|#
directive|define
name|htstrategy
value|nodev
end_define

begin_define
define|#
directive|define
name|htopen
value|nodev
end_define

begin_define
define|#
directive|define
name|htclose
value|nodev
end_define

begin_define
define|#
directive|define
name|MT
value|""
end_define

begin_define
define|#
directive|define
name|mtstrategy
value|nodev
end_define

begin_define
define|#
directive|define
name|mtopen
value|nodev
end_define

begin_define
define|#
directive|define
name|mtclose
value|nodev
end_define

begin_define
define|#
directive|define
name|UT
value|""
end_define

begin_define
define|#
directive|define
name|utstrategy
value|nodev
end_define

begin_define
define|#
directive|define
name|utopen
value|nodev
end_define

begin_define
define|#
directive|define
name|utclose
value|nodev
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|devsw
name|devsw
index|[]
init|=
block|{
block|{
name|HP
block|,
name|hpstrategy
block|,
name|hpopen
block|,
name|nullsys
block|,
name|hpioctl
block|}
block|,
comment|/* 0 = hp */
block|{
name|HT
block|,
name|htstrategy
block|,
name|htopen
block|,
name|htclose
block|,
name|noioctl
block|}
block|,
comment|/* 1 = ht */
block|{
literal|"up"
block|,
name|upstrategy
block|,
name|upopen
block|,
name|nullsys
block|,
name|upioctl
block|}
block|,
comment|/* 2 = up */
block|{
literal|"hk"
block|,
name|rkstrategy
block|,
name|rkopen
block|,
name|nullsys
block|,
name|rkioctl
block|}
block|,
comment|/* 3 = hk */
block|{
literal|""
block|,
name|nodev
block|,
name|nodev
block|,
name|nullsys
block|,
name|noioctl
block|}
block|,
comment|/* 4 = sw */
block|{
name|TM
block|,
name|tmstrategy
block|,
name|tmopen
block|,
name|tmclose
block|,
name|noioctl
block|}
block|,
comment|/* 5 = tm */
block|{
name|TS
block|,
name|tsstrategy
block|,
name|tsopen
block|,
name|tsclose
block|,
name|noioctl
block|}
block|,
comment|/* 6 = ts */
block|{
name|MT
block|,
name|mtstrategy
block|,
name|mtopen
block|,
name|mtclose
block|,
name|noioctl
block|}
block|,
comment|/* 7 = mt */
block|{
literal|""
block|,
name|nodev
block|,
name|nodev
block|,
name|nullsys
block|,
name|noioctl
block|}
block|,
comment|/* 8 = tu */
block|{
literal|"ra"
block|,
name|rastrategy
block|,
name|raopen
block|,
name|nullsys
block|,
name|raioctl
block|}
block|,
comment|/* 9 = ra */
block|{
name|UT
block|,
name|utstrategy
block|,
name|utopen
block|,
name|utclose
block|,
name|noioctl
block|}
block|,
comment|/* 10 = ut */
block|{
name|RB
block|,
name|idcstrategy
block|,
name|idcopen
block|,
name|nullsys
block|,
name|idcioctl
block|}
block|,
comment|/* 11 = rb */
block|{
literal|""
block|,
name|nodev
block|,
name|nodev
block|,
name|nullsys
block|,
name|noioctl
block|}
block|,
comment|/* 12 = uu */
block|{
literal|""
block|,
name|nodev
block|,
name|nodev
block|,
name|nullsys
block|,
name|noioctl
block|}
block|,
comment|/* 13 = rx */
block|{
literal|"rl"
block|,
name|rlstrategy
block|,
name|rlopen
block|,
name|nullsys
block|,
name|rlioctl
block|}
block|,
comment|/* 14 = rl */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|, }
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
operator|-
literal|1
operator|)
decl_stmt|;
end_decl_stmt

end_unit

