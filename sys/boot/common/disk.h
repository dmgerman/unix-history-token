begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Google, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Device descriptor for partitioned disks. To use, set the  * d_slice and d_partition variables as follows:  *  * Whole disk access:  *  * 	d_slice = -1  * 	d_partition = -1  *  * Whole MBR slice:  *  * 	d_slice = MBR slice number (typically 1..4)  * 	d_partition = -1  *  * BSD disklabel partition within an MBR slice:  *  * 	d_slice = MBR slice number (typically 1..4)  * 	d_partition = disklabel partition (typically 0..19)  *  * BSD disklabel partition on the true dedicated disk:  *  * 	d_slice = -1  * 	d_partition = disklabel partition (typically 0..19)  *  * GPT partition:  *  * 	d_slice = GPT partition number (typically 1..N)  * 	d_partition = 255  *  * For both MBR and GPT, to automatically find the 'best' slice or partition,  * set d_slice to zero. This uses the partition type to decide which partition  * to use according to the following list of preferences:  *  * 	FreeBSD (active)  * 	FreeBSD (inactive)  * 	Linux (active)  * 	Linux (inactive)  * 	DOS/Windows (active)  * 	DOS/Windows (inactive)  *  * Active MBR slices (marked as bootable) are preferred over inactive. GPT  * doesn't have the concept of active/inactive partitions. In both MBR and GPT,  * if there are multiple slices/partitions of a given type, the first one  * is chosen.  *  * The low-level disk device will typically call disk_open() from its open  * method to interpret the disk partition tables according to the rules above.  * This will initialize d_offset to the block offset of the start of the  * selected partition - this offset should be added to the offset passed to  * the device's strategy method.  */
end_comment

begin_struct
struct|struct
name|disk_devdesc
block|{
name|struct
name|devsw
modifier|*
name|d_dev
decl_stmt|;
name|int
name|d_type
decl_stmt|;
name|int
name|d_unit
decl_stmt|;
name|void
modifier|*
name|d_opendata
decl_stmt|;
name|int
name|d_slice
decl_stmt|;
name|int
name|d_partition
decl_stmt|;
name|off_t
name|d_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Parse disk metadata and initialise dev->d_offset.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|disk_open
parameter_list|(
name|struct
name|disk_devdesc
modifier|*
name|dev
parameter_list|,
name|off_t
name|mediasize
parameter_list|,
name|u_int
name|sectorsize
parameter_list|,
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DISK_F_NOCACHE
value|0x0001
end_define

begin_comment
comment|/* Do not use metadata caching */
end_comment

begin_function_decl
specifier|extern
name|int
name|disk_close
parameter_list|(
name|struct
name|disk_devdesc
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|disk_cleanup
parameter_list|(
specifier|const
name|struct
name|devsw
modifier|*
name|d_dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Print information about slices on a disk.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|disk_print
parameter_list|(
name|struct
name|disk_devdesc
modifier|*
name|dev
parameter_list|,
name|char
modifier|*
name|prefix
parameter_list|,
name|int
name|verbose
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|disk_fmtdev
parameter_list|(
name|struct
name|disk_devdesc
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|disk_parsedev
parameter_list|(
name|struct
name|disk_devdesc
modifier|*
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|devspec
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

end_unit

