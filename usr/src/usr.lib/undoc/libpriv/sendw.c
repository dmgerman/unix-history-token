begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)sendw.c	4.2	(Melbourne)	82/01/22	*/
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/mush.h>
end_include

begin_include
include|#
directive|include
file|<sys/mu_msg.h>
end_include

begin_macro
name|sendw
argument_list|(
argument|smp
argument_list|,
argument|rmp
argument_list|,
argument|opt
argument_list|)
end_macro

begin_decl_stmt
name|mmsgbuf
modifier|*
name|smp
decl_stmt|,
modifier|*
name|rmp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|mmsgbuf
name|mb
decl_stmt|;
specifier|register
name|r
expr_stmt|;
name|mb
operator|=
operator|*
name|smp
expr_stmt|;
if|if
condition|(
operator|(
name|r
operator|=
name|mu_msg
argument_list|(
name|MSG_SNDW
argument_list|,
name|opt
argument_list|,
operator|&
name|mb
argument_list|)
operator|)
operator|>=
literal|0
condition|)
operator|*
name|rmp
operator|=
name|mb
expr_stmt|;
return|return
name|r
return|;
block|}
end_block

end_unit

