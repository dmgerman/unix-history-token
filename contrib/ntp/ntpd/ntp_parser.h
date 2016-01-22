begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* A Bison parser, made by GNU Bison 2.7.12-4996.  */
end_comment

begin_comment
comment|/* Bison interface for Yacc-like parsers in C           Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.        This program is free software: you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation, either version 3 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program.  If not, see<http://www.gnu.org/licenses/>.  */
end_comment

begin_comment
comment|/* As a special exception, you may create a larger work that contains    part or all of the Bison parser skeleton and distribute that work    under terms of your choice, so long as that work isn't itself a    parser generator using the skeleton or a modified version thereof    as a parser skeleton.  Alternatively, if you modify or redistribute    the parser skeleton itself, you may (at your option) remove this    special exception, which will cause the skeleton and the resulting    Bison output files to be licensed under the GNU General Public    License without this special exception.        This special exception was added by the Free Software Foundation in    version 2.2 of Bison.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|YY_YY_NTP_PARSER_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|YY_YY_NTP_PARSER_H_INCLUDED
end_define

begin_comment
comment|/* Enabling traces.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|YYDEBUG
end_ifndef

begin_define
define|#
directive|define
name|YYDEBUG
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|YYDEBUG
end_if

begin_decl_stmt
specifier|extern
name|int
name|yydebug
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Tokens.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|YYTOKENTYPE
end_ifndef

begin_define
define|#
directive|define
name|YYTOKENTYPE
end_define

begin_comment
comment|/* Put the tokens into the symbol table, so that GDB and other debuggers       know about them.  */
end_comment

