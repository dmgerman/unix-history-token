begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ErrorChecking.h - Helpers for verifying llvm::Errors -----*- C++ -*-===//
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
name|LLVM_UNITTESTS_DEBUGINFO_CODEVIEW_ERRORCHECKING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_UNITTESTS_DEBUGINFO_CODEVIEW_ERRORCHECKING_H
end_define

begin_define
define|#
directive|define
name|EXPECT_NO_ERROR
parameter_list|(
name|Err
parameter_list|)
define|\
value|{                                                                            \     auto E = Err;                                                              \     EXPECT_FALSE(static_cast<bool>(E));                                        \     if (E)                                                                     \       consumeError(std::move(E));                                              \   }
end_define

begin_define
define|#
directive|define
name|EXPECT_ERROR
parameter_list|(
name|Err
parameter_list|)
define|\
value|{                                                                            \     auto E = Err;                                                              \     EXPECT_TRUE(static_cast<bool>(E));                                         \     if (E)                                                                     \       consumeError(std::move(E));                                              \   }
end_define

begin_define
define|#
directive|define
name|EXPECT_EXPECTED
parameter_list|(
name|Exp
parameter_list|)
define|\
value|{                                                                            \     auto E = Exp.takeError();                                                  \     EXPECT_FALSE(static_cast<bool>(E));                                        \     if (E) {                                                                   \       consumeError(std::move(E));                                              \       return;                                                                  \     }                                                                          \   }
end_define

begin_define
define|#
directive|define
name|EXPECT_EXPECTED_EQ
parameter_list|(
name|Val
parameter_list|,
name|Exp
parameter_list|)
define|\
value|{                                                                            \     auto Result = Exp;                                                         \     auto E = Result.takeError();                                               \     EXPECT_FALSE(static_cast<bool>(E));                                        \     if (E) {                                                                   \       consumeError(std::move(E));                                              \       return;                                                                  \     }                                                                          \     EXPECT_EQ(Val, *Result);                                                   \   }
end_define

begin_define
define|#
directive|define
name|EXPECT_UNEXPECTED
parameter_list|(
name|Exp
parameter_list|)
define|\
value|{                                                                            \     auto E = Exp.takeError();                                                  \     EXPECT_TRUE(static_cast<bool>(E));                                         \     if (E) {                                                                   \       consumeError(std::move(E));                                              \       return;                                                                  \     }                                                                          \   }
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

