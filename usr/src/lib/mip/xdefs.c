begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)xdefs.c	4.3 (Berkeley) 3/19/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_include
include|#
directive|include
file|"pass1.h"
end_include

begin_comment
comment|/*	communication between lexical routines	*/
end_comment

begin_decl_stmt
name|char
name|ftitle
index|[
literal|100
index|]
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* title of the file */
end_comment

begin_decl_stmt
name|char
name|ititle
index|[
literal|100
index|]
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* title of initial file */
end_comment

begin_decl_stmt
name|int
name|lineno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line number of the input file */
end_comment

begin_decl_stmt
name|CONSZ
name|lastcon
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the last constant read by the lexical analyzer */
end_comment

begin_decl_stmt
name|float
name|fcon
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the last float read by the lexical analyzer */
end_comment

begin_decl_stmt
name|double
name|dcon
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the last double read by the lexical analyzer */
end_comment

begin_comment
comment|/*	symbol table maintainence */
end_comment

begin_decl_stmt
name|struct
name|symtab
name|stab
index|[
name|SYMTSZ
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* one extra slot for scratch */
end_comment

begin_decl_stmt
name|int
name|curftn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "current" function */
end_comment

begin_decl_stmt
name|int
name|ftnno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "current" function number */
end_comment

begin_decl_stmt
name|int
name|curclass
decl_stmt|,
comment|/* current storage class */
name|instruct
decl_stmt|,
comment|/* "in structure" flag */
name|stwart
decl_stmt|,
comment|/* for accessing names which are structure members or names */
name|blevel
decl_stmt|,
comment|/* block level: 0 for extern, 1 for ftn args,>=2 inside function */
name|curdim
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current offset into the dimension table */
end_comment

begin_decl_stmt
name|int
name|dimtab
index|[
name|DIMTABSZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|paramstk
index|[
name|PARAMSZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used in the definition of function parameters */
end_comment

begin_decl_stmt
name|int
name|paramno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the number of parameters */
end_comment

begin_decl_stmt
name|int
name|autooff
decl_stmt|,
comment|/* the next unused automatic offset */
name|argoff
decl_stmt|,
comment|/* the next unused argument offset */
name|strucoff
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  the next structure offset position */
end_comment

begin_decl_stmt
name|int
name|regvar
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the next free register for register variables */
end_comment

begin_decl_stmt
name|int
name|minrvar
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the smallest that regvar gets witing a function */
end_comment

begin_decl_stmt
name|OFFSZ
name|inoff
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* offset of external element being initialized */
end_comment

begin_decl_stmt
name|int
name|brkflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* complain about break statements not reached */
end_comment

begin_decl_stmt
name|struct
name|sw
name|swtab
index|[
name|SWITSZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* table for cases within a switch */
end_comment

begin_decl_stmt
name|struct
name|sw
modifier|*
name|swp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to next free entry in swtab */
end_comment

begin_decl_stmt
name|int
name|swx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* index of beginning of cases for current switch */
end_comment

begin_comment
comment|/* debugging flag */
end_comment

begin_decl_stmt
name|int
name|xdebug
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|strflg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if on, strings are to be treated as lists */
end_comment

begin_decl_stmt
name|int
name|reached
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if statement can be reached... */
end_comment

begin_decl_stmt
name|int
name|idname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tunnel to buildtree for name id's */
end_comment

begin_decl_stmt
name|NODE
name|node
index|[
name|TREESZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* do we check for funny casts */
end_comment

begin_decl_stmt
name|int
name|hflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* do we check for various heuristics which may indicate errors */
end_comment

begin_decl_stmt
name|int
name|pflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* do we check for portable constructions */
end_comment

begin_decl_stmt
name|int
name|brklab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|contlab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|flostat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|retlab
init|=
name|NOLAB
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|retstat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* save array for break, continue labels, and flostat */
end_comment

begin_decl_stmt
name|int
name|asavbc
index|[
name|BCSZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|psavbc
init|=
name|asavbc
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|BUG1
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|ccnames
index|[]
init|=
block|{
comment|/* names of storage classes */
literal|"SNULL"
block|,
literal|"AUTO"
block|,
literal|"EXTERN"
block|,
literal|"STATIC"
block|,
literal|"REGISTER"
block|,
literal|"EXTDEF"
block|,
literal|"LABEL"
block|,
literal|"ULABEL"
block|,
literal|"MOS"
block|,
literal|"PARAM"
block|,
literal|"STNAME"
block|,
literal|"MOU"
block|,
literal|"UNAME"
block|,
literal|"TYPEDEF"
block|,
literal|"FORTRAN"
block|,
literal|"ENAME"
block|,
literal|"MOE"
block|,
literal|"UFORTRAN"
block|,
literal|"USTATIC"
block|, 	}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|scnames
argument_list|(
name|c
argument_list|)
decl|register
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* return the name for storage class c */
specifier|static
name|char
name|buf
index|[
literal|12
index|]
decl_stmt|;
if|if
condition|(
name|c
operator|&
name|FIELD
condition|)
block|{
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"FIELD[%d]"
argument_list|,
name|c
operator|&
name|FLDSIZ
argument_list|)
expr_stmt|;
return|return
operator|(
name|buf
operator|)
return|;
block|}
return|return
operator|(
name|ccnames
index|[
name|c
index|]
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

