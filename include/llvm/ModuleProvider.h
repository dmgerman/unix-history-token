begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/ModuleProvider.h - Interface for module providers --*- C++ -*-===//
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
name|MODULEPROVIDER_H
end_ifndef

begin_define
define|#
directive|define
name|MODULEPROVIDER_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Function
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|ModuleProvider
block|{
name|protected
label|:
name|Module
modifier|*
name|TheModule
decl_stmt|;
name|ModuleProvider
argument_list|()
expr_stmt|;
name|public
label|:
name|virtual
operator|~
name|ModuleProvider
argument_list|()
expr_stmt|;
comment|/// getModule - returns the module this provider is encapsulating.
comment|///
name|Module
modifier|*
name|getModule
parameter_list|()
block|{
return|return
name|TheModule
return|;
block|}
comment|/// materializeFunction - make sure the given function is fully read.  If the
comment|/// module is corrupt, this returns true and fills in the optional string
comment|/// with information about the problem.  If successful, this returns false.
comment|///
name|virtual
name|bool
name|materializeFunction
argument_list|(
name|Function
operator|*
name|F
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrInfo
operator|=
literal|0
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// dematerializeFunction - If the given function is read in, and if the
comment|/// module provider supports it, release the memory for the function, and set
comment|/// it up to be materialized lazily.  If the provider doesn't support this
comment|/// capability, this method is a noop.
comment|///
name|virtual
name|void
name|dematerializeFunction
parameter_list|(
name|Function
modifier|*
parameter_list|)
block|{}
comment|/// materializeModule - make sure the entire Module has been completely read.
comment|/// On error, return null and fill in the error string if specified.
comment|///
name|virtual
name|Module
modifier|*
name|materializeModule
argument_list|(
name|std
operator|::
name|string
operator|*
name|ErrInfo
operator|=
literal|0
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// releaseModule - no longer delete the Module* when provider is destroyed.
comment|/// On error, return null and fill in the error string if specified.
comment|///
name|virtual
name|Module
modifier|*
name|releaseModule
argument_list|(
name|std
operator|::
name|string
operator|*
name|ErrInfo
operator|=
literal|0
argument_list|)
block|{
comment|// Since we're losing control of this Module, we must hand it back complete
if|if
condition|(
operator|!
name|materializeModule
argument_list|(
name|ErrInfo
argument_list|)
condition|)
return|return
literal|0
return|;
name|Module
modifier|*
name|tempM
init|=
name|TheModule
decl_stmt|;
name|TheModule
operator|=
literal|0
expr_stmt|;
return|return
name|tempM
return|;
block|}
block|}
empty_stmt|;
comment|/// ExistingModuleProvider - Allow conversion from a fully materialized Module
comment|/// into a ModuleProvider, allowing code that expects a ModuleProvider to work
comment|/// if we just have a Module.  Note that the ModuleProvider takes ownership of
comment|/// the Module specified.
name|struct
name|ExistingModuleProvider
range|:
name|public
name|ModuleProvider
block|{
name|explicit
name|ExistingModuleProvider
argument_list|(
argument|Module *M
argument_list|)
block|{
name|TheModule
operator|=
name|M
block|;   }
name|bool
name|materializeFunction
argument_list|(
argument|Function *
argument_list|,
argument|std::string * =
literal|0
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|Module
operator|*
name|materializeModule
argument_list|(
argument|std::string * =
literal|0
argument_list|)
block|{
return|return
name|TheModule
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

