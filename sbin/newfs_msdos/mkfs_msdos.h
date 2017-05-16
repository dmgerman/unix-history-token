begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$NetBSD: mkfs_msdos.h,v 1.3 2015/10/16 17:38:17 christos Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2013 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Christos Zoulas.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_define
define|#
directive|define
name|ALLOPTS
define|\
value|AOPT('@', off_t, offset, 0, "Offset in device") \ AOPT('B', const char *, bootstrap, -1, "Bootstrap file") \ AOPT('C', off_t, create_size, 0, "Create file") \ AOPT('F', uint8_t,  fat_type, 12, "FAT type (12, 16, or 32)") \ AOPT('I', uint32_t, volume_id, 0, "Volume ID") \ AOPT('L', const char *, volume_label, -1, "Volume Label") \ AOPT('N', bool, no_create, -2, "Don't create filesystem, print params only") \ AOPT('O', const char *, OEM_string, -1, "OEM string") \ AOPT('S', uint16_t, bytes_per_sector, 1, "Bytes per sector") \ AOPT('T', time_t, timestamp, 0, "Timestamp") \ AOPT('a', uint32_t, sectors_per_fat, 1, "Sectors per FAT") \ AOPT('b', uint32_t, block_size, 1, "Block size") \ AOPT('c', uint8_t, sectors_per_cluster, 1, "Sectors per cluster") \ AOPT('e', uint16_t, directory_entries, 1, "Directory entries") \ AOPT('f', const char *, floppy, -1, "Standard format floppies (160,180,320,360,640,720,1200,1232,1440,2880)") \ AOPT('h', uint16_t, drive_heads, 1, "Drive heads") \ AOPT('i', uint16_t, info_sector, 1, "Info sector") \ AOPT('k', uint16_t, backup_sector, 1, "Backup sector") \ AOPT('m', uint8_t, media_descriptor, 0, "Media descriptor") \ AOPT('n', uint8_t, num_FAT, 1, "Number of FATs") \ AOPT('o', uint32_t, hidden_sectors, 0, "Hidden sectors") \ AOPT('r', uint16_t, reserved_sectors, 1, "Reserved sectors") \ AOPT('s', uint32_t, size, 1, "File System size") \ AOPT('u', uint16_t, sectors_per_track, 1, "Sectors per track")
end_define

begin_struct
struct|struct
name|msdos_options
block|{
define|#
directive|define
name|AOPT
parameter_list|(
name|_opt
parameter_list|,
name|_type
parameter_list|,
name|_name
parameter_list|,
name|_min
parameter_list|,
name|_desc
parameter_list|)
value|_type _name;
name|ALLOPTS
undef|#
directive|undef
name|AOPT
name|uint32_t
name|timestamp_set
range|:
literal|1
decl_stmt|;
name|uint32_t
name|volume_id_set
range|:
literal|1
decl_stmt|;
name|uint32_t
name|media_descriptor_set
range|:
literal|1
decl_stmt|;
name|uint32_t
name|hidden_sectors_set
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|mkfs_msdos
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|msdos_options
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

