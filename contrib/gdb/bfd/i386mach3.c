begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for i386 a.out binaries.    Copyright (C) 1990, 1991 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_define
define|#
directive|define
name|BYTES_IN_WORD
value|4
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

begin_define
define|#
directive|define
name|MY
parameter_list|(
name|OP
parameter_list|)
value|CAT(i386mach3_,OP)
end_define

begin_define
define|#
directive|define
name|TARGETNAME
value|"a.out-mach3"
end_define

begin_function_decl
specifier|static
name|boolean
name|MY
function_decl|(
name|set_sizes
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MY_backend_data
value|&MY(backend_data)
end_define

begin_expr_stmt
specifier|static
name|CONST
expr|struct
name|aout_backend_data
name|MY
argument_list|(
name|backend_data
argument_list|)
operator|=
block|{
literal|0
block|,
comment|/* zmagic contiguous */
literal|1
block|,
comment|/* text incl header */
literal|0
block|,
comment|/* exec_hdr_flags */
literal|0
block|,
comment|/* text vma? */
name|MY
argument_list|(
name|set_sizes
argument_list|)
block|,
literal|1
block|,
comment|/* exec header not counted */
literal|0
block|,
comment|/* add_dynamic_symbols */
literal|0
block|,
comment|/* add_one_symbol */
literal|0
block|,
comment|/* link_dynamic_object */
literal|0
block|,
comment|/* write_dynamic_symbol */
literal|0
block|,
comment|/* check_dynamic_reloc */
literal|0
comment|/* finish_dynamic_link */
block|}
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"aout-target.h"
end_include

end_unit

