begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Test and measure string and memory functions.    Copyright (C) 1999, 2002, 2004, 2008 Free Software Foundation, Inc.    This file is part of the GNU C Library.    Written by Jakub Jelinek<jakub@redhat.com>, 1999.     The GNU C Library is free software; you can redistribute it and/or    modify it under the terms of the GNU Lesser General Public    License as published by the Free Software Foundation; either    version 2.1 of the License, or (at your option) any later version.     The GNU C Library is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Lesser General Public License for more details.     You should have received a copy of the GNU Lesser General Public    License along with the GNU C Library; if not, write to the Free    Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA    02111-1307 USA.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|void
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|long
name|test
decl_stmt|;
block|}
name|impl_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|impl_t
name|__start_impls
index|[]
decl_stmt|,
name|__stop_impls
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IMPL
parameter_list|(
name|name
parameter_list|,
name|test
parameter_list|)
define|\
value|impl_t tst_ ## name							\   __attribute__ ((section ("impls"), aligned (sizeof (void *))))	\     = { #name, (void (*) (void))name, test };
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TEST_MAIN
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_GNU_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_GNU_SOURCE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|__USE_STRING_INLINES
end_undef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<error.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_define
define|#
directive|define
name|GL
parameter_list|(
name|x
parameter_list|)
value|_##x
end_define

begin_define
define|#
directive|define
name|GLRO
parameter_list|(
name|x
parameter_list|)
value|_##x
end_define

begin_include
include|#
directive|include
file|"hp-timing.h"
end_include

begin_define
define|#
directive|define
name|TEST_FUNCTION
value|test_main ()
end_define

begin_define
define|#
directive|define
name|TIMEOUT
value|(4 * 60)
end_define

begin_define
define|#
directive|define
name|OPT_ITERATIONS
value|10000
end_define

begin_define
define|#
directive|define
name|OPT_RANDOM
value|10001
end_define

begin_define
define|#
directive|define
name|OPT_SEED
value|10002
end_define

begin_decl_stmt
name|unsigned
name|char
modifier|*
name|buf1
decl_stmt|,
modifier|*
name|buf2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ret
decl_stmt|,
name|do_srandom
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
name|seed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|page_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|hp_timing_t
name|_dl_hp_timing_overhead
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|ITERATIONS
end_ifndef

begin_decl_stmt
name|size_t
name|iterations
init|=
literal|100000
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ITERATIONS_OPTIONS
define|\
value|{ "iterations", required_argument, NULL, OPT_ITERATIONS },
end_define

begin_define
define|#
directive|define
name|ITERATIONS_PROCESS
define|\
value|case OPT_ITERATIONS:				\     iterations = strtoul (optarg, NULL, 0);	\     break;
end_define

begin_define
define|#
directive|define
name|ITERATIONS
value|iterations
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ITERATIONS_OPTIONS
end_define

begin_define
define|#
directive|define
name|ITERATIONS_PROCESS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CMDLINE_OPTIONS
value|ITERATIONS_OPTIONS \   { "random", no_argument, NULL, OPT_RANDOM },	\   { "seed", required_argument, NULL, OPT_SEED },
end_define

begin_define
define|#
directive|define
name|CMDLINE_PROCESS
value|ITERATIONS_PROCESS \   case OPT_RANDOM:							\     {									\       int fdr = open ("/dev/urandom", O_RDONLY);			\ 									\       if (fdr< 0 || read (fdr,&seed, sizeof(seed)) != sizeof (seed))	\ 	seed = time (NULL);						\       if (fdr>= 0)							\ 	close (fdr);							\       do_srandom = 1;							\       break;								\     }									\ 									\   case OPT_SEED:							\     seed = strtoul (optarg, NULL, 0);					\     do_srandom = 1;							\     break;
end_define

