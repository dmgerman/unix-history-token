begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   Z M O D E M . H     Manifest constants for ZMODEM  *    application to application file transfer protocol  *    04-17-89  Chuck Forsberg Omen Technology Inc  */
end_comment

begin_define
define|#
directive|define
name|ZPAD
value|'*'
end_define

begin_comment
comment|/* 052 Padding character begins frames */
end_comment

begin_define
define|#
directive|define
name|ZDLE
value|030
end_define

begin_comment
comment|/* Ctrl-X Zmodem escape - `ala BISYNC DLE */
end_comment

begin_define
define|#
directive|define
name|ZDLEE
value|(ZDLE^0100)
end_define

begin_comment
comment|/* Escaped ZDLE as transmitted */
end_comment

begin_define
define|#
directive|define
name|ZBIN
value|'A'
end_define

begin_comment
comment|/* Binary frame indicator (CRC-16) */
end_comment

begin_define
define|#
directive|define
name|ZHEX
value|'B'
end_define

begin_comment
comment|/* HEX frame indicator */
end_comment

begin_define
define|#
directive|define
name|ZBIN32
value|'C'
end_define

begin_comment
comment|/* Binary frame with 32 bit FCS */
end_comment

begin_define
define|#
directive|define
name|ZBINR32
value|'D'
end_define

begin_comment
comment|/* RLE packed Binary frame with 32 bit FCS */
end_comment

begin_define
define|#
directive|define
name|ZVBIN
value|'a'
end_define

begin_comment
comment|/* Binary frame indicator (CRC-16) */
end_comment

begin_define
define|#
directive|define
name|ZVHEX
value|'b'
end_define

begin_comment
comment|/* HEX frame indicator */
end_comment

begin_define
define|#
directive|define
name|ZVBIN32
value|'c'
end_define

begin_comment
comment|/* Binary frame with 32 bit FCS */
end_comment

begin_define
define|#
directive|define
name|ZVBINR32
value|'d'
end_define

begin_comment
comment|/* RLE packed Binary frame with 32 bit FCS */
end_comment

begin_define
define|#
directive|define
name|ZRESC
value|0176
end_define

begin_comment
comment|/* RLE flag/escape character */
end_comment

begin_define
define|#
directive|define
name|ZMAXHLEN
value|16
end_define

begin_comment
comment|/* Max header information length  NEVER CHANGE */
end_comment

begin_define
define|#
directive|define
name|ZMAXSPLEN
value|1024
end_define

begin_comment
comment|/* Max subpacket length  NEVER CHANGE */
end_comment

begin_comment
comment|/* Frame types (see array "frametypes" in zm.c) */
end_comment

begin_define
define|#
directive|define
name|ZRQINIT
value|0
end_define

begin_comment
comment|/* Request receive init */
end_comment

begin_define
define|#
directive|define
name|ZRINIT
value|1
end_define

begin_comment
comment|/* Receive init */
end_comment

begin_define
define|#
directive|define
name|ZSINIT
value|2
end_define

begin_comment
comment|/* Send init sequence (optional) */
end_comment

begin_define
define|#
directive|define
name|ZACK
value|3
end_define

begin_comment
comment|/* ACK to above */
end_comment

begin_define
define|#
directive|define
name|ZFILE
value|4
end_define

begin_comment
comment|/* File name from sender */
end_comment

begin_define
define|#
directive|define
name|ZSKIP
value|5
end_define

begin_comment
comment|/* To sender: skip this file */
end_comment

begin_define
define|#
directive|define
name|ZNAK
value|6
end_define

begin_comment
comment|/* Last packet was garbled */
end_comment

begin_define
define|#
directive|define
name|ZABORT
value|7
end_define

begin_comment
comment|/* Abort batch transfers */
end_comment

begin_define
define|#
directive|define
name|ZFIN
value|8
end_define

begin_comment
comment|/* Finish session */
end_comment

