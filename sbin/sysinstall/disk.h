begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994, Paul Richards.  *  * All rights reserved.  *  * This software may be used, modified, copied, distributed, and  * sold, in both source and binary form provided that the above  * copyright and these terms are retained, verbatim, as the first  * lines of this file.  Under no circumstances is the author  * responsible for the proper functioning of this software, nor does  * the author assume any responsibility for damages incurred with  * its use.  */
end_comment

begin_define
define|#
directive|define
name|MBRSIZE
value|512
end_define

begin_define
define|#
directive|define
name|MBR_MAGIC
value|0xAA55
end_define

begin_define
define|#
directive|define
name|ACTIVE
value|0x80
end_define

begin_define
define|#
directive|define
name|BOOT1
value|"/stand/sdboot"
end_define

begin_define
define|#
directive|define
name|BOOT2
value|"/stand/bootsd"
end_define

begin_comment
comment|/* XXX -- calculate these, this is nasty */
end_comment

begin_define
define|#
directive|define
name|DEFFSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|DEFFRAG
value|8
end_define

begin_comment
comment|/* bootarea.c */
end_comment

begin_function_decl
name|int
name|write_bootblocks
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|enable_label
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|disable_label
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* label.c */
end_comment

begin_function_decl
name|char
modifier|*
name|diskname
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|mbr
block|{
name|unsigned
name|char
name|padding
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|bootcode
index|[
name|DOSPARTOFF
index|]
decl_stmt|;
name|struct
name|dos_partition
name|dospart
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|short
name|magic
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|disk
block|{
name|struct
name|disklabel
name|lbl
decl_stmt|;
name|struct
name|mbr
name|mbr
decl_stmt|;
name|struct
name|devconf
modifier|*
name|devconf
decl_stmt|;
name|int
name|selected
decl_stmt|;
name|int
name|inst_part
decl_stmt|;
name|struct
name|fstab
name|mounts
index|[
name|MAXPARTITIONS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|disk
name|disk_list
index|[]
decl_stmt|;
end_decl_stmt

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
struct|;
end_struct

begin_define
define|#
directive|define
name|PARTITION_TYPES
define|\
value|{ \     {0x00, "Unused"} \    ,{0x01, "Primary DOS with 12 bit FAT"} \    ,{0x02, "XENIX / filesystem"} \    ,{0x03, "XENIX /usr filesystem"}  \    ,{0x04, "Primary DOS with 16 bit FAT"} \    ,{0x05, "Extended DOS"} \    ,{0x06, "Primary 'big' DOS (> 32MB)"} \    ,{0x07, "OS/2 HPFS, QNX or Advanced UNIX"} \    ,{0x08, "AIX filesystem"} \    ,{0x09, "AIX boot partition or Coherent"} \    ,{0x0A, "OS/2 Boot Manager or OPUS"} \    ,{0x10, "OPUS"} \    ,{0x40, "VENIX 286"} \    ,{0x50, "DM"} \    ,{0x51, "DM"} \    ,{0x52, "CP/M or Microport SysV/AT"} \    ,{0x56, "GB"} \    ,{0x61, "Speed"} \    ,{0x63, "ISC UNIX, other System V/386, GNU HURD or Mach"} \    ,{0x64, "Novell Netware 2.xx"} \    ,{0x65, "Novell Netware 3.xx"} \    ,{0x75, "PCIX"} \    ,{0x80, "Minix 1.1 ... 1.4a"} \    ,{0x81, "Minix 1.4b ... 1.5.10"} \    ,{0x82, "Linux"} \    ,{0x93, "Amoeba filesystem"} \    ,{0x94, "Amoeba bad block table"} \    ,{0xA5, "FreeBSD/NetBSD/386BSD"} \    ,{0xB7, "BSDI BSD/386 filesystem"} \    ,{0xB8, "BSDI BSD/386 swap"} \    ,{0xDB, "Concurrent CPM or C.DOS or CTOS"} \    ,{0xE1, "Speed"} \    ,{0xE3, "Speed"} \    ,{0xE4, "Speed"} \    ,{0xF1, "Speed"} \    ,{0xF2, "DOS 3.3+ Secondary"} \    ,{0xF4, "Speed"} \    ,{0xFF, "BBT (Bad Blocks Table)"} \ };
end_define

end_unit

