begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_comment
comment|/* $Header: par.h,v 1.1 84/07/04 17:57:16 timo Exp $ */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|EQ
value|==
end_define

begin_define
define|#
directive|define
name|NE
value|!=
end_define

begin_define
define|#
directive|define
name|EOS
value|'\0'
end_define

begin_define
define|#
directive|define
name|ERR
value|(-1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MFILE
end_ifdef

begin_define
define|#
directive|define
name|MDOTS
value|"... "
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MDOTS
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ERM
value|{fprintf(stderr, "%s: ", pname); fprintf(stderr,
end_define

begin_define
define|#
directive|define
name|MRE
value|); exit(ERR); }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_decl_stmt
name|int
name|__void__
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* to tell `lint' not to care */
end_comment

begin_define
define|#
directive|define
name|VOID
parameter_list|(
name|x
parameter_list|)
value|(__void__ = (int)(x))
end_define

begin_else
else|#
directive|else
else|lint
end_else

begin_define
define|#
directive|define
name|VOID
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_decl_stmt
name|FILE
modifier|*
name|ifile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input file */
end_comment

begin_decl_stmt
name|char
modifier|*
name|iname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input name */
end_comment

begin_decl_stmt
name|char
modifier|*
name|pname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* program name */
end_comment

begin_function
name|main
parameter_list|(
name|pargc
parameter_list|,
name|pargv
parameter_list|)
name|char
modifier|*
name|pargv
index|[]
decl_stmt|;
block|{
specifier|register
name|int
name|argc
decl_stmt|;
specifier|register
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
name|pname
operator|=
name|pargv
index|[
literal|0
index|]
expr_stmt|;
name|argc
operator|=
name|pargc
operator|-
literal|1
expr_stmt|;
name|argv
operator|=
name|pargv
operator|+
literal|1
expr_stmt|;
while|while
condition|(
name|argc
operator|>
literal|0
operator|&&
name|argv
index|[
literal|0
index|]
index|[
literal|0
index|]
name|EQ
literal|'-'
operator|&&
name|argv
index|[
literal|0
index|]
index|[
literal|1
index|]
name|NE
name|EOS
condition|)
block|{
ifdef|#
directive|ifdef
name|OPTIONS
specifier|register
name|int
name|nop
init|=
name|options
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
if|if
condition|(
name|nop
name|EQ
name|ERR
condition|)
name|ERM
literal|"options are [%s] [ file %s]\n"
operator|,
name|OPTIONS
operator|,
name|MDOTS
name|MRE
name|argc
operator|-=
name|nop
expr_stmt|;
name|argv
operator|+=
name|nop
expr_stmt|;
else|#
directive|else
name|ERM
literal|"parameters are [ file %s]\n"
operator|,
name|MDOTS
name|MRE
endif|#
directive|endif
block|}
ifndef|#
directive|ifndef
name|MFILE
if|if
condition|(
name|argc
operator|>
literal|1
condition|)
name|ERM
literal|"arg count\n"
name|MRE
endif|#
directive|endif
do|do
block|{
if|if
condition|(
name|argc
name|EQ
literal|0
operator|||
operator|(
name|argv
index|[
literal|0
index|]
index|[
literal|0
index|]
name|EQ
literal|'-'
operator|&&
name|argv
index|[
literal|0
index|]
index|[
literal|1
index|]
name|EQ
name|EOS
operator|)
condition|)
block|{
name|iname
operator|=
literal|"standard input"
expr_stmt|;
name|ifile
operator|=
name|stdin
expr_stmt|;
block|}
else|else
block|{
name|iname
operator|=
operator|*
name|argv
expr_stmt|;
name|ifile
operator|=
name|fopen
argument_list|(
name|iname
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|MFILE
if|if
condition|(
name|ifile
name|EQ
name|NULL
condition|)
name|ERM
literal|"cannot open %s\n"
operator|,
name|iname
name|MRE
endif|#
directive|endif
block|}
name|process
argument_list|()
expr_stmt|;
if|if
condition|(
name|ifile
name|NE
name|NULL
operator|&&
name|ifile
name|NE
name|stdin
condition|)
name|VOID
argument_list|(
name|fclose
argument_list|(
name|ifile
argument_list|)
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
operator|++
name|argv
operator|,
operator|--
name|argc
operator|>
literal|0
condition|)
do|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

