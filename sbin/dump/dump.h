begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)dump.h	8.2 (Berkeley) 4/28/95  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|MAXINOPB
value|(MAXBSIZE / sizeof(struct dinode))
end_define

begin_define
define|#
directive|define
name|MAXNINDIR
value|(MAXBSIZE / sizeof(daddr_t))
end_define

begin_comment
comment|/*  * Dump maps used to describe what is to be dumped.  */
end_comment

begin_decl_stmt
name|int
name|mapsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of the state maps */
end_comment

begin_decl_stmt
name|char
modifier|*
name|usedinomap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* map of allocated inodes */
end_comment

begin_decl_stmt
name|char
modifier|*
name|dumpdirmap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* map of directories to be dumped */
end_comment

begin_decl_stmt
name|char
modifier|*
name|dumpinomap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* map of files to be dumped */
end_comment

begin_comment
comment|/*  * Map manipulation macros.  */
end_comment

begin_define
define|#
directive|define
name|SETINO
parameter_list|(
name|ino
parameter_list|,
name|map
parameter_list|)
define|\
value|map[(u_int)((ino) - 1) / NBBY] |=  1<< ((u_int)((ino) - 1) % NBBY)
end_define

begin_define
define|#
directive|define
name|CLRINO
parameter_list|(
name|ino
parameter_list|,
name|map
parameter_list|)
define|\
value|map[(u_int)((ino) - 1) / NBBY]&=  ~(1<< ((u_int)((ino) - 1) % NBBY))
end_define

begin_define
define|#
directive|define
name|TSTINO
parameter_list|(
name|ino
parameter_list|,
name|map
parameter_list|)
define|\
value|(map[(u_int)((ino) - 1) / NBBY]&  (1<< ((u_int)((ino) - 1) % NBBY)))
end_define

begin_comment
comment|/*  *	All calculations done in 0.1" units!  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|disk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of the disk file */
end_comment

begin_decl_stmt
name|char
modifier|*
name|tape
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of the tape file */
end_comment

begin_decl_stmt
name|char
modifier|*
name|dumpdates
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of the file containing dump date information*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|temp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of the file for doing rewrite of dumpdates */
end_comment

begin_decl_stmt
name|char
name|lastlevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dump level of previous dump */
end_comment

begin_decl_stmt
name|char
name|level
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dump level of this dump */
end_comment

begin_decl_stmt
name|int
name|uflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* update flag */
end_comment

begin_decl_stmt
name|int
name|diskfd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* disk file descriptor */
end_comment

begin_decl_stmt
name|int
name|tapefd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tape file descriptor */
end_comment

begin_decl_stmt
name|int
name|pipeout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true => output to standard output */
end_comment

begin_decl_stmt
name|ino_t
name|curino
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current inumber; used globally */
end_comment

begin_decl_stmt
name|int
name|newtape
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* new tape flag */
end_comment

begin_decl_stmt
name|int
name|density
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* density in 0.1" units */
end_comment

begin_decl_stmt
name|long
name|tapesize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* estimated tape size, blocks */
end_comment

begin_decl_stmt
name|long
name|tsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tape size in 0.1" units */
end_comment

begin_decl_stmt
name|long
name|asize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of 0.1" units written on current tape */
end_comment

begin_decl_stmt
name|int
name|etapes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* estimated number of tapes */
end_comment

begin_decl_stmt
name|int
name|nonodump
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if set, do not honor UF_NODUMP user flags */
end_comment

begin_decl_stmt
name|int
name|unlimited
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if set, write to end of medium */
end_comment

begin_decl_stmt
name|int
name|notify
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* notify operator flag */
end_comment

begin_decl_stmt
name|int
name|blockswritten
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of blocks written on current tape */
end_comment

begin_decl_stmt
name|int
name|tapeno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current tape number */
end_comment

begin_decl_stmt
name|time_t
name|tstart_writing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* when started writing the first tape block */
end_comment

begin_decl_stmt
name|time_t
name|tend_writing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* after writing the last tape block */
end_comment

begin_decl_stmt
name|struct
name|fs
modifier|*
name|sblock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the file system super block */
end_comment

