begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCJITTestBase.h - Common base class for MCJIT Unit tests  ----------===//
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
comment|// This class implements functionality shared by both MCJIT C API tests, and
end_comment

begin_comment
comment|// the C++ API tests.
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
name|LLVM_UNITTESTS_EXECUTIONENGINE_MCJIT_MCJITTESTAPICOMMON_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_UNITTESTS_EXECUTIONENGINE_MCJIT_MCJITTESTAPICOMMON_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Host.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/TargetSelect.h"
end_include

begin_comment
comment|// Used to skip tests on unsupported architectures and operating systems.
end_comment

begin_comment
comment|// To skip a test, add this macro at the top of a test-case in a suite that
end_comment

begin_comment
comment|// inherits from MCJITTestBase. See MCJITTest.cpp for examples.
end_comment

begin_define
define|#
directive|define
name|SKIP_UNSUPPORTED_PLATFORM
define|\
value|do \     if (!ArchSupportsMCJIT() || !OSSupportsMCJIT()) \       return; \   while(0)
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCJITTestAPICommon
block|{
name|protected
label|:
name|MCJITTestAPICommon
argument_list|()
operator|:
name|HostTriple
argument_list|(
argument|sys::getProcessTriple()
argument_list|)
block|{
name|InitializeNativeTarget
argument_list|()
block|;
name|InitializeNativeTargetAsmPrinter
argument_list|()
block|;
ifdef|#
directive|ifdef
name|LLVM_ON_WIN32
comment|// On Windows, generate ELF objects by specifying "-elf" in triple
name|HostTriple
operator|+=
literal|"-elf"
block|;
endif|#
directive|endif
comment|// LLVM_ON_WIN32
name|HostTriple
operator|=
name|Triple
operator|::
name|normalize
argument_list|(
name|HostTriple
argument_list|)
block|;   }
comment|/// Returns true if the host architecture is known to support MCJIT
name|bool
name|ArchSupportsMCJIT
argument_list|()
block|{
name|Triple
name|Host
argument_list|(
name|HostTriple
argument_list|)
block|;
comment|// If ARCH is not supported, bail
if|if
condition|(
name|std
operator|::
name|find
argument_list|(
name|SupportedArchs
operator|.
name|begin
argument_list|()
argument_list|,
name|SupportedArchs
operator|.
name|end
argument_list|()
argument_list|,
name|Host
operator|.
name|getArch
argument_list|()
argument_list|)
operator|==
name|SupportedArchs
operator|.
name|end
argument_list|()
condition|)
return|return
name|false
return|;
comment|// If ARCH is supported and has no specific sub-arch support
if|if
condition|(
name|std
operator|::
name|find
argument_list|(
name|HasSubArchs
operator|.
name|begin
argument_list|()
argument_list|,
name|HasSubArchs
operator|.
name|end
argument_list|()
argument_list|,
name|Host
operator|.
name|getArch
argument_list|()
argument_list|)
operator|==
name|HasSubArchs
operator|.
name|end
argument_list|()
condition|)
return|return
name|true
return|;
comment|// If ARCH has sub-arch support, find it
name|SmallVectorImpl
operator|<
name|std
operator|::
name|string
operator|>
operator|::
name|const_iterator
name|I
operator|=
name|SupportedSubArchs
operator|.
name|begin
argument_list|()
expr_stmt|;
for|for
control|(
init|;
name|I
operator|!=
name|SupportedSubArchs
operator|.
name|end
argument_list|()
condition|;
operator|++
name|I
control|)
if|if
condition|(
name|Host
operator|.
name|getArchName
argument_list|()
operator|.
name|startswith
argument_list|(
name|I
operator|->
name|c_str
argument_list|()
argument_list|)
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
comment|/// Returns true if the host OS is known to support MCJIT
name|bool
name|OSSupportsMCJIT
parameter_list|()
block|{
name|Triple
name|Host
argument_list|(
name|HostTriple
argument_list|)
decl_stmt|;
if|if
condition|(
name|std
operator|::
name|find
argument_list|(
name|UnsupportedEnvironments
operator|.
name|begin
argument_list|()
argument_list|,
name|UnsupportedEnvironments
operator|.
name|end
argument_list|()
argument_list|,
name|Host
operator|.
name|getEnvironment
argument_list|()
argument_list|)
operator|!=
name|UnsupportedEnvironments
operator|.
name|end
argument_list|()
condition|)
return|return
name|false
return|;
if|if
condition|(
name|std
operator|::
name|find
argument_list|(
name|UnsupportedOSs
operator|.
name|begin
argument_list|()
argument_list|,
name|UnsupportedOSs
operator|.
name|end
argument_list|()
argument_list|,
name|Host
operator|.
name|getOS
argument_list|()
argument_list|)
operator|==
name|UnsupportedOSs
operator|.
name|end
argument_list|()
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
name|std
operator|::
name|string
name|HostTriple
expr_stmt|;
name|SmallVector
operator|<
name|Triple
operator|::
name|ArchType
operator|,
literal|4
operator|>
name|SupportedArchs
expr_stmt|;
name|SmallVector
operator|<
name|Triple
operator|::
name|ArchType
operator|,
literal|1
operator|>
name|HasSubArchs
expr_stmt|;
name|SmallVector
operator|<
name|std
operator|::
name|string
operator|,
literal|2
operator|>
name|SupportedSubArchs
expr_stmt|;
comment|// We need to own the memory
name|SmallVector
operator|<
name|Triple
operator|::
name|OSType
operator|,
literal|4
operator|>
name|UnsupportedOSs
expr_stmt|;
name|SmallVector
operator|<
name|Triple
operator|::
name|EnvironmentType
operator|,
literal|1
operator|>
name|UnsupportedEnvironments
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

