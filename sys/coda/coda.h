begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   *             Coda: an Experimental Distributed File System  *                              Release 3.1  *   *           Copyright (c) 1987-1998 Carnegie Mellon University  *                          All Rights Reserved  *   * Permission  to  use, copy, modify and distribute this software and its  * documentation is hereby granted,  provided  that  both  the  copyright  * notice  and  this  permission  notice  appear  in  all  copies  of the  * software, derivative works or  modified  versions,  and  any  portions  * thereof, and that both notices appear in supporting documentation, and  * that credit is given to Carnegie Mellon University  in  all  documents  * and publicity pertaining to direct or indirect use of this code or its  * derivatives.  *   * CODA IS AN EXPERIMENTAL SOFTWARE SYSTEM AND IS  KNOWN  TO  HAVE  BUGS,  * SOME  OF  WHICH MAY HAVE SERIOUS CONSEQUENCES.  CARNEGIE MELLON ALLOWS  * FREE USE OF THIS SOFTWARE IN ITS "AS IS" CONDITION.   CARNEGIE  MELLON  * DISCLAIMS  ANY  LIABILITY  OF  ANY  KIND  FOR  ANY  DAMAGES WHATSOEVER  * RESULTING DIRECTLY OR INDIRECTLY FROM THE USE OF THIS SOFTWARE  OR  OF  * ANY DERIVATIVE WORK.  *   * Carnegie  Mellon  encourages  users  of  this  software  to return any  * improvements or extensions that  they  make,  and  to  grant  Carnegie  * Mellon the rights to redistribute these changes without encumbrance.  *   * 	@(#) src/sys/coda/coda.h,v 1.1.1.1 1998/08/29 21:14:52 rvb Exp $   * $FreeBSD$  *   */
end_comment

begin_comment
comment|/*  *  * Based on cfs.h from Mach, but revamped for increased simplicity.  * Linux modifications by Peter Braam, Aug 1996  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CODA_HEADER_
end_ifndef

begin_define
define|#
directive|define
name|_CODA_HEADER_
end_define

begin_comment
comment|/* Catch new _KERNEL defn for NetBSD */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CODA_MAXSYMLINKS
end_ifndef

begin_define
define|#
directive|define
name|CODA_MAXSYMLINKS
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DJGPP
argument_list|)
operator|||
name|defined
argument_list|(
name|__CYGWIN32__
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|u_long
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|u_short
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_long
name|ino_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_long
name|dev_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|caddr_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|DOS
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|__int64
name|u_quad_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|u_quad_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|inline
end_define

begin_struct
struct|struct
name|timespec
block|{
name|long
name|ts_sec
decl_stmt|;
name|long
name|ts_nsec
decl_stmt|;
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* DJGPP but not _KERNEL */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|u_quad_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !DJGPP */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
end_if

begin_define
define|#
directive|define
name|cdev_t
value|u_quad_t
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_UQUAD_T_
argument_list|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|__GLIBC__
argument_list|)
operator|||
name|__GLIBC__
operator|<
literal|2
operator|)
end_if

begin_define
define|#
directive|define
name|_UQUAD_T_
value|1
end_define

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|u_quad_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cdev_t
value|udev_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__CYGWIN32__
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|u_int8_t
typedef|;
end_typedef

