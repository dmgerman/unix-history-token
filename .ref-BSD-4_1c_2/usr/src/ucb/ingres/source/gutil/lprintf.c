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
argument|@(#)lprintf.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  LPRINTF -- labelled printf ** **	Just like printf, except outputs the process name first. ** **	Parameters: **		fmt -- the format. **		p1 - p6 -- the parameters. ** **	Returns: **		none ** **	Side Effects: **		none ** **	Trace Flags: **		none */
end_comment

begin_macro
name|lprintf
argument_list|(
argument|fmt
argument_list|,
argument|p1
argument_list|,
argument|p2
argument_list|,
argument|p3
argument_list|,
argument|p4
argument_list|,
argument|p5
argument_list|,
argument|p6
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|extern
name|char
modifier|*
name|Proc_name
decl_stmt|;
if|if
condition|(
name|Proc_name
operator|!=
name|NULL
condition|)
name|printf
argument_list|(
literal|"%s: "
argument_list|,
name|Proc_name
argument_list|)
expr_stmt|;
name|printf
argument_list|(
name|fmt
argument_list|,
name|p1
argument_list|,
name|p2
argument_list|,
name|p3
argument_list|,
name|p4
argument_list|,
name|p5
argument_list|,
name|p6
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

