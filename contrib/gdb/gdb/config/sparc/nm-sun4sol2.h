begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native-dependent definitions for Sparc running SVR4.    Copyright 1994, 1996, 1997, 1999, 2000 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"regcache.h"
end_include

begin_comment
comment|/* Include the generic SVR4 definitions.  */
end_comment

begin_include
include|#
directive|include
file|<nm-sysv4.h>
end_include

begin_comment
comment|/* Before storing, we need to read all the registers.  */
end_comment

begin_define
define|#
directive|define
name|CHILD_PREPARE_TO_STORE
parameter_list|()
value|read_register_bytes (0, NULL, REGISTER_BYTES)
end_define

begin_comment
comment|/* Solaris PSRVADDR support does not seem to include a place for nPC.  */
end_comment

begin_define
define|#
directive|define
name|PRSVADDR_BROKEN
end_define

begin_comment
comment|/* gdb wants to use the prgregset_t interface rather than    the gregset_t interface, partly because that's what's    used in core-sol2.c */
end_comment

begin_define
define|#
directive|define
name|GDB_GREGSET_T
value|prgregset_t
end_define

begin_define
define|#
directive|define
name|GDB_FPREGSET_T
value|prfpregset_t
end_define

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

begin_comment
comment|/* When a hardware watchpoint fires off the PC will be left at the    instruction following the one which caused the watchpoint.      It will *NOT* be necessary for GDB to step over the watchpoint. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CONTINUABLE_WATCHPOINT
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

