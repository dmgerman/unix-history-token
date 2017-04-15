begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* gzclose.c contains minimal changes required to be compiled with zlibWrapper:  * - gz_statep was converted to union to work with -Wstrict-aliasing=1      */
end_comment

begin_comment
comment|/* gzclose.c -- zlib gzclose() function  * Copyright (C) 2004, 2010 Mark Adler  * For conditions of distribution and use, see http://www.zlib.net/zlib_license.html  */
end_comment

begin_include
include|#
directive|include
file|"gzguts.h"
end_include

begin_comment
comment|/* gzclose() is in a separate file so that it is linked in only if it is used.    That way the other gzclose functions can be used instead to avoid linking in    unneeded compression or decompression routines. */
end_comment

begin_function
name|int
name|ZEXPORT
name|gzclose
parameter_list|(
name|file
parameter_list|)
name|gzFile
name|file
decl_stmt|;
block|{
ifndef|#
directive|ifndef
name|NO_GZCOMPRESS
name|gz_statep
name|state
decl_stmt|;
if|if
condition|(
name|file
operator|==
name|NULL
condition|)
return|return
name|Z_STREAM_ERROR
return|;
name|state
operator|=
operator|(
name|gz_statep
operator|)
name|file
expr_stmt|;
return|return
name|state
operator|.
name|state
operator|->
name|mode
operator|==
name|GZ_READ
condition|?
name|gzclose_r
argument_list|(
name|file
argument_list|)
else|:
name|gzclose_w
argument_list|(
name|file
argument_list|)
return|;
else|#
directive|else
return|return
name|gzclose_r
argument_list|(
name|file
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function

end_unit

