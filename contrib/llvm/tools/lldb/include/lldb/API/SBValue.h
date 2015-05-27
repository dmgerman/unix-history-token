begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBValue.h -----------------------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLDB_SBValue_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBValue_h_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBData.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBType.h"
end_include

begin_decl_stmt
name|class
name|ValueImpl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|ValueLocker
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|SBValue
block|{
name|friend
name|class
name|ValueLocker
decl_stmt|;
name|public
label|:
name|SBValue
argument_list|()
expr_stmt|;
name|SBValue
argument_list|(
specifier|const
name|lldb
operator|::
name|SBValue
operator|&
name|rhs
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBValue
operator|&
name|operator
operator|=
operator|(
specifier|const
name|lldb
operator|::
name|SBValue
operator|&
name|rhs
operator|)
expr_stmt|;
operator|~
name|SBValue
argument_list|()
expr_stmt|;
name|bool
name|IsValid
parameter_list|()
function_decl|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|SBError
name|GetError
parameter_list|()
function_decl|;
name|lldb
operator|::
name|user_id_t
name|GetID
argument_list|()
expr_stmt|;
specifier|const
name|char
modifier|*
name|GetName
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|GetTypeName
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|GetDisplayTypeName
parameter_list|()
function_decl|;
name|size_t
name|GetByteSize
parameter_list|()
function_decl|;
name|bool
name|IsInScope
parameter_list|()
function_decl|;
name|lldb
operator|::
name|Format
name|GetFormat
argument_list|()
expr_stmt|;
name|void
name|SetFormat
argument_list|(
name|lldb
operator|::
name|Format
name|format
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|GetValue
parameter_list|()
function_decl|;
name|int64_t
name|GetValueAsSigned
argument_list|(
name|lldb
operator|::
name|SBError
operator|&
name|error
argument_list|,
name|int64_t
name|fail_value
operator|=
literal|0
argument_list|)
decl_stmt|;
name|uint64_t
name|GetValueAsUnsigned
argument_list|(
name|lldb
operator|::
name|SBError
operator|&
name|error
argument_list|,
name|uint64_t
name|fail_value
operator|=
literal|0
argument_list|)
decl_stmt|;
name|int64_t
name|GetValueAsSigned
parameter_list|(
name|int64_t
name|fail_value
init|=
literal|0
parameter_list|)
function_decl|;
name|uint64_t
name|GetValueAsUnsigned
parameter_list|(
name|uint64_t
name|fail_value
init|=
literal|0
parameter_list|)
function_decl|;
name|ValueType
name|GetValueType
parameter_list|()
function_decl|;
name|bool
name|GetValueDidChange
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|GetSummary
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|GetSummary
argument_list|(
name|lldb
operator|::
name|SBStream
operator|&
name|stream
argument_list|,
name|lldb
operator|::
name|SBTypeSummaryOptions
operator|&
name|options
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|GetObjectDescription
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|GetTypeValidatorResult
parameter_list|()
function_decl|;
name|lldb
operator|::
name|SBValue
name|GetDynamicValue
argument_list|(
argument|lldb::DynamicValueType use_dynamic
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBValue
name|GetStaticValue
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SBValue
name|GetNonSyntheticValue
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|DynamicValueType
name|GetPreferDynamicValue
argument_list|()
expr_stmt|;
name|void
name|SetPreferDynamicValue
argument_list|(
name|lldb
operator|::
name|DynamicValueType
name|use_dynamic
argument_list|)
decl_stmt|;
name|bool
name|GetPreferSyntheticValue
parameter_list|()
function_decl|;
name|void
name|SetPreferSyntheticValue
parameter_list|(
name|bool
name|use_synthetic
parameter_list|)
function_decl|;
name|bool
name|IsDynamic
parameter_list|()
function_decl|;
name|bool
name|IsSynthetic
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|GetLocation
parameter_list|()
function_decl|;
comment|// Deprecated - use the one that takes SBError&
name|bool
name|SetValueFromCString
parameter_list|(
specifier|const
name|char
modifier|*
name|value_str
parameter_list|)
function_decl|;
name|bool
name|SetValueFromCString
argument_list|(
specifier|const
name|char
operator|*
name|value_str
argument_list|,
name|lldb
operator|::
name|SBError
operator|&
name|error
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|SBTypeFormat
name|GetTypeFormat
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|LLDB_DISABLE_PYTHON
name|lldb
operator|::
name|SBTypeSummary
name|GetTypeSummary
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|lldb
operator|::
name|SBTypeFilter
name|GetTypeFilter
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|LLDB_DISABLE_PYTHON
name|lldb
operator|::
name|SBTypeSynthetic
name|GetTypeSynthetic
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|lldb
operator|::
name|SBValue
name|GetChildAtIndex
argument_list|(
argument|uint32_t idx
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBValue
name|CreateChildAtOffset
argument_list|(
argument|const char *name
argument_list|,
argument|uint32_t offset
argument_list|,
argument|lldb::SBType type
argument_list|)
expr_stmt|;
comment|// Deprecated - use the expression evaluator to perform type casting
name|lldb
operator|::
name|SBValue
name|Cast
argument_list|(
argument|lldb::SBType type
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBValue
name|CreateValueFromExpression
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|char
operator|*
name|expression
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBValue
name|CreateValueFromExpression
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|char
operator|*
name|expression
argument_list|,
name|SBExpressionOptions
operator|&
name|options
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBValue
name|CreateValueFromAddress
argument_list|(
argument|const char* name
argument_list|,
argument|lldb::addr_t address
argument_list|,
argument|lldb::SBType type
argument_list|)
expr_stmt|;
comment|// this has no address! GetAddress() and GetLoadAddress() as well as AddressOf()
comment|// on the return of this call all return invalid
name|lldb
operator|::
name|SBValue
name|CreateValueFromData
argument_list|(
argument|const char* name
argument_list|,
argument|lldb::SBData data
argument_list|,
argument|lldb::SBType type
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get a child value by index from a value.
comment|///
comment|/// Structs, unions, classes, arrays and pointers have child
comment|/// values that can be access by index.
comment|///
comment|/// Structs and unions access child members using a zero based index
comment|/// for each child member. For
comment|///
comment|/// Classes reserve the first indexes for base classes that have
comment|/// members (empty base classes are omitted), and all members of the
comment|/// current class will then follow the base classes.
comment|///
comment|/// Pointers differ depending on what they point to. If the pointer
comment|/// points to a simple type, the child at index zero
comment|/// is the only child value available, unless \a synthetic_allowed
comment|/// is \b true, in which case the pointer will be used as an array
comment|/// and can create 'synthetic' child values using positive or
comment|/// negative indexes. If the pointer points to an aggregate type
comment|/// (an array, class, union, struct), then the pointee is
comment|/// transparently skipped and any children are going to be the indexes
comment|/// of the child values within the aggregate type. For example if
comment|/// we have a 'Point' type and we have a SBValue that contains a
comment|/// pointer to a 'Point' type, then the child at index zero will be
comment|/// the 'x' member, and the child at index 1 will be the 'y' member
comment|/// (the child at index zero won't be a 'Point' instance).
comment|///
comment|/// Arrays have a preset number of children that can be accessed by
comment|/// index and will returns invalid child values for indexes that are
comment|/// out of bounds unless the \a synthetic_allowed is \b true. In this
comment|/// case the array can create 'synthetic' child values for indexes
comment|/// that aren't in the array bounds using positive or negative
comment|/// indexes.
comment|///
comment|/// @param[in] idx
comment|///     The index of the child value to get
comment|///
comment|/// @param[in] use_dynamic
comment|///     An enumeration that specifies whether to get dynamic values,
comment|///     and also if the target can be run to figure out the dynamic
comment|///     type of the child value.
comment|///
comment|/// @param[in] synthetic_allowed
comment|///     If \b true, then allow child values to be created by index
comment|///     for pointers and arrays for indexes that normally wouldn't
comment|///     be allowed.
comment|///
comment|/// @return
comment|///     A new SBValue object that represents the child member value.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBValue
name|GetChildAtIndex
argument_list|(
argument|uint32_t idx
argument_list|,
argument|lldb::DynamicValueType use_dynamic
argument_list|,
argument|bool can_create_synthetic
argument_list|)
expr_stmt|;
comment|// Matches children of this object only and will match base classes and
comment|// member names if this is a clang typed object.
name|uint32_t
name|GetIndexOfChildWithName
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
comment|// Matches child members of this object and child members of any base
comment|// classes.
name|lldb
operator|::
name|SBValue
name|GetChildMemberWithName
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
expr_stmt|;
comment|// Matches child members of this object and child members of any base
comment|// classes.
name|lldb
operator|::
name|SBValue
name|GetChildMemberWithName
argument_list|(
argument|const char *name
argument_list|,
argument|lldb::DynamicValueType use_dynamic
argument_list|)
expr_stmt|;
comment|// Expands nested expressions like .a->b[0].c[1]->d
name|lldb
operator|::
name|SBValue
name|GetValueForExpressionPath
argument_list|(
specifier|const
name|char
operator|*
name|expr_path
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBValue
name|AddressOf
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|addr_t
name|GetLoadAddress
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SBAddress
name|GetAddress
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get an SBData wrapping what this SBValue points to.
comment|///
comment|/// This method will dereference the current SBValue, if its
comment|/// data type is a T* or T[], and extract item_count elements
comment|/// of type T from it, copying their contents in an SBData.
comment|///
comment|/// @param[in] item_idx
comment|///     The index of the first item to retrieve. For an array
comment|///     this is equivalent to array[item_idx], for a pointer
comment|///     to *(pointer + item_idx). In either case, the measurement
comment|///     unit for item_idx is the sizeof(T) rather than the byte
comment|///
comment|/// @param[in] item_count
comment|///     How many items should be copied into the output. By default
comment|///     only one item is copied, but more can be asked for.
comment|///
comment|/// @return
comment|///     An SBData with the contents of the copied items, on success.
comment|///     An empty SBData otherwise.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBData
name|GetPointeeData
argument_list|(
argument|uint32_t item_idx =
literal|0
argument_list|,
argument|uint32_t item_count =
literal|1
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get an SBData wrapping the contents of this SBValue.
comment|///
comment|/// This method will read the contents of this object in memory
comment|/// and copy them into an SBData for future use.
comment|///
comment|/// @return
comment|///     An SBData with the contents of this SBValue, on success.
comment|///     An empty SBData otherwise.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBData
name|GetData
argument_list|()
expr_stmt|;
name|bool
name|SetData
argument_list|(
name|lldb
operator|::
name|SBData
operator|&
name|data
argument_list|,
name|lldb
operator|::
name|SBError
operator|&
name|error
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|SBDeclaration
name|GetDeclaration
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find out if a SBValue might have children.
comment|///
comment|/// This call is much more efficient than GetNumChildren() as it
comment|/// doesn't need to complete the underlying type. This is designed
comment|/// to be used in a UI environment in order to detect if the
comment|/// disclosure triangle should be displayed or not.
comment|///
comment|/// This function returns true for class, union, structure,
comment|/// pointers, references, arrays and more. Again, it does so without
comment|/// doing any expensive type completion.
comment|///
comment|/// @return
comment|///     Returns \b true if the SBValue might have children, or \b
comment|///     false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|MightHaveChildren
parameter_list|()
function_decl|;
name|uint32_t
name|GetNumChildren
parameter_list|()
function_decl|;
name|void
modifier|*
name|GetOpaqueType
parameter_list|()
function_decl|;
name|lldb
operator|::
name|SBTarget
name|GetTarget
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SBProcess
name|GetProcess
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SBThread
name|GetThread
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SBFrame
name|GetFrame
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SBValue
name|Dereference
argument_list|()
expr_stmt|;
name|bool
name|TypeIsPointerType
parameter_list|()
function_decl|;
name|lldb
operator|::
name|SBType
name|GetType
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SBValue
name|Persist
argument_list|()
expr_stmt|;
name|bool
name|GetDescription
argument_list|(
name|lldb
operator|::
name|SBStream
operator|&
name|description
argument_list|)
decl_stmt|;
name|bool
name|GetExpressionPath
argument_list|(
name|lldb
operator|::
name|SBStream
operator|&
name|description
argument_list|)
decl_stmt|;
name|bool
name|GetExpressionPath
argument_list|(
name|lldb
operator|::
name|SBStream
operator|&
name|description
argument_list|,
name|bool
name|qualify_cxx_base_classes
argument_list|)
decl_stmt|;
name|SBValue
argument_list|(
specifier|const
name|lldb
operator|::
name|ValueObjectSP
operator|&
name|value_sp
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Watch this value if it resides in memory.
comment|///
comment|/// Sets a watchpoint on the value.
comment|///
comment|/// @param[in] resolve_location
comment|///     Resolve the location of this value once and watch its address.
comment|///     This value must currently be set to \b true as watching all
comment|///     locations of a variable or a variable path is not yet supported,
comment|///     though we plan to support it in the future.
comment|///
comment|/// @param[in] read
comment|///     Stop when this value is accessed.
comment|///
comment|/// @param[in] write
comment|///     Stop when this value is modified
comment|///
comment|/// @param[out]
comment|///     An error object. Contains the reason if there is some failure.
comment|///
comment|/// @return
comment|///     An SBWatchpoint object. This object might not be valid upon
comment|///     return due to a value not being contained in memory, too
comment|///     large, or watchpoint resources are not available or all in
comment|///     use.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBWatchpoint
name|Watch
argument_list|(
argument|bool resolve_location
argument_list|,
argument|bool read
argument_list|,
argument|bool write
argument_list|,
argument|SBError&error
argument_list|)
expr_stmt|;
comment|// Backward compatibility fix in the interim.
name|lldb
operator|::
name|SBWatchpoint
name|Watch
argument_list|(
argument|bool resolve_location
argument_list|,
argument|bool read
argument_list|,
argument|bool write
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Watch this value that this value points to in memory
comment|///
comment|/// Sets a watchpoint on the value.
comment|///
comment|/// @param[in] resolve_location
comment|///     Resolve the location of this value once and watch its address.
comment|///     This value must currently be set to \b true as watching all
comment|///     locations of a variable or a variable path is not yet supported,
comment|///     though we plan to support it in the future.
comment|///
comment|/// @param[in] read
comment|///     Stop when this value is accessed.
comment|///
comment|/// @param[in] write
comment|///     Stop when this value is modified
comment|///
comment|/// @param[out]
comment|///     An error object. Contains the reason if there is some failure.
comment|///
comment|/// @return
comment|///     An SBWatchpoint object. This object might not be valid upon
comment|///     return due to a value not being contained in memory, too
comment|///     large, or watchpoint resources are not available or all in
comment|///     use.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBWatchpoint
name|WatchPointee
argument_list|(
argument|bool resolve_location
argument_list|,
argument|bool read
argument_list|,
argument|bool write
argument_list|,
argument|SBError&error
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Same as the protected version of GetSP that takes a locker, except that we make the
comment|/// locker locally in the function.  Since the Target API mutex is recursive, and the
comment|/// StopLocker is a read lock, you can call this function even if you are already
comment|/// holding the two above-mentioned locks.
comment|///
comment|/// @return
comment|///     A ValueObjectSP of the best kind (static, dynamic or synthetic) we
comment|///     can cons up, in accordance with the SBValue's settings.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ValueObjectSP
name|GetSP
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
name|friend
name|class
name|SBBlock
decl_stmt|;
name|friend
name|class
name|SBFrame
decl_stmt|;
name|friend
name|class
name|SBTarget
decl_stmt|;
name|friend
name|class
name|SBThread
decl_stmt|;
name|friend
name|class
name|SBValueList
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the appropriate ValueObjectSP from this SBValue, consulting the
comment|/// use_dynamic and use_synthetic options passed in to SetSP when the
comment|/// SBValue's contents were set.  Since this often requires examining memory,
comment|/// and maybe even running code, it needs to acquire the Target API and Process StopLock.
comment|/// Those are held in an opaque class ValueLocker which is currently local to SBValue.cpp.
comment|/// So you don't have to get these yourself just default construct a ValueLocker, and pass it into this.
comment|/// If we need to make a ValueLocker and use it in some other .cpp file, we'll have to move it to
comment|/// ValueObject.h/cpp or somewhere else convenient.  We haven't needed to so far.
comment|///
comment|/// @param[in] value_locker
comment|///     An object that will hold the Target API, and Process RunLocks, and
comment|///     auto-destroy them when it goes out of scope.  Currently this is only useful in
comment|///     SBValue.cpp.
comment|///
comment|/// @return
comment|///     A ValueObjectSP of the best kind (static, dynamic or synthetic) we
comment|///     can cons up, in accordance with the SBValue's settings.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ValueObjectSP
name|GetSP
argument_list|(
argument|ValueLocker&value_locker
argument_list|)
specifier|const
expr_stmt|;
comment|// these calls do the right thing WRT adjusting their settings according to the target's preferences
name|void
name|SetSP
argument_list|(
specifier|const
name|lldb
operator|::
name|ValueObjectSP
operator|&
name|sp
argument_list|)
decl_stmt|;
name|void
name|SetSP
argument_list|(
specifier|const
name|lldb
operator|::
name|ValueObjectSP
operator|&
name|sp
argument_list|,
name|bool
name|use_synthetic
argument_list|)
decl_stmt|;
name|void
name|SetSP
argument_list|(
specifier|const
name|lldb
operator|::
name|ValueObjectSP
operator|&
name|sp
argument_list|,
name|lldb
operator|::
name|DynamicValueType
name|use_dynamic
argument_list|)
decl_stmt|;
name|void
name|SetSP
argument_list|(
specifier|const
name|lldb
operator|::
name|ValueObjectSP
operator|&
name|sp
argument_list|,
name|lldb
operator|::
name|DynamicValueType
name|use_dynamic
argument_list|,
name|bool
name|use_synthetic
argument_list|)
decl_stmt|;
name|void
name|SetSP
argument_list|(
specifier|const
name|lldb
operator|::
name|ValueObjectSP
operator|&
name|sp
argument_list|,
name|lldb
operator|::
name|DynamicValueType
name|use_dynamic
argument_list|,
name|bool
name|use_synthetic
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|)
decl_stmt|;
name|private
label|:
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|ValueImpl
operator|>
name|ValueImplSP
expr_stmt|;
name|ValueImplSP
name|m_opaque_sp
decl_stmt|;
name|void
name|SetSP
parameter_list|(
name|ValueImplSP
name|impl_sp
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBValue_h_
end_comment

end_unit

