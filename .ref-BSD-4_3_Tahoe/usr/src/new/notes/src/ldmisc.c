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
literal|"$Header: ldmisc.c,v 1.7 85/01/18 15:14:52 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_comment
comment|/*	misc routines used in loading a generic form back into the notefile  *	includes routines to suck in a line, parse a unique identifier and  *	all sorts of other fun stuff  *  *	Ray Essick	december 1981  */
end_comment

begin_comment
comment|/*  *	timein(line, atime) - grab a time from a coded line.  *	makes sure that all the pieces of a time come in.  */
end_comment

begin_macro
name|timein
argument_list|(
argument|line
argument_list|,
argument|atime
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|line
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|when_f
modifier|*
name|atime
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|count
decl_stmt|;
name|count
operator|=
name|sscanf
argument_list|(
name|line
argument_list|,
literal|"%hd:%hd:%hd:%hd:%hd:%ld:"
argument_list|,
operator|&
name|atime
operator|->
name|w_year
argument_list|,
operator|&
name|atime
operator|->
name|w_month
argument_list|,
operator|&
name|atime
operator|->
name|w_day
argument_list|,
operator|&
name|atime
operator|->
name|w_hours
argument_list|,
operator|&
name|atime
operator|->
name|w_mins
argument_list|,
operator|&
name|atime
operator|->
name|w_gmttime
argument_list|)
expr_stmt|;
if|if
condition|(
name|count
operator|<
literal|5
condition|)
block|{
name|printf
argument_list|(
literal|"timein: bad date read, set to now\n"
argument_list|)
expr_stmt|;
name|gettime
argument_list|(
name|atime
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|count
operator|<
literal|6
condition|)
comment|/* no gmttime */
name|atime
operator|->
name|w_gmttime
operator|=
literal|0
expr_stmt|;
comment|/* empty */
block|}
end_block

begin_comment
comment|/*  *	initnote(&note_f)  *  *	zero most of the fields of a note_f  *  */
end_comment

begin_macro
name|initnote
argument_list|(
argument|note
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|note_f
modifier|*
name|note
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
name|strcpy
argument_list|(
name|note
operator|->
name|n_id
operator|.
name|sys
argument_list|,
literal|""
argument_list|)
expr_stmt|;
comment|/* unique id */
name|note
operator|->
name|n_id
operator|.
name|uniqid
operator|=
literal|0
expr_stmt|;
name|note
operator|->
name|n_nresp
operator|=
literal|0
expr_stmt|;
comment|/* no responses */
name|note
operator|->
name|ntitle
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* empty title */
name|strcpy
argument_list|(
name|note
operator|->
name|n_auth
operator|.
name|aname
argument_list|,
literal|"Unknown"
argument_list|)
expr_stmt|;
comment|/* author */
name|note
operator|->
name|n_auth
operator|.
name|aid
operator|=
name|Anonuid
expr_stmt|;
name|gettime
argument_list|(
operator|&
name|note
operator|->
name|n_date
argument_list|)
expr_stmt|;
comment|/* date written */
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
name|strcpy
argument_list|(
name|note
operator|->
name|n_from
argument_list|,
literal|""
argument_list|)
expr_stmt|;
comment|/* from where */
name|note
operator|->
name|n_rindx
operator|=
literal|0
expr_stmt|;
comment|/* no responses */
name|note
operator|->
name|n_stat
operator|=
literal|0
expr_stmt|;
comment|/* no status bits */
block|}
end_block

end_unit

