begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Header: lamp.c,v 1.3 83/12/09 16:51:36 sklower Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*					-[Tue Mar 22 15:17:09 1983 by jkf]-  * 	lamp.c				$Locker:  $  * interface with unix profiling  *  * (c) copyright 1982, Regents of the University of California  */
end_comment

begin_include
include|#
directive|include
file|"global.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PROF
end_ifdef

begin_define
define|#
directive|define
name|PBUFSZ
value|500000
end_define

begin_decl_stmt
name|short
name|pbuf
index|[
name|PBUFSZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* data space for fasl to put counters */
end_comment

begin_decl_stmt
name|int
name|mcnts
index|[
name|NMCOUNT
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mcntp
init|=
operator|(
name|int
operator|)
name|mcnts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|doprof
init|=
name|TRUE
decl_stmt|;
end_decl_stmt

begin_function
name|lispval
name|Lmonitor
parameter_list|()
block|{
extern|extern etext
operator|,
extern|countbase;
if|if
condition|(
name|np
operator|==
name|lbot
condition|)
block|{
name|monitor
argument_list|(
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
literal|0
argument_list|)
expr_stmt|;
name|countbase
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|TYPE
argument_list|(
name|lbot
operator|->
name|val
argument_list|)
operator|==
name|INT
condition|)
block|{
name|monitor
argument_list|(
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
literal|2
argument_list|,
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
name|lbot
operator|->
name|val
operator|->
name|i
argument_list|,
name|pbuf
argument_list|,
name|PBUFSZ
operator|*
operator|(
sizeof|sizeof
argument_list|(
name|short
argument_list|)
operator|)
argument_list|,
literal|7000
argument_list|)
expr_stmt|;
name|countbase
operator|=
operator|(
operator|(
name|int
operator|)
name|pbuf
operator|)
operator|+
literal|12
expr_stmt|;
block|}
else|else
block|{
name|monitor
argument_list|(
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
literal|2
argument_list|,
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
name|sbrk
argument_list|(
literal|0
argument_list|)
argument_list|,
name|pbuf
argument_list|,
name|PBUFSZ
operator|*
operator|(
sizeof|sizeof
argument_list|(
name|short
argument_list|)
operator|)
argument_list|,
literal|7000
argument_list|)
expr_stmt|;
name|countbase
operator|=
operator|(
operator|(
name|int
operator|)
name|pbuf
operator|)
operator|+
literal|12
expr_stmt|;
block|}
return|return
operator|(
name|tatom
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* if prof is not defined, create a dummy Lmonitor */
end_comment

begin_decl_stmt
name|short
name|pbuf
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* data space for fasl to put counters */
end_comment

begin_decl_stmt
name|int
name|mcnts
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mcntp
init|=
operator|(
name|int
operator|)
name|mcnts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|doprof
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_macro
name|Lmonitor
argument_list|()
end_macro

begin_block
block|{
name|error
argument_list|(
literal|"Profiling not enabled"
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

