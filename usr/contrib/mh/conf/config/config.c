begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* config.c - master MH configuration file */
end_comment

begin_comment
comment|/* @(MHWARNING) */
end_comment

begin_comment
comment|/* LINTLIBRARY */
end_comment

begin_include
include|#
directive|include
file|"../h/mh.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|MHRC
end_ifdef

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_endif
endif|#
directive|endif
endif|MHRC
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|binpath
parameter_list|(
name|file
parameter_list|)
value|"@(MHBINPATH)/file"
end_define

begin_define
define|#
directive|define
name|etcpath
parameter_list|(
name|file
parameter_list|)
value|"@(MHETCPATH)/file"
end_define

begin_expr_stmt
unit|@
operator|(
name|MHCONFIG
operator|)
ifdef|#
directive|ifdef
name|MHRC
ifdef|#
directive|ifdef
name|SYS5
expr|struct
name|passwd
operator|*
name|getpwnam
argument_list|()
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
endif|SYS5
end_endif

begin_endif
endif|#
directive|endif
endif|MHRC
end_endif

begin_comment
comment|/*
comment|*/
end_comment

begin_decl_stmt
specifier|static
name|char
name|lpath
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|char
modifier|*
name|libpath
parameter_list|(
name|file
parameter_list|)
name|char
modifier|*
name|file
decl_stmt|;
block|{
name|char
modifier|*
name|cp
decl_stmt|;
ifdef|#
directive|ifdef
name|MHRC
name|char
modifier|*
name|pp
decl_stmt|;
name|struct
name|passwd
modifier|*
name|pw
decl_stmt|;
endif|#
directive|endif
endif|MHRC
ifdef|#
directive|ifdef
name|MHRC
name|m_getdefs
argument_list|()
expr_stmt|;
endif|#
directive|endif
endif|MHRC
switch|switch
condition|(
operator|*
name|file
condition|)
block|{
case|case
literal|'/'
case|:
return|return
name|file
return|;
ifdef|#
directive|ifdef
name|MHRC
case|case
literal|'~'
case|:
if|if
condition|(
name|cp
operator|=
name|index
argument_list|(
name|pp
operator|=
name|file
operator|+
literal|1
argument_list|,
literal|'/'
argument_list|)
condition|)
operator|*
name|cp
operator|++
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
operator|*
name|pp
operator|==
name|NULL
condition|)
name|pp
operator|=
name|mypath
expr_stmt|;
elseif|else
if|if
condition|(
name|pw
operator|=
name|getpwnam
argument_list|(
name|pp
argument_list|)
condition|)
name|pp
operator|=
name|pw
operator|->
name|pw_dir
expr_stmt|;
else|else
block|{
if|if
condition|(
name|cp
condition|)
operator|*
operator|--
name|cp
operator|=
literal|'/'
expr_stmt|;
goto|goto
name|try_it
goto|;
block|}
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|lpath
argument_list|,
literal|"%s/%s"
argument_list|,
name|pp
argument_list|,
name|cp
condition|?
name|cp
else|:
literal|""
argument_list|)
expr_stmt|;
if|if
condition|(
name|cp
condition|)
operator|*
operator|--
name|cp
operator|=
literal|'/'
expr_stmt|;
if|if
condition|(
name|access
argument_list|(
name|lpath
argument_list|,
literal|04
argument_list|)
operator|!=
name|NOTOK
condition|)
return|return
name|lpath
return|;
comment|/* else fall */
name|try_it
label|:
empty_stmt|;
endif|#
directive|endif
endif|MHRC
default|default:
if|if
condition|(
name|access
argument_list|(
operator|(
name|cp
operator|=
name|m_maildir
argument_list|(
name|file
argument_list|)
operator|)
argument_list|,
literal|04
argument_list|)
operator|!=
name|NOTOK
condition|)
return|return
name|cp
return|;
block|}
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|lpath
argument_list|,
name|etcpath
argument_list|(
operator|%
name|s
argument_list|)
argument_list|,
name|file
argument_list|)
expr_stmt|;
return|return
operator|(
name|access
argument_list|(
name|lpath
argument_list|,
literal|04
argument_list|)
operator|!=
name|NOTOK
condition|?
name|lpath
else|:
name|file
operator|)
return|;
block|}
end_function

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/*   * Standard yes/no switches structure  */
end_comment

