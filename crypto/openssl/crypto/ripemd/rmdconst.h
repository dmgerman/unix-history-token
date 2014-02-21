begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/ripemd/rmdconst.h */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@cryptsoft.com).  * The implementation was written so as to conform with Netscapes SSL.  *   * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@cryptsoft.com).  *   * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@cryptsoft.com)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from   *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"  *   * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
end_comment

begin_define
define|#
directive|define
name|KL0
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|KL1
value|0x5A827999L
end_define

begin_define
define|#
directive|define
name|KL2
value|0x6ED9EBA1L
end_define

begin_define
define|#
directive|define
name|KL3
value|0x8F1BBCDCL
end_define

begin_define
define|#
directive|define
name|KL4
value|0xA953FD4EL
end_define

begin_define
define|#
directive|define
name|KR0
value|0x50A28BE6L
end_define

begin_define
define|#
directive|define
name|KR1
value|0x5C4DD124L
end_define

begin_define
define|#
directive|define
name|KR2
value|0x6D703EF3L
end_define

begin_define
define|#
directive|define
name|KR3
value|0x7A6D76E9L
end_define

begin_define
define|#
directive|define
name|KR4
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|WL00
value|0
end_define

begin_define
define|#
directive|define
name|SL00
value|11
end_define

begin_define
define|#
directive|define
name|WL01
value|1
end_define

begin_define
define|#
directive|define
name|SL01
value|14
end_define

begin_define
define|#
directive|define
name|WL02
value|2
end_define

begin_define
define|#
directive|define
name|SL02
value|15
end_define

begin_define
define|#
directive|define
name|WL03
value|3
end_define

begin_define
define|#
directive|define
name|SL03
value|12
end_define

begin_define
define|#
directive|define
name|WL04
value|4
end_define

begin_define
define|#
directive|define
name|SL04
value|5
end_define

begin_define
define|#
directive|define
name|WL05
value|5
end_define

begin_define
define|#
directive|define
name|SL05
value|8
end_define

begin_define
define|#
directive|define
name|WL06
value|6
end_define

begin_define
define|#
directive|define
name|SL06
value|7
end_define

begin_define
define|#
directive|define
name|WL07
value|7
end_define

begin_define
define|#
directive|define
name|SL07
value|9
end_define

begin_define
define|#
directive|define
name|WL08
value|8
end_define

begin_define
define|#
directive|define
name|SL08
value|11
end_define

begin_define
define|#
directive|define
name|WL09
value|9
end_define

begin_define
define|#
directive|define
name|SL09
value|13
end_define

begin_define
define|#
directive|define
name|WL10
value|10
end_define

begin_define
define|#
directive|define
name|SL10
value|14
end_define

begin_define
define|#
directive|define
name|WL11
value|11
end_define

begin_define
define|#
directive|define
name|SL11
value|15
end_define

begin_define
define|#
directive|define
name|WL12
value|12
end_define

begin_define
define|#
directive|define
name|SL12
value|6
end_define

begin_define
define|#
directive|define
name|WL13
value|13
end_define

begin_define
define|#
directive|define
name|SL13
value|7
end_define

begin_define
define|#
directive|define
name|WL14
value|14
end_define

begin_define
define|#
directive|define
name|SL14
value|9
end_define

begin_define
define|#
directive|define
name|WL15
value|15
end_define

begin_define
define|#
directive|define
name|SL15
value|8
end_define

begin_define
define|#
directive|define
name|WL16
value|7
end_define

begin_define
define|#
directive|define
name|SL16
value|7
end_define

begin_define
define|#
directive|define
name|WL17
value|4
end_define

begin_define
define|#
directive|define
name|SL17
value|6
end_define

begin_define
define|#
directive|define
name|WL18
value|13
end_define

begin_define
define|#
directive|define
name|SL18
value|8
end_define

begin_define
define|#
directive|define
name|WL19
value|1
end_define

begin_define
define|#
directive|define
name|SL19
value|13
end_define

