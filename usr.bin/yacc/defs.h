begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Robert Paul Corbett.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)defs.h	5.6 (Berkeley) 5/24/93  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/*  machine-dependent definitions			*/
end_comment

begin_comment
comment|/*  the following definitions are for the Tahoe		*/
end_comment

begin_comment
comment|/*  they might have to be changed for other machines	*/
end_comment

begin_comment
comment|/*  MAXCHAR is the largest unsigned character value	*/
end_comment

begin_comment
comment|/*  MAXSHORT is the largest value of a C short		*/
end_comment

begin_comment
comment|/*  MINSHORT is the most negative value of a C short	*/
end_comment

begin_comment
comment|/*  MAXTABLE is the maximum table size			*/
end_comment

begin_comment
comment|/*  BITS_PER_WORD is the number of bits in a C unsigned	*/
end_comment

begin_comment
comment|/*  WORDSIZE computes the number of words needed to	*/
end_comment

begin_comment
comment|/*	store n bits					*/
end_comment

begin_comment
comment|/*  BIT returns the value of the n-th bit starting	*/
end_comment

begin_comment
comment|/*	from r (0-indexed)				*/
end_comment

begin_comment
comment|/*  SETBIT sets the n-th bit starting from r		*/
end_comment

begin_define
define|#
directive|define
name|MAXCHAR
value|255
end_define

begin_define
define|#
directive|define
name|MAXSHORT
value|32767
end_define

begin_define
define|#
directive|define
name|MINSHORT
value|-32768
end_define

begin_define
define|#
directive|define
name|MAXTABLE
value|32500
end_define

begin_define
define|#
directive|define
name|BITS_PER_WORD
value|32
end_define

begin_define
define|#
directive|define
name|WORDSIZE
parameter_list|(
name|n
parameter_list|)
value|(((n)+(BITS_PER_WORD-1))/BITS_PER_WORD)
end_define

begin_define
define|#
directive|define
name|BIT
parameter_list|(
name|r
parameter_list|,
name|n
parameter_list|)
value|((((r)[(n)>>5])>>((n)&31))&1)
end_define

begin_define
define|#
directive|define
name|SETBIT
parameter_list|(
name|r
parameter_list|,
name|n
parameter_list|)
value|((r)[(n)>>5]|=((unsigned)1<<((n)&31)))
end_define

begin_comment
comment|/*  character names  */
end_comment

begin_define
define|#
directive|define
name|NUL
value|'\0'
end_define

begin_comment
comment|/*  the null character  */
end_comment

begin_define
define|#
directive|define
name|NEWLINE
value|'\n'
end_define

begin_comment
comment|/*  line feed  */
end_comment

begin_define
define|#
directive|define
name|SP
value|' '
end_define

begin_comment
comment|/*  space  */
end_comment

begin_define
define|#
directive|define
name|BS
value|'\b'
end_define

begin_comment
comment|/*  backspace  */
end_comment

begin_define
define|#
directive|define
name|HT
value|'\t'
end_define

begin_comment
comment|/*  horizontal tab  */
end_comment

begin_define
define|#
directive|define
name|VT
value|'\013'
end_define

begin_comment
comment|/*  vertical tab  */
end_comment

begin_define
define|#
directive|define
name|CR
value|'\r'
end_define

begin_comment
comment|/*  carriage return  */
end_comment

begin_define
define|#
directive|define
name|FF
value|'\f'
end_define

begin_comment
comment|/*  form feed  */
end_comment

begin_define
define|#
directive|define
name|QUOTE
value|'\''
end_define

begin_comment
comment|/*  single quote  */
end_comment

begin_define
define|#
directive|define
name|DOUBLE_QUOTE
value|'\"'
end_define

begin_comment
comment|/*  double quote  */
end_comment

begin_define
define|#
directive|define
name|BACKSLASH
value|'\\'
end_define

begin_comment
comment|/*  backslash  */
end_comment

begin_comment
comment|/* defines for constructing filenames */
end_comment

begin_define
define|#
directive|define
name|CODE_SUFFIX
value|".code.c"
end_define

begin_define
define|#
directive|define
name|DEFINES_SUFFIX
value|".tab.h"
end_define

