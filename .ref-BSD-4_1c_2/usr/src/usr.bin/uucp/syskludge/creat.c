begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)creat.c	4.3 (Berkeley) 1/3/83 */
end_comment

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_macro
name|creat
argument_list|(
argument|file
argument_list|,
argument|mode
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mode
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|open
argument_list|(
name|file
argument_list|,
name|FCREATE
operator||
name|FWRONLY
operator||
name|FTRUNCATE
argument_list|,
name|mode
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

