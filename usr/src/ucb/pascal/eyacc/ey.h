begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1979 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)ey.h	5.1 (Berkeley) 4/29/85  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/*  MANIFEST CONSTANT DEFINITIONS */
end_comment

begin_define
define|#
directive|define
name|NTBASE
value|010000
end_define

begin_comment
comment|/* internal codes for error and accept actions */
end_comment

begin_define
define|#
directive|define
name|ERRCODE
value|8190
end_define

begin_define
define|#
directive|define
name|ACCEPTCODE
value|8191
end_define

begin_define
define|#
directive|define
name|errfileno
value|stderr
end_define

begin_comment
comment|/* file number for erros and reduction message */
end_comment

begin_define
define|#
directive|define
name|_tbitset
value|6
end_define

begin_comment
comment|/* 16*_tbitset - 1>= _nterms */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tbitset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of wds of lookahead vector */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nolook
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag to turn off lookahed computations */
end_comment

begin_struct
struct|struct
name|looksets
block|{
name|int
name|lset
index|[
name|_tbitset
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|item
block|{
name|int
modifier|*
name|pitem
decl_stmt|;
name|struct
name|looksets
modifier|*
name|look
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* output actions */
end_comment

begin_define
define|#
directive|define
name|ERRACT
value|4096
end_define

begin_define
define|#
directive|define
name|SHIFTACT
value|8192
end_define

begin_define
define|#
directive|define
name|REDUCACT
value|12288
end_define

begin_define
define|#
directive|define
name|ACCEPTACT
value|16384
end_define

begin_define
define|#
directive|define
name|_REGISTER
value|register
end_define

begin_decl_stmt
specifier|extern
name|int
name|nstate
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of states */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|item
modifier|*
name|pstate
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointers to the descriptions of the states */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|apstate
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* index to actions in amem by state */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|actsiz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of the action table array */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tystate
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* contains type information about the states */
end_comment

begin_comment
comment|/* 0 = simple state, completely generated      1 = state awaiting generation      2 = state with an empty production in closure       */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|stsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum number of states, at present */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|memsiz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum size for productions and states */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mem0
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* added production */
end_comment

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|mem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|amem
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* action table storage */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|actsiz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* action table size */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|memact
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next free action table position */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nprod
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of productions */
end_comment

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|prdptr
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointers to descriptions of productions */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|prdlim
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the number of productions allowed */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|levprd
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* contains production levels to break conflicts */
end_comment

begin_comment
comment|/* last two bits code associativity:        0 = no definition        1 = left associative        2 = binary        3 = right associative      bit 04 is 1 if the production has an action      the high 13 bits have the production level      */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nterms
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of terminals */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nerrors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of errors */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fatfl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if on, error is fatal */
end_comment

begin_comment
comment|/*	the ascii representations of the terminals	*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|extval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start of output values */
end_comment

begin_struct
specifier|extern
struct|struct
name|sxxx1
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|value
decl_stmt|;
block|}
name|trmset
index|[]
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|char
name|cnames
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cnamsz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cnamp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxtmp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the size of the temp arrays */
end_comment

begin_comment
comment|/* temporary vectors, indexable by states, terms, or nterms */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|temp1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|temp2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|trmlev
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vector with the precedence of the terminals */
end_comment

begin_comment
comment|/* The levels are the same as for levprd, but bit 04 is always 0 */
end_comment

begin_comment
comment|/* the ascii representations of the nonterminals */
end_comment

begin_struct
specifier|extern
struct|struct
name|sxxx2
block|{
name|char
modifier|*
name|name
decl_stmt|;
block|}
name|nontrst
index|[]
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|indgo
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* index to the stored goto table */
end_comment

begin_decl_stmt
specifier|extern
name|int
modifier|*
modifier|*
modifier|*
name|pres
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vector of pointers to the productions yielding each nonterminal */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|looksets
modifier|*
modifier|*
name|pfirst
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vector of pointers to first sets for each nonterminal */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pempty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* table of nonterminals nontrivially deriving e */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|stateflags
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flags defining properties of a state (see below) */
end_comment

begin_define
define|#
directive|define
name|GENLAMBDA
value|1
end_define

begin_comment
comment|/* the state can nontrivially derive lambda */
end_comment

begin_define
define|#
directive|define
name|SINGLE_NT
value|2
end_define

begin_comment
comment|/* the state has a single nonterminal before its dot */
end_comment

begin_define
define|#
directive|define
name|NEEDSREDUCE
value|4
end_define

begin_comment
comment|/* the state needs a full reduce state generated */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|looksets
name|lastate
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* saved lookahead sets */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|lookstate
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* index mapping states to saved lookaheads */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|savedlook
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of saved lookahead sets used */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|maxlastate
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum number of saved lookahead sets */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nnonter
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the number of nonterminals */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lastred
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the number of the last reduction of a state */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|ftable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* y.tab.c file */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|foutput
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* y.output file */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|cin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current input file */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|cout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current output file */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arrndx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|zzcwset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|zzpairs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|zzgoent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|zzgobest
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|zzacent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|zzacsave
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|zznsave
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|zzclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|zzrrconf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|zzsrconf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ctokn
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
block|{
name|int
modifier|*
modifier|*
name|ppi
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|ntlim
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum number of nonterminals */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tlim
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum number of terminals */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lineno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current line number */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|peekc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* look-ahead character */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tstates
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ntstates
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mstates
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|looksets
name|clset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|looksets
name|lkst
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nlset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next lookahead set index */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lsetsz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of lookahead sets */
end_comment

begin_struct
specifier|extern
struct|struct
name|wset
block|{
name|int
modifier|*
name|pitem
decl_stmt|,
name|flag
decl_stmt|,
name|ws
index|[
name|_tbitset
index|]
decl_stmt|;
block|}
name|wsets
index|[]
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|cwset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|wssize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lambdarule
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* index to rule that derives lambda */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|numbval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the value of an input number */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ratfor flag */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|oflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* optimization flag */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ndefout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of defined symbols output */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|machine
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|UNIX
value|1
end_define

begin_define
define|#
directive|define
name|GCOS
value|2
end_define

begin_define
define|#
directive|define
name|IBM
value|3
end_define

begin_function_decl
name|struct
name|looksets
modifier|*
name|flset
parameter_list|()
function_decl|;
end_function_decl

end_unit

