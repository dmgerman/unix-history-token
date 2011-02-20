begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCMachObjectWriter.h - Mach Object Writer -------*- C++ -*-===//
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
name|LLVM_MC_MCMACHOBJECTWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCMACHOBJECTWRITER_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCObjectWriter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCMachObjectTargetWriter
block|{
specifier|const
name|unsigned
name|Is64Bit
range|:
literal|1
decl_stmt|;
specifier|const
name|uint32_t
name|CPUType
decl_stmt|;
specifier|const
name|uint32_t
name|CPUSubtype
decl_stmt|;
comment|// FIXME: Remove this, we should just always use it once we no longer care
comment|// about Darwin 'as' compatibility.
specifier|const
name|unsigned
name|UseAggressiveSymbolFolding
range|:
literal|1
decl_stmt|;
name|unsigned
name|LocalDifference_RIT
decl_stmt|;
name|protected
label|:
name|MCMachObjectTargetWriter
argument_list|(
argument|bool Is64Bit_
argument_list|,
argument|uint32_t CPUType_
argument_list|,
argument|uint32_t CPUSubtype_
argument_list|,
argument|bool UseAggressiveSymbolFolding_ = false
argument_list|)
empty_stmt|;
name|void
name|setLocalDifferenceRelocationType
parameter_list|(
name|unsigned
name|Type
parameter_list|)
block|{
name|LocalDifference_RIT
operator|=
name|Type
expr_stmt|;
block|}
name|public
label|:
name|virtual
operator|~
name|MCMachObjectTargetWriter
argument_list|()
expr_stmt|;
comment|/// @name Accessors
comment|/// @{
name|bool
name|is64Bit
argument_list|()
specifier|const
block|{
return|return
name|Is64Bit
return|;
block|}
name|bool
name|useAggressiveSymbolFolding
argument_list|()
specifier|const
block|{
return|return
name|UseAggressiveSymbolFolding
return|;
block|}
name|uint32_t
name|getCPUType
argument_list|()
specifier|const
block|{
return|return
name|CPUType
return|;
block|}
name|uint32_t
name|getCPUSubtype
argument_list|()
specifier|const
block|{
return|return
name|CPUSubtype
return|;
block|}
name|unsigned
name|getLocalDifferenceRelocationType
argument_list|()
specifier|const
block|{
return|return
name|LocalDifference_RIT
return|;
block|}
comment|/// @}
block|}
empty_stmt|;
comment|/// \brief Construct a new Mach-O writer instance.
comment|///
comment|/// This routine takes ownership of the target writer subclass.
comment|///
comment|/// \param MOTW - The target specific Mach-O writer subclass.
comment|/// \param OS - The stream to write to.
comment|/// \returns The constructed object writer.
name|MCObjectWriter
modifier|*
name|createMachObjectWriter
parameter_list|(
name|MCMachObjectTargetWriter
modifier|*
name|MOTW
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|bool
name|IsLittleEndian
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

