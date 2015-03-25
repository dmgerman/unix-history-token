begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsMCNaCl.h - NaCl-related declarations --------------------------===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_MIPS_MCTARGETDESC_MIPSMCNACL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_MIPS_MCTARGETDESC_MIPSMCNACL_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCELFStreamer.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Log2 of the NaCl MIPS sandbox's instruction bundle size.
specifier|static
specifier|const
name|unsigned
name|MIPS_NACL_BUNDLE_ALIGN
init|=
literal|4u
decl_stmt|;
name|bool
name|isBasePlusOffsetMemoryAccess
parameter_list|(
name|unsigned
name|Opcode
parameter_list|,
name|unsigned
modifier|*
name|AddrIdx
parameter_list|,
name|bool
modifier|*
name|IsStore
init|=
name|nullptr
parameter_list|)
function_decl|;
name|bool
name|baseRegNeedsLoadStoreMask
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
function_decl|;
comment|// This function creates an MCELFStreamer for Mips NaCl.
name|MCELFStreamer
modifier|*
name|createMipsNaClELFStreamer
parameter_list|(
name|MCContext
modifier|&
name|Context
parameter_list|,
name|MCAsmBackend
modifier|&
name|TAB
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|MCCodeEmitter
modifier|*
name|Emitter
parameter_list|,
specifier|const
name|MCSubtargetInfo
modifier|&
name|STI
parameter_list|,
name|bool
name|RelaxAll
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

