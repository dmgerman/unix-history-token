begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)fprintf.c	4.1 (Berkeley) 12/21/80 */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_macro
name|fprintf
argument_list|(
argument|iop
argument_list|,
argument|fmt
argument_list|,
argument|args
argument_list|)
end_macro

begin_decl_stmt
name|FILE
modifier|*
name|iop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|_doprnt
argument_list|(
name|fmt
argument_list|,
operator|&
name|args
argument_list|,
name|iop
argument_list|)
expr_stmt|;
return|return
operator|(
name|ferror
argument_list|(
name|iop
argument_list|)
condition|?
name|EOF
else|:
literal|0
operator|)
return|;
block|}
end_block

end_unit

