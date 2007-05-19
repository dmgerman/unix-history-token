begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 2005, 2006 Free Software Foundation, Inc.    Contributed by Richard Henderson<rth@redhat.com>.     This file is part of the GNU OpenMP Library (libgomp).     Libgomp is free software; you can redistribute it and/or modify it    under the terms of the GNU Lesser General Public License as published by    the Free Software Foundation; either version 2.1 of the License, or    (at your option) any later version.     Libgomp is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS    FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for    more details.     You should have received a copy of the GNU Lesser General Public License     along with libgomp; see the file COPYING.LIB.  If not, write to the    Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with other files, some    of which are compiled with GCC, to produce an executable, this library    does not by itself cause the resulting executable to be covered by the    GNU General Public License.  This exception does not however invalidate    any other reasons why the executable file might be covered by the GNU    General Public License.  */
end_comment

begin_comment
comment|/* This file contains system specific routines related to counting    online processors and dynamic load balancing.  It is expected that    a system may well want to write special versions of each of these.     The following implementation uses a mix of POSIX and BSD routines.  */
end_comment

begin_include
include|#
directive|include
file|"libgomp.h"
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GETLOADAVG
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_LOADAVG_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/loadavg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* At startup, determine the default number of threads.  It would seem    this should be related to the number of cpus online.  */
end_comment

begin_function
name|void
name|gomp_init_num_threads
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|_SC_NPROCESSORS_ONLN
name|gomp_nthreads_var
operator|=
name|sysconf
argument_list|(
name|_SC_NPROCESSORS_ONLN
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/* When OMP_DYNAMIC is set, at thread launch determine the number of    threads we should spawn for this team.  */
end_comment

begin_comment
comment|/* ??? I have no idea what best practice for this is.  Surely some    function of the number of processors that are *still* online and    the load average.  Here I use the number of processors online    minus the 15 minute load average.  */
end_comment

begin_function
name|unsigned
name|gomp_dynamic_max_threads
parameter_list|(
name|void
parameter_list|)
block|{
name|unsigned
name|n_onln
decl_stmt|,
name|loadavg
decl_stmt|;
ifdef|#
directive|ifdef
name|_SC_NPROCESSORS_ONLN
name|n_onln
operator|=
name|sysconf
argument_list|(
name|_SC_NPROCESSORS_ONLN
argument_list|)
expr_stmt|;
if|if
condition|(
name|n_onln
operator|>
name|gomp_nthreads_var
condition|)
name|n_onln
operator|=
name|gomp_nthreads_var
expr_stmt|;
else|#
directive|else
name|n_onln
operator|=
name|gomp_nthreads_var
expr_stmt|;
endif|#
directive|endif
name|loadavg
operator|=
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|HAVE_GETLOADAVG
block|{
name|double
name|dloadavg
index|[
literal|3
index|]
decl_stmt|;
if|if
condition|(
name|getloadavg
argument_list|(
name|dloadavg
argument_list|,
literal|3
argument_list|)
operator|==
literal|3
condition|)
block|{
comment|/* Add 0.1 to get a kind of biased rounding.  */
name|loadavg
operator|=
name|dloadavg
index|[
literal|2
index|]
operator|+
literal|0.1
expr_stmt|;
block|}
block|}
endif|#
directive|endif
if|if
condition|(
name|loadavg
operator|>=
name|n_onln
condition|)
return|return
literal|1
return|;
else|else
return|return
name|n_onln
operator|-
name|loadavg
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
ifdef|#
directive|ifdef
name|_SC_NPROCESSORS_ONLN
return|return
name|sysconf
argument_list|(
name|_SC_NPROCESSORS_ONLN
argument_list|)
return|;
else|#
directive|else
return|return
name|gomp_nthreads_var
return|;
endif|#
directive|endif
block|}
end_function

begin_macro
name|ialias
argument_list|(
argument|omp_get_num_procs
argument_list|)
end_macro

end_unit

