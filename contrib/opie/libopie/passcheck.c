begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* passcheck.c: The opiepasscheck() library function.  %%% portions-copyright-cmetz-96 Portions of this software are Copyright 1996-1999 by Craig Metz, All Rights Reserved. The Inner Net License Version 2 applies to these portions of the software. You should have received a copy of the license with this software. If you didn't get a copy, you may request one from<license@inner.net>.  Portions of this software are Copyright 1995 by Randall Atkinson and Dan McDonald, All Rights Reserved. All Rights under this copyright are assigned to the U.S. Naval Research Laboratory (NRL). The NRL Copyright Notice and License Agreement applies to this software.          History:  	Modified by cmetz for OPIE 2.3. OPIE_PASS_{MIN,MAX} changed to 		OPIE_SECRET_{MIN,MAX}. 	Modified by cmetz for OPIE 2.2. Use FUNCTION declaration et al.         Created at NRL for OPIE 2.2 from opiesubr.c. */
end_comment

begin_include
include|#
directive|include
file|"opie_cfg.h"
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

begin_include
include|#
directive|include
file|"opie.h"
end_include

begin_comment
comment|/*     Applies "good password" rules to the secret pass phrase.     We currently implement the following:     Passwords must be at least OPIE_SECRET_MIN (10) characters long.    Passwords must be at most OPIE_SECRET_MAX (127) characters long.     N.B.: Passing NULL pointers to this function is a bad idea. */
end_comment

begin_decl_stmt
name|int
name|opiepasscheck
name|FUNCTION
argument_list|(
operator|(
name|secret
operator|)
argument_list|,
name|char
operator|*
name|secret
argument_list|)
block|{
name|int
name|len
init|=
name|strlen
argument_list|(
name|secret
argument_list|)
decl_stmt|;
if|if
condition|(
name|len
operator|<
name|OPIE_SECRET_MIN
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|len
operator|>
name|OPIE_SECRET_MAX
condition|)
return|return
literal|1
return|;
return|return
literal|0
return|;
block|}
end_decl_stmt

end_unit

