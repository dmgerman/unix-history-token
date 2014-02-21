begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Gleb Smirnoff<glebius@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<net/flowtable.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"netstat.h"
end_include

begin_comment
comment|/*  * Print flowtable statistics.  */
end_comment

begin_function
specifier|static
name|void
name|print_stats
parameter_list|(
name|struct
name|flowtable_stat
modifier|*
name|stat
parameter_list|)
block|{
define|#
directive|define
name|p
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|)
value|if (stat->f || sflag<= 1) \ 	printf(m, (uintmax_t)stat->f, plural(stat->f))
define|#
directive|define
name|p2
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|)
value|if (stat->f || sflag<= 1) \ 	printf(m, (uintmax_t)stat->f, plurales(stat->f))
name|p
argument_list|(
name|ft_lookups
argument_list|,
literal|"\t%ju lookup%s\n"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ft_hits
argument_list|,
literal|"\t%ju hit%s\n"
argument_list|)
expr_stmt|;
name|p2
argument_list|(
name|ft_misses
argument_list|,
literal|"\t%ju miss%s\n"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ft_inserts
argument_list|,
literal|"\t%ju insert%s\n"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ft_collisions
argument_list|,
literal|"\t%ju collision%s\n"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ft_free_checks
argument_list|,
literal|"\t%ju free check%s\n"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ft_frees
argument_list|,
literal|"\t%ju free%s\n"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ft_fail_lle_invalid
argument_list|,
literal|"\t%ju lookup%s with not resolved Layer 2 address\n"
argument_list|)
expr_stmt|;
undef|#
directive|undef
name|p2
undef|#
directive|undef
name|p
block|}
end_function

begin_function
name|void
name|flowtable_stats
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|flowtable_stat
name|stat
decl_stmt|;
name|size_t
name|len
init|=
sizeof|sizeof
argument_list|(
name|stat
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|live
condition|)
return|return;
if|if
condition|(
name|sysctlbyname
argument_list|(
literal|"net.flowtable.ip4.stat"
argument_list|,
operator|&
name|stat
argument_list|,
operator|&
name|len
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"flowtable for IPv4:\n"
argument_list|)
expr_stmt|;
name|print_stats
argument_list|(
operator|&
name|stat
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|sysctlbyname
argument_list|(
literal|"net.flowtable.ip6.stat"
argument_list|,
operator|&
name|stat
argument_list|,
operator|&
name|len
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"flowtable for IPv6:\n"
argument_list|)
expr_stmt|;
name|print_stats
argument_list|(
operator|&
name|stat
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

