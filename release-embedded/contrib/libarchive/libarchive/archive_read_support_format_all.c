begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2011 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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

begin_include
include|#
directive|include
file|"archive_private.h"
end_include

begin_function
name|int
name|archive_read_support_format_all
parameter_list|(
name|struct
name|archive
modifier|*
name|a
parameter_list|)
block|{
name|archive_check_magic
argument_list|(
name|a
argument_list|,
name|ARCHIVE_READ_MAGIC
argument_list|,
name|ARCHIVE_STATE_NEW
argument_list|,
literal|"archive_read_support_format_all"
argument_list|)
expr_stmt|;
comment|/* TODO: It would be nice to compute the ordering 	 * here automatically so that people who enable just 	 * a few formats can still get the benefits.  That 	 * may just require the format registration to include 	 * a "maximum read-ahead" value (anything that uses seek 	 * would be essentially infinite read-ahead).  The core 	 * bid management can then sort the bidders before calling 	 * them. 	 * 	 * If you implement the above, please return the list below 	 * to alphabetic order. 	 */
comment|/* 	 * These bidders are all pretty cheap; they just examine a 	 * small initial part of the archive.  If one of these bids 	 * high, we can maybe avoid running any of the more expensive 	 * bidders below. 	 */
name|archive_read_support_format_ar
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|archive_read_support_format_cpio
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|archive_read_support_format_empty
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|archive_read_support_format_lha
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|archive_read_support_format_mtree
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|archive_read_support_format_tar
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|archive_read_support_format_xar
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|/* 	 * Install expensive bidders last.  By doing them last, we 	 * increase the chance that a high bid from someone else will 	 * make it unnecessary for these to do anything at all. 	 */
comment|/* These three have potentially large look-ahead. */
name|archive_read_support_format_7zip
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|archive_read_support_format_cab
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|archive_read_support_format_rar
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|archive_read_support_format_iso9660
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|/* Seek is really bad, since it forces the read-ahead 	 * logic to discard buffered data. */
name|archive_read_support_format_zip
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

