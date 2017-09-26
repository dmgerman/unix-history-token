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
file|"llvm/ADT/StringSet.h"
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
block|,   }
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
comment|///
comment|/// Passing InternalizeCallback will have the linker call the function with
comment|/// the new module and a list of global value names to be internalized by the
comment|/// callback.
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
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|Module
operator|&
argument_list|,
specifier|const
name|StringSet
operator|<
operator|>
operator|&
argument_list|)
operator|>
name|InternalizeCallback
operator|=
block|{}
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
argument_list|,
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|Module
operator|&
argument_list|,
specifier|const
name|StringSet
operator|<
operator|>
operator|&
argument_list|)
operator|>
name|InternalizeCallback
operator|=
block|{}
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

