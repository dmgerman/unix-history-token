begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994 by Sun Microsystems, Inc.  */
end_comment

begin_comment
comment|/*  * sys/note.h:	interface for annotating source with info for tools  *  * This is the underlying interface; NOTE (/usr/include/note.h) is the  * preferred interface, but all exported header files should include this  * file directly and use _NOTE so as not to take "NOTE" from the user's  * namespace.  For consistency, *all* kernel source should use _NOTE.  *  * By default, annotations expand to nothing.  This file implements  * that.  Tools using annotations will interpose a different version  * of this file that will expand annotations as needed.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_NOTE_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_NOTE_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

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
ifndef|#
directive|ifndef
name|_NOTE
define|#
directive|define
name|_NOTE
parameter_list|(
name|s
parameter_list|)
endif|#
directive|endif
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
comment|/* _SYS_NOTE_H */
end_comment

end_unit

