begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,alpha.core -analyzer-store=region -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// This test case was reported in<rdar:problem/6080742>.
end_comment

begin_comment
comment|// It tests path-sensitivity with respect to '!(cfstring != 0)' (negation of inequality).
end_comment

begin_function_decl
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
specifier|restrict
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|unsigned
name|long
name|UInt32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|long
name|SInt32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|SInt32
name|OSStatus
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|Boolean
typedef|;
end_typedef

begin_enum
enum|enum
block|{
name|noErr
init|=
literal|0
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
specifier|const
name|void
modifier|*
name|CFTypeRef
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|struct
name|__CFString
modifier|*
name|CFStringRef
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|struct
name|__CFAllocator
modifier|*
name|CFAllocatorRef
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|CFRelease
parameter_list|(
name|CFTypeRef
name|cf
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|UInt32
name|CFStringEncoding
typedef|;
end_typedef

begin_enum
enum|enum
block|{
name|kCFStringEncodingMacRoman
init|=
literal|0
block|,
name|kCFStringEncodingWindowsLatin1
init|=
literal|0x0500
block|,
name|kCFStringEncodingISOLatin1
init|=
literal|0x0201
block|,
name|kCFStringEncodingNextStepLatin
init|=
literal|0x0B01
block|,
name|kCFStringEncodingASCII
init|=
literal|0x0600
block|,
name|kCFStringEncodingUnicode
init|=
literal|0x0100
block|,
name|kCFStringEncodingUTF8
init|=
literal|0x08000100
block|,
name|kCFStringEncodingNonLossyASCII
init|=
literal|0x0BFF
block|,
name|kCFStringEncodingUTF16
init|=
literal|0x0100
block|,
name|kCFStringEncodingUTF16BE
init|=
literal|0x10000100
block|,
name|kCFStringEncodingUTF16LE
init|=
literal|0x14000100
block|,
name|kCFStringEncodingUTF32
init|=
literal|0x0c000100
block|,
name|kCFStringEncodingUTF32BE
init|=
literal|0x18000100
block|,
name|kCFStringEncodingUTF32LE
init|=
literal|0x1c000100
block|}
enum|;
end_enum

begin_function_decl
specifier|extern
name|CFStringRef
name|CFStringCreateWithCString
parameter_list|(
name|CFAllocatorRef
name|alloc
parameter_list|,
specifier|const
name|char
modifier|*
name|cStr
parameter_list|,
name|CFStringEncoding
name|encoding
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
block|{
name|memROZWarn
init|=
operator|-
literal|99
block|,
name|memROZError
init|=
operator|-
literal|99
block|,
name|memROZErr
init|=
operator|-
literal|99
block|,
name|memFullErr
init|=
operator|-
literal|108
block|,
name|nilHandleErr
init|=
operator|-
literal|109
block|,
name|memWZErr
init|=
operator|-
literal|111
block|,
name|memPurErr
init|=
operator|-
literal|112
block|,
name|memAdrErr
init|=
operator|-
literal|110
block|,
name|memAZErr
init|=
operator|-
literal|113
block|,
name|memPCErr
init|=
operator|-
literal|114
block|,
name|memBCErr
init|=
operator|-
literal|115
block|,
name|memSCErr
init|=
operator|-
literal|116
block|,
name|memLockedErr
init|=
operator|-
literal|117
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|DEBUG1
end_define

begin_function_decl
name|void
name|DebugStop
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DebugTraceIf
parameter_list|(
name|unsigned
name|int
name|condition
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|DebugDisplayOSStatusMsg
parameter_list|(
name|OSStatus
name|status
parameter_list|,
specifier|const
name|char
modifier|*
name|statusStr
parameter_list|,
specifier|const
name|char
modifier|*
name|fileName
parameter_list|,
name|unsigned
name|long
name|lineNumber
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|Assert
parameter_list|(
name|condition
parameter_list|)
value|if (!(condition)) { DebugStop("Assertion failure: %s [File: %s, Line: %lu]", #condition, __FILE__, __LINE__); }
end_define

begin_define
define|#
directive|define
name|AssertMsg
parameter_list|(
name|condition
parameter_list|,
name|message
parameter_list|)
value|if (!(condition)) { DebugStop("Assertion failure: %s (%s) [File: %s, Line: %lu]", #condition, message, __FILE__, __LINE__); }
end_define

begin_define
define|#
directive|define
name|Require
parameter_list|(
name|condition
parameter_list|)
value|if (!(condition)) { DebugStop("Assertion failure: %s [File: %s, Line: %lu]", #condition, __FILE__, __LINE__); }
end_define

begin_define
define|#
directive|define
name|RequireAction
parameter_list|(
name|condition
parameter_list|,
name|action
parameter_list|)
value|if (!(condition)) { DebugStop("Assertion failure: %s [File: %s, Line: %lu]", #condition, __FILE__, __LINE__); action }
end_define

begin_define
define|#
directive|define
name|RequireActionSilent
parameter_list|(
name|condition
parameter_list|,
name|action
parameter_list|)
value|if (!(condition)) { action }
end_define

begin_define
define|#
directive|define
name|AssertNoErr
parameter_list|(
name|err
parameter_list|)
value|{ DebugDisplayOSStatusMsg((err), #err, __FILE__, __LINE__); }
end_define

begin_define
define|#
directive|define
name|RequireNoErr
parameter_list|(
name|err
parameter_list|,
name|action
parameter_list|)
value|{ if( DebugDisplayOSStatusMsg((err), #err, __FILE__, __LINE__) ) { action }}
end_define

begin_function_decl
name|void
name|DebugStop
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Not an abort function. */
end_comment

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|CFStringRef
name|cfString
decl_stmt|;
name|OSStatus
name|status
init|=
name|noErr
decl_stmt|;
name|cfString
operator|=
name|CFStringCreateWithCString
argument_list|(
literal|0
argument_list|,
literal|"hello"
argument_list|,
name|kCFStringEncodingUTF8
argument_list|)
expr_stmt|;
name|RequireAction
argument_list|(
argument|cfString !=
literal|0
argument_list|,
argument|return memFullErr;
argument_list|)
comment|//no - warning
name|printf
argument_list|(
literal|"cfstring %p\n"
argument_list|,
name|cfString
argument_list|)
expr_stmt|;
name|Exit
label|:
name|CFRelease
argument_list|(
name|cfString
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

