begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * $FreeBSD$  * $Source: /usr/src/eBones/rkinitd/RCS/rkinitd.c,v $  * $Author: dglo $  *  * This is the main source file for rkinit  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SABER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
operator|&&
name|defined
argument_list|(
name|RCS_HDRS
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint || SABER || LOCORE || RCS_HDRS */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<krb.h>
end_include

begin_include
include|#
directive|include
file|<des.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<rkinit.h>
end_include

begin_include
include|#
directive|include
file|<rkinit_err.h>
end_include

begin_include
include|#
directive|include
file|<rkinit_private.h>
end_include

begin_include
include|#
directive|include
file|"rkinitd.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|inetd
init|=
name|TRUE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if we were started by inetd */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_decl_stmt
specifier|static
name|void
name|usage
argument_list|(
name|void
argument_list|)
else|#
directive|else
decl|static
name|void
name|usage
argument_list|()
endif|#
directive|endif
comment|/* __STDC__ */
block|{
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"rkinitd usage: rkinitd [-notimeout]\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_decl_stmt
name|void
name|error
argument_list|(
name|void
argument_list|)
else|#
directive|else
name|void
name|error
argument_list|()
endif|#
directive|endif
comment|/* __STDC__ */
block|{
name|char
name|errbuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
name|strcpy
argument_list|(
name|errbuf
argument_list|,
name|rkinit_errmsg
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|strlen
argument_list|(
name|errbuf
argument_list|)
condition|)
block|{
if|if
condition|(
name|inetd
condition|)
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"rkinitd: %s"
argument_list|,
name|errbuf
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"rkinitd: %s\n"
argument_list|,
name|errbuf
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_decl_stmt
name|int
ifdef|#
directive|ifdef
name|__STDC__
decl|main
argument_list|(
name|int
name|argc
argument_list|,
name|char
operator|*
name|argv
index|[]
argument_list|)
else|#
directive|else
decl|main
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
name|int
name|argc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_block
block|{
name|int
name|version
decl_stmt|;
comment|/* Version of the transaction */
name|int
name|notimeout
init|=
name|FALSE
decl_stmt|;
comment|/* Should we not timeout? */
specifier|static
name|char
modifier|*
name|envinit
index|[
literal|1
index|]
decl_stmt|;
comment|/* Empty environment */
specifier|extern
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
comment|/* This process's environment */
name|int
name|status
init|=
literal|0
decl_stmt|;
comment|/* General error code */
comment|/*      * Clear the environment so that this process does not inherit       * kerberos ticket variable information from the person who started      * the process (if a person started it...).      */
name|environ
operator|=
name|envinit
expr_stmt|;
comment|/* Initialize com_err error table */
name|init_rkin_err_tbl
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
comment|/* This only works if the library was compiled with DEBUG defined */
name|rki_i_am_server
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* DEBUG */
comment|/*       * Make sure that we are running as root or can arrange to be       * running as root.  We need both to be able to read /etc/srvtab      * and to be able to change uid to create tickets.      */
operator|(
name|void
operator|)
name|setuid
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|getuid
argument_list|()
operator|!=
literal|0
condition|)
block|{
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"rkinitd: not running as root.\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* Determine whether to time out */
if|if
condition|(
name|argc
operator|==
literal|2
condition|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
literal|"-notimeout"
argument_list|)
condition|)
name|usage
argument_list|()
expr_stmt|;
else|else
name|notimeout
operator|=
name|TRUE
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|argc
operator|!=
literal|1
condition|)
name|usage
argument_list|()
expr_stmt|;
name|inetd
operator|=
name|setup_rpc
argument_list|(
name|notimeout
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|status
operator|=
name|choose_version
argument_list|(
operator|&
name|version
argument_list|)
operator|!=
name|RKINIT_SUCCESS
operator|)
condition|)
block|{
name|error
argument_list|()
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|status
operator|=
name|get_tickets
argument_list|(
name|version
argument_list|)
operator|!=
name|RKINIT_SUCCESS
operator|)
condition|)
block|{
name|error
argument_list|()
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

