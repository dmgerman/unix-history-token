begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	Awrite_back.c	1.1	86/07/20	*/
end_comment

begin_include
include|#
directive|include
file|"../tahoealign/align.h"
end_include

begin_macro
name|write_back
argument_list|(
argument|infop
argument_list|,
argument|value
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
name|value
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
comment|/* /*	Put the given result where the operand specifies.  /*	 /* /**************************************************/
end_comment

begin_block
block|{
switch|switch
condition|(
name|where
operator|->
name|length
condition|)
block|{
case|case
literal|1
case|:
name|write_byte
argument_list|(
name|infop
argument_list|,
name|value
argument_list|,
name|where
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|write_word
argument_list|(
name|infop
argument_list|,
name|value
argument_list|,
name|where
argument_list|)
expr_stmt|;
break|break;
case|case
literal|4
case|:
name|write_longword
argument_list|(
name|infop
argument_list|,
name|value
argument_list|,
name|where
argument_list|)
expr_stmt|;
break|break;
case|case
literal|8
case|:
name|write_quadword
argument_list|(
name|infop
argument_list|,
name|value
argument_list|,
name|where
argument_list|)
expr_stmt|;
break|break;
default|default :
name|printf
argument_list|(
literal|"Wrong destination length in alignment\n"
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

