begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1993-1997 by Darren Reed.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and due credit is given  * to the original author and the contributors.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<osreldate.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__SVR4
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
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
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|300000
end_if

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<arpa/nameser.h>
end_include

begin_include
include|#
directive|include
file|<resolv.h>
end_include

begin_include
include|#
directive|include
file|"ip_compat.h"
end_include

begin_include
include|#
directive|include
file|"ip_fil.h"
end_include

begin_include
include|#
directive|include
file|"ipf.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
specifier|const
name|char
name|sccsid
index|[]
init|=
literal|"@(#)ipf.c	1.23 6/5/96 (C) 1993-1995 Darren Reed"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"@(#)$Id: ipf.c,v 2.0.2.13.2.2 1997/11/06 21:23:36 darrenr Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|void
name|frsync
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|SOLARIS
end_if

begin_decl_stmt
specifier|static
name|void
name|blockunknown
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__SVR4
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|index
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|zerostats
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
decl|main
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|opts
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|fd
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|procfile
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|,
name|flushfilter
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
specifier|static
name|void
name|set_state
name|__P
argument_list|(
operator|(
name|u_int
operator|)
argument_list|)
decl_stmt|,
name|showstats
name|__P
argument_list|(
operator|(
name|friostat_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|packetlogon
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|,
name|swapactive
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|opendevice
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
specifier|static
name|void
name|closedevice
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|getline
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|size_t
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|ipfname
init|=
name|IPL_NAME
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
name|int
name|c
decl_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
name|getopt
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|"AdDEf:F:Il:noPrsUvyzZ"
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
block|{
switch|switch
condition|(
name|c
condition|)
block|{
case|case
literal|'A'
case|:
name|opts
operator|&=
operator|~
name|OPT_INACTIVE
expr_stmt|;
break|break;
case|case
literal|'E'
case|:
name|set_state
argument_list|(
operator|(
name|u_int
operator|)
literal|1
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'D'
case|:
name|set_state
argument_list|(
operator|(
name|u_int
operator|)
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'d'
case|:
name|opts
operator||=
name|OPT_DEBUG
expr_stmt|;
break|break;
case|case
literal|'f'
case|:
name|procfile
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|,
name|optarg
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'F'
case|:
name|flushfilter
argument_list|(
name|optarg
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'I'
case|:
name|opts
operator||=
name|OPT_INACTIVE
expr_stmt|;
break|break;
case|case
literal|'l'
case|:
name|packetlogon
argument_list|(
name|optarg
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'n'
case|:
name|opts
operator||=
name|OPT_DONOTHING
expr_stmt|;
break|break;
case|case
literal|'o'
case|:
name|opts
operator||=
name|OPT_OUTQUE
expr_stmt|;
break|break;
case|case
literal|'P'
case|:
name|ipfname
operator|=
name|IPL_AUTH
expr_stmt|;
break|break;
case|case
literal|'r'
case|:
name|opts
operator||=
name|OPT_REMOVE
expr_stmt|;
break|break;
case|case
literal|'s'
case|:
name|swapactive
argument_list|()
expr_stmt|;
break|break;
if|#
directive|if
name|SOLARIS
case|case
literal|'U'
case|:
name|blockunknown
argument_list|()
expr_stmt|;
break|break;
endif|#
directive|endif
case|case
literal|'v'
case|:
name|opts
operator||=
name|OPT_VERBOSE
expr_stmt|;
break|break;
case|case
literal|'y'
case|:
name|frsync
argument_list|()
expr_stmt|;
break|break;
case|case
literal|'z'
case|:
name|opts
operator||=
name|OPT_ZERORULEST
expr_stmt|;
break|break;
case|case
literal|'Z'
case|:
name|zerostats
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|fd
operator|!=
operator|-
literal|1
condition|)
operator|(
name|void
operator|)
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
block|}
end_function

begin_function
specifier|static
name|int
name|opendevice
parameter_list|(
name|ipfdev
parameter_list|)
name|char
modifier|*
name|ipfdev
decl_stmt|;
block|{
if|if
condition|(
name|opts
operator|&
name|OPT_DONOTHING
condition|)
return|return
operator|-
literal|2
return|;
if|if
condition|(
operator|!
name|ipfdev
condition|)
name|ipfdev
operator|=
name|ipfname
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|opts
operator|&
name|OPT_DONOTHING
operator|)
operator|&&
name|fd
operator|==
operator|-
literal|1
condition|)
if|if
condition|(
operator|(
name|fd
operator|=
name|open
argument_list|(
name|ipfdev
argument_list|,
name|O_RDWR
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
if|if
condition|(
operator|(
name|fd
operator|=
name|open
argument_list|(
name|ipfname
argument_list|,
name|O_RDONLY
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
name|perror
argument_list|(
literal|"open device"
argument_list|)
expr_stmt|;
return|return
name|fd
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|closedevice
parameter_list|()
block|{
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|fd
operator|=
operator|-
literal|1
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|set_state
parameter_list|(
name|enable
parameter_list|)
name|u_int
name|enable
decl_stmt|;
block|{
if|if
condition|(
name|opendevice
argument_list|(
name|ipfname
argument_list|)
operator|!=
operator|-
literal|2
condition|)
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|SIOCFRENB
argument_list|,
operator|&
name|enable
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|perror
argument_list|(
literal|"SIOCFRENB"
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|static
name|void
name|procfile
parameter_list|(
name|name
parameter_list|,
name|file
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|,
decl|*
name|file
decl_stmt|;
end_function

begin_block
block|{
name|FILE
modifier|*
name|fp
decl_stmt|;
name|char
name|line
index|[
literal|513
index|]
decl_stmt|,
modifier|*
name|s
decl_stmt|;
name|struct
name|frentry
modifier|*
name|fr
decl_stmt|;
name|u_int
name|add
init|=
name|SIOCADAFR
decl_stmt|,
name|del
init|=
name|SIOCRMAFR
decl_stmt|;
operator|(
name|void
operator|)
name|opendevice
argument_list|(
name|ipfname
argument_list|)
expr_stmt|;
if|if
condition|(
name|opts
operator|&
name|OPT_INACTIVE
condition|)
block|{
name|add
operator|=
name|SIOCADIFR
expr_stmt|;
name|del
operator|=
name|SIOCRMIFR
expr_stmt|;
block|}
if|if
condition|(
name|opts
operator|&
name|OPT_DEBUG
condition|)
name|printf
argument_list|(
literal|"add %x del %x\n"
argument_list|,
name|add
argument_list|,
name|del
argument_list|)
expr_stmt|;
name|initparse
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|file
argument_list|,
literal|"-"
argument_list|)
condition|)
name|fp
operator|=
name|stdin
expr_stmt|;
elseif|else
if|if
condition|(
operator|!
operator|(
name|fp
operator|=
name|fopen
argument_list|(
name|file
argument_list|,
literal|"r"
argument_list|)
operator|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: fopen(%s) failed: %s\n"
argument_list|,
name|name
argument_list|,
name|file
argument_list|,
name|STRERROR
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
name|getline
argument_list|(
name|line
argument_list|,
sizeof|sizeof
argument_list|(
name|line
argument_list|)
operator|-
literal|1
argument_list|,
name|fp
argument_list|)
condition|)
block|{
comment|/* 		 * treat both CR and LF as EOL 		 */
if|if
condition|(
operator|(
name|s
operator|=
name|index
argument_list|(
name|line
argument_list|,
literal|'\n'
argument_list|)
operator|)
condition|)
operator|*
name|s
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
operator|(
name|s
operator|=
name|index
argument_list|(
name|line
argument_list|,
literal|'\r'
argument_list|)
operator|)
condition|)
operator|*
name|s
operator|=
literal|'\0'
expr_stmt|;
comment|/* 		 * # is comment marker, everything after is a ignored 		 */
if|if
condition|(
operator|(
name|s
operator|=
name|index
argument_list|(
name|line
argument_list|,
literal|'#'
argument_list|)
operator|)
condition|)
operator|*
name|s
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
operator|!
operator|*
name|line
condition|)
continue|continue;
if|if
condition|(
name|opts
operator|&
name|OPT_VERBOSE
condition|)
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"[%s]\n"
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|fr
operator|=
name|parse
argument_list|(
name|line
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
if|if
condition|(
name|fr
condition|)
block|{
if|if
condition|(
name|opts
operator|&
name|OPT_ZERORULEST
condition|)
name|add
operator|=
name|SIOCZRLST
expr_stmt|;
elseif|else
if|if
condition|(
name|opts
operator|&
name|OPT_INACTIVE
condition|)
name|add
operator|=
operator|(
name|u_int
operator|)
name|fr
operator|->
name|fr_hits
condition|?
name|SIOCINIFR
else|:
name|SIOCADIFR
expr_stmt|;
else|else
name|add
operator|=
operator|(
name|u_int
operator|)
name|fr
operator|->
name|fr_hits
condition|?
name|SIOCINAFR
else|:
name|SIOCADAFR
expr_stmt|;
if|if
condition|(
name|fr
operator|->
name|fr_hits
condition|)
name|fr
operator|->
name|fr_hits
operator|--
expr_stmt|;
if|if
condition|(
name|fr
operator|&&
operator|(
name|opts
operator|&
name|OPT_VERBOSE
operator|)
condition|)
name|printfr
argument_list|(
name|fr
argument_list|)
expr_stmt|;
if|if
condition|(
name|fr
operator|&&
operator|(
name|opts
operator|&
name|OPT_OUTQUE
operator|)
condition|)
name|fr
operator|->
name|fr_flags
operator||=
name|FR_OUTQUE
expr_stmt|;
if|if
condition|(
name|opts
operator|&
name|OPT_DEBUG
condition|)
name|binprint
argument_list|(
name|fr
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|opts
operator|&
name|OPT_ZERORULEST
operator|)
operator|&&
operator|!
operator|(
name|opts
operator|&
name|OPT_DONOTHING
operator|)
condition|)
block|{
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|add
argument_list|,
name|fr
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|perror
argument_list|(
literal|"ioctl(SIOCZRLST)"
argument_list|)
expr_stmt|;
else|else
block|{
ifdef|#
directive|ifdef
name|USE_QUAD_T
name|printf
argument_list|(
literal|"hits %qd bytes %qd "
argument_list|,
else|#
directive|else
argument|printf(
literal|"hits %ld bytes %ld "
argument|,
endif|#
directive|endif
argument|fr->fr_hits, fr->fr_bytes); 					printfr(fr); 				} 			} else if ((opts& OPT_REMOVE)&& 				   !(opts& OPT_DONOTHING)) { 				if (ioctl(fd, del, fr) == -
literal|1
argument|) 					perror(
literal|"ioctl(SIOCDELFR)"
argument|); 			} else if (!(opts& OPT_DONOTHING)) { 				if (ioctl(fd, add, fr) == -
literal|1
argument|) 					perror(
literal|"ioctl(SIOCADDFR)"
argument|); 			} 		} 	} 	(void)fclose(fp); }
comment|/*  * Similar to fgets(3) but can handle '\\'  */
argument|static char *getline(str, size, file) register char	*str; size_t	size; FILE	*file; { 	register char *p; 	register int len;  	do { 		for (p = str; ; p += strlen(p) -
literal|1
argument|) { 			if (!fgets(p, size, file)) 				return(NULL); 			len = strlen(p); 			p[len -
literal|1
argument|] =
literal|'\0'
argument|; 			if (p[len -
literal|1
argument|] !=
literal|'\\'
argument|) 				break; 			size -= len; 		} 	} while (*str ==
literal|'\0'
argument||| *str ==
literal|'\n'
argument|); 	return(str); }   static void packetlogon(opt) char	*opt; { 	int	err
argument_list|,
argument|flag =
literal|0
argument|;  	if ((opts& (OPT_DONOTHING|OPT_VERBOSE)) == OPT_VERBOSE) { 		if ((err = ioctl(fd, SIOCGETFF,&flag))) 			perror(
literal|"ioctl(SIOCGETFF)"
argument|);  		printf(
literal|"log flag is currently %#x\n"
argument|, flag); 	}  	flag&= ~(FF_LOGPASS|FF_LOGNOMATCH|FF_LOGBLOCK);  	if (index(opt,
literal|'p'
argument|)) { 		flag |= FF_LOGPASS; 		if (opts& OPT_VERBOSE) 			printf(
literal|"set log flag: pass\n"
argument|); 	} 	if (index(opt,
literal|'m'
argument|)&& (*opt ==
literal|'n'
argument||| *opt ==
literal|'N'
argument|)) { 		flag |= FF_LOGNOMATCH; 		if (opts& OPT_VERBOSE) 			printf(
literal|"set log flag: nomatch\n"
argument|); 	} 	if (index(opt,
literal|'b'
argument|) || index(opt,
literal|'d'
argument|)) { 		flag |= FF_LOGBLOCK; 		if (opts& OPT_VERBOSE) 			printf(
literal|"set log flag: block\n"
argument|); 	}  	if (opendevice(ipfname) != -
literal|2
argument|&& (err = ioctl(fd, SIOCSETFF,&flag))) 		perror(
literal|"ioctl(SIOCSETFF)"
argument|);  	if ((opts& (OPT_DONOTHING|OPT_VERBOSE)) == OPT_VERBOSE) { 		if ((err = ioctl(fd, SIOCGETFF,&flag))) 			perror(
literal|"ioctl(SIOCGETFF)"
argument|);  		printf(
literal|"log flag is now %#x\n"
argument|, flag); 	} }   static	void	flushfilter(arg) char	*arg; { 	int	fl =
literal|0
argument_list|,
argument|rem;  	if (!arg || !*arg) 		return; 	if (!strcmp(arg,
literal|"s"
argument|) || !strcmp(arg,
literal|"S"
argument|)) { 		if (*arg ==
literal|'S'
argument|) 			fl =
literal|0
argument|; 		else 			fl =
literal|1
argument|; 		rem = fl;  		closedevice(); 		if (opendevice(IPL_STATE) != -
literal|2
argument|&& 		    ioctl(fd, SIOCIPFFL,&fl) == -
literal|1
argument|) 			perror(
literal|"ioctl(SIOCIPFFL)"
argument|); 		if ((opts& (OPT_DONOTHING|OPT_VERBOSE)) == OPT_VERBOSE) { 			printf(
literal|"remove flags %s (%d)\n"
argument|, arg, rem); 			printf(
literal|"removed %d filter rules\n"
argument|, fl); 		} 		closedevice(); 		return; 	} 	if (strchr(arg,
literal|'i'
argument|) || strchr(arg,
literal|'I'
argument|)) 		fl = FR_INQUE; 	if (strchr(arg,
literal|'o'
argument|) || strchr(arg,
literal|'O'
argument|)) 		fl = FR_OUTQUE; 	if (strchr(arg,
literal|'a'
argument|) || strchr(arg,
literal|'A'
argument|)) 		fl = FR_OUTQUE|FR_INQUE; 	fl |= (opts& FR_INACTIVE); 	rem = fl;  	if (opendevice(ipfname) != -
literal|2
argument|&& ioctl(fd, SIOCIPFFL,&fl) == -
literal|1
argument|) 		perror(
literal|"ioctl(SIOCIPFFL)"
argument|); 	if ((opts& (OPT_DONOTHING|OPT_VERBOSE)) == OPT_VERBOSE) { 		printf(
literal|"remove flags %s%s (%d)\n"
argument|, (rem& FR_INQUE) ?
literal|"I"
argument|:
literal|""
argument|, 			(rem& FR_OUTQUE) ?
literal|"O"
argument|:
literal|""
argument|, rem); 		printf(
literal|"removed %d filter rules\n"
argument|, fl); 	} 	return; }   static void swapactive() { 	int in =
literal|2
argument|;  	if (opendevice(ipfname) != -
literal|2
argument|&& ioctl(fd, SIOCSWAPA,&in) == -
literal|1
argument|) 		perror(
literal|"ioctl(SIOCSWAPA)"
argument|); 	else 		printf(
literal|"Set %d now inactive\n"
argument|, in); }   static void frsync() { 	if (opendevice(ipfname) != -
literal|2
argument|&& ioctl(fd, SIOCFRSYN,
literal|0
argument|) == -
literal|1
argument|) 		perror(
literal|"SIOCFRSYN"
argument|); 	else 		printf(
literal|"filter sync'd\n"
argument|); }   void zerostats() { 	friostat_t	fio;  	if (opendevice(ipfname) != -
literal|2
argument|) { 		if (ioctl(fd, SIOCFRZST,&fio) == -
literal|1
argument|) { 			perror(
literal|"ioctl(SIOCFRZST)"
argument|); 			exit(-
literal|1
argument|); 		} 		showstats(&fio); 	}  }
comment|/*  * read the kernel stats for packets blocked and passed  */
argument|static void showstats(fp) friostat_t	*fp; {
if|#
directive|if
name|SOLARIS
argument|printf(
literal|"dropped packets:\tin %lu\tout %lu\n"
argument|, 			fp->f_st[
literal|0
argument|].fr_drop, fp->f_st[
literal|1
argument|].fr_drop); 	printf(
literal|"non-ip packets:\t\tin %lu\tout %lu\n"
argument|, 			fp->f_st[
literal|0
argument|].fr_notip, fp->f_st[
literal|1
argument|].fr_notip); 	printf(
literal|"   bad packets:\t\tin %lu\tout %lu\n"
argument|, 			fp->f_st[
literal|0
argument|].fr_bad, fp->f_st[
literal|1
argument|].fr_bad);
endif|#
directive|endif
argument|printf(
literal|" input packets:\t\tblocked %lu passed %lu nomatch %lu"
argument|, 			fp->f_st[
literal|0
argument|].fr_block, fp->f_st[
literal|0
argument|].fr_pass, 			fp->f_st[
literal|0
argument|].fr_nom); 	printf(
literal|" counted %lu\n"
argument|, fp->f_st[
literal|0
argument|].fr_acct); 	printf(
literal|"output packets:\t\tblocked %lu passed %lu nomatch %lu"
argument|, 			fp->f_st[
literal|1
argument|].fr_block, fp->f_st[
literal|1
argument|].fr_pass, 			fp->f_st[
literal|1
argument|].fr_nom); 	printf(
literal|" counted %lu\n"
argument|, fp->f_st[
literal|0
argument|].fr_acct); 	printf(
literal|" input packets logged:\tblocked %lu passed %lu\n"
argument|, 			fp->f_st[
literal|0
argument|].fr_bpkl, fp->f_st[
literal|0
argument|].fr_ppkl); 	printf(
literal|"output packets logged:\tblocked %lu passed %lu\n"
argument|, 			fp->f_st[
literal|1
argument|].fr_bpkl, fp->f_st[
literal|1
argument|].fr_ppkl); 	printf(
literal|" packets logged:\tinput %lu-%lu output %lu-%lu\n"
argument|, 			fp->f_st[
literal|0
argument|].fr_pkl, fp->f_st[
literal|0
argument|].fr_skip, 			fp->f_st[
literal|1
argument|].fr_pkl, fp->f_st[
literal|1
argument|].fr_skip); }
if|#
directive|if
name|SOLARIS
argument|static void blockunknown() { 	int	flag;  	if (opendevice(ipfname) == -
literal|1
argument|) 		return;  	if ((opts& (OPT_DONOTHING|OPT_VERBOSE)) == OPT_VERBOSE) { 		if (ioctl(fd, SIOCGETFF,&flag)) 			perror(
literal|"ioctl(SIOCGETFF)"
argument|);  		printf(
literal|"log flag is currently %#x\n"
argument|, flag); 	}  	flag ^= FF_BLOCKNONIP;  	if (opendevice(ipfname) != -
literal|2
argument|&& ioctl(fd, SIOCSETFF,&flag)) 		perror(
literal|"ioctl(SIOCSETFF)"
argument|);  	if ((opts& (OPT_DONOTHING|OPT_VERBOSE)) == OPT_VERBOSE) { 		if (ioctl(fd, SIOCGETFF,&flag)) 			perror(
literal|"ioctl(SIOCGETFF)"
argument|);  		printf(
literal|"log flag is now %#x\n"
argument|, flag); 	} }
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

