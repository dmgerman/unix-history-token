begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * lib_strbuf.h - definitions for routines which use the common string buffers  */
end_comment

begin_include
include|#
directive|include
file|<ntp_types.h>
end_include

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
value|do { \ 		if (!lib_inited) \ 			init_lib(); \ 		buf =&lib_stringbuf[lib_nextbuf][0]; \ 		if (++lib_nextbuf>= LIB_NUMBUFS) \ 			lib_nextbuf = 0; \ 	} while (0)
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

begin_decl_stmt
specifier|extern
name|int
name|lib_inited
decl_stmt|;
end_decl_stmt

end_unit

