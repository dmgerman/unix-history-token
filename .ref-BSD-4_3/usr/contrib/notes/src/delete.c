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
literal|"$Header: delete.c,v 1.7 85/01/18 15:08:35 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_comment
comment|/*  *	mdelete(io, first, last)  *	deletes all the notes in the specified range in the notefile.  *  *	no verification of the desire to delete the notes is performed.  *	It just goes and zaps them..  *  *	returns 0 if all goes well, -1 if it didn't like something  *  *	Original coding:	Ray Essick	Jan 1982  */
end_comment

begin_macro
name|mdelete
argument_list|(
argument|io
argument_list|,
argument|first
argument_list|,
argument|last
argument_list|,
argument|zapping
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
name|int
name|first
decl_stmt|,
name|last
decl_stmt|,
comment|/* range */
name|zapping
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* delete/undelete */
end_comment

begin_block
block|{
name|int
name|which
decl_stmt|;
name|struct
name|note_f
name|note
decl_stmt|;
comment|/* for undelete */
name|x
argument_list|(
name|first
operator|>
name|last
argument_list|,
literal|"mdelete: nonsense first/last"
argument_list|)
expr_stmt|;
name|locknf
argument_list|(
name|io
argument_list|,
name|DSCRLOCK
argument_list|)
expr_stmt|;
comment|/* lock for duration */
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
if|if
condition|(
name|last
operator|>
name|io
operator|->
name|descr
operator|.
name|d_nnote
condition|)
name|last
operator|=
name|io
operator|->
name|descr
operator|.
name|d_nnote
expr_stmt|;
if|if
condition|(
name|first
operator|>
name|io
operator|->
name|descr
operator|.
name|d_nnote
condition|)
name|first
operator|=
name|io
operator|->
name|descr
operator|.
name|d_nnote
expr_stmt|;
for|for
control|(
name|which
operator|=
name|first
init|;
name|which
operator|<=
name|last
condition|;
name|which
operator|++
control|)
block|{
if|if
condition|(
name|zapping
condition|)
comment|/* deletion */
block|{
name|delnote
argument_list|(
name|io
argument_list|,
name|which
argument_list|,
name|NOLOCKIT
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|getnrec
argument_list|(
name|io
argument_list|,
name|which
argument_list|,
operator|&
name|note
argument_list|)
expr_stmt|;
comment|/* get the note */
name|note
operator|.
name|n_stat
operator|&=
name|NOT
name|DELETED
expr_stmt|;
comment|/* un-deleted */
name|putnrec
argument_list|(
name|io
argument_list|,
name|which
argument_list|,
operator|&
name|note
argument_list|)
expr_stmt|;
block|}
block|}
name|unlocknf
argument_list|(
name|io
argument_list|,
name|DSCRLOCK
argument_list|)
expr_stmt|;
comment|/* release the lock */
return|return
literal|0
return|;
block|}
end_block

end_unit

