begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB run on an Alpha box under OSF1.  This is    also used by the Alpha/Netware and Alpha GNU/Linux targets.     Copyright 1993, 1994, 1995, 1996, 1998, 1999, 2000, 2002, 2004 Free    Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_ALPHA_H
end_ifndef

begin_define
define|#
directive|define
name|TM_ALPHA_H
end_define

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"coff/sym.h"
end_include

begin_comment
comment|/* Needed for PDR below.  */
end_comment

begin_include
include|#
directive|include
file|"coff/symconst.h"
end_include

begin_struct_decl
struct_decl|struct
name|frame_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|symbol
struct_decl|;
end_struct_decl

begin_comment
comment|/* Special symbol found in blocks associated with routines.  We can hang    alpha_extra_func_info_t's off of this.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_EFI_SYMBOL_NAME
value|"__GDB_EFI_INFO__"
end_define

begin_function_decl
specifier|extern
name|void
name|ecoff_relocate_efi
parameter_list|(
name|struct
name|symbol
modifier|*
parameter_list|,
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|RA_REGNUM
value|26
end_define

begin_comment
comment|/* XXXJRT needed by mdebugread.c */
end_comment

begin_comment
comment|/* Specific information about a procedure.    This overlays the ALPHA's PDR records,     alpharead.c (ab)uses this to save memory */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|alpha_extra_func_info
block|{
name|long
name|numargs
decl_stmt|;
comment|/* number of args to procedure (was iopt) */
name|PDR
name|pdr
decl_stmt|;
comment|/* Procedure descriptor record */
block|}
typedef|*
name|alpha_extra_func_info_t
typedef|;
end_typedef

begin_comment
comment|/* Define the extra_func_info that mipsread.c needs.    FIXME: We should define our own PDR interface, perhaps in a separate    header file. This would get rid of the<bfd.h> inclusion in all sources    and would abstract the mips/alpha interface from ecoff.  */
end_comment

begin_define
define|#
directive|define
name|mips_extra_func_info
value|alpha_extra_func_info
end_define

begin_define
define|#
directive|define
name|mips_extra_func_info_t
value|alpha_extra_func_info_t
end_define

begin_comment
comment|/* It takes two values to specify a frame on the ALPHA.  Sigh.     In fact, at the moment, the *PC* is the primary value that sets up    a frame.  The PC is looked up to see what function it's in; symbol    information from that function tells us which register is the frame    pointer base, and what offset from there is the "virtual frame pointer".    (This is usually an offset from SP.)  FIXME -- this should be cleaned    up so that the primary value is the SP, and the PC is used to disambiguate    multiple functions with the same SP that are at different stack levels. */
end_comment

begin_define
define|#
directive|define
name|SETUP_ARBITRARY_FRAME
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
define|\
value|alpha_setup_arbitrary_frame (argc, argv)
end_define

begin_function_decl
specifier|extern
name|struct
name|frame_info
modifier|*
name|alpha_setup_arbitrary_frame
parameter_list|(
name|int
parameter_list|,
name|CORE_ADDR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TM_ALPHA_H */
end_comment

end_unit

