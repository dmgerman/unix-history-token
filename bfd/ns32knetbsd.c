begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for NetBSD/ns32k a.out-ish binaries.    Copyright 1990, 1991, 1992, 1994, 1995, 1998, 2000, 2001, 2002    Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|BYTES_IN_WORD
value|4
end_define

begin_undef
undef|#
directive|undef
name|TARGET_IS_BIG_ENDIAN_P
end_undef

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
value|4096
end_define

begin_define
define|#
directive|define
name|DEFAULT_ARCH
value|bfd_arch_ns32k
end_define

begin_define
define|#
directive|define
name|DEFAULT_MID
value|M_532_NETBSD
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
value|CONCAT2 (pc532netbsd_,OP)
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
value|CONCAT3 (ns32kaout,_32_,y)
end_define

begin_comment
comment|/* This needs to start with a.out so GDB knows it is an a.out variant.  */
end_comment

begin_define
define|#
directive|define
name|TARGETNAME
value|"a.out-ns32k-netbsd"
end_define

begin_define
define|#
directive|define
name|ns32kaout_32_get_section_contents
value|aout_32_get_section_contents
end_define

begin_define
define|#
directive|define
name|MY_text_includes_header
value|1
end_define

begin_comment
comment|/* We can`t use the MYNS macro here for cpp reasons too subtle  * for me -- IWD  */
end_comment

begin_define
define|#
directive|define
name|MY_bfd_reloc_type_lookup
value|ns32kaout_bfd_reloc_type_lookup
end_define

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_comment
comment|/* To ensure following declaration is OK */
end_comment

begin_decl_stmt
specifier|const
name|struct
name|reloc_howto_struct
modifier|*
name|MY_bfd_reloc_type_lookup
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
name|AND
name|bfd_reloc_code_real_type
name|code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"netbsd.h"
end_include

end_unit

