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
literal|"$Header: index.c,v 1.7.0.2 85/09/09 18:32:22 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_comment
comment|/*  * INPUT KEY PROCESSING FOR INDEX PHASE   *  *	Process all keystrokes while the index page is on the screen.  *	invokes director options also (if user qualified)  *	Returns:>=0 read note with that number ( 0 is policy)  *		 -1	reprint the index page  *		 -2	leave notefiles, update sequencer time  *		 -3	leave notefile, dont update sequencer  *		 -4	Universal leave notefiles  *			(-2 and -3 leave single notefile, -4 leaves  *			entire package, aborting rest of notefiles.  *  *	Original Coding:	Rob Kolstad	Winter 1980  *	modifications:		Ray Essick	December 1981  */
end_comment

begin_macro
name|indx
argument_list|(
argument|io
argument_list|,
argument|firstdis
argument_list|,
argument|lastdis
argument_list|,
argument|respnum
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
name|int
modifier|*
name|firstdis
decl_stmt|,
modifier|*
name|lastdis
decl_stmt|,
modifier|*
name|respnum
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|io_f
name|io2
decl_stmt|;
comment|/* for nested notefiles */
name|char
name|nfname
index|[
name|WDLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* for nested nfs */
name|int
name|num
decl_stmt|;
comment|/* note number */
name|int
name|i
decl_stmt|;
name|int
name|c
decl_stmt|;
name|int
name|znote
decl_stmt|,
name|zresp
decl_stmt|;
comment|/* for asearch */
operator|*
name|respnum
operator|=
literal|0
expr_stmt|;
comment|/* init response */
while|while
condition|(
literal|1
condition|)
block|{
name|at
argument_list|(
operator|-
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|PROMPT
name|printf
argument_list|(
name|PROMPT
argument_list|)
expr_stmt|;
comment|/* issue a prompt */
endif|#
directive|endif
name|c
operator|=
name|gchar
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"\10 \10"
argument_list|)
expr_stmt|;
comment|/* erase the key */
switch|switch
condition|(
name|c
condition|)
comment|/* what to do? */
block|{
case|case
literal|'?'
case|:
case|case
literal|'h'
case|:
name|help
argument_list|(
name|INDXHLP
argument_list|)
expr_stmt|;
comment|/* put the help on screen */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* back and display the index */
case|case
literal|'r'
case|:
comment|/* replot the index page */
case|case
literal|'\f'
case|:
comment|/* everyone else uses ^L, might as well */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
case|case
literal|'W'
case|:
comment|/* this too shall write a note */
case|case
literal|'w'
case|:
comment|/* write a note */
return|return
name|addnote
argument_list|(
name|io
argument_list|,
name|NULL
argument_list|,
literal|"Edit Note text:"
argument_list|,
literal|"Note Title: "
argument_list|,
name|NULL
argument_list|,
name|EDIT
argument_list|)
return|;
comment|/* do it */
case|case
literal|'B'
case|:
comment|/* bitch, bitch, bitch */
if|if
condition|(
name|init
argument_list|(
operator|&
name|io2
argument_list|,
name|GRIPES
argument_list|)
operator|<
literal|0
condition|)
comment|/* no gripe file */
block|{
name|at
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Gripe file not available"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|addnote
argument_list|(
operator|&
name|io2
argument_list|,
name|NULL
argument_list|,
literal|"Edit Gripe text:"
argument_list|,
literal|"Gripe Header: "
argument_list|,
name|NULL
argument_list|,
name|EDIT
argument_list|)
expr_stmt|;
comment|/* let him put the note in */
name|finish
argument_list|(
operator|&
name|io2
argument_list|)
expr_stmt|;
comment|/* close up the gripe file */
block|}
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* replot */
case|case
literal|'-'
case|:
comment|/* back up a little */
case|case
literal|'\b'
case|:
comment|/* add backspace also */
operator|*
name|firstdis
operator|-=
name|Nindex
operator|-
literal|1
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
case|case
literal|'='
case|:
comment|/* back up a lot */
operator|*
name|firstdis
operator|=
literal|1
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
case|case
literal|'+'
case|:
case|case
literal|'\r'
case|:
case|case
literal|'\n'
case|:
case|case
literal|' '
case|:
if|if
condition|(
operator|*
name|lastdis
operator|<
name|io
operator|->
name|descr
operator|.
name|d_nnote
condition|)
block|{
operator|*
name|firstdis
operator|=
operator|*
name|lastdis
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
break|break;
comment|/* keep doing what we were */
case|case
literal|'*'
case|:
comment|/* skip to last page */
if|if
condition|(
operator|*
name|lastdis
operator|<
name|io
operator|->
name|descr
operator|.
name|d_nnote
condition|)
block|{
operator|*
name|firstdis
operator|=
name|io
operator|->
name|descr
operator|.
name|d_nnote
operator|-
name|Nindex
operator|+
literal|1
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
break|break;
comment|/* already at end */
case|case
literal|'q'
case|:
ifdef|#
directive|ifdef
name|K_KEY
case|case
literal|'k'
case|:
comment|/* can use right hand */
endif|#
directive|endif
endif|K_KEY
return|return
name|QUITSEQ
return|;
case|case
literal|'\04'
case|:
comment|/* ^D */
return|return
name|QUITFAST
return|;
comment|/* total exit */
case|case
literal|'z'
case|:
comment|/* ^D w/sequencer update */
return|return
name|QUITUPD
return|;
comment|/* total exit w/update */
case|case
literal|'Q'
case|:
comment|/* exit without update of sequencer */
ifdef|#
directive|ifdef
name|K_KEY
case|case
literal|'K'
case|:
comment|/* so can use just right hand */
endif|#
directive|endif
endif|K_KEY
return|return
name|QUITNOSEQ
return|;
case|case
literal|'N'
case|:
comment|/* go to an archive */
name|sprintf
argument_list|(
name|nfname
argument_list|,
literal|"%s/%s"
argument_list|,
name|ARCHDIR
argument_list|,
name|io
operator|->
name|nf
argument_list|)
expr_stmt|;
comment|/* build dest */
goto|goto
name|donest
goto|;
comment|/* share common code */
case|case
literal|'n'
case|:
comment|/* nest notesfiles - a stack */
name|at
argument_list|(
operator|-
literal|1
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"New notesfile: "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"               \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"
argument_list|)
expr_stmt|;
if|if
condition|(
name|gline
argument_list|(
name|nfname
argument_list|,
name|WDLEN
argument_list|)
operator|==
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* forget it, replot */
name|donest
label|:
comment|/* used by N */
name|closenf
argument_list|(
name|io
argument_list|)
expr_stmt|;
comment|/* save fids */
if|if
condition|(
operator|(
name|i
operator|=
name|control
argument_list|(
name|nfname
argument_list|,
name|NOSEQ
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
comment|/* do the other */
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* some error there */
if|if
condition|(
name|opennf
argument_list|(
name|io
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
block|{
name|at
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Couldn't reopen notesfile %s"
argument_list|,
name|io
operator|->
name|fullname
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|sleep
argument_list|(
literal|2
argument_list|)
expr_stmt|;
return|return
name|QUITNOSEQ
return|;
comment|/* don't update */
block|}
if|if
condition|(
name|i
operator|==
name|QUITFAST
condition|)
comment|/* he in a hurry? */
return|return
name|QUITFAST
return|;
comment|/* oblige him */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* redisplay index */
case|case
literal|'p'
case|:
comment|/* to read note 0 */
if|if
condition|(
name|io
operator|->
name|descr
operator|.
name|d_plcy
condition|)
return|return
literal|0
return|;
else|else
block|{
name|at
argument_list|(
literal|0
argument_list|,
name|PROMPTMSGX
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"There is no policy note"
argument_list|)
expr_stmt|;
continue|continue;
comment|/* grab another key */
block|}
case|case
literal|'d'
case|:
comment|/* to director options */
if|if
condition|(
name|allow
argument_list|(
name|io
argument_list|,
name|DRCTOK
argument_list|)
condition|)
return|return
name|direct
argument_list|(
name|io
argument_list|)
return|;
comment|/* perform those babies */
else|else
block|{
name|at
argument_list|(
literal|0
argument_list|,
name|PROMPTMSGX
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Anonymous: %s   Networked: %s"
argument_list|,
operator|(
name|io
operator|->
name|descr
operator|.
name|d_stat
operator|&
name|ANONOK
operator|)
condition|?
literal|"YES"
else|:
literal|"NO"
argument_list|,
operator|(
name|io
operator|->
name|descr
operator|.
name|d_stat
operator|&
name|NETWRKD
operator|)
condition|?
literal|"YES"
else|:
literal|"NO"
argument_list|)
expr_stmt|;
continue|continue;
block|}
case|case
literal|'x'
case|:
case|case
literal|'X'
case|:
name|i
operator|=
name|tsearch
argument_list|(
name|io
argument_list|,
operator|*
name|lastdis
argument_list|,
name|c
operator|==
literal|'x'
argument_list|)
expr_stmt|;
comment|/* assume lies before here */
if|if
condition|(
name|i
operator|>
literal|0
condition|)
return|return
name|i
return|;
comment|/* return that one */
continue|continue;
comment|/* otherwise get another key */
case|case
literal|'a'
case|:
case|case
literal|'A'
case|:
comment|/* author search from current spot */
name|znote
operator|=
operator|*
name|lastdis
expr_stmt|;
name|zresp
operator|=
literal|0
expr_stmt|;
comment|/* start at the correct place */
name|i
operator|=
name|asearch
argument_list|(
name|io
argument_list|,
operator|&
name|znote
argument_list|,
operator|&
name|zresp
argument_list|,
operator|(
name|c
operator|==
literal|'a'
operator|)
argument_list|)
expr_stmt|;
comment|/* look */
if|if
condition|(
name|i
operator|>
literal|0
condition|)
block|{
operator|*
name|respnum
operator|=
name|zresp
expr_stmt|;
comment|/* return correct value */
return|return
name|znote
return|;
comment|/* and such */
block|}
continue|continue;
comment|/* get another command */
case|case
literal|'1'
case|:
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
name|at
argument_list|(
operator|-
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Read note> "
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|num
operator|=
name|getnum
argument_list|(
name|c
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|at
argument_list|(
operator|-
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"                      "
argument_list|)
expr_stmt|;
continue|continue;
block|}
return|return
name|num
return|;
case|case
literal|'j'
case|:
case|case
literal|'J'
case|:
comment|/* goto first unread article */
return|return
operator|(
name|nxtnote
argument_list|(
name|io
argument_list|,
literal|0
argument_list|,
operator|&
name|io
operator|->
name|stime
argument_list|)
operator|)
return|;
case|case
literal|'l'
case|:
comment|/* leave if no new */
case|case
literal|'L'
case|:
if|if
condition|(
operator|(
name|i
operator|=
name|nxtnote
argument_list|(
name|io
argument_list|,
literal|0
argument_list|,
operator|&
name|io
operator|->
name|stime
argument_list|)
operator|)
operator|<
literal|0
condition|)
return|return
name|QUITSEQ
return|;
comment|/* nope, leave */
else|else
return|return
operator|(
name|i
operator|)
return|;
comment|/* go there */
case|case
literal|'o'
case|:
comment|/* modify sequencer time */
name|gdate
argument_list|(
operator|&
name|io
operator|->
name|stime
argument_list|)
expr_stmt|;
comment|/* let him hack on the time */
continue|continue;
comment|/* and go back */
case|case
literal|'O'
case|:
comment|/* set it for today's notes */
name|gettime
argument_list|(
operator|&
name|io
operator|->
name|stime
argument_list|)
expr_stmt|;
comment|/* grab current date */
name|io
operator|->
name|stime
operator|.
name|w_hours
operator|=
literal|0
expr_stmt|;
comment|/* beginning of day */
name|io
operator|->
name|stime
operator|.
name|w_mins
operator|=
literal|0
expr_stmt|;
name|io
operator|->
name|stime
operator|.
name|w_gmttime
operator|=
literal|0
expr_stmt|;
comment|/* use formatted */
name|at
argument_list|(
literal|0
argument_list|,
name|PROMPTMSGX
argument_list|)
expr_stmt|;
comment|/* tell him what we did */
name|printf
argument_list|(
literal|"Set to read notes since: "
argument_list|)
expr_stmt|;
name|prdate
argument_list|(
operator|&
name|io
operator|->
name|stime
argument_list|)
expr_stmt|;
continue|continue;
comment|/* and get the next command */
case|case
literal|'!'
case|:
name|gshell
argument_list|()
expr_stmt|;
comment|/* give him a shell in right directory */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
default|default:
name|at
argument_list|(
literal|0
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\07     type ? for help, q to quit     "
argument_list|)
expr_stmt|;
continue|continue;
block|}
comment|/* end main index page code */
block|}
block|}
end_block

end_unit

