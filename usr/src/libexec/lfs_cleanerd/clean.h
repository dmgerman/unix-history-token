begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The LFS user-level library will be used when writing cleaners and  * checkers for LFS file systems.  It will have facilities  * for finding and parsing LFS segments.  */
end_comment

begin_define
define|#
directive|define
name|IFILE_NAME
value|"ifile"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|(1)
end_define

begin_define
define|#
directive|define
name|FALSE
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
modifier|*
name|fi_lfsp
decl_stmt|;
comment|/* superblock */
comment|/* 					 * shared cleaner info data  					 * (from top of ifile)  					 */
name|CLEANERINFO
modifier|*
name|fi_cip
decl_stmt|;
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
name|u_long
name|fi_ifile_length
decl_stmt|;
comment|/* length of the ifile */
block|}
name|FS_INFO
typedef|;
end_typedef

begin_define
define|#
directive|define
name|fsid
value|(fsp->fi_statfsp->f_fsid)
end_define

begin_define
define|#
directive|define
name|statfsp
value|(fsp->fi_statfsp)
end_define

begin_define
define|#
directive|define
name|lfsp
value|(fsp->fi_lfsp)
end_define

begin_define
define|#
directive|define
name|cip
value|(fsp->fi_cip)
end_define

begin_define
define|#
directive|define
name|segusep
value|(fsp->fi_segusep)
end_define

begin_define
define|#
directive|define
name|ifilep
value|(fsp->fi_ifilep)
end_define

begin_define
define|#
directive|define
name|ifile_count
value|(fsp->fi_ifile_count)
end_define

begin_define
define|#
directive|define
name|ifile_length
value|(fsp->fi_ifile_length)
end_define

begin_comment
comment|/*   * XXX: size (in bytes) of a segment  *	should lfs_bsize be fsbtodb(fs,1), blksize(fs), or lfs_dsize?   */
end_comment

begin_define
define|#
directive|define
name|seg_size
parameter_list|(
name|fs
parameter_list|)
value|((fs)->lfs_ssize<<(fs)->lfs_bshift)
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
value|((da)<<(fs)->fi_daddr_shift)
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
value|((byte)>>(fs)->fi_daddr_shift)
end_define

begin_define
define|#
directive|define
name|CLEANSIZE
parameter_list|(
name|fs
parameter_list|)
value|(CLEANSIZE_SU(fs)<< fs->lfs_bshift)
end_define

begin_define
define|#
directive|define
name|SEGTABSIZE
parameter_list|(
name|fs
parameter_list|)
value|(SEGTABSIZE_SU(fs)<< fs->lfs_bshift)
end_define

begin_define
define|#
directive|define
name|IFILE_ENTRY
parameter_list|(
name|fs
parameter_list|,
define|if, i)	((IFILE*)((caddr_t)(if) + \ 	(fs)->lfs_bsize*((i)/(fs)->lfs_ifpb) + \ 	sizeof(IFILE)*((i)%(fs)->lfs_ifpb)))
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
value|((SEGUSE*)((caddr_t)(su) + \ 	(fs)->lfs_bsize*((i)/(fs)->lfs_sepb) + \ 	sizeof(IFILE)*((i)%(fs)->lfs_sepb)))
end_define

