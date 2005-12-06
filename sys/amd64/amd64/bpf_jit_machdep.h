begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 - 2003 NetGroup, Politecnico di Torino (Italy)  * Copyright (c) 2005 Jung-uk Kim<jkim@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  * notice, this list of conditions and the following disclaimer in the  * documentation and/or other materials provided with the distribution.  * 3. Neither the name of the Politecnico di Torino nor the names of its  * contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS intERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BPF_JIT_MACHDEP_H_
end_ifndef

begin_define
define|#
directive|define
name|_BPF_JIT_MACHDEP_H_
end_define

begin_comment
comment|/*  * Registers  */
end_comment

begin_define
define|#
directive|define
name|RAX
value|0
end_define

begin_define
define|#
directive|define
name|RCX
value|1
end_define

begin_define
define|#
directive|define
name|RDX
value|2
end_define

begin_define
define|#
directive|define
name|RBX
value|3
end_define

begin_define
define|#
directive|define
name|RSP
value|4
end_define

begin_define
define|#
directive|define
name|RBP
value|5
end_define

begin_define
define|#
directive|define
name|RSI
value|6
end_define

begin_define
define|#
directive|define
name|RDI
value|7
end_define

begin_define
define|#
directive|define
name|EAX
value|0
end_define

begin_define
define|#
directive|define
name|ECX
value|1
end_define

begin_define
define|#
directive|define
name|EDX
value|2
end_define

begin_define
define|#
directive|define
name|EBX
value|3
end_define

begin_define
define|#
directive|define
name|ESP
value|4
end_define

begin_define
define|#
directive|define
name|EBP
value|5
end_define

begin_define
define|#
directive|define
name|ESI
value|6
end_define

begin_define
define|#
directive|define
name|EDI
value|7
end_define

begin_define
define|#
directive|define
name|AX
value|0
end_define

begin_define
define|#
directive|define
name|CX
value|1
end_define

begin_define
define|#
directive|define
name|DX
value|2
end_define

begin_define
define|#
directive|define
name|BX
value|3
end_define

begin_define
define|#
directive|define
name|SP
value|4
end_define

begin_define
define|#
directive|define
name|BP
value|5
end_define

begin_define
define|#
directive|define
name|SI
value|6
end_define

begin_define
define|#
directive|define
name|DI
value|7
end_define

begin_define
define|#
directive|define
name|AL
value|0
end_define

begin_define
define|#
directive|define
name|CL
value|1
end_define

begin_define
define|#
directive|define
name|DL
value|2
end_define

begin_define
define|#
directive|define
name|BL
value|3
end_define

begin_comment
comment|/* A stream of native binary code.*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|bpf_bin_stream
block|{
comment|/* Current native instruction pointer. */
name|int
name|cur_ip
decl_stmt|;
comment|/* 	 * Current BPF instruction pointer, i.e. position in 	 * the BPF program reached by the jitter. 	 */
name|int
name|bpf_pc
decl_stmt|;
comment|/* Instruction buffer, contains the generated native code. */
name|char
modifier|*
name|ibuf
decl_stmt|;
comment|/* Jumps reference table. */
name|u_int
modifier|*
name|refs
decl_stmt|;
block|}
name|bpf_bin_stream
typedef|;
end_typedef

begin_comment
comment|/*  * Prototype of the emit functions.  *  * Different emit functions are used to create the reference table and  * to generate the actual filtering code. This allows to have simpler  * instruction macros.  * The first parameter is the stream that will receive the data.  * The second one is a variable containing the data.  * The third one is the length, that can be 1, 2, or 4 since it is possible  * to emit a byte, a short, or a word at a time.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|emit_func
function_decl|)
parameter_list|(
name|bpf_bin_stream
modifier|*
name|stream
parameter_list|,
name|u_int
name|value
parameter_list|,
name|u_int
name|n
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * native Instruction Macros  */
end_comment

begin_comment
comment|/* mov r32,i32 */
end_comment

begin_define
define|#
directive|define
name|MOVid
parameter_list|(
name|r32
parameter_list|,
name|i32
parameter_list|)
value|do {						\ 	emitm(&stream, (11<< 4) | (1<< 3) | (r32& 0x7), 1);		\ 	emitm(&stream, i32, 4);						\ } while (0)
end_define

begin_comment
comment|/* mov r64,i64 */
end_comment

begin_define
define|#
directive|define
name|MOViq
parameter_list|(
name|r64
parameter_list|,
name|i64
parameter_list|)
value|do {						\ 	emitm(&stream, 0x48, 1);					\ 	emitm(&stream, (11<< 4) | (1<< 3) | (r64& 0x7), 1);		\ 	emitm(&stream, i64, 4);						\ 	emitm(&stream, (i64>> 32), 4);					\ } while (0)
end_define

