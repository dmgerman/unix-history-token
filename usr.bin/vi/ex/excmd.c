begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)excmd.c	8.41 (Berkeley) 3/14/94"
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
file|<queue.h>
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
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_include
include|#
directive|include
file|"vi.h"
end_include

begin_include
include|#
directive|include
file|"excmd.h"
end_include

begin_comment
comment|/*  * This array maps ex command names to command functions.  *  * The order in which command names are listed below is important --  * ambiguous abbreviations are resolved to be the first possible match,  * e.g. "r" means "read", not "rewind", because "read" is listed before  * "rewind".  *  * The syntax of the ex commands is unbelievably irregular, and a special  * case from beginning to end.  Each command has an associated "syntax  * script" which describes the "arguments" that are possible.  The script  * syntax is as follows:  *  *	!		-- ! flag  *	1		-- flags: [+-]*[pl#][+-]*  *	2		-- flags: [-.+^]  *	3		-- flags: [-.+^=]  *	b		-- buffer  *	c[01+a]		-- count (0-N, 1-N, signed 1-N, address offset)  *	f[N#][or]	-- file (a number or N, optional or required)  *	l		-- line  *	S		-- string with file name expansion  *	s		-- string  *	W		-- word string  *	w[N#][or]	-- word (a number or N, optional or required)  */
end_comment

