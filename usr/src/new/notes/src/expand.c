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

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|RCSIDENT
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsident
init|=
literal|"$Header: expand.c,v 1.7 85/01/18 15:40:08 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	Routines to expand notesgroups specifications  *  *	Rick L Spickelmier, UC Berkeley  *	Lou Salkind, NYU  */
end_comment

begin_define
define|#
directive|define
name|MAXGROUP
value|400
end_define

begin_comment
comment|/* lots of them */
end_comment

begin_decl_stmt
specifier|static
name|int
name|seqtyp
init|=
name|NOSEQ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sequencer mode */
end_comment

begin_decl_stmt
specifier|static
name|int
name|last_group
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* active in list */
end_comment

begin_decl_stmt
specifier|static
name|int
name|this_group
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next one to show */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|nflist_f
name|groups
index|[
name|MAXGROUP
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* and the groups */
end_comment

begin_comment
comment|/*  * set the sequencer type (external interface)  */
end_comment

begin_macro
name|setseq
argument_list|(
argument|i
argument_list|)
end_macro

begin_block
block|{
name|seqtyp
operator|=
name|i
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * add a notesfile to the active list  */
end_comment

begin_macro
name|addgrp
argument_list|(
argument|string
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|string
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|i
decl_stmt|;
comment|/* see if it already exists */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|last_group
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|groups
index|[
name|i
index|]
operator|.
name|nf_name
argument_list|,
name|string
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* already in table */
name|groups
index|[
name|i
index|]
operator|.
name|nf_active
operator|=
name|TRUE
expr_stmt|;
comment|/* deleted earlier? */
name|groups
index|[
name|i
index|]
operator|.
name|nf_seqmode
operator|=
name|seqtyp
expr_stmt|;
return|return;
block|}
block|}
if|if
condition|(
name|last_group
operator|>=
name|MAXGROUP
condition|)
block|{
name|printf
argument_list|(
literal|"addgrp: array overflow, ignoring %s\n"
argument_list|,
name|string
argument_list|)
expr_stmt|;
return|return;
block|}
name|groups
index|[
name|last_group
index|]
operator|.
name|nf_active
operator|=
name|TRUE
expr_stmt|;
name|groups
index|[
name|last_group
index|]
operator|.
name|nf_seqmode
operator|=
name|seqtyp
expr_stmt|;
name|groups
index|[
name|last_group
operator|++
index|]
operator|.
name|nf_name
operator|=
name|strsave
argument_list|(
name|string
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * delete the notesfile from the active list  */
end_comment

begin_macro
name|delgroup
argument_list|(
argument|string
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|string
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
comment|/* might as well be fast */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|last_group
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|groups
index|[
name|i
index|]
operator|.
name|nf_name
argument_list|,
name|string
argument_list|)
operator|==
literal|0
condition|)
block|{
name|groups
index|[
name|i
index|]
operator|.
name|nf_active
operator|=
name|FALSE
expr_stmt|;
return|return;
block|}
block|}
block|}
end_block

begin_comment
comment|/*  * given a command line argument, expand it into  * the appropriate sequence command or notesfile  * specification  */
end_comment

