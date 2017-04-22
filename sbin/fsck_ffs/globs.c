begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_endif
unit|static const char copyright[] = "@(#) Copyright (c) 1980, 1986, 1993\n\ 	The Regents of the University of California.  All rights reserved.\n";
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

begin_endif
unit|static char sccsid[] = "@(#)main.c	8.6 (Berkeley) 5/14/95";
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/dinode.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ffs/fs.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"fsck.h"
end_include

begin_decl_stmt
name|long
name|readcnt
index|[
name|BT_NUMBUFTYPES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|totalreadcnt
index|[
name|BT_NUMBUFTYPES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timespec
name|readtime
index|[
name|BT_NUMBUFTYPES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timespec
name|totalreadtime
index|[
name|BT_NUMBUFTYPES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timespec
name|startprog
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|bufarea
name|sblk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file system superblock */
end_comment

begin_decl_stmt
name|struct
name|bufarea
modifier|*
name|pdirbp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current directory contents */
end_comment

begin_decl_stmt
name|struct
name|bufarea
modifier|*
name|pbp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current inode block */
end_comment

begin_decl_stmt
name|ino_t
name|cursnapshot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|dirhash
decl_stmt|,
name|inplast
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|numdirs
decl_stmt|,
name|listmax
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|countdirs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of directories we actually found */
end_comment

begin_decl_stmt
name|int
name|adjrefcnt
index|[
name|MIBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MIB command to adjust inode reference cnt */
end_comment

begin_decl_stmt
name|int
name|adjblkcnt
index|[
name|MIBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MIB command to adjust inode block count */
end_comment

begin_decl_stmt
name|int
name|adjndir
index|[
name|MIBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MIB command to adjust number of directories */
end_comment

begin_decl_stmt
name|int
name|adjnbfree
index|[
name|MIBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MIB command to adjust number of free blocks */
end_comment

begin_decl_stmt
name|int
name|adjnifree
index|[
name|MIBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MIB command to adjust number of free inodes */
end_comment

begin_decl_stmt
name|int
name|adjnffree
index|[
name|MIBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MIB command to adjust number of free frags */
end_comment

begin_decl_stmt
name|int
name|adjnumclusters
index|[
name|MIBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MIB command to adjust number of free clusters */
end_comment

begin_decl_stmt
name|int
name|freefiles
index|[
name|MIBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MIB command to free a set of files */
end_comment

begin_decl_stmt
name|int
name|freedirs
index|[
name|MIBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MIB command to free a set of directories */
end_comment

begin_decl_stmt
name|int
name|freeblks
index|[
name|MIBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MIB command to free a set of data blocks */
end_comment

begin_decl_stmt
name|struct
name|fsck_cmd
name|cmd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sysctl file system update commands */
end_comment

begin_decl_stmt
name|char
name|snapname
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* when doing snapshots, the name of the file */
end_comment

begin_decl_stmt
name|char
modifier|*
name|cdevname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of device being checked */
end_comment

begin_decl_stmt
name|long
name|dev_bsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* computed value of DEV_BSIZE */
end_comment

begin_decl_stmt
name|long
name|secsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* actual disk sector size */
end_comment

begin_decl_stmt
name|u_int
name|real_dev_bsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* actual disk sector size, not overridden */
end_comment

begin_decl_stmt
name|char
name|nflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* assume a no response */
end_comment

begin_decl_stmt
name|char
name|yflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* assume a yes response */
end_comment

begin_decl_stmt
name|int
name|bkgrdflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use a snapshot to run on an active system */
end_comment

begin_decl_stmt
name|ufs2_daddr_t
name|bflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* location of alternate super block */
end_comment

begin_decl_stmt
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output debugging info */
end_comment

begin_decl_stmt
name|int
name|Eflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* delete empty data blocks */
end_comment

begin_decl_stmt
name|int
name|Zflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* zero empty data blocks */
end_comment

begin_decl_stmt
name|int
name|inoopt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* trim out unused inodes */
end_comment

begin_decl_stmt
name|char
name|ckclean
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* only do work if not cleanly unmounted */
end_comment

begin_decl_stmt
name|int
name|cvtlevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* convert to newer file system format */
end_comment

begin_decl_stmt
name|int
name|bkgrdcheck
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* determine if background check is possible */
end_comment

begin_decl_stmt
name|int
name|bkgrdsumadj
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* whether the kernel have ability to adjust superblock summary */
end_comment

begin_decl_stmt
name|char
name|usedsoftdep
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* just fix soft dependency inconsistencies */
end_comment

begin_decl_stmt
name|char
name|preen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* just fix normal inconsistencies */
end_comment

begin_decl_stmt
name|char
name|rerun
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rerun fsck. Only used in non-preen mode */
end_comment

begin_decl_stmt
name|int
name|returntosingle
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 => return to single user mode on exit */
end_comment

begin_decl_stmt
name|char
name|resolved
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cleared if unresolved changes => not clean */
end_comment

begin_decl_stmt
name|char
name|havesb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* superblock has been read */
end_comment

begin_decl_stmt
name|char
name|skipclean
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* skip clean file systems if preening */
end_comment

begin_decl_stmt
name|int
name|fsmodified
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 => write done to file system */
end_comment

begin_decl_stmt
name|int
name|fsreadfd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file descriptor for reading file system */
end_comment

begin_decl_stmt
name|int
name|fswritefd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file descriptor for writing file system */
end_comment

begin_decl_stmt
name|int
name|surrender
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Give up if reads fail */
end_comment

begin_decl_stmt
name|int
name|wantrestart
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Restart fsck on early termination */
end_comment

begin_decl_stmt
name|ufs2_daddr_t
name|maxfsblock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of blocks in the file system */
end_comment

begin_decl_stmt
name|char
modifier|*
name|blockmap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to primary blk allocation map */
end_comment

begin_decl_stmt
name|ino_t
name|maxino
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of inodes in file system */
end_comment

begin_decl_stmt
name|ino_t
name|lfdir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lost& found directory inode number */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|lfname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lost& found directory name */
end_comment

begin_decl_stmt
name|int
name|lfmode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lost& found directory creation mode */
end_comment

begin_decl_stmt
name|ufs2_daddr_t
name|n_blks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of blocks in use */
end_comment

begin_decl_stmt
name|ino_t
name|n_files
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of files in use */
end_comment

begin_decl_stmt
specifier|volatile
name|sig_atomic_t
name|got_siginfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* received a SIGINFO */
end_comment

begin_decl_stmt
specifier|volatile
name|sig_atomic_t
name|got_sigalarm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* received a SIGALRM */
end_comment

begin_decl_stmt
name|struct
name|ufs1_dinode
name|ufs1_zino
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ufs2_dinode
name|ufs2_zino
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|fsckinit
parameter_list|(
name|void
parameter_list|)
block|{
name|bzero
argument_list|(
name|readcnt
argument_list|,
sizeof|sizeof
argument_list|(
name|long
argument_list|)
operator|*
name|BT_NUMBUFTYPES
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|totalreadcnt
argument_list|,
sizeof|sizeof
argument_list|(
name|long
argument_list|)
operator|*
name|BT_NUMBUFTYPES
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|readtime
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|timespec
argument_list|)
operator|*
name|BT_NUMBUFTYPES
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|totalreadtime
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|timespec
argument_list|)
operator|*
name|BT_NUMBUFTYPES
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
operator|&
name|startprog
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|timespec
argument_list|)
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
operator|&
name|sblk
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|bufarea
argument_list|)
argument_list|)
expr_stmt|;
name|pdirbp
operator|=
name|NULL
expr_stmt|;
name|pbp
operator|=
name|NULL
expr_stmt|;
name|cursnapshot
operator|=
literal|0
expr_stmt|;
name|listmax
operator|=
name|numdirs
operator|=
name|dirhash
operator|=
name|inplast
operator|=
literal|0
expr_stmt|;
name|countdirs
operator|=
literal|0
expr_stmt|;
name|bzero
argument_list|(
name|adjrefcnt
argument_list|,
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|*
name|MIBSIZE
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|adjblkcnt
argument_list|,
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|*
name|MIBSIZE
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|adjndir
argument_list|,
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|*
name|MIBSIZE
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|adjnbfree
argument_list|,
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|*
name|MIBSIZE
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|adjnifree
argument_list|,
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|*
name|MIBSIZE
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|adjnffree
argument_list|,
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|*
name|MIBSIZE
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|adjnumclusters
argument_list|,
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|*
name|MIBSIZE
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|freefiles
argument_list|,
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|*
name|MIBSIZE
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|freedirs
argument_list|,
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|*
name|MIBSIZE
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|freeblks
argument_list|,
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|*
name|MIBSIZE
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
operator|&
name|cmd
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|fsck_cmd
argument_list|)
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|snapname
argument_list|,
sizeof|sizeof
argument_list|(
name|char
argument_list|)
operator|*
name|BUFSIZ
argument_list|)
expr_stmt|;
name|cdevname
operator|=
name|NULL
expr_stmt|;
name|dev_bsize
operator|=
literal|0
expr_stmt|;
name|secsize
operator|=
literal|0
expr_stmt|;
name|real_dev_bsize
operator|=
literal|0
expr_stmt|;
name|bkgrdsumadj
operator|=
literal|0
expr_stmt|;
name|usedsoftdep
operator|=
literal|0
expr_stmt|;
name|rerun
operator|=
literal|0
expr_stmt|;
name|returntosingle
operator|=
literal|0
expr_stmt|;
name|resolved
operator|=
literal|0
expr_stmt|;
name|havesb
operator|=
literal|0
expr_stmt|;
name|fsmodified
operator|=
literal|0
expr_stmt|;
name|fsreadfd
operator|=
literal|0
expr_stmt|;
name|fswritefd
operator|=
literal|0
expr_stmt|;
name|maxfsblock
operator|=
literal|0
expr_stmt|;
name|blockmap
operator|=
name|NULL
expr_stmt|;
name|maxino
operator|=
literal|0
expr_stmt|;
name|lfdir
operator|=
literal|0
expr_stmt|;
name|lfname
operator|=
literal|"lost+found"
expr_stmt|;
name|lfmode
operator|=
literal|0700
expr_stmt|;
name|n_blks
operator|=
literal|0
expr_stmt|;
name|n_files
operator|=
literal|0
expr_stmt|;
name|got_siginfo
operator|=
literal|0
expr_stmt|;
name|got_sigalarm
operator|=
literal|0
expr_stmt|;
name|bzero
argument_list|(
operator|&
name|ufs1_zino
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|ufs1_dinode
argument_list|)
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
operator|&
name|ufs2_zino
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|ufs2_dinode
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

