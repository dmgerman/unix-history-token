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
specifier|const
name|char
operator|*
name|Name
block|,
operator|*
name|Desc
block|;
name|T
operator|*
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
specifier|const
name|char
operator|*
name|N
argument_list|,
specifier|const
name|char
operator|*
name|D
argument_list|,
name|T
operator|*
call|(
modifier|*
name|C
call|)
argument_list|()
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
specifier|const
name|char
operator|*
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
specifier|const
name|char
operator|*
name|getDesc
argument_list|()
specifier|const
block|{
return|return
name|Desc
return|;
block|}
name|T
operator|*
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
comment|/// Traits for registry entries. If using other than SimpleRegistryEntry, it
comment|/// is necessary to define an alternate traits class.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|RegistryTraits
block|{
name|RegistryTraits
argument_list|()
block|;
comment|// Do not implement.
name|public
operator|:
typedef|typedef
name|SimpleRegistryEntry
operator|<
name|T
operator|>
name|entry
expr_stmt|;
comment|/// nameof/descof - Accessors for name and description of entries. These are
comment|//                  used to generate help for command-line options.
specifier|static
specifier|const
name|char
operator|*
name|nameof
argument_list|(
argument|const entry&Entry
argument_list|)
block|{
return|return
name|Entry
operator|.
name|getName
argument_list|()
return|;
block|}
specifier|static
specifier|const
name|char
operator|*
name|descof
argument_list|(
argument|const entry&Entry
argument_list|)
block|{
return|return
name|Entry
operator|.
name|getDesc
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
block|,
name|typename
name|U
operator|=
name|RegistryTraits
operator|<
name|T
operator|>
expr|>
name|class
name|Registry
block|{
name|public
operator|:
typedef|typedef
name|U
name|traits
typedef|;
typedef|typedef
name|typename
name|U
operator|::
name|entry
name|entry
expr_stmt|;
name|class
name|node
expr_stmt|;
name|class
name|listener
decl_stmt|;
name|class
name|iterator
decl_stmt|;
name|private
label|:
name|Registry
argument_list|()
expr_stmt|;
comment|// Do not implement.
specifier|static
name|void
name|Announce
parameter_list|(
specifier|const
name|entry
modifier|&
name|E
parameter_list|)
block|{
for|for
control|(
name|listener
modifier|*
name|Cur
init|=
name|ListenerHead
init|;
name|Cur
condition|;
name|Cur
operator|=
name|Cur
operator|->
name|Next
control|)
name|Cur
operator|->
name|registered
argument_list|(
name|E
argument_list|)
expr_stmt|;
block|}
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
name|friend
name|class
name|listener
decl_stmt|;
specifier|static
name|listener
modifier|*
name|ListenerHead
decl_stmt|,
modifier|*
name|ListenerTail
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
literal|0
argument_list|)
operator|,
name|Val
argument_list|(
argument|V
argument_list|)
block|{
if|if
condition|(
name|Tail
condition|)
name|Tail
operator|->
name|Next
operator|=
name|this
expr_stmt|;
else|else
name|Head
operator|=
name|this
expr_stmt|;
name|Tail
operator|=
name|this
expr_stmt|;
name|Announce
argument_list|(
name|V
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Iterators for registry entries.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_function
unit|};
specifier|static
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|iterator
argument_list|(
name|Head
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|iterator
name|end
parameter_list|()
block|{
return|return
name|iterator
argument_list|(
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Abstract base class for registry listeners, which are informed when new
end_comment

begin_comment
comment|/// entries are added to the registry. Simply subclass and instantiate:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   class CollectorPrinter : public Registry<Collector>::listener {
end_comment

begin_comment
comment|///   protected:
end_comment

begin_comment
comment|///     void registered(const Registry<Collector>::entry&e) {
end_comment

begin_comment
comment|///       cerr<< "collector now available: "<< e->getName()<< "\n";
end_comment

begin_comment
comment|///     }
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   public:
end_comment

begin_comment
comment|///     CollectorPrinter() { init(); }  // Print those already registered.
end_comment

begin_comment
comment|///   };
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   CollectorPrinter Printer;
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|listener
block|{
name|listener
modifier|*
name|Prev
decl_stmt|,
modifier|*
name|Next
decl_stmt|;
name|friend
name|void
name|Registry
operator|::
name|Announce
argument_list|(
specifier|const
name|entry
operator|&
name|E
argument_list|)
expr_stmt|;
name|protected
label|:
comment|/// Called when an entry is added to the registry.
comment|///
name|virtual
name|void
name|registered
parameter_list|(
specifier|const
name|entry
modifier|&
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Calls 'registered' for each pre-existing entry.
comment|///
name|void
name|init
parameter_list|()
block|{
for|for
control|(
name|iterator
name|I
init|=
name|begin
argument_list|()
init|,
name|E
init|=
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
name|registered
argument_list|(
operator|*
name|I
argument_list|)
expr_stmt|;
block|}
name|public
label|:
name|listener
argument_list|()
operator|:
name|Prev
argument_list|(
name|ListenerTail
argument_list|)
operator|,
name|Next
argument_list|(
literal|0
argument_list|)
block|{
if|if
condition|(
name|Prev
condition|)
name|Prev
operator|->
name|Next
operator|=
name|this
expr_stmt|;
else|else
name|ListenerHead
operator|=
name|this
expr_stmt|;
name|ListenerTail
operator|=
name|this
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|virtual
operator|~
name|listener
argument_list|()
block|{
if|if
condition|(
name|Next
condition|)
name|Next
operator|->
name|Prev
operator|=
name|Prev
expr_stmt|;
else|else
name|ListenerTail
operator|=
name|Prev
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|Prev
condition|)
name|Prev
operator|->
name|Next
operator|=
name|Next
expr_stmt|;
else|else
name|ListenerHead
operator|=
name|Next
expr_stmt|;
end_if

begin_empty_stmt
unit|}     }
empty_stmt|;
end_empty_stmt

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

begin_comment
comment|//
end_comment

begin_comment
comment|///  2. The registry entry type has a constructor compatible with this
end_comment

begin_comment
comment|///     signature:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///       entry(const char *Name, const char *ShortDesc, T *(*Ctor)());
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If you have more elaborate requirements, then copy and modify.
end_comment

begin_comment
comment|///
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
name|T
operator|*
name|CtorFn
argument_list|()
block|{
return|return
name|new
name|V
argument_list|()
return|;
block|}
name|public
operator|:
name|Add
argument_list|(
specifier|const
name|char
operator|*
name|Name
argument_list|,
specifier|const
name|char
operator|*
name|Desc
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
block|{}
end_expr_stmt

begin_comment
unit|};
comment|/// Registry::Parser now lives in llvm/Support/RegistryParser.h.
end_comment

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
name|typename
name|Registry
operator|<
name|T
operator|,
name|U
operator|>
operator|::
name|node
operator|*
name|Registry
operator|<
name|T
operator|,
name|U
operator|>
operator|::
name|Head
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
name|typename
name|Registry
operator|<
name|T
operator|,
name|U
operator|>
operator|::
name|node
operator|*
name|Registry
operator|<
name|T
operator|,
name|U
operator|>
operator|::
name|Tail
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
name|typename
name|Registry
operator|<
name|T
operator|,
name|U
operator|>
operator|::
name|listener
operator|*
name|Registry
operator|<
name|T
operator|,
name|U
operator|>
operator|::
name|ListenerHead
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
name|typename
name|Registry
operator|<
name|T
operator|,
name|U
operator|>
operator|::
name|listener
operator|*
name|Registry
operator|<
name|T
operator|,
name|U
operator|>
operator|::
name|ListenerTail
expr_stmt|;
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

