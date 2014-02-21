begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native macro definitions for GDB on an Intel i[3456]86.    Copyright 2001, 2004 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NM_I386_H
end_ifndef

begin_define
define|#
directive|define
name|NM_I386_H
value|1
end_define

begin_comment
comment|/* Hardware-assisted breakpoints and watchpoints.  */
end_comment

begin_comment
comment|/* Targets should define this to use the generic x86 watchpoint support.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|I386_USE_GENERIC_WATCHPOINTS
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_HAS_HARDWARE_WATCHPOINTS
end_ifndef

begin_define
define|#
directive|define
name|TARGET_HAS_HARDWARE_WATCHPOINTS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Clear the reference counts and forget everything we knew about DRi.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|i386_cleanup_dregs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Insert a watchpoint to watch a memory region which starts at    address ADDR and whose length is LEN bytes.  Watch memory accesses    of the type TYPE.  Return 0 on success, -1 on failure.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|i386_insert_watchpoint
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|int
name|len
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Remove a watchpoint that watched the memory region which starts at    address ADDR, whose length is LEN bytes, and for accesses of the    type TYPE.  Return 0 on success, -1 on failure.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|i386_remove_watchpoint
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|int
name|len
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return non-zero if we can watch a memory region that starts at    address ADDR and whose length is LEN bytes.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|i386_region_ok_for_watchpoint
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return non-zero if the inferior has some break/watchpoint that    triggered.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|i386_stopped_by_hwbp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* If the inferior has some break/watchpoint that triggered, return    the address associated with that break/watchpoint.  Otherwise,    return zero.  */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|i386_stopped_data_address
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Insert a hardware-assisted breakpoint at address ADDR.  SHADOW is    unused.  Return 0 on success, EBUSY on failure.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|i386_insert_hw_breakpoint
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|void
modifier|*
name|shadow
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Remove a hardware-assisted breakpoint at address ADDR.  SHADOW is    unused. Return 0 on success, -1 on failure.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|i386_remove_hw_breakpoint
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|void
modifier|*
name|shadow
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns the number of hardware watchpoints of type TYPE that we can    set.  Value is positive if we can set CNT watchpoints, zero if    setting watchpoints of type TYPE is not supported, and negative if    CNT is more than the maximum number of watchpoints of type TYPE    that we can support.  TYPE is one of bp_hardware_watchpoint,    bp_read_watchpoint, bp_write_watchpoint, or bp_hardware_breakpoint.    CNT is the number of such watchpoints used so far (including this    one).  OTHERTYPE is non-zero if other types of watchpoints are    currently enabled.     We always return 1 here because we don't have enough information    about possible overlap of addresses that they want to watch.  As an    extreme example, consider the case where all the watchpoints watch    the same address and the same region length: then we can handle a    virtually unlimited number of watchpoints, due to debug register    sharing implemented via reference counts in i386-nat.c.  */
end_comment

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
value|1
end_define

begin_comment
comment|/* Returns non-zero if we can use hardware watchpoints to watch a    region whose address is ADDR and whose length is LEN.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_REGION_OK_FOR_HW_WATCHPOINT
parameter_list|(
name|addr
parameter_list|,
name|len
parameter_list|)
define|\
value|i386_region_ok_for_watchpoint (addr, len)
end_define

begin_comment
comment|/* After a watchpoint trap, the PC points to the instruction after the    one that caused the trap.  Therefore we don't need to step over it.    But we do need to reset the status register to avoid another trap.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_CONTINUABLE_WATCHPOINT
value|1
end_define

begin_define
define|#
directive|define
name|STOPPED_BY_WATCHPOINT
parameter_list|(
name|W
parameter_list|)
value|(i386_stopped_data_address () != 0)
end_define

begin_define
define|#
directive|define
name|target_stopped_data_address
parameter_list|()
value|i386_stopped_data_address ()
end_define

begin_comment
comment|/* Use these macros for watchpoint insertion/removal.  */
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
define|\
value|i386_insert_watchpoint (addr, len, type)
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
define|\
value|i386_remove_watchpoint (addr, len, type)
end_define

begin_define
define|#
directive|define
name|target_insert_hw_breakpoint
parameter_list|(
name|addr
parameter_list|,
name|shadow
parameter_list|)
define|\
value|i386_insert_hw_breakpoint (addr, shadow)
end_define

begin_define
define|#
directive|define
name|target_remove_hw_breakpoint
parameter_list|(
name|addr
parameter_list|,
name|shadow
parameter_list|)
define|\
value|i386_remove_hw_breakpoint (addr, shadow)
end_define

begin_comment
comment|/* child_post_startup_inferior used to    reset all debug registers by calling i386_cleanup_dregs ().  */
end_comment

begin_define
define|#
directive|define
name|CHILD_POST_STARTUP_INFERIOR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I386_USE_GENERIC_WATCHPOINTS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NM_I386_H */
end_comment

end_unit

