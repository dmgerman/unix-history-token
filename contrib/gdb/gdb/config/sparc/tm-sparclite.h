begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for GDB for a Fujitsu SPARClite.    Copyright 1993, 1994, 1995, 1998, 1999, 2000    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"regcache.h"
end_include

begin_define
define|#
directive|define
name|TARGET_SPARCLITE
value|1
end_define

begin_comment
comment|/* Still needed for non-multi-arch case */
end_comment

begin_include
include|#
directive|include
file|"sparc/tm-sparc.h"
end_include

begin_comment
comment|/* Note: we are not defining GDB_MULTI_ARCH for the sparclet target    at this time, because we have not figured out how to detect the    sparclet target from the bfd structure.  */
end_comment

begin_comment
comment|/* Sparclite regs, for debugging purposes */
end_comment

begin_enum
enum|enum
block|{
name|DIA1_REGNUM
init|=
literal|72
block|,
comment|/* debug instr address register 1 */
name|DIA2_REGNUM
init|=
literal|73
block|,
comment|/* debug instr address register 2 */
name|DDA1_REGNUM
init|=
literal|74
block|,
comment|/* debug data address register 1 */
name|DDA2_REGNUM
init|=
literal|75
block|,
comment|/* debug data address register 2 */
name|DDV1_REGNUM
init|=
literal|76
block|,
comment|/* debug data value register 1 */
name|DDV2_REGNUM
init|=
literal|77
block|,
comment|/* debug data value register 2 */
name|DCR_REGNUM
init|=
literal|78
block|,
comment|/* debug control register */
name|DSR_REGNUM
init|=
literal|79
comment|/* debug status regsiter */
block|}
enum|;
end_enum

begin_comment
comment|/* overrides of tm-sparc.h */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_BYTE_ORDER
end_undef

begin_comment
comment|/* Select the sparclite disassembler.  Slightly different instruction set from    the V8 sparc.  */
end_comment

begin_undef
undef|#
directive|undef
name|TM_PRINT_INSN_MACH
end_undef

begin_define
define|#
directive|define
name|TM_PRINT_INSN_MACH
value|bfd_mach_sparc_sparclite
end_define

begin_comment
comment|/* Amount PC must be decremented by after a hardware instruction breakpoint.    This is often the number of bytes in BREAKPOINT    but not always.  */
end_comment

begin_define
define|#
directive|define
name|DECR_PC_AFTER_HW_BREAK
value|4
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GDB_MULTI_ARCH
argument_list|)
operator|||
operator|(
name|GDB_MULTI_ARCH
operator|==
literal|0
operator|)
end_if

begin_comment
comment|/*  * The following defines must go away for MULTI_ARCH.  */
end_comment

begin_undef
undef|#
directive|undef
name|FRAME_CHAIN_VALID
end_undef

begin_define
define|#
directive|define
name|FRAME_CHAIN_VALID
parameter_list|(
name|FP
parameter_list|,
name|FI
parameter_list|)
value|func_frame_chain_valid (FP, FI)
end_define

begin_undef
undef|#
directive|undef
name|NUM_REGS
end_undef

begin_define
define|#
directive|define
name|NUM_REGS
value|80
end_define

begin_undef
undef|#
directive|undef
name|REGISTER_BYTES
end_undef

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(32*4+32*4+8*4+8*4)
end_define

begin_undef
undef|#
directive|undef
name|REGISTER_NAMES
end_undef

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{ "g0", "g1", "g2", "g3", "g4", "g5", "g6", "g7",       \   "o0", "o1", "o2", "o3", "o4", "o5", "sp", "o7",       \   "l0", "l1", "l2", "l3", "l4", "l5", "l6", "l7",       \   "i0", "i1", "i2", "i3", "i4", "i5", "fp", "i7",       \                                                                 \   "f0", "f1", "f2", "f3", "f4", "f5", "f6", "f7",       \   "f8", "f9", "f10", "f11", "f12", "f13", "f14", "f15", \   "f16", "f17", "f18", "f19", "f20", "f21", "f22", "f23",       \   "f24", "f25", "f26", "f27", "f28", "f29", "f30", "f31",       \                                                                 \   "y", "psr", "wim", "tbr", "pc", "npc", "fpsr", "cpsr",        \   "dia1", "dia2", "dda1", "dda2", "ddv1", "ddv2", "dcr", "dsr" }
end_define

