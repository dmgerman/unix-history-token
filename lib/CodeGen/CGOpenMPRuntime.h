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
name|LLVM_CLANG_LIB_CODEGEN_CGOPENMPRUNTIME_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_CODEGEN_CGOPENMPRUNTIME_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/OpenMPKinds.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueHandle.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ArrayType
decl_stmt|;
name|class
name|Constant
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|FunctionType
decl_stmt|;
name|class
name|GlobalVariable
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
name|class
name|Expr
decl_stmt|;
name|class
name|OMPExecutableDirective
decl_stmt|;
name|class
name|VarDecl
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|CodeGenFunction
decl_stmt|;
name|class
name|CodeGenModule
decl_stmt|;
typedef|typedef
name|llvm
operator|::
name|function_ref
operator|<
name|void
argument_list|(
name|CodeGenFunction
operator|&
argument_list|)
operator|>
name|RegionCodeGenTy
expr_stmt|;
name|class
name|CGOpenMPRuntime
block|{
name|private
label|:
enum|enum
name|OpenMPRTLFunction
block|{
comment|/// \brief Call to void __kmpc_fork_call(ident_t *loc, kmp_int32 argc,
comment|/// kmpc_micro microtask, ...);
name|OMPRTL__kmpc_fork_call
block|,
comment|/// \brief Call to void *__kmpc_threadprivate_cached(ident_t *loc,
comment|/// kmp_int32 global_tid, void *data, size_t size, void ***cache);
name|OMPRTL__kmpc_threadprivate_cached
block|,
comment|/// \brief Call to void __kmpc_threadprivate_register( ident_t *,
comment|/// void *data, kmpc_ctor ctor, kmpc_cctor cctor, kmpc_dtor dtor);
name|OMPRTL__kmpc_threadprivate_register
block|,
comment|// Call to __kmpc_int32 kmpc_global_thread_num(ident_t *loc);
name|OMPRTL__kmpc_global_thread_num
block|,
comment|// Call to void __kmpc_critical(ident_t *loc, kmp_int32 global_tid,
comment|// kmp_critical_name *crit);
name|OMPRTL__kmpc_critical
block|,
comment|// Call to void __kmpc_end_critical(ident_t *loc, kmp_int32 global_tid,
comment|// kmp_critical_name *crit);
name|OMPRTL__kmpc_end_critical
block|,
comment|// Call to kmp_int32 __kmpc_cancel_barrier(ident_t *loc, kmp_int32
comment|// global_tid);
name|OMPRTL__kmpc_cancel_barrier
block|,
comment|// Call to void __kmpc_for_static_fini(ident_t *loc, kmp_int32 global_tid);
name|OMPRTL__kmpc_for_static_fini
block|,
comment|// Call to void __kmpc_serialized_parallel(ident_t *loc, kmp_int32
comment|// global_tid);
name|OMPRTL__kmpc_serialized_parallel
block|,
comment|// Call to void __kmpc_end_serialized_parallel(ident_t *loc, kmp_int32
comment|// global_tid);
name|OMPRTL__kmpc_end_serialized_parallel
block|,
comment|// Call to void __kmpc_push_num_threads(ident_t *loc, kmp_int32 global_tid,
comment|// kmp_int32 num_threads);
name|OMPRTL__kmpc_push_num_threads
block|,
comment|// Call to void __kmpc_flush(ident_t *loc);
name|OMPRTL__kmpc_flush
block|,
comment|// Call to kmp_int32 __kmpc_master(ident_t *, kmp_int32 global_tid);
name|OMPRTL__kmpc_master
block|,
comment|// Call to void __kmpc_end_master(ident_t *, kmp_int32 global_tid);
name|OMPRTL__kmpc_end_master
block|,
comment|// Call to kmp_int32 __kmpc_omp_taskyield(ident_t *, kmp_int32 global_tid,
comment|// int end_part);
name|OMPRTL__kmpc_omp_taskyield
block|,
comment|// Call to kmp_int32 __kmpc_single(ident_t *, kmp_int32 global_tid);
name|OMPRTL__kmpc_single
block|,
comment|// Call to void __kmpc_end_single(ident_t *, kmp_int32 global_tid);
name|OMPRTL__kmpc_end_single
block|,
comment|// Call to kmp_task_t * __kmpc_omp_task_alloc(ident_t *, kmp_int32 gtid,
comment|// kmp_int32 flags, size_t sizeof_kmp_task_t, size_t sizeof_shareds,
comment|// kmp_routine_entry_t *task_entry);
name|OMPRTL__kmpc_omp_task_alloc
block|,
comment|// Call to kmp_int32 __kmpc_omp_task(ident_t *, kmp_int32 gtid, kmp_task_t *
comment|// new_task);
name|OMPRTL__kmpc_omp_task
block|,
comment|// Call to void __kmpc_copyprivate(ident_t *loc, kmp_int32 global_tid,
comment|// size_t cpy_size, void *cpy_data, void(*cpy_func)(void *, void *),
comment|// kmp_int32 didit);
name|OMPRTL__kmpc_copyprivate
block|,
comment|// Call to kmp_int32 __kmpc_reduce(ident_t *loc, kmp_int32 global_tid,
comment|// kmp_int32 num_vars, size_t reduce_size, void *reduce_data, void
comment|// (*reduce_func)(void *lhs_data, void *rhs_data), kmp_critical_name *lck);
name|OMPRTL__kmpc_reduce
block|,
comment|// Call to kmp_int32 __kmpc_reduce_nowait(ident_t *loc, kmp_int32
comment|// global_tid, kmp_int32 num_vars, size_t reduce_size, void *reduce_data,
comment|// void (*reduce_func)(void *lhs_data, void *rhs_data), kmp_critical_name
comment|// *lck);
name|OMPRTL__kmpc_reduce_nowait
block|,
comment|// Call to void __kmpc_end_reduce(ident_t *loc, kmp_int32 global_tid,
comment|// kmp_critical_name *lck);
name|OMPRTL__kmpc_end_reduce
block|,
comment|// Call to void __kmpc_end_reduce_nowait(ident_t *loc, kmp_int32 global_tid,
comment|// kmp_critical_name *lck);
name|OMPRTL__kmpc_end_reduce_nowait
block|,
comment|// Call to void __kmpc_omp_task_begin_if0(ident_t *, kmp_int32 gtid,
comment|// kmp_task_t * new_task);
name|OMPRTL__kmpc_omp_task_begin_if0
block|,
comment|// Call to void __kmpc_omp_task_complete_if0(ident_t *, kmp_int32 gtid,
comment|// kmp_task_t * new_task);
name|OMPRTL__kmpc_omp_task_complete_if0
block|,
comment|// Call to void __kmpc_ordered(ident_t *loc, kmp_int32 global_tid);
name|OMPRTL__kmpc_ordered
block|,
comment|// Call to void __kmpc_end_ordered(ident_t *loc, kmp_int32 global_tid);
name|OMPRTL__kmpc_end_ordered
block|,
comment|// Call to kmp_int32 __kmpc_omp_taskwait(ident_t *loc, kmp_int32
comment|// global_tid);
name|OMPRTL__kmpc_omp_taskwait
block|,   }
enum|;
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
comment|/// \brief Map of flags and corresponding default locations.
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
name|getOrCreateDefaultLocation
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
comment|/// \brief Map for SourceLocation and OpenMP runtime library debug locations.
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
comment|/// \brief Stores debug location and ThreadID for the function.
struct|struct
name|DebugLocThreadIdTy
block|{
name|llvm
operator|::
name|Value
operator|*
name|DebugLoc
expr_stmt|;
name|llvm
operator|::
name|Value
operator|*
name|ThreadID
expr_stmt|;
block|}
struct|;
comment|/// \brief Map of local debug location, ThreadId and functions.
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
name|DebugLocThreadIdTy
operator|>
name|OpenMPLocThreadIDMapTy
expr_stmt|;
name|OpenMPLocThreadIDMapTy
name|OpenMPLocThreadIDMap
decl_stmt|;
comment|/// \brief Type kmp_critical_name, originally defined as typedef kmp_int32
comment|/// kmp_critical_name[8];
name|llvm
operator|::
name|ArrayType
operator|*
name|KmpCriticalNameTy
expr_stmt|;
comment|/// \brief An ordered map of auto-generated variables to their unique names.
comment|/// It stores variables with the following names: 1) ".gomp_critical_user_" +
comment|///<critical_section_name> + ".var" for "omp critical" directives; 2)
comment|///<mangled_name_for_global_var> + ".cache." for cache for threadprivate
comment|/// variables.
name|llvm
operator|::
name|StringMap
operator|<
name|llvm
operator|::
name|AssertingVH
operator|<
name|llvm
operator|::
name|Constant
operator|>
operator|,
name|llvm
operator|::
name|BumpPtrAllocator
operator|>
name|InternalVars
expr_stmt|;
comment|/// \brief Type typedef kmp_int32 (* kmp_routine_entry_t)(kmp_int32, void *);
name|llvm
operator|::
name|Type
operator|*
name|KmpRoutineEntryPtrTy
expr_stmt|;
name|QualType
name|KmpRoutineEntryPtrQTy
decl_stmt|;
comment|/// \brief Type typedef struct kmp_task {
comment|///    void *              shareds; /**< pointer to block of pointers to
comment|///    shared vars   */
comment|///    kmp_routine_entry_t routine; /**< pointer to routine to call for
comment|///    executing task */
comment|///    kmp_int32           part_id; /**< part id for the task */
comment|///    kmp_routine_entry_t destructors; /* pointer to function to invoke
comment|///    deconstructors of firstprivate C++ objects */
comment|/// } kmp_task_t;
name|QualType
name|KmpTaskTQTy
decl_stmt|;
comment|/// \brief Build type kmp_routine_entry_t (if not built yet).
name|void
name|emitKmpRoutineEntryT
parameter_list|(
name|QualType
name|KmpInt32Ty
parameter_list|)
function_decl|;
comment|/// \brief Emits object of ident_t type with info for source location.
comment|/// \param Flags Flags for OpenMP location.
comment|///
name|llvm
operator|::
name|Value
operator|*
name|emitUpdateLocation
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|OpenMPLocationFlags Flags = OMP_IDENT_KMPC
argument_list|)
expr_stmt|;
comment|/// \brief Returns pointer to ident_t type.
name|llvm
operator|::
name|Type
operator|*
name|getIdentTyPointerTy
argument_list|()
expr_stmt|;
comment|/// \brief Returns pointer to kmpc_micro type.
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
name|createRuntimeFunction
argument_list|(
argument|OpenMPRTLFunction Function
argument_list|)
expr_stmt|;
comment|/// \brief Returns __kmpc_for_static_init_* runtime function for the specified
comment|/// size \a IVSize and sign \a IVSigned.
name|llvm
operator|::
name|Constant
operator|*
name|createForStaticInitFunction
argument_list|(
argument|unsigned IVSize
argument_list|,
argument|bool IVSigned
argument_list|)
expr_stmt|;
comment|/// \brief Returns __kmpc_dispatch_init_* runtime function for the specified
comment|/// size \a IVSize and sign \a IVSigned.
name|llvm
operator|::
name|Constant
operator|*
name|createDispatchInitFunction
argument_list|(
argument|unsigned IVSize
argument_list|,
argument|bool IVSigned
argument_list|)
expr_stmt|;
comment|/// \brief Returns __kmpc_dispatch_next_* runtime function for the specified
comment|/// size \a IVSize and sign \a IVSigned.
name|llvm
operator|::
name|Constant
operator|*
name|createDispatchNextFunction
argument_list|(
argument|unsigned IVSize
argument_list|,
argument|bool IVSigned
argument_list|)
expr_stmt|;
comment|/// \brief Returns __kmpc_dispatch_fini_* runtime function for the specified
comment|/// size \a IVSize and sign \a IVSigned.
name|llvm
operator|::
name|Constant
operator|*
name|createDispatchFiniFunction
argument_list|(
argument|unsigned IVSize
argument_list|,
argument|bool IVSigned
argument_list|)
expr_stmt|;
comment|/// \brief If the specified mangled name is not in the module, create and
comment|/// return threadprivate cache object. This object is a pointer's worth of
comment|/// storage that's reserved for use by the OpenMP runtime.
comment|/// \param VD Threadprivate variable.
comment|/// \return Cache variable for the specified threadprivate.
name|llvm
operator|::
name|Constant
operator|*
name|getOrCreateThreadPrivateCache
argument_list|(
specifier|const
name|VarDecl
operator|*
name|VD
argument_list|)
expr_stmt|;
comment|/// \brief Emits address of the word in a memory where current thread id is
comment|/// stored.
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|emitThreadIDAddress
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|SourceLocation Loc
argument_list|)
expr_stmt|;
comment|/// \brief Gets thread id value for the current thread.
comment|///
name|llvm
operator|::
name|Value
operator|*
name|getThreadID
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|SourceLocation Loc
argument_list|)
expr_stmt|;
comment|/// \brief Gets (if variable with the given name already exist) or creates
comment|/// internal global variable with the specified Name. The created variable has
comment|/// linkage CommonLinkage by default and is initialized by null value.
comment|/// \param Ty Type of the global variable. If it is exist already the type
comment|/// must be the same.
comment|/// \param Name Name of the variable.
name|llvm
operator|::
name|Constant
operator|*
name|getOrCreateInternalVariable
argument_list|(
name|llvm
operator|::
name|Type
operator|*
name|Ty
argument_list|,
specifier|const
name|llvm
operator|::
name|Twine
operator|&
name|Name
argument_list|)
expr_stmt|;
comment|/// \brief Set of threadprivate variables with the generated initializer.
name|llvm
operator|::
name|DenseSet
operator|<
specifier|const
name|VarDecl
operator|*
operator|>
name|ThreadPrivateWithDefinition
expr_stmt|;
comment|/// \brief Emits initialization code for the threadprivate variables.
comment|/// \param VDAddr Address of the global variable \a VD.
comment|/// \param Ctor Pointer to a global init function for \a VD.
comment|/// \param CopyCtor Pointer to a global copy function for \a VD.
comment|/// \param Dtor Pointer to a global destructor function for \a VD.
comment|/// \param Loc Location of threadprivate declaration.
name|void
name|emitThreadPrivateVarInit
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|VDAddr
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Ctor
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|CopyCtor
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Dtor
argument_list|,
name|SourceLocation
name|Loc
argument_list|)
decl_stmt|;
comment|/// \brief Returns corresponding lock object for the specified critical region
comment|/// name. If the lock object does not exist it is created, otherwise the
comment|/// reference to the existing copy is returned.
comment|/// \param CriticalName Name of the critical region.
comment|///
name|llvm
operator|::
name|Value
operator|*
name|getCriticalRegionLock
argument_list|(
argument|StringRef CriticalName
argument_list|)
expr_stmt|;
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
name|virtual
operator|~
name|CGOpenMPRuntime
argument_list|()
block|{}
name|virtual
name|void
name|clear
argument_list|()
expr_stmt|;
comment|/// \brief Emits outlined function for the specified OpenMP parallel directive
comment|/// \a D. This outlined function has type void(*)(kmp_int32 *ThreadID,
comment|/// kmp_int32 BoundID, struct context_vars*).
comment|/// \param D OpenMP directive.
comment|/// \param ThreadIDVar Variable for thread id in the current OpenMP region.
comment|/// \param CodeGen Code generation sequence for the \a D directive.
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|emitParallelOutlinedFunction
argument_list|(
specifier|const
name|OMPExecutableDirective
operator|&
name|D
argument_list|,
specifier|const
name|VarDecl
operator|*
name|ThreadIDVar
argument_list|,
specifier|const
name|RegionCodeGenTy
operator|&
name|CodeGen
argument_list|)
expr_stmt|;
comment|/// \brief Emits outlined function for the OpenMP task directive \a D. This
comment|/// outlined function has type void(*)(kmp_int32 ThreadID, kmp_int32
comment|/// PartID, struct context_vars*).
comment|/// \param D OpenMP directive.
comment|/// \param ThreadIDVar Variable for thread id in the current OpenMP region.
comment|/// \param CodeGen Code generation sequence for the \a D directive.
comment|///
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|emitTaskOutlinedFunction
argument_list|(
specifier|const
name|OMPExecutableDirective
operator|&
name|D
argument_list|,
specifier|const
name|VarDecl
operator|*
name|ThreadIDVar
argument_list|,
specifier|const
name|RegionCodeGenTy
operator|&
name|CodeGen
argument_list|)
expr_stmt|;
comment|/// \brief Cleans up references to the objects in finished function.
comment|///
name|void
name|functionFinished
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|)
function_decl|;
comment|/// \brief Emits code for parallel or serial call of the \a OutlinedFn with
comment|/// variables captured in a record which address is stored in \a
comment|/// CapturedStruct.
comment|/// \param OutlinedFn Outlined function to be run in parallel threads. Type of
comment|/// this function is void(*)(kmp_int32 *, kmp_int32, struct context_vars*).
comment|/// \param CapturedStruct A pointer to the record with the references to
comment|/// variables used in \a OutlinedFn function.
comment|/// \param IfCond Condition in the associated 'if' clause, if it was
comment|/// specified, nullptr otherwise.
comment|///
name|virtual
name|void
name|emitParallelCall
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|OutlinedFn
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|CapturedStruct
argument_list|,
specifier|const
name|Expr
operator|*
name|IfCond
argument_list|)
decl_stmt|;
comment|/// \brief Emits a critical region.
comment|/// \param CriticalName Name of the critical region.
comment|/// \param CriticalOpGen Generator for the statement associated with the given
comment|/// critical region.
name|virtual
name|void
name|emitCriticalRegion
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|StringRef
name|CriticalName
parameter_list|,
specifier|const
name|RegionCodeGenTy
modifier|&
name|CriticalOpGen
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
comment|/// \brief Emits a master region.
comment|/// \param MasterOpGen Generator for the statement associated with the given
comment|/// master region.
name|virtual
name|void
name|emitMasterRegion
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
specifier|const
name|RegionCodeGenTy
modifier|&
name|MasterOpGen
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
comment|/// \brief Emits code for a taskyield directive.
name|virtual
name|void
name|emitTaskyieldCall
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
comment|/// \brief Emits a single region.
comment|/// \param SingleOpGen Generator for the statement associated with the given
comment|/// single region.
name|virtual
name|void
name|emitSingleRegion
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
specifier|const
name|RegionCodeGenTy
operator|&
name|SingleOpGen
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|CopyprivateVars
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|DestExprs
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|SrcExprs
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|AssignmentOps
argument_list|)
decl_stmt|;
comment|/// \brief Emit an ordered region.
comment|/// \param OrderedOpGen Generator for the statement associated with the given
comment|/// critical region.
name|virtual
name|void
name|emitOrderedRegion
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
specifier|const
name|RegionCodeGenTy
modifier|&
name|OrderedOpGen
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
comment|/// \brief Emit an implicit/explicit barrier for OpenMP threads.
comment|/// \param Kind Directive for which this implicit barrier call must be
comment|/// generated. Must be OMPD_barrier for explicit barrier generation.
comment|///
name|virtual
name|void
name|emitBarrierCall
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|OpenMPDirectiveKind
name|Kind
parameter_list|)
function_decl|;
comment|/// \brief Check if the specified \a ScheduleKind is static non-chunked.
comment|/// This kind of worksharing directive is emitted without outer loop.
comment|/// \param ScheduleKind Schedule kind specified in the 'schedule' clause.
comment|/// \param Chunked True if chunk is specified in the clause.
comment|///
name|virtual
name|bool
name|isStaticNonchunked
argument_list|(
name|OpenMPScheduleClauseKind
name|ScheduleKind
argument_list|,
name|bool
name|Chunked
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Check if the specified \a ScheduleKind is dynamic.
comment|/// This kind of worksharing directive is emitted without outer loop.
comment|/// \param ScheduleKind Schedule Kind specified in the 'schedule' clause.
comment|///
name|virtual
name|bool
name|isDynamic
argument_list|(
name|OpenMPScheduleClauseKind
name|ScheduleKind
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Call the appropriate runtime routine to initialize it before start
comment|/// of loop.
comment|///
comment|/// Depending on the loop schedule, it is nesessary to call some runtime
comment|/// routine before start of the OpenMP loop to get the loop upper / lower
comment|/// bounds \a LB and \a UB and stride \a ST.
comment|///
comment|/// \param CGF Reference to current CodeGenFunction.
comment|/// \param Loc Clang source location.
comment|/// \param SchedKind Schedule kind, specified by the 'schedule' clause.
comment|/// \param IVSize Size of the iteration variable in bits.
comment|/// \param IVSigned Sign of the interation variable.
comment|/// \param Ordered true if loop is ordered, false otherwise.
comment|/// \param IL Address of the output variable in which the flag of the
comment|/// last iteration is returned.
comment|/// \param LB Address of the output variable in which the lower iteration
comment|/// number is returned.
comment|/// \param UB Address of the output variable in which the upper iteration
comment|/// number is returned.
comment|/// \param ST Address of the output variable in which the stride value is
comment|/// returned nesessary to generated the static_chunked scheduled loop.
comment|/// \param Chunk Value of the chunk for the static_chunked scheduled loop.
comment|/// For the default (nullptr) value, the chunk 1 will be used.
comment|///
name|virtual
name|void
name|emitForInit
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
name|OpenMPScheduleClauseKind
name|SchedKind
argument_list|,
name|unsigned
name|IVSize
argument_list|,
name|bool
name|IVSigned
argument_list|,
name|bool
name|Ordered
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|IL
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|LB
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|UB
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|ST
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Chunk
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|/// \brief Call the appropriate runtime routine to notify that we finished
comment|/// iteration of the ordered loop with the dynamic scheduling.
comment|///
comment|/// \param CGF Reference to current CodeGenFunction.
comment|/// \param Loc Clang source location.
comment|/// \param IVSize Size of the iteration variable in bits.
comment|/// \param IVSigned Sign of the interation variable.
comment|///
name|virtual
name|void
name|emitForOrderedIterationEnd
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|unsigned
name|IVSize
parameter_list|,
name|bool
name|IVSigned
parameter_list|)
function_decl|;
comment|/// \brief Call the appropriate runtime routine to notify that we finished
comment|/// all the work with current loop.
comment|///
comment|/// \param CGF Reference to current CodeGenFunction.
comment|/// \param Loc Clang source location.
comment|///
name|virtual
name|void
name|emitForStaticFinish
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
comment|/// Call __kmpc_dispatch_next(
comment|///          ident_t *loc, kmp_int32 tid, kmp_int32 *p_lastiter,
comment|///          kmp_int[32|64] *p_lower, kmp_int[32|64] *p_upper,
comment|///          kmp_int[32|64] *p_stride);
comment|/// \param IVSize Size of the iteration variable in bits.
comment|/// \param IVSigned Sign of the interation variable.
comment|/// \param IL Address of the output variable in which the flag of the
comment|/// last iteration is returned.
comment|/// \param LB Address of the output variable in which the lower iteration
comment|/// number is returned.
comment|/// \param UB Address of the output variable in which the upper iteration
comment|/// number is returned.
comment|/// \param ST Address of the output variable in which the stride value is
comment|/// returned.
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|emitForNext
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|unsigned IVSize
argument_list|,
argument|bool IVSigned
argument_list|,
argument|llvm::Value *IL
argument_list|,
argument|llvm::Value *LB
argument_list|,
argument|llvm::Value *UB
argument_list|,
argument|llvm::Value *ST
argument_list|)
expr_stmt|;
comment|/// \brief Emits call to void __kmpc_push_num_threads(ident_t *loc, kmp_int32
comment|/// global_tid, kmp_int32 num_threads) to generate code for 'num_threads'
comment|/// clause.
comment|/// \param NumThreads An integer value of threads.
name|virtual
name|void
name|emitNumThreadsClause
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|NumThreads
argument_list|,
name|SourceLocation
name|Loc
argument_list|)
decl_stmt|;
comment|/// \brief Returns address of the threadprivate variable for the current
comment|/// thread.
comment|/// \param VD Threadprivate variable.
comment|/// \param VDAddr Address of the global variable \a VD.
comment|/// \param Loc Location of the reference to threadprivate var.
comment|/// \return Address of the threadprivate variable for the current thread.
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|getAddrOfThreadPrivate
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|const VarDecl *VD
argument_list|,
argument|llvm::Value *VDAddr
argument_list|,
argument|SourceLocation Loc
argument_list|)
expr_stmt|;
comment|/// \brief Emit a code for initialization of threadprivate variable. It emits
comment|/// a call to runtime library which adds initial value to the newly created
comment|/// threadprivate variable (if it is not constant) and registers destructor
comment|/// for the variable (if any).
comment|/// \param VD Threadprivate variable.
comment|/// \param VDAddr Address of the global variable \a VD.
comment|/// \param Loc Location of threadprivate declaration.
comment|/// \param PerformInit true if initialization expression is not constant.
name|virtual
name|llvm
operator|::
name|Function
operator|*
name|emitThreadPrivateVarDefinition
argument_list|(
argument|const VarDecl *VD
argument_list|,
argument|llvm::Value *VDAddr
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|bool PerformInit
argument_list|,
argument|CodeGenFunction *CGF = nullptr
argument_list|)
expr_stmt|;
comment|/// \brief Emit flush of the variables specified in 'omp flush' directive.
comment|/// \param Vars List of variables to flush.
name|virtual
name|void
name|emitFlush
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|Vars
argument_list|,
name|SourceLocation
name|Loc
argument_list|)
decl_stmt|;
comment|/// \brief Emit task region for the task directive. The task region is
comment|/// emitted in several steps:
comment|/// 1. Emit a call to kmp_task_t *__kmpc_omp_task_alloc(ident_t *, kmp_int32
comment|/// gtid, kmp_int32 flags, size_t sizeof_kmp_task_t, size_t sizeof_shareds,
comment|/// kmp_routine_entry_t *task_entry). Here task_entry is a pointer to the
comment|/// function:
comment|/// kmp_int32 .omp_task_entry.(kmp_int32 gtid, kmp_task_t *tt) {
comment|///   TaskFunction(gtid, tt->part_id, tt->shareds);
comment|///   return 0;
comment|/// }
comment|/// 2. Copy a list of shared variables to field shareds of the resulting
comment|/// structure kmp_task_t returned by the previous call (if any).
comment|/// 3. Copy a pointer to destructions function to field destructions of the
comment|/// resulting structure kmp_task_t.
comment|/// 4. Emit a call to kmp_int32 __kmpc_omp_task(ident_t *, kmp_int32 gtid,
comment|/// kmp_task_t *new_task), where new_task is a resulting structure from
comment|/// previous items.
comment|/// \param D Current task directive.
comment|/// \param Tied true if the task is tied (the task is tied to the thread that
comment|/// can suspend its task region), false - untied (the task is not tied to any
comment|/// thread).
comment|/// \param Final Contains either constant bool value, or llvm::Value * of i1
comment|/// type for final clause. If the value is true, the task forces all of its
comment|/// child tasks to become final and included tasks.
comment|/// \param TaskFunction An LLVM function with type void (*)(i32 /*gtid*/, i32
comment|/// /*part_id*/, captured_struct */*__context*/);
comment|/// \param SharedsTy A type which contains references the shared variables.
comment|/// \param Shareds Context with the list of shared variables from the \a
comment|/// TaskFunction.
comment|/// \param IfCond Not a nullptr if 'if' clause was specified, nullptr
comment|/// otherwise.
comment|/// \param PrivateVars List of references to private variables for the task
comment|/// directive.
comment|/// \param PrivateCopies List of private copies for each private variable in
comment|/// \p PrivateVars.
comment|/// \param FirstprivateVars List of references to private variables for the
comment|/// task directive.
comment|/// \param FirstprivateCopies List of private copies for each private variable
comment|/// in \p FirstprivateVars.
comment|/// \param FirstprivateInits List of references to auto generated variables
comment|/// used for initialization of a single array element. Used if firstprivate
comment|/// variable is of array type.
name|virtual
name|void
name|emitTaskCall
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
specifier|const
name|OMPExecutableDirective
operator|&
name|D
argument_list|,
name|bool
name|Tied
argument_list|,
name|llvm
operator|::
name|PointerIntPair
operator|<
name|llvm
operator|::
name|Value
operator|*
argument_list|,
literal|1
argument_list|,
name|bool
operator|>
name|Final
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|TaskFunction
argument_list|,
name|QualType
name|SharedsTy
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Shareds
argument_list|,
specifier|const
name|Expr
operator|*
name|IfCond
argument_list|,
specifier|const
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|PrivateVars
argument_list|,
specifier|const
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|PrivateCopies
argument_list|,
specifier|const
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|FirstprivateVars
argument_list|,
specifier|const
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|FirstprivateCopies
argument_list|,
specifier|const
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|FirstprivateInits
argument_list|)
decl_stmt|;
comment|/// \brief Emit code for the directive that does not require outlining.
comment|///
comment|/// \param CodeGen Code generation sequence for the \a D directive.
name|virtual
name|void
name|emitInlinedDirective
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
specifier|const
name|RegionCodeGenTy
modifier|&
name|CodeGen
parameter_list|)
function_decl|;
comment|/// \brief Emit a code for reduction clause. Next code should be emitted for
comment|/// reduction:
comment|/// \code
comment|///
comment|/// static kmp_critical_name lock = { 0 };
comment|///
comment|/// void reduce_func(void *lhs[<n>], void *rhs[<n>]) {
comment|///  ...
comment|///  *(Type<i>*)lhs[i] = RedOp<i>(*(Type<i>*)lhs[i], *(Type<i>*)rhs[i]);
comment|///  ...
comment|/// }
comment|///
comment|/// ...
comment|/// void *RedList[<n>] = {&<RHSExprs>[0], ...,&<RHSExprs>[<n>-1]};
comment|/// switch (__kmpc_reduce{_nowait}(<loc>,<gtid>,<n>, sizeof(RedList),
comment|/// RedList, reduce_func,&<lock>)) {
comment|/// case 1:
comment|///  ...
comment|///<LHSExprs>[i] = RedOp<i>(*<LHSExprs>[i], *<RHSExprs>[i]);
comment|///  ...
comment|/// __kmpc_end_reduce{_nowait}(<loc>,<gtid>,&<lock>);
comment|/// break;
comment|/// case 2:
comment|///  ...
comment|///  Atomic(<LHSExprs>[i] = RedOp<i>(*<LHSExprs>[i], *<RHSExprs>[i]));
comment|///  ...
comment|/// break;
comment|/// default:;
comment|/// }
comment|/// \endcode
comment|///
comment|/// \param LHSExprs List of LHS in \a ReductionOps reduction operations.
comment|/// \param RHSExprs List of RHS in \a ReductionOps reduction operations.
comment|/// \param ReductionOps List of reduction operations in form 'LHS binop RHS'
comment|/// or 'operator binop(LHS, RHS)'.
comment|/// \param WithNowait true if parent directive has also nowait clause, false
comment|/// otherwise.
name|virtual
name|void
name|emitReduction
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|LHSExprs
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|RHSExprs
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|ReductionOps
argument_list|,
name|bool
name|WithNowait
argument_list|)
decl_stmt|;
comment|/// \brief Emit code for 'taskwait' directive.
name|virtual
name|void
name|emitTaskwaitCall
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
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

