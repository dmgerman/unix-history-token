begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"parms.h"
end_include

begin_include
include|#
directive|include
file|"structs.h"
end_include

begin_include
include|#
directive|include
file|"net.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|RCSIDENT
end_ifdef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Header: getnet.c,v 1.7 85/01/18 15:11:46 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_comment
comment|/*  *	getnet(sys, xmit, reply)  *	char *sys, **xmit, **reply)  *  *	This routine will scan the net.how file, looking for alternate  *	routes to the system specified. The xmit and reply pointers are  *	set appropriately.  *	(null if no entry found).  *	The routine returns -1 if the file is not there, otherwise  *	it returns the count of lines matched (0,1,2)  *  *	Original Coding:	Ray Essick	April 1982  */
end_comment

begin_decl_stmt
specifier|static
name|char
name|outgoing
index|[
name|CMDLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|incoming
index|[
name|CMDLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hold net command */
end_comment

begin_macro
name|getnet
argument_list|(
argument|sys
argument_list|,
argument|xmit
argument_list|,
argument|reply
argument_list|,
argument|proto
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|sys
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|xmit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|reply
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|proto
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|FILE
modifier|*
name|nethow
decl_stmt|;
name|char
name|pathname
index|[
literal|256
index|]
decl_stmt|;
comment|/* probably ok */
name|char
name|oneline
index|[
literal|512
index|]
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
name|int
name|i
decl_stmt|,
name|count
decl_stmt|;
name|char
modifier|*
name|tsys
decl_stmt|;
comment|/* room for slop */
name|char
modifier|*
name|tdirect
decl_stmt|;
name|char
modifier|*
name|thow
decl_stmt|;
name|int
name|tproto
decl_stmt|;
name|count
operator|=
literal|0
expr_stmt|;
comment|/* lines we have */
if|if
condition|(
name|xmit
operator|!=
operator|(
name|char
operator|*
operator|*
operator|)
name|NULL
condition|)
operator|*
name|xmit
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|reply
operator|!=
operator|(
name|char
operator|*
operator|*
operator|)
name|NULL
condition|)
operator|*
name|reply
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|proto
operator|!=
operator|(
name|int
operator|*
operator|)
name|NULL
condition|)
operator|*
name|proto
operator|=
literal|0
expr_stmt|;
comment|/* default protocol */
name|sprintf
argument_list|(
name|pathname
argument_list|,
literal|"%s/%s/%s"
argument_list|,
name|Mstdir
argument_list|,
name|UTILITY
argument_list|,
name|NETHOW
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|nethow
operator|=
name|fopen
argument_list|(
name|pathname
argument_list|,
literal|"r"
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
while|while
condition|(
name|fgets
argument_list|(
name|oneline
argument_list|,
sizeof|sizeof
name|oneline
argument_list|,
name|nethow
argument_list|)
operator|!=
name|NULL
operator|&&
name|count
operator|<
literal|2
condition|)
block|{
name|i
operator|=
name|strlen
argument_list|(
name|oneline
argument_list|)
expr_stmt|;
comment|/* get end */
if|if
condition|(
name|oneline
index|[
name|i
operator|-
literal|1
index|]
operator|==
literal|'\n'
condition|)
comment|/* not entire line */
block|{
name|oneline
index|[
name|i
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* strip newline */
block|}
else|else
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: net.how line longer than %d characters"
argument_list|,
name|Invokedas
argument_list|,
name|pathname
argument_list|,
sizeof|sizeof
name|oneline
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
comment|/* line too long */
block|}
if|if
condition|(
name|oneline
index|[
literal|0
index|]
operator|==
literal|'#'
operator|||
name|oneline
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
continue|continue;
comment|/* comment or empty */
comment|/*  *	pick the system name  */
name|tsys
operator|=
name|p
operator|=
name|oneline
expr_stmt|;
comment|/* pick fields */
while|while
condition|(
operator|*
name|p
operator|!=
literal|':'
operator|&&
operator|*
name|p
condition|)
name|p
operator|++
expr_stmt|;
comment|/* skip to colon */
if|if
condition|(
operator|*
name|p
operator|!=
literal|':'
condition|)
continue|continue;
comment|/* bad line */
operator|*
name|p
operator|++
operator|=
literal|'\0'
expr_stmt|;
comment|/* terminate */
comment|/*  *	and the direction field   */
name|tdirect
operator|=
name|p
expr_stmt|;
comment|/* direction */
while|while
condition|(
operator|*
name|p
operator|!=
literal|':'
operator|&&
operator|*
name|p
condition|)
name|p
operator|++
expr_stmt|;
comment|/* skip rest of field */
if|if
condition|(
operator|*
name|p
operator|==
literal|'\0'
condition|)
continue|continue;
comment|/* bad line */
operator|*
name|p
operator|++
operator|=
literal|'\0'
expr_stmt|;
comment|/* terminate */
comment|/*  *	now the protocol (possibly empty)  */
if|if
condition|(
name|sscanf
argument_list|(
name|p
argument_list|,
literal|"%d"
argument_list|,
operator|&
name|tproto
argument_list|)
operator|!=
literal|1
condition|)
comment|/* get protocol */
name|tproto
operator|=
literal|0
expr_stmt|;
comment|/* default */
while|while
condition|(
operator|*
name|p
operator|!=
literal|':'
operator|&&
operator|*
name|p
condition|)
name|p
operator|++
expr_stmt|;
comment|/* skip rest */
name|p
operator|++
expr_stmt|;
comment|/* skip  */
comment|/*  *	skip the empty 4th field to get to the "how to" field  */
while|while
condition|(
operator|*
name|p
operator|!=
literal|':'
operator|&&
operator|*
name|p
condition|)
name|p
operator|++
expr_stmt|;
comment|/* skip rest of field */
name|p
operator|++
expr_stmt|;
comment|/* pointing at "how" */
name|thow
operator|=
name|p
expr_stmt|;
comment|/* assign */
comment|/*  *	now, let's see if it's the one we want.  */
if|if
condition|(
name|strcmp
argument_list|(
name|tsys
argument_list|,
name|sys
argument_list|)
condition|)
comment|/* match? */
continue|continue;
comment|/* no */
if|if
condition|(
operator|*
name|tdirect
operator|==
literal|'x'
condition|)
comment|/* transmit */
block|{
if|if
condition|(
name|xmit
operator|!=
operator|(
name|char
operator|*
operator|*
operator|)
name|NULL
condition|)
comment|/* want it? */
block|{
name|strcpy
argument_list|(
name|outgoing
argument_list|,
name|thow
argument_list|)
expr_stmt|;
comment|/* copy */
operator|*
name|xmit
operator|=
name|outgoing
expr_stmt|;
comment|/* and point */
block|}
if|if
condition|(
name|proto
operator|!=
operator|(
name|int
operator|*
operator|)
name|NULL
condition|)
comment|/* want it? */
operator|*
name|proto
operator|=
name|tproto
expr_stmt|;
comment|/* give it to him */
block|}
else|else
block|{
comment|/* force reply */
if|if
condition|(
name|reply
operator|!=
operator|(
name|char
operator|*
operator|*
operator|)
name|NULL
condition|)
block|{
name|strcpy
argument_list|(
name|incoming
argument_list|,
name|thow
argument_list|)
expr_stmt|;
comment|/* copy */
operator|*
name|reply
operator|=
name|incoming
expr_stmt|;
comment|/* and point */
block|}
block|}
name|count
operator|++
expr_stmt|;
comment|/* bump the count */
block|}
name|fclose
argument_list|(
name|nethow
argument_list|)
expr_stmt|;
return|return
name|count
return|;
block|}
end_block

end_unit

