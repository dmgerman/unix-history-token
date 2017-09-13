begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2008-2009 Stacey Son<sson@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/lockstat.h>
end_include

begin_include
include|#
directive|include
file|<sys/sdt.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_expr_stmt
name|SDT_PROVIDER_DEFINE
argument_list|(
name|lockstat
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE1
argument_list|(
name|lockstat
argument_list|, , ,
name|adaptive__acquire
argument_list|,
literal|"struct mtx *"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE1
argument_list|(
name|lockstat
argument_list|, , ,
name|adaptive__release
argument_list|,
literal|"struct mtx *"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE2
argument_list|(
name|lockstat
argument_list|, , ,
name|adaptive__spin
argument_list|,
literal|"struct mtx *"
argument_list|,
literal|"uint64_t"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE2
argument_list|(
name|lockstat
argument_list|, , ,
name|adaptive__block
argument_list|,
literal|"struct mtx *"
argument_list|,
literal|"uint64_t"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE1
argument_list|(
name|lockstat
argument_list|, , ,
name|spin__acquire
argument_list|,
literal|"struct mtx *"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE1
argument_list|(
name|lockstat
argument_list|, , ,
name|spin__release
argument_list|,
literal|"struct mtx *"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE2
argument_list|(
name|lockstat
argument_list|, , ,
name|spin__spin
argument_list|,
literal|"struct mtx *"
argument_list|,
literal|"uint64_t"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE2
argument_list|(
name|lockstat
argument_list|, , ,
name|rw__acquire
argument_list|,
literal|"struct rwlock *"
argument_list|,
literal|"int"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE2
argument_list|(
name|lockstat
argument_list|, , ,
name|rw__release
argument_list|,
literal|"struct rwlock *"
argument_list|,
literal|"int"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE5
argument_list|(
name|lockstat
argument_list|, , ,
name|rw__block
argument_list|,
literal|"struct rwlock *"
argument_list|,
literal|"uint64_t"
argument_list|,
literal|"int"
argument_list|,
literal|"int"
argument_list|,
literal|"int"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE2
argument_list|(
name|lockstat
argument_list|, , ,
name|rw__spin
argument_list|,
literal|"struct rwlock *"
argument_list|,
literal|"uint64_t"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE1
argument_list|(
name|lockstat
argument_list|, , ,
name|rw__upgrade
argument_list|,
literal|"struct rwlock *"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE1
argument_list|(
name|lockstat
argument_list|, , ,
name|rw__downgrade
argument_list|,
literal|"struct rwlock *"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE2
argument_list|(
name|lockstat
argument_list|, , ,
name|sx__acquire
argument_list|,
literal|"struct sx *"
argument_list|,
literal|"int"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE2
argument_list|(
name|lockstat
argument_list|, , ,
name|sx__release
argument_list|,
literal|"struct sx *"
argument_list|,
literal|"int"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE5
argument_list|(
name|lockstat
argument_list|, , ,
name|sx__block
argument_list|,
literal|"struct sx *"
argument_list|,
literal|"uint64_t"
argument_list|,
literal|"int"
argument_list|,
literal|"int"
argument_list|,
literal|"int"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE2
argument_list|(
name|lockstat
argument_list|, , ,
name|sx__spin
argument_list|,
literal|"struct sx *"
argument_list|,
literal|"uint64_t"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE1
argument_list|(
name|lockstat
argument_list|, , ,
name|sx__upgrade
argument_list|,
literal|"struct sx *"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE1
argument_list|(
name|lockstat
argument_list|, , ,
name|sx__downgrade
argument_list|,
literal|"struct sx *"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE2
argument_list|(
name|lockstat
argument_list|, , ,
name|thread__spin
argument_list|,
literal|"struct mtx *"
argument_list|,
literal|"uint64_t"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|volatile
name|int
name|__read_frequently
name|lockstat_enabled
decl_stmt|;
end_decl_stmt

begin_function
name|uint64_t
name|lockstat_nsecs
parameter_list|(
name|struct
name|lock_object
modifier|*
name|lo
parameter_list|)
block|{
name|struct
name|bintime
name|bt
decl_stmt|;
name|uint64_t
name|ns
decl_stmt|;
if|if
condition|(
operator|!
name|lockstat_enabled
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
operator|(
name|lo
operator|->
name|lo_flags
operator|&
name|LO_NOPROFILE
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|binuptime
argument_list|(
operator|&
name|bt
argument_list|)
expr_stmt|;
name|ns
operator|=
name|bt
operator|.
name|sec
operator|*
operator|(
name|uint64_t
operator|)
literal|1000000000
expr_stmt|;
name|ns
operator|+=
operator|(
operator|(
name|uint64_t
operator|)
literal|1000000000
operator|*
call|(
name|uint32_t
call|)
argument_list|(
name|bt
operator|.
name|frac
operator|>>
literal|32
argument_list|)
operator|)
operator|>>
literal|32
expr_stmt|;
return|return
operator|(
name|ns
operator|)
return|;
block|}
end_function

end_unit

