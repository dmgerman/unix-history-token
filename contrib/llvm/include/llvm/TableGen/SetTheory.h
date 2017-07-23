begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SetTheory.h - Generate ordered sets from DAG expressions -*- C++ -*-===//
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
comment|// This file implements the SetTheory class that computes ordered sets of
end_comment

begin_comment
comment|// Records from DAG expressions.  Operators for standard set operations are
end_comment

begin_comment
comment|// predefined, and it is possible to add special purpose set operators as well.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The user may define named sets as Records of predefined classes. Set
end_comment

begin_comment
comment|// expanders can be added to a SetTheory instance to teach it how to find the
end_comment

begin_comment
comment|// elements of such a named set.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// These are the predefined operators. The argument lists can be individual
end_comment

begin_comment
comment|// elements (defs), other sets (defs of expandable classes), lists, or DAG
end_comment

begin_comment
comment|// expressions that are evaluated recursively.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// - (add S1, S2 ...) Union sets. This is also how sets are created from element
end_comment

begin_comment
comment|//   lists.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// - (sub S1, S2, ...) Set difference. Every element in S1 except for the
end_comment

begin_comment
comment|//   elements in S2, ...
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// - (and S1, S2) Set intersection. Every element in S1 that is also in S2.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// - (shl S, N) Shift left. Remove the first N elements from S.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// - (trunc S, N) Truncate. The first N elements of S.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// - (rotl S, N) Rotate left. Same as (add (shl S, N), (trunc S, N)).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// - (rotr S, N) Rotate right.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// - (decimate S, N) Decimate S by picking every N'th element, starting with
end_comment

begin_comment
comment|//   the first one. For instance, (decimate S, 2) returns the even elements of
end_comment

begin_comment
comment|//   S.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// - (sequence "Format", From, To) Generate a sequence of defs with printf.
end_comment

begin_comment
comment|//   For instance, (sequence "R%u", 0, 3) -> [ R0, R1, R2, R3 ]
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
name|LLVM_TABLEGEN_SETTHEORY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TABLEGEN_SETTHEORY_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SetVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/SMLoc.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DagInit
decl_stmt|;
name|class
name|Init
decl_stmt|;
name|class
name|Record
decl_stmt|;
name|class
name|SetTheory
block|{
name|public
label|:
name|using
name|RecVec
init|=
name|std
operator|::
name|vector
operator|<
name|Record
operator|*
operator|>
decl_stmt|;
name|using
name|RecSet
init|=
name|SmallSetVector
operator|<
name|Record
operator|*
decl_stmt|, 16>;
comment|/// Operator - A callback representing a DAG operator.
name|class
name|Operator
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|public
label|:
name|virtual
operator|~
name|Operator
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// apply - Apply this operator to Expr's arguments and insert the result
comment|/// in Elts.
name|virtual
name|void
name|apply
argument_list|(
name|SetTheory
operator|&
argument_list|,
name|DagInit
operator|*
name|Expr
argument_list|,
name|RecSet
operator|&
name|Elts
argument_list|,
name|ArrayRef
operator|<
name|SMLoc
operator|>
name|Loc
argument_list|)
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
comment|/// Expander - A callback function that can transform a Record representing a
comment|/// set into a fully expanded list of elements. Expanders provide a way for
comment|/// users to define named sets that can be used in DAG expressions.
name|class
name|Expander
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|public
label|:
name|virtual
operator|~
name|Expander
argument_list|()
operator|=
expr|default
expr_stmt|;
name|virtual
name|void
name|expand
parameter_list|(
name|SetTheory
modifier|&
parameter_list|,
name|Record
modifier|*
parameter_list|,
name|RecSet
modifier|&
name|Elts
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
name|private
label|:
comment|// Map set defs to their fully expanded contents. This serves as a memoization
comment|// cache and it makes it possible to return const references on queries.
name|using
name|ExpandMap
init|=
name|std
operator|::
name|map
operator|<
name|Record
operator|*
decl_stmt|,
name|RecVec
decl|>
decl_stmt|;
name|ExpandMap
name|Expansions
decl_stmt|;
comment|// Known DAG operators by name.
name|StringMap
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Operator
operator|>>
name|Operators
expr_stmt|;
comment|// Typed expanders by class name.
name|StringMap
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Expander
operator|>>
name|Expanders
expr_stmt|;
name|public
label|:
comment|/// Create a SetTheory instance with only the standard operators.
name|SetTheory
argument_list|()
expr_stmt|;
comment|/// addExpander - Add an expander for Records with the named super class.
name|void
name|addExpander
argument_list|(
name|StringRef
name|ClassName
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|Expander
operator|>
argument_list|)
decl_stmt|;
comment|/// addFieldExpander - Add an expander for ClassName that simply evaluates
comment|/// FieldName in the Record to get the set elements.  That is all that is
comment|/// needed for a class like:
comment|///
comment|///   class Set<dag d> {
comment|///     dag Elts = d;
comment|///   }
comment|///
name|void
name|addFieldExpander
parameter_list|(
name|StringRef
name|ClassName
parameter_list|,
name|StringRef
name|FieldName
parameter_list|)
function_decl|;
comment|/// addOperator - Add a DAG operator.
name|void
name|addOperator
argument_list|(
name|StringRef
name|Name
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|Operator
operator|>
argument_list|)
decl_stmt|;
comment|/// evaluate - Evaluate Expr and append the resulting set to Elts.
name|void
name|evaluate
argument_list|(
name|Init
operator|*
name|Expr
argument_list|,
name|RecSet
operator|&
name|Elts
argument_list|,
name|ArrayRef
operator|<
name|SMLoc
operator|>
name|Loc
argument_list|)
decl_stmt|;
comment|/// evaluate - Evaluate a sequence of Inits and append to Elts.
name|template
operator|<
name|typename
name|Iter
operator|>
name|void
name|evaluate
argument_list|(
argument|Iter begin
argument_list|,
argument|Iter end
argument_list|,
argument|RecSet&Elts
argument_list|,
argument|ArrayRef<SMLoc> Loc
argument_list|)
block|{
while|while
condition|(
name|begin
operator|!=
name|end
condition|)
name|evaluate
argument_list|(
operator|*
name|begin
operator|++
argument_list|,
name|Elts
argument_list|,
name|Loc
argument_list|)
expr_stmt|;
block|}
comment|/// expand - Expand a record into a set of elements if possible.  Return a
comment|/// pointer to the expanded elements, or NULL if Set cannot be expanded
comment|/// further.
specifier|const
name|RecVec
modifier|*
name|expand
parameter_list|(
name|Record
modifier|*
name|Set
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TABLEGEN_SETTHEORY_H
end_comment

end_unit

