begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*================================================================ ** Copyright 2000, Clark Cooper ** All rights reserved. ** ** This is free software. You are permitted to copy, distribute, or modify ** it under the terms of the MIT/X license (contained in the COPYING file ** with this distribution.) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WINCONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|WINCONFIG_H
end_define

begin_define
define|#
directive|define
name|WIN32_LEAN_AND_MEAN
end_define

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_undef
undef|#
directive|undef
name|WIN32_LEAN_AND_MEAN
end_undef

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_define
define|#
directive|define
name|XML_NS
value|1
end_define

begin_define
define|#
directive|define
name|XML_DTD
value|1
end_define

begin_define
define|#
directive|define
name|XML_CONTEXT_BYTES
value|1024
end_define

begin_comment
comment|/* we will assume all Windows platforms are little endian */
end_comment

begin_define
define|#
directive|define
name|BYTEORDER
value|1234
end_define

begin_comment
comment|/* Windows has memmove() available. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMMOVE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef WINCONFIG_H */
end_comment

end_unit

