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
literal|"$Header: preptxt.c,v 1.7 85/01/18 15:35:18 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_comment
comment|/*  *	preptxt()  *	put the standard headers and text into the specified file  *  *	Original coding:	Ray Essick	December 1981  */
end_comment

begin_macro
name|preptxt
argument_list|(
argument|io
argument_list|,
argument|zfile
argument_list|,
argument|author
argument_list|,
argument|date
argument_list|,
argument|where
argument_list|,
argument|title
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
name|FILE
modifier|*
name|zfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|auth_f
modifier|*
name|author
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|when_f
modifier|*
name|date
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

begin_block
block|{
name|char
name|buf
index|[
name|DATELEN
operator|+
literal|6
index|]
decl_stmt|;
comment|/* formatted date */
name|char
name|auth
index|[
name|NAMESZ
operator|+
name|SYSSZ
operator|+
literal|2
index|]
decl_stmt|;
comment|/* formatted author */
name|int
name|linecount
decl_stmt|;
name|char
name|ttl
index|[
name|TITLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* title + \0 */
name|int
name|i
decl_stmt|;
name|sprdate
argument_list|(
name|date
argument_list|,
name|buf
argument_list|)
expr_stmt|;
comment|/* format the date */
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|author
operator|->
name|aname
argument_list|,
literal|"Anonymous"
argument_list|)
condition|)
name|strcpy
argument_list|(
name|auth
argument_list|,
literal|"Anonymous"
argument_list|)
expr_stmt|;
else|else
block|{
ifdef|#
directive|ifdef
name|USERHOST
name|sprintf
argument_list|(
name|auth
argument_list|,
literal|"%s@%s"
argument_list|,
name|author
operator|->
name|aname
argument_list|,
name|author
operator|->
name|asystem
argument_list|)
expr_stmt|;
else|#
directive|else
name|sprintf
argument_list|(
name|auth
argument_list|,
literal|"%s!%s"
argument_list|,
name|author
operator|->
name|asystem
argument_list|,
name|author
operator|->
name|aname
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|USERHOST
block|}
ifdef|#
directive|ifdef
name|notdef
name|fprintf
argument_list|(
name|zfile
argument_list|,
literal|"/**** %s:%s / %s / %s ****/\n"
argument_list|,
name|System
argument_list|,
name|io
operator|->
name|nf
argument_list|,
name|auth
argument_list|,
name|buf
argument_list|)
expr_stmt|;
name|linecount
operator|=
literal|1
expr_stmt|;
comment|/* 1 line saved */
else|#
directive|else
comment|/*  *	A more verbose but prettier header  */
name|fprintf
argument_list|(
name|zfile
argument_list|,
literal|"/* Written %s by %s in %s:%s */\n"
argument_list|,
name|buf
argument_list|,
name|auth
argument_list|,
name|System
argument_list|,
name|io
operator|->
name|nf
argument_list|)
expr_stmt|;
name|linecount
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|title
condition|)
block|{
name|fprintf
argument_list|(
name|zfile
argument_list|,
literal|"/* ---------- \"%s\" ---------- */\n"
argument_list|,
name|title
argument_list|)
expr_stmt|;
name|linecount
operator|++
expr_stmt|;
comment|/* 1 more line saved */
block|}
endif|#
directive|endif
name|linecount
operator|+=
name|pageout
argument_list|(
name|io
argument_list|,
name|where
argument_list|,
name|zfile
argument_list|)
expr_stmt|;
comment|/* write to the file */
ifdef|#
directive|ifdef
name|notdef
name|fprintf
argument_list|(
name|zfile
argument_list|,
literal|"/* ---------- */\n"
argument_list|)
expr_stmt|;
comment|/* a trailer */
else|#
directive|else
comment|/*  *	prettier stuff; goes together with a prettier header message  *	done above.  */
name|fprintf
argument_list|(
name|zfile
argument_list|,
literal|"/* End of text from %s:%s */\n"
argument_list|,
name|System
argument_list|,
name|io
operator|->
name|nf
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|linecount
operator|++
expr_stmt|;
comment|/* count trailer */
return|return
name|linecount
return|;
block|}
end_block

end_unit

