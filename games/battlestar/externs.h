begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)externs.h	8.1 (Berkeley) 5/31/93  *  *	$FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_define
define|#
directive|define
name|BITS
value|(8)
end_define

begin_define
define|#
directive|define
name|OUTSIDE
value|(position> 68&& position< 246&& position != 218)
end_define

begin_define
define|#
directive|define
name|rnd
parameter_list|(
name|x
parameter_list|)
value|(random() % (x))
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (b) : (a))
end_define

begin_define
define|#
directive|define
name|testbit
parameter_list|(
name|array
parameter_list|,
name|index
parameter_list|)
value|(array[index/BITS]& (1<< (index % BITS)))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|setbit
end_ifndef

begin_define
define|#
directive|define
name|setbit
parameter_list|(
name|array
parameter_list|,
name|index
parameter_list|)
value|(array[index/BITS] |= (1<< (index % BITS)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|clearbit
parameter_list|(
name|array
parameter_list|,
name|index
parameter_list|)
value|(array[index/BITS]&= ~(1<< (index % BITS)))
end_define

begin_comment
comment|/* well known rooms */
end_comment

begin_define
define|#
directive|define
name|FINAL
value|275
end_define

begin_define
define|#
directive|define
name|GARDEN
value|197
end_define

begin_define
define|#
directive|define
name|POOLS
value|126
end_define

begin_define
define|#
directive|define
name|DOCK
value|93
end_define

begin_comment
comment|/* word types */
end_comment

begin_define
define|#
directive|define
name|VERB
value|0
end_define

begin_define
define|#
directive|define
name|OBJECT
value|1
end_define

begin_define
define|#
directive|define
name|NOUNS
value|2
end_define

begin_define
define|#
directive|define
name|PREPS
value|3
end_define

begin_define
define|#
directive|define
name|ADJS
value|4
end_define

begin_define
define|#
directive|define
name|CONJ
value|5
end_define

begin_comment
comment|/* words numbers */
end_comment

begin_define
define|#
directive|define
name|KNIFE
value|0
end_define

begin_define
define|#
directive|define
name|SWORD
value|1
end_define

begin_define
define|#
directive|define
name|LAND
value|2
end_define

begin_define
define|#
directive|define
name|WOODSMAN
value|3
end_define

begin_define
define|#
directive|define
name|TWO_HANDED
value|4
end_define

begin_define
define|#
directive|define
name|CLEAVER
value|5
end_define

begin_define
define|#
directive|define
name|BROAD
value|6
end_define

begin_define
define|#
directive|define
name|MAIL
value|7
end_define

begin_define
define|#
directive|define
name|HELM
value|8
end_define

begin_define
define|#
directive|define
name|SHIELD
value|9
end_define

begin_define
define|#
directive|define
name|MAID
value|10
end_define

begin_define
define|#
directive|define
name|BODY
value|10
end_define

begin_define
define|#
directive|define
name|VIPER
value|11
end_define

begin_define
define|#
directive|define
name|LAMPON
value|12
end_define

begin_define
define|#
directive|define
name|SHOES
value|13
end_define

begin_define
define|#
directive|define
name|CYLON
value|14
end_define

begin_define
define|#
directive|define
name|PAJAMAS
value|15
end_define

begin_define
define|#
directive|define
name|ROBE
value|16
end_define

begin_define
define|#
directive|define
name|AMULET
value|17
end_define

begin_define
define|#
directive|define
name|MEDALION
value|18
end_define

begin_define
define|#
directive|define
name|TALISMAN
value|19
end_define

begin_define
define|#
directive|define
name|DEADWOOD
value|20
end_define

begin_define
define|#
directive|define
name|MALLET
value|21
end_define

begin_define
define|#
directive|define
name|LASER
value|22
end_define

begin_define
define|#
directive|define
name|BATHGOD
value|23
end_define

begin_define
define|#
directive|define
name|NORMGOD
value|24
end_define

begin_define
define|#
directive|define
name|GRENADE
value|25
end_define

begin_define
define|#
directive|define
name|CHAIN
value|26
end_define

begin_define
define|#
directive|define
name|ROPE
value|27
end_define

begin_define
define|#
directive|define
name|LEVIS
value|28
end_define

begin_define
define|#
directive|define
name|MACE
value|29
end_define

begin_define
define|#
directive|define
name|SHOVEL
value|30
end_define

begin_define
define|#
directive|define
name|HALBERD
value|31
end_define

begin_define
define|#
directive|define
name|COMPASS
value|32
end_define

begin_define
define|#
directive|define
name|CRASH
value|33
end_define

begin_define
define|#
directive|define
name|ELF
value|34
end_define

begin_define
define|#
directive|define
name|FOOT
value|35
end_define

begin_define
define|#
directive|define
name|COINS
value|36
end_define

begin_define
define|#
directive|define
name|MATCHES
value|37
end_define

begin_define
define|#
directive|define
name|MAN
value|38
end_define

begin_define
define|#
directive|define
name|PAPAYAS
value|39
end_define

begin_define
define|#
directive|define
name|PINEAPPLE
value|40
end_define

begin_define
define|#
directive|define
name|KIWI
value|41
end_define

begin_define
define|#
directive|define
name|COCONUTS
value|42
end_define

begin_define
define|#
directive|define
name|MANGO
value|43
end_define

begin_define
define|#
directive|define
name|RING
value|44
end_define

begin_define
define|#
directive|define
name|POTION
value|45
end_define

begin_define
define|#
directive|define
name|BRACELET
value|46
end_define

begin_define
define|#
directive|define
name|GIRL
value|47
end_define

begin_define
define|#
directive|define
name|GIRLTALK
value|48
end_define

begin_define
define|#
directive|define
name|DARK
value|49
end_define

begin_define
define|#
directive|define
name|TIMER
value|50
end_define

begin_define
define|#
directive|define
name|CHAR
value|53
end_define

begin_define
define|#
directive|define
name|BOMB
value|54
end_define

begin_define
define|#
directive|define
name|DEADGOD
value|55
end_define

begin_define
define|#
directive|define
name|DEADTIME
value|56
end_define

begin_define
define|#
directive|define
name|DEADNATIVE
value|57
end_define

begin_define
define|#
directive|define
name|NATIVE
value|58
end_define

begin_define
define|#
directive|define
name|HORSE
value|59
end_define

begin_define
define|#
directive|define
name|CAR
value|60
end_define

begin_define
define|#
directive|define
name|POT
value|61
end_define

begin_define
define|#
directive|define
name|BAR
value|62
end_define

begin_define
define|#
directive|define
name|BLOCK
value|63
end_define

begin_define
define|#
directive|define
name|NUMOFOBJECTS
value|64
end_define

begin_comment
comment|/* non-objects below */
end_comment

begin_define
define|#
directive|define
name|UP
value|1000
end_define

begin_define
define|#
directive|define
name|DOWN
value|1001
end_define

begin_define
define|#
directive|define
name|AHEAD
value|1002
end_define

begin_define
define|#
directive|define
name|BACK
value|1003
end_define

begin_define
define|#
directive|define
name|RIGHT
value|1004
end_define

begin_define
define|#
directive|define
name|LEFT
value|1005
end_define

begin_define
define|#
directive|define
name|TAKE
value|1006
end_define

begin_define
define|#
directive|define
name|USE
value|1007
end_define

begin_define
define|#
directive|define
name|LOOK
value|1008
end_define

begin_define
define|#
directive|define
name|QUIT
value|1009
end_define

begin_define
define|#
directive|define
name|NORTH
value|1010
end_define

begin_define
define|#
directive|define
name|SOUTH
value|1011
end_define

begin_define
define|#
directive|define
name|EAST
value|1012
end_define

begin_define
define|#
directive|define
name|WEST
value|1013
end_define

begin_define
define|#
directive|define
name|SU
value|1014
end_define

begin_define
define|#
directive|define
name|DROP
value|1015
end_define

begin_define
define|#
directive|define
name|TAKEOFF
value|1016
end_define

begin_define
define|#
directive|define
name|DRAW
value|1017
end_define

begin_define
define|#
directive|define
name|PUTON
value|1018
end_define

begin_define
define|#
directive|define
name|WEARIT
value|1019
end_define

begin_define
define|#
directive|define
name|PUT
value|1020
end_define

begin_define
define|#
directive|define
name|INVEN
value|1021
end_define

begin_define
define|#
directive|define
name|EVERYTHING
value|1022
end_define

begin_define
define|#
directive|define
name|AND
value|1023
end_define

begin_define
define|#
directive|define
name|KILL
value|1024
end_define

begin_define
define|#
directive|define
name|RAVAGE
value|1025
end_define

begin_define
define|#
directive|define
name|UNDRESS
value|1026
end_define

begin_define
define|#
directive|define
name|THROW
value|1027
end_define

begin_define
define|#
directive|define
name|LAUNCH
value|1028
end_define

begin_define
define|#
directive|define
name|LANDIT
value|1029
end_define

begin_define
define|#
directive|define
name|LIGHT
value|1030
end_define

begin_define
define|#
directive|define
name|FOLLOW
value|1031
end_define

begin_define
define|#
directive|define
name|KISS
value|1032
end_define

begin_define
define|#
directive|define
name|LOVE
value|1033
end_define

begin_define
define|#
directive|define
name|GIVE
value|1034
end_define

begin_define
define|#
directive|define
name|SMITE
value|1035
end_define

begin_define
define|#
directive|define
name|SHOOT
value|1036
end_define

begin_define
define|#
directive|define
name|ON
value|1037
end_define

begin_define
define|#
directive|define
name|OFF
value|1038
end_define

begin_define
define|#
directive|define
name|TIME
value|1039
end_define

begin_define
define|#
directive|define
name|SLEEP
value|1040
end_define

begin_define
define|#
directive|define
name|DIG
value|1041
end_define

begin_define
define|#
directive|define
name|EAT
value|1042
end_define

begin_define
define|#
directive|define
name|SWIM
value|1043
end_define

begin_define
define|#
directive|define
name|DRINK
value|1044
end_define

begin_define
define|#
directive|define
name|DOOR
value|1045
end_define

begin_define
define|#
directive|define
name|SAVE
value|1046
end_define

begin_define
define|#
directive|define
name|RIDE
value|1047
end_define

begin_define
define|#
directive|define
name|DRIVE
value|1048
end_define

begin_define
define|#
directive|define
name|SCORE
value|1049
end_define

begin_define
define|#
directive|define
name|BURY
value|1050
end_define

begin_define
define|#
directive|define
name|JUMP
value|1051
end_define

begin_define
define|#
directive|define
name|KICK
value|1052
end_define

begin_comment
comment|/* injuries */
end_comment

begin_define
define|#
directive|define
name|ARM
value|6
end_define

begin_comment
comment|/* broken arm */
end_comment

begin_define
define|#
directive|define
name|RIBS
value|7
end_define

begin_comment
comment|/* broken ribs */
end_comment

begin_define
define|#
directive|define
name|SPINE
value|9
end_define

begin_comment
comment|/* broken back */
end_comment

begin_define
define|#
directive|define
name|SKULL
value|11
end_define

begin_comment
comment|/* fractured skull */
end_comment

begin_define
define|#
directive|define
name|INCISE
value|10
end_define

begin_comment
comment|/* deep incisions */
end_comment

begin_define
define|#
directive|define
name|NECK
value|12
end_define

begin_comment
comment|/* broken NECK */
end_comment

begin_define
define|#
directive|define
name|NUMOFINJURIES
value|13
end_define

begin_comment
comment|/* notes */
end_comment

begin_define
define|#
directive|define
name|CANTLAUNCH
value|0
end_define

begin_define
define|#
directive|define
name|LAUNCHED
value|1
end_define

begin_define
define|#
directive|define
name|CANTSEE
value|2
end_define

begin_define
define|#
directive|define
name|CANTMOVE
value|3
end_define

begin_define
define|#
directive|define
name|JINXED
value|4
end_define

begin_define
define|#
directive|define
name|DUG
value|5
end_define

begin_define
define|#
directive|define
name|NUMOFNOTES
value|6
end_define

begin_comment
comment|/* fundamental constants */
end_comment

begin_define
define|#
directive|define
name|NUMOFROOMS
value|275
end_define

begin_define
define|#
directive|define
name|NUMOFWORDS
value|((NUMOFOBJECTS + BITS - 1) / BITS)
end_define

begin_define
define|#
directive|define
name|LINELENGTH
value|81
end_define

begin_define
define|#
directive|define
name|TODAY
value|0
end_define

begin_define
define|#
directive|define
name|TONIGHT
value|1
end_define

begin_define
define|#
directive|define
name|CYCLE
value|100
end_define

begin_comment
comment|/* initial variable values */
end_comment

begin_define
define|#
directive|define
name|TANKFULL
value|250
end_define

begin_define
define|#
directive|define
name|TORPEDOES
value|10
end_define

begin_define
define|#
directive|define
name|MAXWEIGHT
value|60
end_define

begin_define
define|#
directive|define
name|MAXCUMBER
value|10
end_define

begin_struct
struct|struct
name|room
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|link
index|[
literal|8
index|]
decl_stmt|;
define|#
directive|define
name|north
value|link[0]
define|#
directive|define
name|south
value|link[1]
define|#
directive|define
name|east
value|link[2]
define|#
directive|define
name|west
value|link[3]
define|#
directive|define
name|up
value|link[4]
define|#
directive|define
name|access
value|link[5]
define|#
directive|define
name|down
value|link[6]
define|#
directive|define
name|flyhere
value|link[7]
specifier|const
name|char
modifier|*
name|desc
decl_stmt|;
name|unsigned
name|int
name|objects
index|[
name|NUMOFWORDS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|room
name|dayfile
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|room
name|nightfile
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|room
modifier|*
name|location
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* object characteristics */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|objdes
index|[
name|NUMOFOBJECTS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|objsht
index|[
name|NUMOFOBJECTS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|ouch
index|[
name|NUMOFINJURIES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|objwt
index|[
name|NUMOFOBJECTS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|objcumber
index|[
name|NUMOFOBJECTS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current input line */
end_comment

begin_define
define|#
directive|define
name|NWORD
value|20
end_define

begin_comment
comment|/* words per line */
end_comment

begin_decl_stmt
name|char
name|words
index|[
name|NWORD
index|]
index|[
literal|15
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wordvalue
index|[
name|NWORD
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wordtype
index|[
name|NWORD
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wordcount
decl_stmt|,
name|wordnumber
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|battlestar_move
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bury
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|card
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chime
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|crash
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cypher
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|die
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dig
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|draw
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drink
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drive
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drop
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eat
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fight
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|follow
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getcom
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getword
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|give
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|initialize
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|jump
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kiss
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|land
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|launch
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|light
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|live
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|love
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|murder
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|news
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|newway
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|open_score_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|parse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printobjs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|put
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|puton
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ravage
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|rate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|restore
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ride
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|save
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|shoot
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|take
parameter_list|(
name|unsigned
name|int
name|from
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|takeoff
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|throw
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|truedirec
parameter_list|(
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ucard
parameter_list|(
specifier|const
name|unsigned
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|use
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|visual
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wearit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|whichway
parameter_list|(
name|struct
name|room
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wordinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|writedes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|zzz
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* state of the game */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gclock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gtime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|position
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|direction
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|left
decl_stmt|,
name|right
decl_stmt|,
name|ahead
decl_stmt|,
name|back
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fuel
decl_stmt|,
name|torps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|carrying
decl_stmt|,
name|encumber
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rythmn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|followfight
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ate
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|snooze
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|meetgirl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|followgod
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|godready
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bs_win
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wintime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wiz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tempwiz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|matchlight
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|matchcount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|loved
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pleasure
decl_stmt|,
name|power
decl_stmt|,
name|ego
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|WEIGHT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|CUMBER
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|notes
index|[
name|NUMOFNOTES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
name|inven
index|[
name|NUMOFWORDS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|wear
index|[
name|NUMOFWORDS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|beenthere
index|[
name|NUMOFROOMS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|injuries
index|[
name|NUMOFINJURIES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|uname
index|[
name|MAXLOGNAME
index|]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|wlist
block|{
specifier|const
name|char
modifier|*
name|string
decl_stmt|;
name|int
name|value
decl_stmt|,
name|article
decl_stmt|;
name|struct
name|wlist
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HASHSIZE
value|256
end_define

begin_define
define|#
directive|define
name|HASHMUL
value|81
end_define

begin_define
define|#
directive|define
name|HASHMASK
value|(HASHSIZE - 1)
end_define

begin_decl_stmt
name|struct
name|wlist
modifier|*
name|hashtab
index|[
name|HASHSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|wlist
name|wlist
index|[]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|objs
block|{
name|short
name|room
decl_stmt|;
name|short
name|obj
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|objs
name|dayobjs
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|objs
name|nightobjs
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|gid_t
name|egid
decl_stmt|;
end_decl_stmt

end_unit

