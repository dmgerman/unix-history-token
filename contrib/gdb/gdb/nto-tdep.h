begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* nto-tdep.h - QNX Neutrino target header.     Copyright 2003 Free Software Foundation, Inc.     Contributed by QNX Software Systems Ltd.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NTO_TDEP_H
end_ifndef

begin_define
define|#
directive|define
name|_NTO_TDEP_H
end_define

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"solist.h"
end_include

begin_comment
comment|/* Generic functions in nto-tdep.c.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|nto_init_solib_absolute_prefix
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|nto_parse_redirection
parameter_list|(
name|char
modifier|*
name|start_argv
index|[]
parameter_list|,
name|char
modifier|*
modifier|*
name|in
parameter_list|,
name|char
modifier|*
modifier|*
name|out
parameter_list|,
name|char
modifier|*
modifier|*
name|err
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_iterate_over_mappings
parameter_list|(
name|int
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|CORE_ADDR
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nto_relocate_section_addresses
parameter_list|(
name|struct
name|so_list
modifier|*
parameter_list|,
name|struct
name|section_table
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nto_map_arch_to_cputype
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nto_find_and_open_solib
parameter_list|(
name|char
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Dummy function for initializing nto_target_ops on targets which do    not define a particular regset.  */
end_comment

begin_function_decl
name|void
name|nto_dummy_supply_regset
parameter_list|(
name|char
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Target operations defined for Neutrino targets (<target>-nto-tdep.c).  */
end_comment

begin_struct
struct|struct
name|nto_target_ops
block|{
name|int
name|nto_internal_debugging
decl_stmt|;
name|unsigned
name|nto_cpuinfo_flags
decl_stmt|;
name|int
name|nto_cpuinfo_valid
decl_stmt|;
name|int
function_decl|(
modifier|*
name|nto_regset_id
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|nto_supply_gregset
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|nto_supply_fpregset
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|nto_supply_altregset
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|nto_supply_regset
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|nto_register_area
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|unsigned
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|nto_regset_fill
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
name|struct
name|link_map_offsets
modifier|*
function_decl|(
modifier|*
name|nto_fetch_link_map_offsets
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|nto_target_ops
name|current_nto_target
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For 'maintenance debug nto-debug' command.  */
end_comment

begin_define
define|#
directive|define
name|nto_internal_debugging
define|\
value|(current_nto_target.nto_internal_debugging)
end_define

begin_comment
comment|/* The CPUINFO flags from the remote.  Currently used by    i386 for fxsave but future proofing other hosts.    This is initialized in procfs_attach or nto_start_remote    depending on our host/target.  It would only be invalid    if we were talking to an older pdebug which didn't support    the cpuinfo message.  */
end_comment

begin_define
define|#
directive|define
name|nto_cpuinfo_flags
define|\
value|(current_nto_target.nto_cpuinfo_flags)
end_define

begin_comment
comment|/* True if successfully retrieved cpuinfo from remote.  */
end_comment

begin_define
define|#
directive|define
name|nto_cpuinfo_valid
define|\
value|(current_nto_target.nto_cpuinfo_valid)
end_define

begin_comment
comment|/* Given a register, return an id that represents the Neutrino    regset it came from.  If reg == -1 update all regsets.  */
end_comment

begin_define
define|#
directive|define
name|nto_regset_id
parameter_list|(
name|reg
parameter_list|)
define|\
value|(*current_nto_target.nto_regset_id) (reg)
end_define

begin_define
define|#
directive|define
name|nto_supply_gregset
parameter_list|(
name|regs
parameter_list|)
define|\
value|(*current_nto_target.nto_supply_gregset) (regs)
end_define

begin_define
define|#
directive|define
name|nto_supply_fpregset
parameter_list|(
name|regs
parameter_list|)
define|\
value|(*current_nto_target.nto_supply_fpregset) (regs)
end_define

begin_define
define|#
directive|define
name|nto_supply_altregset
parameter_list|(
name|regs
parameter_list|)
define|\
value|(*current_nto_target.nto_supply_altregset) (regs)
end_define

begin_comment
comment|/* Given a regset, tell gdb about registers stored in data.  */
end_comment

begin_define
define|#
directive|define
name|nto_supply_regset
parameter_list|(
name|regset
parameter_list|,
name|data
parameter_list|)
define|\
value|(*current_nto_target.nto_supply_regset) (regset, data)
end_define

begin_comment
comment|/* Given a register and regset, calculate the offset into the regset    and stuff it into the last argument.  If regno is -1, calculate the    size of the entire regset.  Returns length of data, -1 if unknown    regset, 0 if unknown register.  */
end_comment

begin_define
define|#
directive|define
name|nto_register_area
parameter_list|(
name|reg
parameter_list|,
name|regset
parameter_list|,
name|off
parameter_list|)
define|\
value|(*current_nto_target.nto_register_area) (reg, regset, off)
end_define

begin_comment
comment|/* Build the Neutrino register set info into the data buffer.      Return -1 if unknown regset, 0 otherwise.  */
end_comment

begin_define
define|#
directive|define
name|nto_regset_fill
parameter_list|(
name|regset
parameter_list|,
name|data
parameter_list|)
define|\
value|(*current_nto_target.nto_regset_fill) (regset, data)
end_define

begin_comment
comment|/* Gives the fetch_link_map_offsets function exposure outside of    solib-svr4.c so that we can override relocate_section_addresses().  */
end_comment

begin_define
define|#
directive|define
name|nto_fetch_link_map_offsets
parameter_list|()
define|\
value|(*current_nto_target.nto_fetch_link_map_offsets) ()
end_define

begin_comment
comment|/* Keep this consistant with neutrino syspage.h.  */
end_comment

begin_enum
enum|enum
block|{
name|CPUTYPE_X86
block|,
name|CPUTYPE_PPC
block|,
name|CPUTYPE_MIPS
block|,
name|CPUTYPE_SPARE
block|,
name|CPUTYPE_ARM
block|,
name|CPUTYPE_SH
block|,
name|CPUTYPE_UNKNOWN
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|OSTYPE_QNX4
block|,
name|OSTYPE_NTO
block|}
enum|;
end_enum

begin_comment
comment|/* These correspond to the DSMSG_* versions in dsmsgs.h. */
end_comment

begin_enum
enum|enum
block|{
name|NTO_REG_GENERAL
block|,
name|NTO_REG_FLOAT
block|,
name|NTO_REG_SYSTEM
block|,
name|NTO_REG_ALT
block|,
name|NTO_REG_END
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|char
name|qnx_reg64
index|[
literal|8
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_debug_regs
block|{
name|qnx_reg64
name|padding
index|[
literal|1024
index|]
decl_stmt|;
block|}
name|nto_regset_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

