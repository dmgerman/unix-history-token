begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Linker.h - Module Linker Interface -----------------------*- C++ -*-===//
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
name|LLVM_LINKER_LINKER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LINKER_LINKER_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/FunctionInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Linker/IRMover.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
name|class
name|StructType
decl_stmt|;
name|class
name|Type
decl_stmt|;
comment|/// This class provides the core functionality of linking in LLVM. It keeps a
comment|/// pointer to the merged module so far. It doesn't take ownership of the
comment|/// module since it is assumed that the user of this class will want to do
comment|/// something with it after the linking.
name|class
name|Linker
block|{
name|IRMover
name|Mover
decl_stmt|;
name|public
label|:
enum|enum
name|Flags
block|{
name|None
init|=
literal|0
block|,
name|OverrideFromSrc
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|LinkOnlyNeeded
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|InternalizeLinkedSymbols
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|}
enum|;
name|Linker
argument_list|(
name|Module
operator|&
name|M
argument_list|)
expr_stmt|;
comment|/// \brief Link \p Src into the composite.
comment|///
comment|/// Passing OverrideSymbols as true will have symbols from Src
comment|/// shadow those in the Dest.
comment|/// For ThinLTO function importing/exporting the \p FunctionInfoIndex
comment|/// is passed. If \p FunctionsToImport is provided, only the functions that
comment|/// are part of the set will be imported from the source module.
comment|/// The \p ValIDToTempMDMap is populated by the linker when function
comment|/// importing is performed.
comment|///
comment|/// Returns true on error.
name|bool
name|linkInModule
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|Src
argument_list|,
name|unsigned
name|Flags
operator|=
name|Flags
operator|::
name|None
argument_list|,
specifier|const
name|FunctionInfoIndex
operator|*
name|Index
operator|=
name|nullptr
argument_list|,
name|DenseSet
operator|<
specifier|const
name|GlobalValue
operator|*
operator|>
operator|*
name|FunctionsToImport
operator|=
name|nullptr
argument_list|,
name|DenseMap
operator|<
name|unsigned
argument_list|,
name|MDNode
operator|*
operator|>
operator|*
name|ValIDToTempMDMap
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|/// This exists to implement the deprecated LLVMLinkModules C api. Don't use
comment|/// for anything else.
name|bool
name|linkInModuleForCAPI
parameter_list|(
name|Module
modifier|&
name|Src
parameter_list|)
function_decl|;
specifier|static
name|bool
name|linkModules
argument_list|(
name|Module
operator|&
name|Dest
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|Src
argument_list|,
name|unsigned
name|Flags
operator|=
name|Flags
operator|::
name|None
argument_list|)
decl_stmt|;
comment|/// \brief Link metadata from \p Src into the composite. The source is
comment|/// destroyed.
comment|///
comment|/// The \p ValIDToTempMDMap sound have been populated earlier during function
comment|/// importing from \p Src.
name|bool
name|linkInMetadata
argument_list|(
name|Module
operator|&
name|Src
argument_list|,
name|DenseMap
operator|<
name|unsigned
argument_list|,
name|MDNode
operator|*
operator|>
operator|*
name|ValIDToTempMDMap
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
comment|/// Perform in-place global value handling on the given Module for
comment|/// exported local functions renamed and promoted for ThinLTO.
name|bool
name|renameModuleForThinLTO
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|,
specifier|const
name|FunctionInfoIndex
modifier|*
name|Index
parameter_list|)
function_decl|;
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

