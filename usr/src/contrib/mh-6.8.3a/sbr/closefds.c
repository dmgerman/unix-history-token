begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* closefds.c - close-up fd:s */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|ident
index|[]
init|=
literal|"@(#)$Id: closefds.c,v 1.3 1992/12/15 00:20:22 jromine Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_include
include|#
directive|include
file|"../h/mh.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|BSD42
end_ifndef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not BSD42 */
end_comment

begin_function
name|void
name|closefds
parameter_list|(
name|i
parameter_list|)
specifier|register
name|int
name|i
decl_stmt|;
block|{
ifndef|#
directive|ifndef
name|BSD42
name|int
name|nbits
init|=
name|_NFILE
decl_stmt|;
else|#
directive|else
comment|/* BSD42 */
name|int
name|nbits
init|=
name|getdtablesize
argument_list|()
decl_stmt|;
endif|#
directive|endif
comment|/* BSD42 */
for|for
control|(
init|;
name|i
operator|<
name|nbits
condition|;
name|i
operator|++
control|)
ifdef|#
directive|ifdef
name|OVERHEAD
if|if
condition|(
name|i
operator|!=
name|fd_def
operator|&&
name|i
operator|!=
name|fd_ctx
condition|)
endif|#
directive|endif
comment|/* OVERHEAD */
operator|(
name|void
operator|)
name|close
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

