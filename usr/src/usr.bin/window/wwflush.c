begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)wwflush.c	3.11 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

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
specifier|register
name|row
operator|,
name|col
expr_stmt|;
if|if
condition|(
operator|(
name|row
operator|=
name|wwcursorrow
operator|)
operator|<
literal|0
condition|)
name|row
operator|=
literal|0
expr_stmt|;
elseif|else
if|if
condition|(
name|row
operator|>=
name|wwnrow
condition|)
name|row
operator|=
name|wwnrow
operator|-
literal|1
expr_stmt|;
if|if
condition|(
operator|(
name|col
operator|=
name|wwcursorcol
operator|)
operator|<
literal|0
condition|)
name|col
operator|=
literal|0
expr_stmt|;
elseif|else
if|if
condition|(
name|col
operator|>=
name|wwncol
condition|)
name|col
operator|=
name|wwncol
operator|-
literal|1
expr_stmt|;
name|xxmove
argument_list|(
name|row
argument_list|,
name|col
argument_list|)
expr_stmt|;
name|xxflush
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

