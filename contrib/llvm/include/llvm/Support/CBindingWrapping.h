begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/CBindingWrapph.h - C Interface Wrapping -----*- C++ -*-===//
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
comment|// This file declares the wrapping macros for the C interface.
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
name|LLVM_SUPPORT_CBINDINGWRAPPING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_CBINDINGWRAPPING_H
end_define

begin_include
include|#
directive|include
file|"llvm-c/Types.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_define
define|#
directive|define
name|DEFINE_SIMPLE_CONVERSION_FUNCTIONS
parameter_list|(
name|ty
parameter_list|,
name|ref
parameter_list|)
define|\
value|inline ty *unwrap(ref P) {                            \     return reinterpret_cast<ty*>(P);                    \   }                                                     \                                                         \   inline ref wrap(const ty *P) {                        \     return reinterpret_cast<ref>(const_cast<ty*>(P));   \   }
end_define

begin_define
define|#
directive|define
name|DEFINE_ISA_CONVERSION_FUNCTIONS
parameter_list|(
name|ty
parameter_list|,
name|ref
parameter_list|)
define|\
value|DEFINE_SIMPLE_CONVERSION_FUNCTIONS(ty, ref)           \                                                         \   template<typename T>                                  \   inline T *unwrap(ref P) {                             \     return cast<T>(unwrap(P));                          \   }
end_define

begin_define
define|#
directive|define
name|DEFINE_STDCXX_CONVERSION_FUNCTIONS
parameter_list|(
name|ty
parameter_list|,
name|ref
parameter_list|)
define|\
value|DEFINE_SIMPLE_CONVERSION_FUNCTIONS(ty, ref)           \                                                         \   template<typename T>                                  \   inline T *unwrap(ref P) {                             \     T *Q = (T*)unwrap(P);                               \     assert(Q&& "Invalid cast!");                       \     return Q;                                           \   }
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

