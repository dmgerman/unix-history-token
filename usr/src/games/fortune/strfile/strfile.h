begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: strfile.h,v 1.10 88/07/28 19:11:02 arnold Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STRFILE__
end_ifndef

begin_define
define|#
directive|define
name|__STRFILE__
end_define

begin_comment
comment|/*  * bits for flag field  */
end_comment

begin_define
define|#
directive|define
name|STR_RANDOM
value|0x1
end_define

begin_define
define|#
directive|define
name|STR_ORDERED
value|0x2
end_define

begin_define
define|#
directive|define
name|STR_ENDSTRING
parameter_list|(
name|line
parameter_list|,
name|tbl
parameter_list|)
value|((line)[0] == (tbl).str_delim&& (line)[1] == (tbl).str_delim)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* information table */
name|unsigned
name|long
name|str_numstr
decl_stmt|;
comment|/* # of strings in the file */
name|unsigned
name|long
name|str_longlen
decl_stmt|;
comment|/* length of longest string */
name|unsigned
name|long
name|str_shortlen
decl_stmt|;
comment|/* length of shortest string */
name|unsigned
name|char
name|str_flags
decl_stmt|;
comment|/* bit field for flags */
name|char
name|str_delim
decl_stmt|;
comment|/* delimiting character */
block|}
name|STRFILE
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STRFILE__ */
end_comment

end_unit

