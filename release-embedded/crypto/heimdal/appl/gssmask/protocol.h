begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of KTH nor the names of its contributors may be  *    used to endorse or promote products derived from this software without  *    specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY KTH AND ITS CONTRIBUTORS ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL KTH OR ITS CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $Id$  */
end_comment

begin_comment
comment|/* missing from tests:  * - export context  * - import context  */
end_comment

begin_comment
comment|/*  * wire encodings:  *   int16: number, 2 bytes, in network order  *   int32: number, 4 bytes, in network order  *   length-encoded: [int32 length, data of length bytes]  *   string: [int32 length, string of length + 1 bytes, includes trailing '\0' ]  */
end_comment

begin_enum
enum|enum
name|gssMaggotErrorCodes
block|{
name|GSMERR_OK
init|=
literal|0
block|,
name|GSMERR_ERROR
block|,
name|GSMERR_CONTINUE_NEEDED
block|,
name|GSMERR_INVALID_TOKEN
block|,
name|GSMERR_AP_MODIFIED
block|,
name|GSMERR_TEST_ISSUE
block|,
name|GSMERR_NOT_SUPPORTED
block|}
enum|;
end_enum

begin_comment
comment|/*  * input:  *   int32: message OP (enum gssMaggotProtocol)  *   ...  *  * return:   -- on error  *    int32: not support (GSMERR_NOT_SUPPORTED)  *  * return:   -- on existing message OP  *    int32: support (GSMERR_OK) -- only sent for extensions  *    ...  */
end_comment

begin_define
define|#
directive|define
name|GSSMAGGOTPROTOCOL
value|14
end_define

begin_enum
enum|enum
name|gssMaggotOp
block|{
name|eGetVersionInfo
init|=
literal|0
block|,
comment|/*      * input:      *   none      * return:      *   int32: last version handled      */
name|eGoodBye
block|,
comment|/*      * input:      *   none      * return:      *   close socket      */
name|eInitContext
block|,
comment|/*      * input:      *   int32: hContext      *   int32: hCred      *   int32: Flags      *      the lowest 0x7f flags maps directly to GSS-API flags      *      DELEGATE		0x001      *      MUTUAL_AUTH		0x002      *      REPLAY_DETECT	0x004      *      SEQUENCE_DETECT	0x008      *      CONFIDENTIALITY	0x010      *      INTEGRITY		0x020      *      ANONYMOUS		0x040      *      *      FIRST_CALL		0x080      *      *      NTLM		0x100      *      SPNEGO		0x200      *   length-encoded: targetname      *   length-encoded: token      * return:      *   int32: hNewContextId      *   int32: gssapi status val      *   length-encoded: output token      */
name|eAcceptContext
block|,
comment|/*      * input:      *   int32: hContext      *   int32: Flags		-- unused ?      *      flags are same as flags for eInitContext      *   length-encoded: token      * return:      *   int32: hNewContextId      *   int32: gssapi status val      *   length-encoded: output token      *   int32: delegation cred id      */
name|eToastResource
block|,
comment|/*      * input:      *   int32: hResource      * return:      *   int32: gsm status val      */
name|eAcquireCreds
block|,
comment|/*      * input:      *   string: principal name      *   string: password      *   int32: flags      *      FORWARDABLE		0x001      *      DEFAULT_CREDS	0x002      *      *      NTLM		0x100      *      SPNEGO		0x200      * return:      *   int32: gsm status val      *   int32: hCred      */
name|eEncrypt
block|,
comment|/*      * input:      *   int32: hContext      *   int32: flags      *   int32: seqno		-- unused      *   length-encode: plaintext      * return:      *   int32: gsm status val      *   length-encode: ciphertext      */
name|eDecrypt
block|,
comment|/*      * input:      *   int32: hContext      *   int32: flags      *   int32: seqno		-- unused      *   length-encode: ciphertext      * return:      *   int32: gsm status val      *   length-encode: plaintext      */
name|eSign
block|,
comment|/* message same as eEncrypt */
name|eVerify
block|,
comment|/*      * input:      *   int32: hContext      *   int32: flags      *   int32: seqno		-- unused      *   length-encode: message      *   length-encode: signature      * return:      *   int32: gsm status val      */
name|eGetVersionAndCapabilities
block|,
comment|/*      * return:      *   int32: protocol version      *   int32: capability flags */
define|#
directive|define
name|ISSERVER
value|0x01
define|#
directive|define
name|ISKDC
value|0x02
define|#
directive|define
name|MS_KERBEROS
value|0x04
define|#
directive|define
name|LOGSERVER
value|0x08
define|#
directive|define
name|HAS_MONIKER
value|0x10
comment|/*   string: version string      */
name|eGetTargetName
block|,
comment|/*      * return:      *   string: target principal name      */
name|eSetLoggingSocket
block|,
comment|/*      * input:      *   int32: hostPort      * return to the port on the host:      *   int32: opcode - for example eLogSetMoniker      */
name|eChangePassword
block|,
comment|/* here ended version 7 of the protocol */
comment|/*      * input:      *   string: principal name      *   string: old password      *   string: new password      * return:      *   int32: gsm status val      */
name|eSetPasswordSelf
block|,
comment|/* same as eChangePassword */
name|eWrap
block|,
comment|/* message same as eEncrypt */
name|eUnwrap
block|,
comment|/* message same as eDecrypt */
name|eConnectLoggingService2
block|,
comment|/*      * return1:      *   int16: log port number      *   int32: master log prototocol version (0)      *      * wait for master to connect on the master log socket      *      * return2:      *   int32: gsm connection status      *   int32: maggot log prototocol version (2)      */
name|eGetMoniker
block|,
comment|/*      * return:      *   string: moniker (Nickname the master can refer to maggot)      */
name|eCallExtension
block|,
comment|/*      * input:      *   string: extension name      *   int32: message id      * return:      *   int32: gsm status val      */
name|eAcquirePKInitCreds
block|,
comment|/*      * input:      *   int32: flags      *   length-encode: certificate (pkcs12 data)      * return:      *   int32: hResource      *   int32: gsm status val (GSMERR_NOT_SUPPORTED)      */
comment|/* here ended version 7 of the protocol */
name|eWrapExt
block|,
comment|/*      * input:      *   int32: hContext      *   int32: flags      *   int32: bflags      *   length-encode: protocol header      *   length-encode: plaintext      *   length-encode: protocol trailer      * return:      *   int32: gsm status val      *   length-encode: ciphertext      */
name|eUnwrapExt
block|,
comment|/*      * input:      *   int32: hContext      *   int32: flags      *   int32: bflags      *   length-encode: protocol header      *   length-encode: ciphertext      *   length-encode: protocol trailer      * return:      *   int32: gsm status val      *   length-encode: plaintext      */
comment|/* here ended version 8 of the protocol */
name|eLastProtocolMessage
block|}
enum|;
end_enum

begin_comment
comment|/* bflags */
end_comment

begin_define
define|#
directive|define
name|WRAP_EXP_ONLY_HEADER
value|1
end_define

begin_enum
enum|enum
name|gssMaggotLogOp
block|{
name|eLogInfo
init|=
literal|0
block|,
comment|/* 	string: File 	int32: Line 	string: message      reply:   	int32: ackid 	*/
name|eLogFailure
block|,
comment|/* 	string: File 	int32: Line 	string: message      reply:   	int32: ackid 	*/
name|eLogSetMoniker
comment|/* 	string: moniker 	*/
block|}
enum|;
end_enum

end_unit

