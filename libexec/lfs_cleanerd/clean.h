begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)clean.h	8.2 (Berkeley) 5/4/95  *	$Id: clean.h,v 1.6 1997/02/22 14:21:44 peter Exp $  */
end_comment

begin_comment
comment|/*  * The LFS user-level library will be used when writing cleaners and  * checkers for LFS file systems.  It will have facilities for finding  * and parsing LFS segments.  */
end_comment

begin_define
define|#
directive|define
name|DUMP_SUM_HEADER
value|0x0001
end_define

begin_define
define|#
directive|define
name|DUMP_INODE_ADDRS
value|0x0002
end_define

begin_define
define|#
directive|define
name|DUMP_FINFOS
value|0x0004
end_define

begin_define
define|#
directive|define
name|DUMP_ALL
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|IFILE_NAME
value|"ifile"
end_define

begin_comment
comment|/*  * Cleaner parameters  *	BUSY_LIM: lower bound of the number of segments currently available  *		as a percentage of the total number of free segments possibly  *		available.  *	IDLE_LIM: Same as BUSY_LIM but used when the system is idle.  *	MIN_SEGS: Minimum number of segments you should always have.  *		I have no idea what this should be, but it should probably  *		be a function of lfsp.  *	NUM_TO_CLEAN: Number of segments to clean at once.  Again, this  *		should probably be based on the file system size and how  *		full or empty the segments being cleaned are.  */
end_comment

begin_define
define|#
directive|define
name|BUSY_LIM
value|0.50
end_define

begin_define
define|#
directive|define
name|IDLE_LIM
value|0.90
end_define

begin_define
define|#
directive|define
name|MIN_SEGS
parameter_list|(
name|lfsp
parameter_list|)
value|(5)
end_define

begin_define
define|#
directive|define
name|NUM_TO_CLEAN
parameter_list|(
name|fsp
parameter_list|)
value|(1)
end_define

begin_define
define|#
directive|define
name|MAXLOADS
value|3
end_define

begin_define
define|#
directive|define
name|ONE_MIN
value|0
end_define

begin_define
define|#
directive|define
name|FIVE_MIN
value|1
end_define

begin_define
define|#
directive|define
name|FIFTEEN_MIN
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|fs_info
block|{
name|struct
name|statfs
modifier|*
name|fi_statfsp
decl_stmt|;
comment|/* fsstat info from getfsstat */
name|struct
name|lfs
name|fi_lfs
decl_stmt|;
comment|/* superblock */
name|CLEANERINFO
modifier|*
name|fi_cip
decl_stmt|;
comment|/* Cleaner info from ifile */
name|SEGUSE
modifier|*
name|fi_segusep
decl_stmt|;
comment|/* segment usage table (from ifile) */
name|IFILE
modifier|*
name|fi_ifilep
decl_stmt|;
comment|/* ifile table (from ifile) */
name|u_long
name|fi_daddr_shift
decl_stmt|;
comment|/* shift to get byte offset of daddr */
name|u_long
name|fi_ifile_count
decl_stmt|;
comment|/* # entries in the ifile table */
name|off_t
name|fi_ifile_length
decl_stmt|;
comment|/* length of the ifile */
block|}
name|FS_INFO
typedef|;
end_typedef

begin_comment
comment|/*  * XXX: size (in bytes) of a segment  *	should lfs_bsize be fsbtodb(fs,1), blksize(fs), or lfs_dsize?  */
end_comment

begin_define
define|#
directive|define
name|seg_size
parameter_list|(
name|fs
parameter_list|)
value|((fs)->lfs_ssize<< (fs)->lfs_bshift)
end_define

begin_comment
comment|/* daddr -> byte offset */
end_comment

begin_define
define|#
directive|define
name|datobyte
parameter_list|(
name|fs
parameter_list|,
name|da
parameter_list|)
value|((da)<< (fs)->fi_daddr_shift)
end_define

begin_define
define|#
directive|define
name|bytetoda
parameter_list|(
name|fs
parameter_list|,
name|byte
parameter_list|)
value|((byte)>> (fs)->fi_daddr_shift)
end_define

begin_define
define|#
directive|define
name|CLEANSIZE
parameter_list|(
name|fsp
parameter_list|)
value|(fsp->fi_lfs.lfs_cleansz<< fsp->fi_lfs.lfs_bshift)
end_define

begin_define
define|#
directive|define
name|SEGTABSIZE
parameter_list|(
name|fsp
parameter_list|)
value|(fsp->fi_lfs.lfs_segtabsz<< fsp->fi_lfs.lfs_bshift)
end_define

begin_define
define|#
directive|define
name|IFILE_ENTRY
parameter_list|(
name|fs
parameter_list|,
define|if, i) \ 	((IFILE *)((caddr_t)(if) + ((i) / (fs)->lfs_ifpb<< (fs)->lfs_bshift)) \ 	+ (i) % (fs)->lfs_ifpb)
end_define

