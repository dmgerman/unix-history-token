begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)dkbad.h	7.1 (Berkeley) 6/4/86  */
end_comment

begin_comment
comment|/*  * Definitions needed to perform bad sector  * revectoring ala DEC STD 144.  *  * The bad sector information is located in the  * first 5 even numbered sectors of the last  * track of the disk pack.  There are five  * identical copies of the information, described  * by the dkbad structure.  *  * Replacement sectors are allocated starting with  * the first sector before the bad sector information  * and working backwards towards the beginning of  * the disk.  A maximum of 126 bad sectors are supported.  * The position of the bad sector in the bad sector table  * determines which replacement sector it corresponds to.  *  * The bad sector information and replacement sectors  * are conventionally only accessible through the  * 'c' file system partition of the disk.  If that  * partition is used for a file system, the user is  * responsible for making sure that it does not overlap  * the bad sector information or any replacement sector.s  */
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
name|bt_mbz
decl_stmt|;
comment|/* unused; should be 0 */
name|u_short
name|bt_flag
decl_stmt|;
comment|/* -1 => alignment cartridge */
struct|struct
name|bt_bad
block|{
name|u_short
name|bt_cyl
decl_stmt|;
comment|/* cylinder number of bad sector */
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

