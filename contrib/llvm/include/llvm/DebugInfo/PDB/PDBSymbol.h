begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PDBSymbol.h - base class for user-facing symbol types -----*- C++-*-===//
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
name|LLVM_DEBUGINFO_PDB_IPDBSYMBOL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_IPDBSYMBOL_H
end_define

begin_include
include|#
directive|include
file|"ConcreteSymbolEnumerator.h"
end_include

begin_include
include|#
directive|include
file|"IPDBRawSymbol.h"
end_include

begin_include
include|#
directive|include
file|"PDBExtras.h"
end_include

begin_include
include|#
directive|include
file|"PDBTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|<unordered_map>
end_include

begin_define
define|#
directive|define
name|FORWARD_SYMBOL_METHOD
parameter_list|(
name|MethodName
parameter_list|)
define|\
value|auto MethodName() const->decltype(RawSymbol->MethodName()) {                 \     return RawSymbol->MethodName();                                            \   }
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|IPDBRawSymbol
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
define|#
directive|define
name|DECLARE_PDB_SYMBOL_CONCRETE_TYPE
parameter_list|(
name|TagValue
parameter_list|)
define|\
value|static const PDB_SymType Tag = TagValue;                                     \   static bool classof(const PDBSymbol *S) { return S->getSymTag() == Tag; }
comment|/// PDBSymbol defines the base of the inheritance hierarchy for concrete symbol
comment|/// types (e.g. functions, executables, vtables, etc).  All concrete symbol
comment|/// types inherit from PDBSymbol and expose the exact set of methods that are
comment|/// valid for that particular symbol type, as described in the Microsoft
comment|/// reference "Lexical and Class Hierarchy of Symbol Types":
comment|/// https://msdn.microsoft.com/en-us/library/370hs6k4.aspx
name|class
name|PDBSymbol
block|{
name|protected
label|:
name|PDBSymbol
argument_list|(
specifier|const
name|IPDBSession
operator|&
name|PDBSession
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBRawSymbol
operator|>
name|Symbol
argument_list|)
expr_stmt|;
name|public
label|:
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|PDBSymbol
operator|>
name|create
argument_list|(
specifier|const
name|IPDBSession
operator|&
name|PDBSession
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBRawSymbol
operator|>
name|Symbol
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|PDBSymbol
argument_list|()
expr_stmt|;
comment|/// Dumps the contents of a symbol a raw_ostream.  By default this will just
comment|/// call dump() on the underlying RawSymbol, which allows us to discover
comment|/// unknown properties, but individual implementations of PDBSymbol may
comment|/// override the behavior to only dump known fields.
name|virtual
name|void
name|dump
argument_list|(
name|PDBSymDumper
operator|&
name|Dumper
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|void
name|defaultDump
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|int
name|Indent
argument_list|)
decl|const
decl_stmt|;
name|PDB_SymType
name|getSymTag
argument_list|()
specifier|const
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|std
operator|::
name|unique_ptr
operator|<
name|T
operator|>
name|findOneChild
argument_list|()
specifier|const
block|{
name|auto
name|Enumerator
argument_list|(
name|findAllChildren
operator|<
name|T
operator|>
operator|(
operator|)
argument_list|)
block|;
return|return
name|Enumerator
operator|->
name|getNext
argument_list|()
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|std
operator|::
name|unique_ptr
operator|<
name|ConcreteSymbolEnumerator
operator|<
name|T
operator|>>
name|findAllChildren
argument_list|()
specifier|const
block|{
name|auto
name|BaseIter
operator|=
name|RawSymbol
operator|->
name|findChildren
argument_list|(
name|T
operator|::
name|Tag
argument_list|)
block|;
return|return
name|llvm
operator|::
name|make_unique
operator|<
name|ConcreteSymbolEnumerator
operator|<
name|T
operator|>>
operator|(
name|std
operator|::
name|move
argument_list|(
name|BaseIter
argument_list|)
operator|)
return|;
block|}
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBEnumSymbols
operator|>
name|findAllChildren
argument_list|(
argument|PDB_SymType Type
argument_list|)
specifier|const
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBEnumSymbols
operator|>
name|findAllChildren
argument_list|()
specifier|const
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBEnumSymbols
operator|>
name|findChildren
argument_list|(
argument|PDB_SymType Type
argument_list|,
argument|StringRef Name
argument_list|,
argument|PDB_NameSearchFlags Flags
argument_list|)
specifier|const
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBEnumSymbols
operator|>
name|findChildrenByRVA
argument_list|(
argument|PDB_SymType Type
argument_list|,
argument|StringRef Name
argument_list|,
argument|PDB_NameSearchFlags Flags
argument_list|,
argument|uint32_t RVA
argument_list|)
specifier|const
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBEnumSymbols
operator|>
name|findInlineFramesByRVA
argument_list|(
argument|uint32_t RVA
argument_list|)
specifier|const
expr_stmt|;
specifier|const
name|IPDBRawSymbol
operator|&
name|getRawSymbol
argument_list|()
specifier|const
block|{
return|return
operator|*
name|RawSymbol
return|;
block|}
name|IPDBRawSymbol
modifier|&
name|getRawSymbol
parameter_list|()
block|{
return|return
operator|*
name|RawSymbol
return|;
block|}
specifier|const
name|IPDBSession
operator|&
name|getSession
argument_list|()
specifier|const
block|{
return|return
name|Session
return|;
block|}
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBEnumSymbols
operator|>
name|getChildStats
argument_list|(
argument|TagStats&Stats
argument_list|)
specifier|const
expr_stmt|;
name|protected
label|:
specifier|const
name|IPDBSession
modifier|&
name|Session
decl_stmt|;
specifier|const
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBRawSymbol
operator|>
name|RawSymbol
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

