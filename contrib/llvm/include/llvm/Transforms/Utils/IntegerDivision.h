begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Transforms/Utils/IntegerDivision.h ------------------*- C++ -*-===//
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
comment|// This file contains an implementation of 32bit and 64bit scalar integer
end_comment

begin_comment
comment|// division for targets that don't have native support. It's largely derived
end_comment

begin_comment
comment|// from compiler-rt's implementations of __udivsi3 and __udivmoddi4,
end_comment

begin_comment
comment|// but hand-tuned for targets that prefer less control flow.
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
name|LLVM_TRANSFORMS_UTILS_INTEGERDIVISION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_INTEGERDIVISION_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BinaryOperator
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Generate code to calculate the remainder of two integers, replacing Rem
comment|/// with the generated code. This currently generates code using the udiv
comment|/// expansion, but future work includes generating more specialized code,
comment|/// e.g. when more information about the operands are known. Implements both
comment|/// 32bit and 64bit scalar division.
comment|///
comment|/// @brief Replace Rem with generated code.
name|bool
name|expandRemainder
parameter_list|(
name|BinaryOperator
modifier|*
name|Rem
parameter_list|)
function_decl|;
comment|/// Generate code to divide two integers, replacing Div with the generated
comment|/// code. This currently generates code similarly to compiler-rt's
comment|/// implementations, but future work includes generating more specialized code
comment|/// when more information about the operands are known. Implements both
comment|/// 32bit and 64bit scalar division.
comment|///
comment|/// @brief Replace Div with generated code.
name|bool
name|expandDivision
parameter_list|(
name|BinaryOperator
modifier|*
name|Div
parameter_list|)
function_decl|;
comment|/// Generate code to calculate the remainder of two integers, replacing Rem
comment|/// with the generated code. Uses ExpandReminder with a 32bit Rem which
comment|/// makes it useful for targets with little or no support for less than
comment|/// 32 bit arithmetic.
comment|///
comment|/// @brief Replace Rem with generated code.
name|bool
name|expandRemainderUpTo32Bits
parameter_list|(
name|BinaryOperator
modifier|*
name|Rem
parameter_list|)
function_decl|;
comment|/// Generate code to calculate the remainder of two integers, replacing Rem
comment|/// with the generated code. Uses ExpandReminder with a 64bit Rem.
comment|///
comment|/// @brief Replace Rem with generated code.
name|bool
name|expandRemainderUpTo64Bits
parameter_list|(
name|BinaryOperator
modifier|*
name|Rem
parameter_list|)
function_decl|;
comment|/// Generate code to divide two integers, replacing Div with the generated
comment|/// code. Uses ExpandDivision with a 32bit Div which makes it useful for
comment|/// targets with little or no support for less than 32 bit arithmetic.
comment|///
comment|/// @brief Replace Rem with generated code.
name|bool
name|expandDivisionUpTo32Bits
parameter_list|(
name|BinaryOperator
modifier|*
name|Div
parameter_list|)
function_decl|;
comment|/// Generate code to divide two integers, replacing Div with the generated
comment|/// code. Uses ExpandDivision with a 64bit Div.
comment|///
comment|/// @brief Replace Rem with generated code.
name|bool
name|expandDivisionUpTo64Bits
parameter_list|(
name|BinaryOperator
modifier|*
name|Div
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

