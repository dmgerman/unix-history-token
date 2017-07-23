begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AuxVector.h ---------------------------------------------*- C++ -*-===//
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
name|liblldb_AuxVector_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_AuxVector_H_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|DataExtractor
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// @class AuxVector
end_comment

begin_comment
comment|/// @brief Represents a processes auxiliary vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// When a process is loaded on Linux a vector of values is placed onto the
end_comment

begin_comment
comment|/// stack communicating operating system specific information.  On construction
end_comment

begin_comment
comment|/// this class locates and parses this information and provides a simple
end_comment

begin_comment
comment|/// read-only interface to the entries found.
end_comment

begin_decl_stmt
name|class
name|AuxVector
block|{
name|public
label|:
name|AuxVector
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
expr_stmt|;
struct|struct
name|Entry
block|{
name|uint64_t
name|type
decl_stmt|;
name|uint64_t
name|value
decl_stmt|;
name|Entry
argument_list|()
operator|:
name|type
argument_list|(
literal|0
argument_list|)
operator|,
name|value
argument_list|(
literal|0
argument_list|)
block|{}
block|}
struct|;
comment|/// Constants describing the type of entry.
comment|/// On Linux, running "LD_SHOW_AUXV=1 ./executable" will spew AUX information.
comment|/// Added AUXV prefix to avoid potential conflicts with system-defined macros
enum|enum
name|EntryType
block|{
name|AUXV_AT_NULL
init|=
literal|0
block|,
comment|///< End of auxv.
name|AUXV_AT_IGNORE
init|=
literal|1
block|,
comment|///< Ignore entry.
name|AUXV_AT_EXECFD
init|=
literal|2
block|,
comment|///< File descriptor of program.
name|AUXV_AT_PHDR
init|=
literal|3
block|,
comment|///< Program headers.
name|AUXV_AT_PHENT
init|=
literal|4
block|,
comment|///< Size of program header.
name|AUXV_AT_PHNUM
init|=
literal|5
block|,
comment|///< Number of program headers.
name|AUXV_AT_PAGESZ
init|=
literal|6
block|,
comment|///< Page size.
name|AUXV_AT_BASE
init|=
literal|7
block|,
comment|///< Interpreter base address.
name|AUXV_AT_FLAGS
init|=
literal|8
block|,
comment|///< Flags.
name|AUXV_AT_ENTRY
init|=
literal|9
block|,
comment|///< Program entry point.
name|AUXV_AT_NOTELF
init|=
literal|10
block|,
comment|///< Set if program is not an ELF.
name|AUXV_AT_UID
init|=
literal|11
block|,
comment|///< UID.
name|AUXV_AT_EUID
init|=
literal|12
block|,
comment|///< Effective UID.
name|AUXV_AT_GID
init|=
literal|13
block|,
comment|///< GID.
name|AUXV_AT_EGID
init|=
literal|14
block|,
comment|///< Effective GID.
name|AUXV_AT_CLKTCK
init|=
literal|17
block|,
comment|///< Clock frequency (e.g. times(2)).
name|AUXV_AT_PLATFORM
init|=
literal|15
block|,
comment|///< String identifying platform.
name|AUXV_AT_HWCAP
init|=
literal|16
block|,
comment|///< Machine dependent hints about processor capabilities.
name|AUXV_AT_FPUCW
init|=
literal|18
block|,
comment|///< Used FPU control word.
name|AUXV_AT_DCACHEBSIZE
init|=
literal|19
block|,
comment|///< Data cache block size.
name|AUXV_AT_ICACHEBSIZE
init|=
literal|20
block|,
comment|///< Instruction cache block size.
name|AUXV_AT_UCACHEBSIZE
init|=
literal|21
block|,
comment|///< Unified cache block size.
name|AUXV_AT_IGNOREPPC
init|=
literal|22
block|,
comment|///< Entry should be ignored.
name|AUXV_AT_SECURE
init|=
literal|23
block|,
comment|///< Boolean, was exec setuid-like?
name|AUXV_AT_BASE_PLATFORM
init|=
literal|24
block|,
comment|///< String identifying real platforms.
name|AUXV_AT_RANDOM
init|=
literal|25
block|,
comment|///< Address of 16 random bytes.
name|AUXV_AT_EXECFN
init|=
literal|31
block|,
comment|///< Filename of executable.
name|AUXV_AT_SYSINFO
init|=
literal|32
block|,
comment|///< Pointer to the global system page used for system
comment|///calls and other nice things.
name|AUXV_AT_SYSINFO_EHDR
init|=
literal|33
block|,
name|AUXV_AT_L1I_CACHESHAPE
init|=
literal|34
block|,
comment|///< Shapes of the caches.
name|AUXV_AT_L1D_CACHESHAPE
init|=
literal|35
block|,
name|AUXV_AT_L2_CACHESHAPE
init|=
literal|36
block|,
name|AUXV_AT_L3_CACHESHAPE
init|=
literal|37
block|,   }
enum|;
name|private
label|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Entry
operator|>
name|EntryVector
expr_stmt|;
name|public
label|:
typedef|typedef
name|EntryVector
operator|::
name|const_iterator
name|iterator
expr_stmt|;
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|m_auxv
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|m_auxv
operator|.
name|end
argument_list|()
return|;
block|}
name|iterator
name|FindEntry
argument_list|(
name|EntryType
name|type
argument_list|)
decl|const
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|GetEntryName
parameter_list|(
specifier|const
name|Entry
modifier|&
name|entry
parameter_list|)
block|{
return|return
name|GetEntryName
argument_list|(
name|static_cast
operator|<
name|EntryType
operator|>
operator|(
name|entry
operator|.
name|type
operator|)
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|char
modifier|*
name|GetEntryName
parameter_list|(
name|EntryType
name|type
parameter_list|)
function_decl|;
name|void
name|DumpToLog
argument_list|(
name|lldb_private
operator|::
name|Log
operator|*
name|log
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|lldb_private
operator|::
name|Process
operator|*
name|m_process
expr_stmt|;
name|EntryVector
name|m_auxv
decl_stmt|;
name|lldb
operator|::
name|DataBufferSP
name|GetAuxvData
argument_list|()
expr_stmt|;
name|void
name|ParseAuxv
argument_list|(
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|data
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

