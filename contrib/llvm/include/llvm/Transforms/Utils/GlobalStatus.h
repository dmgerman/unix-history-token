begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- GlobalStatus.h - Compute status info for globals ---------*- C++ -*-===//
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
name|LLVM_TRANSFORMS_UTILS_GLOBALSTATUS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_GLOBALSTATUS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/AtomicOrdering.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Constant
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|Value
decl_stmt|;
comment|/// It is safe to destroy a constant iff it is only used by constants itself.
comment|/// Note that constants cannot be cyclic, so this test is pretty easy to
comment|/// implement recursively.
comment|///
name|bool
name|isSafeToDestroyConstant
parameter_list|(
specifier|const
name|Constant
modifier|*
name|C
parameter_list|)
function_decl|;
comment|/// As we analyze each global, keep track of some information about it.  If we
comment|/// find out that the address of the global is taken, none of this info will be
comment|/// accurate.
struct|struct
name|GlobalStatus
block|{
comment|/// True if the global's address is used in a comparison.
name|bool
name|IsCompared
init|=
name|false
decl_stmt|;
comment|/// True if the global is ever loaded.  If the global isn't ever loaded it
comment|/// can be deleted.
name|bool
name|IsLoaded
init|=
name|false
decl_stmt|;
comment|/// Keep track of what stores to the global look like.
enum|enum
name|StoredType
block|{
comment|/// There is no store to this global.  It can thus be marked constant.
name|NotStored
block|,
comment|/// This global is stored to, but the only thing stored is the constant it
comment|/// was initialized with. This is only tracked for scalar globals.
name|InitializerStored
block|,
comment|/// This global is stored to, but only its initializer and one other value
comment|/// is ever stored to it.  If this global isStoredOnce, we track the value
comment|/// stored to it in StoredOnceValue below.  This is only tracked for scalar
comment|/// globals.
name|StoredOnce
block|,
comment|/// This global is stored to by multiple values or something else that we
comment|/// cannot track.
name|Stored
block|}
name|StoredType
init|=
name|NotStored
enum|;
comment|/// If only one value (besides the initializer constant) is ever stored to
comment|/// this global, keep track of what value it is.
name|Value
modifier|*
name|StoredOnceValue
init|=
name|nullptr
decl_stmt|;
comment|/// These start out null/false.  When the first accessing function is noticed,
comment|/// it is recorded. When a second different accessing function is noticed,
comment|/// HasMultipleAccessingFunctions is set to true.
specifier|const
name|Function
modifier|*
name|AccessingFunction
init|=
name|nullptr
decl_stmt|;
name|bool
name|HasMultipleAccessingFunctions
init|=
name|false
decl_stmt|;
comment|/// Set to true if this global has a user that is not an instruction (e.g. a
comment|/// constant expr or GV initializer).
name|bool
name|HasNonInstructionUser
init|=
name|false
decl_stmt|;
comment|/// Set to the strongest atomic ordering requirement.
name|AtomicOrdering
name|Ordering
init|=
name|AtomicOrdering
operator|::
name|NotAtomic
decl_stmt|;
name|GlobalStatus
argument_list|()
expr_stmt|;
comment|/// Look at all uses of the global and fill in the GlobalStatus structure.  If
comment|/// the global has its address taken, return true to indicate we can't do
comment|/// anything with it.
specifier|static
name|bool
name|analyzeGlobal
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|,
name|GlobalStatus
modifier|&
name|GS
parameter_list|)
function_decl|;
block|}
struct|;
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
comment|// LLVM_TRANSFORMS_UTILS_GLOBALSTATUS_H
end_comment

end_unit

