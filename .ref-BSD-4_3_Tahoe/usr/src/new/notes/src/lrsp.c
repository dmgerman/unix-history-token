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
literal|"$Header: lrsp.c,v 1.7 85/01/18 15:16:05 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

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
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* that was dumb */
if|if
condition|(
name|resp
operator|>
name|nrec
operator|.
name|n_nresp
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* this too was dumb of him */
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
comment|/* first resp block */
while|while
condition|(
name|resp
operator|>
name|rrec
operator|->
name|r_last
condition|)
comment|/* hi-speed along */
block|{
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
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* broken chain */
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
comment|/*       *	We should now be in the block that contains the response      */
block|{
specifier|register
name|int
name|counted
decl_stmt|;
name|counted
operator|=
operator|(
operator|-
literal|1
operator|)
expr_stmt|;
comment|/* active in this block */
operator|*
name|poffset
operator|=
literal|0
expr_stmt|;
comment|/* start of block */
while|while
condition|(
literal|1
condition|)
comment|/* forever */
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
comment|/* skip holes */
block|{
operator|++
operator|*
name|poffset
expr_stmt|;
comment|/* and try next */
name|x
argument_list|(
operator|*
name|poffset
operator|==
name|RESPSZ
argument_list|,
literal|"lrsp: r_last lied!"
argument_list|)
expr_stmt|;
block|}
name|counted
operator|++
expr_stmt|;
comment|/* a live one */
if|if
condition|(
name|rrec
operator|->
name|r_first
operator|+
name|counted
operator|==
name|resp
condition|)
comment|/* got it */
block|{
break|break;
comment|/* get out */
block|}
operator|++
operator|*
name|poffset
expr_stmt|;
comment|/* on to next */
comment|/*  	     * this above is legit since we KNOW the resp is in this 	     * block so we'll never go over the end 	     */
block|}
block|}
operator|*
name|recnum
operator|=
name|prec
expr_stmt|;
comment|/* set up return */
return|return
literal|0
return|;
block|}
end_block

end_unit

