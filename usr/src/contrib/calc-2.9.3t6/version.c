begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994 David I. Bell  * Permission is granted to use, distribute, or modify this source,  * provided that this copyright notice remains intact.  *  * version - determine the version of calc  */
end_comment

begin_include
include|#
directive|include
file|"calc.h"
end_include

begin_define
define|#
directive|define
name|MAJOR_VER
value|2
end_define

begin_comment
comment|/* major version */
end_comment

begin_define
define|#
directive|define
name|MINOR_VER
value|9
end_define

begin_comment
comment|/* minor version */
end_comment

begin_define
define|#
directive|define
name|PATCH_LEVEL
value|3
end_define

begin_comment
comment|/* patch level */
end_comment

begin_function
name|void
name|version
parameter_list|(
name|stream
parameter_list|)
name|FILE
modifier|*
name|stream
decl_stmt|;
comment|/* stream to write version on */
block|{
name|fprintf
argument_list|(
name|stream
argument_list|,
literal|"C-style arbitrary precision calculator (version %d.%d.%dt6)\n"
argument_list|,
name|MAJOR_VER
argument_list|,
name|MINOR_VER
argument_list|,
name|PATCH_LEVEL
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* END CODE */
end_comment

end_unit

