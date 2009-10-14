begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Target/TargetRegistry.h - Target Registration -----------*- C++ -*-===//
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
comment|// This file exposes the TargetRegistry interface, which tools can use to access
end_comment

begin_comment
comment|// the appropriate target specific classes (TargetMachine, AsmPrinter, etc.)
end_comment

begin_comment
comment|// which have been registered.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Target specific class implementations should register themselves using the
end_comment

begin_comment
comment|// appropriate TargetRegistry interfaces.
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
name|LLVM_TARGET_TARGETREGISTRY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETREGISTRY_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AsmPrinter
decl_stmt|;
name|class
name|MCAsmParser
decl_stmt|;
name|class
name|MCCodeEmitter
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|MCDisassembler
decl_stmt|;
name|class
name|MCInstPrinter
decl_stmt|;
name|class
name|TargetAsmParser
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|formatted_raw_ostream
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// Target - Wrapper for Target specific information.
comment|///
comment|/// For registration purposes, this is a POD type so that targets can be
comment|/// registered without the use of static constructors.
comment|///
comment|/// Targets should implement a single global instance of this class (which
comment|/// will be zero initialized), and pass that instance to the TargetRegistry as
comment|/// part of their initialization.
name|class
name|Target
block|{
name|public
label|:
name|friend
struct_decl|struct
name|TargetRegistry
struct_decl|;
typedef|typedef
name|unsigned
argument_list|(
operator|*
name|TripleMatchQualityFnTy
argument_list|)
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|TT
argument_list|)
expr_stmt|;
typedef|typedef
specifier|const
name|MCAsmInfo
modifier|*
function_decl|(
modifier|*
name|AsmInfoCtorFnTy
function_decl|)
parameter_list|(
specifier|const
name|Target
modifier|&
name|T
parameter_list|,
specifier|const
name|StringRef
modifier|&
name|TT
parameter_list|)
function_decl|;
typedef|typedef
name|TargetMachine
argument_list|*
call|(
modifier|*
name|TargetMachineCtorTy
call|)
argument_list|(
specifier|const
name|Target
operator|&
name|T
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|TT
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Features
argument_list|)
argument_list|;     typedef
name|AsmPrinter
operator|*
operator|(
operator|*
name|AsmPrinterCtorTy
operator|)
operator|(
name|formatted_raw_ostream
operator|&
name|OS
operator|,
name|TargetMachine
operator|&
name|TM
operator|,
specifier|const
name|MCAsmInfo
operator|*
name|MAI
operator|,
name|bool
name|VerboseAsm
operator|)
argument_list|;     typedef
name|TargetAsmParser
operator|*
call|(
modifier|*
name|AsmParserCtorTy
call|)
argument_list|(
specifier|const
name|Target
operator|&
name|T
argument_list|,
name|MCAsmParser
operator|&
name|P
argument_list|)
argument_list|;     typedef
specifier|const
name|MCDisassembler
operator|*
call|(
modifier|*
name|MCDisassemblerCtorTy
call|)
argument_list|(
specifier|const
name|Target
operator|&
name|T
argument_list|)
argument_list|;     typedef
name|MCInstPrinter
operator|*
operator|(
operator|*
name|MCInstPrinterCtorTy
operator|)
operator|(
specifier|const
name|Target
operator|&
name|T
operator|,
name|unsigned
name|SyntaxVariant
operator|,
specifier|const
name|MCAsmInfo
operator|&
name|MAI
operator|,
name|raw_ostream
operator|&
name|O
operator|)
argument_list|;     typedef
name|MCCodeEmitter
operator|*
call|(
modifier|*
name|CodeEmitterCtorTy
call|)
argument_list|(
specifier|const
name|Target
operator|&
name|T
argument_list|,
name|TargetMachine
operator|&
name|TM
argument_list|)
argument_list|;
name|private
operator|:
comment|/// Next - The next registered target in the linked list, maintained by the
comment|/// TargetRegistry.
name|Target
operator|*
name|Next
argument_list|;
comment|/// TripleMatchQualityFn - The target function for rating the match quality
comment|/// of a triple.
name|TripleMatchQualityFnTy
name|TripleMatchQualityFn
argument_list|;
comment|/// Name - The target name.
specifier|const
name|char
operator|*
name|Name
argument_list|;
comment|/// ShortDesc - A short description of the target.
specifier|const
name|char
operator|*
name|ShortDesc
argument_list|;
comment|/// HasJIT - Whether this target supports the JIT.
name|bool
name|HasJIT
argument_list|;
name|AsmInfoCtorFnTy
name|AsmInfoCtorFn
argument_list|;
comment|/// TargetMachineCtorFn - Construction function for this target's
comment|/// TargetMachine, if registered.
name|TargetMachineCtorTy
name|TargetMachineCtorFn
argument_list|;
comment|/// AsmPrinterCtorFn - Construction function for this target's AsmPrinter,
comment|/// if registered.
name|AsmPrinterCtorTy
name|AsmPrinterCtorFn
argument_list|;
comment|/// AsmParserCtorFn - Construction function for this target's AsmParser,
comment|/// if registered.
name|AsmParserCtorTy
name|AsmParserCtorFn
argument_list|;
comment|/// MCDisassemblerCtorFn - Construction function for this target's
comment|/// MCDisassembler, if registered.
name|MCDisassemblerCtorTy
name|MCDisassemblerCtorFn
argument_list|;
comment|/// MCInstPrinterCtorFn - Construction function for this target's
comment|/// MCInstPrinter, if registered.
name|MCInstPrinterCtorTy
name|MCInstPrinterCtorFn
argument_list|;
comment|/// CodeEmitterCtorFn - Construction function for this target's CodeEmitter,
comment|/// if registered.
name|CodeEmitterCtorTy
name|CodeEmitterCtorFn
argument_list|;
name|public
operator|:
comment|/// @name Target Information
comment|/// @{
comment|// getNext - Return the next registered target.
specifier|const
name|Target
operator|*
name|getNext
argument_list|()
specifier|const
block|{
return|return
name|Next
return|;
block|}
comment|/// getName - Get the target name.
specifier|const
name|char
operator|*
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
comment|/// getShortDescription - Get a short description of the target.
specifier|const
name|char
operator|*
name|getShortDescription
argument_list|()
specifier|const
block|{
return|return
name|ShortDesc
return|;
block|}
comment|/// @}
comment|/// @name Feature Predicates
comment|/// @{
comment|/// hasJIT - Check if this targets supports the just-in-time compilation.
name|bool
name|hasJIT
argument_list|()
specifier|const
block|{
return|return
name|HasJIT
return|;
block|}
comment|/// hasTargetMachine - Check if this target supports code generation.
name|bool
name|hasTargetMachine
argument_list|()
specifier|const
block|{
return|return
name|TargetMachineCtorFn
operator|!=
literal|0
return|;
block|}
comment|/// hasAsmPrinter - Check if this target supports .s printing.
name|bool
name|hasAsmPrinter
argument_list|()
specifier|const
block|{
return|return
name|AsmPrinterCtorFn
operator|!=
literal|0
return|;
block|}
comment|/// hasAsmParser - Check if this target supports .s parsing.
name|bool
name|hasAsmParser
argument_list|()
specifier|const
block|{
return|return
name|AsmParserCtorFn
operator|!=
literal|0
return|;
block|}
comment|/// hasMCDisassembler - Check if this target has a disassembler.
name|bool
name|hasMCDisassembler
argument_list|()
specifier|const
block|{
return|return
name|MCDisassemblerCtorFn
operator|!=
literal|0
return|;
block|}
comment|/// hasMCInstPrinter - Check if this target has an instruction printer.
name|bool
name|hasMCInstPrinter
argument_list|()
specifier|const
block|{
return|return
name|MCInstPrinterCtorFn
operator|!=
literal|0
return|;
block|}
comment|/// hasCodeEmitter - Check if this target supports instruction encoding.
name|bool
name|hasCodeEmitter
argument_list|()
specifier|const
block|{
return|return
name|CodeEmitterCtorFn
operator|!=
literal|0
return|;
block|}
comment|/// @}
comment|/// @name Feature Constructors
comment|/// @{
comment|/// createAsmInfo - Create a MCAsmInfo implementation for the specified
comment|/// target triple.
comment|///
comment|/// \arg Triple - This argument is used to determine the target machine
comment|/// feature set; it should always be provided. Generally this should be
comment|/// either the target triple from the module, or the target triple of the
comment|/// host if that does not exist.
specifier|const
name|MCAsmInfo
modifier|*
name|createAsmInfo
argument_list|(
specifier|const
name|StringRef
operator|&
name|Triple
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|AsmInfoCtorFn
condition|)
return|return
literal|0
return|;
return|return
name|AsmInfoCtorFn
argument_list|(
operator|*
name|this
argument_list|,
name|Triple
argument_list|)
return|;
block|}
comment|/// createTargetMachine - Create a target specific machine implementation
comment|/// for the specified \arg Triple.
comment|///
comment|/// \arg Triple - This argument is used to determine the target machine
comment|/// feature set; it should always be provided. Generally this should be
comment|/// either the target triple from the module, or the target triple of the
comment|/// host if that does not exist.
name|TargetMachine
modifier|*
name|createTargetMachine
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Triple
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Features
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|TargetMachineCtorFn
condition|)
return|return
literal|0
return|;
return|return
name|TargetMachineCtorFn
argument_list|(
operator|*
name|this
argument_list|,
name|Triple
argument_list|,
name|Features
argument_list|)
return|;
block|}
comment|/// createAsmPrinter - Create a target specific assembly printer pass.
name|AsmPrinter
modifier|*
name|createAsmPrinter
argument_list|(
name|formatted_raw_ostream
operator|&
name|OS
argument_list|,
name|TargetMachine
operator|&
name|TM
argument_list|,
specifier|const
name|MCAsmInfo
operator|*
name|MAI
argument_list|,
name|bool
name|Verbose
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|AsmPrinterCtorFn
condition|)
return|return
literal|0
return|;
return|return
name|AsmPrinterCtorFn
argument_list|(
name|OS
argument_list|,
name|TM
argument_list|,
name|MAI
argument_list|,
name|Verbose
argument_list|)
return|;
block|}
comment|/// createAsmParser - Create a target specific assembly parser.
comment|///
comment|/// \arg Parser - The target independent parser implementation to use for
comment|/// parsing and lexing.
name|TargetAsmParser
modifier|*
name|createAsmParser
argument_list|(
name|MCAsmParser
operator|&
name|Parser
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|AsmParserCtorFn
condition|)
return|return
literal|0
return|;
return|return
name|AsmParserCtorFn
argument_list|(
operator|*
name|this
argument_list|,
name|Parser
argument_list|)
return|;
block|}
specifier|const
name|MCDisassembler
operator|*
name|createMCDisassembler
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|MCDisassemblerCtorFn
condition|)
return|return
literal|0
return|;
return|return
name|MCDisassemblerCtorFn
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
name|MCInstPrinter
modifier|*
name|createMCInstPrinter
argument_list|(
name|unsigned
name|SyntaxVariant
argument_list|,
specifier|const
name|MCAsmInfo
operator|&
name|MAI
argument_list|,
name|raw_ostream
operator|&
name|O
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|MCInstPrinterCtorFn
condition|)
return|return
literal|0
return|;
return|return
name|MCInstPrinterCtorFn
argument_list|(
operator|*
name|this
argument_list|,
name|SyntaxVariant
argument_list|,
name|MAI
argument_list|,
name|O
argument_list|)
return|;
block|}
comment|/// createCodeEmitter - Create a target specific code emitter.
name|MCCodeEmitter
modifier|*
name|createCodeEmitter
argument_list|(
name|TargetMachine
operator|&
name|TM
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|CodeEmitterCtorFn
condition|)
return|return
literal|0
return|;
return|return
name|CodeEmitterCtorFn
argument_list|(
operator|*
name|this
argument_list|,
name|TM
argument_list|)
return|;
block|}
comment|/// @}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// TargetRegistry - Generic interface to target specific features.
end_comment

