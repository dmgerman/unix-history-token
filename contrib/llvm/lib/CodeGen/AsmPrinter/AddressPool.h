begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/AddressPool.h - Dwarf Debug Framework -----*- C++ -*--===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_CODEGEN_ASMPRINTER_ADDRESSPOOL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_ASMPRINTER_ADDRESSPOOL_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCSection
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|AsmPrinter
decl_stmt|;
comment|// Collection of addresses for this unit and assorted labels.
comment|// A Symbol->unsigned mapping of addresses used by indirect
comment|// references.
name|class
name|AddressPool
block|{
struct|struct
name|AddressPoolEntry
block|{
name|unsigned
name|Number
decl_stmt|;
name|bool
name|TLS
decl_stmt|;
name|AddressPoolEntry
argument_list|(
argument|unsigned Number
argument_list|,
argument|bool TLS
argument_list|)
block|:
name|Number
argument_list|(
name|Number
argument_list|)
operator|,
name|TLS
argument_list|(
argument|TLS
argument_list|)
block|{}
block|}
struct|;
name|DenseMap
operator|<
specifier|const
name|MCSymbol
operator|*
operator|,
name|AddressPoolEntry
operator|>
name|Pool
expr_stmt|;
comment|/// Record whether the AddressPool has been queried for an address index since
comment|/// the last "resetUsedFlag" call. Used to implement type unit fallback - a
comment|/// type that references addresses cannot be placed in a type unit when using
comment|/// fission.
name|bool
name|HasBeenUsed
decl_stmt|;
name|public
label|:
name|AddressPool
argument_list|()
operator|:
name|HasBeenUsed
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// \brief Returns the index into the address pool with the given
comment|/// label/symbol.
name|unsigned
name|getIndex
argument_list|(
argument|const MCSymbol *Sym
argument_list|,
argument|bool TLS = false
argument_list|)
expr_stmt|;
name|void
name|emit
parameter_list|(
name|AsmPrinter
modifier|&
name|Asm
parameter_list|,
specifier|const
name|MCSection
modifier|*
name|AddrSection
parameter_list|)
function_decl|;
name|bool
name|isEmpty
parameter_list|()
block|{
return|return
name|Pool
operator|.
name|empty
argument_list|()
return|;
block|}
name|bool
name|hasBeenUsed
argument_list|()
specifier|const
block|{
return|return
name|HasBeenUsed
return|;
block|}
name|void
name|resetUsedFlag
parameter_list|()
block|{
name|HasBeenUsed
operator|=
name|false
expr_stmt|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

