begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: ohash_int.h,v 1.3 2006/01/16 15:52:25 espie Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_if
if|#
directive|if
name|HAVE_NBTOOL_CONFIG_H
end_if

begin_include
include|#
directive|include
file|"nbtool_config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"ohash.h"
end_include

begin_struct
struct|struct
name|_ohash_record
block|{
name|u_int32_t
name|hv
decl_stmt|;
specifier|const
name|char
modifier|*
name|p
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DELETED
value|((const char *)h)
end_define

begin_define
define|#
directive|define
name|NONE
value|(h->size)
end_define

begin_comment
comment|/* Don't bother changing the hash table if the change is small enough.  */
end_comment

begin_define
define|#
directive|define
name|MINSIZE
value|(1UL<< 4)
end_define

begin_define
define|#
directive|define
name|MINDELETED
value|4
end_define

end_unit

