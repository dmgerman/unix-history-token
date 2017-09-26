begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DebugCrossExSubsection.h ---------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_DEBUGCROSSIMPSUBSECTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_DEBUGCROSSIMPSUBSECTION_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

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
struct|struct
name|CrossModuleImportItem
block|{
specifier|const
name|CrossModuleImport
modifier|*
name|Header
init|=
name|nullptr
decl_stmt|;
name|FixedStreamArray
operator|<
name|support
operator|::
name|ulittle32_t
operator|>
name|Imports
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
name|CrossModuleImportItem
operator|>
block|{
name|public
operator|:
name|using
name|ContextType
operator|=
name|void
block|;
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
name|CrossModuleImportItem
operator|&
name|Item
operator|)
block|; }
expr_stmt|;
name|namespace
name|codeview
block|{
name|class
name|DebugStringTableSubsection
decl_stmt|;
name|class
name|DebugCrossModuleImportsSubsectionRef
name|final
range|:
name|public
name|DebugSubsectionRef
block|{
name|using
name|ReferenceArray
operator|=
name|VarStreamArray
operator|<
name|CrossModuleImportItem
operator|>
block|;
name|using
name|Iterator
operator|=
name|ReferenceArray
operator|::
name|Iterator
block|;
name|public
operator|:
name|DebugCrossModuleImportsSubsectionRef
argument_list|()
operator|:
name|DebugSubsectionRef
argument_list|(
argument|DebugSubsectionKind::CrossScopeImports
argument_list|)
block|{}
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
name|CrossScopeImports
return|;
block|}
name|Error
name|initialize
argument_list|(
argument|BinaryStreamReader Reader
argument_list|)
block|;
name|Error
name|initialize
argument_list|(
argument|BinaryStreamRef Stream
argument_list|)
block|;
name|Iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|References
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
name|References
operator|.
name|end
argument_list|()
return|;
block|}
name|private
operator|:
name|ReferenceArray
name|References
block|; }
decl_stmt|;
name|class
name|DebugCrossModuleImportsSubsection
name|final
range|:
name|public
name|DebugSubsection
block|{
name|public
operator|:
name|explicit
name|DebugCrossModuleImportsSubsection
argument_list|(
name|DebugStringTableSubsection
operator|&
name|Strings
argument_list|)
operator|:
name|DebugSubsection
argument_list|(
name|DebugSubsectionKind
operator|::
name|CrossScopeImports
argument_list|)
block|,
name|Strings
argument_list|(
argument|Strings
argument_list|)
block|{}
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
name|CrossScopeImports
return|;
block|}
name|void
name|addImport
argument_list|(
argument|StringRef Module
argument_list|,
argument|uint32_t ImportId
argument_list|)
block|;
name|uint32_t
name|calculateSerializedSize
argument_list|()
specifier|const
name|override
block|;
name|Error
name|commit
argument_list|(
argument|BinaryStreamWriter&Writer
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
name|DebugStringTableSubsection
operator|&
name|Strings
block|;
name|StringMap
operator|<
name|std
operator|::
name|vector
operator|<
name|support
operator|::
name|ulittle32_t
operator|>>
name|Mappings
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
comment|// LLVM_DEBUGINFO_CODEVIEW_DEBUGCROSSIMPSUBSECTION_H
end_comment

end_unit

