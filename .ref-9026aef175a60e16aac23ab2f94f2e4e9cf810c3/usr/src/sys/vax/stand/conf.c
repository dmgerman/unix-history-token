begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1988 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)conf.c	7.10 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"sys/param.h"
end_include

begin_include
include|#
directive|include
file|"stand/saio.h"
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
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SMALL
end_ifdef

begin_define
define|#
directive|define
name|hpioctl
value|noioctl
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|hpioctl
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HP
value|0
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
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SMALL
end_ifdef

begin_define
define|#
directive|define
name|upioctl
value|noioctl
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|upioctl
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|rkstrategy
argument_list|()
decl_stmt|,
name|rkopen
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
value|0
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
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BOOT
end_ifdef

begin_define
define|#
directive|define
name|TM
value|0
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
value|0
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
value|0
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
value|0
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
value|0
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

begin_define
define|#
directive|define
name|TMSCP
value|0
end_define

begin_define
define|#
directive|define
name|tmscpstrategy
value|nodev
end_define

begin_define
define|#
directive|define
name|tmscpopen
value|nodev
end_define

begin_define
define|#
directive|define
name|tmscpclose
value|nodev
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !BOOT */
end_comment

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
end_else

begin_comment
comment|/* massbus vax */
end_comment

begin_define
define|#
directive|define
name|HT
value|0
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
value|0
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
end_endif

begin_comment
comment|/* massbus vax */
end_comment

begin_define
define|#
directive|define
name|UT
value|"ut"
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

begin_define
define|#
directive|define
name|TMSCP
value|"tms"
end_define

begin_decl_stmt
name|int
name|tmscpstrategy
argument_list|()
decl_stmt|,
name|tmscpopen
argument_list|()
decl_stmt|,
name|tmscpclose
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BOOT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VAX8200
end_ifdef

begin_define
define|#
directive|define
name|KRA
value|"kra"
end_define

begin_decl_stmt
name|int
name|krastrategy
argument_list|()
decl_stmt|,
name|kraopen
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
name|KRA
value|0
end_define

begin_define
define|#
directive|define
name|krastrategy
value|nodev
end_define

begin_define
define|#
directive|define
name|kraopen
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
comment|/*  0 = hp */
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
comment|/*  1 = ht */
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
comment|/*  2 = up */
block|{
literal|"hk"
block|,
name|rkstrategy
block|,
name|rkopen
block|,
name|nullsys
block|,
name|noioctl
block|}
block|,
comment|/*  3 = hk */
block|{
literal|0
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
comment|/*  4 = sw */
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
comment|/*  5 = tm */
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
comment|/*  6 = ts */
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
comment|/*  7 = mt */
block|{
literal|0
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
comment|/*  8 = tu */
block|{
literal|"ra"
block|,
name|rastrategy
block|,
name|raopen
block|,
name|nullsys
block|,
name|noioctl
block|}
block|,
comment|/*  9 = ra */
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
name|noioctl
block|}
block|,
comment|/* 11 = rb */
block|{
literal|0
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
literal|0
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
name|noioctl
block|}
block|,
comment|/* 14 = rl */
block|{
name|TMSCP
block|,
name|tmscpstrategy
block|,
name|tmscpopen
block|,
name|tmscpclose
block|,
name|noioctl
block|}
block|,
comment|/* 15 = tmscp */
block|{
name|KRA
block|,
name|krastrategy
block|,
name|kraopen
block|,
name|nullsys
block|,
name|noioctl
block|}
block|,
comment|/* 16 = kra */
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

