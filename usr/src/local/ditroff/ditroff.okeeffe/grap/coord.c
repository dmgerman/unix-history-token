begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
literal|"@(#)coord.c	1.1 (CWI) 85/07/19"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"grap.h"
end_include

begin_include
include|#
directive|include
file|"y.tab.h"
end_include

begin_decl_stmt
name|char
modifier|*
name|dflt_coord
init|=
literal|"gg"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|curr_coord
init|=
literal|"gg"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ncoord
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of explicit coord's given */
end_comment

begin_decl_stmt
name|Point
name|xcoord
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Point
name|ycoord
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|xcflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 if xcoord set */
end_comment

begin_decl_stmt
name|int
name|ycflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|logcoord
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_macro
name|coord_x
argument_list|(
argument|pt
argument_list|)
end_macro

begin_comment
comment|/* remember x coord */
end_comment

begin_decl_stmt
name|Point
name|pt
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|xcoord
operator|=
name|pt
expr_stmt|;
name|xcflag
operator|=
literal|1
expr_stmt|;
name|margin
operator|=
literal|0
expr_stmt|;
comment|/* no extra space around picture if explicit coords */
block|}
end_block

begin_macro
name|coord_y
argument_list|(
argument|pt
argument_list|)
end_macro

begin_decl_stmt
name|Point
name|pt
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|ycoord
operator|=
name|pt
expr_stmt|;
name|ycflag
operator|=
literal|1
expr_stmt|;
name|margin
operator|=
literal|0
expr_stmt|;
comment|/* no extra space if explicit coords */
block|}
end_block

begin_macro
name|coordlog
argument_list|(
argument|n
argument_list|)
end_macro

begin_comment
comment|/* remember log scaling */
end_comment

begin_decl_stmt
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|logcoord
operator|=
name|n
expr_stmt|;
block|}
end_block

begin_macro
name|coord
argument_list|(
argument|p
argument_list|)
end_macro

begin_comment
comment|/* set coord range */
end_comment

begin_decl_stmt
name|Obj
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|static
name|char
name|buf
index|[
literal|10
index|]
decl_stmt|;
name|ncoord
operator|++
expr_stmt|;
if|if
condition|(
name|ncoord
operator|>
literal|1
operator|&&
name|strcmp
argument_list|(
name|p
operator|->
name|name
argument_list|,
name|dflt_coord
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* resetting default coordinate by implication */
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"gg%d"
argument_list|,
name|ncoord
argument_list|)
expr_stmt|;
name|dflt_coord
operator|=
name|buf
expr_stmt|;
name|p
operator|=
name|lookup
argument_list|(
name|dflt_coord
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|xcflag
condition|)
block|{
name|p
operator|->
name|coord
operator||=
name|XFLAG
expr_stmt|;
name|p
operator|->
name|pt
operator|.
name|x
operator|=
name|min
argument_list|(
name|xcoord
operator|.
name|x
argument_list|,
name|xcoord
operator|.
name|y
argument_list|)
expr_stmt|;
comment|/* "xcoord" is xmin, xmax */
name|p
operator|->
name|pt1
operator|.
name|x
operator|=
name|max
argument_list|(
name|xcoord
operator|.
name|x
argument_list|,
name|xcoord
operator|.
name|y
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|logcoord
operator|&
name|XFLAG
operator|)
operator|&&
name|p
operator|->
name|pt
operator|.
name|x
operator|<=
literal|0.0
condition|)
name|fatal
argument_list|(
literal|"can't have log of x coord %g,%g"
argument_list|,
name|p
operator|->
name|pt
operator|.
name|x
argument_list|,
name|p
operator|->
name|pt1
operator|.
name|x
argument_list|)
expr_stmt|;
name|xcflag
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|ycflag
condition|)
block|{
name|p
operator|->
name|coord
operator||=
name|YFLAG
expr_stmt|;
name|p
operator|->
name|pt
operator|.
name|y
operator|=
name|min
argument_list|(
name|ycoord
operator|.
name|x
argument_list|,
name|ycoord
operator|.
name|y
argument_list|)
expr_stmt|;
comment|/* "ycoord" is ymin, ymax */
name|p
operator|->
name|pt1
operator|.
name|y
operator|=
name|max
argument_list|(
name|ycoord
operator|.
name|x
argument_list|,
name|ycoord
operator|.
name|y
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|logcoord
operator|&
name|YFLAG
operator|)
operator|&&
name|p
operator|->
name|pt
operator|.
name|y
operator|<=
literal|0.0
condition|)
name|fatal
argument_list|(
literal|"can't have log of y coord %g,%g"
argument_list|,
name|p
operator|->
name|pt
operator|.
name|y
argument_list|,
name|p
operator|->
name|pt1
operator|.
name|y
argument_list|)
expr_stmt|;
name|ycflag
operator|=
literal|0
expr_stmt|;
block|}
name|p
operator|->
name|log
operator|=
name|logcoord
expr_stmt|;
name|logcoord
operator|=
literal|0
expr_stmt|;
name|auto_x
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_macro
name|resetcoord
argument_list|(
argument|p
argument_list|)
end_macro

begin_comment
comment|/* reset current coordinate */
end_comment

begin_decl_stmt
name|Obj
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|curr_coord
operator|=
name|p
operator|->
name|name
expr_stmt|;
block|}
end_block

end_unit