begin_struct
struct|struct
name|TargetRegistry
block|{
name|class
name|iterator
block|{
specifier|const
name|Target
modifier|*
name|Current
decl_stmt|;
name|explicit
name|iterator
argument_list|(
name|Target
operator|*
name|T
argument_list|)
operator|:
name|Current
argument_list|(
argument|T
argument_list|)
block|{}
name|friend
expr|struct
name|TargetRegistry
expr_stmt|;
name|public
label|:
name|iterator
argument_list|(
specifier|const
name|iterator
operator|&
name|I
argument_list|)
operator|:
name|Current
argument_list|(
argument|I.Current
argument_list|)
block|{}
name|iterator
argument_list|()
operator|:
name|Current
argument_list|(
literal|0
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|iterator
operator|&
name|x
operator|)
specifier|const
block|{
return|return
name|Current
operator|==
name|x
operator|.
name|Current
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|iterator
operator|&
name|x
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|x
operator|)
return|;
block|}
comment|// Iterator traversal: forward iteration only
name|iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// Preincrement
name|assert
argument_list|(
name|Current
operator|&&
literal|"Cannot increment end iterator!"
argument_list|)
block|;
name|Current
operator|=
name|Current
operator|->
name|getNext
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
name|iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// Postincrement
name|iterator
name|tmp
operator|=
operator|*
name|this
block|;
operator|++
operator|*
name|this
block|;
return|return
name|tmp
return|;
block|}
specifier|const
name|Target
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|Current
operator|&&
literal|"Cannot dereference end iterator!"
argument_list|)
block|;
return|return
operator|*
name|Current
return|;
block|}
specifier|const
name|Target
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
operator|&
name|operator
operator|*
operator|(
operator|)
return|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|/// @name Registry Access
end_comment

