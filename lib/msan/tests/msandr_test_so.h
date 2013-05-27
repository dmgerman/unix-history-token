begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- msandr_test_so.h ----------------------------------------*- C++ -*-===//
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
comment|// This file is a part of MemorySanitizer.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MemorySanitizer unit tests.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MSANDR_MSANDR_TEST_SO_H
end_ifndef

begin_define
define|#
directive|define
name|MSANDR_MSANDR_TEST_SO_H
end_define

begin_function_decl
name|void
name|dso_memfill
parameter_list|(
name|char
modifier|*
name|s
parameter_list|,
name|unsigned
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dso_callfn
parameter_list|(
name|int
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dso_callfn1
parameter_list|(
name|int
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|long
name|long
parameter_list|,
name|long
name|long
parameter_list|,
name|long
name|long
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//NOLINT
end_comment

begin_function_decl
name|int
name|dso_stack_store
parameter_list|(
name|void
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
parameter_list|,
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|break_optimization
parameter_list|(
name|void
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

