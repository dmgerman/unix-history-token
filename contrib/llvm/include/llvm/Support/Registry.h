begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=== Registry.h - Linker-supported plugin registries -----------*- C++ -*-===//
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
comment|// Defines a registry template for discovering pluggable modules.
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
name|LLVM_SUPPORT_REGISTRY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_REGISTRY_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DynamicLibrary.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// A simple registry entry which provides only a name, description, and
comment|/// no-argument constructor.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SimpleRegistryEntry
block|{
name|StringRef
name|Name
block|,
name|Desc
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|T
operator|>
call|(
modifier|*
name|Ctor
call|)
argument_list|()
block|;
name|public
operator|:
name|SimpleRegistryEntry
argument_list|(
argument|StringRef N
argument_list|,
argument|StringRef D
argument_list|,
argument|std::unique_ptr<T> (*C)()
argument_list|)
operator|:
name|Name
argument_list|(
name|N
argument_list|)
block|,
name|Desc
argument_list|(
name|D
argument_list|)
block|,
name|Ctor
argument_list|(
argument|C
argument_list|)
block|{}
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
name|StringRef
name|getDesc
argument_list|()
specifier|const
block|{
return|return
name|Desc
return|;
block|}
name|std
operator|::
name|unique_ptr
operator|<
name|T
operator|>
name|instantiate
argument_list|()
specifier|const
block|{
return|return
name|Ctor
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// A global registry used in conjunction with static constructors to make
comment|/// pluggable components (like targets or garbage collectors) "just work" when
comment|/// linked with an executable.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|Registry
block|{
name|public
operator|:
typedef|typedef
name|T
name|type
typedef|;
typedef|typedef
name|SimpleRegistryEntry
operator|<
name|T
operator|>
name|entry
expr_stmt|;
name|class
name|node
expr_stmt|;
name|class
name|iterator
decl_stmt|;
name|private
label|:
name|Registry
argument_list|()
operator|=
name|delete
expr_stmt|;
name|friend
name|class
name|node
decl_stmt|;
specifier|static
name|node
modifier|*
name|Head
decl_stmt|,
modifier|*
name|Tail
decl_stmt|;
name|public
label|:
comment|/// Node in linked list of entries.
comment|///
name|class
name|node
block|{
name|friend
name|class
name|iterator
decl_stmt|;
name|friend
name|Registry
operator|<
name|T
operator|>
expr_stmt|;
name|node
modifier|*
name|Next
decl_stmt|;
specifier|const
name|entry
modifier|&
name|Val
decl_stmt|;
name|public
label|:
name|node
argument_list|(
specifier|const
name|entry
operator|&
name|V
argument_list|)
operator|:
name|Next
argument_list|(
name|nullptr
argument_list|)
operator|,
name|Val
argument_list|(
argument|V
argument_list|)
block|{}
block|}
empty_stmt|;
comment|/// Add a node to the Registry: this is the interface between the plugin and
comment|/// the executable.
comment|///
comment|/// This function is exported by the executable and called by the plugin to
comment|/// add a node to the executable's registry. Therefore it's not defined here
comment|/// to avoid it being instantiated in the plugin and is instead defined in
comment|/// the executable (see LLVM_INSTANTIATE_REGISTRY below).
specifier|static
name|void
name|add_node
parameter_list|(
name|node
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// Iterators for registry entries.
comment|///
name|class
name|iterator
block|{
specifier|const
name|node
modifier|*
name|Cur
decl_stmt|;
name|public
label|:
name|explicit
name|iterator
argument_list|(
specifier|const
name|node
operator|*
name|N
argument_list|)
operator|:
name|Cur
argument_list|(
argument|N
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|iterator
operator|&
name|That
operator|)
specifier|const
block|{
return|return
name|Cur
operator|==
name|That
operator|.
name|Cur
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|iterator
operator|&
name|That
operator|)
specifier|const
block|{
return|return
name|Cur
operator|!=
name|That
operator|.
name|Cur
return|;
block|}
name|iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|Cur
operator|=
name|Cur
operator|->
name|Next
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|const
name|entry
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|Cur
operator|->
name|Val
return|;
block|}
specifier|const
name|entry
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
operator|&
name|Cur
operator|->
name|Val
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// begin is not defined here in order to avoid usage of an undefined static
end_comment

begin_comment
comment|// data member, instead it's instantiated by LLVM_INSTANTIATE_REGISTRY.
end_comment

begin_function_decl
specifier|static
name|iterator
name|begin
parameter_list|()
function_decl|;
end_function_decl

begin_function
specifier|static
name|iterator
name|end
parameter_list|()
block|{
return|return
name|iterator
argument_list|(
name|nullptr
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
specifier|static
name|iterator_range
operator|<
name|iterator
operator|>
name|entries
argument_list|()
block|{
return|return
name|make_range
argument_list|(
name|begin
argument_list|()
argument_list|,
name|end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// A static registration template. Use like such:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   Registry<Collector>::Add<FancyGC>
end_comment

begin_comment
comment|///   X("fancy-gc", "Newfangled garbage collector.");
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Use of this template requires that:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///  1. The registered subclass has a default constructor.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|V
operator|>
name|class
name|Add
block|{
name|entry
name|Entry
block|;
name|node
name|Node
block|;
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|T
operator|>
name|CtorFn
argument_list|()
block|{
return|return
name|make_unique
operator|<
name|V
operator|>
operator|(
operator|)
return|;
block|}
name|public
operator|:
name|Add
argument_list|(
argument|StringRef Name
argument_list|,
argument|StringRef Desc
argument_list|)
operator|:
name|Entry
argument_list|(
name|Name
argument_list|,
name|Desc
argument_list|,
name|CtorFn
argument_list|)
operator|,
name|Node
argument_list|(
argument|Entry
argument_list|)
block|{
name|add_node
argument_list|(
operator|&
name|Node
argument_list|)
block|;       }
end_expr_stmt

begin_comment
unit|};   }; }
comment|// end namespace llvm
end_comment

begin_comment
comment|/// Instantiate a registry class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This provides template definitions of add_node, begin, and the Head and Tail
end_comment

begin_comment
comment|/// pointers, then explicitly instantiates them. We could explicitly specialize
end_comment

begin_comment
comment|/// them, instead of the two-step process of define then instantiate, but
end_comment

begin_comment
comment|/// strictly speaking that's not allowed by the C++ standard (we would need to
end_comment

begin_comment
comment|/// have explicit specialization declarations in all translation units where the
end_comment

begin_comment
comment|/// specialization is used) so we don't.
end_comment

begin_define
define|#
directive|define
name|LLVM_INSTANTIATE_REGISTRY
parameter_list|(
name|REGISTRY_CLASS
parameter_list|)
define|\
value|namespace llvm { \   template<typename T> typename Registry<T>::node *Registry<T>::Head = nullptr;\   template<typename T> typename Registry<T>::node *Registry<T>::Tail = nullptr;\   template<typename T> \   void Registry<T>::add_node(typename Registry<T>::node *N) { \     if (Tail) \       Tail->Next = N; \     else \       Head = N; \     Tail = N; \   } \   template<typename T> typename Registry<T>::iterator Registry<T>::begin() { \     return iterator(Head); \   } \   template REGISTRY_CLASS::node *Registry<REGISTRY_CLASS::type>::Head; \   template REGISTRY_CLASS::node *Registry<REGISTRY_CLASS::type>::Tail; \   template \   void Registry<REGISTRY_CLASS::type>::add_node(REGISTRY_CLASS::node*); \   template REGISTRY_CLASS::iterator Registry<REGISTRY_CLASS::type>::begin(); \   }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_REGISTRY_H
end_comment

end_unit

