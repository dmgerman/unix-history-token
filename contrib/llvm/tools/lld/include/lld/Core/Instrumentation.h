begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- include/Core/Instrumentation.h - Instrumentation API ---------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Provide an Instrumentation API that optionally uses VTune interfaces.
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
name|LLD_CORE_INSTRUMENTATION_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_CORE_INSTRUMENTATION_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|LLD_HAS_VTUNE
end_ifdef

begin_include
include|#
directive|include
file|<ittnotify.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|lld
block|{
ifdef|#
directive|ifdef
name|LLD_HAS_VTUNE
comment|/// \brief A unique global scope for instrumentation data.
comment|///
comment|/// Domains last for the lifetime of the application and cannot be destroyed.
comment|/// Multiple Domains created with the same name represent the same domain.
name|class
name|Domain
block|{
name|__itt_domain
modifier|*
name|_domain
decl_stmt|;
name|public
label|:
name|explicit
name|Domain
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
operator|:
name|_domain
argument_list|(
argument|__itt_domain_createA(name)
argument_list|)
block|{}
name|operator
name|__itt_domain
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|_domain
return|;
block|}
name|__itt_domain
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|_domain
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief A global reference to a string constant.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These are uniqued by the ITT runtime and cannot be deleted. They are not
end_comment

begin_comment
comment|/// specific to a domain.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Prefer reusing a single StringHandle over passing a ntbs when the same
end_comment

begin_comment
comment|/// string will be used often.
end_comment

begin_decl_stmt
name|class
name|StringHandle
block|{
name|__itt_string_handle
modifier|*
name|_handle
decl_stmt|;
name|public
label|:
name|StringHandle
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
operator|:
name|_handle
argument_list|(
argument|__itt_string_handle_createA(name)
argument_list|)
block|{}
name|operator
name|__itt_string_handle
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|_handle
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief A task on a single thread. Nests within other tasks.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Each thread has its own task stack and tasks nest recursively on that stack.
end_comment

begin_comment
comment|/// A task cannot transfer threads.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// SBRM is used to ensure task starts and ends are ballanced. The lifetime of
end_comment

begin_comment
comment|/// a task is either the lifetime of this object, or until end is called.
end_comment

begin_decl_stmt
name|class
name|ScopedTask
block|{
name|__itt_domain
modifier|*
name|_domain
decl_stmt|;
name|ScopedTask
argument_list|(
specifier|const
name|ScopedTask
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|ScopedTask
modifier|&
name|operator
init|=
operator|(
specifier|const
name|ScopedTask
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|public
label|:
comment|/// \brief Create a task in Domain \p d named \p s.
name|ScopedTask
argument_list|(
specifier|const
name|Domain
operator|&
name|d
argument_list|,
specifier|const
name|StringHandle
operator|&
name|s
argument_list|)
operator|:
name|_domain
argument_list|(
argument|d
argument_list|)
block|{
name|__itt_task_begin
argument_list|(
name|d
argument_list|,
name|__itt_null
argument_list|,
name|__itt_null
argument_list|,
name|s
argument_list|)
block|;   }
name|ScopedTask
argument_list|(
argument|ScopedTask&&other
argument_list|)
block|{
operator|*
name|this
operator|=
name|std
operator|::
name|move
argument_list|(
name|other
argument_list|)
block|;   }
name|ScopedTask
operator|&
name|operator
operator|=
operator|(
name|ScopedTask
operator|&&
name|other
operator|)
block|{
name|_domain
operator|=
name|other
operator|.
name|_domain
block|;
name|other
operator|.
name|_domain
operator|=
name|nullptr
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief Prematurely end this task.
name|void
name|end
parameter_list|()
block|{
if|if
condition|(
name|_domain
condition|)
name|__itt_task_end
argument_list|(
name|_domain
argument_list|)
expr_stmt|;
name|_domain
operator|=
name|nullptr
expr_stmt|;
block|}
operator|~
name|ScopedTask
argument_list|()
block|{
name|end
argument_list|()
block|; }
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief A specific point in time. Allows metadata to be associated.
end_comment

begin_decl_stmt
name|class
name|Marker
block|{
name|public
label|:
name|Marker
argument_list|(
argument|const Domain&d
argument_list|,
argument|const StringHandle&s
argument_list|)
block|{
name|__itt_marker
argument_list|(
name|d
argument_list|,
name|__itt_null
argument_list|,
name|s
argument_list|,
name|__itt_scope_global
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|class
name|Domain
block|{
name|public
label|:
name|Domain
argument_list|(
argument|const char *name
argument_list|)
block|{}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|StringHandle
block|{
name|public
label|:
name|StringHandle
argument_list|(
argument|const char *name
argument_list|)
block|{}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|ScopedTask
block|{
name|public
label|:
name|ScopedTask
argument_list|(
argument|const Domain&d
argument_list|,
argument|const StringHandle&s
argument_list|)
block|{}
name|void
name|end
parameter_list|()
block|{}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|Marker
block|{
name|public
label|:
name|Marker
argument_list|(
argument|const Domain&d
argument_list|,
argument|const StringHandle&s
argument_list|)
block|{}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|inline
specifier|const
name|Domain
modifier|&
name|getDefaultDomain
parameter_list|()
block|{
specifier|static
name|Domain
name|domain
argument_list|(
literal|"org.llvm.lld"
argument_list|)
decl_stmt|;
return|return
name|domain
return|;
block|}
end_function

begin_comment
unit|}
comment|// end namespace lld.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

