begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler,    for powerpc machines running Linux.    Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001 Free Software Foundation,     Inc.    Contributed by Michael Meissner (meissner@cygnus.com).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Don't assume anything about the header files.  */
end_comment

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

begin_undef
undef|#
directive|undef
name|MD_EXEC_PREFIX
end_undef

begin_undef
undef|#
directive|undef
name|MD_STARTFILE_PREFIX
end_undef

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
define|\
value|"-DPPC -D__ELF__ -Dpowerpc -Acpu=powerpc -Amachine=powerpc"
end_define

begin_undef
undef|#
directive|undef
name|CPP_OS_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_OS_DEFAULT_SPEC
value|"%(cpp_os_linux)"
end_define

begin_comment
comment|/* The GNU C++ standard library currently requires _GNU_SOURCE being    defined on glibc-based systems. This temporary hack accomplishes this,    it should go away as soon as libstdc++-v3 has a real fix.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPLUSPLUS_CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPLUSPLUS_CPP_SPEC
value|"-D_GNU_SOURCE %(cpp)"
end_define

begin_undef
undef|#
directive|undef
name|LINK_SHLIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SHLIB_SPEC
value|"%{shared:-shared} %{!shared: %{static:-static}}"
end_define

begin_undef
undef|#
directive|undef
name|LIB_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_DEFAULT_SPEC
value|"%(lib_linux)"
end_define

begin_undef
undef|#
directive|undef
name|STARTFILE_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_DEFAULT_SPEC
value|"%(startfile_linux)"
end_define

begin_undef
undef|#
directive|undef
name|ENDFILE_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_DEFAULT_SPEC
value|"%(endfile_linux)"
end_define

begin_undef
undef|#
directive|undef
name|LINK_START_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_START_DEFAULT_SPEC
value|"%(link_start_linux)"
end_define

begin_undef
undef|#
directive|undef
name|LINK_OS_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_OS_DEFAULT_SPEC
value|"%(link_os_linux)"
end_define

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (PowerPC GNU/Linux)");
end_define

begin_comment
comment|/* Override rs6000.h definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_APP_ON
end_undef

begin_define
define|#
directive|define
name|ASM_APP_ON
value|"#APP\n"
end_define

begin_comment
comment|/* Override rs6000.h definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_APP_OFF
end_undef

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|"#NO_APP\n"
end_define

begin_comment
comment|/* For backward compatibility, we must continue to use the AIX    structure return convention.  */
end_comment

begin_undef
undef|#
directive|undef
name|DRAFT_V4_STRUCT_RET
end_undef

begin_define
define|#
directive|define
name|DRAFT_V4_STRUCT_RET
value|1
end_define

begin_comment
comment|/* Do code reading to identify a signal frame, and set the frame    state data appropriately.  See unwind-dw2.c for the structs.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IN_LIBGCC2
end_ifdef

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/ucontext.h>
end_include

begin_enum
enum|enum
block|{
name|SIGNAL_FRAMESIZE
init|=
literal|64
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MD_FALLBACK_FRAME_STATE_FOR
parameter_list|(
name|CONTEXT
parameter_list|,
name|FS
parameter_list|,
name|SUCCESS
parameter_list|)
define|\
value|do {									\     unsigned char *pc_ = (CONTEXT)->ra;					\     struct sigcontext *sc_;						\     long new_cfa_;							\     int i_;								\ 									\
comment|/* li r0, 0x7777; sc  (rt_sigreturn)  */
value|\
comment|/* li r0, 0x6666; sc  (sigreturn)  */
value|\     if (((*(unsigned int *) (pc_+0) == 0x38007777)			\ 	 || (*(unsigned int *) (pc_+0) == 0x38006666))			\&& (*(unsigned int *) (pc_+4)  == 0x44000002))			\ 	sc_ = (CONTEXT)->cfa + SIGNAL_FRAMESIZE;			\     else								\       break;								\     									\     new_cfa_ = sc_->regs->gpr[STACK_POINTER_REGNUM];			\     (FS)->cfa_how = CFA_REG_OFFSET;					\     (FS)->cfa_reg = STACK_POINTER_REGNUM;				\     (FS)->cfa_offset = new_cfa_ - (long) (CONTEXT)->cfa;		\     									\     for (i_ = 0; i_< 32; i_++)						\       if (i_ != STACK_POINTER_REGNUM)					\ 	{	    							\ 	  (FS)->regs.reg[i_].how = REG_SAVED_OFFSET;			\ 	  (FS)->regs.reg[i_].loc.offset 				\ 	    = (long)&(sc_->regs->gpr[i_]) - new_cfa_;			\ 	}								\ 									\     (FS)->regs.reg[LINK_REGISTER_REGNUM].how = REG_SAVED_OFFSET;	\     (FS)->regs.reg[LINK_REGISTER_REGNUM].loc.offset 			\       = (long)&(sc_->regs->link) - new_cfa_;				\ 									\
comment|/* The unwinder expects the IP to point to the following insn,	\        whereas the kernel returns the address of the actual		\        faulting insn.  */
value|\     sc_->regs->nip += 4;  						\     (FS)->regs.reg[CR0_REGNO].how = REG_SAVED_OFFSET;			\     (FS)->regs.reg[CR0_REGNO].loc.offset 				\       = (long)&(sc_->regs->nip) - new_cfa_;				\     (FS)->retaddr_column = CR0_REGNO;					\     goto SUCCESS;							\   } while (0)
end_define

end_unit

