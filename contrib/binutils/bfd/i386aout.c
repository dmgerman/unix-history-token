begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for i386 a.out binaries.    Copyright 1990, 1991, 1992, 1994, 1996, 1997    Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* The only 386 aout system we have here is GO32 from DJ.     These numbers make BFD work with that. If your aout 386 system    doesn't work with these, we'll have to split them into different    files.  Send me (sac@cygnus.com) the runes to make it work on your    system, and I'll stick it in for the next release.  */
end_comment

begin_define
define|#
directive|define
name|N_HEADER_IN_TEXT
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|BYTES_IN_WORD
value|4
end_define

begin_define
define|#
directive|define
name|N_TXTOFF
parameter_list|(
name|x
parameter_list|)
value|0x20
end_define

begin_define
define|#
directive|define
name|N_TXTADDR
parameter_list|(
name|x
parameter_list|)
value|(N_MAGIC(x)==ZMAGIC ? 0x1020 : 0)
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

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|N_DATADDR
parameter_list|(
name|x
parameter_list|)
value|(N_MAGIC(x)==OMAGIC? (N_TXTADDR(x)+(x).a_text) : (SEGMENT_SIZE + ((0x1020+(x).a_text-1)& ~(SEGMENT_SIZE-1))))
end_define

begin_define
define|#
directive|define
name|NOSUBEXECB
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|0x400000
end_define

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
value|CAT(i386aout_,OP)
end_define

begin_define
define|#
directive|define
name|TARGETNAME
value|"a.out-i386"
end_define

begin_define
define|#
directive|define
name|NO_WRITE_HEADER_KLUDGE
value|1
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
file|"libaout.h"
end_include

begin_comment
comment|/* Set the machine type correctly.  */
end_comment

begin_function
specifier|static
name|boolean
name|i386aout_write_object_contents
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
name|N_SET_MACHTYPE
argument_list|(
operator|*
name|execp
argument_list|,
name|M_386
argument_list|)
expr_stmt|;
name|obj_reloc_entry_size
argument_list|(
name|abfd
argument_list|)
operator|=
name|RELOC_STD_SIZE
expr_stmt|;
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

begin_define
define|#
directive|define
name|MY_write_object_contents
value|i386aout_write_object_contents
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
comment|/* entry is text address */
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

