begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lld/ReaderWriter/MachOLinkingContext.h -----------------------------===//
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
name|LLD_READER_WRITER_MACHO_LINKING_CONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_MACHO_LINKING_CONTEXT_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/LinkingContext.h"
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
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/BinaryFormat/MachO.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_expr_stmt
name|using
name|llvm
operator|::
name|MachO
operator|::
name|HeaderFileType
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|mach_o
block|{
name|class
name|ArchHandler
decl_stmt|;
name|class
name|MachODylibFile
decl_stmt|;
name|class
name|MachOFile
decl_stmt|;
name|class
name|SectCreateFile
decl_stmt|;
block|}
name|class
name|MachOLinkingContext
range|:
name|public
name|LinkingContext
block|{
name|public
operator|:
name|MachOLinkingContext
argument_list|()
block|;
operator|~
name|MachOLinkingContext
argument_list|()
name|override
block|;    enum
name|Arch
block|{
name|arch_unknown
block|,
name|arch_ppc
block|,
name|arch_x86
block|,
name|arch_x86_64
block|,
name|arch_armv6
block|,
name|arch_armv7
block|,
name|arch_armv7s
block|,
name|arch_arm64
block|,   }
block|;    enum
name|class
name|OS
block|{
name|unknown
block|,
name|macOSX
block|,
name|iOS
block|,
name|iOS_simulator
block|}
block|;    enum
name|class
name|ExportMode
block|{
name|globals
block|,
comment|// Default, all global symbols exported.
name|whiteList
block|,
comment|// -exported_symbol[s_list], only listed symbols exported.
name|blackList
comment|// -unexported_symbol[s_list], no listed symbol exported.
block|}
block|;    enum
name|class
name|DebugInfoMode
block|{
name|addDebugMap
block|,
comment|// Default
name|noDebugMap
comment|// -S option
block|}
block|;    enum
name|class
name|UndefinedMode
block|{
name|error
block|,
name|warning
block|,
name|suppress
block|,
name|dynamicLookup
block|}
block|;    enum
name|ObjCConstraint
block|{
name|objc_unknown
operator|=
literal|0
block|,
name|objc_supports_gc
operator|=
literal|2
block|,
name|objc_gc_only
operator|=
literal|4
block|,
comment|// Image optimized by dyld = 8
comment|// GC compaction = 16
name|objc_retainReleaseForSimulator
operator|=
literal|32
block|,
name|objc_retainRelease
block|}
block|;
comment|/// Initializes the context to sane default values given the specified output
comment|/// file type, arch, os, and minimum os version.  This should be called before
comment|/// other setXXX() methods.
name|void
name|configure
argument_list|(
argument|HeaderFileType type
argument_list|,
argument|Arch arch
argument_list|,
argument|OS os
argument_list|,
argument|uint32_t minOSVersion
argument_list|,
argument|bool exportDynamicSymbols
argument_list|)
block|;
name|void
name|addPasses
argument_list|(
argument|PassManager&pm
argument_list|)
name|override
block|;
name|bool
name|validateImpl
argument_list|(
argument|raw_ostream&diagnostics
argument_list|)
name|override
block|;
name|std
operator|::
name|string
name|demangle
argument_list|(
argument|StringRef symbolName
argument_list|)
specifier|const
name|override
block|;
name|void
name|createImplicitFiles
argument_list|(
argument|std::vector<std::unique_ptr<File>>&
argument_list|)
name|override
block|;
comment|/// Creates a new file which is owned by the context.  Returns a pointer to
comment|/// the new file.
name|template
operator|<
name|class
name|T
block|,
name|class
operator|...
name|Args
operator|>
name|typename
name|std
operator|::
name|enable_if
operator|<
operator|!
name|std
operator|::
name|is_array
operator|<
name|T
operator|>
operator|::
name|value
block|,
name|T
operator|*
operator|>
operator|::
name|type
name|make_file
argument_list|(
argument|Args&&... args
argument_list|)
specifier|const
block|{
name|auto
name|file
operator|=
name|std
operator|::
name|unique_ptr
operator|<
name|T
operator|>
operator|(
name|new
name|T
argument_list|(
name|std
operator|::
name|forward
operator|<
name|Args
operator|>
operator|(
name|args
operator|)
operator|...
argument_list|)
operator|)
block|;
name|auto
operator|*
name|filePtr
operator|=
name|file
operator|.
name|get
argument_list|()
block|;
name|auto
operator|*
name|ctx
operator|=
name|const_cast
operator|<
name|MachOLinkingContext
operator|*
operator|>
operator|(
name|this
operator|)
block|;
name|ctx
operator|->
name|getNodes
argument_list|()
operator|.
name|push_back
argument_list|(
name|llvm
operator|::
name|make_unique
operator|<
name|FileNode
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
name|file
argument_list|)
operator|)
argument_list|)
block|;
return|return
name|filePtr
return|;
block|}
name|uint32_t
name|getCPUType
argument_list|()
specifier|const
block|;
name|uint32_t
name|getCPUSubType
argument_list|()
specifier|const
block|;
name|bool
name|addEntryPointLoadCommand
argument_list|()
specifier|const
block|;
name|bool
name|addUnixThreadLoadCommand
argument_list|()
specifier|const
block|;
name|bool
name|outputTypeHasEntry
argument_list|()
specifier|const
block|;
name|bool
name|is64Bit
argument_list|()
specifier|const
block|;
name|virtual
name|uint64_t
name|pageZeroSize
argument_list|()
specifier|const
block|{
return|return
name|_pageZeroSize
return|;
block|}
name|virtual
name|uint64_t
name|pageSize
argument_list|()
specifier|const
block|{
return|return
name|_pageSize
return|;
block|}
name|mach_o
operator|::
name|ArchHandler
operator|&
name|archHandler
argument_list|()
specifier|const
block|;
name|HeaderFileType
name|outputMachOType
argument_list|()
specifier|const
block|{
return|return
name|_outputMachOType
return|;
block|}
name|Arch
name|arch
argument_list|()
specifier|const
block|{
return|return
name|_arch
return|;
block|}
name|StringRef
name|archName
argument_list|()
specifier|const
block|{
return|return
name|nameFromArch
argument_list|(
name|_arch
argument_list|)
return|;
block|}
name|OS
name|os
argument_list|()
specifier|const
block|{
return|return
name|_os
return|;
block|}
name|ExportMode
name|exportMode
argument_list|()
specifier|const
block|{
return|return
name|_exportMode
return|;
block|}
name|void
name|setExportMode
argument_list|(
argument|ExportMode mode
argument_list|)
block|{
name|_exportMode
operator|=
name|mode
block|; }
name|void
name|addExportSymbol
argument_list|(
argument|StringRef sym
argument_list|)
block|;
name|bool
name|exportRestrictMode
argument_list|()
specifier|const
block|{
return|return
name|_exportMode
operator|!=
name|ExportMode
operator|::
name|globals
return|;
block|}
name|bool
name|exportSymbolNamed
argument_list|(
argument|StringRef sym
argument_list|)
specifier|const
block|;
name|DebugInfoMode
name|debugInfoMode
argument_list|()
specifier|const
block|{
return|return
name|_debugInfoMode
return|;
block|}
name|void
name|setDebugInfoMode
argument_list|(
argument|DebugInfoMode mode
argument_list|)
block|{
name|_debugInfoMode
operator|=
name|mode
block|;   }
name|void
name|appendOrderedSymbol
argument_list|(
argument|StringRef symbol
argument_list|,
argument|StringRef filename
argument_list|)
block|;
name|bool
name|keepPrivateExterns
argument_list|()
specifier|const
block|{
return|return
name|_keepPrivateExterns
return|;
block|}
name|void
name|setKeepPrivateExterns
argument_list|(
argument|bool v
argument_list|)
block|{
name|_keepPrivateExterns
operator|=
name|v
block|; }
name|bool
name|demangleSymbols
argument_list|()
specifier|const
block|{
return|return
name|_demangle
return|;
block|}
name|void
name|setDemangleSymbols
argument_list|(
argument|bool d
argument_list|)
block|{
name|_demangle
operator|=
name|d
block|; }
name|bool
name|mergeObjCCategories
argument_list|()
specifier|const
block|{
return|return
name|_mergeObjCCategories
return|;
block|}
name|void
name|setMergeObjCCategories
argument_list|(
argument|bool v
argument_list|)
block|{
name|_mergeObjCCategories
operator|=
name|v
block|; }
comment|/// Create file at specified path which will contain a binary encoding
comment|/// of all input and output file paths.
name|std
operator|::
name|error_code
name|createDependencyFile
argument_list|(
argument|StringRef path
argument_list|)
block|;
name|void
name|addInputFileDependency
argument_list|(
argument|StringRef path
argument_list|)
specifier|const
block|;
name|void
name|addInputFileNotFound
argument_list|(
argument|StringRef path
argument_list|)
specifier|const
block|;
name|void
name|addOutputFileDependency
argument_list|(
argument|StringRef path
argument_list|)
specifier|const
block|;
name|bool
name|minOS
argument_list|(
argument|StringRef mac
argument_list|,
argument|StringRef iOS
argument_list|)
specifier|const
block|;
name|void
name|setDoNothing
argument_list|(
argument|bool value
argument_list|)
block|{
name|_doNothing
operator|=
name|value
block|; }
name|bool
name|doNothing
argument_list|()
specifier|const
block|{
return|return
name|_doNothing
return|;
block|}
name|bool
name|printAtoms
argument_list|()
specifier|const
block|{
return|return
name|_printAtoms
return|;
block|}
name|bool
name|testingFileUsage
argument_list|()
specifier|const
block|{
return|return
name|_testingFileUsage
return|;
block|}
specifier|const
name|StringRefVector
operator|&
name|searchDirs
argument_list|()
specifier|const
block|{
return|return
name|_searchDirs
return|;
block|}
specifier|const
name|StringRefVector
operator|&
name|frameworkDirs
argument_list|()
specifier|const
block|{
return|return
name|_frameworkDirs
return|;
block|}
name|void
name|setSysLibRoots
argument_list|(
specifier|const
name|StringRefVector
operator|&
name|paths
argument_list|)
block|;
specifier|const
name|StringRefVector
operator|&
name|sysLibRoots
argument_list|()
specifier|const
block|{
return|return
name|_syslibRoots
return|;
block|}
name|bool
name|PIE
argument_list|()
specifier|const
block|{
return|return
name|_pie
return|;
block|}
name|void
name|setPIE
argument_list|(
argument|bool pie
argument_list|)
block|{
name|_pie
operator|=
name|pie
block|; }
name|bool
name|generateVersionLoadCommand
argument_list|()
specifier|const
block|{
return|return
name|_generateVersionLoadCommand
return|;
block|}
name|void
name|setGenerateVersionLoadCommand
argument_list|(
argument|bool v
argument_list|)
block|{
name|_generateVersionLoadCommand
operator|=
name|v
block|;   }
name|bool
name|generateFunctionStartsLoadCommand
argument_list|()
specifier|const
block|{
return|return
name|_generateFunctionStartsLoadCommand
return|;
block|}
name|void
name|setGenerateFunctionStartsLoadCommand
argument_list|(
argument|bool v
argument_list|)
block|{
name|_generateFunctionStartsLoadCommand
operator|=
name|v
block|;   }
name|bool
name|generateDataInCodeLoadCommand
argument_list|()
specifier|const
block|{
return|return
name|_generateDataInCodeLoadCommand
return|;
block|}
name|void
name|setGenerateDataInCodeLoadCommand
argument_list|(
argument|bool v
argument_list|)
block|{
name|_generateDataInCodeLoadCommand
operator|=
name|v
block|;   }
name|uint64_t
name|stackSize
argument_list|()
specifier|const
block|{
return|return
name|_stackSize
return|;
block|}
name|void
name|setStackSize
argument_list|(
argument|uint64_t stackSize
argument_list|)
block|{
name|_stackSize
operator|=
name|stackSize
block|; }
name|uint64_t
name|baseAddress
argument_list|()
specifier|const
block|{
return|return
name|_baseAddress
return|;
block|}
name|void
name|setBaseAddress
argument_list|(
argument|uint64_t baseAddress
argument_list|)
block|{
name|_baseAddress
operator|=
name|baseAddress
block|; }
name|ObjCConstraint
name|objcConstraint
argument_list|()
specifier|const
block|{
return|return
name|_objcConstraint
return|;
block|}
name|uint32_t
name|osMinVersion
argument_list|()
specifier|const
block|{
return|return
name|_osMinVersion
return|;
block|}
name|uint32_t
name|sdkVersion
argument_list|()
specifier|const
block|{
return|return
name|_sdkVersion
return|;
block|}
name|void
name|setSdkVersion
argument_list|(
argument|uint64_t v
argument_list|)
block|{
name|_sdkVersion
operator|=
name|v
block|; }
name|uint64_t
name|sourceVersion
argument_list|()
specifier|const
block|{
return|return
name|_sourceVersion
return|;
block|}
name|void
name|setSourceVersion
argument_list|(
argument|uint64_t v
argument_list|)
block|{
name|_sourceVersion
operator|=
name|v
block|; }
name|uint32_t
name|swiftVersion
argument_list|()
specifier|const
block|{
return|return
name|_swiftVersion
return|;
block|}
comment|/// \brief Checks whether a given path on the filesystem exists.
comment|///
comment|/// When running in -test_file_usage mode, this method consults an
comment|/// internally maintained list of files that exist (provided by -path_exists)
comment|/// instead of the actual filesystem.
name|bool
name|pathExists
argument_list|(
argument|StringRef path
argument_list|)
specifier|const
block|;
comment|/// Like pathExists() but only used on files - not directories.
name|bool
name|fileExists
argument_list|(
argument|StringRef path
argument_list|)
specifier|const
block|;
comment|/// \brief Adds any library search paths derived from the given base, possibly
comment|/// modified by -syslibroots.
comment|///
comment|/// The set of paths added consists of approximately all syslibroot-prepended
comment|/// versions of libPath that exist, or the original libPath if there are none
comment|/// for whatever reason. With various edge-cases for compatibility.
name|void
name|addModifiedSearchDir
argument_list|(
argument|StringRef libPath
argument_list|,
argument|bool isSystemPath = false
argument_list|)
block|;
comment|/// \brief Determine whether -lFoo can be resolve within the given path, and
comment|/// return the filename if so.
comment|///
comment|/// The -lFoo option is documented to search for libFoo.dylib and libFoo.a in
comment|/// that order, unless Foo ends in ".o", in which case only the exact file
comment|/// matches (e.g. -lfoo.o would only find foo.o).
name|llvm
operator|::
name|Optional
operator|<
name|StringRef
operator|>
name|searchDirForLibrary
argument_list|(
argument|StringRef path
argument_list|,
argument|StringRef libName
argument_list|)
specifier|const
block|;
comment|/// \brief Iterates through all search path entries looking for libName (as
comment|/// specified by -lFoo).
name|llvm
operator|::
name|Optional
operator|<
name|StringRef
operator|>
name|searchLibrary
argument_list|(
argument|StringRef libName
argument_list|)
specifier|const
block|;
comment|/// Add a framework search path.  Internally, this method may be prepended
comment|/// the path with syslibroot.
name|void
name|addFrameworkSearchDir
argument_list|(
argument|StringRef fwPath
argument_list|,
argument|bool isSystemPath = false
argument_list|)
block|;
comment|/// \brief Iterates through all framework directories looking for
comment|/// Foo.framework/Foo (when fwName = "Foo").
name|llvm
operator|::
name|Optional
operator|<
name|StringRef
operator|>
name|findPathForFramework
argument_list|(
argument|StringRef fwName
argument_list|)
specifier|const
block|;
comment|/// \brief The dylib's binary compatibility version, in the raw uint32 format.
comment|///
comment|/// When building a dynamic library, this is the compatibility version that
comment|/// gets embedded into the result. Other Mach-O binaries that link against
comment|/// this library will store the compatibility version in its load command. At
comment|/// runtime, the loader will verify that the binary is compatible with the
comment|/// installed dynamic library.
name|uint32_t
name|compatibilityVersion
argument_list|()
specifier|const
block|{
return|return
name|_compatibilityVersion
return|;
block|}
comment|/// \brief The dylib's current version, in the the raw uint32 format.
comment|///
comment|/// When building a dynamic library, this is the current version that gets
comment|/// embedded into the result. Other Mach-O binaries that link against
comment|/// this library will store the compatibility version in its load command.
name|uint32_t
name|currentVersion
argument_list|()
specifier|const
block|{
return|return
name|_currentVersion
return|;
block|}
comment|/// \brief The dylib's install name.
comment|///
comment|/// Binaries that link against the dylib will embed this path into the dylib
comment|/// load command. When loading the binaries at runtime, this is the location
comment|/// on disk that the loader will look for the dylib.
name|StringRef
name|installName
argument_list|()
specifier|const
block|{
return|return
name|_installName
return|;
block|}
comment|/// \brief Whether or not the dylib has side effects during initialization.
comment|///
comment|/// Dylibs marked as being dead strippable provide the guarantee that loading
comment|/// the dylib has no side effects, allowing the linker to strip out the dylib
comment|/// when linking a binary that does not use any of its symbols.
name|bool
name|deadStrippableDylib
argument_list|()
specifier|const
block|{
return|return
name|_deadStrippableDylib
return|;
block|}
comment|/// \brief Whether or not to use flat namespace.
comment|///
comment|/// MachO usually uses a two-level namespace, where each external symbol
comment|/// referenced by the target is associated with the dylib that will provide
comment|/// the symbol's definition at runtime. Using flat namespace overrides this
comment|/// behavior: the linker searches all dylibs on the command line and all
comment|/// dylibs those original dylibs depend on, but does not record which dylib
comment|/// an external symbol came from. At runtime dyld again searches all images
comment|/// and uses the first definition it finds. In addition, any undefines in
comment|/// loaded flat_namespace dylibs must be resolvable at build time.
name|bool
name|useFlatNamespace
argument_list|()
specifier|const
block|{
return|return
name|_flatNamespace
return|;
block|}
comment|/// \brief How to handle undefined symbols.
comment|///
comment|/// Options are:
comment|///  * error: Report an error and terminate linking.
comment|///  * warning: Report a warning, but continue linking.
comment|///  * suppress: Ignore and continue linking.
comment|///  * dynamic_lookup: For use with -twolevel namespace: Records source dylibs
comment|///    for symbols that are defined in a linked dylib at static link time.
comment|///    Undefined symbols are handled by searching all loaded images at
comment|///    runtime.
name|UndefinedMode
name|undefinedMode
argument_list|()
specifier|const
block|{
return|return
name|_undefinedMode
return|;
block|}
comment|/// \brief The path to the executable that will load the bundle at runtime.
comment|///
comment|/// When building a Mach-O bundle, this executable will be examined if there
comment|/// are undefined symbols after the main link phase. It is expected that this
comment|/// binary will be loading the bundle at runtime and will provide the symbols
comment|/// at that point.
name|StringRef
name|bundleLoader
argument_list|()
specifier|const
block|{
return|return
name|_bundleLoader
return|;
block|}
name|void
name|setCompatibilityVersion
argument_list|(
argument|uint32_t vers
argument_list|)
block|{
name|_compatibilityVersion
operator|=
name|vers
block|; }
name|void
name|setCurrentVersion
argument_list|(
argument|uint32_t vers
argument_list|)
block|{
name|_currentVersion
operator|=
name|vers
block|; }
name|void
name|setInstallName
argument_list|(
argument|StringRef name
argument_list|)
block|{
name|_installName
operator|=
name|name
block|; }
name|void
name|setDeadStrippableDylib
argument_list|(
argument|bool deadStrippable
argument_list|)
block|{
name|_deadStrippableDylib
operator|=
name|deadStrippable
block|;   }
name|void
name|setUseFlatNamespace
argument_list|(
argument|bool flatNamespace
argument_list|)
block|{
name|_flatNamespace
operator|=
name|flatNamespace
block|;   }
name|void
name|setUndefinedMode
argument_list|(
argument|UndefinedMode undefinedMode
argument_list|)
block|{
name|_undefinedMode
operator|=
name|undefinedMode
block|;   }
name|void
name|setBundleLoader
argument_list|(
argument|StringRef loader
argument_list|)
block|{
name|_bundleLoader
operator|=
name|loader
block|; }
name|void
name|setPrintAtoms
argument_list|(
argument|bool value=true
argument_list|)
block|{
name|_printAtoms
operator|=
name|value
block|; }
name|void
name|setTestingFileUsage
argument_list|(
argument|bool value = true
argument_list|)
block|{
name|_testingFileUsage
operator|=
name|value
block|;   }
name|void
name|addExistingPathForDebug
argument_list|(
argument|StringRef path
argument_list|)
block|{
name|_existingPaths
operator|.
name|insert
argument_list|(
name|path
argument_list|)
block|;   }
name|void
name|addRpath
argument_list|(
argument|StringRef rpath
argument_list|)
block|;
specifier|const
name|StringRefVector
operator|&
name|rpaths
argument_list|()
specifier|const
block|{
return|return
name|_rpaths
return|;
block|}
comment|/// Add section alignment constraint on final layout.
name|void
name|addSectionAlignment
argument_list|(
argument|StringRef seg
argument_list|,
argument|StringRef sect
argument_list|,
argument|uint16_t align
argument_list|)
block|;
comment|/// \brief Add a section based on a command-line sectcreate option.
name|void
name|addSectCreateSection
argument_list|(
argument|StringRef seg
argument_list|,
argument|StringRef sect
argument_list|,
argument|std::unique_ptr<MemoryBuffer> content
argument_list|)
block|;
comment|/// Returns true if specified section had alignment constraints.
name|bool
name|sectionAligned
argument_list|(
argument|StringRef seg
argument_list|,
argument|StringRef sect
argument_list|,
argument|uint16_t&align
argument_list|)
specifier|const
block|;
name|StringRef
name|dyldPath
argument_list|()
specifier|const
block|{
return|return
literal|"/usr/lib/dyld"
return|;
block|}
comment|/// Stub creation Pass should be run.
name|bool
name|needsStubsPass
argument_list|()
specifier|const
block|;
comment|// GOT creation Pass should be run.
name|bool
name|needsGOTPass
argument_list|()
specifier|const
block|;
comment|/// Pass to add TLV sections.
name|bool
name|needsTLVPass
argument_list|()
specifier|const
block|;
comment|/// Pass to transform __compact_unwind into __unwind_info should be run.
name|bool
name|needsCompactUnwindPass
argument_list|()
specifier|const
block|;
comment|/// Pass to add shims switching between thumb and arm mode.
name|bool
name|needsShimPass
argument_list|()
specifier|const
block|;
comment|/// Pass to add objc image info and optimized objc data.
name|bool
name|needsObjCPass
argument_list|()
specifier|const
block|;
comment|/// Magic symbol name stubs will need to help lazy bind.
name|StringRef
name|binderSymbolName
argument_list|()
specifier|const
block|;
comment|/// Used to keep track of direct and indirect dylibs.
name|void
name|registerDylib
argument_list|(
argument|mach_o::MachODylibFile *dylib
argument_list|,
argument|bool upward
argument_list|)
specifier|const
block|;
comment|// Reads a file from disk to memory. Returns only a needed chunk
comment|// if a fat binary.
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>>
name|getMemoryBuffer
argument_list|(
argument|StringRef path
argument_list|)
block|;
comment|/// Used to find indirect dylibs. Instantiates a MachODylibFile if one
comment|/// has not already been made for the requested dylib.  Uses -L and -F
comment|/// search paths to allow indirect dylibs to be overridden.
name|mach_o
operator|::
name|MachODylibFile
operator|*
name|findIndirectDylib
argument_list|(
argument|StringRef path
argument_list|)
block|;
name|uint32_t
name|dylibCurrentVersion
argument_list|(
argument|StringRef installName
argument_list|)
specifier|const
block|;
name|uint32_t
name|dylibCompatVersion
argument_list|(
argument|StringRef installName
argument_list|)
specifier|const
block|;
name|ArrayRef
operator|<
name|mach_o
operator|::
name|MachODylibFile
operator|*
operator|>
name|allDylibs
argument_list|()
specifier|const
block|{
return|return
name|_allDylibs
return|;
block|}
comment|/// Creates a copy (owned by this MachOLinkingContext) of a string.
name|StringRef
name|copy
argument_list|(
argument|StringRef str
argument_list|)
block|{
return|return
name|str
operator|.
name|copy
argument_list|(
name|_allocator
argument_list|)
return|;
block|}
comment|/// If the memoryBuffer is a fat file with a slice for the current arch,
comment|/// this method will return the offset and size of that slice.
name|bool
name|sliceFromFatFile
argument_list|(
argument|MemoryBufferRef mb
argument_list|,
argument|uint32_t&offset
argument_list|,
argument|uint32_t&size
argument_list|)
block|;
comment|/// Returns if a command line option specified dylib is an upward link.
name|bool
name|isUpwardDylib
argument_list|(
argument|StringRef installName
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|isThinObjectFile
argument_list|(
argument|StringRef path
argument_list|,
argument|Arch&arch
argument_list|)
block|;
specifier|static
name|Arch
name|archFromCpuType
argument_list|(
argument|uint32_t cputype
argument_list|,
argument|uint32_t cpusubtype
argument_list|)
block|;
specifier|static
name|Arch
name|archFromName
argument_list|(
argument|StringRef archName
argument_list|)
block|;
specifier|static
name|StringRef
name|nameFromArch
argument_list|(
argument|Arch arch
argument_list|)
block|;
specifier|static
name|uint32_t
name|cpuTypeFromArch
argument_list|(
argument|Arch arch
argument_list|)
block|;
specifier|static
name|uint32_t
name|cpuSubtypeFromArch
argument_list|(
argument|Arch arch
argument_list|)
block|;
specifier|static
name|bool
name|is64Bit
argument_list|(
argument|Arch arch
argument_list|)
block|;
specifier|static
name|bool
name|isHostEndian
argument_list|(
argument|Arch arch
argument_list|)
block|;
specifier|static
name|bool
name|isBigEndian
argument_list|(
argument|Arch arch
argument_list|)
block|;
comment|/// Construct 32-bit value from string "X.Y.Z" where
comment|/// bits are xxxx.yy.zz.  Largest number is 65535.255.255
specifier|static
name|bool
name|parsePackedVersion
argument_list|(
argument|StringRef str
argument_list|,
argument|uint32_t&result
argument_list|)
block|;
comment|/// Construct 64-bit value from string "A.B.C.D.E" where
comment|/// bits are aaaa.bb.cc.dd.ee.  Largest number is 16777215.1023.1023.1023.1023
specifier|static
name|bool
name|parsePackedVersion
argument_list|(
argument|StringRef str
argument_list|,
argument|uint64_t&result
argument_list|)
block|;
name|void
name|finalizeInputFiles
argument_list|()
name|override
block|;
name|llvm
operator|::
name|Error
name|handleLoadedFile
argument_list|(
argument|File&file
argument_list|)
name|override
block|;
name|bool
name|customAtomOrderer
argument_list|(
argument|const DefinedAtom *left
argument_list|,
argument|const DefinedAtom *right
argument_list|,
argument|bool&leftBeforeRight
argument_list|)
specifier|const
block|;
comment|/// Return the 'flat namespace' file. This is the file that supplies
comment|/// atoms for otherwise undefined symbols when the -flat_namespace or
comment|/// -undefined dynamic_lookup options are used.
name|File
operator|*
name|flatNamespaceFile
argument_list|()
specifier|const
block|{
return|return
name|_flatNamespaceFile
return|;
block|}
name|private
operator|:
name|Writer
operator|&
name|writer
argument_list|()
specifier|const
name|override
block|;
name|mach_o
operator|::
name|MachODylibFile
operator|*
name|loadIndirectDylib
argument_list|(
argument|StringRef path
argument_list|)
block|;
name|void
name|checkExportWhiteList
argument_list|(
argument|const DefinedAtom *atom
argument_list|)
specifier|const
block|;
name|void
name|checkExportBlackList
argument_list|(
argument|const DefinedAtom *atom
argument_list|)
specifier|const
block|;   struct
name|ArchInfo
block|{
name|StringRef
name|archName
block|;
name|MachOLinkingContext
operator|::
name|Arch
name|arch
block|;
name|bool
name|littleEndian
block|;
name|uint32_t
name|cputype
block|;
name|uint32_t
name|cpusubtype
block|;   }
block|;    struct
name|SectionAlign
block|{
name|StringRef
name|segmentName
block|;
name|StringRef
name|sectionName
block|;
name|uint16_t
name|align
block|;   }
block|;    struct
name|OrderFileNode
block|{
name|StringRef
name|fileFilter
block|;
name|unsigned
name|order
block|;   }
block|;
specifier|static
name|bool
name|findOrderOrdinal
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|OrderFileNode
operator|>
operator|&
name|nodes
argument_list|,
specifier|const
name|DefinedAtom
operator|*
name|atom
argument_list|,
name|unsigned
operator|&
name|ordinal
argument_list|)
block|;
specifier|static
name|ArchInfo
name|_s_archInfos
index|[]
block|;
name|std
operator|::
name|set
operator|<
name|StringRef
operator|>
name|_existingPaths
block|;
comment|// For testing only.
name|StringRefVector
name|_searchDirs
block|;
name|StringRefVector
name|_syslibRoots
block|;
name|StringRefVector
name|_frameworkDirs
block|;
name|HeaderFileType
name|_outputMachOType
operator|=
name|llvm
operator|::
name|MachO
operator|::
name|MH_EXECUTE
block|;
name|bool
name|_outputMachOTypeStatic
operator|=
name|false
block|;
comment|// Disambiguate static vs dynamic prog
name|bool
name|_doNothing
operator|=
name|false
block|;
comment|// for -help and -v which just print info
name|bool
name|_pie
operator|=
name|false
block|;
name|Arch
name|_arch
operator|=
name|arch_unknown
block|;
name|OS
name|_os
operator|=
name|OS
operator|::
name|macOSX
block|;
name|uint32_t
name|_osMinVersion
operator|=
literal|0
block|;
name|uint32_t
name|_sdkVersion
operator|=
literal|0
block|;
name|uint64_t
name|_sourceVersion
operator|=
literal|0
block|;
name|uint64_t
name|_pageZeroSize
operator|=
literal|0
block|;
name|uint64_t
name|_pageSize
operator|=
literal|4096
block|;
name|uint64_t
name|_baseAddress
operator|=
literal|0
block|;
name|uint64_t
name|_stackSize
operator|=
literal|0
block|;
name|uint32_t
name|_compatibilityVersion
operator|=
literal|0
block|;
name|uint32_t
name|_currentVersion
operator|=
literal|0
block|;
name|ObjCConstraint
name|_objcConstraint
operator|=
name|objc_unknown
block|;
name|uint32_t
name|_swiftVersion
operator|=
literal|0
block|;
name|StringRef
name|_installName
block|;
name|StringRefVector
name|_rpaths
block|;
name|bool
name|_flatNamespace
operator|=
name|false
block|;
name|UndefinedMode
name|_undefinedMode
operator|=
name|UndefinedMode
operator|::
name|error
block|;
name|bool
name|_deadStrippableDylib
operator|=
name|false
block|;
name|bool
name|_printAtoms
operator|=
name|false
block|;
name|bool
name|_testingFileUsage
operator|=
name|false
block|;
name|bool
name|_keepPrivateExterns
operator|=
name|false
block|;
name|bool
name|_demangle
operator|=
name|false
block|;
name|bool
name|_mergeObjCCategories
operator|=
name|true
block|;
name|bool
name|_generateVersionLoadCommand
operator|=
name|false
block|;
name|bool
name|_generateFunctionStartsLoadCommand
operator|=
name|false
block|;
name|bool
name|_generateDataInCodeLoadCommand
operator|=
name|false
block|;
name|StringRef
name|_bundleLoader
block|;
name|mutable
name|std
operator|::
name|unique_ptr
operator|<
name|mach_o
operator|::
name|ArchHandler
operator|>
name|_archHandler
block|;
name|mutable
name|std
operator|::
name|unique_ptr
operator|<
name|Writer
operator|>
name|_writer
block|;
name|std
operator|::
name|vector
operator|<
name|SectionAlign
operator|>
name|_sectAligns
block|;
name|mutable
name|llvm
operator|::
name|StringMap
operator|<
name|mach_o
operator|::
name|MachODylibFile
operator|*
operator|>
name|_pathToDylibMap
block|;
name|mutable
name|std
operator|::
name|vector
operator|<
name|mach_o
operator|::
name|MachODylibFile
operator|*
operator|>
name|_allDylibs
block|;
name|mutable
name|std
operator|::
name|set
operator|<
name|mach_o
operator|::
name|MachODylibFile
operator|*
operator|>
name|_upwardDylibs
block|;
name|mutable
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
name|_indirectDylibs
block|;
name|mutable
name|std
operator|::
name|mutex
name|_dylibsMutex
block|;
name|ExportMode
name|_exportMode
operator|=
name|ExportMode
operator|::
name|globals
block|;
name|llvm
operator|::
name|StringSet
operator|<
operator|>
name|_exportedSymbols
block|;
name|DebugInfoMode
name|_debugInfoMode
operator|=
name|DebugInfoMode
operator|::
name|addDebugMap
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|raw_fd_ostream
operator|>
name|_dependencyInfo
block|;
name|llvm
operator|::
name|StringMap
operator|<
name|std
operator|::
name|vector
operator|<
name|OrderFileNode
operator|>>
name|_orderFiles
block|;
name|unsigned
name|_orderFileEntries
operator|=
literal|0
block|;
name|File
operator|*
name|_flatNamespaceFile
operator|=
name|nullptr
block|;
name|mach_o
operator|::
name|SectCreateFile
operator|*
name|_sectCreateFile
operator|=
name|nullptr
block|; }
decl_stmt|;
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
comment|// LLD_READER_WRITER_MACHO_LINKING_CONTEXT_H
end_comment

end_unit

