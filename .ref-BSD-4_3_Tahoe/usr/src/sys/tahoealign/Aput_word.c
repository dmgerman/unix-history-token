begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	Aput_word.c	1.1	86/07/20	*/
end_comment

begin_include
include|#
directive|include
file|"../tahoealign/align.h"
end_include

begin_expr_stmt
name|put_word
argument_list|(
name|infop
argument_list|,
name|word
argument_list|,
name|where
argument_list|)
specifier|register
name|process_info
operator|*
name|infop
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|char
modifier|*
name|where
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|long
name|word
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* /*	Put the word at the given address in memory. /*	Caveat: It's quite difficult to find a pte reference /*		fault.  So I took the easy way out and just signal /*		an illegal access. /*	 /**************************************************/
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
literal|2
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
name|word
operator|>>
literal|8
expr_stmt|;
operator|*
operator|(
name|where
operator|+
literal|1
operator|)
operator|=
name|word
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

