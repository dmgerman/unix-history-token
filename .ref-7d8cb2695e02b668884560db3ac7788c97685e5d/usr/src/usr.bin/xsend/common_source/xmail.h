begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * %sccs.include.proprietary.c%  *  *	@(#)xmail.h	4.2 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<mp.h>
end_include

begin_decl_stmt
specifier|extern
name|MINT
modifier|*
name|x
decl_stmt|,
modifier|*
name|b
decl_stmt|,
modifier|*
name|one
decl_stmt|,
modifier|*
name|c64
decl_stmt|,
modifier|*
name|t45
decl_stmt|,
modifier|*
name|z
decl_stmt|,
modifier|*
name|q
decl_stmt|,
modifier|*
name|r
decl_stmt|,
modifier|*
name|two
decl_stmt|,
modifier|*
name|t15
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|buf
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|debug
end_ifdef

begin_define
define|#
directive|define
name|nin
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|m_in(x, 8, y)
end_define

begin_define
define|#
directive|define
name|nout
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|m_out(x, 8, y)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

