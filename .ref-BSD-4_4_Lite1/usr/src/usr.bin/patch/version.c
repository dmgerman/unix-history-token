begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: version.c,v 2.0 86/09/17 15:40:11 lwall Exp $  *  * $Log:	version.c,v $  * Revision 2.0  86/09/17  15:40:11  lwall  * Baseline for netwide release.  *   */
end_comment

begin_include
include|#
directive|include
file|"EXTERN.h"
end_include

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_include
include|#
directive|include
file|"util.h"
end_include

begin_include
include|#
directive|include
file|"INTERN.h"
end_include

begin_include
include|#
directive|include
file|"patchlevel.h"
end_include

begin_include
include|#
directive|include
file|"version.h"
end_include

begin_comment
comment|/* Print out the version number and die. */
end_comment

begin_function
name|void
name|version
parameter_list|()
block|{
specifier|extern
name|char
name|rcsid
index|[]
decl_stmt|;
ifdef|#
directive|ifdef
name|lint
name|rcsid
index|[
literal|0
index|]
operator|=
name|rcsid
index|[
literal|0
index|]
expr_stmt|;
else|#
directive|else
name|fatal3
argument_list|(
literal|"%s\nPatch level: %d\n"
argument_list|,
name|rcsid
argument_list|,
name|PATCHLEVEL
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

