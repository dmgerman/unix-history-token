begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native-dependent definitions for Solaris SPARC.     Copyright 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NM_SOL2_H
end_ifndef

begin_define
define|#
directive|define
name|NM_SOL2_H
end_define

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

begin_comment
comment|/* Shared library support.  */
end_comment

begin_include
include|#
directive|include
file|"solib.h"
end_include

begin_comment
comment|/* Hardware wactchpoints.  */
end_comment

begin_comment
comment|/* Solaris 2.6 and above can do HW watchpoints.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEW_PROC_API
end_ifdef

begin_define
define|#
directive|define
name|TARGET_HAS_HARDWARE_WATCHPOINTS
end_define

begin_comment
comment|/* The man page for proc(4) on Solaris 2.6 and up says that the system    can support "thousands" of hardware watchpoints, but gives no    method for finding out how many; It doesn't say anything about the    allowed size for the watched area either.  So we just tell GDB    'yes'.  */
end_comment

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
comment|/* When a hardware watchpoint fires off the PC will be left at the    instruction following the one which caused the watchpoint.  It will    *NOT* be necessary for GDB to step over the watchpoint.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_CONTINUABLE_WATCHPOINT
value|1
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
comment|/* Use these macros for watchpoint insertion/deletion.  TYPE can be 0    (write watch), 1 (read watch), 2 (access watch (read/write).  */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* nm-sol2.h */
end_comment

end_unit

