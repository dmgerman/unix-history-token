begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_comment
comment|/* $Header: term.c,v 2.5 85/08/22 16:09:34 timo Exp $ */
end_comment

begin_comment
comment|/*  * B editor -- Init/end terminal-related modules.  *  * This file should be wiped out completely.  */
end_comment

begin_include
include|#
directive|include
file|"b.h"
end_include

begin_include
include|#
directive|include
file|"erro.h"
end_include

begin_decl_stmt
specifier|extern
name|bool
name|dflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|nosense
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Call initialization code of other terminal-dependent modules.  * N.B. the order of initializations is determined by black magic.  *	Don't change!  */
end_comment

begin_function
name|Visible
name|Procedure
name|initterm
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|NDEBUG
if|if
condition|(
name|dflag
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"*** initterm();\n\r"
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|NDEBUG
comment|/* initshow(); */
name|initgetc
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Extermination code, reverse of initterm().  * N.B. the order of exterminations is determined by black magic.  *      Don't change!  */
end_comment

begin_function
name|Visible
name|Procedure
name|endterm
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|NDEBUG
if|if
condition|(
name|dflag
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"*** endterm();\n\r"
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|NDEBUG
comment|/* endshow(); */
name|endgetc
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Compatible interface with trmsense; return No if not sensed.  */
end_comment

begin_function
name|Visible
name|bool
name|sense
parameter_list|(
name|py
parameter_list|,
name|px
parameter_list|)
name|int
modifier|*
name|py
decl_stmt|;
name|int
modifier|*
name|px
decl_stmt|;
block|{
name|trmsense
argument_list|(
name|py
argument_list|,
name|px
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|py
operator|>=
literal|0
operator|&&
operator|*
name|px
operator|>=
literal|0
condition|)
return|return
name|Yes
return|;
if|if
condition|(
name|nosense
condition|)
name|error
argument_list|(
name|GOTO_NO
argument_list|)
expr_stmt|;
else|else
name|error
argument_list|(
name|GOTO_BAD
argument_list|)
expr_stmt|;
return|return
name|No
return|;
block|}
end_function

end_unit

