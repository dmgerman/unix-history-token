begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)setprivs.c	4.2	(Melbourne)	82/02/20	*/
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/quota.h>
end_include

begin_include
include|#
directive|include
file|<sys/mush.h>
end_include

begin_include
include|#
directive|include
file|<mushmuck.h>
end_include

begin_include
include|#
directive|include
file|<udata.h>
end_include

begin_include
include|#
directive|include
file|<lpdquota.h>
end_include

begin_expr_stmt
name|setprivs
argument_list|(
name|uid
argument_list|,
name|mm
argument_list|,
name|lq
argument_list|,
name|dq
argument_list|,
name|dqf
argument_list|,
name|ud
argument_list|)
specifier|register
name|uid
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|struct
name|mushmuck
modifier|*
name|mm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|struct
name|lpquota
modifier|*
name|lq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|struct
name|dquot
modifier|*
name|dq
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|register
name|char
argument_list|(
operator|*
name|dqf
argument_list|)
index|[
literal|32
index|]
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|struct
name|udata
modifier|*
name|ud
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|putudata
argument_list|(
name|uid
argument_list|,
name|ud
argument_list|)
expr_stmt|;
name|putlpquota
argument_list|(
name|uid
argument_list|,
name|lq
argument_list|)
expr_stmt|;
name|putmush
argument_list|(
name|uid
argument_list|,
name|mm
argument_list|,
operator|(
expr|struct
name|mushmuck
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|putdiscq
argument_list|(
name|uid
argument_list|,
name|dq
argument_list|,
name|dqf
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

