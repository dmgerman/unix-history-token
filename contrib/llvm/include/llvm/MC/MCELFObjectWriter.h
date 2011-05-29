begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCELFObjectWriter.h - ELF Object Writer ---------*- C++ -*-===//
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
name|LLVM_MC_MCELFOBJECTWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCELFOBJECTWRITER_H
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
name|MCELFObjectTargetWriter
block|{
specifier|const
name|Triple
operator|::
name|OSType
name|OSType
expr_stmt|;
specifier|const
name|uint16_t
name|EMachine
decl_stmt|;
specifier|const
name|unsigned
name|HasRelocationAddend
range|:
literal|1
decl_stmt|;
specifier|const
name|unsigned
name|Is64Bit
range|:
literal|1
decl_stmt|;
name|protected
label|:
name|MCELFObjectTargetWriter
argument_list|(
argument|bool Is64Bit_
argument_list|,
argument|Triple::OSType OSType_
argument_list|,
argument|uint16_t EMachine_
argument_list|,
argument|bool HasRelocationAddend_
argument_list|)
empty_stmt|;
name|public
label|:
name|virtual
operator|~
name|MCELFObjectTargetWriter
argument_list|()
expr_stmt|;
comment|/// @name Accessors
comment|/// @{
name|Triple
operator|::
name|OSType
name|getOSType
argument_list|()
block|{
return|return
name|OSType
return|;
block|}
name|uint16_t
name|getEMachine
parameter_list|()
block|{
return|return
name|EMachine
return|;
block|}
name|bool
name|hasRelocationAddend
parameter_list|()
block|{
return|return
name|HasRelocationAddend
return|;
block|}
name|bool
name|is64Bit
parameter_list|()
block|{
return|return
name|Is64Bit
return|;
block|}
comment|/// @}
block|}
empty_stmt|;
comment|/// \brief Construct a new ELF writer instance.
comment|///
comment|/// \param MOTW - The target specific ELF writer subclass.
comment|/// \param OS - The stream to write to.
comment|/// \returns The constructed object writer.
name|MCObjectWriter
modifier|*
name|createELFObjectWriter
parameter_list|(
name|MCELFObjectTargetWriter
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

