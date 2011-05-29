begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- EDDisassembler.h - LLVM Enhanced Disassembler -----------*- C++ -*-===//
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
comment|// This file defines the interface for the Enhanced Disassembly library's
end_comment

begin_comment
comment|// disassembler class.  The disassembler is responsible for vending individual
end_comment

begin_comment
comment|// instructions according to a given architecture and disassembly syntax.
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
name|LLVM_EDDISASSEMBLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EDDISASSEMBLER_H
end_define

begin_include
include|#
directive|include
file|"EDInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
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
file|"llvm/Support/Mutex.h"
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

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AsmLexer
decl_stmt|;
name|class
name|AsmToken
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|MCAsmLexer
decl_stmt|;
name|class
name|AsmParser
decl_stmt|;
name|class
name|TargetAsmLexer
decl_stmt|;
name|class
name|TargetAsmParser
decl_stmt|;
name|class
name|MCDisassembler
decl_stmt|;
name|class
name|MCInstPrinter
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|class
name|MCParsedAsmOperand
decl_stmt|;
name|class
name|MCStreamer
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
name|class
name|SourceMgr
decl_stmt|;
name|class
name|Target
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
struct_decl|struct
name|EDInstInfo
struct_decl|;
struct_decl|struct
name|EDInst
struct_decl|;
struct_decl|struct
name|EDOperand
struct_decl|;
struct_decl|struct
name|EDToken
struct_decl|;
typedef|typedef
name|int
function_decl|(
modifier|*
name|EDByteReaderCallback
function_decl|)
parameter_list|(
name|uint8_t
modifier|*
name|byte
parameter_list|,
name|uint64_t
name|address
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
comment|/// EDDisassembler - Encapsulates a disassembler for a single architecture and
comment|///   disassembly syntax.  Also manages the static disassembler registry.
struct|struct
name|EDDisassembler
block|{
typedef|typedef
enum|enum
block|{
comment|/*! @constant kEDAssemblySyntaxX86Intel Intel syntax for i386 and x86_64. */
name|kEDAssemblySyntaxX86Intel
init|=
literal|0
block|,
comment|/*! @constant kEDAssemblySyntaxX86ATT AT&T syntax for i386 and x86_64. */
name|kEDAssemblySyntaxX86ATT
init|=
literal|1
block|,
name|kEDAssemblySyntaxARMUAL
init|=
literal|2
block|}
name|AssemblySyntax
typedef|;
comment|////////////////////
comment|// Static members //
comment|////////////////////
comment|/// CPUKey - Encapsulates the descriptor of an architecture/disassembly-syntax
comment|///   pair
struct|struct
name|CPUKey
block|{
comment|/// The architecture type
name|llvm
operator|::
name|Triple
operator|::
name|ArchType
name|Arch
expr_stmt|;
comment|/// The assembly syntax
name|AssemblySyntax
name|Syntax
decl_stmt|;
comment|/// operator== - Equality operator
name|bool
name|operator
operator|==
operator|(
specifier|const
name|CPUKey
operator|&
name|key
operator|)
specifier|const
block|{
return|return
operator|(
name|Arch
operator|==
name|key
operator|.
name|Arch
operator|&&
name|Syntax
operator|==
name|key
operator|.
name|Syntax
operator|)
return|;
block|}
comment|/// operator< - Less-than operator
name|bool
name|operator
operator|<
operator|(
specifier|const
name|CPUKey
operator|&
name|key
operator|)
specifier|const
block|{
return|return
operator|(
operator|(
name|Arch
operator|<
name|key
operator|.
name|Arch
operator|)
operator|||
operator|(
operator|(
name|Arch
operator|==
name|key
operator|.
name|Arch
operator|)
operator|&&
name|Syntax
operator|<
operator|(
name|key
operator|.
name|Syntax
operator|)
operator|)
operator|)
return|;
block|}
block|}
struct|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|CPUKey
operator|,
name|EDDisassembler
operator|*
operator|>
name|DisassemblerMap_t
expr_stmt|;
comment|/// True if the disassembler registry has been initialized; false if not
specifier|static
name|bool
name|sInitialized
decl_stmt|;
comment|/// A map from disassembler specifications to disassemblers.  Populated
comment|///   lazily.
specifier|static
name|DisassemblerMap_t
name|sDisassemblers
decl_stmt|;
comment|/// getDisassembler - Returns the specified disassemble, or NULL on failure
comment|///
comment|/// @arg arch   - The desired architecture
comment|/// @arg syntax - The desired disassembly syntax
specifier|static
name|EDDisassembler
modifier|*
name|getDisassembler
argument_list|(
name|llvm
operator|::
name|Triple
operator|::
name|ArchType
name|arch
argument_list|,
name|AssemblySyntax
name|syntax
argument_list|)
decl_stmt|;
comment|/// getDisassembler - Returns the disassembler for a given combination of
comment|///   CPU type, CPU subtype, and assembly syntax, or NULL on failure
comment|///
comment|/// @arg str    - The string representation of the architecture triple, e.g.,
comment|///               "x86_64-apple-darwin"
comment|/// @arg syntax - The disassembly syntax for the required disassembler
specifier|static
name|EDDisassembler
modifier|*
name|getDisassembler
argument_list|(
name|llvm
operator|::
name|StringRef
name|str
argument_list|,
name|AssemblySyntax
name|syntax
argument_list|)
decl_stmt|;
comment|/// initialize - Initializes the disassembler registry and the LLVM backend
specifier|static
name|void
name|initialize
parameter_list|()
function_decl|;
comment|////////////////////////
comment|// Per-object members //
comment|////////////////////////
comment|/// True only if the object has been successfully initialized
name|bool
name|Valid
decl_stmt|;
comment|/// True if the disassembler can provide semantic information
name|bool
name|HasSemantics
decl_stmt|;
comment|/// The stream to write errors to
name|llvm
operator|::
name|raw_ostream
operator|&
name|ErrorStream
expr_stmt|;
comment|/// The architecture/syntax pair for the current architecture
name|CPUKey
name|Key
decl_stmt|;
comment|/// The LLVM target corresponding to the disassembler
specifier|const
name|llvm
operator|::
name|Target
operator|*
name|Tgt
expr_stmt|;
comment|/// The target machine instance.
name|llvm
operator|::
name|OwningPtr
operator|<
name|llvm
operator|::
name|TargetMachine
operator|>
name|TargetMachine
expr_stmt|;
comment|/// The assembly information for the target architecture
name|llvm
operator|::
name|OwningPtr
operator|<
specifier|const
name|llvm
operator|::
name|MCAsmInfo
operator|>
name|AsmInfo
expr_stmt|;
comment|/// The disassembler for the target architecture
name|llvm
operator|::
name|OwningPtr
operator|<
specifier|const
name|llvm
operator|::
name|MCDisassembler
operator|>
name|Disassembler
expr_stmt|;
comment|/// The output string for the instruction printer; must be guarded with
comment|///   PrinterMutex
name|llvm
operator|::
name|OwningPtr
operator|<
name|std
operator|::
name|string
operator|>
name|InstString
expr_stmt|;
comment|/// The output stream for the disassembler; must be guarded with
comment|///   PrinterMutex
name|llvm
operator|::
name|OwningPtr
operator|<
name|llvm
operator|::
name|raw_string_ostream
operator|>
name|InstStream
expr_stmt|;
comment|/// The instruction printer for the target architecture; must be guarded with
comment|///   PrinterMutex when printing
name|llvm
operator|::
name|OwningPtr
operator|<
name|llvm
operator|::
name|MCInstPrinter
operator|>
name|InstPrinter
expr_stmt|;
comment|/// The mutex that guards the instruction printer's printing functions, which
comment|///   use a shared stream
name|llvm
operator|::
name|sys
operator|::
name|Mutex
name|PrinterMutex
expr_stmt|;
comment|/// The array of instruction information provided by the TableGen backend for
comment|///   the target architecture
specifier|const
name|llvm
operator|::
name|EDInstInfo
operator|*
name|InstInfos
expr_stmt|;
comment|/// The target-specific lexer for use in tokenizing strings, in
comment|///   target-independent and target-specific portions
name|llvm
operator|::
name|OwningPtr
operator|<
name|llvm
operator|::
name|AsmLexer
operator|>
name|GenericAsmLexer
expr_stmt|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|llvm
operator|::
name|TargetAsmLexer
operator|>
name|SpecificAsmLexer
expr_stmt|;
comment|/// The guard for the above
name|llvm
operator|::
name|sys
operator|::
name|Mutex
name|ParserMutex
expr_stmt|;
comment|/// The LLVM number used for the target disassembly syntax variant
name|int
name|LLVMSyntaxVariant
decl_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|regvec_t
expr_stmt|;
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
name|regrmap_t
expr_stmt|;
comment|/// A vector of registers for quick mapping from LLVM register IDs to names
name|regvec_t
name|RegVec
decl_stmt|;
comment|/// A map of registers for quick mapping from register names to LLVM IDs
name|regrmap_t
name|RegRMap
decl_stmt|;
comment|/// A set of register IDs for aliases of the stack pointer for the current
comment|///   architecture
name|std
operator|::
name|set
operator|<
name|unsigned
operator|>
name|stackPointers
expr_stmt|;
comment|/// A set of register IDs for aliases of the program counter for the current
comment|///   architecture
name|std
operator|::
name|set
operator|<
name|unsigned
operator|>
name|programCounters
expr_stmt|;
comment|/// Constructor - initializes a disassembler with all the necessary objects,
comment|///   which come pre-allocated from the registry accessor function
comment|///
comment|/// @arg key                - the architecture and disassembly syntax for the
comment|///                           disassembler
name|EDDisassembler
argument_list|(
name|CPUKey
operator|&
name|key
argument_list|)
expr_stmt|;
comment|/// valid - reports whether there was a failure in the constructor.
name|bool
name|valid
parameter_list|()
block|{
return|return
name|Valid
return|;
block|}
comment|/// hasSemantics - reports whether the disassembler can provide operands and
comment|///   tokens.
name|bool
name|hasSemantics
parameter_list|()
block|{
return|return
name|HasSemantics
return|;
block|}
operator|~
name|EDDisassembler
argument_list|()
expr_stmt|;
comment|/// createInst - creates and returns an instruction given a callback and
comment|///   memory address, or NULL on failure
comment|///
comment|/// @arg byteReader - A callback function that provides machine code bytes
comment|/// @arg address    - The address of the first byte of the instruction,
comment|///                   suitable for passing to byteReader
comment|/// @arg arg        - An opaque argument for byteReader
name|EDInst
modifier|*
name|createInst
parameter_list|(
name|EDByteReaderCallback
name|byteReader
parameter_list|,
name|uint64_t
name|address
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
comment|/// initMaps - initializes regVec and regRMap using the provided register
comment|///   info
comment|///
comment|/// @arg registerInfo - the register information to use as a source
name|void
name|initMaps
argument_list|(
specifier|const
name|llvm
operator|::
name|TargetRegisterInfo
operator|&
name|registerInfo
argument_list|)
decl_stmt|;
comment|/// nameWithRegisterID - Returns the name (owned by the EDDisassembler) of a
comment|///   register for a given register ID, or NULL on failure
comment|///
comment|/// @arg registerID - the ID of the register to be queried
specifier|const
name|char
modifier|*
name|nameWithRegisterID
argument_list|(
name|unsigned
name|registerID
argument_list|)
decl|const
decl_stmt|;
comment|/// registerIDWithName - Returns the ID of a register for a given register
comment|///   name, or (unsigned)-1 on failure
comment|///
comment|/// @arg name - The name of the register
name|unsigned
name|registerIDWithName
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
decl|const
decl_stmt|;
comment|/// registerIsStackPointer - reports whether a register ID is an alias for the
comment|///   stack pointer register
comment|///
comment|/// @arg registerID - The LLVM register ID
name|bool
name|registerIsStackPointer
parameter_list|(
name|unsigned
name|registerID
parameter_list|)
function_decl|;
comment|/// registerIsStackPointer - reports whether a register ID is an alias for the
comment|///   stack pointer register
comment|///
comment|/// @arg registerID - The LLVM register ID
name|bool
name|registerIsProgramCounter
parameter_list|(
name|unsigned
name|registerID
parameter_list|)
function_decl|;
comment|/// printInst - prints an MCInst to a string, returning 0 on success, or -1
comment|///   otherwise
comment|///
comment|/// @arg str  - A reference to a string which is filled in with the string
comment|///             representation of the instruction
comment|/// @arg inst - A reference to the MCInst to be printed
name|int
name|printInst
argument_list|(
name|std
operator|::
name|string
operator|&
name|str
argument_list|,
name|llvm
operator|::
name|MCInst
operator|&
name|inst
argument_list|)
decl_stmt|;
comment|/// parseInst - extracts operands and tokens from a string for use in
comment|///   tokenizing the string.  Returns 0 on success, or -1 otherwise.
comment|///
comment|/// @arg operands - A reference to a vector that will be filled in with the
comment|///                 parsed operands
comment|/// @arg tokens   - A reference to a vector that will be filled in with the
comment|///                 tokens
comment|/// @arg str      - The string representation of the instruction
name|int
name|parseInst
argument_list|(
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|MCParsedAsmOperand
operator|*
operator|>
operator|&
name|operands
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|AsmToken
operator|>
operator|&
name|tokens
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|str
argument_list|)
decl_stmt|;
comment|/// llvmSyntaxVariant - returns the LLVM syntax variant for this disassembler
name|int
name|llvmSyntaxVariant
argument_list|()
specifier|const
expr_stmt|;
block|}
struct|;
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

