begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	Aput_byte.c	1.1	86/07/20	*/
end_comment

begin_include
include|#
directive|include
file|"../tahoealign/align.h"
end_include

begin_macro
name|put_byte
argument_list|(
argument|infop
argument_list|,
argument|byte
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
name|char
modifier|*
name|where
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|byte
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* /*	Put the byte at the given address in memory. /*	Caveat: It's quite difficult to find a pte reference /*		fault.  So I took the easy way out and just signal /*		an illegal access. /*	 /**************************************************/
end_comment

begin_block
block|{
specifier|register
name|long
name|code
decl_stmt|;
name|code
operator|=
name|writeable
argument_list|(
name|infop
argument_list|,
name|where
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|code
operator|==
name|TRUE
condition|)
block|{
operator|*
name|where
operator|=
name|byte
expr_stmt|;
block|}
else|else
name|exception
argument_list|(
name|infop
argument_list|,
name|ILL_ACCESS
argument_list|,
name|where
argument_list|,
name|code
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

