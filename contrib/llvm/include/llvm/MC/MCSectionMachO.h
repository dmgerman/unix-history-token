begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCSectionMachO.h - MachO Machine Code Sections -----------*- C++ -*-===//
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
comment|// This file declares the MCSectionMachO class.
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
name|LLVM_MC_MCSECTIONMACHO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCSECTIONMACHO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSection.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MachO.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// This represents a section on a Mach-O system (used by Mac OS X).  On a Mac
comment|/// system, these are also described in /usr/include/mach-o/loader.h.
name|class
name|MCSectionMachO
name|final
range|:
name|public
name|MCSection
block|{
name|char
name|SegmentName
index|[
literal|16
index|]
block|;
comment|// Not necessarily null terminated!
name|char
name|SectionName
index|[
literal|16
index|]
block|;
comment|// Not necessarily null terminated!
comment|/// This is the SECTION_TYPE and SECTION_ATTRIBUTES field of a section, drawn
comment|/// from the enums below.
name|unsigned
name|TypeAndAttributes
block|;
comment|/// The 'reserved2' field of a section, used to represent the size of stubs,
comment|/// for example.
name|unsigned
name|Reserved2
block|;
name|MCSectionMachO
argument_list|(
argument|StringRef Segment
argument_list|,
argument|StringRef Section
argument_list|,
argument|unsigned TAA
argument_list|,
argument|unsigned reserved2
argument_list|,
argument|SectionKind K
argument_list|,
argument|MCSymbol *Begin
argument_list|)
block|;
name|friend
name|class
name|MCContext
block|;
name|public
operator|:
name|StringRef
name|getSegmentName
argument_list|()
specifier|const
block|{
comment|// SegmentName is not necessarily null terminated!
if|if
condition|(
name|SegmentName
index|[
literal|15
index|]
condition|)
return|return
name|StringRef
argument_list|(
name|SegmentName
argument_list|,
literal|16
argument_list|)
return|;
return|return
name|StringRef
argument_list|(
name|SegmentName
argument_list|)
return|;
block|}
name|StringRef
name|getSectionName
argument_list|()
specifier|const
block|{
comment|// SectionName is not necessarily null terminated!
if|if
condition|(
name|SectionName
index|[
literal|15
index|]
condition|)
return|return
name|StringRef
argument_list|(
name|SectionName
argument_list|,
literal|16
argument_list|)
return|;
return|return
name|StringRef
argument_list|(
name|SectionName
argument_list|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|unsigned
name|getTypeAndAttributes
argument_list|()
specifier|const
block|{
return|return
name|TypeAndAttributes
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|unsigned
name|getStubSize
argument_list|()
specifier|const
block|{
return|return
name|Reserved2
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|MachO
operator|::
name|SectionType
name|getType
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|MachO
operator|::
name|SectionType
operator|>
operator|(
name|TypeAndAttributes
operator|&
name|MachO
operator|::
name|SECTION_TYPE
operator|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|bool
name|hasAttribute
argument_list|(
name|unsigned
name|Value
argument_list|)
decl|const
block|{
return|return
operator|(
name|TypeAndAttributes
operator|&
name|Value
operator|)
operator|!=
literal|0
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Parse the section specifier indicated by "Spec". This is a string that can
end_comment

begin_comment
comment|/// appear after a .section directive in a mach-o flavored .s file.  If
end_comment

begin_comment
comment|/// successful, this fills in the specified Out parameters and returns an
end_comment

begin_comment
comment|/// empty string.  When an invalid section specifier is present, this returns
end_comment

begin_comment
comment|/// a string indicating the problem. If no TAA was parsed, TAA is not altered,
end_comment

begin_comment
comment|/// and TAAWasSet becomes false.
end_comment

begin_expr_stmt
specifier|static
name|std
operator|::
name|string
name|ParseSectionSpecifier
argument_list|(
argument|StringRef Spec
argument_list|,
comment|// In.
argument|StringRef&Segment
argument_list|,
comment|// Out.
argument|StringRef&Section
argument_list|,
comment|// Out.
argument|unsigned&TAA
argument_list|,
comment|// Out.
argument|bool&TAAParsed
argument_list|,
comment|// Out.
argument|unsigned&StubSize
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Out.
end_comment

begin_decl_stmt
name|void
name|PrintSwitchToSection
argument_list|(
specifier|const
name|MCAsmInfo
operator|&
name|MAI
argument_list|,
specifier|const
name|Triple
operator|&
name|T
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|MCExpr
operator|*
name|Subsection
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|bool
name|UseCodeAlign
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|isVirtualSection
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|MCSection
modifier|*
name|S
parameter_list|)
block|{
return|return
name|S
operator|->
name|getVariant
argument_list|()
operator|==
name|SV_MachO
return|;
block|}
end_function

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

