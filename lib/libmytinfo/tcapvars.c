begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * tcapvars.c  *  * By Ross Ridge  * Public Domain  * 92/02/01 07:30:21  *  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|<term.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USE_SCCS_IDS
end_ifdef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|SCCSid
index|[]
init|=
literal|"@(#) mytinfo tcapvars.c 3.2 92/02/01 public domain, By Ross Ridge"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
name|PC
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|ospeed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|UP
decl_stmt|,
modifier|*
name|BC
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|_figure_termcap
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|USE_SGTTY
argument_list|)
operator|||
name|defined
argument_list|(
name|USE_TERMIO
argument_list|)
operator|||
name|defined
argument_list|(
name|USE_TERMIOS
argument_list|)
ifdef|#
directive|ifdef
name|USE_TERMIOS
specifier|extern
name|speed_t
name|_baud_tbl
index|[]
decl_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|USE_SMALLMEM
specifier|extern
name|unsigned
name|short
name|_baud_tbl
index|[]
decl_stmt|;
else|#
directive|else
specifier|extern
name|long
name|_baud_tbl
index|[]
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
name|cur_term
operator|->
name|padch
operator|=
name|PC
expr_stmt|;
name|cur_term
operator|->
name|baudrate
operator|=
name|_baud_tbl
index|[
name|ospeed
index|]
expr_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

