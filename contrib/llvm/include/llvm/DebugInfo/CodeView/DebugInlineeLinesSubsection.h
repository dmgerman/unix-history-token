begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DebugInlineeLinesSubsection.h ----------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_DEBUGINLINEELINESSUBSECTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_DEBUGINLINEELINESSUBSECTION_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

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
file|"llvm/DebugInfo/CodeView/Line.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeIndex.h"
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
file|"llvm/Support/BinaryStreamRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Endian.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
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
name|namespace
name|codeview
block|{
name|class
name|DebugChecksumsSubsection
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
comment|// end namespace codeview
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
name|Error
name|operator
argument_list|()
operator|(
name|BinaryStreamRef
name|Stream
operator|,
name|uint32_t
operator|&
name|Len
operator|,
name|codeview
operator|::
name|InlineeSourceLine
operator|&
name|Item
operator|)
block|;
name|bool
name|HasExtraFiles
operator|=
name|false
block|; }
expr_stmt|;
name|namespace
name|codeview
block|{
name|class
name|DebugInlineeLinesSubsectionRef
name|final
range|:
name|public
name|DebugSubsectionRef
block|{
name|using
name|LinesArray
operator|=
name|VarStreamArray
operator|<
name|InlineeSourceLine
operator|>
block|;
name|using
name|Iterator
operator|=
name|LinesArray
operator|::
name|Iterator
block|;
name|public
operator|:
name|DebugInlineeLinesSubsectionRef
argument_list|()
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const DebugSubsectionRef *S
argument_list|)
block|{
return|return
name|S
operator|->
name|kind
argument_list|()
operator|==
name|DebugSubsectionKind
operator|::
name|InlineeLines
return|;
block|}
name|Error
name|initialize
argument_list|(
argument|BinaryStreamReader Reader
argument_list|)
block|;
name|bool
name|hasExtraFiles
argument_list|()
specifier|const
block|;
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
operator|:
name|InlineeLinesSignature
name|Signature
block|;
name|VarStreamArray
operator|<
name|InlineeSourceLine
operator|>
name|Lines
block|; }
decl_stmt|;
name|class
name|DebugInlineeLinesSubsection
name|final
range|:
name|public
name|DebugSubsection
block|{
name|public
operator|:
expr|struct
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
name|DebugInlineeLinesSubsection
argument_list|(
argument|DebugChecksumsSubsection&Checksums
argument_list|,
argument|bool HasExtraFiles = false
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const DebugSubsection *S
argument_list|)
block|{
return|return
name|S
operator|->
name|kind
argument_list|()
operator|==
name|DebugSubsectionKind
operator|::
name|InlineeLines
return|;
block|}
name|Error
name|commit
argument_list|(
argument|BinaryStreamWriter&Writer
argument_list|)
specifier|const
name|override
block|;
name|uint32_t
name|calculateSerializedSize
argument_list|()
specifier|const
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
name|bool
name|hasExtraFiles
argument_list|()
specifier|const
block|{
return|return
name|HasExtraFiles
return|;
block|}
name|void
name|setHasExtraFiles
argument_list|(
argument|bool Has
argument_list|)
block|{
name|HasExtraFiles
operator|=
name|Has
block|; }
name|std
operator|::
name|vector
operator|<
name|Entry
operator|>
operator|::
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Entries
operator|.
name|begin
argument_list|()
return|;
block|}
name|std
operator|::
name|vector
operator|<
name|Entry
operator|>
operator|::
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Entries
operator|.
name|end
argument_list|()
return|;
block|}
name|private
operator|:
name|DebugChecksumsSubsection
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
comment|// LLVM_DEBUGINFO_CODEVIEW_DEBUGINLINEELINESSUBSECTION_H
end_comment

end_unit

