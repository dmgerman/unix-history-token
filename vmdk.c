begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Juniper Networks, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/apm.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"format.h"
end_include

begin_include
include|#
directive|include
file|"image.h"
end_include

begin_include
include|#
directive|include
file|"mkimg.h"
end_include

begin_struct
struct|struct
name|vmdk_header
block|{
name|uint32_t
name|magic
decl_stmt|;
define|#
directive|define
name|VMDK_MAGIC
value|0x564d444b
name|uint32_t
name|version
decl_stmt|;
define|#
directive|define
name|VMDK_VERSION
value|1
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|VMDK_FLAGS_NL_TEST
value|(1<< 0)
define|#
directive|define
name|VMDK_FLAGS_RGT_USED
value|(1<< 1)
define|#
directive|define
name|VMDK_FLAGS_COMPRESSED
value|(1<< 16)
define|#
directive|define
name|VMDK_FLAGS_MARKERS
value|(1<< 17)
name|uint64_t
name|capacity
decl_stmt|;
name|uint64_t
name|grain_size
decl_stmt|;
name|uint64_t
name|desc_offset
decl_stmt|;
name|uint64_t
name|desc_size
decl_stmt|;
name|uint32_t
name|ngtes
decl_stmt|;
define|#
directive|define
name|VMDK_NGTES
value|512
name|uint64_t
name|rgd_offset
decl_stmt|;
name|uint64_t
name|gd_offset
decl_stmt|;
name|uint64_t
name|overhead
decl_stmt|;
name|uint8_t
name|unclean
decl_stmt|;
name|uint8_t
name|nl_test
index|[
literal|4
index|]
decl_stmt|;
define|#
directive|define
name|VMDK_NL_TEST
value|0x0a200d0a
name|uint16_t
name|compress
decl_stmt|;
define|#
directive|define
name|VMDK_COMPRESS_NONE
value|0
define|#
directive|define
name|VMDK_COMPRESS_DEFLATE
value|1
name|char
name|padding
index|[
literal|433
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_decl_stmt
specifier|static
specifier|const
name|char
name|desc_fmt
index|[]
init|=
literal|"# Disk DescriptorFile\n"
literal|"version=%d\n"
literal|"CID=%08x\n"
literal|"parentCID=ffffffff\n"
literal|"createType=\"monolithicSparse\"\n"
literal|"# Extent description\n"
literal|"RW %ju SPARSE \"%s\"\n"
literal|"# The Disk Data Base\n"
literal|"#DDB\n"
literal|"ddb.adapterType = \"ide\"\n"
literal|"ddb.geometry.cylinders = \"%u\"\n"
literal|"ddb.geometry.heads = \"%u\"\n"
literal|"ddb.geometry.sectors = \"%u\"\n"
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|vmdk_write
parameter_list|(
name|int
name|fd
name|__unused
parameter_list|)
block|{
name|char
modifier|*
name|desc
decl_stmt|;
name|lba_t
name|imgsz
decl_stmt|;
name|int
name|desc_len
decl_stmt|;
name|imgsz
operator|=
name|image_get_size
argument_list|()
expr_stmt|;
name|desc_len
operator|=
name|asprintf
argument_list|(
operator|&
name|desc
argument_list|,
name|desc_fmt
argument_list|,
literal|1
comment|/*version*/
argument_list|,
literal|0
comment|/*CID*/
argument_list|,
operator|(
name|uintmax_t
operator|)
name|imgsz
comment|/*size*/
argument_list|,
literal|"mkimg.vmdk"
comment|/*name*/
argument_list|,
name|ncyls
comment|/*cylinders*/
argument_list|,
name|nheads
comment|/*heads*/
argument_list|,
name|nsecs
comment|/*sectors*/
argument_list|)
expr_stmt|;
name|desc_len
operator|=
operator|(
name|desc_len
operator|+
literal|512
operator|-
literal|1
operator|)
operator|&
operator|~
operator|(
literal|512
operator|-
literal|1
operator|)
expr_stmt|;
name|desc
operator|=
name|realloc
argument_list|(
name|desc
argument_list|,
name|desc_len
argument_list|)
expr_stmt|;
comment|/* 	 * Steps: 	 * 1. create embedded descriptor. We need to know its size upfront. 	 * 2. create and populate grain directory and tables. This means 	 *    iterating over the written sectors of the image. 	 * 3. (optional) create and populate redundant directory and 	 *    tables while doing step 2. 	 * 4. create and write header (512 bytes) 	 * 5. write descriptor (# x 512 bytes) 	 * 6. write grain directory and tables (# x 512 bytes) 	 * 7. (optional) write redundant directory and tables (# x 512 bytes) 	 * 8. align to grain size. 	 * 9. create and write grains. 	 * 	 * Notes: 	 * 1. The drain directory is being ignored by some implementations 	 *    so the tables must be at their known/assumed offsets. 	 * 2. Default grain size is 128 sectors (= 64KB). 	 * 3. There are 512 entries in a table, each entry being 32-bits. 	 *    Thus, a grain table is 2KB (= 4 sectors). 	 * 4. Each grain table covers 512 * 128 sectors (= 64K sectors). 	 *    With 512-bytes per sector, this yields 32MB of disk data. 	 * 5. For smaller images, the grain size can be reduced to avoid 	 *    rounding the output file to 32MB. The minimum grain size is 	 *    8 sectors (= 4KB). The smallest VMDK file is 2MB without 	 *    overhead (= metadata). 	 * 6. The capacity is a multiple of the grain size. 	 */
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|struct
name|mkimg_format
name|vmdk_format
init|=
block|{
operator|.
name|name
operator|=
literal|"vmdk"
block|,
operator|.
name|description
operator|=
literal|"Virtual Machine Disk"
block|,
operator|.
name|write
operator|=
name|vmdk_write
block|, }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|FORMAT_DEFINE
argument_list|(
name|vmdk_format
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

