begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_typedef
typedef|typedef
union|union
block|{
name|char
modifier|*
name|s_value
decl_stmt|;
name|char
name|c_value
decl_stmt|;
name|int
name|i_value
decl_stmt|;
name|arg_list
modifier|*
name|a_value
decl_stmt|;
block|}
name|YYSTYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NEWLINE
value|258
end_define

begin_define
define|#
directive|define
name|AND
value|259
end_define

begin_define
define|#
directive|define
name|OR
value|260
end_define

begin_define
define|#
directive|define
name|NOT
value|261
end_define

begin_define
define|#
directive|define
name|STRING
value|262
end_define

begin_define
define|#
directive|define
name|NAME
value|263
end_define

begin_define
define|#
directive|define
name|NUMBER
value|264
end_define

begin_define
define|#
directive|define
name|ASSIGN_OP
value|265
end_define

begin_define
define|#
directive|define
name|REL_OP
value|266
end_define

begin_define
define|#
directive|define
name|INCR_DECR
value|267
end_define

begin_define
define|#
directive|define
name|Define
value|268
end_define

begin_define
define|#
directive|define
name|Break
value|269
end_define

begin_define
define|#
directive|define
name|Quit
value|270
end_define

begin_define
define|#
directive|define
name|Length
value|271
end_define

begin_define
define|#
directive|define
name|Return
value|272
end_define

begin_define
define|#
directive|define
name|For
value|273
end_define

begin_define
define|#
directive|define
name|If
value|274
end_define

begin_define
define|#
directive|define
name|While
value|275
end_define

begin_define
define|#
directive|define
name|Sqrt
value|276
end_define

begin_define
define|#
directive|define
name|Else
value|277
end_define

begin_define
define|#
directive|define
name|Scale
value|278
end_define

begin_define
define|#
directive|define
name|Ibase
value|279
end_define

begin_define
define|#
directive|define
name|Obase
value|280
end_define

begin_define
define|#
directive|define
name|Auto
value|281
end_define

begin_define
define|#
directive|define
name|Read
value|282
end_define

begin_define
define|#
directive|define
name|Warranty
value|283
end_define

begin_define
define|#
directive|define
name|Halt
value|284
end_define

begin_define
define|#
directive|define
name|Last
value|285
end_define

begin_define
define|#
directive|define
name|Continue
value|286
end_define

begin_define
define|#
directive|define
name|Print
value|287
end_define

begin_define
define|#
directive|define
name|Limits
value|288
end_define

begin_define
define|#
directive|define
name|UNARY_MINUS
value|289
end_define

begin_define
define|#
directive|define
name|History
value|290
end_define

begin_decl_stmt
specifier|extern
name|YYSTYPE
name|yylval
decl_stmt|;
end_decl_stmt

end_unit

