begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: info_hes.c,v 5.2 90/06/23 22:19:30 jsp Rel $  *  * Copyright (c) 1989 Jan-Simon Pendry  * Copyright (c) 1989 Imperial College of Science, Technology& Medicine  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * %sccs.include.redist.c%  *  *	@(#)info_hes.c	5.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Get info from Hesiod  */
end_comment

begin_include
include|#
directive|include
file|"am.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_HESIOD_MAPS
end_ifdef

begin_include
include|#
directive|include
file|<hesiod.h>
end_include

begin_define
define|#
directive|define
name|HES_PREFIX
value|"hesiod."
end_define

begin_define
define|#
directive|define
name|HES_PREFLEN
value|7
end_define

begin_comment
comment|/*  * No way to probe the server - check the map name begins with "hesiod."  */
end_comment

begin_macro
name|hesiod_init
argument_list|(
argument|map
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|map
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
name|strncmp
argument_list|(
name|map
argument_list|,
name|HES_PREFIX
argument_list|,
name|HES_PREFLEN
argument_list|)
operator|==
literal|0
condition|?
literal|0
else|:
name|ENOENT
return|;
block|}
end_block

begin_comment
comment|/*  * Do a Hesiod nameserver call.  * Modify time is ignored by Hesiod - XXX  */
end_comment

begin_function
name|int
name|hesiod_search
parameter_list|(
name|m
parameter_list|,
name|map
parameter_list|,
name|key
parameter_list|,
name|pval
parameter_list|,
name|tp
parameter_list|)
name|mnt_map
modifier|*
name|m
decl_stmt|;
name|char
modifier|*
name|map
decl_stmt|;
name|char
modifier|*
name|key
decl_stmt|;
name|char
modifier|*
modifier|*
name|pval
decl_stmt|;
name|time_t
modifier|*
name|tp
decl_stmt|;
block|{
name|int
name|error
decl_stmt|;
name|char
name|hes_map
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|char
modifier|*
modifier|*
name|rvec
decl_stmt|;
comment|/* 	 * Make Hesiod name.  Skip past the "hesiod." 	 * at the start of the map name and append 	 * ".automount".  The net effect is that a lookup 	 * of /defaults in hesiod.home will result in a 	 * call to hes_resolve("/defaults", "home.automount"); 	 */
name|sprintf
argument_list|(
name|hes_map
argument_list|,
literal|"%s%s"
argument_list|,
name|map
operator|+
name|HES_PREFLEN
argument_list|,
literal|".automount"
argument_list|)
expr_stmt|;
comment|/* 	 * Call the resolver 	 */
name|rvec
operator|=
name|hes_resolve
argument_list|(
name|key
argument_list|,
name|hes_map
argument_list|)
expr_stmt|;
comment|/* 	 * If a reply was forthcoming then return 	 * it (and free subsequent replies) 	 */
if|if
condition|(
name|rvec
operator|&&
operator|*
name|rvec
condition|)
block|{
operator|*
name|pval
operator|=
operator|*
name|rvec
expr_stmt|;
while|while
condition|(
operator|*
operator|++
name|rvec
condition|)
name|free
argument_list|(
operator|*
name|rvec
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|/* 	 * Otherwise reflect the hesiod error into a Un*x error 	 */
switch|switch
condition|(
name|hes_error
argument_list|()
condition|)
block|{
case|case
name|HES_ER_NOTFOUND
case|:
name|error
operator|=
name|ENOENT
expr_stmt|;
break|break;
case|case
name|HES_ER_CONFIG
case|:
name|error
operator|=
name|EIO
expr_stmt|;
break|break;
case|case
name|HES_ER_NET
case|:
name|error
operator|=
name|ETIMEDOUT
expr_stmt|;
break|break;
default|default:
name|error
operator|=
name|EINVAL
expr_stmt|;
break|break;
block|}
return|return
name|error
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAS_HESIOD_MAPS */
end_comment

end_unit