begin_decl_stmt
name|EXCMDLIST
specifier|const
name|cmds
index|[]
init|=
block|{
comment|/* C_SCROLL */
block|{
literal|"\004"
block|,
name|ex_pr
block|,
name|E_ADDR2
operator||
name|E_NORC
block|,
literal|""
block|,
literal|"^D"
block|,
literal|"scroll lines"
block|}
block|,
comment|/* C_BANG */
block|{
literal|"!"
block|,
name|ex_bang
block|,
name|E_ADDR2_NONE
operator||
name|E_NORC
block|,
literal|"S"
block|,
literal|"[line [,line]] ! command"
block|,
literal|"filter lines through commands or run commands"
block|}
block|,
comment|/* C_HASH */
block|{
literal|"#"
block|,
name|ex_number
block|,
name|E_ADDR2
operator||
name|E_F_PRCLEAR
operator||
name|E_NORC
operator||
name|E_SETLAST
block|,
literal|"ca1"
block|,
literal|"[line [,line]] # [count] [l]"
block|,
literal|"display numbered lines"
block|}
block|,
comment|/* C_SUBAGAIN */
block|{
literal|"&"
block|,
name|ex_subagain
block|,
name|E_ADDR2
operator||
name|E_NORC
block|,
literal|"s"
block|,
literal|"[line [,line]]& [cgr] [count] [#lp]"
block|,
literal|"repeat the last subsitution"
block|}
block|,
comment|/* C_STAR */
block|{
literal|"*"
block|,
name|ex_at
block|,
literal|0
block|,
literal|"b"
block|,
literal|"* [buffer]"
block|,
literal|"execute a buffer"
block|}
block|,
comment|/* C_SHIFTL */
block|{
literal|"<"
block|,
name|ex_shiftl
block|,
name|E_ADDR2
operator||
name|E_AUTOPRINT
operator||
name|E_NORC
block|,
literal|"ca1"
block|,
literal|"[line [,line]]<[<...] [count] [flags]"
block|,
literal|"shift lines left"
block|}
block|,
comment|/* C_EQUAL */
block|{
literal|"="
block|,
name|ex_equal
block|,
name|E_ADDR1
operator||
name|E_NORC
block|,
literal|"1"
block|,
literal|"[line] = [flags]"
block|,
literal|"display line number"
block|}
block|,
comment|/* C_SHIFTR */
block|{
literal|">"
block|,
name|ex_shiftr
block|,
name|E_ADDR2
operator||
name|E_AUTOPRINT
operator||
name|E_NORC
block|,
literal|"ca1"
block|,
literal|"[line [,line]]>[>...] [count] [flags]"
block|,
literal|"shift lines right"
block|}
block|,
comment|/* C_AT */
block|{
literal|"@"
block|,
name|ex_at
block|,
literal|0
block|,
literal|"b"
block|,
literal|"@ [buffer]"
block|,
literal|"execute a buffer"
block|}
block|,
comment|/* C_APPEND */
block|{
literal|"append"
block|,
name|ex_append
block|,
name|E_ADDR1
operator||
name|E_NORC
operator||
name|E_ZERO
operator||
name|E_ZERODEF
block|,
literal|"!"
block|,
literal|"[line] a[ppend][!]"
block|,
literal|"append input to a line"
block|}
block|,
comment|/* C_ABBR */
block|{
literal|"abbreviate"
block|,
name|ex_abbr
block|,
name|E_NOGLOBAL
block|,
literal|"W"
block|,
literal|"ab[brev] word replace"
block|,
literal|"specify an input abbreviation"
block|}
block|,
comment|/* C_ARGS */
block|{
literal|"args"
block|,
name|ex_args
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|""
block|,
literal|"ar[gs]"
block|,
literal|"display file argument list"
block|}
block|,
comment|/* C_BG */
block|{
literal|"bg"
block|,
name|ex_bg
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|""
block|,
literal|"bg"
block|,
literal|"background the current screen"
block|}
block|,
comment|/* C_CHANGE */
block|{
literal|"change"
block|,
name|ex_change
block|,
name|E_ADDR2
operator||
name|E_NORC
operator||
name|E_ZERODEF
block|,
literal|"!ca"
block|,
literal|"[line [,line]] c[hange][!] [count]"
block|,
literal|"change lines to input"
block|}
block|,
comment|/* C_CD */
block|{
literal|"cd"
block|,
name|ex_cd
block|,
name|E_NOGLOBAL
block|,
literal|"!f1o"
block|,
literal|"cd[!] [directory]"
block|,
literal|"change the current directory"
block|}
block|,
comment|/* C_CHDIR */
block|{
literal|"chdir"
block|,
name|ex_cd
block|,
name|E_NOGLOBAL
block|,
literal|"!f1o"
block|,
literal|"chd[ir][!] [directory]"
block|,
literal|"change the current directory"
block|}
block|,
comment|/* C_COPY */
block|{
literal|"copy"
block|,
name|ex_copy
block|,
name|E_ADDR2
operator||
name|E_AUTOPRINT
operator||
name|E_NORC
block|,
literal|"l1"
block|,
literal|"[line [,line]] co[py] line [flags]"
block|,
literal|"copy lines elsewhere in the file"
block|}
block|,
comment|/* C_DELETE */
block|{
literal|"delete"
block|,
name|ex_delete
block|,
name|E_ADDR2
operator||
name|E_AUTOPRINT
operator||
name|E_NORC
block|,
literal|"bca1"
block|,
literal|"[line [,line]] d[elete] [buffer] [count] [flags]"
block|,
literal|"delete lines from the file"
block|}
block|,
comment|/* C_DISPLAY */
block|{
literal|"display"
block|,
name|ex_display
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|"w1r"
block|,
literal|"display b[uffers] | s[creens] | t[ags]"
block|,
literal|"display buffers, screens or tags"
block|}
block|,
comment|/* C_DIGRAPH */
block|{
literal|"digraph"
block|,
name|ex_digraph
block|,
name|E_NOGLOBAL
operator||
name|E_NOPERM
operator||
name|E_NORC
block|,
literal|""
block|,
literal|"digraph"
block|,
literal|"specify digraphs (not implemented)"
block|}
block|,
comment|/* C_EDIT */
block|{
literal|"edit"
block|,
name|ex_edit
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|"!f1o"
block|,
literal|"e[dit][!] [+cmd] [file]"
block|,
literal|"begin editing another file"
block|}
block|,
comment|/* C_EX */
block|{
literal|"ex"
block|,
name|ex_edit
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|"!f1o"
block|,
literal|"ex[!] [+cmd] [file]"
block|,
literal|"begin editing another file"
block|}
block|,
comment|/* C_EXUSAGE */
block|{
literal|"exusage"
block|,
name|ex_usage
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|"w1o"
block|,
literal|"[exu]sage [command]"
block|,
literal|"display ex command usage statement"
block|}
block|,
comment|/* C_FILE */
block|{
literal|"file"
block|,
name|ex_file
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|"f1o"
block|,
literal|"f[ile] [name]"
block|,
literal|"display (and optionally set) file name"
block|}
block|,
comment|/* C_FG */
block|{
literal|"fg"
block|,
name|ex_fg
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|"f1o"
block|,
literal|"fg [file]"
block|,
literal|"switch the current screen and a backgrounded screen"
block|}
block|,
comment|/* C_GLOBAL */
block|{
literal|"global"
block|,
name|ex_global
block|,
name|E_ADDR2_ALL
operator||
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|"!s"
block|,
literal|"[line [,line]] g[lobal][!] [;/]RE[;/] [commands]"
block|,
literal|"execute a global command on lines matching an RE"
block|}
block|,
comment|/* C_HELP */
block|{
literal|"help"
block|,
name|ex_help
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|""
block|,
literal|"he[lp]"
block|,
literal|"display help statement"
block|}
block|,
comment|/* C_INSERT */
block|{
literal|"insert"
block|,
name|ex_insert
block|,
name|E_ADDR1
operator||
name|E_NORC
block|,
literal|"!"
block|,
literal|"[line] i[nsert][!]"
block|,
literal|"insert input before a line"
block|}
block|,
comment|/* C_JOIN */
block|{
literal|"join"
block|,
name|ex_join
block|,
name|E_ADDR2
operator||
name|E_AUTOPRINT
operator||
name|E_NORC
block|,
literal|"!ca1"
block|,
literal|"[line [,line]] j[oin][!] [count] [flags]"
block|,
literal|"join lines into a single line"
block|}
block|,
comment|/* C_K */
block|{
literal|"k"
block|,
name|ex_mark
block|,
name|E_ADDR1
operator||
name|E_NORC
block|,
literal|"w1r"
block|,
literal|"[line] k key"
block|,
literal|"mark a line position"
block|}
block|,
comment|/* C_LIST */
block|{
literal|"list"
block|,
name|ex_list
block|,
name|E_ADDR2
operator||
name|E_F_PRCLEAR
operator||
name|E_NORC
operator||
name|E_SETLAST
block|,
literal|"ca1"
block|,
literal|"[line [,line]] l[ist] [count] [#]"
block|,
literal|"display lines in an unambiguous form"
block|}
block|,
comment|/* C_MOVE */
block|{
literal|"move"
block|,
name|ex_move
block|,
name|E_ADDR2
operator||
name|E_AUTOPRINT
operator||
name|E_NORC
block|,
literal|"l"
block|,
literal|"[line [,line]] m[ove] line"
block|,
literal|"move lines elsewhere in the file"
block|}
block|,
comment|/* C_MARK */
block|{
literal|"mark"
block|,
name|ex_mark
block|,
name|E_ADDR1
operator||
name|E_NORC
block|,
literal|"w1r"
block|,
literal|"[line] ma[rk] key"
block|,
literal|"mark a line position"
block|}
block|,
comment|/* C_MAP */
block|{
literal|"map"
block|,
name|ex_map
block|,
literal|0
block|,
literal|"!W"
block|,
literal|"map[!] [keys replace]"
block|,
literal|"map input or commands to one or more keys"
block|}
block|,
comment|/* C_MKEXRC */
block|{
literal|"mkexrc"
block|,
name|ex_mkexrc
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|"!f1r"
block|,
literal|"mkexrc[!] file"
block|,
literal|"write a .exrc file"
block|}
block|,
comment|/* C_NEXT */
block|{
literal|"next"
block|,
name|ex_next
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|"!fN"
block|,
literal|"n[ext][!] [file ...]"
block|,
literal|"edit (and optionally specify) the next file"
block|}
block|,
comment|/* C_NUMBER */
block|{
literal|"number"
block|,
name|ex_number
block|,
name|E_ADDR2
operator||
name|E_F_PRCLEAR
operator||
name|E_NORC
operator||
name|E_SETLAST
block|,
literal|"ca1"
block|,
literal|"[line [,line]] nu[mber] [count] [l]"
block|,
literal|"change display to number lines"
block|}
block|,
comment|/* C_OPEN */
block|{
literal|"open"
block|,
name|ex_open
block|,
name|E_ADDR1
block|,
literal|"s"
block|,
literal|"[line] o[pen] [/RE/] [flags]"
block|,
literal|"enter \"open\" mode (not implemented)"
block|}
block|,
comment|/* C_PRINT */
block|{
literal|"print"
block|,
name|ex_pr
block|,
name|E_ADDR2
operator||
name|E_F_PRCLEAR
operator||
name|E_NORC
operator||
name|E_SETLAST
block|,
literal|"ca1"
block|,
literal|"[line [,line]] p[rint] [count] [#l]"
block|,
literal|"display lines"
block|}
block|,
comment|/* C_PRESERVE */
block|{
literal|"preserve"
block|,
name|ex_preserve
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|""
block|,
literal|"pre[serve]"
block|,
literal|"preserve an edit session for recovery"
block|}
block|,
comment|/* C_PREVIOUS */
block|{
literal|"previous"
block|,
name|ex_prev
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|"!"
block|,
literal|"prev[ious][!]"
block|,
literal|"edit the previous file in the file argument list"
block|}
block|,
comment|/* C_PUT */
block|{
literal|"put"
block|,
name|ex_put
block|,
name|E_ADDR1
operator||
name|E_AUTOPRINT
operator||
name|E_NORC
operator||
name|E_ZERO
block|,
literal|"b"
block|,
literal|"[line] pu[t] [buffer]"
block|,
literal|"append a cut buffer to the line"
block|}
block|,
comment|/* C_QUIT */
block|{
literal|"quit"
block|,
name|ex_quit
block|,
name|E_NOGLOBAL
block|,
literal|"!"
block|,
literal|"q[uit][!]"
block|,
literal|"exit ex/vi"
block|}
block|,
comment|/* C_READ */
block|{
literal|"read"
block|,
name|ex_read
block|,
name|E_ADDR1
operator||
name|E_NORC
operator||
name|E_ZERO
operator||
name|E_ZERODEF
block|,
literal|"!s"
block|,
literal|"[line] r[ead] [!cmd | [file]]"
block|,
literal|"append input from a command or file to the line"
block|}
block|,
comment|/* C_RESIZE */
block|{
literal|"resize"
block|,
name|ex_resize
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|"c+"
block|,
literal|"resize [+-]rows"
block|,
literal|"grow or shrink the current screen"
block|}
block|,
comment|/* C_REWIND */
block|{
literal|"rewind"
block|,
name|ex_rew
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|"!"
block|,
literal|"rew[ind][!]"
block|,
literal|"re-edit all the files in the file argument list"
block|}
block|,
comment|/* C_SUBSTITUTE */
block|{
literal|"substitute"
block|,
name|ex_substitute
block|,
name|E_ADDR2
operator||
name|E_NORC
block|,
literal|"s"
block|,
literal|"[line [,line]] s[ubstitute] [[/;]RE[/;]/repl[/;] [cgr] [count] [#lp]]"
block|,
literal|"substitute on lines matching an RE"
block|}
block|,
comment|/* C_SCRIPT */
block|{
literal|"script"
block|,
name|ex_script
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|"!f1o"
block|,
literal|"sc[ript][!] [file]"
block|,
literal|"run a shell in a screen"
block|}
block|,
comment|/* C_SET */
block|{
literal|"set"
block|,
name|ex_set
block|,
name|E_NOGLOBAL
block|,
literal|"wN"
block|,
literal|"se[t] [option[=[value]]...] [nooption ...] [option? ...] [all]"
block|,
literal|"set options (use \":set all\" to see all options)"
block|}
block|,
comment|/* C_SHELL */
block|{
literal|"shell"
block|,
name|ex_shell
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|""
block|,
literal|"sh[ell]"
block|,
literal|"suspend editing and run a shell"
block|}
block|,
comment|/* C_SOURCE */
block|{
literal|"source"
block|,
name|ex_source
block|,
name|E_NOGLOBAL
block|,
literal|"f1r"
block|,
literal|"so[urce] file"
block|,
literal|"read a file of ex commands"
block|}
block|,
comment|/* C_SPLIT */
block|{
literal|"split"
block|,
name|ex_split
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|"fNo"
block|,
literal|"sp[lit] [file ...]"
block|,
literal|"split the current screen into two screens"
block|}
block|,
comment|/* C_STOP */
block|{
literal|"stop"
block|,
name|ex_stop
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|"!"
block|,
literal|"st[op][!]"
block|,
literal|"suspend the edit session"
block|}
block|,
comment|/* C_SUSPEND */
block|{
literal|"suspend"
block|,
name|ex_stop
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|"!"
block|,
literal|"su[spend][!]"
block|,
literal|"suspend the edit session"
block|}
block|,
comment|/* C_T */
block|{
literal|"t"
block|,
name|ex_copy
block|,
name|E_ADDR2
operator||
name|E_AUTOPRINT
operator||
name|E_NORC
block|,
literal|"l1"
block|,
literal|"[line [,line]] t line [flags]"
block|,
literal|"move lines elsewhere in the file"
block|}
block|,
comment|/* C_TAG */
block|{
literal|"tag"
block|,
name|ex_tagpush
block|,
name|E_NOGLOBAL
block|,
literal|"!w1o"
block|,
literal|"ta[g][!] [string]"
block|,
literal|"edit the file containing the tag"
block|}
block|,
comment|/* C_TAGPOP */
block|{
literal|"tagpop"
block|,
name|ex_tagpop
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|"!w1o"
block|,
literal|"tagp[op][!] [number | file]"
block|,
literal|"return to a previous tag"
block|}
block|,
comment|/* C_TAGTOP */
block|{
literal|"tagtop"
block|,
name|ex_tagtop
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|"!"
block|,
literal|"tagt[op][!]"
block|,
literal|"return to the first tag"
block|}
block|,
comment|/* C_UNDOL */
block|{
literal|"Undo"
block|,
name|ex_undol
block|,
name|E_AUTOPRINT
operator||
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|""
block|,
literal|"U[ndo]"
block|,
literal|"undo all the changes to this line"
block|}
block|,
comment|/* C_UNDO */
block|{
literal|"undo"
block|,
name|ex_undo
block|,
name|E_AUTOPRINT
operator||
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|""
block|,
literal|"u[ndo]"
block|,
literal|"undo the most recent change"
block|}
block|,
comment|/* C_UNABBREVIATE */
block|{
literal|"unabbreviate"
block|,
name|ex_unabbr
block|,
name|E_NOGLOBAL
block|,
literal|"w1r"
block|,
literal|"una[bbrev] word"
block|,
literal|"delete an abbreviation"
block|}
block|,
comment|/* C_UNMAP */
block|{
literal|"unmap"
block|,
name|ex_unmap
block|,
name|E_NOGLOBAL
block|,
literal|"!w1r"
block|,
literal|"unm[ap][!] word"
block|,
literal|"delete an input or command map"
block|}
block|,
comment|/* C_VGLOBAL */
block|{
literal|"vglobal"
block|,
name|ex_vglobal
block|,
name|E_ADDR2_ALL
operator||
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|"s"
block|,
literal|"[line [,line]] v[global] [;/]RE[;/] [commands]"
block|,
literal|"execute a global command on lines NOT matching an RE"
block|}
block|,
comment|/* C_VERSION */
block|{
literal|"version"
block|,
name|ex_version
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|""
block|,
literal|"version"
block|,
literal|"display the program version information"
block|}
block|,
comment|/* C_VISUAL_EX */
block|{
literal|"visual"
block|,
name|ex_visual
block|,
name|E_ADDR1
operator||
name|E_NOGLOBAL
operator||
name|E_NORC
operator||
name|E_ZERODEF
block|,
literal|"2c11"
block|,
literal|"[line] vi[sual] [-|.|+|^] [window_size] [flags]"
block|,
literal|"enter visual (vi) mode from ex mode"
block|}
block|,
comment|/* C_VISUAL_VI */
block|{
literal|"visual"
block|,
name|ex_edit
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|"!f1o"
block|,
literal|"vi[sual][!] [+cmd] [file]"
block|,
literal|"edit another file (from vi mode only)"
block|}
block|,
comment|/* C_VIUSAGE */
block|{
literal|"viusage"
block|,
name|ex_viusage
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|"w1o"
block|,
literal|"[viu]sage [key]"
block|,
literal|"display vi key usage statement"
block|}
block|,
comment|/* C_WRITE */
block|{
literal|"write"
block|,
name|ex_write
block|,
name|E_ADDR2_ALL
operator||
name|E_NOGLOBAL
operator||
name|E_NORC
operator||
name|E_ZERODEF
block|,
literal|"!s"
block|,
literal|"[line [,line]] w[rite][!] [!cmd | [>>] [file]]"
block|,
literal|"write the file"
block|}
block|,
comment|/* C_WQ */
block|{
literal|"wq"
block|,
name|ex_wq
block|,
name|E_ADDR2_ALL
operator||
name|E_NOGLOBAL
operator||
name|E_NORC
operator||
name|E_ZERODEF
block|,
literal|"!s"
block|,
literal|"[line [,line]] wq[!] [>>] [file]"
block|,
literal|"write the file and exit"
block|}
block|,
comment|/* C_XIT */
block|{
literal|"xit"
block|,
name|ex_xit
block|,
name|E_ADDR2_ALL
operator||
name|E_NOGLOBAL
operator||
name|E_NORC
operator||
name|E_ZERODEF
block|,
literal|"!f1o"
block|,
literal|"[line [,line]] x[it][!] [file]"
block|,
literal|"exit"
block|}
block|,
comment|/* C_YANK */
block|{
literal|"yank"
block|,
name|ex_yank
block|,
name|E_ADDR2
operator||
name|E_NORC
block|,
literal|"bca"
block|,
literal|"[line [,line]] ya[nk] [buffer] [count]"
block|,
literal|"copy lines to a cut buffer"
block|}
block|,
comment|/* C_Z */
block|{
literal|"z"
block|,
name|ex_z
block|,
name|E_ADDR1
operator||
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|"3c01"
block|,
literal|"[line] z [-|.|+|^|=] [count] [flags]"
block|,
literal|"display different screens of the file"
block|}
block|,
comment|/* C_SUBTILDE */
block|{
literal|"~"
block|,
name|ex_subtilde
block|,
name|E_ADDR2
operator||
name|E_NORC
block|,
literal|"s"
block|,
literal|"[line [,line]] ~ [cgr] [count] [#lp]"
block|,
literal|"replace previous RE with previous replacement string,"
block|}
block|,
block|{
name|NULL
block|}
block|, }
decl_stmt|;
end_decl_stmt

end_unit

