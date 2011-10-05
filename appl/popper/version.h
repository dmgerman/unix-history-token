begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  * static char copyright[] = "Copyright (c) 1990 Regents of the University of California.\nAll rights reserved.\n";  * static char SccsId[] = "@(#)@(#)version.h	2.6  2.6 4/3/91";  *  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_comment
comment|/*  *  Current version of this POP implementation  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|VERSION
value|krb4_version
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

