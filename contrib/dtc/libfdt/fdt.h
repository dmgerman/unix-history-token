begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_FDT_H
end_ifndef

begin_define
define|#
directive|define
name|_FDT_H
end_define

begin_comment
comment|/*  * libfdt - Flat Device Tree manipulation  * Copyright (C) 2006 David Gibson, IBM Corporation.  * Copyright 2012 Kim Phillips, Freescale Semiconductor.  *  * libfdt is dual licensed: you can use it either under the terms of  * the GPL, or the BSD license, at your option.  *  *  a) This library is free software; you can redistribute it and/or  *     modify it under the terms of the GNU General Public License as  *     published by the Free Software Foundation; either version 2 of the  *     License, or (at your option) any later version.  *  *     This library is distributed in the hope that it will be useful,  *     but WITHOUT ANY WARRANTY; without even the implied warranty of  *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  *     GNU General Public License for more details.  *  *     You should have received a copy of the GNU General Public  *     License along with this library; if not, write to the Free  *     Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,  *     MA 02110-1301 USA  *  * Alternatively,  *  *  b) Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *     1. Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *     2. Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  *     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND  *     CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,  *     INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  *     MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  *     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR  *     CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  *     SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *     NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  *     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  *     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *     CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  *     OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  *     EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLY__
end_ifndef

begin_struct
struct|struct
name|fdt_header
block|{
name|fdt32_t
name|magic
decl_stmt|;
comment|/* magic word FDT_MAGIC */
name|fdt32_t
name|totalsize
decl_stmt|;
comment|/* total size of DT block */
name|fdt32_t
name|off_dt_struct
decl_stmt|;
comment|/* offset to structure */
name|fdt32_t
name|off_dt_strings
decl_stmt|;
comment|/* offset to strings */
name|fdt32_t
name|off_mem_rsvmap
decl_stmt|;
comment|/* offset to memory reserve map */
name|fdt32_t
name|version
decl_stmt|;
comment|/* format version */
name|fdt32_t
name|last_comp_version
decl_stmt|;
comment|/* last compatible version */
comment|/* version 2 fields below */
name|fdt32_t
name|boot_cpuid_phys
decl_stmt|;
comment|/* Which physical CPU id we're 					    booting on */
comment|/* version 3 fields below */
name|fdt32_t
name|size_dt_strings
decl_stmt|;
comment|/* size of the strings block */
comment|/* version 17 fields below */
name|fdt32_t
name|size_dt_struct
decl_stmt|;
comment|/* size of the structure block */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fdt_reserve_entry
block|{
name|fdt64_t
name|address
decl_stmt|;
name|fdt64_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fdt_node_header
block|{
name|fdt32_t
name|tag
decl_stmt|;
name|char
name|name
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fdt_property
block|{
name|fdt32_t
name|tag
decl_stmt|;
name|fdt32_t
name|len
decl_stmt|;
name|fdt32_t
name|nameoff
decl_stmt|;
name|char
name|data
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__ASSEMBLY */
end_comment

begin_define
define|#
directive|define
name|FDT_MAGIC
value|0xd00dfeed
end_define

begin_comment
comment|/* 4: version, 4: total size */
end_comment

begin_define
define|#
directive|define
name|FDT_TAGSIZE
value|sizeof(fdt32_t)
end_define

begin_define
define|#
directive|define
name|FDT_BEGIN_NODE
value|0x1
end_define

begin_comment
comment|/* Start node: full name */
end_comment

begin_define
define|#
directive|define
name|FDT_END_NODE
value|0x2
end_define

begin_comment
comment|/* End node */
end_comment

begin_define
define|#
directive|define
name|FDT_PROP
value|0x3
end_define

begin_comment
comment|/* Property: name off, 					   size, content */
end_comment

begin_define
define|#
directive|define
name|FDT_NOP
value|0x4
end_define

begin_comment
comment|/* nop */
end_comment

begin_define
define|#
directive|define
name|FDT_END
value|0x9
end_define

begin_define
define|#
directive|define
name|FDT_V1_SIZE
value|(7*sizeof(fdt32_t))
end_define

begin_define
define|#
directive|define
name|FDT_V2_SIZE
value|(FDT_V1_SIZE + sizeof(fdt32_t))
end_define

begin_define
define|#
directive|define
name|FDT_V3_SIZE
value|(FDT_V2_SIZE + sizeof(fdt32_t))
end_define

begin_define
define|#
directive|define
name|FDT_V16_SIZE
value|FDT_V3_SIZE
end_define

begin_define
define|#
directive|define
name|FDT_V17_SIZE
value|(FDT_V16_SIZE + sizeof(fdt32_t))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FDT_H */
end_comment

end_unit

