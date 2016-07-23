begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- FuzzerExtFunctions.h - Interface to external functions ---*- C++ -* ===//
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
comment|// Defines an interface to (possibly optional) functions.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_FUZZER_EXT_FUNCTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_FUZZER_EXT_FUNCTIONS_H
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_decl_stmt
name|namespace
name|fuzzer
block|{
struct|struct
name|ExternalFunctions
block|{
comment|// Initialize function pointers. Functions that are not available will be set
comment|// to nullptr.  Do not call this constructor  before ``main()`` has been
comment|// entered.
name|ExternalFunctions
argument_list|()
expr_stmt|;
define|#
directive|define
name|EXT_FUNC
parameter_list|(
name|NAME
parameter_list|,
name|RETURN_TYPE
parameter_list|,
name|FUNC_SIG
parameter_list|,
name|WARN
parameter_list|)
define|\
value|RETURN_TYPE(*NAME) FUNC_SIG = nullptr
include|#
directive|include
file|"FuzzerExtFunctions.def"
undef|#
directive|undef
name|EXT_FUNC
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// namespace fuzzer
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

