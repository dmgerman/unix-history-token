begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)uucpdefs.c	5.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_decl_stmt
name|char
name|Progname
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Ifn
decl_stmt|,
name|Ofn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|Rmtname
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|User
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|Loginuser
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|Myname
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Bspeed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|Wrkdir
index|[
name|WKDSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Spool
init|=
name|SPOOL
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|UUDIR
end_ifdef

begin_decl_stmt
name|char
name|DLocal
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|DLocalX
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|Debug
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Pkdebug
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Packflg
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Pkdrvon
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|Retrytime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Unet
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 == UNET connection, else 0.  kludge to suppress ioctl */
end_comment

end_unit

