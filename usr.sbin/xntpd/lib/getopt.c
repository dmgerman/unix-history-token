begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* getopt.c,v 3.1 1993/07/06 01:08:18 jbj Exp  * getopt - get option letter from argv  *  * This is a version of the public domain getopt() implementation by  * Henry Spencer, changed for 4.3BSD compatibility (in addition to System V).  * It allows rescanning of an option list by setting optind to 0 before  * calling.  Thanks to Dennis Ferguson for the appropriate modifications.  *  * This file is in the Public Domain.  */
end_comment

begin_comment
comment|/*LINTLIBRARY*/
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_undef
undef|#
directive|undef
name|putc
end_undef

begin_define
define|#
directive|define
name|putc
value|fputc
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_decl_stmt
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Global argument pointer. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__convex__
end_ifndef

begin_decl_stmt
name|int
name|optind
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Global argv index. */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __convex__ */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|optind
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Global argv index. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __convex__ */
end_comment

begin_comment
comment|/*  * N.B. use following at own risk  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__convex__
end_ifndef

begin_decl_stmt
name|int
name|opterr
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for compatibility, should error be printed? */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __convex__ */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|opterr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for compatibility, should error be printed? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __convex__ */
end_comment

begin_decl_stmt
name|int
name|optopt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for compatibility, option character checked */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|scan
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Private scan pointer. */
end_comment

begin_comment
comment|/*  * Print message about a bad option.  Watch this definition, it's  * not a single statement.  */
end_comment

begin_define
define|#
directive|define
name|BADOPT
parameter_list|(
name|mess
parameter_list|,
name|ch
parameter_list|)
value|if (opterr) { \ 					fputs(argv[0], stderr); \ 					fputs(mess, stderr); \ 					(void) putc(ch, stderr); \ 					(void) putc('\n', stderr); \ 				} \ 				return('?')
end_define

begin_function
name|int
name|getopt_l
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|,
name|optstring
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
name|char
modifier|*
name|optstring
decl_stmt|;
block|{
specifier|register
name|char
name|c
decl_stmt|;
specifier|register
name|char
modifier|*
name|place
decl_stmt|;
name|optarg
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|optind
operator|==
literal|0
condition|)
block|{
name|scan
operator|=
name|NULL
expr_stmt|;
name|optind
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|scan
operator|==
name|NULL
operator|||
operator|*
name|scan
operator|==
literal|'\0'
condition|)
block|{
if|if
condition|(
name|optind
operator|>=
name|argc
operator|||
name|argv
index|[
name|optind
index|]
index|[
literal|0
index|]
operator|!=
literal|'-'
operator|||
name|argv
index|[
name|optind
index|]
index|[
literal|1
index|]
operator|==
literal|'\0'
condition|)
return|return
name|EOF
return|;
if|if
condition|(
name|argv
index|[
name|optind
index|]
index|[
literal|1
index|]
operator|==
literal|'-'
operator|&&
name|argv
index|[
name|optind
index|]
index|[
literal|2
index|]
operator|==
literal|'\0'
condition|)
block|{
name|optind
operator|++
expr_stmt|;
return|return
name|EOF
return|;
block|}
name|scan
operator|=
name|argv
index|[
name|optind
index|]
operator|+
literal|1
expr_stmt|;
name|optind
operator|++
expr_stmt|;
block|}
name|c
operator|=
operator|*
name|scan
operator|++
expr_stmt|;
name|optopt
operator|=
name|c
operator|&
literal|0377
expr_stmt|;
for|for
control|(
name|place
operator|=
name|optstring
init|;
name|place
operator|!=
name|NULL
operator|&&
operator|*
name|place
operator|!=
literal|'\0'
condition|;
operator|++
name|place
control|)
if|if
condition|(
operator|*
name|place
operator|==
name|c
condition|)
break|break;
if|if
condition|(
name|place
operator|==
name|NULL
operator|||
operator|*
name|place
operator|==
literal|'\0'
operator|||
name|c
operator|==
literal|':'
operator|||
name|c
operator|==
literal|'?'
condition|)
block|{
name|BADOPT
argument_list|(
literal|": unknown option -"
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
name|place
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|place
operator|==
literal|':'
condition|)
block|{
if|if
condition|(
operator|*
name|scan
operator|!=
literal|'\0'
condition|)
block|{
name|optarg
operator|=
name|scan
expr_stmt|;
name|scan
operator|=
name|NULL
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|optind
operator|>=
name|argc
condition|)
block|{
name|BADOPT
argument_list|(
literal|": option requires argument -"
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|optarg
operator|=
name|argv
index|[
name|optind
index|]
expr_stmt|;
name|optind
operator|++
expr_stmt|;
block|}
block|}
return|return
name|c
operator|&
literal|0377
return|;
block|}
end_function

end_unit