begin_define
define|#
directive|define
name|ZRPOS
value|9
end_define

begin_comment
comment|/* Resume data trans at this position */
end_comment

begin_define
define|#
directive|define
name|ZDATA
value|10
end_define

begin_comment
comment|/* Data packet(s) follow */
end_comment

begin_define
define|#
directive|define
name|ZEOF
value|11
end_define

begin_comment
comment|/* End of file */
end_comment

begin_define
define|#
directive|define
name|ZFERR
value|12
end_define

begin_comment
comment|/* Fatal Read or Write error Detected */
end_comment

begin_define
define|#
directive|define
name|ZCRC
value|13
end_define

begin_comment
comment|/* Request for file CRC and response */
end_comment

begin_define
define|#
directive|define
name|ZCHALLENGE
value|14
end_define

begin_comment
comment|/* Receiver's Challenge */
end_comment

begin_define
define|#
directive|define
name|ZCOMPL
value|15
end_define

begin_comment
comment|/* Request is complete */
end_comment

begin_define
define|#
directive|define
name|ZCAN
value|16
end_define

begin_comment
comment|/* Other end canned session with CAN*5 */
end_comment

begin_define
define|#
directive|define
name|ZFREECNT
value|17
end_define

begin_comment
comment|/* Request for free bytes on filesystem */
end_comment

begin_define
define|#
directive|define
name|ZCOMMAND
value|18
end_define

begin_comment
comment|/* Command from sending program */
end_comment

begin_define
define|#
directive|define
name|ZSTDERR
value|19
end_define

begin_comment
comment|/* Output to standard error, data follows */
end_comment

begin_comment
comment|/* ZDLE sequences */
end_comment

begin_define
define|#
directive|define
name|ZCRCE
value|'h'
end_define

begin_comment
comment|/* CRC next, frame ends, header packet follows */
end_comment

begin_define
define|#
directive|define
name|ZCRCG
value|'i'
end_define

begin_comment
comment|/* CRC next, frame continues nonstop */
end_comment

begin_define
define|#
directive|define
name|ZCRCQ
value|'j'
end_define

begin_comment
comment|/* CRC next, frame continues, ZACK expected */
end_comment

begin_define
define|#
directive|define
name|ZCRCW
value|'k'
end_define

begin_comment
comment|/* CRC next, ZACK expected, end of frame */
end_comment

begin_define
define|#
directive|define
name|ZRUB0
value|'l'
end_define

begin_comment
comment|/* Translate to rubout 0177 */
end_comment

begin_define
define|#
directive|define
name|ZRUB1
value|'m'
end_define

begin_comment
comment|/* Translate to rubout 0377 */
end_comment

begin_comment
comment|/* zdlread return values (internal) */
end_comment

begin_comment
comment|/* -1 is general error, -2 is timeout */
end_comment

begin_define
define|#
directive|define
name|GOTOR
value|0400
end_define

begin_define
define|#
directive|define
name|GOTCRCE
value|(ZCRCE|GOTOR)
end_define

begin_comment
comment|/* ZDLE-ZCRCE received */
end_comment

begin_define
define|#
directive|define
name|GOTCRCG
value|(ZCRCG|GOTOR)
end_define

begin_comment
comment|/* ZDLE-ZCRCG received */
end_comment

begin_define
define|#
directive|define
name|GOTCRCQ
value|(ZCRCQ|GOTOR)
end_define

begin_comment
comment|/* ZDLE-ZCRCQ received */
end_comment

begin_define
define|#
directive|define
name|GOTCRCW
value|(ZCRCW|GOTOR)
end_define

begin_comment
comment|/* ZDLE-ZCRCW received */
end_comment

begin_define
define|#
directive|define
name|GOTCAN
value|(GOTOR|030)
end_define

begin_comment
comment|/* CAN*5 seen */
end_comment

begin_comment
comment|/* Byte positions within header array */
end_comment

begin_define
define|#
directive|define
name|ZF0
value|3
end_define

