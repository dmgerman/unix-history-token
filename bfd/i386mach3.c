begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for i386 a.out binaries.    Copyright 1990, 1991, 1993, 1994, 1995, 1997, 2001, 2002, 2003    Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* This is for Mach 3, which uses a.out, not Mach-O.  */
end_comment

begin_comment
comment|/* There is no magic number or anything which lets us distinguish this target    from i386aout or i386bsd.  So this target is only useful if it is the    default target.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_PAGE_SIZE
value|1
end_define

begin_define
define|#
directive|define
name|SEGMENT_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|TEXT_START_ADDR
value|0x10000
end_define

begin_define
define|#
directive|define
name|ARCH
value|32
end_define

begin_comment
comment|/* This macro is only relevant when N_MAGIC(x) == ZMAGIC.  */
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
file|"aout/aout64.h"
end_include

begin_include
include|#
directive|include
file|"aout/stab_gnu.h"
end_include

begin_include
include|#
directive|include
file|"aout/ar.h"
end_include

begin_include
include|#
directive|include
file|"libaout.h"
end_include

begin_comment
comment|/* BFD a.out internal data structures */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_ARCH
value|bfd_arch_i386
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
value|CONCAT2 (i386mach3_,OP)
end_define

begin_define
define|#
directive|define
name|TARGETNAME
value|"a.out-mach3"
end_define

begin_function_decl
specifier|static
name|bfd_boolean
name|MY
parameter_list|(
name|set_sizes
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|MY_backend_data
value|&MY(backend_data)
end_define

begin_function_decl
specifier|static
specifier|const
name|struct
name|aout_backend_data
name|MY
parameter_list|(
name|backend_data
parameter_list|)
init|=
block|{
literal|0
operator|,
comment|/* zmagic contiguous */
function_decl|1
operator|,
comment|/* text incl header */
function_decl|0
operator|,
comment|/* entry is text address */
function_decl|0
operator|,
comment|/* exec_hdr_flags */
function_decl|0
operator|,
comment|/* text vma? */
function_decl|MY
parameter_list|(
name|set_sizes
parameter_list|)
operator|,
function_decl|1
operator|,
comment|/* exec header not counted */
function_decl|0
operator|,
comment|/* add_dynamic_symbols */
function_decl|0
operator|,
comment|/* add_one_symbol */
function_decl|0
operator|,
comment|/* link_dynamic_object */
function_decl|0
operator|,
comment|/* write_dynamic_symbol */
function_decl|0
operator|,
comment|/* check_dynamic_reloc */
function_decl|0
end_function_decl

begin_comment
comment|/* finish_dynamic_link */
end_comment

begin_include
unit|};
include|#
directive|include
file|"aout-target.h"
end_include

end_unit