begin_define
define|#
directive|define
name|OUTPUT_SUFFIX
value|".tab.c"
end_define

begin_define
define|#
directive|define
name|VERBOSE_SUFFIX
value|".output"
end_define

begin_comment
comment|/* keyword codes */
end_comment

begin_define
define|#
directive|define
name|TOKEN
value|0
end_define

begin_define
define|#
directive|define
name|LEFT
value|1
end_define

begin_define
define|#
directive|define
name|RIGHT
value|2
end_define

begin_define
define|#
directive|define
name|NONASSOC
value|3
end_define

begin_define
define|#
directive|define
name|MARK
value|4
end_define

begin_define
define|#
directive|define
name|TEXT
value|5
end_define

begin_define
define|#
directive|define
name|TYPE
value|6
end_define

begin_define
define|#
directive|define
name|START
value|7
end_define

begin_define
define|#
directive|define
name|UNION
value|8
end_define

begin_define
define|#
directive|define
name|IDENT
value|9
end_define

begin_define
define|#
directive|define
name|EXPECT
value|10
end_define

begin_comment
comment|/*  symbol classes  */
end_comment

begin_define
define|#
directive|define
name|UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|TERM
value|1
end_define

begin_define
define|#
directive|define
name|NONTERM
value|2
end_define

begin_comment
comment|/*  the undefined value  */
end_comment

begin_define
define|#
directive|define
name|UNDEFINED
value|(-1)
end_define

begin_comment
comment|/*  action codes  */
end_comment

begin_define
define|#
directive|define
name|SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|REDUCE
value|2
end_define

begin_comment
comment|/*  character macros  */
end_comment

begin_define
define|#
directive|define
name|IS_IDENT
parameter_list|(
name|c
parameter_list|)
value|(isalnum(c) || (c) == '_' || (c) == '.' || (c) == '$')
end_define

begin_define
define|#
directive|define
name|IS_OCTAL
parameter_list|(
name|c
parameter_list|)
value|((c)>= '0'&& (c)<= '7')
end_define

begin_define
define|#
directive|define
name|NUMERIC_VALUE
parameter_list|(
name|c
parameter_list|)
value|((c) - '0')
end_define

begin_comment
comment|/*  symbol macros  */
end_comment

begin_define
define|#
directive|define
name|ISTOKEN
parameter_list|(
name|s
parameter_list|)
value|((s)< start_symbol)
end_define

begin_define
define|#
directive|define
name|ISVAR
parameter_list|(
name|s
parameter_list|)
value|((s)>= start_symbol)
end_define

begin_comment
comment|/*  storage allocation macros  */
end_comment

begin_define
define|#
directive|define
name|CALLOC
parameter_list|(
name|k
parameter_list|,
name|n
parameter_list|)
value|(calloc((unsigned)(k),(unsigned)(n)))
end_define

begin_define
define|#
directive|define
name|FREE
parameter_list|(
name|x
parameter_list|)
value|(free((char*)(x)))
end_define

begin_define
define|#
directive|define
name|MALLOC
parameter_list|(
name|n
parameter_list|)
value|(malloc((unsigned)(n)))
end_define

begin_define
define|#
directive|define
name|NEW
parameter_list|(
name|t
parameter_list|)
value|((t*)allocate(sizeof(t)))
end_define

begin_define
define|#
directive|define
name|NEW2
parameter_list|(
name|n
parameter_list|,
name|t
parameter_list|)
value|((t*)allocate((unsigned)((n)*sizeof(t))))
end_define

begin_define
define|#
directive|define
name|REALLOC
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|(realloc((char*)(p),(unsigned)(n)))
end_define

