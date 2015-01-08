begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_stackdepot.h ----------------------------------*- C++ -*-===//
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
comment|// This file is shared between AddressSanitizer and ThreadSanitizer
end_comment

begin_comment
comment|// run-time libraries.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_STACKDEPOT_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_STACKDEPOT_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_internal_defs.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_stacktrace.h"
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
comment|// StackDepot efficiently stores huge amounts of stack traces.
struct_decl|struct
name|StackDepotNode
struct_decl|;
struct|struct
name|StackDepotHandle
block|{
name|StackDepotNode
modifier|*
name|node_
decl_stmt|;
name|StackDepotHandle
argument_list|()
operator|:
name|node_
argument_list|(
literal|0
argument_list|)
block|{}
name|explicit
name|StackDepotHandle
argument_list|(
name|StackDepotNode
operator|*
name|node
argument_list|)
operator|:
name|node_
argument_list|(
argument|node
argument_list|)
block|{}
name|bool
name|valid
argument_list|()
block|{
return|return
name|node_
return|;
block|}
name|u32
name|id
parameter_list|()
function_decl|;
name|int
name|use_count
parameter_list|()
function_decl|;
name|void
name|inc_use_count_unsafe
parameter_list|()
function_decl|;
block|}
struct|;
specifier|const
name|int
name|kStackDepotMaxUseCount
init|=
literal|1U
operator|<<
literal|20
decl_stmt|;
name|StackDepotStats
modifier|*
name|StackDepotGetStats
parameter_list|()
function_decl|;
name|u32
name|StackDepotPut
parameter_list|(
name|StackTrace
name|stack
parameter_list|)
function_decl|;
name|StackDepotHandle
name|StackDepotPut_WithHandle
parameter_list|(
name|StackTrace
name|stack
parameter_list|)
function_decl|;
comment|// Retrieves a stored stack trace by the id.
name|StackTrace
name|StackDepotGet
parameter_list|(
name|u32
name|id
parameter_list|)
function_decl|;
name|void
name|StackDepotLockAll
parameter_list|()
function_decl|;
name|void
name|StackDepotUnlockAll
parameter_list|()
function_decl|;
comment|// Instantiating this class creates a snapshot of StackDepot which can be
comment|// efficiently queried with StackDepotGet(). You can use it concurrently with
comment|// StackDepot, but the snapshot is only guaranteed to contain those stack traces
comment|// which were stored before it was instantiated.
name|class
name|StackDepotReverseMap
block|{
name|public
label|:
name|StackDepotReverseMap
argument_list|()
expr_stmt|;
name|StackTrace
name|Get
parameter_list|(
name|u32
name|id
parameter_list|)
function_decl|;
name|private
label|:
struct|struct
name|IdDescPair
block|{
name|u32
name|id
decl_stmt|;
name|StackDepotNode
modifier|*
name|desc
decl_stmt|;
specifier|static
name|bool
name|IdComparator
parameter_list|(
specifier|const
name|IdDescPair
modifier|&
name|a
parameter_list|,
specifier|const
name|IdDescPair
modifier|&
name|b
parameter_list|)
function_decl|;
block|}
struct|;
name|InternalMmapVector
operator|<
name|IdDescPair
operator|>
name|map_
expr_stmt|;
comment|// Disallow evil constructors.
name|StackDepotReverseMap
argument_list|(
specifier|const
name|StackDepotReverseMap
operator|&
argument_list|)
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|StackDepotReverseMap
operator|&
operator|)
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __sanitizer
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_STACKDEPOT_H
end_comment

end_unit

