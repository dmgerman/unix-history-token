begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Value.h - Definition of the Value class ------------*- C++ -*-===//
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
comment|// This file declares the Value class.
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
name|LLVM_IR_VALUE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_VALUE_H
end_define

begin_include
include|#
directive|include
file|"llvm-c/Core.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Use.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CBindingWrapping.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|APInt
decl_stmt|;
name|class
name|Argument
decl_stmt|;
name|class
name|AssemblyAnnotationWriter
decl_stmt|;
name|class
name|BasicBlock
decl_stmt|;
name|class
name|Constant
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|GlobalAlias
decl_stmt|;
name|class
name|GlobalObject
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|InlineAsm
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|Twine
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|ValueHandleBase
decl_stmt|;
name|class
name|ValueSymbolTable
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|template
operator|<
name|typename
name|ValueTy
operator|>
name|class
name|StringMapEntry
expr_stmt|;
typedef|typedef
name|StringMapEntry
operator|<
name|Value
operator|*
operator|>
name|ValueName
expr_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//                                 Value Class
comment|//===----------------------------------------------------------------------===//
comment|/// \brief LLVM Value Representation
comment|///
comment|/// This is a very important LLVM class. It is the base class of all values
comment|/// computed by a program that may be used as operands to other values. Value is
comment|/// the super class of other important classes such as Instruction and Function.
comment|/// All Values have a Type. Type is not a subclass of Value. Some values can
comment|/// have a name and they belong to some Module.  Setting the name on the Value
comment|/// automatically updates the module's symbol table.
comment|///
comment|/// Every value has a "use list" that keeps track of which other Values are
comment|/// using this Value.  A Value can also have an arbitrary number of ValueHandle
comment|/// objects that watch it and listen to RAUW and Destroy events.  See
comment|/// llvm/IR/ValueHandle.h for details.
name|class
name|Value
block|{
name|Type
modifier|*
name|VTy
decl_stmt|;
name|Use
modifier|*
name|UseList
decl_stmt|;
name|friend
name|class
name|ValueAsMetadata
decl_stmt|;
comment|// Allow access to NameAndIsUsedByMD.
name|friend
name|class
name|ValueHandleBase
decl_stmt|;
name|PointerIntPair
operator|<
name|ValueName
operator|*
operator|,
literal|1
operator|>
name|NameAndIsUsedByMD
expr_stmt|;
specifier|const
name|unsigned
name|char
name|SubclassID
decl_stmt|;
comment|// Subclass identifier (for isa/dyn_cast)
name|unsigned
name|char
name|HasValueHandle
range|:
literal|1
decl_stmt|;
comment|// Has a ValueHandle pointing to this?
name|protected
label|:
comment|/// \brief Hold subclass data that can be dropped.
comment|///
comment|/// This member is similar to SubclassData, however it is for holding
comment|/// information which may be used to aid optimization, but which may be
comment|/// cleared to zero without affecting conservative interpretation.
name|unsigned
name|char
name|SubclassOptionalData
range|:
literal|7
decl_stmt|;
name|private
label|:
comment|/// \brief Hold arbitrary subclass data.
comment|///
comment|/// This member is defined by this class, but is not used for anything.
comment|/// Subclasses can use it to hold whatever state they find useful.  This
comment|/// field is initialized to zero by the ctor.
name|unsigned
name|short
name|SubclassData
decl_stmt|;
name|protected
label|:
comment|/// \brief The number of operands in the subclass.
comment|///
comment|/// This member is defined by this class, but not used for anything.
comment|/// Subclasses can use it to store their number of operands, if they have
comment|/// any.
comment|///
comment|/// This is stored here to save space in User on 64-bit hosts.  Since most
comment|/// instances of Value have operands, 32-bit hosts aren't significantly
comment|/// affected.
name|unsigned
name|NumOperands
decl_stmt|;
name|private
label|:
name|template
operator|<
name|typename
name|UseT
operator|>
comment|// UseT == 'Use' or 'const Use'
name|class
name|use_iterator_impl
operator|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
operator|,
name|UseT
operator|*
operator|,
name|ptrdiff_t
operator|>
block|{
typedef|typedef
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
operator|,
name|UseT
operator|*
operator|,
name|ptrdiff_t
operator|>
name|super
expr_stmt|;
name|UseT
operator|*
name|U
expr_stmt|;
name|explicit
name|use_iterator_impl
argument_list|(
name|UseT
operator|*
name|u
argument_list|)
operator|:
name|U
argument_list|(
argument|u
argument_list|)
block|{}
name|friend
name|class
name|Value
expr_stmt|;
name|public
label|:
typedef|typedef
name|typename
name|super
operator|::
name|reference
name|reference
expr_stmt|;
typedef|typedef
name|typename
name|super
operator|::
name|pointer
name|pointer
expr_stmt|;
name|use_iterator_impl
argument_list|()
operator|:
name|U
argument_list|()
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|use_iterator_impl
operator|&
name|x
operator|)
specifier|const
block|{
return|return
name|U
operator|==
name|x
operator|.
name|U
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|use_iterator_impl
operator|&
name|x
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|x
operator|)
return|;
block|}
name|use_iterator_impl
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// Preincrement
name|assert
argument_list|(
name|U
operator|&&
literal|"Cannot increment end iterator!"
argument_list|)
block|;
name|U
operator|=
name|U
operator|->
name|getNext
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
name|use_iterator_impl
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// Postincrement
name|auto
name|tmp
operator|=
operator|*
name|this
block|;
operator|++
operator|*
name|this
block|;
return|return
name|tmp
return|;
block|}
name|UseT
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|U
operator|&&
literal|"Cannot dereference end iterator!"
argument_list|)
block|;
return|return
operator|*
name|U
return|;
block|}
name|UseT
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
operator|&
name|operator
operator|*
operator|(
operator|)
return|;
block|}
name|operator
name|use_iterator_impl
operator|<
specifier|const
name|UseT
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|use_iterator_impl
operator|<
specifier|const
name|UseT
operator|>
operator|(
name|U
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|UserTy
operator|>
comment|// UserTy == 'User' or 'const User'
name|class
name|user_iterator_impl
operator|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
operator|,
name|UserTy
operator|*
operator|,
name|ptrdiff_t
operator|>
block|{
typedef|typedef
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
operator|,
name|UserTy
operator|*
operator|,
name|ptrdiff_t
operator|>
name|super
expr_stmt|;
name|use_iterator_impl
operator|<
name|Use
operator|>
name|UI
expr_stmt|;
end_expr_stmt

begin_macro
name|explicit
end_macro

begin_expr_stmt
name|user_iterator_impl
argument_list|(
name|Use
operator|*
name|U
argument_list|)
operator|:
name|UI
argument_list|(
argument|U
argument_list|)
block|{}
name|friend
name|class
name|Value
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_typedef
typedef|typedef
name|typename
name|super
operator|::
name|reference
name|reference
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|super
operator|::
name|pointer
name|pointer
expr_stmt|;
end_typedef

begin_macro
name|user_iterator_impl
argument_list|()
end_macro

begin_block
block|{}
end_block

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|user_iterator_impl
operator|&
name|x
operator|)
specifier|const
block|{
return|return
name|UI
operator|==
name|x
operator|.
name|UI
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|user_iterator_impl
operator|&
name|x
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|x
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns true if this iterator is equal to user_end() on the value.
end_comment

begin_expr_stmt
name|bool
name|atEnd
argument_list|()
specifier|const
block|{
return|return
operator|*
name|this
operator|==
name|user_iterator_impl
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|user_iterator_impl
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// Preincrement
operator|++
name|UI
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|user_iterator_impl
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// Postincrement
name|auto
name|tmp
operator|=
operator|*
name|this
block|;
operator|++
operator|*
name|this
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_comment
comment|// Retrieve a pointer to the current User.
end_comment

begin_expr_stmt
name|UserTy
operator|*
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|UI
operator|->
name|getUser
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|UserTy
operator|*
name|operator
operator|->
expr|(
end_expr_stmt

begin_expr_stmt
unit|)
specifier|const
block|{
return|return
name|operator
operator|*
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|operator
name|user_iterator_impl
operator|<
specifier|const
name|UserTy
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|user_iterator_impl
operator|<
specifier|const
name|UserTy
operator|>
operator|(
operator|*
name|UI
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|Use
operator|&
name|getUse
argument_list|()
specifier|const
block|{
return|return
operator|*
name|UI
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return the operand # of this use in its User.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// FIXME: Replace all callers with a direct call to Use::getOperandNo.
end_comment

begin_expr_stmt
name|unsigned
name|getOperandNo
argument_list|()
specifier|const
block|{
return|return
name|UI
operator|->
name|getOperandNo
argument_list|()
return|;
block|}
end_expr_stmt

begin_decl_stmt
unit|};
name|void
name|operator
init|=
operator|(
specifier|const
name|Value
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
end_decl_stmt

begin_macro
name|Value
argument_list|(
argument|const Value&
argument_list|)
end_macro

begin_expr_stmt
name|LLVM_DELETED_FUNCTION
expr_stmt|;
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_macro
name|Value
argument_list|(
argument|Type *Ty
argument_list|,
argument|unsigned scid
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|virtual
operator|~
name|Value
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Support for debugging, callable in GDB: V->dump()
end_comment

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Implement operator<< on Value.
end_comment

begin_decl_stmt
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|O
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Print the name of this Value out to the specified raw_ostream.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is useful when you just want to print 'int %reg126', not the
end_comment

begin_comment
comment|/// instruction that generated it. If you specify a Module for context, then
end_comment

begin_comment
comment|/// even constanst get pretty-printed; for example, the type of a null
end_comment

begin_comment
comment|/// pointer is printed symbolically.
end_comment

begin_decl_stmt
name|void
name|printAsOperand
argument_list|(
name|raw_ostream
operator|&
name|O
argument_list|,
name|bool
name|PrintType
operator|=
name|true
argument_list|,
specifier|const
name|Module
operator|*
name|M
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief All values are typed, get the type of this value.
end_comment

begin_expr_stmt
name|Type
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|VTy
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief All values hold a context through their type.
end_comment

begin_expr_stmt
name|LLVMContext
operator|&
name|getContext
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// \brief All values can potentially be named.
end_comment

begin_expr_stmt
name|bool
name|hasName
argument_list|()
specifier|const
block|{
return|return
name|getValueName
argument_list|()
operator|!=
name|nullptr
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ValueName
operator|*
name|getValueName
argument_list|()
specifier|const
block|{
return|return
name|NameAndIsUsedByMD
operator|.
name|getPointer
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setValueName
parameter_list|(
name|ValueName
modifier|*
name|VN
parameter_list|)
block|{
name|NameAndIsUsedByMD
operator|.
name|setPointer
argument_list|(
name|VN
argument_list|)
expr_stmt|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_function_decl
name|void
name|destroyValueName
parameter_list|()
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_comment
comment|/// \brief Return a constant reference to the value's name.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is cheap and guaranteed to return the same reference as long as the
end_comment

begin_comment
comment|/// value is not modified.
end_comment

begin_expr_stmt
name|StringRef
name|getName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Change the name of the value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Choose a new unique name if the provided name is taken.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Name The new name; or "" if the value's name should be removed.
end_comment

begin_function_decl
name|void
name|setName
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Transfer the name from V to this value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// After taking V's name, sets V's name to empty.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \note It is an error to call V->takeName(V).
end_comment

begin_function_decl
name|void
name|takeName
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Change all uses of this to point to a new Value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Go through the uses list for this definition and make each use point to
end_comment

begin_comment
comment|/// "V" instead of "this".  After this completes, 'this's use list is
end_comment

begin_comment
comment|/// guaranteed to be empty.
end_comment

begin_function_decl
name|void
name|replaceAllUsesWith
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// replaceUsesOutsideBlock - Go through the uses list for this definition and
end_comment

begin_comment
comment|/// make each use point to "V" instead of "this" when the use is outside the
end_comment

begin_comment
comment|/// block. 'This's use list is expected to have at least one element.
end_comment

begin_comment
comment|/// Unlike replaceAllUsesWith this function does not support basic block
end_comment

begin_comment
comment|/// values or constant users.
end_comment

begin_function_decl
name|void
name|replaceUsesOutsideBlock
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|,
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Methods for handling the chain of uses of this Value.
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|bool
name|use_empty
argument_list|()
specifier|const
block|{
return|return
name|UseList
operator|==
name|nullptr
return|;
block|}
end_expr_stmt

begin_typedef
typedef|typedef
name|use_iterator_impl
operator|<
name|Use
operator|>
name|use_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|use_iterator_impl
operator|<
specifier|const
name|Use
operator|>
name|const_use_iterator
expr_stmt|;
end_typedef

begin_function
name|use_iterator
name|use_begin
parameter_list|()
block|{
return|return
name|use_iterator
argument_list|(
name|UseList
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|const_use_iterator
name|use_begin
argument_list|()
specifier|const
block|{
return|return
name|const_use_iterator
argument_list|(
name|UseList
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|use_iterator
name|use_end
parameter_list|()
block|{
return|return
name|use_iterator
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|const_use_iterator
name|use_end
argument_list|()
specifier|const
block|{
return|return
name|const_use_iterator
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|iterator_range
operator|<
name|use_iterator
operator|>
name|uses
argument_list|()
block|{
return|return
name|iterator_range
operator|<
name|use_iterator
operator|>
operator|(
name|use_begin
argument_list|()
operator|,
name|use_end
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|iterator_range
operator|<
name|const_use_iterator
operator|>
name|uses
argument_list|()
specifier|const
block|{
return|return
name|iterator_range
operator|<
name|const_use_iterator
operator|>
operator|(
name|use_begin
argument_list|()
operator|,
name|use_end
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|user_empty
argument_list|()
specifier|const
block|{
return|return
name|UseList
operator|==
name|nullptr
return|;
block|}
end_expr_stmt

begin_typedef
typedef|typedef
name|user_iterator_impl
operator|<
name|User
operator|>
name|user_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|user_iterator_impl
operator|<
specifier|const
name|User
operator|>
name|const_user_iterator
expr_stmt|;
end_typedef

begin_function
name|user_iterator
name|user_begin
parameter_list|()
block|{
return|return
name|user_iterator
argument_list|(
name|UseList
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|const_user_iterator
name|user_begin
argument_list|()
specifier|const
block|{
return|return
name|const_user_iterator
argument_list|(
name|UseList
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|user_iterator
name|user_end
parameter_list|()
block|{
return|return
name|user_iterator
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|const_user_iterator
name|user_end
argument_list|()
specifier|const
block|{
return|return
name|const_user_iterator
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|User
modifier|*
name|user_back
parameter_list|()
block|{
return|return
operator|*
name|user_begin
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|User
operator|*
name|user_back
argument_list|()
specifier|const
block|{
return|return
operator|*
name|user_begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|iterator_range
operator|<
name|user_iterator
operator|>
name|users
argument_list|()
block|{
return|return
name|iterator_range
operator|<
name|user_iterator
operator|>
operator|(
name|user_begin
argument_list|()
operator|,
name|user_end
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|iterator_range
operator|<
name|const_user_iterator
operator|>
name|users
argument_list|()
specifier|const
block|{
return|return
name|iterator_range
operator|<
name|const_user_iterator
operator|>
operator|(
name|user_begin
argument_list|()
operator|,
name|user_end
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return true if there is exactly one user of this value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is specialized because it is a common request and does not require
end_comment

begin_comment
comment|/// traversing the whole use list.
end_comment

begin_expr_stmt
name|bool
name|hasOneUse
argument_list|()
specifier|const
block|{
name|const_use_iterator
name|I
operator|=
name|use_begin
argument_list|()
block|,
name|E
operator|=
name|use_end
argument_list|()
block|;
if|if
condition|(
name|I
operator|==
name|E
condition|)
return|return
name|false
return|;
end_expr_stmt

begin_return
return|return
operator|++
name|I
operator|==
name|E
return|;
end_return

begin_comment
unit|}
comment|/// \brief Return true if this Value has exactly N users.
end_comment

begin_macro
unit|bool
name|hasNUses
argument_list|(
argument|unsigned N
argument_list|)
end_macro

begin_decl_stmt
specifier|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Return true if this value has N users or more.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is logically equivalent to getNumUses()>= N.
end_comment

begin_decl_stmt
name|bool
name|hasNUsesOrMore
argument_list|(
name|unsigned
name|N
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Check if this value is used in the specified basic block.
end_comment

begin_decl_stmt
name|bool
name|isUsedInBasicBlock
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief This method computes the number of uses of this Value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is a linear time operation.  Use hasOneUse, hasNUses, or
end_comment

begin_comment
comment|/// hasNUsesOrMore to check for specific values.
end_comment

begin_expr_stmt
name|unsigned
name|getNumUses
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief This method should only be used by the Use class.
end_comment

begin_function
name|void
name|addUse
parameter_list|(
name|Use
modifier|&
name|U
parameter_list|)
block|{
name|U
operator|.
name|addToList
argument_list|(
operator|&
name|UseList
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Concrete subclass of this.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// An enumeration for keeping track of the concrete subclass of Value that
end_comment

begin_comment
comment|/// is actually instantiated. Values of this enumeration are kept in the
end_comment

begin_comment
comment|/// Value classes SubclassID field. They are used for concrete type
end_comment

begin_comment
comment|/// identification.
end_comment

begin_enum
enum|enum
name|ValueTy
block|{
name|ArgumentVal
block|,
comment|// This is an instance of Argument
name|BasicBlockVal
block|,
comment|// This is an instance of BasicBlock
name|FunctionVal
block|,
comment|// This is an instance of Function
name|GlobalAliasVal
block|,
comment|// This is an instance of GlobalAlias
name|GlobalVariableVal
block|,
comment|// This is an instance of GlobalVariable
name|UndefValueVal
block|,
comment|// This is an instance of UndefValue
name|BlockAddressVal
block|,
comment|// This is an instance of BlockAddress
name|ConstantExprVal
block|,
comment|// This is an instance of ConstantExpr
name|ConstantAggregateZeroVal
block|,
comment|// This is an instance of ConstantAggregateZero
name|ConstantDataArrayVal
block|,
comment|// This is an instance of ConstantDataArray
name|ConstantDataVectorVal
block|,
comment|// This is an instance of ConstantDataVector
name|ConstantIntVal
block|,
comment|// This is an instance of ConstantInt
name|ConstantFPVal
block|,
comment|// This is an instance of ConstantFP
name|ConstantArrayVal
block|,
comment|// This is an instance of ConstantArray
name|ConstantStructVal
block|,
comment|// This is an instance of ConstantStruct
name|ConstantVectorVal
block|,
comment|// This is an instance of ConstantVector
name|ConstantPointerNullVal
block|,
comment|// This is an instance of ConstantPointerNull
name|MetadataAsValueVal
block|,
comment|// This is an instance of MetadataAsValue
name|InlineAsmVal
block|,
comment|// This is an instance of InlineAsm
name|InstructionVal
block|,
comment|// This is an instance of Instruction
comment|// Enum values starting at InstructionVal are used for Instructions;
comment|// don't add new values here!
comment|// Markers:
name|ConstantFirstVal
init|=
name|FunctionVal
block|,
name|ConstantLastVal
init|=
name|ConstantPointerNullVal
block|}
enum|;
end_enum

begin_comment
comment|/// \brief Return an ID for the concrete type of this object.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is used to implement the classof checks.  This should not be used
end_comment

begin_comment
comment|/// for any other purpose, as the values may change as LLVM evolves.  Also,
end_comment

begin_comment
comment|/// note that for instructions, the Instruction's opcode is added to
end_comment

begin_comment
comment|/// InstructionVal. So this means three things:
end_comment

begin_comment
comment|/// # there is no value with code InstructionVal (no opcode==0).
end_comment

begin_comment
comment|/// # there are more possible values for the value type than in ValueTy enum.
end_comment

begin_comment
comment|/// # the InstructionVal enumerator must be the highest valued enumerator in
end_comment

begin_comment
comment|///   the ValueTy enum.
end_comment

begin_expr_stmt
name|unsigned
name|getValueID
argument_list|()
specifier|const
block|{
return|return
name|SubclassID
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return the raw optional flags value contained in this value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This should only be used when testing two Values for equivalence.
end_comment

begin_expr_stmt
name|unsigned
name|getRawSubclassOptionalData
argument_list|()
specifier|const
block|{
return|return
name|SubclassOptionalData
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Clear the optional flags contained in this value.
end_comment

begin_function
name|void
name|clearSubclassOptionalData
parameter_list|()
block|{
name|SubclassOptionalData
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Check the optional flags for equality.
end_comment

begin_decl_stmt
name|bool
name|hasSameSubclassOptionalData
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|)
decl|const
block|{
return|return
name|SubclassOptionalData
operator|==
name|V
operator|->
name|SubclassOptionalData
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Clear any optional flags not set in the given Value.
end_comment

begin_function
name|void
name|intersectOptionalDataWith
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
block|{
name|SubclassOptionalData
operator|&=
name|V
operator|->
name|SubclassOptionalData
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Return true if there is a value handle associated with this value.
end_comment

begin_expr_stmt
name|bool
name|hasValueHandle
argument_list|()
specifier|const
block|{
return|return
name|HasValueHandle
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return true if there is metadata referencing this value.
end_comment

begin_expr_stmt
name|bool
name|isUsedByMetadata
argument_list|()
specifier|const
block|{
return|return
name|NameAndIsUsedByMD
operator|.
name|getInt
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Strip off pointer casts, all-zero GEPs, and aliases.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns the original uncasted value.  If this is called on a non-pointer
end_comment

begin_comment
comment|/// value, it returns 'this'.
end_comment

begin_function_decl
name|Value
modifier|*
name|stripPointerCasts
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
specifier|const
name|Value
operator|*
name|stripPointerCasts
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Value
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|stripPointerCasts
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Strip off pointer casts and all-zero GEPs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns the original uncasted value.  If this is called on a non-pointer
end_comment

begin_comment
comment|/// value, it returns 'this'.
end_comment

begin_function_decl
name|Value
modifier|*
name|stripPointerCastsNoFollowAliases
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
specifier|const
name|Value
operator|*
name|stripPointerCastsNoFollowAliases
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Value
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|stripPointerCastsNoFollowAliases
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Strip off pointer casts and all-constant inbounds GEPs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns the original pointer value.  If this is called on a non-pointer
end_comment

begin_comment
comment|/// value, it returns 'this'.
end_comment

begin_function_decl
name|Value
modifier|*
name|stripInBoundsConstantOffsets
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
specifier|const
name|Value
operator|*
name|stripInBoundsConstantOffsets
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Value
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|stripInBoundsConstantOffsets
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Accumulate offsets from \a stripInBoundsConstantOffsets().
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Stores the resulting constant offset stripped into the APInt provided.
end_comment

begin_comment
comment|/// The provided APInt will be extended or truncated as needed to be the
end_comment

begin_comment
comment|/// correct bitwidth for an offset of this pointer type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If this is called on a non-pointer value, it returns 'this'.
end_comment

begin_function_decl
name|Value
modifier|*
name|stripAndAccumulateInBoundsConstantOffsets
parameter_list|(
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|,
name|APInt
modifier|&
name|Offset
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|const
name|Value
modifier|*
name|stripAndAccumulateInBoundsConstantOffsets
argument_list|(
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|,
name|APInt
operator|&
name|Offset
argument_list|)
decl|const
block|{
return|return
name|const_cast
operator|<
name|Value
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|stripAndAccumulateInBoundsConstantOffsets
argument_list|(
name|DL
argument_list|,
name|Offset
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Strip off pointer casts and inbounds GEPs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns the original pointer value.  If this is called on a non-pointer
end_comment

begin_comment
comment|/// value, it returns 'this'.
end_comment

begin_function_decl
name|Value
modifier|*
name|stripInBoundsOffsets
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
specifier|const
name|Value
operator|*
name|stripInBoundsOffsets
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Value
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|stripInBoundsOffsets
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Check if this is always a dereferenceable pointer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Test if this value is always a pointer to allocated and suitably aligned
end_comment

begin_comment
comment|/// memory for a simple load or store.
end_comment

begin_decl_stmt
name|bool
name|isDereferenceablePointer
argument_list|(
specifier|const
name|DataLayout
operator|*
name|DL
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Translate PHI node to its predecessor from the given basic block.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If this value is a PHI node with CurBB as its parent, return the value in
end_comment

begin_comment
comment|/// the PHI node corresponding to PredBB.  If not, return ourself.  This is
end_comment

begin_comment
comment|/// useful if you want to know the value something has in a predecessor
end_comment

begin_comment
comment|/// block.
end_comment

begin_function_decl
name|Value
modifier|*
name|DoPHITranslation
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|CurBB
parameter_list|,
specifier|const
name|BasicBlock
modifier|*
name|PredBB
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|const
name|Value
modifier|*
name|DoPHITranslation
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|CurBB
argument_list|,
specifier|const
name|BasicBlock
operator|*
name|PredBB
argument_list|)
decl|const
block|{
return|return
name|const_cast
operator|<
name|Value
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|DoPHITranslation
argument_list|(
name|CurBB
argument_list|,
name|PredBB
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief The maximum alignment for instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is the greatest alignment value supported by load, store, and alloca
end_comment

begin_comment
comment|/// instructions, and global values.
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|unsigned
name|MaximumAlignment
init|=
literal|1u
operator|<<
literal|29
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Mutate the type of this Value to be of the specified type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that this is an extremely dangerous operation which can create
end_comment

begin_comment
comment|/// completely invalid IR very easily.  It is strongly recommended that you
end_comment

begin_comment
comment|/// recreate IR objects with the right types instead of mutating them in
end_comment

begin_comment
comment|/// place.
end_comment

begin_function
name|void
name|mutateType
parameter_list|(
name|Type
modifier|*
name|Ty
parameter_list|)
block|{
name|VTy
operator|=
name|Ty
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Sort the use-list.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Sorts the Value's use-list by Cmp using a stable mergesort.  Cmp is
end_comment

begin_comment
comment|/// expected to compare two \a Use references.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|Compare
operator|>
name|void
name|sortUseList
argument_list|(
argument|Compare Cmp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Reverse the use-list.
end_comment

begin_function_decl
name|void
name|reverseUseList
parameter_list|()
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_comment
comment|/// \brief Merge two lists together.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Merges \c L and \c R using \c Cmp.  To enable stable sorts, always pushes
end_comment

begin_comment
comment|/// "equal" items from L before items from R.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return the first element in the list.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \note Completely ignores \a Use::Prev (doesn't read, doesn't update).
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|Compare
operator|>
specifier|static
name|Use
operator|*
name|mergeUseLists
argument_list|(
argument|Use *L
argument_list|,
argument|Use *R
argument_list|,
argument|Compare Cmp
argument_list|)
block|{
name|Use
operator|*
name|Merged
block|;
name|mergeUseListsImpl
argument_list|(
name|L
argument_list|,
name|R
argument_list|,
operator|&
name|Merged
argument_list|,
name|Cmp
argument_list|)
block|;
return|return
name|Merged
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Tail-recursive helper for \a mergeUseLists().
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param[out] Next the first element in the list.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|Compare
operator|>
specifier|static
name|void
name|mergeUseListsImpl
argument_list|(
argument|Use *L
argument_list|,
argument|Use *R
argument_list|,
argument|Use **Next
argument_list|,
argument|Compare Cmp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|unsigned
name|short
name|getSubclassDataFromValue
argument_list|()
specifier|const
block|{
return|return
name|SubclassData
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setValueSubclassData
parameter_list|(
name|unsigned
name|short
name|D
parameter_list|)
block|{
name|SubclassData
operator|=
name|D
expr_stmt|;
block|}
end_function

begin_expr_stmt
unit|};
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|Value
operator|&
name|V
operator|)
block|{
name|V
operator|.
name|print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|void
name|Use
operator|::
name|set
argument_list|(
argument|Value *V
argument_list|)
block|{
if|if
condition|(
name|Val
condition|)
name|removeFromList
argument_list|()
expr_stmt|;
name|Val
operator|=
name|V
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|V
condition|)
name|V
operator|->
name|addUse
argument_list|(
operator|*
name|this
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
unit|}  template
operator|<
name|class
name|Compare
operator|>
name|void
name|Value
operator|::
name|sortUseList
argument_list|(
argument|Compare Cmp
argument_list|)
block|{
if|if
condition|(
operator|!
name|UseList
operator|||
operator|!
name|UseList
operator|->
name|Next
condition|)
comment|// No need to sort 0 or 1 uses.
return|return;
comment|// Note: this function completely ignores Prev pointers until the end when
comment|// they're fixed en masse.
comment|// Create a binomial vector of sorted lists, visiting uses one at a time and
comment|// merging lists as necessary.
specifier|const
name|unsigned
name|MaxSlots
operator|=
literal|32
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|Use
modifier|*
name|Slots
index|[
name|MaxSlots
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Collect the first use, turning it into a single-item list.
end_comment

begin_decl_stmt
name|Use
modifier|*
name|Next
init|=
name|UseList
operator|->
name|Next
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|UseList
operator|->
name|Next
operator|=
name|nullptr
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|unsigned
name|NumSlots
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|Slots
index|[
literal|0
index|]
operator|=
name|UseList
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Collect all but the last use.
end_comment

begin_while
while|while
condition|(
name|Next
operator|->
name|Next
condition|)
block|{
name|Use
modifier|*
name|Current
init|=
name|Next
decl_stmt|;
name|Next
operator|=
name|Current
operator|->
name|Next
expr_stmt|;
comment|// Turn Current into a single-item list.
name|Current
operator|->
name|Next
operator|=
name|nullptr
expr_stmt|;
comment|// Save Current in the first available slot, merging on collisions.
name|unsigned
name|I
decl_stmt|;
for|for
control|(
name|I
operator|=
literal|0
init|;
name|I
operator|<
name|NumSlots
condition|;
operator|++
name|I
control|)
block|{
if|if
condition|(
operator|!
name|Slots
index|[
name|I
index|]
condition|)
break|break;
comment|// Merge two lists, doubling the size of Current and emptying slot I.
comment|//
comment|// Since the uses in Slots[I] originally preceded those in Current, send
comment|// Slots[I] in as the left parameter to maintain a stable sort.
name|Current
operator|=
name|mergeUseLists
argument_list|(
name|Slots
index|[
name|I
index|]
argument_list|,
name|Current
argument_list|,
name|Cmp
argument_list|)
expr_stmt|;
name|Slots
index|[
name|I
index|]
operator|=
name|nullptr
expr_stmt|;
block|}
comment|// Check if this is a new slot.
if|if
condition|(
name|I
operator|==
name|NumSlots
condition|)
block|{
operator|++
name|NumSlots
expr_stmt|;
name|assert
argument_list|(
name|NumSlots
operator|<=
name|MaxSlots
operator|&&
literal|"Use list bigger than 2^32"
argument_list|)
expr_stmt|;
block|}
comment|// Found an open slot.
name|Slots
index|[
name|I
index|]
operator|=
name|Current
expr_stmt|;
block|}
end_while

begin_comment
comment|// Merge all the lists together.
end_comment

begin_expr_stmt
name|assert
argument_list|(
name|Next
operator|&&
literal|"Expected one more Use"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|assert
argument_list|(
operator|!
name|Next
operator|->
name|Next
operator|&&
literal|"Expected only one Use"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|UseList
operator|=
name|Next
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|unsigned
name|I
init|=
literal|0
init|;
name|I
operator|<
name|NumSlots
condition|;
operator|++
name|I
control|)
if|if
condition|(
name|Slots
index|[
name|I
index|]
condition|)
comment|// Since the uses in Slots[I] originally preceded those in UseList, send
comment|// Slots[I] in as the left parameter to maintain a stable sort.
name|UseList
operator|=
name|mergeUseLists
argument_list|(
name|Slots
index|[
name|I
index|]
argument_list|,
name|UseList
argument_list|,
name|Cmp
argument_list|)
expr_stmt|;
end_for

begin_comment
comment|// Fix the Prev pointers.
end_comment

begin_for
for|for
control|(
name|Use
modifier|*
name|I
init|=
name|UseList
init|,
modifier|*
modifier|*
name|Prev
init|=
operator|&
name|UseList
init|;
name|I
condition|;
name|I
operator|=
name|I
operator|->
name|Next
control|)
block|{
name|I
operator|->
name|setPrev
argument_list|(
name|Prev
argument_list|)
expr_stmt|;
name|Prev
operator|=
operator|&
name|I
operator|->
name|Next
expr_stmt|;
block|}
end_for

begin_expr_stmt
unit|}  template
operator|<
name|class
name|Compare
operator|>
name|void
name|Value
operator|::
name|mergeUseListsImpl
argument_list|(
argument|Use *L
argument_list|,
argument|Use *R
argument_list|,
argument|Use **Next
argument_list|,
argument|Compare Cmp
argument_list|)
block|{
if|if
condition|(
operator|!
name|L
condition|)
block|{
operator|*
name|Next
operator|=
name|R
expr_stmt|;
return|return;
block|}
end_expr_stmt

begin_if
if|if
condition|(
operator|!
name|R
condition|)
block|{
operator|*
name|Next
operator|=
name|L
expr_stmt|;
return|return;
block|}
end_if

begin_if
if|if
condition|(
name|Cmp
argument_list|(
operator|*
name|R
argument_list|,
operator|*
name|L
argument_list|)
condition|)
block|{
operator|*
name|Next
operator|=
name|R
expr_stmt|;
name|mergeUseListsImpl
argument_list|(
name|L
argument_list|,
name|R
operator|->
name|Next
argument_list|,
operator|&
name|R
operator|->
name|Next
argument_list|,
name|Cmp
argument_list|)
expr_stmt|;
return|return;
block|}
end_if

begin_expr_stmt
operator|*
name|Next
operator|=
name|L
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|mergeUseListsImpl
argument_list|(
name|L
operator|->
name|Next
argument_list|,
name|R
argument_list|,
operator|&
name|L
operator|->
name|Next
argument_list|,
name|Cmp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// isa - Provide some specializations of isa so that we don't have to include
end_comment

begin_comment
comment|// the subtype header files to test to see if the value is a subclass...
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
unit|template
operator|<
operator|>
expr|struct
name|isa_impl
operator|<
name|Constant
operator|,
name|Value
operator|>
block|{
specifier|static
specifier|inline
name|bool
name|doit
argument_list|(
argument|const Value&Val
argument_list|)
block|{
return|return
name|Val
operator|.
name|getValueID
argument_list|()
operator|>=
name|Value
operator|::
name|ConstantFirstVal
operator|&&
name|Val
operator|.
name|getValueID
argument_list|()
operator|<=
name|Value
operator|::
name|ConstantLastVal
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|isa_impl
operator|<
name|Argument
operator|,
name|Value
operator|>
block|{
specifier|static
specifier|inline
name|bool
name|doit
argument_list|(
argument|const Value&Val
argument_list|)
block|{
return|return
name|Val
operator|.
name|getValueID
argument_list|()
operator|==
name|Value
operator|::
name|ArgumentVal
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|isa_impl
operator|<
name|InlineAsm
operator|,
name|Value
operator|>
block|{
specifier|static
specifier|inline
name|bool
name|doit
argument_list|(
argument|const Value&Val
argument_list|)
block|{
return|return
name|Val
operator|.
name|getValueID
argument_list|()
operator|==
name|Value
operator|::
name|InlineAsmVal
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|isa_impl
operator|<
name|Instruction
operator|,
name|Value
operator|>
block|{
specifier|static
specifier|inline
name|bool
name|doit
argument_list|(
argument|const Value&Val
argument_list|)
block|{
return|return
name|Val
operator|.
name|getValueID
argument_list|()
operator|>=
name|Value
operator|::
name|InstructionVal
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|isa_impl
operator|<
name|BasicBlock
operator|,
name|Value
operator|>
block|{
specifier|static
specifier|inline
name|bool
name|doit
argument_list|(
argument|const Value&Val
argument_list|)
block|{
return|return
name|Val
operator|.
name|getValueID
argument_list|()
operator|==
name|Value
operator|::
name|BasicBlockVal
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|isa_impl
operator|<
name|Function
operator|,
name|Value
operator|>
block|{
specifier|static
specifier|inline
name|bool
name|doit
argument_list|(
argument|const Value&Val
argument_list|)
block|{
return|return
name|Val
operator|.
name|getValueID
argument_list|()
operator|==
name|Value
operator|::
name|FunctionVal
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|isa_impl
operator|<
name|GlobalVariable
operator|,
name|Value
operator|>
block|{
specifier|static
specifier|inline
name|bool
name|doit
argument_list|(
argument|const Value&Val
argument_list|)
block|{
return|return
name|Val
operator|.
name|getValueID
argument_list|()
operator|==
name|Value
operator|::
name|GlobalVariableVal
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|isa_impl
operator|<
name|GlobalAlias
operator|,
name|Value
operator|>
block|{
specifier|static
specifier|inline
name|bool
name|doit
argument_list|(
argument|const Value&Val
argument_list|)
block|{
return|return
name|Val
operator|.
name|getValueID
argument_list|()
operator|==
name|Value
operator|::
name|GlobalAliasVal
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|isa_impl
operator|<
name|GlobalValue
operator|,
name|Value
operator|>
block|{
specifier|static
specifier|inline
name|bool
name|doit
argument_list|(
argument|const Value&Val
argument_list|)
block|{
return|return
name|isa
operator|<
name|GlobalObject
operator|>
operator|(
name|Val
operator|)
operator|||
name|isa
operator|<
name|GlobalAlias
operator|>
operator|(
name|Val
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|isa_impl
operator|<
name|GlobalObject
operator|,
name|Value
operator|>
block|{
specifier|static
specifier|inline
name|bool
name|doit
argument_list|(
argument|const Value&Val
argument_list|)
block|{
return|return
name|isa
operator|<
name|GlobalVariable
operator|>
operator|(
name|Val
operator|)
operator|||
name|isa
operator|<
name|Function
operator|>
operator|(
name|Val
operator|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|// Value* is only 4-byte aligned.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|PointerLikeTypeTraits
operator|<
name|Value
operator|*
operator|>
block|{
typedef|typedef
name|Value
modifier|*
name|PT
typedef|;
name|public
operator|:
specifier|static
specifier|inline
name|void
operator|*
name|getAsVoidPointer
argument_list|(
argument|PT P
argument_list|)
block|{
return|return
name|P
return|;
block|}
specifier|static
specifier|inline
name|PT
name|getFromVoidPointer
argument_list|(
argument|void *P
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|PT
operator|>
operator|(
name|P
operator|)
return|;
block|}
block|enum
block|{
name|NumLowBitsAvailable
operator|=
literal|2
block|}
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Create wrappers for C Binding types (see CBindingWrapping.h).
end_comment

begin_macro
name|DEFINE_ISA_CONVERSION_FUNCTIONS
argument_list|(
argument|Value
argument_list|,
argument|LLVMValueRef
argument_list|)
end_macro

begin_comment
comment|/* Specialized opaque value conversions.  */
end_comment

begin_function
specifier|inline
name|Value
modifier|*
modifier|*
name|unwrap
parameter_list|(
name|LLVMValueRef
modifier|*
name|Vals
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|Value
operator|*
operator|*
operator|>
operator|(
name|Vals
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
operator|*
operator|*
name|unwrap
argument_list|(
argument|LLVMValueRef *Vals
argument_list|,
argument|unsigned Length
argument_list|)
block|{
ifdef|#
directive|ifdef
name|DEBUG
for|for
control|(
name|LLVMValueRef
modifier|*
name|I
init|=
name|Vals
init|,
modifier|*
name|E
init|=
name|Vals
operator|+
name|Length
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
name|cast
operator|<
name|T
operator|>
operator|(
operator|*
name|I
operator|)
expr_stmt|;
endif|#
directive|endif
operator|(
name|void
operator|)
name|Length
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|reinterpret_cast
operator|<
name|T
operator|*
operator|*
operator|>
operator|(
name|Vals
operator|)
return|;
end_return

begin_function
unit|}  inline
name|LLVMValueRef
modifier|*
name|wrap
parameter_list|(
specifier|const
name|Value
modifier|*
modifier|*
name|Vals
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|LLVMValueRef
operator|*
operator|>
operator|(
name|const_cast
operator|<
name|Value
operator|*
operator|*
operator|>
operator|(
name|Vals
operator|)
operator|)
return|;
block|}
end_function

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