begin_comment
comment|/// @{
end_comment

begin_function_decl
specifier|static
name|iterator
name|begin
parameter_list|()
function_decl|;
end_function_decl

begin_function
specifier|static
name|iterator
name|end
parameter_list|()
block|{
return|return
name|iterator
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// lookupTarget - Lookup a target based on a target triple.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Triple - The triple to use for finding a target.
end_comment

begin_comment
comment|/// \param Error - On failure, an error string describing why no target was
end_comment

begin_comment
comment|/// found.
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|Target
modifier|*
name|lookupTarget
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Triple
argument_list|,
name|std
operator|::
name|string
operator|&
name|Error
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getClosestTargetForJIT - Pick the best target that is compatible with
end_comment

begin_comment
comment|/// the current host.  If no close target can be found, this returns null
end_comment

begin_comment
comment|/// and sets the Error string to a reason.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Maintained for compatibility through 2.6.
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|Target
modifier|*
name|getClosestTargetForJIT
argument_list|(
name|std
operator|::
name|string
operator|&
name|Error
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Target Registration
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// RegisterTarget - Register the given target. Attempts to register a
end_comment

begin_comment
comment|/// target which has already been registered will be ignored.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Clients are responsible for ensuring that registration doesn't occur
end_comment

begin_comment
comment|/// while another thread is attempting to access the registry. Typically
end_comment

begin_comment
comment|/// this is done by initializing all targets at program startup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param T - The target being registered.
end_comment

begin_comment
comment|/// @param Name - The target name. This should be a static string.
end_comment

begin_comment
comment|/// @param ShortDesc - A short target description. This should be a static
end_comment

begin_comment
comment|/// string.
end_comment

begin_comment
comment|/// @param TQualityFn - The triple match quality computation function for
end_comment

begin_comment
comment|/// this target.
end_comment

begin_comment
comment|/// @param HasJIT - Whether the target supports JIT code
end_comment

begin_comment
comment|/// generation.
end_comment

begin_decl_stmt
specifier|static
name|void
name|RegisterTarget
argument_list|(
name|Target
operator|&
name|T
argument_list|,
specifier|const
name|char
operator|*
name|Name
argument_list|,
specifier|const
name|char
operator|*
name|ShortDesc
argument_list|,
name|Target
operator|::
name|TripleMatchQualityFnTy
name|TQualityFn
argument_list|,
name|bool
name|HasJIT
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// RegisterAsmInfo - Register a MCAsmInfo implementation for the
end_comment

begin_comment
comment|/// given target.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Clients are responsible for ensuring that registration doesn't occur
end_comment

begin_comment
comment|/// while another thread is attempting to access the registry. Typically
end_comment

begin_comment
comment|/// this is done by initializing all targets at program startup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param T - The target being registered.
end_comment

begin_comment
comment|/// @param Fn - A function to construct a MCAsmInfo for the target.
end_comment

begin_decl_stmt
specifier|static
name|void
name|RegisterAsmInfo
argument_list|(
name|Target
operator|&
name|T
argument_list|,
name|Target
operator|::
name|AsmInfoCtorFnTy
name|Fn
argument_list|)
block|{
comment|// Ignore duplicate registration.
if|if
condition|(
operator|!
name|T
operator|.
name|AsmInfoCtorFn
condition|)
name|T
operator|.
name|AsmInfoCtorFn
operator|=
name|Fn
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// RegisterTargetMachine - Register a TargetMachine implementation for the
end_comment

begin_comment
comment|/// given target.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Clients are responsible for ensuring that registration doesn't occur
end_comment

begin_comment
comment|/// while another thread is attempting to access the registry. Typically
end_comment

begin_comment
comment|/// this is done by initializing all targets at program startup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param T - The target being registered.
end_comment

begin_comment
comment|/// @param Fn - A function to construct a TargetMachine for the target.
end_comment

begin_decl_stmt
specifier|static
name|void
name|RegisterTargetMachine
argument_list|(
name|Target
operator|&
name|T
argument_list|,
name|Target
operator|::
name|TargetMachineCtorTy
name|Fn
argument_list|)
block|{
comment|// Ignore duplicate registration.
if|if
condition|(
operator|!
name|T
operator|.
name|TargetMachineCtorFn
condition|)
name|T
operator|.
name|TargetMachineCtorFn
operator|=
name|Fn
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// RegisterAsmPrinter - Register an AsmPrinter implementation for the given
end_comment

begin_comment
comment|/// target.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Clients are responsible for ensuring that registration doesn't occur
end_comment

begin_comment
comment|/// while another thread is attempting to access the registry. Typically
end_comment

begin_comment
comment|/// this is done by initializing all targets at program startup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param T - The target being registered.
end_comment

begin_comment
comment|/// @param Fn - A function to construct an AsmPrinter for the target.
end_comment

begin_decl_stmt
specifier|static
name|void
name|RegisterAsmPrinter
argument_list|(
name|Target
operator|&
name|T
argument_list|,
name|Target
operator|::
name|AsmPrinterCtorTy
name|Fn
argument_list|)
block|{
comment|// Ignore duplicate registration.
if|if
condition|(
operator|!
name|T
operator|.
name|AsmPrinterCtorFn
condition|)
name|T
operator|.
name|AsmPrinterCtorFn
operator|=
name|Fn
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// RegisterAsmParser - Register a TargetAsmParser implementation for the
end_comment

begin_comment
comment|/// given target.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Clients are responsible for ensuring that registration doesn't occur
end_comment

begin_comment
comment|/// while another thread is attempting to access the registry. Typically
end_comment

begin_comment
comment|/// this is done by initializing all targets at program startup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param T - The target being registered.
end_comment

begin_comment
comment|/// @param Fn - A function to construct an AsmPrinter for the target.
end_comment

begin_decl_stmt
specifier|static
name|void
name|RegisterAsmParser
argument_list|(
name|Target
operator|&
name|T
argument_list|,
name|Target
operator|::
name|AsmParserCtorTy
name|Fn
argument_list|)
block|{
if|if
condition|(
operator|!
name|T
operator|.
name|AsmParserCtorFn
condition|)
name|T
operator|.
name|AsmParserCtorFn
operator|=
name|Fn
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// RegisterMCDisassembler - Register a MCDisassembler implementation for
end_comment

begin_comment
comment|/// the given target.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Clients are responsible for ensuring that registration doesn't occur
end_comment

begin_comment
comment|/// while another thread is attempting to access the registry. Typically
end_comment

begin_comment
comment|/// this is done by initializing all targets at program startup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param T - The target being registered.
end_comment

begin_comment
comment|/// @param Fn - A function to construct an MCDisassembler for the target.
end_comment

begin_decl_stmt
specifier|static
name|void
name|RegisterMCDisassembler
argument_list|(
name|Target
operator|&
name|T
argument_list|,
name|Target
operator|::
name|MCDisassemblerCtorTy
name|Fn
argument_list|)
block|{
if|if
condition|(
operator|!
name|T
operator|.
name|MCDisassemblerCtorFn
condition|)
name|T
operator|.
name|MCDisassemblerCtorFn
operator|=
name|Fn
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|RegisterMCInstPrinter
argument_list|(
name|Target
operator|&
name|T
argument_list|,
name|Target
operator|::
name|MCInstPrinterCtorTy
name|Fn
argument_list|)
block|{
if|if
condition|(
operator|!
name|T
operator|.
name|MCInstPrinterCtorFn
condition|)
name|T
operator|.
name|MCInstPrinterCtorFn
operator|=
name|Fn
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// RegisterCodeEmitter - Register a MCCodeEmitter implementation for the
end_comment

begin_comment
comment|/// given target.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Clients are responsible for ensuring that registration doesn't occur
end_comment

begin_comment
comment|/// while another thread is attempting to access the registry. Typically
end_comment

begin_comment
comment|/// this is done by initializing all targets at program startup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param T - The target being registered.
end_comment

begin_comment
comment|/// @param Fn - A function to construct an AsmPrinter for the target.
end_comment

begin_decl_stmt
specifier|static
name|void
name|RegisterCodeEmitter
argument_list|(
name|Target
operator|&
name|T
argument_list|,
name|Target
operator|::
name|CodeEmitterCtorTy
name|Fn
argument_list|)
block|{
if|if
condition|(
operator|!
name|T
operator|.
name|CodeEmitterCtorFn
condition|)
name|T
operator|.
name|CodeEmitterCtorFn
operator|=
name|Fn
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
unit|};
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// RegisterTarget - Helper template for registering a target, for use in the
end_comment

begin_comment
comment|/// target's initialization function. Usage:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Target TheFooTarget; // The global target instance.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// extern "C" void LLVMInitializeFooTargetInfo() {
end_comment

begin_comment
comment|///   RegisterTarget<Triple::foo> X(TheFooTarget, "foo", "Foo description");
end_comment

begin_comment
comment|/// }
end_comment

begin_expr_stmt
name|template
operator|<
name|Triple
operator|::
name|ArchType
name|TargetArchType
operator|=
name|Triple
operator|::
name|InvalidArch
operator|,
name|bool
name|HasJIT
operator|=
name|false
operator|>
expr|struct
name|RegisterTarget
block|{
name|RegisterTarget
argument_list|(
argument|Target&T
argument_list|,
argument|const char *Name
argument_list|,
argument|const char *Desc
argument_list|)
block|{
name|TargetRegistry
operator|::
name|RegisterTarget
argument_list|(
name|T
argument_list|,
name|Name
argument_list|,
name|Desc
argument_list|,
operator|&
name|getTripleMatchQuality
argument_list|,
name|HasJIT
argument_list|)
block|;     }
specifier|static
name|unsigned
name|getTripleMatchQuality
argument_list|(
argument|const std::string&TT
argument_list|)
block|{
if|if
condition|(
name|Triple
argument_list|(
name|TT
argument_list|)
operator|.
name|getArch
argument_list|()
operator|==
name|TargetArchType
condition|)
return|return
literal|20
return|;
return|return
literal|0
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// RegisterAsmInfo - Helper template for registering a target assembly info
end_comment

begin_comment
comment|/// implementation.  This invokes the static "Create" method on the class to
end_comment

begin_comment
comment|/// actually do the construction.  Usage:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// extern "C" void LLVMInitializeFooTarget() {
end_comment

begin_comment
comment|///   extern Target TheFooTarget;
end_comment

begin_comment
comment|///   RegisterAsmInfo<FooMCAsmInfo> X(TheFooTarget);
end_comment

begin_comment
comment|/// }
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|MCAsmInfoImpl
operator|>
expr|struct
name|RegisterAsmInfo
block|{
name|RegisterAsmInfo
argument_list|(
argument|Target&T
argument_list|)
block|{
name|TargetRegistry
operator|::
name|RegisterAsmInfo
argument_list|(
name|T
argument_list|,
operator|&
name|Allocator
argument_list|)
block|;     }
name|private
operator|:
specifier|static
specifier|const
name|MCAsmInfo
operator|*
name|Allocator
argument_list|(
argument|const Target&T
argument_list|,
argument|const StringRef&TT
argument_list|)
block|{
return|return
name|new
name|MCAsmInfoImpl
argument_list|(
name|T
argument_list|,
name|TT
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// RegisterAsmInfoFn - Helper template for registering a target assembly info
end_comment

begin_comment
comment|/// implementation.  This invokes the specified function to do the
end_comment

begin_comment
comment|/// construction.  Usage:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// extern "C" void LLVMInitializeFooTarget() {
end_comment

begin_comment
comment|///   extern Target TheFooTarget;
end_comment

begin_comment
comment|///   RegisterAsmInfoFn X(TheFooTarget, TheFunction);
end_comment

begin_comment
comment|/// }
end_comment

begin_struct
struct|struct
name|RegisterAsmInfoFn
block|{
name|RegisterAsmInfoFn
argument_list|(
argument|Target&T
argument_list|,
argument|Target::AsmInfoCtorFnTy Fn
argument_list|)
block|{
name|TargetRegistry
operator|::
name|RegisterAsmInfo
argument_list|(
name|T
argument_list|,
name|Fn
argument_list|)
expr_stmt|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|/// RegisterTargetMachine - Helper template for registering a target machine
end_comment

begin_comment
comment|/// implementation, for use in the target machine initialization
end_comment

begin_comment
comment|/// function. Usage:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// extern "C" void LLVMInitializeFooTarget() {
end_comment

begin_comment
comment|///   extern Target TheFooTarget;
end_comment

begin_comment
comment|///   RegisterTargetMachine<FooTargetMachine> X(TheFooTarget);
end_comment

begin_comment
comment|/// }
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|TargetMachineImpl
operator|>
expr|struct
name|RegisterTargetMachine
block|{
name|RegisterTargetMachine
argument_list|(
argument|Target&T
argument_list|)
block|{
name|TargetRegistry
operator|::
name|RegisterTargetMachine
argument_list|(
name|T
argument_list|,
operator|&
name|Allocator
argument_list|)
block|;     }
name|private
operator|:
specifier|static
name|TargetMachine
operator|*
name|Allocator
argument_list|(
argument|const Target&T
argument_list|,
argument|const std::string&TT
argument_list|,
argument|const std::string&FS
argument_list|)
block|{
return|return
name|new
name|TargetMachineImpl
argument_list|(
name|T
argument_list|,
name|TT
argument_list|,
name|FS
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// RegisterAsmPrinter - Helper template for registering a target specific
end_comment

begin_comment
comment|/// assembly printer, for use in the target machine initialization
end_comment

begin_comment
comment|/// function. Usage:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// extern "C" void LLVMInitializeFooAsmPrinter() {
end_comment

begin_comment
comment|///   extern Target TheFooTarget;
end_comment

begin_comment
comment|///   RegisterAsmPrinter<FooAsmPrinter> X(TheFooTarget);
end_comment

begin_comment
comment|/// }
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|AsmPrinterImpl
operator|>
expr|struct
name|RegisterAsmPrinter
block|{
name|RegisterAsmPrinter
argument_list|(
argument|Target&T
argument_list|)
block|{
name|TargetRegistry
operator|::
name|RegisterAsmPrinter
argument_list|(
name|T
argument_list|,
operator|&
name|Allocator
argument_list|)
block|;     }
name|private
operator|:
specifier|static
name|AsmPrinter
operator|*
name|Allocator
argument_list|(
argument|formatted_raw_ostream&OS
argument_list|,
argument|TargetMachine&TM
argument_list|,
argument|const MCAsmInfo *MAI
argument_list|,
argument|bool Verbose
argument_list|)
block|{
return|return
name|new
name|AsmPrinterImpl
argument_list|(
name|OS
argument_list|,
name|TM
argument_list|,
name|MAI
argument_list|,
name|Verbose
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// RegisterAsmParser - Helper template for registering a target specific
end_comment

begin_comment
comment|/// assembly parser, for use in the target machine initialization
end_comment

begin_comment
comment|/// function. Usage:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// extern "C" void LLVMInitializeFooAsmParser() {
end_comment

begin_comment
comment|///   extern Target TheFooTarget;
end_comment

begin_comment
comment|///   RegisterAsmParser<FooAsmParser> X(TheFooTarget);
end_comment

begin_comment
comment|/// }
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|AsmParserImpl
operator|>
expr|struct
name|RegisterAsmParser
block|{
name|RegisterAsmParser
argument_list|(
argument|Target&T
argument_list|)
block|{
name|TargetRegistry
operator|::
name|RegisterAsmParser
argument_list|(
name|T
argument_list|,
operator|&
name|Allocator
argument_list|)
block|;     }
name|private
operator|:
specifier|static
name|TargetAsmParser
operator|*
name|Allocator
argument_list|(
argument|const Target&T
argument_list|,
argument|MCAsmParser&P
argument_list|)
block|{
return|return
name|new
name|AsmParserImpl
argument_list|(
name|T
argument_list|,
name|P
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// RegisterCodeEmitter - Helper template for registering a target specific
end_comment

begin_comment
comment|/// machine code emitter, for use in the target initialization
end_comment

begin_comment
comment|/// function. Usage:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// extern "C" void LLVMInitializeFooCodeEmitter() {
end_comment

begin_comment
comment|///   extern Target TheFooTarget;
end_comment

begin_comment
comment|///   RegisterCodeEmitter<FooCodeEmitter> X(TheFooTarget);
end_comment

begin_comment
comment|/// }
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|CodeEmitterImpl
operator|>
expr|struct
name|RegisterCodeEmitter
block|{
name|RegisterCodeEmitter
argument_list|(
argument|Target&T
argument_list|)
block|{
name|TargetRegistry
operator|::
name|RegisterCodeEmitter
argument_list|(
name|T
argument_list|,
operator|&
name|Allocator
argument_list|)
block|;     }
name|private
operator|:
specifier|static
name|MCCodeEmitter
operator|*
name|Allocator
argument_list|(
argument|const Target&T
argument_list|,
argument|TargetMachine&TM
argument_list|)
block|{
return|return
name|new
name|CodeEmitterImpl
argument_list|(
name|T
argument_list|,
name|TM
argument_list|)
return|;
block|}
end_expr_stmt

begin_endif
unit|};  }
endif|#
directive|endif
end_endif

end_unit

