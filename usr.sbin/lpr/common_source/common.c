begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)common.c	8.5 (Berkeley) 4/28/95"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
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
file|<sys/time.h>
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
file|<dirent.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
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
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"lp.h"
end_include

begin_include
include|#
directive|include
file|"pathnames.h"
end_include

begin_comment
comment|/*  * Routines and data common to all the line printer functions.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|AF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* accounting file */
end_comment

begin_decl_stmt
name|long
name|BR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* baud rate if lp is a tty */
end_comment

begin_decl_stmt
name|char
modifier|*
name|CF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of cifplot filter (per job) */
end_comment

begin_decl_stmt
name|long
name|CT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TCP connection timeout */
end_comment

begin_decl_stmt
name|char
modifier|*
name|DF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of tex filter (per job) */
end_comment

begin_decl_stmt
name|long
name|DU
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* daeomon user-id */
end_comment

begin_decl_stmt
name|char
modifier|*
name|FF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* form feed string */
end_comment

begin_decl_stmt
name|char
modifier|*
name|GF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of graph(1G) filter (per job) */
end_comment

begin_decl_stmt
name|long
name|HL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print header last */
end_comment

begin_decl_stmt
name|char
modifier|*
name|IF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of input filter (created per job) */
end_comment

begin_decl_stmt
name|char
modifier|*
name|LF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* log file for error messages */
end_comment

begin_decl_stmt
name|char
modifier|*
name|LO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lock file name */
end_comment

begin_decl_stmt
name|char
modifier|*
name|LP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line printer device name */
end_comment

begin_decl_stmt
name|long
name|MC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum number of copies allowed */
end_comment

begin_decl_stmt
name|long
name|MX
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum number of blocks to copy */
end_comment

begin_decl_stmt
name|char
modifier|*
name|NF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of ditroff filter (per job) */
end_comment

begin_decl_stmt
name|char
modifier|*
name|OF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of output filter (created once) */
end_comment

begin_decl_stmt
name|char
modifier|*
name|PF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of vrast filter (per job) */
end_comment

begin_decl_stmt
name|long
name|PL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* page length */
end_comment

begin_decl_stmt
name|long
name|PW
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* page width */
end_comment

begin_decl_stmt
name|long
name|PX
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* page width in pixels */
end_comment

begin_decl_stmt
name|long
name|PY
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* page length in pixels */
end_comment

begin_decl_stmt
name|char
modifier|*
name|RF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of fortran text filter (per job) */
end_comment

begin_decl_stmt
name|char
modifier|*
name|RG
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* resricted group */
end_comment

begin_decl_stmt
name|char
modifier|*
name|RM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* remote machine name */
end_comment

begin_decl_stmt
name|char
modifier|*
name|RP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* remote printer name */
end_comment

begin_decl_stmt
name|long
name|RS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* restricted to those with local accounts */
end_comment

begin_decl_stmt
name|long
name|RW
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* open LP for reading and writing */
end_comment

begin_decl_stmt
name|long
name|SB
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* short banner instead of normal header */
end_comment

begin_decl_stmt
name|long
name|SC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* suppress multiple copies */
end_comment

begin_decl_stmt
name|char
modifier|*
name|SD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* spool directory */
end_comment

begin_decl_stmt
name|long
name|SF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* suppress FF on each print job */
end_comment

begin_decl_stmt
name|long
name|SH
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* suppress header page */
end_comment

begin_decl_stmt
name|char
modifier|*
name|ST
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* status file name */
end_comment

begin_decl_stmt
name|char
modifier|*
name|TF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of troff filter (per job) */
end_comment

begin_decl_stmt
name|char
modifier|*
name|TR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* trailer string to be output when Q empties */
end_comment

begin_decl_stmt
name|char
modifier|*
name|MS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mode set, a la stty */
end_comment

begin_decl_stmt
name|char
modifier|*
name|VF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of vplot filter (per job) */
end_comment

begin_decl_stmt
name|char
name|line
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|bp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer into printcap buffer. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* program name */
end_comment

begin_decl_stmt
name|char
modifier|*
name|printer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* printer name */
end_comment

begin_comment
comment|/* host machine name */
end_comment

