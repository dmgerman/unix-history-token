begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Bitcode/Reader/MetadataLoader.h - Load Metadatas -------*- C++ -*-====//
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
comment|// This class handles loading Metadatas.
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
name|LLVM_LIB_BITCODE_READER_METADATALOADER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_BITCODE_READER_METADATALOADER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BitcodeReaderValueList
decl_stmt|;
name|class
name|BitstreamCursor
decl_stmt|;
name|class
name|DISubprogram
decl_stmt|;
name|class
name|Error
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|Metadata
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|Type
decl_stmt|;
comment|/// Helper class that handles loading Metadatas and keeping them available.
name|class
name|MetadataLoader
block|{
name|class
name|MetadataLoaderImpl
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|MetadataLoaderImpl
operator|>
name|Pimpl
expr_stmt|;
name|Error
name|parseMetadata
parameter_list|(
name|bool
name|ModuleLevel
parameter_list|)
function_decl|;
name|public
label|:
operator|~
name|MetadataLoader
argument_list|()
expr_stmt|;
name|MetadataLoader
argument_list|(
argument|BitstreamCursor&Stream
argument_list|,
argument|Module&TheModule
argument_list|,
argument|BitcodeReaderValueList&ValueList
argument_list|,
argument|bool IsImporting
argument_list|,
argument|std::function<Type *(unsigned)> getTypeByID
argument_list|)
empty_stmt|;
name|MetadataLoader
modifier|&
name|operator
init|=
operator|(
name|MetadataLoader
operator|&&
operator|)
decl_stmt|;
name|MetadataLoader
argument_list|(
name|MetadataLoader
operator|&&
argument_list|)
expr_stmt|;
comment|// Parse a module metadata block
name|Error
name|parseModuleMetadata
parameter_list|()
block|{
return|return
name|parseMetadata
argument_list|(
name|true
argument_list|)
return|;
block|}
comment|// Parse a function metadata block
name|Error
name|parseFunctionMetadata
parameter_list|()
block|{
return|return
name|parseMetadata
argument_list|(
name|false
argument_list|)
return|;
block|}
comment|/// Set the mode to strip TBAA metadata on load.
name|void
name|setStripTBAA
parameter_list|(
name|bool
name|StripTBAA
init|=
name|true
parameter_list|)
function_decl|;
comment|/// Return true if the Loader is stripping TBAA metadata.
name|bool
name|isStrippingTBAA
parameter_list|()
function_decl|;
comment|// Return true there are remaining unresolved forward references.
name|bool
name|hasFwdRefs
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return the given metadata, creating a replaceable forward reference if
comment|/// necessary.
name|Metadata
modifier|*
name|getMetadataFwdRefOrLoad
parameter_list|(
name|unsigned
name|Idx
parameter_list|)
function_decl|;
name|MDNode
modifier|*
name|getMDNodeFwdRefOrNull
parameter_list|(
name|unsigned
name|Idx
parameter_list|)
function_decl|;
comment|/// Return the DISubprogra metadata for a Function if any, null otherwise.
name|DISubprogram
modifier|*
name|lookupSubprogramForFunction
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
comment|/// Parse a `METADATA_ATTACHMENT` block for a function.
name|Error
name|parseMetadataAttachment
argument_list|(
name|Function
operator|&
name|F
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|Instruction
operator|*
operator|>
operator|&
name|InstructionList
argument_list|)
decl_stmt|;
comment|/// Parse a `METADATA_KIND` block for the current module.
name|Error
name|parseMetadataKinds
parameter_list|()
function_decl|;
name|unsigned
name|size
argument_list|()
specifier|const
expr_stmt|;
name|void
name|shrinkTo
parameter_list|(
name|unsigned
name|N
parameter_list|)
function_decl|;
comment|/// Perform bitcode upgrades on llvm.dbg.* calls.
name|void
name|upgradeDebugIntrinsics
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_BITCODE_READER_METADATALOADER_H
end_comment

end_unit

