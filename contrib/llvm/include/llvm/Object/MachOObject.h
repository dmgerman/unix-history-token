begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MachOObject.h - Mach-O Object File Wrapper ---------------*- C++ -*-===//
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
name|LLVM_OBJECT_MACHOOBJECT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OBJECT_MACHOOBJECT_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/InMemoryStruct.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/MachOFormat.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MemoryBuffer
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|namespace
name|object
block|{
comment|/// \brief Wrapper object for manipulating Mach-O object files.
comment|///
comment|/// This class is designed to implement a full-featured, efficient, portable,
comment|/// and robust Mach-O interface to Mach-O object files. It does not attempt to
comment|/// smooth over rough edges in the Mach-O format or generalize access to object
comment|/// independent features.
comment|///
comment|/// The class is designed around accessing the Mach-O object which is expected
comment|/// to be fully loaded into memory.
comment|///
comment|/// This class is *not* suitable for concurrent use. For efficient operation,
comment|/// the class uses APIs which rely on the ability to cache the results of
comment|/// certain calls in internal objects which are not safe for concurrent
comment|/// access. This allows the API to be zero-copy on the common paths.
comment|//
comment|// FIXME: It would be cool if we supported a "paged" MemoryBuffer
comment|// implementation. This would allow us to implement a more sensible version of
comment|// MemoryObject which can work like a MemoryBuffer, but be more efficient for
comment|// objects which are in the current address space.
name|class
name|MachOObject
block|{
name|public
label|:
struct|struct
name|LoadCommandInfo
block|{
comment|/// The load command information.
name|macho
operator|::
name|LoadCommand
name|Command
expr_stmt|;
comment|/// The offset to the start of the load command in memory.
name|uint64_t
name|Offset
decl_stmt|;
block|}
struct|;
name|private
label|:
name|OwningPtr
operator|<
name|MemoryBuffer
operator|>
name|Buffer
expr_stmt|;
comment|/// Whether the object is little endian.
name|bool
name|IsLittleEndian
decl_stmt|;
comment|/// Whether the object is 64-bit.
name|bool
name|Is64Bit
decl_stmt|;
comment|/// Whether the object is swapped endianness from the host.
name|bool
name|IsSwappedEndian
decl_stmt|;
comment|/// Whether the string table has been registered.
name|bool
name|HasStringTable
decl_stmt|;
comment|/// The cached information on the load commands.
name|LoadCommandInfo
modifier|*
name|LoadCommands
decl_stmt|;
name|mutable
name|unsigned
name|NumLoadedCommands
decl_stmt|;
comment|/// The cached copy of the header.
name|macho
operator|::
name|Header
name|Header
expr_stmt|;
name|macho
operator|::
name|Header64Ext
name|Header64Ext
expr_stmt|;
comment|/// Cache string table information.
name|StringRef
name|StringTable
decl_stmt|;
name|private
label|:
name|MachOObject
argument_list|(
argument|MemoryBuffer *Buffer
argument_list|,
argument|bool IsLittleEndian
argument_list|,
argument|bool Is64Bit
argument_list|)
empty_stmt|;
name|public
label|:
operator|~
name|MachOObject
argument_list|()
expr_stmt|;
comment|/// \brief Load a Mach-O object from a MemoryBuffer object.
comment|///
comment|/// \param Buffer - The buffer to load the object from. This routine takes
comment|/// exclusive ownership of the buffer (which is passed to the returned object
comment|/// on success).
comment|/// \param ErrorStr [out] - If given, will be set to a user readable error
comment|/// message on failure.
comment|/// \returns The loaded object, or null on error.
specifier|static
name|MachOObject
modifier|*
name|LoadFromBuffer
argument_list|(
name|MemoryBuffer
operator|*
name|Buffer
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrorStr
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// @name File Information
comment|/// @{
name|bool
name|isLittleEndian
argument_list|()
specifier|const
block|{
return|return
name|IsLittleEndian
return|;
block|}
name|bool
name|isSwappedEndian
argument_list|()
specifier|const
block|{
return|return
name|IsSwappedEndian
return|;
block|}
name|bool
name|is64Bit
argument_list|()
specifier|const
block|{
return|return
name|Is64Bit
return|;
block|}
name|unsigned
name|getHeaderSize
argument_list|()
specifier|const
block|{
return|return
name|Is64Bit
operator|?
name|macho
operator|::
name|Header64Size
operator|:
name|macho
operator|::
name|Header32Size
return|;
block|}
name|StringRef
name|getData
argument_list|(
name|size_t
name|Offset
argument_list|,
name|size_t
name|Size
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
comment|/// @name String Table Data
comment|/// @{
name|StringRef
name|getStringTableData
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|HasStringTable
operator|&&
literal|"String table has not been registered!"
argument_list|)
block|;
return|return
name|StringTable
return|;
block|}
name|StringRef
name|getStringAtIndex
argument_list|(
name|unsigned
name|Index
argument_list|)
decl|const
block|{
name|size_t
name|End
init|=
name|getStringTableData
argument_list|()
operator|.
name|find
argument_list|(
literal|'\0'
argument_list|,
name|Index
argument_list|)
decl_stmt|;
return|return
name|getStringTableData
argument_list|()
operator|.
name|slice
argument_list|(
name|Index
argument_list|,
name|End
argument_list|)
return|;
block|}
name|void
name|RegisterStringTable
argument_list|(
name|macho
operator|::
name|SymtabLoadCommand
operator|&
name|SLC
argument_list|)
decl_stmt|;
comment|/// @}
comment|/// @name Object Header Access
comment|/// @{
specifier|const
name|macho
operator|::
name|Header
operator|&
name|getHeader
argument_list|()
specifier|const
block|{
return|return
name|Header
return|;
block|}
specifier|const
name|macho
operator|::
name|Header64Ext
operator|&
name|getHeader64Ext
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|is64Bit
argument_list|()
operator|&&
literal|"Invalid access!"
argument_list|)
block|;
return|return
name|Header64Ext
return|;
block|}
comment|/// @}
comment|/// @name Object Structure Access
comment|/// @{
comment|/// \brief Retrieve the information for the given load command.
specifier|const
name|LoadCommandInfo
modifier|&
name|getLoadCommandInfo
argument_list|(
name|unsigned
name|Index
argument_list|)
decl|const
decl_stmt|;
name|void
name|ReadSegmentLoadCommand
argument_list|(
specifier|const
name|LoadCommandInfo
operator|&
name|LCI
argument_list|,
name|InMemoryStruct
operator|<
name|macho
operator|::
name|SegmentLoadCommand
operator|>
operator|&
name|Res
argument_list|)
decl|const
decl_stmt|;
name|void
name|ReadSegment64LoadCommand
argument_list|(
specifier|const
name|LoadCommandInfo
operator|&
name|LCI
argument_list|,
name|InMemoryStruct
operator|<
name|macho
operator|::
name|Segment64LoadCommand
operator|>
operator|&
name|Res
argument_list|)
decl|const
decl_stmt|;
name|void
name|ReadSymtabLoadCommand
argument_list|(
specifier|const
name|LoadCommandInfo
operator|&
name|LCI
argument_list|,
name|InMemoryStruct
operator|<
name|macho
operator|::
name|SymtabLoadCommand
operator|>
operator|&
name|Res
argument_list|)
decl|const
decl_stmt|;
name|void
name|ReadDysymtabLoadCommand
argument_list|(
specifier|const
name|LoadCommandInfo
operator|&
name|LCI
argument_list|,
name|InMemoryStruct
operator|<
name|macho
operator|::
name|DysymtabLoadCommand
operator|>
operator|&
name|Res
argument_list|)
decl|const
decl_stmt|;
name|void
name|ReadIndirectSymbolTableEntry
argument_list|(
specifier|const
name|macho
operator|::
name|DysymtabLoadCommand
operator|&
name|DLC
argument_list|,
name|unsigned
name|Index
argument_list|,
name|InMemoryStruct
operator|<
name|macho
operator|::
name|IndirectSymbolTableEntry
operator|>
operator|&
name|Res
argument_list|)
decl|const
decl_stmt|;
name|void
name|ReadSection
argument_list|(
specifier|const
name|LoadCommandInfo
operator|&
name|LCI
argument_list|,
name|unsigned
name|Index
argument_list|,
name|InMemoryStruct
operator|<
name|macho
operator|::
name|Section
operator|>
operator|&
name|Res
argument_list|)
decl|const
decl_stmt|;
name|void
name|ReadSection64
argument_list|(
specifier|const
name|LoadCommandInfo
operator|&
name|LCI
argument_list|,
name|unsigned
name|Index
argument_list|,
name|InMemoryStruct
operator|<
name|macho
operator|::
name|Section64
operator|>
operator|&
name|Res
argument_list|)
decl|const
decl_stmt|;
name|void
name|ReadRelocationEntry
argument_list|(
name|uint64_t
name|RelocationTableOffset
argument_list|,
name|unsigned
name|Index
argument_list|,
name|InMemoryStruct
operator|<
name|macho
operator|::
name|RelocationEntry
operator|>
operator|&
name|Res
argument_list|)
decl|const
decl_stmt|;
name|void
name|ReadSymbolTableEntry
argument_list|(
name|uint64_t
name|SymbolTableOffset
argument_list|,
name|unsigned
name|Index
argument_list|,
name|InMemoryStruct
operator|<
name|macho
operator|::
name|SymbolTableEntry
operator|>
operator|&
name|Res
argument_list|)
decl|const
decl_stmt|;
name|void
name|ReadSymbol64TableEntry
argument_list|(
name|uint64_t
name|SymbolTableOffset
argument_list|,
name|unsigned
name|Index
argument_list|,
name|InMemoryStruct
operator|<
name|macho
operator|::
name|Symbol64TableEntry
operator|>
operator|&
name|Res
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
comment|/// @name Object Dump Facilities
comment|/// @{
comment|/// dump - Support for debugging, callable in GDB: V->dump()
comment|//
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
name|void
name|dumpHeader
argument_list|()
specifier|const
expr_stmt|;
comment|/// print - Implement operator<< on Value.
comment|///
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|O
argument_list|)
decl|const
decl_stmt|;
name|void
name|printHeader
argument_list|(
name|raw_ostream
operator|&
name|O
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
block|}
empty_stmt|;
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|MachOObject
operator|&
name|V
operator|)
block|{
name|V
operator|.
name|print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
block|}
comment|// end namespace object
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

