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
name|string
decl_stmt|;
name|struct
name|string_list
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
name|CHECK
value|257
end_define

begin_define
define|#
directive|define
name|CODESTART
value|258
end_define

begin_define
define|#
directive|define
name|COPYRIGHT
value|259
end_define

begin_define
define|#
directive|define
name|CUSTOM
value|260
end_define

begin_define
define|#
directive|define
name|DATE
value|261
end_define

begin_define
define|#
directive|define
name|DEBUG
value|262
end_define

begin_define
define|#
directive|define
name|DESCRIPTION
value|263
end_define

begin_define
define|#
directive|define
name|EXIT
value|264
end_define

begin_define
define|#
directive|define
name|EXPORT
value|265
end_define

begin_define
define|#
directive|define
name|FLAG_ON
value|266
end_define

begin_define
define|#
directive|define
name|FLAG_OFF
value|267
end_define

begin_define
define|#
directive|define
name|FULLMAP
value|268
end_define

begin_define
define|#
directive|define
name|HELP
value|269
end_define

begin_define
define|#
directive|define
name|IMPORT
value|270
end_define

begin_define
define|#
directive|define
name|INPUT
value|271
end_define

begin_define
define|#
directive|define
name|MAP
value|272
end_define

begin_define
define|#
directive|define
name|MESSAGES
value|273
end_define

begin_define
define|#
directive|define
name|MODULE
value|274
end_define

begin_define
define|#
directive|define
name|MULTIPLE
value|275
end_define

begin_define
define|#
directive|define
name|OS_DOMAIN
value|276
end_define

begin_define
define|#
directive|define
name|OUTPUT
value|277
end_define

begin_define
define|#
directive|define
name|PSEUDOPREEMPTION
value|278
end_define

begin_define
define|#
directive|define
name|REENTRANT
value|279
end_define

begin_define
define|#
directive|define
name|SCREENNAME
value|280
end_define

begin_define
define|#
directive|define
name|SHARELIB
value|281
end_define

begin_define
define|#
directive|define
name|STACK
value|282
end_define

begin_define
define|#
directive|define
name|START
value|283
end_define

begin_define
define|#
directive|define
name|SYNCHRONIZE
value|284
end_define

begin_define
define|#
directive|define
name|THREADNAME
value|285
end_define

begin_define
define|#
directive|define
name|TYPE
value|286
end_define

begin_define
define|#
directive|define
name|VERBOSE
value|287
end_define

begin_define
define|#
directive|define
name|VERSIONK
value|288
end_define

begin_define
define|#
directive|define
name|XDCDATA
value|289
end_define

begin_define
define|#
directive|define
name|STRING
value|290
end_define

begin_define
define|#
directive|define
name|QUOTED_STRING
value|291
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

