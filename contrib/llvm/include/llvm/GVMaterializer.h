begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/GVMaterializer.h - Interface for GV materializers --*- C++ -*-===//
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
comment|// This file provides an abstract interface for loading a module from some
end_comment

begin_comment
comment|// place.  This interface allows incremental or random access loading of
end_comment

begin_comment
comment|// functions from the file.  This is useful for applications like JIT compilers
end_comment

begin_comment
comment|// or interprocedural optimizers that do not need the entire program in memory
end_comment

begin_comment
comment|// at the same time.
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
name|LLVM_GVMATERIALIZER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_GVMATERIALIZER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/system_error.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Function
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|GVMaterializer
block|{
name|protected
label|:
name|GVMaterializer
argument_list|()
block|{}
name|public
label|:
name|virtual
operator|~
name|GVMaterializer
argument_list|()
expr_stmt|;
comment|/// isMaterializable - True if GV can be materialized from whatever backing
comment|/// store this GVMaterializer uses and has not been materialized yet.
name|virtual
name|bool
name|isMaterializable
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// isDematerializable - True if GV has been materialized and can be
comment|/// dematerialized back to whatever backing store this GVMaterializer uses.
name|virtual
name|bool
name|isDematerializable
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// Materialize - make sure the given GlobalValue is fully read.
comment|///
name|virtual
name|error_code
name|Materialize
parameter_list|(
name|GlobalValue
modifier|*
name|GV
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Dematerialize - If the given GlobalValue is read in, and if the
comment|/// GVMaterializer supports it, release the memory for the GV, and set it up
comment|/// to be materialized lazily.  If the Materializer doesn't support this
comment|/// capability, this method is a noop.
comment|///
name|virtual
name|void
name|Dematerialize
parameter_list|(
name|GlobalValue
modifier|*
parameter_list|)
block|{}
comment|/// MaterializeModule - make sure the entire Module has been completely read.
comment|///
name|virtual
name|error_code
name|MaterializeModule
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
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

