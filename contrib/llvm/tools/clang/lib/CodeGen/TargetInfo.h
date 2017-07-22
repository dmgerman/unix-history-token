begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- TargetInfo.h - Encapsulate target details -------------*- C++ -*-===//
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
comment|// These classes wrap the information about a call or function
end_comment

begin_comment
comment|// definition used to handle ABI compliancy.
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
name|LLVM_CLANG_LIB_CODEGEN_TARGETINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_CODEGEN_TARGETINFO_H
end_define

begin_include
include|#
directive|include
file|"CGValue.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Constant
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|Value
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Decl
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|ABIInfo
decl_stmt|;
name|class
name|CallArgList
decl_stmt|;
name|class
name|CodeGenModule
decl_stmt|;
name|class
name|CodeGenFunction
decl_stmt|;
name|class
name|CGFunctionInfo
decl_stmt|;
comment|/// TargetCodeGenInfo - This class organizes various target-specific
comment|/// codegeneration issues, like target-specific attributes, builtins and so
comment|/// on.
name|class
name|TargetCodeGenInfo
block|{
name|ABIInfo
modifier|*
name|Info
decl_stmt|;
name|public
label|:
comment|// WARNING: Acquires the ownership of ABIInfo.
name|TargetCodeGenInfo
argument_list|(
name|ABIInfo
operator|*
name|info
operator|=
name|nullptr
argument_list|)
operator|:
name|Info
argument_list|(
argument|info
argument_list|)
block|{}
name|virtual
operator|~
name|TargetCodeGenInfo
argument_list|()
expr_stmt|;
comment|/// getABIInfo() - Returns ABI info helper for the target.
specifier|const
name|ABIInfo
operator|&
name|getABIInfo
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Info
return|;
block|}
comment|/// setTargetAttributes - Provides a convenient hook to handle extra
comment|/// target-specific attributes for the given global.
name|virtual
name|void
name|setTargetAttributes
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|GlobalValue
operator|*
name|GV
argument_list|,
name|CodeGen
operator|::
name|CodeGenModule
operator|&
name|M
argument_list|)
decl|const
block|{}
comment|/// emitTargetMD - Provides a convenient hook to handle extra
comment|/// target-specific metadata for the given global.
name|virtual
name|void
name|emitTargetMD
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|GlobalValue
operator|*
name|GV
argument_list|,
name|CodeGen
operator|::
name|CodeGenModule
operator|&
name|M
argument_list|)
decl|const
block|{}
comment|/// Determines the size of struct _Unwind_Exception on this platform,
comment|/// in 8-bit units.  The Itanium ABI defines this as:
comment|///   struct _Unwind_Exception {
comment|///     uint64 exception_class;
comment|///     _Unwind_Exception_Cleanup_Fn exception_cleanup;
comment|///     uint64 private_1;
comment|///     uint64 private_2;
comment|///   };
name|virtual
name|unsigned
name|getSizeOfUnwindException
argument_list|()
specifier|const
expr_stmt|;
comment|/// Controls whether __builtin_extend_pointer should sign-extend
comment|/// pointers to uint64_t or zero-extend them (the default).  Has
comment|/// no effect for targets:
comment|///   - that have 64-bit pointers, or
comment|///   - that cannot address through registers larger than pointers, or
comment|///   - that implicitly ignore/truncate the top bits when addressing
comment|///     through such registers.
name|virtual
name|bool
name|extendPointerWithSExt
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Determines the DWARF register number for the stack pointer, for
comment|/// exception-handling purposes.  Implements __builtin_dwarf_sp_column.
comment|///
comment|/// Returns -1 if the operation is unsupported by this target.
name|virtual
name|int
name|getDwarfEHStackPointer
argument_list|(
name|CodeGen
operator|::
name|CodeGenModule
operator|&
name|M
argument_list|)
decl|const
block|{
return|return
operator|-
literal|1
return|;
block|}
comment|/// Initializes the given DWARF EH register-size table, a char*.
comment|/// Implements __builtin_init_dwarf_reg_size_table.
comment|///
comment|/// Returns true if the operation is unsupported by this target.
name|virtual
name|bool
name|initDwarfEHRegSizeTable
argument_list|(
name|CodeGen
operator|::
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Address
argument_list|)
decl|const
block|{
return|return
name|true
return|;
block|}
comment|/// Performs the code-generation required to convert a return
comment|/// address as stored by the system into the actual address of the
comment|/// next instruction that will be executed.
comment|///
comment|/// Used by __builtin_extract_return_addr().
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|decodeReturnAddress
argument_list|(
argument|CodeGen::CodeGenFunction&CGF
argument_list|,
argument|llvm::Value *Address
argument_list|)
specifier|const
block|{
return|return
name|Address
return|;
block|}
comment|/// Performs the code-generation required to convert the address
comment|/// of an instruction into a return address suitable for storage
comment|/// by the system in a return slot.
comment|///
comment|/// Used by __builtin_frob_return_addr().
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|encodeReturnAddress
argument_list|(
argument|CodeGen::CodeGenFunction&CGF
argument_list|,
argument|llvm::Value *Address
argument_list|)
specifier|const
block|{
return|return
name|Address
return|;
block|}
comment|/// Corrects the low-level LLVM type for a given constraint and "usual"
comment|/// type.
comment|///
comment|/// \returns A pointer to a new LLVM type, possibly the same as the original
comment|/// on success; 0 on failure.
name|virtual
name|llvm
operator|::
name|Type
operator|*
name|adjustInlineAsmType
argument_list|(
argument|CodeGen::CodeGenFunction&CGF
argument_list|,
argument|StringRef Constraint
argument_list|,
argument|llvm::Type *Ty
argument_list|)
specifier|const
block|{
return|return
name|Ty
return|;
block|}
comment|/// Adds constraints and types for result registers.
name|virtual
name|void
name|addReturnRegisterOutputs
argument_list|(
name|CodeGen
operator|::
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|CodeGen
operator|::
name|LValue
name|ReturnValue
argument_list|,
name|std
operator|::
name|string
operator|&
name|Constraints
argument_list|,
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|Type
operator|*
operator|>
operator|&
name|ResultRegTypes
argument_list|,
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|Type
operator|*
operator|>
operator|&
name|ResultTruncRegTypes
argument_list|,
name|std
operator|::
name|vector
operator|<
name|CodeGen
operator|::
name|LValue
operator|>
operator|&
name|ResultRegDests
argument_list|,
name|std
operator|::
name|string
operator|&
name|AsmString
argument_list|,
name|unsigned
name|NumOutputs
argument_list|)
decl|const
block|{}
comment|/// doesReturnSlotInterfereWithArgs - Return true if the target uses an
comment|/// argument slot for an 'sret' type.
name|virtual
name|bool
name|doesReturnSlotInterfereWithArgs
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// Retrieve the address of a function to call immediately before
comment|/// calling objc_retainAutoreleasedReturnValue.  The
comment|/// implementation of objc_autoreleaseReturnValue sniffs the
comment|/// instruction stream following its return address to decide
comment|/// whether it's a call to objc_retainAutoreleasedReturnValue.
comment|/// This can be prohibitively expensive, depending on the
comment|/// relocation model, and so on some targets it instead sniffs for
comment|/// a particular instruction sequence.  This functions returns
comment|/// that instruction sequence in inline assembly, which will be
comment|/// empty if none is required.
name|virtual
name|StringRef
name|getARCRetainAutoreleasedReturnValueMarker
argument_list|()
specifier|const
block|{
return|return
literal|""
return|;
block|}
comment|/// Return a constant used by UBSan as a signature to identify functions
comment|/// possessing type information, or 0 if the platform is unsupported.
name|virtual
name|llvm
operator|::
name|Constant
operator|*
name|getUBSanFunctionSignature
argument_list|(
argument|CodeGen::CodeGenModule&CGM
argument_list|)
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
comment|/// Determine whether a call to an unprototyped functions under
comment|/// the given calling convention should use the variadic
comment|/// convention or the non-variadic convention.
comment|///
comment|/// There's a good reason to make a platform's variadic calling
comment|/// convention be different from its non-variadic calling
comment|/// convention: the non-variadic arguments can be passed in
comment|/// registers (better for performance), and the variadic arguments
comment|/// can be passed on the stack (also better for performance).  If
comment|/// this is done, however, unprototyped functions *must* use the
comment|/// non-variadic convention, because C99 states that a call
comment|/// through an unprototyped function type must succeed if the
comment|/// function was defined with a non-variadic prototype with
comment|/// compatible parameters.  Therefore, splitting the conventions
comment|/// makes it impossible to call a variadic function through an
comment|/// unprototyped type.  Since function prototypes came out in the
comment|/// late 1970s, this is probably an acceptable trade-off.
comment|/// Nonetheless, not all platforms are willing to make it, and in
comment|/// particularly x86-64 bends over backwards to make the
comment|/// conventions compatible.
comment|///
comment|/// The default is false.  This is correct whenever:
comment|///   - the conventions are exactly the same, because it does not
comment|///     matter and the resulting IR will be somewhat prettier in
comment|///     certain cases; or
comment|///   - the conventions are substantively different in how they pass
comment|///     arguments, because in this case using the variadic convention
comment|///     will lead to C99 violations.
comment|///
comment|/// However, some platforms make the conventions identical except
comment|/// for passing additional out-of-band information to a variadic
comment|/// function: for example, x86-64 passes the number of SSE
comment|/// arguments in %al.  On these platforms, it is desirable to
comment|/// call unprototyped functions using the variadic convention so
comment|/// that unprototyped calls to varargs functions still succeed.
comment|///
comment|/// Relatedly, platforms which pass the fixed arguments to this:
comment|///   A foo(B, C, D);
comment|/// differently than they would pass them to this:
comment|///   A foo(B, C, D, ...);
comment|/// may need to adjust the debugger-support code in Sema to do the
comment|/// right thing when calling a function with no know signature.
name|virtual
name|bool
name|isNoProtoCallVariadic
argument_list|(
specifier|const
name|CodeGen
operator|::
name|CallArgList
operator|&
name|args
argument_list|,
specifier|const
name|FunctionNoProtoType
operator|*
name|fnType
argument_list|)
decl|const
decl_stmt|;
comment|/// Gets the linker options necessary to link a dependent library on this
comment|/// platform.
name|virtual
name|void
name|getDependentLibraryOption
argument_list|(
name|llvm
operator|::
name|StringRef
name|Lib
argument_list|,
name|llvm
operator|::
name|SmallString
operator|<
literal|24
operator|>
operator|&
name|Opt
argument_list|)
decl|const
decl_stmt|;
comment|/// Gets the linker options necessary to detect object file mismatches on
comment|/// this platform.
name|virtual
name|void
name|getDetectMismatchOption
argument_list|(
name|llvm
operator|::
name|StringRef
name|Name
argument_list|,
name|llvm
operator|::
name|StringRef
name|Value
argument_list|,
name|llvm
operator|::
name|SmallString
operator|<
literal|32
operator|>
operator|&
name|Opt
argument_list|)
decl|const
block|{}
comment|/// Get LLVM calling convention for OpenCL kernel.
name|virtual
name|unsigned
name|getOpenCLKernelCallingConv
argument_list|()
specifier|const
expr_stmt|;
comment|/// Get target specific null pointer.
comment|/// \param T is the LLVM type of the null pointer.
comment|/// \param QT is the clang QualType of the null pointer.
comment|/// \return ConstantPointerNull with the given type \p T.
comment|/// Each target can override it to return its own desired constant value.
name|virtual
name|llvm
operator|::
name|Constant
operator|*
name|getNullPointer
argument_list|(
argument|const CodeGen::CodeGenModule&CGM
argument_list|,
argument|llvm::PointerType *T
argument_list|,
argument|QualType QT
argument_list|)
specifier|const
expr_stmt|;
comment|/// Get target favored AST address space of a global variable for languages
comment|/// other than OpenCL and CUDA.
comment|/// If \p D is nullptr, returns the default target favored address space
comment|/// for global variable.
name|virtual
name|unsigned
name|getGlobalVarAddressSpace
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|,
specifier|const
name|VarDecl
operator|*
name|D
argument_list|)
decl|const
decl_stmt|;
comment|/// Get the AST address space for alloca.
name|virtual
name|unsigned
name|getASTAllocaAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|LangAS
operator|::
name|Default
return|;
block|}
comment|/// Perform address space cast of an expression of pointer type.
comment|/// \param V is the LLVM value to be casted to another address space.
comment|/// \param SrcAddr is the language address space of \p V.
comment|/// \param DestAddr is the targeted language address space.
comment|/// \param DestTy is the destination LLVM pointer type.
comment|/// \param IsNonNull is the flag indicating \p V is known to be non null.
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|performAddrSpaceCast
argument_list|(
argument|CodeGen::CodeGenFunction&CGF
argument_list|,
argument|llvm::Value *V
argument_list|,
argument|unsigned SrcAddr
argument_list|,
argument|unsigned DestAddr
argument_list|,
argument|llvm::Type *DestTy
argument_list|,
argument|bool IsNonNull = false
argument_list|)
specifier|const
expr_stmt|;
comment|/// Perform address space cast of a constant expression of pointer type.
comment|/// \param V is the LLVM constant to be casted to another address space.
comment|/// \param SrcAddr is the language address space of \p V.
comment|/// \param DestAddr is the targeted language address space.
comment|/// \param DestTy is the destination LLVM pointer type.
name|virtual
name|llvm
operator|::
name|Constant
operator|*
name|performAddrSpaceCast
argument_list|(
argument|CodeGenModule&CGM
argument_list|,
argument|llvm::Constant *V
argument_list|,
argument|unsigned SrcAddr
argument_list|,
argument|unsigned DestAddr
argument_list|,
argument|llvm::Type *DestTy
argument_list|)
specifier|const
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// namespace CodeGen
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_LIB_CODEGEN_TARGETINFO_H
end_comment

end_unit

