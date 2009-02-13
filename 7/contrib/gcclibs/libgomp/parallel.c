begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 2005 Free Software Foundation, Inc.    Contributed by Richard Henderson<rth@redhat.com>.     This file is part of the GNU OpenMP Library (libgomp).     Libgomp is free software; you can redistribute it and/or modify it    under the terms of the GNU Lesser General Public License as published by    the Free Software Foundation; either version 2.1 of the License, or    (at your option) any later version.     Libgomp is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS    FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for    more details.     You should have received a copy of the GNU Lesser General Public License     along with libgomp; see the file COPYING.LIB.  If not, write to the    Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with other files, some    of which are compiled with GCC, to produce an executable, this library    does not by itself cause the resulting executable to be covered by the    GNU General Public License.  This exception does not however invalidate    any other reasons why the executable file might be covered by the GNU    General Public License.  */
end_comment

begin_comment
comment|/* This file handles the (bare) PARALLEL construct.  */
end_comment

begin_include
include|#
directive|include
file|"libgomp.h"
end_include

begin_comment
comment|/* Determine the number of threads to be launched for a PARALLEL construct.    This algorithm is explicitly described in OpenMP 2.5 section 2.4.1.    SPECIFIED is a combination of the NUM_THREADS clause and the IF clause.    If the IF clause is false, SPECIFIED is forced to 1.  When NUM_THREADS    is not present, SPECIFIED is 0.  */
end_comment

begin_function
name|unsigned
name|gomp_resolve_num_threads
parameter_list|(
name|unsigned
name|specified
parameter_list|)
block|{
comment|/* Early exit for false IF condition or degenerate NUM_THREADS.  */
if|if
condition|(
name|specified
operator|==
literal|1
condition|)
return|return
literal|1
return|;
comment|/* If this is a nested region, and nested regions are disabled, force      this team to use only one thread.  */
if|if
condition|(
name|gomp_thread
argument_list|()
operator|->
name|ts
operator|.
name|team
operator|&&
operator|!
name|gomp_nest_var
condition|)
return|return
literal|1
return|;
comment|/* If NUM_THREADS not specified, use nthreads_var.  */
if|if
condition|(
name|specified
operator|==
literal|0
condition|)
name|specified
operator|=
name|gomp_nthreads_var
expr_stmt|;
comment|/* If dynamic threads are enabled, bound the number of threads      that we launch.  */
if|if
condition|(
name|gomp_dyn_var
condition|)
block|{
name|unsigned
name|dyn
init|=
name|gomp_dynamic_max_threads
argument_list|()
decl_stmt|;
if|if
condition|(
name|dyn
operator|<
name|specified
condition|)
return|return
name|dyn
return|;
block|}
return|return
name|specified
return|;
block|}
end_function

begin_function
name|void
name|GOMP_parallel_start
parameter_list|(
name|void
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|unsigned
name|num_threads
parameter_list|)
block|{
name|num_threads
operator|=
name|gomp_resolve_num_threads
argument_list|(
name|num_threads
argument_list|)
expr_stmt|;
name|gomp_team_start
argument_list|(
name|fn
argument_list|,
name|data
argument_list|,
name|num_threads
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|GOMP_parallel_end
parameter_list|(
name|void
parameter_list|)
block|{
name|gomp_team_end
argument_list|()
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* The public OpenMP API for thread and team related inquiries.  */
end_comment

begin_function
name|int
name|omp_get_num_threads
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|gomp_team
modifier|*
name|team
init|=
name|gomp_thread
argument_list|()
operator|->
name|ts
operator|.
name|team
decl_stmt|;
return|return
name|team
condition|?
name|team
operator|->
name|nthreads
else|:
literal|1
return|;
block|}
end_function

begin_comment
comment|/* ??? Does this function need to disregard dyn_var?  I don't see    how else one could get a useable "maximum".  */
end_comment

begin_function
name|int
name|omp_get_max_threads
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|gomp_resolve_num_threads
argument_list|(
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|omp_get_thread_num
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|gomp_thread
argument_list|()
operator|->
name|ts
operator|.
name|team_id
return|;
block|}
end_function

begin_comment
comment|/* ??? This isn't right.  The definition of this function is false if any    of the IF clauses for any of the parallels is false.  Which is not the    same thing as any outer team having more than one thread.  */
end_comment

begin_function
name|int
name|omp_in_parallel
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|gomp_team
modifier|*
name|team
init|=
name|gomp_thread
argument_list|()
operator|->
name|ts
operator|.
name|team
decl_stmt|;
while|while
condition|(
name|team
condition|)
block|{
if|if
condition|(
name|team
operator|->
name|nthreads
operator|>
literal|1
condition|)
return|return
name|true
return|;
name|team
operator|=
name|team
operator|->
name|prev_ts
operator|.
name|team
expr_stmt|;
block|}
return|return
name|false
return|;
block|}
end_function

begin_macro
name|ialias
argument_list|(
argument|omp_get_num_threads
argument_list|)
end_macro

begin_macro
name|ialias
argument_list|(
argument|omp_get_max_threads
argument_list|)
end_macro

begin_macro
name|ialias
argument_list|(
argument|omp_get_thread_num
argument_list|)
end_macro

begin_macro
name|ialias
argument_list|(
argument|omp_in_parallel
argument_list|)
end_macro

end_unit

