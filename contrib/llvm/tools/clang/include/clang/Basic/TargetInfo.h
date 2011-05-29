begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- TargetInfo.h - Expose information about the target -----*- C++ -*-===//
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
comment|//  This file defines the TargetInfo interface.
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
name|LLVM_CLANG_BASIC_TARGETINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_TARGETINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSwitch.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/AddressSpaces.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/VersionTuple.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
struct_decl|struct
name|fltSemantics
struct_decl|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Diagnostic
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|MacroBuilder
decl_stmt|;
name|class
name|SourceLocation
decl_stmt|;
name|class
name|SourceManager
decl_stmt|;
name|class
name|TargetOptions
decl_stmt|;
name|namespace
name|Builtin
block|{
struct_decl|struct
name|Info
struct_decl|;
block|}
comment|/// TargetCXXABI - The types of C++ ABIs for which we can generate code.
enum|enum
name|TargetCXXABI
block|{
comment|/// The generic ("Itanium") C++ ABI, documented at:
comment|///   http://www.codesourcery.com/public/cxx-abi/
name|CXXABI_Itanium
block|,
comment|/// The ARM C++ ABI, based largely on the Itanium ABI but with
comment|/// significant differences.
comment|///    http://infocenter.arm.com
comment|///                    /help/topic/com.arm.doc.ihi0041c/IHI0041C_cppabi.pdf
name|CXXABI_ARM
block|,
comment|/// The Visual Studio ABI.  Only scattered official documentation exists.
name|CXXABI_Microsoft
block|}
enum|;
comment|/// TargetInfo - This class exposes information about the current target.
comment|///
name|class
name|TargetInfo
range|:
name|public
name|llvm
operator|::
name|RefCountedBase
operator|<
name|TargetInfo
operator|>
block|{
name|llvm
operator|::
name|Triple
name|Triple
block|;
name|protected
operator|:
comment|// Target values set by the ctor of the actual target implementation.  Default
comment|// values are specified by the TargetInfo constructor.
name|bool
name|TLSSupported
block|;
name|bool
name|NoAsmVariants
block|;
comment|// True if {|} are normal characters.
name|unsigned
name|char
name|PointerWidth
block|,
name|PointerAlign
block|;
name|unsigned
name|char
name|BoolWidth
block|,
name|BoolAlign
block|;
name|unsigned
name|char
name|IntWidth
block|,
name|IntAlign
block|;
name|unsigned
name|char
name|FloatWidth
block|,
name|FloatAlign
block|;
name|unsigned
name|char
name|DoubleWidth
block|,
name|DoubleAlign
block|;
name|unsigned
name|char
name|LongDoubleWidth
block|,
name|LongDoubleAlign
block|;
name|unsigned
name|char
name|LargeArrayMinWidth
block|,
name|LargeArrayAlign
block|;
name|unsigned
name|char
name|LongWidth
block|,
name|LongAlign
block|;
name|unsigned
name|char
name|LongLongWidth
block|,
name|LongLongAlign
block|;
specifier|const
name|char
operator|*
name|DescriptionString
block|;
specifier|const
name|char
operator|*
name|UserLabelPrefix
block|;
specifier|const
name|char
operator|*
name|MCountName
block|;
specifier|const
name|llvm
operator|::
name|fltSemantics
operator|*
name|FloatFormat
block|,
operator|*
name|DoubleFormat
block|,
operator|*
name|LongDoubleFormat
block|;
name|unsigned
name|char
name|RegParmMax
block|,
name|SSERegParmMax
block|;
name|TargetCXXABI
name|CXXABI
block|;
specifier|const
name|LangAS
operator|::
name|Map
operator|*
name|AddrSpaceMap
block|;
name|mutable
name|llvm
operator|::
name|StringRef
name|PlatformName
block|;
name|mutable
name|VersionTuple
name|PlatformMinVersion
block|;
name|unsigned
name|HasAlignMac68kSupport
operator|:
literal|1
block|;
name|unsigned
name|RealTypeUsesObjCFPRet
operator|:
literal|3
block|;
comment|// TargetInfo Constructor.  Default initializes all fields.
name|TargetInfo
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|T
argument_list|)
block|;
name|public
operator|:
comment|/// CreateTargetInfo - Construct a target for the given options.
comment|///
comment|/// \param Opts - The options to use to initialize the target. The target may
comment|/// modify the options to canonicalize the target feature information to match
comment|/// what the backend expects.
specifier|static
name|TargetInfo
operator|*
name|CreateTargetInfo
argument_list|(
name|Diagnostic
operator|&
name|Diags
argument_list|,
name|TargetOptions
operator|&
name|Opts
argument_list|)
block|;
name|virtual
operator|~
name|TargetInfo
argument_list|()
block|;
comment|///===---- Target Data Type Query Methods -------------------------------===//
block|enum
name|IntType
block|{
name|NoInt
operator|=
literal|0
block|,
name|SignedShort
block|,
name|UnsignedShort
block|,
name|SignedInt
block|,
name|UnsignedInt
block|,
name|SignedLong
block|,
name|UnsignedLong
block|,
name|SignedLongLong
block|,
name|UnsignedLongLong
block|}
block|;    enum
name|RealType
block|{
name|Float
operator|=
literal|0
block|,
name|Double
block|,
name|LongDouble
block|}
block|;
name|protected
operator|:
name|IntType
name|SizeType
block|,
name|IntMaxType
block|,
name|UIntMaxType
block|,
name|PtrDiffType
block|,
name|IntPtrType
block|,
name|WCharType
block|,
name|WIntType
block|,
name|Char16Type
block|,
name|Char32Type
block|,
name|Int64Type
block|,
name|SigAtomicType
block|;
comment|/// Control whether the alignment of bit-field types is respected when laying
comment|/// out structures. If true, then the alignment of the bit-field type will be
comment|/// used to (a) impact the alignment of the containing structure, and (b)
comment|/// ensure that the individual bit-field will not straddle an alignment
comment|/// boundary.
name|unsigned
name|UseBitFieldTypeAlignment
operator|:
literal|1
block|;
name|public
operator|:
name|IntType
name|getSizeType
argument_list|()
specifier|const
block|{
return|return
name|SizeType
return|;
block|}
name|IntType
name|getIntMaxType
argument_list|()
specifier|const
block|{
return|return
name|IntMaxType
return|;
block|}
name|IntType
name|getUIntMaxType
argument_list|()
specifier|const
block|{
return|return
name|UIntMaxType
return|;
block|}
name|IntType
name|getPtrDiffType
argument_list|(
argument|unsigned AddrSpace
argument_list|)
specifier|const
block|{
return|return
name|AddrSpace
operator|==
literal|0
operator|?
name|PtrDiffType
operator|:
name|getPtrDiffTypeV
argument_list|(
name|AddrSpace
argument_list|)
return|;
block|}
name|IntType
name|getIntPtrType
argument_list|()
specifier|const
block|{
return|return
name|IntPtrType
return|;
block|}
name|IntType
name|getWCharType
argument_list|()
specifier|const
block|{
return|return
name|WCharType
return|;
block|}
name|IntType
name|getWIntType
argument_list|()
specifier|const
block|{
return|return
name|WIntType
return|;
block|}
name|IntType
name|getChar16Type
argument_list|()
specifier|const
block|{
return|return
name|Char16Type
return|;
block|}
name|IntType
name|getChar32Type
argument_list|()
specifier|const
block|{
return|return
name|Char32Type
return|;
block|}
name|IntType
name|getInt64Type
argument_list|()
specifier|const
block|{
return|return
name|Int64Type
return|;
block|}
name|IntType
name|getSigAtomicType
argument_list|()
specifier|const
block|{
return|return
name|SigAtomicType
return|;
block|}
comment|/// getTypeWidth - Return the width (in bits) of the specified integer type
comment|/// enum. For example, SignedInt -> getIntWidth().
name|unsigned
name|getTypeWidth
argument_list|(
argument|IntType T
argument_list|)
specifier|const
block|;
comment|/// getTypeAlign - Return the alignment (in bits) of the specified integer
comment|/// type enum. For example, SignedInt -> getIntAlign().
name|unsigned
name|getTypeAlign
argument_list|(
argument|IntType T
argument_list|)
specifier|const
block|;
comment|/// isTypeSigned - Return whether an integer types is signed. Returns true if
comment|/// the type is signed; false otherwise.
specifier|static
name|bool
name|isTypeSigned
argument_list|(
argument|IntType T
argument_list|)
block|;
comment|/// getPointerWidth - Return the width of pointers on this target, for the
comment|/// specified address space.
name|uint64_t
name|getPointerWidth
argument_list|(
argument|unsigned AddrSpace
argument_list|)
specifier|const
block|{
return|return
name|AddrSpace
operator|==
literal|0
condition|?
name|PointerWidth
else|:
name|getPointerWidthV
argument_list|(
name|AddrSpace
argument_list|)
return|;
block|}
name|uint64_t
name|getPointerAlign
argument_list|(
argument|unsigned AddrSpace
argument_list|)
specifier|const
block|{
return|return
name|AddrSpace
operator|==
literal|0
condition|?
name|PointerAlign
else|:
name|getPointerAlignV
argument_list|(
name|AddrSpace
argument_list|)
return|;
block|}
comment|/// getBoolWidth/Align - Return the size of '_Bool' and C++ 'bool' for this
comment|/// target, in bits.
name|unsigned
name|getBoolWidth
argument_list|()
specifier|const
block|{
return|return
name|BoolWidth
return|;
block|}
name|unsigned
name|getBoolAlign
argument_list|()
specifier|const
block|{
return|return
name|BoolAlign
return|;
block|}
name|unsigned
name|getCharWidth
argument_list|()
specifier|const
block|{
return|return
literal|8
return|;
block|}
comment|// FIXME
name|unsigned
name|getCharAlign
argument_list|()
specifier|const
block|{
return|return
literal|8
return|;
block|}
comment|// FIXME
comment|/// getShortWidth/Align - Return the size of 'signed short' and
comment|/// 'unsigned short' for this target, in bits.
name|unsigned
name|getShortWidth
argument_list|()
specifier|const
block|{
return|return
literal|16
return|;
block|}
comment|// FIXME
name|unsigned
name|getShortAlign
argument_list|()
specifier|const
block|{
return|return
literal|16
return|;
block|}
comment|// FIXME
comment|/// getIntWidth/Align - Return the size of 'signed int' and 'unsigned int' for
comment|/// this target, in bits.
name|unsigned
name|getIntWidth
argument_list|()
specifier|const
block|{
return|return
name|IntWidth
return|;
block|}
name|unsigned
name|getIntAlign
argument_list|()
specifier|const
block|{
return|return
name|IntAlign
return|;
block|}
comment|/// getLongWidth/Align - Return the size of 'signed long' and 'unsigned long'
comment|/// for this target, in bits.
name|unsigned
name|getLongWidth
argument_list|()
specifier|const
block|{
return|return
name|LongWidth
return|;
block|}
name|unsigned
name|getLongAlign
argument_list|()
specifier|const
block|{
return|return
name|LongAlign
return|;
block|}
comment|/// getLongLongWidth/Align - Return the size of 'signed long long' and
comment|/// 'unsigned long long' for this target, in bits.
name|unsigned
name|getLongLongWidth
argument_list|()
specifier|const
block|{
return|return
name|LongLongWidth
return|;
block|}
name|unsigned
name|getLongLongAlign
argument_list|()
specifier|const
block|{
return|return
name|LongLongAlign
return|;
block|}
comment|/// getWCharWidth/Align - Return the size of 'wchar_t' for this target, in
comment|/// bits.
name|unsigned
name|getWCharWidth
argument_list|()
specifier|const
block|{
return|return
name|getTypeWidth
argument_list|(
name|WCharType
argument_list|)
return|;
block|}
name|unsigned
name|getWCharAlign
argument_list|()
specifier|const
block|{
return|return
name|getTypeAlign
argument_list|(
name|WCharType
argument_list|)
return|;
block|}
comment|/// getChar16Width/Align - Return the size of 'char16_t' for this target, in
comment|/// bits.
name|unsigned
name|getChar16Width
argument_list|()
specifier|const
block|{
return|return
name|getTypeWidth
argument_list|(
name|Char16Type
argument_list|)
return|;
block|}
name|unsigned
name|getChar16Align
argument_list|()
specifier|const
block|{
return|return
name|getTypeAlign
argument_list|(
name|Char16Type
argument_list|)
return|;
block|}
comment|/// getChar32Width/Align - Return the size of 'char32_t' for this target, in
comment|/// bits.
name|unsigned
name|getChar32Width
argument_list|()
specifier|const
block|{
return|return
name|getTypeWidth
argument_list|(
name|Char32Type
argument_list|)
return|;
block|}
name|unsigned
name|getChar32Align
argument_list|()
specifier|const
block|{
return|return
name|getTypeAlign
argument_list|(
name|Char32Type
argument_list|)
return|;
block|}
comment|/// getFloatWidth/Align/Format - Return the size/align/format of 'float'.
name|unsigned
name|getFloatWidth
argument_list|()
specifier|const
block|{
return|return
name|FloatWidth
return|;
block|}
name|unsigned
name|getFloatAlign
argument_list|()
specifier|const
block|{
return|return
name|FloatAlign
return|;
block|}
specifier|const
name|llvm
operator|::
name|fltSemantics
operator|&
name|getFloatFormat
argument_list|()
specifier|const
block|{
return|return
operator|*
name|FloatFormat
return|;
block|}
comment|/// getDoubleWidth/Align/Format - Return the size/align/format of 'double'.
name|unsigned
name|getDoubleWidth
argument_list|()
specifier|const
block|{
return|return
name|DoubleWidth
return|;
block|}
name|unsigned
name|getDoubleAlign
argument_list|()
specifier|const
block|{
return|return
name|DoubleAlign
return|;
block|}
specifier|const
name|llvm
operator|::
name|fltSemantics
operator|&
name|getDoubleFormat
argument_list|()
specifier|const
block|{
return|return
operator|*
name|DoubleFormat
return|;
block|}
comment|/// getLongDoubleWidth/Align/Format - Return the size/align/format of 'long
comment|/// double'.
name|unsigned
name|getLongDoubleWidth
argument_list|()
specifier|const
block|{
return|return
name|LongDoubleWidth
return|;
block|}
name|unsigned
name|getLongDoubleAlign
argument_list|()
specifier|const
block|{
return|return
name|LongDoubleAlign
return|;
block|}
specifier|const
name|llvm
operator|::
name|fltSemantics
operator|&
name|getLongDoubleFormat
argument_list|()
specifier|const
block|{
return|return
operator|*
name|LongDoubleFormat
return|;
block|}
comment|// getLargeArrayMinWidth/Align - Return the minimum array size that is
comment|// 'large' and its alignment.
name|unsigned
name|getLargeArrayMinWidth
argument_list|()
specifier|const
block|{
return|return
name|LargeArrayMinWidth
return|;
block|}
name|unsigned
name|getLargeArrayAlign
argument_list|()
specifier|const
block|{
return|return
name|LargeArrayAlign
return|;
block|}
comment|/// getIntMaxTWidth - Return the size of intmax_t and uintmax_t for this
comment|/// target, in bits.
name|unsigned
name|getIntMaxTWidth
argument_list|()
specifier|const
block|{
return|return
name|getTypeWidth
argument_list|(
name|IntMaxType
argument_list|)
return|;
block|}
comment|/// getUserLabelPrefix - This returns the default value of the
comment|/// __USER_LABEL_PREFIX__ macro, which is the prefix given to user symbols by
comment|/// default.  On most platforms this is "_", but it is "" on some, and "." on
comment|/// others.
specifier|const
name|char
operator|*
name|getUserLabelPrefix
argument_list|()
specifier|const
block|{
return|return
name|UserLabelPrefix
return|;
block|}
comment|/// MCountName - This returns name of the mcount instrumentation function.
specifier|const
name|char
operator|*
name|getMCountName
argument_list|()
specifier|const
block|{
return|return
name|MCountName
return|;
block|}
name|bool
name|useBitFieldTypeAlignment
argument_list|()
specifier|const
block|{
return|return
name|UseBitFieldTypeAlignment
return|;
block|}
comment|/// hasAlignMac68kSupport - Check whether this target support '#pragma options
comment|/// align=mac68k'.
name|bool
name|hasAlignMac68kSupport
argument_list|()
specifier|const
block|{
return|return
name|HasAlignMac68kSupport
return|;
block|}
comment|/// getTypeName - Return the user string for the specified integer type enum.
comment|/// For example, SignedShort -> "short".
specifier|static
specifier|const
name|char
operator|*
name|getTypeName
argument_list|(
argument|IntType T
argument_list|)
block|;
comment|/// getTypeConstantSuffix - Return the constant suffix for the specified
comment|/// integer type enum. For example, SignedLong -> "L".
specifier|static
specifier|const
name|char
operator|*
name|getTypeConstantSuffix
argument_list|(
argument|IntType T
argument_list|)
block|;
comment|/// \brief Check whether the given real type should use the "fpret" flavor of
comment|/// Obj-C message passing on this target.
name|bool
name|useObjCFPRetForRealType
argument_list|(
argument|RealType T
argument_list|)
specifier|const
block|{
return|return
name|RealTypeUsesObjCFPRet
operator|&
operator|(
literal|1
operator|<<
name|T
operator|)
return|;
block|}
comment|///===---- Other target property query methods --------------------------===//
comment|/// getTargetDefines - Appends the target-specific #define values for this
comment|/// target set to the specified buffer.
name|virtual
name|void
name|getTargetDefines
argument_list|(
argument|const LangOptions&Opts
argument_list|,
argument|MacroBuilder&Builder
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// getTargetBuiltins - Return information about target-specific builtins for
comment|/// the current primary target, and info about which builtins are non-portable
comment|/// across the current set of primary and secondary targets.
name|virtual
name|void
name|getTargetBuiltins
argument_list|(
argument|const Builtin::Info *&Records
argument_list|,
argument|unsigned&NumRecords
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// getVAListDeclaration - Return the declaration to use for
comment|/// __builtin_va_list, which is target-specific.
name|virtual
specifier|const
name|char
operator|*
name|getVAListDeclaration
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// isValidGCCRegisterName - Returns whether the passed in string
comment|/// is a valid register name according to GCC. This is used by Sema for
comment|/// inline asm statements.
name|bool
name|isValidGCCRegisterName
argument_list|(
argument|llvm::StringRef Name
argument_list|)
specifier|const
block|;
comment|// getNormalizedGCCRegisterName - Returns the "normalized" GCC register name.
comment|// For example, on x86 it will return "ax" when "eax" is passed in.
name|llvm
operator|::
name|StringRef
name|getNormalizedGCCRegisterName
argument_list|(
argument|llvm::StringRef Name
argument_list|)
specifier|const
block|;    struct
name|ConstraintInfo
block|{     enum
block|{
name|CI_None
operator|=
literal|0x00
block|,
name|CI_AllowsMemory
operator|=
literal|0x01
block|,
name|CI_AllowsRegister
operator|=
literal|0x02
block|,
name|CI_ReadWrite
operator|=
literal|0x04
block|,
comment|// "+r" output constraint (read and write).
name|CI_HasMatchingInput
operator|=
literal|0x08
comment|// This output operand has a matching input.
block|}
block|;
name|unsigned
name|Flags
block|;
name|int
name|TiedOperand
block|;
name|std
operator|::
name|string
name|ConstraintStr
block|;
comment|// constraint: "=rm"
name|std
operator|::
name|string
name|Name
block|;
comment|// Operand name: [foo] with no []'s.
name|public
operator|:
name|ConstraintInfo
argument_list|(
argument|llvm::StringRef ConstraintStr
argument_list|,
argument|llvm::StringRef Name
argument_list|)
operator|:
name|Flags
argument_list|(
literal|0
argument_list|)
block|,
name|TiedOperand
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|ConstraintStr
argument_list|(
name|ConstraintStr
operator|.
name|str
argument_list|()
argument_list|)
block|,
name|Name
argument_list|(
argument|Name.str()
argument_list|)
block|{}
specifier|const
name|std
operator|::
name|string
operator|&
name|getConstraintStr
argument_list|()
specifier|const
block|{
return|return
name|ConstraintStr
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
name|bool
name|isReadWrite
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Flags
operator|&
name|CI_ReadWrite
operator|)
operator|!=
literal|0
return|;
block|}
name|bool
name|allowsRegister
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Flags
operator|&
name|CI_AllowsRegister
operator|)
operator|!=
literal|0
return|;
block|}
name|bool
name|allowsMemory
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Flags
operator|&
name|CI_AllowsMemory
operator|)
operator|!=
literal|0
return|;
block|}
comment|/// hasMatchingInput - Return true if this output operand has a matching
comment|/// (tied) input operand.
name|bool
name|hasMatchingInput
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Flags
operator|&
name|CI_HasMatchingInput
operator|)
operator|!=
literal|0
return|;
block|}
comment|/// hasTiedOperand() - Return true if this input operand is a matching
comment|/// constraint that ties it to an output operand.  If this returns true,
comment|/// then getTiedOperand will indicate which output operand this is tied to.
name|bool
name|hasTiedOperand
argument_list|()
specifier|const
block|{
return|return
name|TiedOperand
operator|!=
operator|-
literal|1
return|;
block|}
name|unsigned
name|getTiedOperand
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|hasTiedOperand
argument_list|()
operator|&&
literal|"Has no tied operand!"
argument_list|)
block|;
return|return
operator|(
name|unsigned
operator|)
name|TiedOperand
return|;
block|}
name|void
name|setIsReadWrite
argument_list|()
block|{
name|Flags
operator||=
name|CI_ReadWrite
block|; }
name|void
name|setAllowsMemory
argument_list|()
block|{
name|Flags
operator||=
name|CI_AllowsMemory
block|; }
name|void
name|setAllowsRegister
argument_list|()
block|{
name|Flags
operator||=
name|CI_AllowsRegister
block|; }
name|void
name|setHasMatchingInput
argument_list|()
block|{
name|Flags
operator||=
name|CI_HasMatchingInput
block|; }
comment|/// setTiedOperand - Indicate that this is an input operand that is tied to
comment|/// the specified output operand.  Copy over the various constraint
comment|/// information from the output.
name|void
name|setTiedOperand
argument_list|(
argument|unsigned N
argument_list|,
argument|ConstraintInfo&Output
argument_list|)
block|{
name|Output
operator|.
name|setHasMatchingInput
argument_list|()
block|;
name|Flags
operator|=
name|Output
operator|.
name|Flags
block|;
name|TiedOperand
operator|=
name|N
block|;
comment|// Don't copy Name or constraint string.
block|}
expr|}
block|;
comment|// validateOutputConstraint, validateInputConstraint - Checks that
comment|// a constraint is valid and provides information about it.
comment|// FIXME: These should return a real error instead of just true/false.
name|bool
name|validateOutputConstraint
argument_list|(
argument|ConstraintInfo&Info
argument_list|)
specifier|const
block|;
name|bool
name|validateInputConstraint
argument_list|(
argument|ConstraintInfo *OutputConstraints
argument_list|,
argument|unsigned NumOutputs
argument_list|,
argument|ConstraintInfo&info
argument_list|)
specifier|const
block|;
name|bool
name|resolveSymbolicName
argument_list|(
argument|const char *&Name
argument_list|,
argument|ConstraintInfo *OutputConstraints
argument_list|,
argument|unsigned NumOutputs
argument_list|,
argument|unsigned&Index
argument_list|)
specifier|const
block|;
name|virtual
name|std
operator|::
name|string
name|convertConstraint
argument_list|(
argument|const char Constraint
argument_list|)
specifier|const
block|{
comment|// 'p' defaults to 'r', but can be overridden by targets.
if|if
condition|(
name|Constraint
operator|==
literal|'p'
condition|)
return|return
name|std
operator|::
name|string
argument_list|(
literal|"r"
argument_list|)
return|;
return|return
name|std
operator|::
name|string
argument_list|(
literal|1
argument_list|,
name|Constraint
argument_list|)
return|;
block|}
comment|// Returns a string of target-specific clobbers, in LLVM format.
name|virtual
specifier|const
name|char
operator|*
name|getClobbers
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// getTriple - Return the target triple of the primary target.
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|getTriple
argument_list|()
specifier|const
block|{
return|return
name|Triple
return|;
block|}
specifier|const
name|char
operator|*
name|getTargetDescription
argument_list|()
specifier|const
block|{
return|return
name|DescriptionString
return|;
block|}
expr|struct
name|GCCRegAlias
block|{
specifier|const
name|char
operator|*
specifier|const
name|Aliases
index|[
literal|5
index|]
block|;
specifier|const
name|char
operator|*
specifier|const
name|Register
block|;   }
block|;
name|virtual
name|bool
name|useGlobalsForAutomaticVariables
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// getCFStringSection - Return the section to use for CFString
comment|/// literals, or 0 if no special section is used.
name|virtual
specifier|const
name|char
operator|*
name|getCFStringSection
argument_list|()
specifier|const
block|{
return|return
literal|"__DATA,__cfstring"
return|;
block|}
comment|/// getNSStringSection - Return the section to use for NSString
comment|/// literals, or 0 if no special section is used.
name|virtual
specifier|const
name|char
operator|*
name|getNSStringSection
argument_list|()
specifier|const
block|{
return|return
literal|"__OBJC,__cstring_object,regular,no_dead_strip"
return|;
block|}
comment|/// getNSStringNonFragileABISection - Return the section to use for
comment|/// NSString literals, or 0 if no special section is used (NonFragile ABI).
name|virtual
specifier|const
name|char
operator|*
name|getNSStringNonFragileABISection
argument_list|()
specifier|const
block|{
return|return
literal|"__DATA, __objc_stringobj, regular, no_dead_strip"
return|;
block|}
comment|/// isValidSectionSpecifier - This is an optional hook that targets can
comment|/// implement to perform semantic checking on attribute((section("foo")))
comment|/// specifiers.  In this case, "foo" is passed in to be checked.  If the
comment|/// section specifier is invalid, the backend should return a non-empty string
comment|/// that indicates the problem.
comment|///
comment|/// This hook is a simple quality of implementation feature to catch errors
comment|/// and give good diagnostics in cases when the assembler or code generator
comment|/// would otherwise reject the section specifier.
comment|///
name|virtual
name|std
operator|::
name|string
name|isValidSectionSpecifier
argument_list|(
argument|llvm::StringRef SR
argument_list|)
specifier|const
block|{
return|return
literal|""
return|;
block|}
comment|/// setForcedLangOptions - Set forced language options.
comment|/// Apply changes to the target information with respect to certain
comment|/// language options which change the target configuration.
name|virtual
name|void
name|setForcedLangOptions
argument_list|(
name|LangOptions
operator|&
name|Opts
argument_list|)
block|;
comment|/// getDefaultFeatures - Get the default set of target features for
comment|/// the \args CPU; this should include all legal feature strings on
comment|/// the target.
name|virtual
name|void
name|getDefaultFeatures
argument_list|(
argument|const std::string&CPU
argument_list|,
argument|llvm::StringMap<bool>&Features
argument_list|)
specifier|const
block|{   }
comment|/// getABI - Get the ABI in use.
name|virtual
specifier|const
name|char
operator|*
name|getABI
argument_list|()
specifier|const
block|{
return|return
literal|""
return|;
block|}
comment|/// getCXXABI - Get the C++ ABI in use.
name|virtual
name|TargetCXXABI
name|getCXXABI
argument_list|()
specifier|const
block|{
return|return
name|CXXABI
return|;
block|}
comment|/// setCPU - Target the specific CPU.
comment|///
comment|/// \return - False on error (invalid CPU name).
comment|//
comment|// FIXME: Remove this.
name|virtual
name|bool
name|setCPU
argument_list|(
argument|const std::string&Name
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|/// setABI - Use the specific ABI.
comment|///
comment|/// \return - False on error (invalid ABI name).
name|virtual
name|bool
name|setABI
argument_list|(
argument|const std::string&Name
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// setCXXABI - Use this specific C++ ABI.
comment|///
comment|/// \return - False on error (invalid C++ ABI name).
name|bool
name|setCXXABI
argument_list|(
argument|const std::string&Name
argument_list|)
block|{
specifier|static
specifier|const
name|TargetCXXABI
name|Unknown
operator|=
name|static_cast
operator|<
name|TargetCXXABI
operator|>
operator|(
operator|-
literal|1
operator|)
block|;
name|TargetCXXABI
name|ABI
operator|=
name|llvm
operator|::
name|StringSwitch
operator|<
name|TargetCXXABI
operator|>
operator|(
name|Name
operator|)
operator|.
name|Case
argument_list|(
literal|"arm"
argument_list|,
name|CXXABI_ARM
argument_list|)
operator|.
name|Case
argument_list|(
literal|"itanium"
argument_list|,
name|CXXABI_Itanium
argument_list|)
operator|.
name|Case
argument_list|(
literal|"microsoft"
argument_list|,
name|CXXABI_Microsoft
argument_list|)
operator|.
name|Default
argument_list|(
name|Unknown
argument_list|)
block|;
if|if
condition|(
name|ABI
operator|==
name|Unknown
condition|)
return|return
name|false
return|;
return|return
name|setCXXABI
argument_list|(
name|ABI
argument_list|)
return|;
block|}
comment|/// setCXXABI - Set the C++ ABI to be used by this implementation.
comment|///
comment|/// \return - False on error (ABI not valid on this target)
name|virtual
name|bool
name|setCXXABI
parameter_list|(
name|TargetCXXABI
name|ABI
parameter_list|)
block|{
name|CXXABI
operator|=
name|ABI
expr_stmt|;
return|return
name|true
return|;
block|}
comment|/// setFeatureEnabled - Enable or disable a specific target feature,
comment|/// the feature name must be valid.
comment|///
comment|/// \return - False on error (invalid feature name).
name|virtual
name|bool
name|setFeatureEnabled
argument_list|(
name|llvm
operator|::
name|StringMap
operator|<
name|bool
operator|>
operator|&
name|Features
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|,
name|bool
name|Enabled
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// HandleTargetOptions - Perform initialization based on the user configured
comment|/// set of features (e.g., +sse4). The list is guaranteed to have at most one
comment|/// entry per feature.
comment|///
comment|/// The target may modify the features list, to change which options are
comment|/// passed onwards to the backend.
name|virtual
name|void
name|HandleTargetFeatures
argument_list|(
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|Features
argument_list|)
block|{   }
comment|// getRegParmMax - Returns maximal number of args passed in registers.
name|unsigned
name|getRegParmMax
argument_list|()
specifier|const
block|{
return|return
name|RegParmMax
return|;
block|}
comment|/// isTLSSupported - Whether the target supports thread-local storage.
name|bool
name|isTLSSupported
argument_list|()
specifier|const
block|{
return|return
name|TLSSupported
return|;
block|}
comment|/// hasNoAsmVariants - Return true if {|} are normal characters in the
comment|/// asm string.  If this returns false (the default), then {abc|xyz} is syntax
comment|/// that says that when compiling for asm variant #0, "abc" should be
comment|/// generated, but when compiling for asm variant #1, "xyz" should be
comment|/// generated.
name|bool
name|hasNoAsmVariants
argument_list|()
specifier|const
block|{
return|return
name|NoAsmVariants
return|;
block|}
comment|/// getEHDataRegisterNumber - Return the register number that
comment|/// __builtin_eh_return_regno would return with the specified argument.
name|virtual
name|int
name|getEHDataRegisterNumber
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
return|return
operator|-
literal|1
return|;
block|}
comment|/// getStaticInitSectionSpecifier - Return the section to use for C++ static
comment|/// initialization functions.
name|virtual
specifier|const
name|char
operator|*
name|getStaticInitSectionSpecifier
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
specifier|const
name|LangAS
operator|::
name|Map
operator|&
name|getAddressSpaceMap
argument_list|()
specifier|const
block|{
return|return
operator|*
name|AddrSpaceMap
return|;
block|}
comment|/// \brief Retrieve the name of the platform as it is used in the
comment|/// availability attribute.
name|llvm
operator|::
name|StringRef
name|getPlatformName
argument_list|()
specifier|const
block|{
return|return
name|PlatformName
return|;
block|}
comment|/// \brief Retrieve the minimum desired version of the platform, to
comment|/// which the program should be compiled.
name|VersionTuple
name|getPlatformMinVersion
argument_list|()
specifier|const
block|{
return|return
name|PlatformMinVersion
return|;
block|}
name|protected
label|:
name|virtual
name|uint64_t
name|getPointerWidthV
argument_list|(
name|unsigned
name|AddrSpace
argument_list|)
decl|const
block|{
return|return
name|PointerWidth
return|;
block|}
name|virtual
name|uint64_t
name|getPointerAlignV
argument_list|(
name|unsigned
name|AddrSpace
argument_list|)
decl|const
block|{
return|return
name|PointerAlign
return|;
block|}
name|virtual
name|enum
name|IntType
name|getPtrDiffTypeV
argument_list|(
name|unsigned
name|AddrSpace
argument_list|)
decl|const
block|{
return|return
name|PtrDiffType
return|;
block|}
name|virtual
name|void
name|getGCCRegNames
argument_list|(
specifier|const
name|char
operator|*
specifier|const
operator|*
operator|&
name|Names
argument_list|,
name|unsigned
operator|&
name|NumNames
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|getGCCRegAliases
argument_list|(
specifier|const
name|GCCRegAlias
operator|*
operator|&
name|Aliases
argument_list|,
name|unsigned
operator|&
name|NumAliases
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|bool
name|validateAsmConstraint
argument_list|(
specifier|const
name|char
operator|*
operator|&
name|Name
argument_list|,
name|TargetInfo
operator|::
name|ConstraintInfo
operator|&
name|info
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

