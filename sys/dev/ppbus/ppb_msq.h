begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Nicolas Souchu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PPB_MSQ_H
end_ifndef

begin_define
define|#
directive|define
name|__PPB_MSQ_H
end_define

begin_comment
comment|/*  * Basic definitions  */
end_comment

begin_comment
comment|/* microsequence parameter descriptor */
end_comment

begin_define
define|#
directive|define
name|MS_INS_MASK
value|0x00ff
end_define

begin_comment
comment|/* mask to retrieve the instruction position< 256	XXX */
end_comment

begin_define
define|#
directive|define
name|MS_ARG_MASK
value|0x0f00
end_define

begin_comment
comment|/* mask to retrieve the argument number */
end_comment

begin_define
define|#
directive|define
name|MS_TYP_MASK
value|0xf000
end_define

begin_comment
comment|/* mask to retrieve the type of the param */
end_comment

begin_comment
comment|/* offset of each mask (see above) */
end_comment

begin_define
define|#
directive|define
name|MS_INS_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|MS_ARG_OFFSET
value|8
end_define

begin_define
define|#
directive|define
name|MS_TYP_OFFSET
value|12
end_define

begin_comment
comment|/* list of parameter types */
end_comment

begin_define
define|#
directive|define
name|MS_TYP_INT
value|0x0
end_define

begin_comment
comment|/* integer */
end_comment

begin_define
define|#
directive|define
name|MS_TYP_CHA
value|0x1
end_define

begin_comment
comment|/* character */
end_comment

begin_define
define|#
directive|define
name|MS_TYP_PTR
value|0x2
end_define

begin_comment
comment|/* void pointer */
end_comment

begin_define
define|#
directive|define
name|MS_TYP_FUN
value|0x3
end_define

begin_comment
comment|/* function pointer */
end_comment

begin_define
define|#
directive|define
name|MS_PARAM
parameter_list|(
name|ins
parameter_list|,
name|arg
parameter_list|,
name|typ
parameter_list|)
define|\
value|(((ins<<MS_INS_OFFSET)& MS_INS_MASK) | \ 	 ((arg<<MS_ARG_OFFSET)& MS_ARG_MASK) | \ 	 ((typ<<MS_TYP_OFFSET)& MS_TYP_MASK))
end_define

begin_define
define|#
directive|define
name|MS_INS
parameter_list|(
name|param
parameter_list|)
value|((param& MS_INS_MASK)>> MS_INS_OFFSET)
end_define

begin_define
define|#
directive|define
name|MS_ARG
parameter_list|(
name|param
parameter_list|)
value|((param& MS_ARG_MASK)>> MS_ARG_OFFSET)
end_define

begin_define
define|#
directive|define
name|MS_TYP
parameter_list|(
name|param
parameter_list|)
value|((param& MS_TYP_MASK)>> MS_TYP_OFFSET)
end_define

begin_comment
comment|/* microsequence opcodes - do not change! */
end_comment

begin_define
define|#
directive|define
name|MS_OP_GET
value|0
end_define

begin_comment
comment|/* get<ptr>,<len>			*/
end_comment

begin_define
define|#
directive|define
name|MS_OP_PUT
value|1
end_define

begin_comment
comment|/* put<ptr>,<len>			*/
end_comment

begin_define
define|#
directive|define
name|MS_OP_RFETCH
value|2
end_define

begin_comment
comment|/* rfetch<reg>,<mask>,<ptr>		*/
end_comment

begin_define
define|#
directive|define
name|MS_OP_RSET
value|3
end_define

begin_comment
comment|/* rset<reg>,<mask>,<mask>		*/
end_comment

begin_define
define|#
directive|define
name|MS_OP_RASSERT
value|4
end_define

begin_comment
comment|/* rassert<reg>,<mask>		*/
end_comment

begin_define
define|#
directive|define
name|MS_OP_DELAY
value|5
end_define

begin_comment
comment|/* delay<val>				*/
end_comment

begin_define
define|#
directive|define
name|MS_OP_SET
value|6
end_define

begin_comment
comment|/* set<val>				*/
end_comment

begin_define
define|#
directive|define
name|MS_OP_DBRA
value|7
end_define

