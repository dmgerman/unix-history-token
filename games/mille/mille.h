begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mille.h	8.1 (Berkeley) 5/31/93  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
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

begin_comment
comment|/*  * @(#)mille.h	1.1 (Berkeley) 4/1/82  */
end_comment

begin_comment
comment|/*  * Miscellaneous constants  */
end_comment

begin_define
define|#
directive|define
name|unsgn
value|unsigned
end_define

begin_define
define|#
directive|define
name|CARD
value|short
end_define

begin_define
define|#
directive|define
name|HAND_SZ
value|7
end_define

begin_comment
comment|/* number of cards in a hand	*/
end_comment

begin_define
define|#
directive|define
name|DECK_SZ
value|101
end_define

begin_comment
comment|/* number of cards in decks	*/
end_comment

begin_define
define|#
directive|define
name|NUM_SAFE
value|4
end_define

begin_comment
comment|/* number of saftey cards	*/
end_comment

begin_define
define|#
directive|define
name|NUM_MILES
value|5
end_define

begin_comment
comment|/* number of milestones types	*/
end_comment

begin_define
define|#
directive|define
name|NUM_CARDS
value|20
end_define

begin_comment
comment|/* number of types of cards	*/
end_comment

begin_define
define|#
directive|define
name|BOARD_Y
value|17
end_define

begin_comment
comment|/* size of board screen		*/
end_comment

begin_define
define|#
directive|define
name|BOARD_X
value|40
end_define

begin_define
define|#
directive|define
name|MILES_Y
value|7
end_define

begin_comment
comment|/* size of mileage screen	*/
end_comment

begin_define
define|#
directive|define
name|MILES_X
value|80
end_define

begin_define
define|#
directive|define
name|SCORE_Y
value|17
end_define

begin_comment
comment|/* size of score screen		*/
end_comment

begin_define
define|#
directive|define
name|SCORE_X
value|40
end_define

begin_define
define|#
directive|define
name|MOVE_Y
value|10
end_define

begin_comment
comment|/* Where to print move prompt	*/
end_comment

begin_define
define|#
directive|define
name|MOVE_X
value|20
end_define

begin_define
define|#
directive|define
name|ERR_Y
value|15
end_define

begin_comment
comment|/* Where to print errors	*/
end_comment

begin_define
define|#
directive|define
name|ERR_X
value|5
end_define

begin_define
define|#
directive|define
name|EXT_Y
value|4
end_define

begin_comment
comment|/* Where to put Extension	*/
end_comment

begin_define
define|#
directive|define
name|EXT_X
value|9
end_define

begin_define
define|#
directive|define
name|PLAYER
value|0
end_define

begin_define
define|#
directive|define
name|COMP
value|1
end_define

begin_define
define|#
directive|define
name|W_SMALL
value|0
end_define

begin_comment
comment|/* Small (initial) window	*/
end_comment

begin_define
define|#
directive|define
name|W_FULL
value|1
end_define

begin_comment
comment|/* Full (final) window		*/
end_comment

begin_comment
comment|/*  * Move types  */
end_comment

begin_define
define|#
directive|define
name|M_DISCARD
value|0
end_define

begin_define
define|#
directive|define
name|M_DRAW
value|1
end_define

begin_define
define|#
directive|define
name|M_PLAY
value|2
end_define

begin_define
define|#
directive|define
name|M_ORDER
value|3
end_define

begin_comment
comment|/*  * Scores  */
end_comment

begin_define
define|#
directive|define
name|SC_SAFETY
value|100
end_define

begin_define
define|#
directive|define
name|SC_ALL_SAFE
value|300
end_define

begin_define
define|#
directive|define
name|SC_COUP
value|300
end_define

begin_define
define|#
directive|define
name|SC_TRIP
value|400
end_define

begin_define
define|#
directive|define
name|SC_SAFE
value|300
end_define

begin_define
define|#
directive|define
name|SC_DELAY
value|300
end_define

begin_define
define|#
directive|define
name|SC_EXTENSION
value|200
end_define

begin_define
define|#
directive|define
name|SC_SHUT_OUT
value|500
end_define

begin_comment
comment|/*  * safety descriptions  */
end_comment

begin_define
define|#
directive|define
name|S_UNKNOWN
value|0
end_define

begin_comment
comment|/* location of safety unknown	*/
end_comment

begin_define
define|#
directive|define
name|S_IN_HAND
value|1
end_define

begin_comment
comment|/* safety in player's hand	*/
end_comment

begin_define
define|#
directive|define
name|S_PLAYED
value|2
end_define

