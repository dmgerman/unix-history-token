begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Written by Paul Popelka (paulp@uts.amdahl.com)  *   * You can do anything you want with this software, just don't say you wrote  * it, and don't remove this notice.  *   * This software is provided "as is".  *   * The author supplies this software to be publicly redistributed on the  * understanding that the author is not responsible for the correct  * functioning of this software in any circumstances and is not liable for  * any damages caused by this software.  *   * October 1992  *   *	from NetBSD:	denode.h,v 1.2 1993/09/07 15:41:31 ws Exp  *	$Id$  */
end_comment

begin_comment
comment|/*  * This is the pc filesystem specific portion of the vnode structure. To  * describe a file uniquely the de_dirclust, de_diroffset, and  * de_de.deStartCluster fields are used.  de_dirclust contains the cluster  * number of the directory cluster containing the entry for a file or  * directory.  de_diroffset is the index into the cluster for the entry  * describing a file or directory.  de_de.deStartCluster is the number of  * the first cluster of the file or directory.  Now to describe the quirks  * of the pc filesystem. - Clusters 0 and 1 are reserved. - The first  * allocatable cluster is 2. - The root directory is of fixed size and all  * blocks that make it up are contiguous. - Cluster 0 refers to the root  * directory when it is found in the startcluster field of a directory  * entry that points to another directory. - Cluster 0 implies a 0 length  * file when found in the start cluster field of a directory entry that  * points to a file. - You can't use the cluster number 0 to derive the  * address of the root directory. - Multiple directory entries can point to  * a directory. The entry in the parent directory points to a child  * directory.  Any directories in the child directory contain a ".." entry  * that points back to the child.  The child directory itself contains a  * "." entry that points to itself. - The root directory does not contain a  * "." or ".." entry. - Directory entries for directories are never changed  * once they are created (except when removed).  The size stays 0, and the  * last modification time is never changed.  This is because so many  * directory entries can point to the physical clusters that make up a  * directory.  It would lead to an update nightmare. - The length field in  * a directory entry pointing to a directory contains 0 (always).  The only  * way to find the end of a directory is to follow the cluster chain until  * the "last cluster" marker is found. My extensions to make this house of  * cards work.  These apply only to the in memory copy of the directory  * entry. - A reference count for each denode will be kept since dos  * doesn't keep such things.  */
end_comment

begin_comment
comment|/*  * Internal pseudo-offset for (nonexistent) directory entry for the root  * dir in the root dir  */
end_comment

begin_define
define|#
directive|define
name|MSDOSFSROOT_OFS
value|0x1fffffff
end_define

begin_comment
comment|/*  * The fat cache structure. fc_fsrcn is the filesystem relative cluster  * number that corresponds to the file relative cluster number in this  * structure (fc_frcn).  */
end_comment

