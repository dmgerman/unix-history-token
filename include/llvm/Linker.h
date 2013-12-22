begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Linker.h - Module Linker Interface ------------------*- C++ -*-===//
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
name|LLVM_LINKER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LINKER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|StructType
decl_stmt|;
comment|/// This class provides the core functionality of linking in LLVM. It keeps a
comment|/// pointer to the merged module so far. It doesn't take ownership of the
comment|/// module since it is assumed that the user of this class will want to do
comment|/// something with it after the linking.
name|class
name|Linker
block|{
name|public
label|:
enum|enum
name|LinkerMode
block|{
name|DestroySource
init|=
literal|0
block|,
comment|// Allow source module to be destroyed.
name|PreserveSource
init|=
literal|1
comment|// Preserve the source module.
block|}
enum|;
name|Linker
argument_list|(
name|Module
operator|*
name|M
argument_list|)
expr_stmt|;
operator|~
name|Linker
argument_list|()
expr_stmt|;
name|Module
operator|*
name|getModule
argument_list|()
specifier|const
block|{
return|return
name|Composite
return|;
block|}
name|void
name|deleteModule
parameter_list|()
function_decl|;
comment|/// \brief Link \p Src into the composite. The source is destroyed if
comment|/// \p Mode is DestroySource and preserved if it is PreserveSource.
comment|/// If \p ErrorMsg is not null, information about any error is written
comment|/// to it.
comment|/// Returns true on error.
name|bool
name|linkInModule
argument_list|(
name|Module
operator|*
name|Src
argument_list|,
name|unsigned
name|Mode
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrorMsg
argument_list|)
decl_stmt|;
name|bool
name|linkInModule
argument_list|(
name|Module
operator|*
name|Src
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrorMsg
argument_list|)
block|{
return|return
name|linkInModule
argument_list|(
name|Src
argument_list|,
name|Linker
operator|::
name|DestroySource
argument_list|,
name|ErrorMsg
argument_list|)
return|;
block|}
specifier|static
name|bool
name|LinkModules
argument_list|(
name|Module
operator|*
name|Dest
argument_list|,
name|Module
operator|*
name|Src
argument_list|,
name|unsigned
name|Mode
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrorMsg
argument_list|)
decl_stmt|;
name|private
label|:
name|Module
modifier|*
name|Composite
decl_stmt|;
name|SmallPtrSet
operator|<
name|StructType
operator|*
operator|,
literal|32
operator|>
name|IdentifiedStructTypes
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