begin_define
define|#
directive|define
name|WL20
value|10
end_define

begin_define
define|#
directive|define
name|SL20
value|11
end_define

begin_define
define|#
directive|define
name|WL21
value|6
end_define

begin_define
define|#
directive|define
name|SL21
value|9
end_define

begin_define
define|#
directive|define
name|WL22
value|15
end_define

begin_define
define|#
directive|define
name|SL22
value|7
end_define

begin_define
define|#
directive|define
name|WL23
value|3
end_define

begin_define
define|#
directive|define
name|SL23
value|15
end_define

begin_define
define|#
directive|define
name|WL24
value|12
end_define

begin_define
define|#
directive|define
name|SL24
value|7
end_define

begin_define
define|#
directive|define
name|WL25
value|0
end_define

begin_define
define|#
directive|define
name|SL25
value|12
end_define

begin_define
define|#
directive|define
name|WL26
value|9
end_define

begin_define
define|#
directive|define
name|SL26
value|15
end_define

begin_define
define|#
directive|define
name|WL27
value|5
end_define

begin_define
define|#
directive|define
name|SL27
value|9
end_define

begin_define
define|#
directive|define
name|WL28
value|2
end_define

begin_define
define|#
directive|define
name|SL28
value|11
end_define

begin_define
define|#
directive|define
name|WL29
value|14
end_define

begin_define
define|#
directive|define
name|SL29
value|7
end_define

begin_define
define|#
directive|define
name|WL30
value|11
end_define

begin_define
define|#
directive|define
name|SL30
value|13
end_define

begin_define
define|#
directive|define
name|WL31
value|8
end_define

begin_define
define|#
directive|define
name|SL31
value|12
end_define

begin_define
define|#
directive|define
name|WL32
value|3
end_define

begin_define
define|#
directive|define
name|SL32
value|11
end_define

begin_define
define|#
directive|define
name|WL33
value|10
end_define

begin_define
define|#
directive|define
name|SL33
value|13
end_define

begin_define
define|#
directive|define
name|WL34
value|14
end_define

begin_define
define|#
directive|define
name|SL34
value|6
end_define

begin_define
define|#
directive|define
name|WL35
value|4
end_define

begin_define
define|#
directive|define
name|SL35
value|7
end_define

begin_define
define|#
directive|define
name|WL36
value|9
end_define

begin_define
define|#
directive|define
name|SL36
value|14
end_define

begin_define
define|#
directive|define
name|WL37
value|15
end_define

begin_define
define|#
directive|define
name|SL37
value|9
end_define

begin_define
define|#
directive|define
name|WL38
value|8
end_define

begin_define
define|#
directive|define
name|SL38
value|13
end_define

begin_define
define|#
directive|define
name|WL39
value|1
end_define

begin_define
define|#
directive|define
name|SL39
value|15
end_define

begin_define
define|#
directive|define
name|WL40
value|2
end_define

begin_define
define|#
directive|define
name|SL40
value|14
end_define

begin_define
define|#
directive|define
name|WL41
value|7
end_define

begin_define
define|#
directive|define
name|SL41
value|8
end_define

begin_define
define|#
directive|define
name|WL42
value|0
end_define

begin_define
define|#
directive|define
name|SL42
value|13
end_define

begin_define
define|#
directive|define
name|WL43
value|6
end_define

begin_define
define|#
directive|define
name|SL43
value|6
end_define

begin_define
define|#
directive|define
name|WL44
value|13
end_define

begin_define
define|#
directive|define
name|SL44
value|5
end_define

begin_define
define|#
directive|define
name|WL45
value|11
end_define

begin_define
define|#
directive|define
name|SL45
value|12
end_define

begin_define
define|#
directive|define
name|WL46
value|5
end_define

begin_define
define|#
directive|define
name|SL46
value|7
end_define

begin_define
define|#
directive|define
name|WL47
value|12
end_define

begin_define
define|#
directive|define
name|SL47
value|5
end_define

