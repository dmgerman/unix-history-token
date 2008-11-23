begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: namespace.h,v 1.3 2003/10/27 00:12:43 lukem Exp $	*/
end_comment

begin_comment
comment|/*  * Mainly empty header to make reachover bits of libc happy.  *  * Since all reachover bits will include this, it's a good place to pull  * in nbtool_config.h.  */
end_comment

begin_include
include|#
directive|include
file|"nbtool_config.h"
end_include

begin_comment
comment|/* No aliases in reachover-based libc sources. */
end_comment

begin_undef
undef|#
directive|undef
name|__indr_reference
end_undef

begin_undef
undef|#
directive|undef
name|__weak_alias
end_undef

begin_undef
undef|#
directive|undef
name|__warn_references
end_undef

end_unit

