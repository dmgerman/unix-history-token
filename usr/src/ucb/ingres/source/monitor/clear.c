begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"monitor.h"
end_include

begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_include
include|#
directive|include
file|<aux.h>
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)clear.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  Clear query buffer **	Flag f is set if called explicitly (with \q) and is **	clear if called automatically. ** **	Uses trace flag 3 */
end_comment

begin_macro
name|clear
argument_list|(
argument|f
argument_list|)
end_macro

begin_block
block|{
name|Autoclear
operator|=
literal|0
expr_stmt|;
comment|/* TRUNCATE FILE& RETURN */
if|if
condition|(
name|freopen
argument_list|(
name|Qbname
argument_list|,
literal|"w"
argument_list|,
name|Qryiop
argument_list|)
operator|==
name|NULL
condition|)
name|syserr
argument_list|(
literal|"clear: open"
argument_list|)
expr_stmt|;
if|if
condition|(
name|Nodayfile
operator|>=
literal|0
operator|&&
name|f
condition|)
name|printf
argument_list|(
literal|"\07go\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|f
condition|)
name|clrline
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|Notnull
operator|=
literal|0
expr_stmt|;
block|}
end_block

end_unit

