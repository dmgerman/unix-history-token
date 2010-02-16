begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-EDDisassembler.h - LLVM Enhanced Disassembler -------------*- C++ -*-===//
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
name|EDDisassembler_
end_ifndef

begin_define
define|#
directive|define
name|EDDisassembler_
end_define

begin_include
include|#
directive|include
file|"EDInfo.inc"
end_include

begin_include
include|#
directive|include
file|"llvm-c/EnhancedDisassembly.h"
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
file|"llvm/System/Mutex.h"
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
file|<string>
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
name|TargetRegisterInfo
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// EDDisassembler - Encapsulates a disassembler for a single architecture and
end_comment

begin_comment
comment|///   disassembly syntax.  Also manages the static disassembler registry.
end_comment

begin_struct
struct|struct
name|EDDisassembler
block|{
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
name|EDAssemblySyntax_t
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
if|if
condition|(
name|Arch
operator|>
name|key
operator|.
name|Arch
condition|)
return|return
name|false
return|;
if|if
condition|(
name|Syntax
operator|>=
name|key
operator|.
name|Syntax
condition|)
return|return
name|false
return|;
return|return
name|true
return|;
block|}
block|}
struct|;
end_struct

begin_typedef
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
end_typedef

begin_comment
comment|/// True if the disassembler registry has been initialized; false if not
end_comment

begin_decl_stmt
specifier|static
name|bool
name|sInitialized
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// A map from disassembler specifications to disassemblers.  Populated
end_comment

begin_comment
comment|///   lazily.
end_comment

begin_decl_stmt
specifier|static
name|DisassemblerMap_t
name|sDisassemblers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getDisassembler - Returns the specified disassemble, or NULL on failure
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @arg arch   - The desired architecture
end_comment

begin_comment
comment|/// @arg syntax - The desired disassembly syntax
end_comment

begin_decl_stmt
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
name|EDAssemblySyntax_t
name|syntax
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getDisassembler - Returns the disassembler for a given combination of
end_comment

begin_comment
comment|///   CPU type, CPU subtype, and assembly syntax, or NULL on failure
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @arg str    - The string representation of the architecture triple, e.g.,
end_comment

begin_comment
comment|///               "x86_64-apple-darwin"
end_comment

begin_comment
comment|/// @arg syntax - The disassembly syntax for the required disassembler
end_comment

begin_decl_stmt
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
name|EDAssemblySyntax_t
name|syntax
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// initialize - Initializes the disassembler registry and the LLVM backend
end_comment

begin_function_decl
specifier|static
name|void
name|initialize
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|////////////////////////
end_comment

begin_comment
comment|// Per-object members //
end_comment

begin_comment
comment|////////////////////////
end_comment

begin_comment
comment|/// True only if the object has been fully and successfully initialized
end_comment

begin_decl_stmt
name|bool
name|Valid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The string that stores disassembler errors from the backend
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|ErrorString
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// The stream that wraps the ErrorString
end_comment

begin_expr_stmt
name|llvm
operator|::
name|raw_string_ostream
name|ErrorStream
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// The architecture/syntax pair for the current architecture
end_comment

begin_decl_stmt
name|CPUKey
name|Key
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The LLVM target corresponding to the disassembler
end_comment

begin_expr_stmt
specifier|const
name|llvm
operator|::
name|Target
operator|*
name|Tgt
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// The assembly information for the target architecture
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// The disassembler for the target architecture
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// The output string for the instruction printer; must be guarded with
end_comment

begin_comment
comment|///   PrinterMutex
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// The output stream for the disassembler; must be guarded with
end_comment

begin_comment
comment|///   PrinterMutex
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// The instruction printer for the target architecture; must be guarded with
end_comment

begin_comment
comment|///   PrinterMutex when printing
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// The mutex that guards the instruction printer's printing functions, which
end_comment

begin_comment
comment|///   use a shared stream
end_comment

begin_expr_stmt
name|llvm
operator|::
name|sys
operator|::
name|Mutex
name|PrinterMutex
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// The array of instruction information provided by the TableGen backend for
end_comment

begin_comment
comment|///   the target architecture
end_comment

begin_decl_stmt
specifier|const
name|InstInfo
modifier|*
name|InstInfos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The target-specific lexer for use in tokenizing strings, in
end_comment

begin_comment
comment|///   target-independent and target-specific portions
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// The guard for the above
end_comment

