begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)gomoku.h	8.2 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* board dimensions */
end_comment

begin_define
define|#
directive|define
name|BSZ
value|19
end_define

begin_define
define|#
directive|define
name|BSZ1
value|(BSZ+1)
end_define

begin_define
define|#
directive|define
name|BSZ2
value|(BSZ+2)
end_define

begin_define
define|#
directive|define
name|BAREA
value|(BSZ2*BSZ1+1)
end_define

begin_comment
comment|/* frame dimentions (based on 5 in a row) */
end_comment

begin_define
define|#
directive|define
name|FSZ1
value|BSZ
end_define

begin_define
define|#
directive|define
name|FSZ2
value|(BSZ-4)
end_define

begin_define
define|#
directive|define
name|FAREA
value|(FSZ1*FSZ2 + FSZ2*FSZ2 + FSZ1*FSZ2 + FSZ2*FSZ2)
end_define

begin_define
define|#
directive|define
name|MUP
value|(BSZ1)
end_define

begin_define
define|#
directive|define
name|MDOWN
value|(-BSZ1)
end_define

begin_define
define|#
directive|define
name|MLEFT
value|(-1)
end_define

begin_define
define|#
directive|define
name|MRIGHT
value|(1)
end_define

begin_comment
comment|/* values for s_occ */
end_comment

begin_define
define|#
directive|define
name|BLACK
value|0
end_define

begin_define
define|#
directive|define
name|WHITE
value|1
end_define

begin_define
define|#
directive|define
name|EMPTY
value|2
end_define

begin_define
define|#
directive|define
name|BORDER
value|3
end_define

begin_comment
comment|/* return values for makemove() */
end_comment

begin_define
define|#
directive|define
name|MOVEOK
value|0
end_define

begin_define
define|#
directive|define
name|RESIGN
value|1
end_define

begin_define
define|#
directive|define
name|ILLEGAL
value|2
end_define

begin_define
define|#
directive|define
name|WIN
value|3
end_define

begin_define
define|#
directive|define
name|TIE
value|4
end_define

begin_define
define|#
directive|define
name|SAVE
value|5
end_define

begin_define
define|#
directive|define
name|A
value|1
end_define

begin_define
define|#
directive|define
name|B
value|2
end_define

begin_define
define|#
directive|define
name|C
value|3
end_define

begin_define
define|#
directive|define
name|D
value|4
end_define

begin_define
define|#
directive|define
name|E
value|5
end_define

begin_define
define|#
directive|define
name|F
value|6
end_define

begin_define
define|#
directive|define
name|G
value|7
end_define

begin_define
define|#
directive|define
name|H
value|8
end_define

begin_define
define|#
directive|define
name|J
value|9
end_define

begin_define
define|#
directive|define
name|K
value|10
end_define

begin_define
define|#
directive|define
name|L
value|11
end_define

begin_define
define|#
directive|define
name|M
value|12
end_define

begin_define
define|#
directive|define
name|N
value|13
end_define

begin_define
define|#
directive|define
name|O
value|14
end_define

begin_define
define|#
directive|define
name|P
value|15
end_define

begin_define
define|#
directive|define
name|Q
value|16
end_define

begin_define
define|#
directive|define
name|R
value|17
end_define

begin_define
define|#
directive|define
name|S
value|18
end_define

begin_define
define|#
directive|define
name|T
value|19
end_define

begin_define
define|#
directive|define
name|PT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) + BSZ1 * (y))
end_define

begin_comment
comment|/*  * A 'frame' is a group of five or six contiguous board locations.  * An open ended frame is one with spaces on both ends; otherwise, its closed.  * A 'combo' is a group of intersecting frames and consists of two numbers:  * 'A' is the number of moves to make the combo non-blockable.  * 'B' is the minimum number of moves needed to win once it can't be blocked.  * A 'force' is a combo that is one move away from being non-blockable  *  * Single frame combo values:  *<A,B>	board values  *	5,0	. . . . . O  *	4,1	. . . . . .  *	4,0	. . . . X O  *	3,1	. . . . X .  *	3,0	. . . X X O  *	2,1	. . . X X .  *	2,0	. . X X X O  *	1,1	. . X X X .  *	1,0	. X X X X O  *	0,1	. X X X X .  *	0,0	X X X X X O  *  * The rule for combining two combos (<A1,B1><A2,B2>)  * with V valid intersection points, is:  *	A' = A1 + A2 - 2 - V  *	B' = MIN(A1 + B1 - 1, A2 + B2 - 1)  * Each time a frame is added to the combo, the number of moves to complete  * the force is the number of moves needed to 'fill' the frame plus one at  * the intersection point. The number of moves to win is the number of moves  * to complete the best frame minus the last move to complete the force.  * Note that it doesn't make sense to combine a<1,x> with anything since  * it is already a force. Also, the frames have to be independent so a  * single move doesn't affect more than one frame making up the combo.  *  * Rules for comparing which of two combos (<A1,B1><A2,B2>) is better:  * Both the same color:  *<A',B'> = (A1< A2 || A1 == A2&& B1<= B2) ?<A1,B1> :<A2,B2>  *	We want to complete the force first, then the combo with the  *	fewest moves to win.  * Different colors,<A1,B1> is the combo for the player with the next move:  *<A',B'> = A2<= 1&& (A1> 1 || A2 + B2< A1 + B1) ?<A2,B2> :<A1,B1>  *	We want to block only if we have to (i.e., if they are one move away  *	from completing a force and we don't have a force that we can  *	complete which takes fewer or the same number of moves to win).  */
end_comment

