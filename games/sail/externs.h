begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)externs.h	8.1 (Berkeley) 5/31/93  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"machdep.h"
end_include

begin_comment
comment|/* program mode */
end_comment

begin_decl_stmt
name|int
name|mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|jmp_buf
name|restart
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MODE_PLAYER
value|1
end_define

begin_define
define|#
directive|define
name|MODE_DRIVER
value|2
end_define

begin_define
define|#
directive|define
name|MODE_LOGGER
value|3
end_define

begin_comment
comment|/* command line flags */
end_comment

begin_decl_stmt
name|char
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -D */
end_comment

begin_decl_stmt
name|char
name|randomize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -x, give first available ship */
end_comment

begin_decl_stmt
name|char
name|longfmt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -l, print score in long format */
end_comment

begin_decl_stmt
name|char
name|nobells
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -b, don't ring bell before Signal */
end_comment

begin_comment
comment|/* other initial modes */
end_comment

begin_decl_stmt
name|char
name|issetuid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* running setuid */
end_comment

begin_define
define|#
directive|define
name|die
parameter_list|()
value|(random() % 6 + 1)
end_define

begin_define
define|#
directive|define
name|sqr
parameter_list|(
name|a
parameter_list|)
value|((a) * (a))
end_define

begin_define
define|#
directive|define
name|abs
parameter_list|(
name|a
parameter_list|)
value|((a)> 0 ? (a) : -(a))
end_define

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|grappled
parameter_list|(
name|a
parameter_list|)
value|((a)->file->ngrap)
end_define

begin_define
define|#
directive|define
name|fouled
parameter_list|(
name|a
parameter_list|)
value|((a)->file->nfoul)
end_define

begin_define
define|#
directive|define
name|snagged
parameter_list|(
name|a
parameter_list|)
value|(grappled(a) + fouled(a))
end_define

begin_define
define|#
directive|define
name|grappled2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)->file->grap[(b)->file->index].sn_count)
end_define

begin_define
define|#
directive|define
name|fouled2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)->file->foul[(b)->file->index].sn_count)
end_define

begin_define
define|#
directive|define
name|snagged2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(grappled2(a, b) + fouled2(a, b))
end_define

begin_define
define|#
directive|define
name|Xgrappled2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)->file->grap[(b)->file->index].sn_turn< turn-1 ? grappled2(a, b) : 0)
end_define

begin_define
define|#
directive|define
name|Xfouled2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)->file->foul[(b)->file->index].sn_turn< turn-1 ? fouled2(a, b) : 0)
end_define

begin_define
define|#
directive|define
name|Xsnagged2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(Xgrappled2(a, b) + Xfouled2(a, b))
end_define

begin_define
define|#
directive|define
name|cleangrapple
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|Cleansnag(a, b, c, 1)
end_define

begin_define
define|#
directive|define
name|cleanfoul
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|Cleansnag(a, b, c, 2)
end_define

begin_define
define|#
directive|define
name|cleansnag
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|Cleansnag(a, b, c, 3)
end_define

begin_define
define|#
directive|define
name|sterncolour
parameter_list|(
name|sp
parameter_list|)
value|((sp)->file->stern+'0'-((sp)->file->captured?10:0))
end_define

begin_define
define|#
directive|define
name|sternrow
parameter_list|(
name|sp
parameter_list|)
value|((sp)->file->row + dr[(sp)->file->dir])
end_define

begin_define
define|#
directive|define
name|sterncol
parameter_list|(
name|sp
parameter_list|)
value|((sp)->file->col + dc[(sp)->file->dir])
end_define

begin_define
define|#
directive|define
name|capship
parameter_list|(
name|sp
parameter_list|)
value|((sp)->file->captured?(sp)->file->captured:(sp))
end_define

begin_define
define|#
directive|define
name|readyname
parameter_list|(
name|r
parameter_list|)
value|((r)& R_LOADING ? '*' : ((r)& R_INITIAL ? '!' : ' '))
end_define

begin_comment
comment|/* loadL and loadR, should match loadname[] */
end_comment