begin_define
define|#
directive|define
name|SEGUSE_ENTRY
parameter_list|(
name|fs
parameter_list|,
name|su
parameter_list|,
name|i
parameter_list|)
define|\
value|((SEGUSE *)((caddr_t)(su) + (fs)->lfs_bsize * ((i) / (fs)->lfs_sepb)) +\ 	(i) % (fs)->lfs_sepb)
end_define

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|dump_summary
name|__P
argument_list|(
operator|(
expr|struct
name|lfs
operator|*
operator|,
name|SEGSUM
operator|*
operator|,
name|u_long
operator|,
name|daddr_t
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|err
name|__P
argument_list|(
operator|(
specifier|const
name|int
operator|,
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
name|fs_getmntinfo
name|__P
argument_list|(
operator|(
expr|struct
name|statfs
operator|*
operator|*
operator|,
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
name|get
name|__P
argument_list|(
operator|(
name|int
operator|,
name|off_t
operator|,
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FS_INFO
modifier|*
name|get_fs_info
name|__P
argument_list|(
operator|(
expr|struct
name|statfs
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lfs_segmapv
name|__P
argument_list|(
operator|(
name|FS_INFO
operator|*
operator|,
name|int
operator|,
name|caddr_t
operator|,
name|BLOCK_INFO
operator|*
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mmap_segment
name|__P
argument_list|(
operator|(
name|FS_INFO
operator|*
operator|,
name|int
operator|,
name|caddr_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|munmap_segment
name|__P
argument_list|(
operator|(
name|FS_INFO
operator|*
operator|,
name|caddr_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|reread_fs_info
name|__P
argument_list|(
operator|(
name|FS_INFO
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|toss
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|int
operator|*
operator|,
name|size_t
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
specifier|const
name|void
operator|*
argument_list|,
specifier|const
name|void
operator|*
argument_list|,
specifier|const
name|void
operator|*
argument_list|)
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * USEFUL DEBUGGING FUNCTIONS:  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VERBOSE
end_ifdef

begin_define
define|#
directive|define
name|PRINT_FINFO
parameter_list|(
name|fp
parameter_list|,
name|ip
parameter_list|)
value|{ \ 	(void)printf("    %s %s%d version %d nblocks %d\n", \ 	    (ip)->if_version> (fp)->fi_version ? "TOSSING" : "KEEPING", \ 	    "FINFO for inode: ", (fp)->fi_ino, \ 	    (fp)->fi_version, (fp)->fi_nblocks); \ 	fflush(stdout); \ }
end_define

begin_define
define|#
directive|define
name|PRINT_INODE
parameter_list|(
name|b
parameter_list|,
name|bip
parameter_list|)
value|{ \ 	(void) printf("\t%s inode: %d daddr: 0x%lx create: %s\n", \ 	    b ? "KEEPING" : "TOSSING", (bip)->bi_inode, (bip)->bi_daddr, \ 	    ctime((time_t *)&(bip)->bi_segcreate)); \ 	fflush(stdout); \ }
end_define

begin_define
define|#
directive|define
name|PRINT_BINFO
parameter_list|(
name|bip
parameter_list|)
value|{ \ 	(void)printf("\tinode: %d lbn: %d daddr: 0x%lx create: %s\n", \ 	    (bip)->bi_inode, (bip)->bi_lbn, (bip)->bi_daddr, \ 	    ctime((time_t *)&(bip)->bi_segcreate)); \ 	fflush(stdout); \ }
end_define

begin_define
define|#
directive|define
name|PRINT_SEGUSE
parameter_list|(
name|sup
parameter_list|,
name|n
parameter_list|)
value|{ \ 	(void)printf("Segment %d nbytes=%lu\tflags=%c%c%c ninos=%d nsums=%d lastmod: %s\n", \ 			n, (sup)->su_nbytes, \ 			(sup)->su_flags& SEGUSE_DIRTY ? 'D' : 'C', \ 			(sup)->su_flags& SEGUSE_ACTIVE ? 'A' : ' ', \ 			(sup)->su_flags& SEGUSE_SUPERBLOCK ? 'S' : ' ', \ 			(sup)->su_ninos, (sup)->su_nsums, \ 			ctime((time_t *)&(sup)->su_lastmod)); \ 	fflush(stdout); \ }
end_define

begin_decl_stmt
name|void
name|dump_super
name|__P
argument_list|(
operator|(
expr|struct
name|lfs
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dump_cleaner_info
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_SEGSUM
name|__P
argument_list|(
operator|(
expr|struct
name|lfs
operator|*
operator|,
name|SEGSUM
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_CLEANERINFO
name|__P
argument_list|(
operator|(
name|CLEANERINFO
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PRINT_FINFO
parameter_list|(
name|fp
parameter_list|,
name|ip
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PRINT_INODE
parameter_list|(
name|b
parameter_list|,
name|bip
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PRINT_BINFO
parameter_list|(
name|bip
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PRINT_SEGUSE
parameter_list|(
name|sup
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|dump_cleaner_info
parameter_list|(
name|cip
parameter_list|)
end_define

begin_define
define|#
directive|define
name|dump_super
parameter_list|(
name|lfsp
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

end_unit

