begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993 The Regents of the University of California.  * All rights reserved.  *  * The game adventure was originally written in Fortran by Will Crowther  * and Don Woods.  It was later translated to C and enhanced by Jim  * Gillogly.  This code is derived from software contributed to Berkeley  * by Jim Gillogly at The Rand Corporation.  *  * %sccs.include.redist.c%  *  *	@(#)hdr.h	5.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*   ADVENTURE -- Jim Gillogly, Jul 1977  * This program is a re-write of ADVENT, written in FORTRAN mostly by  * Don Woods of SAIL.  In most places it is as nearly identical to the  * original as possible given the language and word-size differences.  * A few places, such as the message arrays and travel arrays were changed  * to reflect the smaller core size and word size.  The labels of the  * original are reflected in this version, so that the comments of the  * fortran are still applicable here.  *  * The data file distributed with the fortran source is assumed to be called  * "glorkz" in the directory where the program is first run.  */
end_comment

begin_comment
comment|/* hdr.h: included by c advent files */
end_comment

begin_decl_stmt
name|int
name|datfd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* message file descriptor      */
end_comment

begin_decl_stmt
name|int
name|delhit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|yea
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|data_file
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Virtual data file            */
end_comment

begin_define
define|#
directive|define
name|TAB
value|011
end_define

begin_define
define|#
directive|define
name|LF
value|012
end_define

begin_define
define|#
directive|define
name|FLUSHLINE
value|while (getchar()!='\n')
end_define

begin_define
define|#
directive|define
name|FLUSHLF
value|while (next()!=LF)
end_define

begin_decl_stmt
name|int
name|loc
decl_stmt|,
name|newloc
decl_stmt|,
name|oldloc
decl_stmt|,
name|oldlc2
decl_stmt|,
name|wzdark
decl_stmt|,
name|gaveup
decl_stmt|,
name|kq
decl_stmt|,
name|k
decl_stmt|,
name|k2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|wd1
decl_stmt|,
modifier|*
name|wd2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the complete words           */
end_comment

begin_decl_stmt
name|int
name|verb
decl_stmt|,
name|obj
decl_stmt|,
name|spk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|blklin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|saved
decl_stmt|,
name|savet
decl_stmt|,
name|mxscor
decl_stmt|,
name|latncy
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SHORT
value|50
end_define

begin_comment
comment|/* How short is a demo game?    */
end_comment

begin_define
define|#
directive|define
name|MAXSTR
value|20
end_define

begin_comment
comment|/* max length of user's words   */
end_comment

begin_define
define|#
directive|define
name|HTSIZE
value|512
end_define

begin_comment
comment|/* max number of vocab words    */
end_comment

begin_struct
struct|struct
name|hashtab
comment|/* hash table for vocabulary    */
block|{
name|int
name|val
decl_stmt|;
comment|/* word type&index (ktab)      */
name|char
modifier|*
name|atab
decl_stmt|;
comment|/* pointer to actual string     */
block|}
name|voc
index|[
name|HTSIZE
index|]
struct|;
end_struct

begin_define
define|#
directive|define
name|SEED
value|1815622
end_define

begin_comment
comment|/* "Encryption" seed            */
end_comment

begin_struct
struct|struct
name|text
ifdef|#
directive|ifdef
name|OLDSTUFF
block|{
name|int
name|seekadr
decl_stmt|;
comment|/* DATFILE must be< 2**16      */
endif|#
directive|endif
endif|OLDSTUFF
block|{
name|char
modifier|*
name|seekadr
decl_stmt|;
comment|/* Msg start in virtual disk    */
name|int
name|txtlen
decl_stmt|;
comment|/* length of msg starting here  */
block|}
empty_stmt|;
define|#
directive|define
name|RTXSIZ
value|205
name|struct
name|text
name|rtext
index|[
name|RTXSIZ
index|]
decl_stmt|;
comment|/* random text messages         */
define|#
directive|define
name|MAGSIZ
value|35
name|struct
name|text
name|mtext
index|[
name|MAGSIZ
index|]
decl_stmt|;
comment|/* magic messages               */
name|int
name|clsses
decl_stmt|;
define|#
directive|define
name|CLSMAX
value|12
name|struct
name|text
name|ctext
index|[
name|CLSMAX
index|]
decl_stmt|;
comment|/* classes of adventurer        */
name|int
name|cval
index|[
name|CLSMAX
index|]
decl_stmt|;
name|struct
name|text
name|ptext
index|[
literal|101
index|]
decl_stmt|;
comment|/* object descriptions          */
define|#
directive|define
name|LOCSIZ
value|141
comment|/* number of locations          */
name|struct
name|text
name|ltext
index|[
name|LOCSIZ
index|]
decl_stmt|;
comment|/* long loc description         */
name|struct
name|text
name|stext
index|[
name|LOCSIZ
index|]
decl_stmt|;
comment|/* short loc descriptions       */
struct|struct
name|travlist
comment|/* direcs& conditions of travel*/
block|{
name|struct
name|travlist
modifier|*
name|next
decl_stmt|;
comment|/* ptr to next list entry       */
name|int
name|conditions
decl_stmt|;
comment|/* m in writeup (newloc / 1000) */
name|int
name|tloc
decl_stmt|;
comment|/* n in writeup (newloc % 1000) */
name|int
name|tverb
decl_stmt|;
comment|/* the verb that takes you there*/
block|}
modifier|*
name|travel
index|[
name|LOCSIZ
index|]
struct|,
modifier|*
name|tkk
struct|;
comment|/* travel is closer to keys(...)*/
name|int
name|atloc
index|[
name|LOCSIZ
index|]
decl_stmt|;
name|int
name|plac
index|[
literal|101
index|]
decl_stmt|;
comment|/* initial object placement     */
name|int
name|fixd
index|[
literal|101
index|]
decl_stmt|,
name|fixed
index|[
literal|101
index|]
decl_stmt|;
comment|/* location fixed?              */
name|int
name|actspk
index|[
literal|35
index|]
decl_stmt|;
comment|/* rtext msg for verb<n>       */
name|int
name|cond
index|[
name|LOCSIZ
index|]
decl_stmt|;
comment|/* various condition bits       */
specifier|extern
name|int
name|setbit
index|[
literal|16
index|]
decl_stmt|;
comment|/* bit defn masks 1,2,4,...     */
name|int
name|hntmax
decl_stmt|;
name|int
name|hints
index|[
literal|20
index|]
index|[
literal|5
index|]
decl_stmt|;
comment|/* info on hints                */
name|int
name|hinted
index|[
literal|20
index|]
decl_stmt|,
name|hintlc
index|[
literal|20
index|]
decl_stmt|;
name|int
name|place
index|[
literal|101
index|]
decl_stmt|,
name|prop
index|[
literal|101
index|]
decl_stmt|,
name|link
index|[
literal|201
index|]
decl_stmt|;
name|int
name|abb
index|[
name|LOCSIZ
index|]
decl_stmt|;
name|int
name|maxtrs
decl_stmt|,
name|tally
decl_stmt|,
name|tally2
decl_stmt|;
comment|/* treasure values              */
define|#
directive|define
name|FALSE
value|0
define|#
directive|define
name|TRUE
value|1
name|int
name|keys
decl_stmt|,
name|lamp
decl_stmt|,
name|grate
decl_stmt|,
name|cage
decl_stmt|,
name|rod
decl_stmt|,
name|rod2
decl_stmt|,
name|steps
decl_stmt|,
comment|/* mnemonics                    */
name|bird
decl_stmt|,
name|door
decl_stmt|,
name|pillow
decl_stmt|,
name|snake
decl_stmt|,
name|fissur
decl_stmt|,
name|tablet
decl_stmt|,
name|clam
decl_stmt|,
name|oyster
decl_stmt|,
name|magzin
decl_stmt|,
name|dwarf
decl_stmt|,
name|knife
decl_stmt|,
name|food
decl_stmt|,
name|bottle
decl_stmt|,
name|water
decl_stmt|,
name|oil
decl_stmt|,
name|plant
decl_stmt|,
name|plant2
decl_stmt|,
name|axe
decl_stmt|,
name|mirror
decl_stmt|,
name|dragon
decl_stmt|,
name|chasm
decl_stmt|,
name|troll
decl_stmt|,
name|troll2
decl_stmt|,
name|bear
decl_stmt|,
name|messag
decl_stmt|,
name|vend
decl_stmt|,
name|batter
decl_stmt|,
name|nugget
decl_stmt|,
name|coins
decl_stmt|,
name|chest
decl_stmt|,
name|eggs
decl_stmt|,
name|tridnt
decl_stmt|,
name|vase
decl_stmt|,
name|emrald
decl_stmt|,
name|pyram
decl_stmt|,
name|pearl
decl_stmt|,
name|rug
decl_stmt|,
name|chain
decl_stmt|,
name|spices
decl_stmt|,
name|back
decl_stmt|,
name|look
decl_stmt|,
name|cave
decl_stmt|,
name|null
decl_stmt|,
name|entrnc
decl_stmt|,
name|dprssn
decl_stmt|,
name|enter
decl_stmt|,
name|stream
decl_stmt|,
name|pour
decl_stmt|,
name|say
decl_stmt|,
name|lock
decl_stmt|,
name|throw
decl_stmt|,
name|find
decl_stmt|,
name|invent
decl_stmt|;
name|int
name|chloc
decl_stmt|,
name|chloc2
decl_stmt|,
name|dseen
index|[
literal|7
index|]
decl_stmt|,
name|dloc
index|[
literal|7
index|]
decl_stmt|,
comment|/* dwarf stuff                  */
name|odloc
index|[
literal|7
index|]
decl_stmt|,
name|dflag
decl_stmt|,
name|daltlc
decl_stmt|;
name|int
name|tk
index|[
literal|21
index|]
decl_stmt|,
name|stick
decl_stmt|,
name|dtotal
decl_stmt|,
name|attack
decl_stmt|;
name|int
name|turns
decl_stmt|,
name|lmwarn
decl_stmt|,
name|iwest
decl_stmt|,
name|knfloc
decl_stmt|,
name|detail
decl_stmt|,
comment|/* various flags& counters     */
name|abbnum
decl_stmt|,
name|maxdie
decl_stmt|,
name|numdie
decl_stmt|,
name|holdng
decl_stmt|,
name|dkill
decl_stmt|,
name|foobar
decl_stmt|,
name|bonus
decl_stmt|,
name|clock1
decl_stmt|,
name|clock2
decl_stmt|,
name|saved
decl_stmt|,
name|closng
decl_stmt|,
name|panic
decl_stmt|,
name|closed
decl_stmt|,
name|scorng
decl_stmt|;
name|int
name|demo
decl_stmt|,
name|newloc
decl_stmt|,
name|limit
decl_stmt|;
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
name|char
modifier|*
name|decr
parameter_list|()
function_decl|;
name|unsigned
name|long
name|crc
parameter_list|()
function_decl|;
end_struct

begin_comment
comment|/* We need to get a little tricky to avoid strings */
end_comment

begin_define
define|#
directive|define
name|DECR
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|decr('a'+'+','b'+'-','c'+'#','d'+'&','e'+'%')
end_define

end_unit

