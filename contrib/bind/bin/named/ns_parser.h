begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|YYEMPTY
value|(-1)
end_define

begin_define
define|#
directive|define
name|L_EOS
value|257
end_define

begin_define
define|#
directive|define
name|L_IPADDR
value|258
end_define

begin_define
define|#
directive|define
name|L_NUMBER
value|259
end_define

begin_define
define|#
directive|define
name|L_STRING
value|260
end_define

begin_define
define|#
directive|define
name|L_QSTRING
value|261
end_define

begin_define
define|#
directive|define
name|L_END_INCLUDE
value|262
end_define

begin_define
define|#
directive|define
name|T_INCLUDE
value|263
end_define

begin_define
define|#
directive|define
name|T_OPTIONS
value|264
end_define

begin_define
define|#
directive|define
name|T_DIRECTORY
value|265
end_define

begin_define
define|#
directive|define
name|T_PIDFILE
value|266
end_define

begin_define
define|#
directive|define
name|T_NAMED_XFER
value|267
end_define

begin_define
define|#
directive|define
name|T_DUMP_FILE
value|268
end_define

begin_define
define|#
directive|define
name|T_STATS_FILE
value|269
end_define

begin_define
define|#
directive|define
name|T_MEMSTATS_FILE
value|270
end_define

begin_define
define|#
directive|define
name|T_FAKE_IQUERY
value|271
end_define

begin_define
define|#
directive|define
name|T_RECURSION
value|272
end_define

begin_define
define|#
directive|define
name|T_FETCH_GLUE
value|273
end_define

begin_define
define|#
directive|define
name|T_QUERY_SOURCE
value|274
end_define

begin_define
define|#
directive|define
name|T_LISTEN_ON
value|275
end_define

begin_define
define|#
directive|define
name|T_PORT
value|276
end_define

begin_define
define|#
directive|define
name|T_ADDRESS
value|277
end_define

begin_define
define|#
directive|define
name|T_DATASIZE
value|278
end_define

begin_define
define|#
directive|define
name|T_STACKSIZE
value|279
end_define

begin_define
define|#
directive|define
name|T_CORESIZE
value|280
end_define

begin_define
define|#
directive|define
name|T_DEFAULT
value|281
end_define

begin_define
define|#
directive|define
name|T_UNLIMITED
value|282
end_define

begin_define
define|#
directive|define
name|T_FILES
value|283
end_define

begin_define
define|#
directive|define
name|T_HOSTSTATS
value|284
end_define

begin_define
define|#
directive|define
name|T_DEALLOC_ON_EXIT
value|285
end_define

begin_define
define|#
directive|define
name|T_TRANSFERS_IN
value|286
end_define

begin_define
define|#
directive|define
name|T_TRANSFERS_OUT
value|287
end_define

begin_define
define|#
directive|define
name|T_TRANSFERS_PER_NS
value|288
end_define

begin_define
define|#
directive|define
name|T_TRANSFER_FORMAT
value|289
end_define

begin_define
define|#
directive|define
name|T_MAX_TRANSFER_TIME_IN
value|290
end_define

begin_define
define|#
directive|define
name|T_ONE_ANSWER
value|291
end_define

begin_define
define|#
directive|define
name|T_MANY_ANSWERS
value|292
end_define

begin_define
define|#
directive|define
name|T_NOTIFY
value|293
end_define

begin_define
define|#
directive|define
name|T_AUTH_NXDOMAIN
value|294
end_define

begin_define
define|#
directive|define
name|T_MULTIPLE_CNAMES
value|295
end_define

begin_define
define|#
directive|define
name|T_CLEAN_INTERVAL
value|296
end_define

begin_define
define|#
directive|define
name|T_INTERFACE_INTERVAL
value|297
end_define

begin_define
define|#
directive|define
name|T_STATS_INTERVAL
value|298
end_define

begin_define
define|#
directive|define
name|T_LOGGING
value|299
end_define

begin_define
define|#
directive|define
name|T_CATEGORY
value|300
end_define

begin_define
define|#
directive|define
name|T_CHANNEL
value|301
end_define

begin_define
define|#
directive|define
name|T_SEVERITY
value|302
end_define

begin_define
define|#
directive|define
name|T_DYNAMIC
value|303
end_define

begin_define
define|#
directive|define
name|T_FILE
value|304
end_define

begin_define
define|#
directive|define
name|T_VERSIONS
value|305
end_define

begin_define
define|#
directive|define
name|T_SIZE
value|306
end_define

