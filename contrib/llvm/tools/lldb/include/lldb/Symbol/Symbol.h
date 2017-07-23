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
file|"lldb/Symbol/SymbolContextScope.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/UserID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
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
comment|// ObjectFile readers can classify their symbol table entries and searches can
comment|// be made
comment|// on specific types where the symbol values will have drastically different
comment|// meanings
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
argument|bool contains_linker_annotations
argument_list|,
argument|uint32_t flags
argument_list|)
block|;
name|Symbol
argument_list|(
argument|uint32_t symID
argument_list|,
argument|const Mangled&mangled
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
argument|bool contains_linker_annotations
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
argument|const ConstString&name
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
comment|// The GetAddressRef() accessor functions should only be called if
comment|// you previously call ValueIsAddress() otherwise you might get an
comment|// reference to an Address object that contains an constant integer
comment|// value in m_addr_range.m_base_addr.m_offset which could be
comment|// incorrectly used to represent an absolute address since it has
comment|// no section.
comment|//------------------------------------------------------------------
name|Address
operator|&
name|GetAddressRef
argument_list|()
block|{
return|return
name|m_addr_range
operator|.
name|GetBaseAddress
argument_list|()
return|;
block|}
specifier|const
name|Address
operator|&
name|GetAddressRef
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
comment|//------------------------------------------------------------------
comment|// Makes sure the symbol's value is an address and returns the file
comment|// address. Returns LLDB_INVALID_ADDRESS if the symbol's value isn't
comment|// an address.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|addr_t
name|GetFileAddress
argument_list|()
specifier|const
block|;
comment|//------------------------------------------------------------------
comment|// Makes sure the symbol's value is an address and gets the load
comment|// address using \a target if it is. Returns LLDB_INVALID_ADDRESS
comment|// if the symbol's value isn't an address or if the section isn't
comment|// loaded in \a target.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|addr_t
name|GetLoadAddress
argument_list|(
argument|Target *target
argument_list|)
specifier|const
block|;
comment|//------------------------------------------------------------------
comment|// Access the address value. Do NOT hand out the AddressRange as an
comment|// object as the byte size of the address range may not be filled in
comment|// and it should be accessed via GetByteSize().
comment|//------------------------------------------------------------------
name|Address
name|GetAddress
argument_list|()
specifier|const
block|{
comment|// Make sure the our value is an address before we hand a copy out.
comment|// We use the Address inside m_addr_range to contain the value for
comment|// symbols that are not address based symbols so we are using it
comment|// for more than just addresses. For example undefined symbols on
comment|// MacOSX have a nlist.n_value of 0 (zero) and this will get placed
comment|// into m_addr_range.m_base_addr.m_offset and it will have no section.
comment|// So in the GetAddress() accessor, we need to hand out an invalid
comment|// address if the symbol's value isn't an address.
if|if
condition|(
name|ValueIsAddress
argument_list|()
condition|)
return|return
name|m_addr_range
operator|.
name|GetBaseAddress
argument_list|()
return|;
else|else
return|return
name|Address
argument_list|()
return|;
block|}
comment|// When a symbol's value isn't an address, we need to access the raw
comment|// value. This function will ensure this symbol's value isn't an address
comment|// and return the integer value if this checks out, otherwise it will
comment|// return "fail_value" if the symbol is an address value.
name|uint64_t
name|GetIntegerValue
argument_list|(
argument|uint64_t fail_value =
literal|0
argument_list|)
specifier|const
block|{
if|if
condition|(
name|ValueIsAddress
argument_list|()
condition|)
block|{
comment|// This symbol's value is an address. Use Symbol::GetAddress() to get the
comment|// address.
return|return
name|fail_value
return|;
block|}
else|else
block|{
comment|// The value is stored in the base address' offset
return|return
name|m_addr_range
operator|.
name|GetBaseAddress
argument_list|()
operator|.
name|GetOffset
argument_list|()
return|;
block|}
block|}
name|lldb
operator|::
name|addr_t
name|ResolveCallableAddress
argument_list|(
argument|Target&target
argument_list|)
specifier|const
block|;
name|ConstString
name|GetName
argument_list|()
specifier|const
block|;
name|ConstString
name|GetNameNoArguments
argument_list|()
specifier|const
block|;
name|ConstString
name|GetDisplayName
argument_list|()
specifier|const
block|;
name|uint32_t
name|GetID
argument_list|()
specifier|const
block|{
return|return
name|m_uid
return|;
block|}
name|lldb
operator|::
name|LanguageType
name|GetLanguage
argument_list|()
specifier|const
block|{
comment|// TODO: See if there is a way to determine the language for a symbol
comment|// somehow, for now just return our best guess
return|return
name|m_mangled
operator|.
name|GuessLanguage
argument_list|()
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
block|; }
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
name|void
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
argument|Target&target
argument_list|)
specifier|const
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
block|; }
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
block|; }
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
block|; }
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
block|; }
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
block|; }
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
block|; }
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
block|;   }
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
block|; }
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
block|; }
name|bool
name|ContainsLinkerAnnotations
argument_list|()
specifier|const
block|{
return|return
name|m_contains_linker_annotations
return|;
block|}
name|void
name|SetContainsLinkerAnnotations
argument_list|(
argument|bool b
argument_list|)
block|{
name|m_contains_linker_annotations
operator|=
name|b
block|;   }
comment|//------------------------------------------------------------------
comment|/// @copydoc SymbolContextScope::CalculateSymbolContext(SymbolContext*)
comment|///
comment|/// @see SymbolContextScope
comment|//------------------------------------------------------------------
name|void
name|CalculateSymbolContext
argument_list|(
argument|SymbolContext *sc
argument_list|)
name|override
block|;
name|lldb
operator|::
name|ModuleSP
name|CalculateSymbolContextModule
argument_list|()
name|override
block|;
name|Symbol
operator|*
name|CalculateSymbolContextSymbol
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|/// @copydoc SymbolContextScope::DumpSymbolContext(Stream*)
comment|///
comment|/// @see SymbolContextScope
comment|//------------------------------------------------------------------
name|void
name|DumpSymbolContext
argument_list|(
argument|Stream *s
argument_list|)
name|override
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
name|bool
name|ContainsFileAddress
argument_list|(
argument|lldb::addr_t file_addr
argument_list|)
specifier|const
block|;
name|protected
operator|:
comment|// This is the internal guts of ResolveReExportedSymbol, it assumes
comment|// reexport_name is not null, and that module_spec
comment|// is valid.  We track the modules we've already seen to make sure we don't
comment|// get caught in a cycle.
name|Symbol
operator|*
name|ResolveReExportedSymbolInModuleSpec
argument_list|(
argument|Target&target
argument_list|,
argument|ConstString&reexport_name
argument_list|,
argument|lldb_private::ModuleSpec&module_spec
argument_list|,
argument|lldb_private::ModuleList&seen_modules
argument_list|)
specifier|const
block|;
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
comment|// True if the data in m_type_data has
comment|// already been calculated
name|m_is_synthetic
operator|:
literal|1
block|,
comment|// non-zero if this symbol is not actually in the
comment|// symbol table, but synthesized from other info in
comment|// the object file.
name|m_is_debug
operator|:
literal|1
block|,
comment|// non-zero if this symbol is debug information in a
comment|// symbol
name|m_is_external
operator|:
literal|1
block|,
comment|// non-zero if this symbol is globally visible
name|m_size_is_sibling
operator|:
literal|1
block|,
comment|// m_size contains the index of this symbol's
comment|// sibling
name|m_size_is_synthesized
operator|:
literal|1
block|,
comment|// non-zero if this symbol's size was
comment|// calculated using a delta between this symbol
comment|// and the next
name|m_size_is_valid
operator|:
literal|1
block|,
name|m_demangled_is_synthesized
operator|:
literal|1
block|,
comment|// The demangled name was created should
comment|// not be used for expressions or other
comment|// lookups
name|m_contains_linker_annotations
operator|:
literal|1
block|,
comment|// The symbol name contains linker
comment|// annotations, which are optional when
comment|// doing name lookups
name|m_type
operator|:
literal|7
block|;
name|Mangled
name|m_mangled
block|;
comment|// uniqued symbol name/mangled name pair
name|AddressRange
name|m_addr_range
block|;
comment|// Contains the value, or the section offset
comment|// address when the value is an address in a
comment|// section, and the size (if any)
name|uint32_t
name|m_flags
block|;
comment|// A copy of the flags from the original symbol table, the
comment|// ObjectFile plug-in can interpret these
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

