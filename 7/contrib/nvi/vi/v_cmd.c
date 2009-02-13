begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1992, 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|sccsid
index|[]
init|=
literal|"@(#)v_cmd.c	10.9 (Berkeley) 3/28/96"
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<bitstring.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"../common/common.h"
end_include

begin_include
include|#
directive|include
file|"vi.h"
end_include

begin_comment
comment|/*  * This array maps keystrokes to vi command functions.  It is known  * in ex/ex_usage.c that it takes four columns to name a vi character.  */
end_comment

begin_decl_stmt
name|VIKEYS
specifier|const
name|vikeys
index|[
name|MAXVIKEY
operator|+
literal|1
index|]
init|=
block|{
comment|/* 000 NUL -- The code in vi.c expects key 0 to be undefined. */
block|{
name|NULL
block|}
block|,
comment|/* 001  ^A */
block|{
name|v_searchw
block|,
name|V_ABS
operator||
name|V_CNT
operator||
name|V_MOVE
operator||
name|V_KEYW
operator||
name|VM_CUTREQ
operator||
name|VM_RCM_SET
block|,
literal|"[count]^A"
block|,
literal|"^A search forward for cursor word"
block|}
block|,
comment|/* 002  ^B */
block|{
name|v_pageup
block|,
name|V_CNT
operator||
name|VM_RCM_SET
block|,
literal|"[count]^B"
block|,
literal|"^B scroll up by screens"
block|}
block|,
comment|/* 003  ^C */
block|{
name|NULL
block|,
literal|0
block|,
literal|"^C"
block|,
literal|"^C interrupt an operation (e.g. read, write, search)"
block|}
block|,
comment|/* 004  ^D */
block|{
name|v_hpagedown
block|,
name|V_CNT
operator||
name|VM_RCM_SET
block|,
literal|"[count]^D"
block|,
literal|"^D scroll down by half screens (setting count)"
block|}
block|,
comment|/* 005  ^E */
block|{
name|v_linedown
block|,
name|V_CNT
block|,
literal|"[count]^E"
block|,
literal|"^E scroll down by lines"
block|}
block|,
comment|/* 006  ^F */
block|{
name|v_pagedown
block|,
name|V_CNT
operator||
name|VM_RCM_SET
block|,
literal|"[count]^F"
block|,
literal|"^F scroll down by screens"
block|}
block|,
comment|/* 007  ^G */
block|{
name|v_status
block|,
literal|0
block|,
literal|"^G"
block|,
literal|"^G file status"
block|}
block|,
comment|/* 010  ^H */
block|{
name|v_left
block|,
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_RCM_SET
block|,
literal|"[count]^H"
block|,
literal|"^H move left by characters"
block|}
block|,
comment|/* 011  ^I */
block|{
name|NULL
block|}
block|,
comment|/* 012  ^J */
block|{
name|v_down
block|,
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_LMODE
operator||
name|VM_RCM
block|,
literal|"[count]^J"
block|,
literal|"^J move down by lines"
block|}
block|,
comment|/* 013  ^K */
block|{
name|NULL
block|}
block|,
comment|/* 014  ^L */
block|{
name|v_redraw
block|,
literal|0
block|,
literal|"^L"
block|,
literal|"^L redraw screen"
block|}
block|,
comment|/* 015  ^M */
block|{
name|v_cr
block|,
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_LMODE
operator||
name|VM_RCM_SETFNB
block|,
literal|"[count]^M"
block|,
literal|"^M move down by lines (to first non-blank)"
block|}
block|,
comment|/* 016  ^N */
block|{
name|v_down
block|,
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_LMODE
operator||
name|VM_RCM
block|,
literal|"[count]^N"
block|,
literal|"^N move down by lines"
block|}
block|,
comment|/* 017  ^O */
block|{
name|NULL
block|}
block|,
comment|/* 020  ^P */
block|{
name|v_up
block|,
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_LMODE
operator||
name|VM_RCM
block|,
literal|"[count]^P"
block|,
literal|"^P move up by lines"
block|}
block|,
comment|/* 021  ^Q -- same as ^V if not used for hardware flow control. */
block|{
name|NULL
block|}
block|,
comment|/* 022  ^R */
block|{
name|v_redraw
block|,
literal|0
block|,
literal|"^R"
block|,
literal|"^R redraw screen"
block|}
block|,
comment|/* 023  ^S -- not available, used for hardware flow control. */
block|{
name|NULL
block|}
block|,
comment|/* 024  ^T */
block|{
name|v_tagpop
block|,
name|V_ABS
operator||
name|VM_RCM_SET
block|,
literal|"^T"
block|,
literal|"^T tag pop"
block|}
block|,
comment|/* 025  ^U */
block|{
name|v_hpageup
block|,
name|V_CNT
operator||
name|VM_RCM_SET
block|,
literal|"[count]^U"
block|,
literal|"^U half page up (set count)"
block|}
block|,
comment|/* 026  ^V */
block|{
name|NULL
block|,
literal|0
block|,
literal|"^V"
block|,
literal|"^V input a literal character"
block|}
block|,
comment|/* 027  ^W */
block|{
name|v_screen
block|,
literal|0
block|,
literal|"^W"
block|,
literal|"^W move to next screen"
block|}
block|,
comment|/* 030  ^X */
block|{
name|NULL
block|}
block|,
comment|/* 031  ^Y */
block|{
name|v_lineup
block|,
name|V_CNT
block|,
literal|"[count]^Y"
block|,
literal|"^Y page up by lines"
block|}
block|,
comment|/* 032  ^Z */
block|{
name|v_suspend
block|,
name|V_SECURE
block|,
literal|"^Z"
block|,
literal|"^Z suspend editor"
block|}
block|,
comment|/* 033  ^[ */
block|{
name|NULL
block|,
literal|0
block|,
literal|"^[<escape>"
block|,
literal|"^[<escape> exit input mode, cancel partial commands"
block|}
block|,
comment|/* 034  ^\ */
block|{
name|v_exmode
block|,
literal|0
block|,
literal|"^\\"
block|,
literal|" ^\\ switch to ex mode"
block|}
block|,
comment|/* 035  ^] */
block|{
name|v_tagpush
block|,
name|V_ABS
operator||
name|V_KEYW
operator||
name|VM_RCM_SET
block|,
literal|"^]"
block|,
literal|"^] tag push cursor word"
block|}
block|,
comment|/* 036  ^^ */
block|{
name|v_switch
block|,
literal|0
block|,
literal|"^^"
block|,
literal|"^^ switch to previous file"
block|}
block|,
comment|/* 037  ^_ */
block|{
name|NULL
block|}
block|,
comment|/* 040 ' ' */
block|{
name|v_right
block|,
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_RCM_SET
block|,
literal|"[count]' '"
block|,
literal|"<space> move right by columns"
block|}
block|,
comment|/* 041   ! */
block|{
name|v_filter
block|,
name|V_CNT
operator||
name|V_DOT
operator||
name|V_MOTION
operator||
name|V_SECURE
operator||
name|VM_RCM_SET
block|,
literal|"[count]![count]motion command(s)"
block|,
literal|" ! filter through command(s) to motion"
block|}
block|,
comment|/* 042   " */
block|{
name|NULL
block|}
block|,
comment|/* 043   # */
block|{
name|v_increment
block|,
name|V_CHAR
operator||
name|V_CNT
operator||
name|V_DOT
operator||
name|VM_RCM_SET
block|,
literal|"[count]# +|-|#"
block|,
literal|" # number increment/decrement"
block|}
block|,
comment|/* 044   $ */
block|{
name|v_dollar
block|,
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_RCM_SETLAST
block|,
literal|" [count]$"
block|,
literal|" $ move to last column"
block|}
block|,
comment|/* 045   % */
block|{
name|v_match
block|,
name|V_ABS
operator||
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_CUTREQ
operator||
name|VM_RCM_SET
block|,
literal|"%"
block|,
literal|" % move to match"
block|}
block|,
comment|/* 046& */
block|{
name|v_again
block|,
literal|0
block|,
literal|"&"
block|,
literal|"& repeat substitution"
block|}
block|,
comment|/* 047   ' */
block|{
name|v_fmark
block|,
name|V_ABS_L
operator||
name|V_CHAR
operator||
name|V_MOVE
operator||
name|VM_LMODE
operator||
name|VM_RCM_SET
block|,
literal|"'['a-z]"
block|,
literal|" ' move to mark (to first non-blank)"
block|}
block|,
comment|/* 050   ( */
block|{
name|v_sentenceb
block|,
name|V_ABS
operator||
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_CUTREQ
operator||
name|VM_RCM_SET
block|,
literal|"[count]("
block|,
literal|" ( move back sentence"
block|}
block|,
comment|/* 051   ) */
block|{
name|v_sentencef
block|,
name|V_ABS
operator||
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_CUTREQ
operator||
name|VM_RCM_SET
block|,
literal|"[count])"
block|,
literal|" ) move forward sentence"
block|}
block|,
comment|/* 052   * */
block|{
name|NULL
block|}
block|,
comment|/* 053   + */
block|{
name|v_down
block|,
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_LMODE
operator||
name|VM_RCM_SETFNB
block|,
literal|"[count]+"
block|,
literal|" + move down by lines (to first non-blank)"
block|}
block|,
comment|/* 054   , */
block|{
name|v_chrrepeat
block|,
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_RCM_SET
block|,
literal|"[count],"
block|,
literal|" , reverse last F, f, T or t search"
block|}
block|,
comment|/* 055   - */
block|{
name|v_up
block|,
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_LMODE
operator||
name|VM_RCM_SETFNB
block|,
literal|"[count]-"
block|,
literal|" - move up by lines (to first non-blank)"
block|}
block|,
comment|/* 056   . */
block|{
name|NULL
block|,
literal|0
block|,
literal|"."
block|,
literal|" . repeat the last command"
block|}
block|,
comment|/* 057   / */
block|{
name|v_searchf
block|,
name|V_ABS_C
operator||
name|V_MOVE
operator||
name|VM_CUTREQ
operator||
name|VM_RCM_SET
block|,
literal|"/RE[/ offset]"
block|,
literal|" / search forward"
block|}
block|,
comment|/* 060   0 */
block|{
name|v_zero
block|,
name|V_MOVE
operator||
name|VM_RCM_SET
block|,
literal|"0"
block|,
literal|" 0 move to first character"
block|}
block|,
comment|/* 061   1 */
block|{
name|NULL
block|}
block|,
comment|/* 062   2 */
block|{
name|NULL
block|}
block|,
comment|/* 063   3 */
block|{
name|NULL
block|}
block|,
comment|/* 064   4 */
block|{
name|NULL
block|}
block|,
comment|/* 065   5 */
block|{
name|NULL
block|}
block|,
comment|/* 066   6 */
block|{
name|NULL
block|}
block|,
comment|/* 067   7 */
block|{
name|NULL
block|}
block|,
comment|/* 070   8 */
block|{
name|NULL
block|}
block|,
comment|/* 071   9 */
block|{
name|NULL
block|}
block|,
comment|/* 072   : */
block|{
name|v_ex
block|,
literal|0
block|,
literal|":command [| command] ..."
block|,
literal|" : ex command"
block|}
block|,
comment|/* 073   ; */
block|{
name|v_chrepeat
block|,
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_RCM_SET
block|,
literal|"[count];"
block|,
literal|" ; repeat last F, f, T or t search"
block|}
block|,
comment|/* 074< */
block|{
name|v_shiftl
block|,
name|V_CNT
operator||
name|V_DOT
operator||
name|V_MOTION
operator||
name|VM_RCM_SET
block|,
literal|"[count]<[count]motion"
block|,
literal|"< shift lines left to motion"
block|}
block|,
comment|/* 075   = */
block|{
name|NULL
block|}
block|,
comment|/* 076> */
block|{
name|v_shiftr
block|,
name|V_CNT
operator||
name|V_DOT
operator||
name|V_MOTION
operator||
name|VM_RCM_SET
block|,
literal|"[count]>[count]motion"
block|,
literal|"> shift lines right to motion"
block|}
block|,
comment|/* 077   ? */
block|{
name|v_searchb
block|,
name|V_ABS_C
operator||
name|V_MOVE
operator||
name|VM_CUTREQ
operator||
name|VM_RCM_SET
block|,
literal|"?RE[? offset]"
block|,
literal|" ? search backward"
block|}
block|,
comment|/* 100   @ */
block|{
name|v_at
block|,
name|V_CNT
operator||
name|V_RBUF
operator||
name|VM_RCM_SET
block|,
literal|"@buffer"
block|,
literal|" @ execute buffer"
block|}
block|,
comment|/* 101   A */
block|{
name|v_iA
block|,
name|V_CNT
operator||
name|V_DOT
operator||
name|VM_RCM_SET
block|,
literal|"[count]A"
block|,
literal|" A append to the line"
block|}
block|,
comment|/* 102   B */
block|{
name|v_wordB
block|,
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_RCM_SET
block|,
literal|"[count]B"
block|,
literal|" B move back bigword"
block|}
block|,
comment|/* 103   C */
block|{
name|NULL
block|,
literal|0
block|,
literal|"[buffer][count]C"
block|,
literal|" C change to end-of-line"
block|}
block|,
comment|/* 104   D */
block|{
name|NULL
block|,
literal|0
block|,
literal|"[buffer]D"
block|,
literal|" D delete to end-of-line"
block|}
block|,
comment|/* 105   E */
block|{
name|v_wordE
block|,
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_RCM_SET
block|,
literal|"[count]E"
block|,
literal|" E move to end of bigword"
block|}
block|,
comment|/* 106   F */
block|{
name|v_chF
block|,
name|V_CHAR
operator||
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_RCM_SET
block|,
literal|"[count]F character"
block|,
literal|" F character in line backward search"
block|}
block|,
comment|/* 107   G */
block|{
name|v_lgoto
block|,
name|V_ABS_L
operator||
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_LMODE
operator||
name|VM_RCM_SETFNB
block|,
literal|"[count]G"
block|,
literal|" G move to line"
block|}
block|,
comment|/* 110   H */
block|{
name|v_home
block|,
name|V_ABS_L
operator||
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_LMODE
operator||
name|VM_RCM_SETNNB
block|,
literal|"[count]H"
block|,
literal|" H move to count lines from screen top"
block|}
block|,
comment|/* 111   I */
block|{
name|v_iI
block|,
name|V_CNT
operator||
name|V_DOT
operator||
name|VM_RCM_SET
block|,
literal|"[count]I"
block|,
literal|" I insert before first nonblank"
block|}
block|,
comment|/* 112   J */
block|{
name|v_join
block|,
name|V_CNT
operator||
name|V_DOT
operator||
name|VM_RCM_SET
block|,
literal|"[count]J"
block|,
literal|" J join lines"
block|}
block|,
comment|/* 113   K */
block|{
name|NULL
block|}
block|,
comment|/* 114   L */
block|{
name|v_bottom
block|,
name|V_ABS_L
operator||
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_LMODE
operator||
name|VM_RCM_SETNNB
block|,
literal|"[count]L"
block|,
literal|" L move to screen bottom"
block|}
block|,
comment|/* 115   M */
block|{
name|v_middle
block|,
name|V_ABS_L
operator||
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_LMODE
operator||
name|VM_RCM_SETNNB
block|,
literal|"M"
block|,
literal|" M move to screen middle"
block|}
block|,
comment|/* 116   N */
block|{
name|v_searchN
block|,
name|V_ABS_C
operator||
name|V_MOVE
operator||
name|VM_CUTREQ
operator||
name|VM_RCM_SET
block|,
literal|"n"
block|,
literal|" N reverse last search"
block|}
block|,
comment|/* 117   O */
block|{
name|v_iO
block|,
name|V_CNT
operator||
name|V_DOT
operator||
name|VM_RCM_SET
block|,
literal|"[count]O"
block|,
literal|" O insert above line"
block|}
block|,
comment|/* 120   P */
block|{
name|v_Put
block|,
name|V_CNT
operator||
name|V_DOT
operator||
name|V_OBUF
operator||
name|VM_RCM_SET
block|,
literal|"[buffer]P"
block|,
literal|" P insert before cursor from buffer"
block|}
block|,
comment|/* 121   Q */
block|{
name|v_exmode
block|,
literal|0
block|,
literal|"Q"
block|,
literal|" Q switch to ex mode"
block|}
block|,
comment|/* 122   R */
block|{
name|v_Replace
block|,
name|V_CNT
operator||
name|V_DOT
operator||
name|VM_RCM_SET
block|,
literal|"[count]R"
block|,
literal|" R replace characters"
block|}
block|,
comment|/* 123   S */
block|{
name|NULL
block|,
literal|0
block|,
literal|"[buffer][count]S"
block|,
literal|" S substitute for the line(s)"
block|}
block|,
comment|/* 124   T */
block|{
name|v_chT
block|,
name|V_CHAR
operator||
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_RCM_SET
block|,
literal|"[count]T character"
block|,
literal|" T before character in line backward search"
block|}
block|,
comment|/* 125   U */
block|{
name|v_Undo
block|,
name|VM_RCM_SET
block|,
literal|"U"
block|,
literal|" U Restore the current line"
block|}
block|,
comment|/* 126   V */
block|{
name|NULL
block|}
block|,
comment|/* 127   W */
block|{
name|v_wordW
block|,
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_RCM_SET
block|,
literal|"[count]W"
block|,
literal|" W move to next bigword"
block|}
block|,
comment|/* 130   X */
block|{
name|v_Xchar
block|,
name|V_CNT
operator||
name|V_DOT
operator||
name|V_OBUF
operator||
name|VM_RCM_SET
block|,
literal|"[buffer][count]X"
block|,
literal|" X delete character before cursor"
block|}
block|,
comment|/* 131   Y */
block|{
name|NULL
block|,
literal|0
block|,
literal|"[buffer][count]Y"
block|,
literal|" Y copy line"
block|}
block|,
comment|/* 132   Z */
block|{
name|v_zexit
block|,
literal|0
block|,
literal|"ZZ"
block|,
literal|"ZZ save file and exit"
block|}
block|,
comment|/* 133   [ */
block|{
name|v_sectionb
block|,
name|V_ABS
operator||
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_RCM_SET
block|,
literal|"[["
block|,
literal|"[[ move back section"
block|}
block|,
comment|/* 134   \ */
block|{
name|NULL
block|}
block|,
comment|/* 135   ] */
block|{
name|v_sectionf
block|,
name|V_ABS
operator||
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_RCM_SET
block|,
literal|"]]"
block|,
literal|"]] move forward section"
block|}
block|,
comment|/* 136   ^ */
comment|/* 	 * DON'T set the VM_RCM_SETFNB flag, the function has to do the work 	 * anyway, in case it's a motion component.  DO set VM_RCM_SET, so 	 * that any motion that's part of a command is preserved. 	 */
block|{
name|v_first
block|,
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_RCM_SET
block|,
literal|"^"
block|,
literal|" ^ move to first non-blank"
block|}
block|,
comment|/* 137   _ */
comment|/* 	 * Needs both to set the VM_RCM_SETFNB flag, and to do the work 	 * in the function, in case it's a delete. 	 */
block|{
name|v_cfirst
block|,
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_RCM_SETFNB
block|,
literal|"_"
block|,
literal|" _ move to first non-blank"
block|}
block|,
comment|/* 140   ` */
block|{
name|v_bmark
block|,
name|V_ABS_C
operator||
name|V_CHAR
operator||
name|V_MOVE
operator||
name|VM_CUTREQ
operator||
name|VM_RCM_SET
block|,
literal|"`[`a-z]"
block|,
literal|" ` move to mark"
block|}
block|,
comment|/* 141   a */
block|{
name|v_ia
block|,
name|V_CNT
operator||
name|V_DOT
operator||
name|VM_RCM_SET
block|,
literal|"[count]a"
block|,
literal|" a append after cursor"
block|}
block|,
comment|/* 142   b */
block|{
name|v_wordb
block|,
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_RCM_SET
block|,
literal|"[count]b"
block|,
literal|" b move back word"
block|}
block|,
comment|/* 143   c */
block|{
name|v_change
block|,
name|V_CNT
operator||
name|V_DOT
operator||
name|V_MOTION
operator||
name|V_OBUF
operator||
name|VM_RCM_SET
block|,
literal|"[buffer][count]c[count]motion"
block|,
literal|" c change to motion"
block|}
block|,
comment|/* 144   d */
block|{
name|v_delete
block|,
name|V_CNT
operator||
name|V_DOT
operator||
name|V_MOTION
operator||
name|V_OBUF
operator||
name|VM_RCM_SET
block|,
literal|"[buffer][count]d[count]motion"
block|,
literal|" d delete to motion"
block|}
block|,
comment|/* 145   e */
block|{
name|v_worde
block|,
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_RCM_SET
block|,
literal|"[count]e"
block|,
literal|" e move to end of word"
block|}
block|,
comment|/* 146   f */
block|{
name|v_chf
block|,
name|V_CHAR
operator||
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_RCM_SET
block|,
literal|"[count]f character"
block|,
literal|" f character in line forward search"
block|}
block|,
comment|/* 147   g */
block|{
name|NULL
block|}
block|,
comment|/* 150   h */
block|{
name|v_left
block|,
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_RCM_SET
block|,
literal|"[count]h"
block|,
literal|" h move left by columns"
block|}
block|,
comment|/* 151   i */
block|{
name|v_ii
block|,
name|V_CNT
operator||
name|V_DOT
operator||
name|VM_RCM_SET
block|,
literal|"[count]i"
block|,
literal|" i insert before cursor"
block|}
block|,
comment|/* 152   j */
block|{
name|v_down
block|,
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_LMODE
operator||
name|VM_RCM
block|,
literal|"[count]j"
block|,
literal|" j move down by lines"
block|}
block|,
comment|/* 153   k */
block|{
name|v_up
block|,
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_LMODE
operator||
name|VM_RCM
block|,
literal|"[count]k"
block|,
literal|" k move up by lines"
block|}
block|,
comment|/* 154   l */
block|{
name|v_right
block|,
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_RCM_SET
block|,
literal|"[count]l"
block|,
literal|" l move right by columns"
block|}
block|,
comment|/* 155   m */
block|{
name|v_mark
block|,
name|V_CHAR
block|,
literal|"m[a-z]"
block|,
literal|" m set mark"
block|}
block|,
comment|/* 156   n */
block|{
name|v_searchn
block|,
name|V_ABS_C
operator||
name|V_MOVE
operator||
name|VM_CUTREQ
operator||
name|VM_RCM_SET
block|,
literal|"n"
block|,
literal|" n repeat last search"
block|}
block|,
comment|/* 157   o */
block|{
name|v_io
block|,
name|V_CNT
operator||
name|V_DOT
operator||
name|VM_RCM_SET
block|,
literal|"[count]o"
block|,
literal|" o append after line"
block|}
block|,
comment|/* 160   p */
block|{
name|v_put
block|,
name|V_CNT
operator||
name|V_DOT
operator||
name|V_OBUF
operator||
name|VM_RCM_SET
block|,
literal|"[buffer]p"
block|,
literal|" p insert after cursor from buffer"
block|}
block|,
comment|/* 161   q */
block|{
name|NULL
block|}
block|,
comment|/* 162   r */
block|{
name|v_replace
block|,
name|V_CNT
operator||
name|V_DOT
operator||
name|VM_RCM_SET
block|,
literal|"[count]r character"
block|,
literal|" r replace character"
block|}
block|,
comment|/* 163   s */
block|{
name|v_subst
block|,
name|V_CNT
operator||
name|V_DOT
operator||
name|V_OBUF
operator||
name|VM_RCM_SET
block|,
literal|"[buffer][count]s"
block|,
literal|" s substitute character"
block|}
block|,
comment|/* 164   t */
block|{
name|v_cht
block|,
name|V_CHAR
operator||
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_RCM_SET
block|,
literal|"[count]t character"
block|,
literal|" t before character in line forward search"
block|}
block|,
comment|/* 165   u */
comment|/* 	 * DON'T set the V_DOT flag, it' more complicated than that. 	 * See vi/vi.c for details. 	 */
block|{
name|v_undo
block|,
name|VM_RCM_SET
block|,
literal|"u"
block|,
literal|" u undo last change"
block|}
block|,
comment|/* 166   v */
block|{
name|NULL
block|}
block|,
comment|/* 167   w */
block|{
name|v_wordw
block|,
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_RCM_SET
block|,
literal|"[count]w"
block|,
literal|" w move to next word"
block|}
block|,
comment|/* 170   x */
block|{
name|v_xchar
block|,
name|V_CNT
operator||
name|V_DOT
operator||
name|V_OBUF
operator||
name|VM_RCM_SET
block|,
literal|"[buffer][count]x"
block|,
literal|" x delete character"
block|}
block|,
comment|/* 171   y */
block|{
name|v_yank
block|,
name|V_CNT
operator||
name|V_DOT
operator||
name|V_MOTION
operator||
name|V_OBUF
operator||
name|VM_RCM_SET
block|,
literal|"[buffer][count]y[count]motion"
block|,
literal|" y copy text to motion into a cut buffer"
block|}
block|,
comment|/* 172   z */
comment|/* 	 * DON'T set the V_CHAR flag, the char isn't required, 	 * so it's handled specially in getcmd(). 	 */
block|{
name|v_z
block|,
name|V_ABS_L
operator||
name|V_CNT
operator||
name|VM_RCM_SETFNB
block|,
literal|"[line]z[window_size][-|.|+|^|<CR>]"
block|,
literal|" z reposition the screen"
block|}
block|,
comment|/* 173   { */
block|{
name|v_paragraphb
block|,
name|V_ABS
operator||
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_CUTREQ
operator||
name|VM_RCM_SET
block|,
literal|"[count]{"
block|,
literal|" { move back paragraph"
block|}
block|,
comment|/* 174   | */
block|{
name|v_ncol
block|,
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_RCM_SET
block|,
literal|"[count]|"
block|,
literal|" | move to column"
block|}
block|,
comment|/* 175   } */
block|{
name|v_paragraphf
block|,
name|V_ABS
operator||
name|V_CNT
operator||
name|V_MOVE
operator||
name|VM_CUTREQ
operator||
name|VM_RCM_SET
block|,
literal|"[count]}"
block|,
literal|" } move forward paragraph"
block|}
block|,
comment|/* 176   ~ */
block|{
name|v_ulcase
block|,
name|V_CNT
operator||
name|V_DOT
operator||
name|VM_RCM_SET
block|,
literal|"[count]~"
block|,
literal|" ~ reverse case"
block|}
block|, }
decl_stmt|;
end_decl_stmt

end_unit

