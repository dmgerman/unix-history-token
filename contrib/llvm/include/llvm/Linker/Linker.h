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
block|,
comment|/// Don't force link referenced linkonce definitions, import declaration.
name|DontForceLinkLinkonceODR
init|=
operator|(
literal|1
operator|<<
literal|3
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
comment|/// For ThinLTO function importing/exporting the \p ModuleSummaryIndex
comment|/// is passed. If \p GlobalsToImport is provided, only the globals that
comment|/// are part of the set will be imported from the source module.
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
name|DenseSet
operator|<
specifier|const
name|GlobalValue
operator|*
operator|>
operator|*
name|GlobalsToImport
operator|=
name|nullptr
argument_list|)
decl_stmt|;
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

