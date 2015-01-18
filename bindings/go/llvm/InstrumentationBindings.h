begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- InstrumentationBindings.h - instrumentation bindings -----*- C++ -*-===//
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
comment|// This file defines C bindings for the Transforms/Instrumentation component.
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
name|LLVM_BINDINGS_GO_LLVM_INSTRUMENTATIONBINDINGS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_BINDINGS_GO_LLVM_INSTRUMENTATIONBINDINGS_H
end_define

begin_include
include|#
directive|include
file|"llvm-c/Core.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|// FIXME: These bindings shouldn't be Go-specific and should eventually move to
comment|// a (somewhat) less stable collection of C APIs for use in creating bindings of
comment|// LLVM in other languages.
name|void
name|LLVMAddAddressSanitizerFunctionPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
name|void
name|LLVMAddAddressSanitizerModulePass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
name|void
name|LLVMAddThreadSanitizerPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
name|void
name|LLVMAddMemorySanitizerPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
name|void
name|LLVMAddDataFlowSanitizerPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|,
specifier|const
name|char
modifier|*
name|ABIListFile
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

