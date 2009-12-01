begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- llvm/Analysis/CaptureTracking.h - Pointer capture ----*- C++ -*-===//
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
comment|// This file contains routines that help determine which pointers are captured.
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
name|LLVM_ANALYSIS_CAPTURETRACKING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_CAPTURETRACKING_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Value
decl_stmt|;
comment|/// PointerMayBeCaptured - Return true if this pointer value may be captured
comment|/// by the enclosing function (which is required to exist).  This routine can
comment|/// be expensive, so consider caching the results.  The boolean ReturnCaptures
comment|/// specifies whether returning the value (or part of it) from the function
comment|/// counts as capturing it or not.  The boolean StoreCaptures specified whether
comment|/// storing the value (or part of it) into memory anywhere automatically
comment|/// counts as capturing it or not.
name|bool
name|PointerMayBeCaptured
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|,
name|bool
name|ReturnCaptures
parameter_list|,
name|bool
name|StoreCaptures
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

