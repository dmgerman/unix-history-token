begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	Awrite_long.c	1.1	86/07/20	*/
end_comment

begin_include
include|#
directive|include
file|"../tahoealign/align.h"
end_include

begin_macro
name|write_longword
argument_list|(
argument|infop
argument_list|,
argument|longword
argument_list|,
argument|where
argument_list|)
end_macro

begin_decl_stmt
name|process_info
modifier|*
name|infop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|longword
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|oprnd
modifier|*
name|where
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* /*	Put the longword at the given address in /*	tahoe's memory. /* /**************************************************/
end_comment

begin_block
block|{
if|if
condition|(
operator|!
operator|(
name|where
operator|->
name|mode
operator|&
name|W
operator|)
condition|)
name|exception
argument_list|(
name|infop
argument_list|,
name|ILL_ADDRMOD
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|where
operator|->
name|mode
operator|&
name|ADDFIELD
condition|)
comment|/* Mask out R/W bits */
block|{
case|case
name|Add
case|:
case|case
name|SPmode
case|:
name|put_longword
argument_list|(
name|infop
argument_list|,
name|longword
argument_list|,
name|where
operator|->
name|address
argument_list|)
expr_stmt|;
break|break;
case|case
name|Dir
case|:
name|Replace
argument_list|(
name|infop
argument_list|,
name|where
operator|->
name|reg_number
argument_list|,
name|longword
argument_list|)
expr_stmt|;
break|break;
default|default:
name|printf
argument_list|(
literal|"Unknown destination in write_long (alignment code)\n"
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
end_block

end_unit

