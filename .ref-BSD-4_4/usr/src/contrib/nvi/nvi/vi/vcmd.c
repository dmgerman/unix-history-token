begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)vcmd.c	8.1 (Berkeley) 6/9/93"
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
file|"vi.h"
end_include

begin_include
include|#
directive|include
file|"vcmd.h"
end_include

begin_comment
comment|/*  * This array maps keystrokes to vi command functions.  */
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
name|V_KEYW
operator||
name|V_RCM_SET
block|,
literal|"search forward for cursor word: [count]^A"
block|}
block|,
comment|/* 002  ^B */
block|{
name|v_pageup
block|,
name|V_ABS
operator||
name|V_CNT
block|,
literal|"page up by screens: [count]^B"
block|}
block|,
comment|/* 003  ^C */
block|{
name|NULL
block|,
literal|0
block|,
literal|"interrupt a search: ^C"
block|}
block|,
comment|/* 004  ^D */
block|{
name|v_hpagedown
block|,
name|V_ABS
operator||
name|V_CNT
block|,
literal|"page down by half screens (set count): [count]^D"
block|}
block|,
comment|/* 005  ^E */
block|{
name|v_linedown
block|,
name|V_CNT
block|,
literal|"page down by lines: [count]^E"
block|}
block|,
comment|/* 006  ^F */
block|{
name|v_pagedown
block|,
name|V_ABS
operator||
name|V_CNT
block|,
literal|"page down by screens: [count]^F"
block|}
block|,
comment|/* 007  ^G */
block|{
name|v_status
block|,
literal|0
block|,
literal|"file status: ^G"
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
name|V_RCM_SET
block|,
literal|"move left by columns: [count]^H"
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
name|V_LMODE
operator||
name|V_MOVE
operator||
name|V_RCM
block|,
literal|"move down by lines: [count]^J"
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
literal|"redraw screen: ^L"
block|}
block|,
comment|/* 015  ^M */
block|{
name|v_down
block|,
name|V_CNT
operator||
name|V_LMODE
operator||
name|V_MOVE
operator||
name|V_RCM_SETFNB
block|,
literal|"move down by lines (first non-blank): [count]^M"
block|}
block|,
comment|/* 016  ^N */
block|{
name|v_down
block|,
name|V_CNT
operator||
name|V_LMODE
operator||
name|V_MOVE
operator||
name|V_RCM
block|,
literal|"move down by lines: [count]^N"
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
name|V_LMODE
operator||
name|V_MOVE
operator||
name|V_RCM
block|,
literal|"move up by lines: [count]^P"
block|}
block|,
comment|/* 021  ^Q -- not available, used for hardware flow control. */
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
literal|"redraw screen: ^R"
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
name|V_RCM_SET
block|,
literal|"tag pop: ^T"
block|}
block|,
comment|/* 025  ^U */
block|{
name|v_hpageup
block|,
name|V_ABS
operator||
name|V_CNT
block|,
literal|"half page up (set count): [count]^U"
block|}
block|,
comment|/* 026  ^V */
block|{
name|NULL
block|,
literal|0
block|,
literal|"insert a literal character: ^V"
block|}
block|,
comment|/* 027  ^W */
block|{
name|v_window
block|,
literal|0
block|,
literal|"switch windows: ^W"
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
literal|"page up by lines: [count]^Y"
block|}
block|,
comment|/* 032  ^Z */
block|{
name|v_stop
block|,
literal|0
block|,
literal|"suspend: ^Z"
block|}
block|,
comment|/* 033  ^[ */
block|{
name|NULL
block|,
literal|0
block|,
literal|"return to command mode: ^["
block|}
block|,
comment|/* 034  ^\ */
block|{
name|NULL
block|}
block|,
comment|/* 035  ^] */
block|{
name|v_tagpush
block|,
name|V_KEYW
operator||
name|V_RCM_SET
block|,
literal|"tag push cursor word: ^]"
block|}
block|,
comment|/* 036  ^^ */
block|{
name|v_switch
block|,
literal|0
block|,
literal|"change to previous file: ^^"
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
name|V_RCM_SET
block|,
literal|"move right by columns: [count]' '"
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
name|V_RCM_SET
block|,
literal|"filter through command(s): [count]![count]motion command(s)"
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
name|V_KEYNUM
operator||
name|V_RCM_SET
block|,
literal|"number increment/decrement: [count]#[#+-]"
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
name|V_RCM_SETLAST
block|,
literal|"move to last column: [count]$"
block|}
block|,
comment|/* 045   % */
block|{
name|v_match
block|,
name|V_ABS
operator||
name|V_MOVE
operator||
name|V_RCM_SET
block|,
literal|"move to match: %"
block|}
block|,
comment|/* 046& */
block|{
name|v_again
block|,
literal|0
block|,
literal|"repeat substitution:&"
block|}
block|,
comment|/* 047   ' */
block|{
name|v_gomark
block|,
name|V_ABS
operator||
name|V_CHAR
operator||
name|V_LMODE
operator||
name|V_MOVE
operator||
name|V_RCM_SETFNB
block|,
literal|"move to mark (first non-blank): '['a-z]"
block|}
block|,
comment|/* 050   ( */
block|{
name|v_sentenceb
block|,
name|V_CNT
operator||
name|V_MOVE
operator||
name|V_RCM_SET
block|,
literal|"move back sentence: [count]("
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
name|V_RCM_SET
block|,
literal|"move forward sentence: [count])"
block|}
block|,
comment|/* 052   * */
block|{
name|v_errlist
block|,
literal|0
block|,
literal|"step through compile errors: *"
block|}
block|,
comment|/* 053   + */
block|{
name|v_down
block|,
name|V_CNT
operator||
name|V_LMODE
operator||
name|V_MOVE
operator||
name|V_RCM_SETFNB
block|,
literal|"move down by lines (first non-blank): [count]+"
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
name|V_RCM_SET
block|,
literal|"reverse last F, f, T or t search: [count],"
block|}
block|,
comment|/* 055   - */
block|{
name|v_up
block|,
name|V_CNT
operator||
name|V_LMODE
operator||
name|V_MOVE
operator||
name|V_RCM_SETFNB
block|,
literal|"move up by lines (first non-blank): [count]-"
block|}
block|,
comment|/* 056   . */
block|{
name|NULL
block|,
literal|0
block|,
literal|"repeat the last command: ."
block|}
block|,
comment|/* 057   / */
block|{
name|v_searchf
block|,
name|V_ABS
operator||
name|V_MOVE
operator||
name|V_RCM_SET
block|,
literal|"search forward: /RE"
block|}
block|,
comment|/* 060   0 */
block|{
name|v_zero
block|,
name|V_MOVE
operator||
name|V_RCM_SET
block|,
literal|"move to first character: 0"
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
literal|"ex command: :command [| command] ..."
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
name|V_RCM_SET
block|,
literal|"repeat last F, f, T or t search: [count];"
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
name|V_RCM_SET
block|,
literal|"shift lines left: [count]<[count]motion"
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
name|V_RCM_SET
block|,
literal|"shift lines right: [count]>[count]motion"
block|}
block|,
comment|/* 077   ? */
block|{
name|v_searchb
block|,
name|V_ABS
operator||
name|V_MOVE
operator||
name|V_RCM_SET
block|,
literal|"search backward: /RE"
block|}
block|,
comment|/* 100   @ */
block|{
name|v_at
block|,
name|V_RBUF
operator||
name|V_RCM_SET
block|,
literal|"execute buffer: @buffer"
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
name|V_RCM_SET
block|,
literal|"append to line: [count]A"
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
name|V_RCM_SET
block|,
literal|"move back bigword: [count]B"
block|}
block|,
comment|/* 103   C */
block|{
name|v_Change
block|,
name|V_CNT
operator||
name|V_DOT
operator||
name|V_OBUF
operator||
name|V_RCM_SET
block|,
literal|"change to end-of-line: [buffer][count]C"
block|}
block|,
comment|/* 104   D */
block|{
name|v_Delete
block|,
name|V_CNT
operator||
name|V_DOT
operator||
name|V_OBUF
operator||
name|V_RCM_SET
block|,
literal|"delete to end-of-line: [buffer][count]D"
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
name|V_RCM_SET
block|,
literal|"move to end of bigword: [count]E"
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
name|V_RCM_SET
block|,
literal|"character in line backward search: [count]F character"
block|}
block|,
comment|/* 107   G */
block|{
name|v_lgoto
block|,
name|V_ABS
operator||
name|V_CNT
operator||
name|V_LMODE
operator||
name|V_MOVE
operator||
name|V_RCM_SETFNB
block|,
literal|"move to line: [count]G"
block|}
block|,
comment|/* 110   H */
block|{
name|v_home
block|,
name|V_CNT
operator||
name|V_LMODE
operator||
name|V_MOVE
operator||
name|V_RCM_SETFNB
block|,
literal|"move to count lines from screen top: [count]H"
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
name|V_RCM_SET
block|,
literal|"insert at line beginning: [count]I"
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
name|V_RCM_SET
block|,
literal|"join lines: [count]J"
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
name|V_CNT
operator||
name|V_LMODE
operator||
name|V_MOVE
operator||
name|V_RCM_SETFNB
block|,
literal|"move to screen bottom: [count]L"
block|}
block|,
comment|/* 115   M */
block|{
name|v_middle
block|,
name|V_LMODE
operator||
name|V_MOVE
operator||
name|V_RCM_SETFNB
block|,
literal|"move to screen middle: M"
block|}
block|,
comment|/* 116   N */
block|{
name|v_searchN
block|,
name|V_ABS
operator||
name|V_MOVE
operator||
name|V_RCM_SET
block|,
literal|"reverse last search: n"
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
name|V_RCM_SET
block|,
literal|"insert above line: [count]O"
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
name|V_RCM_SET
block|,
literal|"insert before cursor from buffer: [buffer]P"
block|}
block|,
comment|/* 121   Q */
block|{
name|v_exmode
block|,
literal|0
block|,
literal|"switch to ex mode: Q"
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
name|V_RCM_SET
block|,
literal|"replace characters: [count]R"
block|}
block|,
comment|/* 123   S */
block|{
name|v_change
block|,
name|V_CNT
operator||
name|V_DOT
operator||
name|V_OBUF
operator||
name|V_RCM_SET
block|,
literal|"substitute lines: [buffer][count]S"
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
name|V_RCM_SET
block|,
literal|"before character in line backward search: [count]T character"
block|}
block|,
comment|/* 125   U */
block|{
name|v_Undo
block|,
name|V_RCM_SET
block|,
literal|"undo current line: U"
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
name|V_RCM_SET
block|,
literal|"move to next bigword: [count]W"
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
name|V_RCM_SET
block|,
literal|"delete character before cursor: [buffer][count]X"
block|}
block|,
comment|/* 131   Y */
block|{
name|v_Yank
block|,
name|V_CNT
operator||
name|V_LMODE
operator||
name|V_OBUF
block|,
literal|"copy line: [buffer][count]Y"
block|}
block|,
comment|/* 132   Z */
block|{
name|v_exit
block|,
literal|0
block|,
literal|"save file and exit: ZZ"
block|}
block|,
comment|/* 133   [ */
block|{
name|v_sectionb
block|,
name|V_ABS
operator||
name|V_LMODE
operator||
name|V_MOVE
operator||
name|V_RCM_SET
block|,
literal|"move back section: ]]"
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
name|V_LMODE
operator||
name|V_MOVE
operator||
name|V_RCM_SET
block|,
literal|"move forward section: [["
block|}
block|,
comment|/* 136   ^ */
block|{
name|v_first
block|,
name|V_MOVE
operator||
name|V_RCM_SETFNB
block|,
literal|"move to first non-blank: ^"
block|}
block|,
comment|/* 137   _ */
block|{
name|v_first
block|,
name|V_MOVE
operator||
name|V_RCM_SET
block|,
literal|"move to first non-blank: _"
block|}
block|,
comment|/* 140   ` */
block|{
name|v_gomark
block|,
name|V_ABS
operator||
name|V_CHAR
operator||
name|V_MOVE
operator||
name|V_RCM_SET
block|,
literal|"move to mark: `[`a-z]"
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
name|V_RCM_SET
block|,
literal|"append after cursor: [count]a"
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
name|V_RCM_SET
block|,
literal|"move back word: [count]b"
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
name|V_RCM_SET
operator||
name|VC_C
block|,
literal|"change: [buffer][count]c[count]motion"
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
name|V_RCM_SET
operator||
name|VC_D
block|,
literal|"delete: [buffer][count]d[count]motion"
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
name|V_RCM_SET
block|,
literal|"move to end of word: [count]e"
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
name|V_RCM_SET
block|,
literal|"character in line forward search: [count]f character"
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
name|V_RCM_SET
block|,
literal|"move left by columns: [count]h"
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
name|V_RCM_SET
block|,
literal|"insert before cursor: [count]i"
block|}
block|,
comment|/* 152   j */
block|{
name|v_down
block|,
name|V_CNT
operator||
name|V_LMODE
operator||
name|V_MOVE
operator||
name|V_RCM
block|,
literal|"move down by lines: [count]j"
block|}
block|,
comment|/* 153   k */
block|{
name|v_up
block|,
name|V_CNT
operator||
name|V_LMODE
operator||
name|V_MOVE
operator||
name|V_RCM
block|,
literal|"move up by lines: [count]k"
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
name|V_RCM_SET
block|,
literal|"move right by columns: [count]l"
block|}
block|,
comment|/* 155   m */
block|{
name|v_mark
block|,
name|V_CHAR
block|,
literal|"set mark: m[a-z]"
block|}
block|,
comment|/* 156   n */
block|{
name|v_searchn
block|,
name|V_ABS
operator||
name|V_MOVE
operator||
name|V_RCM_SET
block|,
literal|"repeat last search: n"
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
name|V_RCM_SET
block|,
literal|"append after line: [count]o"
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
name|V_RCM_SET
block|,
literal|"insert after cursor from buffer: [buffer]P"
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
name|V_CHAR
operator||
name|V_CNT
operator||
name|V_DOT
operator||
name|V_RCM_SET
block|,
literal|"replace character: [count]r character"
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
name|V_RCM_SET
block|,
literal|"substitute character: [buffer][count]s"
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
name|V_RCM_SET
block|,
literal|"before character in line forward search: [count]t character"
block|}
block|,
comment|/* 165   u */
block|{
name|v_undo
block|,
name|V_RCM_SET
block|,
literal|"undo last change: u"
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
name|V_RCM_SET
block|,
literal|"move to next word: [count]w"
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
name|V_RCM_SET
block|,
literal|"delete character: [buffer][count]x"
block|}
block|,
comment|/* 171   y */
block|{
name|v_yank
block|,
name|V_CNT
operator||
name|V_MOTION
operator||
name|V_OBUF
operator||
name|VC_Y
block|,
literal|"copy text: [buffer][count]y[count]motion"
block|}
block|,
comment|/* 172   z */
comment|/* 	 * DON'T set the V_CHAR flag, the char isn't required, 	 * so it's handled specially in getcmd(). 	 */
block|{
name|v_z
block|,
name|V_CNT
operator||
name|V_RCM_SETFNB
block|,
literal|"redraw window: [line]z[window_size][.-<CR>]"
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
name|V_LMODE
operator||
name|V_MOVE
operator||
name|V_RCM_SET
block|,
literal|"move back paragraph: [count]{"
block|}
block|,
comment|/* 174   | */
block|{
name|v_ncol
block|,
name|V_ABS
operator||
name|V_CNT
operator||
name|V_MOVE
operator||
name|V_RCM_SET
block|,
literal|"move to column: [count]|"
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
name|V_LMODE
operator||
name|V_MOVE
operator||
name|V_RCM_SET
block|,
literal|"move forward paragraph: [count]}"
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
name|V_RCM_SET
block|,
literal|"reverse case: [count]~"
block|}
block|, }
decl_stmt|;
end_decl_stmt

end_unit

