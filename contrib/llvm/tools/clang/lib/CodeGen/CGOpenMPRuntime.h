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
name|class
name|CGOpenMPRuntime
block|{
name|public
label|:
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
comment|// Calls for static scheduling 'omp for' loops.
name|OMPRTL__kmpc_for_static_init_4
block|,
name|OMPRTL__kmpc_for_static_init_4u
block|,
name|OMPRTL__kmpc_for_static_init_8
block|,
name|OMPRTL__kmpc_for_static_init_8u
block|,
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
comment|// Call to void __kmpc_flush(ident_t *loc, ...);
name|OMPRTL__kmpc_flush
block|,
comment|// Call to kmp_int32 __kmpc_master(ident_t *, kmp_int32 global_tid);
name|OMPRTL__kmpc_master
block|,
comment|// Call to void __kmpc_end_master(ident_t *, kmp_int32 global_tid);
name|OMPRTL__kmpc_end_master
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
comment|/// \brief Emits object of ident_t type with info for source location.
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
name|CreateRuntimeFunction
argument_list|(
argument|OpenMPRTLFunction Function
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
name|EmitThreadIDAddress
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
name|GetOpenMPThreadID
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
name|GetOrCreateInternalVariable
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
name|EmitOMPThreadPrivateVarInit
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
name|GetCriticalRegionLock
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
comment|/// \brief Emits outlined function for the specified OpenMP directive \a D
comment|/// (required for parallel and task directives). This outlined function has
comment|/// type void(*)(kmp_int32 /*ThreadID*/, kmp_int32 /*BoundID*/, struct
comment|/// context_vars*).
comment|/// \param D OpenMP directive.
comment|/// \param ThreadIDVar Variable for thread id in the current OpenMP region.
comment|///
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|EmitOpenMPOutlinedFunction
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
argument_list|)
expr_stmt|;
comment|/// \brief Cleans up references to the objects in finished function.
comment|///
name|void
name|FunctionFinished
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|)
function_decl|;
comment|/// \brief Emits code for parallel call of the \a OutlinedFn with variables
comment|/// captured in a record which address is stored in \a CapturedStruct.
comment|/// \param OutlinedFn Outlined function to be run in parallel threads. Type of
comment|/// this function is void(*)(kmp_int32, kmp_int32, struct context_vars*).
comment|/// \param CapturedStruct A pointer to the record with the references to
comment|/// variables used in \a OutlinedFn function.
comment|///
name|virtual
name|void
name|EmitOMPParallelCall
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
argument_list|)
decl_stmt|;
comment|/// \brief Emits code for serial call of the \a OutlinedFn with variables
comment|/// captured in a record which address is stored in \a CapturedStruct.
comment|/// \param OutlinedFn Outlined function to be run in serial mode.
comment|/// \param CapturedStruct A pointer to the record with the references to
comment|/// variables used in \a OutlinedFn function.
comment|///
name|virtual
name|void
name|EmitOMPSerialCall
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
argument_list|)
decl_stmt|;
comment|/// \brief Emits a critical region.
comment|/// \param CriticalName Name of the critical region.
comment|/// \param CriticalOpGen Generator for the statement associated with the given
comment|/// critical region.
name|virtual
name|void
name|EmitOMPCriticalRegion
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|StringRef
name|CriticalName
argument_list|,
specifier|const
name|std
operator|::
name|function
operator|<
name|void
argument_list|()
operator|>
operator|&
name|CriticalOpGen
argument_list|,
name|SourceLocation
name|Loc
argument_list|)
decl_stmt|;
comment|/// \brief Emits a master region.
comment|/// \param MasterOpGen Generator for the statement associated with the given
comment|/// master region.
name|virtual
name|void
name|EmitOMPMasterRegion
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
specifier|const
name|std
operator|::
name|function
operator|<
name|void
argument_list|()
operator|>
operator|&
name|MasterOpGen
argument_list|,
name|SourceLocation
name|Loc
argument_list|)
decl_stmt|;
comment|/// \brief Emits explicit barrier for OpenMP threads.
comment|/// \param IsExplicit true, if it is explicitly specified barrier.
comment|///
name|virtual
name|void
name|EmitOMPBarrierCall
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|bool
name|IsExplicit
init|=
name|true
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
name|EmitOMPForInit
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
comment|/// all the work with current loop.
comment|///
comment|/// \param CGF Reference to current CodeGenFunction.
comment|/// \param Loc Clang source location.
comment|/// \param ScheduleKind Schedule kind, specified by the 'schedule' clause.
comment|///
name|virtual
name|void
name|EmitOMPForFinish
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|OpenMPScheduleClauseKind
name|ScheduleKind
parameter_list|)
function_decl|;
comment|/// \brief Emits call to void __kmpc_push_num_threads(ident_t *loc, kmp_int32
comment|/// global_tid, kmp_int32 num_threads) to generate code for 'num_threads'
comment|/// clause.
comment|/// \param NumThreads An integer value of threads.
name|virtual
name|void
name|EmitOMPNumThreadsClause
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
name|getOMPAddrOfThreadPrivate
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
name|EmitOMPThreadPrivateVarDefinition
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
name|EmitOMPFlush
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

