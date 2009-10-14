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
file|"llvm/CodeGen/MachineModuleInfo.h"
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
comment|/// FnStubs - Darwin '$stub' stubs.  The key is something like "Lfoo$stub",
comment|/// the value is something like "_foo".
name|DenseMap
operator|<
specifier|const
name|MCSymbol
operator|*
block|,
specifier|const
name|MCSymbol
operator|*
operator|>
name|FnStubs
block|;
comment|/// GVStubs - Darwin '$non_lazy_ptr' stubs.  The key is something like
comment|/// "Lfoo$non_lazy_ptr", the value is something like "_foo".
name|DenseMap
operator|<
specifier|const
name|MCSymbol
operator|*
block|,
specifier|const
name|MCSymbol
operator|*
operator|>
name|GVStubs
block|;
comment|/// HiddenGVStubs - Darwin '$non_lazy_ptr' stubs.  The key is something like
comment|/// "Lfoo$non_lazy_ptr", the value is something like "_foo".  Unlike GVStubs
comment|/// these are for things with hidden visibility.
name|DenseMap
operator|<
specifier|const
name|MCSymbol
operator|*
block|,
specifier|const
name|MCSymbol
operator|*
operator|>
name|HiddenGVStubs
block|;
name|virtual
name|void
name|Anchor
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
specifier|const
name|MCSymbol
operator|*
operator|&
name|getFnStubEntry
argument_list|(
argument|const MCSymbol *Sym
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
name|FnStubs
index|[
name|Sym
index|]
return|;
block|}
specifier|const
name|MCSymbol
operator|*
operator|&
name|getGVStubEntry
argument_list|(
argument|const MCSymbol *Sym
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
specifier|const
name|MCSymbol
operator|*
operator|&
name|getHiddenGVStubEntry
argument_list|(
argument|const MCSymbol *Sym
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
name|HiddenGVStubs
index|[
name|Sym
index|]
return|;
block|}
comment|/// Accessor methods to return the set of stubs in sorted order.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|MCSymbol
operator|*
operator|,
specifier|const
name|MCSymbol
operator|*
operator|>
expr|>
name|SymbolListTy
expr_stmt|;
name|SymbolListTy
name|GetFnStubList
argument_list|()
specifier|const
block|{
return|return
name|GetSortedStubs
argument_list|(
name|FnStubs
argument_list|)
return|;
block|}
name|SymbolListTy
name|GetGVStubList
argument_list|()
specifier|const
block|{
return|return
name|GetSortedStubs
argument_list|(
name|GVStubs
argument_list|)
return|;
block|}
name|SymbolListTy
name|GetHiddenGVStubList
argument_list|()
specifier|const
block|{
return|return
name|GetSortedStubs
argument_list|(
name|HiddenGVStubs
argument_list|)
return|;
block|}
name|private
operator|:
specifier|static
name|SymbolListTy
name|GetSortedStubs
argument_list|(
specifier|const
name|DenseMap
operator|<
specifier|const
name|MCSymbol
operator|*
argument_list|,
specifier|const
name|MCSymbol
operator|*
operator|>
operator|&
name|Map
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

