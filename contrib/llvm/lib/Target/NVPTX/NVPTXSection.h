begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- NVPTXSection.h - NVPTX-specific section representation -*- C++ -*-===//
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
comment|// This file declares the NVPTXSection class.
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
name|LLVM_NVPTXSECTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_NVPTXSECTION_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/GlobalVariable.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSection.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// NVPTXSection - Represents a section in PTX
comment|/// PTX does not have sections. We create this class in order to use
comment|/// the ASMPrint interface.
comment|///
name|class
name|NVPTXSection
range|:
name|public
name|MCSection
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|NVPTXSection
argument_list|(
argument|SectionVariant V
argument_list|,
argument|SectionKind K
argument_list|)
operator|:
name|MCSection
argument_list|(
argument|V
argument_list|,
argument|K
argument_list|)
block|{}
name|virtual
operator|~
name|NVPTXSection
argument_list|()
block|{}
comment|/// Override this as NVPTX has its own way of printing switching
comment|/// to a section.
name|virtual
name|void
name|PrintSwitchToSection
argument_list|(
argument|const MCAsmInfo&MAI
argument_list|,
argument|raw_ostream&OS
argument_list|,
argument|const MCExpr *Subsection
argument_list|)
specifier|const
block|{}
comment|/// Base address of PTX sections is zero.
name|virtual
name|bool
name|isBaseAddressKnownZero
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
name|bool
name|UseCodeAlign
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|isVirtualSection
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|std
operator|::
name|string
name|getLabelBeginName
argument_list|()
specifier|const
block|{
return|return
literal|""
return|;
block|}
name|virtual
name|std
operator|::
name|string
name|getLabelEndName
argument_list|()
specifier|const
block|{
return|return
literal|""
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