begin_decl_stmt
name|char
name|sblock_buf
index|[
name|MAXBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|dev_bsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* block size of underlying disk device */
end_comment

begin_decl_stmt
name|int
name|dev_bshift
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* log2(dev_bsize) */
end_comment

begin_decl_stmt
name|int
name|tp_bshift
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* log2(TP_BSIZE) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* operator interface functions */
end_comment

begin_decl_stmt
name|void
name|broadcast
name|__P
argument_list|(
operator|(
name|char
operator|*
name|message
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|infosch
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
name|lastdump
name|__P
argument_list|(
operator|(
name|int
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* int should be char */
end_comment

begin_decl_stmt
name|void
name|msg
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
name|__printflike
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|msgtail
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
name|__printflike
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|query
name|__P
argument_list|(
operator|(
name|char
operator|*
name|question
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|quit
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
name|__printflike
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|timeest
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|time_t
name|unctime
name|__P
argument_list|(
operator|(
name|char
operator|*
name|str
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mapping rouintes */
end_comment

begin_struct_decl
struct_decl|struct
name|dinode
struct_decl|;
end_struct_decl

begin_decl_stmt
name|long
name|blockest
name|__P
argument_list|(
operator|(
expr|struct
name|dinode
operator|*
name|dp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mapfiles
name|__P
argument_list|(
operator|(
name|ino_t
name|maxino
operator|,
name|long
operator|*
name|tapesize
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mapdirs
name|__P
argument_list|(
operator|(
name|ino_t
name|maxino
operator|,
name|long
operator|*
name|tapesize
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file dumping routines */
end_comment

begin_decl_stmt
name|void
name|blksout
name|__P
argument_list|(
operator|(
name|daddr_t
operator|*
name|blkp
operator|,
name|int
name|frags
operator|,
name|ino_t
name|ino
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bread
name|__P
argument_list|(
operator|(
name|daddr_t
name|blkno
operator|,
name|char
operator|*
name|buf
operator|,
name|int
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dumpino
name|__P
argument_list|(
operator|(
expr|struct
name|dinode
operator|*
name|dp
operator|,
name|ino_t
name|ino
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dumpmap
name|__P
argument_list|(
operator|(
name|char
operator|*
name|map
operator|,
name|int
name|type
operator|,
name|ino_t
name|ino
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|writeheader
name|__P
argument_list|(
operator|(
name|ino_t
name|ino
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tape writing routines */
end_comment

begin_decl_stmt
name|int
name|alloctape
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
name|close_rewind
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
name|dumpblock
name|__P
argument_list|(
operator|(
name|daddr_t
name|blkno
operator|,
name|int
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|startnewtape
name|__P
argument_list|(
operator|(
name|int
name|top
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|trewind
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
name|writerec
name|__P
argument_list|(
operator|(
name|char
operator|*
name|dp
operator|,
name|int
name|isspcl
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Exit
name|__P
argument_list|(
operator|(
name|int
name|status
operator|)
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dumpabort
name|__P
argument_list|(
operator|(
name|int
name|signo
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|getfstab
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|rawname
name|__P
argument_list|(
operator|(
name|char
operator|*
name|cp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|dinode
modifier|*
name|getino
name|__P
argument_list|(
operator|(
name|ino_t
name|inum
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rdump routines */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RDUMP
end_ifdef

begin_decl_stmt
name|void
name|rmtclose
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
name|rmthost
name|__P
argument_list|(
operator|(
name|char
operator|*
name|host
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rmtopen
name|__P
argument_list|(
operator|(
name|char
operator|*
name|tape
operator|,
name|int
name|mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rmtwrite
name|__P
argument_list|(
operator|(
name|char
operator|*
name|buf
operator|,
name|int
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RDUMP */
end_comment

begin_decl_stmt
name|void
name|interrupt
name|__P
argument_list|(
operator|(
name|int
name|signo
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in case operator bangs on console */
end_comment

begin_comment
comment|/*  *	Exit status codes  */
end_comment

begin_define
define|#
directive|define
name|X_FINOK
value|0
end_define

begin_comment
comment|/* normal exit */
end_comment

begin_define
define|#
directive|define
name|X_STARTUP
value|1
end_define

begin_comment
comment|/* startup error */
end_comment

begin_define
define|#
directive|define
name|X_REWRITE
value|2
end_define

begin_comment
comment|/* restart writing from the check point */
end_comment

begin_define
define|#
directive|define
name|X_ABORT
value|3
end_define

begin_comment
comment|/* abort dump; don't attempt checkpointing */
end_comment

begin_define
define|#
directive|define
name|OPGRENT
value|"operator"
end_define

begin_comment
comment|/* group entry to notify */
end_comment

begin_decl_stmt
name|struct
name|fstab
modifier|*
name|fstabsearch
name|__P
argument_list|(
operator|(
name|char
operator|*
name|key
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* search fs_file and fs_spec */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NAME_MAX
end_ifndef

begin_define
define|#
directive|define
name|NAME_MAX
value|255
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	The contents of the file _PATH_DUMPDATES is maintained both on  *	a linked list, and then (eventually) arrayified.  */
end_comment

begin_struct
struct|struct
name|dumpdates
block|{
name|char
name|dd_name
index|[
name|NAME_MAX
operator|+
literal|3
index|]
decl_stmt|;
name|char
name|dd_level
decl_stmt|;
name|time_t
name|dd_ddate
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|nddates
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of records (might be zero) */
end_comment

begin_decl_stmt
name|int
name|ddates_in
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* we have read the increment file */
end_comment

begin_decl_stmt
name|struct
name|dumpdates
modifier|*
modifier|*
name|ddatev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the arrayfied version */
end_comment

begin_decl_stmt
name|void
name|initdumptimes
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
name|getdumptime
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
name|putdumptime
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ITITERATE
parameter_list|(
name|i
parameter_list|,
name|ddp
parameter_list|)
define|\
value|for (ddp = ddatev[i = 0]; i< nddates; ddp = ddatev[++i])
end_define

begin_decl_stmt
name|void
name|sig
name|__P
argument_list|(
operator|(
name|int
name|signo
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Compatibility with old systems.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT
end_ifdef

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_define
define|#
directive|define
name|strchr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|index(a,b)
end_define

begin_define
define|#
directive|define
name|strrchr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|rindex(a,b)
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strdup
argument_list|()
decl_stmt|,
modifier|*
name|ctime
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|read
argument_list|()
decl_stmt|,
name|write
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_UTMP
end_ifndef

begin_define
define|#
directive|define
name|_PATH_UTMP
value|"/etc/utmp"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_FSTAB
end_ifndef

begin_define
define|#
directive|define
name|_PATH_FSTAB
value|"/etc/fstab"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

