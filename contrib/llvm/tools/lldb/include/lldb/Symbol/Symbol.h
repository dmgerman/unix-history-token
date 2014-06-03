begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Symbol.h ------------------------------------------------*- C++ -*-===//
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
name|liblldb_Symbol_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Symbol_h_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/AddressRange.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Mangled.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/UserID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/SymbolContextScope.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Symbol
range|:
name|public
name|SymbolContextScope
block|{
name|public
operator|:
comment|// ObjectFile readers can classify their symbol table entries and searches can be made
comment|// on specific types where the symbol values will have drastically different meanings
comment|// and sorting requirements.
name|Symbol
argument_list|()
block|;
name|Symbol
argument_list|(
argument|uint32_t symID
argument_list|,
argument|const char *name
argument_list|,
argument|bool name_is_mangled
argument_list|,
argument|lldb::SymbolType type
argument_list|,
argument|bool external
argument_list|,
argument|bool is_debug
argument_list|,
argument|bool is_trampoline
argument_list|,
argument|bool is_artificial
argument_list|,
argument|const lldb::SectionSP&section_sp
argument_list|,
argument|lldb::addr_t value
argument_list|,
argument|lldb::addr_t size
argument_list|,
argument|bool size_is_valid
argument_list|,
argument|uint32_t flags
argument_list|)
block|;
name|Symbol
argument_list|(
argument|uint32_t symID
argument_list|,
argument|const char *name
argument_list|,
argument|bool name_is_mangled
argument_list|,
argument|lldb::SymbolType type
argument_list|,
argument|bool external
argument_list|,
argument|bool is_debug
argument_list|,
argument|bool is_trampoline
argument_list|,
argument|bool is_artificial
argument_list|,
argument|const AddressRange&range
argument_list|,
argument|bool size_is_valid
argument_list|,
argument|uint32_t flags
argument_list|)
block|;
name|Symbol
argument_list|(
specifier|const
name|Symbol
operator|&
name|rhs
argument_list|)
block|;
specifier|const
name|Symbol
operator|&
name|operator
operator|=
operator|(
specifier|const
name|Symbol
operator|&
name|rhs
operator|)
block|;
name|void
name|Clear
argument_list|()
block|;
name|bool
name|Compare
argument_list|(
argument|const ConstString& name
argument_list|,
argument|lldb::SymbolType type
argument_list|)
specifier|const
block|;
name|void
name|Dump
argument_list|(
argument|Stream *s
argument_list|,
argument|Target *target
argument_list|,
argument|uint32_t index
argument_list|)
specifier|const
block|;
name|bool
name|ValueIsAddress
argument_list|()
specifier|const
block|;
comment|//------------------------------------------------------------------
comment|// Access the address value. Do NOT hand out the AddressRange as an
comment|// object as the byte size of the address range may not be filled in
comment|// and it should be accessed via GetByteSize().
comment|//------------------------------------------------------------------
name|Address
operator|&
name|GetAddress
argument_list|()
block|{
return|return
name|m_addr_range
operator|.
name|GetBaseAddress
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|// Access the address value. Do NOT hand out the AddressRange as an
comment|// object as the byte size of the address range may not be filled in
comment|// and it should be accessed via GetByteSize().
comment|//------------------------------------------------------------------
specifier|const
name|Address
operator|&
name|GetAddress
argument_list|()
specifier|const
block|{
return|return
name|m_addr_range
operator|.
name|GetBaseAddress
argument_list|()
return|;
block|}
specifier|const
name|ConstString
operator|&
name|GetName
argument_list|()
specifier|const
block|{
return|return
name|m_mangled
operator|.
name|GetName
argument_list|()
return|;
block|}
name|uint32_t
name|GetID
argument_list|()
specifier|const
block|{
return|return
name|m_uid
return|;
block|}
name|void
name|SetID
argument_list|(
argument|uint32_t uid
argument_list|)
block|{
name|m_uid
operator|=
name|uid
block|;     }
name|Mangled
operator|&
name|GetMangled
argument_list|()
block|{
return|return
name|m_mangled
return|;
block|}
specifier|const
name|Mangled
operator|&
name|GetMangled
argument_list|()
specifier|const
block|{
return|return
name|m_mangled
return|;
block|}
name|ConstString
name|GetReExportedSymbolName
argument_list|()
specifier|const
block|;
name|FileSpec
name|GetReExportedSymbolSharedLibrary
argument_list|()
specifier|const
block|;
name|bool
name|SetReExportedSymbolName
argument_list|(
specifier|const
name|ConstString
operator|&
name|name
argument_list|)
block|;
name|bool
name|SetReExportedSymbolSharedLibrary
argument_list|(
specifier|const
name|FileSpec
operator|&
name|fspec
argument_list|)
block|;
name|Symbol
operator|*
name|ResolveReExportedSymbol
argument_list|(
name|Target
operator|&
name|target
argument_list|)
block|;
name|uint32_t
name|GetSiblingIndex
argument_list|()
specifier|const
block|;
name|lldb
operator|::
name|SymbolType
name|GetType
argument_list|()
specifier|const
block|{
return|return
operator|(
name|lldb
operator|::
name|SymbolType
operator|)
name|m_type
return|;
block|}
name|void
name|SetType
argument_list|(
argument|lldb::SymbolType type
argument_list|)
block|{
name|m_type
operator|=
operator|(
name|lldb
operator|::
name|SymbolType
operator|)
name|type
block|;     }
specifier|const
name|char
operator|*
name|GetTypeAsString
argument_list|()
specifier|const
block|;
name|uint32_t
name|GetFlags
argument_list|()
specifier|const
block|{
return|return
name|m_flags
return|;
block|}
name|void
name|SetFlags
argument_list|(
argument|uint32_t flags
argument_list|)
block|{
name|m_flags
operator|=
name|flags
block|;     }
name|void
name|GetDescription
argument_list|(
argument|Stream *s
argument_list|,
argument|lldb::DescriptionLevel level
argument_list|,
argument|Target *target
argument_list|)
specifier|const
block|;
name|bool
name|IsSynthetic
argument_list|()
specifier|const
block|{
return|return
name|m_is_synthetic
return|;
block|}
name|void
name|SetIsSynthetic
argument_list|(
argument|bool b
argument_list|)
block|{
name|m_is_synthetic
operator|=
name|b
block|;     }
name|bool
name|GetSizeIsSynthesized
argument_list|()
specifier|const
block|{
return|return
name|m_size_is_synthesized
return|;
block|}
name|void
name|SetSizeIsSynthesized
argument_list|(
argument|bool b
argument_list|)
block|{
name|m_size_is_synthesized
operator|=
name|b
block|;     }
name|bool
name|IsDebug
argument_list|()
specifier|const
block|{
return|return
name|m_is_debug
return|;
block|}
name|void
name|SetDebug
argument_list|(
argument|bool b
argument_list|)
block|{
name|m_is_debug
operator|=
name|b
block|;     }
name|bool
name|IsExternal
argument_list|()
specifier|const
block|{
return|return
name|m_is_external
return|;
block|}
name|void
name|SetExternal
argument_list|(
argument|bool b
argument_list|)
block|{
name|m_is_external
operator|=
name|b
block|;     }
name|bool
name|IsTrampoline
argument_list|()
specifier|const
block|;
name|bool
name|IsIndirect
argument_list|()
specifier|const
block|;
name|bool
name|GetByteSizeIsValid
argument_list|()
specifier|const
block|{
return|return
name|m_size_is_valid
return|;
block|}
name|lldb
operator|::
name|addr_t
name|GetByteSize
argument_list|()
specifier|const
block|;
name|void
name|SetByteSize
argument_list|(
argument|lldb::addr_t size
argument_list|)
block|{
name|m_size_is_valid
operator|=
name|size
operator|>
literal|0
block|;
name|m_addr_range
operator|.
name|SetByteSize
argument_list|(
name|size
argument_list|)
block|;     }
name|bool
name|GetSizeIsSibling
argument_list|()
specifier|const
block|{
return|return
name|m_size_is_sibling
return|;
block|}
name|void
name|SetSizeIsSibling
argument_list|(
argument|bool b
argument_list|)
block|{
name|m_size_is_sibling
operator|=
name|b
block|;     }
comment|// If m_type is "Code" or "Function" then this will return the prologue size
comment|// in bytes, else it will return zero.
name|uint32_t
name|GetPrologueByteSize
argument_list|()
block|;
name|bool
name|GetDemangledNameIsSynthesized
argument_list|()
specifier|const
block|{
return|return
name|m_demangled_is_synthesized
return|;
block|}
name|void
name|SetDemangledNameIsSynthesized
argument_list|(
argument|bool b
argument_list|)
block|{
name|m_demangled_is_synthesized
operator|=
name|b
block|;     }
comment|//------------------------------------------------------------------
comment|/// @copydoc SymbolContextScope::CalculateSymbolContext(SymbolContext*)
comment|///
comment|/// @see SymbolContextScope
comment|//------------------------------------------------------------------
name|virtual
name|void
name|CalculateSymbolContext
argument_list|(
name|SymbolContext
operator|*
name|sc
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|ModuleSP
name|CalculateSymbolContextModule
argument_list|()
block|;
name|virtual
name|Symbol
operator|*
name|CalculateSymbolContextSymbol
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// @copydoc SymbolContextScope::DumpSymbolContext(Stream*)
comment|///
comment|/// @see SymbolContextScope
comment|//------------------------------------------------------------------
name|virtual
name|void
name|DumpSymbolContext
argument_list|(
name|Stream
operator|*
name|s
argument_list|)
block|;
name|lldb
operator|::
name|DisassemblerSP
name|GetInstructions
argument_list|(
argument|const ExecutionContext&exe_ctx
argument_list|,
argument|const char *flavor
argument_list|,
argument|bool prefer_file_cache
argument_list|)
block|;
name|bool
name|GetDisassembly
argument_list|(
argument|const ExecutionContext&exe_ctx
argument_list|,
argument|const char *flavor
argument_list|,
argument|bool prefer_file_cache
argument_list|,
argument|Stream&strm
argument_list|)
block|;
name|protected
operator|:
name|uint32_t
name|m_uid
block|;
comment|// User ID (usually the original symbol table index)
name|uint16_t
name|m_type_data
block|;
comment|// data specific to m_type
name|uint16_t
name|m_type_data_resolved
operator|:
literal|1
block|,
comment|// True if the data in m_type_data has already been calculated
name|m_is_synthetic
operator|:
literal|1
block|,
comment|// non-zero if this symbol is not actually in the symbol table, but synthesized from other info in the object file.
name|m_is_debug
operator|:
literal|1
block|,
comment|// non-zero if this symbol is debug information in a symbol
name|m_is_external
operator|:
literal|1
block|,
comment|// non-zero if this symbol is globally visible
name|m_size_is_sibling
operator|:
literal|1
block|,
comment|// m_size contains the index of this symbol's sibling
name|m_size_is_synthesized
operator|:
literal|1
block|,
comment|// non-zero if this symbol's size was calculated using a delta between this symbol and the next
name|m_size_is_valid
operator|:
literal|1
block|,
name|m_demangled_is_synthesized
operator|:
literal|1
block|,
comment|// The demangled name was created should not be used for expressions or other lookups
name|m_type
operator|:
literal|8
block|;
name|Mangled
name|m_mangled
block|;
comment|// uniqued symbol name/mangled name pair
name|AddressRange
name|m_addr_range
block|;
comment|// Contains the value, or the section offset address when the value is an address in a section, and the size (if any)
name|uint32_t
name|m_flags
block|;
comment|// A copy of the flags from the original symbol table, the ObjectFile plug-in can interpret these
block|}
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_Symbol_h_
end_comment

end_unit

