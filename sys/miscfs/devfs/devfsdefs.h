begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|DEVFS_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DBPRINT
parameter_list|(
name|A
parameter_list|)
value|printf(A)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DBPRINT
parameter_list|(
name|A
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Written by Julian Elischer (julian@DIALIX.oz.au)  *  * $Header: /home/ncvs/src/sys/miscfs/devfs/devfsdefs.h,v 1.11 1996/11/21 07:19:00 julian Exp $  */
end_comment

begin_comment
comment|/* first a couple of defines for compatibility with inodes */
end_comment

begin_define
define|#
directive|define
name|ISUID
value|04000
end_define

begin_comment
comment|/* set user identifier when exec'ing */
end_comment

begin_define
define|#
directive|define
name|ISGID
value|02000
end_define

begin_comment
comment|/* set group identifier when exec'ing */
end_comment

begin_define
define|#
directive|define
name|ISVTX
value|01000
end_define

begin_comment
comment|/* save execution information on exit */
end_comment

begin_define
define|#
directive|define
name|IREAD
value|0400
end_define

begin_comment
comment|/* read permission */
end_comment

begin_define
define|#
directive|define
name|IWRITE
value|0200
end_define

begin_comment
comment|/* write permission */
end_comment

begin_define
define|#
directive|define
name|IEXEC
value|0100
end_define

begin_comment
comment|/* execute permission */
end_comment

begin_define
define|#
directive|define
name|ILOCKED
value|0x0001
end_define

begin_comment
comment|/* inode is locked */
end_comment

begin_define
define|#
directive|define
name|IWANT
value|0x0002
end_define

begin_comment
comment|/* some process waiting on lock */
end_comment

begin_define
define|#
directive|define
name|IRENAME
value|0x0004
end_define

begin_comment
comment|/* inode is being renamed */
end_comment

begin_define
define|#
directive|define
name|IUPD
value|0x0010
end_define

begin_comment
comment|/* file has been modified */
end_comment

begin_define
define|#
directive|define
name|IACC
value|0x0020
end_define

begin_comment
comment|/* inode access time to be updated */
end_comment

begin_define
define|#
directive|define
name|ICHG
value|0x0040
end_define

begin_comment
comment|/* inode has been changed */
end_comment

begin_define
define|#
directive|define
name|IMOD
value|0x0080
end_define

begin_comment
comment|/* inode has been modified */
end_comment

begin_define
define|#
directive|define
name|ISHLOCK
value|0x0100
end_define

begin_comment
comment|/* file has shared lock */
end_comment

begin_define
define|#
directive|define
name|IEXLOCK
value|0x0200
end_define

begin_comment
comment|/* file has exclusive lock */
end_comment

begin_define
define|#
directive|define
name|ILWAIT
value|0x0400
end_define

begin_comment
comment|/* someone waiting on file lock */
end_comment

begin_comment
comment|/*  * Lock and unlock inodes.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_define
define|#
directive|define
name|DNLOCK
parameter_list|(
name|ip
parameter_list|)
value|{ \ 	while ((ip)->i_flag& ILOCKED) { \ 		(ip)->i_flag |= IWANT; \ 		(void) sleep((caddr_t)(ip), PINOD); \ 	} \ 	(ip)->i_flag |= ILOCKED; \ }
end_define

begin_define
define|#
directive|define
name|DNUNLOCK
parameter_list|(
name|ip
parameter_list|)
value|{ \ 	(ip)->i_flag&= ~ILOCKED; \ 	if ((ip)->i_flag&IWANT) { \ 		(ip)->i_flag&= ~IWANT; \ 		wakeup((caddr_t)(ip)); \ 	} \ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DNLOCK
parameter_list|(
name|ip
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DNUNLOCK
parameter_list|(
name|ip
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEVMAXNAMESIZE
value|32
end_define

begin_define
define|#
directive|define
name|DEVMAXPATHSIZE
value|128
end_define

begin_define
define|#
directive|define
name|DEV_DIR
value|1
end_define

begin_define
define|#
directive|define
name|DEV_BDEV
value|2
end_define

begin_define
define|#
directive|define
name|DEV_CDEV
value|3
end_define

begin_define
define|#
directive|define
name|DEV_DDEV
value|4
end_define

begin_define
define|#
directive|define
name|DEV_ALIAS
value|5
end_define

begin_define
define|#
directive|define
name|DEV_SLNK
value|6
end_define

begin_define
define|#
directive|define
name|DEV_PIPE
value|7
end_define

begin_decl_stmt
specifier|extern
name|vop_t
modifier|*
modifier|*
name|devfs_vnodeop_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* our own vector array for dirs */
end_comment

begin_decl_stmt
specifier|extern
name|vop_t
modifier|*
modifier|*
name|dev_spec_vnodeop_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* our own vector array for devs */
end_comment

begin_typedef
typedef|typedef
name|struct
name|dev_name
modifier|*
name|devnm_p
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|devnode
modifier|*
name|dn_p
typedef|;
end_typedef

begin_struct
struct|struct
name|devnode
comment|/* the equivalent of an INODE */
block|{
name|u_short
name|type
decl_stmt|;
name|int
name|flags
decl_stmt|;
comment|/* more inode compatible for now */
comment|/*XXXkill*/
name|u_short
name|mode
decl_stmt|;
comment|/* basically inode compatible (drwxrwxrwx) */
name|u_short
name|uid
decl_stmt|;
comment|/* basically inode compatible  */
name|u_short
name|gid
decl_stmt|;
comment|/* basically inode compatible  */
name|struct
name|timespec
name|atime
decl_stmt|;
comment|/* time of last access */
name|struct
name|timespec
name|mtime
decl_stmt|;
comment|/* time of last modification */
name|struct
name|timespec
name|ctime
decl_stmt|;
comment|/* time file changed */
name|int
name|links
decl_stmt|;
comment|/* how many file links does this node have? */
name|struct
name|devfsmount
modifier|*
name|dvm
decl_stmt|;
comment|/* the mount structure for this 'plane' */
name|struct
name|vnode
modifier|*
name|vn
decl_stmt|;
comment|/* address of last vnode that represented us */
name|u_long
name|vn_id
decl_stmt|;
comment|/* make sure we have the right vnode */
name|int
function_decl|(
modifier|*
modifier|*
modifier|*
name|ops
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* yuk... pointer to pointer(s) to funcs */
name|int
name|len
decl_stmt|;
comment|/* of any associated info (e.g. dir data) */
name|devnm_p
name|linklist
decl_stmt|;
comment|/* circular list of hardlinks to this node */
name|devnm_p
name|last_lookup
decl_stmt|;
comment|/* name I was last looked up from */
name|dn_p
name|nextsibling
decl_stmt|;
comment|/* the list of equivelent nodes */
name|dn_p
modifier|*
name|prevsiblingp
decl_stmt|;
comment|/* backpointer for the above */
union|union
name|typeinfo
block|{
struct|struct
block|{
name|struct
name|cdevsw
modifier|*
name|cdevsw
decl_stmt|;
name|dev_t
name|dev
decl_stmt|;
block|}
name|Cdev
struct|;
struct|struct
block|{
name|struct
name|bdevsw
modifier|*
name|bdevsw
decl_stmt|;
name|dev_t
name|dev
decl_stmt|;
block|}
name|Bdev
struct|;
struct|struct
block|{
name|int
function_decl|(
modifier|*
modifier|*
modifier|*
name|ops
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* duplicate, used in dev_add_node */
name|int
name|arg
decl_stmt|;
block|}
name|Ddev
struct|;
struct|struct
block|{
name|devnm_p
name|dirlist
decl_stmt|;
name|devnm_p
modifier|*
name|dirlast
decl_stmt|;
name|dn_p
name|parent
decl_stmt|;
name|devnm_p
name|myname
decl_stmt|;
comment|/* my entry in .. */
name|int
name|entrycount
decl_stmt|;
block|}
name|Dir
struct|;
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* must be allocated separately */
name|int
name|namelen
decl_stmt|;
block|}
name|Slnk
struct|;
struct|struct
block|{
name|devnm_p
name|realthing
decl_stmt|;
name|devnm_p
name|next
decl_stmt|;
block|}
name|Alias
struct|;
struct|struct
block|{
name|struct
name|socket
modifier|*
name|sock
decl_stmt|;
block|}
name|Pipe
struct|;
block|}
name|by
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|devnode
name|devnode_t
typedef|;
end_typedef

begin_struct
struct|struct
name|dev_name
block|{
comment|/*-----------------------directory entry fields-------------*/
name|char
name|name
index|[
name|DEVMAXNAMESIZE
index|]
decl_stmt|;
name|dn_p
name|dnp
decl_stmt|;
comment|/* the "inode" (devnode) pointer */
name|dn_p
name|parent
decl_stmt|;
comment|/* backpointer to the directory itself */
name|devnm_p
name|next
decl_stmt|;
comment|/* next object in this directory */
name|devnm_p
modifier|*
name|prevp
decl_stmt|;
comment|/* previous pointer in directory linked list */
name|devnm_p
name|nextlink
decl_stmt|;
comment|/* next hardlink to this node */
name|devnm_p
modifier|*
name|prevlinkp
decl_stmt|;
comment|/* previous hardlink pointer for this node */
comment|/*-----------------------aliases or backing nodes----------*/
union|union
block|{
struct|struct
block|{
name|devnm_p
name|aliases
decl_stmt|;
comment|/* aliase chain (kill with us)*/
block|}
name|back
struct|;
struct|struct
block|{
name|devnm_p
name|realthing
decl_stmt|;
comment|/* ptr to the backing node */
block|}
name|front
struct|;
block|}
name|as
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|dev_name
name|devnm_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|devfs_up_and_going
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|devnm_p
name|dev_root
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Rules for front nodes:  * Dirs hava a strict 1:1 relationship with their OWN devnode  * Symlinks similarly  * Device Nodes ALWAYS point to the devnode that is linked  * to the Backing node. (with a ref count)  */
end_comment

begin_comment
comment|/*  * DEVFS specific per/mount information, used to link a monted fs to a  * particular 'plane' of front nodes.  */
end_comment

begin_struct
struct|struct
name|devfsmount
block|{
name|struct
name|mount
modifier|*
name|mount
decl_stmt|;
comment|/* vfs mount struct for this fs	*/
name|devnm_p
name|plane_root
decl_stmt|;
comment|/* the root of this 'plane'	*/
name|int
name|flags
decl_stmt|;
comment|/* usefule some day 8-) 	*/
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dev_vn_data
block|{
name|char
name|magic
index|[
literal|6
index|]
decl_stmt|;
comment|/* = "devfs" if correct */
name|devnm_p
name|front
decl_stmt|;
name|devnm_p
name|back
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeops
name|spec_vnodeops
decl_stmt|,
name|devfs_vnodeops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Prototypes for DEVFS virtual filesystem operations  */
end_comment

begin_include
include|#
directive|include
file|<miscfs/devfs/devfs_proto.h>
end_include

end_unit

