begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	efs.h	4.3	82/08/01	*/
end_comment

begin_comment
comment|/*  *	Extended File System  *  * Protocol:  *  *	send:	EFS_ACCESS<name><mode><ruid><rgid>  *	reply:	EFS_OK  *	reply:	EFS_ERROR<errno>  *  *	send:	EFS_CHMOD<name><mode><uid><gid>  *	reply:	EFS_OK  *	reply:	EFS_ERROR<errno>  *  *	send:	EFS_CHOWN<name><owner><group><uid><gid>  *	reply:	EFS_OK  *	reply:	EFS_ERROR<errno>  *  *	send:	EFS_CLOSE  *	reply:	EFS_OK  *	reply:	EFS_ERROR<errno>  *  *	send:	EFS_CREAT<name><mode><umask><uid><gid>  *	reply:	EFS_OK  *	reply:	EFS_ERROR<errno>  *  *	send:	EFS_FSTAT	  *	reply:	EFS_OK<data>...  *	reply:	EFS_ERROR<errno>  *  *	send:	EFS_IOCTL  *	reply:	EFS_OK<data>...  *	reply:	EFS_ERROR<errno>  *  *	send:	EFS_LINK<name1><name2><uid><gid>  *	reply:	EFS_OK  *	reply:	EFS_ERROR<errno>  *  *	send:	EFS_LSTAT<name><uid><gid>  *	reply:	EFS_OK<data>...  *	reply:	EFS_ERROR<errno>  *  *	send:	EFS_OPEN<name><mode><uid><gid>  *	reply:	EFS_OK<size>  *	reply:	EFS_ERROR<errno>  *  *	send:	EFS_READ<offset><count>  *	reply:	EFS_OK<data>...  *	reply:	EFS_ERROR<errno>  *  *	send:	EFS_READLINK<name><uid><gid>  *	reply:	EFS_OK<data>...  *	reply:	EFS_ERROR<errno>  *  *	send:	EFS_STAT<name><uid><gid>  *	reply:	EFS_OK<data>...  *	reply:	EFS_ERROR<errno>  *  *	send:	EFS_SYMLINK<name1><name2><uid><gid>  *	reply:	EFS_OK  *	reply:	EFS_ERROR<errno>  *  *	send:	EFS_UNLINK<name><uid><gid>  *	reply:	EFS_OK  *	reply:	EFS_ERROR<errno>  *  *	send:	EFS_UTIME<name><uid><gid>  *	reply:	EFS_OK  *	reply:	EFS_ERROR<errno>  *  *	send:	EFS_WRITE<offset><count><data>...  *	reply:	EFS_OK  *	reply:	EFS_ERROR<errno>  *  */
end_comment

begin_define
define|#
directive|define
name|EFS_NHT
value|10
end_define

begin_define
define|#
directive|define
name|EFS_HTMAX
value|32
end_define

begin_define
define|#
directive|define
name|EFS_NPB
value|32
end_define

