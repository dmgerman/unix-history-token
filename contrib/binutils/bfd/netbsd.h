begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end definitions used by all NetBSD targets.    Copyright 1990, 1991, 1992, 1994, 1995, 1996, 1997, 1998, 2000    Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Check for our machine type (part of magic number).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MACHTYPE_OK
end_ifndef

begin_define
define|#
directive|define
name|MACHTYPE_OK
parameter_list|(
name|m
parameter_list|)
value|((m) == DEFAULT_MID || (m) == M_UNKNOWN)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is the normal load address for executables.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_START_ADDR
value|TARGET_PAGE_SIZE
end_define

begin_comment
comment|/* NetBSD ZMAGIC has its header in the text segment.  */
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

begin_comment
comment|/* Determine if this is a shared library using the flags.  */
end_comment

begin_define
define|#
directive|define
name|N_SHARED_LIB
parameter_list|(
name|x
parameter_list|)
value|(N_DYNAMIC(x))
end_define

begin_comment
comment|/* We have 6 bits of flags and 10 bits of machine ID.  */
end_comment

begin_define
define|#
directive|define
name|N_MACHTYPE
parameter_list|(
name|exec
parameter_list|)
define|\
value|((enum machine_type) (((exec).a_info>> 16)& 0x03ff))
end_define

begin_define
define|#
directive|define
name|N_FLAGS
parameter_list|(
name|exec
parameter_list|)
define|\
value|(((exec).a_info>> 26)& 0x3f)
end_define

begin_define
define|#
directive|define
name|N_SET_INFO
parameter_list|(
name|exec
parameter_list|,
name|magic
parameter_list|,
name|type
parameter_list|,
name|flags
parameter_list|)
define|\
value|((exec).a_info = ((magic)& 0xffff) \ 	 | (((int) (type)& 0x3ff)<< 16) \ 	 | (((flags)& 0x3f)<< 24))
end_define

begin_define
define|#
directive|define
name|N_SET_MACHTYPE
parameter_list|(
name|exec
parameter_list|,
name|machtype
parameter_list|)
define|\
value|((exec).a_info = \          ((exec).a_info& 0xfb00ffff) | ((((int) (machtype))&0x3ff)<< 16))
end_define

begin_define
define|#
directive|define
name|N_SET_FLAGS
parameter_list|(
name|exec
parameter_list|,
name|flags
parameter_list|)
define|\
value|((exec).a_info = \ 	 ((exec).a_info& 0x03ffffff) | ((flags& 0x03f)<< 26))
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
file|"libbfd.h"
end_include

begin_include
include|#
directive|include
file|"libaout.h"
end_include

begin_comment
comment|/* On NetBSD, the magic number is always in ntohl's "network" (big-endian)    format.  */
end_comment

begin_define
define|#
directive|define
name|SWAP_MAGIC
parameter_list|(
name|ext
parameter_list|)
value|bfd_getb32 (ext)
end_define

begin_comment
comment|/* On NetBSD, the entry point may be taken to be the start of the text    section.  */
end_comment

begin_define
define|#
directive|define
name|MY_entry_is_text_address
value|1
end_define

begin_define
define|#
directive|define
name|MY_write_object_contents
value|MY(write_object_contents)
end_define

begin_function_decl
specifier|static
name|boolean
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

begin_define
define|#
directive|define
name|MY_text_includes_header
value|1
end_define

begin_include
include|#
directive|include
file|"aout-target.h"
end_include

begin_comment
comment|/* Write an object file.    Section contents have already been written.  We write the    file header, symbols, and relocation.  */
end_comment

begin_function
specifier|static
name|boolean
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
comment|/* We must make certain that the magic number has been set.  This      will normally have been done by set_section_contents, but only if      there actually are some section contents.  */
if|if
condition|(
operator|!
name|abfd
operator|->
name|output_has_begun
condition|)
block|{
name|bfd_size_type
name|text_size
decl_stmt|;
name|file_ptr
name|text_end
decl_stmt|;
name|NAME
argument_list|(
name|aout
argument_list|,
name|adjust_sizes_and_vmas
argument_list|)
argument_list|(
name|abfd
argument_list|,
operator|&
name|text_size
argument_list|,
operator|&
name|text_end
argument_list|)
expr_stmt|;
block|}
name|obj_reloc_entry_size
argument_list|(
name|abfd
argument_list|)
operator|=
name|RELOC_STD_SIZE
expr_stmt|;
comment|/* Magic number, maestro, please!  */
switch|switch
condition|(
name|bfd_get_arch
argument_list|(
name|abfd
argument_list|)
condition|)
block|{
case|case
name|DEFAULT_ARCH
case|:
name|N_SET_MACHTYPE
argument_list|(
operator|*
name|execp
argument_list|,
name|DEFAULT_MID
argument_list|)
expr_stmt|;
break|break;
default|default:
name|N_SET_MACHTYPE
argument_list|(
operator|*
name|execp
argument_list|,
name|M_UNKNOWN
argument_list|)
expr_stmt|;
break|break;
block|}
comment|/* The NetBSD magic number is always big-endian */
ifndef|#
directive|ifndef
name|TARGET_IS_BIG_ENDIAN_P
comment|/* XXX aren't there any macro to change byteorder of a word independent of      the host's or target's endianesses?  */
name|execp
operator|->
name|a_info
operator|=
operator|(
name|execp
operator|->
name|a_info
operator|&
literal|0xff
operator|)
operator|<<
literal|24
operator||
operator|(
name|execp
operator|->
name|a_info
operator|&
literal|0xff00
operator|)
operator|<<
literal|8
operator||
operator|(
name|execp
operator|->
name|a_info
operator|&
literal|0xff0000
operator|)
operator|>>
literal|8
operator||
operator|(
name|execp
operator|->
name|a_info
operator|&
literal|0xff000000
operator|)
operator|>>
literal|24
expr_stmt|;
endif|#
directive|endif
name|WRITE_HEADERS
argument_list|(
name|abfd
argument_list|,
name|execp
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_function

end_unit

