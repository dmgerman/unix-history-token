begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Linux for S/390.    Copyright (C) 1999, 2000, 2001, 2002 Free Software Foundation, Inc.    Contributed by Hartmut Penner (hpenner@de.ibm.com) and                   Ulrich Weigand (uweigand@de.ibm.com).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_H
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_H
end_define

begin_comment
comment|/* Target specific version string.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEFAULT_TARGET_64BIT
end_ifdef

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (Linux for zSeries)");
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (Linux for S/390)");
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Target specific type definitions.  */
end_comment

begin_comment
comment|/* ??? Do we really want long as size_t on 31-bit?  */
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
value|(TARGET_64BIT ? "long unsigned int" : "long unsigned int")
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
value|(TARGET_64BIT ? "long int" : "int")
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

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|32
end_define

begin_comment
comment|/* Target specific preprocessor settings.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do						\     {						\       builtin_define_std ("linux");		\       builtin_define_std ("unix");		\       builtin_assert ("system=linux");		\       builtin_assert ("system=unix");		\       builtin_define ("__ELF__");		\       builtin_define ("__gnu_linux__");		\       if (flag_pic)				\         {					\           builtin_define ("__PIC__");		\           builtin_define ("__pic__");		\         }					\     }						\   while (0)
end_define

begin_comment
comment|/* Target specific assembler settings.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEFAULT_TARGET_64BIT
end_ifdef

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{m31:-m31 -Aesa}"
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{m64:-m64 -Aesame}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Target specific linker settings.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEFAULT_TARGET_64BIT
end_ifdef

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
value|{ "m64" }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
value|{ "m31" }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LINK_ARCH31_SPEC
define|\
value|"-m elf_s390 \    %{shared:-shared} \    %{!shared: \       %{static:-static} \       %{!static: \ 	%{rdynamic:-export-dynamic} \ 	%{!dynamic-linker:-dynamic-linker /lib/ld.so.1}}}"
end_define

begin_define
define|#
directive|define
name|LINK_ARCH64_SPEC
define|\
value|"-m elf64_s390 \    %{shared:-shared} \    %{!shared: \       %{static:-static} \       %{!static: \ 	%{rdynamic:-export-dynamic} \ 	%{!dynamic-linker:-dynamic-linker /lib/ld64.so.1}}}"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEFAULT_TARGET_64BIT
end_ifdef

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{m31:%(link_arch31)} %{!m31:%(link_arch64)}"
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{m64:%(link_arch64)} %{!m64:%(link_arch31)}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This macro defines names of additional specifications to put in the specs    that can be used in various specifications like CC1_SPEC.  Its definition    is an initializer with a subgrouping for each command option.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_SPECS
define|\
value|{ "link_arch31",	LINK_ARCH31_SPEC },	\   { "link_arch64",	LINK_ARCH64_SPEC },
end_define

begin_comment
unit|\
comment|/* Do code reading to identify a signal frame, and set the frame    state data appropriately.  See unwind-dw2.c for the structs.  */
end_comment

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
value|do {									\     unsigned char *pc_ = (CONTEXT)->ra;					\     long new_cfa_;							\     int i_;								\ 									\     typedef struct 							\       {									\         unsigned long psw_mask;						\         unsigned long psw_addr;						\         unsigned long gprs[16];						\         unsigned int  acrs[16];						\         unsigned int  fpc;						\         unsigned int  __pad;						\         double        fprs[16];						\       } __attribute__ ((__aligned__ (8))) sigregs_;			\ 									\     sigregs_ *regs_;							\ 									\
comment|/* svc $__NR_sigreturn or svc $__NR_rt_sigreturn  */
value|\     if (pc_[0] != 0x0a || (pc_[1] != 119&& pc_[1] != 173))		\       break;								\ 									\
comment|/* New-style RT frame:  						\ 	retcode + alignment (8 bytes)					\ 	siginfo (128 bytes)						\ 	ucontext (contains sigregs)  */
value|\     if ((CONTEXT)->ra == (CONTEXT)->cfa)				\       {									\ 	struct ucontext_						\ 	  {								\ 	    unsigned long     uc_flags;					\ 	    struct ucontext_ *uc_link;					\ 	    unsigned long     uc_stack[3];				\ 	    sigregs_          uc_mcontext;				\ 	  } *uc_ = (CONTEXT)->cfa + 8 + 128;				\ 									\ 	regs_ =&uc_->uc_mcontext;					\       }									\ 									\
comment|/* Old-style RT frame and all non-RT frames:			\ 	old signal mask (8 bytes)					\ 	pointer to sigregs  */
value|\     else								\       {									\ 	regs_ = *(sigregs_ **)((CONTEXT)->cfa + 8);			\       }									\       									\     new_cfa_ = regs_->gprs[15] + 16*sizeof(long) + 32;			\     (FS)->cfa_how = CFA_REG_OFFSET;					\     (FS)->cfa_reg = 15;							\     (FS)->cfa_offset = 							\       new_cfa_ - (long) (CONTEXT)->cfa + 16*sizeof(long) + 32;		\ 									\     for (i_ = 0; i_< 16; i_++)						\       {									\ 	(FS)->regs.reg[i_].how = REG_SAVED_OFFSET;			\ 	(FS)->regs.reg[i_].loc.offset = 				\ 	  (long)&regs_->gprs[i_] - new_cfa_;				\       }									\     for (i_ = 0; i_< 16; i_++)						\       {									\ 	(FS)->regs.reg[16+i_].how = REG_SAVED_OFFSET;			\ 	(FS)->regs.reg[16+i_].loc.offset = 				\ 	  (long)&regs_->fprs[i_] - new_cfa_;				\       }									\ 									\
comment|/* Load return addr from PSW into dummy register 32.  */
value|\     (FS)->regs.reg[32].how = REG_SAVED_OFFSET;				\     (FS)->regs.reg[32].loc.offset = (long)&regs_->psw_addr - new_cfa_;	\     (FS)->retaddr_column = 32;						\ 									\     goto SUCCESS;							\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

