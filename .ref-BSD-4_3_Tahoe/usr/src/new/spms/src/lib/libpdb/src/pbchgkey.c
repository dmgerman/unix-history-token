begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * pbchgkey() substitutes newkey for oldkey. Returns integer NO if buffer  * space exceeded, otherwise YES.  */
end_comment

begin_include
include|#
directive|include
file|"null.h"
end_include

begin_include
include|#
directive|include
file|"pdbuf.h"
end_include

begin_include
include|#
directive|include
file|"yesno.h"
end_include

begin_macro
name|pbchgkey
argument_list|(
argument|oldkey
argument_list|,
argument|newkey
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|oldkey
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* old key string */
end_comment

begin_decl_stmt
name|char
modifier|*
name|newkey
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* new key string */
end_comment

begin_block
block|{
specifier|register
name|char
modifier|*
name|bp
decl_stmt|;
comment|/* buffer pointer */
name|char
modifier|*
name|pbfndkey
parameter_list|()
function_decl|;
comment|/* find key */
name|char
modifier|*
name|strncpy
parameter_list|()
function_decl|;
comment|/* copy n characters */
name|int
name|chgklen
decl_stmt|;
comment|/* incremental key string length */
name|int
name|newklen
decl_stmt|;
comment|/* new key string length */
name|int
name|pbstretch
parameter_list|()
function_decl|;
comment|/* stretch buffer */
name|int
name|strlen
parameter_list|()
function_decl|;
comment|/* string length */
if|if
condition|(
operator|(
name|bp
operator|=
name|pbfndkey
argument_list|(
name|newkey
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
name|pbrmkey
argument_list|(
name|oldkey
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
name|bp
operator|=
name|pbfndkey
argument_list|(
name|oldkey
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
name|newklen
operator|=
name|strlen
argument_list|(
name|newkey
argument_list|)
expr_stmt|;
name|chgklen
operator|=
name|newklen
operator|-
name|strlen
argument_list|(
name|oldkey
argument_list|)
expr_stmt|;
if|if
condition|(
name|pbstretch
argument_list|(
name|bp
argument_list|,
name|chgklen
argument_list|)
operator|==
name|NO
condition|)
return|return
operator|(
name|NO
operator|)
return|;
name|strncpy
argument_list|(
name|bp
argument_list|,
name|newkey
argument_list|,
name|newklen
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|YES
operator|)
return|;
block|}
end_block

end_unit