begin_decl_stmt
name|char
name|host
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|from
init|=
name|host
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* client's machine name */
end_comment

begin_decl_stmt
name|int
name|remote
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if sending files to a remote host */
end_comment

begin_decl_stmt
name|char
modifier|*
name|printcapdb
index|[
literal|2
index|]
init|=
block|{
name|_PATH_PRINTCAP
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uid_t
name|uid
decl_stmt|,
name|euid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|compar
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|,
specifier|const
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Create a TCP connection to host "rhost" at port "rport".  * If rport == 0, then use the printer service port.  * Most of this code comes from rcmd.c.  */
end_comment

begin_function
name|int
name|getport
parameter_list|(
name|rhost
parameter_list|,
name|rport
parameter_list|)
name|char
modifier|*
name|rhost
decl_stmt|;
name|int
name|rport
decl_stmt|;
block|{
name|struct
name|hostent
modifier|*
name|hp
decl_stmt|;
name|struct
name|servent
modifier|*
name|sp
decl_stmt|;
name|struct
name|sockaddr_in
name|sin
decl_stmt|;
name|int
name|s
decl_stmt|,
name|timo
init|=
literal|1
decl_stmt|,
name|lport
init|=
name|IPPORT_RESERVED
operator|-
literal|1
decl_stmt|;
name|int
name|err
decl_stmt|;
comment|/* 	 * Get the host address and port number to connect to. 	 */
if|if
condition|(
name|rhost
operator|==
name|NULL
condition|)
name|fatal
argument_list|(
literal|"no remote host to connect to"
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|sin
argument_list|,
sizeof|sizeof
argument_list|(
name|sin
argument_list|)
argument_list|)
expr_stmt|;
name|sin
operator|.
name|sin_addr
operator|.
name|s_addr
operator|=
name|inet_addr
argument_list|(
name|rhost
argument_list|)
expr_stmt|;
if|if
condition|(
name|sin
operator|.
name|sin_addr
operator|.
name|s_addr
operator|!=
name|INADDR_NONE
condition|)
name|sin
operator|.
name|sin_family
operator|=
name|AF_INET
expr_stmt|;
else|else
block|{
name|hp
operator|=
name|gethostbyname
argument_list|(
name|rhost
argument_list|)
expr_stmt|;
if|if
condition|(
name|hp
operator|==
name|NULL
condition|)
name|fatal
argument_list|(
literal|"unknown host %s"
argument_list|,
name|rhost
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
name|hp
operator|->
name|h_addr
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|sin
operator|.
name|sin_addr
argument_list|,
name|hp
operator|->
name|h_length
argument_list|)
expr_stmt|;
name|sin
operator|.
name|sin_family
operator|=
name|hp
operator|->
name|h_addrtype
expr_stmt|;
block|}
if|if
condition|(
name|rport
operator|==
literal|0
condition|)
block|{
name|sp
operator|=
name|getservbyname
argument_list|(
literal|"printer"
argument_list|,
literal|"tcp"
argument_list|)
expr_stmt|;
if|if
condition|(
name|sp
operator|==
name|NULL
condition|)
name|fatal
argument_list|(
literal|"printer/tcp: unknown service"
argument_list|)
expr_stmt|;
name|sin
operator|.
name|sin_port
operator|=
name|sp
operator|->
name|s_port
expr_stmt|;
block|}
else|else
name|sin
operator|.
name|sin_port
operator|=
name|htons
argument_list|(
name|rport
argument_list|)
expr_stmt|;
comment|/* 	 * Try connecting to the server. 	 */
name|retry
label|:
name|seteuid
argument_list|(
name|euid
argument_list|)
expr_stmt|;
name|s
operator|=
name|rresvport
argument_list|(
operator|&
name|lport
argument_list|)
expr_stmt|;
name|seteuid
argument_list|(
name|uid
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|connect
argument_list|(
name|s
argument_list|,
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
operator|&
name|sin
argument_list|,
sizeof|sizeof
argument_list|(
name|sin
argument_list|)
argument_list|)
operator|<
literal|0
condition|)
block|{
name|err
operator|=
name|errno
expr_stmt|;
operator|(
name|void
operator|)
name|close
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|errno
operator|=
name|err
expr_stmt|;
if|if
condition|(
name|errno
operator|==
name|EADDRINUSE
condition|)
block|{
name|lport
operator|--
expr_stmt|;
goto|goto
name|retry
goto|;
block|}
if|if
condition|(
name|errno
operator|==
name|ECONNREFUSED
operator|&&
name|timo
operator|<=
literal|16
condition|)
block|{
name|sleep
argument_list|(
name|timo
argument_list|)
expr_stmt|;
name|timo
operator|*=
literal|2
expr_stmt|;
goto|goto
name|retry
goto|;
block|}
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
return|return
operator|(
name|s
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Getline reads a line from the control file cfp, removes tabs, converts  *  new-line to null and leaves it in line.  * Returns 0 at EOF or the number of characters read.  */
end_comment

begin_function
name|int
name|getline
parameter_list|(
name|cfp
parameter_list|)
name|FILE
modifier|*
name|cfp
decl_stmt|;
block|{
specifier|register
name|int
name|linel
init|=
literal|0
decl_stmt|;
specifier|register
name|char
modifier|*
name|lp
init|=
name|line
decl_stmt|;
specifier|register
name|c
expr_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
name|getc
argument_list|(
name|cfp
argument_list|)
operator|)
operator|!=
literal|'\n'
operator|&&
name|linel
operator|+
literal|1
operator|<
sizeof|sizeof
argument_list|(
name|line
argument_list|)
condition|)
block|{
if|if
condition|(
name|c
operator|==
name|EOF
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
name|c
operator|==
literal|'\t'
condition|)
block|{
do|do
block|{
operator|*
name|lp
operator|++
operator|=
literal|' '
expr_stmt|;
name|linel
operator|++
expr_stmt|;
block|}
do|while
condition|(
operator|(
name|linel
operator|&
literal|07
operator|)
operator|!=
literal|0
operator|&&
name|linel
operator|+
literal|1
operator|<
sizeof|sizeof
argument_list|(
name|line
argument_list|)
condition|)
do|;
continue|continue;
block|}
operator|*
name|lp
operator|++
operator|=
name|c
expr_stmt|;
name|linel
operator|++
expr_stmt|;
block|}
operator|*
name|lp
operator|++
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|linel
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Scan the current directory and make a list of daemon files sorted by  * creation time.  * Return the number of entries and a pointer to the list.  */
end_comment

begin_decl_stmt
name|int
name|getq
argument_list|(
name|namelist
argument_list|)
decl|struct
name|queue
modifier|*
argument_list|(
operator|*
name|namelist
index|[]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|dirent
modifier|*
name|d
decl_stmt|;
specifier|register
name|struct
name|queue
modifier|*
name|q
decl_stmt|,
modifier|*
modifier|*
name|queue
decl_stmt|;
specifier|register
name|int
name|nitems
decl_stmt|;
name|struct
name|stat
name|stbuf
decl_stmt|;
name|DIR
modifier|*
name|dirp
decl_stmt|;
name|int
name|arraysz
decl_stmt|;
name|seteuid
argument_list|(
name|euid
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|dirp
operator|=
name|opendir
argument_list|(
name|SD
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|fstat
argument_list|(
name|dirp
operator|->
name|dd_fd
argument_list|,
operator|&
name|stbuf
argument_list|)
operator|<
literal|0
condition|)
goto|goto
name|errdone
goto|;
name|seteuid
argument_list|(
name|uid
argument_list|)
expr_stmt|;
comment|/* 	 * Estimate the array size by taking the size of the directory file 	 * and dividing it by a multiple of the minimum size entry.  	 */
name|arraysz
operator|=
operator|(
name|stbuf
operator|.
name|st_size
operator|/
literal|24
operator|)
expr_stmt|;
name|queue
operator|=
operator|(
expr|struct
name|queue
operator|*
operator|*
operator|)
name|malloc
argument_list|(
name|arraysz
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|queue
operator|*
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|queue
operator|==
name|NULL
condition|)
goto|goto
name|errdone
goto|;
name|nitems
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|(
name|d
operator|=
name|readdir
argument_list|(
name|dirp
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|d_name
index|[
literal|0
index|]
operator|!=
literal|'c'
operator|||
name|d
operator|->
name|d_name
index|[
literal|1
index|]
operator|!=
literal|'f'
condition|)
continue|continue;
comment|/* daemon control files only */
name|seteuid
argument_list|(
name|euid
argument_list|)
expr_stmt|;
if|if
condition|(
name|stat
argument_list|(
name|d
operator|->
name|d_name
argument_list|,
operator|&
name|stbuf
argument_list|)
operator|<
literal|0
condition|)
continue|continue;
comment|/* Doesn't exist */
name|seteuid
argument_list|(
name|uid
argument_list|)
expr_stmt|;
name|q
operator|=
operator|(
expr|struct
name|queue
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|time_t
argument_list|)
operator|+
name|strlen
argument_list|(
name|d
operator|->
name|d_name
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|q
operator|==
name|NULL
condition|)
goto|goto
name|errdone
goto|;
name|q
operator|->
name|q_time
operator|=
name|stbuf
operator|.
name|st_mtime
expr_stmt|;
name|strcpy
argument_list|(
name|q
operator|->
name|q_name
argument_list|,
name|d
operator|->
name|d_name
argument_list|)
expr_stmt|;
comment|/* 		 * Check to make sure the array has space left and 		 * realloc the maximum size. 		 */
if|if
condition|(
operator|++
name|nitems
operator|>
name|arraysz
condition|)
block|{
name|arraysz
operator|*=
literal|2
expr_stmt|;
name|queue
operator|=
operator|(
expr|struct
name|queue
operator|*
operator|*
operator|)
name|realloc
argument_list|(
operator|(
name|char
operator|*
operator|)
name|queue
argument_list|,
name|arraysz
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|queue
operator|*
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|queue
operator|==
name|NULL
condition|)
goto|goto
name|errdone
goto|;
block|}
name|queue
index|[
name|nitems
operator|-
literal|1
index|]
operator|=
name|q
expr_stmt|;
block|}
name|closedir
argument_list|(
name|dirp
argument_list|)
expr_stmt|;
if|if
condition|(
name|nitems
condition|)
name|qsort
argument_list|(
name|queue
argument_list|,
name|nitems
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|queue
operator|*
argument_list|)
argument_list|,
name|compar
argument_list|)
expr_stmt|;
operator|*
name|namelist
operator|=
name|queue
expr_stmt|;
return|return
operator|(
name|nitems
operator|)
return|;
name|errdone
label|:
name|closedir
argument_list|(
name|dirp
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Compare modification times.  */
end_comment

begin_function
specifier|static
name|int
name|compar
parameter_list|(
name|p1
parameter_list|,
name|p2
parameter_list|)
specifier|const
name|void
modifier|*
name|p1
decl_stmt|,
decl|*
name|p2
decl_stmt|;
end_function

begin_block
block|{
if|if
condition|(
operator|(
operator|*
operator|(
expr|struct
name|queue
operator|*
operator|*
operator|)
name|p1
operator|)
operator|->
name|q_time
operator|<
operator|(
operator|*
operator|(
expr|struct
name|queue
operator|*
operator|*
operator|)
name|p2
operator|)
operator|->
name|q_time
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
operator|(
operator|*
operator|(
expr|struct
name|queue
operator|*
operator|*
operator|)
name|p1
operator|)
operator|->
name|q_time
operator|>
operator|(
operator|*
operator|(
expr|struct
name|queue
operator|*
operator|*
operator|)
name|p2
operator|)
operator|->
name|q_time
condition|)
return|return
operator|(
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Figure out whether the local machine is the same  * as the remote machine (RM) entry (if it exists).  */
end_comment

begin_function
name|char
modifier|*
name|checkremote
parameter_list|()
block|{
name|char
name|name
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
specifier|register
name|struct
name|hostent
modifier|*
name|hp
decl_stmt|;
specifier|static
name|char
name|errbuf
index|[
literal|128
index|]
decl_stmt|;
name|remote
operator|=
literal|0
expr_stmt|;
comment|/* assume printer is local */
if|if
condition|(
name|RM
operator|!=
name|NULL
condition|)
block|{
comment|/* get the official name of the local host */
name|gethostname
argument_list|(
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|name
argument_list|)
argument_list|)
expr_stmt|;
name|name
index|[
sizeof|sizeof
argument_list|(
name|name
argument_list|)
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
name|hp
operator|=
name|gethostbyname
argument_list|(
name|name
argument_list|)
expr_stmt|;
if|if
condition|(
name|hp
operator|==
operator|(
expr|struct
name|hostent
operator|*
operator|)
name|NULL
condition|)
block|{
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|errbuf
argument_list|,
sizeof|sizeof
argument_list|(
name|errbuf
argument_list|)
argument_list|,
literal|"unable to get official name for local machine %s"
argument_list|,
name|name
argument_list|)
expr_stmt|;
return|return
name|errbuf
return|;
block|}
else|else
block|{
operator|(
name|void
operator|)
name|strncpy
argument_list|(
name|name
argument_list|,
name|hp
operator|->
name|h_name
argument_list|,
sizeof|sizeof
argument_list|(
name|name
argument_list|)
argument_list|)
expr_stmt|;
name|name
index|[
sizeof|sizeof
argument_list|(
name|name
argument_list|)
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
comment|/* get the official name of RM */
name|hp
operator|=
name|gethostbyname
argument_list|(
name|RM
argument_list|)
expr_stmt|;
if|if
condition|(
name|hp
operator|==
operator|(
expr|struct
name|hostent
operator|*
operator|)
name|NULL
condition|)
block|{
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|errbuf
argument_list|,
sizeof|sizeof
argument_list|(
name|errbuf
argument_list|)
argument_list|,
literal|"unable to get official name for remote machine %s"
argument_list|,
name|RM
argument_list|)
expr_stmt|;
return|return
name|errbuf
return|;
block|}
comment|/* 		 * if the two hosts are not the same, 		 * then the printer must be remote. 		 */
if|if
condition|(
name|strcasecmp
argument_list|(
name|name
argument_list|,
name|hp
operator|->
name|h_name
argument_list|)
operator|!=
literal|0
condition|)
name|remote
operator|=
literal|1
expr_stmt|;
block|}
return|return
name|NULL
return|;
block|}
end_function

begin_comment
comment|/* sleep n milliseconds */
end_comment

begin_function
name|void
name|delay
parameter_list|(
name|n
parameter_list|)
block|{
name|struct
name|timeval
name|tdelay
decl_stmt|;
if|if
condition|(
name|n
operator|<=
literal|0
operator|||
name|n
operator|>
literal|10000
condition|)
name|fatal
argument_list|(
literal|"unreasonable delay period (%d)"
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|tdelay
operator|.
name|tv_sec
operator|=
name|n
operator|/
literal|1000
expr_stmt|;
name|tdelay
operator|.
name|tv_usec
operator|=
name|n
operator|*
literal|1000
operator|%
literal|1000000
expr_stmt|;
operator|(
name|void
operator|)
name|select
argument_list|(
literal|0
argument_list|,
operator|(
name|fd_set
operator|*
operator|)
literal|0
argument_list|,
operator|(
name|fd_set
operator|*
operator|)
literal|0
argument_list|,
operator|(
name|fd_set
operator|*
operator|)
literal|0
argument_list|,
operator|&
name|tdelay
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
ifdef|#
directive|ifdef
name|__STDC__
name|fatal
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
modifier|...
parameter_list|)
else|#
directive|else
function|fatal
parameter_list|(
name|msg
parameter_list|,
name|va_alist
parameter_list|)
name|char
modifier|*
name|msg
decl_stmt|;
function|va_dcl
endif|#
directive|endif
block|{
name|va_list
name|ap
decl_stmt|;
ifdef|#
directive|ifdef
name|__STDC__
name|va_start
argument_list|(
name|ap
argument_list|,
name|msg
argument_list|)
expr_stmt|;
else|#
directive|else
name|va_start
argument_list|(
name|ap
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|from
operator|!=
name|host
condition|)
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s: "
argument_list|,
name|host
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s: "
argument_list|,
name|name
argument_list|)
expr_stmt|;
if|if
condition|(
name|printer
condition|)
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s: "
argument_list|,
name|printer
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|vprintf
argument_list|(
name|msg
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

