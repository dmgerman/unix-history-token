begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)dump.h	5.4 (Berkeley) 2/23/87  */
end_comment

begin_define
define|#
directive|define
name|NI
value|16
end_define

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
file|<sys/fs.h>
end_include

begin_include
include|#
directive|include
file|<sys/inode.h>
end_include

begin_include
include|#
directive|include
file|<protocols/dumprestore.h>
end_include

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_include
include|#
directive|include
file|<utmp.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<fstab.h>
end_include

begin_define
define|#
directive|define
name|MWORD
parameter_list|(
name|m
parameter_list|,
name|i
parameter_list|)
value|(m[(unsigned)(i-1)/NBBY])
end_define

begin_define
define|#
directive|define
name|MBIT
parameter_list|(
name|i
parameter_list|)
value|(1<<((unsigned)(i-1)%NBBY))
end_define

begin_define
define|#
directive|define
name|BIS
parameter_list|(
name|i
parameter_list|,
name|w
parameter_list|)
value|(MWORD(w,i) |=  MBIT(i))
end_define

begin_define
define|#
directive|define
name|BIC
parameter_list|(
name|i
parameter_list|,
name|w
parameter_list|)
value|(MWORD(w,i)&= ~MBIT(i))
end_define

begin_define
define|#
directive|define
name|BIT
parameter_list|(
name|i
parameter_list|,
name|w
parameter_list|)
value|(MWORD(w,i)& MBIT(i))
end_define

begin_decl_stmt
name|int
name|msiz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|clrmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|dirmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|nodmap
decl_stmt|;
end_decl_stmt

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
name|increm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of the file containing incremental information*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|temp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of the file for doing rewrite of increm */
end_comment

begin_decl_stmt
name|char
name|lastincno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* increment number of previous dump */
end_comment

begin_decl_stmt
name|char
name|incno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* increment number */
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
name|fi
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* disk file descriptor */
end_comment

begin_decl_stmt
name|int
name|to
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
name|ino
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current inumber; used globally */
end_comment

begin_decl_stmt
name|int
name|nsubdir
decl_stmt|;
end_decl_stmt

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
name|nadded
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of added sub directories */
end_comment

begin_decl_stmt
name|int
name|dadded
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* directory added flag */
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
name|tsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tape size in 0.1" units */
end_comment

begin_decl_stmt
name|long
name|esize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* estimated tape size, blocks */
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
name|char
modifier|*
name|processname
decl_stmt|;
end_decl_stmt

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
name|buf
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

begin_function_decl
name|char
modifier|*
name|ctime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|prdate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|atol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mark
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|add
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dirdump
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dump
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tapsrec
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dmpspc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dsrch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nullf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getsuffix
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|rawname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|dinode
modifier|*
name|getino
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|interrupt
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in case operator bangs on console */
end_comment

begin_define
define|#
directive|define
name|HOUR
value|(60L*60L)
end_define

begin_define
define|#
directive|define
name|DAY
value|(24L*HOUR)
end_define

begin_define
define|#
directive|define
name|YEAR
value|(365L*DAY)
end_define

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
comment|/* abort all of dump; don't attempt checkpointing*/
end_comment

begin_define
define|#
directive|define
name|NINCREM
value|"/etc/dumpdates"
end_define

begin_comment
comment|/*new format incremental info*/
end_comment

begin_define
define|#
directive|define
name|TEMP
value|"/etc/dtmp"
end_define

begin_comment
comment|/*output temp file*/
end_comment

begin_define
define|#
directive|define
name|TAPE
value|"/dev/rmt8"
end_define

begin_comment
comment|/* default tape device */
end_comment

begin_define
define|#
directive|define
name|DISK
value|"/dev/rrp1g"
end_define

begin_comment
comment|/* default disk */
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

begin_define
define|#
directive|define
name|DIALUP
value|"ttyd"
end_define

begin_comment
comment|/* prefix for dialups */
end_comment

begin_function_decl
name|struct
name|fstab
modifier|*
name|fstabsearch
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* search in fs_file and fs_spec */
end_comment

begin_comment
comment|/*  *	The contents of the file NINCREM is maintained both on  *	a linked list, and then (eventually) arrayified.  */
end_comment

begin_struct
struct|struct
name|idates
block|{
name|char
name|id_name
index|[
name|MAXNAMLEN
operator|+
literal|3
index|]
decl_stmt|;
name|char
name|id_incno
decl_stmt|;
name|time_t
name|id_ddate
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|itime
block|{
name|struct
name|idates
name|it_value
decl_stmt|;
name|struct
name|itime
modifier|*
name|it_next
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|itime
modifier|*
name|ithead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of the list version */
end_comment

begin_decl_stmt
name|int
name|nidates
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of records (might be zero) */
end_comment

begin_decl_stmt
name|int
name|idates_in
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* we have read the increment file */
end_comment

begin_decl_stmt
name|struct
name|idates
modifier|*
modifier|*
name|idatev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the arrayfied version */
end_comment

begin_define
define|#
directive|define
name|ITITERATE
parameter_list|(
name|i
parameter_list|,
name|ip
parameter_list|)
value|for (i = 0,ip = idatev[0]; i< nidates; i++, ip = idatev[i])
end_define

begin_comment
comment|/*  *	We catch these interrupts  */
end_comment

begin_function_decl
name|int
name|sighup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigquit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigill
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigtrap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigfpe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigkill
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigbus
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigsegv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigsys
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigalrm
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigterm
parameter_list|()
function_decl|;
end_function_decl

end_unit

