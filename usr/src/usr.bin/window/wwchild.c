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
literal|"@(#)wwchild.c	2.1 83/07/30"
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

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_macro
name|wwchild
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
name|union
name|wait
name|w
decl_stmt|;
name|int
name|pid
decl_stmt|;
while|while
condition|(
operator|(
name|pid
operator|=
name|wait3
argument_list|(
operator|&
name|w
argument_list|,
name|WNOHANG
operator||
name|WUNTRACED
argument_list|,
literal|0
argument_list|)
operator|)
operator|>
literal|0
condition|)
block|{
for|for
control|(
name|wp
operator|=
name|wwhead
init|;
name|wp
condition|;
name|wp
operator|=
name|wp
operator|->
name|ww_next
control|)
block|{
if|if
condition|(
name|wp
operator|->
name|ww_pid
operator|==
name|pid
condition|)
block|{
name|wp
operator|->
name|ww_state
operator|=
name|WW_DEAD
expr_stmt|;
comment|/* 				wwprintf(curwin, 					"\r\n%d: Died\r\n", pid); 				*/
break|break;
block|}
block|}
comment|/* 		if (wp == 0) 			wwprintf(curwin, "\r\n%d: No such child\r\n", pid); 		*/
block|}
block|}
end_block

end_unit

