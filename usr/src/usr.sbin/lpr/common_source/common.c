begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)common.c	5.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * Routines and data common to all the line printer functions.  */
end_comment

begin_include
include|#
directive|include
file|"lp.h"
end_include

begin_decl_stmt
name|int
name|DU
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* daeomon user-id */
end_comment

begin_decl_stmt
name|int
name|MX
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum number of blocks to copy */
end_comment

begin_decl_stmt
name|int
name|MC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum number of copies allowed */
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
name|ST
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* status file name */
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
name|char
modifier|*
name|AF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* accounting file */
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
name|OF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of output filter (created once) */
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
name|RF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of fortran text filter (per job) */
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
name|NF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of ditroff filter (per job) */
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
name|char
modifier|*
name|GF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of graph(1G) filter (per job) */
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
modifier|*
name|CF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of cifplot filter (per job) */
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
name|TR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* trailer string to be output when Q empties */
end_comment

begin_decl_stmt
name|short
name|SC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* suppress multiple copies */
end_comment

begin_decl_stmt
name|short
name|SF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* suppress FF on each print job */
end_comment

begin_decl_stmt
name|short
name|SH
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* suppress header page */
end_comment

begin_decl_stmt
name|short
name|SB
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* short banner instead of normal header */
end_comment

begin_decl_stmt
name|short
name|HL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print header last */
end_comment

begin_decl_stmt
name|short
name|RW
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* open LP for reading and writing */
end_comment

begin_decl_stmt
name|short
name|PW
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* page width */
end_comment

begin_decl_stmt
name|short
name|PL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* page length */
end_comment

begin_decl_stmt
name|short
name|PX
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* page width in pixels */
end_comment

begin_decl_stmt
name|short
name|PY
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* page length in pixels */
end_comment

begin_decl_stmt
name|short
name|BR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* baud rate if lp is a tty */
end_comment

begin_decl_stmt
name|int
name|FC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flags to clear if lp is a tty */
end_comment

begin_decl_stmt
name|int
name|FS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flags to set if lp is a tty */
end_comment

begin_decl_stmt
name|int
name|XC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flags to clear for local mode */
end_comment

begin_decl_stmt
name|int
name|XS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flags to set for local mode */
end_comment

begin_decl_stmt
name|short
name|RS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* restricted to those with local accounts */
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
name|pbuf
index|[
name|BUFSIZ
operator|/
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer for printcap strings */
end_comment

begin_decl_stmt
name|char
modifier|*
name|bp
init|=
name|pbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer into pbuf for pgetent() */
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

begin_decl_stmt
name|char
name|host
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* host machine name */
end_comment

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

begin_comment
comment|/*  * Create a connection to the remote printer server.  * Most of this code comes from rcmd.c.  */
end_comment

begin_macro
name|getport
argument_list|(
argument|rhost
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|rhost
decl_stmt|;
end_decl_stmt

begin_block
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
name|sin
operator|.
name|sin_port
operator|=
name|sp
operator|->
name|s_port
expr_stmt|;
comment|/* 	 * Try connecting to the server. 	 */
name|retry
label|:
name|s
operator|=
name|rresvport
argument_list|(
operator|&
name|lport
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
name|caddr_t
operator|)
operator|&
name|sin
argument_list|,
sizeof|sizeof
argument_list|(
name|sin
argument_list|)
argument_list|,
literal|0
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
end_block

begin_macro
name|rresvport
argument_list|(
argument|alport
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|alport
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|sockaddr_in
name|sin
decl_stmt|;
name|int
name|s
decl_stmt|;
name|sin
operator|.
name|sin_family
operator|=
name|AF_INET
expr_stmt|;
name|sin
operator|.
name|sin_addr
operator|.
name|s_addr
operator|=
literal|0
expr_stmt|;
name|s
operator|=
name|socket
argument_list|(
name|AF_INET
argument_list|,
name|SOCK_STREAM
argument_list|,
literal|0
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
for|for
control|(
init|;
operator|*
name|alport
operator|>
name|IPPORT_RESERVED
operator|/
literal|2
condition|;
operator|(
operator|*
name|alport
operator|)
operator|--
control|)
block|{
name|sin
operator|.
name|sin_port
operator|=
name|htons
argument_list|(
operator|(
name|u_short
operator|)
operator|*
name|alport
argument_list|)
expr_stmt|;
if|if
condition|(
name|bind
argument_list|(
name|s
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|sin
argument_list|,
sizeof|sizeof
argument_list|(
name|sin
argument_list|)
argument_list|,
literal|0
argument_list|)
operator|>=
literal|0
condition|)
return|return
operator|(
name|s
operator|)
return|;
if|if
condition|(
name|errno
operator|!=
name|EADDRINUSE
operator|&&
name|errno
operator|!=
name|EADDRNOTAVAIL
condition|)
break|break;
block|}
operator|(
name|void
operator|)
name|close
argument_list|(
name|s
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
comment|/*  * Getline reads a line from the control file cfp, removes tabs, converts  *  new-line to null and leaves it in line.  * Returns 0 at EOF or the number of characters read.  */
end_comment

begin_macro
name|getline
argument_list|(
argument|cfp
argument_list|)
end_macro

begin_decl_stmt
name|FILE
modifier|*
name|cfp
decl_stmt|;
end_decl_stmt

begin_block
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
end_block

begin_comment
comment|/*  * Scan the current directory and make a list of daemon files sorted by  * creation time.  * Return the number of entries and a pointer to the list.  */
end_comment

begin_macro
name|getq
argument_list|(
argument|namelist
argument_list|)
end_macro

begin_decl_stmt
name|struct
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
name|direct
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
name|int
name|arraysz
decl_stmt|,
name|compar
argument_list|()
decl_stmt|;
name|DIR
modifier|*
name|dirp
decl_stmt|;
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
operator|(
name|stbuf
operator|.
name|st_size
operator|/
literal|12
operator|)
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

begin_expr_stmt
specifier|static
name|compar
argument_list|(
name|p1
argument_list|,
name|p2
argument_list|)
specifier|register
expr|struct
name|queue
operator|*
operator|*
name|p1
operator|,
operator|*
operator|*
name|p2
expr_stmt|;
end_expr_stmt

begin_block
block|{
if|if
condition|(
operator|(
operator|*
name|p1
operator|)
operator|->
name|q_time
operator|<
operator|(
operator|*
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
name|p1
operator|)
operator|->
name|q_time
operator|>
operator|(
operator|*
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
comment|/*VARARGS1*/
end_comment

begin_macro
name|fatal
argument_list|(
argument|msg
argument_list|,
argument|a1
argument_list|,
argument|a2
argument_list|,
argument|a3
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|msg
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|from
operator|!=
name|host
condition|)
name|printf
argument_list|(
literal|"%s: "
argument_list|,
name|host
argument_list|)
expr_stmt|;
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
name|printf
argument_list|(
literal|"%s: "
argument_list|,
name|printer
argument_list|)
expr_stmt|;
name|printf
argument_list|(
name|msg
argument_list|,
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|)
expr_stmt|;
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
end_block

end_unit

