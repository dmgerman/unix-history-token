begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* lib_strbuf.h,v 3.1 1993/07/06 01:08:28 jbj Exp  * lib_strbuf.h - definitions for routines which use the common string buffers  */
end_comment

begin_comment
comment|/*  * Sizes of things  */
end_comment

begin_define
define|#
directive|define
name|LIB_NUMBUFS
value|20
end_define

begin_define
define|#
directive|define
name|LIB_BUFLENGTH
value|80
end_define

begin_comment
comment|/*  * Macro to get a pointer to the next buffer  */
end_comment

begin_define
define|#
directive|define
name|LIB_GETBUF
parameter_list|(
name|buf
parameter_list|)
define|\
value|do { \ 		buf =&lib_stringbuf[lib_nextbuf][0]; \ 		if (++lib_nextbuf>= LIB_NUMBUFS) \ 			lib_nextbuf = 0; \ 	} while (0)
end_define

begin_decl_stmt
specifier|extern
name|char
name|lib_stringbuf
index|[
name|LIB_NUMBUFS
index|]
index|[
name|LIB_BUFLENGTH
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lib_nextbuf
decl_stmt|;
end_decl_stmt

end_unit