begin_comment
comment|/* dbra<offset>			*/
end_comment

begin_define
define|#
directive|define
name|MS_OP_BRSET
value|8
end_define

begin_comment
comment|/* brset<mask>,<offset>		*/
end_comment

begin_define
define|#
directive|define
name|MS_OP_BRCLEAR
value|9
end_define

begin_comment
comment|/* brclear<mask>,<offset>		*/
end_comment

begin_define
define|#
directive|define
name|MS_OP_RET
value|10
end_define

begin_comment
comment|/* ret<retcode>			*/
end_comment

begin_define
define|#
directive|define
name|MS_OP_C_CALL
value|11
end_define

begin_comment
comment|/* c_call<function>,<parameter>	*/
end_comment

begin_define
define|#
directive|define
name|MS_OP_PTR
value|12
end_define

begin_comment
comment|/* ptr<pointer>			*/
end_comment

begin_define
define|#
directive|define
name|MS_OP_ADELAY
value|13
end_define

begin_comment
comment|/* adelay<val>				*/
end_comment

begin_define
define|#
directive|define
name|MS_OP_BRSTAT
value|14
end_define

begin_comment
comment|/* brstat<mask>,<mask>,<offset>	*/
end_comment

begin_define
define|#
directive|define
name|MS_OP_SUBRET
value|15
end_define

begin_comment
comment|/* subret<code>			*/
end_comment

begin_define
define|#
directive|define
name|MS_OP_CALL
value|16
end_define

begin_comment
comment|/* call<microsequence>			*/
end_comment

begin_define
define|#
directive|define
name|MS_OP_RASSERT_P
value|17
end_define

begin_comment
comment|/* rassert_p<iter>,<reg>		*/
end_comment

begin_define
define|#
directive|define
name|MS_OP_RFETCH_P
value|18
end_define

begin_comment
comment|/* rfetch_p<iter>,<reg>,<mask>	*/
end_comment

begin_define
define|#
directive|define
name|MS_OP_TRIG
value|19
end_define

begin_comment
comment|/* trigger<reg>,<len>,<array>	*/
end_comment

begin_comment
comment|/* common masks */
end_comment

begin_define
define|#
directive|define
name|MS_CLEAR_ALL
value|0x0
end_define

begin_define
define|#
directive|define
name|MS_ASSERT_NONE
value|0x0
end_define

begin_define
define|#
directive|define
name|MS_ASSERT_ALL
value|0xff
end_define

begin_define
define|#
directive|define
name|MS_FETCH_ALL
value|0xff
end_define

begin_comment
comment|/* undefined parameter value */
end_comment

begin_define
define|#
directive|define
name|MS_NULL
value|0
end_define

begin_define
define|#
directive|define
name|MS_UNKNOWN
value|MS_NULL
end_define

begin_comment
comment|/* predifined parameters */
end_comment

begin_define
define|#
directive|define
name|MS_ACCUM
value|-1
end_define

begin_comment
comment|/* use accum previously set by MS_OP_SET */
end_comment

begin_comment
comment|/* these are register numbers according to our PC-like parallel port model */
end_comment

begin_define
define|#
directive|define
name|MS_REG_DTR
value|0x0
end_define

begin_define
define|#
directive|define
name|MS_REG_STR
value|0x1
end_define

begin_define
define|#
directive|define
name|MS_REG_CTR
value|0x2
end_define

begin_define
define|#
directive|define
name|MS_REG_EPP_A
value|0x3
end_define

begin_define
define|#
directive|define
name|MS_REG_EPP_D
value|0x4
end_define

begin_comment
comment|/*  * Microsequence macro abstraction level  */
end_comment

begin_comment
comment|/* register operations */
end_comment

begin_define
define|#
directive|define
name|MS_RSET
parameter_list|(
name|reg
parameter_list|,
name|assert
parameter_list|,
name|clear
parameter_list|)
value|{ MS_OP_RSET, {{ reg }, { assert }, { clear }}}
end_define

begin_define
define|#
directive|define
name|MS_RASSERT
parameter_list|(
name|reg
parameter_list|,
name|byte
parameter_list|)
value|{ MS_OP_RASSERT, { { reg }, { byte }}}
end_define

