begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)morg.c	5.3 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"monop.ext"
end_include

begin_comment
comment|/*  *	These routines deal with mortgaging.  */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|names
index|[
name|MAX_PRP
operator|+
literal|2
index|]
decl_stmt|,
modifier|*
name|morg_coms
index|[]
init|=
block|{
literal|"quit"
block|,
comment|/*  0 */
literal|"print"
block|,
comment|/*  1 */
literal|"where"
block|,
comment|/*  2 */
literal|"own holdings"
block|,
comment|/*  3 */
literal|"holdings"
block|,
comment|/*  4 */
literal|"shell"
block|,
comment|/*  5 */
literal|"mortgage"
block|,
comment|/*  6 */
literal|"unmortgage"
block|,
comment|/*  7 */
literal|"buy"
block|,
comment|/*  8 */
literal|"sell"
block|,
comment|/*  9 */
literal|"card"
block|,
comment|/* 10 */
literal|"pay"
block|,
comment|/* 11 */
literal|"trade"
block|,
comment|/* 12 */
literal|"resign"
block|,
comment|/* 13 */
literal|"save game"
block|,
comment|/* 14 */
literal|"restore game"
block|,
comment|/* 15 */
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|shrt
name|square
index|[
name|MAX_PRP
operator|+
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|num_good
decl_stmt|,
name|got_houses
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	This routine is the command level response the mortgage command.  * it gets the list of mortgageable property and asks which are to  * be mortgaged.  */
end_comment

begin_macro
name|mortgage
argument_list|()
end_macro

begin_block
block|{
name|reg
name|int
name|prop
decl_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
name|set_mlist
argument_list|()
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|got_houses
condition|)
name|printf
argument_list|(
literal|"You can't mortgage property with houses on it.\n"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"You don't have any un-mortgaged property.\n"
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|num_good
operator|==
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"Your only mortageable property is %s\n"
argument_list|,
name|names
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|getyn
argument_list|(
literal|"Do you want to mortgage it? "
argument_list|)
operator|==
literal|0
condition|)
name|m
argument_list|(
name|square
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return;
block|}
name|prop
operator|=
name|getinp
argument_list|(
literal|"Which property do you want to mortgage? "
argument_list|,
name|names
argument_list|)
expr_stmt|;
if|if
condition|(
name|prop
operator|==
name|num_good
condition|)
return|return;
name|m
argument_list|(
name|square
index|[
name|prop
index|]
argument_list|)
expr_stmt|;
name|notify
argument_list|(
name|cur_p
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*  *	This routine sets up the list of mortgageable property  */
end_comment

begin_macro
name|set_mlist
argument_list|()
end_macro

begin_block
block|{
name|reg
name|OWN
modifier|*
name|op
decl_stmt|;
name|num_good
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|op
operator|=
name|cur_p
operator|->
name|own_list
init|;
name|op
condition|;
name|op
operator|=
name|op
operator|->
name|next
control|)
if|if
condition|(
operator|!
name|op
operator|->
name|sqr
operator|->
name|desc
operator|->
name|morg
condition|)
if|if
condition|(
name|op
operator|->
name|sqr
operator|->
name|type
operator|==
name|PRPTY
operator|&&
name|op
operator|->
name|sqr
operator|->
name|desc
operator|->
name|houses
condition|)
name|got_houses
operator|++
expr_stmt|;
else|else
block|{
name|names
index|[
name|num_good
index|]
operator|=
name|op
operator|->
name|sqr
operator|->
name|name
expr_stmt|;
name|square
index|[
name|num_good
operator|++
index|]
operator|=
name|sqnum
argument_list|(
name|op
operator|->
name|sqr
argument_list|)
expr_stmt|;
block|}
name|names
index|[
name|num_good
operator|++
index|]
operator|=
literal|"done"
expr_stmt|;
name|names
index|[
name|num_good
operator|--
index|]
operator|=
literal|0
expr_stmt|;
return|return
name|num_good
return|;
block|}
end_block

begin_comment
comment|/*  *	This routine actually mortgages the property.  */
end_comment

begin_macro
name|m
argument_list|(
argument|prop
argument_list|)
end_macro

begin_decl_stmt
name|reg
name|int
name|prop
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|reg
name|int
name|price
decl_stmt|;
name|price
operator|=
name|board
index|[
name|prop
index|]
operator|.
name|cost
operator|/
literal|2
expr_stmt|;
name|board
index|[
name|prop
index|]
operator|.
name|desc
operator|->
name|morg
operator|=
name|TRUE
expr_stmt|;
name|printf
argument_list|(
literal|"That got you $%d\n"
argument_list|,
name|price
argument_list|)
expr_stmt|;
name|cur_p
operator|->
name|money
operator|+=
name|price
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  *	This routine is the command level repsponse to the unmortgage  * command.  It gets the list of mortgaged property and asks which are  * to be unmortgaged.  */
end_comment

begin_macro
name|unmortgage
argument_list|()
end_macro

begin_block
block|{
name|reg
name|int
name|prop
decl_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
name|set_umlist
argument_list|()
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"You don't have any mortgaged property.\n"
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|num_good
operator|==
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"Your only mortaged property is %s\n"
argument_list|,
name|names
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|getyn
argument_list|(
literal|"Do you want to unmortgage it? "
argument_list|)
operator|==
literal|0
condition|)
name|unm
argument_list|(
name|square
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return;
block|}
name|prop
operator|=
name|getinp
argument_list|(
literal|"Which property do you want to unmortgage? "
argument_list|,
name|names
argument_list|)
expr_stmt|;
if|if
condition|(
name|prop
operator|==
name|num_good
condition|)
return|return;
name|unm
argument_list|(
name|square
index|[
name|prop
index|]
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*  *	This routine sets up the list of mortgaged property  */
end_comment

begin_macro
name|set_umlist
argument_list|()
end_macro

begin_block
block|{
name|reg
name|OWN
modifier|*
name|op
decl_stmt|;
name|num_good
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|op
operator|=
name|cur_p
operator|->
name|own_list
init|;
name|op
condition|;
name|op
operator|=
name|op
operator|->
name|next
control|)
if|if
condition|(
name|op
operator|->
name|sqr
operator|->
name|desc
operator|->
name|morg
condition|)
block|{
name|names
index|[
name|num_good
index|]
operator|=
name|op
operator|->
name|sqr
operator|->
name|name
expr_stmt|;
name|square
index|[
name|num_good
operator|++
index|]
operator|=
name|sqnum
argument_list|(
name|op
operator|->
name|sqr
argument_list|)
expr_stmt|;
block|}
name|names
index|[
name|num_good
operator|++
index|]
operator|=
literal|"done"
expr_stmt|;
name|names
index|[
name|num_good
operator|--
index|]
operator|=
literal|0
expr_stmt|;
return|return
name|num_good
return|;
block|}
end_block

begin_comment
comment|/*  *	This routine actually unmortgages the property  */
end_comment

begin_macro
name|unm
argument_list|(
argument|prop
argument_list|)
end_macro

begin_decl_stmt
name|reg
name|int
name|prop
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|reg
name|int
name|price
decl_stmt|;
name|price
operator|=
name|board
index|[
name|prop
index|]
operator|.
name|cost
operator|/
literal|2
expr_stmt|;
name|board
index|[
name|prop
index|]
operator|.
name|desc
operator|->
name|morg
operator|=
name|FALSE
expr_stmt|;
name|price
operator|+=
name|price
operator|/
literal|10
expr_stmt|;
name|printf
argument_list|(
literal|"That cost you $%d\n"
argument_list|,
name|price
argument_list|)
expr_stmt|;
name|cur_p
operator|->
name|money
operator|-=
name|price
expr_stmt|;
name|set_umlist
argument_list|()
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  *	This routine forces the indebted player to fix his  * financial woes.  */
end_comment

begin_macro
name|force_morg
argument_list|()
end_macro

begin_block
block|{
name|told_em
operator|=
name|fixing
operator|=
name|TRUE
expr_stmt|;
while|while
condition|(
name|cur_p
operator|->
name|money
operator|<=
literal|0
condition|)
name|fix_ex
argument_list|(
name|getinp
argument_list|(
literal|"How are you going to fix it up? "
argument_list|,
name|morg_coms
argument_list|)
argument_list|)
expr_stmt|;
name|fixing
operator|=
name|FALSE
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  *	This routine is a special execute for the force_morg routine  */
end_comment

begin_macro
name|fix_ex
argument_list|(
argument|com_num
argument_list|)
end_macro

begin_decl_stmt
name|reg
name|int
name|com_num
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|told_em
operator|=
name|FALSE
expr_stmt|;
call|(
modifier|*
name|func
index|[
name|com_num
index|]
call|)
argument_list|()
expr_stmt|;
name|notify
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

