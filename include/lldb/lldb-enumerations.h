begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lldb-enumerations.h -------------------------------------*- C++ -*-===//
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
name|LLDB_lldb_enumerations_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_lldb_enumerations_h_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SWIG
end_ifndef

begin_comment
comment|// With MSVC, the default type of an enum is always signed, even if one of the
end_comment

begin_comment
comment|// enumerator values is too large to fit into a signed integer but would
end_comment

begin_comment
comment|// otherwise fit into an unsigned integer.  As a result of this, all of LLDB's
end_comment

begin_comment
comment|// flag-style enumerations that specify something like eValueFoo = 1u<< 31
end_comment

begin_comment
comment|// result in negative values.  This usually just results in a benign warning,
end_comment

begin_comment
comment|// but in a few places we actually do comparisons on the enum values, which
end_comment

begin_comment
comment|// would cause a real bug.  Furthermore, there's no way to silence only this
end_comment

begin_comment
comment|// warning, as it's part of -Wmicrosoft which also catches a whole slew of
end_comment

begin_comment
comment|// other useful issues.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// To make matters worse, early versions of SWIG don't recognize the syntax
end_comment

begin_comment
comment|// of specifying the underlying type of an enum (and Python doesn't care anyway)
end_comment

begin_comment
comment|// so we need a way to specify the underlying type when the enum is being used
end_comment

begin_comment
comment|// from C++ code, but just use a regular enum when swig is pre-processing.
end_comment

begin_define
define|#
directive|define
name|FLAGS_ENUM
parameter_list|(
name|Name
parameter_list|)
value|enum Name : unsigned
end_define

begin_define
define|#
directive|define
name|FLAGS_ANONYMOUS_ENUM
parameter_list|()
value|enum : unsigned
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FLAGS_ENUM
parameter_list|(
name|Name
parameter_list|)
value|enum Name
end_define