begin_decl_stmt
name|struct
name|swit
name|anoyes
index|[]
init|=
block|{
literal|"no"
block|,
literal|0
block|,
literal|"yes"
block|,
literal|0
block|,
name|NULL
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/*   * MH constants  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|components
init|=
literal|"components"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|current
init|=
literal|"cur"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|defalt
init|=
literal|"inbox"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|digestcomps
init|=
literal|"digestcomps"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|distcomps
init|=
literal|"distcomps"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|draft
init|=
literal|"draft"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|forwcomps
init|=
literal|"forwcomps"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|mh_defaults
init|=
name|etcpath
argument_list|(
name|mh
operator|.
name|profile
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|mh_profile
init|=
literal|".mh_profile"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|mhlformat
init|=
literal|"mhl.format"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|mhlforward
init|=
literal|"mhl.forward"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|nsequence
init|=
literal|"Sequence-Negation"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|pfolder
init|=
literal|"Current-Folder"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|psequence
init|=
literal|"Previous-Sequence"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|rcvdistcomps
init|=
literal|"rcvdistcomps"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|replcomps
init|=
literal|"replcomps"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|usequence
init|=
literal|"Unseen-Sequence"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * MH not-so constants  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|context
init|=
literal|"context"
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NOMHSEQ
end_ifndef

begin_decl_stmt
name|char
modifier|*
name|mh_seq
init|=
literal|".mh_sequences"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
else|NOMHSEQ
end_else

begin_decl_stmt
name|char
modifier|*
name|mh_seq
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|NOMHSEQ
end_endif

begin_comment
comment|/*   * MH globals  */
end_comment

begin_decl_stmt
name|char
name|ctxflags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* status of user's context */
end_comment

begin_decl_stmt
name|char
modifier|*
name|invo_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pgm invocation name */
end_comment

begin_decl_stmt
name|char
modifier|*
name|mypath
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user's $HOME */
end_comment

begin_decl_stmt
name|char
modifier|*
name|defpath
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pathname of user's profile */
end_comment

begin_decl_stmt
name|char
modifier|*
name|ctxpath
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pathname of user's context */
end_comment

begin_decl_stmt
name|struct
name|node
modifier|*
name|m_defs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* profile/context structure */
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/*   * MH processes  */
end_comment

begin_comment
comment|/*  * This program is usually called directly by users, but it is  * also invoked by the post program to process an "fcc".  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|fileproc
init|=
name|binpath
argument_list|(
name|refile
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * This program is called to incorporate messages into a folder.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|incproc
init|=
name|binpath
argument_list|(
name|inc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * When a user runs an MH program for the first time, this program  * is called to create his MH profile, and mail directory.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|installproc
init|=
name|etcpath
argument_list|(
name|install
operator|-
name|mh
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This is the program invoked by a "list" response to "What now?"  *  whereas, showproc is the program invoked by show, next, prev.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MORE
end_ifndef

begin_decl_stmt
name|char
modifier|*
name|lproc
init|=
literal|"/usr/ucb/more"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
else|MORE
end_else

begin_decl_stmt
name|char
modifier|*
name|lproc
init|=
name|MORE
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|MORE
end_endif

begin_comment
comment|/*  * This is the path for the Bell equivalent mail program.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|mailproc
init|=
name|binpath
argument_list|(
name|mhmail
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * mhl runs this program as a front-end.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MORE
end_ifndef

begin_decl_stmt
name|char
modifier|*
name|moreproc
init|=
literal|"/usr/ucb/more"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
else|MORE
end_else

begin_decl_stmt
name|char
modifier|*
name|moreproc
init|=
name|MORE
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|MORE
end_endif

begin_comment
comment|/*   * This program is mhl - the nifty message lister  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|mhlproc
init|=
name|etcpath
argument_list|(
name|mhl
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * This is the super handy BBoard reading program, which is really just the MH  * shell program  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|mshproc
init|=
name|binpath
argument_list|(
name|msh
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * This program is called to pack a folder.    */
end_comment

begin_decl_stmt
name|char
modifier|*
name|packproc
init|=
name|binpath
argument_list|(
name|packf
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This is the delivery program called through send to  * actually deliver mail to users.  This is the interface to  * the MTS.  */
end_comment

begin_if
if|#
directive|if
name|BERK
operator|&&
name|SENDMTS
end_if

begin_decl_stmt
name|char
modifier|*
name|postproc
init|=
name|etcpath
argument_list|(
name|spost
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|postproc
init|=
name|etcpath
argument_list|(
name|post
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|BERK
end_endif

begin_comment
comment|/*   * This program is called to remove a folder.    */
end_comment

begin_decl_stmt
name|char
modifier|*
name|rmfproc
init|=
name|binpath
argument_list|(
name|rmf
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * This program is called to remove a message by rmm or refile -nolink.  * It's usually empty, which means to rename the file to a backup name.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|rmmproc
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This program is usually called by the user's whatnowproc, but it  * may also be called directly to send a message previously composed.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|sendproc
init|=
name|binpath
argument_list|(
name|send
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This program is called to list messages by the show program.  * By setting showproc to mhl, the user can run mhl instead.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MORE
end_ifndef

begin_decl_stmt
name|char
modifier|*
name|showproc
init|=
literal|"/usr/ucb/more"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
else|MORE
end_else

begin_decl_stmt
name|char
modifier|*
name|showproc
init|=
name|MORE
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|MORE
end_endif

begin_comment
comment|/*   * This program is called under stand-alone MH to deliver a message to  * a local user.  Under other MTS's it can be used to emulate a  * MMDF-II .maildelivery mechanism.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|slocalproc
init|=
name|etcpath
argument_list|(
name|slocal
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * This program is called by vmh as the back-end to the window management  * protocol  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|vmhproc
init|=
name|binpath
argument_list|(
name|msh
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * This program is called after comp, et. al., have built a draft  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|whatnowproc
init|=
name|binpath
argument_list|(
name|whatnow
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * This program is called to list/validate the addresses in a message.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|whomproc
init|=
name|binpath
argument_list|(
name|whom
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/*  * This is the editor invoked by the various message composition  * programs.  It SHOULD be a 2-D scope editor, such as Rand's ned  * or Berkeley's ex, but any editor will work.  We use prompter as  * the default, since with -prepend it works just fine with forw.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|sysed
init|=
literal|"@(MHEDITOR)"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * This is the MH alias file.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|AliasFile
init|=
name|etcpath
argument_list|(
name|MailAliases
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/*   * File protections  */
end_comment

begin_comment
comment|/*  * Folders (directories) are created with this protection (mode)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FOLDPROT
end_ifndef

begin_define
define|#
directive|define
name|FOLDPROT
value|"0711"
end_define

begin_endif
endif|#
directive|endif
endif|not FOLDPROT
end_endif

begin_decl_stmt
name|char
modifier|*
name|foldprot
init|=
name|FOLDPROT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Every NEW message will be created with this protection.  When a  * message is filed it retains its protection, so this only applies  * to messages coming in through inc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MSGPROT
end_ifndef

begin_define
define|#
directive|define
name|MSGPROT
value|"0644"
end_define

begin_endif
endif|#
directive|endif
endif|not MSGPROT
end_endif

begin_decl_stmt
name|char
modifier|*
name|msgprot
init|=
name|MSGPROT
decl_stmt|;
end_decl_stmt

end_unit

