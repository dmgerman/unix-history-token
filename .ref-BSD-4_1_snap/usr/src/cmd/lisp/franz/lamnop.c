begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)lamnop.c	35.1 5/6/81"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"global.h"
end_include

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
name|mcounts
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mcountp
init|=
operator|(
name|int
operator|)
name|mcounts
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

end_unit