begin_expr_stmt
name|llvm
operator|::
name|sys
operator|::
name|Mutex
name|ParserMutex
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// The LLVM number used for the target disassembly syntax variant
end_comment

begin_decl_stmt
name|int
name|LLVMSyntaxVariant
decl_stmt|;
end_decl_stmt

begin_typedef
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
end_typedef

begin_typedef
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
end_typedef

begin_comment
comment|/// A vector of registers for quick mapping from LLVM register IDs to names
end_comment

begin_decl_stmt
name|regvec_t
name|RegVec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// A map of registers for quick mapping from register names to LLVM IDs
end_comment

begin_decl_stmt
name|regrmap_t
name|RegRMap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// A set of register IDs for aliases of the stack pointer for the current
end_comment

begin_comment
comment|///   architecture
end_comment

begin_expr_stmt
name|std
operator|::
name|set
operator|<
name|unsigned
operator|>
name|stackPointers
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// A set of register IDs for aliases of the program counter for the current
end_comment

begin_comment
comment|///   architecture
end_comment

begin_expr_stmt
name|std
operator|::
name|set
operator|<
name|unsigned
operator|>
name|programCounters
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Constructor - initializes a disassembler with all the necessary objects,
end_comment

begin_comment
comment|///   which come pre-allocated from the registry accessor function
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @arg key                - the architecture and disassembly syntax for the
end_comment

begin_comment
comment|///                           disassembler
end_comment

begin_expr_stmt
name|EDDisassembler
argument_list|(
name|CPUKey
operator|&
name|key
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// valid - reports whether there was a failure in the constructor.
end_comment

begin_function
name|bool
name|valid
parameter_list|()
block|{
return|return
name|Valid
return|;
block|}
end_function

begin_expr_stmt
operator|~
name|EDDisassembler
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// createInst - creates and returns an instruction given a callback and
end_comment

begin_comment
comment|///   memory address, or NULL on failure
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @arg byteReader - A callback function that provides machine code bytes
end_comment

begin_comment
comment|/// @arg address    - The address of the first byte of the instruction,
end_comment

begin_comment
comment|///                   suitable for passing to byteReader
end_comment

begin_comment
comment|/// @arg arg        - An opaque argument for byteReader
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// initMaps - initializes regVec and regRMap using the provided register
end_comment

begin_comment
comment|///   info
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @arg registerInfo - the register information to use as a source
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// nameWithRegisterID - Returns the name (owned by the EDDisassembler) of a
end_comment

begin_comment
comment|///   register for a given register ID, or NULL on failure
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @arg registerID - the ID of the register to be queried
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// registerIDWithName - Returns the ID of a register for a given register
end_comment

begin_comment
comment|///   name, or (unsigned)-1 on failure
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @arg name - The name of the register
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// registerIsStackPointer - reports whether a register ID is an alias for the
end_comment

begin_comment
comment|///   stack pointer register
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @arg registerID - The LLVM register ID
end_comment

begin_function_decl
name|bool
name|registerIsStackPointer
parameter_list|(
name|unsigned
name|registerID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// registerIsStackPointer - reports whether a register ID is an alias for the
end_comment

begin_comment
comment|///   stack pointer register
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @arg registerID - The LLVM register ID
end_comment

begin_function_decl
name|bool
name|registerIsProgramCounter
parameter_list|(
name|unsigned
name|registerID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// printInst - prints an MCInst to a string, returning 0 on success, or -1
end_comment

begin_comment
comment|///   otherwise
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @arg str  - A reference to a string which is filled in with the string
end_comment

begin_comment
comment|///             representation of the instruction
end_comment

begin_comment
comment|/// @arg inst - A reference to the MCInst to be printed
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// parseInst - extracts operands and tokens from a string for use in
end_comment

begin_comment
comment|///   tokenizing the string.  Returns 0 on success, or -1 otherwise.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @arg operands - A reference to a vector that will be filled in with the
end_comment

begin_comment
comment|///                 parsed operands
end_comment

begin_comment
comment|/// @arg tokens   - A reference to a vector that will be filled in with the
end_comment

begin_comment
comment|///                 tokens
end_comment

begin_comment
comment|/// @arg str      - The string representation of the instruction
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// llvmSyntaxVariant - returns the LLVM syntax variant for this disassembler
end_comment

begin_expr_stmt
name|int
name|llvmSyntaxVariant
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

end_unit

