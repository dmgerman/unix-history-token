begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* revision.h -- define the version number  * Copyright (C) 1992-1993 Jean-loup Gailly.  * This is free software; you can redistribute it and/or modify it under the  * terms of the GNU General Public License, see the file COPYING.  */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|"1.2.4"
end_define

begin_define
define|#
directive|define
name|PATCHLEVEL
value|0
end_define

begin_define
define|#
directive|define
name|REVDATE
value|"18 Aug 93"
end_define

begin_comment
comment|/* This version does not support compression into old compress format: */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LZW
end_ifdef

begin_undef
undef|#
directive|undef
name|LZW
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* $FreeBSD$ */
end_comment

end_unit

