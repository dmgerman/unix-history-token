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
literal|"@(#)wwflush.c	3.4 83/09/14"
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
file|"tt.h"
end_include

begin_macro
name|wwflush
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|wwcursorrow
operator|<
literal|0
operator|||
name|wwcursorrow
operator|>=
name|wwnrow
operator|||
name|wwcursorcol
operator|<
literal|0
operator|||
name|wwcursorcol
operator|>=
name|wwncol
condition|)
call|(
modifier|*
name|tt
operator|.
name|tt_move
call|)
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|else
call|(
modifier|*
name|tt
operator|.
name|tt_move
call|)
argument_list|(
name|wwcursorrow
argument_list|,
name|wwcursorcol
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

