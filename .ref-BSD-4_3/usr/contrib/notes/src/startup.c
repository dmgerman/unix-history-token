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
file|<pwd.h>
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
literal|"$Header: startup.c,v 1.7.0.3 85/03/18 20:56:44 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_decl_stmt
specifier|static
name|char
modifier|*
name|Bigversion
init|=
literal|"Notesfiles: $Revision: 1.7.0.3 $"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	this file contains code and declarations that are common to  *	all main lines. This routine should be called by all  *	mainline routines immediately.  *  *	We also take care of the problem of some systems not honoring  *	the setuid bit when root runs a program.  *  *	Ray Essick	May 7, 1982  */
end_comment

begin_decl_stmt
specifier|static
name|char
name|SysName
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* holds system name */
end_comment

begin_decl_stmt
specifier|static
name|char
name|authsys
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* author's system */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|UNAME
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/utsname.h>
end_include

begin_comment
comment|/* uname syscall */
end_comment

begin_endif
endif|#
directive|endif
endif|defined(UNAME)
end_endif

begin_decl_stmt
name|char
modifier|*
name|hised
init|=
name|DFLTED
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* his favorite editor */
end_comment

begin_decl_stmt
name|char
modifier|*
name|hisshell
init|=
name|DFLTSH
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* his favorite shell */
end_comment

begin_decl_stmt
name|char
modifier|*
name|hispager
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|hismailer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nrows
init|=
literal|24
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rows on screen */
end_comment

begin_decl_stmt
name|int
name|ncols
init|=
literal|80
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* width of screen */
end_comment

begin_decl_stmt
name|char
modifier|*
name|histty
init|=
operator|(
name|char
operator|*
operator|)
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tty as on command */
end_comment

begin_decl_stmt
name|int
name|intflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DEL hit recently */
end_comment

begin_decl_stmt
name|int
name|globuid
init|=
name|ANONUID
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* his true user id */
end_comment

begin_decl_stmt
name|int
name|Notesuid
init|=
name|NOTESUID
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default to root? */
end_comment

begin_decl_stmt
name|int
name|Anonuid
init|=
name|ANONUID
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Nindex
init|=
literal|12
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # on index page */
end_comment

begin_decl_stmt
name|int
name|ignoresigs
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* critical section */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Mstdir
init|=
name|MSTDIR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* store nf's here */
end_comment

begin_decl_stmt
name|char
modifier|*
name|System
init|=
name|SysName
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* point to it */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Authsystem
init|=
name|authsys
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* init pointer */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Invokedas
init|=
literal|"Unknown"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* argv[0] */
end_comment

