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
literal|"$Header: perms.c,v 1.7.0.1 85/04/09 11:42:48 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_comment
comment|/*   *	getperms - opens and reads the permission file to  *	determine the access rights for this user  *  *	Uses a struture similar to PLATO's. A list is scanned  *	until a match is found. The access rights at that point  *	are then awarded to the user. In the event that no  *	match is found, no access rights are granted.  *  *	Original Coding:	Ray Essick	December 1981  */
end_comment

begin_include
include|#
directive|include
file|<grp.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* for groups */
end_comment

begin_comment
comment|/*  *	Make sure that the name NGROUPS is defined.  *	pre-4.1a probably doesn't define either.  *	4.1a uses the NGRPS constant  *	4.2 uses the NGROUPS constant  *	We make sure that NGROUPS is defined and use that in the  *	generic portion of the routine. The emulation for V7, 4.1, 4.1a  *	and such use the NGRPS or whatever is appropriate.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NGRPS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NGROUPS
argument_list|)
end_if

begin_define
define|#
directive|define
name|NGROUPS
value|NGRPS
end_define

begin_comment
comment|/* name change! */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NGROUPS
end_ifndef

begin_define
define|#
directive|define
name|NGROUPS
value|1
end_define

begin_comment
comment|/* could be better */
end_comment

begin_endif
endif|#
directive|endif
endif|NGROUPS
end_endif

