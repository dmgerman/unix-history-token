begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_typedef
typedef|typedef
union|union
block|{
name|char
modifier|*
name|id
decl_stmt|;
name|int
name|number
decl_stmt|;
block|}
name|YYSTYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NAME
value|258
end_define

begin_define
define|#
directive|define
name|LIBRARY
value|259
end_define

begin_define
define|#
directive|define
name|DESCRIPTION
value|260
end_define

begin_define
define|#
directive|define
name|STACKSIZE
value|261
end_define

begin_define
define|#
directive|define
name|HEAPSIZE
value|262
end_define

begin_define
define|#
directive|define
name|CODE
value|263
end_define

begin_define
define|#
directive|define
name|DATA
value|264
end_define

begin_define
define|#
directive|define
name|SECTIONS
value|265
end_define

begin_define
define|#
directive|define
name|EXPORTS
value|266
end_define

begin_define
define|#
directive|define
name|IMPORTS
value|267
end_define

begin_define
define|#
directive|define
name|VERSIONK
value|268
end_define

begin_define
define|#
directive|define
name|BASE
value|269
end_define

begin_define
define|#
directive|define
name|CONSTANT
value|270
end_define

begin_define
define|#
directive|define
name|READ
value|271
end_define

begin_define
define|#
directive|define
name|WRITE
value|272
end_define

begin_define
define|#
directive|define
name|EXECUTE
value|273
end_define

begin_define
define|#
directive|define
name|SHARED
value|274
end_define

begin_define
define|#
directive|define
name|NONAME
value|275
end_define

begin_define
define|#
directive|define
name|ID
value|276
end_define

begin_define
define|#
directive|define
name|NUMBER
value|277
end_define

begin_decl_stmt
specifier|extern
name|YYSTYPE
name|yylval
decl_stmt|;
end_decl_stmt

end_unit