begin_define
define|#
directive|define
name|MS_RCLR
parameter_list|(
name|reg
parameter_list|,
name|clear
parameter_list|)
value|{ MS_OP_RSET, {{ reg }, { MS_ASSERT_NONE }, { clear }}}
end_define

begin_define
define|#
directive|define
name|MS_RFETCH
parameter_list|(
name|reg
parameter_list|,
name|mask
parameter_list|,
name|ptr
parameter_list|)
value|{ MS_OP_RFETCH, {{ reg }, { mask }, { ptr }}}
end_define

begin_comment
comment|/* trigger the port with array[char, delay,...] */
end_comment

begin_define
define|#
directive|define
name|MS_TRIG
parameter_list|(
name|reg
parameter_list|,
name|len
parameter_list|,
name|array
parameter_list|)
value|{ MS_OP_TRIG, {{ reg }, { len }, { array }}}
end_define

begin_comment
comment|/* assert/fetch from/to ptr */
end_comment

begin_define
define|#
directive|define
name|MS_RASSERT_P
parameter_list|(
name|n
parameter_list|,
name|reg
parameter_list|)
value|{ MS_OP_RASSERT_P, {{ n }, { reg }}}
end_define

begin_define
define|#
directive|define
name|MS_RFETCH_P
parameter_list|(
name|n
parameter_list|,
name|reg
parameter_list|,
name|mask
parameter_list|)
value|{ MS_OP_RFETCH_P, {{ n }, { reg }, { mask }}}
end_define

begin_comment
comment|/* ptr manipulation */
end_comment

begin_define
define|#
directive|define
name|MS_PTR
parameter_list|(
name|ptr
parameter_list|)
value|{ MS_OP_PTR, {{ ptr }}}
end_define

begin_define
define|#
directive|define
name|MS_DASS
parameter_list|(
name|byte
parameter_list|)
value|MS_RASSERT(MS_REG_DTR,byte)
end_define

begin_define
define|#
directive|define
name|MS_SASS
parameter_list|(
name|byte
parameter_list|)
value|MS_RASSERT(MS_REG_STR,byte)
end_define

begin_define
define|#
directive|define
name|MS_CASS
parameter_list|(
name|byte
parameter_list|)
value|MS_RASSERT(MS_REG_CTR,byte)
end_define

begin_define
define|#
directive|define
name|MS_SET
parameter_list|(
name|accum
parameter_list|)
value|{ MS_OP_SET, {{ accum }}}
end_define

begin_define
define|#
directive|define
name|MS_BRSET
parameter_list|(
name|mask
parameter_list|,
name|offset
parameter_list|)
value|{ MS_OP_BRSET, {{ mask }, { offset }}}
end_define

begin_define
define|#
directive|define
name|MS_DBRA
parameter_list|(
name|offset
parameter_list|)
value|{ MS_OP_DBRA, {{ offset }}}
end_define

begin_define
define|#
directive|define
name|MS_BRCLEAR
parameter_list|(
name|mask
parameter_list|,
name|offset
parameter_list|)
value|{ MS_OP_BRCLEAR, {{ mask }, { offset }}}
end_define

begin_define
define|#
directive|define
name|MS_BRSTAT
parameter_list|(
name|mask_set
parameter_list|,
name|mask_clr
parameter_list|,
name|offset
parameter_list|)
define|\
value|{ MS_OP_BRSTAT, {{ mask_set }, { mask_clr }, { offset }}}
end_define

begin_comment
comment|/* C function or submicrosequence call */
end_comment

begin_define
define|#
directive|define
name|MS_C_CALL
parameter_list|(
name|function
parameter_list|,
name|parameter
parameter_list|)
define|\
value|{ MS_OP_C_CALL, {{ function }, { parameter }}}
end_define

begin_define
define|#
directive|define
name|MS_CALL
parameter_list|(
name|microseq
parameter_list|)
value|{ MS_OP_CALL, {{ microseq }}}
end_define

begin_comment
comment|/* mode dependent read/write operations  * ppb_MS_xxx_init() call required otherwise default is  * IEEE1284 operating mode */
end_comment