begin_define
define|#
directive|define
name|CALL
parameter_list|(
name|impl
parameter_list|,
modifier|...
parameter_list|)
define|\
value|(* (proto_t) (impl)->fn) (__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|FOR_EACH_IMPL
parameter_list|(
name|impl
parameter_list|,
name|notall
parameter_list|)
define|\
value|for (impl_t *impl = __start_impls; impl< __stop_impls; ++impl)	\     if (!notall || impl->test)
end_define

begin_define
define|#
directive|define
name|HP_TIMING_BEST
parameter_list|(
name|best_time
parameter_list|,
name|start
parameter_list|,
name|end
parameter_list|)
define|\
value|do									\     {									\       hp_timing_t tmptime;						\       HP_TIMING_DIFF (tmptime, start + _dl_hp_timing_overhead, end);	\       if (best_time> tmptime)						\ 	best_time = tmptime;						\     }									\   while (0)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BUF1PAGES
end_ifndef

begin_define
define|#
directive|define
name|BUF1PAGES
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|void
name|test_init
parameter_list|(
name|void
parameter_list|)
block|{
name|page_size
operator|=
literal|2
operator|*
name|getpagesize
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|MIN_PAGE_SIZE
if|if
condition|(
name|page_size
operator|<
name|MIN_PAGE_SIZE
condition|)
name|page_size
operator|=
name|MIN_PAGE_SIZE
expr_stmt|;
endif|#
directive|endif
name|buf1
operator|=
name|mmap
argument_list|(
literal|0
argument_list|,
operator|(
name|BUF1PAGES
operator|+
literal|1
operator|)
operator|*
name|page_size
argument_list|,
name|PROT_READ
operator||
name|PROT_WRITE
argument_list|,
name|MAP_PRIVATE
operator||
name|MAP_ANON
argument_list|,
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|buf1
operator|==
name|MAP_FAILED
condition|)
name|error
argument_list|(
name|EXIT_FAILURE
argument_list|,
name|errno
argument_list|,
literal|"mmap failed"
argument_list|)
expr_stmt|;
if|if
condition|(
name|mprotect
argument_list|(
name|buf1
operator|+
name|BUF1PAGES
operator|*
name|page_size
argument_list|,
name|page_size
argument_list|,
name|PROT_NONE
argument_list|)
condition|)
name|error
argument_list|(
name|EXIT_FAILURE
argument_list|,
name|errno
argument_list|,
literal|"mprotect failed"
argument_list|)
expr_stmt|;
name|buf2
operator|=
name|mmap
argument_list|(
literal|0
argument_list|,
literal|2
operator|*
name|page_size
argument_list|,
name|PROT_READ
operator||
name|PROT_WRITE
argument_list|,
name|MAP_PRIVATE
operator||
name|MAP_ANON
argument_list|,
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|buf2
operator|==
name|MAP_FAILED
condition|)
name|error
argument_list|(
name|EXIT_FAILURE
argument_list|,
name|errno
argument_list|,
literal|"mmap failed"
argument_list|)
expr_stmt|;
if|if
condition|(
name|mprotect
argument_list|(
name|buf2
operator|+
name|page_size
argument_list|,
name|page_size
argument_list|,
name|PROT_NONE
argument_list|)
condition|)
name|error
argument_list|(
name|EXIT_FAILURE
argument_list|,
name|errno
argument_list|,
literal|"mprotect failed"
argument_list|)
expr_stmt|;
name|HP_TIMING_DIFF_INIT
argument_list|()
expr_stmt|;
if|if
condition|(
name|do_srandom
condition|)
block|{
name|printf
argument_list|(
literal|"Setting seed to 0x%x\n"
argument_list|,
name|seed
argument_list|)
expr_stmt|;
name|srandom
argument_list|(
name|seed
argument_list|)
expr_stmt|;
block|}
name|memset
argument_list|(
name|buf1
argument_list|,
literal|0xa5
argument_list|,
name|BUF1PAGES
operator|*
name|page_size
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|buf2
argument_list|,
literal|0x5a
argument_list|,
name|page_size
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