begin_define
define|#
directive|define
name|MAXA
value|6
end_define

begin_define
define|#
directive|define
name|MAXB
value|2
end_define

begin_define
define|#
directive|define
name|MAXCOMBO
value|0x600
end_define

begin_union
union|union
name|comboval
block|{
struct|struct
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_char
name|a
decl_stmt|;
comment|/* # moves to complete force */
name|u_char
name|b
decl_stmt|;
comment|/* # moves to win */
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|u_char
name|b
decl_stmt|;
comment|/* # moves to win */
name|u_char
name|a
decl_stmt|;
comment|/* # moves to complete force */
endif|#
directive|endif
block|}
name|c
struct|;
name|u_short
name|s
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * This structure is used to record information about single frames (F) and  * combinations of two more frames (C).  * For combinations of two or more frames, there is an additional  * array of pointers to the frames of the combination which is sorted  * by the index into the frames[] array. This is used to prevent duplication  * since frame A combined with B is the same as B with A.  *	struct combostr *c_sort[size c_nframes];  * The leaves of the tree (frames) are numbered 0 (bottom, leftmost)  * to c_nframes - 1 (top, right). This is stored in c_frameindex and  * c_dir if C_LOOP is set.  */
end_comment

begin_struct
struct|struct
name|combostr
block|{
name|struct
name|combostr
modifier|*
name|c_next
decl_stmt|;
comment|/* list of combos at the same level */
name|struct
name|combostr
modifier|*
name|c_prev
decl_stmt|;
comment|/* list of combos at the same level */
name|struct
name|combostr
modifier|*
name|c_link
index|[
literal|2
index|]
decl_stmt|;
comment|/* C:previous level or F:NULL */
name|union
name|comboval
name|c_linkv
index|[
literal|2
index|]
decl_stmt|;
comment|/* C:combo value for link[0,1] */
name|union
name|comboval
name|c_combo
decl_stmt|;
comment|/* C:combo value for this level */
name|u_short
name|c_vertex
decl_stmt|;
comment|/* C:intersection or F:frame head */
name|u_char
name|c_nframes
decl_stmt|;
comment|/* number of frames in the combo */
name|u_char
name|c_dir
decl_stmt|;
comment|/* C:loop frame or F:frame direction */
name|u_char
name|c_flg
decl_stmt|;
comment|/* C:combo flags */
name|u_char
name|c_frameindex
decl_stmt|;
comment|/* C:intersection frame index */
name|u_char
name|c_framecnt
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of frames left to attach */
name|u_char
name|c_emask
index|[
literal|2
index|]
decl_stmt|;
comment|/* C:bit mask of completion spots for 					 * link[0] and link[1] */
name|u_char
name|c_voff
index|[
literal|2
index|]
decl_stmt|;
comment|/* C:vertex offset within frame */
block|}
struct|;
end_struct

begin_comment
comment|/* flag values for c_flg */
end_comment

begin_define
define|#
directive|define
name|C_OPEN_0
value|0x01
end_define

begin_comment
comment|/* link[0] is an open ended frame */
end_comment

begin_define
define|#
directive|define
name|C_OPEN_1
value|0x02
end_define

begin_comment
comment|/* link[1] is an open ended frame */
end_comment

begin_define
define|#
directive|define
name|C_LOOP
value|0x04
end_define

begin_comment
comment|/* link[1] intersects previous frame */
end_comment

begin_define
define|#
directive|define
name|C_MARK
value|0x08
end_define

begin_comment
comment|/* indicates combo processed */
end_comment

begin_comment
comment|/*  * This structure is used for recording the completion points of  * multi frame combos.  */
end_comment

begin_struct
struct|struct
name|elist
block|{
name|struct
name|elist
modifier|*
name|e_next
decl_stmt|;
comment|/* list of completion points */
name|struct
name|combostr
modifier|*
name|e_combo
decl_stmt|;
comment|/* the whole combo */
name|u_char
name|e_off
decl_stmt|;
comment|/* offset in frame of this empty spot */
name|u_char
name|e_frameindex
decl_stmt|;
comment|/* intersection frame index */
name|u_char
name|e_framecnt
decl_stmt|;
comment|/* number of frames left to attach */
name|u_char
name|e_emask
decl_stmt|;
comment|/* real value of the frame's emask */
name|union
name|comboval
name|e_fval
decl_stmt|;
comment|/* frame combo value */
block|}
struct|;
end_struct