begin_comment
comment|/* safety has been played	*/
end_comment

begin_define
define|#
directive|define
name|S_GAS_SAFE
value|0
end_define

begin_comment
comment|/* Gas safety card index	*/
end_comment

begin_define
define|#
directive|define
name|S_SPARE_SAFE
value|1
end_define

begin_comment
comment|/* Tire safety card index	*/
end_comment

begin_define
define|#
directive|define
name|S_DRIVE_SAFE
value|2
end_define

begin_comment
comment|/* Driveing safety card index	*/
end_comment

begin_define
define|#
directive|define
name|S_RIGHT_WAY
value|3
end_define

begin_comment
comment|/* Right-of-Way card index	*/
end_comment

begin_define
define|#
directive|define
name|S_CONV
value|15
end_define

begin_comment
comment|/* conversion from C_ to S_	*/
end_comment

begin_comment
comment|/*  * card numbers  */
end_comment

begin_define
define|#
directive|define
name|C_INIT
value|-1
end_define

begin_define
define|#
directive|define
name|C_25
value|0
end_define

begin_define
define|#
directive|define
name|C_50
value|1
end_define

begin_define
define|#
directive|define
name|C_75
value|2
end_define

begin_define
define|#
directive|define
name|C_100
value|3
end_define

begin_define
define|#
directive|define
name|C_200
value|4
end_define

begin_define
define|#
directive|define
name|C_EMPTY
value|5
end_define

begin_define
define|#
directive|define
name|C_FLAT
value|6
end_define

begin_define
define|#
directive|define
name|C_CRASH
value|7
end_define

begin_define
define|#
directive|define
name|C_STOP
value|8
end_define

begin_define
define|#
directive|define
name|C_LIMIT
value|9
end_define

begin_define
define|#
directive|define
name|C_GAS
value|10
end_define

begin_define
define|#
directive|define
name|C_SPARE
value|11
end_define

begin_define
define|#
directive|define
name|C_REPAIRS
value|12
end_define

begin_define
define|#
directive|define
name|C_GO
value|13
end_define

begin_define
define|#
directive|define
name|C_END_LIMIT
value|14
end_define

begin_define
define|#
directive|define
name|C_GAS_SAFE
value|15
end_define

begin_define
define|#
directive|define
name|C_SPARE_SAFE
value|16
end_define

begin_define
define|#
directive|define
name|C_DRIVE_SAFE
value|17
end_define

begin_define
define|#
directive|define
name|C_RIGHT_WAY
value|18
end_define

begin_comment
comment|/*  * prompt types  */
end_comment

begin_define
define|#
directive|define
name|MOVEPROMPT
value|0
end_define

begin_define
define|#
directive|define
name|REALLYPROMPT
value|1
end_define

begin_define
define|#
directive|define
name|ANOTHERHANDPROMPT
value|2
end_define

begin_define
define|#
directive|define
name|ANOTHERGAMEPROMPT
value|3
end_define

begin_define
define|#
directive|define
name|SAVEGAMEPROMPT
value|4
end_define

begin_define
define|#
directive|define
name|SAMEFILEPROMPT
value|5
end_define

begin_define
define|#
directive|define
name|FILEPROMPT
value|6
end_define

begin_define
define|#
directive|define
name|EXTENSIONPROMPT
value|7
end_define

begin_define
define|#
directive|define
name|OVERWRITEFILEPROMPT
value|8
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_define
define|#
directive|define
name|srandom
parameter_list|(
name|x
parameter_list|)
value|srand(x)
end_define

begin_define
define|#
directive|define
name|random
parameter_list|()
value|rand()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYSV
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|attron
end_ifndef

begin_define
define|#
directive|define
name|erasechar
parameter_list|()
value|_tty.c_cc[VERASE]
end_define

begin_define
define|#
directive|define
name|killchar
parameter_list|()
value|_tty.c_cc[VKILL]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|erasechar
end_ifndef

begin_define
define|#
directive|define
name|erasechar
parameter_list|()
value|_tty.sg_erase
end_define

