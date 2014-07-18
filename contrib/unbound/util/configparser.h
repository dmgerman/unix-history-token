begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|SPACE
value|257
end_define

begin_define
define|#
directive|define
name|LETTER
value|258
end_define

begin_define
define|#
directive|define
name|NEWLINE
value|259
end_define

begin_define
define|#
directive|define
name|COMMENT
value|260
end_define

begin_define
define|#
directive|define
name|COLON
value|261
end_define

begin_define
define|#
directive|define
name|ANY
value|262
end_define

begin_define
define|#
directive|define
name|ZONESTR
value|263
end_define

begin_define
define|#
directive|define
name|STRING_ARG
value|264
end_define

begin_define
define|#
directive|define
name|VAR_SERVER
value|265
end_define

begin_define
define|#
directive|define
name|VAR_VERBOSITY
value|266
end_define

begin_define
define|#
directive|define
name|VAR_NUM_THREADS
value|267
end_define

begin_define
define|#
directive|define
name|VAR_PORT
value|268
end_define

begin_define
define|#
directive|define
name|VAR_OUTGOING_RANGE
value|269
end_define

begin_define
define|#
directive|define
name|VAR_INTERFACE
value|270
end_define

begin_define
define|#
directive|define
name|VAR_DO_IP4
value|271
end_define

begin_define
define|#
directive|define
name|VAR_DO_IP6
value|272
end_define

begin_define
define|#
directive|define
name|VAR_DO_UDP
value|273
end_define

begin_define
define|#
directive|define
name|VAR_DO_TCP
value|274
end_define

begin_define
define|#
directive|define
name|VAR_CHROOT
value|275
end_define

begin_define
define|#
directive|define
name|VAR_USERNAME
value|276
end_define

begin_define
define|#
directive|define
name|VAR_DIRECTORY
value|277
end_define

begin_define
define|#
directive|define
name|VAR_LOGFILE
value|278
end_define

begin_define
define|#
directive|define
name|VAR_PIDFILE
value|279
end_define

begin_define
define|#
directive|define
name|VAR_MSG_CACHE_SIZE
value|280
end_define

begin_define
define|#
directive|define
name|VAR_MSG_CACHE_SLABS
value|281
end_define

begin_define
define|#
directive|define
name|VAR_NUM_QUERIES_PER_THREAD
value|282
end_define

begin_define
define|#
directive|define
name|VAR_RRSET_CACHE_SIZE
value|283
end_define

begin_define
define|#
directive|define
name|VAR_RRSET_CACHE_SLABS
value|284
end_define

begin_define
define|#
directive|define
name|VAR_OUTGOING_NUM_TCP
value|285
end_define

begin_define
define|#
directive|define
name|VAR_INFRA_HOST_TTL
value|286
end_define

begin_define
define|#
directive|define
name|VAR_INFRA_LAME_TTL
value|287
end_define

begin_define
define|#
directive|define
name|VAR_INFRA_CACHE_SLABS
value|288
end_define

begin_define
define|#
directive|define
name|VAR_INFRA_CACHE_NUMHOSTS
value|289
end_define

begin_define
define|#
directive|define
name|VAR_INFRA_CACHE_LAME_SIZE
value|290
end_define

begin_define
define|#
directive|define
name|VAR_NAME
value|291
end_define

begin_define
define|#
directive|define
name|VAR_STUB_ZONE
value|292
end_define

begin_define
define|#
directive|define
name|VAR_STUB_HOST
value|293
end_define

begin_define
define|#
directive|define
name|VAR_STUB_ADDR
value|294
end_define

begin_define
define|#
directive|define
name|VAR_TARGET_FETCH_POLICY
value|295
end_define

begin_define
define|#
directive|define
name|VAR_HARDEN_SHORT_BUFSIZE
value|296
end_define

begin_define
define|#
directive|define
name|VAR_HARDEN_LARGE_QUERIES
value|297
end_define

begin_define
define|#
directive|define
name|VAR_FORWARD_ZONE
value|298
end_define

begin_define
define|#
directive|define
name|VAR_FORWARD_HOST
value|299
end_define

begin_define
define|#
directive|define
name|VAR_FORWARD_ADDR
value|300
end_define

begin_define
define|#
directive|define
name|VAR_DO_NOT_QUERY_ADDRESS
value|301
end_define

begin_define
define|#
directive|define
name|VAR_HIDE_IDENTITY
value|302
end_define

begin_define
define|#
directive|define
name|VAR_HIDE_VERSION
value|303
end_define

begin_define
define|#
directive|define
name|VAR_IDENTITY
value|304
end_define

begin_define
define|#
directive|define
name|VAR_VERSION
value|305
end_define

