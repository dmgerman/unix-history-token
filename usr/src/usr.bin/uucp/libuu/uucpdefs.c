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
literal|"@(#)uucpdefs.c	5.3 (Berkeley) %G%"
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
literal|64
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
name|RRmtname
index|[
literal|64
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Rmtname
init|=
name|RRmtname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|User
index|[
literal|128
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
name|char
name|Myfullname
index|[
literal|64
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

begin_decl_stmt
name|char
name|DLocal
index|[
literal|64
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|DLocalX
index|[
literal|64
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Debug
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
name|long
name|Retrytime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|Usrf
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Uustat global flag */
end_comment

begin_decl_stmt
name|int
name|IsTcpIp
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 == TCP/IP connection, else 0.  kludge to suppress ioctl */
end_comment

begin_decl_stmt
name|char
name|MaxGrade
init|=
literal|'\177'
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|DefMaxGrade
init|=
literal|'\177'
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nologinflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|NOLOGIN
index|[]
init|=
literal|"/etc/nologin"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Save some data space */
end_comment

begin_decl_stmt
name|char
name|DEVNULL
index|[]
init|=
literal|"/dev/null"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|CANTOPEN
index|[]
init|=
literal|"CAN'T OPEN"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|_FAILED
index|[]
init|=
literal|"FAILED"
decl_stmt|;
end_decl_stmt

end_unit

