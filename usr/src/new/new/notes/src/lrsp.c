begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)lrsp.c	1.1\t1/23/83"
decl_stmt|;
end_decl_stmt

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

begin_comment
comment|/*  *	this routine takes in a note number, the io descriptors and  *	and a LOGICAL response number to look for.   *	It the returns the physical response index locations.  *	It returns the response index record, and the offset within  *	that record for the correct response  *  *	Implemented the easy/cheap way. We just scan along the response  *	chain, counting up the undeleted responses.  *	Once we find the correct number, we return with the current  *	set of pointers. What could be easier?  *	In the event that we hit the end of responses before we find  *	the response we want (e.g. the dummy wanted a nonexistent response)  *	we return the index of the last response.  *  *	Returns:	0 if all goes well  *			-1 if bad logical response number   *  *	Ray Essick	May 22, 1981.  *  */
end_comment

begin_macro
name|lrsp
argument_list|(
argument|io
argument_list|,
argument|notenum
argument_list|,
argument|resp
argument_list|,
argument|rrec
argument_list|,
argument|poffset
argument_list|,
argument|recnum
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|io_f
modifier|*
name|io
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|resp_f
modifier|*
name|rrec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|recnum
decl_stmt|,
modifier|*
name|poffset
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|note_f
name|nrec
decl_stmt|;
comment|/* note descriptor */
name|int
name|prec
decl_stmt|;
comment|/* which physical response group we is looking in */
name|getnrec
argument_list|(
name|io
argument_list|,
name|notenum
argument_list|,
operator|&
name|nrec
argument_list|)
expr_stmt|;
comment|/* get the note info */
if|if
condition|(
name|resp
operator|<=
literal|0
condition|)
block|{
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* that was dumb */
block|}
if|if
condition|(
name|resp
operator|>
name|nrec
operator|.
name|n_nresp
condition|)
block|{
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* this too was dumb of him */
block|}
name|prec
operator|=
name|nrec
operator|.
name|n_rindx
expr_stmt|;
comment|/* record # of first response */
operator|*
name|poffset
operator|=
literal|0
expr_stmt|;
name|getrrec
argument_list|(
name|io
argument_list|,
name|prec
argument_list|,
name|rrec
argument_list|)
expr_stmt|;
comment|/* get the first response group */
while|while
condition|(
name|resp
condition|)
block|{
while|while
condition|(
name|rrec
operator|->
name|r_stat
index|[
operator|*
name|poffset
index|]
operator|&
name|DELETED
condition|)
block|{
if|if
condition|(
operator|++
operator|*
name|poffset
operator|==
name|RESPSZ
condition|)
block|{
operator|*
name|poffset
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|(
name|prec
operator|=
name|rrec
operator|->
name|r_next
operator|)
operator|==
operator|-
literal|1
condition|)
block|{
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* broken chain */
block|}
name|getrrec
argument_list|(
name|io
argument_list|,
name|prec
argument_list|,
name|rrec
argument_list|)
expr_stmt|;
comment|/* passed this buffer */
block|}
block|}
if|if
condition|(
operator|--
name|resp
condition|)
block|{
name|rrec
operator|->
name|r_stat
index|[
operator|*
name|poffset
index|]
operator||=
name|DELETED
expr_stmt|;
comment|/* this is the wrong one. lets ignore it. */
block|}
comment|/* we can do this because we never write it back out to screw up others */
block|}
operator|*
name|recnum
operator|=
name|prec
expr_stmt|;
comment|/* set up the response index for the return */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

