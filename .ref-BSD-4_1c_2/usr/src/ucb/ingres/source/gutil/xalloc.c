begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<useful.h>
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)xalloc.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  XALLOC -- allocate block of memory. ** **	This is just like malloc, except that it is guaranteed **	to succeed.  It will syserr if it fails. ** **	Parameters: **		sz -- size in bytes of memory area to allocate. ** **	Returns: **		pointer to area allocated. ** **	Side Effects: **		none. ** **	Trace Flags: **		none. */
end_comment

begin_function
name|char
modifier|*
name|xalloc
parameter_list|(
name|sz
parameter_list|)
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
name|syserr
argument_list|(
literal|"Out of memory"
argument_list|)
expr_stmt|;
return|return
operator|(
name|p
operator|)
return|;
block|}
end_function

end_unit

