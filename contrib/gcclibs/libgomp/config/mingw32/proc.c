begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 2007 Free Software Foundation, Inc.    Contributed by Danny Smith<dannysmith@users.sourceforge.net>     This file is part of the GNU OpenMP Library (libgomp).     Libgomp is free software; you can redistribute it and/or modify it    under the terms of the GNU Lesser General Public License as published by    the Free Software Foundation; either version 2.1 of the License, or    (at your option) any later version.     Libgomp is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS    FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for    more details.     You should have received a copy of the GNU Lesser General Public License     along with libgomp; see the file COPYING.LIB.  If not, write to the    Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with other files, some    of which are compiled with GCC, to produce an executable, this library    does not by itself cause the resulting executable to be covered by the    GNU General Public License.  This exception does not however invalidate    any other reasons why the executable file might be covered by the GNU    General Public License.  */
end_comment

begin_comment
comment|/* This file contains system specific routines related to counting    online processors and dynamic load balancing.  It is expected that    a system may well want to write special versions of each of these.     The following implementation uses win32 API routines.  */
end_comment

begin_include
include|#
directive|include
file|"libgomp.h"
end_include

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_comment
comment|/* Count the CPU's currently available to this process.  */
end_comment

begin_function
specifier|static
name|int
name|count_avail_process_cpus
parameter_list|()
block|{
name|DWORD_PTR
name|process_cpus
decl_stmt|;
name|DWORD_PTR
name|system_cpus
decl_stmt|;
if|if
condition|(
name|GetProcessAffinityMask
argument_list|(
name|GetCurrentProcess
argument_list|()
argument_list|,
operator|&
name|process_cpus
argument_list|,
operator|&
name|system_cpus
argument_list|)
condition|)
block|{
name|unsigned
name|int
name|count
decl_stmt|;
for|for
control|(
name|count
operator|=
literal|0
init|;
name|process_cpus
operator|!=
literal|0
condition|;
name|process_cpus
operator|>>=
literal|1
control|)
if|if
condition|(
name|process_cpus
operator|&
literal|1
condition|)
name|count
operator|++
expr_stmt|;
return|return
name|count
return|;
block|}
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/* At startup, determine the default number of threads.  It would seem    this should be related to the number of cpus available to the process.  */
end_comment

begin_function
name|void
name|gomp_init_num_threads
parameter_list|(
name|void
parameter_list|)
block|{
name|gomp_nthreads_var
operator|=
name|count_avail_process_cpus
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* When OMP_DYNAMIC is set, at thread launch determine the number of    threads we should spawn for this team.  FIXME:  How do we adjust for    load average on MS Windows?  */
end_comment

begin_function
name|unsigned
name|gomp_dynamic_max_threads
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|n_onln
init|=
name|count_avail_process_cpus
argument_list|()
decl_stmt|;
return|return
name|n_onln
operator|>
name|gomp_nthreads_var
condition|?
name|gomp_nthreads_var
else|:
name|n_onln
return|;
block|}
end_function

begin_function
name|int
name|omp_get_num_procs
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|count_avail_process_cpus
argument_list|()
return|;
block|}
end_function

begin_macro
name|ialias
argument_list|(
argument|omp_get_num_procs
argument_list|)
end_macro

end_unit

