begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)lp.h	5.5 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Global definitions for the line printer system.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
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
file|<sys/dir.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/un.h>
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
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<sgtty.h>
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
file|"lp.local.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|DU
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* daeomon user-id */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|MX
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum number of blocks to copy */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|MC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum number of copies allowed */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|LP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line printer device name */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|RM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* remote machine name */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|RG
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* restricted group */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|RP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* remote printer name */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|LO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lock file name */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ST
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* status file name */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|SD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* spool directory */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|AF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* accounting file */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|LF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* log file for error messages */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|OF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of output filter (created once) */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|IF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of input filter (created per job) */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|RF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of fortran text filter (per job) */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|TF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of troff(1) filter (per job) */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|NF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of ditroff(1) filter (per job) */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|DF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of tex filter (per job) */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|GF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of graph(1G) filter (per job) */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|VF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of raster filter (per job) */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|CF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of cifplot filter (per job) */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|FF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* form feed string */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|TR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* trailer string to be output when Q empties */
end_comment

begin_decl_stmt
specifier|extern
name|short
name|SC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* suppress multiple copies */
end_comment

begin_decl_stmt
specifier|extern
name|short
name|SF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* suppress FF on each print job */
end_comment

begin_decl_stmt
specifier|extern
name|short
name|SH
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* suppress header page */
end_comment

begin_decl_stmt
specifier|extern
name|short
name|SB
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* short banner instead of normal header */
end_comment

begin_decl_stmt
specifier|extern
name|short
name|HL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print header last */
end_comment

begin_decl_stmt
specifier|extern
name|short
name|RW
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* open LP for reading and writing */
end_comment

begin_decl_stmt
specifier|extern
name|short
name|PW
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* page width */
end_comment

begin_decl_stmt
specifier|extern
name|short
name|PX
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* page width in pixels */
end_comment

begin_decl_stmt
specifier|extern
name|short
name|PY
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* page length in pixels */
end_comment

begin_decl_stmt
specifier|extern
name|short
name|PL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* page length */
end_comment

begin_decl_stmt
specifier|extern
name|short
name|BR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* baud rate if lp is a tty */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|FC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flags to clear if lp is a tty */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|FS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flags to set if lp is a tty */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|XC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flags to clear for local mode */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|XS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flags to set for local mode */
end_comment

begin_decl_stmt
specifier|extern
name|short
name|RS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* restricted to those with local accounts */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|line
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|pbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer for printcap entry */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|bp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer into ebuf for pgetent() */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* program name */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|printer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* printer name */
end_comment

begin_decl_stmt
specifier|extern
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
specifier|extern
name|char
modifier|*
name|from
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* client's machine name */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sendtorem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* are we sending to a remote? */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Structure used for building a sorted list of control files.  */
end_comment

begin_struct
struct|struct
name|queue
block|{
name|time_t
name|q_time
decl_stmt|;
comment|/* modification time */
name|char
name|q_name
index|[
name|MAXNAMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* control file name */
block|}
struct|;
end_struct

begin_function_decl
name|char
modifier|*
name|pgetstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|index
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|rindex
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|checkremote
parameter_list|()
function_decl|;
end_function_decl

end_unit

