begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * msdos common header file  * [obtained from mtools -wfj]  * how to decipher DOS disk structures in coexisting with DOS  *  * $FreeBSD$  *	from: i386/include/pc msdos.h,v 1.4  */
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

begin_comment
comment|/* DOS partition table -- located in boot block */
end_comment

begin_define
define|#
directive|define
name|DOSBBSECTOR
value|0
end_define

begin_comment
comment|/* DOS boot block relative sector number */
end_comment

begin_define
define|#
directive|define
name|DOSPARTOFF
value|446
end_define

begin_define
define|#
directive|define
name|NDOSPART
value|4
end_define

begin_struct
struct|struct
name|dos_partition
block|{
name|unsigned
name|char
name|dp_flag
decl_stmt|;
comment|/* bootstrap flags */
name|unsigned
name|char
name|dp_shd
decl_stmt|;
comment|/* starting head */
name|unsigned
name|char
name|dp_ssect
decl_stmt|;
comment|/* starting sector */
name|unsigned
name|char
name|dp_scyl
decl_stmt|;
comment|/* starting cylinder */
name|unsigned
name|char
name|dp_typ
decl_stmt|;
comment|/* partition type */
define|#
directive|define
name|DOSPTYP_386BSD
value|0xa5
comment|/* 386BSD partition type */
name|unsigned
name|char
name|dp_ehd
decl_stmt|;
comment|/* end head */
name|unsigned
name|char
name|dp_esect
decl_stmt|;
comment|/* end sector */
name|unsigned
name|char
name|dp_ecyl
decl_stmt|;
comment|/* end cylinder */
name|unsigned
name|long
name|dp_start
decl_stmt|;
comment|/* absolute starting sector number */
name|unsigned
name|long
name|dp_size
decl_stmt|;
comment|/* partition size in sectors */
block|}
name|dos_partitions
index|[
name|NDOSPART
index|]
struct|;
end_struct

end_unit

