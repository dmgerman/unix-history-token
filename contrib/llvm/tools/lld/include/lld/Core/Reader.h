begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lld/Core/Reader.h - Abstract File Format Reading Interface ---------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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
name|LLD_CORE_READER_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_CORE_READER_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Reference.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/BinaryFormat/Magic.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorOr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FileSystem.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|yaml
block|{
name|class
name|IO
decl_stmt|;
block|}
comment|// end namespace yaml
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_decl_stmt
name|namespace
name|lld
block|{
name|class
name|File
decl_stmt|;
name|class
name|LinkingContext
decl_stmt|;
name|class
name|MachOLinkingContext
decl_stmt|;
comment|/// \brief An abstract class for reading object files, library files, and
comment|/// executable files.
comment|///
comment|/// Each file format (e.g. mach-o, etc) has a concrete subclass of Reader.
name|class
name|Reader
block|{
name|public
label|:
name|virtual
operator|~
name|Reader
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// Sniffs the file to determine if this Reader can parse it.
comment|/// The method is called with:
comment|/// 1) the file_magic enumeration returned by identify_magic()
comment|/// 2) the whole file content buffer if the above is not enough.
name|virtual
name|bool
name|canParse
argument_list|(
name|llvm
operator|::
name|file_magic
name|magic
argument_list|,
name|MemoryBufferRef
name|mb
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// \brief Parse a supplied buffer (already filled with the contents of a
comment|/// file) and create a File object.
comment|/// The resulting File object takes ownership of the MemoryBuffer.
name|virtual
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|File
operator|>>
name|loadFile
argument_list|(
argument|std::unique_ptr<MemoryBuffer> mb
argument_list|,
argument|const class Registry&
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
comment|/// \brief An abstract class for handling alternate yaml representations
comment|/// of object files.
comment|///
comment|/// The YAML syntax allows "tags" which are used to specify the type of
comment|/// the YAML node.  In lld, top level YAML documents can be in many YAML
comment|/// representations (e.g mach-o encoded as yaml, etc).  A tag is used to
comment|/// specify which representation is used in the following YAML document.
comment|/// To work, there must be a YamlIOTaggedDocumentHandler registered that
comment|/// handles each tag type.
name|class
name|YamlIOTaggedDocumentHandler
block|{
name|public
label|:
name|virtual
operator|~
name|YamlIOTaggedDocumentHandler
argument_list|()
expr_stmt|;
comment|/// This method is called on each registered YamlIOTaggedDocumentHandler
comment|/// until one returns true.  If the subclass handles tag type !xyz, then
comment|/// this method should call io.mapTag("!xzy") to see if that is the current
comment|/// document type, and if so, process the rest of the document using
comment|/// YAML I/O, then convert the result into an lld::File* and return it.
name|virtual
name|bool
name|handledDocTag
argument_list|(
name|llvm
operator|::
name|yaml
operator|::
name|IO
operator|&
name|io
argument_list|,
specifier|const
name|lld
operator|::
name|File
operator|*
operator|&
name|f
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
comment|/// A registry to hold the list of currently registered Readers and
comment|/// tables which map Reference kind values to strings.
comment|/// The linker does not directly invoke Readers.  Instead, it registers
comment|/// Readers based on it configuration and command line options, then calls
comment|/// the Registry object to parse files.
name|class
name|Registry
block|{
name|public
label|:
name|Registry
argument_list|()
expr_stmt|;
comment|/// Walk the list of registered Readers and find one that can parse the
comment|/// supplied file and parse it.
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|File
operator|>>
name|loadFile
argument_list|(
argument|std::unique_ptr<MemoryBuffer> mb
argument_list|)
specifier|const
expr_stmt|;
comment|/// Walk the list of registered kind tables to convert a Reference Kind
comment|/// name to a value.
name|bool
name|referenceKindFromString
argument_list|(
name|StringRef
name|inputStr
argument_list|,
name|Reference
operator|::
name|KindNamespace
operator|&
name|ns
argument_list|,
name|Reference
operator|::
name|KindArch
operator|&
name|a
argument_list|,
name|Reference
operator|::
name|KindValue
operator|&
name|value
argument_list|)
decl|const
decl_stmt|;
comment|/// Walk the list of registered kind tables to convert a Reference Kind
comment|/// value to a string.
name|bool
name|referenceKindToString
argument_list|(
name|Reference
operator|::
name|KindNamespace
name|ns
argument_list|,
name|Reference
operator|::
name|KindArch
name|a
argument_list|,
name|Reference
operator|::
name|KindValue
name|value
argument_list|,
name|StringRef
operator|&
argument_list|)
decl|const
decl_stmt|;
comment|/// Walk the list of registered tag handlers and have the one that handles
comment|/// the current document type process the yaml into an lld::File*.
name|bool
name|handleTaggedDoc
argument_list|(
name|llvm
operator|::
name|yaml
operator|::
name|IO
operator|&
name|io
argument_list|,
specifier|const
name|lld
operator|::
name|File
operator|*
operator|&
name|file
argument_list|)
decl|const
decl_stmt|;
comment|// These methods are called to dynamically add support for various file
comment|// formats. The methods are also implemented in the appropriate lib*.a
comment|// library, so that the code for handling a format is only linked in, if this
comment|// method is used.  Any options that a Reader might need must be passed
comment|// as parameters to the addSupport*() method.
name|void
name|addSupportArchives
parameter_list|(
name|bool
name|logLoading
parameter_list|)
function_decl|;
name|void
name|addSupportYamlFiles
parameter_list|()
function_decl|;
name|void
name|addSupportMachOObjects
parameter_list|(
name|MachOLinkingContext
modifier|&
parameter_list|)
function_decl|;
comment|/// To convert between kind values and names, the registry walks the list
comment|/// of registered kind tables. Each table is a zero terminated array of
comment|/// KindStrings elements.
struct|struct
name|KindStrings
block|{
name|Reference
operator|::
name|KindValue
name|value
expr_stmt|;
name|StringRef
name|name
decl_stmt|;
block|}
struct|;
comment|/// A Reference Kind value is a tuple of<namespace, arch, value>.  All
comment|/// entries in a conversion table have the same<namespace, arch>.  The
comment|/// array then contains the value/name pairs.
name|void
name|addKindTable
argument_list|(
name|Reference
operator|::
name|KindNamespace
name|ns
argument_list|,
name|Reference
operator|::
name|KindArch
name|arch
argument_list|,
specifier|const
name|KindStrings
name|array
index|[]
argument_list|)
decl_stmt|;
name|private
label|:
struct|struct
name|KindEntry
block|{
name|Reference
operator|::
name|KindNamespace
name|ns
expr_stmt|;
name|Reference
operator|::
name|KindArch
name|arch
expr_stmt|;
specifier|const
name|KindStrings
modifier|*
name|array
decl_stmt|;
block|}
struct|;
name|void
name|add
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|Reader
operator|>
argument_list|)
decl_stmt|;
name|void
name|add
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|YamlIOTaggedDocumentHandler
operator|>
argument_list|)
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Reader
operator|>>
name|_readers
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|YamlIOTaggedDocumentHandler
operator|>>
name|_yamlHandlers
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|KindEntry
operator|>
name|_kindEntries
expr_stmt|;
block|}
empty_stmt|;
comment|// Utilities for building a KindString table.  For instance:
comment|//   static const Registry::KindStrings table[] = {
comment|//      LLD_KIND_STRING_ENTRY(R_VAX_ADDR16),
comment|//      LLD_KIND_STRING_ENTRY(R_VAX_DATA16),
comment|//      LLD_KIND_STRING_END
comment|//   };
define|#
directive|define
name|LLD_KIND_STRING_ENTRY
parameter_list|(
name|name
parameter_list|)
value|{ name, #name }
define|#
directive|define
name|LLD_KIND_STRING_END
value|{ 0,    "" }
block|}
end_decl_stmt

begin_comment
comment|// end namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_CORE_READER_H
end_comment

end_unit