begin_define
define|#
directive|define
name|killchar
parameter_list|()
value|_tty.sg_kill
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
endif|SYSV
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
name|bool
name|coups
index|[
name|NUM_SAFE
index|]
decl_stmt|;
name|bool
name|can_go
decl_stmt|;
name|bool
name|new_battle
decl_stmt|;
name|bool
name|new_speed
decl_stmt|;
name|short
name|safety
index|[
name|NUM_SAFE
index|]
decl_stmt|;
name|short
name|sh_safety
index|[
name|NUM_SAFE
index|]
decl_stmt|;
name|short
name|nummiles
index|[
name|NUM_MILES
index|]
decl_stmt|;
name|short
name|sh_nummiles
index|[
name|NUM_MILES
index|]
decl_stmt|;
name|CARD
name|hand
index|[
name|HAND_SZ
index|]
decl_stmt|;
name|CARD
name|sh_hand
index|[
name|HAND_SZ
index|]
decl_stmt|;
name|CARD
name|battle
decl_stmt|;
name|CARD
name|sh_battle
decl_stmt|;
name|CARD
name|speed
decl_stmt|;
name|CARD
name|sh_speed
decl_stmt|;
name|int
name|mileage
decl_stmt|;
name|int
name|sh_mileage
decl_stmt|;
name|int
name|hand_tot
decl_stmt|;
name|int
name|sh_hand_tot
decl_stmt|;
name|int
name|safescore
decl_stmt|;
name|int
name|sh_safescore
decl_stmt|;
name|int
name|coupscore
decl_stmt|;
name|int
name|total
decl_stmt|;
name|int
name|sh_total
decl_stmt|;
name|int
name|games
decl_stmt|;
name|int
name|sh_games
decl_stmt|;
name|int
name|was_finished
decl_stmt|;
block|}
name|PLAY
typedef|;
end_typedef

begin_comment
comment|/*  * macros  */
end_comment

begin_define
define|#
directive|define
name|other
parameter_list|(
name|x
parameter_list|)
value|(1 - x)
end_define

begin_define
define|#
directive|define
name|nextplay
parameter_list|()
value|(Play = other(Play))
end_define

begin_define
define|#
directive|define
name|nextwin
parameter_list|(
name|x
parameter_list|)
value|(1 - x)
end_define

begin_define
define|#
directive|define
name|opposite
parameter_list|(
name|x
parameter_list|)
value|(Opposite[x])
end_define

begin_define
define|#
directive|define
name|issafety
parameter_list|(
name|x
parameter_list|)
value|(x>= C_GAS_SAFE)
end_define

begin_comment
comment|/*  * externals  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|Debug
decl_stmt|,
name|Finished
decl_stmt|,
name|Next
decl_stmt|,
name|On_exit
decl_stmt|,
name|Order
decl_stmt|,
name|Saved
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|C_fmt
decl_stmt|,
modifier|*
modifier|*
name|C_name
decl_stmt|,
modifier|*
name|Fromfile
decl_stmt|,
name|Initstr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Card_no
decl_stmt|,
name|End
decl_stmt|,
name|Handstart
decl_stmt|,
name|Movetype
decl_stmt|,
name|Numcards
index|[]
decl_stmt|,
name|Numgos
decl_stmt|,
name|Numneed
index|[]
decl_stmt|,
name|Numseen
index|[
name|NUM_CARDS
index|]
decl_stmt|,
name|Play
decl_stmt|,
name|Value
index|[]
decl_stmt|,
name|Window
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CARD
name|Deck
index|[
name|DECK_SZ
index|]
decl_stmt|,
name|Discard
decl_stmt|,
name|Opposite
index|[
name|NUM_CARDS
index|]
decl_stmt|,
name|Sh_discard
decl_stmt|,
modifier|*
name|Topcard
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|outf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PLAY
name|Player
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|Board
decl_stmt|,
modifier|*
name|Miles
decl_stmt|,
modifier|*
name|Score
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * functions  */
end_comment

begin_function_decl
name|void
name|account
parameter_list|(
name|CARD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|calcmove
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|canplay
parameter_list|(
name|PLAY
modifier|*
parameter_list|,
name|PLAY
modifier|*
parameter_list|,
name|CARD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|check_ext
parameter_list|(
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|check_more
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
name|domove
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|error
parameter_list|(
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|EXTRAP
end_ifdef

begin_function_decl
name|void
name|extrapolate
parameter_list|(
name|PLAY
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|finalscore
parameter_list|(
name|PLAY
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CARD
name|getcard
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|getyn
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isrepair
parameter_list|(
name|CARD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|newboard
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|newscore
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|onecard
parameter_list|(
name|PLAY
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prboard
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prompt
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prscore
parameter_list|(
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
name|readch
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|rest_f
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|roll
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rub
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CARD
name|safety
parameter_list|(
name|CARD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|save
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|shuffle
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sort
parameter_list|(
name|CARD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|varpush
parameter_list|(
name|int
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|EXTRAP
end_ifdef

begin_function_decl
name|void
name|undoex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