begin_comment
comment|/* First flags byte */
end_comment

begin_define
define|#
directive|define
name|ZF1
value|2
end_define

begin_define
define|#
directive|define
name|ZF2
value|1
end_define

begin_define
define|#
directive|define
name|ZF3
value|0
end_define

begin_define
define|#
directive|define
name|ZP0
value|0
end_define

begin_comment
comment|/* Low order 8 bits of position */
end_comment

begin_define
define|#
directive|define
name|ZP1
value|1
end_define

begin_define
define|#
directive|define
name|ZP2
value|2
end_define

begin_define
define|#
directive|define
name|ZP3
value|3
end_define

begin_comment
comment|/* High order 8 bits of file position */
end_comment

begin_comment
comment|/* Bit Masks for ZRINIT flags byte ZF0 */
end_comment

begin_define
define|#
directive|define
name|CANFDX
value|01
end_define

begin_comment
comment|/* Rx can send and receive true FDX */
end_comment

begin_define
define|#
directive|define
name|CANOVIO
value|02
end_define

begin_comment
comment|/* Rx can receive data during disk I/O */
end_comment

begin_define
define|#
directive|define
name|CANBRK
value|04
end_define

begin_comment
comment|/* Rx can send a break signal */
end_comment

begin_define
define|#
directive|define
name|CANRLE
value|010
end_define

begin_comment
comment|/* Receiver can decode RLE */
end_comment

begin_define
define|#
directive|define
name|CANLZW
value|020
end_define

begin_comment
comment|/* Receiver can uncompress */
end_comment

begin_define
define|#
directive|define
name|CANFC32
value|040
end_define

begin_comment
comment|/* Receiver can use 32 bit Frame Check */
end_comment

begin_define
define|#
directive|define
name|ESCCTL
value|0100
end_define

begin_comment
comment|/* Receiver expects ctl chars to be escaped */
end_comment

begin_define
define|#
directive|define
name|ESC8
value|0200
end_define

begin_comment
comment|/* Receiver expects 8th bit to be escaped */
end_comment

begin_comment
comment|/* Bit Masks for ZRINIT flags byte ZF0 */
end_comment

begin_define
define|#
directive|define
name|CANVHDR
value|01
end_define

begin_comment
comment|/* Variable headers OK */
end_comment

begin_comment
comment|/* Parameters for ZSINIT frame */
end_comment

begin_define
define|#
directive|define
name|ZATTNLEN
value|32
end_define

begin_comment
comment|/* Max length of attention string */
end_comment

begin_define
define|#
directive|define
name|ALTCOFF
value|ZF1
end_define

begin_comment
comment|/* Offset to alternate canit string, 0 if not used */
end_comment

begin_comment
comment|/* Bit Masks for ZSINIT flags byte ZF0 */
end_comment

begin_define
define|#
directive|define
name|TESCCTL
value|0100
end_define

begin_comment
comment|/* Transmitter expects ctl chars to be escaped */
end_comment

begin_define
define|#
directive|define
name|TESC8
value|0200
end_define

begin_comment
comment|/* Transmitter expects 8th bit to be escaped */
end_comment

begin_comment
comment|/* Parameters for ZFILE frame */
end_comment

begin_comment
comment|/* Conversion options one of these in ZF0 */
end_comment

begin_define
define|#
directive|define
name|ZCBIN
value|1
end_define

begin_comment
comment|/* Binary transfer - inhibit conversion */
end_comment

begin_define
define|#
directive|define
name|ZCNL
value|2
end_define

begin_comment
comment|/* Convert NL to local end of line convention */
end_comment

begin_define
define|#
directive|define
name|ZCRESUM
value|3
end_define

begin_comment
comment|/* Resume interrupted file transfer */
end_comment

begin_comment
comment|/* Management include options, one of these ored in ZF1 */
end_comment

begin_define
define|#
directive|define
name|ZMSKNOLOC
value|0200
end_define

