begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)config.h	8.2 (Berkeley) 4/22/94  */
end_comment

begin_comment
comment|/*  * The first boot and super blocks are given in absolute disk addresses.  * The byte-offset forms are preferred, as they don't imply a sector size.  */
end_comment

begin_define
define|#
directive|define
name|BBSIZE
value|8192
end_define

begin_define
define|#
directive|define
name|SBSIZE
value|8192
end_define

begin_comment
comment|/*  * The following two constants set the default block and fragment sizes.  * Both constants must be a power of 2 and meet the following constraints:  *	MINBSIZE<= DESBLKSIZE<= MAXBSIZE  *	sectorsize<= DESFRAGSIZE<= DESBLKSIZE  *	DESBLKSIZE / DESFRAGSIZE<= 8  */
end_comment

begin_define
define|#
directive|define
name|DFL_FRAGSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|DFL_BLKSIZE
value|8192
end_define

begin_comment
comment|/*  * Cylinder groups may have up to many cylinders. The actual  * number used depends upon how much information can be stored  * on a single cylinder. The default is to use 16 cylinders  * per group.  */
end_comment

begin_define
define|#
directive|define
name|DESCPG
value|16
end_define

begin_comment
comment|/* desired fs_cpg */
end_comment

begin_comment
comment|/*  * MINFREE gives the minimum acceptable percentage of file system  * blocks which may be free. If the freelist drops below this level  * only the superuser may continue to allocate blocks. This may  * be set to 0 if no reserve of free blocks is deemed necessary,  * however throughput drops by fifty percent if the file system  * is run at between 90% and 100% full; thus the default value of  * fs_minfree is 10%. With 10% free space, fragmentation is not a  * problem, so we choose to optimize for time.  */
end_comment

begin_define
define|#
directive|define
name|MINFREE
value|10
end_define

begin_define
define|#
directive|define
name|DEFAULTOPT
value|FS_OPTTIME
end_define

begin_comment
comment|/*  * Preference for optimization.  */
end_comment

begin_define
define|#
directive|define
name|FS_OPTTIME
value|0
end_define

begin_comment
comment|/* minimize allocation time */
end_comment

begin_define
define|#
directive|define
name|FS_OPTSPACE
value|1
end_define

begin_comment
comment|/* minimize disk fragmentation */
end_comment

begin_comment
comment|/*  * ROTDELAY gives the minimum number of milliseconds to initiate  * another disk transfer on the same cylinder. It is used in  * determining the rotationally optimal layout for disk blocks  * within a file; the default of fs_rotdelay is 4ms.  */
end_comment

begin_define
define|#
directive|define
name|ROTDELAY
value|4
end_define

begin_comment
comment|/*  * MAXCONTIG sets the default for the maximum number of blocks  * that may be allocated sequentially. Since UNIX drivers are  * not capable of scheduling multi-block transfers, this defaults  * to 1 (ie no contiguous blocks are allocated).  */
end_comment

begin_define
define|#
directive|define
name|MAXCONTIG
value|1
end_define

begin_comment
comment|/*  * MAXBLKPG determines the maximum number of data blocks which are  * placed in a single cylinder group. The default is one indirect  * block worth of data blocks.  */
end_comment

begin_define
define|#
directive|define
name|MAXBLKPG
parameter_list|(
name|bsize
parameter_list|)
value|((bsize) / sizeof(daddr_t))
end_define

begin_comment
comment|/*  * Each file system has a number of inodes statically allocated.  * We allocate one inode slot per NFPI fragments, expecting this  * to be far more than we will ever need.  */
end_comment

begin_define
define|#
directive|define
name|NFPI
value|4
end_define

begin_comment
comment|/*  * For each cylinder we keep track of the availability of blocks at different  * rotational positions, so that we can lay out the data to be picked  * up with minimum rotational latency.  NRPOS is the default number of  * rotational positions that we distinguish.  With NRPOS of 8 the resolution  * of our summary information is 2ms for a typical 3600 rpm drive.  */
end_comment

begin_define
define|#
directive|define
name|NRPOS
value|8
end_define

begin_comment
comment|/* number distinct rotational positions */
end_comment

begin_comment
comment|/*  * The following constants set the default block and segment size for a log  * structured file system.  Both must be powers of two and the segment size  * must be a multiple of the block size.  We also set minimum block and segment  * sizes.  */
end_comment

begin_define
define|#
directive|define
name|LFS_MINSEGSIZE
value|(64*1024)
end_define

begin_define
define|#
directive|define
name|DFL_LFSSEG
value|(1024 * 1024)
end_define

begin_define
define|#
directive|define
name|DFL_LFSSEG_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|DFL_LFSSEG_MASK
value|0xFFFFF
end_define

begin_define
define|#
directive|define
name|LFS_MINBLOCKSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|DFL_LFSBLOCK
value|4096
end_define

begin_define
define|#
directive|define
name|DFL_LFSBLOCK_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|DFL_LFSBLOCK_MASK
value|0xFFF
end_define

end_unit

