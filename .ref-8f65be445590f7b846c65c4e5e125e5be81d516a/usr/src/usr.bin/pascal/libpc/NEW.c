begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1979 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)NEW.c	1.4 (Berkeley) %G%"
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
file|"h00vars.h"
end_include

begin_macro
name|NEW
argument_list|(
argument|var
argument_list|,
argument|size
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
modifier|*
name|var
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to item being deallocated */
end_comment

begin_decl_stmt
name|long
name|size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sizeof struct pointed to by var */
end_comment

begin_block
block|{
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
name|char
modifier|*
name|memblk
decl_stmt|;
name|memblk
operator|=
name|malloc
argument_list|(
operator|(
name|int
operator|)
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|memblk
operator|==
literal|0
condition|)
block|{
name|ERROR
argument_list|(
literal|"Ran out of memory\n"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
operator|*
name|var
operator|=
name|memblk
expr_stmt|;
if|if
condition|(
name|memblk
operator|<
name|_minptr
condition|)
name|_minptr
operator|=
name|memblk
expr_stmt|;
if|if
condition|(
name|memblk
operator|+
name|size
operator|>
name|_maxptr
condition|)
name|_maxptr
operator|=
name|memblk
operator|+
name|size
expr_stmt|;
block|}
end_block

end_unit

