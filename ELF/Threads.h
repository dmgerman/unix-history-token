begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Threads.h ------------------------------------------------*- C++ -*-===//
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
comment|//
end_comment

begin_comment
comment|// LLD supports threads to distribute workloads to multiple cores. Using
end_comment

begin_comment
comment|// multicore is most effective when more than one core are idle. At the
end_comment

begin_comment
comment|// last step of a build, it is often the case that a linker is the only
end_comment

begin_comment
comment|// active process on a computer. So, we are naturally interested in using
end_comment

begin_comment
comment|// threads wisely to reduce latency to deliver results to users.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// That said, we don't want to do "too clever" things using threads.
end_comment

begin_comment
comment|// Complex multi-threaded algorithms are sometimes extremely hard to
end_comment

begin_comment
comment|// reason about and can easily mess up the entire design.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Fortunately, when a linker links large programs (when the link time is
end_comment

begin_comment
comment|// most critical), it spends most of the time to work on massive number of
end_comment

begin_comment
comment|// small pieces of data of the same kind, and there are opportunities for
end_comment

begin_comment
comment|// large parallelism there. Here are examples:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  - We have hundreds of thousands of input sections that need to be
end_comment

begin_comment
comment|//    copied to a result file at the last step of link. Once we fix a file
end_comment

begin_comment
comment|//    layout, each section can be copied to its destination and its
end_comment

begin_comment
comment|//    relocations can be applied independently.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  - We have tens of millions of small strings when constructing a
end_comment

begin_comment
comment|//    mergeable string section.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For the cases such as the former, we can just use parallel_for_each
end_comment

begin_comment
comment|// instead of std::for_each (or a plain for loop). Because tasks are
end_comment

begin_comment
comment|// completely independent from each other, we can run them in parallel
end_comment

begin_comment
comment|// without any coordination between them. That's very easy to understand
end_comment

begin_comment
comment|// and reason about.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For the cases such as the latter, we can use parallel algorithms to
end_comment

begin_comment
comment|// deal with massive data. We have to write code for a tailored algorithm
end_comment

begin_comment
comment|// for each problem, but the complexity of multi-threading is isolated in
end_comment

begin_comment
comment|// a single pass and doesn't affect the linker's overall design.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The above approach seems to be working fairly well. As an example, when
end_comment

begin_comment
comment|// linking Chromium (output size 1.6 GB), using 4 cores reduces latency to
end_comment

begin_comment
comment|// 75% compared to single core (from 12.66 seconds to 9.55 seconds) on my
end_comment

begin_comment
comment|// Ivy Bridge Xeon 2.8 GHz machine. Using 40 cores reduces it to 63% (from
end_comment

begin_comment
comment|// 12.66 seconds to 7.95 seconds). Because of the Amdahl's law, the
end_comment

begin_comment
comment|// speedup is not linear, but as you add more cores, it gets faster.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// On a final note, if you are trying to optimize, keep the axiom "don't
end_comment

begin_comment
comment|// guess, measure!" in mind. Some important passes of the linker are not
end_comment

begin_comment
comment|// that slow. For example, resolving all symbols is not a very heavy pass,
end_comment

begin_comment
comment|// although it would be very hard to parallelize it. You want to first
end_comment

begin_comment
comment|// identify a slow pass and then optimize it.
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
name|LLD_ELF_THREADS_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_ELF_THREADS_H
end_define

begin_include
include|#
directive|include
file|"Config.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Parallel.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
name|template
operator|<
name|class
name|IterTy
operator|,
name|class
name|FuncTy
operator|>
name|void
name|parallelForEach
argument_list|(
argument|IterTy Begin
argument_list|,
argument|IterTy End
argument_list|,
argument|FuncTy Fn
argument_list|)
block|{
if|if
condition|(
name|Config
operator|->
name|Threads
condition|)
name|parallel_for_each
argument_list|(
name|Begin
argument_list|,
name|End
argument_list|,
name|Fn
argument_list|)
expr_stmt|;
else|else
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
expr_stmt|;
block|}
specifier|inline
name|void
name|parallelFor
argument_list|(
name|size_t
name|Begin
argument_list|,
name|size_t
name|End
argument_list|,
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|size_t
argument_list|)
operator|>
name|Fn
argument_list|)
block|{
if|if
condition|(
name|Config
operator|->
name|Threads
condition|)
block|{
name|parallel_for
argument_list|(
name|Begin
argument_list|,
name|End
argument_list|,
name|Fn
argument_list|)
expr_stmt|;
block|}
else|else
block|{
for|for
control|(
name|size_t
name|I
init|=
name|Begin
init|;
name|I
operator|<
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
block|}
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

