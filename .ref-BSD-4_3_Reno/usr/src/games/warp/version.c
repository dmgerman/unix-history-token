begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: version.c,v 7.0 86/10/08 15:14:39 lwall Exp $  *  * $Log:	version.c,v $  * Revision 7.0  86/10/08  15:14:39  lwall  * Split into separate files.  Added amoebas and pirates.  *   */
end_comment

begin_include
include|#
directive|include
file|"patchlevel.h"
end_include

begin_include
include|#
directive|include
file|"INTERN.h"
end_include

begin_include
include|#
directive|include
file|"version.h"
end_include

begin_comment
comment|/* Print out the version number. */
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
name|printf
argument_list|(
literal|"%s\r\nPatch level: %d\r\n"
argument_list|,
name|rcsid
argument_list|,
name|PATCHLEVEL
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

