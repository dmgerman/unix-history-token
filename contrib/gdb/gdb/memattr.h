begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Memory attributes support, for GDB.    Copyright 2001 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MEMATTR_H
end_ifndef

begin_define
define|#
directive|define
name|MEMATTR_H
end_define

begin_enum
enum|enum
name|mem_access_mode
block|{
name|MEM_RW
block|,
comment|/* read/write */
name|MEM_RO
block|,
comment|/* read only */
name|MEM_WO
comment|/* write only */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|mem_access_width
block|{
name|MEM_WIDTH_UNSPECIFIED
block|,
name|MEM_WIDTH_8
block|,
comment|/*  8 bit accesses */
name|MEM_WIDTH_16
block|,
comment|/* 16  "      "    */
name|MEM_WIDTH_32
block|,
comment|/* 32  "      "    */
name|MEM_WIDTH_64
comment|/* 64  "      "    */
block|}
enum|;
end_enum

begin_comment
comment|/* The set of all attributes that can be set for a memory region.       This structure was created so that memory attributes can be passed    to target_ functions without exposing the details of memory region    list, which would be necessary if these fields were simply added to    the mem_region structure.     FIXME: It would be useful if there was a mechanism for targets to    add their own attributes.  For example, the number of wait states. */
end_comment

begin_struct
struct|struct
name|mem_attrib
block|{
comment|/* read/write, read-only, or write-only */
name|enum
name|mem_access_mode
name|mode
decl_stmt|;
name|enum
name|mem_access_width
name|width
decl_stmt|;
comment|/* enables hardware breakpoints */
name|int
name|hwbreak
decl_stmt|;
comment|/* enables host-side caching of memory region data */
name|int
name|cache
decl_stmt|;
comment|/* enables memory verification.  after a write, memory is re-read      to verify that the write was successful. */
name|int
name|verify
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mem_region
block|{
comment|/* FIXME: memory regions are stored in an unsorted singly-linked      list.  This probably won't scale to handle hundreds of memory      regions --- that many could be needed to describe the allowed      access modes for memory mapped i/o device registers. */
name|struct
name|mem_region
modifier|*
name|next
decl_stmt|;
name|CORE_ADDR
name|lo
decl_stmt|;
name|CORE_ADDR
name|hi
decl_stmt|;
comment|/* Item number of this memory region. */
name|int
name|number
decl_stmt|;
comment|/* Status of this memory region (enabled if non-zero, otherwise disabled) */
name|int
name|enabled_p
decl_stmt|;
comment|/* Attributes for this region */
name|struct
name|mem_attrib
name|attrib
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|struct
name|mem_region
modifier|*
name|lookup_mem_region
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MEMATTR_H */
end_comment

end_unit

