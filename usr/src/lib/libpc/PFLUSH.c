begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)PFLUSH.c 1.1 10/29/80"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_comment
comment|/*  * insure that a usable image is in the buffer window  */
end_comment

begin_macro
name|PFLUSH
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|struct
name|iorec
modifier|*
name|next
decl_stmt|;
name|next
operator|=
name|_fchain
operator|.
name|fchain
expr_stmt|;
while|while
condition|(
name|next
operator|!=
name|FILNIL
condition|)
block|{
if|if
condition|(
operator|(
name|next
operator|->
name|funit
operator|&
operator|(
name|FDEF
operator||
name|FREAD
operator|)
operator|)
operator|==
literal|0
condition|)
block|{
name|fflush
argument_list|(
name|next
operator|->
name|fbuf
argument_list|)
expr_stmt|;
block|}
name|next
operator|=
name|next
operator|->
name|fchain
expr_stmt|;
block|}
block|}
end_block

end_unit

