begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native-dependent definitions for FreeBSD/i386.    Copyright 1986, 1987, 1989, 1992, 1994, 1996, 1997, 2000, 2001    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NM_FBSD_H
end_ifndef

begin_define
define|#
directive|define
name|NM_FBSD_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PT_GETDBREGS
end_ifdef

begin_define
define|#
directive|define
name|I386_USE_GENERIC_WATCHPOINTS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"i386/nm-i386.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PARAM_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Provide access to the i386 hardware debugging registers.  */
end_comment

begin_define
define|#
directive|define
name|I386_DR_LOW_SET_CONTROL
parameter_list|(
name|control
parameter_list|)
define|\
value|i386bsd_dr_set_control (control)
end_define

begin_function_decl
specifier|extern
name|void
name|i386bsd_dr_set_control
parameter_list|(
name|unsigned
name|long
name|control
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|I386_DR_LOW_SET_ADDR
parameter_list|(
name|regnum
parameter_list|,
name|addr
parameter_list|)
define|\
value|i386bsd_dr_set_addr (regnum, addr)
end_define

begin_function_decl
specifier|extern
name|void
name|i386bsd_dr_set_addr
parameter_list|(
name|int
name|regnum
parameter_list|,
name|CORE_ADDR
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|I386_DR_LOW_RESET_ADDR
parameter_list|(
name|regnum
parameter_list|)
define|\
value|i386bsd_dr_reset_addr (regnum)
end_define

begin_function_decl
specifier|extern
name|void
name|i386bsd_dr_reset_addr
parameter_list|(
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|I386_DR_LOW_GET_STATUS
parameter_list|()
define|\
value|i386bsd_dr_get_status ()
end_define

begin_function_decl
specifier|extern
name|unsigned
name|long
name|i386bsd_dr_get_status
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Type of the third argument to the `ptrace' system call.  */
end_comment

begin_define
define|#
directive|define
name|PTRACE_ARG3_TYPE
value|caddr_t
end_define

begin_comment
comment|/* Override copies of {fetch,store}_inferior_registers in `infptrace.c'.  */
end_comment

begin_define
define|#
directive|define
name|FETCH_INFERIOR_REGISTERS
end_define

begin_comment
comment|/* Override child_resume in `infptrace.c' to work around a kernel bug.  */
end_comment

begin_define
define|#
directive|define
name|CHILD_RESUME
end_define

begin_comment
comment|/* We can attach and detach.  */
end_comment

begin_define
define|#
directive|define
name|ATTACH_DETACH
end_define

begin_escape
end_escape

begin_comment
comment|/* Support for the user struct.  */
end_comment

begin_comment
comment|/* Return the size of the user struct.  */
end_comment

begin_define
define|#
directive|define
name|KERNEL_U_SIZE
value|kernel_u_size ()
end_define

begin_function_decl
specifier|extern
name|int
name|kernel_u_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This is the amount to subtract from u.u_ar0    to get the offset in the core file of the register values.  */
end_comment

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|USRSTACK
end_define

begin_define
define|#
directive|define
name|REGISTER_U_ADDR
parameter_list|(
name|addr
parameter_list|,
name|blockend
parameter_list|,
name|regno
parameter_list|)
define|\
value|(addr) = register_u_addr ((blockend), (regno))
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|register_u_addr
parameter_list|(
name|CORE_ADDR
name|blockend
parameter_list|,
name|int
name|regno
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Shared library support.  */
end_comment

begin_comment
comment|/* The FreeBSD<link.h> uses the same condition to distinguish ELF    from a.out.  ELF implies SVR4 shared libraries.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|FREEBSD_ELF
argument_list|)
operator|||
name|defined
argument_list|(
name|__ELF__
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|FREEBSD_AOUT
argument_list|)
end_if

begin_define
define|#
directive|define
name|SVR4_SHARED_LIBS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"solib.h"
end_include

begin_comment
comment|/* Support for shared libraries. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SVR4_SHARED_LIBS
end_ifdef

begin_include
include|#
directive|include
file|"elf/common.h"
end_include

begin_comment
comment|/* Additional ELF shared library info. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SVR4_SHARED_LIBS
end_ifndef

begin_comment
comment|/* Make structure definitions match up with those expected in `solib.c'.  */
end_comment

begin_define
define|#
directive|define
name|link_object
value|sod
end_define

begin_define
define|#
directive|define
name|lo_name
value|sod_name
end_define

begin_define
define|#
directive|define
name|lo_library
value|sod_library
end_define

begin_define
define|#
directive|define
name|lo_unused
value|sod_reserved
end_define

begin_define
define|#
directive|define
name|lo_major
value|sod_major
end_define

begin_define
define|#
directive|define
name|lo_minor
value|sod_minor
end_define

begin_define
define|#
directive|define
name|lo_next
value|sod_next
end_define

begin_define
define|#
directive|define
name|link_map
value|so_map
end_define

begin_define
define|#
directive|define
name|lm_addr
value|som_addr
end_define

begin_define
define|#
directive|define
name|lm_name
value|som_path
end_define

begin_define
define|#
directive|define
name|lm_next
value|som_next
end_define

begin_define
define|#
directive|define
name|lm_lop
value|som_sod
end_define

begin_define
define|#
directive|define
name|lm_lob
value|som_sodbase
end_define

begin_define
define|#
directive|define
name|lm_rwt
value|som_write
end_define

begin_define
define|#
directive|define
name|lm_ld
value|som_dynamic
end_define

begin_define
define|#
directive|define
name|lm_lpd
value|som_spd
end_define

begin_define
define|#
directive|define
name|link_dynamic_2
value|section_dispatch_table
end_define

begin_define
define|#
directive|define
name|ld_loaded
value|sdt_loaded
end_define

begin_define
define|#
directive|define
name|ld_need
value|sdt_sods
end_define

begin_define
define|#
directive|define
name|ld_rules
value|sdt_filler1
end_define

begin_define
define|#
directive|define
name|ld_got
value|sdt_got
end_define

begin_define
define|#
directive|define
name|ld_plt
value|sdt_plt
end_define

begin_define
define|#
directive|define
name|ld_rel
value|sdt_rel
end_define

begin_define
define|#
directive|define
name|ld_hash
value|sdt_hash
end_define

begin_define
define|#
directive|define
name|ld_stab
value|sdt_nzlist
end_define

begin_define
define|#
directive|define
name|ld_stab_hash
value|sdt_filler2
end_define

begin_define
define|#
directive|define
name|ld_buckets
value|sdt_buckets
end_define

begin_define
define|#
directive|define
name|ld_symbols
value|sdt_strings
end_define

begin_define
define|#
directive|define
name|ld_symb_size
value|sdt_str_sz
end_define

begin_define
define|#
directive|define
name|ld_text
value|sdt_text_sz
end_define

begin_define
define|#
directive|define
name|ld_plt_sz
value|sdt_plt_sz
end_define

begin_define
define|#
directive|define
name|rtc_symb
value|rt_symbol
end_define

begin_define
define|#
directive|define
name|rtc_sp
value|rt_sp
end_define

begin_define
define|#
directive|define
name|rtc_next
value|rt_next
end_define

begin_define
define|#
directive|define
name|ld_debug
value|so_debug
end_define

begin_define
define|#
directive|define
name|ldd_version
value|dd_version
end_define

begin_define
define|#
directive|define
name|ldd_in_debugger
value|dd_in_debugger
end_define

begin_define
define|#
directive|define
name|ldd_sym_loaded
value|dd_sym_loaded
end_define

begin_define
define|#
directive|define
name|ldd_bp_addr
value|dd_bpt_addr
end_define

begin_define
define|#
directive|define
name|ldd_bp_inst
value|dd_bpt_shadow
end_define

begin_define
define|#
directive|define
name|ldd_cp
value|dd_cc
end_define

begin_define
define|#
directive|define
name|link_dynamic
value|_dynamic
end_define

begin_define
define|#
directive|define
name|ld_version
value|d_version
end_define

begin_define
define|#
directive|define
name|ldd
value|d_debug
end_define

begin_define
define|#
directive|define
name|ld_un
value|d_un
end_define

begin_define
define|#
directive|define
name|ld_2
value|d_sdt
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SVR4_SHARED_LIBS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NM_FBSD_H */
end_comment

end_unit

