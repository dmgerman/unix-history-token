begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/timeb.h>
end_include

begin_decl_stmt
specifier|static
name|struct
name|timeb
name|gorp
init|=
block|{
literal|0L
block|,
literal|0
block|,
literal|5
operator|*
literal|60
block|,
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_macro
name|ftime
argument_list|(
argument|gorpp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|timeb
modifier|*
name|gorpp
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|*
name|gorpp
operator|=
name|gorp
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

