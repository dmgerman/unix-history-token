begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/ADT/Statistic.h - Easy way to expose stats ---------*- C++ -*-===//
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
comment|// This file defines the 'Statistic' class, which is designed to be an easy way
end_comment

begin_comment
comment|// to expose various metrics from passes.  These statistics are printed at the
end_comment

begin_comment
comment|// end of a run (from llvm_shutdown), when the -stats command line option is
end_comment

begin_comment
comment|// passed on the command line.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This is useful for reporting information like the number of instructions
end_comment

begin_comment
comment|// simplified, optimized or removed by various transformations, like this:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// static Statistic NumInstsKilled("gcse", "Number of instructions killed");
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Later, in the code: ++NumInstsKilled;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NOTE: Statistics *must* be declared as global variables.
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
name|LLVM_ADT_STATISTIC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_STATISTIC_H
end_define

begin_include
include|#
directive|include
file|"llvm/System/Atomic.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|class
name|Statistic
block|{
name|public
label|:
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
specifier|const
name|char
modifier|*
name|Desc
decl_stmt|;
specifier|volatile
name|llvm
operator|::
name|sys
operator|::
name|cas_flag
name|Value
expr_stmt|;
name|bool
name|Initialized
decl_stmt|;
name|llvm
operator|::
name|sys
operator|::
name|cas_flag
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|Value
return|;
block|}
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
comment|/// construct - This should only be called for non-global statistics.
name|void
name|construct
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|desc
parameter_list|)
block|{
name|Name
operator|=
name|name
expr_stmt|;
name|Desc
operator|=
name|desc
expr_stmt|;
name|Value
operator|=
literal|0
expr_stmt|;
name|Initialized
operator|=
literal|0
expr_stmt|;
block|}
comment|// Allow use of this class as the value itself.
name|operator
name|unsigned
argument_list|()
specifier|const
block|{
return|return
name|Value
return|;
block|}
specifier|const
name|Statistic
modifier|&
name|operator
init|=
operator|(
name|unsigned
name|Val
operator|)
block|{
name|Value
operator|=
name|Val
block|;
return|return
name|init
argument_list|()
return|;
block|}
specifier|const
name|Statistic
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|sys
operator|::
name|AtomicIncrement
argument_list|(
operator|&
name|Value
argument_list|)
block|;
return|return
name|init
argument_list|()
return|;
block|}
name|unsigned
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|init
argument_list|()
block|;
name|unsigned
name|OldValue
operator|=
name|Value
block|;
name|sys
operator|::
name|AtomicIncrement
argument_list|(
operator|&
name|Value
argument_list|)
block|;
return|return
name|OldValue
return|;
block|}
specifier|const
name|Statistic
operator|&
name|operator
operator|--
operator|(
operator|)
block|{
name|sys
operator|::
name|AtomicDecrement
argument_list|(
operator|&
name|Value
argument_list|)
block|;
return|return
name|init
argument_list|()
return|;
block|}
name|unsigned
name|operator
operator|--
operator|(
name|int
operator|)
block|{
name|init
argument_list|()
block|;
name|unsigned
name|OldValue
operator|=
name|Value
block|;
name|sys
operator|::
name|AtomicDecrement
argument_list|(
operator|&
name|Value
argument_list|)
block|;
return|return
name|OldValue
return|;
block|}
specifier|const
name|Statistic
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|unsigned
operator|&
name|V
operator|)
block|{
name|sys
operator|::
name|AtomicAdd
argument_list|(
operator|&
name|Value
argument_list|,
name|V
argument_list|)
block|;
return|return
name|init
argument_list|()
return|;
block|}
specifier|const
name|Statistic
operator|&
name|operator
operator|-=
operator|(
specifier|const
name|unsigned
operator|&
name|V
operator|)
block|{
name|sys
operator|::
name|AtomicAdd
argument_list|(
operator|&
name|Value
argument_list|,
operator|-
name|V
argument_list|)
block|;
return|return
name|init
argument_list|()
return|;
block|}
specifier|const
name|Statistic
operator|&
name|operator
operator|*=
operator|(
specifier|const
name|unsigned
operator|&
name|V
operator|)
block|{
name|sys
operator|::
name|AtomicMul
argument_list|(
operator|&
name|Value
argument_list|,
name|V
argument_list|)
block|;
return|return
name|init
argument_list|()
return|;
block|}
specifier|const
name|Statistic
operator|&
name|operator
operator|/=
operator|(
specifier|const
name|unsigned
operator|&
name|V
operator|)
block|{
name|sys
operator|::
name|AtomicDiv
argument_list|(
operator|&
name|Value
argument_list|,
name|V
argument_list|)
block|;
return|return
name|init
argument_list|()
return|;
block|}
name|protected
label|:
name|Statistic
modifier|&
name|init
parameter_list|()
block|{
name|bool
name|tmp
init|=
name|Initialized
decl_stmt|;
name|sys
operator|::
name|MemoryFence
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|tmp
condition|)
name|RegisterStatistic
argument_list|()
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|void
name|RegisterStatistic
parameter_list|()
function_decl|;
block|}
empty_stmt|;
comment|// STATISTIC - A macro to make definition of statistics really simple.  This
comment|// automatically passes the DEBUG_TYPE of the file into the statistic.
define|#
directive|define
name|STATISTIC
parameter_list|(
name|VARNAME
parameter_list|,
name|DESC
parameter_list|)
define|\
value|static llvm::Statistic VARNAME = { DEBUG_TYPE, DESC, 0, 0 }
comment|/// \brief Enable the collection and printing of statistics.
name|void
name|EnableStatistics
parameter_list|()
function_decl|;
comment|/// \brief Print statistics to the file returned by CreateInfoOutputFile().
name|void
name|PrintStatistics
parameter_list|()
function_decl|;
comment|/// \brief Print statistics to the given output stream.
name|void
name|PrintStatistics
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

