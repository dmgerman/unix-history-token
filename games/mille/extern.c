begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
unit|static char sccsid[] = "@(#)extern.c	8.1 (Berkeley) 5/31/93";
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
file|"mille.h"
end_include

begin_comment
comment|/*  * @(#)extern.c	1.1 (Berkeley) 4/1/82  */
end_comment

begin_decl_stmt
name|bool
name|Debug
decl_stmt|,
comment|/* set if debugging code on		*/
name|Finished
decl_stmt|,
comment|/* set if current hand is finished	*/
name|Next
decl_stmt|,
comment|/* set if changing players		*/
name|On_exit
decl_stmt|,
comment|/* set if game saved on exiting		*/
name|Order
decl_stmt|,
comment|/* set if hand should be sorted		*/
name|Saved
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if game just saved		*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|C_fmt
init|=
literal|"%-18.18s"
decl_stmt|,
comment|/* format for printing cards		*/
modifier|*
name|Fromfile
init|=
name|NULL
decl_stmt|,
comment|/* startup file for game		*/
name|Initstr
index|[
literal|100
index|]
decl_stmt|,
comment|/* initial string for error field	*/
modifier|*
name|_cn
index|[
name|NUM_CARDS
index|]
init|=
block|{
comment|/* Card name buffer			*/
literal|""
block|,
literal|"25"
block|,
literal|"50"
block|,
literal|"75"
block|,
literal|"100"
block|,
literal|"200"
block|,
literal|"Out of Gas"
block|,
literal|"Flat Tire"
block|,
literal|"Accident"
block|,
literal|"Stop"
block|,
literal|"Speed Limit"
block|,
literal|"Gasoline"
block|,
literal|"Spare Tire"
block|,
literal|"Repairs"
block|,
literal|"Go"
block|,
literal|"End of Limit"
block|,
literal|"Extra Tank"
block|,
literal|"Puncture Proof"
block|,
literal|"Driving Ace"
block|,
literal|"Right of Way"
block|}
decl_stmt|,
modifier|*
modifier|*
name|C_name
init|=
operator|&
name|_cn
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Card names				*/
end_comment

