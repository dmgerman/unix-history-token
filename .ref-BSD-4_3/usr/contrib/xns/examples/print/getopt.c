begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/*  * get option letter from argument vector  */
end_comment

begin_decl_stmt
name|int
name|opterr
init|=
literal|1
decl_stmt|,
comment|/* useless, never set or used */
name|optind
init|=
literal|1
decl_stmt|,
comment|/* index into parent argv vector */
name|optopt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* character checked for validity */
end_comment

begin_decl_stmt
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* argument associated with option */
end_comment

begin_define
define|#
directive|define
name|BADCH
value|(int)'?'
end_define

begin_define
define|#
directive|define
name|EMSG
value|""
end_define

begin_define
define|#
directive|define
name|tell
parameter_list|(
name|s
parameter_list|)
value|fputs(*nargv,stderr);fputs(s,stderr); \ 		fputc(optopt,stderr);fputc('\n',stderr);return(BADCH);
end_define

begin_macro
name|getopt
argument_list|(
argument|nargc
argument_list|,
argument|nargv
argument_list|,
argument|ostr
argument_list|)
end_macro

begin_decl_stmt
name|int
name|nargc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|nargv
decl_stmt|,
modifier|*
name|ostr
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|static
name|char
modifier|*
name|place
init|=
name|EMSG
decl_stmt|;
comment|/* option letter processing */
specifier|register
name|char
modifier|*
name|oli
decl_stmt|;
comment|/* option letter list index */
name|char
modifier|*
name|index
parameter_list|()
function_decl|;
if|if
condition|(
operator|!
operator|*
name|place
condition|)
block|{
comment|/* update scanning pointer */
if|if
condition|(
name|optind
operator|>=
name|nargc
operator|||
operator|*
operator|(
name|place
operator|=
name|nargv
index|[
name|optind
index|]
operator|)
operator|!=
literal|'-'
operator|||
operator|!
operator|*
operator|++
name|place
condition|)
return|return
operator|(
name|EOF
operator|)
return|;
if|if
condition|(
operator|*
name|place
operator|==
literal|'-'
condition|)
block|{
comment|/* found "--" */
operator|++
name|optind
expr_stmt|;
return|return
operator|(
name|EOF
operator|)
return|;
block|}
block|}
comment|/* option letter okay? */
if|if
condition|(
operator|(
name|optopt
operator|=
operator|(
name|int
operator|)
operator|*
name|place
operator|++
operator|)
operator|==
operator|(
name|int
operator|)
literal|':'
operator|||
operator|!
operator|(
name|oli
operator|=
name|index
argument_list|(
name|ostr
argument_list|,
name|optopt
argument_list|)
operator|)
condition|)
block|{
if|if
condition|(
operator|!
operator|*
name|place
condition|)
operator|++
name|optind
expr_stmt|;
name|tell
argument_list|(
literal|": illegal option -- "
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|*
operator|++
name|oli
operator|!=
literal|':'
condition|)
block|{
comment|/* don't need argument */
name|optarg
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
operator|!
operator|*
name|place
condition|)
operator|++
name|optind
expr_stmt|;
block|}
else|else
block|{
comment|/* need an argument */
if|if
condition|(
operator|*
name|place
condition|)
name|optarg
operator|=
name|place
expr_stmt|;
comment|/* no white space */
elseif|else
if|if
condition|(
name|nargc
operator|<=
operator|++
name|optind
condition|)
block|{
comment|/* no arg */
name|place
operator|=
name|EMSG
expr_stmt|;
name|tell
argument_list|(
literal|": option requires an argument -- "
argument_list|)
expr_stmt|;
block|}
else|else
name|optarg
operator|=
name|nargv
index|[
name|optind
index|]
expr_stmt|;
comment|/* white space */
name|place
operator|=
name|EMSG
expr_stmt|;
operator|++
name|optind
expr_stmt|;
block|}
return|return
operator|(
name|optopt
operator|)
return|;
comment|/* dump back option letter */
block|}
end_block

end_unit