begin_struct
struct|struct
name|timespec
block|{
name|time_t
name|tv_sec
decl_stmt|;
comment|/* seconds */
name|long
name|tv_nsec
decl_stmt|;
comment|/* nanoseconds */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Cfs constants  */
end_comment

begin_define
define|#
directive|define
name|CODA_MAXNAMLEN
value|255
end_define

begin_define
define|#
directive|define
name|CODA_MAXPATHLEN
value|1024
end_define

begin_define
define|#
directive|define
name|CODA_MAXSYMLINK
value|10
end_define

begin_comment
comment|/* these are Coda's version of O_RDONLY etc combinations  * to deal with VFS open modes  */
end_comment

begin_define
define|#
directive|define
name|C_O_READ
value|0x001
end_define

begin_define
define|#
directive|define
name|C_O_WRITE
value|0x002
end_define

begin_define
define|#
directive|define
name|C_O_TRUNC
value|0x010
end_define

begin_define
define|#
directive|define
name|C_O_EXCL
value|0x100
end_define

begin_define
define|#
directive|define
name|C_O_CREAT
value|0x200
end_define

begin_comment
comment|/* these are to find mode bits in Venus */
end_comment

begin_define
define|#
directive|define
name|C_M_READ
value|00400
end_define

begin_define
define|#
directive|define
name|C_M_WRITE
value|00200
end_define

begin_comment
comment|/* for access Venus will use */
end_comment

begin_define
define|#
directive|define
name|C_A_C_OK
value|8
end_define

begin_comment
comment|/* Test for writing upon create.  */
end_comment

begin_define
define|#
directive|define
name|C_A_R_OK
value|4
end_define

begin_comment
comment|/* Test for read permission.  */
end_comment

begin_define
define|#
directive|define
name|C_A_W_OK
value|2
end_define

begin_comment
comment|/* Test for write permission.  */
end_comment

begin_define
define|#
directive|define
name|C_A_X_OK
value|1
end_define

begin_comment
comment|/* Test for execute permission.  */
end_comment

begin_define
define|#
directive|define
name|C_A_F_OK
value|0
end_define

begin_comment
comment|/* Test for existence.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VENUS_DIRENT_T_
end_ifndef

begin_define
define|#
directive|define
name|_VENUS_DIRENT_T_
value|1
end_define

begin_struct
struct|struct
name|venus_dirent
block|{
name|unsigned
name|long
name|d_fileno
decl_stmt|;
comment|/* file number of entry */
name|unsigned
name|short
name|d_reclen
decl_stmt|;
comment|/* length of this record */
name|char
name|d_type
decl_stmt|;
comment|/* file type, see below */
name|char
name|d_namlen
decl_stmt|;
comment|/* length of string in d_name */
name|char
name|d_name
index|[
name|CODA_MAXNAMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* name must be no longer than this */
block|}
struct|;
end_struct

begin_undef
undef|#
directive|undef
name|DIRSIZ
end_undef

begin_define
define|#
directive|define
name|DIRSIZ
parameter_list|(
name|dp
parameter_list|)
value|((sizeof (struct venus_dirent) - (CODA_MAXNAMLEN+1)) + \                          (((dp)->d_namlen+1 + 3)&~ 3))
end_define

begin_comment
comment|/*  * File types  */
end_comment

begin_define
define|#
directive|define
name|CDT_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|CDT_FIFO
value|1
end_define

begin_define
define|#
directive|define
name|CDT_CHR
value|2
end_define

begin_define
define|#
directive|define
name|CDT_DIR
value|4
end_define

begin_define
define|#
directive|define
name|CDT_BLK
value|6
end_define

begin_define
define|#
directive|define
name|CDT_REG
value|8
end_define

begin_define
define|#
directive|define
name|CDT_LNK
value|10
end_define

begin_define
define|#
directive|define
name|CDT_SOCK
value|12
end_define

begin_define
define|#
directive|define
name|CDT_WHT
value|14
end_define

begin_comment
comment|/*  * Convert between stat structure types and directory types.  */
end_comment

begin_define
define|#
directive|define
name|IFTOCDT
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& 0170000)>> 12)
end_define

begin_define
define|#
directive|define
name|CDTTOIF
parameter_list|(
name|dirtype
parameter_list|)
value|((dirtype)<< 12)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_FID_T_
end_ifndef

begin_define
define|#
directive|define
name|_FID_T_
value|1
end_define

begin_typedef
typedef|typedef
name|u_long
name|VolumeId
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_long
name|VnodeId
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_long
name|Unique_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_long
name|FileVersion
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_VICEFID_T_
end_ifndef

