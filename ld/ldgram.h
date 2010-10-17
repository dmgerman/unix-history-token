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
name|bfd_vma
name|integer
decl_stmt|;
struct|struct
name|big_int
block|{
name|bfd_vma
name|integer
decl_stmt|;
name|char
modifier|*
name|str
decl_stmt|;
block|}
name|bigint
struct|;
name|fill_type
modifier|*
name|fill
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
specifier|const
name|char
modifier|*
name|cname
decl_stmt|;
name|struct
name|wildcard_spec
name|wildcard
decl_stmt|;
name|struct
name|wildcard_list
modifier|*
name|wildcard_list
decl_stmt|;
name|struct
name|name_list
modifier|*
name|name_list
decl_stmt|;
name|int
name|token
decl_stmt|;
name|union
name|etree_union
modifier|*
name|etree
decl_stmt|;
struct|struct
name|phdr_info
block|{
name|bfd_boolean
name|filehdr
decl_stmt|;
name|bfd_boolean
name|phdrs
decl_stmt|;
name|union
name|etree_union
modifier|*
name|at
decl_stmt|;
name|union
name|etree_union
modifier|*
name|flags
decl_stmt|;
block|}
name|phdr
struct|;
name|struct
name|lang_nocrossref
modifier|*
name|nocrossref
decl_stmt|;
name|struct
name|lang_output_section_phdr_list
modifier|*
name|section_phdr
decl_stmt|;
name|struct
name|bfd_elf_version_deps
modifier|*
name|deflist
decl_stmt|;
name|struct
name|bfd_elf_version_expr
modifier|*
name|versyms
decl_stmt|;
name|struct
name|bfd_elf_version_tree
modifier|*
name|versnode
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
name|INT
value|257
end_define

begin_define
define|#
directive|define
name|NAME
value|258
end_define

begin_define
define|#
directive|define
name|LNAME
value|259
end_define

begin_define
define|#
directive|define
name|PLUSEQ
value|260
end_define

begin_define
define|#
directive|define
name|MINUSEQ
value|261
end_define

begin_define
define|#
directive|define
name|MULTEQ
value|262
end_define

begin_define
define|#
directive|define
name|DIVEQ
value|263
end_define

begin_define
define|#
directive|define
name|LSHIFTEQ
value|264
end_define

begin_define
define|#
directive|define
name|RSHIFTEQ
value|265
end_define

begin_define
define|#
directive|define
name|ANDEQ
value|266
end_define

begin_define
define|#
directive|define
name|OREQ
value|267
end_define

begin_define
define|#
directive|define
name|OROR
value|268
end_define

begin_define
define|#
directive|define
name|ANDAND
value|269
end_define

begin_define
define|#
directive|define
name|EQ
value|270
end_define

begin_define
define|#
directive|define
name|NE
value|271
end_define

begin_define
define|#
directive|define
name|LE
value|272
end_define

begin_define
define|#
directive|define
name|GE
value|273
end_define

begin_define
define|#
directive|define
name|LSHIFT
value|274
end_define

begin_define
define|#
directive|define
name|RSHIFT
value|275
end_define

begin_define
define|#
directive|define
name|UNARY
value|276
end_define

begin_define
define|#
directive|define
name|END
value|277
end_define

begin_define
define|#
directive|define
name|ALIGN_K
value|278
end_define

begin_define
define|#
directive|define
name|BLOCK
value|279
end_define

begin_define
define|#
directive|define
name|BIND
value|280
end_define

begin_define
define|#
directive|define
name|QUAD
value|281
end_define

begin_define
define|#
directive|define
name|SQUAD
value|282
end_define

begin_define
define|#
directive|define
name|LONG
value|283
end_define

begin_define
define|#
directive|define
name|SHORT
value|284
end_define

begin_define
define|#
directive|define
name|BYTE
value|285
end_define

begin_define
define|#
directive|define
name|SECTIONS
value|286
end_define

begin_define
define|#
directive|define
name|PHDRS
value|287
end_define

begin_define
define|#
directive|define
name|SORT
value|288
end_define

begin_define
define|#
directive|define
name|DATA_SEGMENT_ALIGN
value|289
end_define

begin_define
define|#
directive|define
name|DATA_SEGMENT_END
value|290
end_define

begin_define
define|#
directive|define
name|SIZEOF_HEADERS
value|291
end_define

begin_define
define|#
directive|define
name|OUTPUT_FORMAT
value|292
end_define

begin_define
define|#
directive|define
name|FORCE_COMMON_ALLOCATION
value|293
end_define

begin_define
define|#
directive|define
name|OUTPUT_ARCH
value|294
end_define

begin_define
define|#
directive|define
name|INHIBIT_COMMON_ALLOCATION
value|295
end_define

begin_define
define|#
directive|define
name|INCLUDE
value|296
end_define

begin_define
define|#
directive|define
name|MEMORY
value|297
end_define

begin_define
define|#
directive|define
name|DEFSYMEND
value|298
end_define

