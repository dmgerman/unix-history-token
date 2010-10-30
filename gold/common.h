begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// common.h -- handle common symbols for gold   -*- C++ -*-
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOLD_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|GOLD_COMMON_H
end_define

begin_include
include|#
directive|include
file|"workqueue.h"
end_include

begin_decl_stmt
name|namespace
name|gold
block|{
name|class
name|General_options
decl_stmt|;
name|class
name|Symbol_table
decl_stmt|;
comment|// This task is used to allocate the common symbols.
name|class
name|Allocate_commons_task
range|:
name|public
name|Task
block|{
name|public
operator|:
name|Allocate_commons_task
argument_list|(
specifier|const
name|General_options
operator|&
name|options
argument_list|,
name|Symbol_table
operator|*
name|symtab
argument_list|,
name|Layout
operator|*
name|layout
argument_list|,
name|Task_token
operator|*
name|symtab_lock
argument_list|,
name|Task_token
operator|*
name|blocker
argument_list|)
operator|:
name|options_
argument_list|(
name|options
argument_list|)
block|,
name|symtab_
argument_list|(
name|symtab
argument_list|)
block|,
name|layout_
argument_list|(
name|layout
argument_list|)
block|,
name|symtab_lock_
argument_list|(
name|symtab_lock
argument_list|)
block|,
name|blocker_
argument_list|(
argument|blocker
argument_list|)
block|{ }
comment|// The standard Task methods.
name|Is_runnable_type
name|is_runnable
argument_list|(
name|Workqueue
operator|*
argument_list|)
block|;
name|Task_locker
operator|*
name|locks
argument_list|(
name|Workqueue
operator|*
argument_list|)
block|;
name|void
name|run
argument_list|(
name|Workqueue
operator|*
argument_list|)
block|;
name|private
operator|:
name|class
name|Allocate_commons_locker
block|;
specifier|const
name|General_options
operator|&
name|options_
block|;
name|Symbol_table
operator|*
name|symtab_
block|;
name|Layout
operator|*
name|layout_
block|;
name|Task_token
operator|*
name|symtab_lock_
block|;
name|Task_token
operator|*
name|blocker_
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace gold.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GOLD_COMMON_H)
end_comment

end_unit