begin_decl_stmt
name|char
name|Seqname
index|[
name|WDLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sequencer name */
end_comment

begin_decl_stmt
name|struct
name|when_f
name|Basetime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* zero time */
end_comment

begin_function_decl
name|struct
name|passwd
modifier|*
name|getpwnam
parameter_list|()
function_decl|;
end_function_decl

begin_macro
name|startup
argument_list|(
argument|argc
argument_list|,
argument|argv
argument_list|)
end_macro

begin_decl_stmt
name|int
name|argc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|passwd
modifier|*
name|pw
decl_stmt|;
name|struct
name|auth_f
name|whoami
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
comment|/*  *	Grab "notes" uid from /etc/passwd and also grab uid of  *	user running this process.  *	ditto for "anon".  */
if|if
condition|(
operator|(
name|pw
operator|=
name|getpwnam
argument_list|(
name|NOTES
argument_list|)
operator|)
operator|==
name|NULL
condition|)
comment|/* find notes uid */
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Can't find uid for %s, assuming %d\n"
argument_list|,
name|NOTES
argument_list|,
name|NOTESUID
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DYNADIR
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Assuming Notesfiles live in %s\n"
argument_list|,
name|Mstdir
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|DYNADIR
block|}
else|else
block|{
name|Notesuid
operator|=
name|pw
operator|->
name|pw_uid
operator|&
name|UIDMASK
expr_stmt|;
ifdef|#
directive|ifdef
name|DYNADIR
comment|/*  *	Select Mstdir based on the home directory for the "notes"  *	owner.  Make it one directory "above" the note's home directory.  *	(which in many places will be /usr/spool/notes/.utilities  */
if|if
condition|(
operator|(
name|p
operator|=
name|rindex
argument_list|(
name|pw
operator|->
name|pw_dir
argument_list|,
literal|'/'
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
comment|/* get end */
block|{
operator|*
name|p
operator|=
literal|'\0'
expr_stmt|;
comment|/* terminate */
if|if
condition|(
name|strlen
argument_list|(
name|pw
operator|->
name|pw_dir
argument_list|)
operator|>
literal|0
condition|)
comment|/* non-empty */
name|Mstdir
operator|=
name|strsave
argument_list|(
name|pw
operator|->
name|pw_dir
argument_list|)
expr_stmt|;
comment|/* save it */
block|}
endif|#
directive|endif
endif|DYNADIR
block|}
if|if
condition|(
operator|(
name|pw
operator|=
name|getpwnam
argument_list|(
name|ANON
argument_list|)
operator|)
operator|==
name|NULL
condition|)
comment|/* (prohibited) anon uid */
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Can't find uid for %s, assuming %d\n"
argument_list|,
name|ANON
argument_list|,
name|ANONUID
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|Anonuid
operator|=
name|pw
operator|->
name|pw_uid
operator|&
name|UIDMASK
expr_stmt|;
block|}
name|endpwent
argument_list|()
expr_stmt|;
comment|/*  *	now resolve who is running the program, make sure that  *	we are setuid'ed away from root which breaks our locks  *	at this time (need a better locking mechanism).  *  *	We really want seteuid(), but V7 and a number of others  *	don't offer this.  4.2 Bsd does, so we use it there.  */
name|globuid
operator|=
name|getuid
argument_list|()
operator|&
name|UIDMASK
expr_stmt|;
comment|/* set this */
ifdef|#
directive|ifdef
name|RUNSUID
if|if
condition|(
name|geteuid
argument_list|()
operator|==
literal|0
condition|)
comment|/* root access? */
block|{
ifdef|#
directive|ifdef
name|BSD42
name|seteuid
argument_list|(
name|Notesuid
argument_list|)
expr_stmt|;
comment|/* we'll fix that */
else|#
directive|else
name|setuid
argument_list|(
name|Notesuid
argument_list|)
expr_stmt|;
comment|/* we'll fix that */
endif|#
directive|endif
endif|BSD42
block|}
endif|#
directive|endif
endif|RUNSUID
name|getname
argument_list|(
operator|&
name|whoami
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* get my name */
name|strcpy
argument_list|(
name|Seqname
argument_list|,
operator|&
name|whoami
operator|.
name|aname
argument_list|)
expr_stmt|;
comment|/* load seq name */
comment|/*  *	and now decide where we are   */
ifdef|#
directive|ifdef
name|PORTBINARY
comment|/* to have portable binaries */
name|gethostname
argument_list|(
name|SysName
argument_list|,
sizeof|sizeof
argument_list|(
name|SysName
argument_list|)
argument_list|)
expr_stmt|;
comment|/* load it */
endif|#
directive|endif
endif|defined(PORTBINARY)
ifdef|#
directive|ifdef
name|UNAME
comment|/* like PORTBINARY */
block|{
name|struct
name|utsname
name|name
decl_stmt|;
name|uname
argument_list|(
operator|&
name|name
argument_list|)
expr_stmt|;
comment|/* UNIX 4.0 syscall */
name|strcpy
argument_list|(
name|SysName
argument_list|,
name|name
operator|.
name|nodename
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|defined(UNAME)
ifdef|#
directive|ifdef
name|WHOAMI
block|{
name|char
name|buf
index|[
name|BUFSIZ
index|]
decl_stmt|;
name|FILE
modifier|*
name|fd
decl_stmt|;
if|if
condition|(
operator|(
name|fd
operator|=
name|fopen
argument_list|(
name|WHOAMIFILE
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
comment|/* get file */
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Cannot open %s\n"
argument_list|,
name|WHOAMIFILE
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
name|fgets
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
name|buf
argument_list|,
name|fd
argument_list|)
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"no sysname in %s\n"
argument_list|,
name|WHOAMIFILE
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|sscanf
argument_list|(
name|buf
argument_list|,
literal|"#define sysname \"%[^\"]\""
argument_list|,
name|SysName
argument_list|)
operator|==
literal|1
condition|)
block|{
name|fclose
argument_list|(
name|fd
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
block|}
endif|#
directive|endif
endif|WHOAMI
comment|/*       * Now that we have a copy of the System name loaded into      * the "SysName" array, let's make a copy to use for the       * user as his system. The "System" will get used for things      * like the generation of Unique ID's.      */
name|strcpy
argument_list|(
name|Authsystem
argument_list|,
name|System
argument_list|)
expr_stmt|;
comment|/* copy it */
ifdef|#
directive|ifdef
name|FULLDOMAIN
comment|/*       * append the domain information (if it isn't already there)      * to the Author system name.      */
if|if
condition|(
name|index
argument_list|(
name|Authsystem
argument_list|,
literal|'.'
argument_list|)
operator|==
operator|(
name|char
operator|*
operator|)
name|NULL
condition|)
block|{
name|strcat
argument_list|(
name|Authsystem
argument_list|,
literal|"."
argument_list|)
expr_stmt|;
name|strcat
argument_list|(
name|Authsystem
argument_list|,
name|FULLDOMAIN
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|IDDOMAIN
comment|/*       *	append domain information if needed      *  to the system name as it is used in the unique id.      */
if|if
condition|(
name|index
argument_list|(
name|System
argument_list|,
literal|'.'
argument_list|)
operator|==
operator|(
name|char
operator|*
operator|)
name|NULL
condition|)
comment|/* if not there */
block|{
name|strcat
argument_list|(
name|SysName
argument_list|,
literal|"."
argument_list|)
expr_stmt|;
comment|/* separator */
name|strcat
argument_list|(
name|SysName
argument_list|,
name|FULLDOMAIN
argument_list|)
expr_stmt|;
comment|/* append it */
block|}
endif|#
directive|endif
endif|IDDOMAIN
endif|#
directive|endif
endif|FULLDOMAIN
comment|/*  *	Decide what we were invoked as  *	and set up a few other values that don't fit anywhere.  */
name|Invokedas
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
name|Basetime
operator|.
name|w_year
operator|=
literal|1970
expr_stmt|;
comment|/* unix time 0 */
name|Basetime
operator|.
name|w_month
operator|=
literal|1
expr_stmt|;
name|Basetime
operator|.
name|w_day
operator|=
literal|1
expr_stmt|;
name|Basetime
operator|.
name|w_hours
operator|=
literal|0
expr_stmt|;
name|Basetime
operator|.
name|w_mins
operator|=
literal|0
expr_stmt|;
name|Basetime
operator|.
name|w_gmttime
operator|=
literal|0
expr_stmt|;
block|}
end_block

end_unit

