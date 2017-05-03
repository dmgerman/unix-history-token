begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ModuleDebugInlineeLinesFragment.h ------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_MODULEDEBUGINLINEELINESFRAGMENT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_MODULEDEBUGINLINEELINESFRAGMENT_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/Line.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/ModuleDebugFragment.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamArray.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamReader.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|class
name|ModuleDebugInlineeLineFragmentRef
decl_stmt|;
name|class
name|ModuleDebugFileChecksumFragment
decl_stmt|;
name|class
name|StringTable
decl_stmt|;
name|enum
name|class
name|InlineeLinesSignature
range|:
name|uint32_t
block|{
name|Normal
block|,
comment|// CV_INLINEE_SOURCE_LINE_SIGNATURE
name|ExtraFiles
comment|// CV_INLINEE_SOURCE_LINE_SIGNATURE_EX
block|}
decl_stmt|;
struct|struct
name|InlineeSourceLineHeader
block|{
name|TypeIndex
name|Inlinee
decl_stmt|;
comment|// ID of the function that was inlined.
name|support
operator|::
name|ulittle32_t
name|FileID
expr_stmt|;
comment|// Offset into FileChecksums subsection.
name|support
operator|::
name|ulittle32_t
name|SourceLineNum
expr_stmt|;
comment|// First line of inlined code.
comment|// If extra files present:
comment|//   ulittle32_t ExtraFileCount;
comment|//   ulittle32_t Files[];
block|}
struct|;
struct|struct
name|InlineeSourceLine
block|{
specifier|const
name|InlineeSourceLineHeader
modifier|*
name|Header
decl_stmt|;
name|FixedStreamArray
operator|<
name|support
operator|::
name|ulittle32_t
operator|>
name|ExtraFiles
expr_stmt|;
block|}
struct|;
block|}
name|template
operator|<
operator|>
expr|struct
name|VarStreamArrayExtractor
operator|<
name|codeview
operator|::
name|InlineeSourceLine
operator|>
block|{
typedef|typedef
name|bool
name|ContextType
typedef|;
specifier|static
name|Error
name|extract
argument_list|(
argument|BinaryStreamRef Stream
argument_list|,
argument|uint32_t&Len
argument_list|,
argument|codeview::InlineeSourceLine&Item
argument_list|,
argument|bool HasExtraFiles
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|namespace
name|codeview
block|{
name|class
name|ModuleDebugInlineeLineFragmentRef
name|final
range|:
name|public
name|ModuleDebugFragmentRef
block|{
typedef|typedef
name|VarStreamArray
operator|<
name|InlineeSourceLine
operator|>
name|LinesArray
expr_stmt|;
typedef|typedef
name|LinesArray
operator|::
name|Iterator
name|Iterator
expr_stmt|;
name|public
label|:
name|ModuleDebugInlineeLineFragmentRef
argument_list|()
expr_stmt|;
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|ModuleDebugFragmentRef
modifier|*
name|S
parameter_list|)
block|{
return|return
name|S
operator|->
name|kind
argument_list|()
operator|==
name|ModuleDebugFragmentKind
operator|::
name|InlineeLines
return|;
block|}
name|Error
name|initialize
parameter_list|(
name|BinaryStreamReader
name|Reader
parameter_list|)
function_decl|;
name|bool
name|hasExtraFiles
argument_list|()
specifier|const
expr_stmt|;
name|Iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Lines
operator|.
name|begin
argument_list|()
return|;
block|}
name|Iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Lines
operator|.
name|end
argument_list|()
return|;
block|}
name|private
label|:
name|InlineeLinesSignature
name|Signature
decl_stmt|;
name|VarStreamArray
operator|<
name|InlineeSourceLine
operator|>
name|Lines
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|ModuleDebugInlineeLineFragment
name|final
range|:
name|public
name|ModuleDebugFragment
block|{
name|public
operator|:
name|ModuleDebugInlineeLineFragment
argument_list|(
argument|ModuleDebugFileChecksumFragment&Checksums
argument_list|,
argument|bool HasExtraFiles
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const ModuleDebugFragment *S
argument_list|)
block|{
return|return
name|S
operator|->
name|kind
argument_list|()
operator|==
name|ModuleDebugFragmentKind
operator|::
name|InlineeLines
return|;
block|}
name|Error
name|commit
argument_list|(
argument|BinaryStreamWriter&Writer
argument_list|)
name|override
block|;
name|uint32_t
name|calculateSerializedLength
argument_list|()
name|override
block|;
name|void
name|addInlineSite
argument_list|(
argument|TypeIndex FuncId
argument_list|,
argument|StringRef FileName
argument_list|,
argument|uint32_t SourceLine
argument_list|)
block|;
name|void
name|addExtraFile
argument_list|(
argument|StringRef FileName
argument_list|)
block|;
name|private
operator|:
name|ModuleDebugFileChecksumFragment
operator|&
name|Checksums
block|;
name|bool
name|HasExtraFiles
operator|=
name|false
block|;
name|uint32_t
name|ExtraFileCount
operator|=
literal|0
block|;    struct
name|Entry
block|{
name|std
operator|::
name|vector
operator|<
name|support
operator|::
name|ulittle32_t
operator|>
name|ExtraFiles
block|;
name|InlineeSourceLineHeader
name|Header
block|;   }
block|;
name|std
operator|::
name|vector
operator|<
name|Entry
operator|>
name|Entries
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
unit|} }
endif|#
directive|endif
end_endif

end_unit

