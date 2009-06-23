begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- TargetSelect.h - Target Selection& Registration -------------------===//
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
comment|// This file provides utilities to make sure that certain classes of targets are
end_comment

begin_comment
comment|// linked into the main application executable, and initialize them as
end_comment

begin_comment
comment|// appropriate.
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
name|LLVM_TARGET_TARGETSELECT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETSELECT_H
end_define

begin_include
include|#
directive|include
file|"llvm/Config/config.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Declare all of the target-initialization functions that are available.
define|#
directive|define
name|LLVM_TARGET
parameter_list|(
name|TargetName
parameter_list|)
value|void Initialize##TargetName##Target();
include|#
directive|include
file|"llvm/Config/Targets.def"
comment|// Declare all of the available asm-printer initialization functions.
comment|// Declare all of the target-initialization functions.
define|#
directive|define
name|LLVM_ASM_PRINTER
parameter_list|(
name|TargetName
parameter_list|)
value|void Initialize##TargetName##AsmPrinter();
include|#
directive|include
file|"llvm/Config/AsmPrinters.def"
comment|/// InitializeAllTargets - The main program should call this function if it
comment|/// wants to link in all available targets that LLVM is configured to support.
specifier|inline
name|void
name|InitializeAllTargets
parameter_list|()
block|{
define|#
directive|define
name|LLVM_TARGET
parameter_list|(
name|TargetName
parameter_list|)
value|llvm::Initialize##TargetName##Target();
include|#
directive|include
file|"llvm/Config/Targets.def"
block|}
comment|/// InitializeAllAsmPrinters - The main program should call this function if
comment|/// it wants all asm printers that LLVM is configured to support.  This will
comment|/// cause them to be linked into its executable.
specifier|inline
name|void
name|InitializeAllAsmPrinters
parameter_list|()
block|{
define|#
directive|define
name|LLVM_ASM_PRINTER
parameter_list|(
name|TargetName
parameter_list|)
value|Initialize##TargetName##AsmPrinter();
include|#
directive|include
file|"llvm/Config/AsmPrinters.def"
block|}
comment|/// InitializeNativeTarget - The main program should call this function to
comment|/// initialize the native target corresponding to the host.  This is useful
comment|/// for JIT applications to ensure that the target gets linked in correctly.
specifier|inline
name|bool
name|InitializeNativeTarget
parameter_list|()
block|{
comment|// If we have a native target, initialize it to ensure it is linked in.
ifdef|#
directive|ifdef
name|LLVM_NATIVE_ARCH
define|#
directive|define
name|DoInit2
parameter_list|(
name|TARG
parameter_list|)
value|llvm::Initialize ## TARG ()
define|#
directive|define
name|DoInit
parameter_list|(
name|T
parameter_list|)
value|DoInit2(T)
name|DoInit
argument_list|(
name|LLVM_NATIVE_ARCH
argument_list|)
expr_stmt|;
return|return
name|false
return|;
undef|#
directive|undef
name|DoInit
undef|#
directive|undef
name|DoInit2
else|#
directive|else
return|return
name|true
return|;
endif|#
directive|endif
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