begin_define
define|#
directive|define
name|WL48
value|1
end_define

begin_define
define|#
directive|define
name|SL48
value|11
end_define

begin_define
define|#
directive|define
name|WL49
value|9
end_define

begin_define
define|#
directive|define
name|SL49
value|12
end_define

begin_define
define|#
directive|define
name|WL50
value|11
end_define

begin_define
define|#
directive|define
name|SL50
value|14
end_define

begin_define
define|#
directive|define
name|WL51
value|10
end_define

begin_define
define|#
directive|define
name|SL51
value|15
end_define

begin_define
define|#
directive|define
name|WL52
value|0
end_define

begin_define
define|#
directive|define
name|SL52
value|14
end_define

begin_define
define|#
directive|define
name|WL53
value|8
end_define

begin_define
define|#
directive|define
name|SL53
value|15
end_define

begin_define
define|#
directive|define
name|WL54
value|12
end_define

begin_define
define|#
directive|define
name|SL54
value|9
end_define

begin_define
define|#
directive|define
name|WL55
value|4
end_define

begin_define
define|#
directive|define
name|SL55
value|8
end_define

begin_define
define|#
directive|define
name|WL56
value|13
end_define

begin_define
define|#
directive|define
name|SL56
value|9
end_define

begin_define
define|#
directive|define
name|WL57
value|3
end_define

begin_define
define|#
directive|define
name|SL57
value|14
end_define

begin_define
define|#
directive|define
name|WL58
value|7
end_define

begin_define
define|#
directive|define
name|SL58
value|5
end_define

begin_define
define|#
directive|define
name|WL59
value|15
end_define

begin_define
define|#
directive|define
name|SL59
value|6
end_define

begin_define
define|#
directive|define
name|WL60
value|14
end_define

begin_define
define|#
directive|define
name|SL60
value|8
end_define

begin_define
define|#
directive|define
name|WL61
value|5
end_define

begin_define
define|#
directive|define
name|SL61
value|6
end_define

begin_define
define|#
directive|define
name|WL62
value|6
end_define

begin_define
define|#
directive|define
name|SL62
value|5
end_define

begin_define
define|#
directive|define
name|WL63
value|2
end_define

begin_define
define|#
directive|define
name|SL63
value|12
end_define

begin_define
define|#
directive|define
name|WL64
value|4
end_define

begin_define
define|#
directive|define
name|SL64
value|9
end_define

begin_define
define|#
directive|define
name|WL65
value|0
end_define

begin_define
define|#
directive|define
name|SL65
value|15
end_define

begin_define
define|#
directive|define
name|WL66
value|5
end_define

begin_define
define|#
directive|define
name|SL66
value|5
end_define

begin_define
define|#
directive|define
name|WL67
value|9
end_define

begin_define
define|#
directive|define
name|SL67
value|11
end_define

begin_define
define|#
directive|define
name|WL68
value|7
end_define

begin_define
define|#
directive|define
name|SL68
value|6
end_define

begin_define
define|#
directive|define
name|WL69
value|12
end_define

begin_define
define|#
directive|define
name|SL69
value|8
end_define

begin_define
define|#
directive|define
name|WL70
value|2
end_define

begin_define
define|#
directive|define
name|SL70
value|13
end_define

begin_define
define|#
directive|define
name|WL71
value|10
end_define

begin_define
define|#
directive|define
name|SL71
value|12
end_define

begin_define
define|#
directive|define
name|WL72
value|14
end_define

begin_define
define|#
directive|define
name|SL72
value|5
end_define

begin_define
define|#
directive|define
name|WL73
value|1
end_define

begin_define
define|#
directive|define
name|SL73
value|12
end_define

begin_define
define|#
directive|define
name|WL74
value|3
end_define

begin_define
define|#
directive|define
name|SL74
value|13
end_define

begin_define
define|#
directive|define
name|WL75
value|8
end_define

begin_define
define|#
directive|define
name|SL75
value|14
end_define

