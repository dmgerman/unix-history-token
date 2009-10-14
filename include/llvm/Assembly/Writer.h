begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Assembly/Writer.h - Printer for LLVM assembly files --*- C++ -*-=//
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
comment|// This functionality is implemented by lib/VMCore/AsmWriter.cpp.
end_comment

begin_comment
comment|// This library is used to print LLVM assembly language files to an iostream. It
end_comment

begin_comment
comment|// can print LLVM code at a variety of granularities, including Modules,
end_comment

begin_comment
comment|// BasicBlocks, and Instructions.  This makes it useful for debugging.
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
name|LLVM_ASSEMBLY_WRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ASSEMBLY_WRITER_H
end_define

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
name|Type
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
comment|/// TypePrinting - Type printing machinery.
name|class
name|TypePrinting
block|{
name|void
modifier|*
name|TypeNames
decl_stmt|;
comment|// A map to remember type names.
name|TypePrinting
argument_list|(
specifier|const
name|TypePrinting
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|TypePrinting
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|public
label|:
name|TypePrinting
argument_list|()
expr_stmt|;
operator|~
name|TypePrinting
argument_list|()
expr_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
name|void
name|print
parameter_list|(
specifier|const
name|Type
modifier|*
name|Ty
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|bool
name|IgnoreTopLevelName
init|=
name|false
parameter_list|)
function_decl|;
name|void
name|printAtLeastOneLevel
parameter_list|(
specifier|const
name|Type
modifier|*
name|Ty
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
block|{
name|print
argument_list|(
name|Ty
argument_list|,
name|OS
argument_list|,
name|true
argument_list|)
expr_stmt|;
block|}
comment|/// hasTypeName - Return true if the type has a name in TypeNames, false
comment|/// otherwise.
name|bool
name|hasTypeName
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// addTypeName - Add a name for the specified type if it doesn't already have
comment|/// one.  This name will be printed instead of the structural version of the
comment|/// type in order to make the output more concise.
name|void
name|addTypeName
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|N
argument_list|)
decl_stmt|;
name|private
label|:
name|void
name|CalcTypeName
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
name|SmallVectorImpl
operator|<
specifier|const
name|Type
operator|*
operator|>
operator|&
name|TypeStack
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|,
name|bool
name|IgnoreTopLevelName
operator|=
name|false
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
comment|// WriteTypeSymbolic - This attempts to write the specified type as a symbolic
comment|// type, if there is an entry in the Module's symbol table for the specified
comment|// type or one of its component types.
comment|//
name|void
name|WriteTypeSymbolic
parameter_list|(
name|raw_ostream
modifier|&
parameter_list|,
specifier|const
name|Type
modifier|*
parameter_list|,
specifier|const
name|Module
modifier|*
name|M
parameter_list|)
function_decl|;
comment|// WriteAsOperand - Write the name of the specified value out to the specified
comment|// ostream.  This can be useful when you just want to print int %reg126, not the
comment|// whole instruction that generated it.  If you specify a Module for context,
comment|// then even constants get pretty-printed; for example, the type of a null
comment|// pointer is printed symbolically.
comment|//
name|void
name|WriteAsOperand
parameter_list|(
name|raw_ostream
modifier|&
parameter_list|,
specifier|const
name|Value
modifier|*
parameter_list|,
name|bool
name|PrintTy
init|=
name|true
parameter_list|,
specifier|const
name|Module
modifier|*
name|Context
init|=
literal|0
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

