begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCSection.h - Machine Code Sections ----------------------*- C++ -*-===//
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
comment|// This file declares the MCSection class.
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
name|LLVM_MC_MCSECTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCSECTION_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/SectionKind.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCContext
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// MCSection - Instances of this class represent a uniqued identifier for a
comment|/// section in the current translation unit.  The MCContext class uniques and
comment|/// creates these.
name|class
name|MCSection
block|{
name|MCSection
argument_list|(
specifier|const
name|MCSection
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|MCSection
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|protected
label|:
name|MCSection
argument_list|(
argument|SectionKind K
argument_list|)
block|:
name|Kind
argument_list|(
argument|K
argument_list|)
block|{}
name|SectionKind
name|Kind
decl_stmt|;
name|public
label|:
name|virtual
operator|~
name|MCSection
argument_list|()
expr_stmt|;
name|SectionKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
name|virtual
name|void
name|PrintSwitchToSection
argument_list|(
specifier|const
name|MCAsmInfo
operator|&
name|MAI
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
name|class
name|MCSectionCOFF
range|:
name|public
name|MCSection
block|{
name|std
operator|::
name|string
name|Name
block|;
comment|/// IsDirective - This is true if the section name is a directive, not
comment|/// something that should be printed with ".section".
comment|///
comment|/// FIXME: This is a hack.  Switch to a semantic view of the section instead
comment|/// of a syntactic one.
name|bool
name|IsDirective
block|;
name|MCSectionCOFF
argument_list|(
argument|StringRef name
argument_list|,
argument|bool isDirective
argument_list|,
argument|SectionKind K
argument_list|)
operator|:
name|MCSection
argument_list|(
name|K
argument_list|)
block|,
name|Name
argument_list|(
name|name
argument_list|)
block|,
name|IsDirective
argument_list|(
argument|isDirective
argument_list|)
block|{     }
name|public
operator|:
specifier|static
name|MCSectionCOFF
operator|*
name|Create
argument_list|(
argument|StringRef Name
argument_list|,
argument|bool IsDirective
argument_list|,
argument|SectionKind K
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
name|bool
name|isDirective
argument_list|()
specifier|const
block|{
return|return
name|IsDirective
return|;
block|}
name|virtual
name|void
name|PrintSwitchToSection
argument_list|(
argument|const MCAsmInfo&MAI
argument_list|,
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;   }
decl_stmt|;
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

