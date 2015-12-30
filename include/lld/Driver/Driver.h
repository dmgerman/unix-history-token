begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lld/Driver/Driver.h - Linker Driver Emulator -----------------------===//
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

begin_comment
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Interface for Drivers which convert command line arguments into
end_comment

begin_comment
comment|/// LinkingContext objects, then perform the link.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLD_DRIVER_DRIVER_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_DRIVER_DRIVER_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Node.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
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

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|class
name|LinkingContext
decl_stmt|;
name|class
name|CoreLinkingContext
decl_stmt|;
name|class
name|MachOLinkingContext
decl_stmt|;
name|class
name|PECOFFLinkingContext
decl_stmt|;
name|class
name|ELFLinkingContext
decl_stmt|;
typedef|typedef
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
name|FileVector
expr_stmt|;
name|FileVector
name|makeErrorFile
argument_list|(
name|StringRef
name|path
argument_list|,
name|std
operator|::
name|error_code
name|ec
argument_list|)
decl_stmt|;
name|FileVector
name|parseMemberFiles
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|File
operator|>
name|File
argument_list|)
decl_stmt|;
name|FileVector
name|loadFile
parameter_list|(
name|LinkingContext
modifier|&
name|ctx
parameter_list|,
name|StringRef
name|path
parameter_list|,
name|bool
name|wholeArchive
parameter_list|)
function_decl|;
comment|/// Base class for all Drivers.
name|class
name|Driver
block|{
name|protected
label|:
comment|/// Performs link using specified options
specifier|static
name|bool
name|link
parameter_list|(
name|LinkingContext
modifier|&
name|context
parameter_list|,
name|raw_ostream
modifier|&
name|diag
init|=
name|llvm
operator|::
name|errs
argument_list|()
parameter_list|)
function_decl|;
comment|/// Parses the LLVM options from the context.
specifier|static
name|void
name|parseLLVMOptions
parameter_list|(
specifier|const
name|LinkingContext
modifier|&
name|context
parameter_list|)
function_decl|;
name|private
label|:
name|Driver
argument_list|()
operator|=
name|delete
expr_stmt|;
block|}
empty_stmt|;
comment|/// Driver for "universal" lld tool which can mimic any linker command line
comment|/// parsing once it figures out which command line flavor to use.
name|class
name|UniversalDriver
range|:
name|public
name|Driver
block|{
name|public
operator|:
comment|/// Determine flavor and pass control to Driver for that flavor.
specifier|static
name|bool
name|link
argument_list|(
name|llvm
operator|::
name|MutableArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|args
argument_list|,
name|raw_ostream
operator|&
name|diag
operator|=
name|llvm
operator|::
name|errs
argument_list|()
argument_list|)
block|;
name|private
operator|:
name|UniversalDriver
argument_list|()
operator|=
name|delete
block|; }
decl_stmt|;
comment|/// Driver for gnu/binutil 'ld' command line options.
name|class
name|GnuLdDriver
range|:
name|public
name|Driver
block|{
name|public
operator|:
comment|/// Parses command line arguments same as gnu/binutils ld and performs link.
comment|/// Returns true iff an error occurred.
specifier|static
name|bool
name|linkELF
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|args
argument_list|,
name|raw_ostream
operator|&
name|diag
operator|=
name|llvm
operator|::
name|errs
argument_list|()
argument_list|)
block|;
comment|/// Uses gnu/binutils style ld command line options to fill in options struct.
comment|/// Returns true iff there was an error.
specifier|static
name|bool
name|parse
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|args
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|ELFLinkingContext
operator|>
operator|&
name|context
argument_list|,
name|raw_ostream
operator|&
name|diag
operator|=
name|llvm
operator|::
name|errs
argument_list|()
argument_list|)
block|;
comment|/// Parses a given memory buffer as a linker script and evaluate that.
comment|/// Public function for testing.
specifier|static
name|std
operator|::
name|error_code
name|evalLinkerScript
argument_list|(
argument|ELFLinkingContext&ctx
argument_list|,
argument|std::unique_ptr<MemoryBuffer> mb
argument_list|,
argument|raw_ostream&diag
argument_list|,
argument|bool nostdlib
argument_list|)
block|;
comment|/// A factory method to create an instance of ELFLinkingContext.
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|ELFLinkingContext
operator|>
name|createELFLinkingContext
argument_list|(
argument|llvm::Triple triple
argument_list|)
block|;
name|private
operator|:
specifier|static
name|llvm
operator|::
name|Triple
name|getDefaultTarget
argument_list|(
specifier|const
name|char
operator|*
name|progName
argument_list|)
block|;
specifier|static
name|bool
name|applyEmulation
argument_list|(
name|llvm
operator|::
name|Triple
operator|&
name|triple
argument_list|,
name|llvm
operator|::
name|opt
operator|::
name|InputArgList
operator|&
name|args
argument_list|,
name|raw_ostream
operator|&
name|diag
argument_list|)
block|;
specifier|static
name|void
name|addPlatformSearchDirs
argument_list|(
name|ELFLinkingContext
operator|&
name|ctx
argument_list|,
name|llvm
operator|::
name|Triple
operator|&
name|triple
argument_list|,
name|llvm
operator|::
name|Triple
operator|&
name|baseTriple
argument_list|)
block|;
name|GnuLdDriver
argument_list|()
operator|=
name|delete
block|; }
decl_stmt|;
comment|/// Driver for darwin/ld64 'ld' command line options.
name|class
name|DarwinLdDriver
range|:
name|public
name|Driver
block|{
name|public
operator|:
comment|/// Parses command line arguments same as darwin's ld and performs link.
comment|/// Returns true iff there was an error.
specifier|static
name|bool
name|linkMachO
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|args
argument_list|,
name|raw_ostream
operator|&
name|diag
operator|=
name|llvm
operator|::
name|errs
argument_list|()
argument_list|)
block|;
comment|/// Uses darwin style ld command line options to update LinkingContext object.
comment|/// Returns true iff there was an error.
specifier|static
name|bool
name|parse
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|args
argument_list|,
name|MachOLinkingContext
operator|&
name|info
argument_list|,
name|raw_ostream
operator|&
name|diag
operator|=
name|llvm
operator|::
name|errs
argument_list|()
argument_list|)
block|;
name|private
operator|:
name|DarwinLdDriver
argument_list|()
operator|=
name|delete
block|; }
decl_stmt|;
comment|/// Driver for Windows 'link.exe' command line options
name|namespace
name|coff
block|{
name|void
name|link
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|args
argument_list|)
decl_stmt|;
block|}
name|namespace
name|elf2
block|{
name|void
name|link
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|args
argument_list|)
decl_stmt|;
block|}
comment|/// Driver for lld unit tests
name|class
name|CoreDriver
range|:
name|public
name|Driver
block|{
name|public
operator|:
comment|/// Parses command line arguments same as lld-core and performs link.
comment|/// Returns true iff there was an error.
specifier|static
name|bool
name|link
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|args
argument_list|,
name|raw_ostream
operator|&
name|diag
operator|=
name|llvm
operator|::
name|errs
argument_list|()
argument_list|)
block|;
comment|/// Uses lld-core command line options to fill in options struct.
comment|/// Returns true iff there was an error.
specifier|static
name|bool
name|parse
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|args
argument_list|,
name|CoreLinkingContext
operator|&
name|info
argument_list|,
name|raw_ostream
operator|&
name|diag
operator|=
name|llvm
operator|::
name|errs
argument_list|()
argument_list|)
block|;
name|private
operator|:
name|CoreDriver
argument_list|()
operator|=
name|delete
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

end_unit

