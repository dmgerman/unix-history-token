begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)null_fn.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  NULL_FN -- A null function ** **	This routine does absolutely nothing at all. ** **	Algorithm: **		none. ** **	Parameters: **		none. ** **	Returns: **		zero ** **	Side Effects: **		none. ** **	Defined Constants: **		none. ** **	Defines: **		null_fn ** **	Requires: **		nothing. ** **	Required By: **		Lots (this system doesn't do much). ** **	Files: **		none. ** **	Compilation Flags: **		none. ** **	Trace Flags: **		none. ** **	Diagnostics: **		none. ** **	Syserrs: **		none. ** **	Deficiencies: **		It should do nothing faster. ** **	History: **		5/12/80 (eric& polly) -- written. ** **	Version: **		7.1 ** **	WARNING: **		Do not use this routine if you want to do something. */
end_comment

begin_macro
name|null_fn
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

