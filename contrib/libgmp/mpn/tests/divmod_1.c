begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"gmp.h"
end_include

begin_include
include|#
directive|include
file|"gmp-impl.h"
end_include

begin_include
include|#
directive|include
file|"longlong.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|USG
end_ifndef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_function
name|unsigned
name|long
name|cputime
parameter_list|()
block|{
name|struct
name|rusage
name|rus
decl_stmt|;
name|getrusage
argument_list|(
literal|0
argument_list|,
operator|&
name|rus
argument_list|)
expr_stmt|;
return|return
name|rus
operator|.
name|ru_utime
operator|.
name|tv_sec
operator|*
literal|1000
operator|+
name|rus
operator|.
name|ru_utime
operator|.
name|tv_usec
operator|/
literal|1000
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|CLOCKS_PER_SEC
end_ifndef

begin_define
define|#
directive|define
name|CLOCKS_PER_SEC
value|1000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|CLOCKS_PER_SEC
operator|>=
literal|10000
end_if

begin_define
define|#
directive|define
name|CLOCK_TO_MILLISEC
parameter_list|(
name|cl
parameter_list|)
value|((cl) / (CLOCKS_PER_SEC / 1000))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CLOCK_TO_MILLISEC
parameter_list|(
name|cl
parameter_list|)
value|((cl) * 1000 / CLOCKS_PER_SEC)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|unsigned
name|long
name|cputime
parameter_list|()
block|{
return|return
name|CLOCK_TO_MILLISEC
argument_list|(
name|clock
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|M
value|* 1000000
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CLOCK
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__m88k__
argument_list|)
end_if

begin_define
define|#
directive|define
name|CLOCK
value|20 M
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__i386__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|CLOCK
value|(16.666667 M)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__m68k__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|CLOCK
value|(20 M)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_IBMR2
argument_list|)
end_elif

begin_define
define|#
directive|define
name|CLOCK
value|(25 M)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__sparc__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|CLOCK
value|(20 M)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__sun__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|CLOCK
value|(20 M)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__mips
argument_list|)
end_elif

begin_define
define|#
directive|define
name|CLOCK
value|(40 M)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__hppa__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|CLOCK
value|(50 M)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__alpha
argument_list|)
end_elif

begin_define
define|#
directive|define
name|CLOCK
value|(133 M)
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"Don't know CLOCK of your machine"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OPS
end_ifndef

begin_define
define|#
directive|define
name|OPS
value|20000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIZE
end_ifndef

begin_define
define|#
directive|define
name|SIZE
value|1000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TIMES
end_ifndef

begin_define
define|#
directive|define
name|TIMES
value|OPS/SIZE
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|OPS
end_undef

begin_define
define|#
directive|define
name|OPS
value|(SIZE*TIMES)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|main
parameter_list|()
block|{
name|mp_limb_t
name|nptr
index|[
name|SIZE
index|]
decl_stmt|;
name|mp_limb_t
name|qptr
index|[
name|SIZE
index|]
decl_stmt|;
name|mp_limb_t
name|pptr
index|[
name|SIZE
index|]
decl_stmt|;
name|mp_limb_t
name|dlimb
decl_stmt|,
name|rlimb
decl_stmt|,
name|plimb
decl_stmt|;
name|mp_size_t
name|nsize
decl_stmt|,
name|qsize
decl_stmt|,
name|psize
decl_stmt|;
name|int
name|test
decl_stmt|;
for|for
control|(
name|test
operator|=
literal|0
init|;
condition|;
name|test
operator|++
control|)
block|{
ifdef|#
directive|ifdef
name|RANDOM
name|nsize
operator|=
name|random
argument_list|()
operator|%
name|SIZE
operator|+
literal|1
expr_stmt|;
else|#
directive|else
name|nsize
operator|=
name|SIZE
expr_stmt|;
endif|#
directive|endif
name|mpn_random2
argument_list|(
name|nptr
argument_list|,
name|nsize
argument_list|)
expr_stmt|;
name|mpn_random2
argument_list|(
operator|&
name|dlimb
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|dlimb
operator|==
literal|0
condition|)
name|abort
argument_list|()
expr_stmt|;
name|rlimb
operator|=
name|mpn_divmod_1
argument_list|(
name|qptr
argument_list|,
name|nptr
argument_list|,
name|nsize
argument_list|,
name|dlimb
argument_list|)
expr_stmt|;
name|qsize
operator|=
name|nsize
operator|-
operator|(
name|qptr
index|[
name|nsize
operator|-
literal|1
index|]
operator|==
literal|0
operator|)
expr_stmt|;
if|if
condition|(
name|qsize
operator|==
literal|0
condition|)
block|{
name|plimb
operator|=
name|rlimb
expr_stmt|;
name|psize
operator|=
name|qsize
expr_stmt|;
block|}
else|else
block|{
name|plimb
operator|=
name|mpn_mul_1
argument_list|(
name|pptr
argument_list|,
name|qptr
argument_list|,
name|qsize
argument_list|,
name|dlimb
argument_list|)
expr_stmt|;
name|psize
operator|=
name|qsize
expr_stmt|;
name|plimb
operator|+=
name|mpn_add_1
argument_list|(
name|pptr
argument_list|,
name|pptr
argument_list|,
name|psize
argument_list|,
name|rlimb
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|plimb
operator|!=
literal|0
condition|)
name|pptr
index|[
name|psize
operator|++
index|]
operator|=
name|plimb
expr_stmt|;
if|if
condition|(
name|nsize
operator|!=
name|psize
operator|||
name|mpn_cmp
argument_list|(
name|nptr
argument_list|,
name|pptr
argument_list|,
name|nsize
argument_list|)
operator|!=
literal|0
condition|)
name|abort
argument_list|()
expr_stmt|;
block|}
block|}
end_function

end_unit

