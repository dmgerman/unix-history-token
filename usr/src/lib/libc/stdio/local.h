begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * %sccs.include.redist.c%  *  *	@(#)local.h	5.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Information local to this implementation of stdio,  * in particular, macros and private variables.  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|c_plusplus
end_if

begin_function_decl
specifier|extern
name|int
name|__sflush
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|__sfp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__srefill
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__sread
parameter_list|(
name|void
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__swrite
parameter_list|(
name|void
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|fpos_t
name|__sseek
parameter_list|(
name|void
modifier|*
parameter_list|,
name|fpos_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__sclose
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__sinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|__cleanup
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__smakebuf
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_fwalk
parameter_list|(
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|FILE
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STDC__ || c_plusplus */
end_comment

begin_function_decl
specifier|extern
name|int
name|__sflush
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|__sfp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__srefill
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__sread
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__swrite
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|fpos_t
name|__sseek
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__sclose
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__sinit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cleanup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|__cleanup
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__smakebuf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__sfwalk
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ || c_plusplus */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|__sdidinit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Return true iff the given FILE cannot be written now.  */
end_comment

begin_define
define|#
directive|define
name|cantwrite
parameter_list|(
name|fp
parameter_list|)
define|\
value|((((fp)->_flags& __SWR) == 0 || (fp)->_bf._base == NULL)&& \ 	 __swsetup(fp))
end_define

begin_comment
comment|/*  * Test whether the given stdio file has an active ungetc buffer;  * release such a buffer, without restoring ordinary unread data.  */
end_comment

begin_define
define|#
directive|define
name|HASUB
parameter_list|(
name|fp
parameter_list|)
value|((fp)->_ub._base != NULL)
end_define

begin_define
define|#
directive|define
name|FREEUB
parameter_list|(
name|fp
parameter_list|)
value|{ \ 	if ((fp)->_ub._base != (fp)->_ubuf) \ 		free((char *)(fp)->_ub._base); \ 	(fp)->_ub._base = NULL; \ }
end_define

begin_comment
comment|/*  * test for an fgetline() buffer.  */
end_comment

begin_define
define|#
directive|define
name|HASLB
parameter_list|(
name|fp
parameter_list|)
value|((fp)->_lb._base != NULL)
end_define

begin_define
define|#
directive|define
name|FREELB
parameter_list|(
name|fp
parameter_list|)
value|{ \ 	free((char *)(fp)->_lb._base); \ 	(fp)->_lb._base = NULL; \ }
end_define

end_unit

