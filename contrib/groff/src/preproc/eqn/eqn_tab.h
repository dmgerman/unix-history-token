begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|OVER
value|257
end_define

begin_define
define|#
directive|define
name|SMALLOVER
value|258
end_define

begin_define
define|#
directive|define
name|SQRT
value|259
end_define

begin_define
define|#
directive|define
name|SUB
value|260
end_define

begin_define
define|#
directive|define
name|SUP
value|261
end_define

begin_define
define|#
directive|define
name|LPILE
value|262
end_define

begin_define
define|#
directive|define
name|RPILE
value|263
end_define

begin_define
define|#
directive|define
name|CPILE
value|264
end_define

begin_define
define|#
directive|define
name|PILE
value|265
end_define

begin_define
define|#
directive|define
name|LEFT
value|266
end_define

begin_define
define|#
directive|define
name|RIGHT
value|267
end_define

begin_define
define|#
directive|define
name|TO
value|268
end_define

begin_define
define|#
directive|define
name|FROM
value|269
end_define

begin_define
define|#
directive|define
name|SIZE
value|270
end_define

begin_define
define|#
directive|define
name|FONT
value|271
end_define

begin_define
define|#
directive|define
name|ROMAN
value|272
end_define

begin_define
define|#
directive|define
name|BOLD
value|273
end_define

begin_define
define|#
directive|define
name|ITALIC
value|274
end_define

begin_define
define|#
directive|define
name|FAT
value|275
end_define

begin_define
define|#
directive|define
name|ACCENT
value|276
end_define

begin_define
define|#
directive|define
name|BAR
value|277
end_define

begin_define
define|#
directive|define
name|UNDER
value|278
end_define

begin_define
define|#
directive|define
name|ABOVE
value|279
end_define

begin_define
define|#
directive|define
name|TEXT
value|280
end_define

begin_define
define|#
directive|define
name|QUOTED_TEXT
value|281
end_define

begin_define
define|#
directive|define
name|FWD
value|282
end_define

begin_define
define|#
directive|define
name|BACK
value|283
end_define

begin_define
define|#
directive|define
name|DOWN
value|284
end_define

begin_define
define|#
directive|define
name|UP
value|285
end_define

begin_define
define|#
directive|define
name|MATRIX
value|286
end_define

begin_define
define|#
directive|define
name|COL
value|287
end_define

begin_define
define|#
directive|define
name|LCOL
value|288
end_define

begin_define
define|#
directive|define
name|RCOL
value|289
end_define

begin_define
define|#
directive|define
name|CCOL
value|290
end_define

begin_define
define|#
directive|define
name|MARK
value|291
end_define

begin_define
define|#
directive|define
name|LINEUP
value|292
end_define

begin_define
define|#
directive|define
name|TYPE
value|293
end_define

begin_define
define|#
directive|define
name|VCENTER
value|294
end_define

begin_define
define|#
directive|define
name|PRIME
value|295
end_define

begin_define
define|#
directive|define
name|SPLIT
value|296
end_define

begin_define
define|#
directive|define
name|NOSPLIT
value|297
end_define

begin_define
define|#
directive|define
name|UACCENT
value|298
end_define

begin_define
define|#
directive|define
name|SPECIAL
value|299
end_define

begin_define
define|#
directive|define
name|SPACE
value|300
end_define

begin_define
define|#
directive|define
name|GFONT
value|301
end_define

begin_define
define|#
directive|define
name|GSIZE
value|302
end_define

begin_define
define|#
directive|define
name|DEFINE
value|303
end_define

begin_define
define|#
directive|define
name|NDEFINE
value|304
end_define

begin_define
define|#
directive|define
name|TDEFINE
value|305
end_define

begin_define
define|#
directive|define
name|SDEFINE
value|306
end_define

begin_define
define|#
directive|define
name|UNDEF
value|307
end_define

begin_define
define|#
directive|define
name|IFDEF
value|308
end_define

begin_define
define|#
directive|define
name|INCLUDE
value|309
end_define

begin_define
define|#
directive|define
name|DELIM
value|310
end_define

begin_define
define|#
directive|define
name|CHARTYPE
value|311
end_define

begin_define
define|#
directive|define
name|SET
value|312
end_define

begin_define
define|#
directive|define
name|GRFONT
value|313
end_define

begin_define
define|#
directive|define
name|GBFONT
value|314
end_define

begin_typedef
typedef|typedef
union|union
block|{
name|char
modifier|*
name|str
decl_stmt|;
name|box
modifier|*
name|b
decl_stmt|;
name|pile_box
modifier|*
name|pb
decl_stmt|;
name|matrix_box
modifier|*
name|mb
decl_stmt|;
name|int
name|n
decl_stmt|;
name|column
modifier|*
name|col
decl_stmt|;
block|}
name|YYSTYPE
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|YYSTYPE
name|yylval
decl_stmt|;
end_decl_stmt

end_unit

