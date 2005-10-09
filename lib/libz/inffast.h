begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* inffast.h -- header to use inffast.c  * Copyright (C) 1995-2003 Mark Adler  * For conditions of distribution and use, see copyright notice in zlib.h  */
end_comment

begin_comment
comment|/* WARNING: this file should *not* be used by applications. It is    part of the implementation of the compression library and is    subject to change. Applications should only use zlib.h.  */
end_comment

begin_decl_stmt
name|void
name|inflate_fast
name|OF
argument_list|(
operator|(
name|z_streamp
name|strm
operator|,
name|unsigned
name|start
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

