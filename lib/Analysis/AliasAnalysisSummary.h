begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=====- CFLSummary.h - Abstract stratified sets implementation. --------=====//
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
comment|/// \file
end_comment

begin_comment
comment|/// This file defines various utility types and functions useful to
end_comment

begin_comment
comment|/// summary-based alias analysis.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Summary-based analysis, also known as bottom-up analysis, is a style of
end_comment

begin_comment
comment|/// interprocedrual static analysis that tries to analyze the callees before the
end_comment

begin_comment
comment|/// callers get analyzed. The key idea of summary-based analysis is to first
end_comment

begin_comment
comment|/// process each function indepedently, outline its behavior in a condensed
end_comment

begin_comment
comment|/// summary, and then instantiate the summary at the callsite when the said
end_comment

begin_comment
comment|/// function is called elsewhere. This is often in contrast to another style
end_comment

begin_comment
comment|/// called top-down analysis, in which callers are always analyzed first before
end_comment

begin_comment
comment|/// the callees.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// In a summary-based analysis, functions must be examined independently and
end_comment

begin_comment
comment|/// out-of-context. We have no information on the state of the memory, the
end_comment

begin_comment
comment|/// arguments, the global values, and anything else external to the function. To
end_comment

begin_comment
comment|/// carry out the analysis conservative assumptions have to be made about those
end_comment

begin_comment
comment|/// external states. In exchange for the potential loss of precision, the
end_comment

begin_comment
comment|/// summary we obtain this way is highly reusable, which makes the analysis
end_comment

begin_comment
comment|/// easier to scale to large programs even if carried out context-sensitively.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Currently, all CFL-based alias analyses adopt the summary-based approach
end_comment

begin_comment
comment|/// and therefore heavily rely on this header.
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
name|LLVM_ANALYSIS_ALIASANALYSISSUMMARY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_ALIASANALYSISSUMMARY_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMapInfo.h"
end_include

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
file|"llvm/IR/CallSite.h"
end_include

