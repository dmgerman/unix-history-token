begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/BinaryFormat/Magic.h - File magic identification ----*- C++ -*-===//
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
name|LLVM_BINARYFORMAT_MAGIC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_BINARYFORMAT_MAGIC_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|<system_error>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// file_magic - An "enum class" enumeration of file types based on magic (the
comment|/// first N bytes of the file).
struct|struct
name|file_magic
block|{
enum|enum
name|Impl
block|{
name|unknown
init|=
literal|0
block|,
comment|///< Unrecognized file
name|bitcode
block|,
comment|///< Bitcode file
name|archive
block|,
comment|///< ar style archive file
name|elf
block|,
comment|///< ELF Unknown type
name|elf_relocatable
block|,
comment|///< ELF Relocatable object file
name|elf_executable
block|,
comment|///< ELF Executable image
name|elf_shared_object
block|,
comment|///< ELF dynamically linked shared lib
name|elf_core
block|,
comment|///< ELF core image
name|macho_object
block|,
comment|///< Mach-O Object file
name|macho_executable
block|,
comment|///< Mach-O Executable
name|macho_fixed_virtual_memory_shared_lib
block|,
comment|///< Mach-O Shared Lib, FVM
name|macho_core
block|,
comment|///< Mach-O Core File
name|macho_preload_executable
block|,
comment|///< Mach-O Preloaded Executable
name|macho_dynamically_linked_shared_lib
block|,
comment|///< Mach-O dynlinked shared lib
name|macho_dynamic_linker
block|,
comment|///< The Mach-O dynamic linker
name|macho_bundle
block|,
comment|///< Mach-O Bundle file
name|macho_dynamically_linked_shared_lib_stub
block|,
comment|///< Mach-O Shared lib stub
name|macho_dsym_companion
block|,
comment|///< Mach-O dSYM companion file
name|macho_kext_bundle
block|,
comment|///< Mach-O kext bundle file
name|macho_universal_binary
block|,
comment|///< Mach-O universal binary
name|coff_cl_gl_object
block|,
comment|///< Microsoft cl.exe's intermediate code file
name|coff_object
block|,
comment|///< COFF object file
name|coff_import_library
block|,
comment|///< COFF import library
name|pecoff_executable
block|,
comment|///< PECOFF executable file
name|windows_resource
block|,
comment|///< Windows compiled resource file (.res)
name|wasm_object
comment|///< WebAssembly Object file
block|}
enum|;
name|bool
name|is_object
argument_list|()
specifier|const
block|{
return|return
name|V
operator|!=
name|unknown
return|;
block|}
name|file_magic
argument_list|()
operator|=
expr|default
expr_stmt|;
name|file_magic
argument_list|(
argument|Impl V
argument_list|)
block|:
name|V
argument_list|(
argument|V
argument_list|)
block|{}
name|operator
name|Impl
argument_list|()
specifier|const
block|{
return|return
name|V
return|;
block|}
name|private
label|:
name|Impl
name|V
init|=
name|unknown
decl_stmt|;
block|}
struct|;
comment|/// @brief Identify the type of a binary file based on how magical it is.
name|file_magic
name|identify_magic
parameter_list|(
name|StringRef
name|magic
parameter_list|)
function_decl|;
comment|/// @brief Get and identify \a path's type based on its content.
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to the type of file, or file_magic::unknown.
comment|/// @returns errc::success if result has been successfully set, otherwise a
comment|///          platform-specific error_code.
name|std
operator|::
name|error_code
name|identify_magic
argument_list|(
specifier|const
name|Twine
operator|&
name|path
argument_list|,
name|file_magic
operator|&
name|result
argument_list|)
expr_stmt|;
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

