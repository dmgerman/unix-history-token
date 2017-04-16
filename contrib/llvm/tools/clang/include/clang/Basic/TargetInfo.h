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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines the clang::TargetInfo interface.
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
file|"clang/Basic/AddressSpaces.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Specifiers.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/TargetCXXABI.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/TargetOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/VersionTuple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/APInt.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
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
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DataLayout.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
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
name|DiagnosticsEngine
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|CodeGenOptions
decl_stmt|;
name|class
name|MacroBuilder
decl_stmt|;
name|class
name|QualType
decl_stmt|;
name|class
name|SourceLocation
decl_stmt|;
name|class
name|SourceManager
decl_stmt|;
name|namespace
name|Builtin
block|{
struct_decl|struct
name|Info
struct_decl|;
block|}
comment|/// \brief Exposes information about the current target.
comment|///
name|class
name|TargetInfo
range|:
name|public
name|RefCountedBase
operator|<
name|TargetInfo
operator|>
block|{
name|std
operator|::
name|shared_ptr
operator|<
name|TargetOptions
operator|>
name|TargetOpts
block|;
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
name|BigEndian
block|;
name|bool
name|TLSSupported
block|;
name|bool
name|NoAsmVariants
block|;
comment|// True if {|} are normal characters.
name|bool
name|HasFloat128
block|;
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
name|HalfWidth
block|,
name|HalfAlign
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
block|,
name|Float128Align
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
name|unsigned
name|char
name|SuitableAlign
block|;
name|unsigned
name|char
name|DefaultAlignForAttributeAligned
block|;
name|unsigned
name|char
name|MinGlobalAlign
block|;
name|unsigned
name|char
name|MaxAtomicPromoteWidth
block|,
name|MaxAtomicInlineWidth
block|;
name|unsigned
name|short
name|MaxVectorAlign
block|;
name|unsigned
name|short
name|MaxTLSAlign
block|;
name|unsigned
name|short
name|SimdDefaultAlign
block|;
name|unsigned
name|short
name|NewAlign
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|DataLayout
operator|>
name|DataLayout
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
name|HalfFormat
block|,
operator|*
name|FloatFormat
block|,
operator|*
name|DoubleFormat
block|,
operator|*
name|LongDoubleFormat
block|,
operator|*
name|Float128Format
block|;
name|unsigned
name|char
name|RegParmMax
block|,
name|SSERegParmMax
block|;
name|TargetCXXABI
name|TheCXXABI
block|;
specifier|const
name|LangAS
operator|::
name|Map
operator|*
name|AddrSpaceMap
block|;
name|mutable
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
name|unsigned
name|ComplexLongDoubleUsesFP2Ret
operator|:
literal|1
block|;
name|unsigned
name|HasBuiltinMSVaList
operator|:
literal|1
block|;
name|unsigned
name|IsRenderScriptTarget
operator|:
literal|1
block|;
comment|// TargetInfo Constructor.  Default initializes all fields.
name|TargetInfo
argument_list|(
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|T
argument_list|)
block|;
name|void
name|resetDataLayout
argument_list|(
argument|StringRef DL
argument_list|)
block|{
name|DataLayout
operator|.
name|reset
argument_list|(
argument|new llvm::DataLayout(DL)
argument_list|)
block|;   }
name|public
operator|:
comment|/// \brief Construct a target for the given options.
comment|///
comment|/// \param Opts - The options to use to initialize the target. The target may
comment|/// modify the options to canonicalize the target feature information to match
comment|/// what the backend expects.
specifier|static
name|TargetInfo
operator|*
name|CreateTargetInfo
argument_list|(
name|DiagnosticsEngine
operator|&
name|Diags
argument_list|,
specifier|const
name|std
operator|::
name|shared_ptr
operator|<
name|TargetOptions
operator|>
operator|&
name|Opts
argument_list|)
block|;
name|virtual
operator|~
name|TargetInfo
argument_list|()
block|;
comment|/// \brief Retrieve the target options.
name|TargetOptions
operator|&
name|getTargetOpts
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|TargetOpts
operator|&&
literal|"Missing target options"
argument_list|)
block|;
return|return
operator|*
name|TargetOpts
return|;
block|}
comment|///===---- Target Data Type Query Methods -------------------------------===//
expr|enum
name|IntType
block|{
name|NoInt
operator|=
literal|0
block|,
name|SignedChar
block|,
name|UnsignedChar
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
name|NoFloat
operator|=
literal|255
block|,
name|Float
operator|=
literal|0
block|,
name|Double
block|,
name|LongDouble
block|,
name|Float128
block|}
block|;
comment|/// \brief The different kinds of __builtin_va_list types defined by
comment|/// the target implementation.
block|enum
name|BuiltinVaListKind
block|{
comment|/// typedef char* __builtin_va_list;
name|CharPtrBuiltinVaList
operator|=
literal|0
block|,
comment|/// typedef void* __builtin_va_list;
name|VoidPtrBuiltinVaList
block|,
comment|/// __builtin_va_list as defined by the AArch64 ABI
comment|/// http://infocenter.arm.com/help/topic/com.arm.doc.ihi0055a/IHI0055A_aapcs64.pdf
name|AArch64ABIBuiltinVaList
block|,
comment|/// __builtin_va_list as defined by the PNaCl ABI:
comment|/// http://www.chromium.org/nativeclient/pnacl/bitcode-abi#TOC-Machine-Types
name|PNaClABIBuiltinVaList
block|,
comment|/// __builtin_va_list as defined by the Power ABI:
comment|/// https://www.power.org
comment|///        /resources/downloads/Power-Arch-32-bit-ABI-supp-1.0-Embedded.pdf
name|PowerABIBuiltinVaList
block|,
comment|/// __builtin_va_list as defined by the x86-64 ABI:
comment|/// http://refspecs.linuxbase.org/elf/x86_64-abi-0.21.pdf
name|X86_64ABIBuiltinVaList
block|,
comment|/// __builtin_va_list as defined by ARM AAPCS ABI
comment|/// http://infocenter.arm.com
comment|//        /help/topic/com.arm.doc.ihi0042d/IHI0042D_aapcs.pdf
name|AAPCSABIBuiltinVaList
block|,
comment|// typedef struct __va_list_tag
comment|//   {
comment|//     long __gpr;
comment|//     long __fpr;
comment|//     void *__overflow_arg_area;
comment|//     void *__reg_save_area;
comment|//   } va_list[1];
name|SystemZBuiltinVaList
block|}
block|;
name|protected
operator|:
name|IntType
name|SizeType
block|,
name|IntMaxType
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
block|,
name|ProcessIDType
block|;
comment|/// \brief Whether Objective-C's built-in boolean type should be signed char.
comment|///
comment|/// Otherwise, when this flag is not set, the normal built-in boolean type is
comment|/// used.
name|unsigned
name|UseSignedCharForObjCBool
operator|:
literal|1
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
comment|/// \brief Whether zero length bitfields (e.g., int : 0;) force alignment of
comment|/// the next bitfield.
comment|///
comment|/// If the alignment of the zero length bitfield is greater than the member
comment|/// that follows it, `bar', `bar' will be aligned as the type of the
comment|/// zero-length bitfield.
name|unsigned
name|UseZeroLengthBitfieldAlignment
operator|:
literal|1
block|;
comment|/// \brief  Whether explicit bit field alignment attributes are honored.
name|unsigned
name|UseExplicitBitFieldAlignment
operator|:
literal|1
block|;
comment|/// If non-zero, specifies a fixed alignment value for bitfields that follow
comment|/// zero length bitfield, regardless of the zero length bitfield type.
name|unsigned
name|ZeroLengthBitfieldBoundary
block|;
comment|/// \brief Specify if mangling based on address space map should be used or
comment|/// not for language specific address spaces
name|bool
name|UseAddrSpaceMapMangling
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
name|getCorrespondingUnsignedType
argument_list|(
name|IntMaxType
argument_list|)
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
name|getUIntPtrType
argument_list|()
specifier|const
block|{
return|return
name|getCorrespondingUnsignedType
argument_list|(
name|IntPtrType
argument_list|)
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
name|getUInt64Type
argument_list|()
specifier|const
block|{
return|return
name|getCorrespondingUnsignedType
argument_list|(
name|Int64Type
argument_list|)
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
name|IntType
name|getProcessIDType
argument_list|()
specifier|const
block|{
return|return
name|ProcessIDType
return|;
block|}
specifier|static
name|IntType
name|getCorrespondingUnsignedType
argument_list|(
argument|IntType T
argument_list|)
block|{
switch|switch
condition|(
name|T
condition|)
block|{
case|case
name|SignedChar
case|:
return|return
name|UnsignedChar
return|;
case|case
name|SignedShort
case|:
return|return
name|UnsignedShort
return|;
case|case
name|SignedInt
case|:
return|return
name|UnsignedInt
return|;
case|case
name|SignedLong
case|:
return|return
name|UnsignedLong
return|;
case|case
name|SignedLongLong
case|:
return|return
name|UnsignedLongLong
return|;
default|default:
name|llvm_unreachable
argument_list|(
literal|"Unexpected signed integer type"
argument_list|)
expr_stmt|;
block|}
block|}
comment|/// \brief Return the width (in bits) of the specified integer type enum.
comment|///
comment|/// For example, SignedInt -> getIntWidth().
name|unsigned
name|getTypeWidth
argument_list|(
argument|IntType T
argument_list|)
specifier|const
block|;
comment|/// \brief Return integer type with specified width.
name|virtual
name|IntType
name|getIntTypeByWidth
argument_list|(
argument|unsigned BitWidth
argument_list|,
argument|bool IsSigned
argument_list|)
specifier|const
block|;
comment|/// \brief Return the smallest integer type with at least the specified width.
name|virtual
name|IntType
name|getLeastIntTypeByWidth
argument_list|(
argument|unsigned BitWidth
argument_list|,
argument|bool IsSigned
argument_list|)
specifier|const
block|;
comment|/// \brief Return floating point type with specified width.
name|RealType
name|getRealTypeByWidth
argument_list|(
argument|unsigned BitWidth
argument_list|)
specifier|const
block|;
comment|/// \brief Return the alignment (in bits) of the specified integer type enum.
comment|///
comment|/// For example, SignedInt -> getIntAlign().
name|unsigned
name|getTypeAlign
argument_list|(
argument|IntType T
argument_list|)
specifier|const
block|;
comment|/// \brief Returns true if the type is signed; false otherwise.
specifier|static
name|bool
name|isTypeSigned
argument_list|(
argument|IntType T
argument_list|)
block|;
comment|/// \brief Return the width of pointers on this target, for the
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
operator|?
name|PointerWidth
operator|:
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
comment|/// \brief Return the maximum width of pointers on this target.
name|virtual
name|uint64_t
name|getMaxPointerWidth
argument_list|()
specifier|const
block|{
return|return
name|PointerWidth
return|;
block|}
comment|/// \brief Get integer value for null pointer.
comment|/// \param AddrSpace address space of pointee in source language.
name|virtual
name|uint64_t
name|getNullPointerValue
argument_list|(
argument|unsigned AddrSpace
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// \brief Return the size of '_Bool' and C++ 'bool' for this target, in bits.
name|unsigned
name|getBoolWidth
argument_list|()
specifier|const
block|{
return|return
name|BoolWidth
return|;
block|}
comment|/// \brief Return the alignment of '_Bool' and C++ 'bool' for this target.
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
comment|/// \brief Return the size of 'signed short' and 'unsigned short' for this
comment|/// target, in bits.
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
comment|/// \brief Return the alignment of 'signed short' and 'unsigned short' for
comment|/// this target.
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
comment|/// \brief Determine whether the __int128 type is supported on this target.
name|virtual
name|bool
name|hasInt128Type
argument_list|()
specifier|const
block|{
return|return
name|getPointerWidth
argument_list|(
literal|0
argument_list|)
operator|>=
literal|64
return|;
block|}
comment|// FIXME
comment|/// \brief Determine whether the __float128 type is supported on this target.
name|virtual
name|bool
name|hasFloat128Type
argument_list|()
specifier|const
block|{
return|return
name|HasFloat128
return|;
block|}
comment|/// \brief Return the alignment that is suitable for storing any
comment|/// object with a fundamental alignment requirement.
name|unsigned
name|getSuitableAlign
argument_list|()
specifier|const
block|{
return|return
name|SuitableAlign
return|;
block|}
comment|/// \brief Return the default alignment for __attribute__((aligned)) on
comment|/// this target, to be used if no alignment value is specified.
name|unsigned
name|getDefaultAlignForAttributeAligned
argument_list|()
specifier|const
block|{
return|return
name|DefaultAlignForAttributeAligned
return|;
block|}
comment|/// getMinGlobalAlign - Return the minimum alignment of a global variable,
comment|/// unless its alignment is explicitly reduced via attributes.
name|unsigned
name|getMinGlobalAlign
argument_list|()
specifier|const
block|{
return|return
name|MinGlobalAlign
return|;
block|}
comment|/// Return the largest alignment for which a suitably-sized allocation with
comment|/// '::operator new(size_t)' is guaranteed to produce a correctly-aligned
comment|/// pointer.
name|unsigned
name|getNewAlign
argument_list|()
specifier|const
block|{
return|return
name|NewAlign
condition|?
name|NewAlign
else|:
name|std
operator|::
name|max
argument_list|(
name|LongDoubleAlign
argument_list|,
name|LongLongAlign
argument_list|)
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
comment|/// getHalfWidth/Align/Format - Return the size/align/format of 'half'.
name|unsigned
name|getHalfWidth
argument_list|()
specifier|const
block|{
return|return
name|HalfWidth
return|;
block|}
name|unsigned
name|getHalfAlign
argument_list|()
specifier|const
block|{
return|return
name|HalfAlign
return|;
block|}
specifier|const
name|llvm
operator|::
name|fltSemantics
operator|&
name|getHalfFormat
argument_list|()
specifier|const
block|{
return|return
operator|*
name|HalfFormat
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
comment|/// getFloat128Width/Align/Format - Return the size/align/format of
comment|/// '__float128'.
name|unsigned
name|getFloat128Width
argument_list|()
specifier|const
block|{
return|return
literal|128
return|;
block|}
name|unsigned
name|getFloat128Align
argument_list|()
specifier|const
block|{
return|return
name|Float128Align
return|;
block|}
specifier|const
name|llvm
operator|::
name|fltSemantics
operator|&
name|getFloat128Format
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Float128Format
return|;
block|}
comment|/// \brief Return true if the 'long double' type should be mangled like
comment|/// __float128.
name|virtual
name|bool
name|useFloat128ManglingForLongDouble
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Return the value for the C99 FLT_EVAL_METHOD macro.
name|virtual
name|unsigned
name|getFloatEvalMethod
argument_list|()
specifier|const
block|{
return|return
literal|0
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
comment|/// \brief Return the maximum width lock-free atomic operation which will
comment|/// ever be supported for the given target
name|unsigned
name|getMaxAtomicPromoteWidth
argument_list|()
specifier|const
block|{
return|return
name|MaxAtomicPromoteWidth
return|;
block|}
comment|/// \brief Return the maximum width lock-free atomic operation which can be
comment|/// inlined given the supported features of the given target.
name|unsigned
name|getMaxAtomicInlineWidth
argument_list|()
specifier|const
block|{
return|return
name|MaxAtomicInlineWidth
return|;
block|}
comment|/// \brief Returns true if the given target supports lock-free atomic
comment|/// operations at the specified width and alignment.
name|virtual
name|bool
name|hasBuiltinAtomic
argument_list|(
argument|uint64_t AtomicSizeInBits
argument_list|,
argument|uint64_t AlignmentInBits
argument_list|)
specifier|const
block|{
return|return
name|AtomicSizeInBits
operator|<=
name|AlignmentInBits
operator|&&
name|AtomicSizeInBits
operator|<=
name|getMaxAtomicInlineWidth
argument_list|()
operator|&&
operator|(
name|AtomicSizeInBits
operator|<=
name|getCharWidth
argument_list|()
operator|||
name|llvm
operator|::
name|isPowerOf2_64
argument_list|(
name|AtomicSizeInBits
operator|/
name|getCharWidth
argument_list|()
argument_list|)
operator|)
return|;
block|}
comment|/// \brief Return the maximum vector alignment supported for the given target.
name|unsigned
name|getMaxVectorAlign
argument_list|()
specifier|const
block|{
return|return
name|MaxVectorAlign
return|;
block|}
comment|/// \brief Return default simd alignment for the given target. Generally, this
comment|/// value is type-specific, but this alignment can be used for most of the
comment|/// types for the given target.
name|unsigned
name|getSimdDefaultAlign
argument_list|()
specifier|const
block|{
return|return
name|SimdDefaultAlign
return|;
block|}
comment|/// Return the alignment (in bits) of the thrown exception object. This is
comment|/// only meaningful for targets that allocate C++ exceptions in a system
comment|/// runtime, such as those using the Itanium C++ ABI.
name|virtual
name|unsigned
name|getExnObjectAlignment
argument_list|()
specifier|const
block|{
comment|// Itanium says that an _Unwind_Exception has to be "double-word"
comment|// aligned (and thus the end of it is also so-aligned), meaning 16
comment|// bytes.  Of course, that was written for the actual Itanium,
comment|// which is a 64-bit platform.  Classically, the ABI doesn't really
comment|// specify the alignment on other platforms, but in practice
comment|// libUnwind declares the struct with __attribute__((aligned)), so
comment|// we assume that alignment here.  (It's generally 16 bytes, but
comment|// some targets overwrite it.)
return|return
name|getDefaultAlignForAttributeAligned
argument_list|()
return|;
block|}
comment|/// \brief Return the size of intmax_t and uintmax_t for this target, in bits.
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
comment|// Return the size of unwind_word for this target.
name|virtual
name|unsigned
name|getUnwindWordWidth
argument_list|()
specifier|const
block|{
return|return
name|getPointerWidth
argument_list|(
literal|0
argument_list|)
return|;
block|}
comment|/// \brief Return the "preferred" register width on this target.
name|virtual
name|unsigned
name|getRegisterWidth
argument_list|()
specifier|const
block|{
comment|// Currently we assume the register width on the target matches the pointer
comment|// width, we can introduce a new variable for this if/when some target wants
comment|// it.
return|return
name|PointerWidth
return|;
block|}
comment|/// \brief Returns the name of the mcount instrumentation function.
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
comment|/// \brief Check if the Objective-C built-in boolean type should be signed
comment|/// char.
comment|///
comment|/// Otherwise, if this returns false, the normal built-in boolean type
comment|/// should also be used for Objective-C.
name|bool
name|useSignedCharForObjCBool
argument_list|()
specifier|const
block|{
return|return
name|UseSignedCharForObjCBool
return|;
block|}
name|void
name|noSignedCharForObjCBool
argument_list|()
block|{
name|UseSignedCharForObjCBool
operator|=
name|false
block|;   }
comment|/// \brief Check whether the alignment of bit-field types is respected
comment|/// when laying out structures.
name|bool
name|useBitFieldTypeAlignment
argument_list|()
specifier|const
block|{
return|return
name|UseBitFieldTypeAlignment
return|;
block|}
comment|/// \brief Check whether zero length bitfields should force alignment of
comment|/// the next member.
name|bool
name|useZeroLengthBitfieldAlignment
argument_list|()
specifier|const
block|{
return|return
name|UseZeroLengthBitfieldAlignment
return|;
block|}
comment|/// \brief Get the fixed alignment value in bits for a member that follows
comment|/// a zero length bitfield.
name|unsigned
name|getZeroLengthBitfieldBoundary
argument_list|()
specifier|const
block|{
return|return
name|ZeroLengthBitfieldBoundary
return|;
block|}
comment|/// \brief Check whether explicit bitfield alignment attributes should be
comment|//  honored, as in "__attribute__((aligned(2))) int b : 1;".
name|bool
name|useExplicitBitFieldAlignment
argument_list|()
specifier|const
block|{
return|return
name|UseExplicitBitFieldAlignment
return|;
block|}
comment|/// \brief Check whether this target support '\#pragma options align=mac68k'.
name|bool
name|hasAlignMac68kSupport
argument_list|()
specifier|const
block|{
return|return
name|HasAlignMac68kSupport
return|;
block|}
comment|/// \brief Return the user string for the specified integer type enum.
comment|///
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
comment|/// \brief Return the constant suffix for the specified integer type enum.
comment|///
comment|/// For example, SignedLong -> "L".
specifier|const
name|char
operator|*
name|getTypeConstantSuffix
argument_list|(
argument|IntType T
argument_list|)
specifier|const
block|;
comment|/// \brief Return the printf format modifier for the specified
comment|/// integer type enum.
comment|///
comment|/// For example, SignedLong -> "l".
specifier|static
specifier|const
name|char
operator|*
name|getTypeFormatModifier
argument_list|(
argument|IntType T
argument_list|)
block|;
comment|/// \brief Check whether the given real type should use the "fpret" flavor of
comment|/// Objective-C message passing on this target.
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
comment|/// \brief Check whether _Complex long double should use the "fp2ret" flavor
comment|/// of Objective-C message passing on this target.
name|bool
name|useObjCFP2RetForComplexLongDouble
argument_list|()
specifier|const
block|{
return|return
name|ComplexLongDoubleUsesFP2Ret
return|;
block|}
comment|/// \brief Specify if mangling based on address space map should be used or
comment|/// not for language specific address spaces
name|bool
name|useAddressSpaceMapMangling
argument_list|()
specifier|const
block|{
return|return
name|UseAddrSpaceMapMangling
return|;
block|}
comment|///===---- Other target property query methods --------------------------===//
comment|/// \brief Appends the target-specific \#define values for this
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
comment|/// Return information about target-specific builtins for
comment|/// the current primary target, and info about which builtins are non-portable
comment|/// across the current set of primary and secondary targets.
name|virtual
name|ArrayRef
operator|<
name|Builtin
operator|::
name|Info
operator|>
name|getTargetBuiltins
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// The __builtin_clz* and __builtin_ctz* built-in
comment|/// functions are specified to have undefined results for zero inputs, but
comment|/// on targets that support these operations in a way that provides
comment|/// well-defined results for zero without loss of performance, it is a good
comment|/// idea to avoid optimizing based on that undef behavior.
name|virtual
name|bool
name|isCLZForZeroUndef
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// \brief Returns the kind of __builtin_va_list type that should be used
comment|/// with this target.
name|virtual
name|BuiltinVaListKind
name|getBuiltinVaListKind
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// Returns whether or not type \c __builtin_ms_va_list type is
comment|/// available on this target.
name|bool
name|hasBuiltinMSVaList
argument_list|()
specifier|const
block|{
return|return
name|HasBuiltinMSVaList
return|;
block|}
comment|/// Returns true for RenderScript.
name|bool
name|isRenderScriptTarget
argument_list|()
specifier|const
block|{
return|return
name|IsRenderScriptTarget
return|;
block|}
comment|/// \brief Returns whether the passed in string is a valid clobber in an
comment|/// inline asm statement.
comment|///
comment|/// This is used by Sema.
name|bool
name|isValidClobber
argument_list|(
argument|StringRef Name
argument_list|)
specifier|const
block|;
comment|/// \brief Returns whether the passed in string is a valid register name
comment|/// according to GCC.
comment|///
comment|/// This is used by Sema for inline asm statements.
name|bool
name|isValidGCCRegisterName
argument_list|(
argument|StringRef Name
argument_list|)
specifier|const
block|;
comment|/// \brief Returns the "normalized" GCC register name.
comment|///
comment|/// ReturnCannonical true will return the register name without any additions
comment|/// such as "{}" or "%" in it's canonical form, for example:
comment|/// ReturnCanonical = true and Name = "rax", will return "ax".
name|StringRef
name|getNormalizedGCCRegisterName
argument_list|(
argument|StringRef Name
argument_list|,
argument|bool ReturnCanonical = false
argument_list|)
specifier|const
block|;
name|virtual
name|StringRef
name|getConstraintRegister
argument_list|(
argument|const StringRef&Constraint
argument_list|,
argument|const StringRef&Expression
argument_list|)
specifier|const
block|{
return|return
literal|""
return|;
block|}
expr|struct
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
block|,
comment|// This output operand has a matching input.
name|CI_ImmediateConstant
operator|=
literal|0x10
block|,
comment|// This operand must be an immediate constant
name|CI_EarlyClobber
operator|=
literal|0x20
block|,
comment|// "&" output constraint (early clobber).
block|}
block|;
name|unsigned
name|Flags
block|;
name|int
name|TiedOperand
block|;     struct
block|{
name|int
name|Min
block|;
name|int
name|Max
block|;     }
name|ImmRange
block|;
name|llvm
operator|::
name|SmallSet
operator|<
name|int
block|,
literal|4
operator|>
name|ImmSet
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
argument|StringRef ConstraintStr
argument_list|,
argument|StringRef Name
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
block|{
name|ImmRange
operator|.
name|Min
operator|=
name|ImmRange
operator|.
name|Max
operator|=
literal|0
block|;     }
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
name|earlyClobber
argument_list|()
block|{
return|return
operator|(
name|Flags
operator|&
name|CI_EarlyClobber
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
comment|/// \brief Return true if this output operand has a matching
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
comment|/// \brief Return true if this input operand is a matching
comment|/// constraint that ties it to an output operand.
comment|///
comment|/// If this returns true then getTiedOperand will indicate which output
comment|/// operand this is tied to.
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
name|bool
name|requiresImmediateConstant
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Flags
operator|&
name|CI_ImmediateConstant
operator|)
operator|!=
literal|0
return|;
block|}
name|bool
name|isValidAsmImmediate
argument_list|(
argument|const llvm::APInt&Value
argument_list|)
specifier|const
block|{
return|return
operator|(
name|Value
operator|.
name|sge
argument_list|(
name|ImmRange
operator|.
name|Min
argument_list|)
operator|&&
name|Value
operator|.
name|sle
argument_list|(
name|ImmRange
operator|.
name|Max
argument_list|)
operator|)
operator|||
name|ImmSet
operator|.
name|count
argument_list|(
name|Value
operator|.
name|getZExtValue
argument_list|()
argument_list|)
operator|!=
literal|0
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
name|setEarlyClobber
argument_list|()
block|{
name|Flags
operator||=
name|CI_EarlyClobber
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
name|void
name|setRequiresImmediate
argument_list|(
argument|int Min
argument_list|,
argument|int Max
argument_list|)
block|{
name|Flags
operator||=
name|CI_ImmediateConstant
block|;
name|ImmRange
operator|.
name|Min
operator|=
name|Min
block|;
name|ImmRange
operator|.
name|Max
operator|=
name|Max
block|;     }
name|void
name|setRequiresImmediate
argument_list|(
argument|llvm::ArrayRef<int> Exacts
argument_list|)
block|{
name|Flags
operator||=
name|CI_ImmediateConstant
block|;
for|for
control|(
name|int
name|Exact
range|:
name|Exacts
control|)
name|ImmSet
operator|.
name|insert
argument_list|(
name|Exact
argument_list|)
expr_stmt|;
block|}
name|void
name|setRequiresImmediate
argument_list|(
argument|int Exact
argument_list|)
block|{
name|Flags
operator||=
name|CI_ImmediateConstant
block|;
name|ImmSet
operator|.
name|insert
argument_list|(
name|Exact
argument_list|)
block|;     }
name|void
name|setRequiresImmediate
argument_list|()
block|{
name|Flags
operator||=
name|CI_ImmediateConstant
block|;
name|ImmRange
operator|.
name|Min
operator|=
name|INT_MIN
block|;
name|ImmRange
operator|.
name|Max
operator|=
name|INT_MAX
block|;     }
comment|/// \brief Indicate that this is an input operand that is tied to
comment|/// the specified output operand.
comment|///
comment|/// Copy over the various constraint information from the output.
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
comment|/// \brief Validate register name used for global register variables.
comment|///
comment|/// This function returns true if the register passed in RegName can be used
comment|/// for global register variables on this target. In addition, it returns
comment|/// true in HasSizeMismatch if the size of the register doesn't match the
comment|/// variable size passed in RegSize.
name|virtual
name|bool
name|validateGlobalRegisterVariable
argument_list|(
argument|StringRef RegName
argument_list|,
argument|unsigned RegSize
argument_list|,
argument|bool&HasSizeMismatch
argument_list|)
specifier|const
block|{
name|HasSizeMismatch
operator|=
name|false
block|;
return|return
name|true
return|;
block|}
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
argument|MutableArrayRef<ConstraintInfo> OutputConstraints
argument_list|,
argument|ConstraintInfo&info
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|validateOutputSize
argument_list|(
argument|StringRef
comment|/*Constraint*/
argument_list|,
argument|unsigned
comment|/*Size*/
argument_list|)
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
name|bool
name|validateInputSize
argument_list|(
argument|StringRef
comment|/*Constraint*/
argument_list|,
argument|unsigned
comment|/*Size*/
argument_list|)
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
name|bool
name|validateConstraintModifier
argument_list|(
argument|StringRef
comment|/*Constraint*/
argument_list|,
argument|char
comment|/*Modifier*/
argument_list|,
argument|unsigned
comment|/*Size*/
argument_list|,
argument|std::string&
comment|/*SuggestedModifier*/
argument_list|)
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
name|bool
name|validateAsmConstraint
argument_list|(
argument|const char *&Name
argument_list|,
argument|TargetInfo::ConstraintInfo&info
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|bool
name|resolveSymbolicName
argument_list|(
argument|const char *&Name
argument_list|,
argument|ArrayRef<ConstraintInfo> OutputConstraints
argument_list|,
argument|unsigned&Index
argument_list|)
specifier|const
block|;
comment|// Constraint parm will be left pointing at the last character of
comment|// the constraint.  In practice, it won't be changed unless the
comment|// constraint is longer than one character.
name|virtual
name|std
operator|::
name|string
name|convertConstraint
argument_list|(
argument|const char *&Constraint
argument_list|)
specifier|const
block|{
comment|// 'p' defaults to 'r', but can be overridden by targets.
if|if
condition|(
operator|*
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
operator|*
name|Constraint
argument_list|)
return|;
block|}
comment|/// \brief Returns a string of target-specific clobbers, in LLVM format.
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
comment|/// \brief Returns true if NaN encoding is IEEE 754-2008.
comment|/// Only MIPS allows a different encoding.
name|virtual
name|bool
name|isNan2008
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// \brief Returns the target triple of the primary target.
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
name|llvm
operator|::
name|DataLayout
operator|&
name|getDataLayout
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|DataLayout
operator|&&
literal|"Uninitialized DataLayout!"
argument_list|)
block|;
return|return
operator|*
name|DataLayout
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
block|;    struct
name|AddlRegName
block|{
specifier|const
name|char
operator|*
specifier|const
name|Names
index|[
literal|5
index|]
block|;
specifier|const
name|unsigned
name|RegNum
block|;   }
block|;
comment|/// \brief Does this target support "protected" visibility?
comment|///
comment|/// Any target which dynamic libraries will naturally support
comment|/// something like "default" (meaning that the symbol is visible
comment|/// outside this shared object) and "hidden" (meaning that it isn't)
comment|/// visibilities, but "protected" is really an ELF-specific concept
comment|/// with weird semantics designed around the convenience of dynamic
comment|/// linker implementations.  Which is not to suggest that there's
comment|/// consistent target-independent semantics for "default" visibility
comment|/// either; the entire thing is pretty badly mangled.
name|virtual
name|bool
name|hasProtectedVisibility
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// \brief An optional hook that targets can implement to perform semantic
comment|/// checking on attribute((section("foo"))) specifiers.
comment|///
comment|/// In this case, "foo" is passed in to be checked.  If the section
comment|/// specifier is invalid, the backend should return a non-empty string
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
argument|StringRef SR
argument_list|)
specifier|const
block|{
return|return
literal|""
return|;
block|}
comment|/// \brief Set forced language options.
comment|///
comment|/// Apply changes to the target information with respect to certain
comment|/// language options which change the target configuration and adjust
comment|/// the language based on the target options where applicable.
name|virtual
name|void
name|adjust
argument_list|(
name|LangOptions
operator|&
name|Opts
argument_list|)
block|;
comment|/// \brief Adjust target options based on codegen options.
name|virtual
name|void
name|adjustTargetOptions
argument_list|(
argument|const CodeGenOptions&CGOpts
argument_list|,
argument|TargetOptions&TargetOpts
argument_list|)
specifier|const
block|{}
comment|/// \brief Initialize the map with the default set of target features for the
comment|/// CPU this should include all legal feature strings on the target.
comment|///
comment|/// \return False on error (invalid features).
name|virtual
name|bool
name|initFeatureMap
argument_list|(
argument|llvm::StringMap<bool>&Features
argument_list|,
argument|DiagnosticsEngine&Diags
argument_list|,
argument|StringRef CPU
argument_list|,
argument|const std::vector<std::string>&FeatureVec
argument_list|)
specifier|const
block|;
comment|/// \brief Get the ABI currently in use.
name|virtual
name|StringRef
name|getABI
argument_list|()
specifier|const
block|{
return|return
name|StringRef
argument_list|()
return|;
block|}
comment|/// \brief Get the C++ ABI currently in use.
name|TargetCXXABI
name|getCXXABI
argument_list|()
specifier|const
block|{
return|return
name|TheCXXABI
return|;
block|}
comment|/// \brief Target the specified CPU.
comment|///
comment|/// \return  False on error (invalid CPU name).
name|virtual
name|bool
name|setCPU
argument_list|(
argument|const std::string&Name
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Use the specified ABI.
comment|///
comment|/// \return False on error (invalid ABI name).
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
comment|/// \brief Use the specified unit for FP math.
comment|///
comment|/// \return False on error (invalid unit name).
name|virtual
name|bool
name|setFPMath
argument_list|(
argument|StringRef Name
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Enable or disable a specific target feature;
comment|/// the feature name must be valid.
name|virtual
name|void
name|setFeatureEnabled
argument_list|(
argument|llvm::StringMap<bool>&Features
argument_list|,
argument|StringRef Name
argument_list|,
argument|bool Enabled
argument_list|)
specifier|const
block|{
name|Features
index|[
name|Name
index|]
operator|=
name|Enabled
block|;   }
comment|/// \brief Perform initialization based on the user configured
comment|/// set of features (e.g., +sse4).
comment|///
comment|/// The list is guaranteed to have at most one entry per feature.
comment|///
comment|/// The target may modify the features list, to change which options are
comment|/// passed onwards to the backend.
comment|/// FIXME: This part should be fixed so that we can change handleTargetFeatures
comment|/// to merely a TargetInfo initialization routine.
comment|///
comment|/// \return  False on error.
name|virtual
name|bool
name|handleTargetFeatures
argument_list|(
argument|std::vector<std::string>&Features
argument_list|,
argument|DiagnosticsEngine&Diags
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|/// \brief Determine whether the given target has the given feature.
name|virtual
name|bool
name|hasFeature
argument_list|(
argument|StringRef Feature
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|// \brief Validate the contents of the __builtin_cpu_supports(const char*)
comment|// argument.
name|virtual
name|bool
name|validateCpuSupports
argument_list|(
argument|StringRef Name
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|// \brief Returns maximal number of args passed in registers.
name|unsigned
name|getRegParmMax
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|RegParmMax
operator|<
literal|7
operator|&&
literal|"RegParmMax value is larger than AST can handle"
argument_list|)
block|;
return|return
name|RegParmMax
return|;
block|}
comment|/// \brief Whether the target supports thread-local storage.
name|bool
name|isTLSSupported
argument_list|()
specifier|const
block|{
return|return
name|TLSSupported
return|;
block|}
comment|/// \brief Return the maximum alignment (in bits) of a TLS variable
comment|///
comment|/// Gets the maximum alignment (in bits) of a TLS variable on this target.
comment|/// Returns zero if there is no such constraint.
name|unsigned
name|short
name|getMaxTLSAlign
argument_list|()
specifier|const
block|{
return|return
name|MaxTLSAlign
return|;
block|}
comment|/// \brief Whether the target supports SEH __try.
name|bool
name|isSEHTrySupported
argument_list|()
specifier|const
block|{
return|return
name|getTriple
argument_list|()
operator|.
name|isOSWindows
argument_list|()
operator|&&
operator|(
name|getTriple
argument_list|()
operator|.
name|getArch
argument_list|()
operator|==
name|llvm
operator|::
name|Triple
operator|::
name|x86
operator|||
name|getTriple
argument_list|()
operator|.
name|getArch
argument_list|()
operator|==
name|llvm
operator|::
name|Triple
operator|::
name|x86_64
operator|)
return|;
block|}
comment|/// \brief Return true if {|} are normal characters in the asm string.
comment|///
comment|/// If this returns false (the default), then {abc|xyz} is syntax
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
comment|/// \brief Return the register number that __builtin_eh_return_regno would
comment|/// return with the specified argument.
comment|/// This corresponds with TargetLowering's getExceptionPointerRegister
comment|/// and getExceptionSelectorRegister in the backend.
name|virtual
name|int
name|getEHDataRegisterNumber
argument_list|(
argument|unsigned RegNo
argument_list|)
specifier|const
block|{
return|return
operator|-
literal|1
return|;
block|}
comment|/// \brief Return the section to use for C++ static initialization functions.
name|virtual
specifier|const
name|char
operator|*
name|getStaticInitSectionSpecifier
argument_list|()
specifier|const
block|{
return|return
name|nullptr
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
name|bool
name|isBigEndian
argument_list|()
specifier|const
block|{
return|return
name|BigEndian
return|;
block|}
name|bool
name|isLittleEndian
argument_list|()
specifier|const
block|{
return|return
operator|!
name|BigEndian
return|;
block|}
expr|enum
name|CallingConvMethodType
block|{
name|CCMT_Unknown
block|,
name|CCMT_Member
block|,
name|CCMT_NonMember
block|}
block|;
comment|/// \brief Gets the default calling convention for the given target and
comment|/// declaration context.
name|virtual
name|CallingConv
name|getDefaultCallingConv
argument_list|(
argument|CallingConvMethodType MT
argument_list|)
specifier|const
block|{
comment|// Not all targets will specify an explicit calling convention that we can
comment|// express.  This will always do the right thing, even though it's not
comment|// an explicit calling convention.
return|return
name|CC_C
return|;
block|}
expr|enum
name|CallingConvCheckResult
block|{
name|CCCR_OK
block|,
name|CCCR_Warning
block|,
name|CCCR_Ignore
block|,   }
block|;
comment|/// \brief Determines whether a given calling convention is valid for the
comment|/// target. A calling convention can either be accepted, produce a warning
comment|/// and be substituted with the default calling convention, or (someday)
comment|/// produce an error (such as using thiscall on a non-instance function).
name|virtual
name|CallingConvCheckResult
name|checkCallingConvention
argument_list|(
argument|CallingConv CC
argument_list|)
specifier|const
block|{
switch|switch
condition|(
name|CC
condition|)
block|{
default|default:
return|return
name|CCCR_Warning
return|;
case|case
name|CC_C
case|:
return|return
name|CCCR_OK
return|;
block|}
block|}
comment|/// Controls if __builtin_longjmp / __builtin_setjmp can be lowered to
comment|/// llvm.eh.sjlj.longjmp / llvm.eh.sjlj.setjmp.
name|virtual
name|bool
name|hasSjLjLowering
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Whether target allows to overalign ABI-specified preferred alignment
name|virtual
name|bool
name|allowsLargerPreferedTypeAlignment
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// \brief Set supported OpenCL extensions and optional core features.
name|virtual
name|void
name|setSupportedOpenCLOpts
argument_list|()
block|{}
comment|/// \brief Set supported OpenCL extensions as written on command line
name|virtual
name|void
name|setOpenCLExtensionOpts
argument_list|()
block|{
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|Ext
range|:
name|getTargetOpts
argument_list|()
operator|.
name|OpenCLExtensionsAsWritten
control|)
block|{
name|getTargetOpts
argument_list|()
operator|.
name|SupportedOpenCLOptions
operator|.
name|support
argument_list|(
name|Ext
argument_list|)
expr_stmt|;
block|}
block|}
comment|/// \brief Get supported OpenCL extensions and optional core features.
name|OpenCLOptions
operator|&
name|getSupportedOpenCLOpts
argument_list|()
block|{
return|return
name|getTargetOpts
argument_list|()
operator|.
name|SupportedOpenCLOptions
return|;
block|}
comment|/// \brief Get const supported OpenCL extensions and optional core features.
specifier|const
name|OpenCLOptions
operator|&
name|getSupportedOpenCLOpts
argument_list|()
specifier|const
block|{
return|return
name|getTargetOpts
argument_list|()
operator|.
name|SupportedOpenCLOptions
return|;
block|}
comment|/// \brief Get OpenCL image type address space.
name|virtual
name|LangAS
operator|::
name|ID
name|getOpenCLImageAddrSpace
argument_list|()
specifier|const
block|{
return|return
name|LangAS
operator|::
name|opencl_global
return|;
block|}
comment|/// \returns Target specific vtbl ptr address space.
name|virtual
name|unsigned
name|getVtblPtrAddressSpace
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// \returns If a target requires an address within a target specific address
comment|/// space \p AddressSpace to be converted in order to be used, then return the
comment|/// corresponding target specific DWARF address space.
comment|///
comment|/// \returns Otherwise return None and no conversion will be emitted in the
comment|/// DWARF.
name|virtual
name|Optional
operator|<
name|unsigned
operator|>
name|getDWARFAddressSpace
argument_list|(
argument|unsigned AddressSpace
argument_list|)
specifier|const
block|{
return|return
name|None
return|;
block|}
comment|/// \brief Check the target is valid after it is fully initialized.
name|virtual
name|bool
name|validateTarget
argument_list|(
argument|DiagnosticsEngine&Diags
argument_list|)
specifier|const
block|{
return|return
name|true
return|;
block|}
name|protected
operator|:
name|virtual
name|uint64_t
name|getPointerWidthV
argument_list|(
argument|unsigned AddrSpace
argument_list|)
specifier|const
block|{
return|return
name|PointerWidth
return|;
block|}
name|virtual
name|uint64_t
name|getPointerAlignV
argument_list|(
argument|unsigned AddrSpace
argument_list|)
specifier|const
block|{
return|return
name|PointerAlign
return|;
block|}
name|virtual
expr|enum
name|IntType
name|getPtrDiffTypeV
argument_list|(
argument|unsigned AddrSpace
argument_list|)
specifier|const
block|{
return|return
name|PtrDiffType
return|;
block|}
name|virtual
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|getGCCRegNames
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|ArrayRef
operator|<
name|GCCRegAlias
operator|>
name|getGCCRegAliases
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|ArrayRef
operator|<
name|AddlRegName
operator|>
name|getGCCAddlRegNames
argument_list|()
specifier|const
block|{
return|return
name|None
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

