begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- EnumTables.h - Enum to string conversion tables ----------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_ENUMTABLES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_ENUMTABLES_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/BinaryFormat/COFF.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/CodeView.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ScopedPrinter.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|ArrayRef
operator|<
name|EnumEntry
operator|<
name|SymbolKind
operator|>>
name|getSymbolTypeNames
argument_list|()
expr_stmt|;
name|ArrayRef
operator|<
name|EnumEntry
operator|<
name|TypeLeafKind
operator|>>
name|getTypeLeafNames
argument_list|()
expr_stmt|;
name|ArrayRef
operator|<
name|EnumEntry
operator|<
name|uint16_t
operator|>>
name|getRegisterNames
argument_list|()
expr_stmt|;
name|ArrayRef
operator|<
name|EnumEntry
operator|<
name|uint32_t
operator|>>
name|getPublicSymFlagNames
argument_list|()
expr_stmt|;
name|ArrayRef
operator|<
name|EnumEntry
operator|<
name|uint8_t
operator|>>
name|getProcSymFlagNames
argument_list|()
expr_stmt|;
name|ArrayRef
operator|<
name|EnumEntry
operator|<
name|uint16_t
operator|>>
name|getLocalFlagNames
argument_list|()
expr_stmt|;
name|ArrayRef
operator|<
name|EnumEntry
operator|<
name|uint8_t
operator|>>
name|getFrameCookieKindNames
argument_list|()
expr_stmt|;
name|ArrayRef
operator|<
name|EnumEntry
operator|<
name|SourceLanguage
operator|>>
name|getSourceLanguageNames
argument_list|()
expr_stmt|;
name|ArrayRef
operator|<
name|EnumEntry
operator|<
name|uint32_t
operator|>>
name|getCompileSym2FlagNames
argument_list|()
expr_stmt|;
name|ArrayRef
operator|<
name|EnumEntry
operator|<
name|uint32_t
operator|>>
name|getCompileSym3FlagNames
argument_list|()
expr_stmt|;
name|ArrayRef
operator|<
name|EnumEntry
operator|<
name|uint32_t
operator|>>
name|getFileChecksumNames
argument_list|()
expr_stmt|;
name|ArrayRef
operator|<
name|EnumEntry
operator|<
name|unsigned
operator|>>
name|getCPUTypeNames
argument_list|()
expr_stmt|;
name|ArrayRef
operator|<
name|EnumEntry
operator|<
name|uint32_t
operator|>>
name|getFrameProcSymFlagNames
argument_list|()
expr_stmt|;
name|ArrayRef
operator|<
name|EnumEntry
operator|<
name|uint16_t
operator|>>
name|getExportSymFlagNames
argument_list|()
expr_stmt|;
name|ArrayRef
operator|<
name|EnumEntry
operator|<
name|uint32_t
operator|>>
name|getModuleSubstreamKindNames
argument_list|()
expr_stmt|;
name|ArrayRef
operator|<
name|EnumEntry
operator|<
name|uint8_t
operator|>>
name|getThunkOrdinalNames
argument_list|()
expr_stmt|;
name|ArrayRef
operator|<
name|EnumEntry
operator|<
name|uint16_t
operator|>>
name|getTrampolineNames
argument_list|()
expr_stmt|;
name|ArrayRef
operator|<
name|EnumEntry
operator|<
name|COFF
operator|::
name|SectionCharacteristics
operator|>>
name|getImageSectionCharacteristicNames
argument_list|()
expr_stmt|;
block|}
comment|// end namespace codeview
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_CODEVIEW_ENUMTABLES_H
end_comment

end_unit

