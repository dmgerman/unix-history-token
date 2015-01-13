begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- CGOpenMPRuntime.h - Interface to OpenMP Runtimes -----*- C++ -*-===//
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
comment|// This provides a class for OpenMP runtime code generation.
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
name|CLANG_CODEGEN_OPENMPRUNTIME_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CODEGEN_OPENMPRUNTIME_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Type.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Value.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AllocaInst
decl_stmt|;
name|class
name|CallInst
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|Constant
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|StructLayout
decl_stmt|;
name|class
name|FunctionType
decl_stmt|;
name|class
name|StructType
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|Value
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|CodeGen
block|{
name|class
name|CodeGenFunction
decl_stmt|;
name|class
name|CodeGenModule
decl_stmt|;
name|class
name|CGOpenMPRuntime
block|{
name|public
label|:
comment|/// \brief Values for bit flags used in the ident_t to describe the fields.
comment|/// All enumeric elements are named and described in accordance with the code
comment|/// from http://llvm.org/svn/llvm-project/openmp/trunk/runtime/src/kmp.h
enum|enum
name|OpenMPLocationFlags
block|{
comment|/// \brief Use trampoline for internal microtask.
name|OMP_IDENT_IMD
init|=
literal|0x01
block|,
comment|/// \brief Use c-style ident structure.
name|OMP_IDENT_KMPC
init|=
literal|0x02
block|,
comment|/// \brief Atomic reduction option for kmpc_reduce.
name|OMP_ATOMIC_REDUCE
init|=
literal|0x10
block|,
comment|/// \brief Explicit 'barrier' directive.
name|OMP_IDENT_BARRIER_EXPL
init|=
literal|0x20
block|,
comment|/// \brief Implicit barrier in code.
name|OMP_IDENT_BARRIER_IMPL
init|=
literal|0x40
block|,
comment|/// \brief Implicit barrier in 'for' directive.
name|OMP_IDENT_BARRIER_IMPL_FOR
init|=
literal|0x40
block|,
comment|/// \brief Implicit barrier in 'sections' directive.
name|OMP_IDENT_BARRIER_IMPL_SECTIONS
init|=
literal|0xC0
block|,
comment|/// \brief Implicit barrier in 'single' directive.
name|OMP_IDENT_BARRIER_IMPL_SINGLE
init|=
literal|0x140
block|}
enum|;
enum|enum
name|OpenMPRTLFunction
block|{
comment|// Call to void __kmpc_fork_call(ident_t *loc, kmp_int32 argc, kmpc_micro
comment|// microtask, ...);
name|OMPRTL__kmpc_fork_call
block|,
comment|// Call to kmp_int32 kmpc_global_thread_num(ident_t *loc);
name|OMPRTL__kmpc_global_thread_num
block|}
enum|;
name|private
label|:
name|CodeGenModule
modifier|&
name|CGM
decl_stmt|;
comment|/// \brief Default const ident_t object used for initialization of all other
comment|/// ident_t objects.
name|llvm
operator|::
name|Constant
operator|*
name|DefaultOpenMPPSource
expr_stmt|;
comment|/// \brief Map of flags and corrsponding default locations.
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|unsigned
operator|,
name|llvm
operator|::
name|Value
operator|*
operator|>
name|OpenMPDefaultLocMapTy
expr_stmt|;
name|OpenMPDefaultLocMapTy
name|OpenMPDefaultLocMap
decl_stmt|;
name|llvm
operator|::
name|Value
operator|*
name|GetOrCreateDefaultOpenMPLocation
argument_list|(
argument|OpenMPLocationFlags Flags
argument_list|)
expr_stmt|;
comment|/// \brief Describes ident structure that describes a source location.
comment|/// All descriptions are taken from
comment|/// http://llvm.org/svn/llvm-project/openmp/trunk/runtime/src/kmp.h
comment|/// Original structure:
comment|/// typedef struct ident {
comment|///    kmp_int32 reserved_1;   /**<  might be used in Fortran;
comment|///                                  see above  */
comment|///    kmp_int32 flags;        /**<  also f.flags; KMP_IDENT_xxx flags;
comment|///                                  KMP_IDENT_KMPC identifies this union
comment|///                                  member  */
comment|///    kmp_int32 reserved_2;   /**<  not really used in Fortran any more;
comment|///                                  see above */
comment|///#if USE_ITT_BUILD
comment|///                            /*  but currently used for storing
comment|///                                region-specific ITT */
comment|///                            /*  contextual information. */
comment|///#endif /* USE_ITT_BUILD */
comment|///    kmp_int32 reserved_3;   /**< source[4] in Fortran, do not use for
comment|///                                 C++  */
comment|///    char const *psource;    /**< String describing the source location.
comment|///                            The string is composed of semi-colon separated
comment|//                             fields which describe the source file,
comment|///                            the function and a pair of line numbers that
comment|///                            delimit the construct.
comment|///                             */
comment|/// } ident_t;
enum|enum
name|IdentFieldIndex
block|{
comment|/// \brief might be used in Fortran
name|IdentField_Reserved_1
block|,
comment|/// \brief OMP_IDENT_xxx flags; OMP_IDENT_KMPC identifies this union member.
name|IdentField_Flags
block|,
comment|/// \brief Not really used in Fortran any more
name|IdentField_Reserved_2
block|,
comment|/// \brief Source[4] in Fortran, do not use for C++
name|IdentField_Reserved_3
block|,
comment|/// \brief String describing the source location. The string is composed of
comment|/// semi-colon separated fields which describe the source file, the function
comment|/// and a pair of line numbers that delimit the construct.
name|IdentField_PSource
block|}
enum|;
name|llvm
operator|::
name|StructType
operator|*
name|IdentTy
expr_stmt|;
comment|/// \brief Map for Sourcelocation and OpenMP runtime library debug locations.
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|unsigned
operator|,
name|llvm
operator|::
name|Value
operator|*
operator|>
name|OpenMPDebugLocMapTy
expr_stmt|;
name|OpenMPDebugLocMapTy
name|OpenMPDebugLocMap
decl_stmt|;
comment|/// \brief The type for a microtask which gets passed to __kmpc_fork_call().
comment|/// Original representation is:
comment|/// typedef void (kmpc_micro)(kmp_int32 global_tid, kmp_int32 bound_tid,...);
name|llvm
operator|::
name|FunctionType
operator|*
name|Kmpc_MicroTy
expr_stmt|;
comment|/// \brief Map of local debug location and functions.
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|llvm
operator|::
name|Function
operator|*
operator|,
name|llvm
operator|::
name|Value
operator|*
operator|>
name|OpenMPLocMapTy
expr_stmt|;
name|OpenMPLocMapTy
name|OpenMPLocMap
decl_stmt|;
comment|/// \brief Map of local gtid and functions.
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|llvm
operator|::
name|Function
operator|*
operator|,
name|llvm
operator|::
name|Value
operator|*
operator|>
name|OpenMPGtidMapTy
expr_stmt|;
name|OpenMPGtidMapTy
name|OpenMPGtidMap
decl_stmt|;
name|public
label|:
name|explicit
name|CGOpenMPRuntime
parameter_list|(
name|CodeGenModule
modifier|&
name|CGM
parameter_list|)
function_decl|;
operator|~
name|CGOpenMPRuntime
argument_list|()
block|{}
comment|/// \brief Cleans up references to the objects in finished function.
comment|/// \param CGF Reference to finished CodeGenFunction.
comment|///
name|void
name|FunctionFinished
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|)
expr_stmt|;
comment|/// \brief Emits object of ident_t type with info for source location.
comment|/// \param CGF Reference to current CodeGenFunction.
comment|/// \param Loc Clang source location.
comment|/// \param Flags Flags for OpenMP location.
comment|///
name|llvm
operator|::
name|Value
operator|*
name|EmitOpenMPUpdateLocation
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|OpenMPLocationFlags Flags = OMP_IDENT_KMPC
argument_list|)
expr_stmt|;
comment|/// \brief Generates global thread number value.
comment|/// \param CGF Reference to current CodeGenFunction.
comment|/// \param Loc Clang source location.
comment|///
name|llvm
operator|::
name|Value
operator|*
name|GetOpenMPGlobalThreadNum
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|SourceLocation Loc
argument_list|)
expr_stmt|;
comment|/// \brief Returns pointer to ident_t type;
name|llvm
operator|::
name|Type
operator|*
name|getIdentTyPointerTy
argument_list|()
expr_stmt|;
comment|/// \brief Returns pointer to kmpc_micro type;
name|llvm
operator|::
name|Type
operator|*
name|getKmpc_MicroPointerTy
argument_list|()
expr_stmt|;
comment|/// \brief Returns specified OpenMP runtime function.
comment|/// \param Function OpenMP runtime function.
comment|/// \return Specified function.
name|llvm
operator|::
name|Constant
operator|*
name|CreateRuntimeFunction
argument_list|(
argument|OpenMPRTLFunction Function
argument_list|)
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

end_unit

