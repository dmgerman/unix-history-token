begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
literal|"$Header: note.c,v 1.7 85/01/18 15:32:57 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_comment
comment|/*  *	Putnote  *  *	Take the given text, and make put it into the note file.  *	following algorithm:  *	reserve space for text  *	write the text  *	make the note header record  *	lock the index file  *	write the note header info  *	unlock the index file  *	rewrite the correct text header info  *  *  *	Delnote(io, noteno):  marks the status word as deleted.  *  *	Original authors:	Rob Kolstad and Ray Essick	Winter 1980  *	modified;	Ray Essick	December 1981  */
end_comment

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

begin_macro
name|putnote
argument_list|(
argument|io
argument_list|,
argument|where
argument_list|,
argument|title
argument_list|,
argument|status
argument_list|,
argument|note
argument_list|,
argument|auth
argument_list|,
argument|policy
argument_list|,
argument|lockit
argument_list|,
argument|addid
argument_list|,
argument|fromsys
argument_list|,
argument|addtime
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
name|daddr_f
modifier|*
name|where
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|title
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|note_f
modifier|*
name|note
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|auth_f
modifier|*
name|auth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* policy = true if this is the policy note */
end_comment

begin_comment
comment|/* addid = fales if we already have an id for the note */
end_comment

begin_comment
comment|/* addtime = false if we already have a time for the note */
end_comment

begin_decl_stmt
name|char
modifier|*
name|fromsys
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* whom we recieved it from (routing) */
end_comment

begin_block
block|{
name|int
name|count
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
name|int
name|notenum
decl_stmt|;
name|note
operator|->
name|n_nresp
operator|=
literal|0
expr_stmt|;
comment|/* no responses yet */
if|if
condition|(
name|addtime
condition|)
comment|/* dont if compressing... */
block|{
name|gettime
argument_list|(
operator|&
name|note
operator|->
name|n_rcvd
argument_list|)
expr_stmt|;
name|gettime
argument_list|(
operator|&
name|note
operator|->
name|n_lmod
argument_list|)
expr_stmt|;
comment|/* date of last mod is same */
block|}
name|note
operator|->
name|n_auth
operator|=
operator|*
name|auth
expr_stmt|;
comment|/* move author over */
name|strcpy
argument_list|(
name|note
operator|->
name|n_from
argument_list|,
name|fromsys
argument_list|)
expr_stmt|;
comment|/* who gave it to us */
name|note
operator|->
name|n_rindx
operator|=
operator|(
operator|-
literal|1
operator|)
expr_stmt|;
comment|/* no place for responses yet */
name|note
operator|->
name|n_stat
operator|=
name|status
expr_stmt|;
comment|/* director message, deleted, etc */
name|note
operator|->
name|n_addr
operator|=
operator|*
name|where
expr_stmt|;
comment|/* where on disk */
name|strncpy
argument_list|(
name|note
operator|->
name|ntitle
argument_list|,
name|title
argument_list|,
name|TITLEN
argument_list|)
expr_stmt|;
comment|/* copy */
name|note
operator|->
name|ntitle
index|[
name|TITLEN
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* stop for sure */
if|if
condition|(
name|lockit
condition|)
name|locknf
argument_list|(
name|io
argument_list|,
name|DSCRLOCK
argument_list|)
expr_stmt|;
comment|/* BEGIN CRITICAL SECTION */
name|getdscr
argument_list|(
name|io
argument_list|,
operator|&
name|io
operator|->
name|descr
argument_list|)
expr_stmt|;
comment|/* grab notesfile header */
if|if
condition|(
name|io
operator|->
name|descr
operator|.
name|d_stat
operator|&
name|NFINVALID
condition|)
block|{
if|if
condition|(
name|lockit
condition|)
name|unlocknf
argument_list|(
name|io
argument_list|,
name|DSCRLOCK
argument_list|)
expr_stmt|;
name|closenf
argument_list|(
name|io
argument_list|)
expr_stmt|;
name|opennf
argument_list|(
name|io
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* get new links */
name|printf
argument_list|(
literal|"Sorry, your note has been lost in a compression"
argument_list|)
expr_stmt|;
comment|/*  *	Should give the user a chance to recover his text somewhere  *	in here   */
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|sleep
argument_list|(
literal|1
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
name|addid
condition|)
block|{
ifdef|#
directive|ifdef
name|SHAREDATA
name|strmove
argument_list|(
name|System
argument_list|,
name|note
operator|->
name|n_id
operator|.
name|sys
argument_list|)
expr_stmt|;
comment|/* copy sys name */
else|#
directive|else
else|! SHAREDATA
name|strmove
argument_list|(
name|io
operator|->
name|descr
operator|.
name|d_id
operator|.
name|sys
argument_list|,
name|note
operator|->
name|n_id
operator|.
name|sys
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|SHAREDATA
name|note
operator|->
name|n_id
operator|.
name|uniqid
operator|=
operator|++
operator|(
name|io
operator|->
name|descr
operator|.
name|d_id
operator|.
name|uniqid
operator|)
expr_stmt|;
comment|/* and unique id num */
ifdef|#
directive|ifdef
name|UNIQPLEX
name|note
operator|->
name|n_id
operator|.
name|uniqid
operator|+=
name|UNIQPLEX
operator|*
name|io
operator|->
name|descr
operator|.
name|d_nfnum
expr_stmt|;
comment|/* mpx in nf num */
endif|#
directive|endif
block|}
if|if
condition|(
name|policy
condition|)
block|{
name|io
operator|->
name|descr
operator|.
name|d_plcy
operator|=
literal|1
expr_stmt|;
comment|/* mark as having a policy note */
name|notenum
operator|=
literal|0
expr_stmt|;
block|}
else|else
name|notenum
operator|=
operator|++
name|io
operator|->
name|descr
operator|.
name|d_nnote
expr_stmt|;
comment|/* this note's number */
if|if
condition|(
name|addtime
condition|)
comment|/* see if want timestamp */
name|gettime
argument_list|(
operator|&
name|io
operator|->
name|descr
operator|.
name|d_lastm
argument_list|)
expr_stmt|;
comment|/* last time file modified */
name|putnrec
argument_list|(
name|io
argument_list|,
name|notenum
argument_list|,
name|note
argument_list|)
expr_stmt|;
comment|/* write note info */
name|putdscr
argument_list|(
name|io
argument_list|,
operator|&
name|io
operator|->
name|descr
argument_list|)
expr_stmt|;
comment|/* rewrite header info */
if|if
condition|(
name|lockit
condition|)
name|unlocknf
argument_list|(
name|io
argument_list|,
name|DSCRLOCK
argument_list|)
expr_stmt|;
comment|/* END CRITICAL SECTION */
name|io
operator|->
name|nnotwrit
operator|++
expr_stmt|;
comment|/* bump count of writes */
return|return
operator|(
name|io
operator|->
name|descr
operator|.
name|d_nnote
operator|)
return|;
comment|/* tell which slot it is in */
block|}
end_block

begin_macro
name|delnote
argument_list|(
argument|io
argument_list|,
argument|noteno
argument_list|,
argument|lockit
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|io_f
modifier|*
name|io
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|note_f
name|note
decl_stmt|;
if|if
condition|(
name|lockit
condition|)
name|locknf
argument_list|(
name|io
argument_list|,
name|DSCRLOCK
argument_list|)
expr_stmt|;
comment|/* CRITICAL */
name|getnrec
argument_list|(
name|io
argument_list|,
name|noteno
argument_list|,
operator|&
name|note
argument_list|)
expr_stmt|;
comment|/* get the note */
name|note
operator|.
name|n_stat
operator||=
name|DELETED
expr_stmt|;
comment|/* deleted */
name|putnrec
argument_list|(
name|io
argument_list|,
name|noteno
argument_list|,
operator|&
name|note
argument_list|)
expr_stmt|;
name|getdscr
argument_list|(
name|io
argument_list|,
operator|&
name|io
operator|->
name|descr
argument_list|)
expr_stmt|;
comment|/* update delete count */
name|io
operator|->
name|descr
operator|.
name|d_delnote
operator|++
expr_stmt|;
name|io
operator|->
name|descr
operator|.
name|d_delresp
operator|+=
name|note
operator|.
name|n_nresp
expr_stmt|;
comment|/* count resps */
name|putdscr
argument_list|(
name|io
argument_list|,
operator|&
name|io
operator|->
name|descr
argument_list|)
expr_stmt|;
if|if
condition|(
name|lockit
condition|)
name|unlocknf
argument_list|(
name|io
argument_list|,
name|DSCRLOCK
argument_list|)
expr_stmt|;
comment|/* END CRITICAL */
block|}
end_block

end_unit