begin_define
define|#
directive|define
name|L_EMPTY
value|0
end_define

begin_comment
comment|/* should be 0, don't change */
end_comment

begin_define
define|#
directive|define
name|L_GRAPE
value|1
end_define

begin_define
define|#
directive|define
name|L_CHAIN
value|2
end_define

begin_define
define|#
directive|define
name|L_ROUND
value|3
end_define

begin_define
define|#
directive|define
name|L_DOUBLE
value|4
end_define

begin_define
define|#
directive|define
name|L_EXPLODE
value|5
end_define

begin_comment
comment|/*  * readyL and readyR, these are bits, except R_EMPTY  */
end_comment

begin_define
define|#
directive|define
name|R_EMPTY
value|0
end_define

begin_comment
comment|/* not loaded and not loading */
end_comment

begin_define
define|#
directive|define
name|R_LOADING
value|1
end_define

begin_comment
comment|/* loading */
end_comment

begin_define
define|#
directive|define
name|R_DOUBLE
value|2
end_define

begin_comment
comment|/* loading double */
end_comment

begin_define
define|#
directive|define
name|R_LOADED
value|4
end_define

begin_comment
comment|/* loaded */
end_comment

begin_define
define|#
directive|define
name|R_INITIAL
value|8
end_define

begin_comment
comment|/* loaded initial */
end_comment

begin_define
define|#
directive|define
name|HULL
value|0
end_define

begin_define
define|#
directive|define
name|RIGGING
value|1
end_define

begin_define
define|#
directive|define
name|W_CAPTAIN
value|1
end_define

begin_define
define|#
directive|define
name|W_CAPTURED
value|2
end_define

begin_define
define|#
directive|define
name|W_CLASS
value|3
end_define

begin_define
define|#
directive|define
name|W_CREW
value|4
end_define

begin_define
define|#
directive|define
name|W_DBP
value|5
end_define

begin_define
define|#
directive|define
name|W_DRIFT
value|6
end_define

begin_define
define|#
directive|define
name|W_EXPLODE
value|7
end_define

begin_define
define|#
directive|define
name|W_FILE
value|8
end_define

begin_define
define|#
directive|define
name|W_FOUL
value|9
end_define

begin_define
define|#
directive|define
name|W_GUNL
value|10
end_define

begin_define
define|#
directive|define
name|W_GUNR
value|11
end_define

begin_define
define|#
directive|define
name|W_HULL
value|12
end_define

begin_define
define|#
directive|define
name|W_MOVE
value|13
end_define

begin_define
define|#
directive|define
name|W_OBP
value|14
end_define

begin_define
define|#
directive|define
name|W_PCREW
value|15
end_define

begin_define
define|#
directive|define
name|W_UNFOUL
value|16
end_define

begin_define
define|#
directive|define
name|W_POINTS
value|17
end_define

begin_define
define|#
directive|define
name|W_QUAL
value|18
end_define

begin_define
define|#
directive|define
name|W_UNGRAP
value|19
end_define

begin_define
define|#
directive|define
name|W_RIGG
value|20
end_define

begin_define
define|#
directive|define
name|W_COL
value|21
end_define

begin_define
define|#
directive|define
name|W_DIR
value|22
end_define

begin_define
define|#
directive|define
name|W_ROW
value|23
end_define

begin_define
define|#
directive|define
name|W_SIGNAL
value|24
end_define

begin_define
define|#
directive|define
name|W_SINK
value|25
end_define

begin_define
define|#
directive|define
name|W_STRUCK
value|26
end_define

begin_define
define|#
directive|define
name|W_TA
value|27
end_define

begin_define
define|#
directive|define
name|W_ALIVE
value|28
end_define

begin_define
define|#
directive|define
name|W_TURN
value|29
end_define

begin_define
define|#
directive|define
name|W_WIND
value|30
end_define

begin_define
define|#
directive|define
name|W_FS
value|31
end_define

begin_define
define|#
directive|define
name|W_GRAP
value|32
end_define

begin_define
define|#
directive|define
name|W_RIG1
value|33
end_define

