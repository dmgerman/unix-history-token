begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ClangASTNodesEmitter.h - Generate Clang AST node tables -*- C++ -*--===//
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
comment|// These tablegen backends emit Clang AST node tables
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
name|CLANGAST_EMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|CLANGAST_EMITTER_H
end_define

begin_include
include|#
directive|include
file|"TableGenBackend.h"
end_include

begin_include
include|#
directive|include
file|"Record.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<cctype>
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
comment|/// ClangASTNodesEmitter - The top-level class emits .inc files containing
comment|///  declarations of Clang statements.
comment|///
name|class
name|ClangASTNodesEmitter
range|:
name|public
name|TableGenBackend
block|{
comment|// A map from a node to each of its derived nodes.
typedef|typedef
name|std
operator|::
name|multimap
operator|<
name|Record
operator|*
operator|,
name|Record
operator|*
operator|>
name|ChildMap
expr_stmt|;
typedef|typedef
name|ChildMap
operator|::
name|const_iterator
name|ChildIterator
expr_stmt|;
name|RecordKeeper
modifier|&
name|Records
decl_stmt|;
name|Record
name|Root
decl_stmt|;
specifier|const
name|std
operator|::
name|string
operator|&
name|BaseSuffix
expr_stmt|;
comment|// Create a macro-ized version of a name
specifier|static
name|std
operator|::
name|string
name|macroName
argument_list|(
argument|std::string S
argument_list|)
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
name|S
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|S
index|[
name|i
index|]
operator|=
name|std
operator|::
name|toupper
argument_list|(
name|S
index|[
name|i
index|]
argument_list|)
expr_stmt|;
return|return
name|S
return|;
block|}
end_decl_stmt

begin_comment
comment|// Return the name to be printed in the base field. Normally this is
end_comment

begin_comment
comment|// the record's name plus the base suffix, but if it is the root node and
end_comment

begin_comment
comment|// the suffix is non-empty, it's just the suffix.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|baseName
argument_list|(
argument|Record&R
argument_list|)
block|{
if|if
condition|(
operator|&
name|R
operator|==
operator|&
name|Root
operator|&&
operator|!
name|BaseSuffix
operator|.
name|empty
argument_list|()
condition|)
return|return
name|BaseSuffix
return|;
end_expr_stmt

begin_return
return|return
name|R
operator|.
name|getName
argument_list|()
operator|+
name|BaseSuffix
return|;
end_return

begin_expr_stmt
unit|}    std
operator|::
name|pair
operator|<
name|Record
operator|*
operator|,
name|Record
operator|*
operator|>
name|EmitNode
argument_list|(
specifier|const
name|ChildMap
operator|&
name|Tree
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|,
name|Record
operator|*
name|Base
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_decl_stmt
name|explicit
name|ClangASTNodesEmitter
argument_list|(
name|RecordKeeper
operator|&
name|R
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|N
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|S
argument_list|)
range|:
name|Records
argument_list|(
name|R
argument_list|)
decl_stmt|,
name|Root
argument_list|(
name|N
argument_list|,
name|SMLoc
argument_list|()
argument_list|,
name|R
argument_list|)
decl_stmt|,
name|BaseSuffix
argument_list|(
name|S
argument_list|)
block|{}
end_decl_stmt

begin_comment
comment|// run - Output the .inc file contents
end_comment

begin_function_decl
name|void
name|run
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|};
comment|/// ClangDeclContextEmitter - Emits an addendum to a .inc file to enumerate the
end_comment

begin_comment
comment|/// clang declaration contexts.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|ClangDeclContextEmitter
range|:
name|public
name|TableGenBackend
block|{
name|RecordKeeper
operator|&
name|Records
block|;
name|public
operator|:
name|explicit
name|ClangDeclContextEmitter
argument_list|(
name|RecordKeeper
operator|&
name|R
argument_list|)
operator|:
name|Records
argument_list|(
argument|R
argument_list|)
block|{}
comment|// run - Output the .inc file contents
name|void
name|run
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

