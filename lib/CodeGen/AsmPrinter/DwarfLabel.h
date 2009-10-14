begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- lib/CodeGen/DwarfLabel.h - Dwarf Label -----------------*- C++ -*-===//
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
comment|// DWARF Labels.
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
name|CODEGEN_ASMPRINTER_DWARFLABEL_H__
end_ifndef

begin_define
define|#
directive|define
name|CODEGEN_ASMPRINTER_DWARFLABEL_H__
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|FoldingSetNodeID
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|/// DWLabel - Labels are used to track locations in the assembler file.
comment|/// Labels appear in the form @verbatim<prefix><Tag><Number> @endverbatim,
comment|/// where the tag is a category of label (Ex. location) and number is a value
comment|/// unique in that category.
name|class
name|DWLabel
block|{
comment|/// Tag - Label category tag. Should always be a statically declared C
comment|/// string.
comment|///
specifier|const
name|char
modifier|*
name|Tag
decl_stmt|;
comment|/// Number - Value to make label unique.
comment|///
name|unsigned
name|Number
decl_stmt|;
name|public
label|:
name|DWLabel
argument_list|(
argument|const char *T
argument_list|,
argument|unsigned N
argument_list|)
block|:
name|Tag
argument_list|(
name|T
argument_list|)
operator|,
name|Number
argument_list|(
argument|N
argument_list|)
block|{}
comment|// Accessors.
specifier|const
name|char
operator|*
name|getTag
argument_list|()
specifier|const
block|{
return|return
name|Tag
return|;
block|}
name|unsigned
name|getNumber
argument_list|()
specifier|const
block|{
return|return
name|Number
return|;
block|}
comment|/// Profile - Used to gather unique data for the folding set.
comment|///
name|void
name|Profile
argument_list|(
name|FoldingSetNodeID
operator|&
name|ID
argument_list|)
decl|const
decl_stmt|;
ifndef|#
directive|ifndef
name|NDEBUG
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|O
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

