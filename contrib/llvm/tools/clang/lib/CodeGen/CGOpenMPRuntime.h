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
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
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
name|GlobalDecl
decl_stmt|;
name|class
name|OMPDependClause
decl_stmt|;
name|class
name|OMPExecutableDirective
decl_stmt|;
name|class
name|OMPLoopDirective
decl_stmt|;
name|class
name|VarDecl
decl_stmt|;
name|class
name|OMPDeclareReductionDecl
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|Address
decl_stmt|;
name|class
name|CodeGenFunction
decl_stmt|;
name|class
name|CodeGenModule
decl_stmt|;
comment|/// A basic class for pre|post-action for advanced codegen sequence for OpenMP
comment|/// region.
name|class
name|PrePostActionTy
block|{
name|public
label|:
name|explicit
name|PrePostActionTy
parameter_list|()
block|{}
name|virtual
name|void
name|Enter
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|)
block|{}
name|virtual
name|void
name|Exit
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|)
block|{}
name|virtual
operator|~
name|PrePostActionTy
argument_list|()
block|{}
block|}
empty_stmt|;
comment|/// Class provides a way to call simple version of codegen for OpenMP region, or
comment|/// an advanced with possible pre|post-actions in codegen.
name|class
name|RegionCodeGenTy
name|final
block|{
name|intptr_t
name|CodeGen
decl_stmt|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|CodeGenTy
function_decl|)
parameter_list|(
name|intptr_t
parameter_list|,
name|CodeGenFunction
modifier|&
parameter_list|,
name|PrePostActionTy
modifier|&
parameter_list|)
function_decl|;
name|CodeGenTy
name|Callback
decl_stmt|;
name|mutable
name|PrePostActionTy
modifier|*
name|PrePostAction
decl_stmt|;
name|RegionCodeGenTy
argument_list|()
operator|=
name|delete
expr_stmt|;
name|RegionCodeGenTy
modifier|&
name|operator
init|=
operator|(
specifier|const
name|RegionCodeGenTy
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|template
operator|<
name|typename
name|Callable
operator|>
specifier|static
name|void
name|CallbackFn
argument_list|(
argument|intptr_t CodeGen
argument_list|,
argument|CodeGenFunction&CGF
argument_list|,
argument|PrePostActionTy&Action
argument_list|)
block|{
return|return
operator|(
operator|*
name|reinterpret_cast
operator|<
name|Callable
operator|*
operator|>
operator|(
name|CodeGen
operator|)
operator|)
operator|(
name|CGF
operator|,
name|Action
operator|)
return|;
block|}
name|public
label|:
name|template
operator|<
name|typename
name|Callable
operator|>
name|RegionCodeGenTy
argument_list|(
argument|Callable&&CodeGen
argument_list|,
argument|typename std::enable_if<           !std::is_same<typename std::remove_reference<Callable>::type
argument_list|,
argument|RegionCodeGenTy>::value>::type * = nullptr
argument_list|)
operator|:
name|CodeGen
argument_list|(
name|reinterpret_cast
operator|<
name|intptr_t
operator|>
operator|(
operator|&
name|CodeGen
operator|)
argument_list|)
operator|,
name|Callback
argument_list|(
argument|CallbackFn<typename std::remove_reference<Callable>::type>
argument_list|)
operator|,
name|PrePostAction
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|void
name|setAction
argument_list|(
argument|PrePostActionTy&Action
argument_list|)
specifier|const
block|{
name|PrePostAction
operator|=
operator|&
name|Action
block|; }
name|void
name|operator
argument_list|()
operator|(
name|CodeGenFunction
operator|&
name|CGF
operator|)
specifier|const
expr_stmt|;
block|}
empty_stmt|;
struct|struct
name|OMPTaskDataTy
name|final
block|{
name|SmallVector
operator|<
specifier|const
name|Expr
operator|*
operator|,
literal|4
operator|>
name|PrivateVars
expr_stmt|;
name|SmallVector
operator|<
specifier|const
name|Expr
operator|*
operator|,
literal|4
operator|>
name|PrivateCopies
expr_stmt|;
name|SmallVector
operator|<
specifier|const
name|Expr
operator|*
operator|,
literal|4
operator|>
name|FirstprivateVars
expr_stmt|;
name|SmallVector
operator|<
specifier|const
name|Expr
operator|*
operator|,
literal|4
operator|>
name|FirstprivateCopies
expr_stmt|;
name|SmallVector
operator|<
specifier|const
name|Expr
operator|*
operator|,
literal|4
operator|>
name|FirstprivateInits
expr_stmt|;
name|SmallVector
operator|<
specifier|const
name|Expr
operator|*
operator|,
literal|4
operator|>
name|LastprivateVars
expr_stmt|;
name|SmallVector
operator|<
specifier|const
name|Expr
operator|*
operator|,
literal|4
operator|>
name|LastprivateCopies
expr_stmt|;
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|OpenMPDependClauseKind
operator|,
specifier|const
name|Expr
operator|*
operator|>
operator|,
literal|4
operator|>
name|Dependences
expr_stmt|;
name|llvm
operator|::
name|PointerIntPair
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|Final
expr_stmt|;
name|llvm
operator|::
name|PointerIntPair
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|Schedule
expr_stmt|;
name|llvm
operator|::
name|PointerIntPair
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|Priority
expr_stmt|;
name|unsigned
name|NumberOfParts
init|=
literal|0
decl_stmt|;
name|bool
name|Tied
init|=
name|true
decl_stmt|;
name|bool
name|Nogroup
init|=
name|false
decl_stmt|;
block|}
struct|;
name|class
name|CGOpenMPRuntime
block|{
name|protected
label|:
name|CodeGenModule
modifier|&
name|CGM
decl_stmt|;
comment|/// \brief Creates offloading entry for the provided entry ID \a ID,
comment|/// address \a Addr, size \a Size, and flags \a Flags.
name|virtual
name|void
name|createOffloadEntry
argument_list|(
name|llvm
operator|::
name|Constant
operator|*
name|ID
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|Addr
argument_list|,
name|uint64_t
name|Size
argument_list|,
name|int32_t
name|Flags
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// \brief Helper to emit outlined function for 'target' directive.
comment|/// \param D Directive to emit.
comment|/// \param ParentName Name of the function that encloses the target region.
comment|/// \param OutlinedFn Outlined function value to be defined by this call.
comment|/// \param OutlinedFnID Outlined function ID value to be defined by this call.
comment|/// \param IsOffloadEntry True if the outlined function is an offload entry.
comment|/// \param CodeGen Lambda codegen specific to an accelerator device.
comment|/// An oulined function may not be an entry if, e.g. the if clause always
comment|/// evaluates to false.
name|virtual
name|void
name|emitTargetOutlinedFunctionHelper
argument_list|(
specifier|const
name|OMPExecutableDirective
operator|&
name|D
argument_list|,
name|StringRef
name|ParentName
argument_list|,
name|llvm
operator|::
name|Function
operator|*
operator|&
name|OutlinedFn
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
operator|&
name|OutlinedFnID
argument_list|,
name|bool
name|IsOffloadEntry
argument_list|,
specifier|const
name|RegionCodeGenTy
operator|&
name|CodeGen
argument_list|)
decl_stmt|;
comment|/// \brief Emits code for OpenMP 'if' clause using specified \a CodeGen
comment|/// function. Here is the logic:
comment|/// if (Cond) {
comment|///   ThenGen();
comment|/// } else {
comment|///   ElseGen();
comment|/// }
name|void
name|emitOMPIfClause
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
specifier|const
name|Expr
modifier|*
name|Cond
parameter_list|,
specifier|const
name|RegionCodeGenTy
modifier|&
name|ThenGen
parameter_list|,
specifier|const
name|RegionCodeGenTy
modifier|&
name|ElseGen
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
argument|unsigned Flags =
literal|0
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
comment|/// \brief Get the function name of an outlined region.
comment|//  The name can be customized depending on the target.
comment|//
name|virtual
name|StringRef
name|getOutlinedHelperName
argument_list|()
specifier|const
block|{
return|return
literal|".omp_outlined."
return|;
block|}
name|private
label|:
comment|/// \brief Default const ident_t object used for initialization of all other
comment|/// ident_t objects.
name|llvm
operator|::
name|Constant
operator|*
name|DefaultOpenMPPSource
operator|=
name|nullptr
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
name|Address
name|getOrCreateDefaultLocation
parameter_list|(
name|unsigned
name|Flags
parameter_list|)
function_decl|;
name|llvm
operator|::
name|StructType
operator|*
name|IdentTy
operator|=
name|nullptr
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
operator|=
name|nullptr
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
comment|/// Map of UDRs and corresponding combiner/initializer.
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|OMPDeclareReductionDecl
operator|*
operator|,
name|std
operator|::
name|pair
operator|<
name|llvm
operator|::
name|Function
operator|*
operator|,
name|llvm
operator|::
name|Function
operator|*
operator|>>
name|UDRMapTy
expr_stmt|;
name|UDRMapTy
name|UDRMap
decl_stmt|;
comment|/// Map of functions and locally defined UDRs.
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
name|SmallVector
operator|<
specifier|const
name|OMPDeclareReductionDecl
operator|*
operator|,
literal|4
operator|>>
name|FunctionUDRMapTy
expr_stmt|;
name|FunctionUDRMapTy
name|FunctionUDRMap
decl_stmt|;
name|IdentifierInfo
modifier|*
name|In
init|=
name|nullptr
decl_stmt|;
name|IdentifierInfo
modifier|*
name|Out
init|=
name|nullptr
decl_stmt|;
name|IdentifierInfo
modifier|*
name|Priv
init|=
name|nullptr
decl_stmt|;
name|IdentifierInfo
modifier|*
name|Orig
init|=
name|nullptr
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
operator|=
name|nullptr
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
comment|/// \brief Type typedef struct kmp_depend_info {
comment|///    kmp_intptr_t               base_addr;
comment|///    size_t                     len;
comment|///    struct {
comment|///             bool                   in:1;
comment|///             bool                   out:1;
comment|///    } flags;
comment|/// } kmp_depend_info_t;
name|QualType
name|KmpDependInfoTy
decl_stmt|;
comment|/// struct kmp_dim {  // loop bounds info casted to kmp_int64
comment|///  kmp_int64 lo; // lower
comment|///  kmp_int64 up; // upper
comment|///  kmp_int64 st; // stride
comment|/// };
name|QualType
name|KmpDimTy
decl_stmt|;
comment|/// \brief Type struct __tgt_offload_entry{
comment|///   void      *addr;       // Pointer to the offload entry info.
comment|///                          // (function or global)
comment|///   char      *name;       // Name of the function or global.
comment|///   size_t     size;       // Size of the entry info (0 if it a function).
comment|/// };
name|QualType
name|TgtOffloadEntryQTy
decl_stmt|;
comment|/// struct __tgt_device_image{
comment|/// void   *ImageStart;       // Pointer to the target code start.
comment|/// void   *ImageEnd;         // Pointer to the target code end.
comment|/// // We also add the host entries to the device image, as it may be useful
comment|/// // for the target runtime to have access to that information.
comment|/// __tgt_offload_entry  *EntriesBegin;   // Begin of the table with all
comment|///                                       // the entries.
comment|/// __tgt_offload_entry  *EntriesEnd;     // End of the table with all the
comment|///                                       // entries (non inclusive).
comment|/// };
name|QualType
name|TgtDeviceImageQTy
decl_stmt|;
comment|/// struct __tgt_bin_desc{
comment|///   int32_t              NumDevices;      // Number of devices supported.
comment|///   __tgt_device_image   *DeviceImages;   // Arrays of device images
comment|///                                         // (one per device).
comment|///   __tgt_offload_entry  *EntriesBegin;   // Begin of the table with all the
comment|///                                         // entries.
comment|///   __tgt_offload_entry  *EntriesEnd;     // End of the table with all the
comment|///                                         // entries (non inclusive).
comment|/// };
name|QualType
name|TgtBinaryDescriptorQTy
decl_stmt|;
comment|/// \brief Entity that registers the offloading constants that were emitted so
comment|/// far.
name|class
name|OffloadEntriesInfoManagerTy
block|{
name|CodeGenModule
modifier|&
name|CGM
decl_stmt|;
comment|/// \brief Number of entries registered so far.
name|unsigned
name|OffloadingEntriesNum
decl_stmt|;
name|public
label|:
comment|/// Base class of the entries info.
name|class
name|OffloadEntryInfo
block|{
name|public
label|:
comment|/// Kind of a given entry. Currently, only target regions are
comment|/// supported.
enum|enum
name|OffloadingEntryInfoKinds
enum|:
name|unsigned
block|{
comment|// Entry is a target region.
name|OFFLOAD_ENTRY_INFO_TARGET_REGION
init|=
literal|0
block|,
comment|// Invalid entry info.
name|OFFLOAD_ENTRY_INFO_INVALID
init|=
operator|~
literal|0u
block|}
enum|;
name|OffloadEntryInfo
argument_list|()
operator|:
name|Flags
argument_list|(
literal|0
argument_list|)
operator|,
name|Order
argument_list|(
operator|~
literal|0u
argument_list|)
operator|,
name|Kind
argument_list|(
argument|OFFLOAD_ENTRY_INFO_INVALID
argument_list|)
block|{}
name|explicit
name|OffloadEntryInfo
argument_list|(
argument|OffloadingEntryInfoKinds Kind
argument_list|,
argument|unsigned Order
argument_list|,
argument|int32_t Flags
argument_list|)
operator|:
name|Flags
argument_list|(
name|Flags
argument_list|)
operator|,
name|Order
argument_list|(
name|Order
argument_list|)
operator|,
name|Kind
argument_list|(
argument|Kind
argument_list|)
block|{}
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|Order
operator|!=
operator|~
literal|0u
return|;
block|}
name|unsigned
name|getOrder
argument_list|()
specifier|const
block|{
return|return
name|Order
return|;
block|}
name|OffloadingEntryInfoKinds
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
name|int32_t
name|getFlags
argument_list|()
specifier|const
block|{
return|return
name|Flags
return|;
block|}
name|void
name|setFlags
parameter_list|(
name|int32_t
name|NewFlags
parameter_list|)
block|{
name|Flags
operator|=
name|NewFlags
expr_stmt|;
block|}
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|OffloadEntryInfo
modifier|*
name|Info
parameter_list|)
block|{
return|return
name|true
return|;
block|}
name|private
label|:
comment|/// Flags associated with the device global.
name|int32_t
name|Flags
decl_stmt|;
comment|/// Order this entry was emitted.
name|unsigned
name|Order
decl_stmt|;
name|OffloadingEntryInfoKinds
name|Kind
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief Return true if a there are no entries defined.
name|bool
name|empty
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Return number of entries defined so far.
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|OffloadingEntriesNum
return|;
block|}
name|OffloadEntriesInfoManagerTy
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|)
operator|:
name|CGM
argument_list|(
name|CGM
argument_list|)
operator|,
name|OffloadingEntriesNum
argument_list|(
literal|0
argument_list|)
block|{}
comment|///
comment|/// Target region entries related.
comment|///
comment|/// \brief Target region entries info.
name|class
name|OffloadEntryInfoTargetRegion
operator|:
name|public
name|OffloadEntryInfo
block|{
comment|// \brief Address of the entity that has to be mapped for offloading.
name|llvm
operator|::
name|Constant
operator|*
name|Addr
block|;
comment|// \brief Address that can be used as the ID of the entry.
name|llvm
operator|::
name|Constant
operator|*
name|ID
block|;
name|public
operator|:
name|OffloadEntryInfoTargetRegion
argument_list|()
operator|:
name|OffloadEntryInfo
argument_list|(
name|OFFLOAD_ENTRY_INFO_TARGET_REGION
argument_list|,
operator|~
literal|0u
argument_list|,
comment|/*Flags=*/
literal|0
argument_list|)
block|,
name|Addr
argument_list|(
name|nullptr
argument_list|)
block|,
name|ID
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|explicit
name|OffloadEntryInfoTargetRegion
argument_list|(
argument|unsigned Order
argument_list|,
argument|llvm::Constant *Addr
argument_list|,
argument|llvm::Constant *ID
argument_list|,
argument|int32_t Flags
argument_list|)
operator|:
name|OffloadEntryInfo
argument_list|(
name|OFFLOAD_ENTRY_INFO_TARGET_REGION
argument_list|,
name|Order
argument_list|,
name|Flags
argument_list|)
block|,
name|Addr
argument_list|(
name|Addr
argument_list|)
block|,
name|ID
argument_list|(
argument|ID
argument_list|)
block|{}
name|llvm
operator|::
name|Constant
operator|*
name|getAddress
argument_list|()
specifier|const
block|{
return|return
name|Addr
return|;
block|}
name|llvm
operator|::
name|Constant
operator|*
name|getID
argument_list|()
specifier|const
block|{
return|return
name|ID
return|;
block|}
name|void
name|setAddress
argument_list|(
argument|llvm::Constant *V
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|Addr
operator|&&
literal|"Address as been set before!"
argument_list|)
block|;
name|Addr
operator|=
name|V
block|;       }
name|void
name|setID
argument_list|(
argument|llvm::Constant *V
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|ID
operator|&&
literal|"ID as been set before!"
argument_list|)
block|;
name|ID
operator|=
name|V
block|;       }
specifier|static
name|bool
name|classof
argument_list|(
argument|const OffloadEntryInfo *Info
argument_list|)
block|{
return|return
name|Info
operator|->
name|getKind
argument_list|()
operator|==
name|OFFLOAD_ENTRY_INFO_TARGET_REGION
return|;
block|}
expr|}
block|;
comment|/// \brief Initialize target region entry.
name|void
name|initializeTargetRegionEntryInfo
argument_list|(
argument|unsigned DeviceID
argument_list|,
argument|unsigned FileID
argument_list|,
argument|StringRef ParentName
argument_list|,
argument|unsigned LineNum
argument_list|,
argument|unsigned Order
argument_list|)
block|;
comment|/// \brief Register target region entry.
name|void
name|registerTargetRegionEntryInfo
argument_list|(
argument|unsigned DeviceID
argument_list|,
argument|unsigned FileID
argument_list|,
argument|StringRef ParentName
argument_list|,
argument|unsigned LineNum
argument_list|,
argument|llvm::Constant *Addr
argument_list|,
argument|llvm::Constant *ID
argument_list|,
argument|int32_t Flags
argument_list|)
block|;
comment|/// \brief Return true if a target region entry with the provided
comment|/// information exists.
name|bool
name|hasTargetRegionEntryInfo
argument_list|(
argument|unsigned DeviceID
argument_list|,
argument|unsigned FileID
argument_list|,
argument|StringRef ParentName
argument_list|,
argument|unsigned LineNum
argument_list|)
specifier|const
block|;
comment|/// brief Applies action \a Action on all registered entries.
typedef|typedef
name|llvm
operator|::
name|function_ref
operator|<
name|void
argument_list|(
name|unsigned
argument_list|,
name|unsigned
argument_list|,
name|StringRef
argument_list|,
name|unsigned
argument_list|,
name|OffloadEntryInfoTargetRegion
operator|&
argument_list|)
operator|>
name|OffloadTargetRegionEntryInfoActTy
expr_stmt|;
name|void
name|actOnTargetRegionEntriesInfo
argument_list|(
specifier|const
name|OffloadTargetRegionEntryInfoActTy
operator|&
name|Action
argument_list|)
expr_stmt|;
name|private
label|:
comment|// Storage for target region entries kind. The storage is to be indexed by
comment|// file ID, device ID, parent function name and line number.
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|unsigned
operator|,
name|OffloadEntryInfoTargetRegion
operator|>
name|OffloadEntriesTargetRegionPerLine
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|StringMap
operator|<
name|OffloadEntriesTargetRegionPerLine
operator|>
name|OffloadEntriesTargetRegionPerParentName
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|unsigned
operator|,
name|OffloadEntriesTargetRegionPerParentName
operator|>
name|OffloadEntriesTargetRegionPerFile
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|unsigned
operator|,
name|OffloadEntriesTargetRegionPerFile
operator|>
name|OffloadEntriesTargetRegionPerDevice
expr_stmt|;
typedef|typedef
name|OffloadEntriesTargetRegionPerDevice
name|OffloadEntriesTargetRegionTy
typedef|;
name|OffloadEntriesTargetRegionTy
name|OffloadEntriesTargetRegion
decl_stmt|;
block|}
empty_stmt|;
name|OffloadEntriesInfoManagerTy
name|OffloadEntriesInfoManager
decl_stmt|;
comment|/// \brief Creates and registers offloading binary descriptor for the current
comment|/// compilation unit. The function that does the registration is returned.
name|llvm
operator|::
name|Function
operator|*
name|createOffloadingBinaryDescriptorRegistration
argument_list|()
expr_stmt|;
comment|/// \brief Creates all the offload entries in the current compilation unit
comment|/// along with the associated metadata.
name|void
name|createOffloadEntriesAndInfoMetadata
parameter_list|()
function_decl|;
comment|/// \brief Loads all the offload entries information from the host IR
comment|/// metadata.
name|void
name|loadOffloadInfoMetadata
parameter_list|()
function_decl|;
comment|/// \brief Returns __tgt_offload_entry type.
name|QualType
name|getTgtOffloadEntryQTy
parameter_list|()
function_decl|;
comment|/// \brief Returns __tgt_device_image type.
name|QualType
name|getTgtDeviceImageQTy
parameter_list|()
function_decl|;
comment|/// \brief Returns __tgt_bin_desc type.
name|QualType
name|getTgtBinaryDescriptorQTy
parameter_list|()
function_decl|;
comment|/// \brief Start scanning from statement \a S and and emit all target regions
comment|/// found along the way.
comment|/// \param S Starting statement.
comment|/// \param ParentName Name of the function declaration that is being scanned.
name|void
name|scanForTargetRegionsFunctions
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|,
name|StringRef
name|ParentName
parameter_list|)
function_decl|;
comment|/// \brief Build type kmp_routine_entry_t (if not built yet).
name|void
name|emitKmpRoutineEntryT
parameter_list|(
name|QualType
name|KmpInt32Ty
parameter_list|)
function_decl|;
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
argument|unsigned Function
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
name|Address
name|emitThreadIDAddress
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
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
name|SmallPtrSet
operator|<
specifier|const
name|VarDecl
operator|*
operator|,
literal|4
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
name|Address
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
struct|struct
name|TaskResultTy
block|{
name|llvm
operator|::
name|Value
operator|*
name|NewTask
operator|=
name|nullptr
expr_stmt|;
name|llvm
operator|::
name|Value
operator|*
name|TaskEntry
operator|=
name|nullptr
expr_stmt|;
name|llvm
operator|::
name|Value
operator|*
name|NewTaskNewTaskTTy
operator|=
name|nullptr
expr_stmt|;
name|LValue
name|TDBase
decl_stmt|;
name|RecordDecl
modifier|*
name|KmpTaskTQTyRD
init|=
name|nullptr
decl_stmt|;
name|llvm
operator|::
name|Value
operator|*
name|TaskDupFn
operator|=
name|nullptr
expr_stmt|;
block|}
struct|;
comment|/// Emit task region for the task directive. The task region is emitted in
comment|/// several steps:
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
comment|/// \param D Current task directive.
comment|/// \param TaskFunction An LLVM function with type void (*)(i32 /*gtid*/, i32
comment|/// /*part_id*/, captured_struct */*__context*/);
comment|/// \param SharedsTy A type which contains references the shared variables.
comment|/// \param Shareds Context with the list of shared variables from the \p
comment|/// TaskFunction.
comment|/// \param Data Additional data for task generation like tiednsee, final
comment|/// state, list of privates etc.
name|TaskResultTy
name|emitTaskInit
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
name|llvm
operator|::
name|Value
operator|*
name|TaskFunction
argument_list|,
name|QualType
name|SharedsTy
argument_list|,
name|Address
name|Shareds
argument_list|,
specifier|const
name|OMPTaskDataTy
operator|&
name|Data
argument_list|)
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
comment|/// Emit code for the specified user defined reduction construct.
name|virtual
name|void
name|emitUserDefinedReduction
parameter_list|(
name|CodeGenFunction
modifier|*
name|CGF
parameter_list|,
specifier|const
name|OMPDeclareReductionDecl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// Get combiner/initializer for the specified user-defined reduction, if any.
name|virtual
name|std
operator|::
name|pair
operator|<
name|llvm
operator|::
name|Function
operator|*
operator|,
name|llvm
operator|::
name|Function
operator|*
operator|>
name|getUserDefinedReduction
argument_list|(
specifier|const
name|OMPDeclareReductionDecl
operator|*
name|D
argument_list|)
expr_stmt|;
comment|/// \brief Emits outlined function for the specified OpenMP parallel directive
comment|/// \a D. This outlined function has type void(*)(kmp_int32 *ThreadID,
comment|/// kmp_int32 BoundID, struct context_vars*).
comment|/// \param D OpenMP directive.
comment|/// \param ThreadIDVar Variable for thread id in the current OpenMP region.
comment|/// \param InnermostKind Kind of innermost directive (for simple directives it
comment|/// is a directive itself, for combined - its innermost directive).
comment|/// \param CodeGen Code generation sequence for the \a D directive.
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|emitParallelOutlinedFunction
argument_list|(
argument|const OMPExecutableDirective&D
argument_list|,
argument|const VarDecl *ThreadIDVar
argument_list|,
argument|OpenMPDirectiveKind InnermostKind
argument_list|,
argument|const RegionCodeGenTy&CodeGen
argument_list|)
expr_stmt|;
comment|/// \brief Emits outlined function for the specified OpenMP teams directive
comment|/// \a D. This outlined function has type void(*)(kmp_int32 *ThreadID,
comment|/// kmp_int32 BoundID, struct context_vars*).
comment|/// \param D OpenMP directive.
comment|/// \param ThreadIDVar Variable for thread id in the current OpenMP region.
comment|/// \param InnermostKind Kind of innermost directive (for simple directives it
comment|/// is a directive itself, for combined - its innermost directive).
comment|/// \param CodeGen Code generation sequence for the \a D directive.
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|emitTeamsOutlinedFunction
argument_list|(
argument|const OMPExecutableDirective&D
argument_list|,
argument|const VarDecl *ThreadIDVar
argument_list|,
argument|OpenMPDirectiveKind InnermostKind
argument_list|,
argument|const RegionCodeGenTy&CodeGen
argument_list|)
expr_stmt|;
comment|/// \brief Emits outlined function for the OpenMP task directive \a D. This
comment|/// outlined function has type void(*)(kmp_int32 ThreadID, struct task_t*
comment|/// TaskT).
comment|/// \param D OpenMP directive.
comment|/// \param ThreadIDVar Variable for thread id in the current OpenMP region.
comment|/// \param PartIDVar Variable for partition id in the current OpenMP untied
comment|/// task region.
comment|/// \param TaskTVar Variable for task_t argument.
comment|/// \param InnermostKind Kind of innermost directive (for simple directives it
comment|/// is a directive itself, for combined - its innermost directive).
comment|/// \param CodeGen Code generation sequence for the \a D directive.
comment|/// \param Tied true if task is generated for tied task, false otherwise.
comment|/// \param NumberOfParts Number of parts in untied task. Ignored for tied
comment|/// tasks.
comment|///
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|emitTaskOutlinedFunction
argument_list|(
argument|const OMPExecutableDirective&D
argument_list|,
argument|const VarDecl *ThreadIDVar
argument_list|,
argument|const VarDecl *PartIDVar
argument_list|,
argument|const VarDecl *TaskTVar
argument_list|,
argument|OpenMPDirectiveKind InnermostKind
argument_list|,
argument|const RegionCodeGenTy&CodeGen
argument_list|,
argument|bool Tied
argument_list|,
argument|unsigned&NumberOfParts
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
comment|/// \param CapturedVars A pointer to the record with the references to
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
name|ArrayRef
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|>
name|CapturedVars
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
comment|/// \param Hint Value of the 'hint' clause (optional).
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
parameter_list|,
specifier|const
name|Expr
modifier|*
name|Hint
init|=
name|nullptr
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
comment|/// \brief Emit a taskgroup region.
comment|/// \param TaskgroupOpGen Generator for the statement associated with the
comment|/// given taskgroup region.
name|virtual
name|void
name|emitTaskgroupRegion
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
specifier|const
name|RegionCodeGenTy
modifier|&
name|TaskgroupOpGen
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
comment|/// ordered region.
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
parameter_list|,
name|bool
name|IsThreads
parameter_list|)
function_decl|;
comment|/// \brief Emit an implicit/explicit barrier for OpenMP threads.
comment|/// \param Kind Directive for which this implicit barrier call must be
comment|/// generated. Must be OMPD_barrier for explicit barrier generation.
comment|/// \param EmitChecks true if need to emit checks for cancellation barriers.
comment|/// \param ForceSimpleCall true simple barrier call must be emitted, false if
comment|/// runtime class decides which one to emit (simple or with cancellation
comment|/// checks).
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
parameter_list|,
name|bool
name|EmitChecks
init|=
name|true
parameter_list|,
name|bool
name|ForceSimpleCall
init|=
name|false
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
comment|/// \brief Check if the specified \a ScheduleKind is static non-chunked.
comment|/// This kind of distribute directive is emitted without outer loop.
comment|/// \param ScheduleKind Schedule kind specified in the 'dist_schedule' clause.
comment|/// \param Chunked True if chunk is specified in the clause.
comment|///
name|virtual
name|bool
name|isStaticNonchunked
argument_list|(
name|OpenMPDistScheduleClauseKind
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
comment|/// struct with the values to be passed to the dispatch runtime function
struct|struct
name|DispatchRTInput
block|{
comment|/// Loop lower bound
name|llvm
operator|::
name|Value
operator|*
name|LB
operator|=
name|nullptr
expr_stmt|;
comment|/// Loop upper bound
name|llvm
operator|::
name|Value
operator|*
name|UB
operator|=
name|nullptr
expr_stmt|;
comment|/// Chunk size specified using 'schedule' clause (nullptr if chunk
comment|/// was not specified)
name|llvm
operator|::
name|Value
operator|*
name|Chunk
operator|=
name|nullptr
expr_stmt|;
name|DispatchRTInput
argument_list|()
operator|=
expr|default
expr_stmt|;
name|DispatchRTInput
argument_list|(
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
name|Chunk
argument_list|)
operator|:
name|LB
argument_list|(
name|LB
argument_list|)
operator|,
name|UB
argument_list|(
name|UB
argument_list|)
operator|,
name|Chunk
argument_list|(
argument|Chunk
argument_list|)
block|{}
block|}
struct|;
comment|/// Call the appropriate runtime routine to initialize it before start
comment|/// of loop.
comment|/// This is used for non static scheduled types and when the ordered
comment|/// clause is present on the loop construct.
comment|/// Depending on the loop schedule, it is necessary to call some runtime
comment|/// routine before start of the OpenMP loop to get the loop upper / lower
comment|/// bounds \a LB and \a UB and stride \a ST.
comment|///
comment|/// \param CGF Reference to current CodeGenFunction.
comment|/// \param Loc Clang source location.
comment|/// \param ScheduleKind Schedule kind, specified by the 'schedule' clause.
comment|/// \param IVSize Size of the iteration variable in bits.
comment|/// \param IVSigned Sign of the interation variable.
comment|/// \param Ordered true if loop is ordered, false otherwise.
comment|/// \param DispatchValues struct containing llvm values for lower bound, upper
comment|/// bound, and chunk expression.
comment|/// For the default (nullptr) value, the chunk 1 will be used.
comment|///
name|virtual
name|void
name|emitForDispatchInit
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
specifier|const
name|OpenMPScheduleTy
modifier|&
name|ScheduleKind
parameter_list|,
name|unsigned
name|IVSize
parameter_list|,
name|bool
name|IVSigned
parameter_list|,
name|bool
name|Ordered
parameter_list|,
specifier|const
name|DispatchRTInput
modifier|&
name|DispatchValues
parameter_list|)
function_decl|;
comment|/// \brief Call the appropriate runtime routine to initialize it before start
comment|/// of loop.
comment|///
comment|/// This is used only in case of static schedule, when the user did not
comment|/// specify a ordered clause on the loop construct.
comment|/// Depending on the loop schedule, it is necessary to call some runtime
comment|/// routine before start of the OpenMP loop to get the loop upper / lower
comment|/// bounds \a LB and \a UB and stride \a ST.
comment|///
comment|/// \param CGF Reference to current CodeGenFunction.
comment|/// \param Loc Clang source location.
comment|/// \param ScheduleKind Schedule kind, specified by the 'schedule' clause.
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
name|emitForStaticInit
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
specifier|const
name|OpenMPScheduleTy
operator|&
name|ScheduleKind
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
name|Address
name|IL
argument_list|,
name|Address
name|LB
argument_list|,
name|Address
name|UB
argument_list|,
name|Address
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
comment|///
comment|/// \param CGF Reference to current CodeGenFunction.
comment|/// \param Loc Clang source location.
comment|/// \param SchedKind Schedule kind, specified by the 'dist_schedule' clause.
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
name|emitDistributeStaticInit
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
name|OpenMPDistScheduleClauseKind
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
name|Address
name|IL
argument_list|,
name|Address
name|LB
argument_list|,
name|Address
name|UB
argument_list|,
name|Address
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
argument|Address IL
argument_list|,
argument|Address LB
argument_list|,
argument|Address UB
argument_list|,
argument|Address ST
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
comment|/// \brief Emit call to void __kmpc_push_proc_bind(ident_t *loc, kmp_int32
comment|/// global_tid, int proc_bind) to generate code for 'proc_bind' clause.
name|virtual
name|void
name|emitProcBindClause
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|OpenMPProcBindClauseKind
name|ProcBind
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
comment|/// \brief Returns address of the threadprivate variable for the current
comment|/// thread.
comment|/// \param VD Threadprivate variable.
comment|/// \param VDAddr Address of the global variable \a VD.
comment|/// \param Loc Location of the reference to threadprivate var.
comment|/// \return Address of the threadprivate variable for the current thread.
name|virtual
name|Address
name|getAddrOfThreadPrivate
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
specifier|const
name|VarDecl
modifier|*
name|VD
parameter_list|,
name|Address
name|VDAddr
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
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
argument|Address VDAddr
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
comment|/// \param TaskFunction An LLVM function with type void (*)(i32 /*gtid*/, i32
comment|/// /*part_id*/, captured_struct */*__context*/);
comment|/// \param SharedsTy A type which contains references the shared variables.
comment|/// \param Shareds Context with the list of shared variables from the \p
comment|/// TaskFunction.
comment|/// \param IfCond Not a nullptr if 'if' clause was specified, nullptr
comment|/// otherwise.
comment|/// \param Data Additional data for task generation like tiednsee, final
comment|/// state, list of privates etc.
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
name|llvm
operator|::
name|Value
operator|*
name|TaskFunction
argument_list|,
name|QualType
name|SharedsTy
argument_list|,
name|Address
name|Shareds
argument_list|,
specifier|const
name|Expr
operator|*
name|IfCond
argument_list|,
specifier|const
name|OMPTaskDataTy
operator|&
name|Data
argument_list|)
decl_stmt|;
comment|/// Emit task region for the taskloop directive. The taskloop region is
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
comment|/// 4. Emit a call to void __kmpc_taskloop(ident_t *loc, int gtid, kmp_task_t
comment|/// *task, int if_val, kmp_uint64 *lb, kmp_uint64 *ub, kmp_int64 st, int
comment|/// nogroup, int sched, kmp_uint64 grainsize, void *task_dup ), where new_task
comment|/// is a resulting structure from
comment|/// previous items.
comment|/// \param D Current task directive.
comment|/// \param TaskFunction An LLVM function with type void (*)(i32 /*gtid*/, i32
comment|/// /*part_id*/, captured_struct */*__context*/);
comment|/// \param SharedsTy A type which contains references the shared variables.
comment|/// \param Shareds Context with the list of shared variables from the \p
comment|/// TaskFunction.
comment|/// \param IfCond Not a nullptr if 'if' clause was specified, nullptr
comment|/// otherwise.
comment|/// \param Data Additional data for task generation like tiednsee, final
comment|/// state, list of privates etc.
name|virtual
name|void
name|emitTaskLoopCall
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
specifier|const
name|OMPLoopDirective
operator|&
name|D
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
name|Address
name|Shareds
argument_list|,
specifier|const
name|Expr
operator|*
name|IfCond
argument_list|,
specifier|const
name|OMPTaskDataTy
operator|&
name|Data
argument_list|)
decl_stmt|;
comment|/// \brief Emit code for the directive that does not require outlining.
comment|///
comment|/// \param InnermostKind Kind of innermost directive (for simple directives it
comment|/// is a directive itself, for combined - its innermost directive).
comment|/// \param CodeGen Code generation sequence for the \a D directive.
comment|/// \param HasCancel true if region has inner cancel directive, false
comment|/// otherwise.
name|virtual
name|void
name|emitInlinedDirective
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|OpenMPDirectiveKind
name|InnermostKind
parameter_list|,
specifier|const
name|RegionCodeGenTy
modifier|&
name|CodeGen
parameter_list|,
name|bool
name|HasCancel
init|=
name|false
parameter_list|)
function_decl|;
comment|/// Emits reduction function.
comment|/// \param ArgsType Array type containing pointers to reduction variables.
comment|/// \param Privates List of private copies for original reduction arguments.
comment|/// \param LHSExprs List of LHS in \a ReductionOps reduction operations.
comment|/// \param RHSExprs List of RHS in \a ReductionOps reduction operations.
comment|/// \param ReductionOps List of reduction operations in form 'LHS binop RHS'
comment|/// or 'operator binop(LHS, RHS)'.
name|llvm
operator|::
name|Value
operator|*
name|emitReductionFunction
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|,
name|llvm
operator|::
name|Type
operator|*
name|ArgsType
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|Privates
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
argument_list|)
expr_stmt|;
comment|/// Emits single reduction combiner
name|void
name|emitSingleReductionCombiner
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
specifier|const
name|Expr
modifier|*
name|ReductionOp
parameter_list|,
specifier|const
name|Expr
modifier|*
name|PrivateRef
parameter_list|,
specifier|const
name|DeclRefExpr
modifier|*
name|LHS
parameter_list|,
specifier|const
name|DeclRefExpr
modifier|*
name|RHS
parameter_list|)
function_decl|;
struct|struct
name|ReductionOptionsTy
block|{
name|bool
name|WithNowait
decl_stmt|;
name|bool
name|SimpleReduction
decl_stmt|;
name|OpenMPDirectiveKind
name|ReductionKind
decl_stmt|;
block|}
struct|;
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
comment|/// \param Privates List of private copies for original reduction arguments.
comment|/// \param LHSExprs List of LHS in \a ReductionOps reduction operations.
comment|/// \param RHSExprs List of RHS in \a ReductionOps reduction operations.
comment|/// \param ReductionOps List of reduction operations in form 'LHS binop RHS'
comment|/// or 'operator binop(LHS, RHS)'.
comment|/// \param Options List of options for reduction codegen:
comment|///     WithNowait true if parent directive has also nowait clause, false
comment|///     otherwise.
comment|///     SimpleReduction Emit reduction operation only. Used for omp simd
comment|///     directive on the host.
comment|///     ReductionKind The kind of reduction to perform.
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
name|Privates
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
name|ReductionOptionsTy
name|Options
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
comment|/// \brief Emit code for 'cancellation point' construct.
comment|/// \param CancelRegion Region kind for which the cancellation point must be
comment|/// emitted.
comment|///
name|virtual
name|void
name|emitCancellationPointCall
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|OpenMPDirectiveKind
name|CancelRegion
parameter_list|)
function_decl|;
comment|/// \brief Emit code for 'cancel' construct.
comment|/// \param IfCond Condition in the associated 'if' clause, if it was
comment|/// specified, nullptr otherwise.
comment|/// \param CancelRegion Region kind for which the cancel must be emitted.
comment|///
name|virtual
name|void
name|emitCancelCall
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
specifier|const
name|Expr
modifier|*
name|IfCond
parameter_list|,
name|OpenMPDirectiveKind
name|CancelRegion
parameter_list|)
function_decl|;
comment|/// \brief Emit outilined function for 'target' directive.
comment|/// \param D Directive to emit.
comment|/// \param ParentName Name of the function that encloses the target region.
comment|/// \param OutlinedFn Outlined function value to be defined by this call.
comment|/// \param OutlinedFnID Outlined function ID value to be defined by this call.
comment|/// \param IsOffloadEntry True if the outlined function is an offload entry.
comment|/// \param CodeGen Code generation sequence for the \a D directive.
comment|/// An oulined function may not be an entry if, e.g. the if clause always
comment|/// evaluates to false.
name|virtual
name|void
name|emitTargetOutlinedFunction
argument_list|(
specifier|const
name|OMPExecutableDirective
operator|&
name|D
argument_list|,
name|StringRef
name|ParentName
argument_list|,
name|llvm
operator|::
name|Function
operator|*
operator|&
name|OutlinedFn
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
operator|&
name|OutlinedFnID
argument_list|,
name|bool
name|IsOffloadEntry
argument_list|,
specifier|const
name|RegionCodeGenTy
operator|&
name|CodeGen
argument_list|)
decl_stmt|;
comment|/// \brief Emit the target offloading code associated with \a D. The emitted
comment|/// code attempts offloading the execution to the device, an the event of
comment|/// a failure it executes the host version outlined in \a OutlinedFn.
comment|/// \param D Directive to emit.
comment|/// \param OutlinedFn Host version of the code to be offloaded.
comment|/// \param OutlinedFnID ID of host version of the code to be offloaded.
comment|/// \param IfCond Expression evaluated in if clause associated with the target
comment|/// directive, or null if no if clause is used.
comment|/// \param Device Expression evaluated in device clause associated with the
comment|/// target directive, or null if no device clause is used.
comment|/// \param CapturedVars Values captured in the current region.
name|virtual
name|void
name|emitTargetCall
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
specifier|const
name|OMPExecutableDirective
operator|&
name|D
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
name|OutlinedFnID
argument_list|,
specifier|const
name|Expr
operator|*
name|IfCond
argument_list|,
specifier|const
name|Expr
operator|*
name|Device
argument_list|,
name|ArrayRef
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|>
name|CapturedVars
argument_list|)
decl_stmt|;
comment|/// \brief Emit the target regions enclosed in \a GD function definition or
comment|/// the function itself in case it is a valid device function. Returns true if
comment|/// \a GD was dealt with successfully.
comment|/// \param GD Function to scan.
name|virtual
name|bool
name|emitTargetFunctions
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|)
function_decl|;
comment|/// \brief Emit the global variable if it is a valid device global variable.
comment|/// Returns true if \a GD was dealt with successfully.
comment|/// \param GD Variable declaration to emit.
name|virtual
name|bool
name|emitTargetGlobalVariable
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|)
function_decl|;
comment|/// \brief Emit the global \a GD if it is meaningful for the target. Returns
comment|/// if it was emitted successfully.
comment|/// \param GD Global to scan.
name|virtual
name|bool
name|emitTargetGlobal
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|)
function_decl|;
comment|/// \brief Creates the offloading descriptor in the event any target region
comment|/// was emitted in the current module and return the function that registers
comment|/// it.
name|virtual
name|llvm
operator|::
name|Function
operator|*
name|emitRegistrationFunction
argument_list|()
expr_stmt|;
comment|/// \brief Emits code for teams call of the \a OutlinedFn with
comment|/// variables captured in a record which address is stored in \a
comment|/// CapturedStruct.
comment|/// \param OutlinedFn Outlined function to be run by team masters. Type of
comment|/// this function is void(*)(kmp_int32 *, kmp_int32, struct context_vars*).
comment|/// \param CapturedVars A pointer to the record with the references to
comment|/// variables used in \a OutlinedFn function.
comment|///
name|virtual
name|void
name|emitTeamsCall
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
specifier|const
name|OMPExecutableDirective
operator|&
name|D
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
name|ArrayRef
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|>
name|CapturedVars
argument_list|)
decl_stmt|;
comment|/// \brief Emits call to void __kmpc_push_num_teams(ident_t *loc, kmp_int32
comment|/// global_tid, kmp_int32 num_teams, kmp_int32 thread_limit) to generate code
comment|/// for num_teams clause.
comment|/// \param NumTeams An integer expression of teams.
comment|/// \param ThreadLimit An integer expression of threads.
name|virtual
name|void
name|emitNumTeamsClause
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
specifier|const
name|Expr
modifier|*
name|NumTeams
parameter_list|,
specifier|const
name|Expr
modifier|*
name|ThreadLimit
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
comment|/// Struct that keeps all the relevant information that should be kept
comment|/// throughout a 'target data' region.
name|class
name|TargetDataInfo
block|{
comment|/// Set to true if device pointer information have to be obtained.
name|bool
name|RequiresDevicePointerInfo
init|=
name|false
decl_stmt|;
name|public
label|:
comment|/// The array of base pointer passed to the runtime library.
name|llvm
operator|::
name|Value
operator|*
name|BasePointersArray
operator|=
name|nullptr
expr_stmt|;
comment|/// The array of section pointers passed to the runtime library.
name|llvm
operator|::
name|Value
operator|*
name|PointersArray
operator|=
name|nullptr
expr_stmt|;
comment|/// The array of sizes passed to the runtime library.
name|llvm
operator|::
name|Value
operator|*
name|SizesArray
operator|=
name|nullptr
expr_stmt|;
comment|/// The array of map types passed to the runtime library.
name|llvm
operator|::
name|Value
operator|*
name|MapTypesArray
operator|=
name|nullptr
expr_stmt|;
comment|/// The total number of pointers passed to the runtime library.
name|unsigned
name|NumberOfPtrs
init|=
literal|0u
decl_stmt|;
comment|/// Map between the a declaration of a capture and the corresponding base
comment|/// pointer address where the runtime returns the device pointers.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|ValueDecl
operator|*
operator|,
name|Address
operator|>
name|CaptureDeviceAddrMap
expr_stmt|;
name|explicit
name|TargetDataInfo
parameter_list|()
block|{}
name|explicit
name|TargetDataInfo
argument_list|(
argument|bool RequiresDevicePointerInfo
argument_list|)
block|:
name|RequiresDevicePointerInfo
argument_list|(
argument|RequiresDevicePointerInfo
argument_list|)
block|{}
comment|/// Clear information about the data arrays.
name|void
name|clearArrayInfo
parameter_list|()
block|{
name|BasePointersArray
operator|=
name|nullptr
expr_stmt|;
name|PointersArray
operator|=
name|nullptr
expr_stmt|;
name|SizesArray
operator|=
name|nullptr
expr_stmt|;
name|MapTypesArray
operator|=
name|nullptr
expr_stmt|;
name|NumberOfPtrs
operator|=
literal|0u
expr_stmt|;
block|}
comment|/// Return true if the current target data information has valid arrays.
name|bool
name|isValid
parameter_list|()
block|{
return|return
name|BasePointersArray
operator|&&
name|PointersArray
operator|&&
name|SizesArray
operator|&&
name|MapTypesArray
operator|&&
name|NumberOfPtrs
return|;
block|}
name|bool
name|requiresDevicePointerInfo
parameter_list|()
block|{
return|return
name|RequiresDevicePointerInfo
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Emit the target data mapping code associated with \a D.
comment|/// \param D Directive to emit.
comment|/// \param IfCond Expression evaluated in if clause associated with the
comment|/// target directive, or null if no device clause is used.
comment|/// \param Device Expression evaluated in device clause associated with the
comment|/// target directive, or null if no device clause is used.
comment|/// \param Info A record used to store information that needs to be preserved
comment|/// until the region is closed.
name|virtual
name|void
name|emitTargetDataCalls
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
specifier|const
name|OMPExecutableDirective
modifier|&
name|D
parameter_list|,
specifier|const
name|Expr
modifier|*
name|IfCond
parameter_list|,
specifier|const
name|Expr
modifier|*
name|Device
parameter_list|,
specifier|const
name|RegionCodeGenTy
modifier|&
name|CodeGen
parameter_list|,
name|TargetDataInfo
modifier|&
name|Info
parameter_list|)
function_decl|;
comment|/// \brief Emit the data mapping/movement code associated with the directive
comment|/// \a D that should be of the form 'target [{enter|exit} data | update]'.
comment|/// \param D Directive to emit.
comment|/// \param IfCond Expression evaluated in if clause associated with the target
comment|/// directive, or null if no if clause is used.
comment|/// \param Device Expression evaluated in device clause associated with the
comment|/// target directive, or null if no device clause is used.
name|virtual
name|void
name|emitTargetDataStandAloneCall
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
specifier|const
name|OMPExecutableDirective
modifier|&
name|D
parameter_list|,
specifier|const
name|Expr
modifier|*
name|IfCond
parameter_list|,
specifier|const
name|Expr
modifier|*
name|Device
parameter_list|)
function_decl|;
comment|/// Marks function \a Fn with properly mangled versions of vector functions.
comment|/// \param FD Function marked as 'declare simd'.
comment|/// \param Fn LLVM function that must be marked with 'declare simd'
comment|/// attributes.
name|virtual
name|void
name|emitDeclareSimdFunction
argument_list|(
specifier|const
name|FunctionDecl
operator|*
name|FD
argument_list|,
name|llvm
operator|::
name|Function
operator|*
name|Fn
argument_list|)
decl_stmt|;
comment|/// Emit initialization for doacross loop nesting support.
comment|/// \param D Loop-based construct used in doacross nesting construct.
name|virtual
name|void
name|emitDoacrossInit
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
specifier|const
name|OMPLoopDirective
modifier|&
name|D
parameter_list|)
function_decl|;
comment|/// Emit code for doacross ordered directive with 'depend' clause.
comment|/// \param C 'depend' clause with 'sink|source' dependency kind.
name|virtual
name|void
name|emitDoacrossOrdered
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
specifier|const
name|OMPDependClause
modifier|*
name|C
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