begin_comment
comment|/*  * fs_getmntinfo:  *  *    This function will get information on all mounted file systems  * with the given type.  It will return the number of mounted file  * systems with the right type.  It will return in *buf a pointer to  * the array of statfs structures.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fs_getmntinfo
name|__P
argument_list|(
operator|(
expr|struct
name|statfs
operator|*
operator|*
name|buf
operator|,
name|int
name|type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * get_fs_info:  *  * get all the information available on a file system  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|get_fs_info
name|__P
argument_list|(
operator|(
expr|struct
name|statfs
operator|*
name|lstatfsp
operator|,
name|FS_INFO
operator|*
operator|*
name|fspp
operator|,
name|int
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_fs_info
name|__P
argument_list|(
operator|(
name|FS_INFO
operator|*
name|fsp
operator|,
name|int
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * get_superblock:   *    gets the superblock from disk (possibly in face of errors)   */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|get_superblock
name|__P
argument_list|(
operator|(
name|FS_INFO
operator|*
name|fsp
operator|,
expr|struct
name|lfs
operator|*
name|sbp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * get_ifile:   *    This function will map the ifile into memory.  It returns  * NULL on failure.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|get_ifile
name|__P
argument_list|(
operator|(
name|FS_INFO
operator|*
name|fsp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * segmapv:  *  *   This function will scan a segment and return a list of  *<inode, blocknum> pairs which indicate which blocks were  * contained as live data within the segment at some point  * (it may have "died" since then).  Any given pair will be   * listed at most once.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lfs_segmapv
name|__P
argument_list|(
operator|(
name|FS_INFO
operator|*
name|fsp
operator|,
name|int
name|seg
operator|,
name|caddr_t
name|seg_buf
operator|,
name|BLOCK_INFO
operator|*
operator|*
name|blocks
operator|,
name|int
operator|*
name|bcount
operator|,
name|INODE_INFO
operator|*
operator|*
name|inodes
operator|,
name|int
operator|*
name|icount
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * this will parse a partial segment and create a vector of block_info's  * for live data blocks for live inodes.  It will not include blocks or   * inodes from files with new version numbers.    */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|pseg_blocks
name|__P
argument_list|(
operator|(
name|FS_INFO
operator|*
name|fsp
operator|,
name|int
name|seg
operator|,
name|SEGSUM
operator|*
name|s
operator|,
name|caddr_t
name|seg_buf
operator|,
name|BLOCK_INFO
operator|*
operator|*
name|blocks
operator|,
name|int
operator|*
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * this will parse a partial segment and create a vector of inode_info's  * for live inodes.  It will not include blocks or inodes from files   * with new version numbers.    */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|pseg_inodes
name|__P
argument_list|(
operator|(
name|FS_INFO
operator|*
name|fsp
operator|,
name|int
name|seg
operator|,
name|SEGSUM
operator|*
name|s
operator|,
name|caddr_t
name|seg_buf
operator|,
name|INODE_INFO
operator|*
operator|*
name|inodes
operator|,
name|int
operator|*
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * return the size of the partial segment in bytes.   */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|pseg_size
name|__P
argument_list|(
operator|(
name|FS_INFO
operator|*
name|fsp
operator|,
name|SEGSUM
operator|*
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * join block list b with list a (eliminating duplicates), leaving result  * in list a.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|pseg_bjoin
name|__P
argument_list|(
operator|(
name|FS_INFO
operator|*
name|fsp
operator|,
name|BLOCK_INFO
operator|*
operator|*
name|ablocks
operator|,
name|int
operator|*
name|acount
operator|,
name|BLOCK_INFO
operator|*
name|bblocks
operator|,
name|int
name|bcount
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * join inode list b with list a (eliminating duplicates), leaving result  * in list a.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|pseg_ijoin
name|__P
argument_list|(
operator|(
name|FS_INFO
operator|*
name|fsp
operator|,
name|INODE_INFO
operator|*
operator|*
name|ainodes
operator|,
name|int
operator|*
name|acount
operator|,
name|INODE_INFO
operator|*
name|binodes
operator|,
name|int
name|bcount
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* is the segsum block valid? return TRUE if it is, FALSE otherwise */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|segsum_valid
name|__P
argument_list|(
operator|(
name|FS_INFO
operator|*
name|fsp
operator|,
name|SEGSUM
operator|*
name|ssp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * pseg_valid:  *  * returns 1 if the partial segment is valid, and 0 if it is invalid.  * it uses the checksums to verify validity.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pseg_valid
name|__P
argument_list|(
operator|(
name|FS_INFO
operator|*
name|fsp
operator|,
name|SEGSUM
operator|*
name|ssp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * pseg_finfos:  *   * get array of FINFO pointers for partial segment  * return the array in finfos, and the size of the array in count  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|pseg_finfos
name|__P
argument_list|(
operator|(
name|FS_INFO
operator|*
name|fsp
operator|,
name|SEGSUM
operator|*
name|ssp
operator|,
name|FINFO
operator|*
operator|*
operator|*
name|finfos
operator|,
name|int
operator|*
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * blocksize:  *  * returns the size (in bytes) of a (logical) block.  * this is used because lfs uses different block sizes, depending  * on the logical # of the block.  Lfs uses various sizes so  * it doesn't need fragments.  */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|blocksize
name|__P
argument_list|(
operator|(
name|FS_INFO
operator|*
name|fsp
operator|,
name|int
name|index
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * finfo_size:  *  * returns the size in bytes of an FINFO structure   */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|finfo_size
name|__P
argument_list|(
operator|(
name|FINFO
operator|*
name|finfop
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Simple, general purpose, fast checksum.  Data must be short-aligned.  * Returns a u_long in case we ever want to do something more rigorous.  *  * XXX  * Use the TCP/IP checksum instead.  */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|cksum
name|__P
argument_list|(
operator|(
specifier|register
name|void
operator|*
name|str
operator|,
specifier|register
name|size_t
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * read a segment into a memory buffer  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mmap_segment
name|__P
argument_list|(
operator|(
name|FS_INFO
operator|*
name|fsp
operator|,
name|int
name|segment
operator|,
name|caddr_t
operator|*
name|seg_buf
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|munmap_segment
name|__P
argument_list|(
operator|(
name|FS_INFO
operator|*
name|fsp
operator|,
name|caddr_t
name|seg_buf
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * USEFUL DEBUGGING TOOLS:  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|print_IFILE
name|__P
argument_list|(
operator|(
name|IFILE
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_SEGUSE
name|__P
argument_list|(
operator|(
name|SEGUSE
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_CLEANERINFO
name|__P
argument_list|(
operator|(
name|CLEANERINFO
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_SEGSUM
name|__P
argument_list|(
operator|(
name|SEGSUM
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_time_t
name|__P
argument_list|(
operator|(
name|time_t
name|t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_BLOCK_INFO
name|__P
argument_list|(
operator|(
name|BLOCK_INFO
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_INODE_INFO
name|__P
argument_list|(
operator|(
name|INODE_INFO
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_FINFO
name|__P
argument_list|(
operator|(
name|FINFO
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_lfs
name|__P
argument_list|(
operator|(
expr|struct
name|lfs
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

