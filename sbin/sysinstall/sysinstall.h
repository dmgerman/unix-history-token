begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994, Paul Richards.  *  * All rights reserved.  *  * This software may be used, modified, copied, distributed, and  * sold, in both source and binary form provided that the above  * copyright and these terms are retained, verbatim, as the first  * lines of this file.  Under no circumstances is the author  * responsible for the proper functioning of this software, nor does  * the author assume any responsibility for damages incurred with  * its use.  */
end_comment

begin_define
define|#
directive|define
name|MAX_NO_DISKS
value|10
end_define

begin_define
define|#
directive|define
name|SCRATCHSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|BOOT_MAGIC
value|0xAA55
end_define

begin_define
define|#
directive|define
name|ACTIVE
value|0x80
end_define

begin_struct
struct|struct
name|mboot
block|{
name|unsigned
name|char
name|padding
index|[
literal|2
index|]
decl_stmt|;
comment|/* force the longs to be long alligned */
name|unsigned
name|char
name|bootinst
index|[
name|DOSPARTOFF
index|]
decl_stmt|;
name|struct
name|dos_partition
name|parts
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|short
name|int
name|signature
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|part_type
block|{
name|unsigned
name|char
name|type
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
name|part_types
index|[]
init|=
block|{
block|{
literal|0x00
block|,
literal|"unused"
block|}
block|,
block|{
literal|0x01
block|,
literal|"Primary DOS with 12 bit FAT"
block|}
block|,
block|{
literal|0x02
block|,
literal|"XENIX / filesystem"
block|}
block|,
block|{
literal|0x03
block|,
literal|"XENIX /usr filesystem"
block|}
block|,
block|{
literal|0x04
block|,
literal|"Primary DOS with 16 bit FAT"
block|}
block|,
block|{
literal|0x05
block|,
literal|"Extended DOS"
block|}
block|,
block|{
literal|0x06
block|,
literal|"Primary 'big' DOS (> 32MB)"
block|}
block|,
block|{
literal|0x07
block|,
literal|"OS/2 HPFS, QNX or Advanced UNIX"
block|}
block|,
block|{
literal|0x08
block|,
literal|"AIX filesystem"
block|}
block|,
block|{
literal|0x09
block|,
literal|"AIX boot partition or Coherent"
block|}
block|,
block|{
literal|0x0A
block|,
literal|"OS/2 Boot Manager or OPUS"
block|}
block|,
block|{
literal|0x10
block|,
literal|"OPUS"
block|}
block|,
block|{
literal|0x40
block|,
literal|"VENIX 286"
block|}
block|,
block|{
literal|0x50
block|,
literal|"DM"
block|}
block|,
block|{
literal|0x51
block|,
literal|"DM"
block|}
block|,
block|{
literal|0x52
block|,
literal|"CP/M or Microport SysV/AT"
block|}
block|,
block|{
literal|0x56
block|,
literal|"GB"
block|}
block|,
block|{
literal|0x61
block|,
literal|"Speed"
block|}
block|,
block|{
literal|0x63
block|,
literal|"ISC UNIX, other System V/386, GNU HURD or Mach"
block|}
block|,
block|{
literal|0x64
block|,
literal|"Novell Netware 2.xx"
block|}
block|,
block|{
literal|0x65
block|,
literal|"Novell Netware 3.xx"
block|}
block|,
block|{
literal|0x75
block|,
literal|"PCIX"
block|}
block|,
block|{
literal|0x80
block|,
literal|"Minix 1.1 ... 1.4a"
block|}
block|,
block|{
literal|0x81
block|,
literal|"Minix 1.4b ... 1.5.10"
block|}
block|,
block|{
literal|0x82
block|,
literal|"Linux"
block|}
block|,
block|{
literal|0x93
block|,
literal|"Amoeba filesystem"
block|}
block|,
block|{
literal|0x94
block|,
literal|"Amoeba bad block table"
block|}
block|,
block|{
literal|0xA5
block|,
literal|"386BSD"
block|}
block|,
block|{
literal|0xB7
block|,
literal|"BSDI BSD/386 filesystem"
block|}
block|,
block|{
literal|0xB8
block|,
literal|"BSDI BSD/386 swap"
block|}
block|,
block|{
literal|0xDB
block|,
literal|"Concurrent CPM or C.DOS or CTOS"
block|}
block|,
block|{
literal|0xE1
block|,
literal|"Speed"
block|}
block|,
block|{
literal|0xE3
block|,
literal|"Speed"
block|}
block|,
block|{
literal|0xE4
block|,
literal|"Speed"
block|}
block|,
block|{
literal|0xF1
block|,
literal|"Speed"
block|}
block|,
block|{
literal|0xF2
block|,
literal|"DOS 3.3+ Secondary"
block|}
block|,
block|{
literal|0xF4
block|,
literal|"Speed"
block|}
block|,
block|{
literal|0xFF
block|,
literal|"BBT (Bad Blocks Table)"
block|}
block|}
struct|;
end_struct

end_unit

