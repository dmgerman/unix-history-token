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
value|257
end_define

begin_define
define|#
directive|define
name|LIBRARY
value|258
end_define

begin_define
define|#
directive|define
name|DESCRIPTION
value|259
end_define

begin_define
define|#
directive|define
name|STACKSIZE
value|260
end_define

begin_define
define|#
directive|define
name|HEAPSIZE
value|261
end_define

begin_define
define|#
directive|define
name|CODE
value|262
end_define

begin_define
define|#
directive|define
name|DATA
value|263
end_define

begin_define
define|#
directive|define
name|SECTIONS
value|264
end_define

begin_define
define|#
directive|define
name|EXPORTS
value|265
end_define

begin_define
define|#
directive|define
name|IMPORTS
value|266
end_define

begin_define
define|#
directive|define
name|VERSIONK
value|267
end_define

begin_define
define|#
directive|define
name|BASE
value|268
end_define

begin_define
define|#
directive|define
name|CONSTANT
value|269
end_define

begin_define
define|#
directive|define
name|READ
value|270
end_define

begin_define
define|#
directive|define
name|WRITE
value|271
end_define

begin_define
define|#
directive|define
name|EXECUTE
value|272
end_define

begin_define
define|#
directive|define
name|SHARED
value|273
end_define

begin_define
define|#
directive|define
name|NONSHARED
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
name|SINGLE
value|276
end_define

begin_define
define|#
directive|define
name|MULTIPLE
value|277
end_define

begin_define
define|#
directive|define
name|INITINSTANCE
value|278
end_define

begin_define
define|#
directive|define
name|INITGLOBAL
value|279
end_define

begin_define
define|#
directive|define
name|TERMINSTANCE
value|280
end_define

begin_define
define|#
directive|define
name|TERMGLOBAL
value|281
end_define

begin_define
define|#
directive|define
name|ID
value|282
end_define

begin_define
define|#
directive|define
name|NUMBER
value|283
end_define

begin_decl_stmt
specifier|extern
name|YYSTYPE
name|yylval
decl_stmt|;
end_decl_stmt

end_unit

