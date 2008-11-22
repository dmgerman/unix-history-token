begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, NetBSD/arm ELF version.    Copyright (C) 2002, 2003 Free Software Foundation, Inc.    Contributed by Wasabi Systems, Inc.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Run-time Target Specification.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fputs (" (NetBSD/arm ELF)", stderr);
end_define

begin_comment
comment|/* arm.h defaults to ARM6 CPU.  */
end_comment

begin_comment
comment|/* This defaults us to little-endian.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ENDIAN_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ENDIAN_DEFAULT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|MULTILIB_DEFAULTS
end_undef

begin_comment
comment|/* Default it to use ATPCS with soft-VFP.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
define|\
value|(ARM_FLAG_APCS_32			\    | ARM_FLAG_SOFT_FLOAT		\    | ARM_FLAG_APCS_FRAME		\    | ARM_FLAG_ATPCS			\    | ARM_FLAG_VFP			\    | ARM_FLAG_MMU_TRAPS			\    | TARGET_ENDIAN_DEFAULT)
end_define

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do					\     {					\       NETBSD_OS_CPP_BUILTINS_ELF();	\     }					\   while (0)
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
value|NETBSD_CPP_SPEC
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_EXTRA_ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_ASM_SPEC
define|\
value|"-matpcs %{fpic|fpie:-k} %{fPIC|fPIE:-k}"
end_define

begin_comment
comment|/* Default floating point model is soft-VFP.    FIXME: -mhard-float currently implies FPA.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_ASM_FLOAT_SPEC
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_ASM_FLOAT_SPEC
define|\
value|"%{mhard-float:-mfpu=fpa} \    %{msoft-float:-mfpu=softvfp} \    %{!mhard-float: \      %{!msoft-float:-mfpu=softvfp}}"
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_EXTRA_SPECS
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_SPECS
define|\
value|{ "subtarget_extra_asm_spec",	SUBTARGET_EXTRA_ASM_SPEC }, \   { "subtarget_asm_float_spec", SUBTARGET_ASM_FLOAT_SPEC }, \   { "netbsd_link_spec",		NETBSD_LINK_SPEC_ELF },	\   { "netbsd_entry_point",	NETBSD_ENTRY_POINT },
end_define

begin_define
define|#
directive|define
name|NETBSD_ENTRY_POINT
value|"__start"
end_define

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
define|\
value|"-X %{mbig-endian:-EB} %{mlittle-endian:-EL} \    %(netbsd_link_spec)"
end_define

begin_comment
comment|/* Make GCC agree with<machine/ansi.h>.  */
end_comment

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"long unsigned int"
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
value|"long int"
end_define

begin_comment
comment|/* We don't have any limit on the length as out debugger is GDB.  */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_CONTIN_LENGTH
end_undef

begin_comment
comment|/* NetBSD does its profiling differently to the Acorn compiler. We          don't need a word following the mcount call; and to skip it    requires either an assembly stub or use of fomit-frame-pointer when      compiling the profiling functions.  Since we break Acorn CC    compatibility below a little more won't hurt.  */
end_comment

begin_undef
undef|#
directive|undef
name|ARM_FUNCTION_PROFILER
end_undef

begin_define
define|#
directive|define
name|ARM_FUNCTION_PROFILER
parameter_list|(
name|STREAM
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|{							\   asm_fprintf (STREAM, "\tmov\t%Rip, %Rlr\n");		\   asm_fprintf (STREAM, "\tbl\t__mcount%s\n",		\ 	       NEED_PLT_RELOC ? "(PLT)" : "");		\ }
end_define

begin_comment
comment|/* VERY BIG NOTE: Change of structure alignment for NetBSD/arm.    There are consequences you should be aware of...     Normally GCC/arm uses a structure alignment of 32 for compatibility    with armcc.  This means that structures are padded to a word    boundary.  However this causes problems with bugged NetBSD kernel    code (possibly userland code as well - I have not checked every    binary).  The nature of this bugged code is to rely on sizeof()    returning the correct size of various structures rounded to the      nearest byte (SCSI and ether code are two examples, the vm system    is another).  This code breaks when the structure alignment is 32    as sizeof() will report a word=rounded size.  By changing the            structure alignment to 8. GCC will conform to what is expected by    NetBSD.        This has several side effects that should be considered.    1. Structures will only be aligned to the size of the largest member.       i.e. structures containing only bytes will be byte aligned.            structures containing shorts will be half word aligned.                      structures containing ints will be word aligned.                           This means structures should be padded to a word boundary if       alignment of 32 is required for byte structures etc.            2. A potential performance penalty may exist if strings are no longer       word aligned.  GCC will not be able to use word load/stores to copy       short strings.     This modification is not encouraged but with the present state of the    NetBSD source tree it is currently the only solution that meets the    requirements.  */
end_comment

begin_undef
undef|#
directive|undef
name|DEFAULT_STRUCTURE_SIZE_BOUNDARY
end_undef

begin_define
define|#
directive|define
name|DEFAULT_STRUCTURE_SIZE_BOUNDARY
value|8
end_define

begin_comment
comment|/* Emit code to set up a trampoline and synchronize the caches.  */
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
value|do									\   {									\     emit_move_insn (gen_rtx (MEM, SImode, plus_constant ((TRAMP), 8)),	\ 		    (CXT));						\     emit_move_insn (gen_rtx (MEM, SImode, plus_constant ((TRAMP), 12)),	\ 		    (FNADDR));						\     emit_library_call (gen_rtx_SYMBOL_REF (Pmode, "__clear_cache"),	\ 		       0, VOIDmode, 2, TRAMP, Pmode,			\ 		       plus_constant (TRAMP, TRAMPOLINE_SIZE), Pmode);	\   }									\ while (0)
end_define

begin_comment
comment|/* Clear the instruction cache from `BEG' to `END'.  This makes a    call to the ARM_SYNC_ICACHE architecture specific syscall.  */
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
value|do									\   {									\     extern int sysarch(int number, void *args);				\     struct								\       {									\ 	unsigned int addr;						\ 	int          len;						\       } s;								\     s.addr = (unsigned int)(BEG);					\     s.len = (END) - (BEG);						\     (void) sysarch (0,&s);						\   }									\ while (0)
end_define

end_unit

