begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Written by Paul Popelka (paulp@uts.amdahl.com)  *   * You can do anything you want with this software, just don't say you wrote  * it, and don't remove this notice.  *   * This software is provided "as is".  *   * The author supplies this software to be publicly redistributed on the  * understanding that the author is not responsible for the correct  * functioning of this software in any circumstances and is not liable for  * any damages caused by this software.  *   * October 1992  *   *	from NetBSD:	direntry.h,v 1.1 1993/08/13 11:35:32 cgd Exp  *	$Id$  */
end_comment

begin_comment
comment|/*  * Structure of a dos directory entry.  */
end_comment

begin_struct
struct|struct
name|direntry
block|{
name|u_char
name|deName
index|[
literal|8
index|]
decl_stmt|;
comment|/* filename, blank filled */
define|#
directive|define
name|SLOT_EMPTY
value|0x00
comment|/* slot has never been used */
define|#
directive|define
name|SLOT_E5
value|0x05
comment|/* the real value is 0xe5 */
define|#
directive|define
name|SLOT_DELETED
value|0xe5
comment|/* file in this slot deleted */
name|u_char
name|deExtension
index|[
literal|3
index|]
decl_stmt|;
comment|/* extension, blank filled */
name|u_char
name|deAttributes
decl_stmt|;
comment|/* file attributes */
define|#
directive|define
name|ATTR_NORMAL
value|0x00
comment|/* normal file */
define|#
directive|define
name|ATTR_READONLY
value|0x01
comment|/* file is readonly */
define|#
directive|define
name|ATTR_HIDDEN
value|0x02
comment|/* file is hidden */
define|#
directive|define
name|ATTR_SYSTEM
value|0x04
comment|/* file is a system file */
define|#
directive|define
name|ATTR_VOLUME
value|0x08
comment|/* entry is a volume label */
define|#
directive|define
name|ATTR_DIRECTORY
value|0x10
comment|/* entry is a directory name */
define|#
directive|define
name|ATTR_ARCHIVE
value|0x20
comment|/* file is new or modified */
name|char
name|deReserved
index|[
literal|10
index|]
decl_stmt|;
comment|/* reserved */
name|u_short
name|deTime
decl_stmt|;
comment|/* create/last update time */
name|u_short
name|deDate
decl_stmt|;
comment|/* create/last update date */
name|u_short
name|deStartCluster
decl_stmt|;
comment|/* starting cluster of file */
name|u_long
name|deFileSize
decl_stmt|;
comment|/* size of file in bytes */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This is the format of the contents of the deTime field in the direntry  * structure.  */
end_comment

begin_struct
struct|struct
name|DOStime
block|{
name|u_short
name|dt_2seconds
range|:
literal|5
decl_stmt|,
comment|/* seconds divided by 2 */
name|dt_minutes
range|:
literal|6
decl_stmt|,
comment|/* minutes */
name|dt_hours
range|:
literal|5
decl_stmt|;
comment|/* hours */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This is the format of the contents of the deDate field in the direntry  * structure.  */
end_comment

begin_struct
struct|struct
name|DOSdate
block|{
name|u_short
name|dd_day
range|:
literal|5
decl_stmt|,
comment|/* day of month */
name|dd_month
range|:
literal|4
decl_stmt|,
comment|/* month */
name|dd_year
range|:
literal|7
decl_stmt|;
comment|/* years since 1980 */
block|}
struct|;
end_struct

begin_union
union|union
name|dostime
block|{
name|struct
name|DOStime
name|dts
decl_stmt|;
name|u_short
name|dti
decl_stmt|;
block|}
union|;
end_union

begin_union
union|union
name|dosdate
block|{
name|struct
name|DOSdate
name|dds
decl_stmt|;
name|u_short
name|ddi
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * The following defines are used to rename fields in the ufs_specific  * structure in the nameidata structure in namei.h  */
end_comment

begin_define
define|#
directive|define
name|ni_msdosfs
value|ni_ufs
end_define

begin_define
define|#
directive|define
name|msdosfs_count
value|ufs_count
end_define

begin_define
define|#
directive|define
name|msdosfs_offset
value|ufs_offset
end_define

begin_define
define|#
directive|define
name|msdosfs_cluster
value|ufs_ino
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL
argument_list|)
end_if

begin_decl_stmt
name|void
name|unix2dostime
name|__P
argument_list|(
operator|(
expr|struct
name|timeval
operator|*
name|tvp
operator|,
expr|union
name|dosdate
operator|*
name|ddp
operator|,
expr|union
name|dostime
operator|*
name|dtp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dos2unixtime
name|__P
argument_list|(
operator|(
expr|union
name|dosdate
operator|*
name|ddp
operator|,
expr|union
name|dostime
operator|*
name|dtp
operator|,
expr|struct
name|timeval
operator|*
name|tvp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dos2unixfn
name|__P
argument_list|(
operator|(
name|u_char
name|dn
index|[
literal|11
index|]
operator|,
name|u_char
operator|*
name|un
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|unix2dosfn
name|__P
argument_list|(
operator|(
name|u_char
operator|*
name|un
operator|,
name|u_char
name|dn
index|[
literal|11
index|]
operator|,
name|int
name|unlen
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

