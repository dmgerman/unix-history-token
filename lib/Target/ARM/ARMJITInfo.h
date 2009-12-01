begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ARMJITInfo.h - ARM implementation of the JIT interface  --*- C++ -*-===//
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
comment|// This file contains the declaration of the ARMJITInfo class.
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
name|ARMJITINFO_H
end_ifndef

begin_define
define|#
directive|define
name|ARMJITINFO_H
end_define

begin_include
include|#
directive|include
file|"ARMMachineFunctionInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineConstantPool.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineJumpTableInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetJITInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ARMTargetMachine
decl_stmt|;
name|class
name|ARMJITInfo
range|:
name|public
name|TargetJITInfo
block|{
comment|// ConstPoolId2AddrMap - A map from constant pool ids to the corresponding
comment|// CONSTPOOL_ENTRY addresses.
name|SmallVector
operator|<
name|intptr_t
block|,
literal|16
operator|>
name|ConstPoolId2AddrMap
block|;
comment|// JumpTableId2AddrMap - A map from inline jumptable ids to the
comment|// corresponding inline jump table bases.
name|SmallVector
operator|<
name|intptr_t
block|,
literal|16
operator|>
name|JumpTableId2AddrMap
block|;
comment|// PCLabelMap - A map from PC labels to addresses.
name|DenseMap
operator|<
name|unsigned
block|,
name|intptr_t
operator|>
name|PCLabelMap
block|;
comment|// Sym2IndirectSymMap - A map from symbol (GlobalValue and ExternalSymbol)
comment|// addresses to their indirect symbol addresses.
name|DenseMap
operator|<
name|void
operator|*
block|,
name|intptr_t
operator|>
name|Sym2IndirectSymMap
block|;
comment|// IsPIC - True if the relocation model is PIC. This is used to determine
comment|// how to codegen function stubs.
name|bool
name|IsPIC
block|;
name|public
operator|:
name|explicit
name|ARMJITInfo
argument_list|()
operator|:
name|IsPIC
argument_list|(
argument|false
argument_list|)
block|{
name|useGOT
operator|=
name|false
block|; }
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
block|;
comment|/// emitGlobalValueIndirectSym - Use the specified JITCodeEmitter object
comment|/// to emit an indirect symbol which contains the address of the specified
comment|/// ptr.
name|virtual
name|void
operator|*
name|emitGlobalValueIndirectSym
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|,
name|void
operator|*
name|ptr
argument_list|,
name|JITCodeEmitter
operator|&
name|JCE
argument_list|)
block|;
comment|// getStubLayout - Returns the size and alignment of the largest call stub
comment|// on ARM.
name|virtual
name|StubLayout
name|getStubLayout
argument_list|()
block|;
comment|/// emitFunctionStub - Use the specified JITCodeEmitter object to emit a
comment|/// small native function that simply calls the function at the specified
comment|/// address.
name|virtual
name|void
operator|*
name|emitFunctionStub
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|,
name|void
operator|*
name|Fn
argument_list|,
name|JITCodeEmitter
operator|&
name|JCE
argument_list|)
block|;
comment|/// getLazyResolverFunction - Expose the lazy resolver to the JIT.
name|virtual
name|LazyResolverFn
name|getLazyResolverFunction
argument_list|(
name|JITCompilerFn
argument_list|)
block|;
comment|/// relocate - Before the JIT can run a block of code that has been emitted,
comment|/// it must rewrite the code to contain the actual addresses of any
comment|/// referenced global symbols.
name|virtual
name|void
name|relocate
argument_list|(
argument|void *Function
argument_list|,
argument|MachineRelocation *MR
argument_list|,
argument|unsigned NumRelocs
argument_list|,
argument|unsigned char* GOTBase
argument_list|)
block|;
comment|/// hasCustomConstantPool - Allows a target to specify that constant
comment|/// pool address resolution is handled by the target.
name|virtual
name|bool
name|hasCustomConstantPool
argument_list|()
specifier|const
block|{
return|return
name|true
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
name|true
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
ifdef|#
directive|ifdef
name|__APPLE__
return|return
name|true
return|;
else|#
directive|else
return|return
name|false
return|;
endif|#
directive|endif
block|}
comment|/// Initialize - Initialize internal stage for the function being JITted.
comment|/// Resize constant pool ids to CONSTPOOL_ENTRY addresses map; resize
comment|/// jump table ids to jump table bases map; remember if codegen relocation
comment|/// model is PIC.
name|void
name|Initialize
parameter_list|(
specifier|const
name|MachineFunction
modifier|&
name|MF
parameter_list|,
name|bool
name|isPIC
parameter_list|)
block|{
specifier|const
name|ARMFunctionInfo
modifier|*
name|AFI
init|=
name|MF
operator|.
name|getInfo
operator|<
name|ARMFunctionInfo
operator|>
operator|(
operator|)
decl_stmt|;
name|ConstPoolId2AddrMap
operator|.
name|resize
argument_list|(
name|AFI
operator|->
name|getNumConstPoolEntries
argument_list|()
argument_list|)
expr_stmt|;
name|JumpTableId2AddrMap
operator|.
name|resize
argument_list|(
name|AFI
operator|->
name|getNumJumpTables
argument_list|()
argument_list|)
expr_stmt|;
name|IsPIC
operator|=
name|isPIC
expr_stmt|;
block|}
comment|/// getConstantPoolEntryAddr - The ARM target puts all constant
comment|/// pool entries into constant islands. This returns the address of the
comment|/// constant pool entry of the specified index.
name|intptr_t
name|getConstantPoolEntryAddr
argument_list|(
name|unsigned
name|CPI
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|CPI
operator|<
name|ConstPoolId2AddrMap
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|ConstPoolId2AddrMap
index|[
name|CPI
index|]
return|;
block|}
comment|/// addConstantPoolEntryAddr - Map a Constant Pool Index to the address
comment|/// where its associated value is stored. When relocations are processed,
comment|/// this value will be used to resolve references to the constant.
name|void
name|addConstantPoolEntryAddr
parameter_list|(
name|unsigned
name|CPI
parameter_list|,
name|intptr_t
name|Addr
parameter_list|)
block|{
name|assert
argument_list|(
name|CPI
operator|<
name|ConstPoolId2AddrMap
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|ConstPoolId2AddrMap
index|[
name|CPI
index|]
operator|=
name|Addr
expr_stmt|;
block|}
comment|/// getJumpTableBaseAddr - The ARM target inline all jump tables within
comment|/// text section of the function. This returns the address of the base of
comment|/// the jump table of the specified index.
name|intptr_t
name|getJumpTableBaseAddr
argument_list|(
name|unsigned
name|JTI
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|JTI
operator|<
name|JumpTableId2AddrMap
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|JumpTableId2AddrMap
index|[
name|JTI
index|]
return|;
block|}
comment|/// addJumpTableBaseAddr - Map a jump table index to the address where
comment|/// the corresponding inline jump table is emitted. When relocations are
comment|/// processed, this value will be used to resolve references to the
comment|/// jump table.
name|void
name|addJumpTableBaseAddr
parameter_list|(
name|unsigned
name|JTI
parameter_list|,
name|intptr_t
name|Addr
parameter_list|)
block|{
name|assert
argument_list|(
name|JTI
operator|<
name|JumpTableId2AddrMap
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|JumpTableId2AddrMap
index|[
name|JTI
index|]
operator|=
name|Addr
expr_stmt|;
block|}
comment|/// getPCLabelAddr - Retrieve the address of the PC label of the specified id.
name|intptr_t
name|getPCLabelAddr
argument_list|(
name|unsigned
name|Id
argument_list|)
decl|const
block|{
name|DenseMap
operator|<
name|unsigned
operator|,
name|intptr_t
operator|>
operator|::
name|const_iterator
name|I
operator|=
name|PCLabelMap
operator|.
name|find
argument_list|(
name|Id
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|I
operator|!=
name|PCLabelMap
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|I
operator|->
name|second
return|;
block|}
comment|/// addPCLabelAddr - Remember the address of the specified PC label.
name|void
name|addPCLabelAddr
parameter_list|(
name|unsigned
name|Id
parameter_list|,
name|intptr_t
name|Addr
parameter_list|)
block|{
name|PCLabelMap
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|Id
argument_list|,
name|Addr
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// getIndirectSymAddr - Retrieve the address of the indirect symbol of the
comment|/// specified symbol located at address. Returns 0 if the indirect symbol
comment|/// has not been emitted.
name|intptr_t
name|getIndirectSymAddr
argument_list|(
name|void
operator|*
name|Addr
argument_list|)
decl|const
block|{
name|DenseMap
operator|<
name|void
operator|*
operator|,
name|intptr_t
operator|>
operator|::
name|const_iterator
name|I
operator|=
name|Sym2IndirectSymMap
operator|.
name|find
argument_list|(
name|Addr
argument_list|)
expr_stmt|;
if|if
condition|(
name|I
operator|!=
name|Sym2IndirectSymMap
operator|.
name|end
argument_list|()
condition|)
return|return
name|I
operator|->
name|second
return|;
return|return
literal|0
return|;
block|}
comment|/// addIndirectSymAddr - Add a mapping from address of an emitted symbol to
comment|/// its indirect symbol address.
name|void
name|addIndirectSymAddr
parameter_list|(
name|void
modifier|*
name|SymAddr
parameter_list|,
name|intptr_t
name|IndSymAddr
parameter_list|)
block|{
name|Sym2IndirectSymMap
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|SymAddr
argument_list|,
name|IndSymAddr
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|private
label|:
comment|/// resolveRelocDestAddr - Resolve the resulting address of the relocation
comment|/// if it's not already solved. Constantpool entries must be resolved by
comment|/// ARM target.
name|intptr_t
name|resolveRelocDestAddr
argument_list|(
name|MachineRelocation
operator|*
name|MR
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

