begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * 	DATAKIT VCS Interface Definitions  *		@(#)dkit.h	1.4 Garage 84/03/30  */
end_comment

begin_comment
comment|/*  *	Host Software Version number  */
end_comment

begin_define
define|#
directive|define
name|HOSTVERSION
value|2
end_define

begin_comment
comment|/* Change the string below when you update this */
end_comment

begin_define
define|#
directive|define
name|S_HOSTVERSION
value|"@(#) Datakit Host Protocol Version 2"
end_define

begin_comment
comment|/*  *   bits defined in channel flag  */
end_comment

begin_define
define|#
directive|define
name|DK_OPEN
value|01
end_define

begin_comment
comment|/* channel is open flag */
end_comment

begin_define
define|#
directive|define
name|DK_LINGR
value|02
end_define

begin_comment
comment|/* closed by user, waiting sync */
end_comment

begin_define
define|#
directive|define
name|DK_BUSY
value|04
end_define

begin_comment
comment|/* output in progress */
end_comment

begin_define
define|#
directive|define
name|DK_RESET
value|010
end_define

begin_comment
comment|/* cmc told us to close this channel */
end_comment

begin_define
define|#
directive|define
name|DK_RCV
value|020
end_define

begin_comment
comment|/* receive active on channel */
end_comment

begin_define
define|#
directive|define
name|DK_RCVQ
value|040
end_define

begin_comment
comment|/* receive done queued 'cause timer */
end_comment

begin_define
define|#
directive|define
name|DK_SPND
value|0100
end_define

begin_comment
comment|/* output is currently suspended */
end_comment

begin_comment
comment|/*  *   command codes passed to dkit_cmd  */
end_comment

begin_define
define|#
directive|define
name|DKC_XINIT
value|01
end_define

begin_comment
comment|/* re-init transmitter section */
end_comment

begin_define
define|#
directive|define
name|DKC_FLUSH
value|02
end_define

begin_comment
comment|/* flush all pending output */
end_comment

begin_define
define|#
directive|define
name|DKC_SPND
value|04
end_define

begin_comment
comment|/* suspend further output */
end_comment

begin_define
define|#
directive|define
name|DKC_RSME
value|010
end_define

begin_comment
comment|/* resume output after suspend */
end_comment

begin_comment
comment|/*  *   receive mode, and completion indicators  */
end_comment

begin_define
define|#
directive|define
name|DKR_FULL
value|01
end_define

begin_comment
comment|/* buffer full, normal read done */
end_comment

begin_define
define|#
directive|define
name|DKR_CNTL
value|02
end_define

begin_comment
comment|/* read terminated on control character */
end_comment

begin_define
define|#
directive|define
name|DKR_ABORT
value|010
end_define

begin_comment
comment|/* receive aborted by higher level command */
end_comment

begin_define
define|#
directive|define
name|DKR_BLOCK
value|040
end_define

begin_comment
comment|/* end of block */
end_comment

begin_define
define|#
directive|define
name|DKR_TIME
value|0100
end_define

begin_comment
comment|/* end of time limit reached */
end_comment

begin_comment
comment|/*  *   Datakit-specific mbuf types  */
end_comment

begin_define
define|#
directive|define
name|DKMT_HDR
value|128
end_define

begin_comment
comment|/* Header packet with driver stuff */
end_comment

begin_define
define|#
directive|define
name|DKMT_DATA
value|DKMT_HDR+1
end_define

begin_comment
comment|/* Data */
end_comment

begin_define
define|#
directive|define
name|DKMT_CTL
value|DKMT_HDR+2
end_define

begin_comment
comment|/* Control bytes */
end_comment

begin_define
define|#
directive|define
name|DKMT_PCB
value|DKMT_HDR+3
end_define

begin_comment
comment|/* Setup request block */
end_comment

begin_define
define|#
directive|define
name|DKMT_ROUTE
value|DKMT_HDR+4
end_define

begin_comment
comment|/* dkip routing table entry */
end_comment

begin_define
define|#
directive|define
name|DKMT_ITTY
value|DKMT_HDR+5
end_define

begin_comment
comment|/* dktty input buffer */
end_comment

begin_define
define|#
directive|define
name|DKMT_OTTY
value|DKMT_HDR+6
end_define

begin_comment
comment|/* dktty output buffer */
end_comment

begin_define
define|#
directive|define
name|DKMT_CTYPE
value|DKMT_HDR+7
end_define

begin_comment
comment|/* Connection source/dest */
end_comment

end_unit

