begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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

begin_expr_stmt
name|int
name|nolook
literal|0
expr_stmt|;
end_expr_stmt

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

begin_expr_stmt
name|int
name|nstate
literal|0
expr_stmt|;
end_expr_stmt

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
name|_nstates
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum number of states, at present */
end_comment

begin_decl_stmt
name|int
name|memsiz
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
name|_actsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* action table size */
end_comment

begin_expr_stmt
name|int
name|memact
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* next free action table position */
end_comment

begin_expr_stmt
name|int
name|nprod
literal|1
expr_stmt|;
end_expr_stmt

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
block|{
literal|0
operator|,
literal|0
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* last two bits code associativity:        0 = no definition        1 = left associative        2 = binary        3 = right associative      bit 04 is 1 if the production has an action      the high 13 bits have the production level      */
end_comment

begin_expr_stmt
name|int
name|nterms
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* number of terminals */
end_comment

begin_decl_stmt
name|int
name|tlim
name|_nterms
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the maximum number of terminals */
end_comment

begin_comment
comment|/*	the ascii representations of the terminals	*/
end_comment

begin_expr_stmt
name|int
name|extval
literal|0
expr_stmt|;
end_expr_stmt

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

begin_expr_stmt
name|int
operator|*
name|pempty
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* table of nonterminals nontrivially deriving e */
end_comment

begin_expr_stmt
name|int
name|nnonter
operator|-
literal|1
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* the number of nonterminals */
end_comment

begin_expr_stmt
name|int
name|lastred
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* the number of the last reduction of a state */
end_comment

begin_decl_stmt
name|int
name|ftable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* y.tab.c file */
end_comment

begin_decl_stmt
name|int
name|foutput
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* y.output file */
end_comment

begin_decl_stmt
name|int
name|arrndx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used in the output of arrays on y.tab.c */
end_comment

begin_expr_stmt
name|int
name|zzcwset
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|int
name|zzpairs
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|int
name|zzgoent
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|int
name|zzgobest
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|int
name|zzacent
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|int
name|zzacsave
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|int
name|zznsave
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|int
name|zzclose
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|int
name|zzsrconf
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|int
name|zzrrconf
literal|0
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
modifier|*
name|ctokn
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|int
name|lineno
literal|1
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* current input line number */
end_comment

begin_expr_stmt
name|int
name|peekc
operator|-
literal|1
expr_stmt|;
end_expr_stmt

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

begin_expr_stmt
name|int
name|nlset
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* next lookahead set index */
end_comment

begin_decl_stmt
name|int
name|lsetsz
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
name|_wsetsize
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

begin_expr_stmt
name|int
name|rflag
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* ratfor flag */
end_comment

begin_expr_stmt
name|int
name|oflag
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* optimization flag */
end_comment

begin_expr_stmt
name|int
name|ndefout
literal|3
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* number of defined symbols output */
end_comment

begin_expr_stmt
name|int
name|nerrors
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* number of errors */
end_comment

begin_expr_stmt
name|int
name|fatfl
literal|1
expr_stmt|;
end_expr_stmt

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

