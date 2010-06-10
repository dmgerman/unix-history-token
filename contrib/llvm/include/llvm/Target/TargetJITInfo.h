begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Target/TargetJITInfo.h - Target Information for JIT ------*- C++ -*-===//
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
comment|// This file exposes an abstract interface used by the Just-In-Time code
end_comment

begin_comment
comment|// generator to perform target-specific activities, such as emitting stubs.  If
end_comment

begin_comment
comment|// a TargetMachine supports JIT code generation, it should provide one of these
end_comment

begin_comment
comment|// objects through the getJITInfo() method.
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
name|LLVM_TARGET_TARGETJITINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETJITINFO_H
end_define

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
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
name|JITCodeEmitter
decl_stmt|;
name|class
name|MachineRelocation
decl_stmt|;
comment|/// TargetJITInfo - Target specific information required by the Just-In-Time
comment|/// code generator.
name|class
name|TargetJITInfo
block|{
name|public
label|:
name|virtual
operator|~
name|TargetJITInfo
argument_list|()
block|{}
comment|/// replaceMachineCodeForFunction - Make it so that calling the function
comment|/// whose machine code is at OLD turns into a call to NEW, perhaps by
comment|/// overwriting OLD with a branch to NEW.  This is used for self-modifying
comment|/// code.
comment|///
name|virtual
name|void
name|replaceMachineCodeForFunction
argument_list|(
name|void
operator|*
name|Old
argument_list|,
name|void
operator|*
name|New
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// emitGlobalValueIndirectSym - Use the specified JITCodeEmitter object
comment|/// to emit an indirect symbol which contains the address of the specified
comment|/// ptr.
name|virtual
name|void
modifier|*
name|emitGlobalValueIndirectSym
parameter_list|(
specifier|const
name|GlobalValue
modifier|*
name|GV
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|JITCodeEmitter
modifier|&
name|JCE
parameter_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"This target doesn't implement emitGlobalValueIndirectSym!"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|/// Records the required size and alignment for a call stub in bytes.
struct|struct
name|StubLayout
block|{
name|size_t
name|Size
decl_stmt|;
name|size_t
name|Alignment
decl_stmt|;
block|}
struct|;
comment|/// Returns the maximum size and alignment for a call stub on this target.
name|virtual
name|StubLayout
name|getStubLayout
parameter_list|()
block|{
name|llvm_unreachable
argument_list|(
literal|"This target doesn't implement getStubLayout!"
argument_list|)
expr_stmt|;
name|StubLayout
name|Result
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
return|return
name|Result
return|;
block|}
comment|/// emitFunctionStub - Use the specified JITCodeEmitter object to emit a
comment|/// small native function that simply calls the function at the specified
comment|/// address.  The JITCodeEmitter must already have storage allocated for the
comment|/// stub.  Return the address of the resultant function, which may have been
comment|/// aligned from the address the JCE was set up to emit at.
name|virtual
name|void
modifier|*
name|emitFunctionStub
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|,
name|void
modifier|*
name|Target
parameter_list|,
name|JITCodeEmitter
modifier|&
name|JCE
parameter_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"This target doesn't implement emitFunctionStub!"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|/// getPICJumpTableEntry - Returns the value of the jumptable entry for the
comment|/// specific basic block.
name|virtual
name|uintptr_t
name|getPICJumpTableEntry
parameter_list|(
name|uintptr_t
name|BB
parameter_list|,
name|uintptr_t
name|JTBase
parameter_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"This target doesn't implement getPICJumpTableEntry!"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|/// LazyResolverFn - This typedef is used to represent the function that
comment|/// unresolved call points should invoke.  This is a target specific
comment|/// function that knows how to walk the stack and find out which stub the
comment|/// call is coming from.
typedef|typedef
name|void
function_decl|(
modifier|*
name|LazyResolverFn
function_decl|)
parameter_list|()
function_decl|;
comment|/// JITCompilerFn - This typedef is used to represent the JIT function that
comment|/// lazily compiles the function corresponding to a stub.  The JIT keeps
comment|/// track of the mapping between stubs and LLVM Functions, the target
comment|/// provides the ability to figure out the address of a stub that is called
comment|/// by the LazyResolverFn.
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|JITCompilerFn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/// getLazyResolverFunction - This method is used to initialize the JIT,
comment|/// giving the target the function that should be used to compile a
comment|/// function, and giving the JIT the target function used to do the lazy
comment|/// resolving.
name|virtual
name|LazyResolverFn
name|getLazyResolverFunction
parameter_list|(
name|JITCompilerFn
parameter_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"Not implemented for this target!"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|/// relocate - Before the JIT can run a block of code that has been emitted,
comment|/// it must rewrite the code to contain the actual addresses of any
comment|/// referenced global symbols.
name|virtual
name|void
name|relocate
parameter_list|(
name|void
modifier|*
name|Function
parameter_list|,
name|MachineRelocation
modifier|*
name|MR
parameter_list|,
name|unsigned
name|NumRelocs
parameter_list|,
name|unsigned
name|char
modifier|*
name|GOTBase
parameter_list|)
block|{
name|assert
argument_list|(
name|NumRelocs
operator|==
literal|0
operator|&&
literal|"This target does not have relocations!"
argument_list|)
expr_stmt|;
block|}
comment|/// allocateThreadLocalMemory - Each target has its own way of
comment|/// handling thread local variables. This method returns a value only
comment|/// meaningful to the target.
name|virtual
name|char
modifier|*
name|allocateThreadLocalMemory
parameter_list|(
name|size_t
name|size
parameter_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"This target does not implement thread local storage!"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|/// needsGOT - Allows a target to specify that it would like the
comment|/// JIT to manage a GOT for it.
name|bool
name|needsGOT
argument_list|()
specifier|const
block|{
return|return
name|useGOT
return|;
block|}
comment|/// hasCustomConstantPool - Allows a target to specify that constant
comment|/// pool address resolution is handled by the target.
name|virtual
name|bool
name|hasCustomConstantPool
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// hasCustomJumpTables - Allows a target to specify that jumptables
comment|/// are emitted by the target.
name|virtual
name|bool
name|hasCustomJumpTables
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// allocateSeparateGVMemory - If true, globals should be placed in
comment|/// separately allocated heap memory rather than in the same
comment|/// code memory allocated by JITCodeEmitter.
name|virtual
name|bool
name|allocateSeparateGVMemory
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|protected
label|:
name|bool
name|useGOT
decl_stmt|;
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