begin_decl_stmt
specifier|static
name|char
modifier|*
name|gnameptr
index|[
name|NGROUPS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* point to names */
end_comment

begin_decl_stmt
specifier|static
name|int
name|ngroups
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if have gids */
end_comment

begin_macro
name|getperms
argument_list|(
argument|io
argument_list|,
argument|sysflag
argument_list|,
argument|name
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
name|sysflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true for remote system */
end_comment

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
name|FILE
modifier|*
name|acs
decl_stmt|,
modifier|*
name|fopen
argument_list|()
decl_stmt|;
name|struct
name|group
modifier|*
name|gr
decl_stmt|,
modifier|*
name|getgrgid
argument_list|()
decl_stmt|;
name|char
name|fn
index|[
name|WDLEN
index|]
decl_stmt|;
name|struct
name|perm_f
name|entry
decl_stmt|;
name|int
name|hisperms
decl_stmt|;
comment|/* built up perms */
name|int
name|given
decl_stmt|;
comment|/* if assigned perms */
if|if
condition|(
name|sysflag
operator|==
literal|0
operator|&&
name|globuid
operator|==
name|Notesuid
condition|)
comment|/* "notes" omnipotent */
block|{
name|io
operator|->
name|access
operator|=
name|READOK
operator|+
name|RESPOK
operator|+
name|WRITOK
operator|+
name|DRCTOK
expr_stmt|;
comment|/* all */
comment|/*  *	should I just set it to -1 or something that turns on  *	all the bits?  or leave it with the defined bits only?  */
return|return;
block|}
if|if
condition|(
name|sysflag
operator|==
literal|0
operator|&&
name|ngroups
operator|==
literal|0
condition|)
block|{
specifier|register
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
comment|/* temp loop stuff */
name|int
name|gidset
index|[
name|NGROUPS
index|]
decl_stmt|;
comment|/* hold gid list */
name|ngroups
operator|=
name|NGROUPS
expr_stmt|;
comment|/* max allowed */
comment|/*  	 * NOTE that the getgroups system call doesn't behave as  	 * documented in the 4.2 manual.  The manual says to call it 	 * ret=getgroups(&ngroups,&gidset) where ngroups is value-result. 	 * and ret is 0 on success.  Actual implementation works as below. 	 */
if|if
condition|(
operator|(
name|ngroups
operator|=
name|getgroups
argument_list|(
name|ngroups
argument_list|,
operator|&
name|gidset
argument_list|)
operator|)
operator|>=
literal|0
condition|)
comment|/* worked */
block|{
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|j
operator|=
literal|0
init|;
name|i
operator|<
name|ngroups
condition|;
name|i
operator|++
control|)
comment|/* get names */
block|{
if|if
condition|(
operator|(
name|gr
operator|=
name|getgrgid
argument_list|(
name|gidset
index|[
name|i
index|]
argument_list|)
operator|)
operator|==
name|NULL
condition|)
continue|continue;
comment|/* bogus, skip it */
name|gnameptr
index|[
name|j
operator|++
index|]
operator|=
name|strsave
argument_list|(
name|gr
operator|->
name|gr_name
argument_list|)
expr_stmt|;
comment|/* save it */
block|}
name|ngroups
operator|=
name|j
expr_stmt|;
comment|/* save count */
block|}
block|}
name|io
operator|->
name|access
operator|=
literal|0
expr_stmt|;
comment|/* default null */
name|hisperms
operator|=
literal|0
expr_stmt|;
comment|/* set up mask */
name|given
operator|=
literal|0
expr_stmt|;
name|sprintf
argument_list|(
name|fn
argument_list|,
literal|"%s/%s/%s"
argument_list|,
name|io
operator|->
name|basedir
argument_list|,
name|io
operator|->
name|nf
argument_list|,
name|ACCESS
argument_list|)
expr_stmt|;
name|x
argument_list|(
operator|(
name|acs
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
literal|"getperms: no list"
argument_list|)
expr_stmt|;
while|while
condition|(
name|fread
argument_list|(
operator|&
name|entry
argument_list|,
sizeof|sizeof
name|entry
argument_list|,
literal|1
argument_list|,
name|acs
argument_list|)
operator|==
literal|1
condition|)
block|{
if|if
condition|(
operator|(
name|sysflag
operator|!=
literal|0
operator|)
operator|&&
operator|(
name|entry
operator|.
name|ptype
operator|!=
name|PERMSYSTEM
operator|)
condition|)
continue|continue;
comment|/* looking for systems */
if|if
condition|(
operator|(
name|sysflag
operator|==
literal|0
operator|)
operator|&&
operator|(
name|entry
operator|.
name|ptype
operator|==
name|PERMSYSTEM
operator|)
condition|)
continue|continue;
comment|/* users != systems */
if|if
condition|(
name|strcmp
argument_list|(
name|entry
operator|.
name|name
argument_list|,
literal|"Other"
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
operator|!
name|given
condition|)
comment|/* he hasn't matched */
name|hisperms
operator|=
name|entry
operator|.
name|perms
expr_stmt|;
comment|/* give him these */
goto|goto
name|gotit
goto|;
comment|/* and exit ... */
block|}
switch|switch
condition|(
name|entry
operator|.
name|ptype
condition|)
block|{
case|case
name|PERMUSER
case|:
if|if
condition|(
name|strcmp
argument_list|(
name|name
argument_list|,
name|entry
operator|.
name|name
argument_list|)
operator|==
literal|0
condition|)
block|{
name|hisperms
operator|=
name|entry
operator|.
name|perms
expr_stmt|;
goto|goto
name|gotit
goto|;
block|}
break|break;
case|case
name|PERMGROUP
case|:
comment|/* a group entry */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|ngroups
condition|;
name|i
operator|++
control|)
comment|/* check all */
if|if
condition|(
name|strcmp
argument_list|(
name|entry
operator|.
name|name
argument_list|,
name|gnameptr
index|[
name|i
index|]
argument_list|)
operator|==
literal|0
condition|)
block|{
name|hisperms
operator||=
name|entry
operator|.
name|perms
expr_stmt|;
comment|/* OR them in */
name|given
operator|++
expr_stmt|;
comment|/* mark as such */
break|break;
block|}
break|break;
case|case
name|PERMSYSTEM
case|:
if|if
condition|(
name|strcmp
argument_list|(
name|name
argument_list|,
name|entry
operator|.
name|name
argument_list|)
operator|==
literal|0
condition|)
block|{
name|hisperms
operator|=
name|entry
operator|.
name|perms
expr_stmt|;
name|given
operator|++
expr_stmt|;
goto|goto
name|gotit
goto|;
block|}
break|break;
default|default:
comment|/* bad access list */
name|x
argument_list|(
literal|1
argument_list|,
literal|"getperms: bad list"
argument_list|)
expr_stmt|;
block|}
block|}
name|gotit
label|:
name|fclose
argument_list|(
name|acs
argument_list|)
expr_stmt|;
comment|/* close the access file */
name|io
operator|->
name|access
operator|=
name|hisperms
expr_stmt|;
comment|/* what we built */
return|return;
block|}
end_block

