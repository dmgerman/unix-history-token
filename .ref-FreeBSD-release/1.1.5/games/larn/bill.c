begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"header.h"
end_include

begin_comment
comment|/* bill.c		 "Larn is copyrighted 1986 by Noah Morgan. */
end_comment

begin_decl_stmt
specifier|static
name|char
name|mail600
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	function to create the tax bill for the user  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|pid
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|letter1
argument_list|()
block|{
name|sprintf
argument_list|(
name|mail600
argument_list|,
literal|"/tmp/#%dmail600"
argument_list|,
name|pid
argument_list|)
block|;
comment|/* prepare path */
if|if
condition|(
name|lcreat
argument_list|(
name|mail600
argument_list|)
operator|<
literal|0
condition|)
block|{
name|write
argument_list|(
literal|1
argument_list|,
literal|"can't write 600 letter\n"
argument_list|,
literal|23
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|lprcat
argument_list|(
literal|"\n\n\n\n\n\n\n\n\n\n\n\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|standout
argument_list|(
literal|"From:"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprcat
argument_list|(
literal|"  the LRS (Larn Revenue Service)\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|standout
argument_list|(
literal|"\nSubject:"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprcat
argument_list|(
literal|"  undeclared income\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprcat
argument_list|(
literal|"\n   We heard you survived the caverns of Larn.  Let me be the"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprcat
argument_list|(
literal|"\nfirst to congratulate you on your success.  It is quite a feat."
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprcat
argument_list|(
literal|"\nIt must also have been very profitable for you."
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprcat
argument_list|(
literal|"\n\n   The Dungeon Master has informed us that you brought"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprintf
argument_list|(
literal|"\n%d gold pieces back with you from your journey.  As the"
argument_list|,
operator|(
name|long
operator|)
name|c
index|[
name|GOLD
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprcat
argument_list|(
literal|"\ncounty of Larn is in dire need of funds, we have spared no time"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprintf
argument_list|(
literal|"\nin preparing your tax bill.  You owe %d gold pieces as"
argument_list|,
operator|(
name|long
operator|)
name|c
index|[
name|GOLD
index|]
operator|*
name|TAXRATE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprcat
argument_list|(
literal|"\nof this notice, and is due within 5 days.  Failure to pay will"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprcat
argument_list|(
literal|"\nmean penalties.  Once again, congratulations, We look forward"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprcat
argument_list|(
literal|"\nto your future successful expeditions.\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lwclose
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
literal|1
operator|)
return|;
end_return

begin_macro
unit|}  static
name|letter2
argument_list|()
end_macro

begin_block
block|{
name|sprintf
argument_list|(
name|mail600
argument_list|,
literal|"/tmp/#%dmail600"
argument_list|,
name|pid
argument_list|)
expr_stmt|;
comment|/* prepare path */
if|if
condition|(
name|lcreat
argument_list|(
name|mail600
argument_list|)
operator|<
literal|0
condition|)
block|{
name|write
argument_list|(
literal|1
argument_list|,
literal|"can't write 601 letter\n"
argument_list|,
literal|23
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|lprcat
argument_list|(
literal|"\n\n\n\n\n\n\n\n\n\n\n\n"
argument_list|)
expr_stmt|;
name|standout
argument_list|(
literal|"From:"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"  His Majesty King Wilfred of Larndom\n"
argument_list|)
expr_stmt|;
name|standout
argument_list|(
literal|"\nSubject:"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"  a noble deed\n"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"\n   I have heard of your magnificent feat, and I, King Wilfred,"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"\nforthwith declare today to be a national holiday.  Furthermore,"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"\nhence three days, Ye be invited to the castle to receive the"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"\nhonour of Knight of the realm.  Upon thy name shall it be written. . ."
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"\nBravery and courage be yours."
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"\nMay you live in happiness forevermore . . .\n"
argument_list|)
expr_stmt|;
name|lwclose
argument_list|()
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

begin_expr_stmt
specifier|static
name|letter3
argument_list|()
block|{
name|sprintf
argument_list|(
name|mail600
argument_list|,
literal|"/tmp/#%dmail600"
argument_list|,
name|pid
argument_list|)
block|;
comment|/* prepare path */
if|if
condition|(
name|lcreat
argument_list|(
name|mail600
argument_list|)
operator|<
literal|0
condition|)
block|{
name|write
argument_list|(
literal|1
argument_list|,
literal|"can't write 602 letter\n"
argument_list|,
literal|23
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|lprcat
argument_list|(
literal|"\n\n\n\n\n\n\n\n\n\n\n\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|standout
argument_list|(
literal|"From:"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprcat
argument_list|(
literal|"  Count Endelford\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|standout
argument_list|(
literal|"\nSubject:"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprcat
argument_list|(
literal|"  You Bastard!\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprcat
argument_list|(
literal|"\n   I heard (from sources) of your journey.  Congratulations!"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprcat
argument_list|(
literal|"\nYou Bastard!  With several attempts I have yet to endure the"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprcat
argument_list|(
literal|" caves,\nand you, a nobody, makes the journey!  From this time"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprcat
argument_list|(
literal|" onward, bewarned\nupon our meeting you shall pay the price!\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lwclose
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
literal|1
operator|)
return|;
end_return

begin_macro
unit|}  static
name|letter4
argument_list|()
end_macro

begin_block
block|{
name|sprintf
argument_list|(
name|mail600
argument_list|,
literal|"/tmp/#%dmail600"
argument_list|,
name|pid
argument_list|)
expr_stmt|;
comment|/* prepare path */
if|if
condition|(
name|lcreat
argument_list|(
name|mail600
argument_list|)
operator|<
literal|0
condition|)
block|{
name|write
argument_list|(
literal|1
argument_list|,
literal|"can't write 603 letter\n"
argument_list|,
literal|23
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|lprcat
argument_list|(
literal|"\n\n\n\n\n\n\n\n\n\n\n\n"
argument_list|)
expr_stmt|;
name|standout
argument_list|(
literal|"From:"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"  Mainair, Duke of Larnty\n"
argument_list|)
expr_stmt|;
name|standout
argument_list|(
literal|"\nSubject:"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"  High Praise\n"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"\n   With a certainty a hero I declare to be amongst us!  A nod of"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"\nfavour I send to thee.  Me thinks Count Endelford this day of"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"\nright breath'eth fire as of dragon of whom ye are slayer.  I"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"\nyearn to behold his anger and jealously.  Should ye choose to"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"\nunleash some of thy wealth upon those who be unfortunate, I,"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"\nDuke Mainair, Shall equal thy gift also.\n"
argument_list|)
expr_stmt|;
name|lwclose
argument_list|()
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

begin_expr_stmt
specifier|static
name|letter5
argument_list|()
block|{
name|sprintf
argument_list|(
name|mail600
argument_list|,
literal|"/tmp/#%dmail600"
argument_list|,
name|pid
argument_list|)
block|;
comment|/* prepare path */
if|if
condition|(
name|lcreat
argument_list|(
name|mail600
argument_list|)
operator|<
literal|0
condition|)
block|{
name|write
argument_list|(
literal|1
argument_list|,
literal|"can't write 604 letter\n"
argument_list|,
literal|23
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|lprcat
argument_list|(
literal|"\n\n\n\n\n\n\n\n\n\n\n\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|standout
argument_list|(
literal|"From:"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprcat
argument_list|(
literal|"  St. Mary's Children's Home\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|standout
argument_list|(
literal|"\nSubject:"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprcat
argument_list|(
literal|"  these poor children\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprcat
argument_list|(
literal|"\n   News of your great conquests has spread to all of Larndom."
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprcat
argument_list|(
literal|"\nMight I have a moment of a great man's time.  We here at St."
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprcat
argument_list|(
literal|"\nMary's Children's Home are very poor, and many children are"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprcat
argument_list|(
literal|"\nstarving.  Disease is widespread and very often fatal without"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprcat
argument_list|(
literal|"\ngood food.  Could you possibly find it in your heart to help us"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprcat
argument_list|(
literal|"\nin our plight?  Whatever you could give will help much."
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lprcat
argument_list|(
literal|"\n(your gift is tax deductible)\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lwclose
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
literal|1
operator|)
return|;
end_return

begin_macro
unit|}  static
name|letter6
argument_list|()
end_macro

begin_block
block|{
name|sprintf
argument_list|(
name|mail600
argument_list|,
literal|"/tmp/#%dmail600"
argument_list|,
name|pid
argument_list|)
expr_stmt|;
comment|/* prepare path */
if|if
condition|(
name|lcreat
argument_list|(
name|mail600
argument_list|)
operator|<
literal|0
condition|)
block|{
name|write
argument_list|(
literal|1
argument_list|,
literal|"can't write 605 letter\n"
argument_list|,
literal|23
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|lprcat
argument_list|(
literal|"\n\n\n\n\n\n\n\n\n\n\n\n"
argument_list|)
expr_stmt|;
name|standout
argument_list|(
literal|"From:"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"  The National Cancer Society of Larn\n"
argument_list|)
expr_stmt|;
name|standout
argument_list|(
literal|"\nSubject:"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"  hope\n"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"\nCongratulations on your successful expedition.  We are sure much"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"\ncourage and determination were needed on your quest.  There are"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"\nmany though, that could never hope to undertake such a journey"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"\ndue to an enfeebling disease -- cancer.  We at the National"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"\nCancer Society of Larn wish to appeal to your philanthropy in"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"\norder to save many good people -- possibly even yourself a few"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"\nyears from now.  Much work needs to be done in researching this"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"\ndreaded disease, and you can help today.  Could you please see it"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"\nin your heart to give generously?  Your continued good health"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"\ncan be your everlasting reward.\n"
argument_list|)
expr_stmt|;
name|lwclose
argument_list|()
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  *	function to mail the letters to the player if a winner  */
end_comment

begin_function_decl
specifier|static
name|int
function_decl|(
modifier|*
name|pfn
index|[]
function_decl|)
parameter_list|()
init|=
block|{
name|letter1
operator|,
function_decl|letter2
operator|,
function_decl|letter3
operator|,
function_decl|letter4
operator|,
function_decl|letter5
operator|,
function_decl|letter6
end_function_decl

begin_macro
unit|};
name|mailbill
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
name|char
name|buf
index|[
literal|128
index|]
decl_stmt|;
name|wait
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|pid
operator|=
name|getpid
argument_list|()
expr_stmt|;
if|if
condition|(
name|fork
argument_list|()
operator|==
literal|0
condition|)
block|{
name|resetscroll
argument_list|()
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|pfn
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|()
argument_list|)
condition|;
name|i
operator|++
control|)
if|if
condition|(
call|(
modifier|*
name|pfn
index|[
name|i
index|]
call|)
argument_list|()
condition|)
block|{
name|sleep
argument_list|(
literal|20
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"mail %s< %s"
argument_list|,
name|loginname
argument_list|,
name|mail600
argument_list|)
expr_stmt|;
name|system
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|unlink
argument_list|(
name|mail600
argument_list|)
expr_stmt|;
block|}
name|exit
argument_list|()
expr_stmt|;
block|}
block|}
end_block

end_unit

