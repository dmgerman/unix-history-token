begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2002-2003 NetGroup, Politecnico di Torino (Italy)  * Copyright (C) 2005-2009 Jung-uk Kim<jkim@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  * notice, this list of conditions and the following disclaimer in the  * documentation and/or other materials provided with the distribution.  * 3. Neither the name of the Politecnico di Torino nor the names of its  * contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|R8
value|0
end_define

begin_define
define|#
directive|define
name|R9
value|1
end_define

begin_define
define|#
directive|define
name|R10
value|2
end_define

begin_define
define|#
directive|define
name|R11
value|3
end_define

begin_define
define|#
directive|define
name|R12
value|4
end_define

begin_define
define|#
directive|define
name|R13
value|5
end_define

begin_define
define|#
directive|define
name|R14
value|6
end_define

begin_define
define|#
directive|define
name|R15
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
name|R8D
value|0
end_define

begin_define
define|#
directive|define
name|R9D
value|1
end_define

begin_define
define|#
directive|define
name|R10D
value|2
end_define

begin_define
define|#
directive|define
name|R11D
value|3
end_define

begin_define
define|#
directive|define
name|R12D
value|4
end_define

begin_define
define|#
directive|define
name|R13D
value|5
end_define

begin_define
define|#
directive|define
name|R14D
value|6
end_define

begin_define
define|#
directive|define
name|R15D
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
comment|/* Optimization flags */
end_comment

begin_define
define|#
directive|define
name|BPF_JIT_FRET
value|0x01
end_define

begin_define
define|#
directive|define
name|BPF_JIT_FPKT
value|0x02
end_define

begin_define
define|#
directive|define
name|BPF_JIT_FMEM
value|0x04
end_define

begin_define
define|#
directive|define
name|BPF_JIT_FJMP
value|0x08
end_define

begin_define
define|#
directive|define
name|BPF_JIT_FLEN
value|0x10
end_define

begin_define
define|#
directive|define
name|BPF_JIT_FLAG_ALL
define|\
value|(BPF_JIT_FPKT | BPF_JIT_FMEM | BPF_JIT_FJMP | BPF_JIT_FLEN)
end_define

begin_comment
comment|/* A stream of native binary code */
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
comment|/*  * Native instruction macros  */
end_comment

begin_comment
comment|/* movl i32,r32 */
end_comment

begin_define
define|#
directive|define
name|MOVid
parameter_list|(
name|i32
parameter_list|,
name|r32
parameter_list|)
value|do {						\ 	emitm(&stream, (11<< 4) | (1<< 3) | (r32& 0x7), 1);		\ 	emitm(&stream, i32, 4);						\ } while (0)
end_define

begin_comment
comment|/* movq i64,r64 */
end_comment

begin_define
define|#
directive|define
name|MOViq
parameter_list|(
name|i64
parameter_list|,
name|r64
parameter_list|)
value|do {						\ 	emitm(&stream, 0x48, 1);					\ 	emitm(&stream, (11<< 4) | (1<< 3) | (r64& 0x7), 1);		\ 	emitm(&stream, i64, 4);						\ 	emitm(&stream, (i64>> 32), 4);					\ } while (0)
end_define

begin_comment
comment|/* movl sr32,dr32 */
end_comment

