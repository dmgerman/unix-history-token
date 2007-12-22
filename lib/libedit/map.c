begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Christos Zoulas of Cornell University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$NetBSD: map.c,v 1.24 2006/04/09 01:36:51 christos Exp $  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SCCSID
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)map.c	8.1 (Berkeley) 6/4/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint&& not SCCSID */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * map.c: Editor function definitions  */
end_comment

begin_include
include|#
directive|include
file|"sys.h"
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"el.h"
end_include

begin_define
define|#
directive|define
name|N_KEYS
value|256
end_define

begin_function_decl
name|private
name|void
name|map_print_key
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|el_action_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|private
name|void
name|map_print_some_keys
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|el_action_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|private
name|void
name|map_print_all_keys
parameter_list|(
name|EditLine
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|private
name|void
name|map_init_nls
parameter_list|(
name|EditLine
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|private
name|void
name|map_init_meta
parameter_list|(
name|EditLine
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* keymap tables ; should be N_KEYS*sizeof(KEYCMD) bytes long */
end_comment

begin_decl_stmt
name|private
specifier|const
name|el_action_t
name|el_map_emacs
index|[]
init|=
block|{
comment|/*   0 */
name|EM_SET_MARK
block|,
comment|/* ^@ */
comment|/*   1 */
name|ED_MOVE_TO_BEG
block|,
comment|/* ^A */
comment|/*   2 */
name|ED_PREV_CHAR
block|,
comment|/* ^B */
comment|/*   3 */
name|ED_TTY_SIGINT
block|,
comment|/* ^C */
comment|/*   4 */
name|EM_DELETE_OR_LIST
block|,
comment|/* ^D */
comment|/*   5 */
name|ED_MOVE_TO_END
block|,
comment|/* ^E */
comment|/*   6 */
name|ED_NEXT_CHAR
block|,
comment|/* ^F */
comment|/*   7 */
name|ED_UNASSIGNED
block|,
comment|/* ^G */
comment|/*   8 */
name|EM_DELETE_PREV_CHAR
block|,
comment|/* ^H */
comment|/*   9 */
name|ED_UNASSIGNED
block|,
comment|/* ^I */
comment|/*  10 */
name|ED_NEWLINE
block|,
comment|/* ^J */
comment|/*  11 */
name|ED_KILL_LINE
block|,
comment|/* ^K */
comment|/*  12 */
name|ED_CLEAR_SCREEN
block|,
comment|/* ^L */
comment|/*  13 */
name|ED_NEWLINE
block|,
comment|/* ^M */
comment|/*  14 */
name|ED_NEXT_HISTORY
block|,
comment|/* ^N */
comment|/*  15 */
name|ED_TTY_FLUSH_OUTPUT
block|,
comment|/* ^O */
comment|/*  16 */
name|ED_PREV_HISTORY
block|,
comment|/* ^P */
comment|/*  17 */
name|ED_TTY_START_OUTPUT
block|,
comment|/* ^Q */
comment|/*  18 */
name|ED_REDISPLAY
block|,
comment|/* ^R */
comment|/*  19 */
name|ED_TTY_STOP_OUTPUT
block|,
comment|/* ^S */
comment|/*  20 */
name|ED_TRANSPOSE_CHARS
block|,
comment|/* ^T */
comment|/*  21 */
name|EM_KILL_LINE
block|,
comment|/* ^U */
comment|/*  22 */
name|ED_QUOTED_INSERT
block|,
comment|/* ^V */
comment|/*  23 */
name|EM_KILL_REGION
block|,
comment|/* ^W */
comment|/*  24 */
name|ED_SEQUENCE_LEAD_IN
block|,
comment|/* ^X */
comment|/*  25 */
name|EM_YANK
block|,
comment|/* ^Y */
comment|/*  26 */
name|ED_TTY_SIGTSTP
block|,
comment|/* ^Z */
comment|/*  27 */
name|EM_META_NEXT
block|,
comment|/* ^[ */
comment|/*  28 */
name|ED_TTY_SIGQUIT
block|,
comment|/* ^\ */
comment|/*  29 */
name|ED_TTY_DSUSP
block|,
comment|/* ^] */
comment|/*  30 */
name|ED_UNASSIGNED
block|,
comment|/* ^^ */
comment|/*  31 */
name|ED_UNASSIGNED
block|,
comment|/* ^_ */
comment|/*  32 */
name|ED_INSERT
block|,
comment|/* SPACE */
comment|/*  33 */
name|ED_INSERT
block|,
comment|/* ! */
comment|/*  34 */
name|ED_INSERT
block|,
comment|/* " */
comment|/*  35 */
name|ED_INSERT
block|,
comment|/* # */
comment|/*  36 */
name|ED_INSERT
block|,
comment|/* $ */
comment|/*  37 */
name|ED_INSERT
block|,
comment|/* % */
comment|/*  38 */
name|ED_INSERT
block|,
comment|/*& */
comment|/*  39 */
name|ED_INSERT
block|,
comment|/* ' */
comment|/*  40 */
name|ED_INSERT
block|,
comment|/* ( */
comment|/*  41 */
name|ED_INSERT
block|,
comment|/* ) */
comment|/*  42 */
name|ED_INSERT
block|,
comment|/* * */
comment|/*  43 */
name|ED_INSERT
block|,
comment|/* + */
comment|/*  44 */
name|ED_INSERT
block|,
comment|/* , */
comment|/*  45 */
name|ED_INSERT
block|,
comment|/* - */
comment|/*  46 */
name|ED_INSERT
block|,
comment|/* . */
comment|/*  47 */
name|ED_INSERT
block|,
comment|/* / */
comment|/*  48 */
name|ED_DIGIT
block|,
comment|/* 0 */
comment|/*  49 */
name|ED_DIGIT
block|,
comment|/* 1 */
comment|/*  50 */
name|ED_DIGIT
block|,
comment|/* 2 */
comment|/*  51 */
name|ED_DIGIT
block|,
comment|/* 3 */
comment|/*  52 */
name|ED_DIGIT
block|,
comment|/* 4 */
comment|/*  53 */
name|ED_DIGIT
block|,
comment|/* 5 */
comment|/*  54 */
name|ED_DIGIT
block|,
comment|/* 6 */
comment|/*  55 */
name|ED_DIGIT
block|,
comment|/* 7 */
comment|/*  56 */
name|ED_DIGIT
block|,
comment|/* 8 */
comment|/*  57 */
name|ED_DIGIT
block|,
comment|/* 9 */
comment|/*  58 */
name|ED_INSERT
block|,
comment|/* : */
comment|/*  59 */
name|ED_INSERT
block|,
comment|/* ; */
comment|/*  60 */
name|ED_INSERT
block|,
comment|/*< */
comment|/*  61 */
name|ED_INSERT
block|,
comment|/* = */
comment|/*  62 */
name|ED_INSERT
block|,
comment|/*> */
comment|/*  63 */
name|ED_INSERT
block|,
comment|/* ? */
comment|/*  64 */
name|ED_INSERT
block|,
comment|/* @ */
comment|/*  65 */
name|ED_INSERT
block|,
comment|/* A */
comment|/*  66 */
name|ED_INSERT
block|,
comment|/* B */
comment|/*  67 */
name|ED_INSERT
block|,
comment|/* C */
comment|/*  68 */
name|ED_INSERT
block|,
comment|/* D */
comment|/*  69 */
name|ED_INSERT
block|,
comment|/* E */
comment|/*  70 */
name|ED_INSERT
block|,
comment|/* F */
comment|/*  71 */
name|ED_INSERT
block|,
comment|/* G */
comment|/*  72 */
name|ED_INSERT
block|,
comment|/* H */
comment|/*  73 */
name|ED_INSERT
block|,
comment|/* I */
comment|/*  74 */
name|ED_INSERT
block|,
comment|/* J */
comment|/*  75 */
name|ED_INSERT
block|,
comment|/* K */
comment|/*  76 */
name|ED_INSERT
block|,
comment|/* L */
comment|/*  77 */
name|ED_INSERT
block|,
comment|/* M */
comment|/*  78 */
name|ED_INSERT
block|,
comment|/* N */
comment|/*  79 */
name|ED_INSERT
block|,
comment|/* O */
comment|/*  80 */
name|ED_INSERT
block|,
comment|/* P */
comment|/*  81 */
name|ED_INSERT
block|,
comment|/* Q */
comment|/*  82 */
name|ED_INSERT
block|,
comment|/* R */
comment|/*  83 */
name|ED_INSERT
block|,
comment|/* S */
comment|/*  84 */
name|ED_INSERT
block|,
comment|/* T */
comment|/*  85 */
name|ED_INSERT
block|,
comment|/* U */
comment|/*  86 */
name|ED_INSERT
block|,
comment|/* V */
comment|/*  87 */
name|ED_INSERT
block|,
comment|/* W */
comment|/*  88 */
name|ED_INSERT
block|,
comment|/* X */
comment|/*  89 */
name|ED_INSERT
block|,
comment|/* Y */
comment|/*  90 */
name|ED_INSERT
block|,
comment|/* Z */
comment|/*  91 */
name|ED_INSERT
block|,
comment|/* [ */
comment|/*  92 */
name|ED_INSERT
block|,
comment|/* \ */
comment|/*  93 */
name|ED_INSERT
block|,
comment|/* ] */
comment|/*  94 */
name|ED_INSERT
block|,
comment|/* ^ */
comment|/*  95 */
name|ED_INSERT
block|,
comment|/* _ */
comment|/*  96 */
name|ED_INSERT
block|,
comment|/* ` */
comment|/*  97 */
name|ED_INSERT
block|,
comment|/* a */
comment|/*  98 */
name|ED_INSERT
block|,
comment|/* b */
comment|/*  99 */
name|ED_INSERT
block|,
comment|/* c */
comment|/* 100 */
name|ED_INSERT
block|,
comment|/* d */
comment|/* 101 */
name|ED_INSERT
block|,
comment|/* e */
comment|/* 102 */
name|ED_INSERT
block|,
comment|/* f */
comment|/* 103 */
name|ED_INSERT
block|,
comment|/* g */
comment|/* 104 */
name|ED_INSERT
block|,
comment|/* h */
comment|/* 105 */
name|ED_INSERT
block|,
comment|/* i */
comment|/* 106 */
name|ED_INSERT
block|,
comment|/* j */
comment|/* 107 */
name|ED_INSERT
block|,
comment|/* k */
comment|/* 108 */
name|ED_INSERT
block|,
comment|/* l */
comment|/* 109 */
name|ED_INSERT
block|,
comment|/* m */
comment|/* 110 */
name|ED_INSERT
block|,
comment|/* n */
comment|/* 111 */
name|ED_INSERT
block|,
comment|/* o */
comment|/* 112 */
name|ED_INSERT
block|,
comment|/* p */
comment|/* 113 */
name|ED_INSERT
block|,
comment|/* q */
comment|/* 114 */
name|ED_INSERT
block|,
comment|/* r */
comment|/* 115 */
name|ED_INSERT
block|,
comment|/* s */
comment|/* 116 */
name|ED_INSERT
block|,
comment|/* t */
comment|/* 117 */
name|ED_INSERT
block|,
comment|/* u */
comment|/* 118 */
name|ED_INSERT
block|,
comment|/* v */
comment|/* 119 */
name|ED_INSERT
block|,
comment|/* w */
comment|/* 120 */
name|ED_INSERT
block|,
comment|/* x */
comment|/* 121 */
name|ED_INSERT
block|,
comment|/* y */
comment|/* 122 */
name|ED_INSERT
block|,
comment|/* z */
comment|/* 123 */
name|ED_INSERT
block|,
comment|/* { */
comment|/* 124 */
name|ED_INSERT
block|,
comment|/* | */
comment|/* 125 */
name|ED_INSERT
block|,
comment|/* } */
comment|/* 126 */
name|ED_INSERT
block|,
comment|/* ~ */
comment|/* 127 */
name|EM_DELETE_PREV_CHAR
block|,
comment|/* ^? */
comment|/* 128 */
name|ED_UNASSIGNED
block|,
comment|/* M-^@ */
comment|/* 129 */
name|ED_UNASSIGNED
block|,
comment|/* M-^A */
comment|/* 130 */
name|ED_UNASSIGNED
block|,
comment|/* M-^B */
comment|/* 131 */
name|ED_UNASSIGNED
block|,
comment|/* M-^C */
comment|/* 132 */
name|ED_UNASSIGNED
block|,
comment|/* M-^D */
comment|/* 133 */
name|ED_UNASSIGNED
block|,
comment|/* M-^E */
comment|/* 134 */
name|ED_UNASSIGNED
block|,
comment|/* M-^F */
comment|/* 135 */
name|ED_UNASSIGNED
block|,
comment|/* M-^G */
comment|/* 136 */
name|ED_DELETE_PREV_WORD
block|,
comment|/* M-^H */
comment|/* 137 */
name|ED_UNASSIGNED
block|,
comment|/* M-^I */
comment|/* 138 */
name|ED_UNASSIGNED
block|,
comment|/* M-^J */
comment|/* 139 */
name|ED_UNASSIGNED
block|,
comment|/* M-^K */
comment|/* 140 */
name|ED_CLEAR_SCREEN
block|,
comment|/* M-^L */
comment|/* 141 */
name|ED_UNASSIGNED
block|,
comment|/* M-^M */
comment|/* 142 */
name|ED_UNASSIGNED
block|,
comment|/* M-^N */
comment|/* 143 */
name|ED_UNASSIGNED
block|,
comment|/* M-^O */
comment|/* 144 */
name|ED_UNASSIGNED
block|,
comment|/* M-^P */
comment|/* 145 */
name|ED_UNASSIGNED
block|,
comment|/* M-^Q */
comment|/* 146 */
name|ED_UNASSIGNED
block|,
comment|/* M-^R */
comment|/* 147 */
name|ED_UNASSIGNED
block|,
comment|/* M-^S */
comment|/* 148 */
name|ED_UNASSIGNED
block|,
comment|/* M-^T */
comment|/* 149 */
name|ED_UNASSIGNED
block|,
comment|/* M-^U */
comment|/* 150 */
name|ED_UNASSIGNED
block|,
comment|/* M-^V */
comment|/* 151 */
name|ED_UNASSIGNED
block|,
comment|/* M-^W */
comment|/* 152 */
name|ED_UNASSIGNED
block|,
comment|/* M-^X */
comment|/* 153 */
name|ED_UNASSIGNED
block|,
comment|/* M-^Y */
comment|/* 154 */
name|ED_UNASSIGNED
block|,
comment|/* M-^Z */
comment|/* 155 */
name|ED_UNASSIGNED
block|,
comment|/* M-^[ */
comment|/* 156 */
name|ED_UNASSIGNED
block|,
comment|/* M-^\ */
comment|/* 157 */
name|ED_UNASSIGNED
block|,
comment|/* M-^] */
comment|/* 158 */
name|ED_UNASSIGNED
block|,
comment|/* M-^^ */
comment|/* 159 */
name|EM_COPY_PREV_WORD
block|,
comment|/* M-^_ */
comment|/* 160 */
name|ED_UNASSIGNED
block|,
comment|/* M-SPACE */
comment|/* 161 */
name|ED_UNASSIGNED
block|,
comment|/* M-! */
comment|/* 162 */
name|ED_UNASSIGNED
block|,
comment|/* M-" */
comment|/* 163 */
name|ED_UNASSIGNED
block|,
comment|/* M-# */
comment|/* 164 */
name|ED_UNASSIGNED
block|,
comment|/* M-$ */
comment|/* 165 */
name|ED_UNASSIGNED
block|,
comment|/* M-% */
comment|/* 166 */
name|ED_UNASSIGNED
block|,
comment|/* M-& */
comment|/* 167 */
name|ED_UNASSIGNED
block|,
comment|/* M-' */
comment|/* 168 */
name|ED_UNASSIGNED
block|,
comment|/* M-( */
comment|/* 169 */
name|ED_UNASSIGNED
block|,
comment|/* M-) */
comment|/* 170 */
name|ED_UNASSIGNED
block|,
comment|/* M-* */
comment|/* 171 */
name|ED_UNASSIGNED
block|,
comment|/* M-+ */
comment|/* 172 */
name|ED_UNASSIGNED
block|,
comment|/* M-, */
comment|/* 173 */
name|ED_UNASSIGNED
block|,
comment|/* M-- */
comment|/* 174 */
name|ED_UNASSIGNED
block|,
comment|/* M-. */
comment|/* 175 */
name|ED_UNASSIGNED
block|,
comment|/* M-/ */
comment|/* 176 */
name|ED_ARGUMENT_DIGIT
block|,
comment|/* M-0 */
comment|/* 177 */
name|ED_ARGUMENT_DIGIT
block|,
comment|/* M-1 */
comment|/* 178 */
name|ED_ARGUMENT_DIGIT
block|,
comment|/* M-2 */
comment|/* 179 */
name|ED_ARGUMENT_DIGIT
block|,
comment|/* M-3 */
comment|/* 180 */
name|ED_ARGUMENT_DIGIT
block|,
comment|/* M-4 */
comment|/* 181 */
name|ED_ARGUMENT_DIGIT
block|,
comment|/* M-5 */
comment|/* 182 */
name|ED_ARGUMENT_DIGIT
block|,
comment|/* M-6 */
comment|/* 183 */
name|ED_ARGUMENT_DIGIT
block|,
comment|/* M-7 */
comment|/* 184 */
name|ED_ARGUMENT_DIGIT
block|,
comment|/* M-8 */
comment|/* 185 */
name|ED_ARGUMENT_DIGIT
block|,
comment|/* M-9 */
comment|/* 186 */
name|ED_UNASSIGNED
block|,
comment|/* M-: */
comment|/* 187 */
name|ED_UNASSIGNED
block|,
comment|/* M-; */
comment|/* 188 */
name|ED_UNASSIGNED
block|,
comment|/* M-< */
comment|/* 189 */
name|ED_UNASSIGNED
block|,
comment|/* M-= */
comment|/* 190 */
name|ED_UNASSIGNED
block|,
comment|/* M-> */
comment|/* 191 */
name|ED_UNASSIGNED
block|,
comment|/* M-? */
comment|/* 192 */
name|ED_UNASSIGNED
block|,
comment|/* M-@ */
comment|/* 193 */
name|ED_UNASSIGNED
block|,
comment|/* M-A */
comment|/* 194 */
name|ED_PREV_WORD
block|,
comment|/* M-B */
comment|/* 195 */
name|EM_CAPITOL_CASE
block|,
comment|/* M-C */
comment|/* 196 */
name|EM_DELETE_NEXT_WORD
block|,
comment|/* M-D */
comment|/* 197 */
name|ED_UNASSIGNED
block|,
comment|/* M-E */
comment|/* 198 */
name|EM_NEXT_WORD
block|,
comment|/* M-F */
comment|/* 199 */
name|ED_UNASSIGNED
block|,
comment|/* M-G */
comment|/* 200 */
name|ED_UNASSIGNED
block|,
comment|/* M-H */
comment|/* 201 */
name|ED_UNASSIGNED
block|,
comment|/* M-I */
comment|/* 202 */
name|ED_UNASSIGNED
block|,
comment|/* M-J */
comment|/* 203 */
name|ED_UNASSIGNED
block|,
comment|/* M-K */
comment|/* 204 */
name|EM_LOWER_CASE
block|,
comment|/* M-L */
comment|/* 205 */
name|ED_UNASSIGNED
block|,
comment|/* M-M */
comment|/* 206 */
name|ED_SEARCH_NEXT_HISTORY
block|,
comment|/* M-N */
comment|/* 207 */
name|ED_SEQUENCE_LEAD_IN
block|,
comment|/* M-O */
comment|/* 208 */
name|ED_SEARCH_PREV_HISTORY
block|,
comment|/* M-P */
comment|/* 209 */
name|ED_UNASSIGNED
block|,
comment|/* M-Q */
comment|/* 210 */
name|ED_UNASSIGNED
block|,
comment|/* M-R */
comment|/* 211 */
name|ED_UNASSIGNED
block|,
comment|/* M-S */
comment|/* 212 */
name|ED_UNASSIGNED
block|,
comment|/* M-T */
comment|/* 213 */
name|EM_UPPER_CASE
block|,
comment|/* M-U */
comment|/* 214 */
name|ED_UNASSIGNED
block|,
comment|/* M-V */
comment|/* 215 */
name|EM_COPY_REGION
block|,
comment|/* M-W */
comment|/* 216 */
name|ED_COMMAND
block|,
comment|/* M-X */
comment|/* 217 */
name|ED_UNASSIGNED
block|,
comment|/* M-Y */
comment|/* 218 */
name|ED_UNASSIGNED
block|,
comment|/* M-Z */
comment|/* 219 */
name|ED_SEQUENCE_LEAD_IN
block|,
comment|/* M-[ */
comment|/* 220 */
name|ED_UNASSIGNED
block|,
comment|/* M-\ */
comment|/* 221 */
name|ED_UNASSIGNED
block|,
comment|/* M-] */
comment|/* 222 */
name|ED_UNASSIGNED
block|,
comment|/* M-^ */
comment|/* 223 */
name|ED_UNASSIGNED
block|,
comment|/* M-_ */
comment|/* 223 */
name|ED_UNASSIGNED
block|,
comment|/* M-` */
comment|/* 224 */
name|ED_UNASSIGNED
block|,
comment|/* M-a */
comment|/* 225 */
name|ED_PREV_WORD
block|,
comment|/* M-b */
comment|/* 226 */
name|EM_CAPITOL_CASE
block|,
comment|/* M-c */
comment|/* 227 */
name|EM_DELETE_NEXT_WORD
block|,
comment|/* M-d */
comment|/* 228 */
name|ED_UNASSIGNED
block|,
comment|/* M-e */
comment|/* 229 */
name|EM_NEXT_WORD
block|,
comment|/* M-f */
comment|/* 230 */
name|ED_UNASSIGNED
block|,
comment|/* M-g */
comment|/* 231 */
name|ED_UNASSIGNED
block|,
comment|/* M-h */
comment|/* 232 */
name|ED_UNASSIGNED
block|,
comment|/* M-i */
comment|/* 233 */
name|ED_UNASSIGNED
block|,
comment|/* M-j */
comment|/* 234 */
name|ED_UNASSIGNED
block|,
comment|/* M-k */
comment|/* 235 */
name|EM_LOWER_CASE
block|,
comment|/* M-l */
comment|/* 236 */
name|ED_UNASSIGNED
block|,
comment|/* M-m */
comment|/* 237 */
name|ED_SEARCH_NEXT_HISTORY
block|,
comment|/* M-n */
comment|/* 238 */
name|ED_UNASSIGNED
block|,
comment|/* M-o */
comment|/* 239 */
name|ED_SEARCH_PREV_HISTORY
block|,
comment|/* M-p */
comment|/* 240 */
name|ED_UNASSIGNED
block|,
comment|/* M-q */
comment|/* 241 */
name|ED_UNASSIGNED
block|,
comment|/* M-r */
comment|/* 242 */
name|ED_UNASSIGNED
block|,
comment|/* M-s */
comment|/* 243 */
name|ED_UNASSIGNED
block|,
comment|/* M-t */
comment|/* 244 */
name|EM_UPPER_CASE
block|,
comment|/* M-u */
comment|/* 245 */
name|ED_UNASSIGNED
block|,
comment|/* M-v */
comment|/* 246 */
name|EM_COPY_REGION
block|,
comment|/* M-w */
comment|/* 247 */
name|ED_COMMAND
block|,
comment|/* M-x */
comment|/* 248 */
name|ED_UNASSIGNED
block|,
comment|/* M-y */
comment|/* 249 */
name|ED_UNASSIGNED
block|,
comment|/* M-z */
comment|/* 250 */
name|ED_UNASSIGNED
block|,
comment|/* M-{ */
comment|/* 251 */
name|ED_UNASSIGNED
block|,
comment|/* M-| */
comment|/* 252 */
name|ED_UNASSIGNED
block|,
comment|/* M-} */
comment|/* 253 */
name|ED_UNASSIGNED
block|,
comment|/* M-~ */
comment|/* 254 */
name|ED_DELETE_PREV_WORD
comment|/* M-^? */
comment|/* 255 */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * keymap table for vi.  Each index into above tbl; should be  * N_KEYS entries long.  Vi mode uses a sticky-extend to do command mode:  * insert mode characters are in the normal keymap, and command mode  * in the extended keymap.  */
end_comment

begin_decl_stmt
name|private
specifier|const
name|el_action_t
name|el_map_vi_insert
index|[]
init|=
block|{
ifdef|#
directive|ifdef
name|KSHVI
comment|/*   0 */
name|ED_UNASSIGNED
block|,
comment|/* ^@ */
comment|/*   1 */
name|ED_INSERT
block|,
comment|/* ^A */
comment|/*   2 */
name|ED_INSERT
block|,
comment|/* ^B */
comment|/*   3 */
name|ED_INSERT
block|,
comment|/* ^C */
comment|/*   4 */
name|VI_LIST_OR_EOF
block|,
comment|/* ^D */
comment|/*   5 */
name|ED_INSERT
block|,
comment|/* ^E */
comment|/*   6 */
name|ED_INSERT
block|,
comment|/* ^F */
comment|/*   7 */
name|ED_INSERT
block|,
comment|/* ^G */
comment|/*   8 */
name|VI_DELETE_PREV_CHAR
block|,
comment|/* ^H */
comment|/* BackSpace key */
comment|/*   9 */
name|ED_INSERT
block|,
comment|/* ^I */
comment|/* Tab Key  */
comment|/*  10 */
name|ED_NEWLINE
block|,
comment|/* ^J */
comment|/*  11 */
name|ED_INSERT
block|,
comment|/* ^K */
comment|/*  12 */
name|ED_INSERT
block|,
comment|/* ^L */
comment|/*  13 */
name|ED_NEWLINE
block|,
comment|/* ^M */
comment|/*  14 */
name|ED_INSERT
block|,
comment|/* ^N */
comment|/*  15 */
name|ED_INSERT
block|,
comment|/* ^O */
comment|/*  16 */
name|ED_INSERT
block|,
comment|/* ^P */
comment|/*  17 */
name|ED_TTY_START_OUTPUT
block|,
comment|/* ^Q */
comment|/*  18 */
name|ED_INSERT
block|,
comment|/* ^R */
comment|/*  19 */
name|ED_TTY_STOP_OUTPUT
block|,
comment|/* ^S */
comment|/*  20 */
name|ED_INSERT
block|,
comment|/* ^T */
comment|/*  21 */
name|VI_KILL_LINE_PREV
block|,
comment|/* ^U */
comment|/*  22 */
name|ED_QUOTED_INSERT
block|,
comment|/* ^V */
comment|/*  23 */
name|ED_DELETE_PREV_WORD
block|,
comment|/* ^W */
comment|/* ED_DELETE_PREV_WORD: Only until strt edit pos */
comment|/*  24 */
name|ED_INSERT
block|,
comment|/* ^X */
comment|/*  25 */
name|ED_INSERT
block|,
comment|/* ^Y */
comment|/*  26 */
name|ED_INSERT
block|,
comment|/* ^Z */
comment|/*  27 */
name|VI_COMMAND_MODE
block|,
comment|/* ^[ */
comment|/* [ Esc ] key */
comment|/*  28 */
name|ED_TTY_SIGQUIT
block|,
comment|/* ^\ */
comment|/*  29 */
name|ED_INSERT
block|,
comment|/* ^] */
comment|/*  30 */
name|ED_INSERT
block|,
comment|/* ^^ */
comment|/*  31 */
name|ED_INSERT
block|,
comment|/* ^_ */
else|#
directive|else
comment|/* !KSHVI */
comment|/* 				 * NOTE: These mappings do NOT Correspond well 				 * to the KSH VI editing assignments. 				 * On the other and they are convenient and 				 * many people have have gotten used to them. 				 */
comment|/*   0 */
name|ED_UNASSIGNED
block|,
comment|/* ^@ */
comment|/*   1 */
name|ED_MOVE_TO_BEG
block|,
comment|/* ^A */
comment|/*   2 */
name|ED_PREV_CHAR
block|,
comment|/* ^B */
comment|/*   3 */
name|ED_TTY_SIGINT
block|,
comment|/* ^C */
comment|/*   4 */
name|VI_LIST_OR_EOF
block|,
comment|/* ^D */
comment|/*   5 */
name|ED_MOVE_TO_END
block|,
comment|/* ^E */
comment|/*   6 */
name|ED_NEXT_CHAR
block|,
comment|/* ^F */
comment|/*   7 */
name|ED_UNASSIGNED
block|,
comment|/* ^G */
comment|/*   8 */
name|VI_DELETE_PREV_CHAR
block|,
comment|/* ^H */
comment|/* BackSpace key */
comment|/*   9 */
name|ED_UNASSIGNED
block|,
comment|/* ^I */
comment|/* Tab Key */
comment|/*  10 */
name|ED_NEWLINE
block|,
comment|/* ^J */
comment|/*  11 */
name|ED_KILL_LINE
block|,
comment|/* ^K */
comment|/*  12 */
name|ED_CLEAR_SCREEN
block|,
comment|/* ^L */
comment|/*  13 */
name|ED_NEWLINE
block|,
comment|/* ^M */
comment|/*  14 */
name|ED_NEXT_HISTORY
block|,
comment|/* ^N */
comment|/*  15 */
name|ED_TTY_FLUSH_OUTPUT
block|,
comment|/* ^O */
comment|/*  16 */
name|ED_PREV_HISTORY
block|,
comment|/* ^P */
comment|/*  17 */
name|ED_TTY_START_OUTPUT
block|,
comment|/* ^Q */
comment|/*  18 */
name|ED_REDISPLAY
block|,
comment|/* ^R */
comment|/*  19 */
name|ED_TTY_STOP_OUTPUT
block|,
comment|/* ^S */
comment|/*  20 */
name|ED_TRANSPOSE_CHARS
block|,
comment|/* ^T */
comment|/*  21 */
name|VI_KILL_LINE_PREV
block|,
comment|/* ^U */
comment|/*  22 */
name|ED_QUOTED_INSERT
block|,
comment|/* ^V */
comment|/*  23 */
name|ED_DELETE_PREV_WORD
block|,
comment|/* ^W */
comment|/*  24 */
name|ED_UNASSIGNED
block|,
comment|/* ^X */
comment|/*  25 */
name|ED_TTY_DSUSP
block|,
comment|/* ^Y */
comment|/*  26 */
name|ED_TTY_SIGTSTP
block|,
comment|/* ^Z */
comment|/*  27 */
name|VI_COMMAND_MODE
block|,
comment|/* ^[ */
comment|/*  28 */
name|ED_TTY_SIGQUIT
block|,
comment|/* ^\ */
comment|/*  29 */
name|ED_UNASSIGNED
block|,
comment|/* ^] */
comment|/*  30 */
name|ED_UNASSIGNED
block|,
comment|/* ^^ */
comment|/*  31 */
name|ED_UNASSIGNED
block|,
comment|/* ^_ */
endif|#
directive|endif
comment|/* KSHVI */
comment|/*  32 */
name|ED_INSERT
block|,
comment|/* SPACE */
comment|/*  33 */
name|ED_INSERT
block|,
comment|/* ! */
comment|/*  34 */
name|ED_INSERT
block|,
comment|/* " */
comment|/*  35 */
name|ED_INSERT
block|,
comment|/* # */
comment|/*  36 */
name|ED_INSERT
block|,
comment|/* $ */
comment|/*  37 */
name|ED_INSERT
block|,
comment|/* % */
comment|/*  38 */
name|ED_INSERT
block|,
comment|/*& */
comment|/*  39 */
name|ED_INSERT
block|,
comment|/* ' */
comment|/*  40 */
name|ED_INSERT
block|,
comment|/* ( */
comment|/*  41 */
name|ED_INSERT
block|,
comment|/* ) */
comment|/*  42 */
name|ED_INSERT
block|,
comment|/* * */
comment|/*  43 */
name|ED_INSERT
block|,
comment|/* + */
comment|/*  44 */
name|ED_INSERT
block|,
comment|/* , */
comment|/*  45 */
name|ED_INSERT
block|,
comment|/* - */
comment|/*  46 */
name|ED_INSERT
block|,
comment|/* . */
comment|/*  47 */
name|ED_INSERT
block|,
comment|/* / */
comment|/*  48 */
name|ED_INSERT
block|,
comment|/* 0 */
comment|/*  49 */
name|ED_INSERT
block|,
comment|/* 1 */
comment|/*  50 */
name|ED_INSERT
block|,
comment|/* 2 */
comment|/*  51 */
name|ED_INSERT
block|,
comment|/* 3 */
comment|/*  52 */
name|ED_INSERT
block|,
comment|/* 4 */
comment|/*  53 */
name|ED_INSERT
block|,
comment|/* 5 */
comment|/*  54 */
name|ED_INSERT
block|,
comment|/* 6 */
comment|/*  55 */
name|ED_INSERT
block|,
comment|/* 7 */
comment|/*  56 */
name|ED_INSERT
block|,
comment|/* 8 */
comment|/*  57 */
name|ED_INSERT
block|,
comment|/* 9 */
comment|/*  58 */
name|ED_INSERT
block|,
comment|/* : */
comment|/*  59 */
name|ED_INSERT
block|,
comment|/* ; */
comment|/*  60 */
name|ED_INSERT
block|,
comment|/*< */
comment|/*  61 */
name|ED_INSERT
block|,
comment|/* = */
comment|/*  62 */
name|ED_INSERT
block|,
comment|/*> */
comment|/*  63 */
name|ED_INSERT
block|,
comment|/* ? */
comment|/*  64 */
name|ED_INSERT
block|,
comment|/* @ */
comment|/*  65 */
name|ED_INSERT
block|,
comment|/* A */
comment|/*  66 */
name|ED_INSERT
block|,
comment|/* B */
comment|/*  67 */
name|ED_INSERT
block|,
comment|/* C */
comment|/*  68 */
name|ED_INSERT
block|,
comment|/* D */
comment|/*  69 */
name|ED_INSERT
block|,
comment|/* E */
comment|/*  70 */
name|ED_INSERT
block|,
comment|/* F */
comment|/*  71 */
name|ED_INSERT
block|,
comment|/* G */
comment|/*  72 */
name|ED_INSERT
block|,
comment|/* H */
comment|/*  73 */
name|ED_INSERT
block|,
comment|/* I */
comment|/*  74 */
name|ED_INSERT
block|,
comment|/* J */
comment|/*  75 */
name|ED_INSERT
block|,
comment|/* K */
comment|/*  76 */
name|ED_INSERT
block|,
comment|/* L */
comment|/*  77 */
name|ED_INSERT
block|,
comment|/* M */
comment|/*  78 */
name|ED_INSERT
block|,
comment|/* N */
comment|/*  79 */
name|ED_INSERT
block|,
comment|/* O */
comment|/*  80 */
name|ED_INSERT
block|,
comment|/* P */
comment|/*  81 */
name|ED_INSERT
block|,
comment|/* Q */
comment|/*  82 */
name|ED_INSERT
block|,
comment|/* R */
comment|/*  83 */
name|ED_INSERT
block|,
comment|/* S */
comment|/*  84 */
name|ED_INSERT
block|,
comment|/* T */
comment|/*  85 */
name|ED_INSERT
block|,
comment|/* U */
comment|/*  86 */
name|ED_INSERT
block|,
comment|/* V */
comment|/*  87 */
name|ED_INSERT
block|,
comment|/* W */
comment|/*  88 */
name|ED_INSERT
block|,
comment|/* X */
comment|/*  89 */
name|ED_INSERT
block|,
comment|/* Y */
comment|/*  90 */
name|ED_INSERT
block|,
comment|/* Z */
comment|/*  91 */
name|ED_INSERT
block|,
comment|/* [ */
comment|/*  92 */
name|ED_INSERT
block|,
comment|/* \ */
comment|/*  93 */
name|ED_INSERT
block|,
comment|/* ] */
comment|/*  94 */
name|ED_INSERT
block|,
comment|/* ^ */
comment|/*  95 */
name|ED_INSERT
block|,
comment|/* _ */
comment|/*  96 */
name|ED_INSERT
block|,
comment|/* ` */
comment|/*  97 */
name|ED_INSERT
block|,
comment|/* a */
comment|/*  98 */
name|ED_INSERT
block|,
comment|/* b */
comment|/*  99 */
name|ED_INSERT
block|,
comment|/* c */
comment|/* 100 */
name|ED_INSERT
block|,
comment|/* d */
comment|/* 101 */
name|ED_INSERT
block|,
comment|/* e */
comment|/* 102 */
name|ED_INSERT
block|,
comment|/* f */
comment|/* 103 */
name|ED_INSERT
block|,
comment|/* g */
comment|/* 104 */
name|ED_INSERT
block|,
comment|/* h */
comment|/* 105 */
name|ED_INSERT
block|,
comment|/* i */
comment|/* 106 */
name|ED_INSERT
block|,
comment|/* j */
comment|/* 107 */
name|ED_INSERT
block|,
comment|/* k */
comment|/* 108 */
name|ED_INSERT
block|,
comment|/* l */
comment|/* 109 */
name|ED_INSERT
block|,
comment|/* m */
comment|/* 110 */
name|ED_INSERT
block|,
comment|/* n */
comment|/* 111 */
name|ED_INSERT
block|,
comment|/* o */
comment|/* 112 */
name|ED_INSERT
block|,
comment|/* p */
comment|/* 113 */
name|ED_INSERT
block|,
comment|/* q */
comment|/* 114 */
name|ED_INSERT
block|,
comment|/* r */
comment|/* 115 */
name|ED_INSERT
block|,
comment|/* s */
comment|/* 116 */
name|ED_INSERT
block|,
comment|/* t */
comment|/* 117 */
name|ED_INSERT
block|,
comment|/* u */
comment|/* 118 */
name|ED_INSERT
block|,
comment|/* v */
comment|/* 119 */
name|ED_INSERT
block|,
comment|/* w */
comment|/* 120 */
name|ED_INSERT
block|,
comment|/* x */
comment|/* 121 */
name|ED_INSERT
block|,
comment|/* y */
comment|/* 122 */
name|ED_INSERT
block|,
comment|/* z */
comment|/* 123 */
name|ED_INSERT
block|,
comment|/* { */
comment|/* 124 */
name|ED_INSERT
block|,
comment|/* | */
comment|/* 125 */
name|ED_INSERT
block|,
comment|/* } */
comment|/* 126 */
name|ED_INSERT
block|,
comment|/* ~ */
comment|/* 127 */
name|VI_DELETE_PREV_CHAR
block|,
comment|/* ^? */
comment|/* 128 */
name|ED_INSERT
block|,
comment|/* M-^@ */
comment|/* 129 */
name|ED_INSERT
block|,
comment|/* M-^A */
comment|/* 130 */
name|ED_INSERT
block|,
comment|/* M-^B */
comment|/* 131 */
name|ED_INSERT
block|,
comment|/* M-^C */
comment|/* 132 */
name|ED_INSERT
block|,
comment|/* M-^D */
comment|/* 133 */
name|ED_INSERT
block|,
comment|/* M-^E */
comment|/* 134 */
name|ED_INSERT
block|,
comment|/* M-^F */
comment|/* 135 */
name|ED_INSERT
block|,
comment|/* M-^G */
comment|/* 136 */
name|ED_INSERT
block|,
comment|/* M-^H */
comment|/* 137 */
name|ED_INSERT
block|,
comment|/* M-^I */
comment|/* 138 */
name|ED_INSERT
block|,
comment|/* M-^J */
comment|/* 139 */
name|ED_INSERT
block|,
comment|/* M-^K */
comment|/* 140 */
name|ED_INSERT
block|,
comment|/* M-^L */
comment|/* 141 */
name|ED_INSERT
block|,
comment|/* M-^M */
comment|/* 142 */
name|ED_INSERT
block|,
comment|/* M-^N */
comment|/* 143 */
name|ED_INSERT
block|,
comment|/* M-^O */
comment|/* 144 */
name|ED_INSERT
block|,
comment|/* M-^P */
comment|/* 145 */
name|ED_INSERT
block|,
comment|/* M-^Q */
comment|/* 146 */
name|ED_INSERT
block|,
comment|/* M-^R */
comment|/* 147 */
name|ED_INSERT
block|,
comment|/* M-^S */
comment|/* 148 */
name|ED_INSERT
block|,
comment|/* M-^T */
comment|/* 149 */
name|ED_INSERT
block|,
comment|/* M-^U */
comment|/* 150 */
name|ED_INSERT
block|,
comment|/* M-^V */
comment|/* 151 */
name|ED_INSERT
block|,
comment|/* M-^W */
comment|/* 152 */
name|ED_INSERT
block|,
comment|/* M-^X */
comment|/* 153 */
name|ED_INSERT
block|,
comment|/* M-^Y */
comment|/* 154 */
name|ED_INSERT
block|,
comment|/* M-^Z */
comment|/* 155 */
name|ED_INSERT
block|,
comment|/* M-^[ */
comment|/* 156 */
name|ED_INSERT
block|,
comment|/* M-^\ */
comment|/* 157 */
name|ED_INSERT
block|,
comment|/* M-^] */
comment|/* 158 */
name|ED_INSERT
block|,
comment|/* M-^^ */
comment|/* 159 */
name|ED_INSERT
block|,
comment|/* M-^_ */
comment|/* 160 */
name|ED_INSERT
block|,
comment|/* M-SPACE */
comment|/* 161 */
name|ED_INSERT
block|,
comment|/* M-! */
comment|/* 162 */
name|ED_INSERT
block|,
comment|/* M-" */
comment|/* 163 */
name|ED_INSERT
block|,
comment|/* M-# */
comment|/* 164 */
name|ED_INSERT
block|,
comment|/* M-$ */
comment|/* 165 */
name|ED_INSERT
block|,
comment|/* M-% */
comment|/* 166 */
name|ED_INSERT
block|,
comment|/* M-& */
comment|/* 167 */
name|ED_INSERT
block|,
comment|/* M-' */
comment|/* 168 */
name|ED_INSERT
block|,
comment|/* M-( */
comment|/* 169 */
name|ED_INSERT
block|,
comment|/* M-) */
comment|/* 170 */
name|ED_INSERT
block|,
comment|/* M-* */
comment|/* 171 */
name|ED_INSERT
block|,
comment|/* M-+ */
comment|/* 172 */
name|ED_INSERT
block|,
comment|/* M-, */
comment|/* 173 */
name|ED_INSERT
block|,
comment|/* M-- */
comment|/* 174 */
name|ED_INSERT
block|,
comment|/* M-. */
comment|/* 175 */
name|ED_INSERT
block|,
comment|/* M-/ */
comment|/* 176 */
name|ED_INSERT
block|,
comment|/* M-0 */
comment|/* 177 */
name|ED_INSERT
block|,
comment|/* M-1 */
comment|/* 178 */
name|ED_INSERT
block|,
comment|/* M-2 */
comment|/* 179 */
name|ED_INSERT
block|,
comment|/* M-3 */
comment|/* 180 */
name|ED_INSERT
block|,
comment|/* M-4 */
comment|/* 181 */
name|ED_INSERT
block|,
comment|/* M-5 */
comment|/* 182 */
name|ED_INSERT
block|,
comment|/* M-6 */
comment|/* 183 */
name|ED_INSERT
block|,
comment|/* M-7 */
comment|/* 184 */
name|ED_INSERT
block|,
comment|/* M-8 */
comment|/* 185 */
name|ED_INSERT
block|,
comment|/* M-9 */
comment|/* 186 */
name|ED_INSERT
block|,
comment|/* M-: */
comment|/* 187 */
name|ED_INSERT
block|,
comment|/* M-; */
comment|/* 188 */
name|ED_INSERT
block|,
comment|/* M-< */
comment|/* 189 */
name|ED_INSERT
block|,
comment|/* M-= */
comment|/* 190 */
name|ED_INSERT
block|,
comment|/* M-> */
comment|/* 191 */
name|ED_INSERT
block|,
comment|/* M-? */
comment|/* 192 */
name|ED_INSERT
block|,
comment|/* M-@ */
comment|/* 193 */
name|ED_INSERT
block|,
comment|/* M-A */
comment|/* 194 */
name|ED_INSERT
block|,
comment|/* M-B */
comment|/* 195 */
name|ED_INSERT
block|,
comment|/* M-C */
comment|/* 196 */
name|ED_INSERT
block|,
comment|/* M-D */
comment|/* 197 */
name|ED_INSERT
block|,
comment|/* M-E */
comment|/* 198 */
name|ED_INSERT
block|,
comment|/* M-F */
comment|/* 199 */
name|ED_INSERT
block|,
comment|/* M-G */
comment|/* 200 */
name|ED_INSERT
block|,
comment|/* M-H */
comment|/* 201 */
name|ED_INSERT
block|,
comment|/* M-I */
comment|/* 202 */
name|ED_INSERT
block|,
comment|/* M-J */
comment|/* 203 */
name|ED_INSERT
block|,
comment|/* M-K */
comment|/* 204 */
name|ED_INSERT
block|,
comment|/* M-L */
comment|/* 205 */
name|ED_INSERT
block|,
comment|/* M-M */
comment|/* 206 */
name|ED_INSERT
block|,
comment|/* M-N */
comment|/* 207 */
name|ED_INSERT
block|,
comment|/* M-O */
comment|/* 208 */
name|ED_INSERT
block|,
comment|/* M-P */
comment|/* 209 */
name|ED_INSERT
block|,
comment|/* M-Q */
comment|/* 210 */
name|ED_INSERT
block|,
comment|/* M-R */
comment|/* 211 */
name|ED_INSERT
block|,
comment|/* M-S */
comment|/* 212 */
name|ED_INSERT
block|,
comment|/* M-T */
comment|/* 213 */
name|ED_INSERT
block|,
comment|/* M-U */
comment|/* 214 */
name|ED_INSERT
block|,
comment|/* M-V */
comment|/* 215 */
name|ED_INSERT
block|,
comment|/* M-W */
comment|/* 216 */
name|ED_INSERT
block|,
comment|/* M-X */
comment|/* 217 */
name|ED_INSERT
block|,
comment|/* M-Y */
comment|/* 218 */
name|ED_INSERT
block|,
comment|/* M-Z */
comment|/* 219 */
name|ED_INSERT
block|,
comment|/* M-[ */
comment|/* 220 */
name|ED_INSERT
block|,
comment|/* M-\ */
comment|/* 221 */
name|ED_INSERT
block|,
comment|/* M-] */
comment|/* 222 */
name|ED_INSERT
block|,
comment|/* M-^ */
comment|/* 223 */
name|ED_INSERT
block|,
comment|/* M-_ */
comment|/* 224 */
name|ED_INSERT
block|,
comment|/* M-` */
comment|/* 225 */
name|ED_INSERT
block|,
comment|/* M-a */
comment|/* 226 */
name|ED_INSERT
block|,
comment|/* M-b */
comment|/* 227 */
name|ED_INSERT
block|,
comment|/* M-c */
comment|/* 228 */
name|ED_INSERT
block|,
comment|/* M-d */
comment|/* 229 */
name|ED_INSERT
block|,
comment|/* M-e */
comment|/* 230 */
name|ED_INSERT
block|,
comment|/* M-f */
comment|/* 231 */
name|ED_INSERT
block|,
comment|/* M-g */
comment|/* 232 */
name|ED_INSERT
block|,
comment|/* M-h */
comment|/* 233 */
name|ED_INSERT
block|,
comment|/* M-i */
comment|/* 234 */
name|ED_INSERT
block|,
comment|/* M-j */
comment|/* 235 */
name|ED_INSERT
block|,
comment|/* M-k */
comment|/* 236 */
name|ED_INSERT
block|,
comment|/* M-l */
comment|/* 237 */
name|ED_INSERT
block|,
comment|/* M-m */
comment|/* 238 */
name|ED_INSERT
block|,
comment|/* M-n */
comment|/* 239 */
name|ED_INSERT
block|,
comment|/* M-o */
comment|/* 240 */
name|ED_INSERT
block|,
comment|/* M-p */
comment|/* 241 */
name|ED_INSERT
block|,
comment|/* M-q */
comment|/* 242 */
name|ED_INSERT
block|,
comment|/* M-r */
comment|/* 243 */
name|ED_INSERT
block|,
comment|/* M-s */
comment|/* 244 */
name|ED_INSERT
block|,
comment|/* M-t */
comment|/* 245 */
name|ED_INSERT
block|,
comment|/* M-u */
comment|/* 246 */
name|ED_INSERT
block|,
comment|/* M-v */
comment|/* 247 */
name|ED_INSERT
block|,
comment|/* M-w */
comment|/* 248 */
name|ED_INSERT
block|,
comment|/* M-x */
comment|/* 249 */
name|ED_INSERT
block|,
comment|/* M-y */
comment|/* 250 */
name|ED_INSERT
block|,
comment|/* M-z */
comment|/* 251 */
name|ED_INSERT
block|,
comment|/* M-{ */
comment|/* 252 */
name|ED_INSERT
block|,
comment|/* M-| */
comment|/* 253 */
name|ED_INSERT
block|,
comment|/* M-} */
comment|/* 254 */
name|ED_INSERT
block|,
comment|/* M-~ */
comment|/* 255 */
name|ED_INSERT
comment|/* M-^? */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|private
specifier|const
name|el_action_t
name|el_map_vi_command
index|[]
init|=
block|{
comment|/*   0 */
name|ED_UNASSIGNED
block|,
comment|/* ^@ */
comment|/*   1 */
name|ED_MOVE_TO_BEG
block|,
comment|/* ^A */
comment|/*   2 */
name|ED_UNASSIGNED
block|,
comment|/* ^B */
comment|/*   3 */
name|ED_TTY_SIGINT
block|,
comment|/* ^C */
comment|/*   4 */
name|ED_UNASSIGNED
block|,
comment|/* ^D */
comment|/*   5 */
name|ED_MOVE_TO_END
block|,
comment|/* ^E */
comment|/*   6 */
name|ED_UNASSIGNED
block|,
comment|/* ^F */
comment|/*   7 */
name|ED_UNASSIGNED
block|,
comment|/* ^G */
comment|/*   8 */
name|ED_DELETE_PREV_CHAR
block|,
comment|/* ^H */
comment|/*   9 */
name|ED_UNASSIGNED
block|,
comment|/* ^I */
comment|/*  10 */
name|ED_NEWLINE
block|,
comment|/* ^J */
comment|/*  11 */
name|ED_KILL_LINE
block|,
comment|/* ^K */
comment|/*  12 */
name|ED_CLEAR_SCREEN
block|,
comment|/* ^L */
comment|/*  13 */
name|ED_NEWLINE
block|,
comment|/* ^M */
comment|/*  14 */
name|ED_NEXT_HISTORY
block|,
comment|/* ^N */
comment|/*  15 */
name|ED_TTY_FLUSH_OUTPUT
block|,
comment|/* ^O */
comment|/*  16 */
name|ED_PREV_HISTORY
block|,
comment|/* ^P */
comment|/*  17 */
name|ED_TTY_START_OUTPUT
block|,
comment|/* ^Q */
comment|/*  18 */
name|ED_REDISPLAY
block|,
comment|/* ^R */
comment|/*  19 */
name|ED_TTY_STOP_OUTPUT
block|,
comment|/* ^S */
comment|/*  20 */
name|ED_UNASSIGNED
block|,
comment|/* ^T */
comment|/*  21 */
name|VI_KILL_LINE_PREV
block|,
comment|/* ^U */
comment|/*  22 */
name|ED_UNASSIGNED
block|,
comment|/* ^V */
comment|/*  23 */
name|ED_DELETE_PREV_WORD
block|,
comment|/* ^W */
comment|/*  24 */
name|ED_UNASSIGNED
block|,
comment|/* ^X */
comment|/*  25 */
name|ED_UNASSIGNED
block|,
comment|/* ^Y */
comment|/*  26 */
name|ED_UNASSIGNED
block|,
comment|/* ^Z */
comment|/*  27 */
name|EM_META_NEXT
block|,
comment|/* ^[ */
comment|/*  28 */
name|ED_TTY_SIGQUIT
block|,
comment|/* ^\ */
comment|/*  29 */
name|ED_UNASSIGNED
block|,
comment|/* ^] */
comment|/*  30 */
name|ED_UNASSIGNED
block|,
comment|/* ^^ */
comment|/*  31 */
name|ED_UNASSIGNED
block|,
comment|/* ^_ */
comment|/*  32 */
name|ED_NEXT_CHAR
block|,
comment|/* SPACE */
comment|/*  33 */
name|ED_UNASSIGNED
block|,
comment|/* ! */
comment|/*  34 */
name|ED_UNASSIGNED
block|,
comment|/* " */
comment|/*  35 */
name|VI_COMMENT_OUT
block|,
comment|/* # */
comment|/*  36 */
name|ED_MOVE_TO_END
block|,
comment|/* $ */
comment|/*  37 */
name|VI_MATCH
block|,
comment|/* % */
comment|/*  38 */
name|ED_UNASSIGNED
block|,
comment|/*& */
comment|/*  39 */
name|ED_UNASSIGNED
block|,
comment|/* ' */
comment|/*  40 */
name|ED_UNASSIGNED
block|,
comment|/* ( */
comment|/*  41 */
name|ED_UNASSIGNED
block|,
comment|/* ) */
comment|/*  42 */
name|ED_UNASSIGNED
block|,
comment|/* * */
comment|/*  43 */
name|ED_NEXT_HISTORY
block|,
comment|/* + */
comment|/*  44 */
name|VI_REPEAT_PREV_CHAR
block|,
comment|/* , */
comment|/*  45 */
name|ED_PREV_HISTORY
block|,
comment|/* - */
comment|/*  46 */
name|VI_REDO
block|,
comment|/* . */
comment|/*  47 */
name|VI_SEARCH_PREV
block|,
comment|/* / */
comment|/*  48 */
name|VI_ZERO
block|,
comment|/* 0 */
comment|/*  49 */
name|ED_ARGUMENT_DIGIT
block|,
comment|/* 1 */
comment|/*  50 */
name|ED_ARGUMENT_DIGIT
block|,
comment|/* 2 */
comment|/*  51 */
name|ED_ARGUMENT_DIGIT
block|,
comment|/* 3 */
comment|/*  52 */
name|ED_ARGUMENT_DIGIT
block|,
comment|/* 4 */
comment|/*  53 */
name|ED_ARGUMENT_DIGIT
block|,
comment|/* 5 */
comment|/*  54 */
name|ED_ARGUMENT_DIGIT
block|,
comment|/* 6 */
comment|/*  55 */
name|ED_ARGUMENT_DIGIT
block|,
comment|/* 7 */
comment|/*  56 */
name|ED_ARGUMENT_DIGIT
block|,
comment|/* 8 */
comment|/*  57 */
name|ED_ARGUMENT_DIGIT
block|,
comment|/* 9 */
comment|/*  58 */
name|ED_COMMAND
block|,
comment|/* : */
comment|/*  59 */
name|VI_REPEAT_NEXT_CHAR
block|,
comment|/* ; */
comment|/*  60 */
name|ED_UNASSIGNED
block|,
comment|/*< */
comment|/*  61 */
name|ED_UNASSIGNED
block|,
comment|/* = */
comment|/*  62 */
name|ED_UNASSIGNED
block|,
comment|/*> */
comment|/*  63 */
name|VI_SEARCH_NEXT
block|,
comment|/* ? */
comment|/*  64 */
name|VI_ALIAS
block|,
comment|/* @ */
comment|/*  65 */
name|VI_ADD_AT_EOL
block|,
comment|/* A */
comment|/*  66 */
name|VI_PREV_BIG_WORD
block|,
comment|/* B */
comment|/*  67 */
name|VI_CHANGE_TO_EOL
block|,
comment|/* C */
comment|/*  68 */
name|ED_KILL_LINE
block|,
comment|/* D */
comment|/*  69 */
name|VI_END_BIG_WORD
block|,
comment|/* E */
comment|/*  70 */
name|VI_PREV_CHAR
block|,
comment|/* F */
comment|/*  71 */
name|VI_TO_HISTORY_LINE
block|,
comment|/* G */
comment|/*  72 */
name|ED_UNASSIGNED
block|,
comment|/* H */
comment|/*  73 */
name|VI_INSERT_AT_BOL
block|,
comment|/* I */
comment|/*  74 */
name|ED_SEARCH_NEXT_HISTORY
block|,
comment|/* J */
comment|/*  75 */
name|ED_SEARCH_PREV_HISTORY
block|,
comment|/* K */
comment|/*  76 */
name|ED_UNASSIGNED
block|,
comment|/* L */
comment|/*  77 */
name|ED_UNASSIGNED
block|,
comment|/* M */
comment|/*  78 */
name|VI_REPEAT_SEARCH_PREV
block|,
comment|/* N */
comment|/*  79 */
name|ED_SEQUENCE_LEAD_IN
block|,
comment|/* O */
comment|/*  80 */
name|VI_PASTE_PREV
block|,
comment|/* P */
comment|/*  81 */
name|ED_UNASSIGNED
block|,
comment|/* Q */
comment|/*  82 */
name|VI_REPLACE_MODE
block|,
comment|/* R */
comment|/*  83 */
name|VI_SUBSTITUTE_LINE
block|,
comment|/* S */
comment|/*  84 */
name|VI_TO_PREV_CHAR
block|,
comment|/* T */
comment|/*  85 */
name|VI_UNDO_LINE
block|,
comment|/* U */
comment|/*  86 */
name|ED_UNASSIGNED
block|,
comment|/* V */
comment|/*  87 */
name|VI_NEXT_BIG_WORD
block|,
comment|/* W */
comment|/*  88 */
name|ED_DELETE_PREV_CHAR
block|,
comment|/* X */
comment|/*  89 */
name|VI_YANK_END
block|,
comment|/* Y */
comment|/*  90 */
name|ED_UNASSIGNED
block|,
comment|/* Z */
comment|/*  91 */
name|ED_SEQUENCE_LEAD_IN
block|,
comment|/* [ */
comment|/*  92 */
name|ED_UNASSIGNED
block|,
comment|/* \ */
comment|/*  93 */
name|ED_UNASSIGNED
block|,
comment|/* ] */
comment|/*  94 */
name|ED_MOVE_TO_BEG
block|,
comment|/* ^ */
comment|/*  95 */
name|VI_HISTORY_WORD
block|,
comment|/* _ */
comment|/*  96 */
name|ED_UNASSIGNED
block|,
comment|/* ` */
comment|/*  97 */
name|VI_ADD
block|,
comment|/* a */
comment|/*  98 */
name|VI_PREV_WORD
block|,
comment|/* b */
comment|/*  99 */
name|VI_CHANGE_META
block|,
comment|/* c */
comment|/* 100 */
name|VI_DELETE_META
block|,
comment|/* d */
comment|/* 101 */
name|VI_END_WORD
block|,
comment|/* e */
comment|/* 102 */
name|VI_NEXT_CHAR
block|,
comment|/* f */
comment|/* 103 */
name|ED_UNASSIGNED
block|,
comment|/* g */
comment|/* 104 */
name|ED_PREV_CHAR
block|,
comment|/* h */
comment|/* 105 */
name|VI_INSERT
block|,
comment|/* i */
comment|/* 106 */
name|ED_NEXT_HISTORY
block|,
comment|/* j */
comment|/* 107 */
name|ED_PREV_HISTORY
block|,
comment|/* k */
comment|/* 108 */
name|ED_NEXT_CHAR
block|,
comment|/* l */
comment|/* 109 */
name|ED_UNASSIGNED
block|,
comment|/* m */
comment|/* 110 */
name|VI_REPEAT_SEARCH_NEXT
block|,
comment|/* n */
comment|/* 111 */
name|ED_UNASSIGNED
block|,
comment|/* o */
comment|/* 112 */
name|VI_PASTE_NEXT
block|,
comment|/* p */
comment|/* 113 */
name|ED_UNASSIGNED
block|,
comment|/* q */
comment|/* 114 */
name|VI_REPLACE_CHAR
block|,
comment|/* r */
comment|/* 115 */
name|VI_SUBSTITUTE_CHAR
block|,
comment|/* s */
comment|/* 116 */
name|VI_TO_NEXT_CHAR
block|,
comment|/* t */
comment|/* 117 */
name|VI_UNDO
block|,
comment|/* u */
comment|/* 118 */
name|VI_HISTEDIT
block|,
comment|/* v */
comment|/* 119 */
name|VI_NEXT_WORD
block|,
comment|/* w */
comment|/* 120 */
name|ED_DELETE_NEXT_CHAR
block|,
comment|/* x */
comment|/* 121 */
name|VI_YANK
block|,
comment|/* y */
comment|/* 122 */
name|ED_UNASSIGNED
block|,
comment|/* z */
comment|/* 123 */
name|ED_UNASSIGNED
block|,
comment|/* { */
comment|/* 124 */
name|VI_TO_COLUMN
block|,
comment|/* | */
comment|/* 125 */
name|ED_UNASSIGNED
block|,
comment|/* } */
comment|/* 126 */
name|VI_CHANGE_CASE
block|,
comment|/* ~ */
comment|/* 127 */
name|ED_DELETE_PREV_CHAR
block|,
comment|/* ^? */
comment|/* 128 */
name|ED_UNASSIGNED
block|,
comment|/* M-^@ */
comment|/* 129 */
name|ED_UNASSIGNED
block|,
comment|/* M-^A */
comment|/* 130 */
name|ED_UNASSIGNED
block|,
comment|/* M-^B */
comment|/* 131 */
name|ED_UNASSIGNED
block|,
comment|/* M-^C */
comment|/* 132 */
name|ED_UNASSIGNED
block|,
comment|/* M-^D */
comment|/* 133 */
name|ED_UNASSIGNED
block|,
comment|/* M-^E */
comment|/* 134 */
name|ED_UNASSIGNED
block|,
comment|/* M-^F */
comment|/* 135 */
name|ED_UNASSIGNED
block|,
comment|/* M-^G */
comment|/* 136 */
name|ED_UNASSIGNED
block|,
comment|/* M-^H */
comment|/* 137 */
name|ED_UNASSIGNED
block|,
comment|/* M-^I */
comment|/* 138 */
name|ED_UNASSIGNED
block|,
comment|/* M-^J */
comment|/* 139 */
name|ED_UNASSIGNED
block|,
comment|/* M-^K */
comment|/* 140 */
name|ED_UNASSIGNED
block|,
comment|/* M-^L */
comment|/* 141 */
name|ED_UNASSIGNED
block|,
comment|/* M-^M */
comment|/* 142 */
name|ED_UNASSIGNED
block|,
comment|/* M-^N */
comment|/* 143 */
name|ED_UNASSIGNED
block|,
comment|/* M-^O */
comment|/* 144 */
name|ED_UNASSIGNED
block|,
comment|/* M-^P */
comment|/* 145 */
name|ED_UNASSIGNED
block|,
comment|/* M-^Q */
comment|/* 146 */
name|ED_UNASSIGNED
block|,
comment|/* M-^R */
comment|/* 147 */
name|ED_UNASSIGNED
block|,
comment|/* M-^S */
comment|/* 148 */
name|ED_UNASSIGNED
block|,
comment|/* M-^T */
comment|/* 149 */
name|ED_UNASSIGNED
block|,
comment|/* M-^U */
comment|/* 150 */
name|ED_UNASSIGNED
block|,
comment|/* M-^V */
comment|/* 151 */
name|ED_UNASSIGNED
block|,
comment|/* M-^W */
comment|/* 152 */
name|ED_UNASSIGNED
block|,
comment|/* M-^X */
comment|/* 153 */
name|ED_UNASSIGNED
block|,
comment|/* M-^Y */
comment|/* 154 */
name|ED_UNASSIGNED
block|,
comment|/* M-^Z */
comment|/* 155 */
name|ED_UNASSIGNED
block|,
comment|/* M-^[ */
comment|/* 156 */
name|ED_UNASSIGNED
block|,
comment|/* M-^\ */
comment|/* 157 */
name|ED_UNASSIGNED
block|,
comment|/* M-^] */
comment|/* 158 */
name|ED_UNASSIGNED
block|,
comment|/* M-^^ */
comment|/* 159 */
name|ED_UNASSIGNED
block|,
comment|/* M-^_ */
comment|/* 160 */
name|ED_UNASSIGNED
block|,
comment|/* M-SPACE */
comment|/* 161 */
name|ED_UNASSIGNED
block|,
comment|/* M-! */
comment|/* 162 */
name|ED_UNASSIGNED
block|,
comment|/* M-" */
comment|/* 163 */
name|ED_UNASSIGNED
block|,
comment|/* M-# */
comment|/* 164 */
name|ED_UNASSIGNED
block|,
comment|/* M-$ */
comment|/* 165 */
name|ED_UNASSIGNED
block|,
comment|/* M-% */
comment|/* 166 */
name|ED_UNASSIGNED
block|,
comment|/* M-& */
comment|/* 167 */
name|ED_UNASSIGNED
block|,
comment|/* M-' */
comment|/* 168 */
name|ED_UNASSIGNED
block|,
comment|/* M-( */
comment|/* 169 */
name|ED_UNASSIGNED
block|,
comment|/* M-) */
comment|/* 170 */
name|ED_UNASSIGNED
block|,
comment|/* M-* */
comment|/* 171 */
name|ED_UNASSIGNED
block|,
comment|/* M-+ */
comment|/* 172 */
name|ED_UNASSIGNED
block|,
comment|/* M-, */
comment|/* 173 */
name|ED_UNASSIGNED
block|,
comment|/* M-- */
comment|/* 174 */
name|ED_UNASSIGNED
block|,
comment|/* M-. */
comment|/* 175 */
name|ED_UNASSIGNED
block|,
comment|/* M-/ */
comment|/* 176 */
name|ED_UNASSIGNED
block|,
comment|/* M-0 */
comment|/* 177 */
name|ED_UNASSIGNED
block|,
comment|/* M-1 */
comment|/* 178 */
name|ED_UNASSIGNED
block|,
comment|/* M-2 */
comment|/* 179 */
name|ED_UNASSIGNED
block|,
comment|/* M-3 */
comment|/* 180 */
name|ED_UNASSIGNED
block|,
comment|/* M-4 */
comment|/* 181 */
name|ED_UNASSIGNED
block|,
comment|/* M-5 */
comment|/* 182 */
name|ED_UNASSIGNED
block|,
comment|/* M-6 */
comment|/* 183 */
name|ED_UNASSIGNED
block|,
comment|/* M-7 */
comment|/* 184 */
name|ED_UNASSIGNED
block|,
comment|/* M-8 */
comment|/* 185 */
name|ED_UNASSIGNED
block|,
comment|/* M-9 */
comment|/* 186 */
name|ED_UNASSIGNED
block|,
comment|/* M-: */
comment|/* 187 */
name|ED_UNASSIGNED
block|,
comment|/* M-; */
comment|/* 188 */
name|ED_UNASSIGNED
block|,
comment|/* M-< */
comment|/* 189 */
name|ED_UNASSIGNED
block|,
comment|/* M-= */
comment|/* 190 */
name|ED_UNASSIGNED
block|,
comment|/* M-> */
comment|/* 191 */
name|ED_UNASSIGNED
block|,
comment|/* M-? */
comment|/* 192 */
name|ED_UNASSIGNED
block|,
comment|/* M-@ */
comment|/* 193 */
name|ED_UNASSIGNED
block|,
comment|/* M-A */
comment|/* 194 */
name|ED_UNASSIGNED
block|,
comment|/* M-B */
comment|/* 195 */
name|ED_UNASSIGNED
block|,
comment|/* M-C */
comment|/* 196 */
name|ED_UNASSIGNED
block|,
comment|/* M-D */
comment|/* 197 */
name|ED_UNASSIGNED
block|,
comment|/* M-E */
comment|/* 198 */
name|ED_UNASSIGNED
block|,
comment|/* M-F */
comment|/* 199 */
name|ED_UNASSIGNED
block|,
comment|/* M-G */
comment|/* 200 */
name|ED_UNASSIGNED
block|,
comment|/* M-H */
comment|/* 201 */
name|ED_UNASSIGNED
block|,
comment|/* M-I */
comment|/* 202 */
name|ED_UNASSIGNED
block|,
comment|/* M-J */
comment|/* 203 */
name|ED_UNASSIGNED
block|,
comment|/* M-K */
comment|/* 204 */
name|ED_UNASSIGNED
block|,
comment|/* M-L */
comment|/* 205 */
name|ED_UNASSIGNED
block|,
comment|/* M-M */
comment|/* 206 */
name|ED_UNASSIGNED
block|,
comment|/* M-N */
comment|/* 207 */
name|ED_SEQUENCE_LEAD_IN
block|,
comment|/* M-O */
comment|/* 208 */
name|ED_UNASSIGNED
block|,
comment|/* M-P */
comment|/* 209 */
name|ED_UNASSIGNED
block|,
comment|/* M-Q */
comment|/* 210 */
name|ED_UNASSIGNED
block|,
comment|/* M-R */
comment|/* 211 */
name|ED_UNASSIGNED
block|,
comment|/* M-S */
comment|/* 212 */
name|ED_UNASSIGNED
block|,
comment|/* M-T */
comment|/* 213 */
name|ED_UNASSIGNED
block|,
comment|/* M-U */
comment|/* 214 */
name|ED_UNASSIGNED
block|,
comment|/* M-V */
comment|/* 215 */
name|ED_UNASSIGNED
block|,
comment|/* M-W */
comment|/* 216 */
name|ED_UNASSIGNED
block|,
comment|/* M-X */
comment|/* 217 */
name|ED_UNASSIGNED
block|,
comment|/* M-Y */
comment|/* 218 */
name|ED_UNASSIGNED
block|,
comment|/* M-Z */
comment|/* 219 */
name|ED_SEQUENCE_LEAD_IN
block|,
comment|/* M-[ */
comment|/* 220 */
name|ED_UNASSIGNED
block|,
comment|/* M-\ */
comment|/* 221 */
name|ED_UNASSIGNED
block|,
comment|/* M-] */
comment|/* 222 */
name|ED_UNASSIGNED
block|,
comment|/* M-^ */
comment|/* 223 */
name|ED_UNASSIGNED
block|,
comment|/* M-_ */
comment|/* 224 */
name|ED_UNASSIGNED
block|,
comment|/* M-` */
comment|/* 225 */
name|ED_UNASSIGNED
block|,
comment|/* M-a */
comment|/* 226 */
name|ED_UNASSIGNED
block|,
comment|/* M-b */
comment|/* 227 */
name|ED_UNASSIGNED
block|,
comment|/* M-c */
comment|/* 228 */
name|ED_UNASSIGNED
block|,
comment|/* M-d */
comment|/* 229 */
name|ED_UNASSIGNED
block|,
comment|/* M-e */
comment|/* 230 */
name|ED_UNASSIGNED
block|,
comment|/* M-f */
comment|/* 231 */
name|ED_UNASSIGNED
block|,
comment|/* M-g */
comment|/* 232 */
name|ED_UNASSIGNED
block|,
comment|/* M-h */
comment|/* 233 */
name|ED_UNASSIGNED
block|,
comment|/* M-i */
comment|/* 234 */
name|ED_UNASSIGNED
block|,
comment|/* M-j */
comment|/* 235 */
name|ED_UNASSIGNED
block|,
comment|/* M-k */
comment|/* 236 */
name|ED_UNASSIGNED
block|,
comment|/* M-l */
comment|/* 237 */
name|ED_UNASSIGNED
block|,
comment|/* M-m */
comment|/* 238 */
name|ED_UNASSIGNED
block|,
comment|/* M-n */
comment|/* 239 */
name|ED_UNASSIGNED
block|,
comment|/* M-o */
comment|/* 240 */
name|ED_UNASSIGNED
block|,
comment|/* M-p */
comment|/* 241 */
name|ED_UNASSIGNED
block|,
comment|/* M-q */
comment|/* 242 */
name|ED_UNASSIGNED
block|,
comment|/* M-r */
comment|/* 243 */
name|ED_UNASSIGNED
block|,
comment|/* M-s */
comment|/* 244 */
name|ED_UNASSIGNED
block|,
comment|/* M-t */
comment|/* 245 */
name|ED_UNASSIGNED
block|,
comment|/* M-u */
comment|/* 246 */
name|ED_UNASSIGNED
block|,
comment|/* M-v */
comment|/* 247 */
name|ED_UNASSIGNED
block|,
comment|/* M-w */
comment|/* 248 */
name|ED_UNASSIGNED
block|,
comment|/* M-x */
comment|/* 249 */
name|ED_UNASSIGNED
block|,
comment|/* M-y */
comment|/* 250 */
name|ED_UNASSIGNED
block|,
comment|/* M-z */
comment|/* 251 */
name|ED_UNASSIGNED
block|,
comment|/* M-{ */
comment|/* 252 */
name|ED_UNASSIGNED
block|,
comment|/* M-| */
comment|/* 253 */
name|ED_UNASSIGNED
block|,
comment|/* M-} */
comment|/* 254 */
name|ED_UNASSIGNED
block|,
comment|/* M-~ */
comment|/* 255 */
name|ED_UNASSIGNED
comment|/* M-^? */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* map_init():  *	Initialize and allocate the maps  */
end_comment

begin_function
name|protected
name|int
name|map_init
parameter_list|(
name|EditLine
modifier|*
name|el
parameter_list|)
block|{
comment|/*          * Make sure those are correct before starting.          */
ifdef|#
directive|ifdef
name|MAP_DEBUG
if|if
condition|(
sizeof|sizeof
argument_list|(
name|el_map_emacs
argument_list|)
operator|!=
name|N_KEYS
operator|*
sizeof|sizeof
argument_list|(
name|el_action_t
argument_list|)
condition|)
name|EL_ABORT
argument_list|(
operator|(
name|el
operator|->
name|errfile
operator|,
literal|"Emacs map incorrect\n"
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
sizeof|sizeof
argument_list|(
name|el_map_vi_command
argument_list|)
operator|!=
name|N_KEYS
operator|*
sizeof|sizeof
argument_list|(
name|el_action_t
argument_list|)
condition|)
name|EL_ABORT
argument_list|(
operator|(
name|el
operator|->
name|errfile
operator|,
literal|"Vi command map incorrect\n"
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
sizeof|sizeof
argument_list|(
name|el_map_vi_insert
argument_list|)
operator|!=
name|N_KEYS
operator|*
sizeof|sizeof
argument_list|(
name|el_action_t
argument_list|)
condition|)
name|EL_ABORT
argument_list|(
operator|(
name|el
operator|->
name|errfile
operator|,
literal|"Vi insert map incorrect\n"
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|el
operator|->
name|el_map
operator|.
name|alt
operator|=
operator|(
name|el_action_t
operator|*
operator|)
name|el_malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|el_action_t
argument_list|)
operator|*
name|N_KEYS
argument_list|)
expr_stmt|;
if|if
condition|(
name|el
operator|->
name|el_map
operator|.
name|alt
operator|==
name|NULL
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|el
operator|->
name|el_map
operator|.
name|key
operator|=
operator|(
name|el_action_t
operator|*
operator|)
name|el_malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|el_action_t
argument_list|)
operator|*
name|N_KEYS
argument_list|)
expr_stmt|;
if|if
condition|(
name|el
operator|->
name|el_map
operator|.
name|key
operator|==
name|NULL
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|el
operator|->
name|el_map
operator|.
name|emacs
operator|=
name|el_map_emacs
expr_stmt|;
name|el
operator|->
name|el_map
operator|.
name|vic
operator|=
name|el_map_vi_command
expr_stmt|;
name|el
operator|->
name|el_map
operator|.
name|vii
operator|=
name|el_map_vi_insert
expr_stmt|;
name|el
operator|->
name|el_map
operator|.
name|help
operator|=
operator|(
name|el_bindings_t
operator|*
operator|)
name|el_malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|el_bindings_t
argument_list|)
operator|*
name|EL_NUM_FCNS
argument_list|)
expr_stmt|;
if|if
condition|(
name|el
operator|->
name|el_map
operator|.
name|help
operator|==
name|NULL
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
operator|(
name|void
operator|)
name|memcpy
argument_list|(
name|el
operator|->
name|el_map
operator|.
name|help
argument_list|,
name|help__get
argument_list|()
argument_list|,
sizeof|sizeof
argument_list|(
name|el_bindings_t
argument_list|)
operator|*
name|EL_NUM_FCNS
argument_list|)
expr_stmt|;
name|el
operator|->
name|el_map
operator|.
name|func
operator|=
operator|(
name|el_func_t
operator|*
operator|)
name|el_malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|el_func_t
argument_list|)
operator|*
name|EL_NUM_FCNS
argument_list|)
expr_stmt|;
if|if
condition|(
name|el
operator|->
name|el_map
operator|.
name|func
operator|==
name|NULL
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|memcpy
argument_list|(
name|el
operator|->
name|el_map
operator|.
name|func
argument_list|,
name|func__get
argument_list|()
argument_list|,
sizeof|sizeof
argument_list|(
name|el_func_t
argument_list|)
operator|*
name|EL_NUM_FCNS
argument_list|)
expr_stmt|;
name|el
operator|->
name|el_map
operator|.
name|nfunc
operator|=
name|EL_NUM_FCNS
expr_stmt|;
ifdef|#
directive|ifdef
name|VIDEFAULT
name|map_init_vi
argument_list|(
name|el
argument_list|)
expr_stmt|;
else|#
directive|else
name|map_init_emacs
argument_list|(
name|el
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* VIDEFAULT */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* map_end():  *	Free the space taken by the editor maps  */
end_comment

begin_function
name|protected
name|void
name|map_end
parameter_list|(
name|EditLine
modifier|*
name|el
parameter_list|)
block|{
name|el_free
argument_list|(
operator|(
name|ptr_t
operator|)
name|el
operator|->
name|el_map
operator|.
name|alt
argument_list|)
expr_stmt|;
name|el
operator|->
name|el_map
operator|.
name|alt
operator|=
name|NULL
expr_stmt|;
name|el_free
argument_list|(
operator|(
name|ptr_t
operator|)
name|el
operator|->
name|el_map
operator|.
name|key
argument_list|)
expr_stmt|;
name|el
operator|->
name|el_map
operator|.
name|key
operator|=
name|NULL
expr_stmt|;
name|el
operator|->
name|el_map
operator|.
name|emacs
operator|=
name|NULL
expr_stmt|;
name|el
operator|->
name|el_map
operator|.
name|vic
operator|=
name|NULL
expr_stmt|;
name|el
operator|->
name|el_map
operator|.
name|vii
operator|=
name|NULL
expr_stmt|;
name|el_free
argument_list|(
operator|(
name|ptr_t
operator|)
name|el
operator|->
name|el_map
operator|.
name|help
argument_list|)
expr_stmt|;
name|el
operator|->
name|el_map
operator|.
name|help
operator|=
name|NULL
expr_stmt|;
name|el_free
argument_list|(
operator|(
name|ptr_t
operator|)
name|el
operator|->
name|el_map
operator|.
name|func
argument_list|)
expr_stmt|;
name|el
operator|->
name|el_map
operator|.
name|func
operator|=
name|NULL
expr_stmt|;
block|}
end_function

begin_comment
comment|/* map_init_nls():  *	Find all the printable keys and bind them to self insert  */
end_comment

begin_function
name|private
name|void
name|map_init_nls
parameter_list|(
name|EditLine
modifier|*
name|el
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|el_action_t
modifier|*
name|map
init|=
name|el
operator|->
name|el_map
operator|.
name|key
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0200
init|;
name|i
operator|<=
literal|0377
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|isprint
argument_list|(
name|i
argument_list|)
condition|)
name|map
index|[
name|i
index|]
operator|=
name|ED_INSERT
expr_stmt|;
block|}
end_function

begin_comment
comment|/* map_init_meta():  *	Bind all the meta keys to the appropriate ESC-<key> sequence  */
end_comment

begin_function
name|private
name|void
name|map_init_meta
parameter_list|(
name|EditLine
modifier|*
name|el
parameter_list|)
block|{
name|char
name|buf
index|[
literal|3
index|]
decl_stmt|;
name|int
name|i
decl_stmt|;
name|el_action_t
modifier|*
name|map
init|=
name|el
operator|->
name|el_map
operator|.
name|key
decl_stmt|;
name|el_action_t
modifier|*
name|alt
init|=
name|el
operator|->
name|el_map
operator|.
name|alt
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<=
literal|0377
operator|&&
name|map
index|[
name|i
index|]
operator|!=
name|EM_META_NEXT
condition|;
name|i
operator|++
control|)
continue|continue;
if|if
condition|(
name|i
operator|>
literal|0377
condition|)
block|{
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<=
literal|0377
operator|&&
name|alt
index|[
name|i
index|]
operator|!=
name|EM_META_NEXT
condition|;
name|i
operator|++
control|)
continue|continue;
if|if
condition|(
name|i
operator|>
literal|0377
condition|)
block|{
name|i
operator|=
literal|033
expr_stmt|;
if|if
condition|(
name|el
operator|->
name|el_map
operator|.
name|type
operator|==
name|MAP_VI
condition|)
name|map
operator|=
name|alt
expr_stmt|;
block|}
else|else
name|map
operator|=
name|alt
expr_stmt|;
block|}
name|buf
index|[
literal|0
index|]
operator|=
operator|(
name|char
operator|)
name|i
expr_stmt|;
name|buf
index|[
literal|2
index|]
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0200
init|;
name|i
operator|<=
literal|0377
condition|;
name|i
operator|++
control|)
switch|switch
condition|(
name|map
index|[
name|i
index|]
condition|)
block|{
case|case
name|ED_INSERT
case|:
case|case
name|ED_UNASSIGNED
case|:
case|case
name|ED_SEQUENCE_LEAD_IN
case|:
break|break;
default|default:
name|buf
index|[
literal|1
index|]
operator|=
name|i
operator|&
literal|0177
expr_stmt|;
name|key_add
argument_list|(
name|el
argument_list|,
name|buf
argument_list|,
name|key_map_cmd
argument_list|(
name|el
argument_list|,
operator|(
name|int
operator|)
name|map
index|[
name|i
index|]
argument_list|)
argument_list|,
name|XK_CMD
argument_list|)
expr_stmt|;
break|break;
block|}
name|map
index|[
operator|(
name|int
operator|)
name|buf
index|[
literal|0
index|]
index|]
operator|=
name|ED_SEQUENCE_LEAD_IN
expr_stmt|;
block|}
end_function

begin_comment
comment|/* map_init_vi():  *	Initialize the vi bindings  */
end_comment

begin_function
name|protected
name|void
name|map_init_vi
parameter_list|(
name|EditLine
modifier|*
name|el
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|el_action_t
modifier|*
name|key
init|=
name|el
operator|->
name|el_map
operator|.
name|key
decl_stmt|;
name|el_action_t
modifier|*
name|alt
init|=
name|el
operator|->
name|el_map
operator|.
name|alt
decl_stmt|;
specifier|const
name|el_action_t
modifier|*
name|vii
init|=
name|el
operator|->
name|el_map
operator|.
name|vii
decl_stmt|;
specifier|const
name|el_action_t
modifier|*
name|vic
init|=
name|el
operator|->
name|el_map
operator|.
name|vic
decl_stmt|;
name|el
operator|->
name|el_map
operator|.
name|type
operator|=
name|MAP_VI
expr_stmt|;
name|el
operator|->
name|el_map
operator|.
name|current
operator|=
name|el
operator|->
name|el_map
operator|.
name|key
expr_stmt|;
name|key_reset
argument_list|(
name|el
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|N_KEYS
condition|;
name|i
operator|++
control|)
block|{
name|key
index|[
name|i
index|]
operator|=
name|vii
index|[
name|i
index|]
expr_stmt|;
name|alt
index|[
name|i
index|]
operator|=
name|vic
index|[
name|i
index|]
expr_stmt|;
block|}
name|map_init_meta
argument_list|(
name|el
argument_list|)
expr_stmt|;
name|map_init_nls
argument_list|(
name|el
argument_list|)
expr_stmt|;
name|tty_bind_char
argument_list|(
name|el
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|term_bind_arrow
argument_list|(
name|el
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* map_init_emacs():  *	Initialize the emacs bindings  */
end_comment

begin_function
name|protected
name|void
name|map_init_emacs
parameter_list|(
name|EditLine
modifier|*
name|el
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|char
name|buf
index|[
literal|3
index|]
decl_stmt|;
name|el_action_t
modifier|*
name|key
init|=
name|el
operator|->
name|el_map
operator|.
name|key
decl_stmt|;
name|el_action_t
modifier|*
name|alt
init|=
name|el
operator|->
name|el_map
operator|.
name|alt
decl_stmt|;
specifier|const
name|el_action_t
modifier|*
name|emacs
init|=
name|el
operator|->
name|el_map
operator|.
name|emacs
decl_stmt|;
name|el
operator|->
name|el_map
operator|.
name|type
operator|=
name|MAP_EMACS
expr_stmt|;
name|el
operator|->
name|el_map
operator|.
name|current
operator|=
name|el
operator|->
name|el_map
operator|.
name|key
expr_stmt|;
name|key_reset
argument_list|(
name|el
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|N_KEYS
condition|;
name|i
operator|++
control|)
block|{
name|key
index|[
name|i
index|]
operator|=
name|emacs
index|[
name|i
index|]
expr_stmt|;
name|alt
index|[
name|i
index|]
operator|=
name|ED_UNASSIGNED
expr_stmt|;
block|}
name|map_init_meta
argument_list|(
name|el
argument_list|)
expr_stmt|;
name|map_init_nls
argument_list|(
name|el
argument_list|)
expr_stmt|;
name|buf
index|[
literal|0
index|]
operator|=
name|CONTROL
argument_list|(
literal|'X'
argument_list|)
expr_stmt|;
name|buf
index|[
literal|1
index|]
operator|=
name|CONTROL
argument_list|(
literal|'X'
argument_list|)
expr_stmt|;
name|buf
index|[
literal|2
index|]
operator|=
literal|0
expr_stmt|;
name|key_add
argument_list|(
name|el
argument_list|,
name|buf
argument_list|,
name|key_map_cmd
argument_list|(
name|el
argument_list|,
name|EM_EXCHANGE_MARK
argument_list|)
argument_list|,
name|XK_CMD
argument_list|)
expr_stmt|;
name|tty_bind_char
argument_list|(
name|el
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|term_bind_arrow
argument_list|(
name|el
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* map_set_editor():  *	Set the editor  */
end_comment

begin_function
name|protected
name|int
name|map_set_editor
parameter_list|(
name|EditLine
modifier|*
name|el
parameter_list|,
name|char
modifier|*
name|editor
parameter_list|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|editor
argument_list|,
literal|"emacs"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|map_init_emacs
argument_list|(
name|el
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
name|strcmp
argument_list|(
name|editor
argument_list|,
literal|"vi"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|map_init_vi
argument_list|(
name|el
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/* map_get_editor():  *	Retrieve the editor  */
end_comment

begin_function
name|protected
name|int
name|map_get_editor
parameter_list|(
name|EditLine
modifier|*
name|el
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|editor
parameter_list|)
block|{
if|if
condition|(
name|editor
operator|==
name|NULL
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
switch|switch
condition|(
name|el
operator|->
name|el_map
operator|.
name|type
condition|)
block|{
case|case
name|MAP_EMACS
case|:
operator|*
name|editor
operator|=
literal|"emacs"
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
name|MAP_VI
case|:
operator|*
name|editor
operator|=
literal|"vi"
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/* map_print_key():  *	Print the function description for 1 key  */
end_comment

begin_function
name|private
name|void
name|map_print_key
parameter_list|(
name|EditLine
modifier|*
name|el
parameter_list|,
name|el_action_t
modifier|*
name|map
parameter_list|,
specifier|const
name|char
modifier|*
name|in
parameter_list|)
block|{
name|char
name|outbuf
index|[
name|EL_BUFSIZ
index|]
decl_stmt|;
name|el_bindings_t
modifier|*
name|bp
decl_stmt|,
modifier|*
name|ep
decl_stmt|;
if|if
condition|(
name|in
index|[
literal|0
index|]
operator|==
literal|'\0'
operator|||
name|in
index|[
literal|1
index|]
operator|==
literal|'\0'
condition|)
block|{
operator|(
name|void
operator|)
name|key__decode_str
argument_list|(
name|in
argument_list|,
name|outbuf
argument_list|,
sizeof|sizeof
argument_list|(
name|outbuf
argument_list|)
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|ep
operator|=
operator|&
name|el
operator|->
name|el_map
operator|.
name|help
index|[
name|el
operator|->
name|el_map
operator|.
name|nfunc
index|]
expr_stmt|;
for|for
control|(
name|bp
operator|=
name|el
operator|->
name|el_map
operator|.
name|help
init|;
name|bp
operator|<
name|ep
condition|;
name|bp
operator|++
control|)
if|if
condition|(
name|bp
operator|->
name|func
operator|==
name|map
index|[
operator|(
name|unsigned
name|char
operator|)
operator|*
name|in
index|]
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|el
operator|->
name|el_outfile
argument_list|,
literal|"%s\t->\t%s\n"
argument_list|,
name|outbuf
argument_list|,
name|bp
operator|->
name|name
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
else|else
name|key_print
argument_list|(
name|el
argument_list|,
name|in
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* map_print_some_keys():  *	Print keys from first to last  */
end_comment

begin_function
name|private
name|void
name|map_print_some_keys
parameter_list|(
name|EditLine
modifier|*
name|el
parameter_list|,
name|el_action_t
modifier|*
name|map
parameter_list|,
name|int
name|first
parameter_list|,
name|int
name|last
parameter_list|)
block|{
name|el_bindings_t
modifier|*
name|bp
decl_stmt|,
modifier|*
name|ep
decl_stmt|;
name|char
name|firstbuf
index|[
literal|2
index|]
decl_stmt|,
name|lastbuf
index|[
literal|2
index|]
decl_stmt|;
name|char
name|unparsbuf
index|[
name|EL_BUFSIZ
index|]
decl_stmt|,
name|extrabuf
index|[
name|EL_BUFSIZ
index|]
decl_stmt|;
name|firstbuf
index|[
literal|0
index|]
operator|=
name|first
expr_stmt|;
name|firstbuf
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
name|lastbuf
index|[
literal|0
index|]
operator|=
name|last
expr_stmt|;
name|lastbuf
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|map
index|[
name|first
index|]
operator|==
name|ED_UNASSIGNED
condition|)
block|{
if|if
condition|(
name|first
operator|==
name|last
condition|)
block|{
operator|(
name|void
operator|)
name|key__decode_str
argument_list|(
name|firstbuf
argument_list|,
name|unparsbuf
argument_list|,
sizeof|sizeof
argument_list|(
name|unparsbuf
argument_list|)
argument_list|,
name|STRQQ
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|el
operator|->
name|el_outfile
argument_list|,
literal|"%-15s->  is undefined\n"
argument_list|,
name|unparsbuf
argument_list|)
expr_stmt|;
block|}
return|return;
block|}
name|ep
operator|=
operator|&
name|el
operator|->
name|el_map
operator|.
name|help
index|[
name|el
operator|->
name|el_map
operator|.
name|nfunc
index|]
expr_stmt|;
for|for
control|(
name|bp
operator|=
name|el
operator|->
name|el_map
operator|.
name|help
init|;
name|bp
operator|<
name|ep
condition|;
name|bp
operator|++
control|)
block|{
if|if
condition|(
name|bp
operator|->
name|func
operator|==
name|map
index|[
name|first
index|]
condition|)
block|{
if|if
condition|(
name|first
operator|==
name|last
condition|)
block|{
operator|(
name|void
operator|)
name|key__decode_str
argument_list|(
name|firstbuf
argument_list|,
name|unparsbuf
argument_list|,
sizeof|sizeof
argument_list|(
name|unparsbuf
argument_list|)
argument_list|,
name|STRQQ
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|el
operator|->
name|el_outfile
argument_list|,
literal|"%-15s->  %s\n"
argument_list|,
name|unparsbuf
argument_list|,
name|bp
operator|->
name|name
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|(
name|void
operator|)
name|key__decode_str
argument_list|(
name|firstbuf
argument_list|,
name|unparsbuf
argument_list|,
sizeof|sizeof
argument_list|(
name|unparsbuf
argument_list|)
argument_list|,
name|STRQQ
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|key__decode_str
argument_list|(
name|lastbuf
argument_list|,
name|extrabuf
argument_list|,
sizeof|sizeof
argument_list|(
name|extrabuf
argument_list|)
argument_list|,
name|STRQQ
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|el
operator|->
name|el_outfile
argument_list|,
literal|"%-4s to %-7s->  %s\n"
argument_list|,
name|unparsbuf
argument_list|,
name|extrabuf
argument_list|,
name|bp
operator|->
name|name
argument_list|)
expr_stmt|;
block|}
return|return;
block|}
block|}
ifdef|#
directive|ifdef
name|MAP_DEBUG
if|if
condition|(
name|map
operator|==
name|el
operator|->
name|el_map
operator|.
name|key
condition|)
block|{
operator|(
name|void
operator|)
name|key__decode_str
argument_list|(
name|firstbuf
argument_list|,
name|unparsbuf
argument_list|,
sizeof|sizeof
argument_list|(
name|unparsbuf
argument_list|)
argument_list|,
name|STRQQ
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|el
operator|->
name|el_outfile
argument_list|,
literal|"BUG!!! %s isn't bound to anything.\n"
argument_list|,
name|unparsbuf
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|el
operator|->
name|el_outfile
argument_list|,
literal|"el->el_map.key[%d] == %d\n"
argument_list|,
name|first
argument_list|,
name|el
operator|->
name|el_map
operator|.
name|key
index|[
name|first
index|]
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|(
name|void
operator|)
name|key__decode_str
argument_list|(
name|firstbuf
argument_list|,
name|unparsbuf
argument_list|,
sizeof|sizeof
argument_list|(
name|unparsbuf
argument_list|)
argument_list|,
name|STRQQ
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|el
operator|->
name|el_outfile
argument_list|,
literal|"BUG!!! %s isn't bound to anything.\n"
argument_list|,
name|unparsbuf
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|el
operator|->
name|el_outfile
argument_list|,
literal|"el->el_map.alt[%d] == %d\n"
argument_list|,
name|first
argument_list|,
name|el
operator|->
name|el_map
operator|.
name|alt
index|[
name|first
index|]
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|EL_ABORT
argument_list|(
operator|(
name|el
operator|->
name|el_errfile
operator|,
literal|"Error printing keys\n"
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* map_print_all_keys():  *	Print the function description for all keys.  */
end_comment

begin_function
name|private
name|void
name|map_print_all_keys
parameter_list|(
name|EditLine
modifier|*
name|el
parameter_list|)
block|{
name|int
name|prev
decl_stmt|,
name|i
decl_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|el
operator|->
name|el_outfile
argument_list|,
literal|"Standard key bindings\n"
argument_list|)
expr_stmt|;
name|prev
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|N_KEYS
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|el
operator|->
name|el_map
operator|.
name|key
index|[
name|prev
index|]
operator|==
name|el
operator|->
name|el_map
operator|.
name|key
index|[
name|i
index|]
condition|)
continue|continue;
name|map_print_some_keys
argument_list|(
name|el
argument_list|,
name|el
operator|->
name|el_map
operator|.
name|key
argument_list|,
name|prev
argument_list|,
name|i
operator|-
literal|1
argument_list|)
expr_stmt|;
name|prev
operator|=
name|i
expr_stmt|;
block|}
name|map_print_some_keys
argument_list|(
name|el
argument_list|,
name|el
operator|->
name|el_map
operator|.
name|key
argument_list|,
name|prev
argument_list|,
name|i
operator|-
literal|1
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|el
operator|->
name|el_outfile
argument_list|,
literal|"Alternative key bindings\n"
argument_list|)
expr_stmt|;
name|prev
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|N_KEYS
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|el
operator|->
name|el_map
operator|.
name|alt
index|[
name|prev
index|]
operator|==
name|el
operator|->
name|el_map
operator|.
name|alt
index|[
name|i
index|]
condition|)
continue|continue;
name|map_print_some_keys
argument_list|(
name|el
argument_list|,
name|el
operator|->
name|el_map
operator|.
name|alt
argument_list|,
name|prev
argument_list|,
name|i
operator|-
literal|1
argument_list|)
expr_stmt|;
name|prev
operator|=
name|i
expr_stmt|;
block|}
name|map_print_some_keys
argument_list|(
name|el
argument_list|,
name|el
operator|->
name|el_map
operator|.
name|alt
argument_list|,
name|prev
argument_list|,
name|i
operator|-
literal|1
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|el
operator|->
name|el_outfile
argument_list|,
literal|"Multi-character bindings\n"
argument_list|)
expr_stmt|;
name|key_print
argument_list|(
name|el
argument_list|,
literal|""
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|el
operator|->
name|el_outfile
argument_list|,
literal|"Arrow key bindings\n"
argument_list|)
expr_stmt|;
name|term_print_arrow
argument_list|(
name|el
argument_list|,
literal|""
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* map_bind():  *	Add/remove/change bindings  */
end_comment

begin_function
name|protected
name|int
name|map_bind
parameter_list|(
name|EditLine
modifier|*
name|el
parameter_list|,
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|el_action_t
modifier|*
name|map
decl_stmt|;
name|int
name|ntype
decl_stmt|,
name|rem
decl_stmt|;
specifier|const
name|char
modifier|*
name|p
decl_stmt|;
name|char
name|inbuf
index|[
name|EL_BUFSIZ
index|]
decl_stmt|;
name|char
name|outbuf
index|[
name|EL_BUFSIZ
index|]
decl_stmt|;
specifier|const
name|char
modifier|*
name|in
init|=
name|NULL
decl_stmt|;
name|char
modifier|*
name|out
init|=
name|NULL
decl_stmt|;
name|el_bindings_t
modifier|*
name|bp
decl_stmt|,
modifier|*
name|ep
decl_stmt|;
name|int
name|cmd
decl_stmt|;
name|int
name|key
decl_stmt|;
if|if
condition|(
name|argv
operator|==
name|NULL
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|map
operator|=
name|el
operator|->
name|el_map
operator|.
name|key
expr_stmt|;
name|ntype
operator|=
name|XK_CMD
expr_stmt|;
name|key
operator|=
name|rem
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|argc
operator|=
literal|1
init|;
operator|(
name|p
operator|=
name|argv
index|[
name|argc
index|]
operator|)
operator|!=
name|NULL
condition|;
name|argc
operator|++
control|)
if|if
condition|(
name|p
index|[
literal|0
index|]
operator|==
literal|'-'
condition|)
switch|switch
condition|(
name|p
index|[
literal|1
index|]
condition|)
block|{
case|case
literal|'a'
case|:
name|map
operator|=
name|el
operator|->
name|el_map
operator|.
name|alt
expr_stmt|;
break|break;
case|case
literal|'s'
case|:
name|ntype
operator|=
name|XK_STR
expr_stmt|;
break|break;
ifdef|#
directive|ifdef
name|notyet
case|case
literal|'c'
case|:
name|ntype
operator|=
name|XK_EXE
expr_stmt|;
break|break;
endif|#
directive|endif
case|case
literal|'k'
case|:
name|key
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'r'
case|:
name|rem
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'v'
case|:
name|map_init_vi
argument_list|(
name|el
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
literal|'e'
case|:
name|map_init_emacs
argument_list|(
name|el
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
literal|'l'
case|:
name|ep
operator|=
operator|&
name|el
operator|->
name|el_map
operator|.
name|help
index|[
name|el
operator|->
name|el_map
operator|.
name|nfunc
index|]
expr_stmt|;
for|for
control|(
name|bp
operator|=
name|el
operator|->
name|el_map
operator|.
name|help
init|;
name|bp
operator|<
name|ep
condition|;
name|bp
operator|++
control|)
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|el
operator|->
name|el_outfile
argument_list|,
literal|"%s\n\t%s\n"
argument_list|,
name|bp
operator|->
name|name
argument_list|,
name|bp
operator|->
name|description
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
default|default:
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|el
operator|->
name|el_errfile
argument_list|,
literal|"%s: Invalid switch `%c'.\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|,
name|p
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
else|else
break|break;
if|if
condition|(
name|argv
index|[
name|argc
index|]
operator|==
name|NULL
condition|)
block|{
name|map_print_all_keys
argument_list|(
name|el
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
name|key
condition|)
name|in
operator|=
name|argv
index|[
name|argc
operator|++
index|]
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
name|in
operator|=
name|parse__string
argument_list|(
name|inbuf
argument_list|,
name|argv
index|[
name|argc
operator|++
index|]
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|el
operator|->
name|el_errfile
argument_list|,
literal|"%s: Invalid \\ or ^ in instring.\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|rem
condition|)
block|{
if|if
condition|(
name|key
condition|)
block|{
operator|(
name|void
operator|)
name|term_clear_arrow
argument_list|(
name|el
argument_list|,
name|in
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|in
index|[
literal|1
index|]
condition|)
operator|(
name|void
operator|)
name|key_delete
argument_list|(
name|el
argument_list|,
name|in
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|map
index|[
operator|(
name|unsigned
name|char
operator|)
operator|*
name|in
index|]
operator|==
name|ED_SEQUENCE_LEAD_IN
condition|)
operator|(
name|void
operator|)
name|key_delete
argument_list|(
name|el
argument_list|,
name|in
argument_list|)
expr_stmt|;
else|else
name|map
index|[
operator|(
name|unsigned
name|char
operator|)
operator|*
name|in
index|]
operator|=
name|ED_UNASSIGNED
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
name|argv
index|[
name|argc
index|]
operator|==
name|NULL
condition|)
block|{
if|if
condition|(
name|key
condition|)
name|term_print_arrow
argument_list|(
name|el
argument_list|,
name|in
argument_list|)
expr_stmt|;
else|else
name|map_print_key
argument_list|(
name|el
argument_list|,
name|map
argument_list|,
name|in
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
ifdef|#
directive|ifdef
name|notyet
if|if
condition|(
name|argv
index|[
name|argc
operator|+
literal|1
index|]
operator|!=
name|NULL
condition|)
block|{
name|bindkey_usage
argument_list|()
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
endif|#
directive|endif
switch|switch
condition|(
name|ntype
condition|)
block|{
case|case
name|XK_STR
case|:
case|case
name|XK_EXE
case|:
if|if
condition|(
operator|(
name|out
operator|=
name|parse__string
argument_list|(
name|outbuf
argument_list|,
name|argv
index|[
name|argc
index|]
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|el
operator|->
name|el_errfile
argument_list|,
literal|"%s: Invalid \\ or ^ in outstring.\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|key
condition|)
name|term_set_arrow
argument_list|(
name|el
argument_list|,
name|in
argument_list|,
name|key_map_str
argument_list|(
name|el
argument_list|,
name|out
argument_list|)
argument_list|,
name|ntype
argument_list|)
expr_stmt|;
else|else
name|key_add
argument_list|(
name|el
argument_list|,
name|in
argument_list|,
name|key_map_str
argument_list|(
name|el
argument_list|,
name|out
argument_list|)
argument_list|,
name|ntype
argument_list|)
expr_stmt|;
name|map
index|[
operator|(
name|unsigned
name|char
operator|)
operator|*
name|in
index|]
operator|=
name|ED_SEQUENCE_LEAD_IN
expr_stmt|;
break|break;
case|case
name|XK_CMD
case|:
if|if
condition|(
operator|(
name|cmd
operator|=
name|parse_cmd
argument_list|(
name|el
argument_list|,
name|argv
index|[
name|argc
index|]
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|el
operator|->
name|el_errfile
argument_list|,
literal|"%s: Invalid command `%s'.\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|,
name|argv
index|[
name|argc
index|]
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|key
condition|)
name|term_set_arrow
argument_list|(
name|el
argument_list|,
name|in
argument_list|,
name|key_map_str
argument_list|(
name|el
argument_list|,
name|out
argument_list|)
argument_list|,
name|ntype
argument_list|)
expr_stmt|;
else|else
block|{
if|if
condition|(
name|in
index|[
literal|1
index|]
condition|)
block|{
name|key_add
argument_list|(
name|el
argument_list|,
name|in
argument_list|,
name|key_map_cmd
argument_list|(
name|el
argument_list|,
name|cmd
argument_list|)
argument_list|,
name|ntype
argument_list|)
expr_stmt|;
name|map
index|[
operator|(
name|unsigned
name|char
operator|)
operator|*
name|in
index|]
operator|=
name|ED_SEQUENCE_LEAD_IN
expr_stmt|;
block|}
else|else
block|{
name|key_clear
argument_list|(
name|el
argument_list|,
name|map
argument_list|,
name|in
argument_list|)
expr_stmt|;
name|map
index|[
operator|(
name|unsigned
name|char
operator|)
operator|*
name|in
index|]
operator|=
name|cmd
expr_stmt|;
block|}
block|}
break|break;
default|default:
name|EL_ABORT
argument_list|(
operator|(
name|el
operator|->
name|el_errfile
operator|,
literal|"Bad XK_ type %d\n"
operator|,
name|ntype
operator|)
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* map_addfunc():  *	add a user defined function  */
end_comment

begin_function
name|protected
name|int
name|map_addfunc
parameter_list|(
name|EditLine
modifier|*
name|el
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|help
parameter_list|,
name|el_func_t
name|func
parameter_list|)
block|{
name|void
modifier|*
name|p
decl_stmt|;
name|int
name|nf
init|=
name|el
operator|->
name|el_map
operator|.
name|nfunc
operator|+
literal|1
decl_stmt|;
if|if
condition|(
name|name
operator|==
name|NULL
operator|||
name|help
operator|==
name|NULL
operator|||
name|func
operator|==
name|NULL
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
operator|(
name|p
operator|=
name|el_realloc
argument_list|(
name|el
operator|->
name|el_map
operator|.
name|func
argument_list|,
name|nf
operator|*
sizeof|sizeof
argument_list|(
name|el_func_t
argument_list|)
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|el
operator|->
name|el_map
operator|.
name|func
operator|=
operator|(
name|el_func_t
operator|*
operator|)
name|p
expr_stmt|;
if|if
condition|(
operator|(
name|p
operator|=
name|el_realloc
argument_list|(
name|el
operator|->
name|el_map
operator|.
name|help
argument_list|,
name|nf
operator|*
sizeof|sizeof
argument_list|(
name|el_bindings_t
argument_list|)
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|el
operator|->
name|el_map
operator|.
name|help
operator|=
operator|(
name|el_bindings_t
operator|*
operator|)
name|p
expr_stmt|;
name|nf
operator|=
name|el
operator|->
name|el_map
operator|.
name|nfunc
expr_stmt|;
name|el
operator|->
name|el_map
operator|.
name|func
index|[
name|nf
index|]
operator|=
name|func
expr_stmt|;
name|el
operator|->
name|el_map
operator|.
name|help
index|[
name|nf
index|]
operator|.
name|name
operator|=
name|name
expr_stmt|;
name|el
operator|->
name|el_map
operator|.
name|help
index|[
name|nf
index|]
operator|.
name|func
operator|=
name|nf
expr_stmt|;
name|el
operator|->
name|el_map
operator|.
name|help
index|[
name|nf
index|]
operator|.
name|description
operator|=
name|help
expr_stmt|;
name|el
operator|->
name|el_map
operator|.
name|nfunc
operator|++
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

