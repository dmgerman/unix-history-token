begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
unit|static char sccsid[] = "@(#)globals.c	8.1 (Berkeley) 5/31/93";
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
file|"externs.h"
end_include

begin_decl_stmt
name|int
name|WEIGHT
init|=
name|MAXWEIGHT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|CUMBER
init|=
name|MAXCUMBER
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|objdes
index|[
name|NUMOFOBJECTS
index|]
init|=
block|{
literal|"There is a knife here"
block|,
literal|"There is an exquisitely crafted sword and scabbard here."
block|,
literal|0
block|,
comment|/* can land from here */
literal|"There is a fierce woodsman here brandishing a heavy mallet."
block|,
literal|"There is an unwieldy two-handed sword here."
block|,
literal|"There is a bloody meat cleaver here."
block|,
literal|"A rusty broadsword is lying here."
block|,
literal|"There is an ancient coat of finely woven mail here."
block|,
literal|"There is a old dented helmet with an ostrich plume here."
block|,
literal|"There is a shield of some native tribe here."
block|,
literal|"The maid's body is lying here. She was murdered!"
block|,
literal|"There is a Viper ready for launch here."
block|,
literal|"A kerosene lantern is burning luridly here."
block|,
literal|"An old pair of shoes has been discarded here."
block|,
literal|0
block|,
comment|/* cylon */
literal|"There is a pair of pajamas here."
block|,
literal|"A kingly robe of royal purple and spun gold is draped here."
block|,
literal|"There is a strange golden amulet on the floor here."
block|,
literal|"A medallion of solid gold shimmers on the ground nearby."
block|,
literal|"A talisman of gold is lying here."
block|,
literal|"A dead woodsman has fallen here. He was savagely murdered."
block|,
literal|"A heavy wooden mallet lies nearby."
block|,
literal|"There is a laser pistol here."
block|,
literal|"A flower-like young goddess is bathing in the hot mineral pools. She is \nwatching you, but continues to steep and sing softly."
block|,
literal|"The goddess is reclining on a bed of ferns and studying you intently."
block|,
literal|"There is a grenade here"
block|,
literal|"There is a length of heavy chain here."
block|,
literal|"There is a stout rope here."
block|,
literal|"There is a pair of Levi's here."
block|,
literal|"A bloody mace is lying on the ground here."
block|,
literal|"There is a shovel here."
block|,
literal|"A long, sharp halberd is propped up here."
block|,
literal|"There is a compass here"
block|,
literal|"Wreckage and smoldering debris from a crash litter the ground here."
block|,
literal|"A woodland Elf armed with a shield and deadly halberd lunges toward you!"
block|,
literal|"I think I hear footsteps behind us."
block|,
literal|"There are a few coins here."
block|,
literal|"There are some matches here."
block|,
literal|"An unctuous man in a white suit and a dwarf are standing here."
block|,
literal|"There are some ripe papayas here."
block|,
literal|"There is a ripe pineapple here."
block|,
literal|"There are some kiwi fruit here."
block|,
literal|"There are some coconuts here."
block|,
literal|"There is a ripe mango here."
block|,
literal|"There is a sparkling diamond ring here."
block|,
literal|"There is a colorful pink potion in a small crystal vial here."
block|,
literal|"A gold bracelet is on the ground here."
block|,
literal|"A swarthy woman with stern features pulls you aside from the crowd,\n'I must talk to you -- but not here.  Meet me at midnight in the gardens.'"
block|,
literal|"The swarthy woman has been awaiting you anxiously. 'I must warn you that the\nIsland has anticipated your Quest.  You will not be welcomed. The Darkness is\nstrong where you must search.  Seek not the shadows save only at night, for\nthen are they the weakest.  In the mountains far from here a canyon winds\nwith ferns and streams and forgotten vines.  There you must go. Take this\nrope.'"
block|,
literal|"Out from the shadows a figure leaps!  His black cape swirls around, and he\nholds a laser sword at your chest.  'So, you have come to fulfill the Quest.\nHa! Your weapons are no match for me!'"
block|,
literal|"An old timer with one eye missing and no money for a drink sits at the bar."
block|,
literal|"You are flying through an asteroid field!"
block|,
literal|"A planet is nearby."
block|,
literal|"The ground is charred here."
block|,
literal|"There is a thermonuclear warhead here."
block|,
literal|"The fragile, beautiful young goddess lies here.  You murdered her horribly."
block|,
literal|"The old timer is lying here.  He is dead."
block|,
literal|"The native girl's body is lying here."
block|,
literal|"A native girl is sitting here."
block|,
literal|"A gorgeous white stallion is standing here."
block|,
literal|"The keys are in the ignition."
block|,
literal|"A pot of pearls and jewels is sitting here."
block|,
literal|"A bar of solid gold is here."
block|,
literal|"There is a 10 kilogram diamond block here."
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|objsht
index|[
name|NUMOFOBJECTS
index|]
init|=
block|{
literal|"knife"
block|,
literal|"fine sword"
block|,
literal|0
block|,
literal|"Woodsman"
block|,
literal|"two-handed sword"
block|,
literal|"meat cleaver"
block|,
literal|"broadsword"
block|,
literal|"coat of mail"
block|,
literal|"plumed helmet"
block|,
literal|"shield"
block|,
literal|"maid's body"
block|,
literal|"viper"
block|,
literal|"lantern"
block|,
literal|"shoes"
block|,
literal|0
block|,
literal|"pajamas"
block|,
literal|"robe"
block|,
literal|"amulet"
block|,
literal|"medallion"
block|,
literal|"talisman"
block|,
literal|"woodsman's body"
block|,
literal|"wooden mallet"
block|,
literal|"laser"
block|,
literal|0
block|,
literal|0
block|,
literal|"grenade"
block|,
literal|"chain"
block|,
literal|"rope"
block|,
literal|"levis"
block|,
literal|"mace"
block|,
literal|"shovel"
block|,
literal|"halberd"
block|,
literal|"compass"
block|,
literal|0
block|,
literal|"Elf"
block|,
literal|0
block|,
literal|"coins"
block|,
literal|"match book"
block|,
literal|0
block|,
literal|"papayas"
block|,
literal|"pineapple"
block|,
literal|"kiwi"
block|,
literal|"coconuts"
block|,
literal|"mango"
block|,
literal|"ring"
block|,
literal|"potion"
block|,
literal|"bracelet"
block|,
literal|0
block|,
literal|0
block|,
literal|"Dark Lord"
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|"warhead"
block|,
literal|"goddess's body"
block|,
literal|"old timer's body"
block|,
literal|"girl's body"
block|,
literal|0
block|,
literal|"stallion"
block|,
literal|"car"
block|,
literal|"pot of jewels"
block|,
literal|"bar of gold"
block|,
literal|"diamond block"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|ouch
index|[
name|NUMOFINJURIES
index|]
init|=
block|{
literal|"some minor abrasions"
block|,
literal|"some minor lacerations"
block|,
literal|"a minor puncture wound"
block|,
literal|"a minor amputation"
block|,
literal|"a sprained wrist"
block|,
literal|"a fractured ankle and shattered kneecap"
block|,
literal|"a broken arm and dislocated shoulder"
block|,
literal|"a few broken ribs"
block|,
literal|"a broken leg and torn ligaments"
block|,
literal|"a broken back and ruptured spleen"
block|,
literal|"some deep incisions and a loss of blood"
block|,
literal|"a fractured skull and mashed face"
block|,
literal|"a broken neck"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|objwt
index|[
name|NUMOFOBJECTS
index|]
init|=
block|{
literal|1
block|,
literal|5
block|,
literal|0
block|,
literal|10
block|,
literal|15
block|,
literal|2
block|,
literal|10
block|,
literal|10
block|,
literal|3
block|,
literal|5
block|,
literal|50
block|,
literal|2500
block|,
literal|2
block|,
literal|1
block|,
literal|100
block|,
literal|1
block|,
literal|2
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|60
block|,
literal|10
block|,
literal|5
block|,
literal|0
block|,
literal|50
block|,
literal|5
block|,
literal|15
block|,
literal|5
block|,
literal|1
block|,
literal|20
block|,
literal|10
block|,
literal|10
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|2
block|,
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|100
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|55
block|,
literal|47
block|,
literal|50
block|,
literal|45
block|,
literal|45
block|,
literal|100
block|,
literal|2000
block|,
literal|30
block|,
literal|20
block|,
literal|10
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|objcumber
index|[
name|NUMOFOBJECTS
index|]
init|=
block|{
literal|1
block|,
literal|5
block|,
literal|0
block|,
literal|150
block|,
literal|10
block|,
literal|1
block|,
literal|5
block|,
literal|2
block|,
literal|2
block|,
literal|1
block|,
literal|5
block|,
literal|10
block|,
literal|1
block|,
literal|1
block|,
literal|10
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|7
block|,
literal|5
block|,
literal|4
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|5
block|,
literal|4
block|,
literal|4
block|,
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|3
block|,
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|10
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|7
block|,
literal|8
block|,
literal|10
block|,
literal|8
block|,
literal|8
block|,
literal|10
block|,
literal|10
block|,
literal|3
block|,
literal|1
block|,
literal|2
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bs_win
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|matchcount
init|=
literal|20
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|followgod
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|followfight
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

end_unit