begin_define
define|#
directive|define
name|VAR_HARDEN_GLUE
value|306
end_define

begin_define
define|#
directive|define
name|VAR_MODULE_CONF
value|307
end_define

begin_define
define|#
directive|define
name|VAR_TRUST_ANCHOR_FILE
value|308
end_define

begin_define
define|#
directive|define
name|VAR_TRUST_ANCHOR
value|309
end_define

begin_define
define|#
directive|define
name|VAR_VAL_OVERRIDE_DATE
value|310
end_define

begin_define
define|#
directive|define
name|VAR_BOGUS_TTL
value|311
end_define

begin_define
define|#
directive|define
name|VAR_VAL_CLEAN_ADDITIONAL
value|312
end_define

begin_define
define|#
directive|define
name|VAR_VAL_PERMISSIVE_MODE
value|313
end_define

begin_define
define|#
directive|define
name|VAR_INCOMING_NUM_TCP
value|314
end_define

begin_define
define|#
directive|define
name|VAR_MSG_BUFFER_SIZE
value|315
end_define

begin_define
define|#
directive|define
name|VAR_KEY_CACHE_SIZE
value|316
end_define

begin_define
define|#
directive|define
name|VAR_KEY_CACHE_SLABS
value|317
end_define

begin_define
define|#
directive|define
name|VAR_TRUSTED_KEYS_FILE
value|318
end_define

begin_define
define|#
directive|define
name|VAR_VAL_NSEC3_KEYSIZE_ITERATIONS
value|319
end_define

begin_define
define|#
directive|define
name|VAR_USE_SYSLOG
value|320
end_define

begin_define
define|#
directive|define
name|VAR_OUTGOING_INTERFACE
value|321
end_define

begin_define
define|#
directive|define
name|VAR_ROOT_HINTS
value|322
end_define

begin_define
define|#
directive|define
name|VAR_DO_NOT_QUERY_LOCALHOST
value|323
end_define

begin_define
define|#
directive|define
name|VAR_CACHE_MAX_TTL
value|324
end_define

begin_define
define|#
directive|define
name|VAR_HARDEN_DNSSEC_STRIPPED
value|325
end_define

begin_define
define|#
directive|define
name|VAR_ACCESS_CONTROL
value|326
end_define

begin_define
define|#
directive|define
name|VAR_LOCAL_ZONE
value|327
end_define

begin_define
define|#
directive|define
name|VAR_LOCAL_DATA
value|328
end_define

begin_define
define|#
directive|define
name|VAR_INTERFACE_AUTOMATIC
value|329
end_define

begin_define
define|#
directive|define
name|VAR_STATISTICS_INTERVAL
value|330
end_define

begin_define
define|#
directive|define
name|VAR_DO_DAEMONIZE
value|331
end_define

begin_define
define|#
directive|define
name|VAR_USE_CAPS_FOR_ID
value|332
end_define

begin_define
define|#
directive|define
name|VAR_STATISTICS_CUMULATIVE
value|333
end_define

begin_define
define|#
directive|define
name|VAR_OUTGOING_PORT_PERMIT
value|334
end_define

begin_define
define|#
directive|define
name|VAR_OUTGOING_PORT_AVOID
value|335
end_define

begin_define
define|#
directive|define
name|VAR_DLV_ANCHOR_FILE
value|336
end_define

begin_define
define|#
directive|define
name|VAR_DLV_ANCHOR
value|337
end_define

begin_define
define|#
directive|define
name|VAR_NEG_CACHE_SIZE
value|338
end_define

begin_define
define|#
directive|define
name|VAR_HARDEN_REFERRAL_PATH
value|339
end_define

begin_define
define|#
directive|define
name|VAR_PRIVATE_ADDRESS
value|340
end_define

begin_define
define|#
directive|define
name|VAR_PRIVATE_DOMAIN
value|341
end_define

begin_define
define|#
directive|define
name|VAR_REMOTE_CONTROL
value|342
end_define

begin_define
define|#
directive|define
name|VAR_CONTROL_ENABLE
value|343
end_define

begin_define
define|#
directive|define
name|VAR_CONTROL_INTERFACE
value|344
end_define

begin_define
define|#
directive|define
name|VAR_CONTROL_PORT
value|345
end_define

begin_define
define|#
directive|define
name|VAR_SERVER_KEY_FILE
value|346
end_define

begin_define
define|#
directive|define
name|VAR_SERVER_CERT_FILE
value|347
end_define

begin_define
define|#
directive|define
name|VAR_CONTROL_KEY_FILE
value|348
end_define

begin_define
define|#
directive|define
name|VAR_CONTROL_CERT_FILE
value|349
end_define

