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
name|sccsid
init|=
literal|"@(#)wwmisc.c	1.1 83/07/12"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ww.h"
end_include

begin_decl_stmt
name|struct
name|ww
modifier|*
name|_wwcurrent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|wwsetcurrent
argument_list|(
name|wp
argument_list|)
specifier|register
expr|struct
name|ww
operator|*
name|wp
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|_wwcurrent
operator|=
name|wp
expr_stmt|;
block|}
end_block

begin_macro
name|wwhaschildren
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|struct
name|ww
modifier|*
name|wp
decl_stmt|;
for|for
control|(
name|wp
operator|=
name|_wwhead
init|;
name|wp
condition|;
name|wp
operator|=
name|wp
operator|->
name|ww_next
control|)
if|if
condition|(
name|wp
operator|->
name|ww_state
operator|==
name|WW_HASPROC
condition|)
return|return
literal|1
return|;
return|return
literal|0
return|;
block|}
end_block

end_unit