begin_struct
struct|struct
name|fatcache
block|{
name|u_short
name|fc_frcn
decl_stmt|;
comment|/* file relative cluster number */
name|u_short
name|fc_fsrcn
decl_stmt|;
comment|/* filesystem relative cluster number */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The fat entry cache as it stands helps make extending files a "quick"  * operation by avoiding having to scan the fat to discover the last  * cluster of the file. The cache also helps sequential reads by  * remembering the last cluster read from the file.  This also prevents us  * from having to rescan the fat to find the next cluster to read.  This  * cache is probably pretty worthless if a file is opened by multiple  * processes.  */
end_comment

begin_define
define|#
directive|define
name|FC_SIZE
value|2
end_define

begin_comment
comment|/* number of entries in the cache */
end_comment

begin_define
define|#
directive|define
name|FC_LASTMAP
value|0
end_define

begin_comment
comment|/* entry the last call to pcbmap() resolved 				 * to */
end_comment

begin_define
define|#
directive|define
name|FC_LASTFC
value|1
end_define

begin_comment
comment|/* entry for the last cluster in the file */
end_comment

begin_define
define|#
directive|define
name|FCE_EMPTY
value|0xffff
end_define

begin_comment
comment|/* doesn't represent an actual cluster # */
end_comment

begin_comment
comment|/*  * Set a slot in the fat cache.  */
end_comment

begin_define
define|#
directive|define
name|fc_setcache
parameter_list|(
name|dep
parameter_list|,
name|slot
parameter_list|,
name|frcn
parameter_list|,
name|fsrcn
parameter_list|)
define|\
value|(dep)->de_fc[slot].fc_frcn = frcn; \ 	(dep)->de_fc[slot].fc_fsrcn = fsrcn;
end_define

begin_comment
comment|/*  * This is the in memory variant of a dos directory entry.  It is usually  * contained within a vnode.  */
end_comment

begin_struct
struct|struct
name|denode
block|{
name|struct
name|denode
modifier|*
name|de_chain
index|[
literal|2
index|]
decl_stmt|;
comment|/* hash chain ptrs */
name|struct
name|vnode
modifier|*
name|de_vnode
decl_stmt|;
comment|/* addr of vnode we are part of */
name|struct
name|vnode
modifier|*
name|de_devvp
decl_stmt|;
comment|/* vnode of blk dev we live on */
name|u_long
name|de_flag
decl_stmt|;
comment|/* flag bits */
name|dev_t
name|de_dev
decl_stmt|;
comment|/* device where direntry lives */
name|u_long
name|de_dirclust
decl_stmt|;
comment|/* cluster of the directory file containing this entry */
name|u_long
name|de_diroffset
decl_stmt|;
comment|/* ordinal of this entry in the directory */
name|long
name|de_refcnt
decl_stmt|;
comment|/* reference count */
name|struct
name|msdosfsmount
modifier|*
name|de_pmp
decl_stmt|;
comment|/* addr of our mount struct */
name|struct
name|lockf
modifier|*
name|de_lockf
decl_stmt|;
comment|/* byte level lock list */
name|long
name|de_spare0
decl_stmt|;
comment|/* current lock holder */
name|long
name|de_spare1
decl_stmt|;
comment|/* lock wanter */
name|struct
name|direntry
name|de_de
decl_stmt|;
comment|/* the actual directory entry */
name|struct
name|fatcache
name|de_fc
index|[
name|FC_SIZE
index|]
decl_stmt|;
comment|/* fat cache */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Values for the de_flag field of the denode.  */
end_comment

begin_define
define|#
directive|define
name|DELOCKED
value|0x0001
end_define

begin_comment
comment|/* directory entry is locked */
end_comment

begin_define
define|#
directive|define
name|DEWANT
value|0x0002
end_define

begin_comment
comment|/* someone wants this de */
end_comment

begin_define
define|#
directive|define
name|DERENAME
value|0x0004
end_define

begin_comment
comment|/* de is being renamed */
end_comment

begin_define
define|#
directive|define
name|DEUPD
value|0x0008
end_define

begin_comment
comment|/* file has been modified */
end_comment

begin_define
define|#
directive|define
name|DESHLOCK
value|0x0010
end_define

begin_comment
comment|/* file has shared lock */
end_comment

begin_define
define|#
directive|define
name|DEEXLOCK
value|0x0020
end_define

begin_comment
comment|/* file has exclusive lock */
end_comment

begin_define
define|#
directive|define
name|DELWAIT
value|0x0040
end_define

begin_comment
comment|/* someone waiting on file lock */
end_comment

begin_define
define|#
directive|define
name|DEMOD
value|0x0080
end_define

begin_comment
comment|/* denode wants to be written back to disk */
end_comment

begin_comment
comment|/*  * Shorthand macros used to reference fields in the direntry contained in  * the denode structure.  */
end_comment

begin_define
define|#
directive|define
name|de_Name
value|de_de.deName
end_define

begin_define
define|#
directive|define
name|de_Extension
value|de_de.deExtension
end_define

begin_define
define|#
directive|define
name|de_Attributes
value|de_de.deAttributes
end_define

begin_define
define|#
directive|define
name|de_Reserved
value|de_de.deReserved
end_define

begin_define
define|#
directive|define
name|de_Time
value|de_de.deTime
end_define

begin_define
define|#
directive|define
name|de_Date
value|de_de.deDate
end_define

begin_define
define|#
directive|define
name|de_StartCluster
value|de_de.deStartCluster
end_define

begin_define
define|#
directive|define
name|de_FileSize
value|de_de.deFileSize
end_define

begin_define
define|#
directive|define
name|de_forw
value|de_chain[0]
end_define

begin_define
define|#
directive|define
name|de_back
value|de_chain[1]
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|VTODE
parameter_list|(
name|vp
parameter_list|)
value|((struct denode *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|DETOV
parameter_list|(
name|de
parameter_list|)
value|((de)->de_vnode)
end_define

begin_define
define|#
directive|define
name|DELOCK
parameter_list|(
name|de
parameter_list|)
value|delock(de)
end_define

begin_define
define|#
directive|define
name|DEUNLOCK
parameter_list|(
name|de
parameter_list|)
value|deunlock(de)
end_define

begin_define
define|#
directive|define
name|DEUPDAT
parameter_list|(
name|dep
parameter_list|,
name|t
parameter_list|,
name|waitfor
parameter_list|)
define|\
value|if (dep->de_flag& DEUPD) \ 		(void) deupdat(dep, t, waitfor);
end_define

begin_define
define|#
directive|define
name|DETIMES
parameter_list|(
name|dep
parameter_list|,
name|t
parameter_list|)
define|\
value|if (dep->de_flag& DEUPD) { \ 		(dep)->de_flag |= DEMOD; \ 		unix2dostime(t, (union dosdate *)&dep->de_Date, \ 			(union dostime *)&dep->de_Time); \ 		(dep)->de_flag&= ~DEUPD; \ 	}
end_define

begin_comment
comment|/*  * This overlays the fid sturcture (see mount.h)  */
end_comment

begin_struct
struct|struct
name|defid
block|{
name|u_short
name|defid_len
decl_stmt|;
comment|/* length of structure */
name|u_short
name|defid_pad
decl_stmt|;
comment|/* force long alignment */
name|u_long
name|defid_dirclust
decl_stmt|;
comment|/* cluster this dir entry came from */
name|u_long
name|defid_dirofs
decl_stmt|;
comment|/* index of entry within the cluster */
comment|/* u_long	defid_gen;	/* generation number */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Prototypes for MSDOSFS vnode operations  */
end_comment

begin_decl_stmt
name|int
name|msdosfs_lookup
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_create
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
expr|struct
name|vattr
operator|*
name|vap
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_mknod
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
expr|struct
name|vattr
operator|*
name|vap
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_open
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|mode
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_close
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|fflag
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_access
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|mode
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_getattr
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|vattr
operator|*
name|vap
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_setattr
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|vattr
operator|*
name|vap
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_read
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|,
name|int
name|ioflag
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_write
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|,
name|int
name|ioflag
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_ioctl
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|command
operator|,
name|caddr_t
name|data
operator|,
name|int
name|fflag
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_select
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|which
operator|,
name|int
name|fflags
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_mmap
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|fflags
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_fsync
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|fflags
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
name|int
name|waitfor
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_seek
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|off_t
name|oldoff
operator|,
name|off_t
name|newoff
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_remove
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_link
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_rename
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
name|fndp
operator|,
expr|struct
name|nameidata
operator|*
name|tdnp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_mkdir
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
expr|struct
name|vattr
operator|*
name|vap
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_rmdir
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_symlink
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
expr|struct
name|vattr
operator|*
name|vap
operator|,
name|char
operator|*
name|target
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_readdir
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
name|int
operator|*
name|eofflagp
operator|,
name|u_int
operator|*
name|cookies
operator|,
name|int
name|ncookies
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_readlink
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_abortop
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
name|ndp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_inactive
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_reclaim
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_lock
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_unlock
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_bmap
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|daddr_t
name|bn
operator|,
expr|struct
name|vnode
operator|*
operator|*
name|vpp
operator|,
name|daddr_t
operator|*
name|bnp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_strategy
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
name|bp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_print
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_islocked
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_advlock
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|caddr_t
name|id
operator|,
name|int
name|op
operator|,
expr|struct
name|flock
operator|*
name|fl
operator|,
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Internal service routine prototypes.  */
end_comment

begin_decl_stmt
name|int
name|deget
name|__P
argument_list|(
operator|(
expr|struct
name|msdosfsmount
operator|*
name|pmp
operator|,
name|u_long
name|dirclust
operator|,
name|u_long
name|diroffset
operator|,
expr|struct
name|direntry
operator|*
name|direntptr
operator|,
expr|struct
name|denode
operator|*
operator|*
name|depp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(KERNEL) */
end_comment

end_unit