begin_define
define|#
directive|define
name|WL76
value|11
end_define

begin_define
define|#
directive|define
name|SL76
value|11
end_define

begin_define
define|#
directive|define
name|WL77
value|6
end_define

begin_define
define|#
directive|define
name|SL77
value|8
end_define

begin_define
define|#
directive|define
name|WL78
value|15
end_define

begin_define
define|#
directive|define
name|SL78
value|5
end_define

begin_define
define|#
directive|define
name|WL79
value|13
end_define

begin_define
define|#
directive|define
name|SL79
value|6
end_define

begin_define
define|#
directive|define
name|WR00
value|5
end_define

begin_define
define|#
directive|define
name|SR00
value|8
end_define

begin_define
define|#
directive|define
name|WR01
value|14
end_define

begin_define
define|#
directive|define
name|SR01
value|9
end_define

begin_define
define|#
directive|define
name|WR02
value|7
end_define

begin_define
define|#
directive|define
name|SR02
value|9
end_define

begin_define
define|#
directive|define
name|WR03
value|0
end_define

begin_define
define|#
directive|define
name|SR03
value|11
end_define

begin_define
define|#
directive|define
name|WR04
value|9
end_define

begin_define
define|#
directive|define
name|SR04
value|13
end_define

begin_define
define|#
directive|define
name|WR05
value|2
end_define

begin_define
define|#
directive|define
name|SR05
value|15
end_define

begin_define
define|#
directive|define
name|WR06
value|11
end_define

begin_define
define|#
directive|define
name|SR06
value|15
end_define

begin_define
define|#
directive|define
name|WR07
value|4
end_define

begin_define
define|#
directive|define
name|SR07
value|5
end_define

begin_define
define|#
directive|define
name|WR08
value|13
end_define

begin_define
define|#
directive|define
name|SR08
value|7
end_define

begin_define
define|#
directive|define
name|WR09
value|6
end_define

begin_define
define|#
directive|define
name|SR09
value|7
end_define

begin_define
define|#
directive|define
name|WR10
value|15
end_define

begin_define
define|#
directive|define
name|SR10
value|8
end_define

begin_define
define|#
directive|define
name|WR11
value|8
end_define

begin_define
define|#
directive|define
name|SR11
value|11
end_define

begin_define
define|#
directive|define
name|WR12
value|1
end_define

begin_define
define|#
directive|define
name|SR12
value|14
end_define

begin_define
define|#
directive|define
name|WR13
value|10
end_define

begin_define
define|#
directive|define
name|SR13
value|14
end_define

begin_define
define|#
directive|define
name|WR14
value|3
end_define

begin_define
define|#
directive|define
name|SR14
value|12
end_define

begin_define
define|#
directive|define
name|WR15
value|12
end_define

begin_define
define|#
directive|define
name|SR15
value|6
end_define

begin_define
define|#
directive|define
name|WR16
value|6
end_define

begin_define
define|#
directive|define
name|SR16
value|9
end_define

begin_define
define|#
directive|define
name|WR17
value|11
end_define

begin_define
define|#
directive|define
name|SR17
value|13
end_define

begin_define
define|#
directive|define
name|WR18
value|3
end_define

begin_define
define|#
directive|define
name|SR18
value|15
end_define

begin_define
define|#
directive|define
name|WR19
value|7
end_define

begin_define
define|#
directive|define
name|SR19
value|7
end_define

begin_define
define|#
directive|define
name|WR20
value|0
end_define

begin_define
define|#
directive|define
name|SR20
value|12
end_define

begin_define
define|#
directive|define
name|WR21
value|13
end_define

begin_define
define|#
directive|define
name|SR21
value|8
end_define

begin_define
define|#
directive|define
name|WR22
value|5
end_define

begin_define
define|#
directive|define
name|SR22
value|9
end_define

begin_define
define|#
directive|define
name|WR23
value|10
end_define

begin_define
define|#
directive|define
name|SR23
value|11
end_define

