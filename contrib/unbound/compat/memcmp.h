begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	memcmp.h: undef memcmp for compat.  *  *	Copyright (c) 2012, NLnet Labs. All rights reserved.  *  * See LICENSE for the license. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COMPAT_MEMCMP_H
end_ifndef

begin_define
define|#
directive|define
name|COMPAT_MEMCMP_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|memcmp
end_ifdef

begin_comment
comment|/* undef here otherwise autoheader messes it up in config.h */
end_comment

begin_undef
undef|#
directive|undef
name|memcmp
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMPAT_MEMCMP_H */
end_comment

end_unit

