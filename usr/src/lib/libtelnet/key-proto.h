begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)key-proto.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Copyright (C) 1990 by the Massachusetts Institute of Technology  *  * Export of this software from the United States of America is assumed  * to require a specific license from the United States Government.  * It is the responsibility of any person or organization contemplating  * export to obtain such a license before exporting.  *  * WITHIN THAT CONSTRAINT, permission to use, copy, modify, and  * distribute this software and its documentation for any purpose and  * without fee is hereby granted, provided that the above copyright  * notice appear in all copies and that both that copyright notice and  * this permission notice appear in supporting documentation, and that  * the name of M.I.T. not be used in advertising or publicity pertaining  * to distribution of the software without specific, written prior  * permission.  M.I.T. makes no representations about the suitability of  * this software for any purpose.  It is provided "as is" without express  * or implied warranty.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KEY_PROTO__
end_ifndef

begin_define
define|#
directive|define
name|__KEY_PROTO__
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|P
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|key_file_exists
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|key_lookup
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|,
name|Block
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|key_stream_init
name|P
argument_list|(
operator|(
name|Block
operator|,
name|Block
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|char
name|key_stream
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

