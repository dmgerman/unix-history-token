begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)utime.h	5.1 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|utimbuf
block|{
name|time_t
name|actime
decl_stmt|;
comment|/* Access time */
name|time_t
name|modtime
decl_stmt|;
comment|/* Modification time */
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|c_plusplus
end_if

begin_function_decl
name|int
name|utime
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|utimbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|utime
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

