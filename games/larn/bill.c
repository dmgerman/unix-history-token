begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static char sccsid[] = "@(#)bill.c	5.2 (Berkeley) 5/28/91";
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
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
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"header.h"
end_include

begin_comment
comment|/* bill.c		 Larn is copyrighted 1986 by Noah Morgan. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|mail
index|[]
init|=
block|{
literal|"From: dev-null (the LRS - Larn Revenue Service)\n"
block|,
literal|"Subject: undeclared income\n"
block|,
literal|"\n   We have heard you survived the caverns of Larn.  Let me be the"
block|,
literal|"\nfirst to congratulate you on your success.  It was quite a feat."
block|,
literal|"\nIt was also very profitable for you..."
block|,
literal|"\n\n   The Dungeon Master has informed us that you brought"
block|,
literal|"1"
block|,
literal|"\ncounty of Larn is in dire need of funds, we have spared no time"
block|,
literal|"2"
block|,
literal|"\nof this notice, and is due within 5 days.  Failure to pay will"
block|,
literal|"\nmean penalties.  Once again, congratulations, We look forward"
block|,
literal|"\nto your future successful expeditions.\n"
block|,
name|NULL
block|,
literal|"From: dev-null (His Majesty King Wilfred of Larndom)\n"
block|,
literal|"Subject: a noble deed\n"
block|,
literal|"\n   I have heard of your magnificent feat, and I, King Wilfred,"
block|,
literal|"\nforthwith declare today to be a national holiday.  Furthermore,"
block|,
literal|"\nhence three days, ye be invited to the castle to receive the"
block|,
literal|"\nhonour of Knight of the realm.  Upon thy name shall it be written..."
block|,
literal|"\n\nBravery and courage be yours."
block|,
literal|"\n\nMay you live in happiness forevermore...\n"
block|,
name|NULL
block|,
literal|"From: dev-null (Count Endelford)\n"
block|,
literal|"Subject: You Bastard!\n"
block|,
literal|"\n   I have heard (from sources) of your journey.  Congratulations!"
block|,
literal|"\nYou Bastard!  With several attempts I have yet to endure the"
block|,
literal|" caves,\nand you, a nobody, makes the journey!  From this time"
block|,
literal|" onward, bewarned\nupon our meeting you shall pay the price!\n"
block|,
name|NULL
block|,
literal|"From: dev-null (Mainair, Duke of Larnty)\n"
block|,
literal|"Subject: High Praise\n"
block|,
literal|"\n   With certainty, a hero I declare to be amongst us!  A nod of"
block|,
literal|"\nfavour I send to thee.  Me thinks Count Endelford this day of"
block|,
literal|"\nright breath'eth fire as of dragon of whom ye are slayer.  I"
block|,
literal|"\nyearn to behold his anger and jealously.  Should ye choose to"
block|,
literal|"\nunleash some of thy wealth upon those who be unfortunate, I,"
block|,
literal|"\nDuke Mainair, shall equal thy gift also.\n"
block|,
name|NULL
block|,
literal|"From: dev-null (St. Mary's Children's Home)\n"
block|,
literal|"Subject: these poor children\n"
block|,
literal|"\n   News of your great conquests has spread to all of Larndom."
block|,
literal|"\nMight I have a moment of a great adventurers's time?  We here at"
block|,
literal|"\nSt. Mary's Children's Home are very poor, and many children are"
block|,
literal|"\nstarving.  Disease is widespread and very often fatal without"
block|,
literal|"\ngood food.  Could you possibly find it in your heart to help us"
block|,
literal|"\nin our plight?  Whatever you could give will help much."
block|,
literal|"\n(your gift is tax deductible)\n"
block|,
name|NULL
block|,
literal|"From: dev-null (The National Cancer Society of Larn)\n"
block|,
literal|"Subject: hope\n"
block|,
literal|"\nCongratulations on your successful expedition.  We are sure much"
block|,
literal|"\ncourage and determination were needed on your quest.  There are"
block|,
literal|"\nmany though, that could never hope to undertake such a journey"
block|,
literal|"\ndue to an enfeebling disease -- cancer.  We at the National"
block|,
literal|"\nCancer Society of Larn wish to appeal to your philanthropy in"
block|,
literal|"\norder to save many good people -- possibly even yourself a few"
block|,
literal|"\nyears from now.  Much work needs to be done in researching this"
block|,
literal|"\ndreaded disease, and you can help today.  Could you please see it"
block|,
literal|"\nin your heart to give generously?  Your continued good health"
block|,
literal|"\ncan be your everlasting reward.\n"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	function to mail the letters to the player if a winner  */
end_comment

begin_function
name|void
name|mailbill
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
name|char
name|fname
index|[
literal|32
index|]
decl_stmt|;
name|char
name|buf
index|[
literal|128
index|]
decl_stmt|;
name|char
modifier|*
modifier|*
name|cp
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|wait
argument_list|(
literal|0
argument_list|)
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
name|cp
operator|=
name|mail
expr_stmt|;
name|sprintf
argument_list|(
name|fname
argument_list|,
literal|"/tmp/#%dlarnmail"
argument_list|,
name|getpid
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|6
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|(
name|fd
operator|=
name|open
argument_list|(
name|fname
argument_list|,
name|O_WRONLY
operator||
name|O_TRUNC
operator||
name|O_CREAT
argument_list|)
operator|,
literal|0660
operator|)
operator|==
operator|-
literal|1
condition|)
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
while|while
condition|(
operator|*
name|cp
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
operator|*
name|cp
index|[
literal|0
index|]
operator|==
literal|'1'
condition|)
block|{
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"\n%ld gold pieces back with you from your journey.  As the"
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
name|write
argument_list|(
name|fd
argument_list|,
name|buf
argument_list|,
name|strlen
argument_list|(
name|buf
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|*
name|cp
index|[
literal|0
index|]
operator|==
literal|'2'
condition|)
block|{
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"\nin preparing your tax bill.  You owe %ld gold pieces as"
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
name|write
argument_list|(
name|fd
argument_list|,
name|buf
argument_list|,
name|strlen
argument_list|(
name|buf
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
name|write
argument_list|(
name|fd
argument_list|,
operator|*
name|cp
argument_list|,
name|strlen
argument_list|(
operator|*
name|cp
argument_list|)
argument_list|)
expr_stmt|;
name|cp
operator|++
expr_stmt|;
block|}
name|cp
operator|++
expr_stmt|;
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"/usr/sbin/sendmail %s< %s> /dev/null"
argument_list|,
name|loginname
argument_list|,
name|fname
argument_list|)
expr_stmt|;
name|system
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|unlink
argument_list|(
name|fname
argument_list|)
expr_stmt|;
block|}
block|}
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