begin_comment
comment|/*  * One spot structure for each location on the board.  * A frame consists of the combination for the current spot plus the five spots  * 0: right, 1: right& down, 2: down, 3: down& left.  */
end_comment

begin_struct
struct|struct
name|spotstr
block|{
name|short
name|s_occ
decl_stmt|;
comment|/* color of occupant */
name|short
name|s_wval
decl_stmt|;
comment|/* weighted value */
name|int
name|s_flg
decl_stmt|;
comment|/* flags for graph walks */
name|struct
name|combostr
modifier|*
name|s_frame
index|[
literal|4
index|]
decl_stmt|;
comment|/* level 1 combo for frame[dir] */
name|union
name|comboval
name|s_fval
index|[
literal|2
index|]
index|[
literal|4
index|]
decl_stmt|;
comment|/* combo value for [color][frame] */
name|union
name|comboval
name|s_combo
index|[
literal|2
index|]
decl_stmt|;
comment|/* minimum combo value for BLK& WHT */
name|u_char
name|s_level
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of frames in the min combo */
name|u_char
name|s_nforce
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of<1,x> combos */
name|struct
name|elist
modifier|*
name|s_empty
decl_stmt|;
comment|/* level n combo completion spots */
name|struct
name|elist
modifier|*
name|s_nempty
decl_stmt|;
comment|/* level n+1 combo completion spots */
name|int
name|dummy
index|[
literal|2
index|]
decl_stmt|;
comment|/* XXX */
block|}
struct|;
end_struct

begin_comment
comment|/* flag values for s_flg */
end_comment

begin_define
define|#
directive|define
name|CFLAG
value|0x000001
end_define

begin_comment
comment|/* frame is part of a combo */
end_comment

begin_define
define|#
directive|define
name|CFLAGALL
value|0x00000F
end_define

begin_comment
comment|/* all frame directions marked */
end_comment

begin_define
define|#
directive|define
name|IFLAG
value|0x000010
end_define

begin_comment
comment|/* legal intersection point */
end_comment

begin_define
define|#
directive|define
name|IFLAGALL
value|0x0000F0
end_define

begin_comment
comment|/* any intersection points? */
end_comment

begin_define
define|#
directive|define
name|FFLAG
value|0x000100
end_define

begin_comment
comment|/* frame is part of a<1,x> combo */
end_comment

begin_define
define|#
directive|define
name|FFLAGALL
value|0x000F00
end_define

begin_comment
comment|/* all force frames */
end_comment

begin_define
define|#
directive|define
name|MFLAG
value|0x001000
end_define

begin_comment
comment|/* frame has already been seen */
end_comment

begin_define
define|#
directive|define
name|MFLAGALL
value|0x00F000
end_define

begin_comment
comment|/* all frames seen */
end_comment

begin_define
define|#
directive|define
name|BFLAG
value|0x010000
end_define

begin_comment
comment|/* frame intersects border or dead */
end_comment

begin_define
define|#
directive|define
name|BFLAGALL
value|0x0F0000
end_define

begin_comment
comment|/* all frames dead */
end_comment

begin_comment
comment|/*  * This structure is used to store overlap information between frames.  */
end_comment

begin_struct
struct|struct
name|ovlp_info
block|{
name|int
name|o_intersect
decl_stmt|;
comment|/* intersection spot */
name|struct
name|combostr
modifier|*
name|o_fcombo
decl_stmt|;
comment|/* the connecting combo */
name|u_char
name|o_link
decl_stmt|;
comment|/* which link to update (0 or 1) */
name|u_char
name|o_off
decl_stmt|;
comment|/* offset in frame of intersection */
name|u_char
name|o_frameindex
decl_stmt|;
comment|/* intersection frame index */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|letters
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|fmtbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|pdir
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dd
index|[
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|spotstr
name|board
index|[
name|BAREA
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* info for board */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|combostr
name|frames
index|[
name|FAREA
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* storage for single frames */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|combostr
modifier|*
name|sortframes
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sorted, non-empty frames */
end_comment

begin_decl_stmt
specifier|extern
name|u_char
name|overlap
index|[
name|FAREA
operator|*
name|FAREA
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* frame [a][b] overlap */
end_comment

begin_decl_stmt
specifier|extern
name|short
name|intersect
index|[
name|FAREA
operator|*
name|FAREA
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* frame [a][b] intersection */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|movelog
index|[
name|BSZ
operator|*
name|BSZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* history of moves */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|movenum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|copy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|stoc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|tail
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|x
parameter_list|)
end_define

end_unit