begin_define
define|#
directive|define
name|WR24
value|14
end_define

begin_define
define|#
directive|define
name|SR24
value|7
end_define

begin_define
define|#
directive|define
name|WR25
value|15
end_define

begin_define
define|#
directive|define
name|SR25
value|7
end_define

begin_define
define|#
directive|define
name|WR26
value|8
end_define

begin_define
define|#
directive|define
name|SR26
value|12
end_define

begin_define
define|#
directive|define
name|WR27
value|12
end_define

begin_define
define|#
directive|define
name|SR27
value|7
end_define

begin_define
define|#
directive|define
name|WR28
value|4
end_define

begin_define
define|#
directive|define
name|SR28
value|6
end_define

begin_define
define|#
directive|define
name|WR29
value|9
end_define

begin_define
define|#
directive|define
name|SR29
value|15
end_define

begin_define
define|#
directive|define
name|WR30
value|1
end_define

begin_define
define|#
directive|define
name|SR30
value|13
end_define

begin_define
define|#
directive|define
name|WR31
value|2
end_define

begin_define
define|#
directive|define
name|SR31
value|11
end_define

begin_define
define|#
directive|define
name|WR32
value|15
end_define

begin_define
define|#
directive|define
name|SR32
value|9
end_define

begin_define
define|#
directive|define
name|WR33
value|5
end_define

begin_define
define|#
directive|define
name|SR33
value|7
end_define

begin_define
define|#
directive|define
name|WR34
value|1
end_define

begin_define
define|#
directive|define
name|SR34
value|15
end_define

begin_define
define|#
directive|define
name|WR35
value|3
end_define

begin_define
define|#
directive|define
name|SR35
value|11
end_define

begin_define
define|#
directive|define
name|WR36
value|7
end_define

begin_define
define|#
directive|define
name|SR36
value|8
end_define

begin_define
define|#
directive|define
name|WR37
value|14
end_define

begin_define
define|#
directive|define
name|SR37
value|6
end_define

begin_define
define|#
directive|define
name|WR38
value|6
end_define

begin_define
define|#
directive|define
name|SR38
value|6
end_define

begin_define
define|#
directive|define
name|WR39
value|9
end_define

begin_define
define|#
directive|define
name|SR39
value|14
end_define

begin_define
define|#
directive|define
name|WR40
value|11
end_define

begin_define
define|#
directive|define
name|SR40
value|12
end_define

begin_define
define|#
directive|define
name|WR41
value|8
end_define

begin_define
define|#
directive|define
name|SR41
value|13
end_define

begin_define
define|#
directive|define
name|WR42
value|12
end_define

begin_define
define|#
directive|define
name|SR42
value|5
end_define

begin_define
define|#
directive|define
name|WR43
value|2
end_define

begin_define
define|#
directive|define
name|SR43
value|14
end_define

begin_define
define|#
directive|define
name|WR44
value|10
end_define

begin_define
define|#
directive|define
name|SR44
value|13
end_define

begin_define
define|#
directive|define
name|WR45
value|0
end_define

begin_define
define|#
directive|define
name|SR45
value|13
end_define

begin_define
define|#
directive|define
name|WR46
value|4
end_define

begin_define
define|#
directive|define
name|SR46
value|7
end_define

begin_define
define|#
directive|define
name|WR47
value|13
end_define

begin_define
define|#
directive|define
name|SR47
value|5
end_define

begin_define
define|#
directive|define
name|WR48
value|8
end_define

begin_define
define|#
directive|define
name|SR48
value|15
end_define

begin_define
define|#
directive|define
name|WR49
value|6
end_define

begin_define
define|#
directive|define
name|SR49
value|5
end_define

begin_define
define|#
directive|define
name|WR50
value|4
end_define

begin_define
define|#
directive|define
name|SR50
value|8
end_define

begin_define
define|#
directive|define
name|WR51
value|1
end_define

begin_define
define|#
directive|define
name|SR51
value|11
end_define

