begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * 	@(#)lp.h	8.2 (Berkeley) 4/28/95  */
end_comment

begin_comment
comment|/*  * Global definitions for the line printer system.  */
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
name|long
name|BR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* baud rate if lp is a tty */
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
name|long
name|CT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TCP connection timeout */
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
name|long
name|DU
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* daeomon user-id */
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
name|GF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of graph(1G) filter (per job) */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|HL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print header last */
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
name|LP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line printer device name */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|MC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum number of copies allowed */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|MX
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum number of blocks to copy */
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
name|OF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of output filter (created once) */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|PL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* page length */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|PW
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* page width */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|PX
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* page width in pixels */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|PY
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* page length in pixels */
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
name|RP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* remote printer name */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|RS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* restricted to those with local accounts */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|RW
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* open LP for reading and writing */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|SB
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* short banner instead of normal header */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|SC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* suppress multiple copies */
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
name|long
name|SF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* suppress FF on each print job */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|SH
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* suppress header page */
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
name|TR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* trailer string to be output when Q empties */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|MS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mode set, a la stty */
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
name|line
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|bp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer into printcap buffer */
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

begin_comment
comment|/* host machine name */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|host
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
end_decl_stmt

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
name|remote
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if sending files to a remote host */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|printcapdb
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* printcap database array */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|requ
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* job number of spool entries */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|requests
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of spool requests */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|user
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* users to process */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|users
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of users in user array */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|person
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of person doing lprm */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|name
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

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_macro
name|__BEGIN_DECLS
end_macro

begin_struct_decl
struct_decl|struct
name|dirent
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|blankfill
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|checkremote
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
name|chk
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
name|void
name|displayq
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
name|dump
name|__P
argument_list|(
operator|(
name|char
operator|*
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
name|fatal
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getline
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getport
name|__P
argument_list|(
operator|(
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
name|getq
name|__P
argument_list|(
operator|(
expr|struct
name|queue
operator|*
operator|(
operator|*
index|[]
operator|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|header
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|inform
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
name|int
name|inlist
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|iscf
name|__P
argument_list|(
operator|(
expr|struct
name|dirent
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isowner
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ldump
name|__P
argument_list|(
operator|(
name|char
operator|*
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
name|lockchk
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
name|void
name|prank
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
name|process
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
name|void
name|rmjob
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rmremote
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|show
name|__P
argument_list|(
operator|(
name|char
operator|*
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
name|startdaemon
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
name|void
name|delay
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

end_unit