begin_comment
comment|/*  *	Some compatibility routines to let us use the fancy 4.2 Bsd  *	getgroups() system call while running 4.1, 4.1a or V7 kernels.  *	I've undoubtedly missed some kernels.  */
end_comment

begin_comment
comment|/*  *	getgroups  *  *	Returns an integer and a set of groups.  *	Emulates the 4.2 getgroups command under 4.1a Bsd  *  *	Stolen mostly from the 4.1a command "groups".  *  *	Ray Essick, January 1984  *  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD41A
argument_list|)
end_if

begin_macro
name|getgroups
argument_list|(
argument|ngroups
argument_list|,
argument|gidset
argument_list|)
end_macro

begin_decl_stmt
name|int
name|ngroups
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|gidset
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
specifier|register
name|int
name|maxback
decl_stmt|;
comment|/* most to user */
name|int
name|grps
index|[
name|NGRPS
operator|/
operator|(
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|*
literal|8
operator|)
index|]
decl_stmt|;
comment|/* NGRPS=NGROUPS */
name|setgrp
argument_list|(
literal|0
argument_list|,
name|grps
argument_list|)
expr_stmt|;
comment|/* get groups */
name|maxback
operator|=
name|ngroups
expr_stmt|;
comment|/* save limit */
name|ngroups
operator|=
literal|0
expr_stmt|;
comment|/* start empty */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|NGRPS
operator|&&
name|ngroups
operator|<
name|maxback
condition|;
name|i
operator|++
control|)
comment|/* for each */
if|if
condition|(
name|grps
index|[
name|i
operator|/
operator|(
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|*
literal|8
operator|)
index|]
operator|&
operator|(
literal|1
operator|<<
operator|(
name|i
operator|%
operator|(
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|*
literal|8
operator|)
operator|)
operator|)
condition|)
block|{
operator|*
name|gidset
operator|++
operator|=
name|i
expr_stmt|;
comment|/* save the group */
name|ngroups
operator|++
expr_stmt|;
comment|/* and count */
block|}
return|return
operator|(
name|ngroups
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
endif|defined (BSD41A)
end_endif

begin_comment
comment|/*  *	The V7 and 4.1 version of this system call. Also serves well   *	for the 2.8 Bsd kernels and probably for the more recent BTL  *	kernels.  *	This could be extended to read from /etc/groups to actually give  *	the user all groups he is permitted.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|V7
argument_list|)
operator|||
name|defined
argument_list|(
name|BSD41
argument_list|)
operator|||
name|defined
argument_list|(
name|BSD2x
argument_list|)
operator|||
name|defined
argument_list|(
name|USG
argument_list|)
end_if

begin_macro
name|getgroups
argument_list|(
argument|ngroups
argument_list|,
argument|gidset
argument_list|)
end_macro

begin_comment
comment|/* simple V7 one */
end_comment

begin_decl_stmt
name|int
name|ngroups
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|gidset
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|*
name|gidset
operator|=
name|getgid
argument_list|()
operator|&
name|GIDMASK
expr_stmt|;
name|ngroups
operator|=
literal|1
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
endif|defined (V7) || defined (BSD41) || defined (BSD2x) || defined(USG)
end_endif

end_unit

