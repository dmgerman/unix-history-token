begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- TargetCXXABI.h - C++ ABI Target Configuration ----------*- C++ -*-===//
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
comment|/// \brief Defines the TargetCXXABI class, which abstracts details of the
end_comment

begin_comment
comment|/// C++ ABI that we're targeting.
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
name|LLVM_CLANG_TARGETCXXABI_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TARGETCXXABI_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief The basic abstraction for the target C++ ABI.
name|class
name|TargetCXXABI
block|{
name|public
label|:
comment|/// \brief The basic C++ ABI kind.
enum|enum
name|Kind
block|{
comment|/// The generic Itanium ABI is the standard ABI of most open-source
comment|/// and Unix-like platforms.  It is the primary ABI targeted by
comment|/// many compilers, including Clang and GCC.
comment|///
comment|/// It is documented here:
comment|///   http://www.codesourcery.com/public/cxx-abi/
name|GenericItanium
block|,
comment|/// The generic ARM ABI is a modified version of the Itanium ABI
comment|/// proposed by ARM for use on ARM-based platforms.
comment|///
comment|/// These changes include:
comment|///   - the representation of member function pointers is adjusted
comment|///     to not conflict with the 'thumb' bit of ARM function pointers;
comment|///   - constructors and destructors return 'this';
comment|///   - guard variables are smaller;
comment|///   - inline functions are never key functions;
comment|///   - array cookies have a slightly different layout;
comment|///   - additional convenience functions are specified;
comment|///   - and more!
comment|///
comment|/// It is documented here:
comment|///    http://infocenter.arm.com
comment|///                    /help/topic/com.arm.doc.ihi0041c/IHI0041C_cppabi.pdf
name|GenericARM
block|,
comment|/// The iOS ABI is a partial implementation of the ARM ABI.
comment|/// Several of the features of the ARM ABI were not fully implemented
comment|/// in the compilers that iOS was launched with.
comment|///
comment|/// Essentially, the iOS ABI includes the ARM changes to:
comment|///   - member function pointers,
comment|///   - guard variables,
comment|///   - array cookies, and
comment|///   - constructor/destructor signatures.
name|iOS
block|,
comment|/// The generic AArch64 ABI is also a modified version of the Itanium ABI,
comment|/// but it has fewer divergences than the 32-bit ARM ABI.
comment|///
comment|/// The relevant changes from the generic ABI in this case are:
comment|///   - representation of member function pointers adjusted as in ARM.
comment|///   - guard variables  are smaller.
name|GenericAArch64
block|,
comment|/// The Microsoft ABI is the ABI used by Microsoft Visual Studio (and
comment|/// compatible compilers).
comment|///
comment|/// FIXME: should this be split into Win32 and Win64 variants?
comment|///
comment|/// Only scattered and incomplete official documentation exists.
name|Microsoft
block|}
enum|;
name|private
label|:
comment|// Right now, this class is passed around as a cheap value type.
comment|// If you add more members, especially non-POD members, please
comment|// audit the users to pass it by reference instead.
name|Kind
name|TheKind
decl_stmt|;
name|public
label|:
comment|/// A bogus initialization of the platform ABI.
name|TargetCXXABI
argument_list|()
operator|:
name|TheKind
argument_list|(
argument|GenericItanium
argument_list|)
block|{}
name|TargetCXXABI
argument_list|(
argument|Kind kind
argument_list|)
operator|:
name|TheKind
argument_list|(
argument|kind
argument_list|)
block|{}
name|void
name|set
argument_list|(
argument|Kind kind
argument_list|)
block|{
name|TheKind
operator|=
name|kind
block|;   }
name|Kind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|TheKind
return|;
block|}
comment|/// \brief Does this ABI generally fall into the Itanium family of ABIs?
name|bool
name|isItaniumFamily
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|getKind
argument_list|()
condition|)
block|{
case|case
name|GenericAArch64
case|:
case|case
name|GenericItanium
case|:
case|case
name|GenericARM
case|:
case|case
name|iOS
case|:
return|return
name|true
return|;
case|case
name|Microsoft
case|:
return|return
name|false
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"bad ABI kind"
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Is this ABI an MSVC-compatible ABI?
name|bool
name|isMicrosoft
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|getKind
argument_list|()
condition|)
block|{
case|case
name|GenericAArch64
case|:
case|case
name|GenericItanium
case|:
case|case
name|GenericARM
case|:
case|case
name|iOS
case|:
return|return
name|false
return|;
case|case
name|Microsoft
case|:
return|return
name|true
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"bad ABI kind"
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Is the default C++ member function calling convention
comment|/// the same as the default calling convention?
name|bool
name|isMemberFunctionCCDefault
argument_list|()
specifier|const
block|{
comment|// Right now, this is always false for Microsoft.
return|return
operator|!
name|isMicrosoft
argument_list|()
return|;
block|}
comment|/// Are temporary objects passed by value to a call destroyed by the callee?
comment|/// This is a fundamental language change, since it implies that objects
comment|/// passed by value do *not* live to the end of the full expression.
comment|/// Temporaries passed to a function taking a const reference live to the end
comment|/// of the full expression as usual.  Both the caller and the callee must
comment|/// have access to the destructor, while only the caller needs the
comment|/// destructor if this is false.
name|bool
name|isArgumentDestroyedByCallee
argument_list|()
specifier|const
block|{
return|return
name|isMicrosoft
argument_list|()
return|;
block|}
comment|/// \brief Does this ABI have different entrypoints for complete-object
comment|/// and base-subobject constructors?
name|bool
name|hasConstructorVariants
argument_list|()
specifier|const
block|{
return|return
name|isItaniumFamily
argument_list|()
return|;
block|}
comment|/// \brief Does this ABI allow virtual bases to be primary base classes?
name|bool
name|hasPrimaryVBases
argument_list|()
specifier|const
block|{
return|return
name|isItaniumFamily
argument_list|()
return|;
block|}
comment|/// \brief Does this ABI use key functions?  If so, class data such as the
comment|/// vtable is emitted with strong linkage by the TU containing the key
comment|/// function.
name|bool
name|hasKeyFunctions
argument_list|()
specifier|const
block|{
return|return
name|isItaniumFamily
argument_list|()
return|;
block|}
comment|/// \brief Can an out-of-line inline function serve as a key function?
comment|///
comment|/// This flag is only useful in ABIs where type data (for example,
comment|/// v-tables and type_info objects) are emitted only after processing
comment|/// the definition of a special "key" virtual function.  (This is safe
comment|/// because the ODR requires that every virtual function be defined
comment|/// somewhere in a program.)  This usually permits such data to be
comment|/// emitted in only a single object file, as opposed to redundantly
comment|/// in every object file that requires it.
comment|///
comment|/// One simple and common definition of "key function" is the first
comment|/// virtual function in the class definition which is not defined there.
comment|/// This rule works very well when that function has a non-inline
comment|/// definition in some non-header file.  Unfortunately, when that
comment|/// function is defined inline, this rule requires the type data
comment|/// to be emitted weakly, as if there were no key function.
comment|///
comment|/// The ARM ABI observes that the ODR provides an additional guarantee:
comment|/// a virtual function is always ODR-used, so if it is defined inline,
comment|/// that definition must appear in every translation unit that defines
comment|/// the class.  Therefore, there is no reason to allow such functions
comment|/// to serve as key functions.
comment|///
comment|/// Because this changes the rules for emitting type data,
comment|/// it can cause type data to be emitted with both weak and strong
comment|/// linkage, which is not allowed on all platforms.  Therefore,
comment|/// exploiting this observation requires an ABI break and cannot be
comment|/// done on a generic Itanium platform.
name|bool
name|canKeyFunctionBeInline
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|getKind
argument_list|()
condition|)
block|{
case|case
name|GenericARM
case|:
return|return
name|false
return|;
case|case
name|GenericAArch64
case|:
case|case
name|GenericItanium
case|:
case|case
name|iOS
case|:
comment|// old iOS compilers did not follow this rule
case|case
name|Microsoft
case|:
return|return
name|true
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"bad ABI kind"
argument_list|)
expr_stmt|;
block|}
comment|/// When is record layout allowed to allocate objects in the tail
comment|/// padding of a base class?
comment|///
comment|/// This decision cannot be changed without breaking platform ABI
comment|/// compatibility, and yet it is tied to language guarantees which
comment|/// the committee has so far seen fit to strengthen no less than
comment|/// three separate times:
comment|///   - originally, there were no restrictions at all;
comment|///   - C++98 declared that objects could not be allocated in the
comment|///     tail padding of a POD type;
comment|///   - C++03 extended the definition of POD to include classes
comment|///     containing member pointers; and
comment|///   - C++11 greatly broadened the definition of POD to include
comment|///     all trivial standard-layout classes.
comment|/// Each of these changes technically took several existing
comment|/// platforms and made them permanently non-conformant.
expr|enum
name|TailPaddingUseRules
block|{
comment|/// The tail-padding of a base class is always theoretically
comment|/// available, even if it's POD.  This is not strictly conforming
comment|/// in any language mode.
name|AlwaysUseTailPadding
block|,
comment|/// Only allocate objects in the tail padding of a base class if
comment|/// the base class is not POD according to the rules of C++ TR1.
comment|/// This is non strictly conforming in C++11 mode.
name|UseTailPaddingUnlessPOD03
block|,
comment|/// Only allocate objects in the tail padding of a base class if
comment|/// the base class is not POD according to the rules of C++11.
name|UseTailPaddingUnlessPOD11
block|}
expr_stmt|;
name|TailPaddingUseRules
name|getTailPaddingUseRules
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|getKind
argument_list|()
condition|)
block|{
comment|// To preserve binary compatibility, the generic Itanium ABI has
comment|// permanently locked the definition of POD to the rules of C++ TR1,
comment|// and that trickles down to all the derived ABIs.
case|case
name|GenericItanium
case|:
case|case
name|GenericAArch64
case|:
case|case
name|GenericARM
case|:
case|case
name|iOS
case|:
return|return
name|UseTailPaddingUnlessPOD03
return|;
comment|// MSVC always allocates fields in the tail-padding of a base class
comment|// subobject, even if they're POD.
case|case
name|Microsoft
case|:
return|return
name|AlwaysUseTailPadding
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"bad ABI kind"
argument_list|)
expr_stmt|;
block|}
comment|/// Try to parse an ABI name, returning false on error.
name|bool
name|tryParse
argument_list|(
argument|llvm::StringRef name
argument_list|)
expr_stmt|;
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|TargetCXXABI
operator|&
name|left
operator|,
specifier|const
name|TargetCXXABI
operator|&
name|right
operator|)
block|{
return|return
name|left
operator|.
name|getKind
argument_list|()
operator|==
name|right
operator|.
name|getKind
argument_list|()
return|;
block|}
name|friend
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|TargetCXXABI
operator|&
name|left
operator|,
specifier|const
name|TargetCXXABI
operator|&
name|right
operator|)
block|{
return|return
operator|!
operator|(
name|left
operator|==
name|right
operator|)
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

