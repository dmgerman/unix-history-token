begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)intss.c	4.2 (Berkeley) 7/1/81 */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/*  * Name refers to ``in TSS'', i.e. in the  * TSS operating system and thus that input is a terminal.  */
end_comment

begin_macro
name|intss
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
name|isatty
argument_list|(
name|fileno
argument_list|(
name|stdin
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