begin_decl_stmt
name|int
name|Card_no
decl_stmt|,
comment|/* Card number for current move		*/
name|End
decl_stmt|,
comment|/* End value for current hand		*/
name|Handstart
init|=
name|COMP
decl_stmt|,
comment|/* Player who starts hand		*/
name|Movetype
decl_stmt|,
comment|/* Current move type			*/
name|Play
decl_stmt|,
comment|/* Current player			*/
name|Numgos
decl_stmt|,
comment|/* Number of Go cards used by computer	*/
name|Window
init|=
name|W_SMALL
decl_stmt|,
comment|/* Current window wanted		*/
name|Numseen
index|[
name|NUM_CARDS
index|]
decl_stmt|,
comment|/* Number of cards seen in current hand	*/
name|Value
index|[
name|NUM_MILES
index|]
init|=
block|{
comment|/* Value of mileage cards		*/
literal|25
block|,
literal|50
block|,
literal|75
block|,
literal|100
block|,
literal|200
block|}
decl_stmt|,
name|Numcards
index|[
name|NUM_CARDS
index|]
init|=
block|{
comment|/* Number of cards in deck		*/
literal|10
block|,
comment|/* C_25 */
literal|10
block|,
comment|/* C_50 */
literal|10
block|,
comment|/* C_75 */
literal|12
block|,
comment|/* C_100 */
literal|4
block|,
comment|/* C_200 */
literal|2
block|,
comment|/* C_EMPTY */
literal|2
block|,
comment|/* C_FLAT */
literal|2
block|,
comment|/* C_CRASH */
literal|4
block|,
comment|/* C_STOP */
literal|3
block|,
comment|/* C_LIMIT */
literal|6
block|,
comment|/* C_GAS */
literal|6
block|,
comment|/* C_SPARE */
literal|6
block|,
comment|/* C_REPAIRS */
literal|14
block|,
comment|/* C_GO */
literal|6
block|,
comment|/* C_END_LIMIT */
literal|1
block|,
comment|/* C_GAS_SAFE */
literal|1
block|,
comment|/* C_SPARE_SAFE */
literal|1
block|,
comment|/* C_DRIVE_SAFE */
literal|1
block|,
comment|/* C_RIGHT_WAY */
literal|0
comment|/* C_INIT */
block|}
decl_stmt|,
name|Numneed
index|[
name|NUM_CARDS
index|]
init|=
block|{
comment|/* number of cards needed per hand	*/
literal|0
block|,
comment|/* C_25 */
literal|0
block|,
comment|/* C_50 */
literal|0
block|,
comment|/* C_75 */
literal|0
block|,
comment|/* C_100 */
literal|0
block|,
comment|/* C_200 */
literal|2
block|,
comment|/* C_EMPTY */
literal|2
block|,
comment|/* C_FLAT */
literal|2
block|,
comment|/* C_CRASH */
literal|4
block|,
comment|/* C_STOP */
literal|3
block|,
comment|/* C_LIMIT */
literal|2
block|,
comment|/* C_GAS */
literal|2
block|,
comment|/* C_SPARE */
literal|2
block|,
comment|/* C_REPAIRS */
literal|10
block|,
comment|/* C_GO */
literal|3
block|,
comment|/* C_END_LIMIT */
literal|1
block|,
comment|/* C_GAS_SAFE */
literal|1
block|,
comment|/* C_SPARE_SAFE */
literal|1
block|,
comment|/* C_DRIVE_SAFE */
literal|1
block|,
comment|/* C_RIGHT_WAY */
literal|0
comment|/* C_INIT */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CARD
name|Discard
decl_stmt|,
comment|/* Top of discard pile			*/
name|Sh_discard
decl_stmt|,
comment|/* Last discard card shown		*/
modifier|*
name|Topcard
decl_stmt|,
comment|/* Pointer to next card to be picked	*/
name|Opposite
index|[
name|NUM_CARDS
index|]
init|=
block|{
comment|/* Opposites of each card		*/
name|C_25
block|,
name|C_50
block|,
name|C_75
block|,
name|C_100
block|,
name|C_200
block|,
name|C_GAS
block|,
name|C_SPARE
block|,
name|C_REPAIRS
block|,
name|C_GO
block|,
name|C_END_LIMIT
block|,
name|C_EMPTY
block|,
name|C_FLAT
block|,
name|C_CRASH
block|,
name|C_STOP
block|,
name|C_LIMIT
block|,
name|C_EMPTY
block|,
name|C_FLAT
block|,
name|C_CRASH
block|,
name|C_STOP
block|,
name|C_INIT
block|}
decl_stmt|,
name|Deck
index|[
name|DECK_SZ
index|]
init|=
block|{
comment|/* Current deck				*/
name|C_25
block|,
name|C_25
block|,
name|C_25
block|,
name|C_25
block|,
name|C_25
block|,
name|C_25
block|,
name|C_25
block|,
name|C_25
block|,
name|C_25
block|,
name|C_25
block|,
name|C_50
block|,
name|C_50
block|,
name|C_50
block|,
name|C_50
block|,
name|C_50
block|,
name|C_50
block|,
name|C_50
block|,
name|C_50
block|,
name|C_50
block|,
name|C_50
block|,
name|C_75
block|,
name|C_75
block|,
name|C_75
block|,
name|C_75
block|,
name|C_75
block|,
name|C_75
block|,
name|C_75
block|,
name|C_75
block|,
name|C_75
block|,
name|C_75
block|,
name|C_100
block|,
name|C_100
block|,
name|C_100
block|,
name|C_100
block|,
name|C_100
block|,
name|C_100
block|,
name|C_100
block|,
name|C_100
block|,
name|C_100
block|,
name|C_100
block|,
name|C_100
block|,
name|C_100
block|,
name|C_200
block|,
name|C_200
block|,
name|C_200
block|,
name|C_200
block|,
name|C_EMPTY
block|,
name|C_EMPTY
block|,
name|C_FLAT
block|,
name|C_FLAT
block|,
name|C_CRASH
block|,
name|C_CRASH
block|,
name|C_STOP
block|,
name|C_STOP
block|,
name|C_STOP
block|,
name|C_STOP
block|,
name|C_LIMIT
block|,
name|C_LIMIT
block|,
name|C_LIMIT
block|,
name|C_GAS
block|,
name|C_GAS
block|,
name|C_GAS
block|,
name|C_GAS
block|,
name|C_GAS
block|,
name|C_GAS
block|,
name|C_SPARE
block|,
name|C_SPARE
block|,
name|C_SPARE
block|,
name|C_SPARE
block|,
name|C_SPARE
block|,
name|C_SPARE
block|,
name|C_REPAIRS
block|,
name|C_REPAIRS
block|,
name|C_REPAIRS
block|,
name|C_REPAIRS
block|,
name|C_REPAIRS
block|,
name|C_REPAIRS
block|,
name|C_END_LIMIT
block|,
name|C_END_LIMIT
block|,
name|C_END_LIMIT
block|,
name|C_END_LIMIT
block|,
name|C_END_LIMIT
block|,
name|C_END_LIMIT
block|,
name|C_GO
block|,
name|C_GO
block|,
name|C_GO
block|,
name|C_GO
block|,
name|C_GO
block|,
name|C_GO
block|,
name|C_GO
block|,
name|C_GO
block|,
name|C_GO
block|,
name|C_GO
block|,
name|C_GO
block|,
name|C_GO
block|,
name|C_GO
block|,
name|C_GO
block|,
name|C_GAS_SAFE
block|,
name|C_SPARE_SAFE
block|,
name|C_DRIVE_SAFE
block|,
name|C_RIGHT_WAY
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|outf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PLAY
name|Player
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Player descriptions			*/
end_comment

begin_decl_stmt
name|WINDOW
modifier|*
name|Board
decl_stmt|,
comment|/* Playing field screen			*/
modifier|*
name|Miles
decl_stmt|,
comment|/* Mileage screen			*/
modifier|*
name|Score
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Score screen				*/
end_comment

end_unit

