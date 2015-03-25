begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- CGLoopInfo.h - LLVM CodeGen for loop metadata -*- C++ -*---------===//
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
comment|// This is the internal state used for llvm translation for loop statement
end_comment

begin_comment
comment|// metadata.
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
name|LLVM_CLANG_LIB_CODEGEN_CGLOOPINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_CODEGEN_CGLOOPINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Value.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BasicBlock
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|CodeGen
block|{
comment|/// \brief Attributes that may be specified on loops.
struct|struct
name|LoopAttributes
block|{
name|explicit
name|LoopAttributes
parameter_list|(
name|bool
name|IsParallel
init|=
name|false
parameter_list|)
function_decl|;
name|void
name|clear
parameter_list|()
function_decl|;
comment|/// \brief Generate llvm.loop.parallel metadata for loads and stores.
name|bool
name|IsParallel
decl_stmt|;
comment|/// \brief Values of llvm.loop.vectorize.enable metadata.
enum|enum
name|LVEnableState
block|{
name|VecUnspecified
block|,
name|VecEnable
block|,
name|VecDisable
block|}
enum|;
comment|/// \brief llvm.loop.vectorize.enable
name|LVEnableState
name|VectorizerEnable
decl_stmt|;
comment|/// \brief llvm.loop.vectorize.width
name|unsigned
name|VectorizerWidth
decl_stmt|;
comment|/// \brief llvm.loop.interleave.count
name|unsigned
name|VectorizerUnroll
decl_stmt|;
block|}
struct|;
comment|/// \brief Information used when generating a structured loop.
name|class
name|LoopInfo
block|{
name|public
label|:
comment|/// \brief Construct a new LoopInfo for the loop with entry Header.
name|LoopInfo
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|*
name|Header
argument_list|,
specifier|const
name|LoopAttributes
operator|&
name|Attrs
argument_list|)
expr_stmt|;
comment|/// \brief Get the loop id metadata for this loop.
name|llvm
operator|::
name|MDNode
operator|*
name|getLoopID
argument_list|()
specifier|const
block|{
return|return
name|LoopID
return|;
block|}
comment|/// \brief Get the header block of this loop.
name|llvm
operator|::
name|BasicBlock
operator|*
name|getHeader
argument_list|()
specifier|const
block|{
return|return
name|Header
return|;
block|}
comment|/// \brief Get the set of attributes active for this loop.
specifier|const
name|LoopAttributes
operator|&
name|getAttributes
argument_list|()
specifier|const
block|{
return|return
name|Attrs
return|;
block|}
name|private
label|:
comment|/// \brief Loop ID metadata.
name|llvm
operator|::
name|MDNode
operator|*
name|LoopID
expr_stmt|;
comment|/// \brief Header block of this loop.
name|llvm
operator|::
name|BasicBlock
operator|*
name|Header
expr_stmt|;
comment|/// \brief The attributes for this loop.
name|LoopAttributes
name|Attrs
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief A stack of loop information corresponding to loop nesting levels.
comment|/// This stack can be used to prepare attributes which are applied when a loop
comment|/// is emitted.
name|class
name|LoopInfoStack
block|{
name|LoopInfoStack
argument_list|(
argument|const LoopInfoStack&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|LoopInfoStack
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|public
label|:
name|LoopInfoStack
argument_list|()
block|{}
comment|/// \brief Begin a new structured loop. The set of staged attributes will be
comment|/// applied to the loop and then cleared.
name|void
name|push
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|*
name|Header
argument_list|)
decl_stmt|;
comment|/// \brief End the current loop.
name|void
name|pop
parameter_list|()
function_decl|;
comment|/// \brief Return the top loop id metadata.
name|llvm
operator|::
name|MDNode
operator|*
name|getCurLoopID
argument_list|()
specifier|const
block|{
return|return
name|getInfo
argument_list|()
operator|.
name|getLoopID
argument_list|()
return|;
block|}
comment|/// \brief Return true if the top loop is parallel.
name|bool
name|getCurLoopParallel
argument_list|()
specifier|const
block|{
return|return
name|hasInfo
argument_list|()
operator|?
name|getInfo
argument_list|()
operator|.
name|getAttributes
argument_list|()
operator|.
name|IsParallel
operator|:
name|false
return|;
block|}
comment|/// \brief Function called by the CodeGenFunction when an instruction is
comment|/// created.
name|void
name|InsertHelper
argument_list|(
name|llvm
operator|::
name|Instruction
operator|*
name|I
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Set the next pushed loop as parallel.
name|void
name|setParallel
parameter_list|(
name|bool
name|Enable
init|=
name|true
parameter_list|)
block|{
name|StagedAttrs
operator|.
name|IsParallel
operator|=
name|Enable
expr_stmt|;
block|}
comment|/// \brief Set the next pushed loop 'vectorizer.enable'
name|void
name|setVectorizerEnable
parameter_list|(
name|bool
name|Enable
init|=
name|true
parameter_list|)
block|{
name|StagedAttrs
operator|.
name|VectorizerEnable
operator|=
name|Enable
condition|?
name|LoopAttributes
operator|::
name|VecEnable
else|:
name|LoopAttributes
operator|::
name|VecDisable
expr_stmt|;
block|}
comment|/// \brief Set the vectorizer width for the next loop pushed.
name|void
name|setVectorizerWidth
parameter_list|(
name|unsigned
name|W
parameter_list|)
block|{
name|StagedAttrs
operator|.
name|VectorizerWidth
operator|=
name|W
expr_stmt|;
block|}
comment|/// \brief Set the vectorizer unroll for the next loop pushed.
name|void
name|setVectorizerUnroll
parameter_list|(
name|unsigned
name|U
parameter_list|)
block|{
name|StagedAttrs
operator|.
name|VectorizerUnroll
operator|=
name|U
expr_stmt|;
block|}
name|private
label|:
comment|/// \brief Returns true if there is LoopInfo on the stack.
name|bool
name|hasInfo
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Active
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// \brief Return the LoopInfo for the current loop. HasInfo should be called
comment|/// first to ensure LoopInfo is present.
specifier|const
name|LoopInfo
operator|&
name|getInfo
argument_list|()
specifier|const
block|{
return|return
name|Active
operator|.
name|back
argument_list|()
return|;
block|}
comment|/// \brief The set of attributes that will be applied to the next pushed loop.
name|LoopAttributes
name|StagedAttrs
decl_stmt|;
comment|/// \brief Stack of active loops.
name|llvm
operator|::
name|SmallVector
operator|<
name|LoopInfo
operator|,
literal|4
operator|>
name|Active
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace CodeGen
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

