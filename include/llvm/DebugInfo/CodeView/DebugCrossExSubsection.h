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
name|LLVM_DEBUGINFO_CODEVIEW_DEBUGCROSSEXSUBSECTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_DEBUGCROSSEXSUBSECTION_H
end_define

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
file|"llvm/Support/Endian.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|class
name|DebugCrossModuleExportsSubsectionRef
name|final
range|:
name|public
name|DebugSubsectionRef
block|{
typedef|typedef
name|FixedStreamArray
operator|<
name|CrossModuleExport
operator|>
name|ReferenceArray
expr_stmt|;
typedef|typedef
name|ReferenceArray
operator|::
name|Iterator
name|Iterator
expr_stmt|;
name|public
label|:
name|DebugCrossModuleExportsSubsectionRef
argument_list|()
operator|:
name|DebugSubsectionRef
argument_list|(
argument|DebugSubsectionKind::CrossScopeExports
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
name|CrossScopeExports
return|;
block|}
name|Error
name|initialize
parameter_list|(
name|BinaryStreamReader
name|Reader
parameter_list|)
function_decl|;
name|Error
name|initialize
parameter_list|(
name|BinaryStreamRef
name|Stream
parameter_list|)
function_decl|;
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
label|:
name|FixedStreamArray
operator|<
name|CrossModuleExport
operator|>
name|References
expr_stmt|;
block|}
empty_stmt|;
name|class
name|DebugCrossModuleExportsSubsection
name|final
range|:
name|public
name|DebugSubsection
block|{
name|public
operator|:
name|DebugCrossModuleExportsSubsection
argument_list|()
operator|:
name|DebugSubsection
argument_list|(
argument|DebugSubsectionKind::CrossScopeExports
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
name|CrossScopeExports
return|;
block|}
name|void
name|addMapping
argument_list|(
argument|uint32_t Local
argument_list|,
argument|uint32_t Global
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
name|std
operator|::
name|map
operator|<
name|uint32_t
block|,
name|uint32_t
operator|>
name|Mappings
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