begin_define
define|#
directive|define
name|DIA1_REGNUM
value|72
end_define

begin_comment
comment|/* debug instr address register 1 */
end_comment

begin_define
define|#
directive|define
name|DIA2_REGNUM
value|73
end_define

begin_comment
comment|/* debug instr address register 2 */
end_comment

begin_define
define|#
directive|define
name|DDA1_REGNUM
value|74
end_define

begin_comment
comment|/* debug data address register 1 */
end_comment

begin_define
define|#
directive|define
name|DDA2_REGNUM
value|75
end_define

begin_comment
comment|/* debug data address register 2 */
end_comment

begin_define
define|#
directive|define
name|DDV1_REGNUM
value|76
end_define

begin_comment
comment|/* debug data value register 1 */
end_comment

begin_define
define|#
directive|define
name|DDV2_REGNUM
value|77
end_define

begin_comment
comment|/* debug data value register 2 */
end_comment

begin_define
define|#
directive|define
name|DCR_REGNUM
value|78
end_define

begin_comment
comment|/* debug control register */
end_comment

begin_define
define|#
directive|define
name|DSR_REGNUM
value|79
end_define

begin_comment
comment|/* debug status regsiter */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GDB_MULTI_ARCH */
end_comment

begin_define
define|#
directive|define
name|TARGET_HW_BREAK_LIMIT
value|2
end_define

begin_define
define|#
directive|define
name|TARGET_HW_WATCH_LIMIT
value|2
end_define

begin_comment
comment|/* Enable watchpoint macro's */
end_comment

begin_define
define|#
directive|define
name|TARGET_HAS_HARDWARE_WATCHPOINTS
end_define

begin_define
define|#
directive|define
name|TARGET_CAN_USE_HARDWARE_WATCHPOINT
parameter_list|(
name|type
parameter_list|,
name|cnt
parameter_list|,
name|ot
parameter_list|)
define|\
value|sparclite_check_watch_resources (type, cnt, ot)
end_define

begin_comment
comment|/* When a hardware watchpoint fires off the PC will be left at the    instruction which caused the watchpoint.  It will be necessary for    GDB to step over the watchpoint. ***     #define STOPPED_BY_WATCHPOINT(W) \    ((W).kind == TARGET_WAITKIND_STOPPED \&& (W).value.sig == TARGET_SIGNAL_TRAP \&& ((int) read_register (IPSW_REGNUM)& 0x00100000))  */
end_comment

begin_comment
comment|/* Use these macros for watchpoint insertion/deletion.  */
end_comment

begin_define
define|#
directive|define
name|target_insert_watchpoint
parameter_list|(
name|addr
parameter_list|,
name|len
parameter_list|,
name|type
parameter_list|)
value|sparclite_insert_watchpoint (addr, len, type)
end_define

begin_define
define|#
directive|define
name|target_remove_watchpoint
parameter_list|(
name|addr
parameter_list|,
name|len
parameter_list|,
name|type
parameter_list|)
value|sparclite_remove_watchpoint (addr, len, type)
end_define

begin_define
define|#
directive|define
name|target_insert_hw_breakpoint
parameter_list|(
name|addr
parameter_list|,
name|len
parameter_list|)
value|sparclite_insert_hw_breakpoint (addr, len)
end_define

begin_define
define|#
directive|define
name|target_remove_hw_breakpoint
parameter_list|(
name|addr
parameter_list|,
name|len
parameter_list|)
value|sparclite_remove_hw_breakpoint (addr, len)
end_define

begin_define
define|#
directive|define
name|target_stopped_data_address
parameter_list|()
value|sparclite_stopped_data_address()
end_define

end_unit

