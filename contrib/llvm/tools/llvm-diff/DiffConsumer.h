begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DiffConsumer.h - Difference Consumer --------------------*- C++ -*-===//
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
comment|// This header defines the interface to the LLVM difference Consumer
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
name|_LLVM_DIFFCONSUMER_H_
end_ifndef

begin_define
define|#
directive|define
name|_LLVM_DIFFCONSUMER_H_
end_define

begin_include
include|#
directive|include
file|"DiffLog.h"
end_include

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
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|Function
decl_stmt|;
comment|/// The interface for consumers of difference data.
name|class
name|Consumer
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|public
label|:
comment|/// Record that a local context has been entered.  Left and
comment|/// Right are IR "containers" of some sort which are being
comment|/// considered for structural equivalence: global variables,
comment|/// functions, blocks, instructions, etc.
name|virtual
name|void
name|enterContext
parameter_list|(
name|Value
modifier|*
name|Left
parameter_list|,
name|Value
modifier|*
name|Right
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Record that a local context has been exited.
name|virtual
name|void
name|exitContext
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// Record a difference within the current context.
name|virtual
name|void
name|log
parameter_list|(
name|StringRef
name|Text
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Record a formatted difference within the current context.
name|virtual
name|void
name|logf
parameter_list|(
specifier|const
name|LogBuilder
modifier|&
name|Log
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Record a line-by-line instruction diff.
name|virtual
name|void
name|logd
parameter_list|(
specifier|const
name|DiffLogBuilder
modifier|&
name|Log
parameter_list|)
init|=
literal|0
function_decl|;
name|protected
label|:
name|virtual
operator|~
name|Consumer
argument_list|()
block|{}
block|}
empty_stmt|;
name|class
name|DiffConsumer
range|:
name|public
name|Consumer
block|{
name|private
operator|:
expr|struct
name|DiffContext
block|{
name|DiffContext
argument_list|(
name|Value
operator|*
name|L
argument_list|,
name|Value
operator|*
name|R
argument_list|)
operator|:
name|L
argument_list|(
name|L
argument_list|)
block|,
name|R
argument_list|(
name|R
argument_list|)
block|,
name|Differences
argument_list|(
name|false
argument_list|)
block|,
name|IsFunction
argument_list|(
argument|isa<Function>(L)
argument_list|)
block|{}
name|Value
operator|*
name|L
block|;
name|Value
operator|*
name|R
block|;
name|bool
name|Differences
block|;
name|bool
name|IsFunction
block|;
name|DenseMap
operator|<
name|Value
operator|*
block|,
name|unsigned
operator|>
name|LNumbering
block|;
name|DenseMap
operator|<
name|Value
operator|*
block|,
name|unsigned
operator|>
name|RNumbering
block|;     }
block|;
name|raw_ostream
operator|&
name|out
block|;
name|SmallVector
operator|<
name|DiffContext
block|,
literal|5
operator|>
name|contexts
block|;
name|bool
name|Differences
block|;
name|unsigned
name|Indent
block|;
name|void
name|printValue
argument_list|(
argument|Value *V
argument_list|,
argument|bool isL
argument_list|)
block|;
name|void
name|header
argument_list|()
block|;
name|void
name|indent
argument_list|()
block|;
name|public
operator|:
name|DiffConsumer
argument_list|()
operator|:
name|out
argument_list|(
name|errs
argument_list|()
argument_list|)
block|,
name|Differences
argument_list|(
name|false
argument_list|)
block|,
name|Indent
argument_list|(
literal|0
argument_list|)
block|{}
name|bool
name|hadDifferences
argument_list|()
specifier|const
block|;
name|void
name|enterContext
argument_list|(
argument|Value *L
argument_list|,
argument|Value *R
argument_list|)
name|override
block|;
name|void
name|exitContext
argument_list|()
name|override
block|;
name|void
name|log
argument_list|(
argument|StringRef text
argument_list|)
name|override
block|;
name|void
name|logf
argument_list|(
argument|const LogBuilder&Log
argument_list|)
name|override
block|;
name|void
name|logd
argument_list|(
argument|const DiffLogBuilder&Log
argument_list|)
name|override
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

