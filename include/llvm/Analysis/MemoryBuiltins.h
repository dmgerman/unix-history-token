begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Analysis/MemoryBuiltins.h- Calls to memory builtins -*- C++ -*-===//
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
comment|// This family of functions identifies calls to builtin functions that allocate
end_comment

begin_comment
comment|// or free memory.
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
name|LLVM_ANALYSIS_MEMORYBUILTINS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_MEMORYBUILTINS_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|CallInst
decl_stmt|;
name|class
name|PointerType
decl_stmt|;
name|class
name|TargetData
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|Value
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//  malloc Call Utility Functions.
comment|//
comment|/// isMalloc - Returns true if the value is either a malloc call or a bitcast of
comment|/// the result of a malloc call
name|bool
name|isMalloc
parameter_list|(
specifier|const
name|Value
modifier|*
name|I
parameter_list|)
function_decl|;
comment|/// extractMallocCall - Returns the corresponding CallInst if the instruction
comment|/// is a malloc call.  Since CallInst::CreateMalloc() only creates calls, we
comment|/// ignore InvokeInst here.
specifier|const
name|CallInst
modifier|*
name|extractMallocCall
parameter_list|(
specifier|const
name|Value
modifier|*
name|I
parameter_list|)
function_decl|;
name|CallInst
modifier|*
name|extractMallocCall
parameter_list|(
name|Value
modifier|*
name|I
parameter_list|)
function_decl|;
comment|/// extractMallocCallFromBitCast - Returns the corresponding CallInst if the
comment|/// instruction is a bitcast of the result of a malloc call.
specifier|const
name|CallInst
modifier|*
name|extractMallocCallFromBitCast
parameter_list|(
specifier|const
name|Value
modifier|*
name|I
parameter_list|)
function_decl|;
name|CallInst
modifier|*
name|extractMallocCallFromBitCast
parameter_list|(
name|Value
modifier|*
name|I
parameter_list|)
function_decl|;
comment|/// isArrayMalloc - Returns the corresponding CallInst if the instruction
comment|/// is a call to malloc whose array size can be determined and the array size
comment|/// is not constant 1.  Otherwise, return NULL.
specifier|const
name|CallInst
modifier|*
name|isArrayMalloc
parameter_list|(
specifier|const
name|Value
modifier|*
name|I
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
parameter_list|)
function_decl|;
comment|/// getMallocType - Returns the PointerType resulting from the malloc call.
comment|/// The PointerType depends on the number of bitcast uses of the malloc call:
comment|///   0: PointerType is the malloc calls' return type.
comment|///   1: PointerType is the bitcast's result type.
comment|///>1: Unique PointerType cannot be determined, return NULL.
specifier|const
name|PointerType
modifier|*
name|getMallocType
parameter_list|(
specifier|const
name|CallInst
modifier|*
name|CI
parameter_list|)
function_decl|;
comment|/// getMallocAllocatedType - Returns the Type allocated by malloc call.
comment|/// The Type depends on the number of bitcast uses of the malloc call:
comment|///   0: PointerType is the malloc calls' return type.
comment|///   1: PointerType is the bitcast's result type.
comment|///>1: Unique PointerType cannot be determined, return NULL.
specifier|const
name|Type
modifier|*
name|getMallocAllocatedType
parameter_list|(
specifier|const
name|CallInst
modifier|*
name|CI
parameter_list|)
function_decl|;
comment|/// getMallocArraySize - Returns the array size of a malloc call.  If the
comment|/// argument passed to malloc is a multiple of the size of the malloced type,
comment|/// then return that multiple.  For non-array mallocs, the multiple is
comment|/// constant 1.  Otherwise, return NULL for mallocs whose array size cannot be
comment|/// determined.
name|Value
modifier|*
name|getMallocArraySize
parameter_list|(
name|CallInst
modifier|*
name|CI
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
parameter_list|,
name|bool
name|LookThroughSExt
init|=
name|false
parameter_list|)
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//  free Call Utility Functions.
comment|//
comment|/// isFreeCall - Returns true if the the value is a call to the builtin free()
name|bool
name|isFreeCall
parameter_list|(
specifier|const
name|Value
modifier|*
name|I
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