begin_comment
comment|/*  the structure of a symbol table entry  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|bucket
name|bucket
typedef|;
end_typedef

begin_struct
struct|struct
name|bucket
block|{
name|struct
name|bucket
modifier|*
name|link
decl_stmt|;
name|struct
name|bucket
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|tag
decl_stmt|;
name|short
name|value
decl_stmt|;
name|short
name|index
decl_stmt|;
name|short
name|prec
decl_stmt|;
name|char
name|class
decl_stmt|;
name|char
name|assoc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  the structure of the LR(0) state machine  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|core
name|core
typedef|;
end_typedef

begin_struct
struct|struct
name|core
block|{
name|struct
name|core
modifier|*
name|next
decl_stmt|;
name|struct
name|core
modifier|*
name|link
decl_stmt|;
name|short
name|number
decl_stmt|;
name|short
name|accessing_symbol
decl_stmt|;
name|short
name|nitems
decl_stmt|;
name|short
name|items
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  the structure used to record shifts  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|shifts
name|shifts
typedef|;
end_typedef

begin_struct
struct|struct
name|shifts
block|{
name|struct
name|shifts
modifier|*
name|next
decl_stmt|;
name|short
name|number
decl_stmt|;
name|short
name|nshifts
decl_stmt|;
name|short
name|shift
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  the structure used to store reductions  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|reductions
name|reductions
typedef|;
end_typedef

begin_struct
struct|struct
name|reductions
block|{
name|struct
name|reductions
modifier|*
name|next
decl_stmt|;
name|short
name|number
decl_stmt|;
name|short
name|nreds
decl_stmt|;
name|short
name|rules
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  the structure used to represent parser actions  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|action
name|action
typedef|;
end_typedef

begin_struct
struct|struct
name|action
block|{
name|struct
name|action
modifier|*
name|next
decl_stmt|;
name|short
name|symbol
decl_stmt|;
name|short
name|number
decl_stmt|;
name|short
name|prec
decl_stmt|;
name|char
name|action_code
decl_stmt|;
name|char
name|assoc
decl_stmt|;
name|char
name|suppressed
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* global variables */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|dflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|lflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|rflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|tflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|vflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|symbol_prefix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|myname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|line
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|outline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|banner
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|tables
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|header
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|body
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|trailer
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|action_file_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|code_file_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|defines_file_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|input_file_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|output_file_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|text_file_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|union_file_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|verbose_file_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|action_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|code_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|defines_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|input_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|output_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|text_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|union_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|verbose_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nitems
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nrules
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nsyms
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ntokens
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nvars
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ntags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|unionized
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|start_symbol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|symbol_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|symbol_value
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|symbol_prec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|symbol_assoc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|ritem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|rlhs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|rrhs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|rprec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rassoc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
modifier|*
name|derives
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|nullable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bucket
modifier|*
name|first_symbol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bucket
modifier|*
name|last_symbol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nstates
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|core
modifier|*
name|first_state
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|shifts
modifier|*
name|first_shift
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|reductions
modifier|*
name|first_reduction
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|accessing_symbol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|core
modifier|*
modifier|*
name|state_table
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|shifts
modifier|*
modifier|*
name|shift_table
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|reductions
modifier|*
modifier|*
name|reduction_table
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
modifier|*
name|LA
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|LAruleno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|lookaheads
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|goto_map
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|from_state
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|to_state
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|action
modifier|*
modifier|*
name|parser
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|SRexpect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|SRtotal
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|RRtotal
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|SRconflicts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|RRconflicts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|defred
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|rules_used
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
name|nunused
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
name|final_state
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global functions */
end_comment

begin_function_decl
name|char
modifier|*
name|allocate
parameter_list|(
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|closure
parameter_list|(
name|short
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|create_symbol_table
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|default_action_warning
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dollar_error
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dollar_warning
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|done
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fatal
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|finalize_closure
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_parser
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_symbols
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_symbol_table
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|illegal_character
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|illegal_tag
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lalr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bucket
modifier|*
name|lookup
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lr0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bucket
modifier|*
name|make_bucket
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|make_parser
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|no_grammar
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|no_space
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|open_error
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|output
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|over_unionized
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prec_redeclared
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reader
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reflexive_transitive_closure
parameter_list|(
name|unsigned
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reprec_warning
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|restarted_warning
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|retyped_warning
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|revalued_warning
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_first_derives
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|syntax_error
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terminal_lhs
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terminal_start
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tokenized_start
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|undefined_goal
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|undefined_symbol_warning
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unexpected_EOF
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unknown_rhs
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unterminated_action
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unterminated_comment
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unterminated_string
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unterminated_text
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unterminated_union
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|untyped_lhs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|untyped_rhs
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|used_reserved
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|verbose
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_section
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

