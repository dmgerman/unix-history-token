begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for i386 a.out binaries under dynix.    Copyright 1994, 1995, 2001, 2003 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This BFD is currently only tested with gdb, writing object files    may not work.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_START_ADDR
value|4096
end_define

begin_define
define|#
directive|define
name|TARGET_PAGE_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|SEGMENT_SIZE
value|TARGET_PAGE_SIZE
end_define

begin_include
include|#
directive|include
file|"aout/dynix3.h"
end_include

begin_define
define|#
directive|define
name|DEFAULT_ARCH
value|bfd_arch_i386
end_define

begin_define
define|#
directive|define
name|MACHTYPE_OK
parameter_list|(
name|mtype
parameter_list|)
value|((mtype) == M_386 || (mtype) == M_UNKNOWN)
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
value|CONCAT2 (i386dynix_,OP)
end_define

begin_define
define|#
directive|define
name|TARGETNAME
value|"a.out-i386-dynix"
end_define

begin_define
define|#
directive|define
name|NAME
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|CONCAT3 (i386dynix,_32_,y)
end_define

begin_define
define|#
directive|define
name|ARCH_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|NAME_swap_exec_header_in
value|NAME(i386dynix_32_,swap_exec_header_in)
end_define

begin_define
define|#
directive|define
name|MY_get_section_contents
value|aout_32_get_section_contents
end_define

begin_comment
comment|/* aoutx.h requires definitions for NMAGIC, BMAGIC and QMAGIC.  */
end_comment

begin_define
define|#
directive|define
name|NMAGIC
value|0
end_define

begin_define
define|#
directive|define
name|BMAGIC
value|OMAGIC
end_define

begin_define
define|#
directive|define
name|QMAGIC
value|XMAGIC
end_define

begin_include
include|#
directive|include
file|"aoutx.h"
end_include

begin_comment
comment|/* (Ab)use some fields in the internal exec header to be able to read    executables that contain shared data.  */
end_comment

begin_define
define|#
directive|define
name|a_shdata
value|a_tload
end_define

begin_define
define|#
directive|define
name|a_shdrsize
value|a_dload
end_define

begin_function
name|void
name|i386dynix_32_swap_exec_header_in
parameter_list|(
name|abfd
parameter_list|,
name|raw_bytes
parameter_list|,
name|execp
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|struct
name|external_exec
modifier|*
name|raw_bytes
decl_stmt|;
name|struct
name|internal_exec
modifier|*
name|execp
decl_stmt|;
block|{
name|struct
name|external_exec
modifier|*
name|bytes
init|=
operator|(
expr|struct
name|external_exec
operator|*
operator|)
name|raw_bytes
decl_stmt|;
comment|/* The internal_exec structure has some fields that are unused in this      configuration (IE for i960), so ensure that all such uninitialized      fields are zero'd out.  There are places where two of these structs      are memcmp'd, and thus the contents do matter. */
name|memset
argument_list|(
operator|(
name|PTR
operator|)
name|execp
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|internal_exec
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Now fill in fields in the execp, from the bytes in the raw data.  */
name|execp
operator|->
name|a_info
operator|=
name|H_GET_32
argument_list|(
name|abfd
argument_list|,
name|bytes
operator|->
name|e_info
argument_list|)
expr_stmt|;
name|execp
operator|->
name|a_text
operator|=
name|GET_WORD
argument_list|(
name|abfd
argument_list|,
name|bytes
operator|->
name|e_text
argument_list|)
expr_stmt|;
name|execp
operator|->
name|a_data
operator|=
name|GET_WORD
argument_list|(
name|abfd
argument_list|,
name|bytes
operator|->
name|e_data
argument_list|)
expr_stmt|;
name|execp
operator|->
name|a_bss
operator|=
name|GET_WORD
argument_list|(
name|abfd
argument_list|,
name|bytes
operator|->
name|e_bss
argument_list|)
expr_stmt|;
name|execp
operator|->
name|a_syms
operator|=
name|GET_WORD
argument_list|(
name|abfd
argument_list|,
name|bytes
operator|->
name|e_syms
argument_list|)
expr_stmt|;
name|execp
operator|->
name|a_entry
operator|=
name|GET_WORD
argument_list|(
name|abfd
argument_list|,
name|bytes
operator|->
name|e_entry
argument_list|)
expr_stmt|;
name|execp
operator|->
name|a_trsize
operator|=
name|GET_WORD
argument_list|(
name|abfd
argument_list|,
name|bytes
operator|->
name|e_trsize
argument_list|)
expr_stmt|;
name|execp
operator|->
name|a_drsize
operator|=
name|GET_WORD
argument_list|(
name|abfd
argument_list|,
name|bytes
operator|->
name|e_drsize
argument_list|)
expr_stmt|;
name|execp
operator|->
name|a_shdata
operator|=
name|GET_WORD
argument_list|(
name|abfd
argument_list|,
name|bytes
operator|->
name|e_shdata
argument_list|)
expr_stmt|;
name|execp
operator|->
name|a_shdrsize
operator|=
name|GET_WORD
argument_list|(
name|abfd
argument_list|,
name|bytes
operator|->
name|e_shdrsize
argument_list|)
expr_stmt|;
block|}
end_function

begin_include
include|#
directive|include
file|"aout-target.h"
end_include

end_unit

