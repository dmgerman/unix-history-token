begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sysexits.h>
end_include

begin_include
include|#
directive|include
file|"useful.h"
end_include

begin_comment
comment|/* **  UTIL.C -- General Purpose Routines ** **	Defines: **		stripquotes **		xalloc **		any */
end_comment

begin_escape
end_escape

begin_comment
comment|/* **  STRIPQUOTES -- Strip quotes& quote bits from a string. ** **	Runs through a string and strips off unquoted quote **	characters and quote bits.  This is done in place. ** **	Parameters: **		s -- the string to strip. ** **	Returns: **		none. ** **	Side Effects: **		none. ** **	Requires: **		none. ** **	Called By: **		deliver ** **	History: **		3/5/80 -- written. */
end_comment

begin_macro
name|stripquotes
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
specifier|register
name|char
modifier|*
name|q
decl_stmt|;
specifier|register
name|char
name|c
decl_stmt|;
for|for
control|(
name|p
operator|=
name|q
operator|=
name|s
init|;
operator|(
name|c
operator|=
operator|*
name|p
operator|++
operator|)
operator|!=
literal|'\0'
condition|;
control|)
block|{
if|if
condition|(
name|c
operator|!=
literal|'"'
condition|)
operator|*
name|q
operator|++
operator|=
name|c
operator|&
literal|0177
expr_stmt|;
block|}
operator|*
name|q
operator|=
literal|'\0'
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **  XALLOC -- Allocate memory and bitch wildly on failure. ** **	THIS IS A CLUDGE.  This should be made to give a proper **	error -- but after all, what can we do? ** **	Parameters: **		sz -- size of area to allocate. ** **	Returns: **		pointer to data region. ** **	Side Effects: **		Memory is allocated. ** **	Requires: **		malloc **		syserr **		exit ** **	Called By: **		lots of people. ** **	History: **		12/31/79 -- written. */
end_comment

begin_function
name|char
modifier|*
name|xalloc
parameter_list|(
name|sz
parameter_list|)
specifier|register
name|unsigned
name|int
name|sz
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
name|p
operator|=
name|malloc
argument_list|(
name|sz
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|==
name|NULL
condition|)
block|{
name|syserr
argument_list|(
literal|"Out of memory!!"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|EX_UNAVAIL
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|p
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  ANY -- Return TRUE if the character exists in the string. ** **	Parameters: **		c -- the character. **		s -- the string **			(sounds like an avant garde script) ** **	Returns: **		TRUE -- if c could be found in s. **		FALSE -- otherwise. ** **	Side Effects: **		none. ** **	Requires: **		none. ** **	Called By: **		prescan ** **	History: **		3/5/80 -- written. */
end_comment

begin_expr_stmt
name|any
argument_list|(
name|c
argument_list|,
name|s
argument_list|)
specifier|register
name|char
name|c
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
name|c2
decl_stmt|;
while|while
condition|(
operator|(
name|c2
operator|=
operator|*
name|s
operator|++
operator|)
operator|!=
literal|'\0'
condition|)
if|if
condition|(
name|c2
operator|==
name|c
condition|)
return|return
operator|(
name|TRUE
operator|)
return|;
return|return
operator|(
name|FALSE
operator|)
return|;
block|}
end_block

end_unit

