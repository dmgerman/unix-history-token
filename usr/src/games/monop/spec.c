begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)spec.c	5.2 (Berkeley) 6/18/88"
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

begin_decl_stmt
specifier|static
name|char
modifier|*
name|perc
index|[]
init|=
block|{
literal|"10%"
block|,
literal|"ten percent"
block|,
literal|"%"
block|,
literal|"$200"
block|,
literal|"200"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_macro
name|inc_tax
argument_list|()
end_macro

begin_block
block|{
comment|/* collect income tax			*/
name|reg
name|int
name|worth
decl_stmt|,
name|com_num
decl_stmt|;
name|com_num
operator|=
name|getinp
argument_list|(
literal|"Do you wish to lose 10%% of your total worth or $200? "
argument_list|,
name|perc
argument_list|)
expr_stmt|;
name|worth
operator|=
name|cur_p
operator|->
name|money
operator|+
name|prop_worth
argument_list|(
name|cur_p
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"You were worth $%d"
argument_list|,
name|worth
argument_list|)
expr_stmt|;
name|worth
operator|/=
literal|10
expr_stmt|;
if|if
condition|(
name|com_num
operator|>
literal|2
condition|)
block|{
if|if
condition|(
name|worth
operator|<
literal|200
condition|)
name|printf
argument_list|(
literal|".  Good try, but not quite.\n"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|worth
operator|>
literal|200
condition|)
name|lucky
argument_list|(
literal|".\nGood guess.  "
argument_list|)
expr_stmt|;
name|cur_p
operator|->
name|money
operator|-=
literal|200
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|", so you pay $%d"
argument_list|,
name|worth
argument_list|)
expr_stmt|;
if|if
condition|(
name|worth
operator|>
literal|200
condition|)
name|printf
argument_list|(
literal|"  OUCH!!!!.\n"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|worth
operator|<
literal|200
condition|)
name|lucky
argument_list|(
literal|"\nGood guess.  "
argument_list|)
expr_stmt|;
name|cur_p
operator|->
name|money
operator|-=
name|worth
expr_stmt|;
block|}
if|if
condition|(
name|worth
operator|==
literal|200
condition|)
name|lucky
argument_list|(
literal|"\nIt makes no difference!  "
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|goto_jail
argument_list|()
end_macro

begin_block
block|{
comment|/* move player to jail			*/
name|cur_p
operator|->
name|loc
operator|=
name|JAIL
expr_stmt|;
block|}
end_block

begin_macro
name|lux_tax
argument_list|()
end_macro

begin_block
block|{
comment|/* landing on luxury tax		*/
name|printf
argument_list|(
literal|"You lose $75\n"
argument_list|)
expr_stmt|;
name|cur_p
operator|->
name|money
operator|-=
literal|75
expr_stmt|;
block|}
end_block

begin_macro
name|cc
argument_list|()
end_macro

begin_block
block|{
comment|/* draw community chest card		*/
name|get_card
argument_list|(
operator|&
name|CC_D
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|chance
argument_list|()
end_macro

begin_block
block|{
comment|/* draw chance card			*/
name|get_card
argument_list|(
operator|&
name|CH_D
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

