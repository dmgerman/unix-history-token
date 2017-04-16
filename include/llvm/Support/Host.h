begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/Host.h - Host machine characteristics --------*- C++ -*-===//
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
comment|// Methods for querying the nature of the host machine.
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
name|LLVM_SUPPORT_HOST_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_HOST_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNU__
argument_list|)
operator|||
name|defined
argument_list|(
name|__HAIKU__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<endian.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_AIX
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<sys/machine.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BYTE_ORDER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|LLVM_ON_WIN32
argument_list|)
end_if

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
if|#
directive|if
name|defined
argument_list|(
name|BYTE_ORDER
argument_list|)
operator|&&
name|defined
argument_list|(
name|BIG_ENDIAN
argument_list|)
operator|&&
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|constexpr
name|bool
name|IsBigEndianHost
init|=
name|true
decl_stmt|;
else|#
directive|else
name|constexpr
name|bool
name|IsBigEndianHost
init|=
name|false
decl_stmt|;
endif|#
directive|endif
specifier|static
specifier|const
name|bool
name|IsLittleEndianHost
init|=
operator|!
name|IsBigEndianHost
decl_stmt|;
comment|/// getDefaultTargetTriple() - Return the default target triple the compiler
comment|/// has been configured to produce code for.
comment|///
comment|/// The target triple is a string in the format of:
comment|///   CPU_TYPE-VENDOR-OPERATING_SYSTEM
comment|/// or
comment|///   CPU_TYPE-VENDOR-KERNEL-OPERATING_SYSTEM
name|std
operator|::
name|string
name|getDefaultTargetTriple
argument_list|()
expr_stmt|;
comment|/// getProcessTriple() - Return an appropriate target triple for generating
comment|/// code to be loaded into the current process, e.g. when using the JIT.
name|std
operator|::
name|string
name|getProcessTriple
argument_list|()
expr_stmt|;
comment|/// getHostCPUName - Get the LLVM name for the host CPU. The particular format
comment|/// of the name is target dependent, and suitable for passing as -mcpu to the
comment|/// target which matches the host.
comment|///
comment|/// \return - The host CPU name, or empty if the CPU could not be determined.
name|StringRef
name|getHostCPUName
parameter_list|()
function_decl|;
comment|/// getHostCPUFeatures - Get the LLVM names for the host CPU features.
comment|/// The particular format of the names are target dependent, and suitable for
comment|/// passing as -mattr to the target which matches the host.
comment|///
comment|/// \param Features - A string mapping feature names to either
comment|/// true (if enabled) or false (if disabled). This routine makes no guarantees
comment|/// about exactly which features may appear in this map, except that they are
comment|/// all valid LLVM feature names.
comment|///
comment|/// \return - True on success.
name|bool
name|getHostCPUFeatures
argument_list|(
name|StringMap
operator|<
name|bool
operator|>
operator|&
name|Features
argument_list|)
decl_stmt|;
comment|/// Get the number of physical cores (as opposed to logical cores returned
comment|/// from thread::hardware_concurrency(), which includes hyperthreads).
comment|/// Returns -1 if unknown for the current host system.
name|int
name|getHostNumPhysicalCores
parameter_list|()
function_decl|;
name|namespace
name|detail
block|{
comment|/// Helper functions to extract HostCPUName from /proc/cpuinfo on linux.
name|StringRef
name|getHostCPUNameForPowerPC
parameter_list|(
specifier|const
name|StringRef
modifier|&
name|ProcCpuinfoContent
parameter_list|)
function_decl|;
name|StringRef
name|getHostCPUNameForARM
parameter_list|(
specifier|const
name|StringRef
modifier|&
name|ProcCpuinfoContent
parameter_list|)
function_decl|;
name|StringRef
name|getHostCPUNameForS390x
parameter_list|(
specifier|const
name|StringRef
modifier|&
name|ProcCpuinfoContent
parameter_list|)
function_decl|;
block|}
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