begin_define
define|#
directive|define
name|MS_PUT
parameter_list|(
name|ptr
parameter_list|,
name|len
parameter_list|)
value|{ MS_OP_PUT, {{ ptr }, { len }}}
end_define

begin_define
define|#
directive|define
name|MS_GET
parameter_list|(
name|ptr
parameter_list|,
name|len
parameter_list|)
value|{ MS_OP_GET, {{ ptr }, { len }}}
end_define

begin_comment
comment|/* delay in microseconds */
end_comment

begin_define
define|#
directive|define
name|MS_DELAY
parameter_list|(
name|udelay
parameter_list|)
value|{ MS_OP_DELAY, {{ udelay }}}
end_define

begin_comment
comment|/* asynchroneous delay in ms */
end_comment

begin_define
define|#
directive|define
name|MS_ADELAY
parameter_list|(
name|mdelay
parameter_list|)
value|{ MS_OP_ADELAY, {{ mdelay }}}
end_define

begin_comment
comment|/* return from submicrosequence execution or microseqence execution */
end_comment

begin_define
define|#
directive|define
name|MS_SUBRET
parameter_list|(
name|code
parameter_list|)
value|{ MS_OP_SUBRET,	{{ code }}}
end_define

begin_define
define|#
directive|define
name|MS_RET
parameter_list|(
name|code
parameter_list|)
value|{ MS_OP_RET, {{ code }}}
end_define

begin_comment
comment|/*  * Function abstraction level  */
end_comment

begin_define
define|#
directive|define
name|ppb_MS_GET_init
parameter_list|(
name|bus
parameter_list|,
name|dev
parameter_list|,
name|body
parameter_list|)
value|ppb_MS_init(bus, dev, body, MS_OP_GET)
end_define

begin_define
define|#
directive|define
name|ppb_MS_PUT_init
parameter_list|(
name|bus
parameter_list|,
name|dev
parameter_list|,
name|body
parameter_list|)
value|ppb_MS_init(bus, dev, body, MS_OP_PUT)
end_define

begin_function_decl
specifier|extern
name|int
name|ppb_MS_init
parameter_list|(
name|device_t
parameter_list|,
comment|/* ppbus bus */
name|device_t
parameter_list|,
comment|/* ppbus device */
name|struct
name|ppb_microseq
modifier|*
parameter_list|,
comment|/* loop msq to assign */
name|int
name|opcode
comment|/* MS_OP_GET, MS_OP_PUT */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_MS_init_msq
parameter_list|(
name|struct
name|ppb_microseq
modifier|*
parameter_list|,
name|int
parameter_list|,
comment|/* number of parameters */
modifier|...
comment|/* descriptor, value, ... */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_MS_exec
parameter_list|(
name|device_t
parameter_list|,
comment|/* ppbus bus */
name|device_t
parameter_list|,
comment|/* ppbus device */
name|int
parameter_list|,
comment|/* microseq opcode */
name|union
name|ppb_insarg
parameter_list|,
comment|/* param1 */
name|union
name|ppb_insarg
parameter_list|,
comment|/* param2 */
name|union
name|ppb_insarg
parameter_list|,
comment|/* param3 */
name|int
modifier|*
comment|/* returned value */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_MS_loop
parameter_list|(
name|device_t
parameter_list|,
comment|/* ppbus bus */
name|device_t
parameter_list|,
comment|/* ppbus device */
name|struct
name|ppb_microseq
modifier|*
parameter_list|,
comment|/* prologue msq of loop */
name|struct
name|ppb_microseq
modifier|*
parameter_list|,
comment|/* body msq of loop */
name|struct
name|ppb_microseq
modifier|*
parameter_list|,
comment|/* epilogue msq of loop */
name|int
parameter_list|,
comment|/* number of iter */
name|int
modifier|*
comment|/* returned value */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_MS_microseq
parameter_list|(
name|device_t
parameter_list|,
comment|/* ppbus bus */
name|device_t
parameter_list|,
comment|/* ppbus device */
name|struct
name|ppb_microseq
modifier|*
parameter_list|,
comment|/* msq to execute */
name|int
modifier|*
comment|/* returned value */
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

