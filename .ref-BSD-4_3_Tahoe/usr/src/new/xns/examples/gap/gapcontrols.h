begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * various control values used by GAP  * $Header: gapcontrols.h,v 2.0 85/11/21 07:23:02 jqj Exp $  *  * $Log:	gapcontrols.h,v $  * Revision 2.0  85/11/21  07:23:02  jqj  * 4.3BSD standard release  *   * Revision 1.2  85/11/20  13:59:16  jqj  * added symbolic entries for Gap connection types  *   */
end_comment

begin_comment
comment|/*  * some of the service types used by GAP TTY services  * to identify themselves.  */
end_comment

begin_define
define|#
directive|define
name|TTYService_any
value|0
end_define

begin_comment
comment|/* matches any service */
end_comment

begin_define
define|#
directive|define
name|TTYService_sa
value|1
end_define

begin_comment
comment|/* Used by system administrator interface */
end_comment

begin_define
define|#
directive|define
name|TTYService_exec
value|2
end_define

begin_comment
comment|/* Used by Mesa and other TTY executives */
end_comment

begin_define
define|#
directive|define
name|TTYService_its
value|3
end_define

begin_comment
comment|/* Used by ITS */
end_comment

begin_define
define|#
directive|define
name|TTYService_sender
value|4
end_define

begin_comment
comment|/* Diagnostic service...sends continuously */
end_comment

begin_comment
comment|/* Numbers above 64K for experimental and non-Xerox use. */
end_comment

begin_comment
comment|/*  * Controls used in GAP connection streams.  In-band controls appear  * as nonstandard SPP packet types.  Out-of-band controls appear as  * Attn packets with a single byte of data, whose value is the OOB  * control.  */
end_comment

begin_comment
comment|/* generic controls, both in-band and out-of-band */
end_comment

begin_define
define|#
directive|define
name|GAPCTLabortGetTransaction
value|0306
end_define

begin_comment
comment|/* oob with mark */
end_comment

begin_define
define|#
directive|define
name|GAPCTLabortMark
value|0315
end_define

begin_comment
comment|/* inband */
end_comment

begin_define
define|#
directive|define
name|GAPCTLabortPutTransaction
value|0307
end_define

begin_comment
comment|/* oob with mark */
end_comment

begin_define
define|#
directive|define
name|GAPCTLareYouThere
value|0304
end_define

begin_comment
comment|/* oob */
end_comment

begin_define
define|#
directive|define
name|GAPCTLaudibleSignal
value|0303
end_define

begin_comment
comment|/* oob */
end_comment

begin_define
define|#
directive|define
name|GAPCTLcleanup
value|0320
end_define

begin_comment
comment|/* inband, oob */
end_comment

begin_define
define|#
directive|define
name|GAPCTLdisconnect
value|0312
end_define

begin_comment
comment|/* inband */
end_comment

begin_define
define|#
directive|define
name|GAPCTLendOfTransaction
value|0310
end_define

begin_comment
comment|/* inband */
end_comment

begin_define
define|#
directive|define
name|GAPCTLendOfTransparentData
value|0314
end_define

begin_comment
comment|/* inband */
end_comment

begin_define
define|#
directive|define
name|GAPCTLexcessiveRetransmissions
value|0333
end_define

begin_comment
comment|/* oob with mark */
end_comment

begin_define
define|#
directive|define
name|GAPCTLiAmHere
value|0305
end_define

begin_comment
comment|/* oob */
end_comment

begin_define
define|#
directive|define
name|GAPCTLinterrupt
value|0301
end_define

begin_comment
comment|/* oob */
end_comment

begin_define
define|#
directive|define
name|GAPCTLnone
value|0300
end_define

begin_comment
comment|/* inband, of course */
end_comment

begin_define
define|#
directive|define
name|GAPCTLremoteNotResponding
value|0331
end_define

begin_comment
comment|/* oob with mark */
end_comment

begin_define
define|#
directive|define
name|GAPCTLresume
value|0302
end_define

begin_comment
comment|/* oob */
end_comment

begin_define
define|#
directive|define
name|GAPCTLtransparentDataFollows
value|0313
end_define

begin_comment
comment|/* inband */
end_comment

begin_define
define|#
directive|define
name|GAPCTLyourTurnToSend
value|0311
end_define

begin_comment
comment|/* inband */
end_comment

begin_define
define|#
directive|define
name|GAPCTLunchained3270
value|0335
end_define

begin_comment
comment|/* inband */
end_comment

begin_define
define|#
directive|define
name|GAPCTLreadModified3270
value|0336
end_define

begin_comment
comment|/* inband */
end_comment

begin_define
define|#
directive|define
name|GAPCTLstatus3270
value|0337
end_define

begin_comment
comment|/* inband */
end_comment

begin_define
define|#
directive|define
name|GAPCTLtestRequest3270
value|0340
end_define

begin_comment
comment|/* inband */
end_comment

begin_define
define|#
directive|define
name|GAPCTLsscpData
value|0345
end_define

begin_comment
comment|/* inband? */
end_comment

begin_define
define|#
directive|define
name|GAPCTLreadModifiedAll3270
value|0344
end_define

begin_comment
comment|/* inband? */
end_comment

begin_define
define|#
directive|define
name|GAPCTLread3270
value|0345
end_define

begin_comment
comment|/* inband? */
end_comment

begin_comment
comment|/* status bytes -- all are oob */
end_comment

begin_define
define|#
directive|define
name|GAPCTLmediumDown
value|0322
end_define

begin_define
define|#
directive|define
name|GAPCTLmediumUp
value|0321
end_define

begin_define
define|#
directive|define
name|GAPCTLnoGetForData
value|0325
end_define

begin_define
define|#
directive|define
name|GAPCTLourAccessIDRejected
value|0323
end_define

begin_define
define|#
directive|define
name|GAPCTLunsupportedProtocolFeature
value|0326
end_define

begin_define
define|#
directive|define
name|GAPCTLunexpectedRemoteBeharior
value|0327
end_define

begin_define
define|#
directive|define
name|GAPCTLunexpectedSoftwareFailure
value|0330
end_define

begin_define
define|#
directive|define
name|GAPCTLweRejectedAccessID
value|0324
end_define

begin_define
define|#
directive|define
name|GAPCTLpuActive
value|0347
end_define

begin_define
define|#
directive|define
name|GAPCTLpuInactive
value|0359
end_define

end_unit