begin_struct
struct|struct
name|efs_controlblock
block|{
name|u_char
name|efs_cmd
decl_stmt|;
comment|/* command */
name|char
name|efs_error
decl_stmt|;
comment|/* return error code */
union|union
block|{
struct|struct
block|{
name|short
name|efs_a_uid
decl_stmt|;
comment|/* user id */
name|short
name|efs_a_gid
decl_stmt|;
comment|/* group id */
name|int
name|efs_a_grps
index|[
name|NGRPS
operator|/
operator|(
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|*
literal|8
operator|)
index|]
decl_stmt|;
comment|/* group bit array */
union|union
block|{
struct|struct
block|{
name|short
name|efs_aa_owner
decl_stmt|;
comment|/* user id */
name|short
name|efs_aa_group
decl_stmt|;
comment|/* group id */
block|}
name|efs_aa
struct|;
struct|struct
block|{
name|short
name|efs_ab_cmask
decl_stmt|;
comment|/* cmask */
name|short
name|efs_ab_mode
decl_stmt|;
comment|/* mode */
block|}
name|efs_ab
struct|;
name|time_t
name|efs_ac_time
index|[
literal|2
index|]
decl_stmt|;
comment|/* utime */
block|}
name|efs_a_un
union|;
block|}
name|efs_a
struct|;
struct|struct
block|{
name|u_long
name|efs_b_count
decl_stmt|;
comment|/* bytes remaining for IO */
name|off_t
name|efs_b_offset
decl_stmt|;
comment|/* offset in file for IO */
block|}
name|efs_b
struct|;
name|off_t
name|efs_c_size
decl_stmt|;
comment|/* size of file or transfer */
block|}
name|efs_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|efs_uid
value|efs_un.efs_a.efs_a_uid
end_define

begin_define
define|#
directive|define
name|efs_gid
value|efs_un.efs_a.efs_a_gid
end_define

begin_define
define|#
directive|define
name|efs_grps
value|efs_un.efs_a.efs_a_grps
end_define

begin_define
define|#
directive|define
name|efs_owner
value|efs_un.efs_a.efs_a_un.efs_aa.efs_aa_owner
end_define

begin_define
define|#
directive|define
name|efs_group
value|efs_un.efs_a.efs_a_un.efs_aa.efs_aa_group
end_define

begin_define
define|#
directive|define
name|efs_cmask
value|efs_un.efs_a.efs_a_un.efs_ab.efs_ab_cmask
end_define

begin_define
define|#
directive|define
name|efs_mode
value|efs_un.efs_a.efs_a_un.efs_ab.efs_ab_mode
end_define

begin_define
define|#
directive|define
name|efs_time
value|efs_un.efs_a.efs_a_un.efs_ac_time
end_define

begin_define
define|#
directive|define
name|efs_count
value|efs_un.efs_b.efs_b_count
end_define

begin_define
define|#
directive|define
name|efs_offset
value|efs_un.efs_b.efs_b_offset
end_define

begin_define
define|#
directive|define
name|efs_size
value|efs_un.efs_c_size
end_define

begin_define
define|#
directive|define
name|EFS_ACCESS
value|0
end_define

begin_define
define|#
directive|define
name|EFS_CHMOD
value|1
end_define

begin_define
define|#
directive|define
name|EFS_CHOWN
value|2
end_define

begin_define
define|#
directive|define
name|EFS_CLOSE
value|3
end_define

begin_define
define|#
directive|define
name|EFS_CREAT
value|4
end_define

begin_define
define|#
directive|define
name|EFS_FSTAT
value|5
end_define

begin_define
define|#
directive|define
name|EFS_LINK
value|6
end_define

begin_define
define|#
directive|define
name|EFS_OPEN
value|7
end_define

begin_define
define|#
directive|define
name|EFS_READ
value|8
end_define

begin_define
define|#
directive|define
name|EFS_STAT
value|9
end_define

begin_define
define|#
directive|define
name|EFS_UNLINK
value|10
end_define

begin_define
define|#
directive|define
name|EFS_UTIME
value|11
end_define

begin_define
define|#
directive|define
name|EFS_WRITE
value|12
end_define

begin_define
define|#
directive|define
name|EFS_IOCTL
value|13
end_define

begin_define
define|#
directive|define
name|EFS_LSTAT
value|14
end_define

begin_define
define|#
directive|define
name|EFS_READLINK
value|15
end_define

begin_define
define|#
directive|define
name|EFS_SYMLINK
value|16
end_define

begin_define
define|#
directive|define
name|EFS_OK
value|100
end_define

begin_define
define|#
directive|define
name|EFS_ERROR
value|101
end_define

begin_comment
comment|/* The hosttable relates a host name to a network address */
end_comment

begin_struct
struct|struct
name|hosttable
block|{
name|char
name|ht_name
index|[
name|EFS_HTMAX
index|]
decl_stmt|;
name|struct
name|sockaddr_in
name|ht_addr
decl_stmt|;
block|}
name|efs_hosttable
index|[
name|EFS_NHT
index|]
struct|;
end_struct

begin_define
define|#
directive|define
name|EFSIOSHTAB
value|_IOW(e, 0, struct efs_hosttable)
end_define

begin_comment
comment|/* set hosttable */
end_comment

begin_define
define|#
directive|define
name|EFSIOGHTAB
value|_IOR(e, 1, struct efs_hosttable)
end_define

begin_comment
comment|/* get hosttable */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|int
name|efs_major
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* major device of efs char special routines */
end_comment

begin_define
define|#
directive|define
name|efsinode
parameter_list|(
name|ip
parameter_list|)
define|\
value|(((ip)->i_mode&IFMT) == IFCHR&& \ 	major((ip)->i_rdev) == efs_major&& minor((ip)->i_rdev) == 0)
end_define

begin_comment
comment|/*  * The patchboard connects file pointers on the local  * machine and sockets on the remote machine  */
end_comment

begin_struct
struct|struct
name|patchboard
block|{
name|struct
name|file
modifier|*
name|pb_fp
decl_stmt|;
comment|/* file pointer associated with pb */
name|struct
name|socket
modifier|*
name|pb_so
decl_stmt|;
comment|/* socket associated with pb */
name|off_t
name|pb_filesize
decl_stmt|;
comment|/* size of remote file */
name|struct
name|patchboard
modifier|*
name|pb_link
decl_stmt|;
comment|/* link to next free pb */
block|}
name|efs_patchboard
index|[
name|EFS_NPB
index|]
struct|,
modifier|*
name|efs_freepb
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

