begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)NEWZ.c 1.1 10/29/80"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_include
include|#
directive|include
file|"h01errs.h"
end_include

begin_macro
name|NEWZ
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
name|int
name|size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sizeof struct pointed to by var */
end_comment

begin_block
block|{
specifier|register
name|char
modifier|*
name|cp
decl_stmt|;
name|char
modifier|*
name|limit
decl_stmt|;
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
name|cp
operator|=
name|malloc
argument_list|(
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|cp
operator|==
literal|0
condition|)
block|{
name|ERROR
argument_list|(
name|EOUTOFMEM
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
operator|*
name|var
operator|=
name|cp
expr_stmt|;
if|if
condition|(
name|cp
operator|<
name|_minptr
condition|)
name|_minptr
operator|=
name|cp
expr_stmt|;
name|limit
operator|=
name|cp
operator|+
name|size
expr_stmt|;
if|if
condition|(
name|limit
operator|>
name|_maxptr
condition|)
name|_maxptr
operator|=
name|limit
expr_stmt|;
for|for
control|(
init|;
name|cp
operator|<
name|limit
condition|;
operator|*
name|cp
operator|++
operator|=
literal|'\0'
control|)
comment|/* void */
empty_stmt|;
block|}
end_block

end_unit