begin_define
define|#
directive|define
name|T_SYSLOG
value|307
end_define

begin_define
define|#
directive|define
name|T_DEBUG
value|308
end_define

begin_define
define|#
directive|define
name|T_NULL_OUTPUT
value|309
end_define

begin_define
define|#
directive|define
name|T_PRINT_TIME
value|310
end_define

begin_define
define|#
directive|define
name|T_PRINT_CATEGORY
value|311
end_define

begin_define
define|#
directive|define
name|T_PRINT_SEVERITY
value|312
end_define

begin_define
define|#
directive|define
name|T_TOPOLOGY
value|313
end_define

begin_define
define|#
directive|define
name|T_SERVER
value|314
end_define

begin_define
define|#
directive|define
name|T_LONG_AXFR
value|315
end_define

begin_define
define|#
directive|define
name|T_BOGUS
value|316
end_define

begin_define
define|#
directive|define
name|T_TRANSFERS
value|317
end_define

begin_define
define|#
directive|define
name|T_KEYS
value|318
end_define

begin_define
define|#
directive|define
name|T_ZONE
value|319
end_define

begin_define
define|#
directive|define
name|T_IN
value|320
end_define

begin_define
define|#
directive|define
name|T_CHAOS
value|321
end_define

begin_define
define|#
directive|define
name|T_HESIOD
value|322
end_define

begin_define
define|#
directive|define
name|T_TYPE
value|323
end_define

begin_define
define|#
directive|define
name|T_MASTER
value|324
end_define

begin_define
define|#
directive|define
name|T_SLAVE
value|325
end_define

begin_define
define|#
directive|define
name|T_STUB
value|326
end_define

begin_define
define|#
directive|define
name|T_RESPONSE
value|327
end_define

begin_define
define|#
directive|define
name|T_HINT
value|328
end_define

begin_define
define|#
directive|define
name|T_MASTERS
value|329
end_define

begin_define
define|#
directive|define
name|T_TRANSFER_SOURCE
value|330
end_define

begin_define
define|#
directive|define
name|T_ALSO_NOTIFY
value|331
end_define

begin_define
define|#
directive|define
name|T_ACL
value|332
end_define

begin_define
define|#
directive|define
name|T_ALLOW_UPDATE
value|333
end_define

begin_define
define|#
directive|define
name|T_ALLOW_QUERY
value|334
end_define

begin_define
define|#
directive|define
name|T_ALLOW_TRANSFER
value|335
end_define

begin_define
define|#
directive|define
name|T_SEC_KEY
value|336
end_define

begin_define
define|#
directive|define
name|T_ALGID
value|337
end_define

begin_define
define|#
directive|define
name|T_SECRET
value|338
end_define

begin_define
define|#
directive|define
name|T_CHECK_NAMES
value|339
end_define

begin_define
define|#
directive|define
name|T_WARN
value|340
end_define

begin_define
define|#
directive|define
name|T_FAIL
value|341
end_define

begin_define
define|#
directive|define
name|T_IGNORE
value|342
end_define

begin_define
define|#
directive|define
name|T_FORWARD
value|343
end_define

begin_define
define|#
directive|define
name|T_FORWARDERS
value|344
end_define

begin_define
define|#
directive|define
name|T_ONLY
value|345
end_define

begin_define
define|#
directive|define
name|T_FIRST
value|346
end_define

begin_define
define|#
directive|define
name|T_IF_NO_ANSWER
value|347
end_define

begin_define
define|#
directive|define
name|T_IF_NO_DOMAIN
value|348
end_define

begin_define
define|#
directive|define
name|T_YES
value|349
end_define

begin_define
define|#
directive|define
name|T_TRUE
value|350
end_define

begin_define
define|#
directive|define
name|T_NO
value|351
end_define

begin_define
define|#
directive|define
name|T_FALSE
value|352
end_define

begin_typedef
typedef|typedef
union|union
block|{
name|char
modifier|*
name|cp
decl_stmt|;
name|int
name|s_int
decl_stmt|;
name|long
name|num
decl_stmt|;
name|u_long
name|ul_int
decl_stmt|;
name|u_int16_t
name|us_int
decl_stmt|;
name|struct
name|in_addr
name|ip_addr
decl_stmt|;
name|ip_match_element
name|ime
decl_stmt|;
name|ip_match_list
name|iml
decl_stmt|;
name|key_info
name|keyi
decl_stmt|;
name|enum
name|axfr_format
name|axfr_fmt
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

