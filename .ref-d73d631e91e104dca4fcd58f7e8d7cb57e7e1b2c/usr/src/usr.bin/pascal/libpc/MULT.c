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
literal|"@(#)MULT.c	1.3 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_function
name|long
modifier|*
name|MULT
parameter_list|(
name|result0
parameter_list|,
name|left
parameter_list|,
name|right
parameter_list|,
name|siz
parameter_list|)
name|long
modifier|*
name|result0
decl_stmt|;
specifier|register
name|long
modifier|*
name|left
decl_stmt|;
specifier|register
name|long
modifier|*
name|right
decl_stmt|;
name|long
name|siz
decl_stmt|;
block|{
specifier|register
name|long
modifier|*
name|result
init|=
name|result0
decl_stmt|;
specifier|register
name|int
name|size
init|=
name|siz
decl_stmt|;
do|do
block|{
operator|*
name|result
operator|++
operator|=
operator|*
name|left
operator|++
operator|&
operator|*
name|right
operator|++
expr_stmt|;
block|}
do|while
condition|(
operator|--
name|size
condition|)
do|;
return|return
name|result0
return|;
block|}
end_function

end_unit

