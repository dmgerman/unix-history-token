begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	pup_proto.c	6.1	83/07/29	*/
end_comment

begin_include
include|#
directive|include
file|"../h/param.h"
end_include

begin_include
include|#
directive|include
file|"../h/socket.h"
end_include

begin_include
include|#
directive|include
file|"../h/protosw.h"
end_include

begin_include
include|#
directive|include
file|"../h/domain.h"
end_include

begin_comment
comment|/*  * PUP-I protocol family: raw interface  */
end_comment

begin_function_decl
name|int
name|rpup_output
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|raw_usrreq
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|protosw
name|pupsw
index|[]
init|=
block|{
block|{
name|SOCK_RAW
block|,
name|PF_PUP
block|,
literal|0
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
literal|0
block|,
name|rpup_output
block|,
literal|0
block|,
literal|0
block|,
name|raw_usrreq
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|, }
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|domain
name|pupdomain
init|=
block|{
name|AF_PUP
block|,
literal|"pup"
block|,
name|pupsw
block|,
operator|&
name|pupsw
index|[
sizeof|sizeof
argument_list|(
name|pupsw
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|pupsw
index|[
literal|0
index|]
argument_list|)
index|]
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_comment
comment|/*  * 3 Mb/s Ethernet link protocol family: raw interface  */
end_comment

begin_function_decl
name|int
name|raw_enoutput
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|raw_usrreq
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|protosw
name|ensw
index|[]
init|=
block|{
block|{
name|SOCK_RAW
block|,
name|PF_ETHERLINK
block|,
literal|0
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
literal|0
block|,
name|raw_enoutput
block|,
literal|0
block|,
literal|0
block|,
name|raw_usrreq
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|, }
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|domain
name|endomain
init|=
block|{
name|AF_ETHERLINK
literal|"ether"
block|,
name|ensw
block|,
operator|&
name|ensw
index|[
sizeof|sizeof
argument_list|(
name|ensw
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|ensw
index|[
literal|0
index|]
argument_list|)
index|]
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

