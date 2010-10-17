begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|BISON_Y_TAB_H
end_ifndef

begin_define
define|#
directive|define
name|BISON_Y_TAB_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|YYSTYPE
end_ifndef

begin_typedef
typedef|typedef
union|union
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|list
modifier|*
name|list
decl_stmt|;
block|}
name|yystype
typedef|;
end_typedef

begin_define
define|#
directive|define
name|YYSTYPE
value|yystype
end_define

begin_define
define|#
directive|define
name|YYSTYPE_IS_TRIVIAL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NEWLINE
value|257
end_define

begin_define
define|#
directive|define
name|VERBOSE
value|258
end_define

begin_define
define|#
directive|define
name|FILENAME
value|259
end_define

begin_define
define|#
directive|define
name|ADDLIB
value|260
end_define

begin_define
define|#
directive|define
name|LIST
value|261
end_define

begin_define
define|#
directive|define
name|ADDMOD
value|262
end_define

begin_define
define|#
directive|define
name|CLEAR
value|263
end_define

begin_define
define|#
directive|define
name|CREATE
value|264
end_define

begin_define
define|#
directive|define
name|DELETE
value|265
end_define

begin_define
define|#
directive|define
name|DIRECTORY
value|266
end_define

begin_define
define|#
directive|define
name|END
value|267
end_define

begin_define
define|#
directive|define
name|EXTRACT
value|268
end_define

begin_define
define|#
directive|define
name|FULLDIR
value|269
end_define

begin_define
define|#
directive|define
name|HELP
value|270
end_define

begin_define
define|#
directive|define
name|QUIT
value|271
end_define

begin_define
define|#
directive|define
name|REPLACE
value|272
end_define

begin_define
define|#
directive|define
name|SAVE
value|273
end_define

begin_define
define|#
directive|define
name|OPEN
value|274
end_define

begin_decl_stmt
specifier|extern
name|YYSTYPE
name|yylval
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not BISON_Y_TAB_H */
end_comment

end_unit

