begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SparcBaseInfo.h - Top level definitions for Sparc ---- --*- C++ -*-===//
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
comment|// This file contains small standalone helper functions and enum definitions
end_comment

begin_comment
comment|// for the Sparc target useful for the compiler back-end and the MC libraries.
end_comment

begin_comment
comment|// As such, it deliberately does not include references to LLVM core code gen
end_comment

begin_comment
comment|// types, passes, etc..
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SPARCBASEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|SPARCBASEINFO_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// SPII - This namespace holds target specific flags for instruction info.
name|namespace
name|SPII
block|{
comment|/// Target Operand Flags. Sparc specific TargetFlags for MachineOperands and
comment|/// SDNodes.
enum|enum
name|TOF
block|{
name|MO_NO_FLAG
block|,
comment|// Extract the low 10 bits of an address.
comment|// Assembler: %lo(addr)
name|MO_LO
block|,
comment|// Extract bits 31-10 of an address. Only for sethi.
comment|// Assembler: %hi(addr) or %lm(addr)
name|MO_HI
block|,
comment|// Extract bits 43-22 of an adress. Only for sethi.
comment|// Assembler: %h44(addr)
name|MO_H44
block|,
comment|// Extract bits 21-12 of an address.
comment|// Assembler: %m44(addr)
name|MO_M44
block|,
comment|// Extract bits 11-0 of an address.
comment|// Assembler: %l44(addr)
name|MO_L44
block|,
comment|// Extract bits 63-42 of an address. Only for sethi.
comment|// Assembler: %hh(addr)
name|MO_HH
block|,
comment|// Extract bits 41-32 of an address.
comment|// Assembler: %hm(addr)
name|MO_HM
block|,
comment|// TargetFlags for Thread Local Storage.
name|MO_TLS_GD_HI22
block|,
name|MO_TLS_GD_LO10
block|,
name|MO_TLS_GD_ADD
block|,
name|MO_TLS_GD_CALL
block|,
name|MO_TLS_LDM_HI22
block|,
name|MO_TLS_LDM_LO10
block|,
name|MO_TLS_LDM_ADD
block|,
name|MO_TLS_LDM_CALL
block|,
name|MO_TLS_LDO_HIX22
block|,
name|MO_TLS_LDO_LOX10
block|,
name|MO_TLS_LDO_ADD
block|,
name|MO_TLS_IE_HI22
block|,
name|MO_TLS_IE_LO10
block|,
name|MO_TLS_IE_LD
block|,
name|MO_TLS_IE_LDX
block|,
name|MO_TLS_IE_ADD
block|,
name|MO_TLS_LE_HIX22
block|,
name|MO_TLS_LE_LOX10
block|}
enum|;
block|}
comment|// end namespace SPII
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

