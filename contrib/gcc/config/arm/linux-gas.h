begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.    ARM Linux-based GNU systems version.    Copyright (C) 1997, 1998, 1999, 2000, 2001 Free Software Foundation, Inc.    Contributed by Russell King<rmk92@ecs.soton.ac.uk>.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This is how we tell the assembler that a symbol is weak.    GAS always supports weak symbols.  */
end_comment

begin_comment
comment|/* This is used in ASM_FILE_START.  */
end_comment

begin_undef
undef|#
directive|undef
name|ARM_OS_NAME
end_undef

begin_define
define|#
directive|define
name|ARM_OS_NAME
value|"Linux"
end_define

begin_comment
comment|/* Unsigned chars produces much better code than signed.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SIGNED_CHAR
value|0
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_CPP_SPEC
value|"%{posix:-D_POSIX_SOURCE} %{fPIC:-D__PIC__ -D__pic__} %{fpic:-D__PIC__ -D__pic__}"
end_define

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
end_undef

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"long int"
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|BITS_PER_WORD
end_define

begin_comment
comment|/* Emit code to set up a trampoline and synchronise the caches.  */
end_comment

begin_undef
undef|#
directive|undef
name|INITIALIZE_TRAMPOLINE
end_undef

begin_define
define|#
directive|define
name|INITIALIZE_TRAMPOLINE
parameter_list|(
name|TRAMP
parameter_list|,
name|FNADDR
parameter_list|,
name|CXT
parameter_list|)
define|\
value|{									\   emit_move_insn (gen_rtx (MEM, SImode, plus_constant ((TRAMP), 8)),	\ 		  (CXT));						\   emit_move_insn (gen_rtx (MEM, SImode, plus_constant ((TRAMP), 12)),	\ 		  (FNADDR));						\   emit_library_call (gen_rtx_SYMBOL_REF (Pmode, "__clear_cache"),	\ 		     0, VOIDmode, 2, TRAMP, Pmode,			\ 		     plus_constant (TRAMP, TRAMPOLINE_SIZE), Pmode);	\ }
end_define

begin_comment
comment|/* Clear the instruction cache from `beg' to `end'.  This makes an    inline system call to SYS_cacheflush.  */
end_comment

begin_define
define|#
directive|define
name|CLEAR_INSN_CACHE
parameter_list|(
name|BEG
parameter_list|,
name|END
parameter_list|)
define|\
value|{									\   register unsigned long _beg __asm ("a1") = (unsigned long) (BEG);	\   register unsigned long _end __asm ("a2") = (unsigned long) (END);	\   register unsigned long _flg __asm ("a3") = 0;				\   __asm __volatile ("swi 0x9f0002		@ sys_cacheflush"	\ 		    : "=r" (_beg)					\ 		    : "0" (_beg), "r" (_end), "r" (_flg));		\ }
end_define

end_unit

