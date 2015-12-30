begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- FuzzerDFSan.h - Internal header for the Fuzzer -----------*- C++ -* ===//
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
comment|// DFSan interface.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_FUZZER_DFSAN_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_FUZZER_DFSAN_H
end_define

begin_define
define|#
directive|define
name|LLVM_FUZZER_SUPPORTS_DFSAN
value|0
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__has_include
argument_list|)
end_if

begin_if
if|#
directive|if
name|__has_include
argument_list|(
operator|<
name|sanitizer
operator|/
name|dfsan_interface
operator|.
name|h
operator|>
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|LLVM_FUZZER_SUPPORTS_DFSAN
end_undef

begin_define
define|#
directive|define
name|LLVM_FUZZER_SUPPORTS_DFSAN
value|1
end_define

begin_include
include|#
directive|include
file|<sanitizer/dfsan_interface.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __linux__
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined(__has_include)
end_comment

begin_if
if|#
directive|if
name|LLVM_FUZZER_SUPPORTS_DFSAN
end_if

begin_extern
extern|extern
literal|"C"
block|{
name|__attribute__
argument_list|(
argument|(weak)
argument_list|)
name|dfsan_label
name|dfsan_create_label
parameter_list|(
specifier|const
name|char
modifier|*
name|desc
parameter_list|,
name|void
modifier|*
name|userdata
parameter_list|)
function_decl|;
name|__attribute__
argument_list|(
argument|(weak)
argument_list|)
name|void
name|dfsan_set_label
parameter_list|(
name|dfsan_label
name|label
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
name|__attribute__
argument_list|(
argument|(weak)
argument_list|)
name|void
name|dfsan_add_label
parameter_list|(
name|dfsan_label
name|label
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
name|__attribute__
argument_list|(
argument|(weak)
argument_list|)
specifier|const
name|struct
name|dfsan_label_info
modifier|*
name|dfsan_get_label_info
parameter_list|(
name|dfsan_label
name|label
parameter_list|)
function_decl|;
name|__attribute__
argument_list|(
argument|(weak)
argument_list|)
name|dfsan_label
name|dfsan_read_label
parameter_list|(
specifier|const
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
block|}
end_extern

begin_comment
comment|// extern "C"
end_comment

begin_decl_stmt
name|namespace
name|fuzzer
block|{
specifier|static
name|bool
name|ReallyHaveDFSan
parameter_list|()
block|{
return|return
operator|&
name|dfsan_create_label
operator|!=
name|nullptr
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace fuzzer
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|// When compiling with a compiler which does not support dfsan,
end_comment

begin_comment
comment|// this code is still expected to build (but not necessary work).
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|dfsan_label
typedef|;
end_typedef

begin_struct
struct|struct
name|dfsan_label_info
block|{
name|dfsan_label
name|l1
decl_stmt|,
name|l2
decl_stmt|;
specifier|const
name|char
modifier|*
name|desc
decl_stmt|;
name|void
modifier|*
name|userdata
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|namespace
name|fuzzer
block|{
specifier|static
name|bool
name|ReallyHaveDFSan
parameter_list|()
block|{
return|return
name|false
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace fuzzer
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_FUZZER_DFSAN_H
end_comment

end_unit

