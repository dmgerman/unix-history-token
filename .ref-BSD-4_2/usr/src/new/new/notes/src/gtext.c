begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)gtext.c	1.2 2/1/83"
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
comment|/*  *	get the text for a note/response  *  *	Calls unix editor with a unique file name   *	Also makes sure the returned text is of   *	appropriate size  *  *	Ray Essick 10/23/80  *	Modified : rbk	10/26/80  *	modified again:	rbe 12 nov 81	fix to version 7 and general shtuff  *	modified a third time to add insert-text for user  *		Ray Essick	December 1981  */
end_comment

begin_macro
name|gettext
argument_list|(
argument|io
argument_list|,
argument|where
argument_list|,
argument|preface
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

begin_comment
comment|/* where we left it */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|preface
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* text included in buffer */
end_comment

begin_block
block|{
name|FILE
modifier|*
name|scr
decl_stmt|,
modifier|*
name|fopen
argument_list|()
decl_stmt|;
name|int
name|c
decl_stmt|;
name|char
name|cmd
index|[
name|CMDLEN
index|]
decl_stmt|;
comment|/* build the editor call */
name|char
name|fn
index|[
name|WDLEN
index|]
decl_stmt|;
comment|/* scratch file name */
specifier|extern
name|char
modifier|*
name|myeditor
decl_stmt|;
name|sprintf
argument_list|(
name|fn
argument_list|,
literal|"/tmp/nf%d"
argument_list|,
name|getpid
argument_list|()
argument_list|)
expr_stmt|;
name|x
argument_list|(
operator|(
name|scr
operator|=
name|fopen
argument_list|(
name|fn
argument_list|,
literal|"w"
argument_list|)
operator|)
operator|==
name|NULL
argument_list|,
literal|"gettext: create scratch"
argument_list|)
expr_stmt|;
name|x
argument_list|(
name|chmod
argument_list|(
name|fn
argument_list|,
literal|0666
argument_list|)
operator|<
literal|0
argument_list|,
literal|"gettext: chmod tmp"
argument_list|)
expr_stmt|;
if|if
condition|(
name|preface
operator|!=
name|NULL
condition|)
block|{
while|while
condition|(
operator|(
name|c
operator|=
name|getc
argument_list|(
name|preface
argument_list|)
operator|)
operator|!=
name|EOF
condition|)
block|{
name|putc
argument_list|(
name|c
argument_list|,
name|scr
argument_list|)
expr_stmt|;
comment|/* move included text */
block|}
block|}
name|fclose
argument_list|(
name|scr
argument_list|)
expr_stmt|;
name|c
operator|=
name|dounix
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
name|myeditor
argument_list|,
name|fn
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* call his editor */
if|if
condition|(
name|c
operator|!=
literal|0
condition|)
name|wfchar
argument_list|()
expr_stmt|;
name|x
argument_list|(
operator|(
name|scr
operator|=
name|fopen
argument_list|(
name|fn
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
argument_list|,
literal|"gettext: scratch file"
argument_list|)
expr_stmt|;
name|c
operator|=
name|pagein
argument_list|(
name|io
argument_list|,
name|scr
argument_list|,
name|where
argument_list|)
expr_stmt|;
comment|/* move text in */
name|fclose
argument_list|(
name|scr
argument_list|)
expr_stmt|;
name|x
argument_list|(
name|unlink
argument_list|(
name|fn
argument_list|)
operator|<
literal|0
argument_list|,
literal|"gettext: unlink"
argument_list|)
expr_stmt|;
return|return
operator|(
name|c
operator|)
return|;
comment|/* return count of characters moved */
block|}
end_block

end_unit

