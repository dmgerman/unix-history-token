begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)assert.h	4.3 (Berkeley) %G%  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NDEBUG
end_ifdef

begin_define
define|#
directive|define
name|assert
end_define

begin_define
define|#
directive|define
name|_assert
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|expression
parameter_list|)
value|{ \ 	if (!(expression)) { \ 		(void)fprintf(stderr, \ 		    "assertion \"%s\" failed: file \"%s\", line %d\n", \ 		    "expression", __FILE__, __LINE__); \ 		exit(2); \ 	} \ }
end_define

begin_define
define|#
directive|define
name|_assert
parameter_list|(
name|expression
parameter_list|)
value|assert(expression)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

