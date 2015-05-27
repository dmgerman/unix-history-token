begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_asm.h -----------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Various support for assemebler.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Some toolchains do not support .cfi asm directives, so we have to hide
end_comment

begin_comment
comment|// them inside macros.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__clang__
argument_list|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GCC_HAVE_DWARF2_CFI_ASM
argument_list|)
operator|)
end_if

begin_comment
comment|// GCC defined __GCC_HAVE_DWARF2_CFI_ASM if it supports CFI.
end_comment

begin_comment
comment|// Clang seems to support CFI by default (or not?).
end_comment

begin_comment
comment|// We need two versions of macros: for inline asm and standalone asm files.
end_comment

begin_define
define|#
directive|define
name|CFI_INL_ADJUST_CFA_OFFSET
parameter_list|(
name|n
parameter_list|)
value|".cfi_adjust_cfa_offset " #n ";"
end_define

begin_define
define|#
directive|define
name|CFI_STARTPROC
value|.cfi_startproc
end_define

begin_define
define|#
directive|define
name|CFI_ENDPROC
value|.cfi_endproc
end_define

begin_define
define|#
directive|define
name|CFI_ADJUST_CFA_OFFSET
parameter_list|(
name|n
parameter_list|)
value|.cfi_adjust_cfa_offset n
end_define

begin_define
define|#
directive|define
name|CFI_REL_OFFSET
parameter_list|(
name|reg
parameter_list|,
name|n
parameter_list|)
value|.cfi_rel_offset reg, n
end_define

begin_define
define|#
directive|define
name|CFI_DEF_CFA_REGISTER
parameter_list|(
name|reg
parameter_list|)
value|.cfi_def_cfa_register reg
end_define

begin_define
define|#
directive|define
name|CFI_RESTORE
parameter_list|(
name|reg
parameter_list|)
value|.cfi_restore reg
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// No CFI
end_comment

begin_define
define|#
directive|define
name|CFI_INL_ADJUST_CFA_OFFSET
parameter_list|(
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|CFI_STARTPROC
end_define

begin_define
define|#
directive|define
name|CFI_ENDPROC
end_define

begin_define
define|#
directive|define
name|CFI_ADJUST_CFA_OFFSET
parameter_list|(
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|CFI_REL_OFFSET
parameter_list|(
name|reg
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|CFI_DEF_CFA_REGISTER
parameter_list|(
name|reg
parameter_list|)
end_define

begin_define
define|#
directive|define
name|CFI_RESTORE
parameter_list|(
name|reg
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

