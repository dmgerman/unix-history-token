begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /mit/kerberos/src/lib/des/RCS/key_parity.c,v $  * $Author: jtkohl $  *  * Copyright 1989 by the Massachusetts Institute of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  *  * These routines check and fix parity of encryption keys for the DES  * algorithm.  *  * Under U.S. law, this software may not be exported outside the US  * without license from the U.S. Commerce department.  *  * These routines form the library interface to the DES facilities.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid_key_parity_c
index|[]
init|=
literal|"$Header: key_parity.c,v 4.0 89/01/22 11:45:12 jtkohl Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_include
include|#
directive|include
file|<mit-copyright.h>
end_include

begin_include
include|#
directive|include
file|<des.h>
end_include

begin_include
include|#
directive|include
file|"des_internal.h"
end_include

begin_include
include|#
directive|include
file|"odd.h"
end_include

begin_comment
comment|/* Load compile-time generated odd_parity table */
end_comment

begin_comment
comment|/*  * des_fixup_key_parity: Forces odd parity per byte; parity is bits  *                       8,16,...64 in des order, implies 0, 8, 16, ...  *                       vax order.  */
end_comment

begin_function
name|void
name|des_fixup_key_parity
parameter_list|(
name|key
parameter_list|)
specifier|register
name|des_cblock
name|key
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|des_cblock
argument_list|)
condition|;
name|i
operator|++
control|)
name|key
index|[
name|i
index|]
operator|=
name|odd_parity
index|[
name|key
index|[
name|i
index|]
index|]
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * des_check_key_parity: returns true iff key has the correct des parity.  *                       See des_fix_key_parity for the definition of  *                       correct des parity.  */
end_comment

begin_function
name|int
name|des_check_key_parity
parameter_list|(
name|key
parameter_list|)
specifier|register
name|des_cblock
name|key
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|des_cblock
argument_list|)
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|key
index|[
name|i
index|]
operator|!=
name|odd_parity
index|[
name|key
index|[
name|i
index|]
index|]
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

end_unit

