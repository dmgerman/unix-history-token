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
literal|"@(#)excmd.c	8.1 (Berkeley) 6/9/93"
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
file|"excmd.h"
end_include

begin_comment
comment|/*  * This array maps ex command names to command functions.  *  * The order in which command names are listed below is important --  * ambiguous abbreviations are resolved to be the first possible match,  * e.g. "r" means "read", not "rewind", because "read" is listed before  * "rewind").  *  * The syntax of the ex commands is unbelievably irregular.  Stupid is  * another description that leaps to mind.  In any case, it's a special  * case from one end to the other.  Each command has a "syntax script"  * associated with it, which describes the items that are possible.  The  * script syntax is as follows:  *	!		-- ! flag  *	+		-- +cmd  *	1		-- flags: [+-]*[pl#][+-]*  *	2		-- flags: [-.+^]  *>		-->> string  *	b		-- buffer  *	c		-- count  *	f[N]|#[or]	-- file (a number or N, optional or required)  *	l		-- line  *	w[N]|#[or]	-- word (a number or N, optional or required)  *	s		-- string (parse locally)  */
end_comment

begin_decl_stmt
name|EXCMDLIST
name|cmds
index|[]
init|=
block|{
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
literal|"s"
block|,
literal|"[line [,line]] ! command"
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
literal|"c1"
block|,
literal|"[line [,line]] # [count] [l]"
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
literal|"[line [,line]]& [options] [count] [flags]"
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
literal|"@ [buffer]"
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
name|E_NORC
block|,
literal|"c1"
block|,
literal|"[line [,line]]<[<...] [count] [flags]"
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
name|E_NORC
block|,
literal|"c1"
block|,
literal|"[line [,line]]>[>...] [count] [flags]"
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
literal|"s"
block|,
literal|"ab[brev] word replace"
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
block|}
block|,
comment|/* C_BDISPLAY */
block|{
literal|"bdisplay"
block|,
name|ex_bdisplay
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|""
block|,
literal|"[b]display"
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
literal|"!c"
block|,
literal|"[line [,line]] c[hange][!] [count]"
block|}
block|,
comment|/* C_CC */
block|{
literal|"cc"
block|,
name|ex_cc
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|"s"
block|,
literal|"cc [argument ...]"
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
name|E_NORC
block|,
literal|"l1"
block|,
literal|"[line [,line]] co[py] line [flags]"
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
name|E_NORC
block|,
literal|"bc1"
block|,
literal|"[line [,line]] d[elete] [buffer] [count] [flags]"
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
literal|"digraph XXX"
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
literal|"!+f1o"
block|,
literal|"e[dit][!] [+cmd] [file]"
block|}
block|,
comment|/* C_ERRLIST */
block|{
literal|"errlist"
block|,
name|ex_errlist
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|"f1o"
block|,
literal|"errlist [file]"
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
literal|"!+f1o"
block|,
literal|"ex[!] [+cmd] [file]"
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
literal|"w1r"
block|,
literal|"[exu]sage cmd"
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
literal|"f10"
block|,
literal|"f[ile] [name]"
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
literal|"[line [,line]] g[lobal][!] [;/]pattern[;/] [commands]"
block|}
block|,
comment|/* C_INSERT */
block|{
literal|"insert"
block|,
name|ex_append
block|,
name|E_ADDR1
operator||
name|E_NORC
block|,
literal|"!"
block|,
literal|"[line] i[nsert][!]"
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
name|E_NORC
block|,
literal|"!c1"
block|,
literal|"[line [,line]] j[oin][!] [count] [flags]"
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
literal|"c1"
block|,
literal|"[line [,line]] l[ist] [count] [#]"
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
name|E_NORC
block|,
literal|"l"
block|,
literal|"[line [,line]] m[ove] line"
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
block|}
block|,
comment|/* C_MAKE */
block|{
literal|"make"
block|,
name|ex_make
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
operator||
name|E_NOPERM
block|,
literal|"s"
block|,
literal|"make [argument ...]"
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
literal|"s"
block|,
literal|"map[!] [key replace]"
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
literal|"c1"
block|,
literal|"[line [,line]] nu[mber] [count] [l]"
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
literal|"c1"
block|,
literal|"[line [,line]] p[rint] [count] [#l]"
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
literal|"!fN"
block|,
literal|"prev[ious][!] [file ...]"
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
name|E_NORC
operator||
name|E_ZERO
block|,
literal|"b"
block|,
literal|"[line] pu[t] [buffer]"
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
literal|"s"
block|,
literal|"[line] r[ead] [!cmd | [file]]"
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
literal|"[line [,line]] s[ubstitute] [[/;]pat[/;]/repl[/;] [count] [#cglpr]]"
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
literal|"f1o"
block|,
literal|"sp[lit] file"
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
block|}
block|,
comment|/* C_T */
block|{
literal|"t"
block|,
name|ex_move
block|,
name|E_ADDR2
operator||
name|E_NORC
block|,
literal|"l1"
block|,
literal|"[line [,line]] t line [flags]"
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
literal|"!"
block|,
literal|"tagp[op][!]"
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
block|}
block|,
comment|/* C_UNDOL */
block|{
literal|"Undo"
block|,
name|ex_undol
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|""
block|,
literal|"U[ndo]"
block|}
block|,
comment|/* C_UNDO */
block|{
literal|"undo"
block|,
name|ex_undo
block|,
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|""
block|,
literal|"u[ndo]"
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
literal|"unm[ap][!] key"
block|}
block|,
comment|/* C_VGLOBAL */
block|{
literal|"vglobal"
block|,
name|ex_global
block|,
name|E_ADDR2_ALL
operator||
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|"s"
block|,
literal|"[line [,line]] v[global] [;/]pattern[;/] [commands]"
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
block|}
block|,
comment|/* C_VISUAL */
block|{
literal|"visual"
block|,
name|ex_visual
block|,
name|E_ADDR2
operator||
name|E_NOGLOBAL
operator||
name|E_NORC
block|,
literal|"2c1"
block|,
literal|"[line] vi[sual] [type] [count] [flags]"
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
literal|"w1r"
block|,
literal|"[viu]sage key"
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
literal|"s"
block|,
literal|"[line [,line]] w[rite][!] [!cmd | [>>] [file]]"
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
literal|"s"
block|,
literal|"[line [,line]] wq[!] [>>] [file]"
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
literal|"bc"
block|,
literal|"[line [,line]] ya[nk] [buffer] [count]"
block|}
block|,
block|{
name|NULL
block|}
block|, }
decl_stmt|;
end_decl_stmt

end_unit

