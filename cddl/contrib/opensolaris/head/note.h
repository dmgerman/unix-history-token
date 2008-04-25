begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994 by Sun Microsystems, Inc.  */
end_comment

begin_comment
comment|/*  * note.h:	interface for annotating source with info for tools  *  * NOTE is the default interface, but if the identifier NOTE is in use for  * some other purpose, you may prepare a similar header file using your own  * identifier, mapping that identifier to _NOTE.  Also, exported header  * files should *not* use NOTE, since the name may already be in use in  * a program's namespace.  Rather, exported header files should include  * sys/note.h directly and use _NOTE.  For consistency, all kernel source  * should use _NOTE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NOTE_H
end_ifndef

begin_define
define|#
directive|define
name|_NOTE_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|<sys/note.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
define|#
directive|define
name|NOTE
value|_NOTE
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NOTE_H */
end_comment

end_unit

