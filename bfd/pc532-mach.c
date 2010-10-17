begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for Mach3/532 a.out-ish binaries.    Copyright 1990, 1991, 1992, 1994, 1995, 2000, 2001, 2002    Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by Ian Dall  *            19-Apr-94  *  * Formerly part of aout-pc532-mach.c. Split out to allow more  * flexibility with multiple formats.  *  */
end_comment

begin_comment
comment|/* This architecture has N_TXTOFF and N_TXTADDR defined as if  * N_HEADER_IN_TEXT, but the a_text entry (text size) does not include the  * space for the header. So we have N_HEADER_IN_TEXT defined to  * 1 and specially define our own N_TXTSIZE  */
end_comment

begin_define
define|#
directive|define
name|N_HEADER_IN_TEXT
parameter_list|(
name|x
parameter_list|)
value|1
end_define

begin_define
define|#
directive|define
name|N_TXTSIZE
parameter_list|(
name|x
parameter_list|)
value|((x).a_text)
end_define

begin_define
define|#
directive|define
name|TEXT_START_ADDR
value|0x10000
end_define

begin_comment
comment|/* from old ld */
end_comment

begin_define
define|#
directive|define
name|TARGET_PAGE_SIZE
value|0x1000
end_define

begin_comment
comment|/* from old ld,  032& 532 are really 512/4k */
end_comment

begin_comment
comment|/* Use a_entry of 0 to distinguish object files from OMAGIC executables */
end_comment

begin_define
define|#
directive|define
name|N_TXTADDR
parameter_list|(
name|x
parameter_list|)
define|\
value|(N_MAGIC(x) == OMAGIC ? \    ((x).a_entry< TEXT_START_ADDR? 0: TEXT_START_ADDR): \    (N_MAGIC(x) == NMAGIC? TEXT_START_ADDR: \     TEXT_START_ADDR + EXEC_BYTES_SIZE))
end_define

begin_define
define|#
directive|define
name|SEGMENT_SIZE
value|TARGET_PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|N_SHARED_LIB
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|SEGMENT_SIZE
value|TARGET_PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|DEFAULT_ARCH
value|bfd_arch_ns32k
end_define

begin_comment
comment|/* Do not "beautify" the CONCAT* macro args.  Traditional C will not    remove whitespace added here, and thus will fail to concatenate    the tokens.  */
end_comment

begin_define
define|#
directive|define
name|MY
parameter_list|(
name|OP
parameter_list|)
value|CONCAT2 (pc532machaout_,OP)
end_define

begin_comment
comment|/* Must be the same as aout-ns32k.c */
end_comment

begin_define
define|#
directive|define
name|NAME
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|CONCAT3 (ns32kaout,_32_,y)
end_define

begin_define
define|#
directive|define
name|TARGETNAME
value|"a.out-pc532-mach"
end_define

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|"libaout.h"
end_include

begin_include
include|#
directive|include
file|"libbfd.h"
end_include

begin_include
include|#
directive|include
file|"aout/aout64.h"
end_include

begin_define
define|#
directive|define
name|MY_bfd_reloc_type_lookup
value|ns32kaout_bfd_reloc_type_lookup
end_define

begin_comment
comment|/* libaout doesn't use NAME for these ...  */
end_comment

begin_define
define|#
directive|define
name|MY_get_section_contents
value|aout_32_get_section_contents
end_define

begin_define
define|#
directive|define
name|MY_text_includes_header
value|1
end_define

begin_define
define|#
directive|define
name|MY_exec_header_not_counted
value|1
end_define

begin_decl_stmt
name|reloc_howto_type
modifier|*
name|ns32kaout_bfd_reloc_type_lookup
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|bfd_reloc_code_real_type
name|code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|bfd_boolean
name|MY
parameter_list|(
name|write_object_contents
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *abfd
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
specifier|static
name|bfd_boolean
name|MY
function|(
name|write_object_contents
function|)
parameter_list|(
name|abfd
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
block|{
name|struct
name|external_exec
name|exec_bytes
decl_stmt|;
name|struct
name|internal_exec
modifier|*
name|execp
init|=
name|exec_hdr
argument_list|(
name|abfd
argument_list|)
decl_stmt|;
name|obj_reloc_entry_size
argument_list|(
name|abfd
argument_list|)
operator|=
name|RELOC_STD_SIZE
expr_stmt|;
name|BFD_ASSERT
argument_list|(
name|bfd_get_arch
argument_list|(
name|abfd
argument_list|)
operator|==
name|bfd_arch_ns32k
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|bfd_get_mach
argument_list|(
name|abfd
argument_list|)
condition|)
block|{
case|case
literal|32032
case|:
name|N_SET_MACHTYPE
argument_list|(
operator|*
name|execp
argument_list|,
name|M_NS32032
argument_list|)
expr_stmt|;
break|break;
case|case
literal|32532
case|:
default|default:
name|N_SET_MACHTYPE
argument_list|(
operator|*
name|execp
argument_list|,
name|M_NS32532
argument_list|)
expr_stmt|;
break|break;
block|}
name|N_SET_FLAGS
argument_list|(
operator|*
name|execp
argument_list|,
name|aout_backend_info
argument_list|(
name|abfd
argument_list|)
operator|->
name|exec_hdr_flags
argument_list|)
expr_stmt|;
name|WRITE_HEADERS
argument_list|(
name|abfd
argument_list|,
name|execp
argument_list|)
expr_stmt|;
return|return
name|TRUE
return|;
block|}
end_function

begin_define
define|#
directive|define
name|MY_write_object_contents
value|MY(write_object_contents)
end_define

begin_include
include|#
directive|include
file|"aout-target.h"
end_include

end_unit

