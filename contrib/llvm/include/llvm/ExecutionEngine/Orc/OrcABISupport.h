begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- OrcABISupport.h - ABI support code -----------------------*- C++ -*-===//
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
comment|// ABI specific code for Orc, e.g. callback assembly.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ABI classes should be part of the JIT *target* process, not the host
end_comment

begin_comment
comment|// process (except where you're doing hosted JITing and the two are one and the
end_comment

begin_comment
comment|// same).
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
name|LLVM_EXECUTIONENGINE_ORC_ORCABISUPPORT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_ORC_ORCABISUPPORT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/JITSymbol.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Memory.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|orc
block|{
comment|/// Generic ORC ABI support.
comment|///
comment|/// This class can be substituted as the target architecure support class for
comment|/// ORC templates that require one (e.g. IndirectStubsManagers). It does not
comment|/// support lazy JITing however, and any attempt to use that functionality
comment|/// will result in execution of an llvm_unreachable.
name|class
name|OrcGenericABI
block|{
name|public
label|:
specifier|static
specifier|const
name|unsigned
name|PointerSize
init|=
sizeof|sizeof
argument_list|(
name|uintptr_t
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|TrampolineSize
init|=
literal|1
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|ResolverCodeSize
init|=
literal|1
decl_stmt|;
name|using
name|JITReentryFn
init|=
name|JITTargetAddress
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
name|CallbackMgr
argument_list|,
name|void
operator|*
name|TrampolineId
argument_list|)
decl_stmt|;
specifier|static
name|void
name|writeResolverCode
parameter_list|(
name|uint8_t
modifier|*
name|ResolveMem
parameter_list|,
name|JITReentryFn
name|Reentry
parameter_list|,
name|void
modifier|*
name|CallbackMgr
parameter_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"writeResolverCode is not supported by the generic host "
literal|"support class"
argument_list|)
expr_stmt|;
block|}
specifier|static
name|void
name|writeTrampolines
parameter_list|(
name|uint8_t
modifier|*
name|TrampolineMem
parameter_list|,
name|void
modifier|*
name|ResolverAddr
parameter_list|,
name|unsigned
name|NumTrampolines
parameter_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"writeTrampolines is not supported by the generic host "
literal|"support class"
argument_list|)
expr_stmt|;
block|}
name|class
name|IndirectStubsInfo
block|{
name|public
label|:
specifier|const
specifier|static
name|unsigned
name|StubSize
init|=
literal|1
decl_stmt|;
name|unsigned
name|getNumStubs
argument_list|()
specifier|const
block|{
name|llvm_unreachable
argument_list|(
literal|"Not supported"
argument_list|)
block|; }
name|void
operator|*
name|getStub
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|{
name|llvm_unreachable
argument_list|(
literal|"Not supported"
argument_list|)
block|; }
name|void
operator|*
operator|*
name|getPtr
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|{
name|llvm_unreachable
argument_list|(
literal|"Not supported"
argument_list|)
block|; }
block|}
empty_stmt|;
specifier|static
name|Error
name|emitIndirectStubsBlock
parameter_list|(
name|IndirectStubsInfo
modifier|&
name|StubsInfo
parameter_list|,
name|unsigned
name|MinStubs
parameter_list|,
name|void
modifier|*
name|InitialPtrVal
parameter_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"emitIndirectStubsBlock is not supported by the generic "
literal|"host support class"
argument_list|)
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|/// @brief Provide information about stub blocks generated by the
comment|///        makeIndirectStubsBlock function.
name|template
operator|<
name|unsigned
name|StubSizeVal
operator|>
name|class
name|GenericIndirectStubsInfo
block|{
name|public
operator|:
specifier|const
specifier|static
name|unsigned
name|StubSize
operator|=
name|StubSizeVal
block|;
name|GenericIndirectStubsInfo
argument_list|()
operator|=
expr|default
block|;
name|GenericIndirectStubsInfo
argument_list|(
argument|unsigned NumStubs
argument_list|,
argument|sys::OwningMemoryBlock StubsMem
argument_list|)
operator|:
name|NumStubs
argument_list|(
name|NumStubs
argument_list|)
block|,
name|StubsMem
argument_list|(
argument|std::move(StubsMem)
argument_list|)
block|{}
name|GenericIndirectStubsInfo
argument_list|(
name|GenericIndirectStubsInfo
operator|&&
name|Other
argument_list|)
operator|:
name|NumStubs
argument_list|(
name|Other
operator|.
name|NumStubs
argument_list|)
block|,
name|StubsMem
argument_list|(
argument|std::move(Other.StubsMem)
argument_list|)
block|{
name|Other
operator|.
name|NumStubs
operator|=
literal|0
block|;   }
name|GenericIndirectStubsInfo
operator|&
name|operator
operator|=
operator|(
name|GenericIndirectStubsInfo
operator|&&
name|Other
operator|)
block|{
name|NumStubs
operator|=
name|Other
operator|.
name|NumStubs
block|;
name|Other
operator|.
name|NumStubs
operator|=
literal|0
block|;
name|StubsMem
operator|=
name|std
operator|::
name|move
argument_list|(
name|Other
operator|.
name|StubsMem
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// @brief Number of stubs in this block.
name|unsigned
name|getNumStubs
argument_list|()
specifier|const
block|{
return|return
name|NumStubs
return|;
block|}
comment|/// @brief Get a pointer to the stub at the given index, which must be in
comment|///        the range 0 .. getNumStubs() - 1.
name|void
operator|*
name|getStub
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|{
return|return
name|static_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|StubsMem
operator|.
name|base
argument_list|()
operator|)
operator|+
name|Idx
operator|*
name|StubSize
return|;
block|}
comment|/// @brief Get a pointer to the implementation-pointer at the given index,
comment|///        which must be in the range 0 .. getNumStubs() - 1.
name|void
operator|*
operator|*
name|getPtr
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|{
name|char
operator|*
name|PtrsBase
operator|=
name|static_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|StubsMem
operator|.
name|base
argument_list|()
operator|)
operator|+
name|NumStubs
operator|*
name|StubSize
block|;
return|return
name|reinterpret_cast
operator|<
name|void
operator|*
operator|*
operator|>
operator|(
name|PtrsBase
operator|)
operator|+
name|Idx
return|;
block|}
name|private
operator|:
name|unsigned
name|NumStubs
operator|=
literal|0
block|;
name|sys
operator|::
name|OwningMemoryBlock
name|StubsMem
block|; }
expr_stmt|;
name|class
name|OrcAArch64
block|{
name|public
label|:
specifier|static
specifier|const
name|unsigned
name|PointerSize
init|=
literal|8
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|TrampolineSize
init|=
literal|12
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|ResolverCodeSize
init|=
literal|0x120
decl_stmt|;
name|using
name|IndirectStubsInfo
init|=
name|GenericIndirectStubsInfo
operator|<
literal|8
operator|>
decl_stmt|;
name|using
name|JITReentryFn
init|=
name|JITTargetAddress
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
name|CallbackMgr
argument_list|,
name|void
operator|*
name|TrampolineId
argument_list|)
decl_stmt|;
comment|/// @brief Write the resolver code into the given memory. The user is be
comment|///        responsible for allocating the memory and setting permissions.
specifier|static
name|void
name|writeResolverCode
parameter_list|(
name|uint8_t
modifier|*
name|ResolveMem
parameter_list|,
name|JITReentryFn
name|Reentry
parameter_list|,
name|void
modifier|*
name|CallbackMgr
parameter_list|)
function_decl|;
comment|/// @brief Write the requsted number of trampolines into the given memory,
comment|///        which must be big enough to hold 1 pointer, plus NumTrampolines
comment|///        trampolines.
specifier|static
name|void
name|writeTrampolines
parameter_list|(
name|uint8_t
modifier|*
name|TrampolineMem
parameter_list|,
name|void
modifier|*
name|ResolverAddr
parameter_list|,
name|unsigned
name|NumTrampolines
parameter_list|)
function_decl|;
comment|/// @brief Emit at least MinStubs worth of indirect call stubs, rounded out to
comment|///        the nearest page size.
comment|///
comment|///   E.g. Asking for 4 stubs on x86-64, where stubs are 8-bytes, with 4k
comment|/// pages will return a block of 512 stubs (4096 / 8 = 512). Asking for 513
comment|/// will return a block of 1024 (2-pages worth).
specifier|static
name|Error
name|emitIndirectStubsBlock
parameter_list|(
name|IndirectStubsInfo
modifier|&
name|StubsInfo
parameter_list|,
name|unsigned
name|MinStubs
parameter_list|,
name|void
modifier|*
name|InitialPtrVal
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// @brief X86_64 code that's common to all ABIs.
comment|///
comment|/// X86_64 supports lazy JITing.
name|class
name|OrcX86_64_Base
block|{
name|public
label|:
specifier|static
specifier|const
name|unsigned
name|PointerSize
init|=
literal|8
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|TrampolineSize
init|=
literal|8
decl_stmt|;
name|using
name|IndirectStubsInfo
init|=
name|GenericIndirectStubsInfo
operator|<
literal|8
operator|>
decl_stmt|;
comment|/// @brief Write the requsted number of trampolines into the given memory,
comment|///        which must be big enough to hold 1 pointer, plus NumTrampolines
comment|///        trampolines.
specifier|static
name|void
name|writeTrampolines
parameter_list|(
name|uint8_t
modifier|*
name|TrampolineMem
parameter_list|,
name|void
modifier|*
name|ResolverAddr
parameter_list|,
name|unsigned
name|NumTrampolines
parameter_list|)
function_decl|;
comment|/// @brief Emit at least MinStubs worth of indirect call stubs, rounded out to
comment|///        the nearest page size.
comment|///
comment|///   E.g. Asking for 4 stubs on x86-64, where stubs are 8-bytes, with 4k
comment|/// pages will return a block of 512 stubs (4096 / 8 = 512). Asking for 513
comment|/// will return a block of 1024 (2-pages worth).
specifier|static
name|Error
name|emitIndirectStubsBlock
parameter_list|(
name|IndirectStubsInfo
modifier|&
name|StubsInfo
parameter_list|,
name|unsigned
name|MinStubs
parameter_list|,
name|void
modifier|*
name|InitialPtrVal
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// @brief X86_64 support for SysV ABI (Linux, MacOSX).
comment|///
comment|/// X86_64_SysV supports lazy JITing.
name|class
name|OrcX86_64_SysV
range|:
name|public
name|OrcX86_64_Base
block|{
name|public
operator|:
specifier|static
specifier|const
name|unsigned
name|ResolverCodeSize
operator|=
literal|0x6C
block|;
name|using
name|JITReentryFn
operator|=
name|JITTargetAddress
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
name|CallbackMgr
argument_list|,
name|void
operator|*
name|TrampolineId
argument_list|)
block|;
comment|/// @brief Write the resolver code into the given memory. The user is be
comment|///        responsible for allocating the memory and setting permissions.
specifier|static
name|void
name|writeResolverCode
argument_list|(
argument|uint8_t *ResolveMem
argument_list|,
argument|JITReentryFn Reentry
argument_list|,
argument|void *CallbackMgr
argument_list|)
block|; }
decl_stmt|;
comment|/// @brief X86_64 support for Win32.
comment|///
comment|/// X86_64_Win32 supports lazy JITing.
name|class
name|OrcX86_64_Win32
range|:
name|public
name|OrcX86_64_Base
block|{
name|public
operator|:
specifier|static
specifier|const
name|unsigned
name|ResolverCodeSize
operator|=
literal|0x74
block|;
name|using
name|JITReentryFn
operator|=
name|JITTargetAddress
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
name|CallbackMgr
argument_list|,
name|void
operator|*
name|TrampolineId
argument_list|)
block|;
comment|/// @brief Write the resolver code into the given memory. The user is be
comment|///        responsible for allocating the memory and setting permissions.
specifier|static
name|void
name|writeResolverCode
argument_list|(
argument|uint8_t *ResolveMem
argument_list|,
argument|JITReentryFn Reentry
argument_list|,
argument|void *CallbackMgr
argument_list|)
block|; }
decl_stmt|;
comment|/// @brief I386 support.
comment|///
comment|/// I386 supports lazy JITing.
name|class
name|OrcI386
block|{
name|public
label|:
specifier|static
specifier|const
name|unsigned
name|PointerSize
init|=
literal|4
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|TrampolineSize
init|=
literal|8
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|ResolverCodeSize
init|=
literal|0x4a
decl_stmt|;
name|using
name|IndirectStubsInfo
init|=
name|GenericIndirectStubsInfo
operator|<
literal|8
operator|>
decl_stmt|;
name|using
name|JITReentryFn
init|=
name|JITTargetAddress
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
name|CallbackMgr
argument_list|,
name|void
operator|*
name|TrampolineId
argument_list|)
decl_stmt|;
comment|/// @brief Write the resolver code into the given memory. The user is be
comment|///        responsible for allocating the memory and setting permissions.
specifier|static
name|void
name|writeResolverCode
parameter_list|(
name|uint8_t
modifier|*
name|ResolveMem
parameter_list|,
name|JITReentryFn
name|Reentry
parameter_list|,
name|void
modifier|*
name|CallbackMgr
parameter_list|)
function_decl|;
comment|/// @brief Write the requsted number of trampolines into the given memory,
comment|///        which must be big enough to hold 1 pointer, plus NumTrampolines
comment|///        trampolines.
specifier|static
name|void
name|writeTrampolines
parameter_list|(
name|uint8_t
modifier|*
name|TrampolineMem
parameter_list|,
name|void
modifier|*
name|ResolverAddr
parameter_list|,
name|unsigned
name|NumTrampolines
parameter_list|)
function_decl|;
comment|/// @brief Emit at least MinStubs worth of indirect call stubs, rounded out to
comment|///        the nearest page size.
comment|///
comment|///   E.g. Asking for 4 stubs on i386, where stubs are 8-bytes, with 4k
comment|/// pages will return a block of 512 stubs (4096 / 8 = 512). Asking for 513
comment|/// will return a block of 1024 (2-pages worth).
specifier|static
name|Error
name|emitIndirectStubsBlock
parameter_list|(
name|IndirectStubsInfo
modifier|&
name|StubsInfo
parameter_list|,
name|unsigned
name|MinStubs
parameter_list|,
name|void
modifier|*
name|InitialPtrVal
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
comment|// end namespace orc
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_EXECUTIONENGINE_ORC_ORCABISUPPORT_H
end_comment

end_unit