begin_define
define|#
directive|define
name|NOLOAD
value|299
end_define

begin_define
define|#
directive|define
name|DSECT
value|300
end_define

begin_define
define|#
directive|define
name|COPY
value|301
end_define

begin_define
define|#
directive|define
name|INFO
value|302
end_define

begin_define
define|#
directive|define
name|OVERLAY
value|303
end_define

begin_define
define|#
directive|define
name|DEFINED
value|304
end_define

begin_define
define|#
directive|define
name|TARGET_K
value|305
end_define

begin_define
define|#
directive|define
name|SEARCH_DIR
value|306
end_define

begin_define
define|#
directive|define
name|MAP
value|307
end_define

begin_define
define|#
directive|define
name|ENTRY
value|308
end_define

begin_define
define|#
directive|define
name|NEXT
value|309
end_define

begin_define
define|#
directive|define
name|SIZEOF
value|310
end_define

begin_define
define|#
directive|define
name|ADDR
value|311
end_define

begin_define
define|#
directive|define
name|LOADADDR
value|312
end_define

begin_define
define|#
directive|define
name|MAX_K
value|313
end_define

begin_define
define|#
directive|define
name|MIN_K
value|314
end_define

begin_define
define|#
directive|define
name|STARTUP
value|315
end_define

begin_define
define|#
directive|define
name|HLL
value|316
end_define

begin_define
define|#
directive|define
name|SYSLIB
value|317
end_define

begin_define
define|#
directive|define
name|FLOAT
value|318
end_define

begin_define
define|#
directive|define
name|NOFLOAT
value|319
end_define

begin_define
define|#
directive|define
name|NOCROSSREFS
value|320
end_define

begin_define
define|#
directive|define
name|ORIGIN
value|321
end_define

begin_define
define|#
directive|define
name|FILL
value|322
end_define

begin_define
define|#
directive|define
name|LENGTH
value|323
end_define

begin_define
define|#
directive|define
name|CREATE_OBJECT_SYMBOLS
value|324
end_define

begin_define
define|#
directive|define
name|INPUT
value|325
end_define

begin_define
define|#
directive|define
name|GROUP
value|326
end_define

begin_define
define|#
directive|define
name|OUTPUT
value|327
end_define

begin_define
define|#
directive|define
name|CONSTRUCTORS
value|328
end_define

begin_define
define|#
directive|define
name|ALIGNMOD
value|329
end_define

begin_define
define|#
directive|define
name|AT
value|330
end_define

begin_define
define|#
directive|define
name|SUBALIGN
value|331
end_define

begin_define
define|#
directive|define
name|PROVIDE
value|332
end_define

begin_define
define|#
directive|define
name|CHIP
value|333
end_define

begin_define
define|#
directive|define
name|LIST
value|334
end_define

begin_define
define|#
directive|define
name|SECT
value|335
end_define

begin_define
define|#
directive|define
name|ABSOLUTE
value|336
end_define

begin_define
define|#
directive|define
name|LOAD
value|337
end_define

begin_define
define|#
directive|define
name|NEWLINE
value|338
end_define

begin_define
define|#
directive|define
name|ENDWORD
value|339
end_define

begin_define
define|#
directive|define
name|ORDER
value|340
end_define

begin_define
define|#
directive|define
name|NAMEWORD
value|341
end_define

begin_define
define|#
directive|define
name|ASSERT_K
value|342
end_define

begin_define
define|#
directive|define
name|FORMAT
value|343
end_define

begin_define
define|#
directive|define
name|PUBLIC
value|344
end_define

begin_define
define|#
directive|define
name|BASE
value|345
end_define

begin_define
define|#
directive|define
name|ALIAS
value|346
end_define

begin_define
define|#
directive|define
name|TRUNCATE
value|347
end_define

begin_define
define|#
directive|define
name|REL
value|348
end_define

begin_define
define|#
directive|define
name|INPUT_SCRIPT
value|349
end_define

begin_define
define|#
directive|define
name|INPUT_MRI_SCRIPT
value|350
end_define

begin_define
define|#
directive|define
name|INPUT_DEFSYM
value|351
end_define

begin_define
define|#
directive|define
name|CASE
value|352
end_define

begin_define
define|#
directive|define
name|EXTERN
value|353
end_define

begin_define
define|#
directive|define
name|START
value|354
end_define

begin_define
define|#
directive|define
name|VERS_TAG
value|355
end_define

begin_define
define|#
directive|define
name|VERS_IDENTIFIER
value|356
end_define

begin_define
define|#
directive|define
name|GLOBAL
value|357
end_define

begin_define
define|#
directive|define
name|LOCAL
value|358
end_define

begin_define
define|#
directive|define
name|VERSIONK
value|359
end_define

begin_define
define|#
directive|define
name|INPUT_VERSION_SCRIPT
value|360
end_define

begin_define
define|#
directive|define
name|KEEP
value|361
end_define

begin_define
define|#
directive|define
name|EXCLUDE_FILE
value|362
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

