begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ubsan_diag.h --------------------------------------------*- C++ -*-===//
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
comment|// Diagnostics emission for Clang's undefined behavior sanitizer.
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
name|UBSAN_DIAG_H
end_ifndef

begin_define
define|#
directive|define
name|UBSAN_DIAG_H
end_define

begin_include
include|#
directive|include
file|"ubsan_value.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_stacktrace.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_symbolizer.h"
end_include

begin_decl_stmt
name|namespace
name|__ubsan
block|{
name|class
name|SymbolizedStackHolder
block|{
name|SymbolizedStack
modifier|*
name|Stack
decl_stmt|;
name|void
name|clear
parameter_list|()
block|{
if|if
condition|(
name|Stack
condition|)
name|Stack
operator|->
name|ClearAll
argument_list|()
expr_stmt|;
block|}
name|public
label|:
name|explicit
name|SymbolizedStackHolder
argument_list|(
name|SymbolizedStack
operator|*
name|Stack
operator|=
name|nullptr
argument_list|)
operator|:
name|Stack
argument_list|(
argument|Stack
argument_list|)
block|{}
operator|~
name|SymbolizedStackHolder
argument_list|()
block|{
name|clear
argument_list|()
block|; }
name|void
name|reset
argument_list|(
argument|SymbolizedStack *S
argument_list|)
block|{
if|if
condition|(
name|Stack
operator|!=
name|S
condition|)
name|clear
argument_list|()
expr_stmt|;
name|Stack
operator|=
name|S
expr_stmt|;
block|}
specifier|const
name|SymbolizedStack
operator|*
name|get
argument_list|()
specifier|const
block|{
return|return
name|Stack
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
name|SymbolizedStack
modifier|*
name|getSymbolizedLocation
parameter_list|(
name|uptr
name|PC
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|inline
name|SymbolizedStack
modifier|*
name|getCallerLocation
parameter_list|(
name|uptr
name|CallerPC
parameter_list|)
block|{
name|CHECK
argument_list|(
name|CallerPC
argument_list|)
expr_stmt|;
name|uptr
name|PC
init|=
name|StackTrace
operator|::
name|GetPreviousInstructionPc
argument_list|(
name|CallerPC
argument_list|)
decl_stmt|;
return|return
name|getSymbolizedLocation
argument_list|(
name|PC
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// A location of some data within the program's address space.
end_comment

begin_typedef
typedef|typedef
name|uptr
name|MemoryLocation
typedef|;
end_typedef

begin_comment
comment|/// \brief Location at which a diagnostic can be emitted. Either a
end_comment

begin_comment
comment|/// SourceLocation, a MemoryLocation, or a SymbolizedStack.
end_comment

begin_decl_stmt
name|class
name|Location
block|{
name|public
label|:
enum|enum
name|LocationKind
block|{
name|LK_Null
block|,
name|LK_Source
block|,
name|LK_Memory
block|,
name|LK_Symbolized
block|}
enum|;
name|private
label|:
name|LocationKind
name|Kind
decl_stmt|;
comment|// FIXME: In C++11, wrap these in an anonymous union.
name|SourceLocation
name|SourceLoc
decl_stmt|;
name|MemoryLocation
name|MemoryLoc
decl_stmt|;
specifier|const
name|SymbolizedStack
modifier|*
name|SymbolizedLoc
decl_stmt|;
comment|// Not owned.
name|public
label|:
name|Location
argument_list|()
operator|:
name|Kind
argument_list|(
argument|LK_Null
argument_list|)
block|{}
name|Location
argument_list|(
argument|SourceLocation Loc
argument_list|)
operator|:
name|Kind
argument_list|(
name|LK_Source
argument_list|)
operator|,
name|SourceLoc
argument_list|(
argument|Loc
argument_list|)
block|{}
name|Location
argument_list|(
argument|MemoryLocation Loc
argument_list|)
operator|:
name|Kind
argument_list|(
name|LK_Memory
argument_list|)
operator|,
name|MemoryLoc
argument_list|(
argument|Loc
argument_list|)
block|{}
comment|// SymbolizedStackHolder must outlive Location object.
name|Location
argument_list|(
specifier|const
name|SymbolizedStackHolder
operator|&
name|Stack
argument_list|)
operator|:
name|Kind
argument_list|(
name|LK_Symbolized
argument_list|)
operator|,
name|SymbolizedLoc
argument_list|(
argument|Stack.get()
argument_list|)
block|{}
name|LocationKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
name|bool
name|isSourceLocation
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|LK_Source
return|;
block|}
name|bool
name|isMemoryLocation
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|LK_Memory
return|;
block|}
name|bool
name|isSymbolizedStack
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|LK_Symbolized
return|;
block|}
name|SourceLocation
name|getSourceLocation
argument_list|()
specifier|const
block|{
name|CHECK
argument_list|(
name|isSourceLocation
argument_list|()
argument_list|)
block|;
return|return
name|SourceLoc
return|;
block|}
name|MemoryLocation
name|getMemoryLocation
argument_list|()
specifier|const
block|{
name|CHECK
argument_list|(
name|isMemoryLocation
argument_list|()
argument_list|)
block|;
return|return
name|MemoryLoc
return|;
block|}
specifier|const
name|SymbolizedStack
operator|*
name|getSymbolizedStack
argument_list|()
specifier|const
block|{
name|CHECK
argument_list|(
name|isSymbolizedStack
argument_list|()
argument_list|)
block|;
return|return
name|SymbolizedLoc
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// A diagnostic severity level.
end_comment

begin_enum
enum|enum
name|DiagLevel
block|{
name|DL_Error
block|,
comment|///< An error.
name|DL_Note
comment|///< A note, attached to a prior diagnostic.
block|}
enum|;
end_enum

begin_comment
comment|/// \brief Annotation for a range of locations in a diagnostic.
end_comment

begin_decl_stmt
name|class
name|Range
block|{
name|Location
name|Start
decl_stmt|,
name|End
decl_stmt|;
specifier|const
name|char
modifier|*
name|Text
decl_stmt|;
name|public
label|:
name|Range
argument_list|()
operator|:
name|Start
argument_list|()
operator|,
name|End
argument_list|()
operator|,
name|Text
argument_list|()
block|{}
name|Range
argument_list|(
argument|MemoryLocation Start
argument_list|,
argument|MemoryLocation End
argument_list|,
argument|const char *Text
argument_list|)
operator|:
name|Start
argument_list|(
name|Start
argument_list|)
operator|,
name|End
argument_list|(
name|End
argument_list|)
operator|,
name|Text
argument_list|(
argument|Text
argument_list|)
block|{}
name|Location
name|getStart
argument_list|()
specifier|const
block|{
return|return
name|Start
return|;
block|}
name|Location
name|getEnd
argument_list|()
specifier|const
block|{
return|return
name|End
return|;
block|}
specifier|const
name|char
operator|*
name|getText
argument_list|()
specifier|const
block|{
return|return
name|Text
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief A mangled C++ name. Really just a strong typedef for 'const char*'.
end_comment

begin_decl_stmt
name|class
name|MangledName
block|{
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
name|public
label|:
name|MangledName
argument_list|(
specifier|const
name|char
operator|*
name|Name
argument_list|)
operator|:
name|Name
argument_list|(
argument|Name
argument_list|)
block|{}
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Representation of an in-flight diagnostic.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Temporary \c Diag instances are created by the handler routines to
end_comment

begin_comment
comment|/// accumulate arguments for a diagnostic. The destructor emits the diagnostic
end_comment

begin_comment
comment|/// message.
end_comment

begin_decl_stmt
name|class
name|Diag
block|{
comment|/// The location at which the problem occurred.
name|Location
name|Loc
decl_stmt|;
comment|/// The diagnostic level.
name|DiagLevel
name|Level
decl_stmt|;
comment|/// The message which will be emitted, with %0, %1, ... placeholders for
comment|/// arguments.
specifier|const
name|char
modifier|*
name|Message
decl_stmt|;
name|public
label|:
comment|/// Kinds of arguments, corresponding to members of \c Arg's union.
enum|enum
name|ArgKind
block|{
name|AK_String
block|,
comment|///< A string argument, displayed as-is.
name|AK_Mangled
block|,
comment|///< A C++ mangled name, demangled before display.
name|AK_UInt
block|,
comment|///< An unsigned integer argument.
name|AK_SInt
block|,
comment|///< A signed integer argument.
name|AK_Float
block|,
comment|///< A floating-point argument.
name|AK_Pointer
comment|///< A pointer argument, displayed in hexadecimal.
block|}
enum|;
comment|/// An individual diagnostic message argument.
struct|struct
name|Arg
block|{
name|Arg
argument_list|()
block|{}
name|Arg
argument_list|(
specifier|const
name|char
operator|*
name|String
argument_list|)
operator|:
name|Kind
argument_list|(
name|AK_String
argument_list|)
operator|,
name|String
argument_list|(
argument|String
argument_list|)
block|{}
name|Arg
argument_list|(
argument|MangledName MN
argument_list|)
operator|:
name|Kind
argument_list|(
name|AK_Mangled
argument_list|)
operator|,
name|String
argument_list|(
argument|MN.getName()
argument_list|)
block|{}
name|Arg
argument_list|(
argument|UIntMax UInt
argument_list|)
operator|:
name|Kind
argument_list|(
name|AK_UInt
argument_list|)
operator|,
name|UInt
argument_list|(
argument|UInt
argument_list|)
block|{}
name|Arg
argument_list|(
argument|SIntMax SInt
argument_list|)
operator|:
name|Kind
argument_list|(
name|AK_SInt
argument_list|)
operator|,
name|SInt
argument_list|(
argument|SInt
argument_list|)
block|{}
name|Arg
argument_list|(
argument|FloatMax Float
argument_list|)
operator|:
name|Kind
argument_list|(
name|AK_Float
argument_list|)
operator|,
name|Float
argument_list|(
argument|Float
argument_list|)
block|{}
name|Arg
argument_list|(
specifier|const
name|void
operator|*
name|Pointer
argument_list|)
operator|:
name|Kind
argument_list|(
name|AK_Pointer
argument_list|)
operator|,
name|Pointer
argument_list|(
argument|Pointer
argument_list|)
block|{}
name|ArgKind
name|Kind
expr_stmt|;
union|union
block|{
specifier|const
name|char
modifier|*
name|String
decl_stmt|;
name|UIntMax
name|UInt
decl_stmt|;
name|SIntMax
name|SInt
decl_stmt|;
name|FloatMax
name|Float
decl_stmt|;
specifier|const
name|void
modifier|*
name|Pointer
decl_stmt|;
block|}
union|;
block|}
struct|;
name|private
label|:
specifier|static
specifier|const
name|unsigned
name|MaxArgs
init|=
literal|5
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|MaxRanges
init|=
literal|1
decl_stmt|;
comment|/// The arguments which have been added to this diagnostic so far.
name|Arg
name|Args
index|[
name|MaxArgs
index|]
decl_stmt|;
name|unsigned
name|NumArgs
decl_stmt|;
comment|/// The ranges which have been added to this diagnostic so far.
name|Range
name|Ranges
index|[
name|MaxRanges
index|]
decl_stmt|;
name|unsigned
name|NumRanges
decl_stmt|;
name|Diag
modifier|&
name|AddArg
parameter_list|(
name|Arg
name|A
parameter_list|)
block|{
name|CHECK
argument_list|(
name|NumArgs
operator|!=
name|MaxArgs
argument_list|)
expr_stmt|;
name|Args
index|[
name|NumArgs
operator|++
index|]
operator|=
name|A
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|Diag
modifier|&
name|AddRange
parameter_list|(
name|Range
name|A
parameter_list|)
block|{
name|CHECK
argument_list|(
name|NumRanges
operator|!=
name|MaxRanges
argument_list|)
expr_stmt|;
name|Ranges
index|[
name|NumRanges
operator|++
index|]
operator|=
name|A
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \c Diag objects are not copyable.
name|Diag
argument_list|(
specifier|const
name|Diag
operator|&
argument_list|)
expr_stmt|;
comment|// NOT IMPLEMENTED
name|Diag
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Diag
operator|&
operator|)
decl_stmt|;
name|public
label|:
name|Diag
argument_list|(
argument|Location Loc
argument_list|,
argument|DiagLevel Level
argument_list|,
argument|const char *Message
argument_list|)
block|:
name|Loc
argument_list|(
name|Loc
argument_list|)
operator|,
name|Level
argument_list|(
name|Level
argument_list|)
operator|,
name|Message
argument_list|(
name|Message
argument_list|)
operator|,
name|NumArgs
argument_list|(
literal|0
argument_list|)
operator|,
name|NumRanges
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|Diag
argument_list|()
expr_stmt|;
name|Diag
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|char
operator|*
name|Str
operator|)
block|{
return|return
name|AddArg
argument_list|(
name|Str
argument_list|)
return|;
block|}
name|Diag
operator|&
name|operator
operator|<<
operator|(
name|MangledName
name|MN
operator|)
block|{
return|return
name|AddArg
argument_list|(
name|MN
argument_list|)
return|;
block|}
name|Diag
operator|&
name|operator
operator|<<
operator|(
name|unsigned
name|long
name|long
name|V
operator|)
block|{
return|return
name|AddArg
argument_list|(
name|UIntMax
argument_list|(
name|V
argument_list|)
argument_list|)
return|;
block|}
name|Diag
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|void
operator|*
name|V
operator|)
block|{
return|return
name|AddArg
argument_list|(
name|V
argument_list|)
return|;
block|}
name|Diag
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|TypeDescriptor
operator|&
name|V
operator|)
expr_stmt|;
name|Diag
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|Value
operator|&
name|V
operator|)
expr_stmt|;
name|Diag
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|Range
operator|&
name|R
operator|)
block|{
return|return
name|AddRange
argument_list|(
name|R
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_struct
struct|struct
name|ReportOptions
block|{
comment|/// If DieAfterReport is specified, UBSan will terminate the program after the
comment|/// report is printed.
name|bool
name|DieAfterReport
decl_stmt|;
comment|/// pc/bp are used to unwind the stack trace.
name|uptr
name|pc
decl_stmt|;
name|uptr
name|bp
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|GET_REPORT_OPTIONS
parameter_list|(
name|die_after_report
parameter_list|)
define|\
value|GET_CALLER_PC_BP; \     ReportOptions Opts = {die_after_report, pc, bp}
end_define

begin_comment
comment|/// \brief Instantiate this class before printing diagnostics in the error
end_comment

begin_comment
comment|/// report. This class ensures that reports from different threads and from
end_comment

begin_comment
comment|/// different sanitizers won't be mixed.
end_comment

begin_decl_stmt
name|class
name|ScopedReport
block|{
name|ReportOptions
name|Opts
decl_stmt|;
name|Location
name|SummaryLoc
decl_stmt|;
name|public
label|:
name|ScopedReport
argument_list|(
argument|ReportOptions Opts
argument_list|,
argument|Location SummaryLoc
argument_list|)
empty_stmt|;
operator|~
name|ScopedReport
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|InitializeSuppressions
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|IsVptrCheckSuppressed
parameter_list|(
specifier|const
name|char
modifier|*
name|TypeName
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|}
comment|// namespace __ubsan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// UBSAN_DIAG_H
end_comment

end_unit