begin_define
define|#
directive|define
name|MOVrd
parameter_list|(
name|sr32
parameter_list|,
name|dr32
parameter_list|)
value|do {						\ 	emitm(&stream, 0x89, 1);					\ 	emitm(&stream,							\ 	    (3<< 6) | ((sr32& 0x7)<< 3) | (dr32& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* movl sr32,dr32 (dr32 = %r8-15d) */
end_comment

begin_define
define|#
directive|define
name|MOVrd2
parameter_list|(
name|sr32
parameter_list|,
name|dr32
parameter_list|)
value|do {						\ 	emitm(&stream, 0x8941, 2);					\ 	emitm(&stream,							\ 	    (3<< 6) | ((sr32& 0x7)<< 3) | (dr32& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* movl sr32,dr32 (sr32 = %r8-15d) */
end_comment

begin_define
define|#
directive|define
name|MOVrd3
parameter_list|(
name|sr32
parameter_list|,
name|dr32
parameter_list|)
value|do {						\ 	emitm(&stream, 0x8944, 2);					\ 	emitm(&stream,							\ 	    (3<< 6) | ((sr32& 0x7)<< 3) | (dr32& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* movq sr64,dr64 */
end_comment

begin_define
define|#
directive|define
name|MOVrq
parameter_list|(
name|sr64
parameter_list|,
name|dr64
parameter_list|)
value|do {						\ 	emitm(&stream, 0x8948, 2);					\ 	emitm(&stream,							\ 	    (3<< 6) | ((sr64& 0x7)<< 3) | (dr64& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* movq sr64,dr64 (dr64 = %r8-15) */
end_comment

begin_define
define|#
directive|define
name|MOVrq2
parameter_list|(
name|sr64
parameter_list|,
name|dr64
parameter_list|)
value|do {						\ 	emitm(&stream, 0x8949, 2);					\ 	emitm(&stream,							\ 	    (3<< 6) | ((sr64& 0x7)<< 3) | (dr64& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* movq sr64,dr64 (sr64 = %r8-15) */
end_comment

begin_define
define|#
directive|define
name|MOVrq3
parameter_list|(
name|sr64
parameter_list|,
name|dr64
parameter_list|)
value|do {						\ 	emitm(&stream, 0x894c, 2);					\ 	emitm(&stream,							\ 	    (3<< 6) | ((sr64& 0x7)<< 3) | (dr64& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* movl (sr64,or64,1),dr32 */
end_comment

begin_define
define|#
directive|define
name|MOVobd
parameter_list|(
name|sr64
parameter_list|,
name|or64
parameter_list|,
name|dr32
parameter_list|)
value|do {					\ 	emitm(&stream, 0x8b, 1);					\ 	emitm(&stream, ((dr32& 0x7)<< 3) | 4, 1);			\ 	emitm(&stream, ((or64& 0x7)<< 3) | (sr64& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* movw (sr64,or64,1),dr16 */
end_comment

begin_define
define|#
directive|define
name|MOVobw
parameter_list|(
name|sr64
parameter_list|,
name|or64
parameter_list|,
name|dr16
parameter_list|)
value|do {					\ 	emitm(&stream, 0x8b66, 2);					\ 	emitm(&stream, ((dr16& 0x7)<< 3) | 4, 1);			\ 	emitm(&stream, ((or64& 0x7)<< 3) | (sr64& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* movb (sr64,or64,1),dr8 */
end_comment

begin_define
define|#
directive|define
name|MOVobb
parameter_list|(
name|sr64
parameter_list|,
name|or64
parameter_list|,
name|dr8
parameter_list|)
value|do {					\ 	emitm(&stream, 0x8a, 1);					\ 	emitm(&stream, ((dr8& 0x7)<< 3) | 4, 1);			\ 	emitm(&stream, ((or64& 0x7)<< 3) | (sr64& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* movl sr32,(dr64,or64,1) */
end_comment

begin_define
define|#
directive|define
name|MOVomd
parameter_list|(
name|sr32
parameter_list|,
name|dr64
parameter_list|,
name|or64
parameter_list|)
value|do {					\ 	emitm(&stream, 0x89, 1);					\ 	emitm(&stream, ((sr32& 0x7)<< 3) | 4, 1);			\ 	emitm(&stream, ((or64& 0x7)<< 3) | (dr64& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* bswapl dr32 */
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
comment|/* xchgb %al,%ah */
end_comment

begin_define
define|#
directive|define
name|SWAP_AX
parameter_list|()
value|do {							\ 	emitm(&stream, 0xc486, 2);					\ } while (0)
end_define

begin_comment
comment|/* pushq r64 */
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
comment|/* leaveq */
end_comment

begin_define
define|#
directive|define
name|LEAVE
parameter_list|()
value|do {							\ 	emitm(&stream, 0xc9, 1);					\ } while (0)
end_define

begin_comment
comment|/* retq */
end_comment

begin_define
define|#
directive|define
name|RET
parameter_list|()
value|do {							\ 	emitm(&stream, 0xc3, 1);					\ } while (0)
end_define

begin_comment
comment|/* addl sr32,dr32 */
end_comment

begin_define
define|#
directive|define
name|ADDrd
parameter_list|(
name|sr32
parameter_list|,
name|dr32
parameter_list|)
value|do {						\ 	emitm(&stream, 0x01, 1);					\ 	emitm(&stream,							\ 	    (3<< 6) | ((sr32& 0x7)<< 3) | (dr32& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* addl i32,%eax */
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
comment|/* addl i8,r32 */
end_comment

begin_define
define|#
directive|define
name|ADDib
parameter_list|(
name|i8
parameter_list|,
name|r32
parameter_list|)
value|do {						\ 	emitm(&stream, 0x83, 1);					\ 	emitm(&stream, (24<< 3) | r32, 1);				\ 	emitm(&stream, i8, 1);						\ } while (0)
end_define

begin_comment
comment|/* subl sr32,dr32 */
end_comment

begin_define
define|#
directive|define
name|SUBrd
parameter_list|(
name|sr32
parameter_list|,
name|dr32
parameter_list|)
value|do {						\ 	emitm(&stream, 0x29, 1);					\ 	emitm(&stream,							\ 	    (3<< 6) | ((sr32& 0x7)<< 3) | (dr32& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* subl i32,%eax */
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
comment|/* subq i8,r64 */
end_comment

begin_define
define|#
directive|define
name|SUBib
parameter_list|(
name|i8
parameter_list|,
name|r64
parameter_list|)
value|do {						\ 	emitm(&stream, 0x8348, 2);					\ 	emitm(&stream, (29<< 3) | (r64& 0x7), 1);			\ 	emitm(&stream, i8, 1);						\ } while (0)
end_define

begin_comment
comment|/* mull r32 */
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
comment|/* divl r32 */
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
comment|/* andb i8,r8 */
end_comment

begin_define
define|#
directive|define
name|ANDib
parameter_list|(
name|i8
parameter_list|,
name|r8
parameter_list|)
value|do {						\ 	if (r8 == AL) {							\ 		emitm(&stream, 0x24, 1);				\ 	} else {							\ 		emitm(&stream, 0x80, 1);				\ 		emitm(&stream, (7<< 5) | r8, 1);			\ 	}								\ 	emitm(&stream, i8, 1);						\ } while (0)
end_define

begin_comment
comment|/* andl i32,r32 */
end_comment

begin_define
define|#
directive|define
name|ANDid
parameter_list|(
name|i32
parameter_list|,
name|r32
parameter_list|)
value|do {						\ 	if (r32 == EAX) {						\ 		emitm(&stream, 0x25, 1);				\ 	} else {							\ 		emitm(&stream, 0x81, 1);				\ 		emitm(&stream, (7<< 5) | r32, 1);			\ 	}								\ 	emitm(&stream, i32, 4);						\ } while (0)
end_define

begin_comment
comment|/* andl sr32,dr32 */
end_comment

begin_define
define|#
directive|define
name|ANDrd
parameter_list|(
name|sr32
parameter_list|,
name|dr32
parameter_list|)
value|do {						\ 	emitm(&stream, 0x21, 1);					\ 	emitm(&stream,							\ 	    (3<< 6) | ((sr32& 0x7)<< 3) | (dr32& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* testl i32,r32 */
end_comment

begin_define
define|#
directive|define
name|TESTid
parameter_list|(
name|i32
parameter_list|,
name|r32
parameter_list|)
value|do {						\ 	if (r32 == EAX) {						\ 		emitm(&stream, 0xa9, 1);				\ 	} else {							\ 		emitm(&stream, 0xf7, 1);				\ 		emitm(&stream, (3<< 6) | r32, 1);			\ 	}								\ 	emitm(&stream, i32, 4);						\ } while (0)
end_define

begin_comment
comment|/* testl sr32,dr32 */
end_comment

begin_define
define|#
directive|define
name|TESTrd
parameter_list|(
name|sr32
parameter_list|,
name|dr32
parameter_list|)
value|do {						\ 	emitm(&stream, 0x85, 1);					\ 	emitm(&stream,							\ 	    (3<< 6) | ((sr32& 0x7)<< 3) | (dr32& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* orl sr32,dr32 */
end_comment

begin_define
define|#
directive|define
name|ORrd
parameter_list|(
name|sr32
parameter_list|,
name|dr32
parameter_list|)
value|do {						\ 	emitm(&stream, 0x09, 1);					\ 	emitm(&stream,							\ 	    (3<< 6) | ((sr32& 0x7)<< 3) | (dr32& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* orl i32,r32 */
end_comment

begin_define
define|#
directive|define
name|ORid
parameter_list|(
name|i32
parameter_list|,
name|r32
parameter_list|)
value|do {						\ 	if (r32 == EAX) {						\ 		emitm(&stream, 0x0d, 1);				\ 	} else {							\ 		emitm(&stream, 0x81, 1);				\ 		emitm(&stream, (25<< 3) | r32, 1);			\ 	}								\ 	emitm(&stream, i32, 4);						\ } while (0)
end_define

begin_comment
comment|/* shll i8,r32 */
end_comment

begin_define
define|#
directive|define
name|SHLib
parameter_list|(
name|i8
parameter_list|,
name|r32
parameter_list|)
value|do {						\ 	emitm(&stream, 0xc1, 1);					\ 	emitm(&stream, (7<< 5) | (r32& 0x7), 1);			\ 	emitm(&stream, i8, 1);						\ } while (0)
end_define

begin_comment
comment|/* shll %cl,dr32 */
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
comment|/* shrl i8,r32 */
end_comment

begin_define
define|#
directive|define
name|SHRib
parameter_list|(
name|i8
parameter_list|,
name|r32
parameter_list|)
value|do {						\ 	emitm(&stream, 0xc1, 1);					\ 	emitm(&stream, (29<< 3) | (r32& 0x7), 1);			\ 	emitm(&stream, i8, 1);						\ } while (0)
end_define

begin_comment
comment|/* shrl %cl,dr32 */
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
comment|/* negl r32 */
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
comment|/* cmpl sr32,dr32 */
end_comment

begin_define
define|#
directive|define
name|CMPrd
parameter_list|(
name|sr32
parameter_list|,
name|dr32
parameter_list|)
value|do {						\ 	emitm(&stream, 0x39, 1);					\ 	emitm(&stream,							\ 	    (3<< 6) | ((sr32& 0x7)<< 3) | (dr32& 0x7), 1);		\ } while (0)
end_define

begin_comment
comment|/* cmpl i32,dr32 */
end_comment

begin_define
define|#
directive|define
name|CMPid
parameter_list|(
name|i32
parameter_list|,
name|dr32
parameter_list|)
value|do {						\ 	if (dr32 == EAX){						\ 		emitm(&stream, 0x3d, 1);				\ 		emitm(&stream, i32, 4);					\ 	} else {							\ 		emitm(&stream, 0x81, 1);				\ 		emitm(&stream, (0x1f<< 3) | (dr32& 0x7), 1);		\ 		emitm(&stream, i32, 4);					\ 	}								\ } while (0)
end_define

begin_comment
comment|/* jb off8 */
end_comment

begin_define
define|#
directive|define
name|JBb
parameter_list|(
name|off8
parameter_list|)
value|do {							\ 	emitm(&stream, 0x72, 1);					\ 	emitm(&stream, off8, 1);					\ } while (0)
end_define

begin_comment
comment|/* jae off8 */
end_comment

begin_define
define|#
directive|define
name|JAEb
parameter_list|(
name|off8
parameter_list|)
value|do {							\ 	emitm(&stream, 0x73, 1);					\ 	emitm(&stream, off8, 1);					\ } while (0)
end_define

begin_comment
comment|/* jne off8 */
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
comment|/* ja off8 */
end_comment

begin_define
define|#
directive|define
name|JAb
parameter_list|(
name|off8
parameter_list|)
value|do {							\ 	emitm(&stream, 0x77, 1);					\ 	emitm(&stream, off8, 1);					\ } while (0)
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
comment|/* xorl r32,r32 */
end_comment

begin_define
define|#
directive|define
name|ZEROrd
parameter_list|(
name|r32
parameter_list|)
value|do {						\ 	emitm(&stream, 0x31, 1);					\ 	emitm(&stream, (3<< 6) | ((r32& 0x7)<< 3) | (r32& 0x7), 1);	\ } while (0)
end_define

begin_comment
comment|/*  * Conditional long jumps  */
end_comment

begin_define
define|#
directive|define
name|JB
value|0x82
end_define

begin_define
define|#
directive|define
name|JAE
value|0x83
end_define

begin_define
define|#
directive|define
name|JE
value|0x84
end_define

begin_define
define|#
directive|define
name|JNE
value|0x85
end_define

begin_define
define|#
directive|define
name|JBE
value|0x86
end_define

begin_define
define|#
directive|define
name|JA
value|0x87
end_define

begin_define
define|#
directive|define
name|JCC
parameter_list|(
name|t
parameter_list|,
name|f
parameter_list|)
value|do {							\ 	if (ins->jt != 0&& ins->jf != 0) {				\
comment|/* 5 is the size of the following jmp */
value|\ 		emitm(&stream, ((t)<< 8) | 0x0f, 2);			\ 		emitm(&stream, stream.refs[stream.bpf_pc + ins->jt] -	\ 		    stream.refs[stream.bpf_pc] + 5, 4);			\ 		JMP(stream.refs[stream.bpf_pc + ins->jf] -		\ 		    stream.refs[stream.bpf_pc]);			\ 	} else if (ins->jt != 0) {					\ 		emitm(&stream, ((t)<< 8) | 0x0f, 2);			\ 		emitm(&stream, stream.refs[stream.bpf_pc + ins->jt] -	\ 		    stream.refs[stream.bpf_pc], 4);			\ 	} else {							\ 		emitm(&stream, ((f)<< 8) | 0x0f, 2);			\ 		emitm(&stream, stream.refs[stream.bpf_pc + ins->jf] -	\ 		    stream.refs[stream.bpf_pc], 4);			\ 	}								\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BPF_JIT_MACHDEP_H_ */
end_comment

end_unit