begin_enum
enum|enum
name|yytokentype
block|{
name|T_Abbrev
init|=
literal|258
block|,
name|T_Age
init|=
literal|259
block|,
name|T_All
init|=
literal|260
block|,
name|T_Allan
init|=
literal|261
block|,
name|T_Allpeers
init|=
literal|262
block|,
name|T_Auth
init|=
literal|263
block|,
name|T_Autokey
init|=
literal|264
block|,
name|T_Automax
init|=
literal|265
block|,
name|T_Average
init|=
literal|266
block|,
name|T_Bclient
init|=
literal|267
block|,
name|T_Beacon
init|=
literal|268
block|,
name|T_Broadcast
init|=
literal|269
block|,
name|T_Broadcastclient
init|=
literal|270
block|,
name|T_Broadcastdelay
init|=
literal|271
block|,
name|T_Burst
init|=
literal|272
block|,
name|T_Calibrate
init|=
literal|273
block|,
name|T_Ceiling
init|=
literal|274
block|,
name|T_Clockstats
init|=
literal|275
block|,
name|T_Cohort
init|=
literal|276
block|,
name|T_ControlKey
init|=
literal|277
block|,
name|T_Crypto
init|=
literal|278
block|,
name|T_Cryptostats
init|=
literal|279
block|,
name|T_Ctl
init|=
literal|280
block|,
name|T_Day
init|=
literal|281
block|,
name|T_Default
init|=
literal|282
block|,
name|T_Digest
init|=
literal|283
block|,
name|T_Disable
init|=
literal|284
block|,
name|T_Discard
init|=
literal|285
block|,
name|T_Dispersion
init|=
literal|286
block|,
name|T_Double
init|=
literal|287
block|,
name|T_Driftfile
init|=
literal|288
block|,
name|T_Drop
init|=
literal|289
block|,
name|T_Dscp
init|=
literal|290
block|,
name|T_Ellipsis
init|=
literal|291
block|,
name|T_Enable
init|=
literal|292
block|,
name|T_End
init|=
literal|293
block|,
name|T_False
init|=
literal|294
block|,
name|T_File
init|=
literal|295
block|,
name|T_Filegen
init|=
literal|296
block|,
name|T_Filenum
init|=
literal|297
block|,
name|T_Flag1
init|=
literal|298
block|,
name|T_Flag2
init|=
literal|299
block|,
name|T_Flag3
init|=
literal|300
block|,
name|T_Flag4
init|=
literal|301
block|,
name|T_Flake
init|=
literal|302
block|,
name|T_Floor
init|=
literal|303
block|,
name|T_Freq
init|=
literal|304
block|,
name|T_Fudge
init|=
literal|305
block|,
name|T_Host
init|=
literal|306
block|,
name|T_Huffpuff
init|=
literal|307
block|,
name|T_Iburst
init|=
literal|308
block|,
name|T_Ident
init|=
literal|309
block|,
name|T_Ignore
init|=
literal|310
block|,
name|T_Incalloc
init|=
literal|311
block|,
name|T_Incmem
init|=
literal|312
block|,
name|T_Initalloc
init|=
literal|313
block|,
name|T_Initmem
init|=
literal|314
block|,
name|T_Includefile
init|=
literal|315
block|,
name|T_Integer
init|=
literal|316
block|,
name|T_Interface
init|=
literal|317
block|,
name|T_Intrange
init|=
literal|318
block|,
name|T_Io
init|=
literal|319
block|,
name|T_Ipv4
init|=
literal|320
block|,
name|T_Ipv4_flag
init|=
literal|321
block|,
name|T_Ipv6
init|=
literal|322
block|,
name|T_Ipv6_flag
init|=
literal|323
block|,
name|T_Kernel
init|=
literal|324
block|,
name|T_Key
init|=
literal|325
block|,
name|T_Keys
init|=
literal|326
block|,
name|T_Keysdir
init|=
literal|327
block|,
name|T_Kod
init|=
literal|328
block|,
name|T_Mssntp
init|=
literal|329
block|,
name|T_Leapfile
init|=
literal|330
block|,
name|T_Leapsmearinterval
init|=
literal|331
block|,
name|T_Limited
init|=
literal|332
block|,
name|T_Link
init|=
literal|333
block|,
name|T_Listen
init|=
literal|334
block|,
name|T_Logconfig
init|=
literal|335
block|,
name|T_Logfile
init|=
literal|336
block|,
name|T_Loopstats
init|=
literal|337
block|,
name|T_Lowpriotrap
init|=
literal|338
block|,
name|T_Manycastclient
init|=
literal|339
block|,
name|T_Manycastserver
init|=
literal|340
block|,
name|T_Mask
init|=
literal|341
block|,
name|T_Maxage
init|=
literal|342
block|,
name|T_Maxclock
init|=
literal|343
block|,
name|T_Maxdepth
init|=
literal|344
block|,
name|T_Maxdist
init|=
literal|345
block|,
name|T_Maxmem
init|=
literal|346
block|,
name|T_Maxpoll
init|=
literal|347
block|,
name|T_Mdnstries
init|=
literal|348
block|,
name|T_Mem
init|=
literal|349
block|,
name|T_Memlock
init|=
literal|350
block|,
name|T_Minclock
init|=
literal|351
block|,
name|T_Mindepth
init|=
literal|352
block|,
name|T_Mindist
init|=
literal|353
block|,
name|T_Minimum
init|=
literal|354
block|,
name|T_Minpoll
init|=
literal|355
block|,
name|T_Minsane
init|=
literal|356
block|,
name|T_Mode
init|=
literal|357
block|,
name|T_Mode7
init|=
literal|358
block|,
name|T_Monitor
init|=
literal|359
block|,
name|T_Month
init|=
literal|360
block|,
name|T_Mru
init|=
literal|361
block|,
name|T_Multicastclient
init|=
literal|362
block|,
name|T_Nic
init|=
literal|363
block|,
name|T_Nolink
init|=
literal|364
block|,
name|T_Nomodify
init|=
literal|365
block|,
name|T_Nomrulist
init|=
literal|366
block|,
name|T_None
init|=
literal|367
block|,
name|T_Nonvolatile
init|=
literal|368
block|,
name|T_Nopeer
init|=
literal|369
block|,
name|T_Noquery
init|=
literal|370
block|,
name|T_Noselect
init|=
literal|371
block|,
name|T_Noserve
init|=
literal|372
block|,
name|T_Notrap
init|=
literal|373
block|,
name|T_Notrust
init|=
literal|374
block|,
name|T_Ntp
init|=
literal|375
block|,
name|T_Ntpport
init|=
literal|376
block|,
name|T_NtpSignDsocket
init|=
literal|377
block|,
name|T_Orphan
init|=
literal|378
block|,
name|T_Orphanwait
init|=
literal|379
block|,
name|T_Panic
init|=
literal|380
block|,
name|T_Peer
init|=
literal|381
block|,
name|T_Peerstats
init|=
literal|382
block|,
name|T_Phone
init|=
literal|383
block|,
name|T_Pid
init|=
literal|384
block|,
name|T_Pidfile
init|=
literal|385
block|,
name|T_Pool
init|=
literal|386
block|,
name|T_Port
init|=
literal|387
block|,
name|T_Preempt
init|=
literal|388
block|,
name|T_Prefer
init|=
literal|389
block|,
name|T_Protostats
init|=
literal|390
block|,
name|T_Pw
init|=
literal|391
block|,
name|T_Randfile
init|=
literal|392
block|,
name|T_Rawstats
init|=
literal|393
block|,
name|T_Refid
init|=
literal|394
block|,
name|T_Requestkey
init|=
literal|395
block|,
name|T_Reset
init|=
literal|396
block|,
name|T_Restrict
init|=
literal|397
block|,
name|T_Revoke
init|=
literal|398
block|,
name|T_Rlimit
init|=
literal|399
block|,
name|T_Saveconfigdir
init|=
literal|400
block|,
name|T_Server
init|=
literal|401
block|,
name|T_Setvar
init|=
literal|402
block|,
name|T_Source
init|=
literal|403
block|,
name|T_Stacksize
init|=
literal|404
block|,
name|T_Statistics
init|=
literal|405
block|,
name|T_Stats
init|=
literal|406
block|,
name|T_Statsdir
init|=
literal|407
block|,
name|T_Step
init|=
literal|408
block|,
name|T_Stepback
init|=
literal|409
block|,
name|T_Stepfwd
init|=
literal|410
block|,
name|T_Stepout
init|=
literal|411
block|,
name|T_Stratum
init|=
literal|412
block|,
name|T_String
init|=
literal|413
block|,
name|T_Sys
init|=
literal|414
block|,
name|T_Sysstats
init|=
literal|415
block|,
name|T_Tick
init|=
literal|416
block|,
name|T_Time1
init|=
literal|417
block|,
name|T_Time2
init|=
literal|418
block|,
name|T_Timer
init|=
literal|419
block|,
name|T_Timingstats
init|=
literal|420
block|,
name|T_Tinker
init|=
literal|421
block|,
name|T_Tos
init|=
literal|422
block|,
name|T_Trap
init|=
literal|423
block|,
name|T_True
init|=
literal|424
block|,
name|T_Trustedkey
init|=
literal|425
block|,
name|T_Ttl
init|=
literal|426
block|,
name|T_Type
init|=
literal|427
block|,
name|T_U_int
init|=
literal|428
block|,
name|T_UEcrypto
init|=
literal|429
block|,
name|T_UEcryptonak
init|=
literal|430
block|,
name|T_UEdigest
init|=
literal|431
block|,
name|T_Unconfig
init|=
literal|432
block|,
name|T_Unpeer
init|=
literal|433
block|,
name|T_Version
init|=
literal|434
block|,
name|T_WanderThreshold
init|=
literal|435
block|,
name|T_Week
init|=
literal|436
block|,
name|T_Wildcard
init|=
literal|437
block|,
name|T_Xleave
init|=
literal|438
block|,
name|T_Year
init|=
literal|439
block|,
name|T_Flag
init|=
literal|440
block|,
name|T_EOC
init|=
literal|441
block|,
name|T_Simulate
init|=
literal|442
block|,
name|T_Beep_Delay
init|=
literal|443
block|,
name|T_Sim_Duration
init|=
literal|444
block|,
name|T_Server_Offset
init|=
literal|445
block|,
name|T_Duration
init|=
literal|446
block|,
name|T_Freq_Offset
init|=
literal|447
block|,
name|T_Wander
init|=
literal|448
block|,
name|T_Jitter
init|=
literal|449
block|,
name|T_Prop_Delay
init|=
literal|450
block|,
name|T_Proc_Delay
init|=
literal|451
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Tokens.  */
end_comment

begin_define
define|#
directive|define
name|T_Abbrev
value|258
end_define

begin_define
define|#
directive|define
name|T_Age
value|259
end_define

begin_define
define|#
directive|define
name|T_All
value|260
end_define

begin_define
define|#
directive|define
name|T_Allan
value|261
end_define

begin_define
define|#
directive|define
name|T_Allpeers
value|262
end_define

begin_define
define|#
directive|define
name|T_Auth
value|263
end_define

begin_define
define|#
directive|define
name|T_Autokey
value|264
end_define

begin_define
define|#
directive|define
name|T_Automax
value|265
end_define

begin_define
define|#
directive|define
name|T_Average
value|266
end_define

begin_define
define|#
directive|define
name|T_Bclient
value|267
end_define

begin_define
define|#
directive|define
name|T_Beacon
value|268
end_define

begin_define
define|#
directive|define
name|T_Broadcast
value|269
end_define

begin_define
define|#
directive|define
name|T_Broadcastclient
value|270
end_define

begin_define
define|#
directive|define
name|T_Broadcastdelay
value|271
end_define

begin_define
define|#
directive|define
name|T_Burst
value|272
end_define

begin_define
define|#
directive|define
name|T_Calibrate
value|273
end_define

begin_define
define|#
directive|define
name|T_Ceiling
value|274
end_define

begin_define
define|#
directive|define
name|T_Clockstats
value|275
end_define

begin_define
define|#
directive|define
name|T_Cohort
value|276
end_define

begin_define
define|#
directive|define
name|T_ControlKey
value|277
end_define

begin_define
define|#
directive|define
name|T_Crypto
value|278
end_define

begin_define
define|#
directive|define
name|T_Cryptostats
value|279
end_define

begin_define
define|#
directive|define
name|T_Ctl
value|280
end_define

begin_define
define|#
directive|define
name|T_Day
value|281
end_define

begin_define
define|#
directive|define
name|T_Default
value|282
end_define

begin_define
define|#
directive|define
name|T_Digest
value|283
end_define

begin_define
define|#
directive|define
name|T_Disable
value|284
end_define

begin_define
define|#
directive|define
name|T_Discard
value|285
end_define

begin_define
define|#
directive|define
name|T_Dispersion
value|286
end_define

begin_define
define|#
directive|define
name|T_Double
value|287
end_define

begin_define
define|#
directive|define
name|T_Driftfile
value|288
end_define

begin_define
define|#
directive|define
name|T_Drop
value|289
end_define

begin_define
define|#
directive|define
name|T_Dscp
value|290
end_define

begin_define
define|#
directive|define
name|T_Ellipsis
value|291
end_define

begin_define
define|#
directive|define
name|T_Enable
value|292
end_define

begin_define
define|#
directive|define
name|T_End
value|293
end_define

begin_define
define|#
directive|define
name|T_False
value|294
end_define

begin_define
define|#
directive|define
name|T_File
value|295
end_define

begin_define
define|#
directive|define
name|T_Filegen
value|296
end_define

begin_define
define|#
directive|define
name|T_Filenum
value|297
end_define

begin_define
define|#
directive|define
name|T_Flag1
value|298
end_define

begin_define
define|#
directive|define
name|T_Flag2
value|299
end_define

begin_define
define|#
directive|define
name|T_Flag3
value|300
end_define

begin_define
define|#
directive|define
name|T_Flag4
value|301
end_define

begin_define
define|#
directive|define
name|T_Flake
value|302
end_define

begin_define
define|#
directive|define
name|T_Floor
value|303
end_define

begin_define
define|#
directive|define
name|T_Freq
value|304
end_define

begin_define
define|#
directive|define
name|T_Fudge
value|305
end_define

begin_define
define|#
directive|define
name|T_Host
value|306
end_define

begin_define
define|#
directive|define
name|T_Huffpuff
value|307
end_define

begin_define
define|#
directive|define
name|T_Iburst
value|308
end_define

begin_define
define|#
directive|define
name|T_Ident
value|309
end_define

begin_define
define|#
directive|define
name|T_Ignore
value|310
end_define

begin_define
define|#
directive|define
name|T_Incalloc
value|311
end_define

begin_define
define|#
directive|define
name|T_Incmem
value|312
end_define

begin_define
define|#
directive|define
name|T_Initalloc
value|313
end_define

begin_define
define|#
directive|define
name|T_Initmem
value|314
end_define

begin_define
define|#
directive|define
name|T_Includefile
value|315
end_define

begin_define
define|#
directive|define
name|T_Integer
value|316
end_define

begin_define
define|#
directive|define
name|T_Interface
value|317
end_define

begin_define
define|#
directive|define
name|T_Intrange
value|318
end_define

begin_define
define|#
directive|define
name|T_Io
value|319
end_define

begin_define
define|#
directive|define
name|T_Ipv4
value|320
end_define

begin_define
define|#
directive|define
name|T_Ipv4_flag
value|321
end_define

begin_define
define|#
directive|define
name|T_Ipv6
value|322
end_define

begin_define
define|#
directive|define
name|T_Ipv6_flag
value|323
end_define

begin_define
define|#
directive|define
name|T_Kernel
value|324
end_define

begin_define
define|#
directive|define
name|T_Key
value|325
end_define

begin_define
define|#
directive|define
name|T_Keys
value|326
end_define

begin_define
define|#
directive|define
name|T_Keysdir
value|327
end_define

begin_define
define|#
directive|define
name|T_Kod
value|328
end_define

begin_define
define|#
directive|define
name|T_Mssntp
value|329
end_define

begin_define
define|#
directive|define
name|T_Leapfile
value|330
end_define

begin_define
define|#
directive|define
name|T_Leapsmearinterval
value|331
end_define

begin_define
define|#
directive|define
name|T_Limited
value|332
end_define

begin_define
define|#
directive|define
name|T_Link
value|333
end_define

begin_define
define|#
directive|define
name|T_Listen
value|334
end_define

begin_define
define|#
directive|define
name|T_Logconfig
value|335
end_define

begin_define
define|#
directive|define
name|T_Logfile
value|336
end_define

begin_define
define|#
directive|define
name|T_Loopstats
value|337
end_define

begin_define
define|#
directive|define
name|T_Lowpriotrap
value|338
end_define

begin_define
define|#
directive|define
name|T_Manycastclient
value|339
end_define

begin_define
define|#
directive|define
name|T_Manycastserver
value|340
end_define

begin_define
define|#
directive|define
name|T_Mask
value|341
end_define

begin_define
define|#
directive|define
name|T_Maxage
value|342
end_define

begin_define
define|#
directive|define
name|T_Maxclock
value|343
end_define

begin_define
define|#
directive|define
name|T_Maxdepth
value|344
end_define

begin_define
define|#
directive|define
name|T_Maxdist
value|345
end_define

begin_define
define|#
directive|define
name|T_Maxmem
value|346
end_define

begin_define
define|#
directive|define
name|T_Maxpoll
value|347
end_define

begin_define
define|#
directive|define
name|T_Mdnstries
value|348
end_define

begin_define
define|#
directive|define
name|T_Mem
value|349
end_define

begin_define
define|#
directive|define
name|T_Memlock
value|350
end_define

begin_define
define|#
directive|define
name|T_Minclock
value|351
end_define

begin_define
define|#
directive|define
name|T_Mindepth
value|352
end_define

begin_define
define|#
directive|define
name|T_Mindist
value|353
end_define

begin_define
define|#
directive|define
name|T_Minimum
value|354
end_define

begin_define
define|#
directive|define
name|T_Minpoll
value|355
end_define

begin_define
define|#
directive|define
name|T_Minsane
value|356
end_define

begin_define
define|#
directive|define
name|T_Mode
value|357
end_define

begin_define
define|#
directive|define
name|T_Mode7
value|358
end_define

begin_define
define|#
directive|define
name|T_Monitor
value|359
end_define

begin_define
define|#
directive|define
name|T_Month
value|360
end_define

begin_define
define|#
directive|define
name|T_Mru
value|361
end_define

begin_define
define|#
directive|define
name|T_Multicastclient
value|362
end_define

begin_define
define|#
directive|define
name|T_Nic
value|363
end_define

begin_define
define|#
directive|define
name|T_Nolink
value|364
end_define

begin_define
define|#
directive|define
name|T_Nomodify
value|365
end_define

begin_define
define|#
directive|define
name|T_Nomrulist
value|366
end_define

begin_define
define|#
directive|define
name|T_None
value|367
end_define

begin_define
define|#
directive|define
name|T_Nonvolatile
value|368
end_define

begin_define
define|#
directive|define
name|T_Nopeer
value|369
end_define

begin_define
define|#
directive|define
name|T_Noquery
value|370
end_define

begin_define
define|#
directive|define
name|T_Noselect
value|371
end_define

begin_define
define|#
directive|define
name|T_Noserve
value|372
end_define

begin_define
define|#
directive|define
name|T_Notrap
value|373
end_define

begin_define
define|#
directive|define
name|T_Notrust
value|374
end_define

begin_define
define|#
directive|define
name|T_Ntp
value|375
end_define

begin_define
define|#
directive|define
name|T_Ntpport
value|376
end_define

begin_define
define|#
directive|define
name|T_NtpSignDsocket
value|377
end_define

begin_define
define|#
directive|define
name|T_Orphan
value|378
end_define

begin_define
define|#
directive|define
name|T_Orphanwait
value|379
end_define

begin_define
define|#
directive|define
name|T_Panic
value|380
end_define

begin_define
define|#
directive|define
name|T_Peer
value|381
end_define

begin_define
define|#
directive|define
name|T_Peerstats
value|382
end_define

begin_define
define|#
directive|define
name|T_Phone
value|383
end_define

begin_define
define|#
directive|define
name|T_Pid
value|384
end_define

begin_define
define|#
directive|define
name|T_Pidfile
value|385
end_define

begin_define
define|#
directive|define
name|T_Pool
value|386
end_define

begin_define
define|#
directive|define
name|T_Port
value|387
end_define

begin_define
define|#
directive|define
name|T_Preempt
value|388
end_define

begin_define
define|#
directive|define
name|T_Prefer
value|389
end_define

begin_define
define|#
directive|define
name|T_Protostats
value|390
end_define

begin_define
define|#
directive|define
name|T_Pw
value|391
end_define

begin_define
define|#
directive|define
name|T_Randfile
value|392
end_define

begin_define
define|#
directive|define
name|T_Rawstats
value|393
end_define

begin_define
define|#
directive|define
name|T_Refid
value|394
end_define

begin_define
define|#
directive|define
name|T_Requestkey
value|395
end_define

begin_define
define|#
directive|define
name|T_Reset
value|396
end_define

begin_define
define|#
directive|define
name|T_Restrict
value|397
end_define

begin_define
define|#
directive|define
name|T_Revoke
value|398
end_define

begin_define
define|#
directive|define
name|T_Rlimit
value|399
end_define

begin_define
define|#
directive|define
name|T_Saveconfigdir
value|400
end_define

begin_define
define|#
directive|define
name|T_Server
value|401
end_define

begin_define
define|#
directive|define
name|T_Setvar
value|402
end_define

begin_define
define|#
directive|define
name|T_Source
value|403
end_define

begin_define
define|#
directive|define
name|T_Stacksize
value|404
end_define

begin_define
define|#
directive|define
name|T_Statistics
value|405
end_define

begin_define
define|#
directive|define
name|T_Stats
value|406
end_define

begin_define
define|#
directive|define
name|T_Statsdir
value|407
end_define

begin_define
define|#
directive|define
name|T_Step
value|408
end_define

begin_define
define|#
directive|define
name|T_Stepback
value|409
end_define

begin_define
define|#
directive|define
name|T_Stepfwd
value|410
end_define

begin_define
define|#
directive|define
name|T_Stepout
value|411
end_define

begin_define
define|#
directive|define
name|T_Stratum
value|412
end_define

begin_define
define|#
directive|define
name|T_String
value|413
end_define

begin_define
define|#
directive|define
name|T_Sys
value|414
end_define

begin_define
define|#
directive|define
name|T_Sysstats
value|415
end_define

begin_define
define|#
directive|define
name|T_Tick
value|416
end_define

begin_define
define|#
directive|define
name|T_Time1
value|417
end_define

begin_define
define|#
directive|define
name|T_Time2
value|418
end_define

begin_define
define|#
directive|define
name|T_Timer
value|419
end_define

begin_define
define|#
directive|define
name|T_Timingstats
value|420
end_define

begin_define
define|#
directive|define
name|T_Tinker
value|421
end_define

begin_define
define|#
directive|define
name|T_Tos
value|422
end_define

begin_define
define|#
directive|define
name|T_Trap
value|423
end_define

begin_define
define|#
directive|define
name|T_True
value|424
end_define

begin_define
define|#
directive|define
name|T_Trustedkey
value|425
end_define

begin_define
define|#
directive|define
name|T_Ttl
value|426
end_define

begin_define
define|#
directive|define
name|T_Type
value|427
end_define

begin_define
define|#
directive|define
name|T_U_int
value|428
end_define

begin_define
define|#
directive|define
name|T_UEcrypto
value|429
end_define

begin_define
define|#
directive|define
name|T_UEcryptonak
value|430
end_define

begin_define
define|#
directive|define
name|T_UEdigest
value|431
end_define

begin_define
define|#
directive|define
name|T_Unconfig
value|432
end_define

begin_define
define|#
directive|define
name|T_Unpeer
value|433
end_define

begin_define
define|#
directive|define
name|T_Version
value|434
end_define

begin_define
define|#
directive|define
name|T_WanderThreshold
value|435
end_define

begin_define
define|#
directive|define
name|T_Week
value|436
end_define

begin_define
define|#
directive|define
name|T_Wildcard
value|437
end_define

begin_define
define|#
directive|define
name|T_Xleave
value|438
end_define

begin_define
define|#
directive|define
name|T_Year
value|439
end_define

begin_define
define|#
directive|define
name|T_Flag
value|440
end_define

begin_define
define|#
directive|define
name|T_EOC
value|441
end_define

begin_define
define|#
directive|define
name|T_Simulate
value|442
end_define

begin_define
define|#
directive|define
name|T_Beep_Delay
value|443
end_define

begin_define
define|#
directive|define
name|T_Sim_Duration
value|444
end_define

begin_define
define|#
directive|define
name|T_Server_Offset
value|445
end_define

begin_define
define|#
directive|define
name|T_Duration
value|446
end_define

begin_define
define|#
directive|define
name|T_Freq_Offset
value|447
end_define

begin_define
define|#
directive|define
name|T_Wander
value|448
end_define

begin_define
define|#
directive|define
name|T_Jitter
value|449
end_define

begin_define
define|#
directive|define
name|T_Prop_Delay
value|450
end_define

begin_define
define|#
directive|define
name|T_Proc_Delay
value|451
end_define

begin_if
if|#
directive|if
operator|!
name|defined
name|YYSTYPE
operator|&&
operator|!
name|defined
name|YYSTYPE_IS_DECLARED
end_if

begin_typedef
typedef|typedef
union|union
name|YYSTYPE
block|{
comment|/* Line 2053 of yacc.c  */
line|#
directive|line
number|51
file|"../../ntpd/ntp_parser.y"
name|char
modifier|*
name|String
decl_stmt|;
name|double
name|Double
decl_stmt|;
name|int
name|Integer
decl_stmt|;
name|unsigned
name|U_int
decl_stmt|;
name|gen_fifo
modifier|*
name|Generic_fifo
decl_stmt|;
name|attr_val
modifier|*
name|Attr_val
decl_stmt|;
name|attr_val_fifo
modifier|*
name|Attr_val_fifo
decl_stmt|;
name|int_fifo
modifier|*
name|Int_fifo
decl_stmt|;
name|string_fifo
modifier|*
name|String_fifo
decl_stmt|;
name|address_node
modifier|*
name|Address_node
decl_stmt|;
name|address_fifo
modifier|*
name|Address_fifo
decl_stmt|;
name|setvar_node
modifier|*
name|Set_var
decl_stmt|;
name|server_info
modifier|*
name|Sim_server
decl_stmt|;
name|server_info_fifo
modifier|*
name|Sim_server_fifo
decl_stmt|;
name|script_info
modifier|*
name|Sim_script
decl_stmt|;
name|script_info_fifo
modifier|*
name|Sim_script_fifo
decl_stmt|;
comment|/* Line 2053 of yacc.c  */
line|#
directive|line
number|469
file|"ntp_parser.h"
block|}
name|YYSTYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|YYSTYPE_IS_TRIVIAL
value|1
end_define

begin_define
define|#
directive|define
name|yystype
value|YYSTYPE
end_define

begin_comment
comment|/* obsolescent; will be withdrawn */
end_comment

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

begin_decl_stmt
specifier|extern
name|YYSTYPE
name|yylval
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|YYPARSE_PARAM
end_ifdef

begin_if
if|#
directive|if
name|defined
name|__STDC__
operator|||
name|defined
name|__cplusplus
end_if

begin_function_decl
name|int
name|yyparse
parameter_list|(
name|void
modifier|*
name|YYPARSE_PARAM
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|yyparse
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! YYPARSE_PARAM */
end_comment

begin_if
if|#
directive|if
name|defined
name|__STDC__
operator|||
name|defined
name|__cplusplus
end_if

begin_function_decl
name|int
name|yyparse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|yyparse
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! YYPARSE_PARAM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !YY_YY_NTP_PARSER_H_INCLUDED  */
end_comment

end_unit