begin_include
include|#
directive|include
file|<bitset>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|cflaa
block|{
comment|//===----------------------------------------------------------------------===//
comment|// AliasAttr related stuffs
comment|//===----------------------------------------------------------------------===//
comment|/// The number of attributes that AliasAttr should contain. Attributes are
comment|/// described below, and 32 was an arbitrary choice because it fits nicely in 32
comment|/// bits (because we use a bitset for AliasAttr).
specifier|static
specifier|const
name|unsigned
name|NumAliasAttrs
init|=
literal|32
decl_stmt|;
comment|/// These are attributes that an alias analysis can use to mark certain special
comment|/// properties of a given pointer. Refer to the related functions below to see
comment|/// what kinds of attributes are currently defined.
typedef|typedef
name|std
operator|::
name|bitset
operator|<
name|NumAliasAttrs
operator|>
name|AliasAttrs
expr_stmt|;
comment|/// Attr represent whether the said pointer comes from an unknown source
comment|/// (such as opaque memory or an integer cast).
name|AliasAttrs
name|getAttrNone
parameter_list|()
function_decl|;
comment|/// AttrUnknown represent whether the said pointer comes from a source not known
comment|/// to alias analyses (such as opaque memory or an integer cast).
name|AliasAttrs
name|getAttrUnknown
parameter_list|()
function_decl|;
name|bool
name|hasUnknownAttr
parameter_list|(
name|AliasAttrs
parameter_list|)
function_decl|;
comment|/// AttrCaller represent whether the said pointer comes from a source not known
comment|/// to the current function but known to the caller. Values pointed to by the
comment|/// arguments of the current function have this attribute set
name|AliasAttrs
name|getAttrCaller
parameter_list|()
function_decl|;
name|bool
name|hasCallerAttr
parameter_list|(
name|AliasAttrs
parameter_list|)
function_decl|;
name|bool
name|hasUnknownOrCallerAttr
parameter_list|(
name|AliasAttrs
parameter_list|)
function_decl|;
comment|/// AttrEscaped represent whether the said pointer comes from a known source but
comment|/// escapes to the unknown world (e.g. casted to an integer, or passed as an
comment|/// argument to opaque function). Unlike non-escaped pointers, escaped ones may
comment|/// alias pointers coming from unknown sources.
name|AliasAttrs
name|getAttrEscaped
parameter_list|()
function_decl|;
name|bool
name|hasEscapedAttr
parameter_list|(
name|AliasAttrs
parameter_list|)
function_decl|;
comment|/// AttrGlobal represent whether the said pointer is a global value.
comment|/// AttrArg represent whether the said pointer is an argument, and if so, what
comment|/// index the argument has.
name|AliasAttrs
name|getGlobalOrArgAttrFromValue
parameter_list|(
specifier|const
name|Value
modifier|&
parameter_list|)
function_decl|;
name|bool
name|isGlobalOrArgAttr
parameter_list|(
name|AliasAttrs
parameter_list|)
function_decl|;
comment|/// Given an AliasAttrs, return a new AliasAttrs that only contains attributes
comment|/// meaningful to the caller. This function is primarily used for
comment|/// interprocedural analysis
comment|/// Currently, externally visible AliasAttrs include AttrUnknown, AttrGlobal,
comment|/// and AttrEscaped
name|AliasAttrs
name|getExternallyVisibleAttrs
parameter_list|(
name|AliasAttrs
parameter_list|)
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|// Function summary related stuffs
comment|//===----------------------------------------------------------------------===//
comment|/// The maximum number of arguments we can put into a summary.
specifier|static
specifier|const
name|unsigned
name|MaxSupportedArgsInSummary
init|=
literal|50
decl_stmt|;
comment|/// We use InterfaceValue to describe parameters/return value, as well as
comment|/// potential memory locations that are pointed to by parameters/return value,
comment|/// of a function.
comment|/// Index is an integer which represents a single parameter or a return value.
comment|/// When the index is 0, it refers to the return value. Non-zero index i refers
comment|/// to the i-th parameter.
comment|/// DerefLevel indicates the number of dereferences one must perform on the
comment|/// parameter/return value to get this InterfaceValue.
struct|struct
name|InterfaceValue
block|{
name|unsigned
name|Index
decl_stmt|;
name|unsigned
name|DerefLevel
decl_stmt|;
block|}
struct|;
specifier|inline
name|bool
name|operator
operator|==
operator|(
name|InterfaceValue
name|LHS
operator|,
name|InterfaceValue
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|Index
operator|==
name|RHS
operator|.
name|Index
operator|&&
name|LHS
operator|.
name|DerefLevel
operator|==
name|RHS
operator|.
name|DerefLevel
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
name|InterfaceValue
name|LHS
operator|,
name|InterfaceValue
name|RHS
operator|)
block|{
return|return
operator|!
operator|(
name|LHS
operator|==
name|RHS
operator|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|<
operator|(
name|InterfaceValue
name|LHS
operator|,
name|InterfaceValue
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|Index
operator|<
name|RHS
operator|.
name|Index
operator|||
operator|(
name|LHS
operator|.
name|Index
operator|==
name|RHS
operator|.
name|Index
operator|&&
name|LHS
operator|.
name|DerefLevel
operator|<
name|RHS
operator|.
name|DerefLevel
operator|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|>
operator|(
name|InterfaceValue
name|LHS
operator|,
name|InterfaceValue
name|RHS
operator|)
block|{
return|return
name|RHS
operator|<
name|LHS
return|;
block|}
specifier|inline
name|bool
name|operator
operator|<=
operator|(
name|InterfaceValue
name|LHS
operator|,
name|InterfaceValue
name|RHS
operator|)
block|{
return|return
operator|!
operator|(
name|RHS
operator|<
name|LHS
operator|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|>=
operator|(
name|InterfaceValue
name|LHS
operator|,
name|InterfaceValue
name|RHS
operator|)
block|{
return|return
operator|!
operator|(
name|LHS
operator|<
name|RHS
operator|)
return|;
block|}
comment|// We use UnknownOffset to represent pointer offsets that cannot be determined
comment|// at compile time. Note that MemoryLocation::UnknownSize cannot be used here
comment|// because we require a signed value.
specifier|static
specifier|const
name|int64_t
name|UnknownOffset
init|=
name|INT64_MAX
decl_stmt|;
specifier|inline
name|int64_t
name|addOffset
parameter_list|(
name|int64_t
name|LHS
parameter_list|,
name|int64_t
name|RHS
parameter_list|)
block|{
if|if
condition|(
name|LHS
operator|==
name|UnknownOffset
operator|||
name|RHS
operator|==
name|UnknownOffset
condition|)
return|return
name|UnknownOffset
return|;
comment|// FIXME: Do we need to guard against integer overflow here?
return|return
name|LHS
operator|+
name|RHS
return|;
block|}
comment|/// We use ExternalRelation to describe an externally visible aliasing relations
comment|/// between parameters/return value of a function.
struct|struct
name|ExternalRelation
block|{
name|InterfaceValue
name|From
decl_stmt|,
name|To
decl_stmt|;
name|int64_t
name|Offset
decl_stmt|;
block|}
struct|;
specifier|inline
name|bool
name|operator
operator|==
operator|(
name|ExternalRelation
name|LHS
operator|,
name|ExternalRelation
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|From
operator|==
name|RHS
operator|.
name|From
operator|&&
name|LHS
operator|.
name|To
operator|==
name|RHS
operator|.
name|To
operator|&&
name|LHS
operator|.
name|Offset
operator|==
name|RHS
operator|.
name|Offset
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
name|ExternalRelation
name|LHS
operator|,
name|ExternalRelation
name|RHS
operator|)
block|{
return|return
operator|!
operator|(
name|LHS
operator|==
name|RHS
operator|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|<
operator|(
name|ExternalRelation
name|LHS
operator|,
name|ExternalRelation
name|RHS
operator|)
block|{
if|if
condition|(
name|LHS
operator|.
name|From
operator|<
name|RHS
operator|.
name|From
condition|)
return|return
name|true
return|;
if|if
condition|(
name|LHS
operator|.
name|From
operator|>
name|RHS
operator|.
name|From
condition|)
return|return
name|false
return|;
if|if
condition|(
name|LHS
operator|.
name|To
operator|<
name|RHS
operator|.
name|To
condition|)
return|return
name|true
return|;
if|if
condition|(
name|LHS
operator|.
name|To
operator|>
name|RHS
operator|.
name|To
condition|)
return|return
name|false
return|;
return|return
name|LHS
operator|.
name|Offset
operator|<
name|RHS
operator|.
name|Offset
return|;
block|}
specifier|inline
name|bool
name|operator
operator|>
operator|(
name|ExternalRelation
name|LHS
operator|,
name|ExternalRelation
name|RHS
operator|)
block|{
return|return
name|RHS
operator|<
name|LHS
return|;
block|}
specifier|inline
name|bool
name|operator
operator|<=
operator|(
name|ExternalRelation
name|LHS
operator|,
name|ExternalRelation
name|RHS
operator|)
block|{
return|return
operator|!
operator|(
name|RHS
operator|<
name|LHS
operator|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|>=
operator|(
name|ExternalRelation
name|LHS
operator|,
name|ExternalRelation
name|RHS
operator|)
block|{
return|return
operator|!
operator|(
name|LHS
operator|<
name|RHS
operator|)
return|;
block|}
comment|/// We use ExternalAttribute to describe an externally visible AliasAttrs
comment|/// for parameters/return value.
struct|struct
name|ExternalAttribute
block|{
name|InterfaceValue
name|IValue
decl_stmt|;
name|AliasAttrs
name|Attr
decl_stmt|;
block|}
struct|;
comment|/// AliasSummary is just a collection of ExternalRelation and ExternalAttribute
struct|struct
name|AliasSummary
block|{
comment|// RetParamRelations is a collection of ExternalRelations.
name|SmallVector
operator|<
name|ExternalRelation
operator|,
literal|8
operator|>
name|RetParamRelations
expr_stmt|;
comment|// RetParamAttributes is a collection of ExternalAttributes.
name|SmallVector
operator|<
name|ExternalAttribute
operator|,
literal|8
operator|>
name|RetParamAttributes
expr_stmt|;
block|}
struct|;
comment|/// This is the result of instantiating InterfaceValue at a particular callsite
struct|struct
name|InstantiatedValue
block|{
name|Value
modifier|*
name|Val
decl_stmt|;
name|unsigned
name|DerefLevel
decl_stmt|;
block|}
struct|;
name|Optional
operator|<
name|InstantiatedValue
operator|>
name|instantiateInterfaceValue
argument_list|(
name|InterfaceValue
argument_list|,
name|CallSite
argument_list|)
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|==
operator|(
name|InstantiatedValue
name|LHS
operator|,
name|InstantiatedValue
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|Val
operator|==
name|RHS
operator|.
name|Val
operator|&&
name|LHS
operator|.
name|DerefLevel
operator|==
name|RHS
operator|.
name|DerefLevel
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
name|InstantiatedValue
name|LHS
operator|,
name|InstantiatedValue
name|RHS
operator|)
block|{
return|return
operator|!
operator|(
name|LHS
operator|==
name|RHS
operator|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|<
operator|(
name|InstantiatedValue
name|LHS
operator|,
name|InstantiatedValue
name|RHS
operator|)
block|{
return|return
name|std
operator|::
name|less
operator|<
name|Value
operator|*
operator|>
operator|(
operator|)
operator|(
name|LHS
operator|.
name|Val
operator|,
name|RHS
operator|.
name|Val
operator|)
operator|||
operator|(
name|LHS
operator|.
name|Val
operator|==
name|RHS
operator|.
name|Val
operator|&&
name|LHS
operator|.
name|DerefLevel
operator|<
name|RHS
operator|.
name|DerefLevel
operator|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|>
operator|(
name|InstantiatedValue
name|LHS
operator|,
name|InstantiatedValue
name|RHS
operator|)
block|{
return|return
name|RHS
operator|<
name|LHS
return|;
block|}
specifier|inline
name|bool
name|operator
operator|<=
operator|(
name|InstantiatedValue
name|LHS
operator|,
name|InstantiatedValue
name|RHS
operator|)
block|{
return|return
operator|!
operator|(
name|RHS
operator|<
name|LHS
operator|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|>=
operator|(
name|InstantiatedValue
name|LHS
operator|,
name|InstantiatedValue
name|RHS
operator|)
block|{
return|return
operator|!
operator|(
name|LHS
operator|<
name|RHS
operator|)
return|;
block|}
comment|/// This is the result of instantiating ExternalRelation at a particular
comment|/// callsite
struct|struct
name|InstantiatedRelation
block|{
name|InstantiatedValue
name|From
decl_stmt|,
name|To
decl_stmt|;
name|int64_t
name|Offset
decl_stmt|;
block|}
struct|;
name|Optional
operator|<
name|InstantiatedRelation
operator|>
name|instantiateExternalRelation
argument_list|(
name|ExternalRelation
argument_list|,
name|CallSite
argument_list|)
expr_stmt|;
comment|/// This is the result of instantiating ExternalAttribute at a particular
comment|/// callsite
struct|struct
name|InstantiatedAttr
block|{
name|InstantiatedValue
name|IValue
decl_stmt|;
name|AliasAttrs
name|Attr
decl_stmt|;
block|}
struct|;
name|Optional
operator|<
name|InstantiatedAttr
operator|>
name|instantiateExternalAttribute
argument_list|(
name|ExternalAttribute
argument_list|,
name|CallSite
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|cflaa
operator|::
name|InstantiatedValue
operator|>
block|{
specifier|static
specifier|inline
name|cflaa
operator|::
name|InstantiatedValue
name|getEmptyKey
argument_list|()
block|{
return|return
name|cflaa
operator|::
name|InstantiatedValue
block|{
name|DenseMapInfo
operator|<
name|Value
operator|*
operator|>
operator|::
name|getEmptyKey
argument_list|()
block|,
name|DenseMapInfo
operator|<
name|unsigned
operator|>
operator|::
name|getEmptyKey
argument_list|()
block|}
return|;
block|}
specifier|static
specifier|inline
name|cflaa
operator|::
name|InstantiatedValue
name|getTombstoneKey
argument_list|()
block|{
return|return
name|cflaa
operator|::
name|InstantiatedValue
block|{
name|DenseMapInfo
operator|<
name|Value
operator|*
operator|>
operator|::
name|getTombstoneKey
argument_list|()
block|,
name|DenseMapInfo
operator|<
name|unsigned
operator|>
operator|::
name|getTombstoneKey
argument_list|()
block|}
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|static
name|unsigned
name|getHashValue
argument_list|(
specifier|const
name|cflaa
operator|::
name|InstantiatedValue
operator|&
name|IV
argument_list|)
block|{
return|return
name|DenseMapInfo
operator|<
name|std
operator|::
name|pair
operator|<
name|Value
operator|*
operator|,
name|unsigned
operator|>>
operator|::
name|getHashValue
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|IV
operator|.
name|Val
argument_list|,
name|IV
operator|.
name|DerefLevel
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|bool
name|isEqual
argument_list|(
specifier|const
name|cflaa
operator|::
name|InstantiatedValue
operator|&
name|LHS
argument_list|,
specifier|const
name|cflaa
operator|::
name|InstantiatedValue
operator|&
name|RHS
argument_list|)
block|{
return|return
name|LHS
operator|.
name|Val
operator|==
name|RHS
operator|.
name|Val
operator|&&
name|LHS
operator|.
name|DerefLevel
operator|==
name|RHS
operator|.
name|DerefLevel
return|;
block|}
end_decl_stmt

begin_endif
unit|}; }
endif|#
directive|endif
end_endif

end_unit

