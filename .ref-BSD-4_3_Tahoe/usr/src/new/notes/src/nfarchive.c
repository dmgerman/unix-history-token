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
literal|"$Header: nfarchive.c,v 1.7 85/01/18 15:25:22 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_comment
comment|/*  *	nfarchive - will archive the specified notesfiles. All notes that  *	have not been modofied in the last n days (default 14, settable  *	by option on command line) will be archived and placed in  *	the archive directory.  *  *	Ray Essick			March 1982  */
end_comment

begin_decl_stmt
name|int
name|deleteonly
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dirmsgflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* key on dir msg */
end_comment

begin_decl_stmt
name|int
name|daysold
init|=
name|ARCHTIME
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* eligibility age */
end_comment

begin_decl_stmt
name|int
name|worksetsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* minimum to keep */
end_comment

begin_macro
name|archone
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
return|return
name|archiver
argument_list|(
name|nfname
argument_list|,
name|daysold
argument_list|,
name|worksetsize
argument_list|,
name|deleteonly
argument_list|,
name|dirmsgflag
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
name|struct
name|nflist_f
modifier|*
name|nfptr
decl_stmt|;
name|int
name|i
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
literal|"Usage: %s [-d] [-m+ or -m-] [-#] [-w#] [-f file] topic1 [topic2 ...]\n"
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
literal|"Sorry, only notes 'owner' can archive notes\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|BAD
argument_list|)
expr_stmt|;
block|}
name|deleteonly
operator|=
literal|0
expr_stmt|;
comment|/* default to archiving */
name|dirmsgflag
operator|=
name|DIRNOCARE
expr_stmt|;
comment|/* don't consider dirmessage */
name|daysold
operator|=
name|ARCHTIME
expr_stmt|;
comment|/* default threshold */
name|worksetsize
operator|=
name|WORKSETSIZE
expr_stmt|;
comment|/* default to leave */
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
literal|'d'
case|:
comment|/* delete only, no archiving */
name|deleteonly
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'m'
case|:
comment|/* director message status */
if|if
condition|(
name|argv
index|[
name|i
index|]
index|[
literal|2
index|]
operator|==
literal|'-'
condition|)
name|dirmsgflag
operator|=
name|DIROFF
expr_stmt|;
comment|/* delete when off */
else|else
name|dirmsgflag
operator|=
name|DIRON
expr_stmt|;
comment|/* only when on */
comment|/* also if just "-m" */
break|break;
case|case
literal|'w'
case|:
comment|/* change workset size */
if|if
condition|(
name|argv
index|[
name|i
index|]
index|[
literal|2
index|]
operator|==
literal|'\0'
condition|)
name|worksetsize
operator|=
name|WORKSETSIZE
expr_stmt|;
comment|/* default */
else|else
name|worksetsize
operator|=
name|atoi
argument_list|(
operator|&
name|argv
index|[
name|i
index|]
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
comment|/* specified */
break|break;
case|case
literal|'0'
case|:
comment|/* allow 0 days */
case|case
literal|'1'
case|:
comment|/* change days old parameter */
case|case
literal|'2'
case|:
case|case
literal|'3'
case|:
case|case
literal|'4'
case|:
case|case
literal|'5'
case|:
case|case
literal|'6'
case|:
case|case
literal|'7'
case|:
case|case
literal|'8'
case|:
case|case
literal|'9'
case|:
name|daysold
operator|=
name|atoi
argument_list|(
operator|&
name|argv
index|[
name|i
index|]
index|[
literal|1
index|]
argument_list|)
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
literal|"-f must be followed by filename\n"
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
comment|/* load it */
block|}
comment|/*  *	now process things  */
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
name|archone
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
block|}
end_function

end_unit