begin_macro
name|expand
argument_list|(
argument|argp
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|argp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
modifier|*
name|endp
decl_stmt|;
while|while
condition|(
literal|1
condition|)
comment|/* do entire string */
block|{
while|while
condition|(
name|isspace
argument_list|(
operator|*
name|argp
argument_list|)
condition|)
comment|/* skip trash chars */
name|argp
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|argp
operator|==
literal|'\0'
condition|)
comment|/* fell off end */
return|return;
name|endp
operator|=
name|argp
expr_stmt|;
while|while
condition|(
operator|*
name|endp
condition|)
block|{
if|if
condition|(
name|isspace
argument_list|(
operator|*
name|endp
argument_list|)
operator|||
operator|*
name|endp
operator|==
literal|','
condition|)
block|{
operator|*
name|endp
operator|++
operator|=
literal|'\0'
expr_stmt|;
break|break;
block|}
name|endp
operator|++
expr_stmt|;
comment|/* now points at next (or NULL) */
block|}
switch|switch
condition|(
name|argp
index|[
literal|0
index|]
condition|)
comment|/* on first character */
block|{
comment|/*  *	Parse options that make sense at this point.  */
case|case
literal|'-'
case|:
comment|/* options */
block|{
switch|switch
condition|(
name|argp
index|[
literal|1
index|]
condition|)
block|{
case|case
literal|'s'
case|:
comment|/* -S-equencer */
name|seqtyp
operator|=
name|NORMSEQ
expr_stmt|;
break|break;
case|case
literal|'x'
case|:
comment|/* e-X-tended sequencer */
name|seqtyp
operator|=
name|EXTSEQ
expr_stmt|;
break|break;
case|case
literal|'i'
case|:
comment|/* indexing sequencer */
name|seqtyp
operator|=
name|INDXSEQ
expr_stmt|;
break|break;
case|case
literal|'n'
case|:
comment|/* -N-o sequencer */
name|seqtyp
operator|=
name|NOSEQ
expr_stmt|;
break|break;
default|default:
break|break;
comment|/* ignore it */
block|}
break|break;
block|}
comment|/*  *	specified a file  the hard way (via colon).  This usually  *	happens in the NFSEQ definition  */
case|case
literal|':'
case|:
comment|/* include a file */
name|readrc
argument_list|(
operator|&
name|argp
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|/* do it */
break|break;
comment|/*  *	Eliminate notesfles.  If the arg is "! pattern", we remove the  *	notesfiles that "pattern" matches from the list of notesfiles  *	to read.  *  */
case|case
literal|'!'
case|:
comment|/* eliminate notesfiles */
block|{
if|if
condition|(
name|patcheck
argument_list|(
operator|&
name|argp
index|[
literal|1
index|]
argument_list|)
condition|)
comment|/* wildcard */
name|dopat
argument_list|(
operator|&
name|argp
index|[
literal|1
index|]
argument_list|,
name|delgroup
argument_list|)
expr_stmt|;
else|else
name|delgroup
argument_list|(
operator|&
name|argp
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
break|break;
block|}
comment|/*  *	Anything else is just a "pattern" and specifies some notesfiles  *	to be added to the list.  */
default|default:
comment|/* add notesfiles */
block|{
if|if
condition|(
name|patcheck
argument_list|(
name|argp
argument_list|)
condition|)
comment|/* wildcard check */
name|dopat
argument_list|(
name|argp
argument_list|,
name|addgrp
argument_list|)
expr_stmt|;
else|else
name|addgrp
argument_list|(
name|argp
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
name|argp
operator|=
name|endp
expr_stmt|;
block|}
comment|/* NOT REACHED */
block|}
end_block

begin_comment
comment|/*  * read a file which contains the command line arguments  */
end_comment

begin_macro
name|readrc
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|FILE
modifier|*
name|f
decl_stmt|;
name|char
name|buf
index|[
name|BUFSIZ
index|]
decl_stmt|;
if|if
condition|(
operator|(
name|f
operator|=
name|fopen
argument_list|(
name|s
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: unable to read file "
argument_list|,
name|Invokedas
argument_list|)
expr_stmt|;
name|perror
argument_list|(
name|s
argument_list|)
expr_stmt|;
comment|/* and the error */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
while|while
condition|(
name|fgets
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
name|buf
operator|-
literal|1
argument_list|,
name|f
argument_list|)
condition|)
name|expand
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|f
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  *	return the next active notesfile in the list  */
end_comment

begin_function
name|struct
name|nflist_f
modifier|*
name|nextgroup
parameter_list|()
block|{
while|while
condition|(
name|this_group
operator|<
name|last_group
condition|)
block|{
if|if
condition|(
name|groups
index|[
name|this_group
index|]
operator|.
name|nf_active
condition|)
return|return
operator|(
operator|&
name|groups
index|[
name|this_group
operator|++
index|]
operator|)
return|;
comment|/* give it */
else|else
name|this_group
operator|++
expr_stmt|;
comment|/* try another */
block|}
return|return
operator|(
operator|(
expr|struct
name|nflist_f
operator|*
operator|)
name|NULL
operator|)
return|;
comment|/* no more */
block|}
end_function

end_unit

