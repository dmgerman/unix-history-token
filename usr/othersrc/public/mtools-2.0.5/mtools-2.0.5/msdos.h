begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * msdos common header file  */
end_comment

begin_define
define|#
directive|define
name|MSECTOR_SIZE
value|512
end_define

begin_comment
comment|/* MSDOS sector size in bytes */
end_comment

begin_define
define|#
directive|define
name|MDIR_SIZE
value|32
end_define

begin_comment
comment|/* MSDOS directory size in bytes */
end_comment

begin_define
define|#
directive|define
name|MAX_CLUSTER
value|8192
end_define

begin_comment
comment|/* largest cluster size */
end_comment

begin_define
define|#
directive|define
name|MAX_PATH
value|128
end_define

begin_comment
comment|/* largest MSDOS path length */
end_comment

begin_define
define|#
directive|define
name|MAX_DIR_SECS
value|64
end_define

begin_comment
comment|/* largest directory (in sectors) */
end_comment

begin_define
define|#
directive|define
name|NEW
value|1
end_define

begin_define
define|#
directive|define
name|OLD
value|0
end_define

begin_struct
struct|struct
name|directory
block|{
name|unsigned
name|char
name|name
index|[
literal|8
index|]
decl_stmt|;
comment|/* file name */
name|unsigned
name|char
name|ext
index|[
literal|3
index|]
decl_stmt|;
comment|/* file extension */
name|unsigned
name|char
name|attr
decl_stmt|;
comment|/* attribute byte */
name|unsigned
name|char
name|reserved
index|[
literal|10
index|]
decl_stmt|;
comment|/* ?? */
name|unsigned
name|char
name|time
index|[
literal|2
index|]
decl_stmt|;
comment|/* time stamp */
name|unsigned
name|char
name|date
index|[
literal|2
index|]
decl_stmt|;
comment|/* date stamp */
name|unsigned
name|char
name|start
index|[
literal|2
index|]
decl_stmt|;
comment|/* starting cluster number */
name|unsigned
name|char
name|size
index|[
literal|4
index|]
decl_stmt|;
comment|/* size of the file */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|device
block|{
name|char
name|drive
decl_stmt|;
comment|/* the drive letter */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* full path to device */
name|long
name|offset
decl_stmt|;
comment|/* skip this many bytes */
name|int
name|fat_bits
decl_stmt|;
comment|/* FAT encoding scheme */
name|int
name|mode
decl_stmt|;
comment|/* any special open() flags */
name|int
function_decl|(
modifier|*
name|gioctl
function_decl|)
parameter_list|()
function_decl|;
comment|/* gioctl() function if needed */
name|int
name|tracks
decl_stmt|;
comment|/* tracks */
name|int
name|heads
decl_stmt|;
comment|/* heads */
name|int
name|sectors
decl_stmt|;
comment|/* sectors */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bootsector
block|{
name|unsigned
name|char
name|jump
index|[
literal|3
index|]
decl_stmt|;
comment|/* Jump to boot code */
name|unsigned
name|char
name|banner
index|[
literal|8
index|]
decl_stmt|;
comment|/* OEM name& version */
name|unsigned
name|char
name|secsiz
index|[
literal|2
index|]
decl_stmt|;
comment|/* Bytes per sector hopefully 512 */
name|unsigned
name|char
name|clsiz
decl_stmt|;
comment|/* Cluster size in sectors */
name|unsigned
name|char
name|nrsvsect
index|[
literal|2
index|]
decl_stmt|;
comment|/* Number of reserved (boot) sectors */
name|unsigned
name|char
name|nfat
decl_stmt|;
comment|/* Number of FAT tables hopefully 2 */
name|unsigned
name|char
name|dirents
index|[
literal|2
index|]
decl_stmt|;
comment|/* Number of directory slots */
name|unsigned
name|char
name|psect
index|[
literal|2
index|]
decl_stmt|;
comment|/* Total sectors on disk */
name|unsigned
name|char
name|descr
decl_stmt|;
comment|/* Media descriptor=first byte of FAT */
name|unsigned
name|char
name|fatlen
index|[
literal|2
index|]
decl_stmt|;
comment|/* Sectors in FAT */
name|unsigned
name|char
name|nsect
index|[
literal|2
index|]
decl_stmt|;
comment|/* Sectors/track */
name|unsigned
name|char
name|nheads
index|[
literal|2
index|]
decl_stmt|;
comment|/* Heads */
name|unsigned
name|char
name|nhs
index|[
literal|4
index|]
decl_stmt|;
comment|/* number of hidden sectors */
name|unsigned
name|char
name|bigsect
index|[
literal|4
index|]
decl_stmt|;
comment|/* big total sectors */
name|unsigned
name|char
name|junk
index|[
literal|476
index|]
decl_stmt|;
comment|/* who cares? */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|void
name|SIG_TYPE
typedef|;
end_typedef

begin_comment
comment|/* typedef int SIG_TYPE; */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_define
define|#
directive|define
name|strchr
value|index
end_define

begin_define
define|#
directive|define
name|strrchr
value|rindex
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

end_unit