begin_define
define|#
directive|define
name|VAR_EXTENDED_STATISTICS
value|350
end_define

begin_define
define|#
directive|define
name|VAR_LOCAL_DATA_PTR
value|351
end_define

begin_define
define|#
directive|define
name|VAR_JOSTLE_TIMEOUT
value|352
end_define

begin_define
define|#
directive|define
name|VAR_STUB_PRIME
value|353
end_define

begin_define
define|#
directive|define
name|VAR_UNWANTED_REPLY_THRESHOLD
value|354
end_define

begin_define
define|#
directive|define
name|VAR_LOG_TIME_ASCII
value|355
end_define

begin_define
define|#
directive|define
name|VAR_DOMAIN_INSECURE
value|356
end_define

begin_define
define|#
directive|define
name|VAR_PYTHON
value|357
end_define

begin_define
define|#
directive|define
name|VAR_PYTHON_SCRIPT
value|358
end_define

begin_define
define|#
directive|define
name|VAR_VAL_SIG_SKEW_MIN
value|359
end_define

begin_define
define|#
directive|define
name|VAR_VAL_SIG_SKEW_MAX
value|360
end_define

begin_define
define|#
directive|define
name|VAR_CACHE_MIN_TTL
value|361
end_define

begin_define
define|#
directive|define
name|VAR_VAL_LOG_LEVEL
value|362
end_define

begin_define
define|#
directive|define
name|VAR_AUTO_TRUST_ANCHOR_FILE
value|363
end_define

begin_define
define|#
directive|define
name|VAR_KEEP_MISSING
value|364
end_define

begin_define
define|#
directive|define
name|VAR_ADD_HOLDDOWN
value|365
end_define

begin_define
define|#
directive|define
name|VAR_DEL_HOLDDOWN
value|366
end_define

begin_define
define|#
directive|define
name|VAR_SO_RCVBUF
value|367
end_define

begin_define
define|#
directive|define
name|VAR_EDNS_BUFFER_SIZE
value|368
end_define

begin_define
define|#
directive|define
name|VAR_PREFETCH
value|369
end_define

begin_define
define|#
directive|define
name|VAR_PREFETCH_KEY
value|370
end_define

begin_define
define|#
directive|define
name|VAR_SO_SNDBUF
value|371
end_define

begin_define
define|#
directive|define
name|VAR_SO_REUSEPORT
value|372
end_define

begin_define
define|#
directive|define
name|VAR_HARDEN_BELOW_NXDOMAIN
value|373
end_define

begin_define
define|#
directive|define
name|VAR_IGNORE_CD_FLAG
value|374
end_define

begin_define
define|#
directive|define
name|VAR_LOG_QUERIES
value|375
end_define

begin_define
define|#
directive|define
name|VAR_TCP_UPSTREAM
value|376
end_define

begin_define
define|#
directive|define
name|VAR_SSL_UPSTREAM
value|377
end_define

begin_define
define|#
directive|define
name|VAR_SSL_SERVICE_KEY
value|378
end_define

begin_define
define|#
directive|define
name|VAR_SSL_SERVICE_PEM
value|379
end_define

begin_define
define|#
directive|define
name|VAR_SSL_PORT
value|380
end_define

begin_define
define|#
directive|define
name|VAR_FORWARD_FIRST
value|381
end_define

begin_define
define|#
directive|define
name|VAR_STUB_FIRST
value|382
end_define

begin_define
define|#
directive|define
name|VAR_MINIMAL_RESPONSES
value|383
end_define

begin_define
define|#
directive|define
name|VAR_RRSET_ROUNDROBIN
value|384
end_define

begin_define
define|#
directive|define
name|VAR_MAX_UDP_SIZE
value|385
end_define

begin_define
define|#
directive|define
name|VAR_DELAY_CLOSE
value|386
end_define

begin_define
define|#
directive|define
name|VAR_UNBLOCK_LAN_ZONES
value|387
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|YYSTYPE
end_ifdef

begin_undef
undef|#
directive|undef
name|YYSTYPE_IS_DECLARED
end_undef

begin_define
define|#
directive|define
name|YYSTYPE_IS_DECLARED
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|YYSTYPE_IS_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|YYSTYPE_IS_DECLARED
value|1
end_define

begin_typedef
typedef|typedef
union|union
block|{
name|char
modifier|*
name|str
decl_stmt|;
block|}
name|YYSTYPE
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !YYSTYPE_IS_DECLARED */
end_comment

begin_decl_stmt
specifier|extern
name|YYSTYPE
name|yylval
decl_stmt|;
end_decl_stmt

end_unit

