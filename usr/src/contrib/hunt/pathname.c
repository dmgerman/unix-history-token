begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Hunt  *  Copyright (c) 1985 Conrad C. Huang, Gregory S. Couch, Kenneth C.R.C. Arnold  *  San Francisco, California  */
end_comment

begin_comment
comment|/*  * There is no particular significance to the numbers assigned  * to Test_port.  They're just random numbers greater than the  * range reserved for privileged sockets.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|Driver
init|=
literal|"/home/socr/a/conrad/games/src/hunt/huntd.dbg"
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|INTERNET
end_ifdef

begin_decl_stmt
name|u_short
name|Test_port
init|=
operator|(
literal|'h'
operator|<<
literal|8
operator|)
operator||
literal|'t'
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|Sock_name
init|=
literal|"/tmp/hunt"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Stat_name
init|=
literal|"/tmp/hunt.stats"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|Driver
init|=
name|HUNTD
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|INTERNET
end_ifdef

begin_decl_stmt
name|u_short
name|Test_port
init|=
operator|(
literal|'h'
operator|<<
literal|8
operator|)
operator||
literal|'t'
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|Sock_name
init|=
literal|"/tmp/hunt"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Stat_name
init|=
literal|"/tmp/hunt.stats"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

