begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1979 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1980 Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

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
literal|"@(#)ey0.c	5.1 (Berkeley) 4/29/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|_actsize
value|2500
end_define

begin_define
define|#
directive|define
name|_memsize
value|3000
end_define

begin_define
define|#
directive|define
name|_nstates
value|700
end_define

begin_define
define|#
directive|define
name|_nterms
value|95
end_define

begin_define
define|#
directive|define
name|_nprod
value|300
end_define

begin_define
define|#
directive|define
name|_nnonterm
value|150
end_define

begin_define
define|#
directive|define
name|_tempsize
value|700
end_define

begin_define
define|#
directive|define
name|_cnamsz
value|3500
end_define

begin_define
define|#
directive|define
name|_lsetsize
value|600
end_define

begin_define
define|#
directive|define
name|_wsetsize
value|400
end_define

begin_define
define|#
directive|define
name|_maxlastate
value|100
end_define

begin_define
define|#
directive|define
name|_tbitset
value|6
end_define

begin_decl_stmt
name|int
name|tbitset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of lookahed sets */
end_comment

begin_decl_stmt
name|int
name|nolook
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag to suppress lookahead computations */
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
block|}
struct|;
end_struct

begin_comment
comment|/* this file contains the definitions for most externally known data */
end_comment

begin_decl_stmt
name|int
name|nstate
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of states */
end_comment

begin_decl_stmt
name|struct
name|item
modifier|*
name|pstate
index|[
name|_nstates
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointers to the descriptions of the states */
end_comment

begin_decl_stmt
name|int
name|apstate
index|[
name|_nstates
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* index to the actions for the states */
end_comment

begin_decl_stmt
name|int
name|tystate
index|[
name|_nstates
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* contains type information about the states */
end_comment

begin_decl_stmt
name|int
name|stsize
init|=
name|_nstates
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum number of states, at present */
end_comment

begin_decl_stmt
name|int
name|memsiz
init|=
name|_memsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum size for productions and states */
end_comment

begin_decl_stmt
name|int
name|mem0
index|[
name|_memsize
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* production storage */
end_comment

begin_decl_stmt
name|int
modifier|*
name|mem
init|=
name|mem0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|amem
index|[
name|_actsize
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* action table storage */
end_comment

begin_decl_stmt
name|int
name|actsiz
init|=
name|_actsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* action table size */
end_comment

begin_decl_stmt
name|int
name|memact
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next free action table position */
end_comment

begin_decl_stmt
name|int
name|nprod
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of productions */
end_comment

begin_decl_stmt
name|int
modifier|*
name|prdptr
index|[
name|_nprod
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointers to descriptions of productions */
end_comment

begin_decl_stmt
name|int
name|prdlim
init|=
name|_nprod
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the maximum number of productions */
end_comment

begin_comment
comment|/* levprd - productions levels to break conflicts */
end_comment

begin_decl_stmt
name|int
name|levprd
index|[
name|_nprod
index|]
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last two bits code associativity:        0 = no definition        1 = left associative        2 = binary        3 = right associative      bit 04 is 1 if the production has an action      the high 13 bits have the production level      */
end_comment

begin_decl_stmt
name|int
name|nterms
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of terminals */
end_comment

begin_decl_stmt
name|int
name|tlim
init|=
name|_nterms
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the maximum number of terminals */
end_comment

begin_comment
comment|/*	the ascii representations of the terminals	*/
end_comment

begin_decl_stmt
name|int
name|extval
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start of output values */
end_comment

begin_struct
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
index|[
name|_nterms
index|]
struct|;
end_struct

begin_decl_stmt
name|char
name|cnames
index|[
name|_cnamsz
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cnamsz
init|=
name|_cnamsz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|cnamp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|maxtmp
init|=
name|_tempsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the size of the temp1 array */
end_comment

begin_decl_stmt
name|int
name|temp1
index|[
name|_tempsize
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* temporary storage, indexed by terms + nterms or states */
end_comment

begin_decl_stmt
name|int
name|temp2
index|[
name|_nnonterm
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* temporary storage indexed by nonterminals */
end_comment

begin_decl_stmt
name|int
name|trmlev
index|[
name|_nterms
index|]
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
struct|struct
name|sxxx2
block|{
name|char
modifier|*
name|name
decl_stmt|;
block|}
name|nontrst
index|[
name|_nnonterm
index|]
struct|;
end_struct

begin_decl_stmt
name|int
name|ntlim
init|=
name|_nnonterm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* limit to the number of nonterminals */
end_comment

begin_decl_stmt
name|int
name|indgo
index|[
name|_nstates
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* index to the stored goto table */
end_comment

begin_decl_stmt
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
name|int
modifier|*
name|pempty
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* table of nonterminals nontrivially deriving e */
end_comment

begin_decl_stmt
name|int
name|nnonter
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the number of nonterminals */
end_comment

begin_decl_stmt
name|int
name|lastred
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the number of the last reduction of a state */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|ftable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* y.tab.c file */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|foutput
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* y.output file */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|cout
init|=
name|stdout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|arrndx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used in the output of arrays on y.tab.c */
end_comment

begin_decl_stmt
name|int
name|zzcwset
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|zzpairs
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|zzgoent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|zzgobest
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|zzacent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|zzacsave
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|zznsave
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|zzclose
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|zzsrconf
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|zzrrconf
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ctokn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lineno
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current input line number */
end_comment

begin_decl_stmt
name|int
name|peekc
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* look-ahead character */
end_comment

begin_decl_stmt
name|int
name|tstates
index|[
name|_nterms
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* states generated by terminal gotos */
end_comment

begin_decl_stmt
name|int
name|ntstates
index|[
name|_nnonterm
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* states generated by nonterminal gotos */
end_comment

begin_decl_stmt
name|int
name|mstates
index|[
name|_nstates
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* chain of overflows of term/nonterm generation lists  */
end_comment

begin_decl_stmt
name|struct
name|looksets
name|clset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|looksets
name|lkst
index|[
name|_lsetsize
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nlset
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next lookahead set index */
end_comment

begin_decl_stmt
name|int
name|lsetsz
init|=
name|_lsetsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of lookahead sets */
end_comment

begin_struct
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
index|[
name|_wsetsize
index|]
struct|;
end_struct

begin_decl_stmt
name|int
name|cwset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wssize
init|=
name|_wsetsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lambdarule
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|stateflags
index|[
name|_nstates
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|char
name|lookstate
index|[
name|_nstates
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|looksets
name|lastate
index|[
name|_maxlastate
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|maxlastate
init|=
name|_maxlastate
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|savedlook
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|numbval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the value of an input number */
end_comment

begin_decl_stmt
name|int
name|rflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ratfor flag */
end_comment

begin_decl_stmt
name|int
name|oflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* optimization flag */
end_comment

begin_decl_stmt
name|int
name|ndefout
init|=
literal|3
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of defined symbols output */
end_comment

begin_decl_stmt
name|int
name|nerrors
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of errors */
end_comment

begin_decl_stmt
name|int
name|fatfl
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if on, error is fatal */
end_comment

begin_decl_stmt
name|int
name|machine
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* has a number describing the machine */
end_comment

end_unit

