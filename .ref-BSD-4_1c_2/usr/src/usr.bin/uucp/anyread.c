begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)anyread.c	4.1	(Berkeley)	9/11/82"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_comment
comment|/*******  *	anyread		check if anybody can read  *	return 0 ok: FAIL not ok  */
end_comment

begin_macro
name|anyread
argument_list|(
argument|file
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|file
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|stat
name|s
decl_stmt|;
if|if
condition|(
name|stat
argument_list|(
name|file
argument_list|,
operator|&
name|s
argument_list|)
operator|!=
literal|0
condition|)
comment|/* for security check a non existant file is readable */
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
operator|!
operator|(
name|s
operator|.
name|st_mode
operator|&
name|ANYREAD
operator|)
condition|)
return|return
operator|(
name|FAIL
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

