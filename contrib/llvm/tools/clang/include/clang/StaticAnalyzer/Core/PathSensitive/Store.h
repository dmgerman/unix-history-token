begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== Store.h - Interface for maps from Locations to Values ------*- C++ -*--==//
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
comment|//  This file defined the types Store and StoreManager.
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
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_STORE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_STORE_H
end_define

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/MemRegion.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/SValBuilder.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/StoreRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Stmt
decl_stmt|;
name|class
name|Expr
decl_stmt|;
name|class
name|ObjCIvarDecl
decl_stmt|;
name|class
name|CXXBasePath
decl_stmt|;
name|class
name|StackFrameContext
decl_stmt|;
name|namespace
name|ento
block|{
name|class
name|CallEvent
decl_stmt|;
name|class
name|ProgramState
decl_stmt|;
name|class
name|ProgramStateManager
decl_stmt|;
name|class
name|ScanReachableSymbols
decl_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseSet
operator|<
name|SymbolRef
operator|>
name|InvalidatedSymbols
expr_stmt|;
name|class
name|StoreManager
block|{
name|protected
label|:
name|SValBuilder
modifier|&
name|svalBuilder
decl_stmt|;
name|ProgramStateManager
modifier|&
name|StateMgr
decl_stmt|;
comment|/// MRMgr - Manages region objects associated with this StoreManager.
name|MemRegionManager
modifier|&
name|MRMgr
decl_stmt|;
name|ASTContext
modifier|&
name|Ctx
decl_stmt|;
name|StoreManager
argument_list|(
name|ProgramStateManager
operator|&
name|stateMgr
argument_list|)
expr_stmt|;
name|public
label|:
name|virtual
operator|~
name|StoreManager
argument_list|()
block|{}
comment|/// Return the value bound to specified location in a given state.
comment|/// \param[in] store The analysis state.
comment|/// \param[in] loc The symbolic memory location.
comment|/// \param[in] T An optional type that provides a hint indicating the
comment|///   expected type of the returned value.  This is used if the value is
comment|///   lazily computed.
comment|/// \return The value bound to the location \c loc.
name|virtual
name|SVal
name|getBinding
argument_list|(
argument|Store store
argument_list|,
argument|Loc loc
argument_list|,
argument|QualType T = QualType()
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// Return the default value bound to a region in a given store. The default
comment|/// binding is the value of sub-regions that were not initialized separately
comment|/// from their base region. For example, if the structure is zero-initialized
comment|/// upon construction, this method retrieves the concrete zero value, even if
comment|/// some or all fields were later overwritten manually. Default binding may be
comment|/// an unknown, undefined, concrete, or symbolic value.
comment|/// \param[in] store The store in which to make the lookup.
comment|/// \param[in] R The region to find the default binding for.
comment|/// \return The default value bound to the region in the store, if a default
comment|/// binding exists.
name|virtual
name|Optional
operator|<
name|SVal
operator|>
name|getDefaultBinding
argument_list|(
argument|Store store
argument_list|,
argument|const MemRegion *R
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// Return the default value bound to a LazyCompoundVal. The default binding
comment|/// is used to represent the value of any fields or elements within the
comment|/// structure represented by the LazyCompoundVal which were not initialized
comment|/// explicitly separately from the whole structure. Default binding may be an
comment|/// unknown, undefined, concrete, or symbolic value.
comment|/// \param[in] lcv The lazy compound value.
comment|/// \return The default value bound to the LazyCompoundVal \c lcv, if a
comment|/// default binding exists.
name|Optional
operator|<
name|SVal
operator|>
name|getDefaultBinding
argument_list|(
argument|nonloc::LazyCompoundVal lcv
argument_list|)
block|{
return|return
name|getDefaultBinding
argument_list|(
name|lcv
operator|.
name|getStore
argument_list|()
argument_list|,
name|lcv
operator|.
name|getRegion
argument_list|()
argument_list|)
return|;
block|}
comment|/// Return a state with the specified value bound to the given location.
comment|/// \param[in] store The analysis state.
comment|/// \param[in] loc The symbolic memory location.
comment|/// \param[in] val The value to bind to location \c loc.
comment|/// \return A pointer to a ProgramState object that contains the same
comment|///   bindings as \c state with the addition of having the value specified
comment|///   by \c val bound to the location given for \c loc.
name|virtual
name|StoreRef
name|Bind
parameter_list|(
name|Store
name|store
parameter_list|,
name|Loc
name|loc
parameter_list|,
name|SVal
name|val
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|StoreRef
name|BindDefault
parameter_list|(
name|Store
name|store
parameter_list|,
specifier|const
name|MemRegion
modifier|*
name|R
parameter_list|,
name|SVal
name|V
parameter_list|)
function_decl|;
comment|/// \brief Create a new store with the specified binding removed.
comment|/// \param ST the original store, that is the basis for the new store.
comment|/// \param L the location whose binding should be removed.
name|virtual
name|StoreRef
name|killBinding
parameter_list|(
name|Store
name|ST
parameter_list|,
name|Loc
name|L
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// getInitialStore - Returns the initial "empty" store representing the
comment|///  value bindings upon entry to an analyzed function.
name|virtual
name|StoreRef
name|getInitialStore
parameter_list|(
specifier|const
name|LocationContext
modifier|*
name|InitLoc
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// getRegionManager - Returns the internal RegionManager object that is
comment|///  used to query and manipulate MemRegion objects.
name|MemRegionManager
modifier|&
name|getRegionManager
parameter_list|()
block|{
return|return
name|MRMgr
return|;
block|}
name|virtual
name|Loc
name|getLValueVar
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|VD
parameter_list|,
specifier|const
name|LocationContext
modifier|*
name|LC
parameter_list|)
block|{
return|return
name|svalBuilder
operator|.
name|makeLoc
argument_list|(
name|MRMgr
operator|.
name|getVarRegion
argument_list|(
name|VD
argument_list|,
name|LC
argument_list|)
argument_list|)
return|;
block|}
name|Loc
name|getLValueCompoundLiteral
parameter_list|(
specifier|const
name|CompoundLiteralExpr
modifier|*
name|CL
parameter_list|,
specifier|const
name|LocationContext
modifier|*
name|LC
parameter_list|)
block|{
return|return
name|loc
operator|::
name|MemRegionVal
argument_list|(
name|MRMgr
operator|.
name|getCompoundLiteralRegion
argument_list|(
name|CL
argument_list|,
name|LC
argument_list|)
argument_list|)
return|;
block|}
name|virtual
name|SVal
name|getLValueIvar
parameter_list|(
specifier|const
name|ObjCIvarDecl
modifier|*
name|decl
parameter_list|,
name|SVal
name|base
parameter_list|)
function_decl|;
name|virtual
name|SVal
name|getLValueField
parameter_list|(
specifier|const
name|FieldDecl
modifier|*
name|D
parameter_list|,
name|SVal
name|Base
parameter_list|)
block|{
return|return
name|getLValueFieldOrIvar
argument_list|(
name|D
argument_list|,
name|Base
argument_list|)
return|;
block|}
name|virtual
name|SVal
name|getLValueElement
parameter_list|(
name|QualType
name|elementType
parameter_list|,
name|NonLoc
name|offset
parameter_list|,
name|SVal
name|Base
parameter_list|)
function_decl|;
comment|// FIXME: This should soon be eliminated altogether; clients should deal with
comment|// region extents directly.
name|virtual
name|DefinedOrUnknownSVal
name|getSizeInElements
parameter_list|(
name|ProgramStateRef
name|state
parameter_list|,
specifier|const
name|MemRegion
modifier|*
name|region
parameter_list|,
name|QualType
name|EleTy
parameter_list|)
block|{
return|return
name|UnknownVal
argument_list|()
return|;
block|}
comment|/// ArrayToPointer - Used by ExprEngine::VistCast to handle implicit
comment|///  conversions between arrays and pointers.
name|virtual
name|SVal
name|ArrayToPointer
parameter_list|(
name|Loc
name|Array
parameter_list|,
name|QualType
name|ElementTy
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Evaluates a chain of derived-to-base casts through the path specified in
comment|/// \p Cast.
name|SVal
name|evalDerivedToBase
parameter_list|(
name|SVal
name|Derived
parameter_list|,
specifier|const
name|CastExpr
modifier|*
name|Cast
parameter_list|)
function_decl|;
comment|/// Evaluates a chain of derived-to-base casts through the specified path.
name|SVal
name|evalDerivedToBase
parameter_list|(
name|SVal
name|Derived
parameter_list|,
specifier|const
name|CXXBasePath
modifier|&
name|CastPath
parameter_list|)
function_decl|;
comment|/// Evaluates a derived-to-base cast through a single level of derivation.
name|SVal
name|evalDerivedToBase
parameter_list|(
name|SVal
name|Derived
parameter_list|,
name|QualType
name|DerivedPtrType
parameter_list|,
name|bool
name|IsVirtual
parameter_list|)
function_decl|;
comment|/// \brief Attempts to do a down cast. Used to model BaseToDerived and C++
comment|///        dynamic_cast.
comment|/// The callback may result in the following 3 scenarios:
comment|///  - Successful cast (ex: derived is subclass of base).
comment|///  - Failed cast (ex: derived is definitely not a subclass of base).
comment|///    The distinction of this case from the next one is necessary to model
comment|///    dynamic_cast.
comment|///  - We don't know (base is a symbolic region and we don't have
comment|///    enough info to determine if the cast will succeed at run time).
comment|/// The function returns an SVal representing the derived class; it's
comment|/// valid only if Failed flag is set to false.
name|SVal
name|attemptDownCast
parameter_list|(
name|SVal
name|Base
parameter_list|,
name|QualType
name|DerivedPtrType
parameter_list|,
name|bool
modifier|&
name|Failed
parameter_list|)
function_decl|;
specifier|const
name|ElementRegion
modifier|*
name|GetElementZeroRegion
parameter_list|(
specifier|const
name|SubRegion
modifier|*
name|R
parameter_list|,
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// castRegion - Used by ExprEngine::VisitCast to handle casts from
comment|///  a MemRegion* to a specific location type.  'R' is the region being
comment|///  casted and 'CastToTy' the result type of the cast.
specifier|const
name|MemRegion
modifier|*
name|castRegion
parameter_list|(
specifier|const
name|MemRegion
modifier|*
name|region
parameter_list|,
name|QualType
name|CastToTy
parameter_list|)
function_decl|;
name|virtual
name|StoreRef
name|removeDeadBindings
parameter_list|(
name|Store
name|store
parameter_list|,
specifier|const
name|StackFrameContext
modifier|*
name|LCtx
parameter_list|,
name|SymbolReaper
modifier|&
name|SymReaper
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|includedInBindings
argument_list|(
name|Store
name|store
argument_list|,
specifier|const
name|MemRegion
operator|*
name|region
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// If the StoreManager supports it, increment the reference count of
comment|/// the specified Store object.
name|virtual
name|void
name|incrementReferenceCount
parameter_list|(
name|Store
name|store
parameter_list|)
block|{}
comment|/// If the StoreManager supports it, decrement the reference count of
comment|/// the specified Store object.  If the reference count hits 0, the memory
comment|/// associated with the object is recycled.
name|virtual
name|void
name|decrementReferenceCount
parameter_list|(
name|Store
name|store
parameter_list|)
block|{}
typedef|typedef
name|SmallVector
operator|<
specifier|const
name|MemRegion
operator|*
operator|,
literal|8
operator|>
name|InvalidatedRegions
expr_stmt|;
comment|/// invalidateRegions - Clears out the specified regions from the store,
comment|///  marking their values as unknown. Depending on the store, this may also
comment|///  invalidate additional regions that may have changed based on accessing
comment|///  the given regions. Optionally, invalidates non-static globals as well.
comment|/// \param[in] store The initial store
comment|/// \param[in] Values The values to invalidate.
comment|/// \param[in] E The current statement being evaluated. Used to conjure
comment|///   symbols to mark the values of invalidated regions.
comment|/// \param[in] Count The current block count. Used to conjure
comment|///   symbols to mark the values of invalidated regions.
comment|/// \param[in] Call The call expression which will be used to determine which
comment|///   globals should get invalidated.
comment|/// \param[in,out] IS A set to fill with any symbols that are no longer
comment|///   accessible. Pass \c NULL if this information will not be used.
comment|/// \param[in] ITraits Information about invalidation for a particular
comment|///   region/symbol.
comment|/// \param[in,out] InvalidatedTopLevel A vector to fill with regions
comment|////  explicitly being invalidated. Pass \c NULL if this
comment|///   information will not be used.
comment|/// \param[in,out] Invalidated A vector to fill with any regions being
comment|///   invalidated. This should include any regions explicitly invalidated
comment|///   even if they do not currently have bindings. Pass \c NULL if this
comment|///   information will not be used.
name|virtual
name|StoreRef
name|invalidateRegions
argument_list|(
name|Store
name|store
argument_list|,
name|ArrayRef
operator|<
name|SVal
operator|>
name|Values
argument_list|,
specifier|const
name|Expr
operator|*
name|E
argument_list|,
name|unsigned
name|Count
argument_list|,
specifier|const
name|LocationContext
operator|*
name|LCtx
argument_list|,
specifier|const
name|CallEvent
operator|*
name|Call
argument_list|,
name|InvalidatedSymbols
operator|&
name|IS
argument_list|,
name|RegionAndSymbolInvalidationTraits
operator|&
name|ITraits
argument_list|,
name|InvalidatedRegions
operator|*
name|InvalidatedTopLevel
argument_list|,
name|InvalidatedRegions
operator|*
name|Invalidated
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// enterStackFrame - Let the StoreManager to do something when execution
comment|/// engine is about to execute into a callee.
name|StoreRef
name|enterStackFrame
parameter_list|(
name|Store
name|store
parameter_list|,
specifier|const
name|CallEvent
modifier|&
name|Call
parameter_list|,
specifier|const
name|StackFrameContext
modifier|*
name|CalleeCtx
parameter_list|)
function_decl|;
comment|/// Finds the transitive closure of symbols within the given region.
comment|///
comment|/// Returns false if the visitor aborted the scan.
name|virtual
name|bool
name|scanReachableSymbols
parameter_list|(
name|Store
name|S
parameter_list|,
specifier|const
name|MemRegion
modifier|*
name|R
parameter_list|,
name|ScanReachableSymbols
modifier|&
name|Visitor
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|print
parameter_list|(
name|Store
name|store
parameter_list|,
name|raw_ostream
modifier|&
name|Out
parameter_list|,
specifier|const
name|char
modifier|*
name|nl
parameter_list|,
specifier|const
name|char
modifier|*
name|sep
parameter_list|)
init|=
literal|0
function_decl|;
name|class
name|BindingsHandler
block|{
name|public
label|:
name|virtual
operator|~
name|BindingsHandler
argument_list|()
expr_stmt|;
name|virtual
name|bool
name|HandleBinding
parameter_list|(
name|StoreManager
modifier|&
name|SMgr
parameter_list|,
name|Store
name|store
parameter_list|,
specifier|const
name|MemRegion
modifier|*
name|region
parameter_list|,
name|SVal
name|val
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
name|class
name|FindUniqueBinding
range|:
name|public
name|BindingsHandler
block|{
name|SymbolRef
name|Sym
block|;
specifier|const
name|MemRegion
operator|*
name|Binding
block|;
name|bool
name|First
block|;
name|public
operator|:
name|FindUniqueBinding
argument_list|(
argument|SymbolRef sym
argument_list|)
operator|:
name|Sym
argument_list|(
name|sym
argument_list|)
block|,
name|Binding
argument_list|(
name|nullptr
argument_list|)
block|,
name|First
argument_list|(
argument|true
argument_list|)
block|{}
name|bool
name|HandleBinding
argument_list|(
argument|StoreManager& SMgr
argument_list|,
argument|Store store
argument_list|,
argument|const MemRegion* R
argument_list|,
argument|SVal val
argument_list|)
name|override
block|;
name|explicit
name|operator
name|bool
argument_list|()
block|{
return|return
name|First
operator|&&
name|Binding
return|;
block|}
specifier|const
name|MemRegion
operator|*
name|getRegion
argument_list|()
block|{
return|return
name|Binding
return|;
block|}
expr|}
block|;
comment|/// iterBindings - Iterate over the bindings in the Store.
name|virtual
name|void
name|iterBindings
argument_list|(
argument|Store store
argument_list|,
argument|BindingsHandler& f
argument_list|)
operator|=
literal|0
block|;
name|protected
operator|:
specifier|const
name|ElementRegion
operator|*
name|MakeElementRegion
argument_list|(
argument|const SubRegion *baseRegion
argument_list|,
argument|QualType pointeeTy
argument_list|,
argument|uint64_t index =
literal|0
argument_list|)
block|;
comment|/// CastRetrievedVal - Used by subclasses of StoreManager to implement
comment|///  implicit casts that arise from loads from regions that are reinterpreted
comment|///  as another region.
name|SVal
name|CastRetrievedVal
argument_list|(
argument|SVal val
argument_list|,
argument|const TypedValueRegion *region
argument_list|,
argument|QualType castTy
argument_list|,
argument|bool performTestOnly = true
argument_list|)
block|;
name|private
operator|:
name|SVal
name|getLValueFieldOrIvar
argument_list|(
argument|const Decl *decl
argument_list|,
argument|SVal base
argument_list|)
block|; }
decl_stmt|;
specifier|inline
name|StoreRef
operator|::
name|StoreRef
argument_list|(
argument|Store store
argument_list|,
argument|StoreManager& smgr
argument_list|)
operator|:
name|store
argument_list|(
name|store
argument_list|)
operator|,
name|mgr
argument_list|(
argument|smgr
argument_list|)
block|{
if|if
condition|(
name|store
condition|)
name|mgr
operator|.
name|incrementReferenceCount
argument_list|(
name|store
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|StoreRef
operator|::
name|StoreRef
argument_list|(
specifier|const
name|StoreRef
operator|&
name|sr
argument_list|)
operator|:
name|store
argument_list|(
name|sr
operator|.
name|store
argument_list|)
operator|,
name|mgr
argument_list|(
argument|sr.mgr
argument_list|)
block|{
if|if
condition|(
name|store
condition|)
name|mgr
operator|.
name|incrementReferenceCount
argument_list|(
name|store
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|StoreRef
operator|::
operator|~
name|StoreRef
argument_list|()
block|{
if|if
condition|(
name|store
condition|)
name|mgr
operator|.
name|decrementReferenceCount
argument_list|(
name|store
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|StoreRef
operator|&
name|StoreRef
operator|::
name|operator
operator|=
operator|(
name|StoreRef
specifier|const
operator|&
name|newStore
operator|)
block|{
name|assert
argument_list|(
operator|&
name|newStore
operator|.
name|mgr
operator|==
operator|&
name|mgr
argument_list|)
block|;
if|if
condition|(
name|store
operator|!=
name|newStore
operator|.
name|store
condition|)
block|{
name|mgr
operator|.
name|incrementReferenceCount
argument_list|(
name|newStore
operator|.
name|store
argument_list|)
expr_stmt|;
name|mgr
operator|.
name|decrementReferenceCount
argument_list|(
name|store
argument_list|)
expr_stmt|;
name|store
operator|=
name|newStore
operator|.
name|getStore
argument_list|()
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
comment|// FIXME: Do we need to pass ProgramStateManager anymore?
name|std
operator|::
name|unique_ptr
operator|<
name|StoreManager
operator|>
name|CreateRegionStoreManager
argument_list|(
name|ProgramStateManager
operator|&
name|StMgr
argument_list|)
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|StoreManager
operator|>
name|CreateFieldsOnlyRegionStoreManager
argument_list|(
name|ProgramStateManager
operator|&
name|StMgr
argument_list|)
expr_stmt|;
block|}
comment|// end GR namespace
block|}
end_decl_stmt

begin_comment
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

