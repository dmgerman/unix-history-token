begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lld/Core/Parallel.h - Parallel utilities ---------------------------===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLD_CORE_PARALLEL_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_CORE_PARALLEL_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/TaskGroup.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MathExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Config/llvm-config.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|LLVM_ENABLE_THREADS
end_if

begin_include
include|#
directive|include
file|<concrt.h>
end_include

begin_include
include|#
directive|include
file|<ppl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|lld
block|{
if|#
directive|if
operator|!
name|LLVM_ENABLE_THREADS
name|template
operator|<
name|class
name|RandomAccessIterator
operator|,
name|class
name|Comparator
operator|>
name|void
name|parallel_sort
argument_list|(
argument|RandomAccessIterator Start
argument_list|,
argument|RandomAccessIterator End
argument_list|,
argument|const Comparator&Comp = std::less<         typename std::iterator_traits<RandomAccessIterator>::value_type>()
argument_list|)
block|{
name|std
operator|::
name|sort
argument_list|(
name|Start
argument_list|,
name|End
argument_list|,
name|Comp
argument_list|)
block|; }
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
comment|// Use ppl parallel_sort on Windows.
name|template
operator|<
name|class
name|RandomAccessIterator
operator|,
name|class
name|Comparator
operator|>
name|void
name|parallel_sort
argument_list|(
argument|RandomAccessIterator Start
argument_list|,
argument|RandomAccessIterator End
argument_list|,
argument|const Comparator&Comp = std::less<         typename std::iterator_traits<RandomAccessIterator>::value_type>()
argument_list|)
block|{
name|concurrency
operator|::
name|parallel_sort
argument_list|(
name|Start
argument_list|,
name|End
argument_list|,
name|Comp
argument_list|)
block|; }
else|#
directive|else
name|namespace
name|detail
block|{
specifier|const
name|ptrdiff_t
name|MinParallelSize
operator|=
literal|1024
block|;
comment|/// \brief Inclusive median.
name|template
operator|<
name|class
name|RandomAccessIterator
block|,
name|class
name|Comparator
operator|>
name|RandomAccessIterator
name|medianOf3
argument_list|(
argument|RandomAccessIterator Start
argument_list|,
argument|RandomAccessIterator End
argument_list|,
argument|const Comparator&Comp
argument_list|)
block|{
name|RandomAccessIterator
name|Mid
operator|=
name|Start
operator|+
operator|(
name|std
operator|::
name|distance
argument_list|(
name|Start
argument_list|,
name|End
argument_list|)
operator|/
literal|2
operator|)
block|;
return|return
name|Comp
argument_list|(
operator|*
name|Start
argument_list|,
operator|*
operator|(
name|End
operator|-
literal|1
operator|)
argument_list|)
condition|?
operator|(
name|Comp
argument_list|(
operator|*
name|Mid
argument_list|,
operator|*
operator|(
name|End
operator|-
literal|1
operator|)
argument_list|)
condition|?
operator|(
name|Comp
argument_list|(
operator|*
name|Start
argument_list|,
operator|*
name|Mid
argument_list|)
condition|?
name|Mid
else|:
name|Start
operator|)
else|:
name|End
operator|-
literal|1
operator|)
else|:
operator|(
name|Comp
argument_list|(
operator|*
name|Mid
argument_list|,
operator|*
name|Start
argument_list|)
condition|?
operator|(
name|Comp
argument_list|(
operator|*
operator|(
name|End
operator|-
literal|1
operator|)
argument_list|,
operator|*
name|Mid
argument_list|)
condition|?
name|Mid
else|:
name|End
operator|-
literal|1
operator|)
else|:
name|Start
operator|)
return|;
block|}
name|template
operator|<
name|class
name|RandomAccessIterator
block|,
name|class
name|Comparator
operator|>
name|void
name|parallel_quick_sort
argument_list|(
argument|RandomAccessIterator Start
argument_list|,
argument|RandomAccessIterator End
argument_list|,
argument|const Comparator&Comp
argument_list|,
argument|TaskGroup&TG
argument_list|,
argument|size_t Depth
argument_list|)
block|{
comment|// Do a sequential sort for small inputs.
if|if
condition|(
name|std
operator|::
name|distance
argument_list|(
name|Start
argument_list|,
name|End
argument_list|)
operator|<
name|detail
operator|::
name|MinParallelSize
operator|||
name|Depth
operator|==
literal|0
condition|)
block|{
name|std
operator|::
name|sort
argument_list|(
name|Start
argument_list|,
name|End
argument_list|,
name|Comp
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// Partition.
name|auto
name|Pivot
init|=
name|medianOf3
argument_list|(
name|Start
argument_list|,
name|End
argument_list|,
name|Comp
argument_list|)
decl_stmt|;
comment|// Move Pivot to End.
name|std
operator|::
name|swap
argument_list|(
operator|*
operator|(
name|End
operator|-
literal|1
operator|)
argument_list|,
operator|*
name|Pivot
argument_list|)
block|;
name|Pivot
operator|=
name|std
operator|::
name|partition
argument_list|(
name|Start
argument_list|,
name|End
operator|-
literal|1
argument_list|,
index|[
operator|&
name|Comp
operator|,
name|End
index|]
operator|(
name|decltype
argument_list|(
argument|*Start
argument_list|)
name|V
operator|)
block|{
return|return
name|Comp
argument_list|(
name|V
argument_list|,
operator|*
operator|(
name|End
operator|-
literal|1
operator|)
argument_list|)
return|;
block|}
argument_list|)
block|;
comment|// Move Pivot to middle of partition.
name|std
operator|::
name|swap
argument_list|(
operator|*
name|Pivot
argument_list|,
operator|*
operator|(
name|End
operator|-
literal|1
operator|)
argument_list|)
block|;
comment|// Recurse.
name|TG
operator|.
name|spawn
argument_list|(
index|[
operator|=
operator|,
operator|&
name|Comp
operator|,
operator|&
name|TG
index|]
block|{
name|parallel_quick_sort
argument_list|(
name|Start
argument_list|,
name|Pivot
argument_list|,
name|Comp
argument_list|,
name|TG
argument_list|,
name|Depth
operator|-
literal|1
argument_list|)
block|;   }
argument_list|)
block|;
name|parallel_quick_sort
argument_list|(
name|Pivot
operator|+
literal|1
argument_list|,
name|End
argument_list|,
name|Comp
argument_list|,
name|TG
argument_list|,
name|Depth
operator|-
literal|1
argument_list|)
block|; }
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|RandomAccessIterator
operator|,
name|class
name|Comparator
operator|>
name|void
name|parallel_sort
argument_list|(
argument|RandomAccessIterator Start
argument_list|,
argument|RandomAccessIterator End
argument_list|,
argument|const Comparator&Comp = std::less<         typename std::iterator_traits<RandomAccessIterator>::value_type>()
argument_list|)
block|{
name|TaskGroup
name|TG
block|;
name|detail
operator|::
name|parallel_quick_sort
argument_list|(
name|Start
argument_list|,
name|End
argument_list|,
name|Comp
argument_list|,
name|TG
argument_list|,
name|llvm
operator|::
name|Log2_64
argument_list|(
name|std
operator|::
name|distance
argument_list|(
name|Start
argument_list|,
name|End
argument_list|)
argument_list|)
operator|+
literal|1
argument_list|)
block|; }
endif|#
directive|endif
name|template
operator|<
name|class
name|T
operator|>
name|void
name|parallel_sort
argument_list|(
argument|T *Start
argument_list|,
argument|T *End
argument_list|)
block|{
name|parallel_sort
argument_list|(
name|Start
argument_list|,
name|End
argument_list|,
name|std
operator|::
name|less
operator|<
name|T
operator|>
operator|(
operator|)
argument_list|)
block|; }
if|#
directive|if
operator|!
name|LLVM_ENABLE_THREADS
name|template
operator|<
name|class
name|IterTy
operator|,
name|class
name|FuncTy
operator|>
name|void
name|parallel_for_each
argument_list|(
argument|IterTy Begin
argument_list|,
argument|IterTy End
argument_list|,
argument|FuncTy Fn
argument_list|)
block|{
name|std
operator|::
name|for_each
argument_list|(
name|Begin
argument_list|,
name|End
argument_list|,
name|Fn
argument_list|)
block|; }
name|template
operator|<
name|class
name|IndexTy
operator|,
name|class
name|FuncTy
operator|>
name|void
name|parallel_for
argument_list|(
argument|IndexTy Begin
argument_list|,
argument|IndexTy End
argument_list|,
argument|FuncTy Fn
argument_list|)
block|{
for|for
control|(
name|IndexTy
name|I
init|=
name|Begin
init|;
name|I
operator|!=
name|End
condition|;
operator|++
name|I
control|)
name|Fn
argument_list|(
name|I
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif

begin_comment
comment|// Use ppl parallel_for_each on Windows.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|IterTy
operator|,
name|class
name|FuncTy
operator|>
name|void
name|parallel_for_each
argument_list|(
argument|IterTy Begin
argument_list|,
argument|IterTy End
argument_list|,
argument|FuncTy Fn
argument_list|)
block|{
name|concurrency
operator|::
name|parallel_for_each
argument_list|(
name|Begin
argument_list|,
name|End
argument_list|,
name|Fn
argument_list|)
block|; }
name|template
operator|<
name|class
name|IndexTy
operator|,
name|class
name|FuncTy
operator|>
name|void
name|parallel_for
argument_list|(
argument|IndexTy Begin
argument_list|,
argument|IndexTy End
argument_list|,
argument|FuncTy Fn
argument_list|)
block|{
name|concurrency
operator|::
name|parallel_for
argument_list|(
name|Begin
argument_list|,
name|End
argument_list|,
name|Fn
argument_list|)
block|; }
else|#
directive|else
name|template
operator|<
name|class
name|IterTy
operator|,
name|class
name|FuncTy
operator|>
name|void
name|parallel_for_each
argument_list|(
argument|IterTy Begin
argument_list|,
argument|IterTy End
argument_list|,
argument|FuncTy Fn
argument_list|)
block|{
comment|// TaskGroup has a relatively high overhead, so we want to reduce
comment|// the number of spawn() calls. We'll create up to 1024 tasks here.
comment|// (Note that 1024 is an arbitrary number. This code probably needs
comment|// improving to take the number of available cores into account.)
name|ptrdiff_t
name|TaskSize
operator|=
name|std
operator|::
name|distance
argument_list|(
name|Begin
argument_list|,
name|End
argument_list|)
operator|/
literal|1024
block|;
if|if
condition|(
name|TaskSize
operator|==
literal|0
condition|)
name|TaskSize
operator|=
literal|1
expr_stmt|;
name|TaskGroup
name|TG
expr_stmt|;
end_expr_stmt

begin_while
while|while
condition|(
name|TaskSize
operator|<=
name|std
operator|::
name|distance
argument_list|(
name|Begin
argument_list|,
name|End
argument_list|)
condition|)
block|{
name|TG
operator|.
name|spawn
argument_list|(
index|[
operator|=
operator|,
operator|&
name|Fn
index|]
block|{
name|std
operator|::
name|for_each
argument_list|(
name|Begin
argument_list|,
name|Begin
operator|+
name|TaskSize
argument_list|,
name|Fn
argument_list|)
block|; }
argument_list|)
expr_stmt|;
name|Begin
operator|+=
name|TaskSize
expr_stmt|;
block|}
end_while

begin_expr_stmt
name|TG
operator|.
name|spawn
argument_list|(
index|[
operator|=
operator|,
operator|&
name|Fn
index|]
block|{
name|std
operator|::
name|for_each
argument_list|(
name|Begin
argument_list|,
name|End
argument_list|,
name|Fn
argument_list|)
block|; }
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|class
name|IndexTy
operator|,
name|class
name|FuncTy
operator|>
name|void
name|parallel_for
argument_list|(
argument|IndexTy Begin
argument_list|,
argument|IndexTy End
argument_list|,
argument|FuncTy Fn
argument_list|)
block|{
name|ptrdiff_t
name|TaskSize
operator|=
operator|(
name|End
operator|-
name|Begin
operator|)
operator|/
literal|1024
block|;
if|if
condition|(
name|TaskSize
operator|==
literal|0
condition|)
name|TaskSize
operator|=
literal|1
expr_stmt|;
name|TaskGroup
name|TG
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|IndexTy
name|I
init|=
name|Begin
decl_stmt|;
end_decl_stmt

begin_for
for|for
control|(
init|;
name|I
operator|+
name|TaskSize
operator|<
name|End
condition|;
name|I
operator|+=
name|TaskSize
control|)
block|{
name|TG
operator|.
name|spawn
argument_list|(
index|[
operator|=
operator|,
operator|&
name|Fn
index|]
block|{
for|for
control|(
name|IndexTy
name|J
init|=
name|I
init|,
name|E
init|=
name|I
operator|+
name|TaskSize
init|;
name|J
operator|!=
name|E
condition|;
operator|++
name|J
control|)
name|Fn
argument_list|(
name|J
argument_list|)
expr_stmt|;
block|}
block|)
empty_stmt|;
end_for

begin_expr_stmt
unit|}   TG
operator|.
name|spawn
argument_list|(
index|[
operator|=
operator|,
operator|&
name|Fn
index|]
block|{
for|for
control|(
name|IndexTy
name|J
init|=
name|I
init|;
name|J
operator|<
name|End
condition|;
operator|++
name|J
control|)
name|Fn
argument_list|(
name|J
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
unit|}
comment|// End namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_CORE_PARALLEL_H
end_comment

end_unit