begin_define
define|#
directive|define
name|_VICEFID_T_
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|ViceFid
block|{
name|VolumeId
name|Volume
decl_stmt|;
name|VnodeId
name|Vnode
decl_stmt|;
name|Unique_t
name|Unique
decl_stmt|;
block|}
name|ViceFid
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VICEFID */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_function
specifier|static
name|__inline__
name|ino_t
name|coda_f2i
parameter_list|(
name|struct
name|ViceFid
modifier|*
name|fid
parameter_list|)
block|{
if|if
condition|(
operator|!
name|fid
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|fid
operator|->
name|Vnode
operator|==
literal|0xfffffffe
operator|||
name|fid
operator|->
name|Vnode
operator|==
literal|0xffffffff
condition|)
return|return
operator|(
operator|(
name|fid
operator|->
name|Volume
operator|<<
literal|20
operator|)
operator||
operator|(
name|fid
operator|->
name|Unique
operator|&
literal|0xfffff
operator|)
operator|)
return|;
else|else
return|return
operator|(
name|fid
operator|->
name|Unique
operator|+
operator|(
name|fid
operator|->
name|Vnode
operator|<<
literal|10
operator|)
operator|+
operator|(
name|fid
operator|->
name|Volume
operator|<<
literal|20
operator|)
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|coda_f2i
parameter_list|(
name|fid
parameter_list|)
define|\
value|((fid) ? ((fid)->Unique + ((fid)->Vnode<<10) + ((fid)->Volume<<20)) : 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__BIT_TYPES_DEFINED__
end_ifndef

begin_define
define|#
directive|define
name|u_int32_t
value|unsigned int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_VUID_T_
end_ifndef

begin_define
define|#
directive|define
name|_VUID_T_
end_define

begin_typedef
typedef|typedef
name|u_int32_t
name|vuid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|vgid_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_VUID_T_ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CODACRED_T_
end_ifndef

begin_define
define|#
directive|define
name|_CODACRED_T_
end_define

begin_struct
struct|struct
name|coda_cred
block|{
name|vuid_t
name|cr_uid
decl_stmt|,
name|cr_euid
decl_stmt|,
name|cr_suid
decl_stmt|,
name|cr_fsuid
decl_stmt|;
comment|/* Real, efftve, set, fs uid*/
name|vgid_t
name|cr_groupid
decl_stmt|,
name|cr_egid
decl_stmt|,
name|cr_sgid
decl_stmt|,
name|cr_fsgid
decl_stmt|;
comment|/* same for groups */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_VENUS_VATTR_T_
end_ifndef

begin_define
define|#
directive|define
name|_VENUS_VATTR_T_
end_define

begin_comment
comment|/*  * Vnode types.  VNON means no type.  */
end_comment

begin_enum
enum|enum
name|coda_vtype
block|{
name|C_VNON
block|,
name|C_VREG
block|,
name|C_VDIR
block|,
name|C_VBLK
block|,
name|C_VCHR
block|,
name|C_VLNK
block|,
name|C_VSOCK
block|,
name|C_VFIFO
block|,
name|C_VBAD
block|}
enum|;
end_enum

begin_struct
struct|struct
name|coda_vattr
block|{
name|int
name|va_type
decl_stmt|;
comment|/* vnode type (for create) */
name|u_short
name|va_mode
decl_stmt|;
comment|/* files access mode and type */
name|short
name|va_nlink
decl_stmt|;
comment|/* number of references to file */
name|vuid_t
name|va_uid
decl_stmt|;
comment|/* owner user id */
name|vgid_t
name|va_gid
decl_stmt|;
comment|/* owner group id */
name|long
name|va_fileid
decl_stmt|;
comment|/* file id */
name|u_quad_t
name|va_size
decl_stmt|;
comment|/* file size in bytes */
name|long
name|va_blocksize
decl_stmt|;
comment|/* blocksize preferred for i/o */
name|struct
name|timespec
name|va_atime
decl_stmt|;
comment|/* time of last access */
name|struct
name|timespec
name|va_mtime
decl_stmt|;
comment|/* time of last modification */
name|struct
name|timespec
name|va_ctime
decl_stmt|;
comment|/* time file changed */
name|u_long
name|va_gen
decl_stmt|;
comment|/* generation number of file */
name|u_long
name|va_flags
decl_stmt|;
comment|/* flags defined for file */
name|cdev_t
name|va_rdev
decl_stmt|;
comment|/* device special file represents */
name|u_quad_t
name|va_bytes
decl_stmt|;
comment|/* bytes of disk space held by file */
name|u_quad_t
name|va_filerev
decl_stmt|;
comment|/* file modification number */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Kernel<--> Venus communications.  */
end_comment

begin_define
define|#
directive|define
name|CODA_ROOT
value|2
end_define

begin_define
define|#
directive|define
name|CODA_SYNC
value|3
end_define

begin_define
define|#
directive|define
name|CODA_OPEN
value|4
end_define

begin_define
define|#
directive|define
name|CODA_CLOSE
value|5
end_define

begin_define
define|#
directive|define
name|CODA_IOCTL
value|6
end_define

begin_define
define|#
directive|define
name|CODA_GETATTR
value|7
end_define

begin_define
define|#
directive|define
name|CODA_SETATTR
value|8
end_define

begin_define
define|#
directive|define
name|CODA_ACCESS
value|9
end_define

begin_define
define|#
directive|define
name|CODA_LOOKUP
value|10
end_define

begin_define
define|#
directive|define
name|CODA_CREATE
value|11
end_define

begin_define
define|#
directive|define
name|CODA_REMOVE
value|12
end_define

begin_define
define|#
directive|define
name|CODA_LINK
value|13
end_define

begin_define
define|#
directive|define
name|CODA_RENAME
value|14
end_define

begin_define
define|#
directive|define
name|CODA_MKDIR
value|15
end_define

begin_define
define|#
directive|define
name|CODA_RMDIR
value|16
end_define

begin_define
define|#
directive|define
name|CODA_READDIR
value|17
end_define

begin_define
define|#
directive|define
name|CODA_SYMLINK
value|18
end_define

begin_define
define|#
directive|define
name|CODA_READLINK
value|19
end_define

begin_define
define|#
directive|define
name|CODA_FSYNC
value|20
end_define

begin_define
define|#
directive|define
name|CODA_INACTIVE
value|21
end_define

begin_define
define|#
directive|define
name|CODA_VGET
value|22
end_define

begin_define
define|#
directive|define
name|CODA_SIGNAL
value|23
end_define

begin_define
define|#
directive|define
name|CODA_REPLACE
value|24
end_define

begin_define
define|#
directive|define
name|CODA_FLUSH
value|25
end_define

begin_define
define|#
directive|define
name|CODA_PURGEUSER
value|26
end_define

begin_define
define|#
directive|define
name|CODA_ZAPFILE
value|27
end_define

begin_define
define|#
directive|define
name|CODA_ZAPDIR
value|28
end_define

begin_define
define|#
directive|define
name|CODA_PURGEFID
value|30
end_define

begin_define
define|#
directive|define
name|CODA_OPEN_BY_PATH
value|31
end_define

begin_define
define|#
directive|define
name|CODA_RESOLVE
value|32
end_define

begin_define
define|#
directive|define
name|CODA_REINTEGRATE
value|33
end_define

begin_define
define|#
directive|define
name|CODA_NCALLS
value|34
end_define

begin_define
define|#
directive|define
name|DOWNCALL
parameter_list|(
name|opcode
parameter_list|)
value|(opcode>= CODA_REPLACE&& opcode<= CODA_PURGEFID)
end_define

begin_define
define|#
directive|define
name|VC_MAXDATASIZE
value|8192
end_define

begin_define
define|#
directive|define
name|VC_MAXMSGSIZE
value|sizeof(union inputArgs)+sizeof(union outputArgs) +\                             VC_MAXDATASIZE
end_define

begin_define
define|#
directive|define
name|CIOC_KERNEL_VERSION
value|_IOWR('c', 10, sizeof (int))
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* don't care about kernel version number */
end_comment

begin_define
define|#
directive|define
name|CODA_KERNEL_VERSION
value|0
end_define

begin_comment
comment|/* The old venus 4.6 compatible interface */
end_comment

begin_define
define|#
directive|define
name|CODA_KERNEL_VERSION
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* venus_lookup gets an extra parameter to aid windows.*/
end_comment

begin_define
define|#
directive|define
name|CODA_KERNEL_VERSION
value|2
end_define

begin_comment
comment|/*  *        Venus<-> Coda  RPC arguments  */
end_comment

begin_struct
struct|struct
name|coda_in_hdr
block|{
name|unsigned
name|long
name|opcode
decl_stmt|;
name|unsigned
name|long
name|unique
decl_stmt|;
comment|/* Keep multiple outstanding msgs distinct */
name|u_short
name|pid
decl_stmt|;
comment|/* Common to all */
name|u_short
name|pgid
decl_stmt|;
comment|/* Common to all */
name|u_short
name|sid
decl_stmt|;
comment|/* Common to all */
name|struct
name|coda_cred
name|cred
decl_stmt|;
comment|/* Common to all */
block|}
struct|;
end_struct

begin_comment
comment|/* Really important that opcode and unique are 1st two fields! */
end_comment

begin_struct
struct|struct
name|coda_out_hdr
block|{
name|unsigned
name|long
name|opcode
decl_stmt|;
name|unsigned
name|long
name|unique
decl_stmt|;
name|unsigned
name|long
name|result
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* coda_root: NO_IN */
end_comment

begin_struct
struct|struct
name|coda_root_out
block|{
name|struct
name|coda_out_hdr
name|oh
decl_stmt|;
name|ViceFid
name|VFid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coda_root_in
block|{
name|struct
name|coda_in_hdr
name|in
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* coda_sync: */
end_comment

begin_comment
comment|/* Nothing needed for coda_sync */
end_comment

begin_comment
comment|/* coda_open: */
end_comment

begin_struct
struct|struct
name|coda_open_in
block|{
name|struct
name|coda_in_hdr
name|ih
decl_stmt|;
name|ViceFid
name|VFid
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coda_open_out
block|{
name|struct
name|coda_out_hdr
name|oh
decl_stmt|;
name|cdev_t
name|dev
decl_stmt|;
name|ino_t
name|inode
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* coda_close: */
end_comment

begin_struct
struct|struct
name|coda_close_in
block|{
name|struct
name|coda_in_hdr
name|ih
decl_stmt|;
name|ViceFid
name|VFid
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coda_close_out
block|{
name|struct
name|coda_out_hdr
name|out
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* coda_ioctl: */
end_comment

begin_struct
struct|struct
name|coda_ioctl_in
block|{
name|struct
name|coda_in_hdr
name|ih
decl_stmt|;
name|ViceFid
name|VFid
decl_stmt|;
name|int
name|cmd
decl_stmt|;
name|int
name|len
decl_stmt|;
name|int
name|rwflag
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
comment|/* Place holder for data. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coda_ioctl_out
block|{
name|struct
name|coda_out_hdr
name|oh
decl_stmt|;
name|int
name|len
decl_stmt|;
name|caddr_t
name|data
decl_stmt|;
comment|/* Place holder for data. */
block|}
struct|;
end_struct

begin_comment
comment|/* coda_getattr: */
end_comment

begin_struct
struct|struct
name|coda_getattr_in
block|{
name|struct
name|coda_in_hdr
name|ih
decl_stmt|;
name|ViceFid
name|VFid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coda_getattr_out
block|{
name|struct
name|coda_out_hdr
name|oh
decl_stmt|;
name|struct
name|coda_vattr
name|attr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* coda_setattr: NO_OUT */
end_comment

begin_struct
struct|struct
name|coda_setattr_in
block|{
name|struct
name|coda_in_hdr
name|ih
decl_stmt|;
name|ViceFid
name|VFid
decl_stmt|;
name|struct
name|coda_vattr
name|attr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coda_setattr_out
block|{
name|struct
name|coda_out_hdr
name|out
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* coda_access: NO_OUT */
end_comment

begin_struct
struct|struct
name|coda_access_in
block|{
name|struct
name|coda_in_hdr
name|ih
decl_stmt|;
name|ViceFid
name|VFid
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coda_access_out
block|{
name|struct
name|coda_out_hdr
name|out
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* lookup flags */
end_comment

begin_define
define|#
directive|define
name|CLU_CASE_SENSITIVE
value|0x01
end_define

begin_define
define|#
directive|define
name|CLU_CASE_INSENSITIVE
value|0x02
end_define

begin_comment
comment|/* coda_lookup: */
end_comment

begin_struct
struct|struct
name|coda_lookup_in
block|{
name|struct
name|coda_in_hdr
name|ih
decl_stmt|;
name|ViceFid
name|VFid
decl_stmt|;
name|int
name|name
decl_stmt|;
comment|/* Place holder for data. */
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coda_lookup_out
block|{
name|struct
name|coda_out_hdr
name|oh
decl_stmt|;
name|ViceFid
name|VFid
decl_stmt|;
name|int
name|vtype
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* coda_create: */
end_comment

begin_struct
struct|struct
name|coda_create_in
block|{
name|struct
name|coda_in_hdr
name|ih
decl_stmt|;
name|ViceFid
name|VFid
decl_stmt|;
name|struct
name|coda_vattr
name|attr
decl_stmt|;
name|int
name|excl
decl_stmt|;
name|int
name|mode
decl_stmt|;
name|int
name|name
decl_stmt|;
comment|/* Place holder for data. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coda_create_out
block|{
name|struct
name|coda_out_hdr
name|oh
decl_stmt|;
name|ViceFid
name|VFid
decl_stmt|;
name|struct
name|coda_vattr
name|attr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* coda_remove: NO_OUT */
end_comment

begin_struct
struct|struct
name|coda_remove_in
block|{
name|struct
name|coda_in_hdr
name|ih
decl_stmt|;
name|ViceFid
name|VFid
decl_stmt|;
name|int
name|name
decl_stmt|;
comment|/* Place holder for data. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coda_remove_out
block|{
name|struct
name|coda_out_hdr
name|out
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* coda_link: NO_OUT */
end_comment

begin_struct
struct|struct
name|coda_link_in
block|{
name|struct
name|coda_in_hdr
name|ih
decl_stmt|;
name|ViceFid
name|sourceFid
decl_stmt|;
comment|/* cnode to link *to* */
name|ViceFid
name|destFid
decl_stmt|;
comment|/* Directory in which to place link */
name|int
name|tname
decl_stmt|;
comment|/* Place holder for data. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coda_link_out
block|{
name|struct
name|coda_out_hdr
name|out
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* coda_rename: NO_OUT */
end_comment

begin_struct
struct|struct
name|coda_rename_in
block|{
name|struct
name|coda_in_hdr
name|ih
decl_stmt|;
name|ViceFid
name|sourceFid
decl_stmt|;
name|int
name|srcname
decl_stmt|;
name|ViceFid
name|destFid
decl_stmt|;
name|int
name|destname
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coda_rename_out
block|{
name|struct
name|coda_out_hdr
name|out
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* coda_mkdir: */
end_comment

begin_struct
struct|struct
name|coda_mkdir_in
block|{
name|struct
name|coda_in_hdr
name|ih
decl_stmt|;
name|ViceFid
name|VFid
decl_stmt|;
name|struct
name|coda_vattr
name|attr
decl_stmt|;
name|int
name|name
decl_stmt|;
comment|/* Place holder for data. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coda_mkdir_out
block|{
name|struct
name|coda_out_hdr
name|oh
decl_stmt|;
name|ViceFid
name|VFid
decl_stmt|;
name|struct
name|coda_vattr
name|attr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* coda_rmdir: NO_OUT */
end_comment

begin_struct
struct|struct
name|coda_rmdir_in
block|{
name|struct
name|coda_in_hdr
name|ih
decl_stmt|;
name|ViceFid
name|VFid
decl_stmt|;
name|int
name|name
decl_stmt|;
comment|/* Place holder for data. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coda_rmdir_out
block|{
name|struct
name|coda_out_hdr
name|out
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* coda_readdir: */
end_comment

begin_struct
struct|struct
name|coda_readdir_in
block|{
name|struct
name|coda_in_hdr
name|ih
decl_stmt|;
name|ViceFid
name|VFid
decl_stmt|;
name|int
name|count
decl_stmt|;
name|int
name|offset
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coda_readdir_out
block|{
name|struct
name|coda_out_hdr
name|oh
decl_stmt|;
name|int
name|size
decl_stmt|;
name|caddr_t
name|data
decl_stmt|;
comment|/* Place holder for data. */
block|}
struct|;
end_struct

begin_comment
comment|/* coda_symlink: NO_OUT */
end_comment

begin_struct
struct|struct
name|coda_symlink_in
block|{
name|struct
name|coda_in_hdr
name|ih
decl_stmt|;
name|ViceFid
name|VFid
decl_stmt|;
comment|/* Directory to put symlink in */
name|int
name|srcname
decl_stmt|;
name|struct
name|coda_vattr
name|attr
decl_stmt|;
name|int
name|tname
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coda_symlink_out
block|{
name|struct
name|coda_out_hdr
name|out
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* coda_readlink: */
end_comment

begin_struct
struct|struct
name|coda_readlink_in
block|{
name|struct
name|coda_in_hdr
name|ih
decl_stmt|;
name|ViceFid
name|VFid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coda_readlink_out
block|{
name|struct
name|coda_out_hdr
name|oh
decl_stmt|;
name|int
name|count
decl_stmt|;
name|caddr_t
name|data
decl_stmt|;
comment|/* Place holder for data. */
block|}
struct|;
end_struct

begin_comment
comment|/* coda_fsync: NO_OUT */
end_comment

begin_struct
struct|struct
name|coda_fsync_in
block|{
name|struct
name|coda_in_hdr
name|ih
decl_stmt|;
name|ViceFid
name|VFid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coda_fsync_out
block|{
name|struct
name|coda_out_hdr
name|out
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* coda_inactive: NO_OUT */
end_comment

begin_struct
struct|struct
name|coda_inactive_in
block|{
name|struct
name|coda_in_hdr
name|ih
decl_stmt|;
name|ViceFid
name|VFid
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* coda_vget: */
end_comment

begin_struct
struct|struct
name|coda_vget_in
block|{
name|struct
name|coda_in_hdr
name|ih
decl_stmt|;
name|ViceFid
name|VFid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coda_vget_out
block|{
name|struct
name|coda_out_hdr
name|oh
decl_stmt|;
name|ViceFid
name|VFid
decl_stmt|;
name|int
name|vtype
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* CODA_SIGNAL is out-of-band, doesn't need data. */
end_comment

begin_comment
comment|/* CODA_INVALIDATE is a venus->kernel call */
end_comment

begin_comment
comment|/* CODA_FLUSH is a venus->kernel call */
end_comment

begin_comment
comment|/* coda_purgeuser: */
end_comment

begin_comment
comment|/* CODA_PURGEUSER is a venus->kernel call */
end_comment

begin_struct
struct|struct
name|coda_purgeuser_out
block|{
name|struct
name|coda_out_hdr
name|oh
decl_stmt|;
name|struct
name|coda_cred
name|cred
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* coda_zapfile: */
end_comment

begin_comment
comment|/* CODA_ZAPFILE is a venus->kernel call */
end_comment

begin_struct
struct|struct
name|coda_zapfile_out
block|{
name|struct
name|coda_out_hdr
name|oh
decl_stmt|;
name|ViceFid
name|CodaFid
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* coda_zapdir: */
end_comment

begin_comment
comment|/* CODA_ZAPDIR is a venus->kernel call */
end_comment

begin_struct
struct|struct
name|coda_zapdir_out
block|{
name|struct
name|coda_out_hdr
name|oh
decl_stmt|;
name|ViceFid
name|CodaFid
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* coda_zapnode: */
end_comment

begin_comment
comment|/* CODA_ZAPVNODE is a venus->kernel call */
end_comment

begin_struct
struct|struct
name|coda_zapvnode_out
block|{
name|struct
name|coda_out_hdr
name|oh
decl_stmt|;
name|struct
name|coda_cred
name|cred
decl_stmt|;
name|ViceFid
name|VFid
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* coda_purgefid: */
end_comment

begin_comment
comment|/* CODA_PURGEFID is a venus->kernel call */
end_comment

begin_struct
struct|struct
name|coda_purgefid_out
block|{
name|struct
name|coda_out_hdr
name|oh
decl_stmt|;
name|ViceFid
name|CodaFid
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* coda_rdwr: */
end_comment

begin_struct
struct|struct
name|coda_rdwr_in
block|{
name|struct
name|coda_in_hdr
name|ih
decl_stmt|;
name|ViceFid
name|VFid
decl_stmt|;
name|int
name|rwflag
decl_stmt|;
name|int
name|count
decl_stmt|;
name|int
name|offset
decl_stmt|;
name|int
name|ioflag
decl_stmt|;
name|caddr_t
name|data
decl_stmt|;
comment|/* Place holder for data. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coda_rdwr_out
block|{
name|struct
name|coda_out_hdr
name|oh
decl_stmt|;
name|int
name|rwflag
decl_stmt|;
name|int
name|count
decl_stmt|;
name|caddr_t
name|data
decl_stmt|;
comment|/* Place holder for data. */
block|}
struct|;
end_struct

begin_comment
comment|/* coda_replace: */
end_comment

begin_comment
comment|/* CODA_REPLACE is a venus->kernel call */
end_comment

begin_struct
struct|struct
name|coda_replace_out
block|{
comment|/* coda_replace is a venus->kernel call */
name|struct
name|coda_out_hdr
name|oh
decl_stmt|;
name|ViceFid
name|NewFid
decl_stmt|;
name|ViceFid
name|OldFid
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* coda_open_by_path: */
end_comment

begin_struct
struct|struct
name|coda_open_by_path_in
block|{
name|struct
name|coda_in_hdr
name|ih
decl_stmt|;
name|ViceFid
name|VFid
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coda_open_by_path_out
block|{
name|struct
name|coda_out_hdr
name|oh
decl_stmt|;
name|int
name|path
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*   * Occasionally, we don't cache the fid returned by CODA_LOOKUP.   * For instance, if the fid is inconsistent.   * This case is handled by setting the top bit of the type result parameter.  */
end_comment

begin_define
define|#
directive|define
name|CODA_NOCACHE
value|0x80000000
end_define

begin_union
union|union
name|inputArgs
block|{
name|struct
name|coda_in_hdr
name|ih
decl_stmt|;
comment|/* NB: every struct below begins with an ih */
name|struct
name|coda_open_in
name|coda_open
decl_stmt|;
name|struct
name|coda_close_in
name|coda_close
decl_stmt|;
name|struct
name|coda_ioctl_in
name|coda_ioctl
decl_stmt|;
name|struct
name|coda_getattr_in
name|coda_getattr
decl_stmt|;
name|struct
name|coda_setattr_in
name|coda_setattr
decl_stmt|;
name|struct
name|coda_access_in
name|coda_access
decl_stmt|;
name|struct
name|coda_lookup_in
name|coda_lookup
decl_stmt|;
name|struct
name|coda_create_in
name|coda_create
decl_stmt|;
name|struct
name|coda_remove_in
name|coda_remove
decl_stmt|;
name|struct
name|coda_link_in
name|coda_link
decl_stmt|;
name|struct
name|coda_rename_in
name|coda_rename
decl_stmt|;
name|struct
name|coda_mkdir_in
name|coda_mkdir
decl_stmt|;
name|struct
name|coda_rmdir_in
name|coda_rmdir
decl_stmt|;
name|struct
name|coda_readdir_in
name|coda_readdir
decl_stmt|;
name|struct
name|coda_symlink_in
name|coda_symlink
decl_stmt|;
name|struct
name|coda_readlink_in
name|coda_readlink
decl_stmt|;
name|struct
name|coda_fsync_in
name|coda_fsync
decl_stmt|;
name|struct
name|coda_inactive_in
name|coda_inactive
decl_stmt|;
name|struct
name|coda_vget_in
name|coda_vget
decl_stmt|;
name|struct
name|coda_rdwr_in
name|coda_rdwr
decl_stmt|;
name|struct
name|coda_open_by_path_in
name|coda_open_by_path
decl_stmt|;
block|}
union|;
end_union

begin_union
union|union
name|outputArgs
block|{
name|struct
name|coda_out_hdr
name|oh
decl_stmt|;
comment|/* NB: every struct below begins with an oh */
name|struct
name|coda_root_out
name|coda_root
decl_stmt|;
name|struct
name|coda_open_out
name|coda_open
decl_stmt|;
name|struct
name|coda_ioctl_out
name|coda_ioctl
decl_stmt|;
name|struct
name|coda_getattr_out
name|coda_getattr
decl_stmt|;
name|struct
name|coda_lookup_out
name|coda_lookup
decl_stmt|;
name|struct
name|coda_create_out
name|coda_create
decl_stmt|;
name|struct
name|coda_mkdir_out
name|coda_mkdir
decl_stmt|;
name|struct
name|coda_readdir_out
name|coda_readdir
decl_stmt|;
name|struct
name|coda_readlink_out
name|coda_readlink
decl_stmt|;
name|struct
name|coda_vget_out
name|coda_vget
decl_stmt|;
name|struct
name|coda_purgeuser_out
name|coda_purgeuser
decl_stmt|;
name|struct
name|coda_zapfile_out
name|coda_zapfile
decl_stmt|;
name|struct
name|coda_zapdir_out
name|coda_zapdir
decl_stmt|;
name|struct
name|coda_zapvnode_out
name|coda_zapvnode
decl_stmt|;
name|struct
name|coda_purgefid_out
name|coda_purgefid
decl_stmt|;
name|struct
name|coda_rdwr_out
name|coda_rdwr
decl_stmt|;
name|struct
name|coda_replace_out
name|coda_replace
decl_stmt|;
name|struct
name|coda_open_by_path_out
name|coda_open_by_path
decl_stmt|;
block|}
union|;
end_union

begin_union
union|union
name|coda_downcalls
block|{
comment|/* CODA_INVALIDATE is a venus->kernel call */
comment|/* CODA_FLUSH is a venus->kernel call */
name|struct
name|coda_purgeuser_out
name|purgeuser
decl_stmt|;
name|struct
name|coda_zapfile_out
name|zapfile
decl_stmt|;
name|struct
name|coda_zapdir_out
name|zapdir
decl_stmt|;
name|struct
name|coda_zapvnode_out
name|zapvnode
decl_stmt|;
name|struct
name|coda_purgefid_out
name|purgefid
decl_stmt|;
name|struct
name|coda_replace_out
name|replace
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Used for identifying usage of "Control" and pioctls  */
end_comment

begin_define
define|#
directive|define
name|PIOCPARM_MASK
value|0x0000ffff
end_define

begin_struct
struct|struct
name|ViceIoctl
block|{
name|caddr_t
name|in
decl_stmt|,
name|out
decl_stmt|;
comment|/* Data to be transferred in, or out */
name|short
name|in_size
decl_stmt|;
comment|/* Size of input buffer<= 2K */
name|short
name|out_size
decl_stmt|;
comment|/* Maximum size of output buffer,<= 2K */
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__CYGWIN32__
argument_list|)
operator|||
name|defined
argument_list|(
name|DJGPP
argument_list|)
end_if

begin_struct
struct|struct
name|PioctlData
block|{
name|unsigned
name|long
name|cmd
decl_stmt|;
specifier|const
name|char
modifier|*
name|path
decl_stmt|;
name|int
name|follow
decl_stmt|;
name|struct
name|ViceIoctl
name|vi
decl_stmt|;
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_struct
struct|struct
name|PioctlData
block|{
specifier|const
name|char
modifier|*
name|path
decl_stmt|;
name|int
name|follow
decl_stmt|;
name|struct
name|ViceIoctl
name|vi
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CODA_CONTROL
value|".CONTROL"
end_define

begin_define
define|#
directive|define
name|CODA_CONTROLLEN
value|8
end_define

begin_define
define|#
directive|define
name|CTL_VOL
value|-1
end_define

begin_define
define|#
directive|define
name|CTL_VNO
value|-1
end_define

begin_define
define|#
directive|define
name|CTL_UNI
value|-1
end_define

begin_define
define|#
directive|define
name|CTL_INO
value|-1
end_define

begin_define
define|#
directive|define
name|CTL_FILE
value|"/coda/.CONTROL"
end_define

begin_define
define|#
directive|define
name|IS_CTL_FID
parameter_list|(
name|fidp
parameter_list|)
value|((fidp)->Volume == CTL_VOL&&\ 				 (fidp)->Vnode == CTL_VNO&&\ 				 (fidp)->Unique == CTL_UNI)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

