begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)nlist.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<nlist.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_decl_stmt
name|struct
name|nlist
name|psnl
index|[]
init|=
block|{
block|{
literal|"_ecmx"
block|}
block|,
define|#
directive|define
name|X_ECMX
value|0
block|{
literal|"_fscale"
block|}
block|,
define|#
directive|define
name|X_FSCALE
value|1
block|{
literal|"_ccpu"
block|}
block|,
define|#
directive|define
name|X_CCPU
value|2
block|{
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|fixpt_t
name|ccpu
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel _ccpu variable */
end_comment

begin_decl_stmt
name|int
name|nlistread
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if nlist already read. */
end_comment

begin_decl_stmt
name|int
name|ecmx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel _ecmx variable */
end_comment

begin_decl_stmt
name|int
name|fscale
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel _fscale variable */
end_comment

begin_define
define|#
directive|define
name|kread
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|)
define|\
value|kvm_read(psnl[x].n_value, (char *)&v, sizeof v) != sizeof(v)
end_define

begin_macro
name|donlist
argument_list|()
end_macro

begin_block
block|{
specifier|extern
name|int
name|eval
decl_stmt|;
name|int
name|rval
decl_stmt|;
name|rval
operator|=
literal|0
expr_stmt|;
name|nlistread
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|kvm_nlist
argument_list|(
name|psnl
argument_list|)
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ps: kvm_nlist: %s\n"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
name|eval
operator|=
literal|1
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|kread
argument_list|(
name|X_FSCALE
argument_list|,
name|fscale
argument_list|)
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ps: fscale: %s\n"
argument_list|,
name|kvm_geterr
argument_list|()
argument_list|)
expr_stmt|;
name|eval
operator|=
name|rval
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|kread
argument_list|(
name|X_ECMX
argument_list|,
name|ecmx
argument_list|)
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ps: ecmx: %s\n"
argument_list|,
name|kvm_geterr
argument_list|()
argument_list|)
expr_stmt|;
name|eval
operator|=
name|rval
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|kread
argument_list|(
name|X_CCPU
argument_list|,
name|ccpu
argument_list|)
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ps: ccpu: %s\n"
argument_list|,
name|kvm_geterr
argument_list|()
argument_list|)
expr_stmt|;
name|eval
operator|=
name|rval
operator|=
literal|1
expr_stmt|;
block|}
return|return
operator|(
name|rval
operator|)
return|;
block|}
end_block

end_unit

