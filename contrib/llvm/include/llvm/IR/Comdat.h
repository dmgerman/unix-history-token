begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/IR/Comdat.h - Comdat definitions --------------------*- C++ -*-===//
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
comment|/// @file
end_comment

begin_comment
comment|/// This file contains the declaration of the Comdat class, which represents a
end_comment

begin_comment
comment|/// single COMDAT in LLVM.
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
name|LLVM_IR_COMDAT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_COMDAT_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|template
operator|<
name|typename
name|ValueTy
operator|>
name|class
name|StringMapEntry
expr_stmt|;
comment|// This is a Name X SelectionKind pair. The reason for having this be an
comment|// independent object instead of just adding the name and the SelectionKind
comment|// to a GlobalObject is that it is invalid to have two Comdats with the same
comment|// name but different SelectionKind. This structure makes that unrepresentable.
name|class
name|Comdat
block|{
name|public
label|:
enum|enum
name|SelectionKind
block|{
name|Any
block|,
comment|///< The linker may choose any COMDAT.
name|ExactMatch
block|,
comment|///< The data referenced by the COMDAT must be the same.
name|Largest
block|,
comment|///< The linker will choose the largest COMDAT.
name|NoDuplicates
block|,
comment|///< No other Module may specify this COMDAT.
name|SameSize
block|,
comment|///< The data referenced by the COMDAT must be the same size.
block|}
enum|;
name|Comdat
argument_list|(
specifier|const
name|Comdat
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|Comdat
argument_list|(
name|Comdat
operator|&&
name|C
argument_list|)
expr_stmt|;
name|SelectionKind
name|getSelectionKind
argument_list|()
specifier|const
block|{
return|return
name|SK
return|;
block|}
name|void
name|setSelectionKind
parameter_list|(
name|SelectionKind
name|Val
parameter_list|)
block|{
name|SK
operator|=
name|Val
expr_stmt|;
block|}
name|StringRef
name|getName
argument_list|()
specifier|const
expr_stmt|;
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|bool
name|IsForDebug
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|friend
name|class
name|Module
decl_stmt|;
name|Comdat
argument_list|()
expr_stmt|;
comment|// Points to the map in Module.
name|StringMapEntry
operator|<
name|Comdat
operator|>
operator|*
name|Name
operator|=
name|nullptr
expr_stmt|;
name|SelectionKind
name|SK
init|=
name|Any
decl_stmt|;
block|}
empty_stmt|;
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|Comdat
operator|&
name|C
operator|)
block|{
name|C
operator|.
name|print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
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
comment|// LLVM_IR_COMDAT_H
end_comment

end_unit