begin_comment
comment|/* mov dr32,sr32 */
end_comment

begin_define
define|#
directive|define
name|MOVrd
parameter_list|(
name|dr32
parameter_list|,
name|sr32
parameter_list|)
value|do {						\ 	emitm(&stream, (8<< 4) | 3 | (1<< 3), 1);			\ 	emitm(&stream,							\ 	    (3<< 6) | ((dr32& 0x7)<< 3) | (sr32& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* mov dr64,sr64 */
end_comment

begin_define
define|#
directive|define
name|MOVrq
parameter_list|(
name|dr64
parameter_list|,
name|sr64
parameter_list|)
value|do {						\ 	emitm(&stream, 0x48, 1);					\ 	emitm(&stream, (8<< 4) | 3 | (1<< 3), 1);			\ 	emitm(&stream,							\ 	    (3<< 6) | ((dr64& 0x7)<< 3) | (sr64& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* mov dr32,sr64[off] */
end_comment

begin_define
define|#
directive|define
name|MOVodd
parameter_list|(
name|dr32
parameter_list|,
name|sr64
parameter_list|,
name|off
parameter_list|)
value|do {					\ 	emitm(&stream, (8<< 4) | 3 | (1<< 3), 1);			\ 	emitm(&stream,							\ 	    (1<< 6) | ((dr32& 0x7)<< 3) | (sr64& 0x7), 1);		\ 	emitm(&stream, off, 1);						\ } while (0)
end_define

begin_comment
comment|/* mov dr64[off],sr32 */
end_comment

begin_define
define|#
directive|define
name|MOVoqd
parameter_list|(
name|dr64
parameter_list|,
name|off
parameter_list|,
name|sr32
parameter_list|)
value|do {					\ 	emitm(&stream, (8<< 4) | 1 | (1<< 3), 1);			\ 	emitm(&stream,							\ 	    (1<< 6) | ((sr32& 0x7)<< 3) | (dr64& 0x7), 1);		\ 	emitm(&stream, off, 1);						\ } while (0)
end_define

begin_comment
comment|/* mov dr32,sr64[or64] */
end_comment

begin_define
define|#
directive|define
name|MOVobd
parameter_list|(
name|dr32
parameter_list|,
name|sr64
parameter_list|,
name|or64
parameter_list|)
value|do {					\ 	emitm(&stream, (8<< 4) | 3 | (1<< 3), 1);			\ 	emitm(&stream, ((dr32& 0x7)<< 3) | 4, 1);			\ 	emitm(&stream, ((or64& 0x7)<< 3) | (sr64& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* mov dr16,sr64[or64] */
end_comment

begin_define
define|#
directive|define
name|MOVobw
parameter_list|(
name|dr32
parameter_list|,
name|sr64
parameter_list|,
name|or64
parameter_list|)
value|do {					\ 	emitm(&stream, 0x66, 1);					\ 	emitm(&stream, (8<< 4) | 3 | (1<< 3), 1);			\ 	emitm(&stream, ((dr32& 0x7)<< 3) | 4, 1);			\ 	emitm(&stream, ((or64& 0x7)<< 3) | (sr64& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* mov dr8,sr64[or64] */
end_comment

begin_define
define|#
directive|define
name|MOVobb
parameter_list|(
name|dr8
parameter_list|,
name|sr64
parameter_list|,
name|or64
parameter_list|)
value|do {					\ 	emitm(&stream, 0x8a, 1);					\ 	emitm(&stream, ((dr8& 0x7)<< 3) | 4, 1);			\ 	emitm(&stream, ((or64& 0x7)<< 3) | (sr64& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* mov [dr64][or64],sr32 */
end_comment

begin_define
define|#
directive|define
name|MOVomd
parameter_list|(
name|dr64
parameter_list|,
name|or64
parameter_list|,
name|sr32
parameter_list|)
value|do {					\ 	emitm(&stream, 0x89, 1);					\ 	emitm(&stream, ((sr32& 0x7)<< 3) | 4, 1);			\ 	emitm(&stream, ((or64& 0x7)<< 3) | (dr64& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* bswap dr32 */
end_comment

begin_define
define|#
directive|define
name|BSWAP
parameter_list|(
name|dr32
parameter_list|)
value|do {						\ 	emitm(&stream, 0xf, 1);						\ 	emitm(&stream, (0x19<< 3) | dr32, 1);				\ } while (0)
end_define

begin_comment
comment|/* xchg al,ah */
end_comment

begin_define
define|#
directive|define
name|SWAP_AX
parameter_list|()
value|do {							\ 	emitm(&stream, 0x86, 1);					\ 	emitm(&stream, 0xc4, 1);					\ } while (0)
end_define

begin_comment
comment|/* push r64 */
end_comment

begin_define
define|#
directive|define
name|PUSH
parameter_list|(
name|r64
parameter_list|)
value|do {							\ 	emitm(&stream, (5<< 4) | (0<< 3) | (r64& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* pop r64 */
end_comment

begin_define
define|#
directive|define
name|POP
parameter_list|(
name|r64
parameter_list|)
value|do {							\ 	emitm(&stream, (5<< 4) | (1<< 3) | (r64& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* leave/ret */
end_comment

begin_define
define|#
directive|define
name|LEAVE_RET
parameter_list|()
value|do {						\ 	emitm(&stream, 0xc9, 1);					\ 	emitm(&stream, 0xc3, 1);					\ } while (0)
end_define

begin_comment
comment|/* add dr32,sr32 */
end_comment

begin_define
define|#
directive|define
name|ADDrd
parameter_list|(
name|dr32
parameter_list|,
name|sr32
parameter_list|)
value|do {						\ 	emitm(&stream, 0x03, 1);					\ 	emitm(&stream,							\ 	    (3<< 6) | ((dr32& 0x7)<< 3) | (sr32& 0x7), 1);	\ } while (0)
end_define

begin_comment
comment|/* add eax,i32 */
end_comment

begin_define
define|#
directive|define
name|ADD_EAXi
parameter_list|(
name|i32
parameter_list|)
value|do {						\ 	emitm(&stream, 0x05, 1);					\ 	emitm(&stream, i32, 4);						\ } while (0)
end_define

begin_comment
comment|/* add r32,i32 */
end_comment

begin_define
define|#
directive|define
name|ADDid
parameter_list|(
name|r32
parameter_list|,
name|i32
parameter_list|)
value|do {						\ 	emitm(&stream, 0x81, 1);					\ 	emitm(&stream, (24<< 3) | r32, 1);				\ 	emitm(&stream, i32, 4);						\ } while (0)
end_define

begin_comment
comment|/* add r32,i8 */
end_comment

begin_define
define|#
directive|define
name|ADDib
parameter_list|(
name|r32
parameter_list|,
name|i8
parameter_list|)
value|do {						\ 	emitm(&stream, 0x83, 1);					\ 	emitm(&stream, (24<< 3) | r32, 1);				\ 	emitm(&stream, i8, 1);						\ } while (0)
end_define

begin_comment
comment|/* sub dr32,sr32 */
end_comment

begin_define
define|#
directive|define
name|SUBrd
parameter_list|(
name|dr32
parameter_list|,
name|sr32
parameter_list|)
value|do {						\ 	emitm(&stream, 0x2b, 1);					\ 	emitm(&stream,							\ 	    (3<< 6) | ((dr32& 0x7)<< 3) | (sr32& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* sub eax,i32 */
end_comment

begin_define
define|#
directive|define
name|SUB_EAXi
parameter_list|(
name|i32
parameter_list|)
value|do {						\ 	emitm(&stream, 0x2d, 1);					\ 	emitm(&stream, i32, 4);						\ } while (0)
end_define

begin_comment
comment|/* mul r32 */
end_comment

begin_define
define|#
directive|define
name|MULrd
parameter_list|(
name|r32
parameter_list|)
value|do {							\ 	emitm(&stream, 0xf7, 1);					\ 	emitm(&stream, (7<< 5) | (r32& 0x7), 1);			\ } while (0)
end_define

begin_comment
comment|/* div r32 */
end_comment

begin_define
define|#
directive|define
name|DIVrd
parameter_list|(
name|r32
parameter_list|)
value|do {							\ 	emitm(&stream, 0xf7, 1);					\ 	emitm(&stream, (15<< 4) | (r32& 0x7), 1);			\ } while (0)
end_define

begin_comment
comment|/* and r8,i8 */
end_comment

begin_define
define|#
directive|define
name|ANDib
parameter_list|(
name|r8
parameter_list|,
name|i8
parameter_list|)
value|do {						\ 	emitm(&stream, 0x80, 1);					\ 	emitm(&stream, (7<< 5) | r8, 1);				\ 	emitm(&stream, i8, 1);						\ } while (0)
end_define

begin_comment
comment|/* and r32,i32 */
end_comment

begin_define
define|#
directive|define
name|ANDid
parameter_list|(
name|r32
parameter_list|,
name|i32
parameter_list|)
value|do {						\ 	if (r32 == EAX) {						\ 		emitm(&stream, 0x25, 1);				\ 		emitm(&stream, i32, 4);					\ 	} else {							\ 		emitm(&stream, 0x81, 1);				\ 		emitm(&stream, (7<< 5) | r32, 1);			\ 		emitm(&stream, i32, 4);					\ 	}								\ } while (0)
end_define

begin_comment
comment|/* and dr32,sr32 */
end_comment

begin_define
define|#
directive|define
name|ANDrd
parameter_list|(
name|dr32
parameter_list|,
name|sr32
parameter_list|)
value|do {						\ 	emitm(&stream, 0x23, 1);					\ 	emitm(&stream,							\ 	    (3<< 6) | ((dr32& 0x7)<< 3) | (sr32& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* or dr32,sr32 */
end_comment

begin_define
define|#
directive|define
name|ORrd
parameter_list|(
name|dr32
parameter_list|,
name|sr32
parameter_list|)
value|do {						\ 	emitm(&stream, 0x0b, 1);					\ 	emitm(&stream,							\ 	    (3<< 6) | ((dr32& 0x7)<< 3) | (sr32& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* or r32,i32 */
end_comment

begin_define
define|#
directive|define
name|ORid
parameter_list|(
name|r32
parameter_list|,
name|i32
parameter_list|)
value|do {						\ 	if (r32 == EAX) {						\ 		emitm(&stream, 0x0d, 1);				\ 		emitm(&stream, i32, 4);					\ 	} else {							\ 		emitm(&stream, 0x81, 1);				\ 		emitm(&stream, (25<< 3) | r32, 1);			\ 		emitm(&stream, i32, 4);					\ 	}								\ } while (0)
end_define

begin_comment
comment|/* shl r32,i8 */
end_comment

begin_define
define|#
directive|define
name|SHLib
parameter_list|(
name|r32
parameter_list|,
name|i8
parameter_list|)
value|do {						\ 	emitm(&stream, 0xc1, 1);					\ 	emitm(&stream, (7<< 5) | (r32& 0x7), 1);			\ 	emitm(&stream, i8, 1);						\ } while (0)
end_define

begin_comment
comment|/* shl dr32,cl */
end_comment

begin_define
define|#
directive|define
name|SHL_CLrb
parameter_list|(
name|dr32
parameter_list|)
value|do {						\ 	emitm(&stream, 0xd3, 1);					\ 	emitm(&stream, (7<< 5) | (dr32& 0x7), 1);			\ } while (0)
end_define

begin_comment
comment|/* shr r32,i8 */
end_comment

begin_define
define|#
directive|define
name|SHRib
parameter_list|(
name|r32
parameter_list|,
name|i8
parameter_list|)
value|do {						\ 	emitm(&stream, 0xc1, 1);					\ 	emitm(&stream, (29<< 3) | (r32& 0x7), 1);			\ 	emitm(&stream, i8, 1);						\ } while (0)
end_define

begin_comment
comment|/* shr dr32,cl */
end_comment

begin_define
define|#
directive|define
name|SHR_CLrb
parameter_list|(
name|dr32
parameter_list|)
value|do {						\ 	emitm(&stream, 0xd3, 1);					\ 	emitm(&stream, (29<< 3) | (dr32& 0x7), 1);			\ } while (0)
end_define

begin_comment
comment|/* neg r32 */
end_comment

begin_define
define|#
directive|define
name|NEGd
parameter_list|(
name|r32
parameter_list|)
value|do {							\ 	emitm(&stream, 0xf7, 1);					\ 	emitm(&stream, (27<< 3) | (r32& 0x7), 1);			\ } while (0)
end_define

begin_comment
comment|/* cmp dr32,sr64[off] */
end_comment

begin_define
define|#
directive|define
name|CMPodd
parameter_list|(
name|dr32
parameter_list|,
name|sr64
parameter_list|,
name|off
parameter_list|)
value|do {					\ 	emitm(&stream, (3<< 4) | 3 | (1<< 3), 1);			\ 	emitm(&stream,							\ 	    (1<< 6) | ((dr32& 0x7)<< 3) | (sr64& 0x7), 1);		\ 	emitm(&stream, off, 1);						\ } while (0)
end_define

begin_comment
comment|/* cmp dr32,sr32 */
end_comment

begin_define
define|#
directive|define
name|CMPrd
parameter_list|(
name|dr32
parameter_list|,
name|sr32
parameter_list|)
value|do {						\ 	emitm(&stream, 0x3b, 1);					\ 	emitm(&stream,							\ 	    (3<< 6) | ((dr32& 0x7)<< 3) | (sr32& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* cmp dr32,i32 */
end_comment

begin_define
define|#
directive|define
name|CMPid
parameter_list|(
name|dr32
parameter_list|,
name|i32
parameter_list|)
value|do {						\ 	if (dr32 == EAX){						\ 		emitm(&stream, 0x3d, 1);				\ 		emitm(&stream, i32, 4);					\ 	} else {							\ 		emitm(&stream, 0x81, 1);				\ 		emitm(&stream, (0x1f<< 3) | (dr32& 0x7), 1);		\ 		emitm(&stream, i32, 4);					\ 	}								\ } while (0)
end_define

begin_comment
comment|/* jne off32 */
end_comment

begin_define
define|#
directive|define
name|JNEb
parameter_list|(
name|off8
parameter_list|)
value|do {							\ 	emitm(&stream, 0x75, 1);					\ 	emitm(&stream, off8, 1);					\ } while (0)
end_define

begin_comment
comment|/* je off32 */
end_comment

begin_define
define|#
directive|define
name|JE
parameter_list|(
name|off32
parameter_list|)
value|do {							\ 	emitm(&stream, 0x0f, 1);					\ 	emitm(&stream, 0x84, 1);					\ 	emitm(&stream, off32, 4);					\ } while (0)
end_define

begin_comment
comment|/* jle off32 */
end_comment

begin_define
define|#
directive|define
name|JLE
parameter_list|(
name|off32
parameter_list|)
value|do {							\ 	emitm(&stream, 0x0f, 1);					\ 	emitm(&stream, 0x8e, 1);					\ 	emitm(&stream, off32, 4);					\ } while (0)
end_define

begin_comment
comment|/* jle off8 */
end_comment

begin_define
define|#
directive|define
name|JLEb
parameter_list|(
name|off8
parameter_list|)
value|do {							\ 	emitm(&stream, 0x7e, 1);					\ 	emitm(&stream, off8, 1);					\ } while (0)
end_define

begin_comment
comment|/* ja off32 */
end_comment

begin_define
define|#
directive|define
name|JA
parameter_list|(
name|off32
parameter_list|)
value|do {							\ 	emitm(&stream, 0x0f, 1);					\ 	emitm(&stream, 0x87, 1);					\ 	emitm(&stream, off32, 4);					\ } while (0)
end_define

begin_comment
comment|/* jae off32 */
end_comment

begin_define
define|#
directive|define
name|JAE
parameter_list|(
name|off32
parameter_list|)
value|do {							\ 	emitm(&stream, 0x0f, 1);					\ 	emitm(&stream, 0x83, 1);					\ 	emitm(&stream, off32, 4);					\ } while (0)
end_define

begin_comment
comment|/* jg off32 */
end_comment

begin_define
define|#
directive|define
name|JG
parameter_list|(
name|off32
parameter_list|)
value|do {							\ 	emitm(&stream, 0x0f, 1);					\ 	emitm(&stream, 0x8f, 1);					\ 	emitm(&stream, off32, 4);					\ } while (0)
end_define

begin_comment
comment|/* jge off32 */
end_comment

begin_define
define|#
directive|define
name|JGE
parameter_list|(
name|off32
parameter_list|)
value|do {							\ 	emitm(&stream, 0x0f, 1);					\ 	emitm(&stream, 0x8d, 1);					\ 	emitm(&stream, off32, 4);					\ } while (0)
end_define

begin_comment
comment|/* jmp off32 */
end_comment

begin_define
define|#
directive|define
name|JMP
parameter_list|(
name|off32
parameter_list|)
value|do {							\ 	emitm(&stream, 0xe9, 1);					\ 	emitm(&stream, off32, 4);					\ } while (0)
end_define

begin_comment
comment|/* xor eax,eax */
end_comment

begin_define
define|#
directive|define
name|ZERO_EAX
parameter_list|()
value|do {							\ 	emitm(&stream, 0x31, 1);					\ 	emitm(&stream, 0xc0, 1);					\ } while (0)
end_define

begin_comment
comment|/* xor edx,edx */
end_comment

begin_define
define|#
directive|define
name|ZERO_EDX
parameter_list|()
value|do {							\ 	emitm(&stream, 0x31, 1);					\ 	emitm(&stream, 0xd2, 1);					\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BPF_JIT_MACHDEP_H_ */
end_comment

end_unit

