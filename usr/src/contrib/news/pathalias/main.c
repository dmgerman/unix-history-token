begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pathalias -- by steve bellovin, as told to peter honeyman */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)main.c	9.8 91/06/11"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VMS
end_ifndef

begin_define
define|#
directive|define
name|MAIN
value|main
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAIN
value|XXmain
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"def.h"
end_include

begin_comment
comment|/* exports */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Cfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current input file */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Graphout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file for dumping edges (-g option) */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Linkout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file for dumping shortest path tree */
end_comment

begin_decl_stmt
name|char
modifier|*
modifier|*
name|Argv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* external copy of argv (for input files) */
end_comment

begin_decl_stmt
name|node
modifier|*
name|Home
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* node for local host */
end_comment

begin_decl_stmt
name|int
name|Cflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print costs (-c option) */
end_comment

begin_decl_stmt
name|int
name|Dflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* penalize routes beyond domains (-D option) */
end_comment

begin_decl_stmt
name|int
name|Iflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ignore case (-i option) */
end_comment

begin_decl_stmt
name|int
name|Tflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* trace links (-t option) */
end_comment

begin_decl_stmt
name|int
name|Vflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* verbose (-v option) */
end_comment

begin_decl_stmt
name|int
name|Fflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print cost of first hop */
end_comment

begin_decl_stmt
name|int
name|InetFlag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* local host is w/in scope of DNS (-I flag) */
end_comment

begin_decl_stmt
name|int
name|Lineno
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line number within current input file */
end_comment

begin_decl_stmt
name|int
name|Argc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* external copy of argc (for input files) */
end_comment

begin_function_decl
specifier|extern
name|void
name|die
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tracelink
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* imports */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|optind
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|Lcount
decl_stmt|,
name|Ncount
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|long
name|allocation
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|wasted
argument_list|()
decl_stmt|,
name|mapit
argument_list|()
decl_stmt|,
name|hashanalyze
argument_list|()
decl_stmt|,
name|deadlink
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|local
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|node
modifier|*
name|addnode
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|getopt
argument_list|()
decl_stmt|,
name|yyparse
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|printit
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|USAGE
value|"usage: %s [-vciDfI] [-l localname] [-d deadlink] [-t tracelink] [-g edgeout] [-s treeout] [-a avoid] [files ...]\n"
end_define

