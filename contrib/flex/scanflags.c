begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* scanflags - flags used by scanning. */
end_comment

begin_comment
comment|/*  Copyright (c) 1990 The Regents of the University of California. */
end_comment

begin_comment
comment|/*  All rights reserved. */
end_comment

begin_comment
comment|/*  This code is derived from software contributed to Berkeley by */
end_comment

begin_comment
comment|/*  Vern Paxson. */
end_comment

begin_comment
comment|/*  The United States Government has rights in this work pursuant */
end_comment

begin_comment
comment|/*  to contract no. DE-AC03-76SF00098 between the United States */
end_comment

begin_comment
comment|/*  Department of Energy and the University of California. */
end_comment

begin_comment
comment|/*  This file is part of flex. */
end_comment

begin_comment
comment|/*  Redistribution and use in source and binary forms, with or without */
end_comment

begin_comment
comment|/*  modification, are permitted provided that the following conditions */
end_comment

begin_comment
comment|/*  are met: */
end_comment

begin_comment
comment|/*  1. Redistributions of source code must retain the above copyright */
end_comment

begin_comment
comment|/*     notice, this list of conditions and the following disclaimer. */
end_comment

begin_comment
comment|/*  2. Redistributions in binary form must reproduce the above copyright */
end_comment

begin_comment
comment|/*     notice, this list of conditions and the following disclaimer in the */
end_comment

begin_comment
comment|/*     documentation and/or other materials provided with the distribution. */
end_comment

begin_comment
comment|/*  Neither the name of the University nor the names of its contributors */
end_comment

begin_comment
comment|/*  may be used to endorse or promote products derived from this software */
end_comment

begin_comment
comment|/*  without specific prior written permission. */
end_comment

begin_comment
comment|/*  THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR */
end_comment

begin_comment
comment|/*  IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED */
end_comment

begin_comment
comment|/*  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR */
end_comment

begin_comment
comment|/*  PURPOSE. */
end_comment

begin_include
include|#
directive|include
file|"flexdef.h"
end_include

begin_decl_stmt
name|scanflags_t
modifier|*
name|_sf_stk
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|_sf_top_ix
init|=
literal|0
decl_stmt|,
name|_sf_max
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|sf_push
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|_sf_top_ix
operator|+
literal|1
operator|>=
name|_sf_max
condition|)
name|_sf_stk
operator|=
operator|(
name|scanflags_t
operator|*
operator|)
name|flex_realloc
argument_list|(
operator|(
name|void
operator|*
operator|)
name|_sf_stk
argument_list|,
sizeof|sizeof
argument_list|(
name|scanflags_t
argument_list|)
operator|*
operator|(
name|_sf_max
operator|+=
literal|32
operator|)
argument_list|)
expr_stmt|;
comment|// copy the top element
name|_sf_stk
index|[
name|_sf_top_ix
operator|+
literal|1
index|]
operator|=
name|_sf_stk
index|[
name|_sf_top_ix
index|]
expr_stmt|;
operator|++
name|_sf_top_ix
expr_stmt|;
block|}
end_function

begin_function
name|void
name|sf_pop
parameter_list|(
name|void
parameter_list|)
block|{
name|assert
argument_list|(
name|_sf_top_ix
operator|>
literal|0
argument_list|)
expr_stmt|;
operator|--
name|_sf_top_ix
expr_stmt|;
block|}
end_function

begin_comment
comment|/* one-time initialization. Should be called before any sf_ functions. */
end_comment

begin_function
name|void
name|sf_init
parameter_list|(
name|void
parameter_list|)
block|{
name|assert
argument_list|(
name|_sf_stk
operator|==
name|NULL
argument_list|)
expr_stmt|;
name|_sf_stk
operator|=
operator|(
name|scanflags_t
operator|*
operator|)
name|flex_alloc
argument_list|(
sizeof|sizeof
argument_list|(
name|scanflags_t
argument_list|)
operator|*
operator|(
name|_sf_max
operator|=
literal|32
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|_sf_stk
condition|)
name|lerrsf_fatal
argument_list|(
name|_
argument_list|(
literal|"Unable to allocate %ld of stack"
argument_list|)
argument_list|,
operator|(
name|void
operator|*
operator|)
operator|(
name|uintptr_t
operator|)
sizeof|sizeof
argument_list|(
name|scanflags_t
argument_list|)
argument_list|)
expr_stmt|;
name|_sf_stk
index|[
name|_sf_top_ix
index|]
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/* vim:set expandtab cindent tabstop=4 softtabstop=4 shiftwidth=4 textwidth=0: */
end_comment

end_unit

