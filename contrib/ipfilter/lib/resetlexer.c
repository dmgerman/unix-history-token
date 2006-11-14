begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_include
include|#
directive|include
file|"ipf.h"
end_include

begin_decl_stmt
name|long
name|string_start
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|string_end
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|string_val
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|pos
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|resetlexer
parameter_list|()
block|{
name|string_start
operator|=
operator|-
literal|1
expr_stmt|;
name|string_end
operator|=
operator|-
literal|1
expr_stmt|;
name|string_val
operator|=
name|NULL
expr_stmt|;
name|pos
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

