begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2007 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"archive_platform.h"
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"archive.h"
end_include

begin_function
name|int
name|archive_read_support_compression_all
parameter_list|(
name|struct
name|archive
modifier|*
name|a
parameter_list|)
block|{
comment|/* Bzip falls back to "bunzip2" command-line */
name|archive_read_support_compression_bzip2
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|/* The decompress code doesn't use an outside library. */
name|archive_read_support_compression_compress
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|/* Gzip decompress falls back to "gunzip" command-line. */
name|archive_read_support_compression_gzip
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|/* The LZMA file format has a very weak signature, so it 	 * may not be feasible to keep this here, but we'll try. 	 * This will come back out if there are problems. */
comment|/* Lzma falls back to "unlzma" command-line program. */
name|archive_read_support_compression_lzma
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|/* Xz falls back to "unxz" command-line program. */
name|archive_read_support_compression_xz
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|/* The decode code doesn't use an outside library. */
name|archive_read_support_compression_uu
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|/* Note: We always return ARCHIVE_OK here, even if some of the 	 * above return ARCHIVE_WARN.  The intent here is to enable 	 * "as much as possible."  Clients who need specific 	 * compression should enable those individually so they can 	 * verify the level of support. */
comment|/* Clear any warning messages set by the above functions. */
name|archive_clear_error
argument_list|(
name|a
argument_list|)
expr_stmt|;
return|return
operator|(
name|ARCHIVE_OK
operator|)
return|;
block|}
end_function

end_unit

