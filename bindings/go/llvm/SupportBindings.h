begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SupportBindings.h - Additional bindings for Support ------*- C++ -*-===//
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
comment|// This file defines additional C bindings for the Support component.
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
name|LLVM_BINDINGS_GO_LLVM_SUPPORTBINDINGS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_BINDINGS_GO_LLVM_SUPPORTBINDINGS_H
end_define

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
comment|// This function duplicates the LLVMLoadLibraryPermanently function in the
comment|// stable C API and adds an extra ErrMsg parameter to retrieve the error
comment|// message.
name|void
name|LLVMLoadLibraryPermanently2
parameter_list|(
specifier|const
name|char
modifier|*
name|Filename
parameter_list|,
name|char
modifier|*
modifier|*
name|ErrMsg
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

