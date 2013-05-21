begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|FLEX_SCANNER
end_ifdef

begin_comment
comment|/* dnl   tables_shared.c - tables serialization code dnl  dnl   Copyright (c) 1990 The Regents of the University of California. dnl   All rights reserved. dnl  dnl   This code is derived from software contributed to Berkeley by dnl   Vern Paxson. dnl  dnl   The United States Government has rights in this work pursuant dnl   to contract no. DE-AC03-76SF00098 between the United States dnl   Department of Energy and the University of California. dnl  dnl   This file is part of flex. dnl  dnl   Redistribution and use in source and binary forms, with or without dnl   modification, are permitted provided that the following conditions dnl   are met: dnl  dnl   1. Redistributions of source code must retain the above copyright dnl      notice, this list of conditions and the following disclaimer. dnl   2. Redistributions in binary form must reproduce the above copyright dnl      notice, this list of conditions and the following disclaimer in the dnl      documentation and/or other materials provided with the distribution. dnl  dnl   Neither the name of the University nor the names of its contributors dnl   may be used to endorse or promote products derived from this software dnl   without specific prior written permission. dnl  dnl   THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR dnl   IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED dnl   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR dnl   PURPOSE. dnl  */
end_comment

begin_escape
end_escape

begin_comment
comment|/* This file is meant to be included in both the skeleton and the actual  * flex code (hence the name "_shared").   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|yyskel_static
end_ifndef

begin_define
define|#
directive|define
name|yyskel_static
value|static
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"flexdef.h"
end_include

begin_include
include|#
directive|include
file|"tables.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|yyskel_static
end_ifndef

begin_define
define|#
directive|define
name|yyskel_static
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** Get the number of integers in this table. This is NOT the  *  same thing as the number of elements.  *  @param td the table   *  @return the number of integers in the table  */
end_comment

begin_function
name|yyskel_static
name|flex_int32_t
name|yytbl_calc_total_len
parameter_list|(
specifier|const
name|struct
name|yytbl_data
modifier|*
name|tbl
parameter_list|)
block|{
name|flex_int32_t
name|n
decl_stmt|;
comment|/* total number of ints */
name|n
operator|=
name|tbl
operator|->
name|td_lolen
expr_stmt|;
if|if
condition|(
name|tbl
operator|->
name|td_hilen
operator|>
literal|0
condition|)
name|n
operator|*=
name|tbl
operator|->
name|td_hilen
expr_stmt|;
if|if
condition|(
name|tbl
operator|->
name|td_id
operator|==
name|YYTD_ID_TRANSITION
condition|)
name|n
operator|*=
literal|2
expr_stmt|;
return|return
name|n
return|;
block|}
end_function

end_unit

