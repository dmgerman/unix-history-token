begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ValueObject.h -------------------------------------------*- C++ -*-===//
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
name|liblldb_ValueObject_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ValueObject_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/Value.h"
end_include

begin_include
include|#
directive|include
file|"lldb/DataFormatters/DumpValueObjectOptions.h"
end_include

begin_comment
comment|// for DumpValueObj...
end_comment

begin_include
include|#
directive|include
file|"lldb/Symbol/CompilerType.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/Type.h"
end_include

begin_comment
comment|// for TypeImpl
end_comment

begin_include
include|#
directive|include
file|"lldb/Target/ExecutionContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Process.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/DataExtractor.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Error.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/SharedCluster.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/UserID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_comment
comment|// for LLDB_INVALID...
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_comment
comment|// for DynamicValue...
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_comment
comment|// for ValueObjectSP
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-private-enumerations.h"
end_include

begin_comment
comment|// for AddressType
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_comment
comment|// for addr_t, offs...
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_comment
comment|// for StringRef
end_comment

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<initializer_list>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_comment
comment|// for recursive_mutex
end_comment

begin_include
include|#
directive|include
file|<string>
end_include

begin_comment
comment|// for string
end_comment

begin_include
include|#
directive|include
file|<utility>
end_include

begin_comment
comment|// for pair
end_comment

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// for size_t
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// for uint32_t
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Declaration
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|EvaluateExpressionOptions
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ExecutionContextScope
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Log
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Scalar
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Stream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|SymbolContextScope
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|TypeFormatImpl
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|TypeSummaryImpl
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|TypeSummaryOptions
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|/// ValueObject:
comment|///
comment|/// This abstract class provides an interface to a particular value, be it a
comment|/// register, a local or global variable,
comment|/// that is evaluated in some particular scope.  The ValueObject also has the
comment|/// capability of being the "child" of
comment|/// some other variable object, and in turn of having children.
comment|/// If a ValueObject is a root variable object - having no parent - then it must
comment|/// be constructed with respect to some
comment|/// particular ExecutionContextScope.  If it is a child, it inherits the
comment|/// ExecutionContextScope from its parent.
comment|/// The ValueObject will update itself if necessary before fetching its value,
comment|/// summary, object description, etc.
comment|/// But it will always update itself in the ExecutionContextScope with which it
comment|/// was originally created.
comment|/// A brief note on life cycle management for ValueObjects.  This is a little
comment|/// tricky because a ValueObject can contain
comment|/// various other ValueObjects - the Dynamic Value, its children, the
comment|/// dereference value, etc.  Any one of these can be
comment|/// handed out as a shared pointer, but for that contained value object to be
comment|/// valid, the root object and potentially other
comment|/// of the value objects need to stay around.
comment|/// We solve this problem by handing out shared pointers to the Value Object and
comment|/// any of its dependents using a shared
comment|/// ClusterManager.  This treats each shared pointer handed out for the entire
comment|/// cluster as a reference to the whole
comment|/// cluster.  The whole cluster will stay around until the last reference is
comment|/// released.
comment|///
comment|/// The ValueObject mostly handle this automatically, if a value object is made
comment|/// with a Parent ValueObject, then it adds
comment|/// itself to the ClusterManager of the parent.
comment|/// It does mean that external to the ValueObjects we should only ever make
comment|/// available ValueObjectSP's, never ValueObjects
comment|/// or pointers to them.  So all the "Root level" ValueObject derived
comment|/// constructors should be private, and
comment|/// should implement a Create function that new's up object and returns a Shared
comment|/// Pointer that it gets from the GetSP() method.
comment|///
comment|/// However, if you are making an derived ValueObject that will be contained in
comment|/// a parent value object, you should just
comment|/// hold onto a pointer to it internally, and by virtue of passing the parent
comment|/// ValueObject into its constructor, it will
comment|/// be added to the ClusterManager for the parent.  Then if you ever hand out a
comment|/// Shared Pointer to the contained ValueObject,
comment|/// just do so by calling GetSP() on the contained object.
name|class
name|ValueObject
range|:
name|public
name|UserID
block|{
name|public
operator|:
expr|enum
name|GetExpressionPathFormat
block|{
name|eGetExpressionPathFormatDereferencePointers
operator|=
literal|1
block|,
name|eGetExpressionPathFormatHonorPointers
block|}
block|;    enum
name|ValueObjectRepresentationStyle
block|{
name|eValueObjectRepresentationStyleValue
operator|=
literal|1
block|,
name|eValueObjectRepresentationStyleSummary
block|,
name|eValueObjectRepresentationStyleLanguageSpecific
block|,
name|eValueObjectRepresentationStyleLocation
block|,
name|eValueObjectRepresentationStyleChildrenCount
block|,
name|eValueObjectRepresentationStyleType
block|,
name|eValueObjectRepresentationStyleName
block|,
name|eValueObjectRepresentationStyleExpressionPath
block|}
block|;    enum
name|ExpressionPathScanEndReason
block|{
name|eExpressionPathScanEndReasonEndOfString
operator|=
literal|1
block|,
comment|// out of data to parse
name|eExpressionPathScanEndReasonNoSuchChild
block|,
comment|// child element not found
name|eExpressionPathScanEndReasonNoSuchSyntheticChild
block|,
comment|// (synthetic) child
comment|// element not found
name|eExpressionPathScanEndReasonEmptyRangeNotAllowed
block|,
comment|// [] only allowed for
comment|// arrays
name|eExpressionPathScanEndReasonDotInsteadOfArrow
block|,
comment|// . used when -> should be
comment|// used
name|eExpressionPathScanEndReasonArrowInsteadOfDot
block|,
comment|// -> used when . should be
comment|// used
name|eExpressionPathScanEndReasonFragileIVarNotAllowed
block|,
comment|// ObjC ivar expansion
comment|// not allowed
name|eExpressionPathScanEndReasonRangeOperatorNotAllowed
block|,
comment|// [] not allowed by
comment|// options
name|eExpressionPathScanEndReasonRangeOperatorInvalid
block|,
comment|// [] not valid on objects
comment|// other than scalars,
comment|// pointers or arrays
name|eExpressionPathScanEndReasonArrayRangeOperatorMet
block|,
comment|// [] is good for arrays,
comment|// but I cannot parse it
name|eExpressionPathScanEndReasonBitfieldRangeOperatorMet
block|,
comment|// [] is good for
comment|// bitfields, but I
comment|// cannot parse after
comment|// it
name|eExpressionPathScanEndReasonUnexpectedSymbol
block|,
comment|// something is malformed in
comment|// the expression
name|eExpressionPathScanEndReasonTakingAddressFailed
block|,
comment|// impossible to apply&
comment|// operator
name|eExpressionPathScanEndReasonDereferencingFailed
block|,
comment|// impossible to apply *
comment|// operator
name|eExpressionPathScanEndReasonRangeOperatorExpanded
block|,
comment|// [] was expanded into a
comment|// VOList
name|eExpressionPathScanEndReasonSyntheticValueMissing
block|,
comment|// getting the synthetic
comment|// children failed
name|eExpressionPathScanEndReasonUnknown
operator|=
literal|0xFFFF
block|}
block|;    enum
name|ExpressionPathEndResultType
block|{
name|eExpressionPathEndResultTypePlain
operator|=
literal|1
block|,
comment|// anything but...
name|eExpressionPathEndResultTypeBitfield
block|,
comment|// a bitfield
name|eExpressionPathEndResultTypeBoundedRange
block|,
comment|// a range [low-high]
name|eExpressionPathEndResultTypeUnboundedRange
block|,
comment|// a range []
name|eExpressionPathEndResultTypeValueObjectList
block|,
comment|// several items in a VOList
name|eExpressionPathEndResultTypeInvalid
operator|=
literal|0xFFFF
block|}
block|;    enum
name|ExpressionPathAftermath
block|{
name|eExpressionPathAftermathNothing
operator|=
literal|1
block|,
comment|// just return it
name|eExpressionPathAftermathDereference
block|,
comment|// dereference the target
name|eExpressionPathAftermathTakeAddress
comment|// take target's address
block|}
block|;    enum
name|ClearUserVisibleDataItems
block|{
name|eClearUserVisibleDataItemsNothing
operator|=
literal|1u
operator|<<
literal|0
block|,
name|eClearUserVisibleDataItemsValue
operator|=
literal|1u
operator|<<
literal|1
block|,
name|eClearUserVisibleDataItemsSummary
operator|=
literal|1u
operator|<<
literal|2
block|,
name|eClearUserVisibleDataItemsLocation
operator|=
literal|1u
operator|<<
literal|3
block|,
name|eClearUserVisibleDataItemsDescription
operator|=
literal|1u
operator|<<
literal|4
block|,
name|eClearUserVisibleDataItemsSyntheticChildren
operator|=
literal|1u
operator|<<
literal|5
block|,
name|eClearUserVisibleDataItemsValidator
operator|=
literal|1u
operator|<<
literal|6
block|,
name|eClearUserVisibleDataItemsAllStrings
operator|=
name|eClearUserVisibleDataItemsValue
operator||
name|eClearUserVisibleDataItemsSummary
operator||
name|eClearUserVisibleDataItemsLocation
operator||
name|eClearUserVisibleDataItemsDescription
block|,
name|eClearUserVisibleDataItemsAll
operator|=
literal|0xFFFF
block|}
block|;    struct
name|GetValueForExpressionPathOptions
block|{     enum
name|class
name|SyntheticChildrenTraversal
block|{
name|None
block|,
name|ToSynthetic
block|,
name|FromSynthetic
block|,
name|Both
block|}
block|;
name|bool
name|m_check_dot_vs_arrow_syntax
block|;
name|bool
name|m_no_fragile_ivar
block|;
name|bool
name|m_allow_bitfields_syntax
block|;
name|SyntheticChildrenTraversal
name|m_synthetic_children_traversal
block|;
name|GetValueForExpressionPathOptions
argument_list|(
argument|bool dot = false
argument_list|,
argument|bool no_ivar = false
argument_list|,
argument|bool bitfield = true
argument_list|,
argument|SyntheticChildrenTraversal synth_traverse =             SyntheticChildrenTraversal::ToSynthetic
argument_list|)
operator|:
name|m_check_dot_vs_arrow_syntax
argument_list|(
name|dot
argument_list|)
block|,
name|m_no_fragile_ivar
argument_list|(
name|no_ivar
argument_list|)
block|,
name|m_allow_bitfields_syntax
argument_list|(
name|bitfield
argument_list|)
block|,
name|m_synthetic_children_traversal
argument_list|(
argument|synth_traverse
argument_list|)
block|{}
name|GetValueForExpressionPathOptions
operator|&
name|DoCheckDotVsArrowSyntax
argument_list|()
block|{
name|m_check_dot_vs_arrow_syntax
operator|=
name|true
block|;
return|return
operator|*
name|this
return|;
block|}
name|GetValueForExpressionPathOptions
operator|&
name|DontCheckDotVsArrowSyntax
argument_list|()
block|{
name|m_check_dot_vs_arrow_syntax
operator|=
name|false
block|;
return|return
operator|*
name|this
return|;
block|}
name|GetValueForExpressionPathOptions
operator|&
name|DoAllowFragileIVar
argument_list|()
block|{
name|m_no_fragile_ivar
operator|=
name|false
block|;
return|return
operator|*
name|this
return|;
block|}
name|GetValueForExpressionPathOptions
operator|&
name|DontAllowFragileIVar
argument_list|()
block|{
name|m_no_fragile_ivar
operator|=
name|true
block|;
return|return
operator|*
name|this
return|;
block|}
name|GetValueForExpressionPathOptions
operator|&
name|DoAllowBitfieldSyntax
argument_list|()
block|{
name|m_allow_bitfields_syntax
operator|=
name|true
block|;
return|return
operator|*
name|this
return|;
block|}
name|GetValueForExpressionPathOptions
operator|&
name|DontAllowBitfieldSyntax
argument_list|()
block|{
name|m_allow_bitfields_syntax
operator|=
name|false
block|;
return|return
operator|*
name|this
return|;
block|}
name|GetValueForExpressionPathOptions
operator|&
name|SetSyntheticChildrenTraversal
argument_list|(
argument|SyntheticChildrenTraversal traverse
argument_list|)
block|{
name|m_synthetic_children_traversal
operator|=
name|traverse
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|static
specifier|const
name|GetValueForExpressionPathOptions
name|DefaultOptions
argument_list|()
block|{
specifier|static
name|GetValueForExpressionPathOptions
name|g_default_options
block|;
return|return
name|g_default_options
return|;
block|}
expr|}
block|;
name|class
name|EvaluationPoint
block|{
name|public
operator|:
name|EvaluationPoint
argument_list|()
block|;
name|EvaluationPoint
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|bool use_selected = false
argument_list|)
block|;
name|EvaluationPoint
argument_list|(
specifier|const
name|EvaluationPoint
operator|&
name|rhs
argument_list|)
block|;
operator|~
name|EvaluationPoint
argument_list|()
block|;
specifier|const
name|ExecutionContextRef
operator|&
name|GetExecutionContextRef
argument_list|()
specifier|const
block|{
return|return
name|m_exe_ctx_ref
return|;
block|}
comment|// Set the EvaluationPoint to the values in exe_scope,
comment|// Return true if the Evaluation Point changed.
comment|// Since the ExecutionContextScope is always going to be valid currently,
comment|// the Updated Context will also always be valid.
comment|//        bool
comment|//        SetContext (ExecutionContextScope *exe_scope);
name|void
name|SetIsConstant
argument_list|()
block|{
name|SetUpdated
argument_list|()
block|;
name|m_mod_id
operator|.
name|SetInvalid
argument_list|()
block|;     }
name|bool
name|IsConstant
argument_list|()
specifier|const
block|{
return|return
operator|!
name|m_mod_id
operator|.
name|IsValid
argument_list|()
return|;
block|}
name|ProcessModID
name|GetModID
argument_list|()
specifier|const
block|{
return|return
name|m_mod_id
return|;
block|}
name|void
name|SetUpdateID
argument_list|(
argument|ProcessModID new_id
argument_list|)
block|{
name|m_mod_id
operator|=
name|new_id
block|; }
name|void
name|SetNeedsUpdate
argument_list|()
block|{
name|m_needs_update
operator|=
name|true
block|; }
name|void
name|SetUpdated
argument_list|()
block|;
name|bool
name|NeedsUpdating
argument_list|(
argument|bool accept_invalid_exe_ctx
argument_list|)
block|{
name|SyncWithProcessState
argument_list|(
name|accept_invalid_exe_ctx
argument_list|)
block|;
return|return
name|m_needs_update
return|;
block|}
name|bool
name|IsValid
argument_list|()
block|{
specifier|const
name|bool
name|accept_invalid_exe_ctx
operator|=
name|false
block|;
if|if
condition|(
operator|!
name|m_mod_id
operator|.
name|IsValid
argument_list|()
condition|)
return|return
name|false
return|;
elseif|else
if|if
condition|(
name|SyncWithProcessState
argument_list|(
name|accept_invalid_exe_ctx
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|m_mod_id
operator|.
name|IsValid
argument_list|()
condition|)
return|return
name|false
return|;
block|}
return|return
name|true
return|;
block|}
name|void
name|SetInvalid
argument_list|()
block|{
comment|// Use the stop id to mark us as invalid, leave the thread id and the
comment|// stack id around for logging and
comment|// history purposes.
name|m_mod_id
operator|.
name|SetInvalid
argument_list|()
block|;
comment|// Can't update an invalid state.
name|m_needs_update
operator|=
name|false
block|;     }
name|private
operator|:
name|bool
name|SyncWithProcessState
argument_list|(
argument|bool accept_invalid_exe_ctx
argument_list|)
block|;
name|ProcessModID
name|m_mod_id
block|;
comment|// This is the stop id when this ValueObject was last
comment|// evaluated.
name|ExecutionContextRef
name|m_exe_ctx_ref
block|;
name|bool
name|m_needs_update
block|;   }
block|;
name|virtual
operator|~
name|ValueObject
argument_list|()
block|;
specifier|const
name|EvaluationPoint
operator|&
name|GetUpdatePoint
argument_list|()
specifier|const
block|{
return|return
name|m_update_point
return|;
block|}
name|EvaluationPoint
operator|&
name|GetUpdatePoint
argument_list|()
block|{
return|return
name|m_update_point
return|;
block|}
specifier|const
name|ExecutionContextRef
operator|&
name|GetExecutionContextRef
argument_list|()
specifier|const
block|{
return|return
name|m_update_point
operator|.
name|GetExecutionContextRef
argument_list|()
return|;
block|}
name|lldb
operator|::
name|TargetSP
name|GetTargetSP
argument_list|()
specifier|const
block|{
return|return
name|m_update_point
operator|.
name|GetExecutionContextRef
argument_list|()
operator|.
name|GetTargetSP
argument_list|()
return|;
block|}
name|lldb
operator|::
name|ProcessSP
name|GetProcessSP
argument_list|()
specifier|const
block|{
return|return
name|m_update_point
operator|.
name|GetExecutionContextRef
argument_list|()
operator|.
name|GetProcessSP
argument_list|()
return|;
block|}
name|lldb
operator|::
name|ThreadSP
name|GetThreadSP
argument_list|()
specifier|const
block|{
return|return
name|m_update_point
operator|.
name|GetExecutionContextRef
argument_list|()
operator|.
name|GetThreadSP
argument_list|()
return|;
block|}
name|lldb
operator|::
name|StackFrameSP
name|GetFrameSP
argument_list|()
specifier|const
block|{
return|return
name|m_update_point
operator|.
name|GetExecutionContextRef
argument_list|()
operator|.
name|GetFrameSP
argument_list|()
return|;
block|}
name|void
name|SetNeedsUpdate
argument_list|()
block|;
name|CompilerType
name|GetCompilerType
argument_list|()
block|;
comment|// this vends a TypeImpl that is useful at the SB API layer
name|virtual
name|TypeImpl
name|GetTypeImpl
argument_list|()
block|;
name|virtual
name|bool
name|CanProvideValue
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|// Subclasses must implement the functions below.
comment|//------------------------------------------------------------------
name|virtual
name|uint64_t
name|GetByteSize
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|lldb
operator|::
name|ValueType
name|GetValueType
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|//------------------------------------------------------------------
comment|// Subclasses can implement the functions below.
comment|//------------------------------------------------------------------
name|virtual
name|ConstString
name|GetTypeName
argument_list|()
block|;
name|virtual
name|ConstString
name|GetDisplayTypeName
argument_list|()
block|;
name|virtual
name|ConstString
name|GetQualifiedTypeName
argument_list|()
block|;
name|virtual
name|lldb
operator|::
name|LanguageType
name|GetObjectRuntimeLanguage
argument_list|()
block|;
name|virtual
name|uint32_t
name|GetTypeInfo
argument_list|(
name|CompilerType
operator|*
name|pointee_or_element_compiler_type
operator|=
name|nullptr
argument_list|)
block|;
name|virtual
name|bool
name|IsPointerType
argument_list|()
block|;
name|virtual
name|bool
name|IsArrayType
argument_list|()
block|;
name|virtual
name|bool
name|IsScalarType
argument_list|()
block|;
name|virtual
name|bool
name|IsPointerOrReferenceType
argument_list|()
block|;
name|virtual
name|bool
name|IsPossibleDynamicType
argument_list|()
block|;
name|bool
name|IsNilReference
argument_list|()
block|;
name|bool
name|IsUninitializedReference
argument_list|()
block|;
name|virtual
name|bool
name|IsBaseClass
argument_list|()
block|{
return|return
name|false
return|;
block|}
name|bool
name|IsBaseClass
argument_list|(
name|uint32_t
operator|&
name|depth
argument_list|)
block|;
name|virtual
name|bool
name|IsDereferenceOfParent
argument_list|()
block|{
return|return
name|false
return|;
block|}
name|bool
name|IsIntegerType
argument_list|(
name|bool
operator|&
name|is_signed
argument_list|)
block|;
name|virtual
name|bool
name|GetBaseClassPath
argument_list|(
name|Stream
operator|&
name|s
argument_list|)
block|;
name|virtual
name|void
name|GetExpressionPath
argument_list|(
argument|Stream&s
argument_list|,
argument|bool qualify_cxx_base_classes
argument_list|,
argument|GetExpressionPathFormat = eGetExpressionPathFormatDereferencePointers
argument_list|)
block|;
name|lldb
operator|::
name|ValueObjectSP
name|GetValueForExpressionPath
argument_list|(
argument|llvm::StringRef expression
argument_list|,
argument|ExpressionPathScanEndReason *reason_to_stop = nullptr
argument_list|,
argument|ExpressionPathEndResultType *final_value_type = nullptr
argument_list|,
argument|const GetValueForExpressionPathOptions&options =           GetValueForExpressionPathOptions::DefaultOptions()
argument_list|,
argument|ExpressionPathAftermath *final_task_on_target = nullptr
argument_list|)
block|;
name|virtual
name|bool
name|IsInScope
argument_list|()
block|{
return|return
name|true
return|;
block|}
name|virtual
name|lldb
operator|::
name|offset_t
name|GetByteOffset
argument_list|()
block|{
return|return
literal|0
return|;
block|}
name|virtual
name|uint32_t
name|GetBitfieldBitSize
argument_list|()
block|{
return|return
literal|0
return|;
block|}
name|virtual
name|uint32_t
name|GetBitfieldBitOffset
argument_list|()
block|{
return|return
literal|0
return|;
block|}
name|bool
name|IsBitfield
argument_list|()
block|{
return|return
operator|(
name|GetBitfieldBitSize
argument_list|()
operator|!=
literal|0
operator|)
operator|||
operator|(
name|GetBitfieldBitOffset
argument_list|()
operator|!=
literal|0
operator|)
return|;
block|}
name|virtual
name|bool
name|IsArrayItemForPointer
argument_list|()
block|{
return|return
name|m_is_array_item_for_pointer
return|;
block|}
name|virtual
specifier|const
name|char
operator|*
name|GetValueAsCString
argument_list|()
block|;
name|virtual
name|bool
name|GetValueAsCString
argument_list|(
specifier|const
name|lldb_private
operator|::
name|TypeFormatImpl
operator|&
name|format
argument_list|,
name|std
operator|::
name|string
operator|&
name|destination
argument_list|)
block|;
name|bool
name|GetValueAsCString
argument_list|(
argument|lldb::Format format
argument_list|,
argument|std::string&destination
argument_list|)
block|;
name|virtual
name|uint64_t
name|GetValueAsUnsigned
argument_list|(
argument|uint64_t fail_value
argument_list|,
argument|bool *success = nullptr
argument_list|)
block|;
name|virtual
name|int64_t
name|GetValueAsSigned
argument_list|(
argument|int64_t fail_value
argument_list|,
argument|bool *success = nullptr
argument_list|)
block|;
name|virtual
name|bool
name|SetValueFromCString
argument_list|(
specifier|const
name|char
operator|*
name|value_str
argument_list|,
name|Error
operator|&
name|error
argument_list|)
block|;
comment|// Return the module associated with this value object in case the
comment|// value is from an executable file and might have its data in
comment|// sections of the file. This can be used for variables.
name|virtual
name|lldb
operator|::
name|ModuleSP
name|GetModule
argument_list|()
block|;
name|ValueObject
operator|*
name|GetRoot
argument_list|()
block|;
comment|// Given a ValueObject, loop over itself and its parent, and its parent's
comment|// parent, ..
comment|// until either the given callback returns false, or you end up at a null
comment|// pointer
name|ValueObject
operator|*
name|FollowParentChain
argument_list|(
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
name|ValueObject
operator|*
argument_list|)
operator|>
argument_list|)
block|;
name|virtual
name|bool
name|GetDeclaration
argument_list|(
name|Declaration
operator|&
name|decl
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// The functions below should NOT be modified by subclasses
comment|//------------------------------------------------------------------
specifier|const
name|Error
operator|&
name|GetError
argument_list|()
block|;
specifier|const
name|ConstString
operator|&
name|GetName
argument_list|()
specifier|const
block|;
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|GetChildAtIndex
argument_list|(
argument|size_t idx
argument_list|,
argument|bool can_create
argument_list|)
block|;
comment|// this will always create the children if necessary
name|lldb
operator|::
name|ValueObjectSP
name|GetChildAtIndexPath
argument_list|(
specifier|const
name|std
operator|::
name|initializer_list
operator|<
name|size_t
operator|>
operator|&
name|idxs
argument_list|,
name|size_t
operator|*
name|index_of_error
operator|=
name|nullptr
argument_list|)
block|;
name|lldb
operator|::
name|ValueObjectSP
name|GetChildAtIndexPath
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|size_t
operator|>
operator|&
name|idxs
argument_list|,
name|size_t
operator|*
name|index_of_error
operator|=
name|nullptr
argument_list|)
block|;
name|lldb
operator|::
name|ValueObjectSP
name|GetChildAtIndexPath
argument_list|(
specifier|const
name|std
operator|::
name|initializer_list
operator|<
name|std
operator|::
name|pair
operator|<
name|size_t
argument_list|,
name|bool
operator|>>
operator|&
name|idxs
argument_list|,
name|size_t
operator|*
name|index_of_error
operator|=
name|nullptr
argument_list|)
block|;
name|lldb
operator|::
name|ValueObjectSP
name|GetChildAtIndexPath
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|size_t
argument_list|,
name|bool
operator|>>
operator|&
name|idxs
argument_list|,
name|size_t
operator|*
name|index_of_error
operator|=
name|nullptr
argument_list|)
block|;
comment|// this will always create the children if necessary
name|lldb
operator|::
name|ValueObjectSP
name|GetChildAtNamePath
argument_list|(
specifier|const
name|std
operator|::
name|initializer_list
operator|<
name|ConstString
operator|>
operator|&
name|names
argument_list|,
name|ConstString
operator|*
name|name_of_error
operator|=
name|nullptr
argument_list|)
block|;
name|lldb
operator|::
name|ValueObjectSP
name|GetChildAtNamePath
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|ConstString
operator|>
operator|&
name|names
argument_list|,
name|ConstString
operator|*
name|name_of_error
operator|=
name|nullptr
argument_list|)
block|;
name|lldb
operator|::
name|ValueObjectSP
name|GetChildAtNamePath
argument_list|(
specifier|const
name|std
operator|::
name|initializer_list
operator|<
name|std
operator|::
name|pair
operator|<
name|ConstString
argument_list|,
name|bool
operator|>>
operator|&
name|names
argument_list|,
name|ConstString
operator|*
name|name_of_error
operator|=
name|nullptr
argument_list|)
block|;
name|lldb
operator|::
name|ValueObjectSP
name|GetChildAtNamePath
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|ConstString
argument_list|,
name|bool
operator|>>
operator|&
name|names
argument_list|,
name|ConstString
operator|*
name|name_of_error
operator|=
name|nullptr
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|GetChildMemberWithName
argument_list|(
argument|const ConstString&name
argument_list|,
argument|bool can_create
argument_list|)
block|;
name|virtual
name|size_t
name|GetIndexOfChildWithName
argument_list|(
specifier|const
name|ConstString
operator|&
name|name
argument_list|)
block|;
name|size_t
name|GetNumChildren
argument_list|(
argument|uint32_t max = UINT32_MAX
argument_list|)
block|;
specifier|const
name|Value
operator|&
name|GetValue
argument_list|()
specifier|const
block|;
name|Value
operator|&
name|GetValue
argument_list|()
block|;
name|virtual
name|bool
name|ResolveValue
argument_list|(
name|Scalar
operator|&
name|scalar
argument_list|)
block|;
comment|// return 'false' whenever you set the error, otherwise
comment|// callers may assume true means everything is OK - this will
comment|// break breakpoint conditions among potentially a few others
name|virtual
name|bool
name|IsLogicalTrue
argument_list|(
name|Error
operator|&
name|error
argument_list|)
block|;
name|virtual
specifier|const
name|char
operator|*
name|GetLocationAsCString
argument_list|()
block|;
specifier|const
name|char
operator|*
name|GetSummaryAsCString
argument_list|(
argument|lldb::LanguageType lang = lldb::eLanguageTypeUnknown
argument_list|)
block|;
name|bool
name|GetSummaryAsCString
argument_list|(
argument|TypeSummaryImpl *summary_ptr
argument_list|,
argument|std::string&destination
argument_list|,
argument|lldb::LanguageType lang = lldb::eLanguageTypeUnknown
argument_list|)
block|;
name|bool
name|GetSummaryAsCString
argument_list|(
name|std
operator|::
name|string
operator|&
name|destination
argument_list|,
specifier|const
name|TypeSummaryOptions
operator|&
name|options
argument_list|)
block|;
name|bool
name|GetSummaryAsCString
argument_list|(
name|TypeSummaryImpl
operator|*
name|summary_ptr
argument_list|,
name|std
operator|::
name|string
operator|&
name|destination
argument_list|,
specifier|const
name|TypeSummaryOptions
operator|&
name|options
argument_list|)
block|;
name|std
operator|::
name|pair
operator|<
name|TypeValidatorResult
block|,
name|std
operator|::
name|string
operator|>
name|GetValidationStatus
argument_list|()
block|;
specifier|const
name|char
operator|*
name|GetObjectDescription
argument_list|()
block|;
name|bool
name|HasSpecialPrintableRepresentation
argument_list|(
argument|ValueObjectRepresentationStyle val_obj_display
argument_list|,
argument|lldb::Format custom_format
argument_list|)
block|;    enum
name|class
name|PrintableRepresentationSpecialCases
operator|:
name|bool
block|{
name|eDisable
operator|=
name|false
block|,
name|eAllow
operator|=
name|true
block|}
block|;
name|bool
name|DumpPrintableRepresentation
argument_list|(
argument|Stream&s
argument_list|,
argument|ValueObjectRepresentationStyle val_obj_display =                                   eValueObjectRepresentationStyleSummary
argument_list|,
argument|lldb::Format custom_format = lldb::eFormatInvalid
argument_list|,
argument|PrintableRepresentationSpecialCases special =                                   PrintableRepresentationSpecialCases::eAllow
argument_list|,
argument|bool do_dump_error = true
argument_list|)
block|;
name|bool
name|GetValueIsValid
argument_list|()
specifier|const
block|;
comment|// If you call this on a newly created ValueObject, it will always return
comment|// false.
name|bool
name|GetValueDidChange
argument_list|()
block|;
name|bool
name|UpdateValueIfNeeded
argument_list|(
argument|bool update_format = true
argument_list|)
block|;
name|bool
name|UpdateFormatsIfNeeded
argument_list|()
block|;
name|lldb
operator|::
name|ValueObjectSP
name|GetSP
argument_list|()
block|{
return|return
name|m_manager
operator|->
name|GetSharedPointer
argument_list|(
name|this
argument_list|)
return|;
block|}
comment|// Change the name of the current ValueObject. Should *not* be used from a
comment|// synthetic child provider as it would change the name of the non synthetic
comment|// child as well.
name|void
name|SetName
argument_list|(
specifier|const
name|ConstString
operator|&
name|name
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|addr_t
name|GetAddressOf
argument_list|(
argument|bool scalar_is_load_address = true
argument_list|,
argument|AddressType *address_type = nullptr
argument_list|)
block|;
name|lldb
operator|::
name|addr_t
name|GetPointerValue
argument_list|(
name|AddressType
operator|*
name|address_type
operator|=
name|nullptr
argument_list|)
block|;
name|lldb
operator|::
name|ValueObjectSP
name|GetSyntheticChild
argument_list|(
argument|const ConstString&key
argument_list|)
specifier|const
block|;
name|lldb
operator|::
name|ValueObjectSP
name|GetSyntheticArrayMember
argument_list|(
argument|size_t index
argument_list|,
argument|bool can_create
argument_list|)
block|;
name|lldb
operator|::
name|ValueObjectSP
name|GetSyntheticBitFieldChild
argument_list|(
argument|uint32_t from
argument_list|,
argument|uint32_t to
argument_list|,
argument|bool can_create
argument_list|)
block|;
name|lldb
operator|::
name|ValueObjectSP
name|GetSyntheticExpressionPathChild
argument_list|(
argument|const char *expression
argument_list|,
argument|bool can_create
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|GetSyntheticChildAtOffset
argument_list|(
argument|uint32_t offset
argument_list|,
argument|const CompilerType&type
argument_list|,
argument|bool can_create
argument_list|,
argument|ConstString name_const_str = ConstString()
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|GetSyntheticBase
argument_list|(
argument|uint32_t offset
argument_list|,
argument|const CompilerType&type
argument_list|,
argument|bool can_create
argument_list|,
argument|ConstString name_const_str = ConstString()
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|GetDynamicValue
argument_list|(
argument|lldb::DynamicValueType valueType
argument_list|)
block|;
name|lldb
operator|::
name|DynamicValueType
name|GetDynamicValueType
argument_list|()
block|;
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|GetStaticValue
argument_list|()
block|;
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|GetNonSyntheticValue
argument_list|()
block|;
name|lldb
operator|::
name|ValueObjectSP
name|GetSyntheticValue
argument_list|(
argument|bool use_synthetic = true
argument_list|)
block|;
name|virtual
name|bool
name|HasSyntheticValue
argument_list|()
block|;
name|virtual
name|bool
name|IsSynthetic
argument_list|()
block|{
return|return
name|false
return|;
block|}
name|lldb
operator|::
name|ValueObjectSP
name|GetQualifiedRepresentationIfAvailable
argument_list|(
argument|lldb::DynamicValueType dynValue
argument_list|,
argument|bool synthValue
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|CreateConstantValue
argument_list|(
specifier|const
name|ConstString
operator|&
name|name
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|Dereference
argument_list|(
name|Error
operator|&
name|error
argument_list|)
block|;
comment|// Creates a copy of the ValueObject with a new name and setting the current
comment|// ValueObject as its parent. It should be used when we want to change the
comment|// name of a ValueObject without modifying the actual ValueObject itself
comment|// (e.g. sythetic child provider).
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|Clone
argument_list|(
specifier|const
name|ConstString
operator|&
name|new_name
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|AddressOf
argument_list|(
name|Error
operator|&
name|error
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|addr_t
name|GetLiveAddress
argument_list|()
block|{
return|return
name|LLDB_INVALID_ADDRESS
return|;
block|}
name|virtual
name|void
name|SetLiveAddress
argument_list|(
argument|lldb::addr_t addr = LLDB_INVALID_ADDRESS
argument_list|,
argument|AddressType address_type = eAddressTypeLoad
argument_list|)
block|{}
comment|// Find the address of the C++ vtable pointer
name|virtual
name|lldb
operator|::
name|addr_t
name|GetCPPVTableAddress
argument_list|(
name|AddressType
operator|&
name|address_type
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|Cast
argument_list|(
specifier|const
name|CompilerType
operator|&
name|compiler_type
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|CastPointerType
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
name|CompilerType
operator|&
name|ast_type
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|CastPointerType
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
name|lldb
operator|::
name|TypeSP
operator|&
name|type_sp
argument_list|)
block|;
comment|// The backing bits of this value object were updated, clear any
comment|// descriptive string, so we know we have to refetch them
name|virtual
name|void
name|ValueUpdated
argument_list|()
block|{
name|ClearUserVisibleData
argument_list|(
name|eClearUserVisibleDataItemsValue
operator||
name|eClearUserVisibleDataItemsSummary
operator||
name|eClearUserVisibleDataItemsDescription
argument_list|)
block|;   }
name|virtual
name|bool
name|IsDynamic
argument_list|()
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|DoesProvideSyntheticValue
argument_list|()
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|IsSyntheticChildrenGenerated
argument_list|()
block|;
name|virtual
name|void
name|SetSyntheticChildrenGenerated
argument_list|(
argument|bool b
argument_list|)
block|;
name|virtual
name|SymbolContextScope
operator|*
name|GetSymbolContextScope
argument_list|()
block|;
name|void
name|Dump
argument_list|(
name|Stream
operator|&
name|s
argument_list|)
block|;
name|void
name|Dump
argument_list|(
name|Stream
operator|&
name|s
argument_list|,
specifier|const
name|DumpValueObjectOptions
operator|&
name|options
argument_list|)
block|;
specifier|static
name|lldb
operator|::
name|ValueObjectSP
name|CreateValueObjectFromExpression
argument_list|(
argument|llvm::StringRef name
argument_list|,
argument|llvm::StringRef expression
argument_list|,
argument|const ExecutionContext&exe_ctx
argument_list|)
block|;
specifier|static
name|lldb
operator|::
name|ValueObjectSP
name|CreateValueObjectFromExpression
argument_list|(
argument|llvm::StringRef name
argument_list|,
argument|llvm::StringRef expression
argument_list|,
argument|const ExecutionContext&exe_ctx
argument_list|,
argument|const EvaluateExpressionOptions&options
argument_list|)
block|;
specifier|static
name|lldb
operator|::
name|ValueObjectSP
name|CreateValueObjectFromAddress
argument_list|(
argument|llvm::StringRef name
argument_list|,
argument|uint64_t address
argument_list|,
argument|const ExecutionContext&exe_ctx
argument_list|,
argument|CompilerType type
argument_list|)
block|;
specifier|static
name|lldb
operator|::
name|ValueObjectSP
name|CreateValueObjectFromData
argument_list|(
argument|llvm::StringRef name
argument_list|,
argument|const DataExtractor&data
argument_list|,
argument|const ExecutionContext&exe_ctx
argument_list|,
argument|CompilerType type
argument_list|)
block|;
name|void
name|LogValueObject
argument_list|(
name|Log
operator|*
name|log
argument_list|)
block|;
name|void
name|LogValueObject
argument_list|(
name|Log
operator|*
name|log
argument_list|,
specifier|const
name|DumpValueObjectOptions
operator|&
name|options
argument_list|)
block|;
name|lldb
operator|::
name|ValueObjectSP
name|Persist
argument_list|()
block|;
comment|// returns true if this is a char* or a char[]
comment|// if it is a char* and check_pointer is true,
comment|// it also checks that the pointer is valid
name|bool
name|IsCStringContainer
argument_list|(
argument|bool check_pointer = false
argument_list|)
block|;
name|std
operator|::
name|pair
operator|<
name|size_t
block|,
name|bool
operator|>
name|ReadPointedString
argument_list|(
argument|lldb::DataBufferSP&buffer_sp
argument_list|,
argument|Error&error
argument_list|,
argument|uint32_t max_length =
literal|0
argument_list|,
argument|bool honor_array = true
argument_list|,
argument|lldb::Format item_format = lldb::eFormatCharArray
argument_list|)
block|;
name|virtual
name|size_t
name|GetPointeeData
argument_list|(
argument|DataExtractor&data
argument_list|,
argument|uint32_t item_idx =
literal|0
argument_list|,
argument|uint32_t item_count =
literal|1
argument_list|)
block|;
name|virtual
name|uint64_t
name|GetData
argument_list|(
name|DataExtractor
operator|&
name|data
argument_list|,
name|Error
operator|&
name|error
argument_list|)
block|;
name|virtual
name|bool
name|SetData
argument_list|(
name|DataExtractor
operator|&
name|data
argument_list|,
name|Error
operator|&
name|error
argument_list|)
block|;
name|virtual
name|bool
name|GetIsConstant
argument_list|()
specifier|const
block|{
return|return
name|m_update_point
operator|.
name|IsConstant
argument_list|()
return|;
block|}
name|bool
name|NeedsUpdating
argument_list|()
block|{
specifier|const
name|bool
name|accept_invalid_exe_ctx
operator|=
operator|(
name|CanUpdateWithInvalidExecutionContext
argument_list|()
operator|==
name|eLazyBoolYes
operator|)
block|;
return|return
name|m_update_point
operator|.
name|NeedsUpdating
argument_list|(
name|accept_invalid_exe_ctx
argument_list|)
return|;
block|}
name|void
name|SetIsConstant
argument_list|()
block|{
name|m_update_point
operator|.
name|SetIsConstant
argument_list|()
block|; }
name|lldb
operator|::
name|Format
name|GetFormat
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|SetFormat
argument_list|(
argument|lldb::Format format
argument_list|)
block|{
if|if
condition|(
name|format
operator|!=
name|m_format
condition|)
name|ClearUserVisibleData
argument_list|(
name|eClearUserVisibleDataItemsValue
argument_list|)
expr_stmt|;
name|m_format
operator|=
name|format
block|;   }
name|virtual
name|lldb
operator|::
name|LanguageType
name|GetPreferredDisplayLanguage
argument_list|()
block|;
name|void
name|SetPreferredDisplayLanguage
argument_list|(
name|lldb
operator|::
name|LanguageType
argument_list|)
block|;
name|lldb
operator|::
name|TypeSummaryImplSP
name|GetSummaryFormat
argument_list|()
block|{
name|UpdateFormatsIfNeeded
argument_list|()
block|;
return|return
name|m_type_summary_sp
return|;
block|}
name|void
name|SetSummaryFormat
argument_list|(
argument|lldb::TypeSummaryImplSP format
argument_list|)
block|{
name|m_type_summary_sp
operator|=
name|format
block|;
name|ClearUserVisibleData
argument_list|(
name|eClearUserVisibleDataItemsSummary
argument_list|)
block|;   }
name|lldb
operator|::
name|TypeValidatorImplSP
name|GetValidator
argument_list|()
block|{
name|UpdateFormatsIfNeeded
argument_list|()
block|;
return|return
name|m_type_validator_sp
return|;
block|}
name|void
name|SetValidator
argument_list|(
argument|lldb::TypeValidatorImplSP format
argument_list|)
block|{
name|m_type_validator_sp
operator|=
name|format
block|;
name|ClearUserVisibleData
argument_list|(
name|eClearUserVisibleDataItemsValidator
argument_list|)
block|;   }
name|void
name|SetValueFormat
argument_list|(
argument|lldb::TypeFormatImplSP format
argument_list|)
block|{
name|m_type_format_sp
operator|=
name|format
block|;
name|ClearUserVisibleData
argument_list|(
name|eClearUserVisibleDataItemsValue
argument_list|)
block|;   }
name|lldb
operator|::
name|TypeFormatImplSP
name|GetValueFormat
argument_list|()
block|{
name|UpdateFormatsIfNeeded
argument_list|()
block|;
return|return
name|m_type_format_sp
return|;
block|}
name|void
name|SetSyntheticChildren
argument_list|(
argument|const lldb::SyntheticChildrenSP&synth_sp
argument_list|)
block|{
if|if
condition|(
name|synth_sp
operator|.
name|get
argument_list|()
operator|==
name|m_synthetic_children_sp
operator|.
name|get
argument_list|()
condition|)
return|return;
name|ClearUserVisibleData
argument_list|(
name|eClearUserVisibleDataItemsSyntheticChildren
argument_list|)
block|;
name|m_synthetic_children_sp
operator|=
name|synth_sp
block|;   }
name|lldb
operator|::
name|SyntheticChildrenSP
name|GetSyntheticChildren
argument_list|()
block|{
name|UpdateFormatsIfNeeded
argument_list|()
block|;
return|return
name|m_synthetic_children_sp
return|;
block|}
comment|// Use GetParent for display purposes, but if you want to tell the parent to
comment|// update itself
comment|// then use m_parent.  The ValueObjectDynamicValue's parent is not the correct
comment|// parent for
comment|// displaying, they are really siblings, so for display it needs to route
comment|// through to its grandparent.
name|virtual
name|ValueObject
modifier|*
name|GetParent
parameter_list|()
block|{
return|return
name|m_parent
return|;
block|}
name|virtual
specifier|const
name|ValueObject
operator|*
name|GetParent
argument_list|()
specifier|const
block|{
return|return
name|m_parent
return|;
block|}
name|ValueObject
modifier|*
name|GetNonBaseClassParent
parameter_list|()
function_decl|;
name|void
name|SetAddressTypeOfChildren
parameter_list|(
name|AddressType
name|at
parameter_list|)
block|{
name|m_address_type_of_ptr_or_ref_children
operator|=
name|at
expr_stmt|;
block|}
name|AddressType
name|GetAddressTypeOfChildren
parameter_list|()
function_decl|;
name|void
name|SetHasCompleteType
parameter_list|()
block|{
name|m_did_calculate_complete_objc_class_type
operator|=
name|true
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|/// Find out if a ValueObject might have children.
comment|///
comment|/// This call is much more efficient than CalculateNumChildren() as
comment|/// it doesn't need to complete the underlying type. This is designed
comment|/// to be used in a UI environment in order to detect if the
comment|/// disclosure triangle should be displayed or not.
comment|///
comment|/// This function returns true for class, union, structure,
comment|/// pointers, references, arrays and more. Again, it does so without
comment|/// doing any expensive type completion.
comment|///
comment|/// @return
comment|///     Returns \b true if the ValueObject might have children, or \b
comment|///     false otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|MightHaveChildren
parameter_list|()
function_decl|;
name|virtual
name|lldb
operator|::
name|VariableSP
name|GetVariable
argument_list|()
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
name|bool
name|IsRuntimeSupportValue
parameter_list|()
function_decl|;
name|virtual
name|uint64_t
name|GetLanguageFlags
parameter_list|()
function_decl|;
name|virtual
name|void
name|SetLanguageFlags
parameter_list|(
name|uint64_t
name|flags
parameter_list|)
function_decl|;
name|protected
label|:
typedef|typedef
name|ClusterManager
operator|<
name|ValueObject
operator|>
name|ValueObjectManager
expr_stmt|;
name|class
name|ChildrenManager
block|{
name|public
label|:
name|ChildrenManager
argument_list|()
operator|:
name|m_mutex
argument_list|()
operator|,
name|m_children
argument_list|()
operator|,
name|m_children_count
argument_list|(
literal|0
argument_list|)
block|{}
name|bool
name|HasChildAtIndex
argument_list|(
argument|size_t idx
argument_list|)
block|{
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|recursive_mutex
operator|>
name|guard
argument_list|(
name|m_mutex
argument_list|)
block|;
return|return
operator|(
name|m_children
operator|.
name|find
argument_list|(
name|idx
argument_list|)
operator|!=
name|m_children
operator|.
name|end
argument_list|()
operator|)
return|;
block|}
name|ValueObject
modifier|*
name|GetChildAtIndex
parameter_list|(
name|size_t
name|idx
parameter_list|)
block|{
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|recursive_mutex
operator|>
name|guard
argument_list|(
name|m_mutex
argument_list|)
expr_stmt|;
specifier|const
specifier|auto
name|iter
init|=
name|m_children
operator|.
name|find
argument_list|(
name|idx
argument_list|)
decl_stmt|;
return|return
operator|(
operator|(
name|iter
operator|==
name|m_children
operator|.
name|end
argument_list|()
operator|)
condition|?
name|nullptr
else|:
name|iter
operator|->
name|second
operator|)
return|;
block|}
name|void
name|SetChildAtIndex
parameter_list|(
name|size_t
name|idx
parameter_list|,
name|ValueObject
modifier|*
name|valobj
parameter_list|)
block|{
comment|// we do not need to be mutex-protected to make a pair
name|ChildrenPair
name|pair
argument_list|(
name|idx
argument_list|,
name|valobj
argument_list|)
decl_stmt|;
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|recursive_mutex
operator|>
name|guard
argument_list|(
name|m_mutex
argument_list|)
expr_stmt|;
name|m_children
operator|.
name|insert
argument_list|(
name|pair
argument_list|)
expr_stmt|;
block|}
name|void
name|SetChildrenCount
parameter_list|(
name|size_t
name|count
parameter_list|)
block|{
name|Clear
argument_list|(
name|count
argument_list|)
expr_stmt|;
block|}
name|size_t
name|GetChildrenCount
parameter_list|()
block|{
return|return
name|m_children_count
return|;
block|}
name|void
name|Clear
parameter_list|(
name|size_t
name|new_count
init|=
literal|0
parameter_list|)
block|{
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|recursive_mutex
operator|>
name|guard
argument_list|(
name|m_mutex
argument_list|)
expr_stmt|;
name|m_children_count
operator|=
name|new_count
expr_stmt|;
name|m_children
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|private
label|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|size_t
operator|,
name|ValueObject
operator|*
operator|>
name|ChildrenMap
expr_stmt|;
typedef|typedef
name|ChildrenMap
operator|::
name|iterator
name|ChildrenIterator
expr_stmt|;
typedef|typedef
name|ChildrenMap
operator|::
name|value_type
name|ChildrenPair
expr_stmt|;
name|std
operator|::
name|recursive_mutex
name|m_mutex
expr_stmt|;
name|ChildrenMap
name|m_children
decl_stmt|;
name|size_t
name|m_children_count
decl_stmt|;
block|}
empty_stmt|;
comment|//------------------------------------------------------------------
comment|// Classes that inherit from ValueObject can see and modify these
comment|//------------------------------------------------------------------
name|ValueObject
modifier|*
name|m_parent
decl_stmt|;
comment|// The parent value object, or nullptr if this has no parent
name|ValueObject
modifier|*
name|m_root
decl_stmt|;
comment|// The root of the hierarchy for this ValueObject (or
comment|// nullptr if never calculated)
name|EvaluationPoint
name|m_update_point
decl_stmt|;
comment|// Stores both the stop id and the full
comment|// context at which this value was last
comment|// updated.  When we are asked to update the value object, we check whether
comment|// the context& stop id are the same before updating.
name|ConstString
name|m_name
decl_stmt|;
comment|// The name of this object
name|DataExtractor
name|m_data
decl_stmt|;
comment|// A data extractor that can be used to extract the value.
name|Value
name|m_value
decl_stmt|;
name|Error
name|m_error
decl_stmt|;
comment|// An error object that can describe any errors that occur when
comment|// updating values.
name|std
operator|::
name|string
name|m_value_str
expr_stmt|;
comment|// Cached value string that will get cleared if/when
comment|// the value is updated.
name|std
operator|::
name|string
name|m_old_value_str
expr_stmt|;
comment|// Cached old value string from the last time the
comment|// value was gotten
name|std
operator|::
name|string
name|m_location_str
expr_stmt|;
comment|// Cached location string that will get cleared
comment|// if/when the value is updated.
name|std
operator|::
name|string
name|m_summary_str
expr_stmt|;
comment|// Cached summary string that will get cleared
comment|// if/when the value is updated.
name|std
operator|::
name|string
name|m_object_desc_str
expr_stmt|;
comment|// Cached result of the "object printer".  This
comment|// differs from the summary
comment|// in that the summary is consed up by us, the object_desc_string is builtin.
name|llvm
operator|::
name|Optional
operator|<
name|std
operator|::
name|pair
operator|<
name|TypeValidatorResult
operator|,
name|std
operator|::
name|string
operator|>>
name|m_validation_result
expr_stmt|;
name|CompilerType
name|m_override_type
decl_stmt|;
comment|// If the type of the value object should be
comment|// overridden, the type to impose.
name|ValueObjectManager
modifier|*
name|m_manager
decl_stmt|;
comment|// This object is managed by the root object
comment|// (any ValueObject that gets created
comment|// without a parent.)  The manager gets passed through all the generations of
comment|// dependent objects, and will keep the whole cluster of objects alive as long
comment|// as a shared pointer to any of them has been handed out.  Shared pointers to
comment|// value objects must always be made with the GetSP method.
name|ChildrenManager
name|m_children
decl_stmt|;
name|std
operator|::
name|map
operator|<
name|ConstString
operator|,
name|ValueObject
operator|*
operator|>
name|m_synthetic_children
expr_stmt|;
name|ValueObject
modifier|*
name|m_dynamic_value
decl_stmt|;
name|ValueObject
modifier|*
name|m_synthetic_value
decl_stmt|;
name|ValueObject
modifier|*
name|m_deref_valobj
decl_stmt|;
name|lldb
operator|::
name|ValueObjectSP
name|m_addr_of_valobj_sp
expr_stmt|;
comment|// We have to hold onto a shared
comment|// pointer to this one because it is
comment|// created
comment|// as an independent ValueObjectConstResult, which isn't managed by us.
name|lldb
operator|::
name|Format
name|m_format
expr_stmt|;
name|lldb
operator|::
name|Format
name|m_last_format
expr_stmt|;
name|uint32_t
name|m_last_format_mgr_revision
decl_stmt|;
name|lldb
operator|::
name|TypeSummaryImplSP
name|m_type_summary_sp
expr_stmt|;
name|lldb
operator|::
name|TypeFormatImplSP
name|m_type_format_sp
expr_stmt|;
name|lldb
operator|::
name|SyntheticChildrenSP
name|m_synthetic_children_sp
expr_stmt|;
name|lldb
operator|::
name|TypeValidatorImplSP
name|m_type_validator_sp
expr_stmt|;
name|ProcessModID
name|m_user_id_of_forced_summary
decl_stmt|;
name|AddressType
name|m_address_type_of_ptr_or_ref_children
decl_stmt|;
name|llvm
operator|::
name|SmallVector
operator|<
name|uint8_t
operator|,
literal|16
operator|>
name|m_value_checksum
expr_stmt|;
name|lldb
operator|::
name|LanguageType
name|m_preferred_display_language
expr_stmt|;
name|uint64_t
name|m_language_flags
decl_stmt|;
name|bool
name|m_value_is_valid
range|:
literal|1
decl_stmt|,
name|m_value_did_change
range|:
literal|1
decl_stmt|,
name|m_children_count_valid
range|:
literal|1
decl_stmt|,
name|m_old_value_valid
range|:
literal|1
decl_stmt|,
name|m_is_deref_of_parent
range|:
literal|1
decl_stmt|,
name|m_is_array_item_for_pointer
range|:
literal|1
decl_stmt|,
name|m_is_bitfield_for_scalar
range|:
literal|1
decl_stmt|,
name|m_is_child_at_offset
range|:
literal|1
decl_stmt|,
name|m_is_getting_summary
range|:
literal|1
decl_stmt|,
name|m_did_calculate_complete_objc_class_type
range|:
literal|1
decl_stmt|,
name|m_is_synthetic_children_generated
range|:
literal|1
decl_stmt|;
name|friend
name|class
name|ValueObjectChild
decl_stmt|;
name|friend
name|class
name|ClangExpressionDeclMap
decl_stmt|;
comment|// For GetValue
name|friend
name|class
name|ExpressionVariable
decl_stmt|;
comment|// For SetName
name|friend
name|class
name|Target
decl_stmt|;
comment|// For SetName
name|friend
name|class
name|ValueObjectConstResultImpl
decl_stmt|;
name|friend
name|class
name|ValueObjectSynthetic
decl_stmt|;
comment|// For ClearUserVisibleData
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
comment|// Use the no-argument constructor to make a constant variable object (with no
comment|// ExecutionContextScope.)
name|ValueObject
argument_list|()
expr_stmt|;
comment|// Use this constructor to create a "root variable object".  The ValueObject
comment|// will be locked to this context
comment|// through-out its lifespan.
name|ValueObject
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|AddressType child_ptr_or_ref_addr_type = eAddressTypeLoad
argument_list|)
empty_stmt|;
comment|// Use this constructor to create a ValueObject owned by another ValueObject.
comment|// It will inherit the ExecutionContext
comment|// of its parent.
name|ValueObject
argument_list|(
name|ValueObject
operator|&
name|parent
argument_list|)
expr_stmt|;
name|ValueObjectManager
modifier|*
name|GetManager
parameter_list|()
block|{
return|return
name|m_manager
return|;
block|}
name|virtual
name|bool
name|UpdateValue
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|LazyBool
name|CanUpdateWithInvalidExecutionContext
parameter_list|()
block|{
return|return
name|eLazyBoolCalculate
return|;
block|}
name|virtual
name|void
name|CalculateDynamicValue
argument_list|(
name|lldb
operator|::
name|DynamicValueType
name|use_dynamic
argument_list|)
decl_stmt|;
name|virtual
name|lldb
operator|::
name|DynamicValueType
name|GetDynamicValueTypeImpl
argument_list|()
block|{
return|return
name|lldb
operator|::
name|eNoDynamicValues
return|;
block|}
name|virtual
name|bool
name|HasDynamicValueTypeInfo
parameter_list|()
block|{
return|return
name|false
return|;
block|}
name|virtual
name|void
name|CalculateSyntheticValue
parameter_list|(
name|bool
name|use_synthetic
init|=
name|true
parameter_list|)
function_decl|;
comment|// Should only be called by ValueObject::GetChildAtIndex()
comment|// Returns a ValueObject managed by this ValueObject's manager.
name|virtual
name|ValueObject
modifier|*
name|CreateChildAtIndex
parameter_list|(
name|size_t
name|idx
parameter_list|,
name|bool
name|synthetic_array_member
parameter_list|,
name|int32_t
name|synthetic_index
parameter_list|)
function_decl|;
comment|// Should only be called by ValueObject::GetNumChildren()
name|virtual
name|size_t
name|CalculateNumChildren
parameter_list|(
name|uint32_t
name|max
init|=
name|UINT32_MAX
parameter_list|)
init|=
literal|0
function_decl|;
name|void
name|SetNumChildren
parameter_list|(
name|size_t
name|num_children
parameter_list|)
function_decl|;
name|void
name|SetValueDidChange
parameter_list|(
name|bool
name|value_changed
parameter_list|)
function_decl|;
name|void
name|SetValueIsValid
parameter_list|(
name|bool
name|valid
parameter_list|)
function_decl|;
name|void
name|ClearUserVisibleData
parameter_list|(
name|uint32_t
name|items
init|=
name|ValueObject
operator|::
name|eClearUserVisibleDataItemsAllStrings
parameter_list|)
function_decl|;
name|void
name|AddSyntheticChild
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|key
parameter_list|,
name|ValueObject
modifier|*
name|valobj
parameter_list|)
function_decl|;
name|DataExtractor
modifier|&
name|GetDataExtractor
parameter_list|()
function_decl|;
name|void
name|ClearDynamicTypeInformation
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|// Subclasses must implement the functions below.
comment|//------------------------------------------------------------------
name|virtual
name|CompilerType
name|GetCompilerTypeImpl
parameter_list|()
init|=
literal|0
function_decl|;
specifier|const
name|char
modifier|*
name|GetLocationAsCStringImpl
parameter_list|(
specifier|const
name|Value
modifier|&
name|value
parameter_list|,
specifier|const
name|DataExtractor
modifier|&
name|data
parameter_list|)
function_decl|;
name|bool
name|IsChecksumEmpty
parameter_list|()
function_decl|;
name|void
name|SetPreferredDisplayLanguageIfNeeded
argument_list|(
name|lldb
operator|::
name|LanguageType
argument_list|)
decl_stmt|;
name|private
label|:
name|virtual
name|CompilerType
name|MaybeCalculateCompleteType
parameter_list|()
function_decl|;
name|lldb
operator|::
name|ValueObjectSP
name|GetValueForExpressionPath_Impl
argument_list|(
argument|llvm::StringRef expression_cstr
argument_list|,
argument|ExpressionPathScanEndReason *reason_to_stop
argument_list|,
argument|ExpressionPathEndResultType *final_value_type
argument_list|,
argument|const GetValueForExpressionPathOptions&options
argument_list|,
argument|ExpressionPathAftermath *final_task_on_target
argument_list|)
expr_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ValueObject
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//------------------------------------------------------------------------------
end_comment

begin_comment
comment|// A value object manager class that is seeded with the static variable value
end_comment

begin_comment
comment|// and it vends the user facing value object. If the type is dynamic it can
end_comment

begin_comment
comment|// vend the dynamic type. If this user type also has a synthetic type associated
end_comment

begin_comment
comment|// with it, it will vend the synthetic type. The class watches the process' stop
end_comment

begin_comment
comment|// ID and will update the user type when needed.
end_comment

begin_comment
comment|//------------------------------------------------------------------------------
end_comment

begin_decl_stmt
name|class
name|ValueObjectManager
block|{
comment|// The root value object is the static typed variable object.
name|lldb
operator|::
name|ValueObjectSP
name|m_root_valobj_sp
expr_stmt|;
comment|// The user value object is the value object the user wants to see.
name|lldb
operator|::
name|ValueObjectSP
name|m_user_valobj_sp
expr_stmt|;
name|lldb
operator|::
name|DynamicValueType
name|m_use_dynamic
expr_stmt|;
name|uint32_t
name|m_stop_id
decl_stmt|;
comment|// The stop ID that m_user_valobj_sp is valid for.
name|bool
name|m_use_synthetic
decl_stmt|;
name|public
label|:
name|ValueObjectManager
argument_list|()
block|{}
name|ValueObjectManager
argument_list|(
argument|lldb::ValueObjectSP in_valobj_sp
argument_list|,
argument|lldb::DynamicValueType use_dynamic
argument_list|,
argument|bool use_synthetic
argument_list|)
empty_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|ValueObjectSP
name|GetRootSP
argument_list|()
specifier|const
block|{
return|return
name|m_root_valobj_sp
return|;
block|}
comment|// Gets the correct value object from the root object for a given process
comment|// stop ID. If dynamic values are enabled, or if synthetic children are
comment|// enabled, the value object that the user wants to see might change while
comment|// debugging.
name|lldb
operator|::
name|ValueObjectSP
name|GetSP
argument_list|()
expr_stmt|;
name|void
name|SetUseDynamic
argument_list|(
name|lldb
operator|::
name|DynamicValueType
name|use_dynamic
argument_list|)
decl_stmt|;
name|void
name|SetUseSynthetic
parameter_list|(
name|bool
name|use_synthetic
parameter_list|)
function_decl|;
name|lldb
operator|::
name|DynamicValueType
name|GetUseDynamic
argument_list|()
specifier|const
block|{
return|return
name|m_use_dynamic
return|;
block|}
name|bool
name|GetUseSynthetic
argument_list|()
specifier|const
block|{
return|return
name|m_use_synthetic
return|;
block|}
name|lldb
operator|::
name|TargetSP
name|GetTargetSP
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|ProcessSP
name|GetProcessSP
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|ThreadSP
name|GetThreadSP
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|StackFrameSP
name|GetFrameSP
argument_list|()
specifier|const
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ValueObject_h_
end_comment

end_unit