begin_expr_stmt
name|MAIN
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
specifier|register
name|int
name|argc
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
modifier|*
name|locname
init|=
literal|0
decl_stmt|,
modifier|*
name|bang
decl_stmt|;
specifier|register
name|int
name|c
decl_stmt|;
name|int
name|errflg
init|=
literal|0
decl_stmt|;
name|setbuf
argument_list|(
name|stderr
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|allocation
argument_list|()
expr_stmt|;
comment|/* initialize data space monitoring */
name|Cfile
operator|=
literal|"[deadlinks]"
expr_stmt|;
comment|/* for tracing dead links */
name|Argv
operator|=
name|argv
expr_stmt|;
name|Argc
operator|=
name|argc
expr_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
name|getopt
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|"cd:Dfg:iIl:s:t:v"
argument_list|)
operator|)
operator|!=
name|EOF
condition|)
switch|switch
condition|(
name|c
condition|)
block|{
case|case
literal|'c'
case|:
comment|/* print cost info */
name|Cflag
operator|++
expr_stmt|;
break|break;
case|case
literal|'d'
case|:
comment|/* dead host or link */
if|if
condition|(
operator|(
name|bang
operator|=
name|index
argument_list|(
name|optarg
argument_list|,
literal|'!'
argument_list|)
operator|)
operator|!=
literal|0
condition|)
block|{
operator|*
name|bang
operator|++
operator|=
literal|0
expr_stmt|;
name|deadlink
argument_list|(
name|addnode
argument_list|(
name|optarg
argument_list|)
argument_list|,
name|addnode
argument_list|(
name|bang
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
name|deadlink
argument_list|(
name|addnode
argument_list|(
name|optarg
argument_list|)
argument_list|,
operator|(
name|node
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'D'
case|:
comment|/* penalize routes beyond domains */
name|Dflag
operator|++
expr_stmt|;
break|break;
case|case
literal|'f'
case|:
comment|/* print cost of first hop */
name|Cflag
operator|++
expr_stmt|;
name|Fflag
operator|++
expr_stmt|;
break|break;
case|case
literal|'g'
case|:
comment|/* graph output file */
name|Graphout
operator|=
name|optarg
expr_stmt|;
break|break;
case|case
literal|'i'
case|:
comment|/* ignore case */
name|Iflag
operator|++
expr_stmt|;
break|break;
case|case
literal|'I'
case|:
comment|/* Internet connected */
name|InetFlag
operator|++
expr_stmt|;
break|break;
case|case
literal|'l'
case|:
comment|/* local name */
name|locname
operator|=
name|optarg
expr_stmt|;
break|break;
case|case
literal|'s'
case|:
comment|/* show shortest path tree */
name|Linkout
operator|=
name|optarg
expr_stmt|;
break|break;
case|case
literal|'t'
case|:
comment|/* trace this link */
if|if
condition|(
name|tracelink
argument_list|(
name|optarg
argument_list|)
operator|<
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: can trace only %d links\n"
argument_list|,
name|Argv
index|[
literal|0
index|]
argument_list|,
name|NTRACE
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|ERROR
argument_list|)
expr_stmt|;
block|}
name|Tflag
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'v'
case|:
comment|/* verbose stderr, mixed blessing */
name|Vflag
operator|++
expr_stmt|;
break|break;
default|default:
name|errflg
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|errflg
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|USAGE
argument_list|,
name|Argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|ERROR
argument_list|)
expr_stmt|;
block|}
name|argv
operator|+=
name|optind
expr_stmt|;
comment|/* kludge for yywrap() */
if|if
condition|(
operator|*
name|argv
condition|)
name|freopen
argument_list|(
name|NULL_DEVICE
argument_list|,
literal|"r"
argument_list|,
name|stdin
argument_list|)
expr_stmt|;
else|else
name|Cfile
operator|=
literal|"[stdin]"
expr_stmt|;
if|if
condition|(
operator|!
name|locname
condition|)
name|locname
operator|=
name|local
argument_list|()
expr_stmt|;
if|if
condition|(
operator|*
name|locname
operator|==
literal|0
condition|)
block|{
name|locname
operator|=
literal|"lostinspace"
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: using \"%s\" for local name\n"
argument_list|,
name|Argv
index|[
literal|0
index|]
argument_list|,
name|locname
argument_list|)
expr_stmt|;
block|}
name|Home
operator|=
name|addnode
argument_list|(
name|locname
argument_list|)
expr_stmt|;
comment|/* add home node */
name|Home
operator|->
name|n_cost
operator|=
literal|0
expr_stmt|;
comment|/* doesn't cost to get here */
operator|(
name|void
operator|)
name|yyparse
argument_list|()
expr_stmt|;
comment|/* read in link info */
if|if
condition|(
name|Vflag
operator|>
literal|1
condition|)
name|hashanalyze
argument_list|()
expr_stmt|;
name|vprintf
argument_list|(
name|stderr
argument_list|,
literal|"%d nodes, %d links, alloc %ldk\n"
argument_list|,
name|Ncount
argument_list|,
name|Lcount
argument_list|,
name|allocation
argument_list|()
argument_list|)
expr_stmt|;
name|Cfile
operator|=
literal|"[backlinks]"
expr_stmt|;
comment|/* for tracing back links */
name|Lineno
operator|=
literal|0
expr_stmt|;
comment|/* compute shortest path tree */
name|mapit
argument_list|()
expr_stmt|;
name|vprintf
argument_list|(
name|stderr
argument_list|,
literal|"allocation is %ldk after mapping\n"
argument_list|,
name|allocation
argument_list|()
argument_list|)
expr_stmt|;
comment|/* traverse tree and print paths */
name|printit
argument_list|()
expr_stmt|;
name|vprintf
argument_list|(
name|stderr
argument_list|,
literal|"allocation is %ldk after printing\n"
argument_list|,
name|allocation
argument_list|()
argument_list|)
expr_stmt|;
name|wasted
argument_list|()
expr_stmt|;
comment|/* how much was wasted in memory allocation? */
return|return
name|OK
return|;
block|}
end_block

begin_function
name|void
name|die
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|DEBUG
specifier|extern
name|int
name|abort
parameter_list|()
function_decl|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: %s\n"
argument_list|,
name|Argv
index|[
literal|0
index|]
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
else|#
directive|else
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: %s; notify the authorities\n"
argument_list|,
name|Argv
index|[
literal|0
index|]
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|SEVERE_ERROR
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

