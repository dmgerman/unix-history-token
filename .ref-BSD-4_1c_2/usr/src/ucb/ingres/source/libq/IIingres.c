begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_include
include|#
directive|include
file|<symbol.h>
end_include

begin_include
include|#
directive|include
file|<opsys.h>
end_include

begin_include
include|#
directive|include
file|<aux.h>
end_include

begin_include
include|#
directive|include
file|"IIglobals.h"
end_include

begin_include
include|#
directive|include
file|<pipes.h>
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)IIingres.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_define
define|#
directive|define
name|CLOSED
value|'?'
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|xV7_UNIX
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|IImainpr
init|=
literal|"ingres"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
else|xV7_UNIX
end_else

begin_decl_stmt
name|char
modifier|*
name|IImainpr
init|=
literal|"/usr/bin/ingresx"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|xV7_UNIX
end_endif

begin_decl_stmt
name|char
name|IIPathname
index|[
literal|41
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **	IIingres opens the needed pipes and **	forks an ingres process. ** **	ingres recognizes the EQUEL flag followed by **	three control characters as being an equel processes ** **	parameters to ingres are passed directly. only **	the first 9 are counted. */
end_comment

begin_macro
name|IIingres
argument_list|(
argument|p1
argument_list|,
argument|p2
argument_list|,
argument|p3
argument_list|,
argument|p4
argument_list|,
argument|p5
argument_list|,
argument|p6
argument_list|,
argument|p7
argument_list|,
argument|p8
argument_list|,
argument|p9
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|p1
decl_stmt|,
modifier|*
name|p2
decl_stmt|,
modifier|*
name|p3
decl_stmt|,
modifier|*
name|p4
decl_stmt|,
modifier|*
name|p5
decl_stmt|,
modifier|*
name|p6
decl_stmt|,
modifier|*
name|p7
decl_stmt|,
modifier|*
name|p8
decl_stmt|,
modifier|*
name|p9
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|pipes
index|[
literal|4
index|]
decl_stmt|;
comment|/* pipe vector buffer */
name|char
name|eoption
index|[
literal|15
index|]
decl_stmt|;
comment|/* dummy variable to hold -EQUEL option */
specifier|register
name|char
modifier|*
name|cp
decl_stmt|;
name|char
modifier|*
name|argv
index|[
literal|12
index|]
decl_stmt|;
specifier|register
name|char
modifier|*
modifier|*
name|ap
decl_stmt|;
extern|extern		IIresync(
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern		*(IIinterrupt
end_extern

begin_expr_stmt
unit|)
operator|(
operator|)
operator|,
name|exit
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|pb_t
name|pb
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|xETR1
end_ifdef

begin_if
if|if
condition|(
name|IIdebug
condition|)
name|printf
argument_list|(
literal|"IIingres\n"
argument_list|)
expr_stmt|;
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* test if ingres is already invoked */
end_comment

begin_if
if|if
condition|(
name|IIingpid
condition|)
name|IIsyserr
argument_list|(
literal|"Attempt to invoke INGRES twice"
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
name|IIgetpath
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* open INGRES pipes */
end_comment

begin_if
if|if
condition|(
name|pipe
argument_list|(
operator|&
name|pipes
index|[
literal|0
index|]
argument_list|)
operator|||
name|pipe
argument_list|(
operator|&
name|pipes
index|[
literal|2
index|]
argument_list|)
condition|)
name|IIsyserr
argument_list|(
literal|"pipe error in IIingres"
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
name|IIw_down
operator|=
name|pipes
index|[
literal|1
index|]
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* file desc for equel->parser */
end_comment

begin_expr_stmt
name|IIr_down
operator|=
name|pipes
index|[
literal|2
index|]
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* file desc for parser->equel */
end_comment

begin_comment
comment|/* catch interupts if they are not being ignored */
end_comment

begin_if
if|if
condition|(
name|signal
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
operator|!=
literal|1
condition|)
name|signal
argument_list|(
literal|2
argument_list|,
name|IIresync
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|/* set up equel option flag */
end_comment

begin_expr_stmt
name|cp
operator|=
name|eoption
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|cp
operator|++
operator|=
literal|'-'
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|cp
operator|++
operator|=
name|EQUEL
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|cp
operator|++
operator|=
name|pipes
index|[
literal|0
index|]
operator||
literal|0100
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|cp
operator|++
operator|=
name|pipes
index|[
literal|1
index|]
operator||
literal|0100
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|cp
operator|++
operator|=
name|CLOSED
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|cp
operator|++
operator|=
name|pipes
index|[
literal|3
index|]
operator||
literal|0100
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|cp
operator|++
operator|=
name|CLOSED
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* this will be the equel->ovqp pipe in the future */
end_comment

begin_expr_stmt
operator|*
name|cp
operator|++
operator|=
name|CLOSED
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* old ovqp->equel pipe */
end_comment

begin_comment
comment|/* put "6.3" at end of flag for OVQP to not do flush after 	 * every tuple 	 */
end_comment

begin_expr_stmt
operator|*
name|cp
operator|++
operator|=
literal|'6'
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|cp
operator|++
operator|=
literal|'.'
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|cp
operator|++
operator|=
literal|'3'
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|cp
operator|=
literal|'\0'
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|cp
operator|-
name|eoption
operator|>=
sizeof|sizeof
name|eoption
condition|)
name|IIsyserr
argument_list|(
literal|"IIingres: too big an eoption"
argument_list|)
expr_stmt|;
end_if

begin_if
if|if
condition|(
operator|(
name|IIingpid
operator|=
name|fork
argument_list|()
operator|)
operator|<
literal|0
condition|)
name|IIsyserr
argument_list|(
literal|"IIingres:cant fork %d"
argument_list|,
name|IIingpid
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|/* if parent, close the unneeded files and return */
end_comment

begin_if
if|if
condition|(
name|IIingpid
condition|)
block|{
if|if
condition|(
name|close
argument_list|(
name|pipes
index|[
literal|0
index|]
argument_list|)
operator|||
name|close
argument_list|(
name|pipes
index|[
literal|3
index|]
argument_list|)
condition|)
name|IIsyserr
argument_list|(
literal|"close error 1 in IIingres"
argument_list|)
expr_stmt|;
name|IIinput
operator|=
name|IIr_down
expr_stmt|;
name|IIpb_prime
argument_list|(
operator|&
name|pb
argument_list|,
name|PB_NOTYPE
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|xETR1
if|if
condition|(
name|IIdebug
condition|)
name|printf
argument_list|(
literal|"calling ingres with '%s' database %s\n"
argument_list|,
name|eoption
argument_list|,
name|p1
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return;
block|}
end_if

begin_comment
comment|/* the child overlays /usr/bin/ingres */
end_comment

begin_expr_stmt
name|ap
operator|=
name|argv
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|ap
operator|++
operator|=
literal|"ingres"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|ap
operator|++
operator|=
name|eoption
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|ap
operator|++
operator|=
name|p1
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|ap
operator|++
operator|=
name|p2
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|ap
operator|++
operator|=
name|p3
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|ap
operator|++
operator|=
name|p4
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|ap
operator|++
operator|=
name|p5
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|ap
operator|++
operator|=
name|p6
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|ap
operator|++
operator|=
name|p7
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|ap
operator|++
operator|=
name|p8
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|ap
operator|++
operator|=
name|p9
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|ap
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|xV7_UNIX
end_ifdef

begin_expr_stmt
name|execvp
argument_list|(
name|IImainpr
argument_list|,
name|argv
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
else|xV7_UNIX
end_else

begin_expr_stmt
name|execv
argument_list|(
name|IImainpr
argument_list|,
name|argv
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
endif|xV7_UNIX
end_endif

begin_expr_stmt
name|IIsyserr
argument_list|(
literal|"cannot exec INGRES in IIingres"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/* **  IIGETPATH -- initialize the IIPathname variable ** **	Parameters: **		none ** **	Returns: **		none ** **	Side Effects: **		Sets IIPathname to the home directory of the USERINGRES **		[unix.h] user. ** **	Called By: **		IIingres.c ** **	History: **		3/26/79 -- (marc) written */
end_comment

begin_expr_stmt
unit|IIgetpath
operator|(
operator|)
block|{
name|char
name|line
index|[
name|MAXLINE
operator|+
literal|1
index|]
block|;
specifier|static
name|char
name|reenter
block|;
specifier|register
name|int
name|i
block|;
specifier|register
name|char
operator|*
name|lp
block|; 	struct
name|iob
name|iobuf
block|;
name|char
operator|*
name|field
index|[
name|UF_NFIELDS
index|]
block|;
if|if
condition|(
name|reenter
condition|)
return|return;
else|else
name|reenter
operator|++
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|(
name|i
operator|=
name|IIfopen
argument_list|(
literal|"/etc/passwd"
argument_list|,
operator|&
name|iobuf
argument_list|)
operator|)
operator|<
literal|0
condition|)
name|IIsyserr
argument_list|(
literal|"IIgetpath: no /etc/passwd"
argument_list|)
expr_stmt|;
end_if

begin_do
do|do
block|{
comment|/* get a line from the passwd file */
name|i
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|lp
operator|=
name|line
init|;
operator|(
operator|*
name|lp
operator|=
name|IIgetc
argument_list|(
operator|&
name|iobuf
argument_list|)
operator|)
operator|!=
literal|'\n'
condition|;
name|lp
operator|++
control|)
block|{
if|if
condition|(
operator|*
name|lp
operator|==
operator|-
literal|1
condition|)
name|IIsyserr
argument_list|(
literal|"IIgetpath: no user 'ingres' in /etc/passwd"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|++
name|i
operator|>
sizeof|sizeof
name|line
operator|-
literal|1
condition|)
block|{
operator|*
name|lp
operator|=
literal|'\0'
expr_stmt|;
name|IIsyserr
argument_list|(
literal|"IIgetpath: line overflow: \"%s\""
argument_list|,
name|line
argument_list|)
expr_stmt|;
block|}
block|}
operator|*
name|lp
operator|=
literal|'\0'
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|lp
operator|=
name|line
init|;
operator|*
name|lp
operator|!=
literal|'\0'
condition|;
name|lp
operator|++
control|)
block|{
if|if
condition|(
operator|*
name|lp
operator|==
literal|':'
condition|)
block|{
operator|*
name|lp
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|i
operator|>
name|UF_NFIELDS
condition|)
name|IIsyserr
argument_list|(
literal|"IIgetpath: too many fields in passwd \"%s\""
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|field
index|[
name|i
operator|++
index|]
operator|=
name|lp
operator|+
literal|1
expr_stmt|;
block|}
block|}
comment|/* check for enough fields for valid entry */
if|if
condition|(
name|i
operator|<
literal|3
condition|)
name|IIsyserr
argument_list|(
literal|"IIgetpath: too few fields \"%s\""
argument_list|,
name|line
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
operator|!
name|IIsequal
argument_list|(
name|line
argument_list|,
name|USERINGRES
argument_list|)
condition|)
do|;
end_do

begin_expr_stmt
name|IIclose
argument_list|(
operator|&
name|iobuf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* check that pathname won't overflow static buffer */
end_comment

begin_if
if|if
condition|(
name|field
index|[
name|i
operator|-
literal|1
index|]
operator|-
name|field
index|[
name|i
operator|-
literal|2
index|]
operator|>
sizeof|sizeof
name|IIPathname
condition|)
name|IIsyserr
argument_list|(
literal|"IIgetpath: path too long \"%s\""
argument_list|,
name|field
index|[
name|i
operator|-
literal|2
index|]
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|/* move pathname into buffer */
end_comment

begin_expr_stmt
name|IIbmove
argument_list|(
name|field
index|[
name|i
operator|-
literal|2
index|]
argument_list|,
name|IIPathname
argument_list|,
name|field
index|[
name|i
operator|-
literal|1
index|]
operator|-
name|field
index|[
name|i
operator|-
literal|2
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

unit|}
end_unit

