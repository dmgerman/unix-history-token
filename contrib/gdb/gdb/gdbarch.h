begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Architecture commands for GDB, the GNU debugger.    Copyright 1998, Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GDBARCH_H
end_ifndef

begin_define
define|#
directive|define
name|GDBARCH_H
end_define

begin_comment
comment|/* The target-system-dependant byte order is dynamic */
end_comment

begin_comment
comment|/* TARGET_BYTE_ORDER_SELECTABLE_P determines if the target endianness    is selectable at runtime.  The user can use the `set endian'    command to change it.  TARGET_BYTE_ORDER_AUTO is nonzero when    target_byte_order should be auto-detected (from the program image    say). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_BYTE_ORDER_SELECTABLE_P
end_ifndef

begin_comment
comment|/* compat - Catch old targets that define TARGET_BYTE_ORDER_SLECTABLE    when they should have defined TARGET_BYTE_ORDER_SELECTABLE_P 1 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_BYTE_ORDER_SELECTABLE
end_ifdef

begin_define
define|#
directive|define
name|TARGET_BYTE_ORDER_SELECTABLE_P
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_BYTE_ORDER_SELECTABLE_P
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|target_byte_order
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_BYTE_ORDER_SELECTABLE
end_ifdef

begin_comment
comment|/* compat - Catch old targets that define TARGET_BYTE_ORDER_SELECTABLE    and expect defs.h to re-define TARGET_BYTE_ORDER. */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_BYTE_ORDER
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_BYTE_ORDER
end_ifndef

begin_define
define|#
directive|define
name|TARGET_BYTE_ORDER
value|(target_byte_order + 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|target_byte_order_auto
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_BYTE_ORDER_AUTO
end_ifndef

begin_define
define|#
directive|define
name|TARGET_BYTE_ORDER_AUTO
value|(target_byte_order_auto + 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The target-system-dependant BFD architecture is dynamic */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|target_architecture_auto
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ARCHITECTURE_AUTO
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ARCHITECTURE_AUTO
value|(target_architecture_auto + 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|bfd_arch_info
modifier|*
name|target_architecture
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ARCHITECTURE
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ARCHITECTURE
value|(target_architecture + 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Notify the target dependant backend of a change to the selected    architecture. A zero return status indicates that the target did    not like the change. */
end_comment

begin_extern
extern|extern int (*target_architecture_hook
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|bfd_arch_info
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The target-system-dependant disassembler is semi-dynamic */
end_comment

begin_include
include|#
directive|include
file|"dis-asm.h"
end_include

begin_comment
comment|/* Get defs for disassemble_info */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dis_asm_read_memory
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
name|memaddr
operator|,
name|bfd_byte
operator|*
name|myaddr
operator|,
name|int
name|len
operator|,
name|disassemble_info
operator|*
name|info
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dis_asm_memory_error
name|PARAMS
argument_list|(
operator|(
name|int
name|status
operator|,
name|bfd_vma
name|memaddr
operator|,
name|disassemble_info
operator|*
name|info
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dis_asm_print_address
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
name|addr
operator|,
name|disassemble_info
operator|*
name|info
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern int (*tm_print_insn
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|disassemble_info
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|disassemble_info
name|tm_print_insn_info
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_PRINT_INSN
end_ifndef

begin_define
define|#
directive|define
name|TARGET_PRINT_INSN
parameter_list|(
name|vma
parameter_list|,
name|info
parameter_list|)
value|(*tm_print_insn) (vma, info)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_PRINT_INSN_INFO
end_ifndef

begin_define
define|#
directive|define
name|TARGET_PRINT_INSN_INFO
value|(&tm_print_insn_info)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Set the dynamic target-system-dependant parameters (architecture,    byte-order, ...) using information found in the BFD */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|set_gdbarch_from_file
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Explicitly set the dynamic target-system-dependant parameters based    on bfd_architecture and machine. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|set_architecture_from_arch_mach
name|PARAMS
argument_list|(
operator|(
expr|enum
name|bfd_architecture
operator|,
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* gdbarch trace variable */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gdbarch_debug
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