begin_define
define|#
directive|define
name|FLAGS_ANONYMOUS_ENUM
parameter_list|()
value|enum
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|lldb
block|{
comment|//----------------------------------------------------------------------
comment|// Process and Thread States
comment|//----------------------------------------------------------------------
enum|enum
name|StateType
block|{
name|eStateInvalid
init|=
literal|0
block|,
name|eStateUnloaded
block|,
comment|///< Process is object is valid, but not currently loaded
name|eStateConnected
block|,
comment|///< Process is connected to remote debug services, but not
comment|///launched or attached to anything yet
name|eStateAttaching
block|,
comment|///< Process is currently trying to attach
name|eStateLaunching
block|,
comment|///< Process is in the process of launching
name|eStateStopped
block|,
comment|///< Process or thread is stopped and can be examined.
name|eStateRunning
block|,
comment|///< Process or thread is running and can't be examined.
name|eStateStepping
block|,
comment|///< Process or thread is in the process of stepping and can
comment|///not be examined.
name|eStateCrashed
block|,
comment|///< Process or thread has crashed and can be examined.
name|eStateDetached
block|,
comment|///< Process has been detached and can't be examined.
name|eStateExited
block|,
comment|///< Process has exited and can't be examined.
name|eStateSuspended
comment|///< Process or thread is in a suspended state as far
comment|///< as the debugger is concerned while other processes
comment|///< or threads get the chance to run.
block|}
enum|;
comment|//----------------------------------------------------------------------
comment|// Launch Flags
comment|//----------------------------------------------------------------------
name|FLAGS_ENUM
argument_list|(
argument|LaunchFlags
argument_list|)
block|{
name|eLaunchFlagNone
operator|=
literal|0u
operator|,
name|eLaunchFlagExec
operator|=
operator|(
literal|1u
operator|<<
literal|0
operator|)
operator|,
comment|///< Exec when launching and turn the calling
comment|///process into a new process
name|eLaunchFlagDebug
operator|=
operator|(
literal|1u
operator|<<
literal|1
operator|)
operator|,
comment|///< Stop as soon as the process launches to
comment|///allow the process to be debugged
name|eLaunchFlagStopAtEntry
operator|=
operator|(
literal|1u
operator|<<
literal|2
operator|)
operator|,
comment|///< Stop at the program entry point
comment|///instead of auto-continuing when
comment|///launching or attaching at entry point
name|eLaunchFlagDisableASLR
operator|=
operator|(
literal|1u
operator|<<
literal|3
operator|)
operator|,
comment|///< Disable Address Space Layout Randomization
name|eLaunchFlagDisableSTDIO
operator|=
operator|(
literal|1u
operator|<<
literal|4
operator|)
operator|,
comment|///< Disable stdio for inferior process (e.g. for a GUI app)
name|eLaunchFlagLaunchInTTY
operator|=
operator|(
literal|1u
operator|<<
literal|5
operator|)
operator|,
comment|///< Launch the process in a new TTY if supported by the host
name|eLaunchFlagLaunchInShell
operator|=
operator|(
literal|1u
operator|<<
literal|6
operator|)
operator|,
comment|///< Launch the process inside a shell to get shell expansion
name|eLaunchFlagLaunchInSeparateProcessGroup
operator|=
operator|(
literal|1u
operator|<<
literal|7
operator|)
operator|,
comment|///< Launch the process in a separate process group
name|eLaunchFlagDontSetExitStatus
operator|=
operator|(
literal|1u
operator|<<
literal|8
operator|)
operator|,
comment|///< If you are going to hand the
comment|///process off (e.g. to
comment|///debugserver)
comment|///< set this flag so lldb& the handee don't race to set its exit status.
name|eLaunchFlagDetachOnError
operator|=
operator|(
literal|1u
operator|<<
literal|9
operator|)
operator|,
comment|///< If set, then the client stub
comment|///should detach rather than killing
comment|///the debugee
comment|///< if it loses connection with lldb.
name|eLaunchFlagShellExpandArguments
operator|=
operator|(
literal|1u
operator|<<
literal|10
operator|)
operator|,
comment|///< Perform shell-style argument expansion
name|eLaunchFlagCloseTTYOnExit
operator|=
operator|(
literal|1u
operator|<<
literal|11
operator|)
operator|,
comment|///< Close the open TTY on exit
block|}
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|// Thread Run Modes
comment|//----------------------------------------------------------------------
enum|enum
name|RunMode
block|{
name|eOnlyThisThread
block|,
name|eAllThreads
block|,
name|eOnlyDuringStepping
block|}
enum|;
comment|//----------------------------------------------------------------------
comment|// Byte ordering definitions
comment|//----------------------------------------------------------------------
enum|enum
name|ByteOrder
block|{
name|eByteOrderInvalid
init|=
literal|0
block|,
name|eByteOrderBig
init|=
literal|1
block|,
name|eByteOrderPDP
init|=
literal|2
block|,
name|eByteOrderLittle
init|=
literal|4
block|}
enum|;
comment|//----------------------------------------------------------------------
comment|// Register encoding definitions
comment|//----------------------------------------------------------------------
enum|enum
name|Encoding
block|{
name|eEncodingInvalid
init|=
literal|0
block|,
name|eEncodingUint
block|,
comment|// unsigned integer
name|eEncodingSint
block|,
comment|// signed integer
name|eEncodingIEEE754
block|,
comment|// float
name|eEncodingVector
comment|// vector registers
block|}
enum|;
comment|//----------------------------------------------------------------------
comment|// Display format definitions
comment|//----------------------------------------------------------------------
enum|enum
name|Format
block|{
name|eFormatDefault
init|=
literal|0
block|,
name|eFormatInvalid
init|=
literal|0
block|,
name|eFormatBoolean
block|,
name|eFormatBinary
block|,
name|eFormatBytes
block|,
name|eFormatBytesWithASCII
block|,
name|eFormatChar
block|,
name|eFormatCharPrintable
block|,
comment|// Only printable characters, space if not printable
name|eFormatComplex
block|,
comment|// Floating point complex type
name|eFormatComplexFloat
init|=
name|eFormatComplex
block|,
name|eFormatCString
block|,
comment|// NULL terminated C strings
name|eFormatDecimal
block|,
name|eFormatEnum
block|,
name|eFormatHex
block|,
name|eFormatHexUppercase
block|,
name|eFormatFloat
block|,
name|eFormatOctal
block|,
name|eFormatOSType
block|,
comment|// OS character codes encoded into an integer 'PICT' 'text'
comment|// etc...
name|eFormatUnicode16
block|,
name|eFormatUnicode32
block|,
name|eFormatUnsigned
block|,
name|eFormatPointer
block|,
name|eFormatVectorOfChar
block|,
name|eFormatVectorOfSInt8
block|,
name|eFormatVectorOfUInt8
block|,
name|eFormatVectorOfSInt16
block|,
name|eFormatVectorOfUInt16
block|,
name|eFormatVectorOfSInt32
block|,
name|eFormatVectorOfUInt32
block|,
name|eFormatVectorOfSInt64
block|,
name|eFormatVectorOfUInt64
block|,
name|eFormatVectorOfFloat16
block|,
name|eFormatVectorOfFloat32
block|,
name|eFormatVectorOfFloat64
block|,
name|eFormatVectorOfUInt128
block|,
name|eFormatComplexInteger
block|,
comment|// Integer complex type
name|eFormatCharArray
block|,
comment|// Print characters with no single quotes, used for
comment|// character arrays that can contain non printable
comment|// characters
name|eFormatAddressInfo
block|,
comment|// Describe what an address points to (func + offset with
comment|// file/line, symbol + offset, data, etc)
name|eFormatHexFloat
block|,
comment|// ISO C99 hex float string
name|eFormatInstruction
block|,
comment|// Disassemble an opcode
name|eFormatVoid
block|,
comment|// Do not print this
name|kNumFormats
block|}
enum|;
comment|//----------------------------------------------------------------------
comment|// Description levels for "void GetDescription(Stream *, DescriptionLevel)"
comment|// calls
comment|//----------------------------------------------------------------------
enum|enum
name|DescriptionLevel
block|{
name|eDescriptionLevelBrief
init|=
literal|0
block|,
name|eDescriptionLevelFull
block|,
name|eDescriptionLevelVerbose
block|,
name|eDescriptionLevelInitial
block|,
name|kNumDescriptionLevels
block|}
enum|;
comment|//----------------------------------------------------------------------
comment|// Script interpreter types
comment|//----------------------------------------------------------------------
enum|enum
name|ScriptLanguage
block|{
name|eScriptLanguageNone
block|,
name|eScriptLanguagePython
block|,
name|eScriptLanguageDefault
init|=
name|eScriptLanguagePython
block|,
name|eScriptLanguageUnknown
block|}
enum|;
comment|//----------------------------------------------------------------------
comment|// Register numbering types
comment|// See RegisterContext::ConvertRegisterKindToRegisterNumber to convert
comment|// any of these to the lldb internal register numbering scheme
comment|// (eRegisterKindLLDB).
comment|//----------------------------------------------------------------------
enum|enum
name|RegisterKind
block|{
name|eRegisterKindEHFrame
init|=
literal|0
block|,
comment|// the register numbers seen in eh_frame
name|eRegisterKindDWARF
block|,
comment|// the register numbers seen DWARF
name|eRegisterKindGeneric
block|,
comment|// insn ptr reg, stack ptr reg, etc not specific to any
comment|// particular target
name|eRegisterKindProcessPlugin
block|,
comment|// num used by the process plugin - e.g. by the
comment|// remote gdb-protocol stub program
name|eRegisterKindLLDB
block|,
comment|// lldb's internal register numbers
name|kNumRegisterKinds
block|}
enum|;
comment|//----------------------------------------------------------------------
comment|// Thread stop reasons
comment|//----------------------------------------------------------------------
enum|enum
name|StopReason
block|{
name|eStopReasonInvalid
init|=
literal|0
block|,
name|eStopReasonNone
block|,
name|eStopReasonTrace
block|,
name|eStopReasonBreakpoint
block|,
name|eStopReasonWatchpoint
block|,
name|eStopReasonSignal
block|,
name|eStopReasonException
block|,
name|eStopReasonExec
block|,
comment|// Program was re-exec'ed
name|eStopReasonPlanComplete
block|,
name|eStopReasonThreadExiting
block|,
name|eStopReasonInstrumentation
block|}
enum|;
comment|//----------------------------------------------------------------------
comment|// Command Return Status Types
comment|//----------------------------------------------------------------------
enum|enum
name|ReturnStatus
block|{
name|eReturnStatusInvalid
block|,
name|eReturnStatusSuccessFinishNoResult
block|,
name|eReturnStatusSuccessFinishResult
block|,
name|eReturnStatusSuccessContinuingNoResult
block|,
name|eReturnStatusSuccessContinuingResult
block|,
name|eReturnStatusStarted
block|,
name|eReturnStatusFailed
block|,
name|eReturnStatusQuit
block|}
enum|;
comment|//----------------------------------------------------------------------
comment|// The results of expression evaluation:
comment|//----------------------------------------------------------------------
enum|enum
name|ExpressionResults
block|{
name|eExpressionCompleted
init|=
literal|0
block|,
name|eExpressionSetupError
block|,
name|eExpressionParseError
block|,
name|eExpressionDiscarded
block|,
name|eExpressionInterrupted
block|,
name|eExpressionHitBreakpoint
block|,
name|eExpressionTimedOut
block|,
name|eExpressionResultUnavailable
block|,
name|eExpressionStoppedForDebug
block|}
enum|;
comment|//----------------------------------------------------------------------
comment|// Connection Status Types
comment|//----------------------------------------------------------------------
enum|enum
name|ConnectionStatus
block|{
name|eConnectionStatusSuccess
block|,
comment|// Success
name|eConnectionStatusEndOfFile
block|,
comment|// End-of-file encountered
name|eConnectionStatusError
block|,
comment|// Check GetError() for details
name|eConnectionStatusTimedOut
block|,
comment|// Request timed out
name|eConnectionStatusNoConnection
block|,
comment|// No connection
name|eConnectionStatusLostConnection
block|,
comment|// Lost connection while connected to a valid
comment|// connection
name|eConnectionStatusInterrupted
comment|// Interrupted read
block|}
enum|;
enum|enum
name|ErrorType
block|{
name|eErrorTypeInvalid
block|,
name|eErrorTypeGeneric
block|,
comment|///< Generic errors that can be any value.
name|eErrorTypeMachKernel
block|,
comment|///< Mach kernel error codes.
name|eErrorTypePOSIX
block|,
comment|///< POSIX error codes.
name|eErrorTypeExpression
block|,
comment|///< These are from the ExpressionResults enum.
name|eErrorTypeWin32
comment|///< Standard Win32 error codes.
block|}
enum|;
enum|enum
name|ValueType
block|{
name|eValueTypeInvalid
init|=
literal|0
block|,
name|eValueTypeVariableGlobal
init|=
literal|1
block|,
comment|// globals variable
name|eValueTypeVariableStatic
init|=
literal|2
block|,
comment|// static variable
name|eValueTypeVariableArgument
init|=
literal|3
block|,
comment|// function argument variables
name|eValueTypeVariableLocal
init|=
literal|4
block|,
comment|// function local variables
name|eValueTypeRegister
init|=
literal|5
block|,
comment|// stack frame register value
name|eValueTypeRegisterSet
init|=
literal|6
block|,
comment|// A collection of stack frame register values
name|eValueTypeConstResult
init|=
literal|7
block|,
comment|// constant result variables
name|eValueTypeVariableThreadLocal
init|=
literal|8
comment|// thread local storage variable
block|}
enum|;
comment|//----------------------------------------------------------------------
comment|// Token size/granularities for Input Readers
comment|//----------------------------------------------------------------------
enum|enum
name|InputReaderGranularity
block|{
name|eInputReaderGranularityInvalid
init|=
literal|0
block|,
name|eInputReaderGranularityByte
block|,
name|eInputReaderGranularityWord
block|,
name|eInputReaderGranularityLine
block|,
name|eInputReaderGranularityAll
block|}
enum|;
comment|//------------------------------------------------------------------
comment|/// These mask bits allow a common interface for queries that can
comment|/// limit the amount of information that gets parsed to only the
comment|/// information that is requested. These bits also can indicate what
comment|/// actually did get resolved during query function calls.
comment|///
comment|/// Each definition corresponds to a one of the member variables
comment|/// in this class, and requests that that item be resolved, or
comment|/// indicates that the member did get resolved.
comment|//------------------------------------------------------------------
name|FLAGS_ENUM
argument_list|(
argument|SymbolContextItem
argument_list|)
block|{
name|eSymbolContextTarget
operator|=
operator|(
literal|1u
operator|<<
literal|0
operator|)
operator|,
comment|///< Set when \a target is requested from
comment|///a query, or was located in query
comment|///results
name|eSymbolContextModule
operator|=
operator|(
literal|1u
operator|<<
literal|1
operator|)
operator|,
comment|///< Set when \a module is requested from
comment|///a query, or was located in query
comment|///results
name|eSymbolContextCompUnit
operator|=
operator|(
literal|1u
operator|<<
literal|2
operator|)
operator|,
comment|///< Set when \a comp_unit is requested
comment|///from a query, or was located in query
comment|///results
name|eSymbolContextFunction
operator|=
operator|(
literal|1u
operator|<<
literal|3
operator|)
operator|,
comment|///< Set when \a function is requested
comment|///from a query, or was located in query
comment|///results
name|eSymbolContextBlock
operator|=
operator|(
literal|1u
operator|<<
literal|4
operator|)
operator|,
comment|///< Set when the deepest \a block is
comment|///requested from a query, or was located
comment|///in query results
name|eSymbolContextLineEntry
operator|=
operator|(
literal|1u
operator|<<
literal|5
operator|)
operator|,
comment|///< Set when \a line_entry is
comment|///requested from a query, or was
comment|///located in query results
name|eSymbolContextSymbol
operator|=
operator|(
literal|1u
operator|<<
literal|6
operator|)
operator|,
comment|///< Set when \a symbol is requested from
comment|///a query, or was located in query
comment|///results
name|eSymbolContextEverything
operator|=
operator|(
operator|(
name|eSymbolContextSymbol
operator|<<
literal|1
operator|)
operator|-
literal|1u
operator|)
operator|,
comment|///< Indicates to try and lookup everything
comment|///up during a routine symbol context
comment|///query.
name|eSymbolContextVariable
operator|=
operator|(
literal|1u
operator|<<
literal|7
operator|)
comment|///< Set when \a global or static
comment|///variable is requested from a query, or
comment|///was located in query results.
comment|///< eSymbolContextVariable is potentially expensive to lookup so it isn't
comment|///included in
comment|///< eSymbolContextEverything which stops it from being used during frame PC
comment|///lookups and
comment|///< many other potential address to symbol context lookups.
block|}
empty_stmt|;
name|FLAGS_ENUM
argument_list|(
argument|Permissions
argument_list|)
block|{
name|ePermissionsWritable
operator|=
operator|(
literal|1u
operator|<<
literal|0
operator|)
operator|,
name|ePermissionsReadable
operator|=
operator|(
literal|1u
operator|<<
literal|1
operator|)
operator|,
name|ePermissionsExecutable
operator|=
operator|(
literal|1u
operator|<<
literal|2
operator|)
block|}
empty_stmt|;
enum|enum
name|InputReaderAction
block|{
name|eInputReaderActivate
block|,
comment|// reader is newly pushed onto the reader stack
name|eInputReaderAsynchronousOutputWritten
block|,
comment|// an async output event occurred; the
comment|// reader may want to do something
name|eInputReaderReactivate
block|,
comment|// reader is on top of the stack again after another
comment|// reader was popped off
name|eInputReaderDeactivate
block|,
comment|// another reader was pushed on the stack
name|eInputReaderGotToken
block|,
comment|// reader got one of its tokens (granularity)
name|eInputReaderInterrupt
block|,
comment|// reader received an interrupt signal (probably from a
comment|// control-c)
name|eInputReaderEndOfFile
block|,
comment|// reader received an EOF char (probably from a
comment|// control-d)
name|eInputReaderDone
comment|// reader was just popped off the stack and is done
block|}
enum|;
name|FLAGS_ENUM
argument_list|(
argument|BreakpointEventType
argument_list|)
block|{
name|eBreakpointEventTypeInvalidType
operator|=
operator|(
literal|1u
operator|<<
literal|0
operator|)
operator|,
name|eBreakpointEventTypeAdded
operator|=
operator|(
literal|1u
operator|<<
literal|1
operator|)
operator|,
name|eBreakpointEventTypeRemoved
operator|=
operator|(
literal|1u
operator|<<
literal|2
operator|)
operator|,
name|eBreakpointEventTypeLocationsAdded
operator|=
operator|(
literal|1u
operator|<<
literal|3
operator|)
operator|,
comment|// Locations added doesn't
comment|// get sent when the
comment|// breakpoint is created
name|eBreakpointEventTypeLocationsRemoved
operator|=
operator|(
literal|1u
operator|<<
literal|4
operator|)
operator|,
name|eBreakpointEventTypeLocationsResolved
operator|=
operator|(
literal|1u
operator|<<
literal|5
operator|)
operator|,
name|eBreakpointEventTypeEnabled
operator|=
operator|(
literal|1u
operator|<<
literal|6
operator|)
operator|,
name|eBreakpointEventTypeDisabled
operator|=
operator|(
literal|1u
operator|<<
literal|7
operator|)
operator|,
name|eBreakpointEventTypeCommandChanged
operator|=
operator|(
literal|1u
operator|<<
literal|8
operator|)
operator|,
name|eBreakpointEventTypeConditionChanged
operator|=
operator|(
literal|1u
operator|<<
literal|9
operator|)
operator|,
name|eBreakpointEventTypeIgnoreChanged
operator|=
operator|(
literal|1u
operator|<<
literal|10
operator|)
operator|,
name|eBreakpointEventTypeThreadChanged
operator|=
operator|(
literal|1u
operator|<<
literal|11
operator|)
block|}
empty_stmt|;
name|FLAGS_ENUM
argument_list|(
argument|WatchpointEventType
argument_list|)
block|{
name|eWatchpointEventTypeInvalidType
operator|=
operator|(
literal|1u
operator|<<
literal|0
operator|)
operator|,
name|eWatchpointEventTypeAdded
operator|=
operator|(
literal|1u
operator|<<
literal|1
operator|)
operator|,
name|eWatchpointEventTypeRemoved
operator|=
operator|(
literal|1u
operator|<<
literal|2
operator|)
operator|,
name|eWatchpointEventTypeEnabled
operator|=
operator|(
literal|1u
operator|<<
literal|6
operator|)
operator|,
name|eWatchpointEventTypeDisabled
operator|=
operator|(
literal|1u
operator|<<
literal|7
operator|)
operator|,
name|eWatchpointEventTypeCommandChanged
operator|=
operator|(
literal|1u
operator|<<
literal|8
operator|)
operator|,
name|eWatchpointEventTypeConditionChanged
operator|=
operator|(
literal|1u
operator|<<
literal|9
operator|)
operator|,
name|eWatchpointEventTypeIgnoreChanged
operator|=
operator|(
literal|1u
operator|<<
literal|10
operator|)
operator|,
name|eWatchpointEventTypeThreadChanged
operator|=
operator|(
literal|1u
operator|<<
literal|11
operator|)
operator|,
name|eWatchpointEventTypeTypeChanged
operator|=
operator|(
literal|1u
operator|<<
literal|12
operator|)
block|}
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|/// Programming language type.
comment|///
comment|/// These enumerations use the same language enumerations as the DWARF
comment|/// specification for ease of use and consistency.
comment|/// The enum -> string code is in Language.cpp, don't change this
comment|/// table without updating that code as well.
comment|//----------------------------------------------------------------------
enum|enum
name|LanguageType
block|{
name|eLanguageTypeUnknown
init|=
literal|0x0000
block|,
comment|///< Unknown or invalid language value.
name|eLanguageTypeC89
init|=
literal|0x0001
block|,
comment|///< ISO C:1989.
name|eLanguageTypeC
init|=
literal|0x0002
block|,
comment|///< Non-standardized C, such as K&R.
name|eLanguageTypeAda83
init|=
literal|0x0003
block|,
comment|///< ISO Ada:1983.
name|eLanguageTypeC_plus_plus
init|=
literal|0x0004
block|,
comment|///< ISO C++:1998.
name|eLanguageTypeCobol74
init|=
literal|0x0005
block|,
comment|///< ISO Cobol:1974.
name|eLanguageTypeCobol85
init|=
literal|0x0006
block|,
comment|///< ISO Cobol:1985.
name|eLanguageTypeFortran77
init|=
literal|0x0007
block|,
comment|///< ISO Fortran 77.
name|eLanguageTypeFortran90
init|=
literal|0x0008
block|,
comment|///< ISO Fortran 90.
name|eLanguageTypePascal83
init|=
literal|0x0009
block|,
comment|///< ISO Pascal:1983.
name|eLanguageTypeModula2
init|=
literal|0x000a
block|,
comment|///< ISO Modula-2:1996.
name|eLanguageTypeJava
init|=
literal|0x000b
block|,
comment|///< Java.
name|eLanguageTypeC99
init|=
literal|0x000c
block|,
comment|///< ISO C:1999.
name|eLanguageTypeAda95
init|=
literal|0x000d
block|,
comment|///< ISO Ada:1995.
name|eLanguageTypeFortran95
init|=
literal|0x000e
block|,
comment|///< ISO Fortran 95.
name|eLanguageTypePLI
init|=
literal|0x000f
block|,
comment|///< ANSI PL/I:1976.
name|eLanguageTypeObjC
init|=
literal|0x0010
block|,
comment|///< Objective-C.
name|eLanguageTypeObjC_plus_plus
init|=
literal|0x0011
block|,
comment|///< Objective-C++.
name|eLanguageTypeUPC
init|=
literal|0x0012
block|,
comment|///< Unified Parallel C.
name|eLanguageTypeD
init|=
literal|0x0013
block|,
comment|///< D.
name|eLanguageTypePython
init|=
literal|0x0014
block|,
comment|///< Python.
comment|// NOTE: The below are DWARF5 constants, subject to change upon
comment|// completion of the DWARF5 specification
name|eLanguageTypeOpenCL
init|=
literal|0x0015
block|,
comment|///< OpenCL.
name|eLanguageTypeGo
init|=
literal|0x0016
block|,
comment|///< Go.
name|eLanguageTypeModula3
init|=
literal|0x0017
block|,
comment|///< Modula 3.
name|eLanguageTypeHaskell
init|=
literal|0x0018
block|,
comment|///< Haskell.
name|eLanguageTypeC_plus_plus_03
init|=
literal|0x0019
block|,
comment|///< ISO C++:2003.
name|eLanguageTypeC_plus_plus_11
init|=
literal|0x001a
block|,
comment|///< ISO C++:2011.
name|eLanguageTypeOCaml
init|=
literal|0x001b
block|,
comment|///< OCaml.
name|eLanguageTypeRust
init|=
literal|0x001c
block|,
comment|///< Rust.
name|eLanguageTypeC11
init|=
literal|0x001d
block|,
comment|///< ISO C:2011.
name|eLanguageTypeSwift
init|=
literal|0x001e
block|,
comment|///< Swift.
name|eLanguageTypeJulia
init|=
literal|0x001f
block|,
comment|///< Julia.
name|eLanguageTypeDylan
init|=
literal|0x0020
block|,
comment|///< Dylan.
name|eLanguageTypeC_plus_plus_14
init|=
literal|0x0021
block|,
comment|///< ISO C++:2014.
name|eLanguageTypeFortran03
init|=
literal|0x0022
block|,
comment|///< ISO Fortran 2003.
name|eLanguageTypeFortran08
init|=
literal|0x0023
block|,
comment|///< ISO Fortran 2008.
comment|// Vendor Extensions
comment|// Note: Language::GetNameForLanguageType
comment|// assumes these can be used as indexes into array language_names, and
comment|// Language::SetLanguageFromCString and Language::AsCString
comment|// assume these can be used as indexes into array g_languages.
name|eLanguageTypeMipsAssembler
init|=
literal|0x0024
block|,
comment|///< Mips_Assembler.
name|eLanguageTypeExtRenderScript
init|=
literal|0x0025
block|,
comment|///< RenderScript.
name|eNumLanguageTypes
block|}
enum|;
enum|enum
name|InstrumentationRuntimeType
block|{
name|eInstrumentationRuntimeTypeAddressSanitizer
init|=
literal|0x0000
block|,
name|eInstrumentationRuntimeTypeThreadSanitizer
init|=
literal|0x0001
block|,
name|eNumInstrumentationRuntimeTypes
block|}
enum|;
enum|enum
name|DynamicValueType
block|{
name|eNoDynamicValues
init|=
literal|0
block|,
name|eDynamicCanRunTarget
init|=
literal|1
block|,
name|eDynamicDontRunTarget
init|=
literal|2
block|}
enum|;
enum|enum
name|StopShowColumn
block|{
name|eStopShowColumnAnsiOrCaret
init|=
literal|0
block|,
name|eStopShowColumnAnsi
init|=
literal|1
block|,
name|eStopShowColumnCaret
init|=
literal|2
block|,
name|eStopShowColumnNone
init|=
literal|3
block|}
enum|;
enum|enum
name|AccessType
block|{
name|eAccessNone
block|,
name|eAccessPublic
block|,
name|eAccessPrivate
block|,
name|eAccessProtected
block|,
name|eAccessPackage
block|}
enum|;
enum|enum
name|CommandArgumentType
block|{
name|eArgTypeAddress
init|=
literal|0
block|,
name|eArgTypeAddressOrExpression
block|,
name|eArgTypeAliasName
block|,
name|eArgTypeAliasOptions
block|,
name|eArgTypeArchitecture
block|,
name|eArgTypeBoolean
block|,
name|eArgTypeBreakpointID
block|,
name|eArgTypeBreakpointIDRange
block|,
name|eArgTypeBreakpointName
block|,
name|eArgTypeByteSize
block|,
name|eArgTypeClassName
block|,
name|eArgTypeCommandName
block|,
name|eArgTypeCount
block|,
name|eArgTypeDescriptionVerbosity
block|,
name|eArgTypeDirectoryName
block|,
name|eArgTypeDisassemblyFlavor
block|,
name|eArgTypeEndAddress
block|,
name|eArgTypeExpression
block|,
name|eArgTypeExpressionPath
block|,
name|eArgTypeExprFormat
block|,
name|eArgTypeFilename
block|,
name|eArgTypeFormat
block|,
name|eArgTypeFrameIndex
block|,
name|eArgTypeFullName
block|,
name|eArgTypeFunctionName
block|,
name|eArgTypeFunctionOrSymbol
block|,
name|eArgTypeGDBFormat
block|,
name|eArgTypeHelpText
block|,
name|eArgTypeIndex
block|,
name|eArgTypeLanguage
block|,
name|eArgTypeLineNum
block|,
name|eArgTypeLogCategory
block|,
name|eArgTypeLogChannel
block|,
name|eArgTypeMethod
block|,
name|eArgTypeName
block|,
name|eArgTypeNewPathPrefix
block|,
name|eArgTypeNumLines
block|,
name|eArgTypeNumberPerLine
block|,
name|eArgTypeOffset
block|,
name|eArgTypeOldPathPrefix
block|,
name|eArgTypeOneLiner
block|,
name|eArgTypePath
block|,
name|eArgTypePermissionsNumber
block|,
name|eArgTypePermissionsString
block|,
name|eArgTypePid
block|,
name|eArgTypePlugin
block|,
name|eArgTypeProcessName
block|,
name|eArgTypePythonClass
block|,
name|eArgTypePythonFunction
block|,
name|eArgTypePythonScript
block|,
name|eArgTypeQueueName
block|,
name|eArgTypeRegisterName
block|,
name|eArgTypeRegularExpression
block|,
name|eArgTypeRunArgs
block|,
name|eArgTypeRunMode
block|,
name|eArgTypeScriptedCommandSynchronicity
block|,
name|eArgTypeScriptLang
block|,
name|eArgTypeSearchWord
block|,
name|eArgTypeSelector
block|,
name|eArgTypeSettingIndex
block|,
name|eArgTypeSettingKey
block|,
name|eArgTypeSettingPrefix
block|,
name|eArgTypeSettingVariableName
block|,
name|eArgTypeShlibName
block|,
name|eArgTypeSourceFile
block|,
name|eArgTypeSortOrder
block|,
name|eArgTypeStartAddress
block|,
name|eArgTypeSummaryString
block|,
name|eArgTypeSymbol
block|,
name|eArgTypeThreadID
block|,
name|eArgTypeThreadIndex
block|,
name|eArgTypeThreadName
block|,
name|eArgTypeTypeName
block|,
name|eArgTypeUnsignedInteger
block|,
name|eArgTypeUnixSignal
block|,
name|eArgTypeVarName
block|,
name|eArgTypeValue
block|,
name|eArgTypeWidth
block|,
name|eArgTypeNone
block|,
name|eArgTypePlatform
block|,
name|eArgTypeWatchpointID
block|,
name|eArgTypeWatchpointIDRange
block|,
name|eArgTypeWatchType
block|,
name|eArgRawInput
block|,
name|eArgTypeLastArg
comment|// Always keep this entry as the last entry in this
comment|// enumeration!!
block|}
enum|;
comment|//----------------------------------------------------------------------
comment|// Symbol types
comment|//----------------------------------------------------------------------
enum|enum
name|SymbolType
block|{
name|eSymbolTypeAny
init|=
literal|0
block|,
name|eSymbolTypeInvalid
init|=
literal|0
block|,
name|eSymbolTypeAbsolute
block|,
name|eSymbolTypeCode
block|,
name|eSymbolTypeResolver
block|,
name|eSymbolTypeData
block|,
name|eSymbolTypeTrampoline
block|,
name|eSymbolTypeRuntime
block|,
name|eSymbolTypeException
block|,
name|eSymbolTypeSourceFile
block|,
name|eSymbolTypeHeaderFile
block|,
name|eSymbolTypeObjectFile
block|,
name|eSymbolTypeCommonBlock
block|,
name|eSymbolTypeBlock
block|,
name|eSymbolTypeLocal
block|,
name|eSymbolTypeParam
block|,
name|eSymbolTypeVariable
block|,
name|eSymbolTypeVariableType
block|,
name|eSymbolTypeLineEntry
block|,
name|eSymbolTypeLineHeader
block|,
name|eSymbolTypeScopeBegin
block|,
name|eSymbolTypeScopeEnd
block|,
name|eSymbolTypeAdditional
block|,
comment|// When symbols take more than one entry, the extra
comment|// entries get this type
name|eSymbolTypeCompiler
block|,
name|eSymbolTypeInstrumentation
block|,
name|eSymbolTypeUndefined
block|,
name|eSymbolTypeObjCClass
block|,
name|eSymbolTypeObjCMetaClass
block|,
name|eSymbolTypeObjCIVar
block|,
name|eSymbolTypeReExported
block|}
enum|;
enum|enum
name|SectionType
block|{
name|eSectionTypeInvalid
block|,
name|eSectionTypeCode
block|,
name|eSectionTypeContainer
block|,
comment|// The section contains child sections
name|eSectionTypeData
block|,
name|eSectionTypeDataCString
block|,
comment|// Inlined C string data
name|eSectionTypeDataCStringPointers
block|,
comment|// Pointers to C string data
name|eSectionTypeDataSymbolAddress
block|,
comment|// Address of a symbol in the symbol table
name|eSectionTypeData4
block|,
name|eSectionTypeData8
block|,
name|eSectionTypeData16
block|,
name|eSectionTypeDataPointers
block|,
name|eSectionTypeDebug
block|,
name|eSectionTypeZeroFill
block|,
name|eSectionTypeDataObjCMessageRefs
block|,
comment|// Pointer to function pointer + selector
name|eSectionTypeDataObjCCFStrings
block|,
comment|// Objective C const CFString/NSString objects
name|eSectionTypeDWARFDebugAbbrev
block|,
name|eSectionTypeDWARFDebugAddr
block|,
name|eSectionTypeDWARFDebugAranges
block|,
name|eSectionTypeDWARFDebugFrame
block|,
name|eSectionTypeDWARFDebugInfo
block|,
name|eSectionTypeDWARFDebugLine
block|,
name|eSectionTypeDWARFDebugLoc
block|,
name|eSectionTypeDWARFDebugMacInfo
block|,
name|eSectionTypeDWARFDebugMacro
block|,
name|eSectionTypeDWARFDebugPubNames
block|,
name|eSectionTypeDWARFDebugPubTypes
block|,
name|eSectionTypeDWARFDebugRanges
block|,
name|eSectionTypeDWARFDebugStr
block|,
name|eSectionTypeDWARFDebugStrOffsets
block|,
name|eSectionTypeDWARFAppleNames
block|,
name|eSectionTypeDWARFAppleTypes
block|,
name|eSectionTypeDWARFAppleNamespaces
block|,
name|eSectionTypeDWARFAppleObjC
block|,
name|eSectionTypeELFSymbolTable
block|,
comment|// Elf SHT_SYMTAB section
name|eSectionTypeELFDynamicSymbols
block|,
comment|// Elf SHT_DYNSYM section
name|eSectionTypeELFRelocationEntries
block|,
comment|// Elf SHT_REL or SHT_REL section
name|eSectionTypeELFDynamicLinkInfo
block|,
comment|// Elf SHT_DYNAMIC section
name|eSectionTypeEHFrame
block|,
name|eSectionTypeARMexidx
block|,
name|eSectionTypeARMextab
block|,
name|eSectionTypeCompactUnwind
block|,
comment|// compact unwind section in Mach-O,
comment|// __TEXT,__unwind_info
name|eSectionTypeGoSymtab
block|,
name|eSectionTypeAbsoluteAddress
block|,
comment|// Dummy section for symbols with absolute
comment|// address
name|eSectionTypeOther
block|}
enum|;
name|FLAGS_ENUM
argument_list|(
argument|EmulateInstructionOptions
argument_list|)
block|{
name|eEmulateInstructionOptionNone
operator|=
operator|(
literal|0u
operator|)
operator|,
name|eEmulateInstructionOptionAutoAdvancePC
operator|=
operator|(
literal|1u
operator|<<
literal|0
operator|)
operator|,
name|eEmulateInstructionOptionIgnoreConditions
operator|=
operator|(
literal|1u
operator|<<
literal|1
operator|)
block|}
empty_stmt|;
name|FLAGS_ENUM
argument_list|(
argument|FunctionNameType
argument_list|)
block|{
name|eFunctionNameTypeNone
operator|=
literal|0u
operator|,
name|eFunctionNameTypeAuto
operator|=
operator|(
literal|1u
operator|<<
literal|1
operator|)
operator|,
comment|// Automatically figure out which FunctionNameType
comment|// bits to set based on the function name.
name|eFunctionNameTypeFull
operator|=
operator|(
literal|1u
operator|<<
literal|2
operator|)
operator|,
comment|// The function name.
comment|// For C this is the same as just the name of the function
comment|// For C++ this is the mangled or demangled version of the mangled name.
comment|// For ObjC this is the full function signature with the + or
comment|// - and the square brackets and the class and selector
name|eFunctionNameTypeBase
operator|=
operator|(
literal|1u
operator|<<
literal|3
operator|)
operator|,
comment|// The function name only, no namespaces
comment|// or arguments and no class
comment|// methods or selectors will be searched.
name|eFunctionNameTypeMethod
operator|=
operator|(
literal|1u
operator|<<
literal|4
operator|)
operator|,
comment|// Find function by method name (C++)
comment|// with no namespace or arguments
name|eFunctionNameTypeSelector
operator|=
operator|(
literal|1u
operator|<<
literal|5
operator|)
operator|,
comment|// Find function by selector name (ObjC) names
name|eFunctionNameTypeAny
operator|=
name|eFunctionNameTypeAuto
comment|// DEPRECATED: use eFunctionNameTypeAuto
block|}
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|// Basic types enumeration for the public API SBType::GetBasicType()
comment|//----------------------------------------------------------------------
enum|enum
name|BasicType
block|{
name|eBasicTypeInvalid
init|=
literal|0
block|,
name|eBasicTypeVoid
init|=
literal|1
block|,
name|eBasicTypeChar
block|,
name|eBasicTypeSignedChar
block|,
name|eBasicTypeUnsignedChar
block|,
name|eBasicTypeWChar
block|,
name|eBasicTypeSignedWChar
block|,
name|eBasicTypeUnsignedWChar
block|,
name|eBasicTypeChar16
block|,
name|eBasicTypeChar32
block|,
name|eBasicTypeShort
block|,
name|eBasicTypeUnsignedShort
block|,
name|eBasicTypeInt
block|,
name|eBasicTypeUnsignedInt
block|,
name|eBasicTypeLong
block|,
name|eBasicTypeUnsignedLong
block|,
name|eBasicTypeLongLong
block|,
name|eBasicTypeUnsignedLongLong
block|,
name|eBasicTypeInt128
block|,
name|eBasicTypeUnsignedInt128
block|,
name|eBasicTypeBool
block|,
name|eBasicTypeHalf
block|,
name|eBasicTypeFloat
block|,
name|eBasicTypeDouble
block|,
name|eBasicTypeLongDouble
block|,
name|eBasicTypeFloatComplex
block|,
name|eBasicTypeDoubleComplex
block|,
name|eBasicTypeLongDoubleComplex
block|,
name|eBasicTypeObjCID
block|,
name|eBasicTypeObjCClass
block|,
name|eBasicTypeObjCSel
block|,
name|eBasicTypeNullPtr
block|,
name|eBasicTypeOther
block|}
enum|;
enum|enum
name|TraceType
block|{
name|eTraceTypeNone
init|=
literal|0
block|,
comment|// Hardware Trace generated by the processor.
name|eTraceTypeProcessorTrace
block|}
enum|;
name|FLAGS_ENUM
argument_list|(
argument|TypeClass
argument_list|)
block|{
name|eTypeClassInvalid
operator|=
operator|(
literal|0u
operator|)
operator|,
name|eTypeClassArray
operator|=
operator|(
literal|1u
operator|<<
literal|0
operator|)
operator|,
name|eTypeClassBlockPointer
operator|=
operator|(
literal|1u
operator|<<
literal|1
operator|)
operator|,
name|eTypeClassBuiltin
operator|=
operator|(
literal|1u
operator|<<
literal|2
operator|)
operator|,
name|eTypeClassClass
operator|=
operator|(
literal|1u
operator|<<
literal|3
operator|)
operator|,
name|eTypeClassComplexFloat
operator|=
operator|(
literal|1u
operator|<<
literal|4
operator|)
operator|,
name|eTypeClassComplexInteger
operator|=
operator|(
literal|1u
operator|<<
literal|5
operator|)
operator|,
name|eTypeClassEnumeration
operator|=
operator|(
literal|1u
operator|<<
literal|6
operator|)
operator|,
name|eTypeClassFunction
operator|=
operator|(
literal|1u
operator|<<
literal|7
operator|)
operator|,
name|eTypeClassMemberPointer
operator|=
operator|(
literal|1u
operator|<<
literal|8
operator|)
operator|,
name|eTypeClassObjCObject
operator|=
operator|(
literal|1u
operator|<<
literal|9
operator|)
operator|,
name|eTypeClassObjCInterface
operator|=
operator|(
literal|1u
operator|<<
literal|10
operator|)
operator|,
name|eTypeClassObjCObjectPointer
operator|=
operator|(
literal|1u
operator|<<
literal|11
operator|)
operator|,
name|eTypeClassPointer
operator|=
operator|(
literal|1u
operator|<<
literal|12
operator|)
operator|,
name|eTypeClassReference
operator|=
operator|(
literal|1u
operator|<<
literal|13
operator|)
operator|,
name|eTypeClassStruct
operator|=
operator|(
literal|1u
operator|<<
literal|14
operator|)
operator|,
name|eTypeClassTypedef
operator|=
operator|(
literal|1u
operator|<<
literal|15
operator|)
operator|,
name|eTypeClassUnion
operator|=
operator|(
literal|1u
operator|<<
literal|16
operator|)
operator|,
name|eTypeClassVector
operator|=
operator|(
literal|1u
operator|<<
literal|17
operator|)
operator|,
comment|// Define the last type class as the MSBit of a 32 bit value
name|eTypeClassOther
operator|=
operator|(
literal|1u
operator|<<
literal|31
operator|)
operator|,
comment|// Define a mask that can be used for any type when finding types
name|eTypeClassAny
operator|=
operator|(
literal|0xffffffffu
operator|)
block|}
empty_stmt|;
enum|enum
name|TemplateArgumentKind
block|{
name|eTemplateArgumentKindNull
init|=
literal|0
block|,
name|eTemplateArgumentKindType
block|,
name|eTemplateArgumentKindDeclaration
block|,
name|eTemplateArgumentKindIntegral
block|,
name|eTemplateArgumentKindTemplate
block|,
name|eTemplateArgumentKindTemplateExpansion
block|,
name|eTemplateArgumentKindExpression
block|,
name|eTemplateArgumentKindPack
block|}
enum|;
comment|//----------------------------------------------------------------------
comment|// Options that can be set for a formatter to alter its behavior
comment|// Not all of these are applicable to all formatter types
comment|//----------------------------------------------------------------------
name|FLAGS_ENUM
argument_list|(
argument|TypeOptions
argument_list|)
block|{
name|eTypeOptionNone
operator|=
operator|(
literal|0u
operator|)
operator|,
name|eTypeOptionCascade
operator|=
operator|(
literal|1u
operator|<<
literal|0
operator|)
operator|,
name|eTypeOptionSkipPointers
operator|=
operator|(
literal|1u
operator|<<
literal|1
operator|)
operator|,
name|eTypeOptionSkipReferences
operator|=
operator|(
literal|1u
operator|<<
literal|2
operator|)
operator|,
name|eTypeOptionHideChildren
operator|=
operator|(
literal|1u
operator|<<
literal|3
operator|)
operator|,
name|eTypeOptionHideValue
operator|=
operator|(
literal|1u
operator|<<
literal|4
operator|)
operator|,
name|eTypeOptionShowOneLiner
operator|=
operator|(
literal|1u
operator|<<
literal|5
operator|)
operator|,
name|eTypeOptionHideNames
operator|=
operator|(
literal|1u
operator|<<
literal|6
operator|)
operator|,
name|eTypeOptionNonCacheable
operator|=
operator|(
literal|1u
operator|<<
literal|7
operator|)
operator|,
name|eTypeOptionHideEmptyAggregates
operator|=
operator|(
literal|1u
operator|<<
literal|8
operator|)
block|}
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|// This is the return value for frame comparisons.  If you are comparing frame A
comment|// to frame B
comment|// the following cases arise:
comment|// 1) When frame A pushes frame B (or a frame that ends up pushing B) A is Older
comment|// than B.
comment|// 2) When frame A pushed frame B (or if frame A is on the stack but B is not) A
comment|// is Younger than B
comment|// 3) When frame A and frame B have the same StackID, they are Equal.
comment|// 4) When frame A and frame B have the same immediate parent frame, but are not
comment|// equal, the comparison yields
comment|//    SameParent.
comment|// 5) If the two frames are on different threads or processes the comparison is
comment|// Invalid
comment|// 6) If for some reason we can't figure out what went on, we return Unknown.
comment|//----------------------------------------------------------------------
enum|enum
name|FrameComparison
block|{
name|eFrameCompareInvalid
block|,
name|eFrameCompareUnknown
block|,
name|eFrameCompareEqual
block|,
name|eFrameCompareSameParent
block|,
name|eFrameCompareYounger
block|,
name|eFrameCompareOlder
block|}
enum|;
comment|//----------------------------------------------------------------------
comment|// Address Class
comment|//
comment|// A way of classifying an address used for disassembling and setting
comment|// breakpoints. Many object files can track exactly what parts of their
comment|// object files are code, data and other information. This is of course
comment|// above and beyond just looking at the section types. For example, code
comment|// might contain PC relative data and the object file might be able to
comment|// tell us that an address in code is data.
comment|//----------------------------------------------------------------------
enum|enum
name|AddressClass
block|{
name|eAddressClassInvalid
block|,
name|eAddressClassUnknown
block|,
name|eAddressClassCode
block|,
name|eAddressClassCodeAlternateISA
block|,
name|eAddressClassData
block|,
name|eAddressClassDebug
block|,
name|eAddressClassRuntime
block|}
enum|;
comment|//----------------------------------------------------------------------
comment|// File Permissions
comment|//
comment|// Designed to mimic the unix file permission bits so they can be
comment|// used with functions that set 'mode_t' to certain values for
comment|// permissions.
comment|//----------------------------------------------------------------------
name|FLAGS_ENUM
argument_list|(
argument|FilePermissions
argument_list|)
block|{
name|eFilePermissionsUserRead
operator|=
operator|(
literal|1u
operator|<<
literal|8
operator|)
operator|,
name|eFilePermissionsUserWrite
operator|=
operator|(
literal|1u
operator|<<
literal|7
operator|)
operator|,
name|eFilePermissionsUserExecute
operator|=
operator|(
literal|1u
operator|<<
literal|6
operator|)
operator|,
name|eFilePermissionsGroupRead
operator|=
operator|(
literal|1u
operator|<<
literal|5
operator|)
operator|,
name|eFilePermissionsGroupWrite
operator|=
operator|(
literal|1u
operator|<<
literal|4
operator|)
operator|,
name|eFilePermissionsGroupExecute
operator|=
operator|(
literal|1u
operator|<<
literal|3
operator|)
operator|,
name|eFilePermissionsWorldRead
operator|=
operator|(
literal|1u
operator|<<
literal|2
operator|)
operator|,
name|eFilePermissionsWorldWrite
operator|=
operator|(
literal|1u
operator|<<
literal|1
operator|)
operator|,
name|eFilePermissionsWorldExecute
operator|=
operator|(
literal|1u
operator|<<
literal|0
operator|)
operator|,
name|eFilePermissionsUserRW
operator|=
operator|(
name|eFilePermissionsUserRead
operator||
name|eFilePermissionsUserWrite
operator||
literal|0
operator|)
operator|,
name|eFileFilePermissionsUserRX
operator|=
operator|(
name|eFilePermissionsUserRead
operator||
literal|0
operator||
name|eFilePermissionsUserExecute
operator|)
operator|,
name|eFilePermissionsUserRWX
operator|=
operator|(
name|eFilePermissionsUserRead
operator||
name|eFilePermissionsUserWrite
operator||
name|eFilePermissionsUserExecute
operator|)
operator|,
name|eFilePermissionsGroupRW
operator|=
operator|(
name|eFilePermissionsGroupRead
operator||
name|eFilePermissionsGroupWrite
operator||
literal|0
operator|)
operator|,
name|eFilePermissionsGroupRX
operator|=
operator|(
name|eFilePermissionsGroupRead
operator||
literal|0
operator||
name|eFilePermissionsGroupExecute
operator|)
operator|,
name|eFilePermissionsGroupRWX
operator|=
operator|(
name|eFilePermissionsGroupRead
operator||
name|eFilePermissionsGroupWrite
operator||
name|eFilePermissionsGroupExecute
operator|)
operator|,
name|eFilePermissionsWorldRW
operator|=
operator|(
name|eFilePermissionsWorldRead
operator||
name|eFilePermissionsWorldWrite
operator||
literal|0
operator|)
operator|,
name|eFilePermissionsWorldRX
operator|=
operator|(
name|eFilePermissionsWorldRead
operator||
literal|0
operator||
name|eFilePermissionsWorldExecute
operator|)
operator|,
name|eFilePermissionsWorldRWX
operator|=
operator|(
name|eFilePermissionsWorldRead
operator||
name|eFilePermissionsWorldWrite
operator||
name|eFilePermissionsWorldExecute
operator|)
operator|,
name|eFilePermissionsEveryoneR
operator|=
operator|(
name|eFilePermissionsUserRead
operator||
name|eFilePermissionsGroupRead
operator||
name|eFilePermissionsWorldRead
operator|)
operator|,
name|eFilePermissionsEveryoneW
operator|=
operator|(
name|eFilePermissionsUserWrite
operator||
name|eFilePermissionsGroupWrite
operator||
name|eFilePermissionsWorldWrite
operator|)
operator|,
name|eFilePermissionsEveryoneX
operator|=
operator|(
name|eFilePermissionsUserExecute
operator||
name|eFilePermissionsGroupExecute
operator||
name|eFilePermissionsWorldExecute
operator|)
operator|,
name|eFilePermissionsEveryoneRW
operator|=
operator|(
name|eFilePermissionsEveryoneR
operator||
name|eFilePermissionsEveryoneW
operator||
literal|0
operator|)
operator|,
name|eFilePermissionsEveryoneRX
operator|=
operator|(
name|eFilePermissionsEveryoneR
operator||
literal|0
operator||
name|eFilePermissionsEveryoneX
operator|)
operator|,
name|eFilePermissionsEveryoneRWX
operator|=
operator|(
name|eFilePermissionsEveryoneR
operator||
name|eFilePermissionsEveryoneW
operator||
name|eFilePermissionsEveryoneX
operator|)
operator|,
name|eFilePermissionsFileDefault
operator|=
name|eFilePermissionsUserRW
operator|,
name|eFilePermissionsDirectoryDefault
operator|=
name|eFilePermissionsUserRWX
operator|,
block|}
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|// Queue work item types
comment|//
comment|// The different types of work that can be enqueued on a libdispatch
comment|// aka Grand Central Dispatch (GCD) queue.
comment|//----------------------------------------------------------------------
enum|enum
name|QueueItemKind
block|{
name|eQueueItemKindUnknown
init|=
literal|0
block|,
name|eQueueItemKindFunction
block|,
name|eQueueItemKindBlock
block|}
enum|;
comment|//----------------------------------------------------------------------
comment|// Queue type
comment|// libdispatch aka Grand Central Dispatch (GCD) queues can be either serial
comment|// (executing on one thread) or concurrent (executing on multiple threads).
comment|//----------------------------------------------------------------------
enum|enum
name|QueueKind
block|{
name|eQueueKindUnknown
init|=
literal|0
block|,
name|eQueueKindSerial
block|,
name|eQueueKindConcurrent
block|}
enum|;
comment|//----------------------------------------------------------------------
comment|// Expression Evaluation Stages
comment|// These are the cancellable stages of expression evaluation, passed to the
comment|// expression evaluation callback, so that you can interrupt expression
comment|// evaluation at the various points in its lifecycle.
comment|//----------------------------------------------------------------------
enum|enum
name|ExpressionEvaluationPhase
block|{
name|eExpressionEvaluationParse
init|=
literal|0
block|,
name|eExpressionEvaluationIRGen
block|,
name|eExpressionEvaluationExecution
block|,
name|eExpressionEvaluationComplete
block|}
enum|;
comment|//----------------------------------------------------------------------
comment|// Watchpoint Kind
comment|// Indicates what types of events cause the watchpoint to fire.
comment|// Used by Native*Protocol-related classes.
comment|//----------------------------------------------------------------------
name|FLAGS_ENUM
argument_list|(
argument|WatchpointKind
argument_list|)
block|{
name|eWatchpointKindRead
operator|=
operator|(
literal|1u
operator|<<
literal|0
operator|)
operator|,
name|eWatchpointKindWrite
operator|=
operator|(
literal|1u
operator|<<
literal|1
operator|)
block|}
empty_stmt|;
enum|enum
name|GdbSignal
block|{
name|eGdbSignalBadAccess
init|=
literal|0x91
block|,
name|eGdbSignalBadInstruction
init|=
literal|0x92
block|,
name|eGdbSignalArithmetic
init|=
literal|0x93
block|,
name|eGdbSignalEmulation
init|=
literal|0x94
block|,
name|eGdbSignalSoftware
init|=
literal|0x95
block|,
name|eGdbSignalBreakpoint
init|=
literal|0x96
block|}
enum|;
comment|//----------------------------------------------------------------------
comment|// Used with SBHost::GetPath (lldb::PathType) to find files that are
comment|// related to LLDB on the current host machine. Most files are relative
comment|// to LLDB or are in known locations.
comment|//----------------------------------------------------------------------
enum|enum
name|PathType
block|{
name|ePathTypeLLDBShlibDir
block|,
comment|// The directory where the lldb.so (unix) or LLDB
comment|// mach-o file in LLDB.framework (MacOSX) exists
name|ePathTypeSupportExecutableDir
block|,
comment|// Find LLDB support executable directory
comment|// (debugserver, etc)
name|ePathTypeHeaderDir
block|,
comment|// Find LLDB header file directory
name|ePathTypePythonDir
block|,
comment|// Find Python modules (PYTHONPATH) directory
name|ePathTypeLLDBSystemPlugins
block|,
comment|// System plug-ins directory
name|ePathTypeLLDBUserPlugins
block|,
comment|// User plug-ins directory
name|ePathTypeLLDBTempSystemDir
block|,
comment|// The LLDB temp directory for this system that
comment|// will be cleaned up on exit
name|ePathTypeGlobalLLDBTempSystemDir
block|,
comment|// The LLDB temp directory for this system,
comment|// NOT cleaned up on a process exit.
name|ePathTypeClangDir
comment|// Find path to Clang builtin headers
block|}
enum|;
comment|//----------------------------------------------------------------------
comment|// Kind of member function
comment|// Used by the type system
comment|//----------------------------------------------------------------------
enum|enum
name|MemberFunctionKind
block|{
name|eMemberFunctionKindUnknown
init|=
literal|0
block|,
comment|// Not sure what the type of this is
name|eMemberFunctionKindConstructor
block|,
comment|// A function used to create instances
name|eMemberFunctionKindDestructor
block|,
comment|// A function used to tear down existing
comment|// instances
name|eMemberFunctionKindInstanceMethod
block|,
comment|// A function that applies to a specific
comment|// instance
name|eMemberFunctionKindStaticMethod
comment|// A function that applies to a type rather
comment|// than any instance
block|}
enum|;
comment|//----------------------------------------------------------------------
comment|// String matching algorithm used by SBTarget
comment|//----------------------------------------------------------------------
enum|enum
name|MatchType
block|{
name|eMatchTypeNormal
block|,
name|eMatchTypeRegex
block|,
name|eMatchTypeStartsWith
block|}
enum|;
comment|//----------------------------------------------------------------------
comment|// Bitmask that describes details about a type
comment|//----------------------------------------------------------------------
name|FLAGS_ENUM
argument_list|(
argument|TypeFlags
argument_list|)
block|{
name|eTypeHasChildren
operator|=
operator|(
literal|1u
operator|<<
literal|0
operator|)
operator|,
name|eTypeHasValue
operator|=
operator|(
literal|1u
operator|<<
literal|1
operator|)
operator|,
name|eTypeIsArray
operator|=
operator|(
literal|1u
operator|<<
literal|2
operator|)
operator|,
name|eTypeIsBlock
operator|=
operator|(
literal|1u
operator|<<
literal|3
operator|)
operator|,
name|eTypeIsBuiltIn
operator|=
operator|(
literal|1u
operator|<<
literal|4
operator|)
operator|,
name|eTypeIsClass
operator|=
operator|(
literal|1u
operator|<<
literal|5
operator|)
operator|,
name|eTypeIsCPlusPlus
operator|=
operator|(
literal|1u
operator|<<
literal|6
operator|)
operator|,
name|eTypeIsEnumeration
operator|=
operator|(
literal|1u
operator|<<
literal|7
operator|)
operator|,
name|eTypeIsFuncPrototype
operator|=
operator|(
literal|1u
operator|<<
literal|8
operator|)
operator|,
name|eTypeIsMember
operator|=
operator|(
literal|1u
operator|<<
literal|9
operator|)
operator|,
name|eTypeIsObjC
operator|=
operator|(
literal|1u
operator|<<
literal|10
operator|)
operator|,
name|eTypeIsPointer
operator|=
operator|(
literal|1u
operator|<<
literal|11
operator|)
operator|,
name|eTypeIsReference
operator|=
operator|(
literal|1u
operator|<<
literal|12
operator|)
operator|,
name|eTypeIsStructUnion
operator|=
operator|(
literal|1u
operator|<<
literal|13
operator|)
operator|,
name|eTypeIsTemplate
operator|=
operator|(
literal|1u
operator|<<
literal|14
operator|)
operator|,
name|eTypeIsTypedef
operator|=
operator|(
literal|1u
operator|<<
literal|15
operator|)
operator|,
name|eTypeIsVector
operator|=
operator|(
literal|1u
operator|<<
literal|16
operator|)
operator|,
name|eTypeIsScalar
operator|=
operator|(
literal|1u
operator|<<
literal|17
operator|)
operator|,
name|eTypeIsInteger
operator|=
operator|(
literal|1u
operator|<<
literal|18
operator|)
operator|,
name|eTypeIsFloat
operator|=
operator|(
literal|1u
operator|<<
literal|19
operator|)
operator|,
name|eTypeIsComplex
operator|=
operator|(
literal|1u
operator|<<
literal|20
operator|)
operator|,
name|eTypeIsSigned
operator|=
operator|(
literal|1u
operator|<<
literal|21
operator|)
operator|,
name|eTypeInstanceIsPointer
operator|=
operator|(
literal|1u
operator|<<
literal|22
operator|)
block|}
empty_stmt|;
name|FLAGS_ENUM
argument_list|(
argument|CommandFlags
argument_list|)
block|{
comment|//----------------------------------------------------------------------
comment|// eCommandRequiresTarget
comment|//
comment|// Ensures a valid target is contained in m_exe_ctx prior to executing
comment|// the command. If a target doesn't exist or is invalid, the command
comment|// will fail and CommandObject::GetInvalidTargetDescription() will be
comment|// returned as the error. CommandObject subclasses can override the
comment|// virtual function for GetInvalidTargetDescription() to provide custom
comment|// strings when needed.
comment|//----------------------------------------------------------------------
name|eCommandRequiresTarget
operator|=
operator|(
literal|1u
operator|<<
literal|0
operator|)
operator|,
comment|//----------------------------------------------------------------------
comment|// eCommandRequiresProcess
comment|//
comment|// Ensures a valid process is contained in m_exe_ctx prior to executing
comment|// the command. If a process doesn't exist or is invalid, the command
comment|// will fail and CommandObject::GetInvalidProcessDescription() will be
comment|// returned as the error. CommandObject subclasses can override the
comment|// virtual function for GetInvalidProcessDescription() to provide custom
comment|// strings when needed.
comment|//----------------------------------------------------------------------
name|eCommandRequiresProcess
operator|=
operator|(
literal|1u
operator|<<
literal|1
operator|)
operator|,
comment|//----------------------------------------------------------------------
comment|// eCommandRequiresThread
comment|//
comment|// Ensures a valid thread is contained in m_exe_ctx prior to executing
comment|// the command. If a thread doesn't exist or is invalid, the command
comment|// will fail and CommandObject::GetInvalidThreadDescription() will be
comment|// returned as the error. CommandObject subclasses can override the
comment|// virtual function for GetInvalidThreadDescription() to provide custom
comment|// strings when needed.
comment|//----------------------------------------------------------------------
name|eCommandRequiresThread
operator|=
operator|(
literal|1u
operator|<<
literal|2
operator|)
operator|,
comment|//----------------------------------------------------------------------
comment|// eCommandRequiresFrame
comment|//
comment|// Ensures a valid frame is contained in m_exe_ctx prior to executing
comment|// the command. If a frame doesn't exist or is invalid, the command
comment|// will fail and CommandObject::GetInvalidFrameDescription() will be
comment|// returned as the error. CommandObject subclasses can override the
comment|// virtual function for GetInvalidFrameDescription() to provide custom
comment|// strings when needed.
comment|//----------------------------------------------------------------------
name|eCommandRequiresFrame
operator|=
operator|(
literal|1u
operator|<<
literal|3
operator|)
operator|,
comment|//----------------------------------------------------------------------
comment|// eCommandRequiresRegContext
comment|//
comment|// Ensures a valid register context (from the selected frame if there
comment|// is a frame in m_exe_ctx, or from the selected thread from m_exe_ctx)
comment|// is available from m_exe_ctx prior to executing the command. If a
comment|// target doesn't exist or is invalid, the command will fail and
comment|// CommandObject::GetInvalidRegContextDescription() will be returned as
comment|// the error. CommandObject subclasses can override the virtual function
comment|// for GetInvalidRegContextDescription() to provide custom strings when
comment|// needed.
comment|//----------------------------------------------------------------------
name|eCommandRequiresRegContext
operator|=
operator|(
literal|1u
operator|<<
literal|4
operator|)
operator|,
comment|//----------------------------------------------------------------------
comment|// eCommandTryTargetAPILock
comment|//
comment|// Attempts to acquire the target lock if a target is selected in the
comment|// command interpreter. If the command object fails to acquire the API
comment|// lock, the command will fail with an appropriate error message.
comment|//----------------------------------------------------------------------
name|eCommandTryTargetAPILock
operator|=
operator|(
literal|1u
operator|<<
literal|5
operator|)
operator|,
comment|//----------------------------------------------------------------------
comment|// eCommandProcessMustBeLaunched
comment|//
comment|// Verifies that there is a launched process in m_exe_ctx, if there
comment|// isn't, the command will fail with an appropriate error message.
comment|//----------------------------------------------------------------------
name|eCommandProcessMustBeLaunched
operator|=
operator|(
literal|1u
operator|<<
literal|6
operator|)
operator|,
comment|//----------------------------------------------------------------------
comment|// eCommandProcessMustBePaused
comment|//
comment|// Verifies that there is a paused process in m_exe_ctx, if there
comment|// isn't, the command will fail with an appropriate error message.
comment|//----------------------------------------------------------------------
name|eCommandProcessMustBePaused
operator|=
operator|(
literal|1u
operator|<<
literal|7
operator|)
block|}
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|// Whether a summary should cap how much data it returns to users or not
comment|//----------------------------------------------------------------------
enum|enum
name|TypeSummaryCapping
block|{
name|eTypeSummaryCapped
init|=
name|true
block|,
name|eTypeSummaryUncapped
init|=
name|false
block|}
enum|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_lldb_enumerations_h_
end_comment

end_unit

