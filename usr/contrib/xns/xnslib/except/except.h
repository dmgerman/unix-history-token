begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * except.h  *  * Definitions and macros for C exception mechanism  *  (c) Jeffrey Mogul	Stanford	18 February 1983  */
end_comment

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_Except_buf_x
block|{
name|struct
name|_Except_buf_x
modifier|*
name|Prev
decl_stmt|;
comment|/* exception chain back-pointer */
name|jmp_buf
name|Environ
decl_stmt|;
comment|/* saved environment */
name|char
modifier|*
name|Message
decl_stmt|;
comment|/* Human-readable cause */
name|int
name|Code
decl_stmt|;
comment|/* Exception code */
block|}
name|_Except_Buf
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|_Except_Buf
modifier|*
name|_Except_Header
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global exception chain header */
end_comment

begin_comment
comment|/*  * "syntax":  *	DURING statement HANDLER statement END_HANDLER  */
end_comment

begin_define
define|#
directive|define
name|_E_RESTORE
value|_Except_Header = Exception.Prev
end_define

begin_define
define|#
directive|define
name|DURING
value|{_Except_Buf Exception;\ 		 Exception.Prev=_Except_Header;\ 		 _Except_Header=&Exception;\ 		 if (!setjmp(Exception.Environ)) {
end_define

begin_define
define|#
directive|define
name|HANDLER
value|_E_RESTORE;} else
end_define

begin_define
define|#
directive|define
name|END_HANDLER
value|}
end_define

begin_define
define|#
directive|define
name|E_RETURN
parameter_list|(
name|x
parameter_list|)
value|{_E_RESTORE; return(x);}
end_define

begin_define
define|#
directive|define
name|E_RETURN_VOID
value|{_E_RESTORE; return;}
end_define

begin_define
define|#
directive|define
name|RERAISE
value|raise(Exception.Code, Exception.Message)
end_define

begin_comment
comment|/*  * Exception modes (combined with ||):  */
end_comment

begin_define
define|#
directive|define
name|EX_MODE_REPORT
value|1
end_define

begin_comment
comment|/* report uncaught errors on stderr */
end_comment

begin_define
define|#
directive|define
name|EX_MODE_ABORT
value|2
end_define

begin_comment
comment|/* abort if uncaught error */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ExceptMode
decl_stmt|;
end_decl_stmt

end_unit

