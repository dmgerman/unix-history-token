begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters for target execution on an RS6000, for GDB, the GNU debugger.     Copyright 1986, 1987, 1989, 1991, 1992, 1993, 1994, 1995, 1996,    1997, 1998, 1999, 2000, 2004 Free Software Foundation, Inc.     Contributed by IBM Corporation.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_struct_decl
struct_decl|struct
name|frame_info
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|GDB_MULTI_ARCH
value|1
end_define

begin_comment
comment|/* Minimum possible text address in AIX */
end_comment

begin_define
define|#
directive|define
name|TEXT_SEGMENT_BASE
value|0x10000000
end_define

begin_comment
comment|/* Return whether PC in function NAME is in code that should be skipped when    single-stepping.  */
end_comment

begin_define
define|#
directive|define
name|IN_SOLIB_RETURN_TRAMPOLINE
parameter_list|(
name|pc
parameter_list|,
name|name
parameter_list|)
define|\
value|rs6000_in_solib_return_trampoline (pc, name)
end_define

begin_function_decl
specifier|extern
name|int
name|rs6000_in_solib_return_trampoline
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* If PC is in some function-call trampoline code, return the PC    where the function itself actually starts.  If not, return NULL.  */
end_comment

begin_define
define|#
directive|define
name|SKIP_TRAMPOLINE_CODE
parameter_list|(
name|pc
parameter_list|)
value|rs6000_skip_trampoline_code (pc)
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|rs6000_skip_trampoline_code
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* AIX has a couple of strange returns from wait().  */
end_comment

begin_define
define|#
directive|define
name|CHILD_SPECIAL_WAITSTATUS
parameter_list|(
name|ourstatus
parameter_list|,
name|hoststatus
parameter_list|)
value|( \
comment|/* "stop after load" status.  */
value|\   (hoststatus) == 0x57c ? (ourstatus)->kind = TARGET_WAITKIND_LOADED, 1 : \   \
comment|/* signal 0. I have no idea why wait(2) returns with this status word.  */
value|\
comment|/* It looks harmless. */
value|\   (hoststatus) == 0x7f ? (ourstatus)->kind = TARGET_WAITKIND_SPURIOUS, 1 : \   \
comment|/* A normal waitstatus.  Let the usual macros deal with it.  */
value|\   0)
end_define

begin_comment
comment|/* In xcoff, we cannot process line numbers when we see them. This is    mainly because we don't know the boundaries of the include files. So,    we postpone that, and then enter and sort(?) the whole line table at    once, when we are closing the current symbol table in end_symtab(). */
end_comment

begin_define
define|#
directive|define
name|PROCESS_LINENUMBER_HOOK
parameter_list|()
value|aix_process_linenos ()
end_define

begin_function_decl
specifier|extern
name|void
name|aix_process_linenos
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Register numbers of various important registers.    Note that some of these values are "real" register numbers,    and correspond to the general registers of the machine,    and some are "phony" register numbers which are too large    to be actual register numbers as far as the user is concerned    but do serve to get the desired values when passed to read_register.  */
end_comment

begin_define
define|#
directive|define
name|FP0_REGNUM
value|32
end_define

begin_comment
comment|/* Floating point register 0 */
end_comment

begin_define
define|#
directive|define
name|FPLAST_REGNUM
value|63
end_define

begin_comment
comment|/* Last floating point register */
end_comment

begin_comment
comment|/* Define other aspects of the stack frame.  */
end_comment

begin_define
define|#
directive|define
name|DEPRECATED_INIT_FRAME_PC_FIRST
parameter_list|(
name|fromleaf
parameter_list|,
name|prev
parameter_list|)
define|\
value|(fromleaf ? DEPRECATED_SAVED_PC_AFTER_CALL (prev->next) : \ 	      prev->next ? DEPRECATED_FRAME_SAVED_PC (prev->next) : read_pc ())
end_define

begin_comment
comment|/* Notice when a new child process is started. */
end_comment

begin_define
define|#
directive|define
name|TARGET_CREATE_INFERIOR_HOOK
value|rs6000_create_inferior
end_define

begin_function_decl
specifier|extern
name|void
name|rs6000_create_inferior
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Hook in rs6000-tdep.c for determining the TOC address when    calling functions in the inferior.  */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
function_decl|(
modifier|*
name|rs6000_find_toc_address_hook
function_decl|)
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Hook in rs6000-tdep.c to set the current architecture when starting a    child process. */
end_comment

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|rs6000_set_host_arch_hook
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* We need solib.h for building cross debuggers.  However, we don't want    to clobber any special solib support required by native debuggers, so    only include solib.h if SOLIB_ADD is not defined.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SOLIB_ADD
end_ifndef

begin_include
include|#
directive|include
file|"solib.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