begin_define
define|#
directive|define
name|W_RIG2
value|34
end_define

begin_define
define|#
directive|define
name|W_RIG3
value|35
end_define

begin_define
define|#
directive|define
name|W_RIG4
value|36
end_define

begin_define
define|#
directive|define
name|W_BEGIN
value|37
end_define

begin_define
define|#
directive|define
name|W_END
value|38
end_define

begin_define
define|#
directive|define
name|W_DDEAD
value|39
end_define

begin_define
define|#
directive|define
name|NLOG
value|10
end_define

begin_struct
struct|struct
name|logs
block|{
name|char
name|l_name
index|[
literal|20
index|]
decl_stmt|;
name|int
name|l_uid
decl_stmt|;
name|int
name|l_shipnum
decl_stmt|;
name|int
name|l_gamenum
decl_stmt|;
name|int
name|l_netpoints
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|BP
block|{
name|short
name|turnsent
decl_stmt|;
name|struct
name|ship
modifier|*
name|toship
decl_stmt|;
name|short
name|mensent
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|snag
block|{
name|short
name|sn_count
decl_stmt|;
name|short
name|sn_turn
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NSCENE
value|nscene
end_define

begin_define
define|#
directive|define
name|NSHIP
value|10
end_define

begin_define
define|#
directive|define
name|NBP
value|3
end_define

begin_define
define|#
directive|define
name|NNATION
value|8
end_define

begin_define
define|#
directive|define
name|N_A
value|0
end_define

begin_define
define|#
directive|define
name|N_B
value|1
end_define

begin_define
define|#
directive|define
name|N_S
value|2
end_define

begin_define
define|#
directive|define
name|N_F
value|3
end_define

begin_define
define|#
directive|define
name|N_J
value|4
end_define

begin_define
define|#
directive|define
name|N_D
value|5
end_define

begin_define
define|#
directive|define
name|N_K
value|6
end_define

begin_define
define|#
directive|define
name|N_O
value|7
end_define

begin_struct
struct|struct
name|File
block|{
name|int
name|index
decl_stmt|;
name|char
name|captain
index|[
literal|20
index|]
decl_stmt|;
comment|/* 0 */
name|short
name|points
decl_stmt|;
comment|/* 20 */
name|char
name|loadL
decl_stmt|;
comment|/* 22 */
name|char
name|loadR
decl_stmt|;
comment|/* 24 */
name|char
name|readyL
decl_stmt|;
comment|/* 26 */
name|char
name|readyR
decl_stmt|;
comment|/* 28 */
name|struct
name|BP
name|OBP
index|[
name|NBP
index|]
decl_stmt|;
comment|/* 30 */
name|struct
name|BP
name|DBP
index|[
name|NBP
index|]
decl_stmt|;
comment|/* 48 */
name|char
name|struck
decl_stmt|;
comment|/* 66 */
name|struct
name|ship
modifier|*
name|captured
decl_stmt|;
comment|/* 68 */
name|short
name|pcrew
decl_stmt|;
comment|/* 70 */
name|char
name|movebuf
index|[
literal|60
index|]
decl_stmt|;
comment|/* 72 */
name|char
name|drift
decl_stmt|;
comment|/* 132 */
name|short
name|nfoul
decl_stmt|;
name|short
name|ngrap
decl_stmt|;
name|struct
name|snag
name|foul
index|[
name|NSHIP
index|]
decl_stmt|;
comment|/* 134 */
name|struct
name|snag
name|grap
index|[
name|NSHIP
index|]
decl_stmt|;
comment|/* 144 */
name|char
name|RH
decl_stmt|;
comment|/* 274 */
name|char
name|RG
decl_stmt|;
comment|/* 276 */
name|char
name|RR
decl_stmt|;
comment|/* 278 */
name|char
name|FS
decl_stmt|;
comment|/* 280 */
name|char
name|explode
decl_stmt|;
comment|/* 282 */
name|char
name|sink
decl_stmt|;
comment|/* 284 */
name|char
name|dir
decl_stmt|;
name|short
name|col
decl_stmt|;
name|short
name|row
decl_stmt|;
name|char
name|loadwith
decl_stmt|;
name|char
name|stern
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ship
block|{
name|char
modifier|*
name|shipname
decl_stmt|;
comment|/* 0 */
name|struct
name|shipspecs
modifier|*
name|specs
decl_stmt|;
comment|/* 2 */
name|char
name|nationality
decl_stmt|;
comment|/* 4 */
name|short
name|shiprow
decl_stmt|;
comment|/* 6 */
name|short
name|shipcol
decl_stmt|;
comment|/* 8 */
name|char
name|shipdir
decl_stmt|;
comment|/* 10 */
name|struct
name|File
modifier|*
name|file
decl_stmt|;
comment|/* 12 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scenario
block|{
name|char
name|winddir
decl_stmt|;
comment|/* 0 */
name|char
name|windspeed
decl_stmt|;
comment|/* 2 */
name|char
name|windchange
decl_stmt|;
comment|/* 4 */
name|char
name|vessels
decl_stmt|;
comment|/* 12 */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* 14 */
name|struct
name|ship
name|ship
index|[
name|NSHIP
index|]
decl_stmt|;
comment|/* 16 */
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|scenario
name|scene
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nscene
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|shipspecs
block|{
name|char
name|bs
decl_stmt|;
name|char
name|fs
decl_stmt|;
name|char
name|ta
decl_stmt|;
name|short
name|guns
decl_stmt|;
name|char
name|class
decl_stmt|;
name|char
name|hull
decl_stmt|;
name|char
name|qual
decl_stmt|;
name|char
name|crew1
decl_stmt|;
name|char
name|crew2
decl_stmt|;
name|char
name|crew3
decl_stmt|;
name|char
name|gunL
decl_stmt|;
name|char
name|gunR
decl_stmt|;
name|char
name|carL
decl_stmt|;
name|char
name|carR
decl_stmt|;
name|char
name|rig1
decl_stmt|;
name|char
name|rig2
decl_stmt|;
name|char
name|rig3
decl_stmt|;
name|char
name|rig4
decl_stmt|;
name|short
name|pts
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|shipspecs
name|specs
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|scenario
modifier|*
name|cc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the current scenario */
end_comment

begin_decl_stmt
name|struct
name|ship
modifier|*
name|ls
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*&cc->ship[cc->vessels] */
end_comment

begin_define
define|#
directive|define
name|SHIP
parameter_list|(
name|s
parameter_list|)
value|(&cc->ship[s])
end_define

begin_define
define|#
directive|define
name|foreachship
parameter_list|(
name|sp
parameter_list|)
value|for ((sp) = cc->ship; (sp)< ls; (sp)++)
end_define

begin_struct
struct|struct
name|windeffects
block|{
name|char
name|A
decl_stmt|,
name|B
decl_stmt|,
name|C
decl_stmt|,
name|D
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|windeffects
name|WET
index|[
literal|7
index|]
index|[
literal|6
index|]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|Tables
block|{
name|char
name|H
decl_stmt|,
name|G
decl_stmt|,
name|C
decl_stmt|,
name|R
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|Tables
name|RigTable
index|[
literal|11
index|]
index|[
literal|6
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|Tables
name|HullTable
index|[
literal|11
index|]
index|[
literal|6
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|AMMO
index|[
literal|9
index|]
index|[
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|HDT
index|[
literal|9
index|]
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|HDTrake
index|[
literal|9
index|]
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|QUAL
index|[
literal|9
index|]
index|[
literal|5
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|MT
index|[
literal|9
index|]
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|countryname
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|classname
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|directionname
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|qualname
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|loadname
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|rangeofshot
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|dr
index|[]
decl_stmt|,
name|dc
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|winddir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|windspeed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|turn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|game
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|alive
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|people
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|hasdriver
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|info
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|quality
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|arctan
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|saywhat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ship
modifier|*
name|closestenemy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|calloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|rindex
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strncpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|gets
parameter_list|()
function_decl|;
end_function_decl

end_unit

