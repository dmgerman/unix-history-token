begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	dkbad.h	4.1	81/05/08	*/
end_comment

begin_comment
comment|/*  * Definitions needed to perform bad block  * revectoring ala DEC STD 144.  *  * The bad block information is located in the  * first 5 even numbered sectors of the last  * track of the disk pack.  There are five  * identical copies of the information, described  * by the dkbad structure.  *  * Replacement blocks are allocated starting with  * the first block before the bad block information  * and working backwards towards the beginning of  * the disk.  A maximum of 126 bad blocks are supported.  * The position of the bad block in the bad block table  * determines which replacement block it corresponds to.  *  * The bad block information and replacement blocks  * are conventionally only accessable through the  * 'c' file system partition of the disk.  If that  * partition is used for a file system, the user is  * responsible for making sure that it does not overlap  * the bad block information or any replacement blocks.  */
end_comment

begin_struct
struct|struct
name|dkbad
block|{
name|long
name|bt_csn
decl_stmt|;
comment|/* cartridge serial number */
name|u_short
name|bt_magic
decl_stmt|;
comment|/* magic number for sanity check */
define|#
directive|define
name|BADMAGIC
value|0122155
name|u_short
name|bt_flag
decl_stmt|;
comment|/* -1 => alignment cartridge */
struct|struct
block|{
name|u_short
name|bt_cyl
decl_stmt|;
comment|/* cylinder number of bad block */
name|u_short
name|bt_trksec
decl_stmt|;
comment|/* track and sector number */
block|}
name|bt_bad
index|[
literal|126
index|]
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ECC
value|0
end_define

begin_define
define|#
directive|define
name|SSE
value|1
end_define

begin_define
define|#
directive|define
name|BSE
value|2
end_define

begin_define
define|#
directive|define
name|CONT
value|3
end_define

end_unit

