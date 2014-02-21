begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCWinCOFFObjectWriter.h - Win COFF Object Writer *- C++ -*-===//
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
name|LLVM_MC_MCWINCOFFOBJECTWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCWINCOFFOBJECTWRITER_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCFixup
decl_stmt|;
name|class
name|MCObjectWriter
decl_stmt|;
name|class
name|MCValue
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|MCWinCOFFObjectTargetWriter
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
specifier|const
name|unsigned
name|Machine
decl_stmt|;
name|protected
label|:
name|MCWinCOFFObjectTargetWriter
argument_list|(
argument|unsigned Machine_
argument_list|)
empty_stmt|;
name|public
label|:
name|virtual
operator|~
name|MCWinCOFFObjectTargetWriter
argument_list|()
block|{}
name|unsigned
name|getMachine
argument_list|()
specifier|const
block|{
return|return
name|Machine
return|;
block|}
name|virtual
name|unsigned
name|getRelocType
argument_list|(
specifier|const
name|MCValue
operator|&
name|Target
argument_list|,
specifier|const
name|MCFixup
operator|&
name|Fixup
argument_list|,
name|bool
name|IsCrossSection
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief Construct a new Win COFF writer instance.
comment|///
comment|/// \param MOTW - The target specific WinCOFF writer subclass.
comment|/// \param OS - The stream to write to.
comment|/// \returns The constructed object writer.
name|MCObjectWriter
modifier|*
name|createWinCOFFObjectWriter
parameter_list|(
name|MCWinCOFFObjectTargetWriter
modifier|*
name|MOTW
parameter_list|,
name|raw_ostream
modifier|&
name|OS
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

