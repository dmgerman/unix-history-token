begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/MachineModuleInfoImpls.h -------------------*- C++ -*-===//
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
comment|// This file defines object-file format specific implementations of
end_comment

begin_comment
comment|// MachineModuleInfoImpl.
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
name|LLVM_CODEGEN_MACHINEMODULEINFOIMPLS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINEMODULEINFOIMPLS_H
end_define

begin_include
include|#
directive|include
file|"llvm/BinaryFormat/Wasm.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineModuleInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ValueTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCSymbol
decl_stmt|;
comment|/// MachineModuleInfoMachO - This is a MachineModuleInfoImpl implementation
comment|/// for MachO targets.
name|class
name|MachineModuleInfoMachO
range|:
name|public
name|MachineModuleInfoImpl
block|{
comment|/// GVStubs - Darwin '$non_lazy_ptr' stubs.  The key is something like
comment|/// "Lfoo$non_lazy_ptr", the value is something like "_foo". The extra bit
comment|/// is true if this GV is external.
name|DenseMap
operator|<
name|MCSymbol
operator|*
block|,
name|StubValueTy
operator|>
name|GVStubs
block|;
comment|/// ThreadLocalGVStubs - Darwin '$non_lazy_ptr' stubs.  The key is something
comment|/// like "Lfoo$non_lazy_ptr", the value is something like "_foo". The extra
comment|/// bit is true if this GV is external.
name|DenseMap
operator|<
name|MCSymbol
operator|*
block|,
name|StubValueTy
operator|>
name|ThreadLocalGVStubs
block|;
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|// Out of line virtual method.
name|public
operator|:
name|MachineModuleInfoMachO
argument_list|(
argument|const MachineModuleInfo&
argument_list|)
block|{}
name|StubValueTy
operator|&
name|getGVStubEntry
argument_list|(
argument|MCSymbol *Sym
argument_list|)
block|{
name|assert
argument_list|(
name|Sym
operator|&&
literal|"Key cannot be null"
argument_list|)
block|;
return|return
name|GVStubs
index|[
name|Sym
index|]
return|;
block|}
name|StubValueTy
operator|&
name|getThreadLocalGVStubEntry
argument_list|(
argument|MCSymbol *Sym
argument_list|)
block|{
name|assert
argument_list|(
name|Sym
operator|&&
literal|"Key cannot be null"
argument_list|)
block|;
return|return
name|ThreadLocalGVStubs
index|[
name|Sym
index|]
return|;
block|}
comment|/// Accessor methods to return the set of stubs in sorted order.
name|SymbolListTy
name|GetGVStubList
argument_list|()
block|{
return|return
name|getSortedStubs
argument_list|(
name|GVStubs
argument_list|)
return|;
block|}
name|SymbolListTy
name|GetThreadLocalGVStubList
argument_list|()
block|{
return|return
name|getSortedStubs
argument_list|(
name|ThreadLocalGVStubs
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// MachineModuleInfoELF - This is a MachineModuleInfoImpl implementation
comment|/// for ELF targets.
name|class
name|MachineModuleInfoELF
operator|:
name|public
name|MachineModuleInfoImpl
block|{
comment|/// GVStubs - These stubs are used to materialize global addresses in PIC
comment|/// mode.
name|DenseMap
operator|<
name|MCSymbol
operator|*
block|,
name|StubValueTy
operator|>
name|GVStubs
block|;
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|// Out of line virtual method.
name|public
operator|:
name|MachineModuleInfoELF
argument_list|(
argument|const MachineModuleInfo&
argument_list|)
block|{}
name|StubValueTy
operator|&
name|getGVStubEntry
argument_list|(
argument|MCSymbol *Sym
argument_list|)
block|{
name|assert
argument_list|(
name|Sym
operator|&&
literal|"Key cannot be null"
argument_list|)
block|;
return|return
name|GVStubs
index|[
name|Sym
index|]
return|;
block|}
comment|/// Accessor methods to return the set of stubs in sorted order.
name|SymbolListTy
name|GetGVStubList
argument_list|()
block|{
return|return
name|getSortedStubs
argument_list|(
name|GVStubs
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// MachineModuleInfoWasm - This is a MachineModuleInfoImpl implementation
comment|/// for Wasm targets.
name|class
name|MachineModuleInfoWasm
operator|:
name|public
name|MachineModuleInfoImpl
block|{
comment|/// WebAssembly global variables defined by CodeGen.
name|std
operator|::
name|vector
operator|<
name|wasm
operator|::
name|Global
operator|>
name|Globals
block|;
comment|/// The WebAssembly global variable which is the stack pointer.
name|unsigned
name|StackPointerGlobal
block|;
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|// Out of line virtual method.
name|public
operator|:
name|MachineModuleInfoWasm
argument_list|(
specifier|const
name|MachineModuleInfo
operator|&
argument_list|)
operator|:
name|StackPointerGlobal
argument_list|(
argument|-
literal|1U
argument_list|)
block|{}
name|void
name|addGlobal
argument_list|(
argument|const wasm::Global&G
argument_list|)
block|{
name|Globals
operator|.
name|push_back
argument_list|(
name|G
argument_list|)
block|; }
specifier|const
name|std
operator|::
name|vector
operator|<
name|wasm
operator|::
name|Global
operator|>
operator|&
name|getGlobals
argument_list|()
specifier|const
block|{
return|return
name|Globals
return|;
block|}
name|bool
name|hasStackPointerGlobal
argument_list|()
specifier|const
block|{
return|return
name|StackPointerGlobal
operator|!=
operator|-
literal|1U
return|;
block|}
name|unsigned
name|getStackPointerGlobal
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|hasStackPointerGlobal
argument_list|()
operator|&&
literal|"Stack ptr global hasn't been set"
argument_list|)
block|;
return|return
name|StackPointerGlobal
return|;
block|}
name|void
name|setStackPointerGlobal
argument_list|(
argument|unsigned Global
argument_list|)
block|{
name|StackPointerGlobal
operator|=
name|Global
block|; }
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

