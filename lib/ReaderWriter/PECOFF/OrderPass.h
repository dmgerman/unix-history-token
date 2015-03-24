begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/PECOFF/OrderPass.h -------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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
comment|///
end_comment

begin_comment
comment|/// \file \brief This pass sorts atoms by section name, so that they will appear
end_comment

begin_comment
comment|/// in the correct order in the output.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// In COFF, sections will be merged into one section by the linker if their
end_comment

begin_comment
comment|/// names are the same after discarding the "$" character and all characters
end_comment

begin_comment
comment|/// follow it from their names. The characters following the "$" character
end_comment

begin_comment
comment|/// determines the merge order. Assume there's an object file containing four
end_comment

begin_comment
comment|/// data sections in the following order.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   - .data$2
end_comment

begin_comment
comment|///   - .data$3
end_comment

begin_comment
comment|///   - .data$1
end_comment

begin_comment
comment|///   - .data
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// In this case, the resulting binary should have ".data" section with the
end_comment

begin_comment
comment|/// contents of ".data", ".data$1", ".data$2" and ".data$3" in that order.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLD_READER_WRITER_PE_COFF_ORDER_PASS_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_PE_COFF_ORDER_PASS_H
end_define

begin_include
include|#
directive|include
file|"Atoms.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Parallel.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Pass.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|pecoff
block|{
specifier|static
name|bool
name|compare
parameter_list|(
specifier|const
name|DefinedAtom
modifier|*
name|lhs
parameter_list|,
specifier|const
name|DefinedAtom
modifier|*
name|rhs
parameter_list|)
block|{
name|bool
name|lhsCustom
init|=
operator|(
name|lhs
operator|->
name|sectionChoice
argument_list|()
operator|==
name|DefinedAtom
operator|::
name|sectionCustomRequired
operator|)
decl_stmt|;
name|bool
name|rhsCustom
init|=
operator|(
name|rhs
operator|->
name|sectionChoice
argument_list|()
operator|==
name|DefinedAtom
operator|::
name|sectionCustomRequired
operator|)
decl_stmt|;
if|if
condition|(
name|lhsCustom
operator|&&
name|rhsCustom
condition|)
block|{
name|int
name|cmp
init|=
name|lhs
operator|->
name|customSectionName
argument_list|()
operator|.
name|compare
argument_list|(
name|rhs
operator|->
name|customSectionName
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|cmp
operator|!=
literal|0
condition|)
return|return
name|cmp
operator|<
literal|0
return|;
return|return
name|DefinedAtom
operator|::
name|compareByPosition
argument_list|(
name|lhs
argument_list|,
name|rhs
argument_list|)
return|;
block|}
if|if
condition|(
name|lhsCustom
operator|&&
operator|!
name|rhsCustom
condition|)
return|return
name|true
return|;
if|if
condition|(
operator|!
name|lhsCustom
operator|&&
name|rhsCustom
condition|)
return|return
name|false
return|;
return|return
name|DefinedAtom
operator|::
name|compareByPosition
argument_list|(
name|lhs
argument_list|,
name|rhs
argument_list|)
return|;
block|}
name|class
name|OrderPass
range|:
name|public
name|lld
operator|::
name|Pass
block|{
name|public
operator|:
name|void
name|perform
argument_list|(
argument|std::unique_ptr<MutableFile>&file
argument_list|)
name|override
block|{
name|MutableFile
operator|::
name|DefinedAtomRange
name|defined
operator|=
name|file
operator|->
name|definedAtoms
argument_list|()
block|;
name|parallel_sort
argument_list|(
name|defined
operator|.
name|begin
argument_list|()
argument_list|,
name|defined
operator|.
name|end
argument_list|()
argument_list|,
name|compare
argument_list|)
block|;   }
block|}
decl_stmt|;
block|}
comment|// namespace pecoff
block|}
end_decl_stmt

begin_comment
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

