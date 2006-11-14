begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native support for i386 running Solaris 2.    Copyright 1998, 1999, 2000 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"config/nm-sysv4.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NEW_PROC_API
end_ifdef

begin_comment
comment|/* Solaris 6 and above can do HW watchpoints */
end_comment

begin_define
define|#
directive|define
name|TARGET_HAS_HARDWARE_WATCHPOINTS
end_define

begin_comment
comment|/* The man page for proc4 on solaris 6 and 7 says that the system    can support "thousands" of hardware watchpoints, but gives no    method for finding out how many.  So just tell GDB 'yes'.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_CAN_USE_HARDWARE_WATCHPOINT
parameter_list|(
name|TYPE
parameter_list|,
name|CNT
parameter_list|,
name|OT
parameter_list|)
value|1
end_define

begin_define
define|#
directive|define
name|TARGET_REGION_SIZE_OK_FOR_HW_WATCHPOINT
parameter_list|(
name|SIZE
parameter_list|)
value|1
end_define

begin_comment
comment|/* When a hardware watchpoint fires off the PC will be left at the    instruction following the one which caused the watchpoint.      It will *NOT* be necessary for GDB to step over the watchpoint. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CONTINUABLE_WATCHPOINT
value|1
end_define

begin_comment
comment|/* Solaris x86 2.6 and 2.7 targets have a kernel bug when stepping    over an instruction that causes a page fault without triggering    a hardware watchpoint. The kernel properly notices that it shouldn't    stop, because the hardware watchpoint is not triggered, but it forgets    the step request and continues the program normally.    Work around the problem by removing hardware watchpoints if a step is    requested, GDB will check for a hardware watchpoint trigger after the    step anyway.  */
end_comment

begin_define
define|#
directive|define
name|CANNOT_STEP_HW_WATCHPOINTS
end_define

begin_function_decl
specifier|extern
name|int
name|procfs_stopped_by_watchpoint
parameter_list|(
name|ptid_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|STOPPED_BY_WATCHPOINT
parameter_list|(
name|W
parameter_list|)
define|\
value|procfs_stopped_by_watchpoint(inferior_ptid)
end_define

begin_comment
comment|/* Use these macros for watchpoint insertion/deletion.  */
end_comment

begin_comment
comment|/* type can be 0: write watch, 1: read watch, 2: access watch (read/write) */
end_comment

begin_function_decl
specifier|extern
name|int
name|procfs_set_watchpoint
parameter_list|(
name|ptid_t
parameter_list|,
name|CORE_ADDR
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|target_insert_watchpoint
parameter_list|(
name|ADDR
parameter_list|,
name|LEN
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|procfs_set_watchpoint (inferior_ptid, ADDR, LEN, TYPE, 1)
end_define

begin_define
define|#
directive|define
name|target_remove_watchpoint
parameter_list|(
name|ADDR
parameter_list|,
name|LEN
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|procfs_set_watchpoint (inferior_ptid, ADDR, 0, 0, 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEW_PROC_API */
end_comment

end_unit

