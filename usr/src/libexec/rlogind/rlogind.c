begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1983, 1988, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1983, 1988, 1989, 1993\n\ 	The Regents of the University of California.  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)rlogind.c	8.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * remote login server:  *	\0  *	remuser\0  *	locuser\0  *	terminal_type/speed\0  *	data  *  * Automatic login protocol is done here, using login -f upon success,  * unless OLD_LOGIN is defined (then done in login, ala 4.2/4.3BSD).  */
end_comment

begin_define
define|#
directive|define
name|FD_SETSIZE
value|16
end_define

begin_comment
comment|/* don't need many bits for select */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<termios.h>
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
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"pathnames.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|TIOCPKT_WINDOW
end_ifndef

begin_define
define|#
directive|define
name|TIOCPKT_WINDOW
value|0x80
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
modifier|*
name|env
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NMAX
value|30
end_define

begin_decl_stmt
name|char
name|lusername
index|[
name|NMAX
operator|+
literal|1
index|]
decl_stmt|,
name|rusername
index|[
name|NMAX
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|term
index|[
literal|64
index|]
init|=
literal|"TERM="
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ENVSIZE
value|(sizeof("TERM=")-1)
end_define

begin_comment
comment|/* skip null for concatenation */
end_comment

begin_decl_stmt
name|int
name|keepalive
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|check_all
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|check_all
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|passwd
modifier|*
name|pwd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|doit
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|control
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|protocol
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cleanup
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fatal
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|do_rlogin
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|getstr
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setup_term
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|do_krb_login
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|usage
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|local_domain
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|topdomain
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
specifier|extern
name|int
name|__check_rhosts_file
decl_stmt|;
name|struct
name|sockaddr_in
name|from
decl_stmt|;
name|int
name|ch
decl_stmt|,
name|fromlen
decl_stmt|,
name|on
decl_stmt|;
name|openlog
argument_list|(
literal|"rlogind"
argument_list|,
name|LOG_PID
operator||
name|LOG_CONS
argument_list|,
name|LOG_AUTH
argument_list|)
expr_stmt|;
name|opterr
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|(
name|ch
operator|=
name|getopt
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
name|ARGSTR
argument_list|)
operator|)
operator|!=
name|EOF
condition|)
switch|switch
condition|(
name|ch
condition|)
block|{
case|case
literal|'a'
case|:
name|check_all
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'a'
case|:
name|check_all
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'l'
case|:
name|__check_rhosts_file
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|'n'
case|:
name|keepalive
operator|=
literal|0
expr_stmt|;
break|break;
ifdef|#
directive|ifdef
name|KERBEROS
case|case
literal|'k'
case|:
name|use_kerberos
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'v'
case|:
name|vacuous
operator|=
literal|1
expr_stmt|;
break|break;
endif|#
directive|endif
case|case
literal|'?'
case|:
default|default:
name|usage
argument_list|()
expr_stmt|;
break|break;
block|}
name|argc
operator|-=
name|optind
expr_stmt|;
name|argv
operator|+=
name|optind
expr_stmt|;
ifdef|#
directive|ifdef
name|KERBEROS
if|if
condition|(
name|use_kerberos
operator|&&
name|vacuous
condition|)
block|{
name|usage
argument_list|()
expr_stmt|;
name|fatal
argument_list|(
name|STDERR_FILENO
argument_list|,
literal|"only one of -k and -v allowed"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|fromlen
operator|=
sizeof|sizeof
argument_list|(
name|from
argument_list|)
expr_stmt|;
if|if
condition|(
name|getpeername
argument_list|(
literal|0
argument_list|,
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
operator|&
name|from
argument_list|,
operator|&
name|fromlen
argument_list|)
operator|<
literal|0
condition|)
block|{
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"Couldn't get peer name of remote host: %m"
argument_list|)
expr_stmt|;
name|fatalperror
argument_list|(
literal|"Can't get peer name of remote host"
argument_list|)
expr_stmt|;
block|}
name|on
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|keepalive
operator|&&
name|setsockopt
argument_list|(
literal|0
argument_list|,
name|SOL_SOCKET
argument_list|,
name|SO_KEEPALIVE
argument_list|,
operator|&
name|on
argument_list|,
sizeof|sizeof
argument_list|(
name|on
argument_list|)
argument_list|)
operator|<
literal|0
condition|)
name|syslog
argument_list|(
name|LOG_WARNING
argument_list|,
literal|"setsockopt (SO_KEEPALIVE): %m"
argument_list|)
expr_stmt|;
name|on
operator|=
name|IPTOS_LOWDELAY
expr_stmt|;
if|if
condition|(
name|setsockopt
argument_list|(
literal|0
argument_list|,
name|IPPROTO_IP
argument_list|,
name|IP_TOS
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|on
argument_list|,
sizeof|sizeof
argument_list|(
name|int
argument_list|)
argument_list|)
operator|<
literal|0
condition|)
name|syslog
argument_list|(
name|LOG_WARNING
argument_list|,
literal|"setsockopt (IP_TOS): %m"
argument_list|)
expr_stmt|;
name|doit
argument_list|(
literal|0
argument_list|,
operator|&
name|from
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|int
name|child
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|netf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|line
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|confirmed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|winsize
name|win
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|doit
parameter_list|(
name|f
parameter_list|,
name|fromp
parameter_list|)
name|int
name|f
decl_stmt|;
name|struct
name|sockaddr_in
modifier|*
name|fromp
decl_stmt|;
block|{
name|int
name|master
decl_stmt|,
name|pid
decl_stmt|,
name|on
init|=
literal|1
decl_stmt|;
name|int
name|authenticated
init|=
literal|0
decl_stmt|;
endif|#
directive|endif
specifier|register
name|struct
name|hostent
modifier|*
name|hp
decl_stmt|;
name|char
name|hostname
index|[
literal|2
operator|*
name|MAXHOSTNAMELEN
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|c
decl_stmt|;
name|alarm
argument_list|(
literal|60
argument_list|)
expr_stmt|;
name|read
argument_list|(
name|f
argument_list|,
operator|&
name|c
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|!=
literal|0
condition|)
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|KERBEROS
if|if
condition|(
name|vacuous
condition|)
name|fatal
argument_list|(
name|f
argument_list|,
literal|"Remote host requires Kerberos authentication"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|fromp
operator|->
name|sin_port
operator|=
name|ntohs
argument_list|(
operator|(
name|u_short
operator|)
name|fromp
operator|->
name|sin_port
argument_list|)
expr_stmt|;
name|hp
operator|=
name|gethostbyaddr
argument_list|(
argument|(char *)&fromp->sin_addr
argument_list|,
argument|sizeof(struct in_addr)
argument_list|,
argument|if (use_kerberos) { 		retval = do_krb_login(fromp); 		if (retval ==
literal|0
argument|) 			authenticated++; 		else if (retval>
literal|0
argument|) 			fatal(f, krb_err_txt[retval],
literal|0
argument|); 		write(f,&c,
literal|1
argument|); 		confirmed =
literal|1
argument|;
comment|/* we sent the null! */
argument|} else
ifndef|#
directive|ifndef
name|OLD_LOGIN
argument|{ 		if (fromp->sin_family != AF_INET || 		    fromp->sin_port>= IPPORT_RESERVED || 		    fromp->sin_port< IPPORT_RESERVED/
literal|2
argument|) { 			syslog(LOG_NOTICE,
literal|"Connection from %s on illegal port"
argument|, 				inet_ntoa(fromp->sin_addr)); 			fatal(f,
literal|"Permission denied"
argument|,
literal|0
argument|); 		} 		if (do_rlogin(fromp) ==
literal|0
argument|) 			authenticated++; 	} 	if (confirmed ==
literal|0
argument|) { 		write(f,
literal|""
argument|,
literal|1
argument|); 		confirmed =
literal|1
argument|;
comment|/* we sent the null! */
argument|}
ifdef|#
directive|ifdef
name|KERBEROS
endif|#
directive|endif
argument|netf = f;  	pid = forkpty(&master, line, NULL,&win); 	if (pid<
literal|0
argument|) { 		if (errno == ENOENT) 			fatal(f,
literal|"Out of ptys"
argument|,
literal|0
argument|); 		else 			fatal(f,
literal|"Forkpty"
argument|,
literal|1
argument|); 	} 	if (pid ==
literal|0
argument|) { 		if (f>
literal|2
argument|)
comment|/* f should always be 0, but... */
argument|(void) close(f); 		setup_term(
literal|0
argument|);
ifdef|#
directive|ifdef
name|OLD_LOGIN
argument|execl(
literal|"/bin/login"
argument|,
literal|"login"
argument|,
literal|"-r"
argument|, hp->h_name,
literal|0
argument|);
else|#
directive|else
comment|/* OLD_LOGIN */
argument|if (authenticated) {
ifdef|#
directive|ifdef
name|KERBEROS
argument|if (use_kerberos&& (pwd->pw_uid ==
literal|0
argument|)) 				syslog(LOG_INFO|LOG_AUTH,
literal|"ROOT Kerberos login from %s.%s@%s on %s\n"
argument|, 				    kdata->pname, kdata->pinst, kdata->prealm, 				    hostname);
endif|#
directive|endif
argument|execl(_PATH_LOGIN,
literal|"login"
argument|,
literal|"-p"
argument|,
literal|"-h"
argument|, hostname,
literal|"-f"
argument|, lusername, (char *)NULL); 		} else 			execl(_PATH_LOGIN,
literal|"login"
argument|,
literal|"-p"
argument|,
literal|"-h"
argument|, hostname, lusername, (char *)NULL);
endif|#
directive|endif
comment|/* OLD_LOGIN */
argument|fatal(STDERR_FILENO, _PATH_LOGIN,
literal|1
argument|);
comment|/*NOTREACHED*/
argument|} 	ioctl(f, FIONBIO,&on); 	ioctl(master, FIONBIO,&on); 	ioctl(master, TIOCPKT,&on); 	signal(SIGCHLD, cleanup); 	protocol(f, master); 	signal(SIGCHLD, SIG_IGN); 	cleanup(
literal|0
argument|); }  char	magic[
literal|2
argument|] = {
literal|0377
argument_list|,
literal|0377
argument|}; char	oobdata[] = {TIOCPKT_WINDOW};
comment|/*  * Handle a "control" request (signaled by magic being present)  * in the data stream.  For now, we are only willing to handle  * window size changes.  */
argument|int control(pty, cp, n) 	int pty; 	char *cp; 	int n; { 	struct winsize w;  	if (n<
literal|4
argument|+sizeof (w) || cp[
literal|2
argument|] !=
literal|'s'
argument||| cp[
literal|3
argument|] !=
literal|'s'
argument|) 		return (
literal|0
argument|); 	oobdata[
literal|0
argument|]&= ~TIOCPKT_WINDOW;
comment|/* we know he heard */
argument|bcopy(cp+
literal|4
argument|, (char *)&w, sizeof(w)); 	w.ws_row = ntohs(w.ws_row); 	w.ws_col = ntohs(w.ws_col); 	w.ws_xpixel = ntohs(w.ws_xpixel); 	w.ws_ypixel = ntohs(w.ws_ypixel); 	(void)ioctl(pty, TIOCSWINSZ,&w); 	return (
literal|4
argument|+sizeof (w)); }
comment|/*  * rlogin "protocol" machine.  */
argument|void protocol(f, p) 	register int f
argument_list|,
argument|p; { 	char pibuf[
literal|1024
argument|+
literal|1
argument|]
argument_list|,
argument|fibuf[
literal|1024
argument|]
argument_list|,
argument|*pbp
argument_list|,
argument|*fbp; 	register pcc =
literal|0
argument_list|,
argument|fcc =
literal|0
argument|; 	int cc
argument_list|,
argument|nfd
argument_list|,
argument|n; 	char cntl;
comment|/* 	 * Must ignore SIGTTOU, otherwise we'll stop 	 * when we try and set slave pty's window shape 	 * (our controlling tty is the master pty). 	 */
argument|(void) signal(SIGTTOU, SIG_IGN); 	send(f, oobdata,
literal|1
argument|, MSG_OOB);
comment|/* indicate new rlogin */
argument|if (f> p) 		nfd = f +
literal|1
argument|; 	else 		nfd = p +
literal|1
argument|; 	if (nfd> FD_SETSIZE) { 		syslog(LOG_ERR,
literal|"select mask too small, increase FD_SETSIZE"
argument|); 		fatal(f,
literal|"internal error (select mask too small)"
argument|,
literal|0
argument|); 	} 	for (;;) { 		fd_set ibits
argument_list|,
argument|obits
argument_list|,
argument|ebits
argument_list|,
argument|*omask;  		FD_ZERO(&ebits); 		FD_ZERO(&ibits); 		FD_ZERO(&obits); 		omask = (fd_set *)NULL; 		if (fcc) { 			FD_SET(p,&obits); 			omask =&obits; 		} else 			FD_SET(f,&ibits); 		if (pcc>=
literal|0
argument|) 			if (pcc) { 				FD_SET(f,&obits); 				omask =&obits; 			} else 				FD_SET(p,&ibits); 		FD_SET(p,&ebits); 		if ((n = select(nfd,&ibits, omask,&ebits,
literal|0
argument|))<
literal|0
argument|) { 			if (errno == EINTR) 				continue; 			fatal(f,
literal|"select"
argument|,
literal|1
argument|); 		} 		if (n ==
literal|0
argument|) {
comment|/* shouldn't happen... */
argument|sleep(
literal|5
argument|); 			continue; 		}
define|#
directive|define
name|pkcontrol
parameter_list|(
name|c
parameter_list|)
value|((c)&(TIOCPKT_FLUSHWRITE|TIOCPKT_NOSTOP|TIOCPKT_DOSTOP))
argument|if (FD_ISSET(p,&ebits)) { 			cc = read(p,&cntl,
literal|1
argument|); 			if (cc ==
literal|1
argument|&& pkcontrol(cntl)) { 				cntl |= oobdata[
literal|0
argument|]; 				send(f,&cntl,
literal|1
argument|, MSG_OOB); 				if (cntl& TIOCPKT_FLUSHWRITE) { 					pcc =
literal|0
argument|; 					FD_CLR(p,&ibits); 				} 			} 		} 			fcc = read(f, fibuf, sizeof(fibuf)); 			if (fcc<
literal|0
argument|&& errno == EWOULDBLOCK) 				fcc =
literal|0
argument|; 			else { 				register char *cp; 				int left
argument_list|,
argument|n;  				if (fcc<=
literal|0
argument|) 					break; 				fbp = fibuf;  			top: 				for (cp = fibuf; cp< fibuf+fcc-
literal|1
argument|; cp++) 					if (cp[
literal|0
argument|] == magic[
literal|0
argument|]&& 					    cp[
literal|1
argument|] == magic[
literal|1
argument|]) { 						left = fcc - (cp-fibuf); 						n = control(p, cp, left); 						if (n) { 							left -= n; 							if (left>
literal|0
argument|) 								bcopy(cp+n, cp, left); 							fcc -= n; 							goto top;
comment|/* n^2 */
argument|} 					} 				FD_SET(p,&obits);
comment|/* try write */
argument|} 		}  		if (FD_ISSET(p,&obits)&& fcc>
literal|0
argument|) { 			cc = write(p, fbp, fcc); 			if (cc>
literal|0
argument|) { 				fcc -= cc; 				fbp += cc; 			} 		}  		if (FD_ISSET(p,&ibits)) { 			pcc = read(p, pibuf, sizeof (pibuf)); 			pbp = pibuf; 			if (pcc<
literal|0
argument|&& errno == EWOULDBLOCK) 				pcc =
literal|0
argument|; 			else if (pcc<=
literal|0
argument|) 				break; 			else if (pibuf[
literal|0
argument|] ==
literal|0
argument|) { 				pbp++
argument_list|,
argument|pcc--; 				obits |= fmask;
comment|/* try a write */
argument|} else { 				if (pkcontrol(pibuf[
literal|0
argument|])) { 					pibuf[
literal|0
argument|] |= oobdata[
literal|0
argument|]; 					send(f,&pibuf[
literal|0
argument|],
literal|1
argument|, MSG_OOB); 				} 				pcc =
literal|0
argument|; 			} 		} 			cc = write(f, pbp, pcc); 			if (cc<
literal|0
argument|&& errno == EWOULDBLOCK) {
comment|/* 				 * This happens when we try write after read 				 * from p, but some old kernels balk at large 				 * writes even when select returns true. 				 */
argument|if (!FD_ISSET(p,&ibits)) 					sleep(
literal|5
argument|); 				continue; 			} 			if (cc>
literal|0
argument|) { 				pcc -= cc; 				pbp += cc; 			} 		} 	} }  void cleanup(signo) 	int signo; { 	char *p;  	p = line + sizeof(_PATH_DEV) -
literal|1
argument|; 	if (logout(p)) 		logwtmp(p,
literal|""
argument|,
literal|""
argument|); 	(void)chmod(line,
literal|0666
argument|); 	(void)chown(line,
literal|0
argument|,
literal|0
argument|); 	*p =
literal|'p'
argument|; 	(void)chmod(line,
literal|0666
argument|); 	(void)chown(line,
literal|0
argument|,
literal|0
argument|); 	shutdown(netf,
literal|2
argument|); 	exit(
literal|1
argument|); }  void fatal(f, msg, syserr) 	int f; 	char *msg; 	int syserr; { 	int len; 	char buf[BUFSIZ]
argument_list|,
argument|*bp = buf;
comment|/* 	 * Prepend binary one to message if we haven't sent 	 * the magic null as confirmation. 	 */
argument|if (!confirmed) 		*bp++ =
literal|'\01'
argument|;
comment|/* error indicator */
argument|if (syserr) 		len = sprintf(bp,
literal|"rlogind: %s: %s.\r\n"
argument|, 		    msg, strerror(errno)); 	else 		len = sprintf(bp,
literal|"rlogind: %s.\r\n"
argument|, msg); 	(void) write(f, buf, bp + len - buf); 	exit(
literal|1
argument|); }
ifndef|#
directive|ifndef
name|OLD_LOGIN
argument|int do_rlogin(dest) 	struct sockaddr_in *dest; { 	getstr(rusername, sizeof(rusername),
literal|"remuser too long"
argument|); 	getstr(lusername, sizeof(lusername),
literal|"locuser too long"
argument|); 	getstr(term+ENVSIZE, sizeof(term)-ENVSIZE,
literal|"Terminal type too long"
argument|);  	pwd = getpwnam(lusername); 	if (pwd == NULL) 		return (-
literal|1
argument|); 	if (pwd->pw_uid ==
literal|0
argument|) 		return (-
literal|1
argument|);
comment|/* XXX why don't we syslog() failure? */
argument|return (iruserok(dest->sin_addr.s_addr,
literal|0
argument|, rusername, lusername)); }  void getstr(buf, cnt, errmsg) 	char *buf; 	int cnt; 	char *errmsg; { 	char c;  	do { 		if (read(
literal|0
argument|,&c,
literal|1
argument|) !=
literal|1
argument|) 			exit(
literal|1
argument|); 		if (--cnt<
literal|0
argument|) 			fatal(STDOUT_FILENO, errmsg,
literal|0
argument|); 		*buf++ = c; 	} while (c !=
literal|0
argument|); }  extern	char **environ;  void char *speeds[] = {
literal|"0"
argument_list|,
literal|"50"
argument_list|,
literal|"75"
argument_list|,
literal|"110"
argument_list|,
literal|"134"
argument_list|,
literal|"150"
argument_list|,
literal|"200"
argument_list|,
literal|"300"
argument_list|,
literal|"600"
argument_list|,
literal|"1200"
argument_list|,
literal|"1800"
argument_list|,
literal|"2400"
argument_list|,
literal|"4800"
argument_list|,
literal|"9600"
argument_list|,
literal|"19200"
argument_list|,
literal|"38400"
argument_list|,
argument|};
define|#
directive|define
name|NSPEEDS
value|(sizeof(speeds) / sizeof(speeds[0]))
argument|setup_term(fd) 	int fd; { 	register char *cp = index(term,
literal|'/'
argument|)
argument_list|,
argument|**cpp; 	char *speed;
if|#
directive|if
name|BSD
operator|>
literal|43
argument|struct termios tt;  	tcgetattr(fd,&tt); 	if (cp) { 		*cp++ =
literal|'\0'
argument|; 		speed = cp; 		cp = index(speed,
literal|'/'
argument|); 		if (cp) 			*cp++ =
literal|'\0'
argument|; 		cfsetspeed(&tt, atoi(speed)); 	}  	tt.c_iflag = TTYDEF_IFLAG; 	tt.c_oflag = TTYDEF_OFLAG; 	tt.c_lflag = TTYDEF_LFLAG; 	tcsetattr(fd, TCSADFLUSH,&tt);
else|#
directive|else
argument|struct sgttyb sgttyb;  	(void)ioctl(fd, TIOCGETP,&sgttyb); 	if (cp) { 		*cp++ =
literal|'\0'
argument|; 		speed = cp; 		cp = index(speed,
literal|'/'
argument|); 		if (cp) 			*cp++ =
literal|'\0'
argument|; 		for (cpp = speeds; cpp<&speeds[NSPEEDS]; cpp++) 		    if (strcmp(*cpp, speed) ==
literal|0
argument|) { 			sgttyb.sg_ispeed = sgttyb.sg_ospeed = cpp - speeds; 			break; 		    } 	} 	sgttyb.sg_flags = ECHO|CRMOD|ANYP|XTABS; 	(void)ioctl(fd, TIOCSETP,&sgttyb);
endif|#
directive|endif
argument|env[
literal|0
argument|] = term; 	env[
literal|1
argument|] =
literal|0
argument|; 	environ = env; }
comment|/*  * Check whether host h is in our local domain,  * defined as sharing the last two components of the domain part,  * or the entire domain part if the local domain has only one component.  * If either name is unqualified (contains no '.'),  * assume that the host is local, as it will be  * interpreted as such.  */
argument|local_domain(h) 	char *h; { 	char localhost[MAXHOSTNAMELEN]; 	char *p1
argument_list|,
argument|*p2
argument_list|,
argument|*topdomain();  	localhost[
literal|0
argument|] =
literal|0
argument|; 	(void) gethostname(localhost, sizeof(localhost)); 	p1 = topdomain(localhost); 	p2 = topdomain(h); 	if (p1 == NULL || p2 == NULL || !strcasecmp(p1, p2)) 		return(
literal|1
argument|); 	return(
literal|0
argument|); }  char * topdomain(h) 	char *h; { 	register char *p; 	char *maybe = NULL; 	int dots =
literal|0
argument|;  	for (p = h + strlen(h); p>= h; p--) { 		if (*p ==
literal|'.'
argument|) { 			if (++dots ==
literal|2
argument|) 				return (p); 			maybe = p; 		} 	} 	return (maybe); }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OLD_LOGIN */
end_comment

end_unit

