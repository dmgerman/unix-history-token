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
literal|"@(#)wwend.c	1.4 83/07/19"
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

begin_macro
name|wwend
argument_list|()
end_macro

begin_block
block|{
name|Wcleanup
argument_list|()
expr_stmt|;
name|wwsettty
argument_list|(
literal|0
argument_list|,
operator|&
name|wwoldtty
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

