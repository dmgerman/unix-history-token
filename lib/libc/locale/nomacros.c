begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Tell<ctype.h> to generate extern versions of all its inline  * functions.  The extern versions get called if the system doesn't  * support inlines or the user defines _DONT_USE_CTYPE_INLINE_  * before including<ctype.h>.  */
end_comment

begin_define
define|#
directive|define
name|_EXTERNALIZE_CTYPE_INLINES_
end_define

begin_include
include|#
directive|include
file|<ctype.h>
end_include

end_unit

