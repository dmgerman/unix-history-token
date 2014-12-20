begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * lib_strbuf.h - definitions for routines which use the common string buffers  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LIB_STRBUF_H
end_ifndef

begin_define
define|#
directive|define
name|LIB_STRBUF_H
end_define

begin_include
include|#
directive|include
file|<ntp_types.h>
end_include

begin_include
include|#
directive|include
file|<ntp_malloc.h>
end_include

begin_comment
comment|/* for ZERO() */
end_comment

begin_comment
comment|/*  * Sizes of things  */
end_comment

begin_define
define|#
directive|define
name|LIB_NUMBUF
value|16
end_define

begin_define
define|#
directive|define
name|LIB_BUFLENGTH
value|128
end_define

begin_typedef
typedef|typedef
name|char
name|libbufstr
index|[
name|LIB_BUFLENGTH
index|]
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|libbufstr
name|lib_stringbuf
index|[
name|LIB_NUMBUF
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

begin_comment
comment|/*  * Macro to get a pointer to the next buffer  */
end_comment

begin_define
define|#
directive|define
name|LIB_GETBUF
parameter_list|(
name|bufp
parameter_list|)
define|\
value|do {							\ 		ZERO(lib_stringbuf[lib_nextbuf]);		\ 		(bufp) =&lib_stringbuf[lib_nextbuf++][0];	\ 		lib_nextbuf %= COUNTOF(lib_stringbuf);		\ 	} while (FALSE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIB_STRBUF_H */
end_comment

end_unit

