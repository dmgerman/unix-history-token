begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler,    for Alpha Linux-based GNU systems.    Copyright (C) 1996, 1997, 1998 Free Software Foundation, Inc.    Contributed by Richard Henderson.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
value|(MASK_FP | MASK_FPREGS | MASK_GAS)
end_define

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
value|"-Dlinux -Dunix -Asystem=linux -D_LONGLONG -D__alpha__ " \ SUB_CPP_PREDEFINES
end_define

begin_comment
comment|/* The GNU C++ standard library requires that these macros be defined.  */
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
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
define|\
value|"%{shared: -lc} \    %{!shared: %{pthread:-lpthread} \               %{profile:-lc_p} %{!profile: -lc}}"
end_define

begin_comment
comment|/* Show that we need a GP when profiling.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_PROFILING_NEEDS_GP
end_undef

begin_define
define|#
directive|define
name|TARGET_PROFILING_NEEDS_GP
value|1
end_define

begin_comment
comment|/* Don't care about faults in the prologue.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_CAN_FAULT_IN_PROLOGUE
end_undef

begin_define
define|#
directive|define
name|TARGET_CAN_FAULT_IN_PROLOGUE
value|1
end_define

begin_comment
comment|/* OS fixes up EV5 data fault on prefetch.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_FIXUP_EV5_PREFETCH
end_undef

begin_define
define|#
directive|define
name|TARGET_FIXUP_EV5_PREFETCH
value|1
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
value|"int"
end_define

begin_comment
comment|/* Define this so that all GNU/Linux targets handle the same pragmas.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_PRAGMA_PACK_PUSH_POP
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
value|do {									\     unsigned int *pc_ = (CONTEXT)->ra;					\     struct sigcontext *sc_;						\     long new_cfa_, i_;							\ 									\     if (pc_[0] != 0x47fe0410
comment|/* mov $30,$16 */
value|\         || pc_[2] != 0x00000083
comment|/* callsys */
value|)			\       break;								\     if (pc_[1] == 0x201f0067)
comment|/* lda $0,NR_sigreturn */
value|\       sc_ = (CONTEXT)->cfa;						\     else if (pc_[1] == 0x201f015f)
comment|/* lda $0,NR_rt_sigreturn */
value|\       {									\ 	struct rt_sigframe {						\ 	  struct siginfo info;						\ 	  struct ucontext uc;						\ 	} *rt_ = (CONTEXT)->cfa;					\ 	sc_ =&rt_->uc.uc_mcontext;					\       }									\     else								\       break;								\     new_cfa_ = sc_->sc_regs[30];					\     (FS)->cfa_how = CFA_REG_OFFSET;					\     (FS)->cfa_reg = 30;							\     (FS)->cfa_offset = new_cfa_ - (long) (CONTEXT)->cfa;		\     for (i_ = 0; i_< 30; ++i_)						\       {									\ 	(FS)->regs.reg[i_].how = REG_SAVED_OFFSET;			\ 	(FS)->regs.reg[i_].loc.offset					\ 	  = (long)&sc_->sc_regs[i_] - new_cfa_;				\       }									\     for (i_ = 0; i_< 31; ++i_)						\       {									\ 	(FS)->regs.reg[i_+32].how = REG_SAVED_OFFSET;			\ 	(FS)->regs.reg[i_+32].loc.offset				\ 	  = (long)&sc_->sc_fpregs[i_] - new_cfa_;			\       }									\     (FS)->regs.reg[31].how = REG_SAVED_OFFSET;				\     (FS)->regs.reg[31].loc.offset = (long)&sc_->sc_pc - new_cfa_;	\     (FS)->retaddr_column = 31;						\     goto SUCCESS;							\   } while (0)
end_define

end_unit

