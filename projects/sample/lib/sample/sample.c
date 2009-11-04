begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * File: sample.c  *  * Description:  *  This is a sample source file for a library.  It helps to demonstrate  *  how to setup a project that uses the LLVM build system, header files,  *  and libraries.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/* LLVM Header File #include "llvm/System/DataTypes.h" */
end_comment

begin_comment
comment|/* Header file global to this project */
end_comment

begin_include
include|#
directive|include
file|"sample.h"
end_include

begin_function
name|int
name|compute_sample
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|a
return|;
block|}
end_function

end_unit

