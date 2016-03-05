begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- GVMaterializer.h - Interface for GV materializers --------*- C++ -*-===//
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
comment|// This file provides an abstract interface for loading a module from some
end_comment

begin_comment
comment|// place.  This interface allows incremental or random access loading of
end_comment

begin_comment
comment|// functions from the file.  This is useful for applications like JIT compilers
end_comment

begin_comment
comment|// or interprocedural optimizers that do not need the entire program in memory
end_comment

begin_comment
comment|// at the same time.
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
name|LLVM_IR_GVMATERIALIZER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_GVMATERIALIZER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|<system_error>
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
name|class
name|Function
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|Metadata
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|StructType
decl_stmt|;
name|class
name|GVMaterializer
block|{
name|protected
label|:
name|GVMaterializer
argument_list|()
block|{}
name|public
label|:
name|virtual
operator|~
name|GVMaterializer
argument_list|()
expr_stmt|;
comment|/// Make sure the given GlobalValue is fully read.
comment|///
name|virtual
name|std
operator|::
name|error_code
name|materialize
argument_list|(
name|GlobalValue
operator|*
name|GV
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// Make sure the entire Module has been completely read.
comment|///
name|virtual
name|std
operator|::
name|error_code
name|materializeModule
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
name|std
operator|::
name|error_code
name|materializeMetadata
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|setStripDebugInfo
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// Client should define this interface if the mapping between metadata
comment|/// values and value ids needs to be preserved, e.g. across materializer
comment|/// instantiations. If OnlyTempMD is true, only those that have remained
comment|/// temporary metadata are recorded in the map.
name|virtual
name|void
name|saveMetadataList
argument_list|(
name|DenseMap
operator|<
specifier|const
name|Metadata
operator|*
argument_list|,
name|unsigned
operator|>
operator|&
name|MetadataToIDs
argument_list|,
name|bool
name|OnlyTempMD
argument_list|)
block|{}
name|virtual
name|std
operator|::
name|vector
operator|<
name|StructType
operator|*
operator|>
name|getIdentifiedStructTypes
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

