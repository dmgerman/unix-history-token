begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|MAINLINE
end_define

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

begin_include
include|#
directive|include
file|"newsgate.h"
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
literal|"$Header: newsoutput.c,v 1.7.0.1 85/03/22 10:54:22 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_comment
comment|/*  *	newsoutput - place the specified notesfiles out to the  *	news susbsystem.   *  *	Original Coding:	Ray Essick	April 1982  *	Modified to better handle multiple system gateing  *				Ray Essick	September 1982  */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|whichsys
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* who dumping for */
end_comment

begin_decl_stmt
specifier|static
name|int
name|verbosity
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* quiet */
end_comment

begin_decl_stmt
specifier|static
name|int
name|backward
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* do old format */
end_comment

begin_decl_stmt
name|char
name|rnewscmd
index|[
name|CMDLEN
index|]
init|=
name|DFLTRNEWS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how to rnews */
end_comment

begin_decl_stmt
name|int
name|sendclass
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* classes to send */
end_comment

begin_decl_stmt
name|int
name|usetime
init|=
name|NORMSEQ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user supplied */
end_comment

begin_decl_stmt
name|int
name|gatesyscount
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* actives slots in */
end_comment

begin_decl_stmt
name|char
modifier|*
name|gatesysnames
index|[
name|GATEMAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of names */
end_comment

begin_macro
name|newsone
argument_list|(
argument|nfname
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|nfname
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|verbosity
condition|)
block|{
name|printf
argument_list|(
literal|"\t%s\n"
argument_list|,
name|nfname
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
block|}
return|return
name|newsout
argument_list|(
name|nfname
argument_list|,
name|backward
argument_list|,
name|usetime
argument_list|,
name|verbosity
argument_list|)
return|;
block|}
end_block

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
name|struct
name|nflist_f
modifier|*
name|nfptr
decl_stmt|;
name|char
modifier|*
name|outgoing
decl_stmt|;
name|struct
name|when_f
name|ztime
decl_stmt|;
name|char
name|fmtdate
index|[
name|DATELEN
index|]
decl_stmt|;
comment|/* formatted date */
name|int
name|aflag
decl_stmt|,
name|cflag
decl_stmt|,
name|sflag
decl_stmt|;
name|startup
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
comment|/* common init */
if|if
condition|(
name|argc
operator|==
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"Usage: %s [-ssitename | -a] [-v] [-b] [-f file] topic1 [topic2 ...]\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|BAD
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|globuid
operator|!=
name|Notesuid
condition|)
block|{
name|printf
argument_list|(
literal|"Sorry, only notes 'owner' can send notes to news\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|BAD
argument_list|)
expr_stmt|;
block|}
name|whichsys
operator|=
name|System
expr_stmt|;
comment|/* defaults to local */
name|aflag
operator|=
name|cflag
operator|=
name|sflag
operator|=
literal|0
expr_stmt|;
comment|/* none done */
name|gatesyscount
operator|=
literal|0
expr_stmt|;
comment|/* none there */
name|verbosity
operator|=
literal|0
expr_stmt|;
comment|/* no messages */
name|backward
operator|=
literal|0
expr_stmt|;
comment|/* just new format */
name|usetime
operator|=
name|NORMSEQ
expr_stmt|;
comment|/* non-seq time */
name|strcpy
argument_list|(
name|rnewscmd
argument_list|,
name|DFLTRNEWS
argument_list|)
expr_stmt|;
comment|/* default rnews */
name|getnet
argument_list|(
name|RNEWSNAME
argument_list|,
operator|&
name|outgoing
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|/* how to get there */
if|if
condition|(
name|outgoing
operator|!=
operator|(
name|char
operator|*
operator|)
name|NULL
condition|)
comment|/* specified? */
name|strcpy
argument_list|(
name|rnewscmd
argument_list|,
name|outgoing
argument_list|)
expr_stmt|;
comment|/* load it */
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|argc
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|argv
index|[
name|i
index|]
index|[
literal|0
index|]
operator|==
literal|'-'
condition|)
switch|switch
condition|(
name|argv
index|[
name|i
index|]
index|[
literal|1
index|]
condition|)
block|{
case|case
literal|'s'
case|:
comment|/* gateway for */
name|sflag
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|argv
index|[
name|i
index|]
index|[
literal|2
index|]
operator|!=
literal|'\0'
condition|)
comment|/* -ssite */
block|{
name|whichsys
operator|=
operator|&
name|argv
index|[
name|i
index|]
index|[
literal|2
index|]
expr_stmt|;
block|}
else|else
block|{
comment|/* -s sitename */
if|if
condition|(
operator|++
name|i
operator|==
name|argc
condition|)
comment|/* no sitename */
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"-s must be followed by a sitename\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|BAD
argument_list|)
expr_stmt|;
block|}
name|whichsys
operator|=
name|argv
index|[
name|i
index|]
expr_stmt|;
comment|/* mark site */
block|}
name|gatesyscount
operator|=
literal|1
expr_stmt|;
comment|/* fill in table */
name|gatesysnames
index|[
literal|0
index|]
operator|=
name|whichsys
expr_stmt|;
break|break;
case|case
literal|'a'
case|:
comment|/* all non-local */
name|sendclass
operator||=
name|NEWS_ALLSEND
expr_stmt|;
name|aflag
operator|=
literal|1
expr_stmt|;
name|whichsys
operator|=
name|NEWSSYS
expr_stmt|;
comment|/* it's sequencer */
break|break;
case|case
literal|'c'
case|:
comment|/* file of systems */
name|cflag
operator|=
literal|1
expr_stmt|;
name|whichsys
operator|=
name|NEWSSYS
expr_stmt|;
comment|/* use the global seq */
if|if
condition|(
operator|++
name|i
operator|==
name|argc
condition|)
block|{
name|printf
argument_list|(
literal|"%s: -c option must be followed by filename\n"
argument_list|,
name|Invokedas
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|BAD
argument_list|)
expr_stmt|;
block|}
name|loadgate
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|)
expr_stmt|;
comment|/* load the table */
break|break;
case|case
literal|'v'
case|:
comment|/* messages per group */
name|verbosity
operator|++
expr_stmt|;
break|break;
case|case
literal|'f'
case|:
comment|/* process a file */
if|if
condition|(
operator|++
name|i
operator|==
name|argc
condition|)
comment|/* no filename */
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"-f must be followed by a filename\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|BAD
argument_list|)
expr_stmt|;
block|}
name|readrc
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|)
expr_stmt|;
comment|/* read the file */
break|break;
case|case
literal|'b'
case|:
comment|/* include old headers */
name|backward
operator|++
expr_stmt|;
break|break;
case|case
literal|'t'
case|:
comment|/* explicit time */
case|case
literal|'o'
case|:
comment|/* compatibility */
if|if
condition|(
operator|++
name|i
operator|==
name|argc
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"-t option requires following date\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|BAD
argument_list|)
expr_stmt|;
block|}
switch|switch
condition|(
name|parsetime
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|,
operator|&
name|ztime
argument_list|)
condition|)
block|{
case|case
literal|0
case|:
comment|/* ok */
name|usetime
operator|=
name|BASESEQ
expr_stmt|;
comment|/* use this time */
name|Basetime
operator|=
name|ztime
expr_stmt|;
comment|/* store it */
name|sprdate
argument_list|(
operator|&
name|ztime
argument_list|,
name|fmtdate
argument_list|)
expr_stmt|;
comment|/* format */
name|printf
argument_list|(
literal|"%s: Sending articles since %s\n"
argument_list|,
name|Invokedas
argument_list|,
name|fmtdate
argument_list|)
expr_stmt|;
break|break;
case|case
operator|-
literal|1
case|:
comment|/* no good */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: unable to parse time `%s'\n"
argument_list|,
name|Invokedas
argument_list|,
name|argv
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|BAD
argument_list|)
expr_stmt|;
case|case
operator|-
literal|2
case|:
comment|/* in future */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: parsed date (%s) is in the future\n"
argument_list|,
name|Invokedas
argument_list|,
name|argv
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|BAD
argument_list|)
expr_stmt|;
block|}
break|break;
default|default:
name|printf
argument_list|(
literal|"Bad switch: %c\n"
argument_list|,
name|argv
index|[
name|i
index|]
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|BAD
argument_list|)
expr_stmt|;
block|}
else|else
name|expand
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|)
expr_stmt|;
comment|/* put it in the list */
block|}
comment|/*  *	now, run down the list and send each notesfile.  *	check to make sure some things are used consistently first.  */
if|if
condition|(
name|aflag
operator|+
name|cflag
operator|+
name|sflag
operator|>
literal|1
condition|)
block|{
comment|/* -a and -s */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: -a, -c and -s mutually exclusive\n"
argument_list|,
name|Invokedas
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|BAD
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|gatesyscount
operator|==
literal|0
operator|&&
operator|!
name|cflag
condition|)
comment|/* default to local */
block|{
comment|/*  	 * check against cflag allows empty -c files to "work" 	 */
name|gatesysnames
index|[
literal|0
index|]
operator|=
name|whichsys
expr_stmt|;
name|gatesyscount
operator|=
literal|1
expr_stmt|;
comment|/* just us */
block|}
if|if
condition|(
literal|1
condition|)
comment|/* was verbosity */
block|{
comment|/* now always... */
name|printf
argument_list|(
literal|"%s: Sending news articles through command: %s\n"
argument_list|,
name|Invokedas
argument_list|,
name|rnewscmd
argument_list|)
expr_stmt|;
if|if
condition|(
name|sendclass
operator|&
name|NEWS_ALLSEND
condition|)
block|{
name|printf
argument_list|(
literal|"Sending to News for any system\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|int
name|col
decl_stmt|;
comment|/* count columns */
comment|/*  	     * WE WANT TO SORT THE LIST AT THIS POINT 	     * so that the cansend() routine in newsout.c can do a binary 	     * search to make things faster. 	     */
name|printf
argument_list|(
literal|"Gateway for the following %d system(s):\n"
argument_list|,
name|gatesyscount
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|col
operator|=
literal|0
init|;
name|i
operator|<
name|gatesyscount
condition|;
name|i
operator|++
control|)
block|{
name|printf
argument_list|(
literal|" %16s"
argument_list|,
name|gatesysnames
index|[
name|i
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
operator|++
name|col
operator|%
literal|4
operator|==
literal|0
condition|)
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
comment|/* multi-column */
block|}
block|}
name|printf
argument_list|(
literal|"\n================\n"
argument_list|)
expr_stmt|;
block|}
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
comment|/* make sure in order */
name|sprintf
argument_list|(
name|Seqname
argument_list|,
literal|"%s:%s"
argument_list|,
name|NEWSSEQ
argument_list|,
name|whichsys
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|nfptr
operator|=
name|nextgroup
argument_list|()
operator|)
operator|!=
operator|(
expr|struct
name|nflist_f
operator|*
operator|)
name|NULL
condition|)
name|newsone
argument_list|(
name|nfptr
operator|->
name|nf_name
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|GOOD
argument_list|)
expr_stmt|;
comment|/* all done */
block|}
end_function

begin_comment
comment|/*  *	loadgate(filename)  *  *	fill in the system table.  */
end_comment

begin_macro
name|loadgate
argument_list|(
argument|filename
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|filename
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|FILE
modifier|*
name|fptr
decl_stmt|;
name|char
name|onesystem
index|[
literal|256
index|]
decl_stmt|;
comment|/* system name */
if|if
condition|(
operator|(
name|fptr
operator|=
name|fopen
argument_list|(
name|filename
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
operator|(
name|FILE
operator|*
operator|)
name|NULL
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* bah humbug */
while|while
condition|(
name|fscanf
argument_list|(
name|fptr
argument_list|,
literal|"%s"
argument_list|,
name|onesystem
argument_list|)
operator|==
literal|1
condition|)
block|{
name|gatesysnames
index|[
name|gatesyscount
operator|++
index|]
operator|=
name|strsave
argument_list|(
name|onesystem
argument_list|)
expr_stmt|;
block|}
name|fclose
argument_list|(
name|onesystem
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

