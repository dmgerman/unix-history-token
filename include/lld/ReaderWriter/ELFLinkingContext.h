begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lld/ReaderWriter/ELFLinkingContext.h -------------------------------===//
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
name|LLD_READER_WRITER_ELF_LINKER_CONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_LINKER_CONTEXT_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/LinkingContext.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Pass.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/STDExtras.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/range.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Reader.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Writer.h"
end_include

begin_include
include|#
directive|include
file|"lld/ReaderWriter/LinkerScript.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ELF.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ELF.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<memory>
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
name|FileOutputBuffer
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lld
block|{
struct_decl|struct
name|AtomLayout
struct_decl|;
name|class
name|File
decl_stmt|;
name|class
name|Reference
decl_stmt|;
name|namespace
name|elf
block|{
name|using
name|llvm
operator|::
name|object
operator|::
name|ELF32LE
expr_stmt|;
name|using
name|llvm
operator|::
name|object
operator|::
name|ELF32BE
expr_stmt|;
name|using
name|llvm
operator|::
name|object
operator|::
name|ELF64LE
expr_stmt|;
name|using
name|llvm
operator|::
name|object
operator|::
name|ELF64BE
expr_stmt|;
name|class
name|ELFWriter
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|ELFLinkingContext
operator|>
name|createAArch64LinkingContext
argument_list|(
name|llvm
operator|::
name|Triple
argument_list|)
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|ELFLinkingContext
operator|>
name|createAMDGPULinkingContext
argument_list|(
name|llvm
operator|::
name|Triple
argument_list|)
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|ELFLinkingContext
operator|>
name|createARMLinkingContext
argument_list|(
name|llvm
operator|::
name|Triple
argument_list|)
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|ELFLinkingContext
operator|>
name|createExampleLinkingContext
argument_list|(
name|llvm
operator|::
name|Triple
argument_list|)
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|ELFLinkingContext
operator|>
name|createHexagonLinkingContext
argument_list|(
name|llvm
operator|::
name|Triple
argument_list|)
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|ELFLinkingContext
operator|>
name|createMipsLinkingContext
argument_list|(
name|llvm
operator|::
name|Triple
argument_list|)
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|ELFLinkingContext
operator|>
name|createX86LinkingContext
argument_list|(
name|llvm
operator|::
name|Triple
argument_list|)
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|ELFLinkingContext
operator|>
name|createX86_64LinkingContext
argument_list|(
name|llvm
operator|::
name|Triple
argument_list|)
expr_stmt|;
name|class
name|TargetRelocationHandler
block|{
name|public
label|:
name|virtual
operator|~
name|TargetRelocationHandler
argument_list|()
block|{}
name|virtual
name|std
operator|::
name|error_code
name|applyRelocation
argument_list|(
argument|ELFWriter&
argument_list|,
argument|llvm::FileOutputBuffer&
argument_list|,
argument|const lld::AtomLayout&
argument_list|,
argument|const Reference&
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// namespace elf
comment|/// \brief TargetHandler contains all the information responsible to handle a
comment|/// a particular target on ELF. A target might wish to override implementation
comment|/// of creating atoms and how the atoms are written to the output file.
name|class
name|TargetHandler
block|{
name|public
label|:
name|virtual
operator|~
name|TargetHandler
argument_list|()
block|{}
comment|/// Determines how relocations need to be applied.
name|virtual
specifier|const
name|elf
operator|::
name|TargetRelocationHandler
operator|&
name|getRelocationHandler
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// Returns a reader for object files.
name|virtual
name|std
operator|::
name|unique_ptr
operator|<
name|Reader
operator|>
name|getObjReader
argument_list|()
operator|=
literal|0
expr_stmt|;
comment|/// Returns a reader for .so files.
name|virtual
name|std
operator|::
name|unique_ptr
operator|<
name|Reader
operator|>
name|getDSOReader
argument_list|()
operator|=
literal|0
expr_stmt|;
comment|/// Returns a writer to write an ELF file.
name|virtual
name|std
operator|::
name|unique_ptr
operator|<
name|Writer
operator|>
name|getWriter
argument_list|()
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
name|class
name|ELFLinkingContext
range|:
name|public
name|LinkingContext
block|{
name|public
operator|:
comment|/// \brief The type of ELF executable that the linker
comment|/// creates.
expr|enum
name|class
name|OutputMagic
operator|:
name|uint8_t
block|{
comment|// The default mode, no specific magic set
name|DEFAULT
block|,
comment|// Disallow shared libraries and don't align sections
comment|// PageAlign Data, Mark Text Segment/Data segment RW
name|NMAGIC
block|,
comment|// Disallow shared libraries and don't align sections,
comment|// Mark Text Segment/Data segment RW
name|OMAGIC
block|,   }
block|;
comment|/// \brief ELF DT_FLAGS.
block|enum
name|DTFlag
operator|:
name|uint32_t
block|{
name|DT_NOW
operator|=
literal|1
operator|<<
literal|1
block|,
name|DT_ORIGIN
operator|=
literal|1
operator|<<
literal|2
block|,   }
block|;
name|llvm
operator|::
name|Triple
name|getTriple
argument_list|()
specifier|const
block|{
return|return
name|_triple
return|;
block|}
name|uint64_t
name|getPageSize
argument_list|()
specifier|const
block|{
return|return
name|_maxPageSize
return|;
block|}
name|void
name|setMaxPageSize
argument_list|(
argument|uint64_t v
argument_list|)
block|{
name|_maxPageSize
operator|=
name|v
block|; }
name|OutputMagic
name|getOutputMagic
argument_list|()
specifier|const
block|{
return|return
name|_outputMagic
return|;
block|}
name|uint16_t
name|getOutputELFType
argument_list|()
specifier|const
block|{
return|return
name|_outputELFType
return|;
block|}
name|uint16_t
name|getOutputMachine
argument_list|()
specifier|const
block|;
name|bool
name|mergeCommonStrings
argument_list|()
specifier|const
block|{
return|return
name|_mergeCommonStrings
return|;
block|}
name|virtual
name|int
name|getMachineType
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|uint64_t
name|getBaseAddress
argument_list|()
specifier|const
block|{
return|return
name|_baseAddress
return|;
block|}
name|virtual
name|void
name|setBaseAddress
argument_list|(
argument|uint64_t address
argument_list|)
block|{
name|_baseAddress
operator|=
name|address
block|; }
name|void
name|notifySymbolTableCoalesce
argument_list|(
argument|const Atom *existingAtom
argument_list|,
argument|const Atom *newAtom
argument_list|,
argument|bool&useNew
argument_list|)
name|override
block|;
comment|/// This controls if undefined atoms need to be created for undefines that are
comment|/// present in a SharedLibrary. If this option is set, undefined atoms are
comment|/// created for every undefined symbol that are present in the dynamic table
comment|/// in the shared library
name|bool
name|useShlibUndefines
argument_list|()
specifier|const
block|{
return|return
name|_useShlibUndefines
return|;
block|}
comment|/// \brief Returns true if a given relocation should be added to the
comment|/// dynamic relocation table.
comment|///
comment|/// This table is evaluated at loadtime by the dynamic loader and is
comment|/// referenced by the DT_RELA{,ENT,SZ} entries in the dynamic table.
comment|/// Relocations that return true will be added to the dynamic relocation
comment|/// table.
name|virtual
name|bool
name|isDynamicRelocation
argument_list|(
argument|const Reference&
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Returns true if a given reference is a copy relocation.
comment|///
comment|/// If this is a copy relocation, its target must be an ObjectAtom. We must
comment|/// include in DT_NEEDED the name of the library where this object came from.
name|virtual
name|bool
name|isCopyRelocation
argument_list|(
argument|const Reference&
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
name|bool
name|validateImpl
argument_list|(
argument|raw_ostream&diagnostics
argument_list|)
name|override
block|;
comment|/// \brief Returns true if the linker allows dynamic libraries to be
comment|/// linked with.
comment|///
comment|/// This is true when the output mode of the executable is set to be
comment|/// having NMAGIC/OMAGIC
name|bool
name|allowLinkWithDynamicLibraries
argument_list|()
specifier|const
block|{
if|if
condition|(
name|_outputMagic
operator|==
name|OutputMagic
operator|::
name|NMAGIC
operator|||
name|_outputMagic
operator|==
name|OutputMagic
operator|::
name|OMAGIC
operator|||
name|_noAllowDynamicLibraries
condition|)
return|return
name|false
return|;
return|return
name|true
return|;
block|}
comment|/// \brief Use Elf_Rela format to output relocation tables.
name|virtual
name|bool
name|isRelaOutputFormat
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// \brief Returns true if a given relocation should be added to PLT.
comment|///
comment|/// This table holds all of the relocations used for delayed symbol binding.
comment|/// It will be evaluated at load time if LD_BIND_NOW is set. It is referenced
comment|/// by the DT_{JMPREL,PLTRELSZ} entries in the dynamic table.
comment|/// Relocations that return true will be added to the dynamic plt relocation
comment|/// table.
name|virtual
name|bool
name|isPLTRelocation
argument_list|(
specifier|const
name|Reference
operator|&
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief The path to the dynamic interpreter
name|virtual
name|StringRef
name|getDefaultInterpreter
argument_list|()
specifier|const
block|{
return|return
literal|"/lib64/ld-linux-x86-64.so.2"
return|;
block|}
comment|/// \brief The dynamic linker path set by the --dynamic-linker option
name|StringRef
name|getInterpreter
argument_list|()
specifier|const
block|{
if|if
condition|(
name|_dynamicLinkerPath
operator|.
name|hasValue
argument_list|()
condition|)
return|return
name|_dynamicLinkerPath
operator|.
name|getValue
argument_list|()
return|;
return|return
name|getDefaultInterpreter
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Returns true if the output have dynamic sections.
end_comment

begin_expr_stmt
name|bool
name|isDynamic
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Returns true if we are creating a shared library.
end_comment

begin_expr_stmt
name|bool
name|isDynamicLibrary
argument_list|()
specifier|const
block|{
return|return
name|_outputELFType
operator|==
name|llvm
operator|::
name|ELF
operator|::
name|ET_DYN
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns true if a given relocation is a relative relocation.
end_comment

begin_decl_stmt
name|virtual
name|bool
name|isRelativeReloc
argument_list|(
specifier|const
name|Reference
operator|&
name|r
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|TargetHandler
operator|&
name|getTargetHandler
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|_targetHandler
operator|&&
literal|"Got null TargetHandler!"
argument_list|)
block|;
return|return
operator|*
name|_targetHandler
return|;
block|}
end_expr_stmt

begin_function_decl
name|virtual
name|void
name|registerRelocationNames
parameter_list|(
name|Registry
modifier|&
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|addPasses
argument_list|(
name|PassManager
operator|&
name|pm
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setTriple
argument_list|(
name|llvm
operator|::
name|Triple
name|trip
argument_list|)
block|{
name|_triple
operator|=
name|trip
expr_stmt|;
block|}
end_decl_stmt

begin_function
name|void
name|setNoInhibitExec
parameter_list|(
name|bool
name|v
parameter_list|)
block|{
name|_noInhibitExec
operator|=
name|v
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setExportDynamic
parameter_list|(
name|bool
name|v
parameter_list|)
block|{
name|_exportDynamic
operator|=
name|v
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setIsStaticExecutable
parameter_list|(
name|bool
name|v
parameter_list|)
block|{
name|_isStaticExecutable
operator|=
name|v
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setMergeCommonStrings
parameter_list|(
name|bool
name|v
parameter_list|)
block|{
name|_mergeCommonStrings
operator|=
name|v
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setUseShlibUndefines
parameter_list|(
name|bool
name|use
parameter_list|)
block|{
name|_useShlibUndefines
operator|=
name|use
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setOutputELFType
parameter_list|(
name|uint32_t
name|type
parameter_list|)
block|{
name|_outputELFType
operator|=
name|type
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|shouldExportDynamic
argument_list|()
specifier|const
block|{
return|return
name|_exportDynamic
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|createInternalFiles
argument_list|(
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|File
operator|>>
operator|&
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|void
name|finalizeInputFiles
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Set the dynamic linker path
end_comment

begin_function
name|void
name|setInterpreter
parameter_list|(
name|StringRef
name|s
parameter_list|)
block|{
name|_dynamicLinkerPath
operator|=
name|s
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Set NMAGIC output kind when the linker specifies --nmagic
end_comment

begin_comment
comment|/// or -n in the command line
end_comment

begin_comment
comment|/// Set OMAGIC output kind when the linker specifies --omagic
end_comment

begin_comment
comment|/// or -N in the command line
end_comment

begin_function
name|void
name|setOutputMagic
parameter_list|(
name|OutputMagic
name|magic
parameter_list|)
block|{
name|_outputMagic
operator|=
name|magic
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Disallow dynamic libraries during linking
end_comment

begin_function
name|void
name|setNoAllowDynamicLibraries
parameter_list|()
block|{
name|_noAllowDynamicLibraries
operator|=
name|true
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Searches directories for a match on the input File
end_comment

begin_expr_stmt
name|ErrorOr
operator|<
name|StringRef
operator|>
name|searchLibrary
argument_list|(
argument|StringRef libName
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Searches directories for a match on the input file.
end_comment

begin_comment
comment|/// If \p fileName is an absolute path and \p isSysRooted is true, check
end_comment

begin_comment
comment|/// the file under sysroot directory. If \p fileName is a relative path
end_comment

begin_comment
comment|/// and is not in the current directory, search the file through library
end_comment

begin_comment
comment|/// search directories.
end_comment

begin_expr_stmt
name|ErrorOr
operator|<
name|StringRef
operator|>
name|searchFile
argument_list|(
argument|StringRef fileName
argument_list|,
argument|bool isSysRooted
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Get the entry symbol name
end_comment

begin_expr_stmt
name|StringRef
name|entrySymbolName
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Set new initializer function
end_comment

begin_function
name|void
name|setInitFunction
parameter_list|(
name|StringRef
name|name
parameter_list|)
block|{
name|_initFunction
operator|=
name|name
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Return an initializer function name.
end_comment

begin_comment
comment|/// Either default "_init" or configured by the -init command line option.
end_comment

begin_expr_stmt
name|StringRef
name|initFunction
argument_list|()
specifier|const
block|{
return|return
name|_initFunction
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Set new finalizer function
end_comment

begin_function
name|void
name|setFiniFunction
parameter_list|(
name|StringRef
name|name
parameter_list|)
block|{
name|_finiFunction
operator|=
name|name
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Return a finalizer function name.
end_comment

begin_comment
comment|/// Either default "_fini" or configured by the -fini command line option.
end_comment

begin_expr_stmt
name|StringRef
name|finiFunction
argument_list|()
specifier|const
block|{
return|return
name|_finiFunction
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Add an absolute symbol. Used for --defsym.
end_comment

begin_function
name|void
name|addInitialAbsoluteSymbol
parameter_list|(
name|StringRef
name|name
parameter_list|,
name|uint64_t
name|addr
parameter_list|)
block|{
name|_absoluteSymbols
index|[
name|name
index|]
operator|=
name|addr
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|StringRef
name|sharedObjectName
argument_list|()
specifier|const
block|{
return|return
name|_soname
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setSharedObjectName
parameter_list|(
name|StringRef
name|soname
parameter_list|)
block|{
name|_soname
operator|=
name|soname
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|StringRef
name|getSysroot
argument_list|()
specifier|const
block|{
return|return
name|_sysrootPath
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setSysroot
parameter_list|(
name|StringRef
name|path
parameter_list|)
block|{
name|_sysrootPath
operator|=
name|path
expr_stmt|;
block|}
end_function

begin_function
name|void
name|addRpath
parameter_list|(
name|StringRef
name|path
parameter_list|)
block|{
name|_rpathList
operator|.
name|push_back
argument_list|(
name|path
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|range
operator|<
specifier|const
name|StringRef
operator|*
operator|>
name|getRpathList
argument_list|()
specifier|const
block|{
return|return
name|_rpathList
return|;
block|}
end_expr_stmt

begin_function
name|void
name|addRpathLink
parameter_list|(
name|StringRef
name|path
parameter_list|)
block|{
name|_rpathLinkList
operator|.
name|push_back
argument_list|(
name|path
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|range
operator|<
specifier|const
name|StringRef
operator|*
operator|>
name|getRpathLinkList
argument_list|()
specifier|const
block|{
return|return
name|_rpathLinkList
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
name|uint64_t
operator|>
operator|&
name|getAbsoluteSymbols
argument_list|()
specifier|const
block|{
return|return
name|_absoluteSymbols
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Helper function to allocate strings.
end_comment

begin_decl_stmt
name|StringRef
name|allocateString
argument_list|(
name|StringRef
name|ref
argument_list|)
decl|const
block|{
name|char
modifier|*
name|x
init|=
name|_allocator
operator|.
name|Allocate
operator|<
name|char
operator|>
operator|(
name|ref
operator|.
name|size
argument_list|()
operator|+
literal|1
operator|)
decl_stmt|;
name|memcpy
argument_list|(
name|x
argument_list|,
name|ref
operator|.
name|data
argument_list|()
argument_list|,
name|ref
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|x
index|[
name|ref
operator|.
name|size
argument_list|()
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
name|x
return|;
block|}
end_decl_stmt

begin_comment
comment|// add search path to list.
end_comment

begin_function
name|void
name|addSearchPath
parameter_list|(
name|StringRef
name|ref
parameter_list|)
block|{
name|_inputSearchPaths
operator|.
name|push_back
argument_list|(
name|ref
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Retrieve search path list.
end_comment

begin_function
name|StringRefVector
name|getSearchPaths
parameter_list|()
block|{
return|return
name|_inputSearchPaths
return|;
block|}
end_function

begin_comment
comment|// By default, the linker would merge sections that are read only with
end_comment

begin_comment
comment|// segments that have read and execute permissions. When the user specifies a
end_comment

begin_comment
comment|// flag --rosegment, a separate segment needs to be created.
end_comment

begin_expr_stmt
name|bool
name|mergeRODataToTextSegment
argument_list|()
specifier|const
block|{
return|return
name|_mergeRODataToTextSegment
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setCreateSeparateROSegment
parameter_list|()
block|{
name|_mergeRODataToTextSegment
operator|=
name|false
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|bool
name|isDynamicallyExportedSymbol
argument_list|(
name|StringRef
name|name
argument_list|)
decl|const
block|{
return|return
name|_dynamicallyExportedSymbols
operator|.
name|count
argument_list|(
name|name
argument_list|)
operator|!=
literal|0
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Demangle symbols.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|demangle
argument_list|(
argument|StringRef symbolName
argument_list|)
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|demangleSymbols
argument_list|()
specifier|const
block|{
return|return
name|_demangle
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setDemangleSymbols
parameter_list|(
name|bool
name|d
parameter_list|)
block|{
name|_demangle
operator|=
name|d
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Align segments.
end_comment

begin_expr_stmt
name|bool
name|alignSegments
argument_list|()
specifier|const
block|{
return|return
name|_alignSegments
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setAlignSegments
parameter_list|(
name|bool
name|align
parameter_list|)
block|{
name|_alignSegments
operator|=
name|align
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Enable new dtags.
end_comment

begin_comment
comment|/// If this flag is set lld emits DT_RUNPATH instead of
end_comment

begin_comment
comment|/// DT_RPATH. They are functionally equivalent except for
end_comment

begin_comment
comment|/// the following two differences:
end_comment

begin_comment
comment|/// - DT_RUNPATH is searched after LD_LIBRARY_PATH, while
end_comment

begin_comment
comment|/// DT_RPATH is searched before.
end_comment

begin_comment
comment|/// - DT_RUNPATH is used only to search for direct dependencies
end_comment

begin_comment
comment|/// of the object it's contained in, while DT_RPATH is used
end_comment

begin_comment
comment|/// for indirect dependencies as well.
end_comment

begin_expr_stmt
name|bool
name|getEnableNewDtags
argument_list|()
specifier|const
block|{
return|return
name|_enableNewDtags
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setEnableNewDtags
parameter_list|(
name|bool
name|e
parameter_list|)
block|{
name|_enableNewDtags
operator|=
name|e
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Discard local symbols.
end_comment

begin_expr_stmt
name|bool
name|discardLocals
argument_list|()
specifier|const
block|{
return|return
name|_discardLocals
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setDiscardLocals
parameter_list|(
name|bool
name|d
parameter_list|)
block|{
name|_discardLocals
operator|=
name|d
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Discard temprorary local symbols.
end_comment

begin_expr_stmt
name|bool
name|discardTempLocals
argument_list|()
specifier|const
block|{
return|return
name|_discardTempLocals
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setDiscardTempLocals
parameter_list|(
name|bool
name|d
parameter_list|)
block|{
name|_discardTempLocals
operator|=
name|d
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Strip symbols.
end_comment

begin_expr_stmt
name|bool
name|stripSymbols
argument_list|()
specifier|const
block|{
return|return
name|_stripSymbols
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setStripSymbols
parameter_list|(
name|bool
name|strip
parameter_list|)
block|{
name|_stripSymbols
operator|=
name|strip
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Collect statistics.
end_comment

begin_expr_stmt
name|bool
name|collectStats
argument_list|()
specifier|const
block|{
return|return
name|_collectStats
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setCollectStats
parameter_list|(
name|bool
name|s
parameter_list|)
block|{
name|_collectStats
operator|=
name|s
expr_stmt|;
block|}
end_function

begin_comment
comment|// --wrap option.
end_comment

begin_function
name|void
name|addWrapForSymbol
parameter_list|(
name|StringRef
name|sym
parameter_list|)
block|{
name|_wrapCalls
operator|.
name|insert
argument_list|(
name|sym
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// \brief Set DT_FLAGS flag.
end_comment

begin_function
name|void
name|setDTFlag
parameter_list|(
name|DTFlag
name|f
parameter_list|)
block|{
name|_dtFlags
operator||=
name|f
expr_stmt|;
block|}
end_function

begin_function
name|bool
name|getDTFlag
parameter_list|(
name|DTFlag
name|f
parameter_list|)
block|{
return|return
operator|(
name|_dtFlags
operator|&
name|f
operator|)
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|llvm
operator|::
name|StringSet
operator|<
operator|>
operator|&
name|wrapCalls
argument_list|()
specifier|const
block|{
return|return
name|_wrapCalls
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|setUndefinesResolver
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|File
operator|>
name|resolver
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|script
operator|::
name|Sema
operator|&
name|linkerScriptSema
argument_list|()
block|{
return|return
name|_linkerScriptSema
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|script
operator|::
name|Sema
operator|&
name|linkerScriptSema
argument_list|()
specifier|const
block|{
return|return
name|_linkerScriptSema
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Notify the ELFLinkingContext when the new ELF section is read.
end_comment

begin_function_decl
name|void
name|notifyInputSectionName
parameter_list|(
name|StringRef
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Encountered C-ident input section names.
end_comment

begin_expr_stmt
specifier|const
name|llvm
operator|::
name|StringSet
operator|<
operator|>
operator|&
name|cidentSectionNames
argument_list|()
specifier|const
block|{
return|return
name|_cidentSections
return|;
block|}
end_expr_stmt

begin_comment
comment|// Set R_ARM_TARGET1 relocation behaviour
end_comment

begin_expr_stmt
name|bool
name|armTarget1Rel
argument_list|()
specifier|const
block|{
return|return
name|_armTarget1Rel
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setArmTarget1Rel
parameter_list|(
name|bool
name|value
parameter_list|)
block|{
name|_armTarget1Rel
operator|=
name|value
expr_stmt|;
block|}
end_function

begin_comment
comment|// Set R_MIPS_EH relocation behaviour.
end_comment

begin_expr_stmt
name|bool
name|mipsPcRelEhRel
argument_list|()
specifier|const
block|{
return|return
name|_mipsPcRelEhRel
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setMipsPcRelEhRel
parameter_list|(
name|bool
name|value
parameter_list|)
block|{
name|_mipsPcRelEhRel
operator|=
name|value
expr_stmt|;
block|}
end_function

begin_label
name|protected
label|:
end_label

begin_macro
name|ELFLinkingContext
argument_list|(
argument|llvm::Triple triple
argument_list|,
argument|std::unique_ptr<TargetHandler> handler
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|_triple
argument_list|(
name|triple
argument_list|)
operator|,
name|_targetHandler
argument_list|(
argument|std::move(handler)
argument_list|)
block|{}
name|Writer
operator|&
name|writer
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Method to create a internal file for an undefined symbol
end_comment

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|File
operator|>
name|createUndefinedSymbolFile
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|uint16_t
name|_outputELFType
init|=
name|llvm
operator|::
name|ELF
operator|::
name|ET_EXEC
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|Triple
name|_triple
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|TargetHandler
operator|>
name|_targetHandler
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|uint64_t
name|_baseAddress
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|_isStaticExecutable
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|_noInhibitExec
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|_exportDynamic
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|_mergeCommonStrings
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|_useShlibUndefines
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|_dynamicLinkerArg
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|_noAllowDynamicLibraries
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|_mergeRODataToTextSegment
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|_demangle
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|_discardTempLocals
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|_discardLocals
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|_stripSymbols
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|_alignSegments
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|_enableNewDtags
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|_collectStats
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|_armTarget1Rel
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|_mipsPcRelEhRel
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint64_t
name|_maxPageSize
init|=
literal|0x1000
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|_dtFlags
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OutputMagic
name|_outputMagic
init|=
name|OutputMagic
operator|::
name|DEFAULT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|StringRefVector
name|_inputSearchPaths
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|Writer
operator|>
name|_writer
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Optional
operator|<
name|StringRef
operator|>
name|_dynamicLinkerPath
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|StringRef
name|_initFunction
init|=
literal|"_init"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|StringRef
name|_finiFunction
init|=
literal|"_fini"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|StringRef
name|_sysrootPath
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|StringRef
name|_soname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|StringRefVector
name|_rpathList
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|StringRefVector
name|_rpathLinkList
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|StringSet
operator|<
operator|>
name|_wrapCalls
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
name|uint64_t
operator|>
name|_absoluteSymbols
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|StringSet
operator|<
operator|>
name|_dynamicallyExportedSymbols
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|File
operator|>
name|_resolver
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|mutex
name|_cidentMutex
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|StringSet
operator|<
operator|>
name|_cidentSections
expr_stmt|;
end_expr_stmt

begin_comment
comment|// The linker script semantic object, which owns all script ASTs, is stored
end_comment

begin_comment
comment|// in the current linking context via _linkerScriptSema.
end_comment

begin_expr_stmt
name|script
operator|::
name|Sema
name|_linkerScriptSema
expr_stmt|;
end_expr_stmt

begin_comment
unit|};  }
comment|// end namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

