begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This software is Copyright (c) 1986 by Rick Adams.  *  * Permission is hereby granted to copy, reproduce, redistribute or  * otherwise use this software as long as: there is no monetary  * profit gained specifically from the use or reproduction or this  * software, it is not sold, rented, traded or otherwise marketed, and  * this copyright notice is included prominently in any copy  * made.  *  * The author make no claims as to the fitness or correctness of  * this software for any use whatsoever, and it is provided as is.   * Any use of this software is at the user's own risk.  *  * expire - expire daemon runs around and nails all articles that  *		 have expired.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SCCSID
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|SccsId
init|=
literal|"@(#)expire.c	2.43	3/19/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SCCSID */
end_comment

begin_include
include|#
directive|include
file|"params.h"
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD4_2
argument_list|)
operator|||
name|defined
argument_list|(
name|BSD4_1C
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"ndir.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
modifier|*
name|Progname
init|=
literal|"expire"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used by xerror to identify failing program */
end_comment

begin_comment
comment|/*	Number of array entries to allocate at a time.	*/
end_comment

begin_define
define|#
directive|define
name|SPACE_INCREMENT
value|1000
end_define

begin_struct
struct|struct
name|expdata
block|{
name|char
modifier|*
name|e_name
decl_stmt|;
name|long
name|e_min
decl_stmt|,
name|e_max
decl_stmt|;
name|time_t
name|e_droptime
decl_stmt|,
name|e_expiretime
decl_stmt|;
name|char
name|e_ignorexp
decl_stmt|;
name|char
name|e_doarchive
decl_stmt|;
name|char
name|e_doexpire
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|NARTFILE
index|[
name|BUFLEN
index|]
decl_stmt|,
name|OARTFILE
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|PAGFILE
index|[
name|BUFLEN
index|]
decl_stmt|,
name|DIRFILE
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|NACTIVE
index|[
name|BUFLEN
index|]
decl_stmt|,
name|OACTIVE
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|recdate
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|rectime
decl_stmt|,
name|exptime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|OLDNEWS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|verbose
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ignorexp
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|doarchive
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nohistory
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dorebuild
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|usepost
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|frflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|updateactive
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|baduser
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|filename
index|[]
decl_stmt|,
name|nbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This code uses realloc to get more of the multhist array.  */
end_comment

begin_struct
struct|struct
name|multhist
block|{
name|char
modifier|*
name|mh_ident
decl_stmt|;
name|char
modifier|*
name|mh_file
decl_stmt|;
block|}
modifier|*
name|multhist
struct|;
end_struct

begin_decl_stmt
name|unsigned
name|int
name|mh_size
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|calloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|realloc
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|dptr
decl_stmt|;
name|int
name|dsize
decl_stmt|;
block|}
name|datum
typedef|;
end_typedef

begin_decl_stmt
name|long
name|expincr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|dropincr
decl_stmt|;
end_decl_stmt

begin_function_decl
name|long
name|atol
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|time_t
name|cgtdate
argument_list|()
decl_stmt|,
name|time
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|FILE
modifier|*
name|popen
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|passwd
modifier|*
name|pw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|group
modifier|*
name|gp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|arpat
index|[
name|LBUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|arpatlen
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|ngpat
index|[
name|LBUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ngpatlen
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|afline
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|grpsleft
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|hbuf
name|h
decl_stmt|;
end_decl_stmt

begin_function
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
modifier|*
name|argv
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|p1
decl_stmt|,
modifier|*
name|p2
decl_stmt|,
modifier|*
name|p3
decl_stmt|;
specifier|register
name|time_t
name|now
decl_stmt|,
name|newtime
decl_stmt|;
specifier|register
name|FILE
modifier|*
name|fp
init|=
name|NULL
decl_stmt|;
name|FILE
modifier|*
name|ohfd
decl_stmt|,
modifier|*
name|nhfd
decl_stmt|;
name|DIR
modifier|*
name|ngdirp
init|=
name|NULL
decl_stmt|;
specifier|static
name|struct
name|direct
modifier|*
name|ngdir
decl_stmt|;
name|char
name|fn
index|[
name|BUFLEN
index|]
decl_stmt|;
name|int
name|i
decl_stmt|;
ifndef|#
directive|ifndef
name|DBM
name|char
modifier|*
name|ptr
decl_stmt|,
name|chr
decl_stmt|;
name|FILE
modifier|*
name|subfd
index|[
literal|10
index|]
decl_stmt|;
name|char
modifier|*
name|histfile
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|/* !DBM */
name|pathinit
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|umask
argument_list|(
name|N_UMASK
argument_list|)
expr_stmt|;
comment|/* 	 * Try to run as NEWSUSR/NEWSGRP 	 */
if|if
condition|(
operator|(
name|pw
operator|=
name|getpwnam
argument_list|(
name|NEWSUSR
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|xerror
argument_list|(
literal|"Cannot get NEWSUSR pw entry"
argument_list|)
expr_stmt|;
name|uid
operator|=
name|pw
operator|->
name|pw_uid
expr_stmt|;
if|if
condition|(
operator|(
name|gp
operator|=
name|getgrnam
argument_list|(
name|NEWSGRP
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|xerror
argument_list|(
literal|"Cannot get NEWSGRP gr entry"
argument_list|)
expr_stmt|;
name|gid
operator|=
name|gp
operator|->
name|gr_gid
expr_stmt|;
operator|(
name|void
operator|)
name|setgid
argument_list|(
name|gid
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|setuid
argument_list|(
name|uid
argument_list|)
expr_stmt|;
name|expincr
operator|=
name|DFLTEXP
expr_stmt|;
name|dropincr
operator|=
name|HISTEXP
expr_stmt|;
name|ngpat
index|[
literal|0
index|]
operator|=
literal|','
expr_stmt|;
name|arpat
index|[
literal|0
index|]
operator|=
literal|','
expr_stmt|;
while|while
condition|(
name|argc
operator|>
literal|1
condition|)
block|{
switch|switch
condition|(
name|argv
index|[
literal|1
index|]
index|[
literal|1
index|]
condition|)
block|{
case|case
literal|'v'
case|:
if|if
condition|(
name|isdigit
argument_list|(
name|argv
index|[
literal|1
index|]
index|[
literal|2
index|]
argument_list|)
condition|)
name|verbose
operator|=
name|argv
index|[
literal|1
index|]
index|[
literal|2
index|]
operator|-
literal|'0'
expr_stmt|;
elseif|else
if|if
condition|(
name|argc
operator|>
literal|2
operator|&&
name|argv
index|[
literal|2
index|]
index|[
literal|0
index|]
operator|!=
literal|'-'
condition|)
block|{
name|argv
operator|++
expr_stmt|;
name|argc
operator|--
expr_stmt|;
name|verbose
operator|=
name|atoi
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
else|else
name|verbose
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|verbose
operator|<
literal|3
condition|)
name|setbuf
argument_list|(
name|stdout
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'e'
case|:
comment|/* Use this as default expiration time */
if|if
condition|(
name|argc
operator|>
literal|2
operator|&&
name|argv
index|[
literal|2
index|]
index|[
literal|0
index|]
operator|!=
literal|'-'
condition|)
block|{
name|argv
operator|++
expr_stmt|;
name|argc
operator|--
expr_stmt|;
name|expincr
operator|=
name|atol
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|)
operator|*
name|DAYS
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|isdigit
argument_list|(
name|argv
index|[
literal|1
index|]
index|[
literal|2
index|]
argument_list|)
condition|)
name|expincr
operator|=
name|atol
argument_list|(
operator|&
name|argv
index|[
literal|1
index|]
index|[
literal|2
index|]
argument_list|)
operator|*
name|DAYS
expr_stmt|;
break|break;
case|case
literal|'E'
case|:
comment|/* Use this as default forget time */
if|if
condition|(
name|argc
operator|>
literal|2
operator|&&
name|argv
index|[
literal|2
index|]
index|[
literal|0
index|]
operator|!=
literal|'-'
condition|)
block|{
name|argv
operator|++
expr_stmt|;
name|argc
operator|--
expr_stmt|;
name|dropincr
operator|=
name|atol
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|)
operator|*
name|DAYS
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|isdigit
argument_list|(
name|argv
index|[
literal|1
index|]
index|[
literal|2
index|]
argument_list|)
condition|)
name|dropincr
operator|=
name|atol
argument_list|(
operator|&
name|argv
index|[
literal|1
index|]
index|[
literal|2
index|]
argument_list|)
operator|*
name|DAYS
expr_stmt|;
if|if
condition|(
name|dropincr
operator|<
name|expincr
condition|)
block|{
name|dropincr
operator|=
name|HISTEXP
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"History expiration time< article expiration time. Default used.\n"
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
literal|'I'
case|:
comment|/* Ignore any existing expiration date */
name|ignorexp
operator|=
literal|2
expr_stmt|;
break|break;
case|case
literal|'i'
case|:
comment|/* Ignore any existing expiration date */
name|ignorexp
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'n'
case|:
if|if
condition|(
name|argc
operator|>
literal|2
condition|)
block|{
name|argv
operator|++
expr_stmt|;
name|argc
operator|--
expr_stmt|;
while|while
condition|(
name|argc
operator|>
literal|1
operator|&&
name|argv
index|[
literal|1
index|]
index|[
literal|0
index|]
operator|!=
literal|'-'
condition|)
block|{
name|int
name|argvlen
decl_stmt|;
name|argvlen
operator|=
name|strlen
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|ngpatlen
operator|+
name|argvlen
operator|+
literal|2
operator|>
sizeof|sizeof
argument_list|(
name|ngpat
argument_list|)
condition|)
block|{
name|xerror
argument_list|(
literal|"Too many groups specified for -n\n"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|ngpat
index|[
name|ngpatlen
index|]
operator|==
literal|'\0'
condition|)
block|{
name|ngpat
index|[
name|ngpatlen
operator|++
index|]
operator|=
literal|','
expr_stmt|;
name|ngpat
index|[
name|ngpatlen
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
name|strcpy
argument_list|(
operator|&
name|ngpat
index|[
name|ngpatlen
index|]
argument_list|,
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|ngpatlen
operator|+=
name|argvlen
expr_stmt|;
name|argv
operator|++
expr_stmt|;
name|argc
operator|--
expr_stmt|;
block|}
name|argv
operator|--
expr_stmt|;
name|argc
operator|++
expr_stmt|;
block|}
break|break;
case|case
literal|'a'
case|:
comment|/* archive expired articles */
if|if
condition|(
name|access
argument_list|(
name|OLDNEWS
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
block|{
name|perror
argument_list|(
name|OLDNEWS
argument_list|)
expr_stmt|;
name|xerror
argument_list|(
literal|"No archiving possible\n"
argument_list|)
expr_stmt|;
block|}
name|doarchive
operator|++
expr_stmt|;
if|if
condition|(
name|argc
operator|>
literal|2
condition|)
block|{
name|argv
operator|++
expr_stmt|;
name|argc
operator|--
expr_stmt|;
while|while
condition|(
name|argc
operator|>
literal|1
operator|&&
name|argv
index|[
literal|1
index|]
index|[
literal|0
index|]
operator|!=
literal|'-'
condition|)
block|{
name|int
name|argvlen
decl_stmt|;
name|argvlen
operator|=
name|strlen
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|arpatlen
operator|+
name|argvlen
operator|+
literal|2
operator|>
sizeof|sizeof
argument_list|(
name|arpat
argument_list|)
condition|)
block|{
name|xerror
argument_list|(
literal|"Too many groups specified for -a\n"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|arpat
index|[
name|arpatlen
index|]
operator|==
literal|'\0'
condition|)
block|{
name|arpat
index|[
name|arpatlen
operator|++
index|]
operator|=
literal|','
expr_stmt|;
name|arpat
index|[
name|arpatlen
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
name|strcpy
argument_list|(
operator|&
name|arpat
index|[
name|arpatlen
index|]
argument_list|,
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|arpatlen
operator|+=
name|argvlen
expr_stmt|;
name|argv
operator|++
expr_stmt|;
name|argc
operator|--
expr_stmt|;
block|}
name|argv
operator|--
expr_stmt|;
name|argc
operator|++
expr_stmt|;
block|}
break|break;
case|case
literal|'h'
case|:
comment|/* ignore history */
name|nohistory
operator|++
expr_stmt|;
break|break;
case|case
literal|'r'
case|:
comment|/* rebuild history file */
name|dorebuild
operator|++
expr_stmt|;
name|nohistory
operator|++
expr_stmt|;
break|break;
case|case
literal|'p'
case|:
name|usepost
operator|++
expr_stmt|;
break|break;
case|case
literal|'f'
case|:
name|frflag
operator|++
expr_stmt|;
if|if
condition|(
name|argc
operator|>
literal|2
condition|)
block|{
name|strcpy
argument_list|(
name|baduser
argument_list|,
name|argv
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
name|argv
operator|++
expr_stmt|;
name|argc
operator|--
expr_stmt|;
block|}
break|break;
case|case
literal|'u'
case|:
name|updateactive
operator|++
expr_stmt|;
break|break;
default|default:
name|printf
argument_list|(
literal|"Usage: expire [ -v [level] ] [-e days ] [-i] [-a] [-r] [-h] [-p] [-u] [-f username] [-n newsgroups]\n"
argument_list|)
expr_stmt|;
name|xxit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|argc
operator|--
expr_stmt|;
name|argv
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|ngpat
index|[
literal|0
index|]
operator|==
literal|','
condition|)
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|ngpat
argument_list|,
literal|"all,"
argument_list|)
expr_stmt|;
if|if
condition|(
name|arpat
index|[
literal|0
index|]
operator|==
literal|','
condition|)
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|arpat
argument_list|,
literal|"all,"
argument_list|)
expr_stmt|;
name|now
operator|=
name|time
argument_list|(
operator|(
name|time_t
operator|)
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|chdir
argument_list|(
name|SPOOL
argument_list|)
condition|)
name|xerror
argument_list|(
literal|"Cannot chdir %s"
argument_list|,
name|SPOOL
argument_list|)
expr_stmt|;
if|if
condition|(
name|verbose
condition|)
block|{
name|printf
argument_list|(
literal|"expire: nohistory %d, rebuild %d, doarchive %d\n"
argument_list|,
name|nohistory
argument_list|,
name|dorebuild
argument_list|,
name|doarchive
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"newsgroups: %s\n"
argument_list|,
name|ngpat
argument_list|)
expr_stmt|;
if|if
condition|(
name|doarchive
condition|)
name|printf
argument_list|(
literal|"archiving: %s\n"
argument_list|,
name|arpat
argument_list|)
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|OARTFILE
argument_list|,
literal|"%s/%s"
argument_list|,
name|LIB
argument_list|,
literal|"ohistory"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|NARTFILE
argument_list|,
literal|"%s/%s"
argument_list|,
name|LIB
argument_list|,
literal|"nhistory"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|OACTIVE
argument_list|,
literal|"%s/%s"
argument_list|,
name|LIB
argument_list|,
literal|"oactive"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|NACTIVE
argument_list|,
literal|"%s/%s"
argument_list|,
name|LIB
argument_list|,
literal|"nactive"
argument_list|)
expr_stmt|;
if|if
condition|(
name|updateactive
condition|)
goto|goto
name|doupdateactive
goto|;
ifdef|#
directive|ifdef
name|DBM
if|if
condition|(
operator|!
name|dorebuild
condition|)
block|{
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|PAGFILE
argument_list|,
literal|"%s/%s"
argument_list|,
name|LIB
argument_list|,
literal|"nhistory.pag"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|DIRFILE
argument_list|,
literal|"%s/%s"
argument_list|,
name|LIB
argument_list|,
literal|"nhistory.dir"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|close
argument_list|(
name|creat
argument_list|(
name|PAGFILE
argument_list|,
literal|0666
argument_list|)
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|close
argument_list|(
name|creat
argument_list|(
name|DIRFILE
argument_list|,
literal|0666
argument_list|)
argument_list|)
expr_stmt|;
name|initdbm
argument_list|(
name|NARTFILE
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
name|nohistory
condition|)
block|{
name|ohfd
operator|=
name|xfopen
argument_list|(
name|ACTIVE
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
if|if
condition|(
name|dorebuild
condition|)
block|{
comment|/* Allocate initial space for multiple newsgroup (for an 			   article) array */
name|multhist
operator|=
operator|(
expr|struct
name|multhist
operator|*
operator|)
name|calloc
argument_list|(
name|SPACE_INCREMENT
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|multhist
argument_list|)
argument_list|)
expr_stmt|;
name|mh_size
operator|=
name|SPACE_INCREMENT
expr_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|afline
argument_list|,
literal|"exec sort -t\t +1.6 -2 +1>%s"
argument_list|,
name|NARTFILE
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|nhfd
operator|=
name|popen
argument_list|(
name|afline
argument_list|,
literal|"w"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|xerror
argument_list|(
literal|"Cannot exec %s"
argument_list|,
name|afline
argument_list|)
expr_stmt|;
block|}
else|else
name|nhfd
operator|=
name|xfopen
argument_list|(
literal|"/dev/null"
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|ohfd
operator|=
name|xfopen
argument_list|(
name|ARTFILE
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
name|nhfd
operator|=
name|xfopen
argument_list|(
name|NARTFILE
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|NUNREC
condition|;
name|i
operator|++
control|)
name|h
operator|.
name|unrec
index|[
name|i
index|]
operator|=
name|NULL
expr_stmt|;
while|while
condition|(
name|TRUE
condition|)
block|{
name|fp
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|nohistory
condition|)
block|{
do|do
block|{
if|if
condition|(
name|ngdir
operator|==
name|NULL
condition|)
block|{
if|if
condition|(
name|ngdirp
operator|!=
name|NULL
condition|)
name|closedir
argument_list|(
name|ngdirp
argument_list|)
expr_stmt|;
if|if
condition|(
name|fgets
argument_list|(
name|afline
argument_list|,
name|BUFLEN
argument_list|,
name|ohfd
argument_list|)
operator|==
name|NULL
condition|)
goto|goto
name|out
goto|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|nbuf
argument_list|,
name|afline
argument_list|)
expr_stmt|;
name|p1
operator|=
name|index
argument_list|(
name|nbuf
argument_list|,
literal|' '
argument_list|)
expr_stmt|;
if|if
condition|(
name|p1
operator|==
name|NULL
condition|)
name|p1
operator|=
name|index
argument_list|(
name|nbuf
argument_list|,
literal|'\n'
argument_list|)
expr_stmt|;
if|if
condition|(
name|p1
operator|!=
name|NULL
condition|)
operator|*
name|p1
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
operator|!
name|ngmatch
argument_list|(
name|nbuf
argument_list|,
name|ngpat
argument_list|)
condition|)
continue|continue;
comment|/* Change a group name from 					   a.b.c to a/b/c */
for|for
control|(
name|p1
operator|=
name|nbuf
init|;
operator|*
name|p1
condition|;
name|p1
operator|++
control|)
if|if
condition|(
operator|*
name|p1
operator|==
literal|'.'
condition|)
operator|*
name|p1
operator|=
literal|'/'
expr_stmt|;
if|if
condition|(
operator|(
name|ngdirp
operator|=
name|opendir
argument_list|(
name|nbuf
argument_list|)
operator|)
operator|==
name|NULL
condition|)
continue|continue;
block|}
name|ngdir
operator|=
name|readdir
argument_list|(
name|ngdirp
argument_list|)
expr_stmt|;
comment|/*	Continue looking if not an article.	*/
block|}
do|while
condition|(
name|ngdir
operator|==
name|NULL
operator|||
operator|!
name|islegal
argument_list|(
name|fn
argument_list|,
name|nbuf
argument_list|,
name|ngdir
operator|->
name|d_name
argument_list|)
condition|)
do|;
name|p2
operator|=
name|fn
expr_stmt|;
if|if
condition|(
name|verbose
operator|>
literal|2
condition|)
name|printf
argument_list|(
literal|"article: %s\n"
argument_list|,
name|fn
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|filename
argument_list|,
name|dirname
argument_list|(
name|fn
argument_list|)
argument_list|)
expr_stmt|;
name|fp
operator|=
name|access
argument_list|(
name|filename
argument_list|,
literal|04
argument_list|)
condition|?
name|NULL
else|:
name|fopen
argument_list|(
name|filename
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|char
name|dc
decl_stmt|;
if|if
condition|(
name|fgets
argument_list|(
name|afline
argument_list|,
name|BUFLEN
argument_list|,
name|ohfd
argument_list|)
operator|==
name|NULL
condition|)
break|break;
if|if
condition|(
name|verbose
operator|>
literal|2
condition|)
name|printf
argument_list|(
literal|"article: %s"
argument_list|,
name|afline
argument_list|)
expr_stmt|;
name|p1
operator|=
name|index
argument_list|(
name|afline
argument_list|,
literal|'\t'
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|p1
condition|)
continue|continue;
operator|*
name|p1
operator|=
literal|'\0'
expr_stmt|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|h
operator|.
name|ident
argument_list|,
name|afline
argument_list|)
expr_stmt|;
operator|*
name|p1
operator|=
literal|'\t'
expr_stmt|;
name|p2
operator|=
name|index
argument_list|(
name|p1
operator|+
literal|1
argument_list|,
literal|'\t'
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|p2
condition|)
continue|continue;
operator|*
name|p2
operator|=
literal|'\0'
expr_stmt|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|recdate
argument_list|,
name|p1
operator|+
literal|1
argument_list|)
expr_stmt|;
name|rectime
operator|=
name|cgtdate
argument_list|(
name|recdate
argument_list|)
expr_stmt|;
operator|*
name|p2
operator|++
operator|=
literal|'\t'
expr_stmt|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|nbuf
argument_list|,
name|p2
argument_list|)
expr_stmt|;
name|p3
operator|=
name|index
argument_list|(
name|nbuf
argument_list|,
literal|'/'
argument_list|)
expr_stmt|;
if|if
condition|(
name|p3
condition|)
block|{
specifier|register
name|char
modifier|*
name|p4
decl_stmt|;
name|p4
operator|=
name|index
argument_list|(
name|p3
argument_list|,
literal|'\n'
argument_list|)
expr_stmt|;
if|if
condition|(
name|p4
condition|)
block|{
while|while
condition|(
name|p4
index|[
operator|-
literal|1
index|]
operator|==
literal|' '
condition|)
name|p4
operator|--
expr_stmt|;
operator|*
name|p4
operator|=
literal|'\0'
expr_stmt|;
block|}
comment|/* 				 * convert list of newsgroups from 				 *	ng1/num ng2/num ... 				 * to 				 *	ng1,ng2,... 				 */
name|p4
operator|=
name|p3
expr_stmt|;
do|do
block|{
operator|*
name|p3
operator|++
operator|=
name|NGDELIM
expr_stmt|;
while|while
condition|(
operator|*
name|p4
operator|!=
literal|'\0'
operator|&&
operator|*
name|p4
operator|!=
literal|' '
condition|)
name|p4
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|p4
operator|++
operator|==
literal|'\0'
condition|)
block|{
operator|*
operator|--
name|p3
operator|=
literal|'\0'
expr_stmt|;
break|break;
block|}
while|while
condition|(
operator|*
name|p3
operator|=
operator|*
name|p4
operator|++
condition|)
block|{
if|if
condition|(
operator|*
name|p3
operator|==
literal|'/'
condition|)
break|break;
else|else
name|p3
operator|++
expr_stmt|;
block|}
block|}
do|while
condition|(
operator|*
name|p3
condition|)
do|;
block|}
else|else
block|{
comment|/* 				 * Nothing after the 2nd tab.  This happens 				 * when there's no message left in the spool 				 * directory, only the memory of it in the 				 * history file. Use date in the history file 				 * to decide if we should keep this article. 				 */
name|grpsleft
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
goto|goto
name|checkdate
goto|;
block|}
if|if
condition|(
operator|!
name|ngmatch
argument_list|(
name|nbuf
argument_list|,
name|ngpat
argument_list|)
operator|||
operator|(
operator|(
name|rectime
operator|+
name|expincr
operator|>
name|now
operator|)
operator|&&
operator|!
name|dorebuild
operator|&&
operator|!
name|frflag
operator|&&
operator|!
name|usepost
operator|&&
name|recdate
index|[
literal|0
index|]
operator|!=
literal|' '
operator|)
condition|)
goto|goto
name|keephist
goto|;
if|if
condition|(
name|recdate
index|[
literal|0
index|]
operator|!=
literal|' '
condition|)
block|{
name|grpsleft
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
goto|goto
name|nailit
goto|;
comment|/* just expire it */
block|}
comment|/* 			 * Look for the file--possibly several times, 			 * if it was posted to several news groups. 			 */
name|dc
operator|=
literal|' '
expr_stmt|;
name|p3
operator|=
name|p2
expr_stmt|;
while|while
condition|(
name|dc
operator|!=
literal|'\n'
condition|)
block|{
name|p1
operator|=
name|index
argument_list|(
name|p3
argument_list|,
literal|' '
argument_list|)
expr_stmt|;
if|if
condition|(
name|p1
condition|)
block|{
name|dc
operator|=
literal|' '
expr_stmt|;
operator|*
name|p1
operator|=
literal|'\0'
expr_stmt|;
block|}
else|else
block|{
name|p1
operator|=
name|index
argument_list|(
name|p3
argument_list|,
literal|'\n'
argument_list|)
expr_stmt|;
if|if
condition|(
name|p1
operator|&&
name|p1
operator|>
name|p3
condition|)
block|{
name|dc
operator|=
literal|'\n'
expr_stmt|;
operator|*
name|p1
operator|=
literal|'\0'
expr_stmt|;
block|}
else|else
block|{
name|fp
operator|=
name|NULL
expr_stmt|;
break|break;
block|}
block|}
name|strcpy
argument_list|(
name|filename
argument_list|,
name|dirname
argument_list|(
name|p3
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|access
argument_list|(
name|filename
argument_list|,
literal|4
argument_list|)
operator|==
literal|0
operator|&&
operator|(
operator|(
name|fp
operator|=
name|fopen
argument_list|(
name|filename
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|!=
name|NULL
operator|)
condition|)
break|break;
name|p3
operator|=
name|p1
operator|+
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|p1
condition|)
operator|*
name|p1
operator|=
name|dc
expr_stmt|;
block|}
if|if
condition|(
name|fp
operator|==
name|NULL
condition|)
block|{
comment|/* 			 * this probably means that the article has been 			 * cancelled.  Lets assume that, and make an 			 * entry in the history file to that effect. 			 */
if|if
condition|(
name|verbose
condition|)
name|perror
argument_list|(
name|filename
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|p2
argument_list|,
literal|"cancelled\n"
argument_list|)
expr_stmt|;
name|grpsleft
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
goto|goto
name|checkdate
goto|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|NUNREC
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|h
operator|.
name|unrec
index|[
name|i
index|]
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|h
operator|.
name|unrec
index|[
name|i
index|]
argument_list|)
expr_stmt|;
else|else
break|break;
if|if
condition|(
operator|!
name|hread
argument_list|(
operator|&
name|h
argument_list|,
name|fp
argument_list|,
name|TRUE
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"Garbled article %s.\n"
argument_list|,
name|filename
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|fp
argument_list|)
expr_stmt|;
comment|/* 			 * Usually means disk ran out of space. 			 * Drop this article from our history file 			 * completely, so we have a chance of picking 			 * it up again from another feed .. 			 */
goto|goto
name|nailit
goto|;
block|}
if|if
condition|(
name|dorebuild
condition|)
block|{
specifier|register
name|char
modifier|*
name|cp
decl_stmt|,
modifier|*
name|lastslash
decl_stmt|;
specifier|register
name|struct
name|multhist
modifier|*
name|mhp
decl_stmt|;
if|if
condition|(
name|recdate
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
block|{
name|struct
name|stat
name|statb
decl_stmt|;
if|if
condition|(
name|fstat
argument_list|(
name|fileno
argument_list|(
name|fp
argument_list|)
argument_list|,
operator|&
name|statb
argument_list|)
operator|<
literal|0
condition|)
name|rectime
operator|=
name|cgtdate
argument_list|(
name|h
operator|.
name|subdate
argument_list|)
expr_stmt|;
else|else
name|rectime
operator|=
name|statb
operator|.
name|st_mtime
expr_stmt|;
block|}
else|else
name|rectime
operator|=
name|cgtdate
argument_list|(
name|recdate
argument_list|)
expr_stmt|;
comment|/* 			 * Format of filename until now was /SPOOL/a/b/c/4 			 * and this code changes it to a.b.c/4 (the correct 			 * kind of entry in the history file.) 			 * 			 * This can't be a strcpy because the addresses overlap 			 * and some machines can't handle that. 			 */
name|p1
operator|=
name|filename
expr_stmt|;
name|cp
operator|=
name|p1
operator|+
name|strlen
argument_list|(
name|SPOOL
argument_list|)
expr_stmt|;
while|while
condition|(
operator|*
operator|++
name|cp
condition|)
block|{
if|if
condition|(
operator|*
name|cp
operator|==
literal|'/'
condition|)
block|{
name|lastslash
operator|=
name|p1
expr_stmt|;
operator|*
name|p1
operator|++
operator|=
literal|'.'
expr_stmt|;
block|}
else|else
operator|*
name|p1
operator|++
operator|=
operator|*
name|cp
expr_stmt|;
block|}
operator|*
name|p1
operator|=
literal|'\0'
expr_stmt|;
operator|*
name|lastslash
operator|=
literal|'/'
expr_stmt|;
if|if
condition|(
operator|(
name|cp
operator|=
name|index
argument_list|(
name|h
operator|.
name|nbuf
argument_list|,
name|NGDELIM
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|struct
name|tm
modifier|*
name|tm
decl_stmt|;
name|saveit
label|:
name|tm
operator|=
name|localtime
argument_list|(
operator|&
name|rectime
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|USG
name|fprintf
argument_list|(
argument|nhfd
argument_list|,
literal|"%s\t%s%2.2d/%2.2d/%d %2.2d:%2.2d\t%s\n"
argument_list|,
else|#
directive|else
comment|/* !USG */
argument|fprintf(nhfd,
literal|"%s\t%s%02d/%02d/%d %02d:%02d\t%s\n"
argument|,
endif|#
directive|endif
comment|/* !USG */
argument|h.ident, h.expdate[
literal|0
argument|] ?
literal|" "
argument|:
literal|""
argument|, 					tm->tm_mon+
literal|1
argument|, tm->tm_mday, tm->tm_year, 					tm->tm_hour, tm->tm_min, filename); 				(void) fclose(fp); 				continue; 			} 			for (mhp = multhist; mhp< multhist+mh_size&& mhp->mh_ident != NULL; mhp++) { 				if (mhp->mh_file == NULL) 					continue; 				if (strcmp(mhp->mh_ident, h.ident)) 					continue; 				(void) strcat(filename,
literal|" "
argument|); 				(void) strcat(filename, mhp->mh_file); 				free(mhp->mh_file); 				mhp->mh_file = NULL;
comment|/* 				 * if we have all the links, write to hist now 				 */
argument|if (chrcnt(filename,
literal|' '
argument|) == chrcnt(cp,NGDELIM)) 					goto saveit; 				break; 			}
comment|/* 			 * Here is where we realloc the multhist space rather 			 * than the old way of static allocation.  It's 			 * really trivial.  We just clear out the space 			 * in case it was reused.  The old static array was 			 * guaranteed to be cleared since it was cleared when 			 * the process started. 			 */
argument|if (mhp>= multhist + mh_size) { 				multhist = (struct multhist *) 					realloc ((char *)multhist, 					  sizeof (struct multhist) * 					  (SPACE_INCREMENT + mh_size)); 				if (multhist == NULL) 					xerror(
literal|"Too many articles with multiple newsgroups"
argument|); 				for (mhp = multhist + mh_size; 				  mhp< multhist+mh_size+SPACE_INCREMENT; 					mhp++) { 					mhp->mh_ident = NULL; 					mhp->mh_file = NULL; 				} 				mhp = multhist + mh_size; 				mh_size += SPACE_INCREMENT; 			}  			if (mhp->mh_ident == NULL) { 				mhp->mh_ident = malloc(strlen(h.ident)+
literal|1
argument|); 				(void) strcpy(mhp->mh_ident, h.ident); 			} 			cp = malloc(strlen(filename) +
literal|1
argument|); 			if (cp == NULL) 				xerror(
literal|"Out of memory"
argument|); 			(void) strcpy(cp, filename); 			mhp->mh_file = cp; 			(void) fclose(fp); 			continue; 		}  		(void) fclose(fp); 		rectime = cgtdate(recdate);  		if (h.expdate[
literal|0
argument|]) 			exptime = cgtdate(h.expdate); 		newtime = (usepost ? cgtdate(h.subdate) : rectime) + expincr; 		if (!h.expdate[
literal|0
argument|] || ignorexp ==
literal|2
argument||| 		    (ignorexp ==
literal|1
argument|&& newtime< exptime)) 			exptime = newtime; 		if (frflag ? strcmp(baduser,h.from)==
literal|0
argument|: now>= exptime) { nailit:
ifdef|#
directive|ifdef
name|DEBUG
argument|printf(
literal|"cancel %s\n"
argument|, filename);
else|#
directive|else
comment|/* !DEBUG */
argument|if (verbose) 				printf(
literal|"cancel %s\n"
argument|, h.ident); 			ulall(p2,&h); 			(void) sprintf(p2,
literal|"%s\n"
argument|, grpsleft); 			if (verbose>
literal|2
argument|&& grpsleft[
literal|0
argument|]) 				printf(
literal|"Some good in %s\n"
argument|, h.ident);
endif|#
directive|endif
comment|/* !DEBUG */
argument|} else { 			if (verbose>
literal|2
argument|) 				printf(
literal|"Good article %s\n"
argument|, h.ident); 			grpsleft[
literal|0
argument|] =
literal|'!'
argument|; 		}  checkdate: 		if (grpsleft[
literal|0
argument|] ==
literal|'\0'
argument|&& now>= rectime + dropincr) { 			if (verbose>
literal|3
argument|) 				printf(
literal|"Drop history of %s - %s\n"
argument|, 				    h.ident, recdate); 		} else { 			long hpos; keephist: 			hpos = ftell(nhfd);  			if (verbose>
literal|3
argument|) 				printf(
literal|"Retain history of %s - %s\n"
argument|, 				    h.ident, recdate); 			if (fputs(afline, nhfd) == EOF) 				xerror(
literal|"history write failed"
argument|);
ifdef|#
directive|ifdef
name|DBM
argument|if (!dorebuild) 				remember(h.ident, hpos);
endif|#
directive|endif
comment|/* DBM */
argument|} 	} out: 	if (dorebuild) { 		register struct multhist *mhp; 		struct tm *tm; 		for (mhp = multhist; mhp< multhist+mh_size&& mhp->mh_ident != NULL; mhp++) 			if (mhp->mh_file != NULL) { 				if (verbose) 					printf(
literal|"Article: %s [%s] Cannot find all links\n"
argument|, mhp->mh_ident, mhp->mh_file); 				(void) sprintf(filename,
literal|"%s/%s"
argument|,SPOOL,mhp->mh_file); 				for (p1 = filename; *p1 !=
literal|' '
argument|&& *p1 !=
literal|'\0'
argument|; p1++) 					if (*p1 ==
literal|'.'
argument|) 						*p1 =
literal|'/'
argument|; 				*p1 =
literal|'\0'
argument|; 				if ((fp = fopen(filename,
literal|"r"
argument|)) == NULL) { 					if (verbose) 						printf(
literal|"Can't open %s.\n"
argument|, filename); 					continue; 				} 				if (!hread(&h, fp, TRUE)) { 					printf(
literal|"Garbled article %s.\n"
argument|, filename); 					(void) fclose(fp); 					continue; 				} else { 					struct stat statb; 					if (fstat(fileno(fp),&statb)<
literal|0
argument|) 						rectime = cgtdate(h.subdate); 					else 						rectime = statb.st_mtime; 				} 				tm = localtime(&rectime); 				if (
ifdef|#
directive|ifdef
name|USG
argument|fprintf(nhfd,
literal|"%s\t%s%2.2d/%2.2d/%d %2.2d:%2.2d\t%s\n"
argument|,
else|#
directive|else
comment|/* !USG */
argument|fprintf(nhfd,
literal|"%s\t%s%02d/%02d/%d %02d:%02d\t%s\n"
argument|,
endif|#
directive|endif
comment|/* !USG */
argument|h.ident, h.expdate[
literal|0
argument|] ?
literal|" "
argument|:
literal|""
argument|, 					tm->tm_mon+
literal|1
argument|, tm->tm_mday, tm->tm_year, 					tm->tm_hour, tm->tm_min, mhp->mh_file) 					== EOF ) 						xerror(
literal|"History write failed"
argument|); 				(void) fclose(fp); 				continue; 			} 		(void) pclose(nhfd); 		free ((char *)multhist); 	} else 		fclose(nhfd);  	if (dorebuild || !nohistory) { 		(void) rename(ARTFILE, OARTFILE); 		(void) rename(NARTFILE, ARTFILE);
ifdef|#
directive|ifdef
name|DBM
argument|if (dorebuild) 			rebuilddbm( ); 		else { 			char tempname[BUFLEN]; 			(void) sprintf(tempname,
literal|"%s.pag"
argument|, ARTFILE); 			(void) strcat(OARTFILE,
literal|".pag"
argument|); 			(void) strcat(NARTFILE,
literal|".pag"
argument|); 			(void) rename(tempname, OARTFILE); 			(void) rename(NARTFILE, tempname); 			(void) sprintf(tempname,
literal|"%s.dir"
argument|, ARTFILE); 			(void) strcpy(rindex(OARTFILE,
literal|'.'
argument|),
literal|".dir"
argument|); 			(void) strcpy(rindex(NARTFILE,
literal|'.'
argument|),
literal|".dir"
argument|); 			(void) rename(tempname, OARTFILE); 			(void) rename(NARTFILE, tempname); 		}
endif|#
directive|endif
argument|}
ifndef|#
directive|ifndef
name|DBM
comment|/* rebuild history subfiles */
argument|for (i =
literal|0
argument|; i<
literal|10
argument|; i++) { 		(void) sprintf(fn,
literal|"%s.d/%c"
argument|, ARTFILE, i +
literal|'0'
argument|); 		close(creat(fn,
literal|0644
argument|)); 		subfd[i] = xfopen(fn,
literal|"w+"
argument|); 	} 	ohfd = xfopen(ARTFILE,
literal|"r"
argument|); 	while (fgets(fn, BUFLEN, ohfd) != NULL) { 		ptr = histfile(fn); 		chr = *(ptr + strlen(ptr) -
literal|1
argument|); 		if (isdigit(chr)) 			i = chr -
literal|'0'
argument|; 		else 			i =
literal|0
argument|; 		fputs(fn, subfd[i]); 	} 	(void) fclose(ohfd); 	for (i =
literal|0
argument|; i<
literal|10
argument|; i++) 		fclose(subfd[i]);
endif|#
directive|endif
comment|/* !DBM */
argument|doupdateactive: 	ohfd = xfopen(ACTIVE,
literal|"r"
argument|); 	nhfd = xfopen(NACTIVE,
literal|"w"
argument|); 	do { 		long n; 		long maxart, minart; 		char cansub; 		int gdsize, hassubs; 		struct stat stbuf;  		if (fgets(afline, BUFLEN, ohfd) == NULL) 			continue; 		if (sscanf(afline,
literal|"%s %ld %ld %c"
argument|,nbuf,&maxart,&minart,&cansub)<
literal|4
argument|) 			xerror(
literal|"Active file corrupt"
argument|); 		if (!ngmatch(nbuf, ngpat)) { 			if (fputs(afline, nhfd) == EOF) 				xerror(
literal|"active file write failed"
argument|); 			continue; 		} 		minart =
literal|99999L
argument|;
comment|/* Change a group name from a.b.c to a/b/c */
argument|for (p1=nbuf; *p1; p1++) 			if (*p1 ==
literal|'.'
argument|) 				*p1 =
literal|'/'
argument|;  		hassubs = stat(nbuf,&stbuf) !=
literal|0
argument||| stbuf.st_nlink !=
literal|2
argument|; 		gdsize = strlen(nbuf); 		if ((ngdirp = opendir(nbuf)) != NULL) { 			while (ngdir = readdir(ngdirp)) { 				nbuf[gdsize] =
literal|'/'
argument|; 				(void) strcpy(&nbuf[gdsize+
literal|1
argument|], ngdir->d_name);
comment|/* We have to do a stat because of micro.6809 */
argument|if (hassubs&& (stat(nbuf,&stbuf)<
literal|0
argument||| 					!(stbuf.st_mode&S_IFREG)) ) 					continue; 				n = atol(ngdir->d_name); 				if (n>
literal|0
argument|&& n< minart) 					minart = n; 				if (n>
literal|0
argument|&& n> maxart) 					maxart = n; 			} 			closedir(ngdirp); 		} 		afline[gdsize] =
literal|'\0'
argument|; 		if (minart> maxart) 			minart = maxart; 		if (fprintf(nhfd,
literal|"%s %05ld %05ld %c\n"
argument|, afline, maxart, 			minart, cansub) == EOF) 			xerror(
literal|"Active file write failed"
argument|); 	} while (!feof(ohfd)); 	(void) fclose(nhfd); 	(void) fclose(ohfd);  	(void) rename(ACTIVE, OACTIVE); 	(void) rename(NACTIVE, ACTIVE);  	xxit(
literal|0
argument|); }
comment|/* Unlink (using unwound tail recursion) all the articles in 'artlist'. */
argument|ulall(artlist, hp) char	*artlist; struct hbuf *hp; { 	register char	*p, *q; 	int	last =
literal|0
argument|; 	char	newname[BUFLEN]; 	time_t	timep[
literal|2
argument|]; 	char *fn;  	grpsleft[
literal|0
argument|] =
literal|'\0'
argument|; 	do { 		if (verbose>
literal|2
argument|) 			printf(
literal|"ulall '%s', '%s'\n"
argument|, artlist, hp->subdate); 		if (nohistory) { 			last =
literal|1
argument|; 		} else { 			while (*artlist ==
literal|' '
argument||| *artlist ==
literal|'\n'
argument||| *artlist ==
literal|','
argument|) 				artlist++; 			if (*artlist ==
literal|'\0'
argument|) 				return; 			p = index(artlist,
literal|' '
argument|); 			if (p == NULL) { 				last =
literal|1
argument|; 				p = index(artlist,
literal|'\n'
argument|); 			} 			if (p == NULL) { 				last =
literal|1
argument|; 				fn = dirname(artlist); 				if (unlink(fn)<
literal|0
argument|&& errno != ENOENT) 					perror(fn); 				return; 			} 			if (p) 				*p =
literal|0
argument|; 		} 		strcpy(newname, artlist); 		q = index(newname,
literal|'/'
argument|); 		if (q) { 			*q++ = NGDELIM; 			*q =
literal|'\0'
argument|; 		} else { 			q = index(newname,
literal|'\0'
argument|); 			if (q == artlist)
comment|/* null -> the end */
argument|return;
comment|/* should be impossible to get here */
argument|} 		fn = dirname(artlist); 		if (ngmatch(newname, ngpat)) { 			if (doarchive){ 				if (ngmatch(newname, arpat)) { 					q = fn + strlen(SPOOL) +
literal|1
argument|; 					(void) sprintf(newname,
literal|"%s/%s"
argument|, OLDNEWS, q); 					if (verbose) 						printf(
literal|"link %s to %s\n"
argument|, fn, newname); 					if (link(fn, newname) == -
literal|1
argument|) { 						if (mkparents(newname) ==
literal|0
argument|) 							if (link(fn, newname) == -
literal|1
argument|) 								fcopy(fn, newname); 					} 					timep[
literal|0
argument|] = timep[
literal|1
argument|] = cgtdate(hp->subdate); 					(void) utime(newname, timep); 				} 			} 			if (verbose) 				printf(
literal|"unlink %s\n"
argument|, fn); 			if (unlink(fn)<
literal|0
argument|&& errno != ENOENT) 				perror(fn); 		} else { 			if (verbose>
literal|3
argument|) 				printf(
literal|"retain %s (%s)\n"
argument|, hp->ident, fn); 			strcat(grpsleft, artlist); 			strcat(grpsleft,
literal|" "
argument|); 		} 		artlist = p +
literal|1
argument|; 	} while (!last); }  fcopy(fn, newname) char *fn, *newname; { 	int f1, f2; 	int r; 	char buf[BUFSIZ]; 	f1 = open(fn,
literal|0
argument|); 	if (f1<
literal|0
argument|) 		return -
literal|1
argument|; 	f2 = open(newname,
literal|1
argument|); 	if (f2<
literal|0
argument|) { 		if (errno == ENOENT) { 			f2 = creat(newname,
literal|0644
argument|); 			if (f2<
literal|0
argument|) { 				close(f1); 				return -
literal|1
argument|; 			} 		} else { 			close(f1); 			return -
literal|1
argument|; 		} 	} 	while((r=read(f1, buf, BUFSIZ))>
literal|0
argument|) 		write(f2, buf, r); 	(void) close(f1); 	(void) close(f2); 	return
literal|0
argument|; }
comment|/*   * Count instances of c in s  */
argument|chrcnt(s, c) register char *s; register c; { 	register n =
literal|0
argument|; 	register cc;  	while (cc = *s++) 		if (cc == c) 			n++; 	return n; }
comment|/*  * If any parent directories of this dir don't exist, create them.  */
argument|mkparents(fullname) char *fullname; { 	char buf[
literal|200
argument|]; 	register char *p; 	int rc;  	(void) strcpy(buf, fullname); 	p = rindex(buf,
literal|'/'
argument|); 	if (p) 		*p =
literal|'\0'
argument|; 	if (access(buf,
literal|0
argument|) ==
literal|0
argument|) 		return
literal|0
argument|; 	mkparents(buf); 	if ((rc = mkdir(buf,
literal|0755
argument|))<
literal|0
argument|) 		perror(
literal|"mkdir failed"
argument|); 	if (verbose) 		printf(
literal|"mkdir %s, rc %d\n"
argument|, buf, rc);  	return rc; }
comment|/*	Make sure this file is a legal article. */
argument|islegal(fullname, path, name) register char *fullname; register char *path; register char *name; { 	struct stat buffer;  	(void) sprintf(fullname,
literal|"%s/%s"
argument|, path, name);
comment|/* make sure the article is numeric. */
argument|while (*name !=
literal|'\0'
argument|) 		if (!isascii(*name) || !isdigit(*name)) 			return
literal|0
argument|; 		else 			name++;
comment|/*  Now make sure we don't have a group like net.micro.432, 	 *  which is numeric but not a regular file -- i.e., check 	 *  for being a regular file. 	 */
argument|if ((stat(fullname,&buffer) ==
literal|0
argument|)&& 		((buffer.st_mode& S_IFMT) == S_IFREG)) {
comment|/* Now that we found a legal group in a/b/c/4 		   notation, switch it to a.b.c/4 notation.  */
argument|for (name = fullname; name != NULL&& *name !=
literal|'\0'
argument|; name++) 			if (*name ==
literal|'/'
argument|&& name != rindex (name,
literal|'/'
argument|)) 				*name =
literal|'.'
argument|;  			return
literal|1
argument|; 	} 	return
literal|0
argument|; }
ifdef|#
directive|ifdef
name|DBM
comment|/*  * This is taken mostly intact from ../cvt/cvt.hist.c and is used at the  * end by the options that make a new history file.  * Routine to convert history file to dbm file.  The old 3 field  * history file is still kept there, because we need it for expire  * and for a human readable copy.  But we keep a dbm hashed copy  * around by message ID so we can answer the yes/no question "have  * we already seen this message".  The content is the ftell offset  * into the real history file when we get the article - you can't  * really do much with this because the file gets compacted.  */
argument|FILE *fd;  char namebuf[BUFSIZ]; char lb[BUFSIZ];  rebuilddbm() { 	register char *p; 	long fpos;  	(void) umask(
literal|0
argument|); 	(void) sprintf(namebuf,
literal|"%s.dir"
argument|, ARTFILE); 	(void) close(creat(namebuf,
literal|0666
argument|)); 	(void) sprintf(namebuf,
literal|"%s.pag"
argument|, ARTFILE); 	(void) close(creat(namebuf,
literal|0666
argument|)); 	(void) sprintf(namebuf,
literal|"%s"
argument|, ARTFILE);  	fd = fopen(namebuf,
literal|"r"
argument|); 	if (fd == NULL) { 		perror(namebuf); 		xxit(
literal|2
argument|); 	}  	initdbm(namebuf); 	while (fpos=ftell(fd), fgets(lb, BUFSIZ, fd) != NULL) { 		p = index(lb,
literal|'\t'
argument|); 		if (p) 			*p =
literal|0
argument|; 		remember(lb, fpos); 	} }  remember(article, fileoff) register char *article; long fileoff; { 	datum	lhs, rhs;  	lcase(article); 	lhs.dptr = article; 	lhs.dsize = strlen(article) +
literal|1
argument|; 	rhs.dptr = (char *)&fileoff; 	rhs.dsize = sizeof fileoff;  	if (verbose>
literal|5
argument|) 		printf(
literal|"remember: %s @ %ld\n"
argument|, article, fileoff); 	if (store(lhs, rhs)<
literal|0
argument|) 		xerror(
literal|"dbm store failed"
argument|); }
endif|#
directive|endif
comment|/* DBM */
argument|xxit(i) { 	exit(i); }
end_function

end_unit