begin_comment
comment|/* Skip file if not present at rx */
end_comment

begin_comment
comment|/* Management options, one of these ored in ZF1 */
end_comment

begin_define
define|#
directive|define
name|ZMMASK
value|037
end_define

begin_comment
comment|/* Mask for the choices below */
end_comment

begin_define
define|#
directive|define
name|ZMNEWL
value|1
end_define

begin_comment
comment|/* Transfer if source newer or longer */
end_comment

begin_define
define|#
directive|define
name|ZMCRC
value|2
end_define

begin_comment
comment|/* Transfer if different file CRC or length */
end_comment

begin_define
define|#
directive|define
name|ZMAPND
value|3
end_define

begin_comment
comment|/* Append contents to existing file (if any) */
end_comment

begin_define
define|#
directive|define
name|ZMCLOB
value|4
end_define

begin_comment
comment|/* Replace existing file */
end_comment

begin_define
define|#
directive|define
name|ZMNEW
value|5
end_define

begin_comment
comment|/* Transfer if source newer */
end_comment

begin_comment
comment|/* Number 5 is alive ... */
end_comment

begin_define
define|#
directive|define
name|ZMDIFF
value|6
end_define

begin_comment
comment|/* Transfer if dates or lengths different */
end_comment

begin_define
define|#
directive|define
name|ZMPROT
value|7
end_define

begin_comment
comment|/* Protect destination file */
end_comment

begin_comment
comment|/* Transport options, one of these in ZF2 */
end_comment

begin_define
define|#
directive|define
name|ZTLZW
value|1
end_define

begin_comment
comment|/* Lempel-Ziv compression */
end_comment

begin_define
define|#
directive|define
name|ZTRLE
value|3
end_define

begin_comment
comment|/* Run Length encoding */
end_comment

begin_comment
comment|/* Extended options for ZF3, bit encoded */
end_comment

begin_define
define|#
directive|define
name|ZXSPARS
value|64
end_define

begin_comment
comment|/* Encoding for sparse file operations */
end_comment

begin_define
define|#
directive|define
name|ZCANVHDR
value|01
end_define

begin_comment
comment|/* Variable headers OK */
end_comment

begin_comment
comment|/* Parameters for ZCOMMAND frame ZF0 (otherwise 0) */
end_comment

begin_define
define|#
directive|define
name|ZCACK1
value|1
end_define

begin_comment
comment|/* Acknowledge, then do command */
end_comment

begin_function_decl
name|long
name|rclhdr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Globals used by ZMODEM functions */
end_comment

begin_extern
extern|extern Rxframeind;
end_extern

begin_comment
comment|/* ZBIN ZBIN32, or ZHEX type of frame */
end_comment

begin_extern
extern|extern Rxtype;
end_extern

begin_comment
comment|/* Type of header received */
end_comment

begin_extern
extern|extern Rxcount;
end_extern

begin_comment
comment|/* Count of data bytes received */
end_comment

begin_extern
extern|extern Rxtimeout;
end_extern

begin_comment
comment|/* Tenths of seconds to wait for something */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|Rxpos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Received file position */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|Txpos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Transmitted file position */
end_comment

begin_extern
extern|extern Txfcs32;
end_extern

begin_comment
comment|/* TURE means send binary frames with 32 bit FCS */
end_comment

begin_extern
extern|extern Crc32t;
end_extern

begin_comment
comment|/* Display flag indicating 32 bit CRC being sent */
end_comment

begin_extern
extern|extern Crc32;
end_extern

begin_comment
comment|/* Display flag indicating 32 bit CRC being received */
end_comment

begin_extern
extern|extern Znulls;
end_extern

begin_comment
comment|/* Number of nulls to send at beginning of ZDATA hdr */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|Attn
index|[
name|ZATTNLEN
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Attention string rx sends to tx on err */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Altcan
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Alternate canit string */
end_comment

begin_comment
comment|/* End of ZMODEM.H */
end_comment

end_unit

