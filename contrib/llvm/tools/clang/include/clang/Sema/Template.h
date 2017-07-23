begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------- SemaTemplate.h - C++ Templates ---------------------*- C++ -*-===/
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
comment|//===----------------------------------------------------------------------===/
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file provides types used in the semantic analysis of C++ templates.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_SEMA_TEMPLATE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_TEMPLATE_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/DeclTemplate.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclVisitor.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/Sema.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief Data structure that captures multiple levels of template argument
comment|/// lists for use in template instantiation.
comment|///
comment|/// Multiple levels of template arguments occur when instantiating the
comment|/// definitions of member templates. For example:
comment|///
comment|/// \code
comment|/// template<typename T>
comment|/// struct X {
comment|///   template<T Value>
comment|///   struct Y {
comment|///     void f();
comment|///   };
comment|/// };
comment|/// \endcode
comment|///
comment|/// When instantiating X<int>::Y<17>::f, the multi-level template argument
comment|/// list will contain a template argument list (int) at depth 0 and a
comment|/// template argument list (17) at depth 1.
name|class
name|MultiLevelTemplateArgumentList
block|{
comment|/// \brief The template argument list at a certain template depth
typedef|typedef
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|ArgList
expr_stmt|;
comment|/// \brief The template argument lists, stored from the innermost template
comment|/// argument list (first) to the outermost template argument list (last).
name|SmallVector
operator|<
name|ArgList
operator|,
literal|4
operator|>
name|TemplateArgumentLists
expr_stmt|;
comment|/// \brief The number of outer levels of template arguments that are not
comment|/// being substituted.
name|unsigned
name|NumRetainedOuterLevels
init|=
literal|0
decl_stmt|;
name|public
label|:
comment|/// \brief Construct an empty set of template argument lists.
name|MultiLevelTemplateArgumentList
argument_list|()
block|{ }
comment|/// \brief Construct a single-level template argument list.
name|explicit
name|MultiLevelTemplateArgumentList
parameter_list|(
specifier|const
name|TemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|)
block|{
name|addOuterTemplateArguments
argument_list|(
operator|&
name|TemplateArgs
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Determine the number of levels in this template argument
comment|/// list.
name|unsigned
name|getNumLevels
argument_list|()
specifier|const
block|{
return|return
name|TemplateArgumentLists
operator|.
name|size
argument_list|()
operator|+
name|NumRetainedOuterLevels
return|;
block|}
comment|/// \brief Determine the number of substituted levels in this template
comment|/// argument list.
name|unsigned
name|getNumSubstitutedLevels
argument_list|()
specifier|const
block|{
return|return
name|TemplateArgumentLists
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the template argument at a given depth and index.
specifier|const
name|TemplateArgument
operator|&
name|operator
argument_list|()
operator|(
name|unsigned
name|Depth
operator|,
name|unsigned
name|Index
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|NumRetainedOuterLevels
operator|<=
name|Depth
operator|&&
name|Depth
operator|<
name|getNumLevels
argument_list|()
argument_list|)
block|;
name|assert
argument_list|(
name|Index
operator|<
name|TemplateArgumentLists
index|[
name|getNumLevels
argument_list|()
operator|-
name|Depth
operator|-
literal|1
index|]
operator|.
name|size
argument_list|()
argument_list|)
block|;
return|return
name|TemplateArgumentLists
index|[
name|getNumLevels
argument_list|()
operator|-
name|Depth
operator|-
literal|1
index|]
index|[
name|Index
index|]
return|;
block|}
comment|/// \brief Determine whether there is a non-NULL template argument at the
comment|/// given depth and index.
comment|///
comment|/// There must exist a template argument list at the given depth.
name|bool
name|hasTemplateArgument
argument_list|(
name|unsigned
name|Depth
argument_list|,
name|unsigned
name|Index
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Depth
operator|<
name|getNumLevels
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|Depth
operator|<
name|NumRetainedOuterLevels
condition|)
return|return
name|false
return|;
if|if
condition|(
name|Index
operator|>=
name|TemplateArgumentLists
index|[
name|getNumLevels
argument_list|()
operator|-
name|Depth
operator|-
literal|1
index|]
operator|.
name|size
argument_list|()
condition|)
return|return
name|false
return|;
return|return
operator|!
call|(
modifier|*
name|this
call|)
argument_list|(
name|Depth
argument_list|,
name|Index
argument_list|)
operator|.
name|isNull
argument_list|()
return|;
block|}
comment|/// \brief Clear out a specific template argument.
name|void
name|setArgument
parameter_list|(
name|unsigned
name|Depth
parameter_list|,
name|unsigned
name|Index
parameter_list|,
name|TemplateArgument
name|Arg
parameter_list|)
block|{
name|assert
argument_list|(
name|NumRetainedOuterLevels
operator|<=
name|Depth
operator|&&
name|Depth
operator|<
name|getNumLevels
argument_list|()
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|Index
operator|<
name|TemplateArgumentLists
index|[
name|getNumLevels
argument_list|()
operator|-
name|Depth
operator|-
literal|1
index|]
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|const_cast
operator|<
name|TemplateArgument
operator|&
operator|>
operator|(
name|TemplateArgumentLists
index|[
name|getNumLevels
argument_list|()
operator|-
name|Depth
operator|-
literal|1
index|]
index|[
name|Index
index|]
operator|)
operator|=
name|Arg
expr_stmt|;
block|}
comment|/// \brief Add a new outermost level to the multi-level template argument
comment|/// list.
name|void
name|addOuterTemplateArguments
parameter_list|(
specifier|const
name|TemplateArgumentList
modifier|*
name|TemplateArgs
parameter_list|)
block|{
name|addOuterTemplateArguments
argument_list|(
name|ArgList
argument_list|(
name|TemplateArgs
operator|->
name|data
argument_list|()
argument_list|,
name|TemplateArgs
operator|->
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Add a new outmost level to the multi-level template argument
comment|/// list.
name|void
name|addOuterTemplateArguments
parameter_list|(
name|ArgList
name|Args
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|NumRetainedOuterLevels
operator|&&
literal|"substituted args outside retained args?"
argument_list|)
expr_stmt|;
name|TemplateArgumentLists
operator|.
name|push_back
argument_list|(
name|Args
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Add an outermost level that we are not substituting. We have no
comment|/// arguments at this level, and do not remove it from the depth of inner
comment|/// template parameters that we instantiate.
name|void
name|addOuterRetainedLevel
parameter_list|()
block|{
operator|++
name|NumRetainedOuterLevels
expr_stmt|;
block|}
comment|/// \brief Retrieve the innermost template argument list.
specifier|const
name|ArgList
operator|&
name|getInnermost
argument_list|()
specifier|const
block|{
return|return
name|TemplateArgumentLists
operator|.
name|front
argument_list|()
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief The context in which partial ordering of function templates occurs.
enum|enum
name|TPOC
block|{
comment|/// \brief Partial ordering of function templates for a function call.
name|TPOC_Call
block|,
comment|/// \brief Partial ordering of function templates for a call to a
comment|/// conversion function.
name|TPOC_Conversion
block|,
comment|/// \brief Partial ordering of function templates in other contexts, e.g.,
comment|/// taking the address of a function template or matching a function
comment|/// template specialization to a function template.
name|TPOC_Other
block|}
enum|;
comment|// This is lame but unavoidable in a world without forward
comment|// declarations of enums.  The alternatives are to either pollute
comment|// Sema.h (by including this file) or sacrifice type safety (by
comment|// making Sema.h declare things as enums).
name|class
name|TemplatePartialOrderingContext
block|{
name|TPOC
name|Value
decl_stmt|;
name|public
label|:
name|TemplatePartialOrderingContext
argument_list|(
argument|TPOC Value
argument_list|)
block|:
name|Value
argument_list|(
argument|Value
argument_list|)
block|{}
name|operator
name|TPOC
argument_list|()
specifier|const
block|{
return|return
name|Value
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Captures a template argument whose value has been deduced
comment|/// via c++ template argument deduction.
name|class
name|DeducedTemplateArgument
range|:
name|public
name|TemplateArgument
block|{
comment|/// \brief For a non-type template argument, whether the value was
comment|/// deduced from an array bound.
name|bool
name|DeducedFromArrayBound
block|;
name|public
operator|:
name|DeducedTemplateArgument
argument_list|()
operator|:
name|TemplateArgument
argument_list|()
block|,
name|DeducedFromArrayBound
argument_list|(
argument|false
argument_list|)
block|{ }
name|DeducedTemplateArgument
argument_list|(
argument|const TemplateArgument&Arg
argument_list|,
argument|bool DeducedFromArrayBound = false
argument_list|)
operator|:
name|TemplateArgument
argument_list|(
name|Arg
argument_list|)
block|,
name|DeducedFromArrayBound
argument_list|(
argument|DeducedFromArrayBound
argument_list|)
block|{ }
comment|/// \brief Construct an integral non-type template argument that
comment|/// has been deduced, possibly from an array bound.
name|DeducedTemplateArgument
argument_list|(
argument|ASTContext&Ctx
argument_list|,
argument|const llvm::APSInt&Value
argument_list|,
argument|QualType ValueType
argument_list|,
argument|bool DeducedFromArrayBound
argument_list|)
operator|:
name|TemplateArgument
argument_list|(
name|Ctx
argument_list|,
name|Value
argument_list|,
name|ValueType
argument_list|)
block|,
name|DeducedFromArrayBound
argument_list|(
argument|DeducedFromArrayBound
argument_list|)
block|{ }
comment|/// \brief For a non-type template argument, determine whether the
comment|/// template argument was deduced from an array bound.
name|bool
name|wasDeducedFromArrayBound
argument_list|()
specifier|const
block|{
return|return
name|DeducedFromArrayBound
return|;
block|}
comment|/// \brief Specify whether the given non-type template argument
comment|/// was deduced from an array bound.
name|void
name|setDeducedFromArrayBound
argument_list|(
argument|bool Deduced
argument_list|)
block|{
name|DeducedFromArrayBound
operator|=
name|Deduced
block|;     }
expr|}
block|;
comment|/// \brief A stack-allocated class that identifies which local
comment|/// variable declaration instantiations are present in this scope.
comment|///
comment|/// A new instance of this class type will be created whenever we
comment|/// instantiate a new function declaration, which will have its own
comment|/// set of parameter declarations.
name|class
name|LocalInstantiationScope
block|{
name|public
operator|:
comment|/// \brief A set of declarations.
typedef|typedef
name|SmallVector
operator|<
name|ParmVarDecl
operator|*
operator|,
literal|4
operator|>
name|DeclArgumentPack
expr_stmt|;
name|private
operator|:
comment|/// \brief Reference to the semantic analysis that is performing
comment|/// this template instantiation.
name|Sema
operator|&
name|SemaRef
block|;
typedef|typedef
name|llvm
operator|::
name|SmallDenseMap
operator|<
specifier|const
name|Decl
operator|*
operator|,
name|llvm
operator|::
name|PointerUnion
operator|<
name|Decl
operator|*
operator|,
name|DeclArgumentPack
operator|*
operator|>
operator|,
literal|4
operator|>
name|LocalDeclsMap
expr_stmt|;
comment|/// \brief A mapping from local declarations that occur
comment|/// within a template to their instantiations.
comment|///
comment|/// This mapping is used during instantiation to keep track of,
comment|/// e.g., function parameter and variable declarations. For example,
comment|/// given:
comment|///
comment|/// \code
comment|///   template<typename T> T add(T x, T y) { return x + y; }
comment|/// \endcode
comment|///
comment|/// when we instantiate add<int>, we will introduce a mapping from
comment|/// the ParmVarDecl for 'x' that occurs in the template to the
comment|/// instantiated ParmVarDecl for 'x'.
comment|///
comment|/// For a parameter pack, the local instantiation scope may contain a
comment|/// set of instantiated parameters. This is stored as a DeclArgumentPack
comment|/// pointer.
name|LocalDeclsMap
name|LocalDecls
decl_stmt|;
comment|/// \brief The set of argument packs we've allocated.
name|SmallVector
operator|<
name|DeclArgumentPack
operator|*
operator|,
literal|1
operator|>
name|ArgumentPacks
expr_stmt|;
comment|/// \brief The outer scope, which contains local variable
comment|/// definitions from some other instantiation (that may not be
comment|/// relevant to this particular scope).
name|LocalInstantiationScope
modifier|*
name|Outer
decl_stmt|;
comment|/// \brief Whether we have already exited this scope.
name|bool
name|Exited
decl_stmt|;
comment|/// \brief Whether to combine this scope with the outer scope, such that
comment|/// lookup will search our outer scope.
name|bool
name|CombineWithOuterScope
decl_stmt|;
comment|/// \brief If non-NULL, the template parameter pack that has been
comment|/// partially substituted per C++0x [temp.arg.explicit]p9.
name|NamedDecl
modifier|*
name|PartiallySubstitutedPack
decl_stmt|;
comment|/// \brief If \c PartiallySubstitutedPack is non-null, the set of
comment|/// explicitly-specified template arguments in that pack.
specifier|const
name|TemplateArgument
modifier|*
name|ArgsInPartiallySubstitutedPack
decl_stmt|;
comment|/// \brief If \c PartiallySubstitutedPack, the number of
comment|/// explicitly-specified template arguments in
comment|/// ArgsInPartiallySubstitutedPack.
name|unsigned
name|NumArgsInPartiallySubstitutedPack
decl_stmt|;
comment|// This class is non-copyable
name|LocalInstantiationScope
argument_list|(
specifier|const
name|LocalInstantiationScope
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|LocalInstantiationScope
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|public
label|:
name|LocalInstantiationScope
argument_list|(
argument|Sema&SemaRef
argument_list|,
argument|bool CombineWithOuterScope = false
argument_list|)
block|:
name|SemaRef
argument_list|(
name|SemaRef
argument_list|)
operator|,
name|Outer
argument_list|(
name|SemaRef
operator|.
name|CurrentInstantiationScope
argument_list|)
operator|,
name|Exited
argument_list|(
name|false
argument_list|)
operator|,
name|CombineWithOuterScope
argument_list|(
name|CombineWithOuterScope
argument_list|)
operator|,
name|PartiallySubstitutedPack
argument_list|(
argument|nullptr
argument_list|)
block|{
name|SemaRef
operator|.
name|CurrentInstantiationScope
operator|=
name|this
block|;     }
operator|~
name|LocalInstantiationScope
argument_list|()
block|{
name|Exit
argument_list|()
block|;     }
specifier|const
name|Sema
operator|&
name|getSema
argument_list|()
specifier|const
block|{
return|return
name|SemaRef
return|;
block|}
comment|/// \brief Exit this local instantiation scope early.
name|void
name|Exit
parameter_list|()
block|{
if|if
condition|(
name|Exited
condition|)
return|return;
for|for
control|(
name|unsigned
name|I
init|=
literal|0
init|,
name|N
init|=
name|ArgumentPacks
operator|.
name|size
argument_list|()
init|;
name|I
operator|!=
name|N
condition|;
operator|++
name|I
control|)
name|delete
name|ArgumentPacks
index|[
name|I
index|]
decl_stmt|;
name|SemaRef
operator|.
name|CurrentInstantiationScope
operator|=
name|Outer
expr_stmt|;
name|Exited
operator|=
name|true
expr_stmt|;
block|}
comment|/// \brief Clone this scope, and all outer scopes, down to the given
comment|/// outermost scope.
name|LocalInstantiationScope
modifier|*
name|cloneScopes
parameter_list|(
name|LocalInstantiationScope
modifier|*
name|Outermost
parameter_list|)
block|{
if|if
condition|(
name|this
operator|==
name|Outermost
condition|)
return|return
name|this
return|;
comment|// Save the current scope from SemaRef since the LocalInstantiationScope
comment|// will overwrite it on construction
name|LocalInstantiationScope
modifier|*
name|oldScope
init|=
name|SemaRef
operator|.
name|CurrentInstantiationScope
decl_stmt|;
name|LocalInstantiationScope
modifier|*
name|newScope
init|=
name|new
name|LocalInstantiationScope
argument_list|(
name|SemaRef
argument_list|,
name|CombineWithOuterScope
argument_list|)
decl_stmt|;
name|newScope
operator|->
name|Outer
operator|=
name|nullptr
expr_stmt|;
if|if
condition|(
name|Outer
condition|)
name|newScope
operator|->
name|Outer
operator|=
name|Outer
operator|->
name|cloneScopes
argument_list|(
name|Outermost
argument_list|)
expr_stmt|;
name|newScope
operator|->
name|PartiallySubstitutedPack
operator|=
name|PartiallySubstitutedPack
expr_stmt|;
name|newScope
operator|->
name|ArgsInPartiallySubstitutedPack
operator|=
name|ArgsInPartiallySubstitutedPack
expr_stmt|;
name|newScope
operator|->
name|NumArgsInPartiallySubstitutedPack
operator|=
name|NumArgsInPartiallySubstitutedPack
expr_stmt|;
for|for
control|(
name|LocalDeclsMap
operator|::
name|iterator
name|I
operator|=
name|LocalDecls
operator|.
name|begin
argument_list|()
operator|,
name|E
operator|=
name|LocalDecls
operator|.
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
block|{
specifier|const
name|Decl
modifier|*
name|D
init|=
name|I
operator|->
name|first
decl_stmt|;
name|llvm
operator|::
name|PointerUnion
operator|<
name|Decl
operator|*
operator|,
name|DeclArgumentPack
operator|*
operator|>
operator|&
name|Stored
operator|=
name|newScope
operator|->
name|LocalDecls
index|[
name|D
index|]
expr_stmt|;
if|if
condition|(
name|I
operator|->
name|second
operator|.
name|is
operator|<
name|Decl
operator|*
operator|>
operator|(
operator|)
condition|)
block|{
name|Stored
operator|=
name|I
operator|->
name|second
operator|.
name|get
operator|<
name|Decl
operator|*
operator|>
operator|(
operator|)
expr_stmt|;
block|}
else|else
block|{
name|DeclArgumentPack
modifier|*
name|OldPack
init|=
name|I
operator|->
name|second
operator|.
name|get
operator|<
name|DeclArgumentPack
operator|*
operator|>
operator|(
operator|)
decl_stmt|;
name|DeclArgumentPack
modifier|*
name|NewPack
init|=
name|new
name|DeclArgumentPack
argument_list|(
operator|*
name|OldPack
argument_list|)
decl_stmt|;
name|Stored
operator|=
name|NewPack
expr_stmt|;
name|newScope
operator|->
name|ArgumentPacks
operator|.
name|push_back
argument_list|(
name|NewPack
argument_list|)
expr_stmt|;
block|}
block|}
comment|// Restore the saved scope to SemaRef
name|SemaRef
operator|.
name|CurrentInstantiationScope
operator|=
name|oldScope
expr_stmt|;
return|return
name|newScope
return|;
block|}
comment|/// \brief deletes the given scope, and all otuer scopes, down to the
comment|/// given outermost scope.
specifier|static
name|void
name|deleteScopes
parameter_list|(
name|LocalInstantiationScope
modifier|*
name|Scope
parameter_list|,
name|LocalInstantiationScope
modifier|*
name|Outermost
parameter_list|)
block|{
while|while
condition|(
name|Scope
operator|&&
name|Scope
operator|!=
name|Outermost
condition|)
block|{
name|LocalInstantiationScope
modifier|*
name|Out
init|=
name|Scope
operator|->
name|Outer
decl_stmt|;
name|delete
name|Scope
decl_stmt|;
name|Scope
operator|=
name|Out
expr_stmt|;
block|}
block|}
comment|/// \brief Find the instantiation of the declaration D within the current
comment|/// instantiation scope.
comment|///
comment|/// \param D The declaration whose instantiation we are searching for.
comment|///
comment|/// \returns A pointer to the declaration or argument pack of declarations
comment|/// to which the declaration \c D is instantiated, if found. Otherwise,
comment|/// returns NULL.
name|llvm
operator|::
name|PointerUnion
operator|<
name|Decl
operator|*
operator|,
name|DeclArgumentPack
operator|*
operator|>
operator|*
name|findInstantiationOf
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|)
expr_stmt|;
name|void
name|InstantiatedLocal
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|,
name|Decl
modifier|*
name|Inst
parameter_list|)
function_decl|;
name|void
name|InstantiatedLocalPackArg
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|,
name|ParmVarDecl
modifier|*
name|Inst
parameter_list|)
function_decl|;
name|void
name|MakeInstantiatedLocalArgPack
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// \brief Note that the given parameter pack has been partially substituted
comment|/// via explicit specification of template arguments
comment|/// (C++0x [temp.arg.explicit]p9).
comment|///
comment|/// \param Pack The parameter pack, which will always be a template
comment|/// parameter pack.
comment|///
comment|/// \param ExplicitArgs The explicitly-specified template arguments provided
comment|/// for this parameter pack.
comment|///
comment|/// \param NumExplicitArgs The number of explicitly-specified template
comment|/// arguments provided for this parameter pack.
name|void
name|SetPartiallySubstitutedPack
parameter_list|(
name|NamedDecl
modifier|*
name|Pack
parameter_list|,
specifier|const
name|TemplateArgument
modifier|*
name|ExplicitArgs
parameter_list|,
name|unsigned
name|NumExplicitArgs
parameter_list|)
function_decl|;
comment|/// \brief Reset the partially-substituted pack when it is no longer of
comment|/// interest.
name|void
name|ResetPartiallySubstitutedPack
parameter_list|()
block|{
name|assert
argument_list|(
name|PartiallySubstitutedPack
operator|&&
literal|"No partially-substituted pack"
argument_list|)
expr_stmt|;
name|PartiallySubstitutedPack
operator|=
name|nullptr
expr_stmt|;
name|ArgsInPartiallySubstitutedPack
operator|=
name|nullptr
expr_stmt|;
name|NumArgsInPartiallySubstitutedPack
operator|=
literal|0
expr_stmt|;
block|}
comment|/// \brief Retrieve the partially-substitued template parameter pack.
comment|///
comment|/// If there is no partially-substituted parameter pack, returns NULL.
name|NamedDecl
modifier|*
name|getPartiallySubstitutedPack
argument_list|(
specifier|const
name|TemplateArgument
operator|*
operator|*
name|ExplicitArgs
operator|=
name|nullptr
argument_list|,
name|unsigned
operator|*
name|NumExplicitArgs
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|TemplateDeclInstantiator
range|:
name|public
name|DeclVisitor
operator|<
name|TemplateDeclInstantiator
decl_stmt|,
name|Decl
modifier|*
decl|>
block|{
name|Sema
modifier|&
name|SemaRef
decl_stmt|;
name|Sema
operator|::
name|ArgumentPackSubstitutionIndexRAII
name|SubstIndex
expr_stmt|;
name|DeclContext
modifier|*
name|Owner
decl_stmt|;
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|TemplateArgs
decl_stmt|;
name|Sema
operator|::
name|LateInstantiatedAttrVec
operator|*
name|LateAttrs
expr_stmt|;
name|LocalInstantiationScope
modifier|*
name|StartingScope
decl_stmt|;
comment|/// \brief A list of out-of-line class template partial
comment|/// specializations that will need to be instantiated after the
comment|/// enclosing class's instantiation is complete.
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|ClassTemplateDecl
operator|*
operator|,
name|ClassTemplatePartialSpecializationDecl
operator|*
operator|>
operator|,
literal|4
operator|>
name|OutOfLinePartialSpecs
expr_stmt|;
comment|/// \brief A list of out-of-line variable template partial
comment|/// specializations that will need to be instantiated after the
comment|/// enclosing variable's instantiation is complete.
comment|/// FIXME: Verify that this is needed.
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|VarTemplateDecl
operator|*
operator|,
name|VarTemplatePartialSpecializationDecl
operator|*
operator|>
operator|,
literal|4
operator|>
name|OutOfLineVarPartialSpecs
expr_stmt|;
name|public
label|:
name|TemplateDeclInstantiator
argument_list|(
name|Sema
operator|&
name|SemaRef
argument_list|,
name|DeclContext
operator|*
name|Owner
argument_list|,
specifier|const
name|MultiLevelTemplateArgumentList
operator|&
name|TemplateArgs
argument_list|)
operator|:
name|SemaRef
argument_list|(
name|SemaRef
argument_list|)
operator|,
name|SubstIndex
argument_list|(
name|SemaRef
argument_list|,
name|SemaRef
operator|.
name|ArgumentPackSubstitutionIndex
argument_list|)
operator|,
name|Owner
argument_list|(
name|Owner
argument_list|)
operator|,
name|TemplateArgs
argument_list|(
name|TemplateArgs
argument_list|)
operator|,
name|LateAttrs
argument_list|(
name|nullptr
argument_list|)
operator|,
name|StartingScope
argument_list|(
argument|nullptr
argument_list|)
block|{}
comment|// Define all the decl visitors using DeclNodes.inc
define|#
directive|define
name|DECL
parameter_list|(
name|DERIVED
parameter_list|,
name|BASE
parameter_list|)
define|\
value|Decl *Visit ## DERIVED ## Decl(DERIVED ## Decl *D);
define|#
directive|define
name|ABSTRACT_DECL
parameter_list|(
name|DECL
parameter_list|)
comment|// Decls which never appear inside a class or function.
define|#
directive|define
name|OBJCCONTAINER
parameter_list|(
name|DERIVED
parameter_list|,
name|BASE
parameter_list|)
define|#
directive|define
name|FILESCOPEASM
parameter_list|(
name|DERIVED
parameter_list|,
name|BASE
parameter_list|)
define|#
directive|define
name|IMPORT
parameter_list|(
name|DERIVED
parameter_list|,
name|BASE
parameter_list|)
define|#
directive|define
name|EXPORT
parameter_list|(
name|DERIVED
parameter_list|,
name|BASE
parameter_list|)
define|#
directive|define
name|LINKAGESPEC
parameter_list|(
name|DERIVED
parameter_list|,
name|BASE
parameter_list|)
define|#
directive|define
name|OBJCCOMPATIBLEALIAS
parameter_list|(
name|DERIVED
parameter_list|,
name|BASE
parameter_list|)
define|#
directive|define
name|OBJCMETHOD
parameter_list|(
name|DERIVED
parameter_list|,
name|BASE
parameter_list|)
define|#
directive|define
name|OBJCTYPEPARAM
parameter_list|(
name|DERIVED
parameter_list|,
name|BASE
parameter_list|)
define|#
directive|define
name|OBJCIVAR
parameter_list|(
name|DERIVED
parameter_list|,
name|BASE
parameter_list|)
define|#
directive|define
name|OBJCPROPERTY
parameter_list|(
name|DERIVED
parameter_list|,
name|BASE
parameter_list|)
define|#
directive|define
name|OBJCPROPERTYIMPL
parameter_list|(
name|DERIVED
parameter_list|,
name|BASE
parameter_list|)
define|#
directive|define
name|EMPTY
parameter_list|(
name|DERIVED
parameter_list|,
name|BASE
parameter_list|)
comment|// Decls which use special-case instantiation code.
define|#
directive|define
name|BLOCK
parameter_list|(
name|DERIVED
parameter_list|,
name|BASE
parameter_list|)
define|#
directive|define
name|CAPTURED
parameter_list|(
name|DERIVED
parameter_list|,
name|BASE
parameter_list|)
define|#
directive|define
name|IMPLICITPARAM
parameter_list|(
name|DERIVED
parameter_list|,
name|BASE
parameter_list|)
include|#
directive|include
file|"clang/AST/DeclNodes.inc"
comment|// A few supplemental visitor functions.
name|Decl
operator|*
name|VisitCXXMethodDecl
argument_list|(
argument|CXXMethodDecl *D
argument_list|,
argument|TemplateParameterList *TemplateParams
argument_list|,
argument|bool IsClassScopeSpecialization = false
argument_list|)
expr_stmt|;
name|Decl
modifier|*
name|VisitFunctionDecl
parameter_list|(
name|FunctionDecl
modifier|*
name|D
parameter_list|,
name|TemplateParameterList
modifier|*
name|TemplateParams
parameter_list|)
function_decl|;
name|Decl
modifier|*
name|VisitDecl
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
name|Decl
modifier|*
name|VisitVarDecl
argument_list|(
name|VarDecl
operator|*
name|D
argument_list|,
name|bool
name|InstantiatingVarTemplate
argument_list|,
name|ArrayRef
operator|<
name|BindingDecl
operator|*
operator|>
operator|*
name|Bindings
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|// Enable late instantiation of attributes.  Late instantiated attributes
comment|// will be stored in LA.
name|void
name|enableLateAttributeInstantiation
argument_list|(
name|Sema
operator|::
name|LateInstantiatedAttrVec
operator|*
name|LA
argument_list|)
block|{
name|LateAttrs
operator|=
name|LA
expr_stmt|;
name|StartingScope
operator|=
name|SemaRef
operator|.
name|CurrentInstantiationScope
expr_stmt|;
block|}
comment|// Disable late instantiation of attributes.
name|void
name|disableLateAttributeInstantiation
parameter_list|()
block|{
name|LateAttrs
operator|=
name|nullptr
expr_stmt|;
name|StartingScope
operator|=
name|nullptr
expr_stmt|;
block|}
name|LocalInstantiationScope
operator|*
name|getStartingScope
argument_list|()
specifier|const
block|{
return|return
name|StartingScope
return|;
block|}
typedef|typedef
name|SmallVectorImpl
operator|<
name|std
operator|::
name|pair
operator|<
name|ClassTemplateDecl
operator|*
operator|,
name|ClassTemplatePartialSpecializationDecl
operator|*
operator|>
expr|>
operator|::
name|iterator
name|delayed_partial_spec_iterator
expr_stmt|;
typedef|typedef
name|SmallVectorImpl
operator|<
name|std
operator|::
name|pair
operator|<
name|VarTemplateDecl
operator|*
operator|,
name|VarTemplatePartialSpecializationDecl
operator|*
operator|>
expr|>
operator|::
name|iterator
name|delayed_var_partial_spec_iterator
expr_stmt|;
comment|/// \brief Return an iterator to the beginning of the set of
comment|/// "delayed" partial specializations, which must be passed to
comment|/// InstantiateClassTemplatePartialSpecialization once the class
comment|/// definition has been completed.
name|delayed_partial_spec_iterator
name|delayed_partial_spec_begin
parameter_list|()
block|{
return|return
name|OutOfLinePartialSpecs
operator|.
name|begin
argument_list|()
return|;
block|}
name|delayed_var_partial_spec_iterator
name|delayed_var_partial_spec_begin
parameter_list|()
block|{
return|return
name|OutOfLineVarPartialSpecs
operator|.
name|begin
argument_list|()
return|;
block|}
comment|/// \brief Return an iterator to the end of the set of
comment|/// "delayed" partial specializations, which must be passed to
comment|/// InstantiateClassTemplatePartialSpecialization once the class
comment|/// definition has been completed.
name|delayed_partial_spec_iterator
name|delayed_partial_spec_end
parameter_list|()
block|{
return|return
name|OutOfLinePartialSpecs
operator|.
name|end
argument_list|()
return|;
block|}
name|delayed_var_partial_spec_iterator
name|delayed_var_partial_spec_end
parameter_list|()
block|{
return|return
name|OutOfLineVarPartialSpecs
operator|.
name|end
argument_list|()
return|;
block|}
comment|// Helper functions for instantiating methods.
name|TypeSourceInfo
modifier|*
name|SubstFunctionType
argument_list|(
name|FunctionDecl
operator|*
name|D
argument_list|,
name|SmallVectorImpl
operator|<
name|ParmVarDecl
operator|*
operator|>
operator|&
name|Params
argument_list|)
decl_stmt|;
name|bool
name|InitFunctionInstantiation
parameter_list|(
name|FunctionDecl
modifier|*
name|New
parameter_list|,
name|FunctionDecl
modifier|*
name|Tmpl
parameter_list|)
function_decl|;
name|bool
name|InitMethodInstantiation
parameter_list|(
name|CXXMethodDecl
modifier|*
name|New
parameter_list|,
name|CXXMethodDecl
modifier|*
name|Tmpl
parameter_list|)
function_decl|;
name|TemplateParameterList
modifier|*
name|SubstTemplateParams
parameter_list|(
name|TemplateParameterList
modifier|*
name|List
parameter_list|)
function_decl|;
name|bool
name|SubstQualifier
parameter_list|(
specifier|const
name|DeclaratorDecl
modifier|*
name|OldDecl
parameter_list|,
name|DeclaratorDecl
modifier|*
name|NewDecl
parameter_list|)
function_decl|;
name|bool
name|SubstQualifier
parameter_list|(
specifier|const
name|TagDecl
modifier|*
name|OldDecl
parameter_list|,
name|TagDecl
modifier|*
name|NewDecl
parameter_list|)
function_decl|;
name|Decl
modifier|*
name|VisitVarTemplateSpecializationDecl
argument_list|(
name|VarTemplateDecl
operator|*
name|VarTemplate
argument_list|,
name|VarDecl
operator|*
name|FromVar
argument_list|,
name|void
operator|*
name|InsertPos
argument_list|,
specifier|const
name|TemplateArgumentListInfo
operator|&
name|TemplateArgsInfo
argument_list|,
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|Converted
argument_list|)
decl_stmt|;
name|Decl
modifier|*
name|InstantiateTypedefNameDecl
parameter_list|(
name|TypedefNameDecl
modifier|*
name|D
parameter_list|,
name|bool
name|IsTypeAlias
parameter_list|)
function_decl|;
name|ClassTemplatePartialSpecializationDecl
modifier|*
name|InstantiateClassTemplatePartialSpecialization
parameter_list|(
name|ClassTemplateDecl
modifier|*
name|ClassTemplate
parameter_list|,
name|ClassTemplatePartialSpecializationDecl
modifier|*
name|PartialSpec
parameter_list|)
function_decl|;
name|VarTemplatePartialSpecializationDecl
modifier|*
name|InstantiateVarTemplatePartialSpecialization
parameter_list|(
name|VarTemplateDecl
modifier|*
name|VarTemplate
parameter_list|,
name|VarTemplatePartialSpecializationDecl
modifier|*
name|PartialSpec
parameter_list|)
function_decl|;
name|void
name|InstantiateEnumDefinition
parameter_list|(
name|EnumDecl
modifier|*
name|Enum
parameter_list|,
name|EnumDecl
modifier|*
name|Pattern
parameter_list|)
function_decl|;
name|private
label|:
name|template
operator|<
name|typename
name|T
operator|>
name|Decl
operator|*
name|instantiateUnresolvedUsingDecl
argument_list|(
argument|T *D
argument_list|,
argument|bool InstantiatingPackElement = false
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_SEMA_TEMPLATE_H
end_comment

end_unit

