begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Bitcode/Archive.h - LLVM Bitcode Archive -----------*- C++ -*-===//
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
comment|// This header file declares the Archive and ArchiveMember classes that provide
end_comment

begin_comment
comment|// manipulation of LLVM Archive files.  The implementation is provided by the
end_comment

begin_comment
comment|// lib/Bitcode/Archive library.  This library is used to read and write
end_comment

begin_comment
comment|// archive (*.a) files that contain LLVM bitcode files (or others).
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
name|LLVM_BITCODE_ARCHIVE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_BITCODE_ARCHIVE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ilist.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist_node.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/Path.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MemoryBuffer
decl_stmt|;
comment|// Forward declare classes
name|class
name|ModuleProvider
decl_stmt|;
comment|// From VMCore
name|class
name|Module
decl_stmt|;
comment|// From VMCore
name|class
name|Archive
decl_stmt|;
comment|// Declared below
name|class
name|ArchiveMemberHeader
decl_stmt|;
comment|// Internal implementation class
name|class
name|LLVMContext
decl_stmt|;
comment|// Global data
comment|/// This class is the main class manipulated by users of the Archive class. It
comment|/// holds information about one member of the Archive. It is also the element
comment|/// stored by the Archive's ilist, the Archive's main abstraction. Because of
comment|/// the special requirements of archive files, users are not permitted to
comment|/// construct ArchiveMember instances. You should obtain them from the methods
comment|/// of the Archive class instead.
comment|/// @brief This class represents a single archive member.
name|class
name|ArchiveMember
range|:
name|public
name|ilist_node
operator|<
name|ArchiveMember
operator|>
block|{
comment|/// @name Types
comment|/// @{
name|public
operator|:
comment|/// These flags are used internally by the archive member to specify various
comment|/// characteristics of the member. The various "is" methods below provide
comment|/// access to the flags. The flags are not user settable.
expr|enum
name|Flags
block|{
name|CompressedFlag
operator|=
literal|1
block|,
comment|///< Member is a normal compressed file
name|SVR4SymbolTableFlag
operator|=
literal|2
block|,
comment|///< Member is a SVR4 symbol table
name|BSD4SymbolTableFlag
operator|=
literal|4
block|,
comment|///< Member is a BSD4 symbol table
name|LLVMSymbolTableFlag
operator|=
literal|8
block|,
comment|///< Member is an LLVM symbol table
name|BitcodeFlag
operator|=
literal|16
block|,
comment|///< Member is bitcode
name|HasPathFlag
operator|=
literal|64
block|,
comment|///< Member has a full or partial path
name|HasLongFilenameFlag
operator|=
literal|128
block|,
comment|///< Member uses the long filename syntax
name|StringTableFlag
operator|=
literal|256
comment|///< Member is an ar(1) format string table
block|}
block|;
comment|/// @}
comment|/// @name Accessors
comment|/// @{
name|public
operator|:
comment|/// @returns the parent Archive instance
comment|/// @brief Get the archive associated with this member
name|Archive
operator|*
name|getArchive
argument_list|()
specifier|const
block|{
return|return
name|parent
return|;
block|}
comment|/// @returns the path to the Archive's file
comment|/// @brief Get the path to the archive member
specifier|const
name|sys
operator|::
name|Path
operator|&
name|getPath
argument_list|()
specifier|const
block|{
return|return
name|path
return|;
block|}
comment|/// The "user" is the owner of the file per Unix security. This may not
comment|/// have any applicability on non-Unix systems but is a required component
comment|/// of the "ar" file format.
comment|/// @brief Get the user associated with this archive member.
name|unsigned
name|getUser
argument_list|()
specifier|const
block|{
return|return
name|info
operator|.
name|getUser
argument_list|()
return|;
block|}
comment|/// The "group" is the owning group of the file per Unix security. This
comment|/// may not have any applicability on non-Unix systems but is a required
comment|/// component of the "ar" file format.
comment|/// @brief Get the group associated with this archive member.
name|unsigned
name|getGroup
argument_list|()
specifier|const
block|{
return|return
name|info
operator|.
name|getGroup
argument_list|()
return|;
block|}
comment|/// The "mode" specifies the access permissions for the file per Unix
comment|/// security. This may not have any applicabiity on non-Unix systems but is
comment|/// a required component of the "ar" file format.
comment|/// @brief Get the permission mode associated with this archive member.
name|unsigned
name|getMode
argument_list|()
specifier|const
block|{
return|return
name|info
operator|.
name|getMode
argument_list|()
return|;
block|}
comment|/// This method returns the time at which the archive member was last
comment|/// modified when it was not in the archive.
comment|/// @brief Get the time of last modification of the archive member.
name|sys
operator|::
name|TimeValue
name|getModTime
argument_list|()
specifier|const
block|{
return|return
name|info
operator|.
name|getTimestamp
argument_list|()
return|;
block|}
comment|/// @returns the size of the archive member in bytes.
comment|/// @brief Get the size of the archive member.
name|uint64_t
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|info
operator|.
name|getSize
argument_list|()
return|;
block|}
comment|/// This method returns the total size of the archive member as it
comment|/// appears on disk. This includes the file content, the header, the
comment|/// long file name if any, and the padding.
comment|/// @brief Get total on-disk member size.
name|unsigned
name|getMemberSize
argument_list|()
specifier|const
block|;
comment|/// This method will return a pointer to the in-memory content of the
comment|/// archive member, if it is available. If the data has not been loaded
comment|/// into memory, the return value will be null.
comment|/// @returns a pointer to the member's data.
comment|/// @brief Get the data content of the archive member
specifier|const
name|void
operator|*
name|getData
argument_list|()
specifier|const
block|{
return|return
name|data
return|;
block|}
comment|/// This method determines if the member is a regular compressed file.
comment|/// @returns true iff the archive member is a compressed regular file.
comment|/// @brief Determine if the member is a compressed regular file.
name|bool
name|isCompressed
argument_list|()
specifier|const
block|{
return|return
name|flags
operator|&
name|CompressedFlag
return|;
block|}
comment|/// @returns true iff the member is a SVR4 (non-LLVM) symbol table
comment|/// @brief Determine if this member is a SVR4 symbol table.
name|bool
name|isSVR4SymbolTable
argument_list|()
specifier|const
block|{
return|return
name|flags
operator|&
name|SVR4SymbolTableFlag
return|;
block|}
comment|/// @returns true iff the member is a BSD4.4 (non-LLVM) symbol table
comment|/// @brief Determine if this member is a BSD4.4 symbol table.
name|bool
name|isBSD4SymbolTable
argument_list|()
specifier|const
block|{
return|return
name|flags
operator|&
name|BSD4SymbolTableFlag
return|;
block|}
comment|/// @returns true iff the archive member is the LLVM symbol table
comment|/// @brief Determine if this member is the LLVM symbol table.
name|bool
name|isLLVMSymbolTable
argument_list|()
specifier|const
block|{
return|return
name|flags
operator|&
name|LLVMSymbolTableFlag
return|;
block|}
comment|/// @returns true iff the archive member is the ar(1) string table
comment|/// @brief Determine if this member is the ar(1) string table.
name|bool
name|isStringTable
argument_list|()
specifier|const
block|{
return|return
name|flags
operator|&
name|StringTableFlag
return|;
block|}
comment|/// @returns true iff the archive member is a bitcode file.
comment|/// @brief Determine if this member is a bitcode file.
name|bool
name|isBitcode
argument_list|()
specifier|const
block|{
return|return
name|flags
operator|&
name|BitcodeFlag
return|;
block|}
comment|/// @returns true iff the file name contains a path (directory) component.
comment|/// @brief Determine if the member has a path
name|bool
name|hasPath
argument_list|()
specifier|const
block|{
return|return
name|flags
operator|&
name|HasPathFlag
return|;
block|}
comment|/// Long filenames are an artifact of the ar(1) file format which allows
comment|/// up to sixteen characters in its header and doesn't allow a path
comment|/// separator character (/). To avoid this, a "long format" member name is
comment|/// allowed that doesn't have this restriction. This method determines if
comment|/// that "long format" is used for this member.
comment|/// @returns true iff the file name uses the long form
comment|/// @brief Determin if the member has a long file name
name|bool
name|hasLongFilename
argument_list|()
specifier|const
block|{
return|return
name|flags
operator|&
name|HasLongFilenameFlag
return|;
block|}
comment|/// This method returns the status info (like Unix stat(2)) for the archive
comment|/// member. The status info provides the file's size, permissions, and
comment|/// modification time. The contents of the Path::StatusInfo structure, other
comment|/// than the size and modification time, may not have utility on non-Unix
comment|/// systems.
comment|/// @returns the status info for the archive member
comment|/// @brief Obtain the status info for the archive member
specifier|const
name|sys
operator|::
name|FileStatus
operator|&
name|getFileStatus
argument_list|()
specifier|const
block|{
return|return
name|info
return|;
block|}
comment|/// This method causes the archive member to be replaced with the contents
comment|/// of the file specified by \p File. The contents of \p this will be
comment|/// updated to reflect the new data from \p File. The \p File must exist and
comment|/// be readable on entry to this method.
comment|/// @returns true if an error occurred, false otherwise
comment|/// @brief Replace contents of archive member with a new file.
name|bool
name|replaceWith
argument_list|(
specifier|const
name|sys
operator|::
name|Path
operator|&
name|aFile
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrMsg
argument_list|)
block|;
comment|/// @}
comment|/// @name Data
comment|/// @{
name|private
operator|:
name|Archive
operator|*
name|parent
block|;
comment|///< Pointer to parent archive
name|sys
operator|::
name|PathWithStatus
name|path
block|;
comment|///< Path of file containing the member
name|sys
operator|::
name|FileStatus
name|info
block|;
comment|///< Status info (size,mode,date)
name|unsigned
name|flags
block|;
comment|///< Flags about the archive member
specifier|const
name|void
operator|*
name|data
block|;
comment|///< Data for the member
comment|/// @}
comment|/// @name Constructors
comment|/// @{
name|public
operator|:
comment|/// The default constructor is only used by the Archive's iplist when it
comment|/// constructs the list's sentry node.
name|ArchiveMember
argument_list|()
block|;
name|private
operator|:
comment|/// Used internally by the Archive class to construct an ArchiveMember.
comment|/// The contents of the ArchiveMember are filled out by the Archive class.
name|explicit
name|ArchiveMember
argument_list|(
name|Archive
operator|*
name|PAR
argument_list|)
block|;
comment|// So Archive can construct an ArchiveMember
name|friend
name|class
name|llvm
operator|::
name|Archive
block|;
comment|/// @}
block|}
decl_stmt|;
comment|/// This class defines the interface to LLVM Archive files. The Archive class
comment|/// presents the archive file as an ilist of ArchiveMember objects. The members
comment|/// can be rearranged in any fashion either by directly editing the ilist or by
comment|/// using editing methods on the Archive class (recommended). The Archive
comment|/// class also provides several ways of accessing the archive file for various
comment|/// purposes such as editing and linking.  Full symbol table support is provided
comment|/// for loading only those files that resolve symbols. Note that read
comment|/// performance of this library is _crucial_ for performance of JIT type
comment|/// applications and the linkers. Consequently, the implementation of the class
comment|/// is optimized for reading.
name|class
name|Archive
block|{
comment|/// @name Types
comment|/// @{
name|public
label|:
comment|/// This is the ilist type over which users may iterate to examine
comment|/// the contents of the archive
comment|/// @brief The ilist type of ArchiveMembers that Archive contains.
typedef|typedef
name|iplist
operator|<
name|ArchiveMember
operator|>
name|MembersList
expr_stmt|;
comment|/// @brief Forward mutable iterator over ArchiveMember
typedef|typedef
name|MembersList
operator|::
name|iterator
name|iterator
expr_stmt|;
comment|/// @brief Forward immutable iterator over ArchiveMember
typedef|typedef
name|MembersList
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
comment|/// @brief Reverse mutable iterator over ArchiveMember
typedef|typedef
name|std
operator|::
name|reverse_iterator
operator|<
name|iterator
operator|>
name|reverse_iterator
expr_stmt|;
comment|/// @brief Reverse immutable iterator over ArchiveMember
typedef|typedef
name|std
operator|::
name|reverse_iterator
operator|<
name|const_iterator
operator|>
name|const_reverse_iterator
expr_stmt|;
comment|/// @brief The in-memory version of the symbol table
typedef|typedef
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
name|unsigned
operator|>
name|SymTabType
expr_stmt|;
comment|/// @}
comment|/// @name ilist accessor methods
comment|/// @{
name|public
label|:
specifier|inline
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|members
operator|.
name|begin
argument_list|()
return|;
block|}
specifier|inline
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|members
operator|.
name|begin
argument_list|()
return|;
block|}
specifier|inline
name|iterator
name|end
parameter_list|()
block|{
return|return
name|members
operator|.
name|end
argument_list|()
return|;
block|}
specifier|inline
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|members
operator|.
name|end
argument_list|()
return|;
block|}
specifier|inline
name|reverse_iterator
name|rbegin
parameter_list|()
block|{
return|return
name|members
operator|.
name|rbegin
argument_list|()
return|;
block|}
specifier|inline
name|const_reverse_iterator
name|rbegin
argument_list|()
specifier|const
block|{
return|return
name|members
operator|.
name|rbegin
argument_list|()
return|;
block|}
specifier|inline
name|reverse_iterator
name|rend
parameter_list|()
block|{
return|return
name|members
operator|.
name|rend
argument_list|()
return|;
block|}
specifier|inline
name|const_reverse_iterator
name|rend
argument_list|()
specifier|const
block|{
return|return
name|members
operator|.
name|rend
argument_list|()
return|;
block|}
specifier|inline
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|members
operator|.
name|size
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|members
operator|.
name|empty
argument_list|()
return|;
block|}
specifier|inline
specifier|const
name|ArchiveMember
operator|&
name|front
argument_list|()
specifier|const
block|{
return|return
name|members
operator|.
name|front
argument_list|()
return|;
block|}
specifier|inline
name|ArchiveMember
modifier|&
name|front
parameter_list|()
block|{
return|return
name|members
operator|.
name|front
argument_list|()
return|;
block|}
specifier|inline
specifier|const
name|ArchiveMember
operator|&
name|back
argument_list|()
specifier|const
block|{
return|return
name|members
operator|.
name|back
argument_list|()
return|;
block|}
specifier|inline
name|ArchiveMember
modifier|&
name|back
parameter_list|()
block|{
return|return
name|members
operator|.
name|back
argument_list|()
return|;
block|}
comment|/// @}
comment|/// @name ilist mutator methods
comment|/// @{
name|public
label|:
comment|/// This method splices a \p src member from an archive (possibly \p this),
comment|/// to a position just before the member given by \p dest in \p this. When
comment|/// the archive is written, \p src will be written in its new location.
comment|/// @brief Move a member to a new location
specifier|inline
name|void
name|splice
parameter_list|(
name|iterator
name|dest
parameter_list|,
name|Archive
modifier|&
name|arch
parameter_list|,
name|iterator
name|src
parameter_list|)
block|{
return|return
name|members
operator|.
name|splice
argument_list|(
name|dest
argument_list|,
name|arch
operator|.
name|members
argument_list|,
name|src
argument_list|)
return|;
block|}
comment|/// This method erases a \p target member from the archive. When the
comment|/// archive is written, it will no longer contain \p target. The associated
comment|/// ArchiveMember is deleted.
comment|/// @brief Erase a member.
specifier|inline
name|iterator
name|erase
parameter_list|(
name|iterator
name|target
parameter_list|)
block|{
return|return
name|members
operator|.
name|erase
argument_list|(
name|target
argument_list|)
return|;
block|}
comment|/// @}
comment|/// @name Constructors
comment|/// @{
name|public
label|:
comment|/// Create an empty archive file and associate it with the \p Filename. This
comment|/// method does not actually create the archive disk file. It creates an
comment|/// empty Archive object. If the writeToDisk method is called, the archive
comment|/// file \p Filename will be created at that point, with whatever content
comment|/// the returned Archive object has at that time.
comment|/// @returns An Archive* that represents the new archive file.
comment|/// @brief Create an empty Archive.
specifier|static
name|Archive
modifier|*
name|CreateEmpty
argument_list|(
specifier|const
name|sys
operator|::
name|Path
operator|&
name|Filename
argument_list|,
comment|///< Name of the archive to (eventually) create.
name|LLVMContext
operator|&
name|C
comment|///< Context to use for global information
argument_list|)
decl_stmt|;
comment|/// Open an existing archive and load its contents in preparation for
comment|/// editing. After this call, the member ilist is completely populated based
comment|/// on the contents of the archive file. You should use this form of open if
comment|/// you intend to modify the archive or traverse its contents (e.g. for
comment|/// printing).
comment|/// @brief Open and load an archive file
specifier|static
name|Archive
modifier|*
name|OpenAndLoad
argument_list|(
specifier|const
name|sys
operator|::
name|Path
operator|&
name|filePath
argument_list|,
comment|///< The file path to open and load
name|LLVMContext
operator|&
name|C
argument_list|,
comment|///< The context to use for global information
name|std
operator|::
name|string
operator|*
name|ErrorMessage
comment|///< An optional error string
argument_list|)
decl_stmt|;
comment|/// This method opens an existing archive file from \p Filename and reads in
comment|/// its symbol table without reading in any of the archive's members. This
comment|/// reduces both I/O and cpu time in opening the archive if it is to be used
comment|/// solely for symbol lookup (e.g. during linking).  The \p Filename must
comment|/// exist and be an archive file or an exception will be thrown. This form
comment|/// of opening the archive is intended for read-only operations that need to
comment|/// locate members via the symbol table for link editing.  Since the archve
comment|/// members are not read by this method, the archive will appear empty upon
comment|/// return. If editing operations are performed on the archive, they will
comment|/// completely replace the contents of the archive! It is recommended that
comment|/// if this form of opening the archive is used that only the symbol table
comment|/// lookup methods (getSymbolTable, findModuleDefiningSymbol, and
comment|/// findModulesDefiningSymbols) be used.
comment|/// @throws std::string if an error occurs opening the file
comment|/// @returns an Archive* that represents the archive file.
comment|/// @brief Open an existing archive and load its symbols.
specifier|static
name|Archive
modifier|*
name|OpenAndLoadSymbols
argument_list|(
specifier|const
name|sys
operator|::
name|Path
operator|&
name|Filename
argument_list|,
comment|///< Name of the archive file to open
name|LLVMContext
operator|&
name|C
argument_list|,
comment|///< The context to use for global info
name|std
operator|::
name|string
operator|*
name|ErrorMessage
operator|=
literal|0
comment|///< An optional error string
argument_list|)
decl_stmt|;
comment|/// This destructor cleans up the Archive object, releases all memory, and
comment|/// closes files. It does nothing with the archive file on disk. If you
comment|/// haven't used the writeToDisk method by the time the destructor is
comment|/// called, all changes to the archive will be lost.
comment|/// @throws std::string if an error occurs
comment|/// @brief Destruct in-memory archive
operator|~
name|Archive
argument_list|()
expr_stmt|;
comment|/// @}
comment|/// @name Accessors
comment|/// @{
name|public
label|:
comment|/// @returns the path to the archive file.
comment|/// @brief Get the archive path.
specifier|const
name|sys
operator|::
name|Path
operator|&
name|getPath
argument_list|()
block|{
return|return
name|archPath
return|;
block|}
comment|/// This method is provided so that editing methods can be invoked directly
comment|/// on the Archive's iplist of ArchiveMember. However, it is recommended
comment|/// that the usual STL style iterator interface be used instead.
comment|/// @returns the iplist of ArchiveMember
comment|/// @brief Get the iplist of the members
name|MembersList
modifier|&
name|getMembers
parameter_list|()
block|{
return|return
name|members
return|;
block|}
comment|/// This method allows direct query of the Archive's symbol table. The
comment|/// symbol table is a std::map of std::string (the symbol) to unsigned (the
comment|/// file offset). Note that for efficiency reasons, the offset stored in
comment|/// the symbol table is not the actual offset. It is the offset from the
comment|/// beginning of the first "real" file member (after the symbol table). Use
comment|/// the getFirstFileOffset() to obtain that offset and add this value to the
comment|/// offset in the symbol table to obtain the real file offset. Note that
comment|/// there is purposefully no interface provided by Archive to look up
comment|/// members by their offset. Use the findModulesDefiningSymbols and
comment|/// findModuleDefiningSymbol methods instead.
comment|/// @returns the Archive's symbol table.
comment|/// @brief Get the archive's symbol table
specifier|const
name|SymTabType
modifier|&
name|getSymbolTable
parameter_list|()
block|{
return|return
name|symTab
return|;
block|}
comment|/// This method returns the offset in the archive file to the first "real"
comment|/// file member. Archive files, on disk, have a signature and might have a
comment|/// symbol table that precedes the first actual file member. This method
comment|/// allows you to determine what the size of those fields are.
comment|/// @returns the offset to the first "real" file member  in the archive.
comment|/// @brief Get the offset to the first "real" file member  in the archive.
name|unsigned
name|getFirstFileOffset
parameter_list|()
block|{
return|return
name|firstFileOffset
return|;
block|}
comment|/// This method will scan the archive for bitcode modules, interpret them
comment|/// and return a vector of the instantiated modules in \p Modules. If an
comment|/// error occurs, this method will return true. If \p ErrMessage is not null
comment|/// and an error occurs, \p *ErrMessage will be set to a string explaining
comment|/// the error that occurred.
comment|/// @returns true if an error occurred
comment|/// @brief Instantiate all the bitcode modules located in the archive
name|bool
name|getAllModules
argument_list|(
name|std
operator|::
name|vector
operator|<
name|Module
operator|*
operator|>
operator|&
name|Modules
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrMessage
argument_list|)
decl_stmt|;
comment|/// This accessor looks up the \p symbol in the archive's symbol table and
comment|/// returns the associated module that defines that symbol. This method can
comment|/// be called as many times as necessary. This is handy for linking the
comment|/// archive into another module based on unresolved symbols. Note that the
comment|/// ModuleProvider returned by this accessor should not be deleted by the
comment|/// caller. It is managed internally by the Archive class. It is possible
comment|/// that multiple calls to this accessor will return the same ModuleProvider
comment|/// instance because the associated module defines multiple symbols.
comment|/// @returns The ModuleProvider* found or null if the archive does not
comment|/// contain a module that defines the \p symbol.
comment|/// @brief Look up a module by symbol name.
name|ModuleProvider
modifier|*
name|findModuleDefiningSymbol
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|symbol
argument_list|,
comment|///< Symbol to be sought
name|std
operator|::
name|string
operator|*
name|ErrMessage
comment|///< Error message storage, if non-zero
argument_list|)
decl_stmt|;
comment|/// This method is similar to findModuleDefiningSymbol but allows lookup of
comment|/// more than one symbol at a time. If \p symbols contains a list of
comment|/// undefined symbols in some module, then calling this method is like
comment|/// making one complete pass through the archive to resolve symbols but is
comment|/// more efficient than looking at the individual members. Note that on
comment|/// exit, the symbols resolved by this method will be removed from \p
comment|/// symbols to ensure they are not re-searched on a subsequent call. If
comment|/// you need to retain the list of symbols, make a copy.
comment|/// @brief Look up multiple symbols in the archive.
name|bool
name|findModulesDefiningSymbols
argument_list|(
name|std
operator|::
name|set
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|symbols
argument_list|,
comment|///< Symbols to be sought
name|std
operator|::
name|set
operator|<
name|ModuleProvider
operator|*
operator|>
operator|&
name|modules
argument_list|,
comment|///< The modules matching \p symbols
name|std
operator|::
name|string
operator|*
name|ErrMessage
comment|///< Error msg storage, if non-zero
argument_list|)
decl_stmt|;
comment|/// This method determines whether the archive is a properly formed llvm
comment|/// bitcode archive.  It first makes sure the symbol table has been loaded
comment|/// and has a non-zero size.  If it does, then it is an archive.  If not,
comment|/// then it tries to load all the bitcode modules of the archive.  Finally,
comment|/// it returns whether it was successfull.
comment|/// @returns true if the archive is a proper llvm bitcode archive
comment|/// @brief Determine whether the archive is a proper llvm bitcode archive.
name|bool
name|isBitcodeArchive
parameter_list|()
function_decl|;
comment|/// @}
comment|/// @name Mutators
comment|/// @{
name|public
label|:
comment|/// This method is the only way to get the archive written to disk. It
comment|/// creates or overwrites the file specified when \p this was created
comment|/// or opened. The arguments provide options for writing the archive. If
comment|/// \p CreateSymbolTable is true, the archive is scanned for bitcode files
comment|/// and a symbol table of the externally visible function and global
comment|/// variable names is created. If \p TruncateNames is true, the names of the
comment|/// archive members will have their path component stripped and the file
comment|/// name will be truncated at 15 characters. If \p Compress is specified,
comment|/// all archive members will be compressed before being written. If
comment|/// \p PrintSymTab is true, the symbol table will be printed to std::cout.
comment|/// @returns true if an error occurred, \p error set to error message
comment|/// @returns false if the writing succeeded.
comment|/// @brief Write (possibly modified) archive contents to disk
name|bool
name|writeToDisk
argument_list|(
name|bool
name|CreateSymbolTable
operator|=
name|false
argument_list|,
comment|///< Create Symbol table
name|bool
name|TruncateNames
operator|=
name|false
argument_list|,
comment|///< Truncate the filename to 15 chars
name|bool
name|Compress
operator|=
name|false
argument_list|,
comment|///< Compress files
name|std
operator|::
name|string
operator|*
name|ErrMessage
operator|=
literal|0
comment|///< If non-null, where error msg is set
argument_list|)
decl_stmt|;
comment|/// This method adds a new file to the archive. The \p filename is examined
comment|/// to determine just enough information to create an ArchiveMember object
comment|/// which is then inserted into the Archive object's ilist at the location
comment|/// given by \p where.
comment|/// @returns true if an error occured, false otherwise
comment|/// @brief Add a file to the archive.
name|bool
name|addFileBefore
argument_list|(
specifier|const
name|sys
operator|::
name|Path
operator|&
name|filename
argument_list|,
comment|///< The file to be added
name|iterator
name|where
argument_list|,
comment|///< Insertion point
name|std
operator|::
name|string
operator|*
name|ErrMsg
comment|///< Optional error message location
argument_list|)
decl_stmt|;
comment|/// @}
comment|/// @name Implementation
comment|/// @{
name|protected
label|:
comment|/// @brief Construct an Archive for \p filename and optionally  map it
comment|/// into memory.
name|explicit
name|Archive
argument_list|(
specifier|const
name|sys
operator|::
name|Path
operator|&
name|filename
argument_list|,
name|LLVMContext
operator|&
name|C
argument_list|)
decl_stmt|;
comment|/// @param data The symbol table data to be parsed
comment|/// @param len  The length of the symbol table data
comment|/// @param error Set to address of a std::string to get error messages
comment|/// @returns false on error
comment|/// @brief Parse the symbol table at \p data.
name|bool
name|parseSymbolTable
argument_list|(
specifier|const
name|void
operator|*
name|data
argument_list|,
name|unsigned
name|len
argument_list|,
name|std
operator|::
name|string
operator|*
name|error
argument_list|)
decl_stmt|;
comment|/// @returns A fully populated ArchiveMember or 0 if an error occurred.
comment|/// @brief Parse the header of a member starting at \p At
name|ArchiveMember
modifier|*
name|parseMemberHeader
argument_list|(
specifier|const
name|char
operator|*
operator|&
name|At
argument_list|,
comment|///< The pointer to the location we're parsing
specifier|const
name|char
operator|*
name|End
argument_list|,
comment|///< The pointer to the end of the archive
name|std
operator|::
name|string
operator|*
name|error
comment|///< Optional error message catcher
argument_list|)
decl_stmt|;
comment|/// @param ErrMessage Set to address of a std::string to get error messages
comment|/// @returns false on error
comment|/// @brief Check that the archive signature is correct
name|bool
name|checkSignature
argument_list|(
name|std
operator|::
name|string
operator|*
name|ErrMessage
argument_list|)
decl_stmt|;
comment|/// @param ErrMessage Set to address of a std::string to get error messages
comment|/// @returns false on error
comment|/// @brief Load the entire archive.
name|bool
name|loadArchive
argument_list|(
name|std
operator|::
name|string
operator|*
name|ErrMessage
argument_list|)
decl_stmt|;
comment|/// @param ErrMessage Set to address of a std::string to get error messages
comment|/// @returns false on error
comment|/// @brief Load just the symbol table.
name|bool
name|loadSymbolTable
argument_list|(
name|std
operator|::
name|string
operator|*
name|ErrMessage
argument_list|)
decl_stmt|;
comment|/// @brief Write the symbol table to an ofstream.
name|void
name|writeSymbolTable
argument_list|(
name|std
operator|::
name|ofstream
operator|&
name|ARFile
argument_list|)
decl_stmt|;
comment|/// Writes one ArchiveMember to an ofstream. If an error occurs, returns
comment|/// false, otherwise true. If an error occurs and error is non-null then
comment|/// it will be set to an error message.
comment|/// @returns false Writing member succeeded
comment|/// @returns true Writing member failed, \p error set to error message
name|bool
name|writeMember
argument_list|(
specifier|const
name|ArchiveMember
operator|&
name|member
argument_list|,
comment|///< The member to be written
name|std
operator|::
name|ofstream
operator|&
name|ARFile
argument_list|,
comment|///< The file to write member onto
name|bool
name|CreateSymbolTable
argument_list|,
comment|///< Should symbol table be created?
name|bool
name|TruncateNames
argument_list|,
comment|///< Should names be truncated to 11 chars?
name|bool
name|ShouldCompress
argument_list|,
comment|///< Should the member be compressed?
name|std
operator|::
name|string
operator|*
name|ErrMessage
comment|///< If non-null, place were error msg is set
argument_list|)
decl_stmt|;
comment|/// @brief Fill in an ArchiveMemberHeader from ArchiveMember.
name|bool
name|fillHeader
argument_list|(
specifier|const
name|ArchiveMember
operator|&
name|mbr
argument_list|,
name|ArchiveMemberHeader
operator|&
name|hdr
argument_list|,
name|int
name|sz
argument_list|,
name|bool
name|TruncateNames
argument_list|)
decl|const
decl_stmt|;
comment|/// @brief Maps archive into memory
name|bool
name|mapToMemory
argument_list|(
name|std
operator|::
name|string
operator|*
name|ErrMsg
argument_list|)
decl_stmt|;
comment|/// @brief Frees all the members and unmaps the archive file.
name|void
name|cleanUpMemory
parameter_list|()
function_decl|;
comment|/// This type is used to keep track of bitcode modules loaded from the
comment|/// symbol table. It maps the file offset to a pair that consists of the
comment|/// associated ArchiveMember and the ModuleProvider.
comment|/// @brief Module mapping type
typedef|typedef
name|std
operator|::
name|map
operator|<
name|unsigned
operator|,
name|std
operator|::
name|pair
operator|<
name|ModuleProvider
operator|*
operator|,
name|ArchiveMember
operator|*
operator|>
expr|>
name|ModuleMap
expr_stmt|;
comment|/// @}
comment|/// @name Data
comment|/// @{
name|protected
label|:
name|sys
operator|::
name|Path
name|archPath
expr_stmt|;
comment|///< Path to the archive file we read/write
name|MembersList
name|members
decl_stmt|;
comment|///< The ilist of ArchiveMember
name|MemoryBuffer
modifier|*
name|mapfile
decl_stmt|;
comment|///< Raw Archive contents mapped into memory
specifier|const
name|char
modifier|*
name|base
decl_stmt|;
comment|///< Base of the memory mapped file data
name|SymTabType
name|symTab
decl_stmt|;
comment|///< The symbol table
name|std
operator|::
name|string
name|strtab
expr_stmt|;
comment|///< The string table for long file names
name|unsigned
name|symTabSize
decl_stmt|;
comment|///< Size in bytes of symbol table
name|unsigned
name|firstFileOffset
decl_stmt|;
comment|///< Offset to first normal file.
name|ModuleMap
name|modules
decl_stmt|;
comment|///< The modules loaded via symbol lookup.
name|ArchiveMember
modifier|*
name|foreignST
decl_stmt|;
comment|///< This holds the foreign symbol table.
name|LLVMContext
modifier|&
name|Context
decl_stmt|;
comment|///< This holds global data.
comment|/// @}
comment|/// @name Hidden
comment|/// @{
name|private
label|:
name|Archive
argument_list|()
expr_stmt|;
comment|///< Do not implement
name|Archive
argument_list|(
specifier|const
name|Archive
operator|&
argument_list|)
expr_stmt|;
comment|///< Do not implement
name|Archive
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Archive
operator|&
operator|)
decl_stmt|;
comment|///< Do not implement
comment|/// @}
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

