begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  Author: Mark Moraes<moraes@csri.toronto.edu> */
end_comment

begin_comment
comment|/*LINTLIBRARY*/
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"globals.h"
end_include

begin_include
include|#
directive|include
file|"trace.h"
end_include

begin_macro
name|RCSID
argument_list|(
literal|"$Id: _strdup.c,v 1.8 1993/05/23 03:38:27 moraes Exp $"
argument_list|)
end_macro

begin_function
name|char
modifier|*
name|__strdup
parameter_list|(
name|s
parameter_list|,
name|fname
parameter_list|,
name|linenum
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
specifier|const
name|char
modifier|*
name|fname
decl_stmt|;
name|int
name|linenum
decl_stmt|;
block|{
name|char
modifier|*
name|cp
decl_stmt|;
name|PRTRACE
argument_list|(
name|sprintf
argument_list|(
name|_malloc_statsbuf
argument_list|,
literal|"%s:%d:"
argument_list|,
name|fname
argument_list|,
name|linenum
argument_list|)
argument_list|)
expr_stmt|;
name|cp
operator|=
name|strdup
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|RECORD_FILE_AND_LINE
argument_list|(
operator|(
name|univptr_t
operator|)
name|cp
argument_list|,
name|fname
argument_list|,
name|linenum
argument_list|)
expr_stmt|;
return|return
operator|(
name|cp
operator|)
return|;
block|}
end_function

end_unit