begin_define
define|#
directive|define
name|WR52
value|3
end_define

begin_define
define|#
directive|define
name|SR52
value|14
end_define

begin_define
define|#
directive|define
name|WR53
value|11
end_define

begin_define
define|#
directive|define
name|SR53
value|14
end_define

begin_define
define|#
directive|define
name|WR54
value|15
end_define

begin_define
define|#
directive|define
name|SR54
value|6
end_define

begin_define
define|#
directive|define
name|WR55
value|0
end_define

begin_define
define|#
directive|define
name|SR55
value|14
end_define

begin_define
define|#
directive|define
name|WR56
value|5
end_define

begin_define
define|#
directive|define
name|SR56
value|6
end_define

begin_define
define|#
directive|define
name|WR57
value|12
end_define

begin_define
define|#
directive|define
name|SR57
value|9
end_define

begin_define
define|#
directive|define
name|WR58
value|2
end_define

begin_define
define|#
directive|define
name|SR58
value|12
end_define

begin_define
define|#
directive|define
name|WR59
value|13
end_define

begin_define
define|#
directive|define
name|SR59
value|9
end_define

begin_define
define|#
directive|define
name|WR60
value|9
end_define

begin_define
define|#
directive|define
name|SR60
value|12
end_define

begin_define
define|#
directive|define
name|WR61
value|7
end_define

begin_define
define|#
directive|define
name|SR61
value|5
end_define

begin_define
define|#
directive|define
name|WR62
value|10
end_define

begin_define
define|#
directive|define
name|SR62
value|15
end_define

begin_define
define|#
directive|define
name|WR63
value|14
end_define

begin_define
define|#
directive|define
name|SR63
value|8
end_define

begin_define
define|#
directive|define
name|WR64
value|12
end_define

begin_define
define|#
directive|define
name|SR64
value|8
end_define

begin_define
define|#
directive|define
name|WR65
value|15
end_define

begin_define
define|#
directive|define
name|SR65
value|5
end_define

begin_define
define|#
directive|define
name|WR66
value|10
end_define

begin_define
define|#
directive|define
name|SR66
value|12
end_define

begin_define
define|#
directive|define
name|WR67
value|4
end_define

begin_define
define|#
directive|define
name|SR67
value|9
end_define

begin_define
define|#
directive|define
name|WR68
value|1
end_define

begin_define
define|#
directive|define
name|SR68
value|12
end_define

begin_define
define|#
directive|define
name|WR69
value|5
end_define

begin_define
define|#
directive|define
name|SR69
value|5
end_define

begin_define
define|#
directive|define
name|WR70
value|8
end_define

begin_define
define|#
directive|define
name|SR70
value|14
end_define

begin_define
define|#
directive|define
name|WR71
value|7
end_define

begin_define
define|#
directive|define
name|SR71
value|6
end_define

begin_define
define|#
directive|define
name|WR72
value|6
end_define

begin_define
define|#
directive|define
name|SR72
value|8
end_define

begin_define
define|#
directive|define
name|WR73
value|2
end_define

begin_define
define|#
directive|define
name|SR73
value|13
end_define

begin_define
define|#
directive|define
name|WR74
value|13
end_define

begin_define
define|#
directive|define
name|SR74
value|6
end_define

begin_define
define|#
directive|define
name|WR75
value|14
end_define

begin_define
define|#
directive|define
name|SR75
value|5
end_define

begin_define
define|#
directive|define
name|WR76
value|0
end_define

begin_define
define|#
directive|define
name|SR76
value|15
end_define

begin_define
define|#
directive|define
name|WR77
value|3
end_define

begin_define
define|#
directive|define
name|SR77
value|13
end_define

begin_define
define|#
directive|define
name|WR78
value|9
end_define

begin_define
define|#
directive|define
name|SR78
value|11
end_define

begin_define
define|#
directive|define
name|WR79
value|11
end_define

begin_define
define|#
directive|define
name|SR79
value|11
end_define

end_unit

