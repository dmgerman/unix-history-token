begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ASanStackFrameLayout.h - ComputeASanStackFrameLayout -----*- C++ -*-===//
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
comment|// This header defines ComputeASanStackFrameLayout and auxiliary data structs.
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
name|LLVM_TRANSFORMS_UTILS_ASANSTACKFRAMELAYOUT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_ASANSTACKFRAMELAYOUT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AllocaInst
decl_stmt|;
comment|// These magic constants should be the same as in
comment|// in asan_internal.h from ASan runtime in compiler-rt.
specifier|static
specifier|const
name|int
name|kAsanStackLeftRedzoneMagic
init|=
literal|0xf1
decl_stmt|;
specifier|static
specifier|const
name|int
name|kAsanStackMidRedzoneMagic
init|=
literal|0xf2
decl_stmt|;
specifier|static
specifier|const
name|int
name|kAsanStackRightRedzoneMagic
init|=
literal|0xf3
decl_stmt|;
comment|// Input/output data struct for ComputeASanStackFrameLayout.
struct|struct
name|ASanStackVariableDescription
block|{
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
comment|// Name of the variable that will be displayed by asan
comment|// if a stack-related bug is reported.
name|uint64_t
name|Size
decl_stmt|;
comment|// Size of the variable in bytes.
name|size_t
name|Alignment
decl_stmt|;
comment|// Alignment of the variable (power of 2).
name|AllocaInst
modifier|*
name|AI
decl_stmt|;
comment|// The actual AllocaInst.
name|size_t
name|Offset
decl_stmt|;
comment|// Offset from the beginning of the frame;
comment|// set by ComputeASanStackFrameLayout.
block|}
struct|;
comment|// Output data struct for ComputeASanStackFrameLayout.
struct|struct
name|ASanStackFrameLayout
block|{
comment|// Frame description, see DescribeAddressIfStack in ASan runtime.
name|SmallString
operator|<
literal|64
operator|>
name|DescriptionString
expr_stmt|;
comment|// The contents of the shadow memory for the stack frame that we need
comment|// to set at function entry.
name|SmallVector
operator|<
name|uint8_t
operator|,
literal|64
operator|>
name|ShadowBytes
expr_stmt|;
name|size_t
name|FrameAlignment
decl_stmt|;
comment|// Alignment for the entire frame.
name|size_t
name|FrameSize
decl_stmt|;
comment|// Size of the frame in bytes.
block|}
struct|;
name|void
name|ComputeASanStackFrameLayout
argument_list|(
comment|// The array of stack variables. The elements may get reordered and changed.
name|SmallVectorImpl
operator|<
name|ASanStackVariableDescription
operator|>
operator|&
name|Vars
argument_list|,
comment|// AddressSanitizer's shadow granularity. Usually 8, may also be 16, 32, 64.
name|size_t
name|Granularity
argument_list|,
comment|// The minimal size of the left-most redzone (header).
comment|// At least 4 pointer sizes, power of 2, and>= Granularity.
comment|// The resulting FrameSize should be multiple of MinHeaderSize.
name|size_t
name|MinHeaderSize
argument_list|,
comment|// The result is put here.
name|ASanStackFrameLayout
operator|*
name|Layout
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_UTILS_ASANSTACKFRAMELAYOUT_H
end_comment

end_unit

