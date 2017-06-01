begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CodeViewYAMLDebugSections.h - CodeView YAMLIO debug sections -------===//
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
comment|// This file defines classes for handling the YAML representation of CodeView
end_comment

begin_comment
comment|// Debug Info.
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
name|LLVM_OBJECTYAML_CODEVIEWYAMLDEBUGSECTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OBJECTYAML_CODEVIEWYAMLDEBUGSECTIONS_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/CodeView.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/DebugSubsection.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ObjectYAML/YAML.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|CodeViewYAML
block|{
name|namespace
name|detail
block|{
struct_decl|struct
name|C13FragmentBase
struct_decl|;
block|}
struct|struct
name|SourceLineEntry
block|{
name|uint32_t
name|Offset
decl_stmt|;
name|uint32_t
name|LineStart
decl_stmt|;
name|uint32_t
name|EndDelta
decl_stmt|;
name|bool
name|IsStatement
decl_stmt|;
block|}
struct|;
struct|struct
name|SourceColumnEntry
block|{
name|uint16_t
name|StartColumn
decl_stmt|;
name|uint16_t
name|EndColumn
decl_stmt|;
block|}
struct|;
struct|struct
name|SourceLineBlock
block|{
name|StringRef
name|FileName
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|SourceLineEntry
operator|>
name|Lines
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|SourceColumnEntry
operator|>
name|Columns
expr_stmt|;
block|}
struct|;
struct|struct
name|HexFormattedString
block|{
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>
name|Bytes
expr_stmt|;
block|}
struct|;
struct|struct
name|SourceFileChecksumEntry
block|{
name|StringRef
name|FileName
decl_stmt|;
name|codeview
operator|::
name|FileChecksumKind
name|Kind
expr_stmt|;
name|HexFormattedString
name|ChecksumBytes
decl_stmt|;
block|}
struct|;
struct|struct
name|SourceLineInfo
block|{
name|uint32_t
name|RelocOffset
decl_stmt|;
name|uint32_t
name|RelocSegment
decl_stmt|;
name|codeview
operator|::
name|LineFlags
name|Flags
expr_stmt|;
name|uint32_t
name|CodeSize
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|SourceLineBlock
operator|>
name|Blocks
expr_stmt|;
block|}
struct|;
struct|struct
name|InlineeSite
block|{
name|uint32_t
name|Inlinee
decl_stmt|;
name|StringRef
name|FileName
decl_stmt|;
name|uint32_t
name|SourceLineNum
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
name|ExtraFiles
expr_stmt|;
block|}
struct|;
struct|struct
name|InlineeInfo
block|{
name|bool
name|HasExtraFiles
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|InlineeSite
operator|>
name|Sites
expr_stmt|;
block|}
struct|;
struct|struct
name|SourceFileInfo
block|{
name|std
operator|::
name|vector
operator|<
name|SourceFileChecksumEntry
operator|>
name|FileChecksums
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|SourceLineInfo
operator|>
name|LineFragments
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|InlineeInfo
operator|>
name|Inlinees
expr_stmt|;
block|}
struct|;
struct|struct
name|C13DebugSection
block|{
name|std
operator|::
name|vector
operator|<
name|detail
operator|::
name|C13FragmentBase
operator|>
name|Fragments
expr_stmt|;
block|}
struct|;
block|}
comment|// namespace CodeViewYAML
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_macro
name|LLVM_YAML_DECLARE_MAPPING_TRAITS
argument_list|(
argument|CodeViewYAML::SourceFileInfo
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

