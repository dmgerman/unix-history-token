begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)systemname.c	5.4 (Berkeley) %G%"
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
file|"trek.h"
end_include

begin_comment
comment|/* **  RETRIEVE THE STARSYSTEM NAME ** **	Very straightforward, this routine just gets the starsystem **	name.  It returns zero if none in the specified quadrant **	(which, by the way, is passed it). ** **	This routine knows all about such things as distressed **	starsystems, etc. */
end_comment

begin_function
name|char
modifier|*
name|systemname
parameter_list|(
name|q1
parameter_list|)
name|struct
name|quad
modifier|*
name|q1
decl_stmt|;
block|{
specifier|register
name|struct
name|quad
modifier|*
name|q
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
name|q
operator|=
name|q1
expr_stmt|;
name|i
operator|=
name|q
operator|->
name|qsystemname
expr_stmt|;
if|if
condition|(
name|i
operator|&
name|Q_DISTRESSED
condition|)
name|i
operator|=
name|Event
index|[
name|i
operator|&
name|Q_SYSTEM
index|]
operator|.
name|systemname
expr_stmt|;
name|i
operator|&=
name|Q_SYSTEM
expr_stmt|;
if|if
condition|(
name|i
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
name|Systemname
index|[
name|i
index|]
operator|)
return|;
block|}
end_function

end_unit

