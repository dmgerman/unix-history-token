begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB run on a mips box under 4.3bsd.     Copyright 1986, 1987, 1989, 1991, 1992, 1993, 1994, 1995, 1996,    1997, 1998, 1999, 2000, 2002, 2003 Free Software Foundation, Inc.     Contributed by Per Bothner (bothner@cs.wisc.edu) at U.Wisconsin    and by Alessandro Forin (af@cs.cmu.edu) at CMU..     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_MIPS_H
end_ifndef

begin_define
define|#
directive|define
name|TM_MIPS_H
value|1
end_define

begin_define
define|#
directive|define
name|GDB_MULTI_ARCH
value|1
end_define

begin_include
include|#
directive|include
file|"regcache.h"
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

begin_struct_decl
struct_decl|struct
name|type
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|value
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|<bfd.h>
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

begin_comment
comment|/* Return non-zero if PC points to an instruction which will cause a step    to execute both the instruction at PC and an instruction at PC+4.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|mips_step_skips_delay
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|STEP_SKIPS_DELAY_P
value|(1)
end_define

begin_define
define|#
directive|define
name|STEP_SKIPS_DELAY
parameter_list|(
name|pc
parameter_list|)
value|(mips_step_skips_delay (pc))
end_define

begin_comment
comment|/* Register numbers of various important registers.    Note that some of these values are "real" register numbers,    and correspond to the general registers of the machine,    and some are "phony" register numbers which are too large    to be actual register numbers as far as the user is concerned    but do serve to get the desired values when passed to read_register.  */
end_comment

begin_define
define|#
directive|define
name|ZERO_REGNUM
value|0
end_define

begin_comment
comment|/* read-only register, always 0 */
end_comment

begin_define
define|#
directive|define
name|V0_REGNUM
value|2
end_define

begin_comment
comment|/* Function integer return value */
end_comment

begin_define
define|#
directive|define
name|A0_REGNUM
value|4
end_define

begin_comment
comment|/* Loc of first arg during a subr call */
end_comment

begin_define
define|#
directive|define
name|T9_REGNUM
value|25
end_define

begin_comment
comment|/* Contains address of callee in PIC */
end_comment

begin_define
define|#
directive|define
name|SP_REGNUM
value|29
end_define

begin_comment
comment|/* Contains address of top of stack */
end_comment

begin_define
define|#
directive|define
name|RA_REGNUM
value|31
end_define

begin_comment
comment|/* Contains return address value */
end_comment

begin_define
define|#
directive|define
name|PS_REGNUM
value|32
end_define

begin_comment
comment|/* Contains processor status */
end_comment

begin_define
define|#
directive|define
name|UNUSED_REGNUM
value|73
end_define

begin_comment
comment|/* Never used, FIXME */
end_comment

begin_define
define|#
directive|define
name|FIRST_EMBED_REGNUM
value|74
end_define

begin_comment
comment|/* First CP0 register for embedded use */
end_comment

begin_define
define|#
directive|define
name|PRID_REGNUM
value|89
end_define

begin_comment
comment|/* Processor ID */
end_comment

begin_define
define|#
directive|define
name|LAST_EMBED_REGNUM
value|89
end_define

begin_comment
comment|/* Last one */
end_comment

begin_comment
comment|/* Special symbol found in blocks associated with routines.  We can hang    mips_extra_func_info_t's off of this.  */
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

begin_comment
comment|/* Specific information about a procedure.    This overlays the MIPS's PDR records,     mipsread.c (ab)uses this to save memory */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|mips_extra_func_info
block|{
name|long
name|numargs
decl_stmt|;
comment|/* number of args to procedure (was iopt) */
name|bfd_vma
name|high_addr
decl_stmt|;
comment|/* upper address bound */
name|long
name|frame_adjust
decl_stmt|;
comment|/* offset of FP from SP (used on MIPS16) */
name|PDR
name|pdr
decl_stmt|;
comment|/* Procedure descriptor record */
block|}
typedef|*
name|mips_extra_func_info_t
typedef|;
end_typedef

begin_comment
comment|/* It takes two values to specify a frame on the MIPS.     In fact, the *PC* is the primary value that sets up a frame.  The    PC is looked up to see what function it's in; symbol information    from that function tells us which register is the frame pointer    base, and what offset from there is the "virtual frame pointer".    (This is usually an offset from SP.)  On most non-MIPS machines,    the primary value is the SP, and the PC, if needed, disambiguates    multiple functions with the same SP.  But on the MIPS we can't do    that since the PC is not stored in the same part of the frame every    time.  This does not seem to be a very clever way to set up frames,    but there is nothing we can do about that.  */
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
value|setup_arbitrary_frame (argc, argv)
end_define

begin_function_decl
specifier|extern
name|struct
name|frame_info
modifier|*
name|setup_arbitrary_frame
parameter_list|(
name|int
parameter_list|,
name|CORE_ADDR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* These are defined in mdebugread.c and are used in mips-tdep.c  */
end_comment

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|sigtramp_address
decl_stmt|,
name|sigtramp_end
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|fixup_sigtramp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions for dealing with MIPS16 call and return stubs.  */
end_comment

begin_define
define|#
directive|define
name|IGNORE_HELPER_CALL
parameter_list|(
name|pc
parameter_list|)
value|mips_ignore_helper (pc)
end_define

begin_function_decl
specifier|extern
name|int
name|mips_ignore_helper
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Definitions and declarations used by mips-tdep.c and remote-mips.c  */
end_comment

begin_define
define|#
directive|define
name|MIPS_INSTLEN
value|4
end_define

begin_comment
comment|/* Length of an instruction */
end_comment

begin_define
define|#
directive|define
name|MIPS16_INSTLEN
value|2
end_define

begin_comment
comment|/* Length of an instruction on MIPS16 */
end_comment

begin_define
define|#
directive|define
name|MIPS_NUMREGS
value|32
end_define

begin_comment
comment|/* Number of integer or float registers */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|t_inst
typedef|;
end_typedef

begin_comment
comment|/* Integer big enough to hold an instruction */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TM_MIPS_H */
end_comment

begin_comment
comment|/* Single step based on where the current instruction will take us.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|mips_software_single_step
parameter_list|(
name|enum
name|target_signal
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

